//This source code is generated by UI Designer Studio.
#ifdef __ECOS
#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "NVTToolCommand.h"
#include "UIMenuWndWiFiModuleLinkRes.c"
#include "UIFlow.h"
#include "UIAppNetwork.h"
extern UIMenuStoreInfo  currentInfo;

//---------------------UIMenuWndWiFiModuleLinkCtrl Debug Definition -----------------------------
#define _UIMENUWNDWIFIMODULELINK_ERROR_MSG        1
#define _UIMENUWNDWIFIMODULELINK_TRACE_MSG        0

#if (_UIMENUWNDWIFIMODULELINK_ERROR_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_ERR))
#define UIMenuWndWiFiModuleLinkErrMsg(...)            debug_msg ("^R UIMenuWndWiFiModuleLink: "__VA_ARGS__)
#else
#define UIMenuWndWiFiModuleLinkErrMsg(...)
#endif

#if (_UIMENUWNDWIFIMODULELINK_TRACE_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_TRC))
#define UIMenuWndWiFiModuleLinkTraceMsg(...)          debug_msg ("^B UIMenuWndWiFiModuleLink: "__VA_ARGS__)
#else
#define UIMenuWndWiFiModuleLinkTraceMsg(...)
#endif

extern BOOL gbDisconnectWifiDerectly;
extern BOOL g_bgsensor;
extern int SX_TIMER_DET_ACC_ID;
extern BOOL gbNeed2RestrartRecord;

//---------------------UIMenuWndWiFiModuleLinkCtrl Global Variables -----------------------------
//---------------------UIMenuWndWiFiModuleLinkCtrl Prototype Declaration  -----------------------

//---------------------UIMenuWndWiFiModuleLinkCtrl Public API  ----------------------------------

//---------------------UIMenuWndWiFiModuleLinkCtrl Private API  ---------------------------------
void UIMenuWndWiFiModuleLink_UpdateData(void);

//---------------------UIMenuWndWiFiModuleLinkCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndWiFiModuleLink)
CTRL_LIST_ITEM(UIMenuWndWiFiModuleLink_StaticICN_WiFi)
CTRL_LIST_ITEM(UIMenuWndWiFiModuleLink_StaticICN_TitleBar)
CTRL_LIST_ITEM(UIMenuWndWiFiModuleLink_StatusTXT_WiFiMode)
CTRL_LIST_ITEM(UIMenuWndWiFiModuleLink_StaticTXT_SSID)
CTRL_LIST_ITEM(UIMenuWndWiFiModuleLink_StaticTXT_Key)
CTRL_LIST_ITEM(UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff)
CTRL_LIST_ITEM(UIMenuWndWiFiModeLink_Panel)
CTRL_LIST_ITEM(UIMenuWndWiFiModeLink_Static_Lock)
CTRL_LIST_END

