	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E0500 @ =0x000003E9
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E04E4
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #6
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldr r3, _081E0504 @ =0x000003EA
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
_081E04E4:
	ldr r0, _081E0504 @ =0x000003EA
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0x3c
	bne _081E0538
	bl Save_WriteExtraToNextSlot
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E050C
	ldr r1, _081E0508 @ =Entity501B_StateSaveFailed
	movs r2, #8
	b _081E0514
	.align 2, 0
_081E0500: .4byte 0x000003E9
_081E0504: .4byte 0x000003EA
_081E0508: .4byte Entity501B_StateSaveFailed
_081E050C:
	bl FUN_081df924
	ldr r1, _081E0530 @ =FUN_081e0544
	movs r2, #5
_081E0514:
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	ldr r0, _081E0534 @ =0x000003E9
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	b _081E053C
	.align 2, 0
_081E0530: .4byte FUN_081e0544
_081E0534: .4byte 0x000003E9
_081E0538:
	adds r0, #1
	strh r0, [r1]
_081E053C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
