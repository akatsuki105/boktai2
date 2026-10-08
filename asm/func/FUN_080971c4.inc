	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _08097260 @ =0x00001444
	adds r6, r4, r0
	adds r7, r4, #0
	adds r7, #0x60
	adds r0, r6, #0
	adds r1, r7, #0
	bl MainSprite_AdvanceAnim
	adds r0, r4, #0
	bl FUN_0808c548
	ldr r5, _08097264 @ =0x030044E0
	ldrh r1, [r5, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080971FA
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08096fa8
_080971FA:
	ldrh r1, [r5, #2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0809727C
	ldr r1, _08097268 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0809727C
	ldr r0, _0809726C @ =0x00001C2C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08097270 @ =0x00001464
	adds r0, r4, r1
	movs r1, #0x14
	bl FUN_080921e8
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _08097274 @ =0x0000204C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r4, #0x58]
	movs r1, #2
	movs r2, #1
	bl EntityCC28_ShowBottomLine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _08097278 @ =FUN_08097584
	b _0809740E
	.align 2, 0
_08097260: .4byte 0x00001444
_08097264: .4byte 0x030044E0
_08097268: .4byte 0x00003AE8
_0809726C: .4byte 0x00001C2C
_08097270: .4byte 0x00001464
_08097274: .4byte 0x0000204C
_08097278: .4byte FUN_08097584
_0809727C:
	ldr r0, _080972A8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0809728A
	b _08097446
_0809728A:
	adds r0, r4, #0
	bl FUN_0808c700
	adds r0, r4, #0
	bl FUN_08096ec4
	cmp r0, #4
	bls _0809729C
	b _0809743C
_0809729C:
	lsls r0, r0, #2
	ldr r1, _080972AC @ =_080972B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080972A8: .4byte 0x030044E0
_080972AC: .4byte _080972B0
_080972B0: @ jump table
	.4byte _0809743C @ case 0
	.4byte _080972FC @ case 1
	.4byte _080972C4 @ case 2
	.4byte _08097364 @ case 3
	.4byte _08097330 @ case 4
_080972C4:
	ldr r2, _080972F0 @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080972F4 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	bl EntityCC28_ShowBottomLine
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _080972F8 @ =FUN_08097584
	b _0809740E
	.align 2, 0
_080972F0: .4byte 0x0000144C
_080972F4: .4byte 0x0000204C
_080972F8: .4byte FUN_08097584
_080972FC:
	ldr r1, _08097320 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _08097324 @ =0x00003AEE
	adds r0, r4, r2
	ldrb r2, [r0]
	ldr r1, _08097328 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08096cac
	ldr r1, _0809732C @ =FUN_080976ec
	b _0809740E
	.align 2, 0
_08097320: .4byte 0x0000144C
_08097324: .4byte 0x00003AEE
_08097328: .4byte 0x00003AEB
_0809732C: .4byte FUN_080976ec
_08097330:
	ldr r0, _08097360 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0
	bl Player_EquipArmor
	adds r0, r4, #0
	bl FUN_0808bac4
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08096fa8
	b _08097474
	.align 2, 0
_08097360: .4byte 0x030046A0
_08097364:
	ldr r0, _08097418 @ =0x0000038A
	bl PlaySound_082406e0
	ldr r2, _0809741C @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	movs r2, #1
	mov r8, r2
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08097420 @ =0x00003AEE
	adds r5, r4, r0
	ldrb r2, [r5]
	ldr r1, _08097424 @ =0x00003FE0
	adds r6, r4, r1
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0809739C
	ldr r1, _08097428 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08096cac
_0809739C:
	ldr r2, _08097428 @ =0x00003AEB
	adds r7, r4, r2
	ldrb r2, [r7]
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080973B8
	ldrb r3, [r5]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08096cac
_080973B8:
	ldr r0, _0809742C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrb r5, [r5]
	cmp r0, r5
	beq _080973CE
	ldrb r7, [r7]
	cmp r0, r7
	bne _080973DA
_080973CE:
	ldr r2, _08097430 @ =0x00001ECC
	adds r1, r4, r2
	ldr r0, [r1]
	mov r2, r8
	orrs r0, r2
	str r0, [r1]
_080973DA:
	ldr r1, _08097420 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08097434 @ =0x00000F6C
	adds r2, r4, r1
	adds r0, r2, r0
	ldr r1, [r0]
	movs r3, #1
	orrs r1, r3
	str r1, [r0]
	ldr r1, _08097428 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r2, r2, r0
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r1, _08097438 @ =FUN_080977a4
_0809740E:
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
	b _08097474
	.align 2, 0
_08097418: .4byte 0x0000038A
_0809741C: .4byte 0x0000144C
_08097420: .4byte 0x00003AEE
_08097424: .4byte 0x00003FE0
_08097428: .4byte 0x00003AEB
_0809742C: .4byte 0x030046A0
_08097430: .4byte 0x00001ECC
_08097434: .4byte 0x00000F6C
_08097438: .4byte FUN_080977a4
_0809743C:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08097474
_08097446:
	ldr r2, _08097480 @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fb68
	cmp r0, #0
	beq _08097474
	ldr r1, _08097484 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _08097488 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08096af0
	adds r0, r4, #0
	bl FUN_08096a34
	adds r0, r4, #0
	bl FUN_080967c0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08096d90
_08097474:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097480: .4byte 0x00003AE8
_08097484: .4byte 0x00001464
_08097488: .4byte 0x00003AEB