//----------------------UIMenuWndWiFiModuleLinkCtrl Event---------------------------
INT32 UIMenuWndWiFiModuleLink_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModuleLink_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModuleLink_OnChildClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModuleLink_OnBattery(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModuleLink_OnTimer(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModuleLink_OnMovieFull(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModuleLink_OnMovieWrError(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModuleLink_OnStorageSlow(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModuleLink_OnOneSecond(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModuleLink_OnOneMovieCutFileEnd(VControl *, UINT32, UINT32 *);

EVENT_BEGIN(UIMenuWndWiFiModuleLink)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndWiFiModuleLink_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndWiFiModuleLink_OnClose)
EVENT_ITEM(NVTEVT_CHILD_CLOSE,UIMenuWndWiFiModuleLink_OnChildClose)
EVENT_ITEM(NVTEVT_BATTERY,UIMenuWndWiFiModuleLink_OnBattery)
EVENT_ITEM(NVTEVT_TIMER,UIMenuWndWiFiModuleLink_OnTimer)
EVENT_ITEM(NVTEVT_CB_MOVIE_OVERTIME,UIMenuWndWiFiModuleLink_OnMovieFull) // the same handling as storage full (may need to show special message)
EVENT_ITEM(NVTEVT_CB_MOVIE_FULL,UIMenuWndWiFiModuleLink_OnMovieFull)
EVENT_ITEM(NVTEVT_CB_MOVIE_LOOPREC_FULL,UIMenuWndWiFiModuleLink_OnMovieFull)
EVENT_ITEM(NVTEVT_CB_MOVIE_WR_ERROR,UIMenuWndWiFiModuleLink_OnMovieWrError)
EVENT_ITEM(NVTEVT_CB_MOVIE_SLOW,UIMenuWndWiFiModuleLink_OnStorageSlow)
EVENT_ITEM(NVTEVT_CB_MOVIE_REC_ONE_SEC,UIMenuWndWiFiModuleLink_OnOneSecond)
EVENT_ITEM(NVTEVT_ALGMSG_PROGRESSEND,UIMenuWndWiFiModuleLink_OnOneMovieCutFileEnd)

EVENT_END


void UIMenuWndWiFiModuleLink_UpdateData(void)
{
    static char buf1[32],buf2[32];
    char *pMacAddr;

    if(UI_GetData(FL_WIFI_LINK)==WIFI_LINK_OK)
    {
        if(UI_GetData(FL_NetWorkMode)==NETWORK_AP_MODE)
        {
            if(currentInfo.strSSID[0] == 0)
            {
                #if (MAC_APPEN_SSID==ENABLE)
                pMacAddr = (char*)UINet_GetMAC();
                sprintf(buf1,"SSID:%s% 02x%02x%02x%02x%02x%02x", UINet_GetSSID() ,pMacAddr[0], pMacAddr[1], pMacAddr[2]
                                                            ,pMacAddr[3], pMacAddr[4], pMacAddr[5]);
                #else
                sprintf(buf1,"SSID:%s",UINet_GetSSID());
                #endif
            }
            else
            {
                sprintf(buf1,"SSID:%s",currentInfo.strSSID);
            }


            sprintf(buf2,"PWD:%s",UINet_GetPASSPHRASE());
            UxStatic_SetData(&UIMenuWndWiFiModuleLink_StaticTXT_SSIDCtrl,STATIC_VALUE,Txt_Pointer(buf1));
            UxStatic_SetData(&UIMenuWndWiFiModuleLink_StaticTXT_KeyCtrl,STATIC_VALUE,Txt_Pointer(buf2));
        }
    }
    else
    {
        sprintf(buf1,"%s:Fail",TXT_WIFI_CONNECT);
        UxStatic_SetData(&UIMenuWndWiFiModuleLink_StaticTXT_SSIDCtrl,STATIC_VALUE,Txt_Pointer(buf1));
        UxStatic_SetData(&UIMenuWndWiFiModuleLink_StaticTXT_KeyCtrl,STATIC_VALUE,STRID_NULL);
    }
    UxCtrl_SetShow(&Button_RefreshCtrl, FALSE);
    UxCtrl_SetShow(&Button_WiFiOffCtrl, FALSE);
	
}
INT32 UIMenuWndWiFiModuleLink_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    static BOOL first=TRUE;
    UIMenuWndWiFiModuleLink_UpdateData();
    UxTab_SetData(&UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOffCtrl, TAB_FOCUS, 0);
    UxCtrl_SetShow(&UIMenuWndWiFiModeLink_PanelCtrl,FALSE);   	
    UxCtrl_SetShow(&UIMenuWndWiFiModeLink_Static_LockCtrl,FALSE);   	
    if(first==TRUE)	
    {
       SxTimer_SetFuncActive(SX_TIMER_DET_ACC_ID,TRUE);    
	first=FALSE;
    }
    else
    {
	Ux_PostEvent(NVTEVT_KEY_SHUTTER2, 1, NVTEVT_KEY_PRESS);	
    }
	
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndWiFiModuleLink_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndWiFiModuleLink_OnChildClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UIMenuWndWiFiModuleLink_UpdateData();
    if(gbDisconnectWifiDerectly==TRUE)
    {
    	     gbDisconnectWifiDerectly=FALSE;
	     gbNeed2RestrartRecord=TRUE;
			 
            if(UI_GetData(FL_WIFI_LINK)==WIFI_LINK_OK)
            {   //change to normal mode for close app
                Ux_PostEvent(NVTEVT_SYSTEM_MODE, 2, System_GetState(SYS_STATE_CURRMODE),SYS_SUBMODE_NORMAL);
                //should close network application,then stop wifi
                Ux_PostEvent(NVTEVT_EXE_WIFI_STOP, 0);
            }
            else
            {
                Ux_CloseWindow(&UIMenuWndWiFiModuleLinkCtrl,0);
            }
	     UI_SetData(FL_WIFI_LINK,WIFI_LINK_NG);			
    }	
    Ux_DefaultEvent(pCtrl,NVTEVT_CHILD_CLOSE,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndWiFiModuleLink_OnBattery(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndWiFiModuleLink_OnTimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_TIMER,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//----------------------UIMenuWndWiFiModuleLink_StaticICN_WiFiCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndWiFiModuleLink_StaticICN_WiFi)
EVENT_END

//----------------------UIMenuWndWiFiModuleLink_StaticICN_TitleBarCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndWiFiModuleLink_StaticICN_TitleBar)
EVENT_END

//----------------------UIMenuWndWiFiModuleLink_StatusTXT_WiFiModeCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndWiFiModuleLink_StatusTXT_WiFiMode)
EVENT_END

//----------------------UIMenuWndWiFiModuleLink_StaticTXT_SSIDCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndWiFiModuleLink_StaticTXT_SSID)
EVENT_END

//----------------------UIMenuWndWiFiModuleLink_StaticTXT_KeyCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndWiFiModuleLink_StaticTXT_Key)
EVENT_END

//----------------------UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOffCtrl Event---------------------------
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyRight(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_WifiOnOff(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyMode(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyShutter2(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnGsensorTrig(VControl *, UINT32, UINT32 *);

INT32 UIMenuWndWiFiModeLink_Tab_Authorized_OK(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyRight)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_WIFIONOFF,UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_WifiOnOff)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyMode)
EVENT_ITEM(NVTEVT_WIFI_AUTHORIZED_OK,UIMenuWndWiFiModeLink_Tab_Authorized_OK)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyShutter2)
//EVENT_ITEM(NVTEVT_GSENSOR_TRIG,UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnGsensorTrig)

EVENT_END

INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];
    switch(uiKeyAct)
    {
    case NVTEVT_KEY_PRESS:
        Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
        break;
    }

    return NVTEVT_CONSUME;
}
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyRight(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];
    switch(uiKeyAct)
    {
    case NVTEVT_KEY_PRESS:
        Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
        break;
    }

    return NVTEVT_CONSUME;
}
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];
    switch(uiKeyAct)
    {
    case NVTEVT_KEY_PRESS:
        switch(UxTab_GetData(&UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOffCtrl, TAB_FOCUS))
        {
        case UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_Button_Refresh:
            break;
        case UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_Button_WiFiOff:
            if(UI_GetData(FL_WIFI_LINK)==WIFI_LINK_OK)
            {   //change to normal mode for close app
                Ux_PostEvent(NVTEVT_SYSTEM_MODE, 2, System_GetState(SYS_STATE_CURRMODE),SYS_SUBMODE_NORMAL);
                //should close network application,then stop wifi
                Ux_PostEvent(NVTEVT_EXE_WIFI_STOP, 0);
            }
            else
            {
                Ux_CloseWindow(&UIMenuWndWiFiModuleLinkCtrl,0);
            }
	     UI_SetData(FL_WIFI_LINK,WIFI_LINK_NG);			
            break;
        }
        break;
    }

    return NVTEVT_CONSUME;
}

INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_WifiOnOff(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];
    switch(uiKeyAct)
    {
    case NVTEVT_KEY_PRESS:	
	     gbNeed2RestrartRecord=TRUE;
		
            if(UI_GetData(FL_WIFI_LINK)==WIFI_LINK_OK)
            {   
            	   //change to normal mode for close app
                Ux_PostEvent(NVTEVT_SYSTEM_MODE, 2, System_GetState(SYS_STATE_CURRMODE),SYS_SUBMODE_NORMAL);
                //should close network application,then stop wifi
                Ux_PostEvent(NVTEVT_EXE_WIFI_STOP, 0);
            }
            else
            {
                Ux_CloseWindow(&UIMenuWndWiFiModuleLinkCtrl,0);
            }
	     UI_SetData(FL_WIFI_LINK,WIFI_LINK_NG);
        break;
    }

    return NVTEVT_CONSUME;
}

INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return UIFlowWndWiFiMovie_OnExeMovieTriggerRawEnc(pCtrl, paramNum, paramArray);	
}


INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	if(UIFlowWndWiFiMovie_GetStatus()==WIFI_MOV_ST_RECORD)
        {
		if(g_bgsensor==FALSE)
		{
			g_bgsensor = TRUE;     
			MediaRec_SetCrash();	
    			UxCtrl_SetShow(&UIMenuWndWiFiModeLink_Static_LockCtrl,TRUE);   	
		}	
        }
    return NVTEVT_CONSUME;	
}

INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	UINT32  uiKeyAct;
	static UINT32 uiRecAudioSet = 0;

	uiKeyAct = paramArray[0];
    switch(uiKeyAct)
    {

		case NVTEVT_KEY_PRESS:

			if(UIFlowWndWiFiMovie_GetStatus() == WIFI_MOV_ST_RECORD)
			{
				uiRecAudioSet = UI_GetData(FL_MOVIE_AUDIO);
				if(uiRecAudioSet == MOVIE_AUDIO_OFF)
				{
					Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIE_AUDIO, 1, MOVIE_AUDIO_ON);
				}
				else
				{
					Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIE_AUDIO, 1, MOVIE_AUDIO_OFF);
				}
			}

			break;
			
    	case NVTEVT_KEY_CONTINUE:
			
			if(UIFlowWndWiFiMovie_GetStatus() == WIFI_MOV_ST_RECORD)
			{
	    		UIFlowWndWiFiMovie_OnExeKeyShutter2(FALSE);
			}
			else
			{
	    		UIFlowWndWiFiMovie_OnExeKeyShutter2(TRUE);
			}

			break;
						
		defult:
			break;
    }
    return NVTEVT_CONSUME;			
}
INT32 UIMenuWndWiFiModeLink_Tab_RefreshAndWiFiOff_OnGsensorTrig(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
	if(UIFlowWndWiFiMovie_GetStatus()==WIFI_MOV_ST_RECORD)
        {
		if(g_bgsensor==FALSE)
		{
			g_bgsensor = TRUE;     
			MediaRec_SetCrash();	
    			UxCtrl_SetShow(&UIMenuWndWiFiModeLink_Static_LockCtrl,TRUE);   	
		}	
        }
    return NVTEVT_CONSUME;	
}

