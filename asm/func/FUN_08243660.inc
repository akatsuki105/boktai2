	push {r4, r5, r6, lr}
	ldr r1, _082436B8 @ =0x03004880
	ldr r6, _082436BC @ =0x03003518
	ldr r0, [r6]
	str r0, [r1]
	ldr r5, _082436C0 @ =0x03002CA0
	ldr r0, [r5]
	str r0, [r1, #4]
	ldr r3, _082436C4 @ =0x03003510
	ldrh r0, [r3]
	movs r4, #0
	strh r0, [r1, #8]
	ldr r2, _082436C8 @ =0x03003514
	ldrh r0, [r2]
	strh r0, [r1, #0xa]
	str r4, [r6]
	str r4, [r5]
	strh r4, [r3]
	strh r4, [r2]
	bl FUN_082407e0
	bl WaitForVBlank
	ldr r0, _082436CC @ =0x0300351C
	strh r4, [r0]
	bl m4aSoundVSyncOff
	bl WaitForVBlank
	ldr r3, _082436D0 @ =0x04000208
	strh r4, [r3]
	ldr r2, _082436D4 @ =0x0300170C
	ldr r1, _082436D8 @ =0x0300481C
	ldr r0, [r1]
	str r0, [r2]
	movs r0, #1
	str r0, [r1]
	strh r0, [r3]
	bl FUN_08241704
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_082436B8: .4byte 0x03004880
_082436BC: .4byte 0x03003518
_082436C0: .4byte 0x03002CA0
_082436C4: .4byte 0x03003510
_082436C8: .4byte 0x03003514
_082436CC: .4byte 0x0300351C
_082436D0: .4byte 0x04000208
_082436D4: .4byte 0x0300170C
_082436D8: .4byte 0x0300481C
