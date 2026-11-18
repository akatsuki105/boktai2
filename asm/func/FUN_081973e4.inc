	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x54
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	bne _0819741A
	ldr r0, _08197420 @ =0x00000AEC
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r2, _08197424 @ =0x00000CC6
	adds r1, r5, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	ldr r1, [r4]
	movs r2, #0xca
	lsls r2, r2, #4
	adds r0, r5, r2
	str r0, [r1, #0xc]
	ldr r1, _08197428 @ =0x00000C5C
	adds r0, r5, r1
	str r6, [r0]
_0819741A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08197420: .4byte 0x00000AEC
_08197424: .4byte 0x00000CC6
_08197428: .4byte 0x00000C5C