INT32 UIMenuWndWiFiModeLink_Tab_Authorized_OK(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_OpenWindow(&UIMenuWndWiFiMobileLinkOKCtrl, 0);

    return NVTEVT_CONSUME;
}

//----------------------Button_RefreshCtrl Event---------------------------
EVENT_BEGIN(Button_Refresh)
EVENT_END

//----------------------Button_WiFiOffCtrl Event---------------------------
EVENT_BEGIN(Button_WiFiOff)
EVENT_END
//---------------------UIMenuWndWiFiModeLink_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndWiFiModeLink_Panel)
CTRL_LIST_END

//----------------------UIMenuWndWiFiModeLink_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndWiFiModeLink_Panel)
EVENT_END

//----------------------UIMenuWndWiFiModeLink_Static_LockCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndWiFiModeLink_Static_Lock)
EVENT_END

INT32 UIMenuWndWiFiModuleLink_OnMovieFull(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return UIFlowWndWiFiMovie_OnMovieFull(pCtrl, paramNum, paramArray);
}
INT32 UIMenuWndWiFiModuleLink_OnMovieWrError(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return UIFlowWndWiFiMovie_OnMovieWrError(pCtrl, paramNum, paramArray);
}
INT32 UIMenuWndWiFiModuleLink_OnStorageSlow(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return UIFlowWndWiFiMovie_OnStorageSlow(pCtrl, paramNum, paramArray);
}
INT32 UIMenuWndWiFiModuleLink_OnOneSecond(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if (UIFlowWndWiFiMovie_GetStatus()==WIFI_MOV_ST_RECORD)
    {
    	 UxCtrl_SetShow(&UIMenuWndWiFiModeLink_PanelCtrl,!UxCtrl_IsShow(&UIMenuWndWiFiModeLink_PanelCtrl));      
    }		
    return UIFlowWndWiFiMovie_OnMovieOneSec(pCtrl, paramNum, paramArray);	
}

INT32 UIMenuWndWiFiModuleLink_OnOneMovieCutFileEnd(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(UxCtrl_IsShow(&UIMenuWndWiFiModeLink_Static_LockCtrl))
    {
	 UxCtrl_SetShow(&UIMenuWndWiFiModeLink_Static_LockCtrl,FALSE);
    }
    return NVTEVT_CONSUME;
}

#endif

