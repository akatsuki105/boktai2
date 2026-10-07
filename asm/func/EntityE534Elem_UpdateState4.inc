	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r6, r1, #0
	adds r4, r2, #0
	ldr r0, _08012754 @ =0x00000CC8
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	beq _080126B8
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
_080126B8:
	ldrb r0, [r6]
	adds r7, r6, #0
	adds r7, #0x28
	cmp r0, #0
	beq _080126F0
	movs r3, #0
	strb r3, [r6]
	ldr r0, [r6, #0x10]
	ldr r1, [r6, #0x14]
	str r0, [r6, #0x20]
	str r1, [r6, #0x24]
	ldr r2, _08012758 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801275C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08012760 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r6, #6]
	str r3, [sp, #4]
	add r0, sp, #4
	adds r1, r7, #0
	ldr r2, _08012764 @ =0x05000002
	bl CpuSet
_080126F0:
	adds r1, r6, #0
	adds r1, #0x20
	adds r2, r6, #0
	adds r2, #0x18
	adds r3, r4, #0
	adds r3, #8
	movs r0, #5
	str r0, [sp]
	adds r0, r1, #0
	bl LerpVec3
	ldrb r0, [r6, #8]
	cmp r0, #0
	bne _08012768
	movs r2, #0x28
	ldrsh r0, [r6, r2]
	rsbs r0, r0, #0
	movs r2, #0x2c
	ldrsh r1, [r6, r2]
	rsbs r1, r1, #0
	bl ArcTan2_8
	strb r0, [r6, #6]
	ldr r5, _08012760 @ =0x0203B400
	ldr r3, _08012758 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _0801275C @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrb r0, [r6, #6]
	subs r0, #7
	movs r1, #0xf
	ands r2, r1
	adds r0, r0, r2
	strb r0, [r6, #6]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	b _0801276A
	.align 2, 0
_08012754: .4byte 0x00000CC8
_08012758: .4byte 0x030046B8
_0801275C: .4byte 0x000003FF
_08012760: .4byte 0x0203B400
_08012764: .4byte 0x05000002
_08012768:
	subs r0, #1
_0801276A:
	strb r0, [r6, #8]
	add r4, sp, #8
	movs r3, #6
	ldrsb r3, [r6, r3]
	ldrh r5, [r6, #0xc]
	ldr r2, _08012794 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	mov ip, r4
	cmp r0, #0
	blt _08012798
	asrs r1, r0, #0xc
	b _0801279E
	.align 2, 0
_08012794: .4byte 0x085B0A08
_08012798:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801279E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080127BA
	asrs r0, r0, #0xc
	b _080127C0
_080127BA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080127C0:
	strh r0, [r4, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r1, [r6, #0x28]
	adds r0, r0, r1
	strh r0, [r6, #0x28]
	mov r2, ip
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	strh r0, [r7, #4]
	ldrh r0, [r6, #0x28]
	ldrh r1, [r6, #0x20]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x2c]
	ldrh r2, [r6, #0x24]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl EntityE534Elem_SetAnim
	ldrh r0, [r6, #4]
	adds r0, #1
	strh r0, [r6, #4]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
