	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	bne _08199A32
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r0, [r5, #0xc]
	ldr r2, _08199A38 @ =0x00000CC6
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Video_SetAuxSpritePltt
	ldr r0, [r5, #0xc]
	movs r1, #0xca
	lsls r1, r1, #4
	adds r4, r4, r1
	str r4, [r0, #0xc]
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r0, r5, r2
	str r6, [r0]
_08199A32:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08199A38: .4byte 0x00000CC6
