	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x2c
	bl FUN_0809f658
	cmp r0, #0
	beq _08065E10
	ldr r1, _08065E18 @ =0x00000397
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08065E10
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r6, r7, r2
	ldrh r0, [r6]
	ldr r5, _08065E1C @ =0x030046A4
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r3, #4
	ldrsh r1, [r1, r3]
	bl Mod
	adds r4, r0, #0
	ldrh r0, [r6]
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl Div
	lsls r4, r4, #8
	adds r4, #0x80
	movs r3, #0xe7
	lsls r3, r3, #2
	adds r2, r7, r3
	strh r4, [r2]
	lsls r0, r0, #8
	adds r0, #0x80
	adds r3, #4
	adds r1, r7, r3
	strh r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _08065E20 @ =0x00000396
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
_08065E10:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08065E18: .4byte 0x00000397
_08065E1C: .4byte 0x030046A4
_08065E20: .4byte 0x00000396
