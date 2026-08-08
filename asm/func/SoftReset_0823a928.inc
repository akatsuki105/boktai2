	push {lr}
	ldr r0, _0823A970 @ =0x03003518
	movs r1, #0
	str r1, [r0]
	ldr r0, _0823A974 @ =0x03002CA0
	str r1, [r0]
	ldr r0, _0823A978 @ =0x03003510
	strh r1, [r0]
	ldr r0, _0823A97C @ =0x03003514
	strh r1, [r0]
	ldr r0, _0823A980 @ =0x0300351C
	strh r1, [r0]
	bl m4aMPlayAllStop
	bl m4aSoundVSyncOff
	bl WaitForVBlank
	bl WaitForVBlank
	bl FUN_082477b4
	bl RtcIoDisable
	ldr r0, _0823A984 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0823A968
	ldr r0, _0823A988 @ =0x03002C64
	ldr r0, [r0]
	cmp r0, #0
	beq _0823A98C
_0823A968:
	bl FUN_08238bf4
	b _0823A998
	.align 2, 0
_0823A970: .4byte 0x03003518
_0823A974: .4byte 0x03002CA0
_0823A978: .4byte 0x03003510
_0823A97C: .4byte 0x03003514
_0823A980: .4byte 0x0300351C
_0823A984: .4byte 0x03002C68
_0823A988: .4byte 0x03002C64
_0823A98C:
	ldr r0, _0823A9B4 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _0823A998
	bl FUN_08237f54
_0823A998:
	movs r0, #0
	bl rfu_setREQCallback
	bl rfu_REQ_stopMode
	bl rfu_waitREQComplete
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0823A9B8
	movs r0, #0xdc
	bl FUN_0824c1f8
	b _0823A9BE
	.align 2, 0
_0823A9B4: .4byte 0x03002C6C
_0823A9B8:
	movs r0, #0xdc
	bl FUN_0824c1f8
_0823A9BE:
	movs r0, #0
	pop {r1}
	bx r1
