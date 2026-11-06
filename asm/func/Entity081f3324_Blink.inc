	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r5, #0
	adds r0, r5, #0
	adds r0, #0xee
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #2
	cmp r0, #0x3c
	bgt _081F283A
	movs r2, #0
	cmp r0, #0x28
	ble _081F283A
	movs r2, #1
_081F283A:
	adds r4, r5, #0
	adds r4, #0xee
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, _081F2868 @ =0x085AE548
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _081F2876
	ldr r1, [r6]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081F286C
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6]
	b _081F2876
	.align 2, 0
_081F2868: .4byte 0x085AE548
_081F286C:
	orrs r1, r2
	str r1, [r6]
	adds r0, r5, #0
	bl Entity081f3324_EmitSmoke
_081F2876:
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0x5a
	bgt _081F2888
	adds r0, r1, #1
	strh r0, [r4]
	movs r0, #0
	b _081F28B8
_081F2888:
	adds r0, r5, #0
	bl Entity081f3324_EmitSmoke
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	adds r0, r5, #0
	adds r0, #0xeb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0
	ldr r0, [r7, #0x38]
	bics r0, r1
	str r0, [r7, #0x38]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r1, r5, #0
	adds r1, #0xea
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_081F28B8:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
