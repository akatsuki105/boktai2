	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _08217BA0 @ =0x0825280C
	add r0, sp, #4
	movs r2, #6
	bl memcpy
	ldr r1, _08217BA4 @ =0x00001FDE
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	add r0, sp
	adds r0, #4
	ldrb r1, [r0]
	ldr r2, _08217BA8 @ =0x0000174C
	adds r0, r4, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _08217BAC @ =0x0000174E
	adds r0, r4, r1
	strh r2, [r0]
	ldr r0, _08217BB0 @ =0x00001734
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08217BB4 @ =0x0000172C
	adds r0, r4, r1
	adds r4, #0x18
	movs r1, #4
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08217BA0: .4byte 0x0825280C
_08217BA4: .4byte 0x00001FDE
_08217BA8: .4byte 0x0000174C
_08217BAC: .4byte 0x0000174E
_08217BB0: .4byte 0x00001734
_08217BB4: .4byte 0x0000172C
