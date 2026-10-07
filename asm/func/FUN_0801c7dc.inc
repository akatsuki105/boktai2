	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x95
	ldrb r0, [r4]
	bl FUN_080b9400
	ldrb r0, [r4]
	bl FUN_080b94cc
	ldr r0, _0801C804 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r3, [r0, r1]
	cmp r3, #0x63
	ble _0801C808
	movs r3, #0x63
	b _0801C80E
	.align 2, 0
_0801C804: .4byte 0x030046A0
_0801C808:
	cmp r3, #0
	bge _0801C80E
	movs r3, #0
_0801C80E:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #4
	movs r2, #9
	bl Video_DrawBGNumber
	movs r0, #0
	bl GetWeaponSkillLevel
	adds r3, r0, #0
	cmp r3, #0x63
	ble _0801C834
	movs r3, #0x63
	b _0801C83A
_0801C834:
	cmp r3, #0
	bge _0801C83A
	movs r3, #0
_0801C83A:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #3
	movs r2, #0xb
	bl Video_DrawBGNumber
	movs r0, #1
	bl GetWeaponSkillLevel
	adds r3, r0, #0
	cmp r3, #0x63
	ble _0801C860
	movs r3, #0x63
	b _0801C866
_0801C860:
	cmp r3, #0
	bge _0801C866
	movs r3, #0
_0801C866:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #8
	movs r2, #0xb
	bl Video_DrawBGNumber
	movs r0, #2
	bl GetWeaponSkillLevel
	adds r3, r0, #0
	cmp r3, #0x63
	ble _0801C88C
	movs r3, #0x63
	b _0801C892
_0801C88C:
	cmp r3, #0
	bge _0801C892
	movs r3, #0
_0801C892:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #3
	movs r2, #0xc
	bl Video_DrawBGNumber
	movs r0, #3
	bl GetWeaponSkillLevel
	adds r3, r0, #0
	cmp r3, #0x63
	ble _0801C8B8
	movs r3, #0x63
	b _0801C8BE
_0801C8B8:
	cmp r3, #0
	bge _0801C8BE
	movs r3, #0
_0801C8BE:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #8
	movs r2, #0xc
	bl Video_DrawBGNumber
	movs r0, #4
	bl GetWeaponSkillLevel
	adds r3, r0, #0
	cmp r3, #0x63
	ble _0801C8E4
	movs r3, #0x63
	b _0801C8EA
_0801C8E4:
	cmp r3, #0
	bge _0801C8EA
	movs r3, #0
_0801C8EA:
	movs r0, #0x21
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #3
	movs r2, #0xd
	bl Video_DrawBGNumber
	adds r0, r5, #0
	bl FUN_0801c40c
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
