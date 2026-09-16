	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r3, #0
	ldr r1, _080910A4 @ =0x030044E0
	ldrh r2, [r1]
	movs r0, #0x20
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _080910AC
	ldr r0, _080910A8 @ =0x00004040
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #2
	b _080910BC
	.align 2, 0
_080910A4: .4byte 0x030044E0
_080910A8: .4byte 0x00004040
_080910AC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _080910C0
	ldr r2, _080910D8 @ =0x00004040
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #2
_080910BC:
	strh r0, [r1]
	movs r3, #1
_080910C0:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080910E0
	ldr r3, _080910DC @ =0x00004042
	adds r1, r5, r3
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	b _080910FA
	.align 2, 0
_080910D8: .4byte 0x00004040
_080910DC: .4byte 0x00004042
_080910E0:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080910F4
	ldr r7, _0809123C @ =0x00004042
	adds r1, r5, r7
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	movs r3, #1
_080910F4:
	cmp r3, #0
	bne _080910FA
	b _08091226
_080910FA:
	adds r0, r5, #0
	bl FUN_08090040
	ldr r0, _08091240 @ =0x00004040
	adds r7, r5, r0
	ldrh r1, [r7]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	ldr r2, _0809123C @ =0x00004042
	adds r6, r5, r2
	ldrh r2, [r6]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	movs r4, #2
	rsbs r4, r4, #0
	ands r2, r4
	movs r0, #0
	ldrsh r3, [r7, r0]
	mov r8, r3
	movs r3, #0
	ldrsh r0, [r6, r3]
	str r0, [sp]
	movs r0, #1
	mov r3, r8
	bl Video_GenerateBGMap
	ldrh r1, [r7]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	ldrh r2, [r6]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	ands r2, r4
	adds r0, r5, #0
	bl FUN_08090f24
	ldr r1, _08091244 @ =0x00004052
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r1, [r7]
	subs r0, r0, r1
	ldr r2, _08091248 @ =0x00002C04
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _0809124C @ =0x00004054
	adds r0, r5, r3
	ldrh r0, [r0]
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _08091250 @ =0x00002C4C
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08091190
	ldr r1, _08091254 @ =0x00004058
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r2, #0x5e
	adds r1, r5, r2
	strh r0, [r1]
	ldr r3, _08091258 @ =0x0000405A
	adds r0, r5, r3
	ldrh r0, [r0]
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r2, #2
	adds r1, r5, r2
	strh r0, [r1]
_08091190:
	mov sb, r7
	adds r2, r6, #0
	movs r7, #0x81
	lsls r7, r7, #6
	adds r3, r5, r7
	ldr r0, _0809125C @ =0x00002FAC
	adds r4, r5, r0
	movs r1, #1
	mov r8, r1
	ldr r7, _08091260 @ =0x00000F84
	mov ip, r7
	movs r6, #5
_080911A8:
	ldr r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _080911C8
	mov r7, sb
	ldrh r0, [r7]
	rsbs r0, r0, #0
	mov r7, ip
	adds r1, r3, r7
	strh r0, [r1]
	ldrh r0, [r2]
	rsbs r0, r0, #0
	ldr r7, _08091264 @ =0x00000F86
	adds r1, r3, r7
	strh r0, [r1]
_080911C8:
	adds r3, #0x60
	adds r4, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080911A8
	ldr r0, _08091268 @ =0x085ACE3C
	ldr r1, _08091240 @ =0x00004040
	adds r1, r1, r5
	mov ip, r1
	ldr r2, _0809123C @ =0x00004042
	adds r2, r2, r5
	mov r8, r2
	adds r4, r0, #0
	adds r4, #0x1c
	movs r3, #0x8a
	lsls r3, r3, #6
	adds r2, r5, r3
	ldr r7, _0809126C @ =0x000031EC
	adds r3, r5, r7
	movs r6, #7
_080911F0:
	ldr r0, [r3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0809121A
	ldrb r1, [r4]
	lsls r1, r1, #2
	mov r7, ip
	ldrh r0, [r7]
	subs r1, r1, r0
	ldr r7, _08091260 @ =0x00000F84
	adds r0, r2, r7
	strh r1, [r0]
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	mov r7, r8
	ldrh r0, [r7]
	subs r1, r1, r0
	ldr r7, _08091264 @ =0x00000F86
	adds r0, r2, r7
	strh r1, [r0]
_0809121A:
	adds r4, #4
	adds r2, #0x60
	adds r3, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080911F0
_08091226:
	adds r0, r5, #0
	bl FUN_08090120
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809123C: .4byte 0x00004042
_08091240: .4byte 0x00004040
_08091244: .4byte 0x00004052
_08091248: .4byte 0x00002C04
_0809124C: .4byte 0x00004054
_08091250: .4byte 0x00002C4C
_08091254: .4byte 0x00004058
_08091258: .4byte 0x0000405A
_0809125C: .4byte 0x00002FAC
_08091260: .4byte 0x00000F84
_08091264: .4byte 0x00000F86
_08091268: .4byte 0x085ACE3C
_0809126C: .4byte 0x000031EC
