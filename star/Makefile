LIB = -lmi_isp -lmi_sensor -lmi_sys -lmi_venc -lmi_vif -lcus3a -lispalgo -lcam_os_wrapper

star-b:
	$(CC) star.c -D SIGMASTAR_ISPAHAN -I include/infinity6b0 -L $(DRV) $(LIB) -lmi_vpe -Os -s -o star

star-c:
	$(CC) star.c -D SIGMASTAR_MARUKO -I include/infinity6c -L $(DRV) $(LIB) -lmi_common -lmi_scl -Os -s -o star

star-e:
	$(CC) star.c -D SIGMASTAR_PUDDING -I include/infinity6e -L $(DRV) $(LIB) -lmi_vpe -lm -Os -s -o star
