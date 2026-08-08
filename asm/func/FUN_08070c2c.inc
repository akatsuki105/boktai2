	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #0x10]
	adds r7, r2, #0
	mov ip, r3
	ldr r0, _08070CE8 @ =0x0203B400
	mov sb, r0
	ldr r6, _08070CEC @ =0x030046B8
	ldr r3, [r6]
	adds r3, #1
	ldr r2, _08070CF0 @ =0x000003FF
	mov r8, r2
	ands r3, r2
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	movs r5, #0x1f
	ands r0, r5
	ldrh r2, [r1]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08070CF4 @ =0xFFFF0000
	mov sl, r2
	ldr r4, [sp]
	ands r4, r2
	orrs r4, r0
	str r4, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	ldr r2, _08070CF8 @ =0x0000FFFF
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r3, r3, #1
	add r3, sb
	ldrh r0, [r3]
	movs r1, #3
	ands r0, r1
	adds r3, r0, #5
	ldr r2, _08070CFC @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _08070D00
	asrs r0, r0, #0xc
	b _08070D06
	.align 2, 0
_08070CE8: .4byte 0x0203B400
_08070CEC: .4byte 0x030046B8
_08070CF0: .4byte 0x000003FF
_08070CF4: .4byte 0xFFFF0000
_08070CF8: .4byte 0x0000FFFF
_08070CFC: .4byte 0x085B0A08
_08070D00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070D06:
	lsls r2, r0, #0x10
	ldr r1, _08070D28 @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #8]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _08070D2C
	asrs r0, r0, #0xc
	b _08070D32
	.align 2, 0
_08070D28: .4byte 0x0000FFFF
_08070D2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070D32:
	rsbs r3, r0, #0
	mov r0, ip
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08070D4E
	asrs r0, r0, #0xc
	b _08070D54
_08070D4E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070D54:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08070D7C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xff
	mov r2, ip
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08070D80
	asrs r0, r0, #0xc
	b _08070D86
	.align 2, 0
_08070D7C: .4byte 0xFFFF0000
_08070D80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08070D86:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08070DB0 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x10]
	mov r1, sp
	ldr r3, [sp, #0x34]
	bl FUN_08061d20
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08070DB0: .4byte 0xFFFF0000
