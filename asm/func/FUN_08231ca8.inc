	push {r4, r5, r6, lr}
	ldr r4, _08231CDC @ =0x030046A0
	ldr r0, [r4]
	ldr r5, _08231CE0 @ =0x00000246
	adds r0, r0, r5
	ldrh r6, [r0]
	ldr r0, _08231CE4 @ =0x03004698
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	bl ClearMemory
	ldr r0, [r4]
	adds r0, #0x30
	ldr r1, _08231CE8 @ =0x0000038A
	bl ClearMemory
	ldr r0, [r4]
	adds r0, r0, r5
	strh r6, [r0]
	bl FUN_08231cec
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08231CDC: .4byte 0x030046A0
_08231CE0: .4byte 0x00000246
_08231CE4: .4byte 0x03004698
_08231CE8: .4byte 0x0000038A
