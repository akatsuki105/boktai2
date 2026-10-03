	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov sl, r1
	ldr r1, _08095570 @ =0x00001E6C
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r3, #1
	ldr r0, _08095574 @ =0x00001ECC
	adds r2, r5, r0
	ldr r0, _08095578 @ =0x00001CEC
	adds r1, r5, r0
	movs r7, #3
_080954D0:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r7, #1
	cmp r7, #0
	bge _080954D0
	movs r7, #0
	movs r1, #2
	rsbs r1, r1, #0
	mov sb, r1
	movs r0, #0xf6
	lsls r0, r0, #4
	adds r2, r5, r0
	mov r8, r2
	str r0, [sp]
_080954F8:
	movs r0, #0x68
	adds r2, r7, #0
	muls r2, r0, r2
	adds r1, r5, r2
	ldr r3, _0809557C @ =0x00000D9C
	adds r0, r1, r3
	movs r6, #0
	ldrsb r6, [r0, r6]
	ldr r0, _08095580 @ =0x00000D9D
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080955F4
	adds r1, r6, #0
	adds r1, #0x24
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r3, _08095584 @ =0x00000F6C
	adds r1, r5, r3
	adds r1, r1, r0
	ldr r0, [r1]
	mov r3, sb
	ands r0, r3
	str r0, [r1]
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #5
	ldr r1, _08095588 @ =0x00001CE4
	adds r0, r0, r1
	adds r4, r5, r0
	movs r3, #0xda
	lsls r3, r3, #4
	adds r0, r5, r3
	adds r0, r0, r2
	ldr r0, [r0]
	ldrb r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	adds r1, #0xa0
	movs r3, #1
	bl MainSprite_SetPose
	mov r0, sl
	cmp r0, #0
	beq _080955A0
	ldr r1, _0809558C @ =0x00003AE8
	adds r0, r5, r1
	ldrb r0, [r0]
	asrs r0, r7
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08095594
	adds r0, r4, #0
	ldr r1, _08095590 @ =0x000002DF
	bl FUN_0808ba0c
	b _080955A8
	.align 2, 0
_08095570: .4byte 0x00001E6C
_08095574: .4byte 0x00001ECC
_08095578: .4byte 0x00001CEC
_0809557C: .4byte 0x00000D9C
_08095580: .4byte 0x00000D9D
_08095584: .4byte 0x00000F6C
_08095588: .4byte 0x00001CE4
_0809558C: .4byte 0x00003AE8
_08095590: .4byte 0x000002DF
_08095594:
	adds r0, r4, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
	b _080955A8
_080955A0:
	adds r0, r4, #0
	ldr r1, _080955E4 @ =0x000002DF
	bl FUN_0808ba0c
_080955A8:
	ldr r2, _080955E8 @ =0x00000F6C
	adds r1, r5, r2
	ldr r3, [sp]
	adds r1, r1, r3
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	ldr r2, _080955EC @ =0x00000F84
	add r2, r8
	movs r0, #0x68
	muls r0, r7, r0
	adds r0, r5, r0
	ldr r3, _080955F0 @ =0x00000D9D
	adds r0, r0, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r5, r0
	ldr r1, _080955EC @ =0x00000F84
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	b _08095658
	.align 2, 0
_080955E4: .4byte 0x000002DF
_080955E8: .4byte 0x00000F6C
_080955EC: .4byte 0x00000F84
_080955F0: .4byte 0x00000D9D
_080955F4:
	cmp r6, #3
	bne _08095658
	ldr r2, _08095634 @ =0x00001E0C
	adds r1, r5, r2
	ldr r0, [r1]
	mov r3, sb
	ands r0, r3
	str r0, [r1]
	ldr r0, _08095638 @ =0x00001E04
	adds r4, r5, r0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r1, #0xa0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetPose
	mov r1, sl
	cmp r1, #0
	beq _08095650
	ldr r2, _0809563C @ =0x00003AE8
	adds r0, r5, r2
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08095644
	adds r0, r4, #0
	ldr r1, _08095640 @ =0x000002DF
	bl FUN_0808ba0c
	b _08095658
	.align 2, 0
_08095634: .4byte 0x00001E0C
_08095638: .4byte 0x00001E04
_0809563C: .4byte 0x00003AE8
_08095640: .4byte 0x000002DF
_08095644:
	adds r0, r4, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
	b _08095658
_08095650:
	adds r0, r4, #0
	ldr r1, _080956B0 @ =0x000002DF
	bl FUN_0808ba0c
_08095658:
	ldr r3, _080956B4 @ =0x00000D98
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r7, r0
	bne _0809568E
	ldr r0, _080956B8 @ =0x00001E6C
	adds r1, r5, r0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	ldr r3, _080956BC @ =0x00001E84
	adds r2, r5, r3
	adds r1, r6, #0
	adds r1, #0x24
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r5, r0
	ldr r1, _080956C0 @ =0x00000F84
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_0809568E:
	movs r2, #0x60
	add r8, r2
	ldr r3, [sp]
	adds r3, #0x60
	str r3, [sp]
	adds r7, #1
	cmp r7, #3
	bgt _080956A0
	b _080954F8
_080956A0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080956B0: .4byte 0x000002DF
_080956B4: .4byte 0x00000D98
_080956B8: .4byte 0x00001E6C
_080956BC: .4byte 0x00001E84
_080956C0: .4byte 0x00000F84
