	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	ldr r2, _08229F80 @ =0x04000208
	ldrh r1, [r2]
	adds r6, r1, #0
	movs r1, #1
	strh r1, [r2]
	ldr r1, _08229F84 @ =0xFFFF0000
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	ldr r0, _08229F88 @ =0x0000FFFF
	cmp r4, r0
	beq _08229F76
	adds r5, r0, #0
_08229F68:
	bl WaitForVBlank
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r5
	bne _08229F68
_08229F76:
	ldr r0, _08229F80 @ =0x04000208
	strh r6, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08229F80: .4byte 0x04000208
_08229F84: .4byte 0xFFFF0000
_08229F88: .4byte 0x0000FFFF
