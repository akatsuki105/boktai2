	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0801b664
FUN_0801b664: @ 0x0801B664
	ldr r1, _0801B66C @ =0x03000098
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801B66C: .4byte 0x03000098

	thumb_func_start FUN_0801b670
FUN_0801b670: @ 0x0801B670
	ldr r1, _0801B680 @ =0x03003584
	ldr r2, _0801B684 @ =0x000002DF
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	adds r0, r1, #0
	bx lr
	.align 2, 0
_0801B680: .4byte 0x03003584
_0801B684: .4byte 0x000002DF

	thumb_func_start FUN_0801b688
FUN_0801b688: @ 0x0801B688
	push {lr}
	adds r3, r0, #0
	adds r0, r1, #0
	adds r0, #0x24
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r3, r3, r2
	ldrb r2, [r1]
	adds r1, r3, #0
	movs r3, #0
	bl Sprite_SetSprite
	pop {r0}
	bx r0

	thumb_func_start FUN_0801b6a4
FUN_0801b6a4: @ 0x0801B6A4
	push {lr}
	bl GetWeaponSkillLevel
	movs r1, #0xa
	bl Div
	adds r0, #6
	cmp r0, #5
	bgt _0801B6BA
	movs r0, #6
	b _0801B6C0
_0801B6BA:
	cmp r0, #0xf
	ble _0801B6C0
	movs r0, #0xf
_0801B6C0:
	pop {r1}
	bx r1

	thumb_func_start weapon_0801b6c4
weapon_0801b6c4: @ 0x0801B6C4
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r7, r1, #0
	ldr r6, _0801B70C @ =0x08DA9E8C
	movs r4, #0
	movs r5, #0
	adds r2, r6, #0
	subs r2, #0x24
	movs r1, #0x41
_0801B6D6:
	ldrb r0, [r2, #1]
	cmp r0, r3
	bne _0801B6F2
	ldrb r0, [r2, #2]
	cmp r0, #4
	beq _0801B6F2
	ldrb r0, [r2, #3]
	cmp r0, r7
	bgt _0801B6F2
	cmp r0, r4
	blt _0801B6F2
	adds r6, r2, #0
	adds r4, r0, #0
	movs r5, #1
_0801B6F2:
	adds r2, #0x24
	subs r1, #1
	cmp r1, #0
	bge _0801B6D6
	cmp r5, #0
	bne _0801B728
	cmp r3, #1
	beq _0801B710
	cmp r3, #1
	ble _0801B720
	cmp r3, #2
	beq _0801B718
	b _0801B720
	.align 2, 0
_0801B70C: .4byte 0x08DA9E8C
_0801B710:
	ldr r0, _0801B714 @ =0x08DAA1C8
	b _0801B72A
	.align 2, 0
_0801B714: .4byte 0x08DAA1C8
_0801B718:
	ldr r0, _0801B71C @ =0x08DAA474
	b _0801B72A
	.align 2, 0
_0801B71C: .4byte 0x08DAA474
_0801B720:
	ldr r0, _0801B724 @ =0x08DA9F1C
	b _0801B72A
	.align 2, 0
_0801B724: .4byte 0x08DA9F1C
_0801B728:
	adds r0, r6, #0
_0801B72A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801b730
FUN_0801b730: @ 0x0801B730
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r6, _0801B768 @ =0x00000978
	add r6, r8
	ldr r7, _0801B76C @ =0x000009FC
	add r7, r8
	movs r5, #0xa8
	lsls r5, r5, #4
	add r5, r8
	ldrb r1, [r6, #1]
	ldrb r2, [r7, #1]
	cmp r1, r2
	bne _0801B804
	ldrb r1, [r6]
	adds r3, r1, #0
	ldrb r1, [r7]
	cmp r3, r1
	bne _0801B7B0
	ldrb r1, [r6, #3]
	ldrb r2, [r7, #3]
	adds r1, r1, r2
	asrs r4, r1, #1
	cmp r4, #0x63
	ble _0801B770
	movs r4, #0x63
	b _0801B776
	.align 2, 0
_0801B768: .4byte 0x00000978
_0801B76C: .4byte 0x000009FC
_0801B770:
	cmp r4, #0
	bgt _0801B776
	movs r4, #1
_0801B776:
	strb r3, [r5]
	ldrb r1, [r6, #1]
	strb r1, [r5, #1]
	ldrb r1, [r6, #2]
	strb r1, [r5, #2]
	strb r4, [r5, #3]
	ldrb r1, [r6, #4]
	strb r1, [r5, #4]
	ldr r3, _0801B7AC @ =0x08DA9E68
	ldrb r2, [r5]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrh r1, [r1, #6]
	movs r4, #0
	strh r1, [r5, #6]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #5]
	strb r1, [r5, #5]
	mov r1, r8
	adds r1, #0x43
	strb r4, [r1]
	b _0801B8B2
	.align 2, 0
_0801B7AC: .4byte 0x08DA9E68
_0801B7B0:
	ldrb r0, [r6, #3]
	ldrb r1, [r7, #3]
	adds r0, r0, r1
	asrs r0, r0, #1
	adds r4, r0, #6
	cmp r4, #0x63
	ble _0801B7C2
	movs r4, #0x63
	b _0801B7C8
_0801B7C2:
	cmp r4, #0
	bgt _0801B7C8
	movs r4, #1
_0801B7C8:
	ldrb r0, [r6, #1]
	adds r1, r4, #0
	bl weapon_0801b6c4
	adds r2, r0, #0
	ldrb r1, [r2]
	strb r1, [r5]
	ldrb r1, [r2, #1]
	strb r1, [r5, #1]
	ldrb r1, [r2, #2]
	strb r1, [r5, #2]
	strb r4, [r5, #3]
	ldrb r1, [r2, #4]
	strb r1, [r5, #4]
	ldrh r1, [r2, #6]
	strh r1, [r5, #6]
	ldr r3, _0801B800 @ =0x08DA9E68
	ldrb r2, [r2]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #5]
	strb r1, [r5, #5]
	mov r2, r8
	adds r2, #0x43
	movs r1, #1
	b _0801B8B0
	.align 2, 0
_0801B800: .4byte 0x08DA9E68
_0801B804:
	ldr r2, _0801B834 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801B838 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0801B83C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xd
	bl Mod
	ldrb r1, [r6, #3]
	ldrb r2, [r7, #3]
	adds r1, r1, r2
	asrs r1, r1, #1
	subs r1, #6
	adds r4, r1, r0
	cmp r4, #0x63
	ble _0801B840
	movs r4, #0x63
	b _0801B846
	.align 2, 0
_0801B834: .4byte 0x030046B8
_0801B838: .4byte 0x000003FF
_0801B83C: .4byte 0x0203B400
_0801B840:
	cmp r4, #0
	bgt _0801B846
	movs r4, #1
_0801B846:
	ldrb r0, [r6, #1]
	cmp r0, #0
	bne _0801B858
	ldrb r0, [r7, #1]
	movs r1, #1
	cmp r0, #1
	bne _0801B87A
	movs r1, #2
	b _0801B87A
_0801B858:
	cmp r0, #1
	bne _0801B868
	ldrb r0, [r7, #1]
	movs r1, #0
	cmp r0, #0
	bne _0801B87A
	movs r1, #2
	b _0801B87A
_0801B868:
	cmp r0, #2
	bne _0801B878
	ldrb r0, [r7, #1]
	movs r1, #0
	cmp r0, #0
	bne _0801B87A
	movs r1, #1
	b _0801B87A
_0801B878:
	movs r1, #0
_0801B87A:
	adds r0, r1, #0
	adds r1, r4, #0
	bl weapon_0801b6c4
	adds r2, r0, #0
	ldrb r1, [r2]
	strb r1, [r5]
	ldrb r1, [r2, #1]
	strb r1, [r5, #1]
	ldrb r1, [r2, #2]
	strb r1, [r5, #2]
	strb r4, [r5, #3]
	ldrb r1, [r2, #4]
	strb r1, [r5, #4]
	ldrh r1, [r2, #6]
	strh r1, [r5, #6]
	ldr r3, _0801B8CC @ =0x08DA9E68
	ldrb r2, [r2]
	lsls r1, r2, #3
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	ldrb r1, [r1, #5]
	strb r1, [r5, #5]
	mov r2, r8
	adds r2, #0x43
	movs r1, #2
_0801B8B0:
	strb r1, [r2]
_0801B8B2:
	movs r3, #8
	ldrsh r1, [r6, r3]
	movs r3, #8
	ldrsh r2, [r7, r3]
	adds r1, r1, r2
	asrs r1, r1, #1
	strh r1, [r5, #8]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801B8CC: .4byte 0x08DA9E68

	thumb_func_start FUN_0801b8d0
FUN_0801b8d0: @ 0x0801B8D0
	movs r2, #0
	str r2, [r0, #0x44]
	adds r3, r0, #0
	adds r3, #0x3c
	movs r2, #1
	strb r2, [r3]
	ldr r2, _0801B8E4 @ =0x00001304
	adds r0, r0, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_0801B8E4: .4byte 0x00001304

	thumb_func_start FUN_0801b8e8
FUN_0801b8e8: @ 0x0801B8E8
	push {lr}
	adds r1, r0, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801B8F8
	movs r0, #0
	b _0801B8FE
_0801B8F8:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_0801B8FE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801b904
FUN_0801b904: @ 0x0801B904
	push {lr}
	ldrb r0, [r1, #2]
	cmp r0, #1
	beq _0801B924
	cmp r0, #1
	bgt _0801B916
	cmp r0, #0
	beq _0801B920
	b _0801B930
_0801B916:
	cmp r0, #2
	beq _0801B928
	cmp r0, #3
	beq _0801B92C
	b _0801B930
_0801B920:
	movs r0, #0x14
	b _0801B932
_0801B924:
	movs r0, #0x28
	b _0801B932
_0801B928:
	movs r0, #0x3c
	b _0801B932
_0801B92C:
	movs r0, #0x50
	b _0801B932
_0801B930:
	movs r0, #0
_0801B932:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801b938
FUN_0801b938: @ 0x0801B938
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r5, r0
	ldr r0, _0801B96C @ =0x00000978
	adds r1, r5, r0
	adds r0, #0x84
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801B95E
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #9
	bls _0801B974
_0801B95E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0
	str r0, [r1]
	ldr r0, _0801B970 @ =0x08DA9F1C
	b _0801BA52
	.align 2, 0
_0801B96C: .4byte 0x00000978
_0801B970: .4byte 0x08DA9F1C
_0801B974:
	ldrb r1, [r1]
	ldrb r0, [r2]
	cmp r1, #0x11
	bne _0801B980
	cmp r0, #0x12
	beq _0801B988
_0801B980:
	cmp r0, #0x11
	bne _0801B9A4
	cmp r1, #0x12
	bne _0801B9A4
_0801B988:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	ble _0801B9A4
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xc8
	str r0, [r1]
	ldr r0, _0801B9A0 @ =0x08DAA114
	b _0801BA52
	.align 2, 0
_0801B9A0: .4byte 0x08DAA114
_0801B9A4:
	ldrb r0, [r6, #1]
	bl GetWeaponSkillLevel
	adds r4, r0, #0
	ldr r2, _0801B9E0 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0801B9E4 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0801B9E8 @ =0x0203B400
	adds r1, r1, r0
	ldr r0, _0801B9EC @ =0x03002CF0
	ldr r0, [r0]
	lsrs r0, r0, #2
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0x64
	bl Mod
	adds r2, r0, #0
	asrs r4, r4, #3
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r1, [r0]
	cmp r1, #0xe
	bhi _0801B9F0
	movs r4, #0
	b _0801B9FC
	.align 2, 0
_0801B9E0: .4byte 0x030046B8
_0801B9E4: .4byte 0x000003FF
_0801B9E8: .4byte 0x0203B400
_0801B9EC: .4byte 0x03002CF0
_0801B9F0:
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, r1
	bne _0801B9FC
	lsls r4, r4, #1
_0801B9FC:
	movs r0, #0
	cmp r2, r4
	bgt _0801BA04
	movs r0, #1
_0801BA04:
	cmp r0, #0
	beq _0801BA50
	ldrb r0, [r6, #2]
	cmp r0, #2
	beq _0801BA30
	cmp r0, #2
	bgt _0801BA18
	cmp r0, #1
	beq _0801BA1E
	b _0801BA50
_0801BA18:
	cmp r0, #3
	beq _0801BA40
	b _0801BA50
_0801BA1E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x50
	str r0, [r1]
	ldr r0, _0801BA2C @ =0x08DA9FD0
	b _0801BA52
	.align 2, 0
_0801BA2C: .4byte 0x08DA9FD0
_0801BA30:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x78
	str r0, [r1]
	ldr r0, _0801BA3C @ =0x08DAA084
	b _0801BA52
	.align 2, 0
_0801BA3C: .4byte 0x08DAA084
_0801BA40:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xa0
	str r0, [r1]
	ldr r0, _0801BA4C @ =0x08DAA0F0
	b _0801BA52
	.align 2, 0
_0801BA4C: .4byte 0x08DAA0F0
_0801BA50:
	movs r0, #0
_0801BA52:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801ba58
FUN_0801ba58: @ 0x0801BA58
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r5, r0
	ldr r0, _0801BA8C @ =0x00000978
	adds r1, r5, r0
	adds r0, #0x84
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801BA7E
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #9
	bls _0801BA94
_0801BA7E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0
	str r0, [r1]
	ldr r0, _0801BA90 @ =0x08DAA1C8
	b _0801BB72
	.align 2, 0
_0801BA8C: .4byte 0x00000978
_0801BA90: .4byte 0x08DAA1C8
_0801BA94:
	ldrb r1, [r1]
	ldrb r0, [r2]
	cmp r1, #0x24
	bne _0801BAA0
	cmp r0, #0x25
	beq _0801BAA8
_0801BAA0:
	cmp r0, #0x24
	bne _0801BAC4
	cmp r1, #0x25
	bne _0801BAC4
_0801BAA8:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	ble _0801BAC4
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xc8
	str r0, [r1]
	ldr r0, _0801BAC0 @ =0x08DAA3C0
	b _0801BB72
	.align 2, 0
_0801BAC0: .4byte 0x08DAA3C0
_0801BAC4:
	ldrb r0, [r6, #1]
	bl GetWeaponSkillLevel
	adds r4, r0, #0
	ldr r2, _0801BB00 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0801BB04 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0801BB08 @ =0x0203B400
	adds r1, r1, r0
	ldr r0, _0801BB0C @ =0x03002CF0
	ldr r0, [r0]
	lsrs r0, r0, #2
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0x64
	bl Mod
	adds r2, r0, #0
	asrs r4, r4, #3
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r1, [r0]
	cmp r1, #0xe
	bhi _0801BB10
	movs r4, #0
	b _0801BB1C
	.align 2, 0
_0801BB00: .4byte 0x030046B8
_0801BB04: .4byte 0x000003FF
_0801BB08: .4byte 0x0203B400
_0801BB0C: .4byte 0x03002CF0
_0801BB10:
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, r1
	bne _0801BB1C
	lsls r4, r4, #1
_0801BB1C:
	movs r0, #0
	cmp r2, r4
	bgt _0801BB24
	movs r0, #1
_0801BB24:
	cmp r0, #0
	beq _0801BB70
	ldrb r0, [r6, #2]
	cmp r0, #2
	beq _0801BB50
	cmp r0, #2
	bgt _0801BB38
	cmp r0, #1
	beq _0801BB3E
	b _0801BB70
_0801BB38:
	cmp r0, #3
	beq _0801BB60
	b _0801BB70
_0801BB3E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x50
	str r0, [r1]
	ldr r0, _0801BB4C @ =0x08DAA27C
	b _0801BB72
	.align 2, 0
_0801BB4C: .4byte 0x08DAA27C
_0801BB50:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x78
	str r0, [r1]
	ldr r0, _0801BB5C @ =0x08DAA330
	b _0801BB72
	.align 2, 0
_0801BB5C: .4byte 0x08DAA330
_0801BB60:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xa0
	str r0, [r1]
	ldr r0, _0801BB6C @ =0x08DAA39C
	b _0801BB72
	.align 2, 0
_0801BB6C: .4byte 0x08DAA39C
_0801BB70:
	movs r0, #0
_0801BB72:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801bb78
FUN_0801bb78: @ 0x0801BB78
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r5, r0
	ldr r0, _0801BBAC @ =0x00000978
	adds r1, r5, r0
	adds r0, #0x84
	adds r2, r5, r0
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r0, [r0]
	cmp r0, #0
	beq _0801BB9E
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #9
	bls _0801BBB4
_0801BB9E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0
	str r0, [r1]
	ldr r0, _0801BBB0 @ =0x08DAA474
	b _0801BC92
	.align 2, 0
_0801BBAC: .4byte 0x00000978
_0801BBB0: .4byte 0x08DAA474
_0801BBB4:
	ldrb r1, [r1]
	ldrb r0, [r2]
	cmp r1, #0x37
	bne _0801BBC0
	cmp r0, #0x38
	beq _0801BBC8
_0801BBC0:
	cmp r0, #0x37
	bne _0801BBE4
	cmp r1, #0x38
	bne _0801BBE4
_0801BBC8:
	adds r0, r5, #0
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #9
	ble _0801BBE4
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xc8
	str r0, [r1]
	ldr r0, _0801BBE0 @ =0x08DAA66C
	b _0801BC92
	.align 2, 0
_0801BBE0: .4byte 0x08DAA66C
_0801BBE4:
	ldrb r0, [r6, #1]
	bl GetWeaponSkillLevel
	adds r4, r0, #0
	ldr r2, _0801BC20 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0801BC24 @ =0x000003FF
	ands r1, r0
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0801BC28 @ =0x0203B400
	adds r1, r1, r0
	ldr r0, _0801BC2C @ =0x03002CF0
	ldr r0, [r0]
	lsrs r0, r0, #2
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0x64
	bl Mod
	adds r2, r0, #0
	asrs r4, r4, #3
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r1, [r0]
	cmp r1, #0xe
	bhi _0801BC30
	movs r4, #0
	b _0801BC3C
	.align 2, 0
_0801BC20: .4byte 0x030046B8
_0801BC24: .4byte 0x000003FF
_0801BC28: .4byte 0x0203B400
_0801BC2C: .4byte 0x03002CF0
_0801BC30:
	adds r0, r5, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, r1
	bne _0801BC3C
	lsls r4, r4, #1
_0801BC3C:
	movs r0, #0
	cmp r2, r4
	bgt _0801BC44
	movs r0, #1
_0801BC44:
	cmp r0, #0
	beq _0801BC90
	ldrb r0, [r6, #2]
	cmp r0, #2
	beq _0801BC70
	cmp r0, #2
	bgt _0801BC58
	cmp r0, #1
	beq _0801BC5E
	b _0801BC90
_0801BC58:
	cmp r0, #3
	beq _0801BC80
	b _0801BC90
_0801BC5E:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x50
	str r0, [r1]
	ldr r0, _0801BC6C @ =0x08DAA528
	b _0801BC92
	.align 2, 0
_0801BC6C: .4byte 0x08DAA528
_0801BC70:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0x78
	str r0, [r1]
	ldr r0, _0801BC7C @ =0x08DAA5DC
	b _0801BC92
	.align 2, 0
_0801BC7C: .4byte 0x08DAA5DC
_0801BC80:
	adds r1, r5, #0
	adds r1, #0x98
	movs r0, #0xa0
	str r0, [r1]
	ldr r0, _0801BC8C @ =0x08DAA648
	b _0801BC92
	.align 2, 0
_0801BC8C: .4byte 0x08DAA648
_0801BC90:
	movs r0, #0
_0801BC92:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801bc98
FUN_0801bc98: @ 0x0801BC98
	push {lr}
	adds r1, r0, #0
	movs r2, #0xa8
	lsls r2, r2, #4
	adds r0, r1, r2
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _0801BCC0
	cmp r0, #1
	bgt _0801BCB2
	cmp r0, #0
	beq _0801BCB8
	b _0801BCD0
_0801BCB2:
	cmp r0, #2
	beq _0801BCC8
	b _0801BCD0
_0801BCB8:
	adds r0, r1, #0
	bl FUN_0801b938
	b _0801BCD2
_0801BCC0:
	adds r0, r1, #0
	bl FUN_0801ba58
	b _0801BCD2
_0801BCC8:
	adds r0, r1, #0
	bl FUN_0801bb78
	b _0801BCD2
_0801BCD0:
	movs r0, #0
_0801BCD2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801bcd8
FUN_0801bcd8: @ 0x0801BCD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r7, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r0, r0, r7
	mov sl, r0
	mov r5, sl
	movs r1, #0
	str r1, [sp, #0x48]
	adds r0, r7, #0
	mov r1, sl
	bl FUN_0801b904
	adds r1, r7, #0
	adds r1, #0x98
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0801bc98
	cmp r0, #0
	beq _0801BD1A
	mov r1, sl
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
_0801BD1A:
	adds r0, r7, #0
	adds r0, #0xa0
	ldr r1, [r0]
	str r0, [sp, #0x4c]
	movs r0, #0x41
	adds r0, r0, r7
	mov sb, r0
	movs r2, #0x42
	adds r2, r2, r7
	mov r8, r2
	cmp r1, #4
	bhi _0801BD34
	b _0801BE80
_0801BD34:
	adds r4, r7, #0
	adds r4, #0xa8
	ldr r0, [r4]
	cmp r0, #0
	bne _0801BD40
	b _0801BE80
_0801BD40:
	mov r3, sl
	ldrb r0, [r3, #1]
	bl GetWeaponSkillLevel
	asrs r0, r0, #2
	ldr r2, [r4]
	lsls r1, r2, #1
	adds r1, r1, r2
	adds r0, r0, r1
	adds r1, r7, #0
	adds r1, #0xb0
	ldr r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	subs r6, r0, r1
	cmp r6, #0x64
	ble _0801BD66
	movs r6, #0x64
	b _0801BD6C
_0801BD66:
	cmp r6, #0
	bge _0801BD6C
	movs r6, #0
_0801BD6C:
	ldr r2, _0801BDA0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801BDA4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _0801BDA8 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, r6
	bgt _0801BDB0
	ldrb r0, [r5]
	bl FUN_0823d414
	ldrb r1, [r0, #0x18]
	cmp r1, #0
	beq _0801BDAC
	movs r1, #1
	str r1, [sp, #0x48]
	ldr r0, [r0, #0x18]
	str r0, [r5, #0x18]
	b _0801BDB4
	.align 2, 0
_0801BDA0: .4byte 0x030046B8
_0801BDA4: .4byte 0x000003FF
_0801BDA8: .4byte 0x0203B400
_0801BDAC:
	strb r1, [r5, #0x18]
	b _0801BDB4
_0801BDB0:
	movs r0, #0
	strb r0, [r5, #0x18]
_0801BDB4:
	ldr r2, _0801BDF8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801BDFC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0801BE00 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, r6
	bgt _0801BE0A
	adds r4, r7, #0
	adds r4, #0x41
	ldrb r0, [r4]
	mov r1, sp
	bl FUN_08242b14
	add r0, sp, #0x18
	ldrb r0, [r0]
	mov sb, r4
	cmp r0, #0
	beq _0801BE04
	ldrb r3, [r5, #0x18]
	cmp r0, r3
	beq _0801BE04
	ldr r0, [sp, #0x18]
	str r0, [r5, #0x1c]
	movs r4, #1
	str r4, [sp, #0x48]
	b _0801BE14
	.align 2, 0
_0801BDF8: .4byte 0x030046B8
_0801BDFC: .4byte 0x000003FF
_0801BE00: .4byte 0x0203B400
_0801BE04:
	movs r0, #0
	strb r0, [r5, #0x1c]
	b _0801BE14
_0801BE0A:
	movs r0, #0
	strb r0, [r5, #0x1c]
	movs r0, #0x41
	adds r0, r0, r7
	mov sb, r0
_0801BE14:
	ldr r2, _0801BE5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801BE60 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801BE64 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, r6
	bgt _0801BE72
	adds r4, r7, #0
	adds r4, #0x42
	ldrb r0, [r4]
	add r1, sp, #0x24
	bl FUN_08242b14
	add r0, sp, #0x3c
	ldrb r0, [r0]
	mov r8, r4
	cmp r0, #0
	beq _0801BE68
	ldrb r2, [r5, #0x18]
	cmp r0, r2
	beq _0801BE68
	ldrb r3, [r5, #0x1c]
	cmp r0, r3
	beq _0801BE68
	ldr r0, [sp, #0x3c]
	str r0, [r5, #0x20]
	b _0801BF16
	.align 2, 0
_0801BE5C: .4byte 0x030046B8
_0801BE60: .4byte 0x000003FF
_0801BE64: .4byte 0x0203B400
_0801BE68:
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #0
	strb r0, [r1]
	b _0801BE80
_0801BE72:
	adds r1, r5, #0
	adds r1, #0x20
	movs r0, #0
	strb r0, [r1]
	movs r4, #0x42
	adds r4, r4, r7
	mov r8, r4
_0801BE80:
	ldr r0, [sp, #0x48]
	cmp r0, #0
	bne _0801BF16
	ldr r1, [sp, #0x4c]
	ldr r0, [r1]
	movs r6, #2
	cmp r0, #9
	bls _0801BEAA
	movs r6, #3
	cmp r0, #0xe
	bls _0801BEAA
	movs r6, #8
	cmp r0, #0x13
	bls _0801BEAA
	movs r6, #0xf
	cmp r0, #0x18
	bls _0801BEAA
	movs r6, #0x28
	cmp r0, #0x1d
	bhi _0801BEAA
	movs r6, #0x19
_0801BEAA:
	ldrb r0, [r5, #1]
	bl FUN_0801b6a4
	adds r4, r0, #0
	ldr r2, [sp, #0x4c]
	ldr r1, [r2]
	movs r0, #0x64
	muls r0, r1, r0
	adds r1, r7, #0
	adds r1, #0xa4
	ldr r1, [r1]
	subs r0, r0, r1
	adds r1, r6, #0
	bl Div
	subs r4, r4, r0
	movs r3, #8
	ldrsh r0, [r5, r3]
	adds r4, r4, r0
	asrs r4, r4, #1
	ldr r1, [sp, #0x4c]
	ldr r0, [r1]
	cmp r0, #4
	bhi _0801BEE0
	movs r4, #0xa
	rsbs r4, r4, #0
	b _0801BEEA
_0801BEE0:
	cmp r0, #9
	bhi _0801BEEA
	cmp r4, #0
	ble _0801BEEA
	movs r4, #0
_0801BEEA:
	movs r0, #0xa
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0801BEF6
	strh r0, [r5, #8]
	b _0801BF02
_0801BEF6:
	cmp r4, #0xa
	ble _0801BF00
	movs r0, #0xa
	strh r0, [r5, #8]
	b _0801BF02
_0801BF00:
	strh r4, [r5, #8]
_0801BF02:
	adds r6, r5, #0
	adds r6, #0xc
	movs r1, #0
	adds r0, r5, #0
	adds r0, #8
_0801BF0C:
	strb r1, [r0, #0x18]
	subs r0, #4
	cmp r0, r5
	bge _0801BF0C
	b _0801BF1E
_0801BF16:
	movs r0, #0
	strh r0, [r5, #8]
	adds r6, r5, #0
	adds r6, #0xc
_0801BF1E:
	mov r2, sb
	ldrb r0, [r2]
	bl FUN_08242c08
	mov r3, r8
	ldrb r0, [r3]
	bl FUN_08242c08
	ldr r4, _0801BF80 @ =0x030046A0
	ldr r1, [r4]
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r1, r1, r0
	adds r0, r6, #0
	movs r2, #0xa
	bl FUN_08230ab0
	movs r0, #0
	strb r0, [r5, #0x16]
	adds r0, r5, #0
	bl FUN_08242b88
	ldr r1, [r4]
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r1, r1, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, [r4]
	adds r2, r0, r2
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, _0801BF84 @ =0x0000270F
	cmp r0, r1
	ble _0801BF68
	strh r1, [r2]
_0801BF68:
	adds r0, r7, #0
	mov r1, sl
	bl FUN_0801b688
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801BF80: .4byte 0x030046A0
_0801BF84: .4byte 0x0000270F

	thumb_func_start FUN_0801bf88
FUN_0801bf88: @ 0x0801BF88
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r0, #0x3d
	ldrb r1, [r0]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r5, r4, r0
	ldr r3, _0801BFEC @ =0x00001308
	adds r6, r4, r3
	ldr r0, [r6]
	bl FUN_080478f0
	adds r1, r4, #0
	adds r1, #0xbc
	adds r0, r5, #0
	bl FUN_08094d1c
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801BFF4
	ldr r1, [r6]
	adds r0, r5, #0
	bl FUN_08094d48
	adds r0, r5, #0
	bl FUN_08094e70
	adds r2, r0, #0
	ldr r1, _0801BFF0 @ =0x00000DA4
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r0, #8]
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r1, r4, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl Sprite_SetSprite
	b _0801C010
	.align 2, 0
_0801BFEC: .4byte 0x00001308
_0801BFF0: .4byte 0x00000DA4
_0801BFF4:
	cmp r7, #0
	bne _0801BFFE
	bl FUN_08049e5c
	b _0801C004
_0801BFFE:
	adds r0, r7, #0
	bl FUN_08049e30
_0801C004:
	ldr r1, _0801C018 @ =0x00000DA4
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
_0801C010:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801C018: .4byte 0x00000DA4

	thumb_func_start FUN_0801c01c
FUN_0801c01c: @ 0x0801C01C
	push {r4, r5, lr}
	sub sp, #0x30
	adds r3, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r3, r0
	ldrb r0, [r1]
	str r0, [sp]
	ldrb r0, [r1, #1]
	str r0, [sp, #4]
	ldrb r0, [r1, #2]
	str r0, [sp, #8]
	ldrb r0, [r1, #3]
	str r0, [sp, #0xc]
	movs r2, #8
	ldrsh r0, [r1, r2]
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r5, [sp, #0x28]
	add r4, sp, #0x28
	ldr r0, _0801C070 @ =0x00000A98
	adds r1, r3, r0
	movs r2, #2
_0801C04C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0801C058
	ldr r0, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x14]
_0801C058:
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _0801C04C
	adds r0, r3, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0x63
	ble _0801C074
	movs r0, #0x63
	b _0801C07A
	.align 2, 0
_0801C070: .4byte 0x00000A98
_0801C074:
	cmp r0, #0
	bge _0801C07A
	movs r0, #0
_0801C07A:
	str r0, [sp, #0x18]
	adds r0, r3, #0
	adds r0, #0xac
	ldr r0, [r0]
	cmp r0, #0x63
	ble _0801C08A
	movs r0, #0x63
	b _0801C090
_0801C08A:
	cmp r0, #0
	bge _0801C090
	movs r0, #0
_0801C090:
	str r0, [sp, #0x1c]
	adds r0, r3, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0x63
	ble _0801C0A0
	movs r0, #0x63
	b _0801C0A6
_0801C0A0:
	cmp r0, #0
	bge _0801C0A6
	movs r0, #0
_0801C0A6:
	str r0, [sp, #0x20]
	adds r0, r3, #0
	adds r0, #0x98
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r0, _0801C0D4 @ =0xFFFF0000
	ands r0, r5
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	mov r2, sp
	str r2, [r4, #4]
	adds r0, r3, #0
	adds r0, #0xba
	ldrh r0, [r0]
	adds r1, r4, #0
	bl Script_ExecById
	add sp, #0x30
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801C0D4: .4byte 0xFFFF0000

	thumb_func_start FUN_0801c0d8
FUN_0801c0d8: @ 0x0801C0D8
	push {lr}
	cmp r1, #1
	beq _0801C0F8
	cmp r1, #1
	bgt _0801C0E8
	cmp r1, #0
	beq _0801C0EE
	b _0801C10A
_0801C0E8:
	cmp r1, #2
	beq _0801C104
	b _0801C10A
_0801C0EE:
	movs r0, #0xe5
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0801C10A
_0801C0F8:
	ldr r0, _0801C100 @ =0x00000395
	bl PlaySound_082406e0
	b _0801C10A
	.align 2, 0
_0801C100: .4byte 0x00000395
_0801C104:
	ldr r0, _0801C110 @ =0x00000396
	bl PlaySound_082406e0
_0801C10A:
	pop {r0}
	bx r0
	.align 2, 0
_0801C110: .4byte 0x00000396

	thumb_func_start FUN_0801c114
FUN_0801c114: @ 0x0801C114
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _0801C174 @ =0x0000C091
	ldr r1, _0801C178 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x48]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0801C17C @ =0x000092B3
	ldr r1, _0801C180 @ =0x0000A41A
	bl GetFile
	adds r1, r0, #0
	adds r0, #0x14
	str r0, [r5, #0x4c]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, _0801C184 @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
	movs r0, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801C174: .4byte 0x0000C091
_0801C178: .4byte 0x00009F57
_0801C17C: .4byte 0x000092B3
_0801C180: .4byte 0x0000A41A
_0801C184: .4byte 0x030043F0

	thumb_func_start FUN_0801c188
FUN_0801c188: @ 0x0801C188
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0801C1FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801C1C0
	adds r1, r4, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #1
	bne _0801C1C0
	movs r2, #0
	strb r2, [r1]
	ldr r1, _0801C200 @ =0x00000BC4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xf8
	str r2, [sp]
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xdc
	bl PlaySound_082406e0
_0801C1C0:
	ldr r0, _0801C1FC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801C1F2
	adds r1, r4, #0
	adds r1, #0x40
	ldrb r2, [r1]
	cmp r2, #0
	bne _0801C1F2
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0801C200 @ =0x00000BC4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xf8
	str r2, [sp]
	movs r2, #5
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xdc
	bl PlaySound_082406e0
_0801C1F2:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C1FC: .4byte 0x030044E0
_0801C200: .4byte 0x00000BC4

	thumb_func_start FUN_0801c204
FUN_0801c204: @ 0x0801C204
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801C258 @ =0x05000002
	bl CpuSet
	mov r8, r4
	movs r7, #0
	ldr r0, _0801C25C @ =0x00000B04
	adds r4, r6, r0
	movs r5, #2
_0801C228:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xf8
	movs r2, #0x3c
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C228
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C258: .4byte 0x05000002
_0801C25C: .4byte 0x00000B04

	thumb_func_start FUN_0801c260
FUN_0801c260: @ 0x0801C260
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801C2B4 @ =0x05000002
	bl CpuSet
	mov r8, r4
	movs r7, #0
	ldr r0, _0801C2B8 @ =0x00000C24
	adds r4, r6, r0
	movs r5, #3
_0801C284:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xf8
	movs r2, #0x41
	movs r3, #0x31
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C284
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C2B4: .4byte 0x05000002
_0801C2B8: .4byte 0x00000C24

	thumb_func_start FUN_0801c2bc
FUN_0801c2bc: @ 0x0801C2BC
	push {lr}
	sub sp, #0x18
	adds r1, r0, #0
	ldr r2, _0801C2F8 @ =0xFFFF0000
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r2, _0801C2FC @ =0x00000DA4
	adds r0, r1, r2
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r1, r2
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0xd0
	movs r3, #0x11
	bl FUN_0822f3fc
	add sp, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0801C2F8: .4byte 0xFFFF0000
_0801C2FC: .4byte 0x00000DA4

	thumb_func_start FUN_0801c300
FUN_0801c300: @ 0x0801C300
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0801C39C @ =0x00000B04
	adds r2, r4, r0
	adds r3, r4, #0
	adds r3, #0x3d
	ldrb r0, [r3]
	movs r1, #3
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	movs r6, #0
	strh r0, [r2, #0x20]
	ldrb r1, [r3]
	lsrs r1, r1, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r2, #0x22]
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	mov r8, r1
	ands r0, r1
	str r0, [r2, #8]
	adds r5, r4, #0
	adds r5, #0xf8
	str r6, [sp]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _0801C3A0 @ =0x00000B64
	adds r2, r4, r0
	movs r0, #0x10
	strh r0, [r2, #0x20]
	movs r0, #0x28
	strh r0, [r2, #0x22]
	ldr r0, [r2, #8]
	mov r1, r8
	ands r0, r1
	str r0, [r2, #8]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #0x3c
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, _0801C3A4 @ =0x00000BC4
	adds r2, r4, r0
	strh r6, [r2, #0x20]
	strh r6, [r2, #0x22]
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	str r6, [sp]
	adds r0, r2, #0
	adds r1, r5, #0
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801C39C: .4byte 0x00000B04
_0801C3A0: .4byte 0x00000B64
_0801C3A4: .4byte 0x00000BC4

	thumb_func_start FUN_0801c3a8
FUN_0801c3a8: @ 0x0801C3A8
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r1, _0801C3EC @ =0x030046A0
	ldr r1, [r1]
	adds r5, r1, #0
	adds r5, #0x60
	movs r7, #0
	movs r6, #3
_0801C3B8:
	ldr r2, _0801C3F0 @ =0x00000C24
	adds r1, r7, r2
	mov r2, ip
	adds r4, r2, r1
	movs r1, #0
	ldrsh r3, [r5, r1]
	cmp r3, #0
	blt _0801C3F4
	movs r2, #3
	ands r2, r3
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, #0x90
	strh r1, [r4, #0x20]
	asrs r2, r3, #2
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, #0x20
	strh r1, [r4, #0x22]
	ldr r1, [r4, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0801C3FA
	.align 2, 0
_0801C3EC: .4byte 0x030046A0
_0801C3F0: .4byte 0x00000C24
_0801C3F4:
	ldr r1, [r4, #8]
	movs r2, #1
	orrs r1, r2
_0801C3FA:
	str r1, [r4, #8]
	adds r5, #2
	adds r7, #0x60
	subs r6, #1
	cmp r6, #0
	bge _0801C3B8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801c40c
FUN_0801c40c: @ 0x0801C40C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0801C430 @ =0x00000B04
	adds r4, r6, r0
	movs r5, #2
_0801C416:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xf8
	bl FUN_082372cc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C416
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801C430: .4byte 0x00000B04

	thumb_func_start FUN_0801c434
FUN_0801c434: @ 0x0801C434
	push {r4, r5, lr}
	ldr r1, _0801C450 @ =0x00000B04
	adds r4, r0, r1
	movs r5, #2
_0801C43C:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C43C
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801C450: .4byte 0x00000B04

	thumb_func_start FUN_0801c454
FUN_0801c454: @ 0x0801C454
	push {r4, r5, lr}
	ldr r1, _0801C470 @ =0x00000C24
	adds r4, r0, r1
	movs r5, #3
_0801C45C:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801C45C
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801C470: .4byte 0x00000C24

	thumb_func_start FUN_0801c474
FUN_0801c474: @ 0x0801C474
	push {lr}
	ldr r1, _0801C484 @ =0x00000DA4
	adds r0, r0, r1
	bl FUN_0822f1c0
	pop {r1}
	bx r1
	.align 2, 0
_0801C484: .4byte 0x00000DA4

	thumb_func_start FUN_0801c488
FUN_0801c488: @ 0x0801C488
	push {r4, r5, r6, r7, lr}
	adds r4, r1, #0
	adds r5, r3, #0
	ldm r2!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r2!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r2!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	adds r1, r4, #0
	bl FUN_0801b688
	ldr r1, [r5]
	ldr r2, [r5, #4]
	str r1, [r4, #0x44]
	str r2, [r4, #0x48]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801c4b0
FUN_0801c4b0: @ 0x0801C4B0
	push {lr}
	adds r0, #0x24
	bl FUN_0822f1c0
	pop {r1}
	bx r1

	thumb_func_start FUN_0801c4bc
FUN_0801c4bc: @ 0x0801C4BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801C510 @ =0x05000002
	bl CpuSet
	movs r5, #0x12
	mov r8, r4
	movs r7, #0
	ldr r0, _0801C514 @ =0x00000AA4
	adds r4, r6, r0
_0801C4E0:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r2, r8
	str r2, [sp, #0xc]
	adds r0, r4, #0
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	subs r4, #0x84
	subs r5, #1
	cmp r5, #0
	bge _0801C4E0
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C510: .4byte 0x05000002
_0801C514: .4byte 0x00000AA4

	thumb_func_start FUN_0801c518
FUN_0801c518: @ 0x0801C518
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x2c
	mov r8, r0
	movs r5, #0x9c
	lsls r5, r5, #1
	add r5, r8
	movs r6, #0
	add r0, sp, #0x24
	mov sb, r0
	adds r7, r5, #0
	movs r4, #0xb2
	lsls r4, r4, #1
	add r4, r8
_0801C538:
	movs r0, #3
	ands r0, r6
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x13
	movs r2, #0x90
	lsls r2, r2, #0x10
	adds r1, r1, r2
	asrs r2, r6, #2
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #0x13
	movs r2, #0x80
	lsls r2, r2, #0xe
	adds r0, r0, r2
	lsrs r1, r1, #0x10
	orrs r1, r0
	str r1, [sp, #0x24]
	adds r0, r6, #0
	mov r1, sp
	bl FUN_08242b14
	mov r0, r8
	adds r1, r7, #0
	mov r2, sp
	mov r3, sb
	bl FUN_0801c488
	movs r0, #1
	lsls r0, r6
	mov r2, r8
	ldr r1, [r2, #0x50]
	ands r0, r1
	cmp r0, #0
	beq _0801C594
	ldr r0, _0801C590 @ =0x000002DF
	strh r0, [r4, #0x32]
	movs r0, #0
	bl FUN_0801b670
	adds r1, r0, #0
	str r1, [r4, #0x40]
	b _0801C5AA
	.align 2, 0
_0801C590: .4byte 0x000002DF
_0801C594:
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r4, #0x32]
	movs r0, #1
	bl FUN_0801b670
	adds r1, r0, #0
	str r1, [r4, #0x40]
	ldrb r1, [r5]
	cmp r1, #0
	beq _0801C5B4
_0801C5AA:
	ldr r1, [r4]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4]
_0801C5B4:
	adds r7, #0x84
	adds r6, #1
	adds r4, #0x84
	adds r5, #0x84
	cmp r6, #0xf
	ble _0801C538
	add sp, #0x2c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801c5d0
FUN_0801c5d0: @ 0x0801C5D0
	push {r4, r5, lr}
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r4, r0, r1
	movs r5, #0x12
_0801C5DA:
	adds r0, r4, #0
	bl FUN_0801c4b0
	adds r4, #0x84
	subs r5, #1
	cmp r5, #0
	bge _0801C5DA
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801c5f0
FUN_0801c5f0: @ 0x0801C5F0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0801C60A
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _0801C610 @ =FUN_0801cbc4
	adds r0, r4, #0
	bl FUN_0801b8d0
_0801C60A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801C610: .4byte FUN_0801cbc4

	thumb_func_start FUN_0801c614
FUN_0801c614: @ 0x0801C614
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0801C668 @ =0x00000B64
	adds r6, r5, r0
	adds r4, r5, #0
	adds r4, #0x3e
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801C6F0
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _0801C66C @ =0x00000B04
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0xf8
	movs r2, #0
	str r2, [sp]
	movs r3, #1
	bl FUN_082370cc
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	ldrb r1, [r4]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _0801C670 @ =0x00000978
	adds r0, r0, r2
	adds r0, r5, r0
	ldr r1, [r0, #0x2c]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0x2c]
	ldrb r0, [r4]
	cmp r0, #0
	bne _0801C674
	movs r0, #0x10
	b _0801C676
	.align 2, 0
_0801C668: .4byte 0x00000B64
_0801C66C: .4byte 0x00000B04
_0801C670: .4byte 0x00000978
_0801C674:
	movs r0, #0x40
_0801C676:
	strh r0, [r6, #0x20]
	movs r0, #0x28
	strh r0, [r6, #0x22]
	adds r6, r5, #0
	adds r6, #0x3e
	ldrb r0, [r6]
	adds r4, r5, #0
	adds r4, #0x41
	adds r0, r4, r0
	movs r1, #1
	ldrb r0, [r0]
	lsls r1, r0
	ldr r0, [r5, #0x50]
	orrs r0, r1
	str r0, [r5, #0x50]
	ldrb r0, [r6]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r1, r0, r3
	ldr r0, _0801C6E8 @ =0x000002DF
	strh r0, [r1]
	movs r0, #0
	bl FUN_0801b670
	ldrb r1, [r6]
	adds r4, r4, r1
	ldrb r1, [r4]
	lsls r2, r1, #5
	adds r2, r2, r1
	lsls r2, r2, #2
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r1, r1, r2
	str r0, [r1]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0801bf88
	ldr r1, _0801C6EC @ =FUN_0801c9e4
	adds r0, r5, #0
	bl FUN_0801b8d0
	b _0801C6FE
	.align 2, 0
_0801C6E8: .4byte 0x000002DF
_0801C6EC: .4byte FUN_0801c9e4
_0801C6F0:
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _0801C708 @ =FUN_0801cec0
	adds r0, r5, #0
	bl FUN_0801b8d0
_0801C6FE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801C708: .4byte FUN_0801cec0

	thumb_func_start FUN_0801c70c
FUN_0801c70c: @ 0x0801C70C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0801C724 @ =0x00000B64
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801C728
	movs r0, #0x40
	b _0801C72A
	.align 2, 0
_0801C724: .4byte 0x00000B64
_0801C728:
	movs r0, #0x68
_0801C72A:
	strh r0, [r1, #0x20]
	movs r0, #0x28
	strh r0, [r1, #0x22]
	adds r1, r4, #0
	adds r1, #0x3e
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801C74C
	ldr r1, _0801C748 @ =FUN_0801c9e4
	b _0801C79A
	.align 2, 0
_0801C748: .4byte FUN_0801c9e4
_0801C74C:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r6, r4, r0
	adds r0, r4, #0
	bl FUN_0801b730
	adds r0, r4, #0
	adds r0, #0x3b
	movs r1, #1
	strb r1, [r0]
	ldrb r1, [r6, #2]
	adds r5, r0, #0
	cmp r1, #3
	bne _0801C792
	ldrb r0, [r6, #1]
	cmp r0, #1
	beq _0801C782
	cmp r0, #1
	bgt _0801C778
	cmp r0, #0
	beq _0801C77E
	b _0801C792
_0801C778:
	cmp r0, #2
	beq _0801C786
	b _0801C792
_0801C77E:
	movs r0, #0x33
	b _0801C788
_0801C782:
	movs r0, #0x35
	b _0801C788
_0801C786:
	movs r0, #0x36
_0801C788:
	bl CheckItemOwn
	cmp r0, #0
	bne _0801C792
	strb r0, [r5]
_0801C792:
	ldrb r0, [r5]
	cmp r0, #0
	beq _0801C7A8
	ldr r1, _0801C7A4 @ =FUN_0801ccd4
_0801C79A:
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801C7B0
	.align 2, 0
_0801C7A4: .4byte FUN_0801ccd4
_0801C7A8:
	ldr r1, _0801C7B8 @ =FUN_0801cf18
	adds r0, r4, #0
	bl FUN_0801b8d0
_0801C7B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801C7B8: .4byte FUN_0801cf18

	thumb_func_start FUN_0801c7bc
FUN_0801c7bc: @ 0x0801C7BC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldm r3!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	ldm r3!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	ldm r3!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	adds r0, #0x24
	adds r1, #0x24
	bl FUN_0822f588
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801c7dc
FUN_0801c7dc: @ 0x0801C7DC
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
	bl FUN_0822be3c
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
	bl FUN_0822be3c
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
	bl FUN_0822be3c
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
	bl FUN_0822be3c
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
	bl FUN_0822be3c
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
	bl FUN_0822be3c
	adds r0, r5, #0
	bl FUN_0801c40c
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801c910
FUN_0801c910: @ 0x0801C910
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0
	str r0, [r5, #0x50]
	movs r4, #0
_0801C91A:
	adds r0, r4, #0
	bl GetWeaponID
	subs r0, #1
	cmp r0, #0x38
	bhi _0801C93A
	adds r0, r4, #0
	bl GetWeaponKind
	cmp r0, #2
	bgt _0801C93A
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x50]
	orrs r0, r1
	str r0, [r5, #0x50]
_0801C93A:
	adds r4, #1
	cmp r4, #0xf
	ble _0801C91A
	movs r0, #0x3e
	adds r0, r0, r5
	mov ip, r0
	adds r3, r5, #0
	adds r3, #0x95
	ldr r0, _0801C9D4 @ =0x030046A0
	ldr r0, [r0]
	movs r6, #1
	adds r2, r0, #0
	adds r2, #0x60
	movs r4, #3
_0801C956:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _0801C968
	adds r1, r6, #0
	lsls r1, r0
	ldr r0, [r5, #0x50]
	bics r0, r1
	str r0, [r5, #0x50]
_0801C968:
	adds r2, #2
	subs r4, #1
	cmp r4, #0
	bge _0801C956
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	strb r0, [r3]
	bl FUN_0822b644
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0801c114
	adds r0, r5, #0
	bl FUN_0801c300
	adds r0, r5, #0
	bl FUN_0801c3a8
	adds r0, r5, #0
	bl FUN_0801c518
	ldr r1, _0801C9D8 @ =0x00001308
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _0801C9DC @ =0x0000EFDA
	bl FUN_08047dc0
	ldr r1, _0801C9E0 @ =0x0000130C
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_0801bf88
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801C9D4: .4byte 0x030046A0
_0801C9D8: .4byte 0x00001308
_0801C9DC: .4byte 0x0000EFDA
_0801C9E0: .4byte 0x0000130C

	thumb_func_start FUN_0801c9e4
FUN_0801c9e4: @ 0x0801C9E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	bl FUN_0801b8e8
	ldr r3, _0801CA28 @ =0x030044E0
	ldrh r6, [r3]
	movs r0, #4
	ands r0, r6
	cmp r0, #0
	beq _0801CA2C
	ldrh r1, [r3, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0801CA08
	b _0801CBAE
_0801CA08:
	adds r1, r5, #0
	adds r1, #0x95
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801CA1E
	movs r0, #0
	strb r0, [r1]
_0801CA1E:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0801CBAE
	.align 2, 0
_0801CA28: .4byte 0x030044E0
_0801CA2C:
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r2, [r1]
	movs r4, #0
	ldrh r3, [r3, #2]
	movs r0, #0x40
	mov ip, r0
	ands r0, r3
	mov r8, r1
	cmp r0, #0
	beq _0801CA46
	movs r4, #1
	b _0801CABE
_0801CA46:
	movs r7, #0x80
	adds r0, r7, #0
	ands r0, r3
	cmp r0, #0
	beq _0801CA54
	movs r4, #2
	b _0801CABE
_0801CA54:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _0801CA60
	movs r4, #4
	b _0801CABE
_0801CA60:
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _0801CA6A
	movs r4, #8
_0801CA6A:
	cmp r4, #0
	bne _0801CABE
	adds r3, r5, #0
	adds r3, #0x3f
	ldrb r1, [r3]
	cmp r1, #7
	bls _0801CAB2
	mov r0, ip
	ands r0, r6
	cmp r0, #0
	beq _0801CA84
	movs r4, #1
	b _0801CA8E
_0801CA84:
	adds r0, r7, #0
	ands r0, r6
	cmp r0, #0
	beq _0801CA8E
	movs r4, #2
_0801CA8E:
	ldr r0, _0801CAA0 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0801CAA4
	movs r0, #4
	orrs r4, r0
	b _0801CABE
	.align 2, 0
_0801CAA0: .4byte 0x030044E0
_0801CAA4:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0801CABE
	movs r0, #8
	orrs r4, r0
	b _0801CABE
_0801CAB2:
	movs r0, #0xf0
	ands r0, r6
	cmp r0, #0
	beq _0801CABE
	adds r0, r1, #1
	strb r0, [r3]
_0801CABE:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _0801CADA
	asrs r0, r2, #2
	cmp r0, #0
	bne _0801CAD6
	movs r0, #3
	ands r0, r2
	adds r2, r0, #0
	adds r2, #0xc
	b _0801CB24
_0801CAD6:
	subs r2, #4
	b _0801CB24
_0801CADA:
	movs r0, #2
	ands r0, r4
	cmp r0, #0
	beq _0801CAF0
	asrs r0, r2, #2
	cmp r0, #3
	bne _0801CAEC
	ands r2, r0
	b _0801CB24
_0801CAEC:
	adds r2, #4
	b _0801CB24
_0801CAF0:
	movs r0, #4
	ands r0, r4
	cmp r0, #0
	beq _0801CB0C
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _0801CB08
	movs r0, #0xfc
	ands r0, r2
	adds r2, r0, #3
	b _0801CB24
_0801CB08:
	subs r2, #1
	b _0801CB24
_0801CB0C:
	movs r0, #8
	ands r4, r0
	cmp r4, #0
	beq _0801CB2C
	movs r0, #3
	ands r0, r2
	cmp r0, #3
	bne _0801CB22
	movs r0, #0xfc
	ands r2, r0
	b _0801CB24
_0801CB22:
	adds r2, #1
_0801CB24:
	adds r1, r5, #0
	adds r1, #0x3f
	movs r0, #0
	strb r0, [r1]
_0801CB2C:
	mov r3, r8
	ldrb r1, [r3]
	cmp r2, r1
	beq _0801CB66
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	ldr r4, _0801CB8C @ =0x00000B24
	adds r1, r5, r4
	strh r0, [r1]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r4, #2
	adds r1, r5, r4
	strh r0, [r1]
	strb r2, [r3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0801bf88
_0801CB66:
	ldr r0, _0801CB90 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0801CB9E
	adds r0, r2, #0
	mov r1, r8
	ldrb r1, [r1]
	lsls r0, r1
	ldr r1, [r5, #0x50]
	ands r0, r1
	cmp r0, #0
	beq _0801CB94
	adds r0, r5, #0
	bl FUN_0801c5f0
	b _0801CBBA
	.align 2, 0
_0801CB8C: .4byte 0x00000B24
_0801CB90: .4byte 0x030044E0
_0801CB94:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0801CBBA
_0801CB9E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801CBAE
	adds r0, r5, #0
	bl FUN_0801c614
	b _0801CBBA
_0801CBAE:
	adds r0, r5, #0
	bl FUN_0801c7dc
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801CBBA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801cbc4
FUN_0801cbc4: @ 0x0801CBC4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3e
	ldrb r0, [r6]
	lsls r1, r0, #5
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0801CC74 @ =0x00000978
	adds r1, r1, r0
	adds r1, r1, r5
	mov r8, r1
	adds r0, r5, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801CC88
	adds r7, r5, #0
	adds r7, #0x3d
	ldrb r0, [r7]
	lsls r1, r0, #5
	adds r1, r1, r0
	lsls r1, r1, #2
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r5, r1
	mov r0, r8
	movs r2, #0xd
	bl FUN_0801c7bc
	mov r3, r8
	ldr r0, [r3, #0x2c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x2c]
	ldrb r0, [r6]
	adds r4, r5, #0
	adds r4, #0x41
	adds r0, r4, r0
	ldrb r1, [r7]
	strb r1, [r0]
	ldrb r0, [r6]
	adds r0, r4, r0
	movs r1, #1
	ldrb r0, [r0]
	lsls r1, r0
	ldr r0, [r5, #0x50]
	bics r0, r1
	str r0, [r5, #0x50]
	ldrb r0, [r6]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, #5
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	movs r2, #0xcb
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r1]
	movs r0, #1
	bl FUN_0801b670
	ldrb r1, [r6]
	adds r4, r4, r1
	ldrb r1, [r4]
	lsls r2, r1, #5
	adds r2, r2, r1
	lsls r2, r2, #2
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r1, r5, r3
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r6]
	cmp r0, #0
	bne _0801CC78
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0x10
	b _0801CC7E
	.align 2, 0
_0801CC74: .4byte 0x00000978
_0801CC78:
	adds r0, r5, #0
	adds r0, #0x54
	movs r1, #0x40
_0801CC7E:
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0x56
	movs r0, #0x28
	strh r0, [r1]
_0801CC88:
	mov r0, r8
	adds r0, #0x44
	adds r1, r5, #0
	adds r1, #0x3d
	ldrb r2, [r1]
	lsls r1, r2, #5
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r2, r5, #0
	adds r2, #0x54
	ldr r3, [r5, #0x44]
	movs r4, #3
	str r4, [sp]
	bl FUN_08237970
	ldr r0, [r5, #0x44]
	cmp r0, #7
	bls _0801CCBC
	adds r0, r5, #0
	bl FUN_0801c70c
	b _0801CCC8
_0801CCBC:
	adds r0, r5, #0
	bl FUN_0801c7dc
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801CCC8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801ccd4
FUN_0801ccd4: @ 0x0801CCD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	bne _0801CCEC
	b _0801CE0A
_0801CCEC:
	ldr r0, _0801CD64 @ =0x00000AA4
	adds r6, r7, r0
	ldr r1, _0801CD68 @ =0x00000978
	adds r1, r1, r7
	mov r8, r1
	ldr r2, _0801CD6C @ =0x000009FC
	adds r5, r7, r2
	subs r0, #0x24
	adds r0, r0, r7
	mov sb, r0
	ldr r1, _0801CD70 @ =0x00000B04
	adds r0, r7, r1
	adds r4, r7, #0
	adds r4, #0xf8
	adds r1, r4, #0
	movs r2, #0x39
	movs r3, #0
	bl Sprite_SetSprite
	bl FUN_08049e5c
	adds r0, r7, #0
	mov r1, sb
	bl FUN_0801b688
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #0x68
	strh r0, [r6, #0x20]
	movs r0, #0x28
	strh r0, [r6, #0x22]
	movs r2, #0
	mov sl, r2
	mov r1, r8
	ldrb r0, [r1, #1]
	ldrb r5, [r5, #1]
	cmp r0, r5
	beq _0801CD52
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r7, r2
	adds r0, r6, #0
	movs r2, #0x42
	movs r3, #0
	bl Sprite_SetSprite
	movs r0, #1
	mov sl, r0
_0801CD52:
	adds r0, r7, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801CD78
	ldr r0, _0801CD74 @ =0x000002DF
	strh r0, [r6, #0x3a]
	movs r0, #0
	b _0801CD80
	.align 2, 0
_0801CD64: .4byte 0x00000AA4
_0801CD68: .4byte 0x00000978
_0801CD6C: .4byte 0x000009FC
_0801CD70: .4byte 0x00000B04
_0801CD74: .4byte 0x000002DF
_0801CD78:
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6, #0x3a]
	movs r0, #1
_0801CD80:
	bl FUN_0801b670
	str r0, [r6, #0x48]
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0801CDE4 @ =0x00000BC4
	adds r0, r7, r2
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _0801CDE8 @ =0x00000BCC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, _0801CDEC @ =0x0000130C
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_080478f0
	mov r2, sl
	cmp r2, #0
	bne _0801CDDA
	ldr r0, _0801CDF0 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, sb
	ldrb r2, [r2, #3]
	cmp r0, r2
	blt _0801CDF4
_0801CDDA:
	movs r0, #1
	bl FUN_08047a28
	b _0801CDFA
	.align 2, 0
_0801CDE4: .4byte 0x00000BC4
_0801CDE8: .4byte 0x00000BCC
_0801CDEC: .4byte 0x0000130C
_0801CDF0: .4byte 0x030046A0
_0801CDF4:
	movs r0, #2
	bl FUN_08047a28
_0801CDFA:
	ldr r1, _0801CE40 @ =0x00000DA4
	adds r0, r7, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	bl FUN_08049e5c
_0801CE0A:
	ldr r4, _0801CE44 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0801CE48
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801CEA4
	adds r1, r7, #0
	adds r1, #0x95
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801CE36
	movs r0, #0
	strb r0, [r1]
_0801CE36:
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _0801CEA4
	.align 2, 0
_0801CE40: .4byte 0x00000DA4
_0801CE44: .4byte 0x030044E0
_0801CE48:
	adds r0, r7, #0
	bl FUN_0801c188
	ldrh r1, [r4, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0801CE78
	adds r0, r7, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801CE80
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _0801CE74 @ =FUN_0801d6c0
	adds r0, r7, #0
	bl FUN_0801b8d0
	b _0801CEB0
	.align 2, 0
_0801CE74: .4byte FUN_0801d6c0
_0801CE78:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801CEA4
_0801CE80:
	ldr r0, _0801CE9C @ =0x00000AA4
	adds r1, r7, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, _0801CEA0 @ =0x00000BCC
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0801c614
	b _0801CEB0
	.align 2, 0
_0801CE9C: .4byte 0x00000AA4
_0801CEA0: .4byte 0x00000BCC
_0801CEA4:
	adds r0, r7, #0
	bl FUN_0801c7dc
	ldr r0, [r7, #0x44]
	adds r0, #1
	str r0, [r7, #0x44]
_0801CEB0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801cec0
FUN_0801cec0: @ 0x0801CEC0
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801CEE6
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801CF00 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_0801CEE6:
	ldr r0, [r4, #0x44]
	cmp r0, #0x14
	bne _0801CF04
	adds r1, r4, #0
	adds r1, #0xb8
	ldrh r0, [r1]
	cmp r0, #0
	beq _0801CF10
	movs r1, #0
	bl Script_ExecById
	b _0801CF10
	.align 2, 0
_0801CF00: .4byte 0x0000FFFF
_0801CF04:
	adds r0, r4, #0
	bl FUN_0801c7dc
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
_0801CF10:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801cf18
FUN_0801cf18: @ 0x0801CF18
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801CFB2
	ldr r0, _0801CFCC @ =0x00000AA4
	adds r6, r5, r0
	movs r1, #0xa8
	lsls r1, r1, #4
	adds r4, r5, r1
	ldr r2, _0801CFD0 @ =0x00000B04
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0xf8
	movs r2, #0x39
	movs r3, #0
	bl Sprite_SetSprite
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, _0801CFD4 @ =0x0000130C
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r0, #3
	bl FUN_08047a28
	bl FUN_08049e5c
	ldr r0, _0801CFD8 @ =0x00000DA4
	adds r2, r5, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0801b688
	ldr r1, _0801CFDC @ =0x00000978
	adds r0, r5, r1
	ldr r2, _0801CFE0 @ =0x000009FC
	adds r1, r5, r2
	ldrb r0, [r0, #1]
	ldrb r1, [r1, #1]
	cmp r0, r1
	beq _0801CF92
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r6, #0
	movs r2, #0x42
	movs r3, #0
	bl Sprite_SetSprite
_0801CF92:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r0, #0x68
	strh r0, [r6, #0x20]
	movs r0, #0x28
	strh r0, [r6, #0x22]
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6, #0x3a]
	movs r0, #1
	bl FUN_0801b670
	str r0, [r6, #0x48]
_0801CFB2:
	ldr r0, _0801CFE4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0801CFE8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0801D014
	.align 2, 0
_0801CFCC: .4byte 0x00000AA4
_0801CFD0: .4byte 0x00000B04
_0801CFD4: .4byte 0x0000130C
_0801CFD8: .4byte 0x00000DA4
_0801CFDC: .4byte 0x00000978
_0801CFE0: .4byte 0x000009FC
_0801CFE4: .4byte 0x030044E0
_0801CFE8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801D008
	ldr r0, _0801D004 @ =0x00000AA4
	adds r1, r5, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	adds r0, r5, #0
	bl FUN_0801c614
	b _0801D014
	.align 2, 0
_0801D004: .4byte 0x00000AA4
_0801D008:
	adds r0, r5, #0
	bl FUN_0801c7dc
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801D014:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801d01c
FUN_0801d01c: @ 0x0801D01C
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	movs r0, #0x9c
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r2, #0x12
_0801D02A:
	ldr r0, [r1, #0x2c]
	orrs r0, r4
	str r0, [r1, #0x2c]
	adds r1, #0x84
	subs r2, #1
	cmp r2, #0
	bge _0801D02A
	movs r4, #1
	ldr r0, _0801D078 @ =0x00000B0C
	adds r1, r3, r0
	movs r2, #2
_0801D040:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0801D040
	movs r4, #1
	ldr r0, _0801D07C @ =0x00000C2C
	adds r1, r3, r0
	movs r2, #3
_0801D056:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0801D056
	ldr r1, _0801D080 @ =0x00000DA4
	adds r0, r3, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801D078: .4byte 0x00000B0C
_0801D07C: .4byte 0x00000C2C
_0801D080: .4byte 0x00000DA4

	thumb_func_start FUN_0801d084
FUN_0801d084: @ 0x0801D084
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r6, r0, #0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _0801D0D8 @ =0x05000002
	bl CpuSet
	mov r8, r4
	movs r7, #0
	ldr r0, _0801D0DC @ =0x00000E04
	adds r4, r6, r0
	movs r5, #0xc
_0801D0A8:
	str r7, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xd8
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801D0A8
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801D0D8: .4byte 0x05000002
_0801D0DC: .4byte 0x00000E04

	thumb_func_start FUN_0801d0e0
FUN_0801d0e0: @ 0x0801D0E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r2, r6, r0
	ldrb r0, [r2, #2]
	cmp r0, #4
	bhi _0801D142
	lsls r0, r0, #2
	ldr r1, _0801D104 @ =_0801D108
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801D104: .4byte _0801D108
_0801D108: @ jump table
	.4byte _0801D11C @ case 0
	.4byte _0801D124 @ case 1
	.4byte _0801D12C @ case 2
	.4byte _0801D132 @ case 3
	.4byte _0801D13A @ case 4
_0801D11C:
	movs r3, #0x28
	movs r1, #8
	str r1, [sp, #4]
	b _0801D148
_0801D124:
	movs r3, #0x1e
	movs r4, #7
	str r4, [sp, #4]
	b _0801D148
_0801D12C:
	movs r3, #0x14
	movs r0, #6
	b _0801D146
_0801D132:
	movs r3, #0xa
	movs r1, #5
	str r1, [sp, #4]
	b _0801D148
_0801D13A:
	movs r3, #0xa
	movs r4, #5
	str r4, [sp, #4]
	b _0801D148
_0801D142:
	movs r3, #0x28
	movs r0, #8
_0801D146:
	str r0, [sp, #4]
_0801D148:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0xe1
	lsls r0, r0, #3
	str r0, [r1]
	ldrb r0, [r2, #5]
	adds r2, r6, #0
	adds r2, #0x60
	strh r0, [r2]
	subs r0, r0, r3
	subs r1, #0x58
	strh r0, [r1]
	ldrh r0, [r2]
	adds r0, r0, r3
	adds r3, r6, #0
	adds r3, #0x5e
	strh r0, [r3]
	movs r4, #0
	ldrsh r0, [r1, r4]
	str r2, [sp, #0xc]
	mov r8, r1
	mov sb, r3
	cmp r0, #0
	bge _0801D17C
	movs r0, #0
	b _0801D184
_0801D17C:
	cmp r0, #0xb0
	ble _0801D186
	movs r0, #0xb0
	mov r1, r8
_0801D184:
	strh r0, [r1]
_0801D186:
	mov r2, sb
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	bge _0801D196
	movs r0, #0
	strh r0, [r2]
	b _0801D1A0
_0801D196:
	cmp r0, #0xb0
	ble _0801D1A0
	movs r0, #0xb0
	mov r1, sb
	strh r0, [r1]
_0801D1A0:
	adds r2, r6, #0
	adds r2, #0x62
	str r2, [sp, #8]
	movs r4, #0
	strh r4, [r2]
	ldr r0, _0801D318 @ =0x00000E04
	adds r7, r6, r0
	strh r4, [r7, #0x20]
	movs r1, #0xd8
	adds r1, r1, r6
	mov sl, r1
	adds r0, r7, #0
	movs r2, #4
	movs r3, #0
	bl Sprite_SetSprite
	strb r4, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	ldr r0, _0801D31C @ =0x00000E64
	adds r7, r6, r0
	movs r1, #0
	strh r1, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #3
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	strb r4, [r7, #0x1a]
	ldr r4, _0801D320 @ =0x00000EC4
	adds r7, r6, r4
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	mov r1, sb
	ldrh r0, [r1]
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #2
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	ldr r1, [sp, #0xc]
	ldrh r0, [r1]
	strh r0, [r7, #0x20]
	ldr r2, [sp, #4]
	adds r0, r7, #0
	mov r1, sl
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r7, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	ldr r1, [sp, #8]
	ldrh r0, [r1]
	subs r0, #0xb0
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #9
	movs r3, #0
	bl Sprite_SetSprite
	movs r2, #1
	strb r2, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r7, #8]
	ldr r0, _0801D324 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0801D328 @ =0x000053E0
	adds r0, r0, r1
	ldr r2, _0801D32C @ =0x000012E4
	adds r4, r6, r2
	ldr r2, _0801D330 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0x81
	lsls r0, r0, #8
	strh r0, [r7, #0x3a]
	str r4, [r7, #0x48]
	ldr r4, _0801D334 @ =0x00001044
	adds r7, r6, r4
	movs r0, #0
	strh r0, [r7, #0x20]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0xa
	movs r3, #0
	bl Sprite_SetSprite
	movs r1, #1
	strb r1, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	movs r0, #0
	strh r0, [r7, #0x20]
	movs r1, #0
	str r1, [sp]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r0, [r7, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7, #8]
	adds r4, #0x60
	adds r7, r6, r4
	movs r5, #0x20
	mov r8, sl
	movs r0, #0
	mov sb, r0
	movs r4, #4
_0801D2D6:
	movs r0, #8
	strh r0, [r7, #0x20]
	strh r5, [r7, #0x22]
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0x16
	movs r3, #0
	bl Sprite_SetSprite
	mov r1, sb
	strb r1, [r7, #0x1a]
	ldr r0, [r7, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #8]
	subs r4, #1
	adds r7, #0x60
	adds r5, #8
	cmp r4, #0
	bge _0801D2D6
	ldr r0, [r6, #0x20]
	ldr r1, [r6, #0x24]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801D318: .4byte 0x00000E04
_0801D31C: .4byte 0x00000E64
_0801D320: .4byte 0x00000EC4
_0801D324: .4byte 0x03003584
_0801D328: .4byte 0x000053E0
_0801D32C: .4byte 0x000012E4
_0801D330: .4byte 0x04000008
_0801D334: .4byte 0x00001044

	thumb_func_start FUN_0801d338
FUN_0801d338: @ 0x0801D338
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r6, #0x66
	ldrb r1, [r6]
	lsls r5, r1, #2
	adds r5, #0xc4
	adds r5, r0, r5
	lsls r4, r1, #1
	adds r4, r4, r1
	lsls r4, r4, #5
	ldr r1, _0801D390 @ =0x00001104
	adds r4, r4, r1
	adds r4, r0, r4
	adds r1, r0, #0
	adds r1, #0xd8
	adds r0, #0x92
	ldrb r2, [r0]
	adds r2, #0x14
	adds r0, r4, #0
	movs r3, #0
	bl Sprite_SetSprite
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r1, #0
	movs r0, #1
	strh r0, [r5]
	strh r1, [r5, #2]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _0801D388
	movs r0, #0
	strb r0, [r6]
_0801D388:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801D390: .4byte 0x00001104

	thumb_func_start FUN_0801d394
FUN_0801d394: @ 0x0801D394
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r2, #0xc4
	ldr r1, _0801D3B8 @ =0x00001104
	adds r3, r0, r1
	movs r6, #0
	movs r5, #4
_0801D3A2:
	ldrh r0, [r2]
	cmp r0, #1
	beq _0801D3BC
	cmp r0, #1
	ble _0801D406
	cmp r0, #2
	beq _0801D3DC
	cmp r0, #3
	beq _0801D3F0
	b _0801D406
	.align 2, 0
_0801D3B8: .4byte 0x00001104
_0801D3BC:
	ldrh r0, [r2, #2]
	movs r1, #8
	subs r1, r1, r0
	lsls r1, r1, #3
	adds r1, #4
	movs r4, #0
	strh r1, [r3, #0x20]
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801D406
	movs r0, #4
	strh r0, [r3, #0x20]
	movs r0, #2
	strh r0, [r2]
	strh r4, [r2, #2]
	b _0801D406
_0801D3DC:
	ldrh r0, [r2, #2]
	cmp r0, #0x3f
	bls _0801D406
	movs r0, #3
	strh r0, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	movs r1, #0x80
	lsls r1, r1, #2
	b _0801D402
_0801D3F0:
	ldrh r0, [r2, #2]
	cmp r0, #7
	bls _0801D406
	strh r6, [r2]
	strh r6, [r2, #2]
	ldr r0, [r3, #8]
	ldr r1, _0801D41C @ =0xFFFFFDFF
	ands r0, r1
	movs r1, #1
_0801D402:
	orrs r0, r1
	str r0, [r3, #8]
_0801D406:
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	subs r5, #1
	adds r2, #4
	adds r3, #0x60
	cmp r5, #0
	bge _0801D3A2
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801D41C: .4byte 0xFFFFFDFF

	thumb_func_start FUN_0801d420
FUN_0801d420: @ 0x0801D420
	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0x80
	ldr r0, [r0]
	asrs r4, r0, #5
	ldr r0, _0801D440 @ =0x00000EC4
	adds r2, r3, r0
	adds r0, r4, #0
	subs r0, #0x18
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801D444
	movs r0, #0
	b _0801D44A
	.align 2, 0
_0801D440: .4byte 0x00000EC4
_0801D444:
	cmp r0, #0xb0
	ble _0801D44C
	movs r0, #0xb0
_0801D44A:
	strh r0, [r2, #0x20]
_0801D44C:
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	ldr r0, _0801D46C @ =0x00000F24
	adds r2, r3, r0
	adds r0, r4, #0
	adds r0, #0x18
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0801D470
	movs r0, #0
	b _0801D476
	.align 2, 0
_0801D46C: .4byte 0x00000F24
_0801D470:
	cmp r0, #0xb0
	ble _0801D478
	movs r0, #0xb0
_0801D476:
	strh r0, [r2, #0x20]
_0801D478:
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801d488
FUN_0801d488: @ 0x0801D488
	ldr r1, _0801D4A0 @ =0x00000EC4
	adds r3, r0, r1
	ldr r1, [r3, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r3, #8]
	ldr r1, _0801D4A4 @ =0x00000F24
	adds r3, r0, r1
	ldr r0, [r3, #8]
	orrs r0, r2
	str r0, [r3, #8]
	bx lr
	.align 2, 0
_0801D4A0: .4byte 0x00000EC4
_0801D4A4: .4byte 0x00000F24

	thumb_func_start FUN_0801d4a8
FUN_0801d4a8: @ 0x0801D4A8
	ldr r1, _0801D4C0 @ =0x00000E04
	adds r2, r0, r1
	adds r0, #0x93
	ldrb r0, [r0]
	strh r0, [r2, #0x20]
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	bx lr
	.align 2, 0
_0801D4C0: .4byte 0x00000E04

	thumb_func_start FUN_0801d4c4
FUN_0801d4c4: @ 0x0801D4C4
	ldr r1, _0801D4D8 @ =0x00000E04
	adds r2, r0, r1
	adds r0, #0x93
	ldrb r0, [r0]
	strh r0, [r2, #0x20]
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	bx lr
	.align 2, 0
_0801D4D8: .4byte 0x00000E04

	thumb_func_start FUN_0801d4dc
FUN_0801d4dc: @ 0x0801D4DC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r2, #0
	mov ip, r3
	movs r0, #0x99
	lsls r0, r0, #5
	adds r4, r5, r0
	ldr r2, _0801D534 @ =0x0000131C
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r2, #0
	movs r3, #0
	strh r0, [r4]
	ldr r7, _0801D538 @ =0x0000131E
	adds r0, r5, r7
	ldrh r0, [r0]
	strb r0, [r4, #2]
	strb r2, [r4, #3]
	strh r3, [r4, #4]
	strb r1, [r4, #6]
	strb r6, [r4, #7]
	mov r0, ip
	cmp r0, #0
	beq _0801D526
	cmp r6, #0
	ble _0801D526
	mov r3, ip
	ldr r2, _0801D53C @ =0x00001328
	adds r1, r5, r2
	adds r2, r6, #0
_0801D518:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r3, #2
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _0801D518
_0801D526:
	adds r0, r4, #0
	bl FUN_080224f0
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801D534: .4byte 0x0000131C
_0801D538: .4byte 0x0000131E
_0801D53C: .4byte 0x00001328

	thumb_func_start FUN_0801d540
FUN_0801d540: @ 0x0801D540
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _0801D58C @ =0x00000FE4
	adds r2, r7, r0
	adds r1, r7, #0
	adds r1, #0x62
	ldrh r0, [r1]
	subs r0, #0xb0
	movs r3, #0
	strh r0, [r2, #0x20]
	adds r0, r7, #0
	adds r0, #0x5c
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r4, #0
	ldrsh r0, [r0, r4]
	ldr r4, _0801D590 @ =0x000010A4
	adds r2, r7, r4
	cmp r1, r0
	bge _0801D594
	adds r1, r7, #0
	adds r1, #0x64
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xd8
	cmp r0, #1
	beq _0801D5E2
	movs r0, #1
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #0
	b _0801D5BA
	.align 2, 0
_0801D58C: .4byte 0x00000FE4
_0801D590: .4byte 0x000010A4
_0801D594:
	adds r0, r7, #0
	adds r0, #0x5e
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _0801D5C2
	adds r1, r7, #0
	adds r1, #0x64
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xd8
	cmp r0, #2
	beq _0801D5E2
	movs r0, #2
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #1
_0801D5BA:
	movs r3, #1
	bl FUN_082370cc
	b _0801D5E2
_0801D5C2:
	adds r1, r7, #0
	adds r1, #0x64
	ldrb r0, [r1]
	adds r6, r7, #0
	adds r6, #0xd8
	cmp r0, #3
	beq _0801D5E2
	movs r0, #3
	strb r0, [r1]
	str r3, [sp]
	adds r0, r2, #0
	adds r1, r6, #0
	movs r2, #2
	movs r3, #1
	bl FUN_082370cc
_0801D5E2:
	movs r0, #0xb4
	adds r0, r0, r7
	mov sb, r0
	ldr r1, _0801D604 @ =0x00000E04
	adds r4, r7, r1
	movs r5, #0xc
_0801D5EE:
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_082372cc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801D5EE
	movs r5, #0
	b _0801D61E
	.align 2, 0
_0801D604: .4byte 0x00000E04
_0801D608:
	adds r1, r5, #6
	movs r0, #0
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	movs r0, #0
	movs r2, #0x10
	movs r3, #5
	bl FUN_0822bcf4
	adds r5, #1
_0801D61E:
	ldr r0, [r7, #0x6c]
	cmp r5, r0
	blo _0801D608
	cmp r5, #9
	bgt _0801D642
	movs r6, #0
	movs r4, #0xd
_0801D62C:
	adds r1, r5, #6
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #0
	movs r2, #0x10
	movs r3, #6
	bl FUN_0822bcf4
	adds r5, #1
	cmp r5, #9
	ble _0801D62C
_0801D642:
	mov r2, sb
	ldr r0, [r2]
	movs r1, #0x3c
	bl Mod
	movs r1, #0x64
	muls r0, r1, r0
	movs r1, #0x3c
	bl Div
	mov r8, r0
	mov r4, sb
	ldr r0, [r4]
	movs r1, #0x3c
	bl Div
	adds r3, r0, #0
	movs r6, #0x11
	str r6, [sp]
	movs r5, #2
	str r5, [sp, #4]
	movs r4, #0xd
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #0x15
	movs r2, #0x10
	bl FUN_0822be3c
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r0, #0
	movs r1, #0x18
	movs r2, #0x10
	mov r3, r8
	bl FUN_0822be3c
	adds r0, r7, #0
	bl FUN_0801d394
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801d6a0
FUN_0801d6a0: @ 0x0801D6A0
	push {r4, r5, lr}
	ldr r1, _0801D6BC @ =0x00000E04
	adds r4, r0, r1
	movs r5, #0xc
_0801D6A8:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0801D6A8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801D6BC: .4byte 0x00000E04

	thumb_func_start FUN_0801d6c0
FUN_0801d6c0: @ 0x0801D6C0
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801D6E6
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801D700 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_0801D6E6:
	ldr r0, [r4, #0x44]
	cmp r0, #0x1f
	bls _0801D708
	adds r0, r4, #0
	bl FUN_0801d01c
	bl FUN_08049f84
	ldr r1, _0801D704 @ =FUN_0801d71c
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801D714
	.align 2, 0
_0801D700: .4byte 0x0000FFFF
_0801D704: .4byte FUN_0801d71c
_0801D708:
	adds r0, r4, #0
	bl FUN_0801c7dc
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
_0801D714:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801d71c
FUN_0801d71c: @ 0x0801D71C
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801D758
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0801c114
	adds r0, r4, #0
	bl FUN_0801d0e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _0801D768 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r0, _0801D76C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	bl FUN_0807c7c8
_0801D758:
	ldr r0, [r4, #0x44]
	cmp r0, #0x1f
	bls _0801D774
	ldr r1, _0801D770 @ =FUN_0801d788
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801D780
	.align 2, 0
_0801D768: .4byte 0x0000FFFF
_0801D76C: .4byte 0x03002BE0
_0801D770: .4byte FUN_0801d788
_0801D774:
	adds r0, r4, #0
	bl FUN_0801d540
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
_0801D780:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801d788
FUN_0801d788: @ 0x0801D788
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801D7A0
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
_0801D7A0:
	ldr r0, [r4, #0x44]
	cmp r0, #0xef
	bls _0801D7B4
	ldr r1, _0801D7B0 @ =FUN_0801db1c
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801D7D2
	.align 2, 0
_0801D7B0: .4byte FUN_0801db1c
_0801D7B4:
	movs r1, #0x3d
	bl Mod
	cmp r0, #0x3c
	bne _0801D7C6
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801D7C6:
	adds r0, r4, #0
	bl FUN_0801d540
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
_0801D7D2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801d7d8
FUN_0801d7d8: @ 0x0801D7D8
	push {lr}
	ldr r2, _0801D7E8 @ =0x00001310
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801D7EC
	movs r0, #0
	b _0801D7F2
	.align 2, 0
_0801D7E8: .4byte 0x00001310
_0801D7EC:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_0801D7F2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801d7f8
FUN_0801d7f8: @ 0x0801D7F8
	ldr r3, _0801D810 @ =0x00001318
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _0801D814 @ =0x00001310
	adds r2, r0, r1
	movs r3, #0
	movs r1, #1
	strb r1, [r2]
	ldr r1, _0801D818 @ =0x00001314
	adds r0, r0, r1
	str r3, [r0]
	bx lr
	.align 2, 0
_0801D810: .4byte 0x00001318
_0801D814: .4byte 0x00001310
_0801D818: .4byte 0x00001314

	thumb_func_start FUN_0801d81c
FUN_0801d81c: @ 0x0801D81C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801d7d8
	cmp r0, #0
	beq _0801D830
	ldr r0, _0801D858 @ =0x00001302
	adds r1, r4, r0
	movs r0, #0x9f
	strh r0, [r1]
_0801D830:
	ldr r1, [r4, #0x6c]
	cmp r1, #0
	beq _0801D860
	adds r2, r4, #0
	adds r2, #0x84
	adds r1, #3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, [r2]
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _0801D85C @ =0x000015FF
	adds r3, r2, #0
	cmp r1, r0
	ble _0801D872
	adds r0, #1
	str r0, [r3]
	b _0801D872
	.align 2, 0
_0801D858: .4byte 0x00001302
_0801D85C: .4byte 0x000015FF
_0801D860:
	adds r2, r4, #0
	adds r2, #0x84
	ldr r1, [r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	asrs r0, r0, #6
	str r0, [r2]
	adds r3, r2, #0
_0801D872:
	ldr r0, _0801D8AC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801D8B8
	ldr r0, _0801D8B0 @ =0x00000E64
	adds r2, r4, r0
	adds r1, r4, #0
	adds r1, #0x80
	ldr r0, [r3]
	str r0, [r1]
	asrs r0, r0, #5
	strh r0, [r2, #0x20]
	ldr r1, _0801D8B4 @ =FUN_0801d8cc
	adds r0, r4, #0
	bl FUN_0801d7f8
	adds r0, r4, #0
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
	adds r0, r4, #0
	bl FUN_0801d420
	b _0801D8C2
	.align 2, 0
_0801D8AC: .4byte 0x030044E0
_0801D8B0: .4byte 0x00000E64
_0801D8B4: .4byte FUN_0801d8cc
_0801D8B8:
	ldr r0, _0801D8C8 @ =0x00001314
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0801D8C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801D8C8: .4byte 0x00001314

	thumb_func_start FUN_0801d8cc
FUN_0801d8cc: @ 0x0801D8CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	bl FUN_0801d7d8
	cmp r0, #0
	beq _0801D904
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #0
	str r0, [r1]
	str r0, [r5, #0x7c]
	adds r1, #4
	str r0, [r1]
	adds r1, #4
	strb r0, [r1]
	subs r1, #0x2a
	strb r0, [r1]
	adds r1, #0x2c
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	ldr r0, _0801D934 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #1
	bl FUN_0807c7c8
_0801D904:
	ldr r0, [r5, #0x6c]
	movs r1, #3
	cmp r0, #0
	beq _0801D90E
	movs r1, #6
_0801D90E:
	lsrs r0, r0, #1
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x88
	ldr r0, [r2]
	cmp r0, #0
	beq _0801D93C
	lsls r0, r1, #2
	ldr r1, [r5, #0x7c]
	adds r1, r1, r0
	str r1, [r5, #0x7c]
	ldr r0, _0801D938 @ =0x000002FF
	cmp r1, r0
	ble _0801D950
	adds r0, #1
	str r0, [r5, #0x7c]
	movs r0, #0
	b _0801D94E
	.align 2, 0
_0801D934: .4byte 0x03002BE0
_0801D938: .4byte 0x000002FF
_0801D93C:
	lsls r1, r1, #2
	ldr r0, [r5, #0x7c]
	subs r0, r0, r1
	str r0, [r5, #0x7c]
	ldr r1, _0801D968 @ =0xFFFFFD00
	cmp r0, r1
	bgt _0801D950
	str r1, [r5, #0x7c]
	movs r0, #1
_0801D94E:
	str r0, [r2]
_0801D950:
	adds r2, r5, #0
	adds r2, #0x84
	adds r0, r5, #0
	adds r0, #0x80
	ldr r1, [r0]
	ldr r0, [r5, #0x7c]
	adds r1, r1, r0
	str r1, [r2]
	cmp r1, #0
	bge _0801D96C
	movs r0, #0
	b _0801D974
	.align 2, 0
_0801D968: .4byte 0xFFFFFD00
_0801D96C:
	movs r0, #0xb0
	lsls r0, r0, #5
	cmp r1, r0
	ble _0801D976
_0801D974:
	str r0, [r2]
_0801D976:
	ldr r0, _0801DA34 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0801DA38 @ =0x000053E0
	adds r4, r0, r1
	ldr r0, _0801DA3C @ =0x00001314
	adds r0, r0, r5
	mov r8, r0
	ldr r0, [r0]
	movs r1, #0x10
	bl Div
	adds r6, r0, #0
	adds r7, r5, #0
	adds r7, #0x8c
	ldr r0, [r7]
	lsls r0, r0, #5
	movs r1, #5
	bl Div
	cmp r6, r0
	bge _0801D9A2
	adds r6, r0, #0
_0801D9A2:
	movs r1, #0x20
	subs r1, r1, r6
	lsls r3, r1, #5
	subs r3, r3, r1
	ldrh r2, [r4, #0x1e]
	movs r4, #0x1f
	movs r0, #0x1f
	ands r0, r2
	muls r0, r6, r0
	adds r3, r3, r0
	asrs r3, r3, #5
	lsls r1, r1, #2
	lsls r2, r2, #0x10
	lsrs r0, r2, #0x15
	ands r0, r4
	muls r0, r6, r0
	adds r1, r1, r0
	asrs r1, r1, #5
	lsrs r2, r2, #0x1a
	ands r2, r4
	adds r0, r2, #0
	muls r0, r6, r0
	asrs r0, r0, #5
	ands r3, r4
	ands r1, r4
	lsls r1, r1, #5
	adds r3, r3, r1
	ands r0, r4
	lsls r0, r0, #0xa
	adds r3, r3, r0
	ldr r1, _0801DA40 @ =0x00001302
	adds r0, r5, r1
	strh r3, [r0]
	adds r2, r5, #0
	adds r2, #0x90
	ldrb r0, [r2]
	cmp r0, #0
	bne _0801DA50
	ldr r0, [r7]
	cmp r0, #4
	bgt _0801DA28
	ldr r0, _0801DA44 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801DA1E
	adds r1, r5, #0
	adds r1, #0x91
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xd
	strb r0, [r2]
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
_0801DA1E:
	mov r0, r8
	ldr r1, [r0]
	ldr r0, _0801DA48 @ =0x000001FF
	cmp r1, r0
	bls _0801DA62
_0801DA28:
	ldr r1, _0801DA4C @ =FUN_0801da7c
	adds r0, r5, #0
	bl FUN_0801d7f8
	b _0801DA6C
	.align 2, 0
_0801DA34: .4byte 0x03003584
_0801DA38: .4byte 0x000053E0
_0801DA3C: .4byte 0x00001314
_0801DA40: .4byte 0x00001302
_0801DA44: .4byte 0x030044E0
_0801DA48: .4byte 0x000001FF
_0801DA4C: .4byte FUN_0801da7c
_0801DA50:
	subs r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bne _0801DA62
	adds r0, r5, #0
	bl FUN_0801d338
_0801DA62:
	ldr r0, _0801DA78 @ =0x00001314
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0801DA6C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801DA78: .4byte 0x00001314

	thumb_func_start FUN_0801da7c
FUN_0801da7c: @ 0x0801DA7C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801d7d8
	cmp r0, #0
	beq _0801DAD0
	ldr r0, _0801DAF4 @ =0x00000E64
	adds r3, r4, r0
	ldr r0, _0801DAF8 @ =0x03003584
	ldr r2, [r0]
	ldr r1, _0801DAFC @ =0x000053E0
	adds r2, r2, r1
	ldr r0, [r3, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r3, #8]
	ldrh r2, [r2, #0x1e]
	ldr r1, _0801DB00 @ =0x00001302
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	adds r0, r4, #0
	adds r0, #0x88
	str r1, [r0]
	str r1, [r4, #0x7c]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
	adds r0, r4, #0
	bl FUN_0801d488
	adds r0, r4, #0
	bl FUN_0801d4c4
	ldr r0, _0801DB04 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0
	bl FUN_0807c7c8
_0801DAD0:
	adds r2, r4, #0
	adds r2, #0x84
	ldr r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	asrs r0, r0, #5
	str r0, [r2]
	ldr r0, _0801DB08 @ =0x00001314
	adds r1, r4, r0
	ldr r0, [r1]
	cmp r0, #0x1f
	bls _0801DB10
	ldr r1, _0801DB0C @ =FUN_0801d81c
	adds r0, r4, #0
	bl FUN_0801d7f8
	b _0801DB14
	.align 2, 0
_0801DAF4: .4byte 0x00000E64
_0801DAF8: .4byte 0x03003584
_0801DAFC: .4byte 0x000053E0
_0801DB00: .4byte 0x00001302
_0801DB04: .4byte 0x03002BE0
_0801DB08: .4byte 0x00001314
_0801DB0C: .4byte FUN_0801d81c
_0801DB10:
	adds r0, #1
	str r0, [r1]
_0801DB14:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801db1c
FUN_0801db1c: @ 0x0801DB1C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801DB74
	ldr r1, _0801DB9C @ =FUN_0801d81c
	adds r0, r5, #0
	bl FUN_0801d7f8
	adds r0, r5, #0
	adds r0, #0x84
	movs r1, #0
	str r1, [r0]
	str r1, [r5, #0x7c]
	adds r2, r5, #0
	adds r2, #0x80
	movs r0, #0x20
	str r0, [r2]
	ldr r0, [r5, #0x68]
	asrs r0, r0, #5
	str r0, [r5, #0x6c]
	adds r0, r5, #0
	adds r0, #0x66
	strb r1, [r0]
	adds r0, #0x3e
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x88
	movs r0, #2
	str r0, [r1]
	ldr r0, [r5, #0x6c]
	cmp r0, #0xa
	bls _0801DB70
	movs r0, #0xa
	str r0, [r5, #0x6c]
_0801DB70:
	ldr r0, [r5, #0x6c]
	str r0, [r5, #0x70]
_0801DB74:
	adds r4, r5, #0
	adds r4, #0x91
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0801DBA0 @ =0x00001318
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #0xb0
	lsls r2, r2, #5
	cmp r1, r2
	ble _0801DBA4
	str r2, [r0]
	b _0801DBAA
	.align 2, 0
_0801DB9C: .4byte FUN_0801d81c
_0801DBA0: .4byte 0x00001318
_0801DBA4:
	cmp r1, #0
	bge _0801DBAA
	str r6, [r0]
_0801DBAA:
	ldr r0, [r0]
	asrs r0, r0, #5
	adds r6, r5, #0
	adds r6, #0x62
	movs r7, #0
	adds r2, r0, #0
	strh r0, [r6]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801DC62
	adds r0, r5, #0
	adds r0, #0x60
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0
	ldrsh r0, [r6, r3]
	subs r4, r1, r0
	cmp r4, #0
	bge _0801DBD2
	rsbs r4, r4, #0
_0801DBD2:
	adds r0, r5, #0
	adds r0, #0x93
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_0801d4a8
	adds r1, r5, #0
	adds r1, #0xa0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x5c
	movs r2, #0
	ldrsh r1, [r6, r2]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	blt _0801DC50
	adds r0, r5, #0
	adds r0, #0x5e
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bgt _0801DC50
	cmp r4, #1
	bgt _0801DC28
	adds r1, r5, #0
	adds r1, #0x65
	movs r0, #1
	strb r0, [r1]
	adds r1, #0x43
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	subs r1, #4
	ldr r0, [r1]
	adds r0, #0x64
	str r0, [r1]
	adds r0, r5, #0
	adds r0, #0x92
	strb r7, [r0]
	b _0801DC62
_0801DC28:
	adds r0, r5, #0
	adds r0, #0x65
	strb r7, [r0]
	cmp r4, #0x63
	bgt _0801DC3E
	adds r1, r5, #0
	adds r1, #0xa4
	ldr r0, [r1]
	adds r0, #0x64
	subs r0, r0, r4
	str r0, [r1]
_0801DC3E:
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x92
	movs r0, #1
	b _0801DC60
_0801DC50:
	adds r0, r5, #0
	adds r0, #0xb0
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0x92
	movs r0, #2
_0801DC60:
	strb r0, [r1]
_0801DC62:
	adds r0, r5, #0
	bl FUN_0801d540
	adds r1, r5, #0
	adds r1, #0xb4
	ldr r0, [r1]
	cmp r0, #0
	bne _0801DC80
	ldr r1, _0801DC7C @ =FUN_0801dc90
	adds r0, r5, #0
	bl FUN_0801b8d0
	b _0801DC8A
	.align 2, 0
_0801DC7C: .4byte FUN_0801dc90
_0801DC80:
	subs r0, #1
	str r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #1
	str r0, [r5, #0x44]
_0801DC8A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801dc90
FUN_0801dc90: @ 0x0801DC90
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801DCAE
	adds r0, r4, #0
	movs r1, #9
	movs r2, #0
	movs r3, #0
	bl FUN_0801d4dc
	movs r0, #0xa9
	bl sound_08240264
_0801DCAE:
	adds r0, r4, #0
	bl FUN_0801d540
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0823b8ac
	ldr r0, [r4, #0x44]
	cmp r0, #0x1d
	bls _0801DCD0
	ldr r1, _0801DCCC @ =FUN_0801dcdc
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801DCD4
	.align 2, 0
_0801DCCC: .4byte FUN_0801dcdc
_0801DCD0:
	adds r0, #1
	str r0, [r4, #0x44]
_0801DCD4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801dcdc
FUN_0801dcdc: @ 0x0801DCDC
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801DD0C
	movs r1, #2
	add r0, sp, #4
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	add r3, sp, #4
	bl FUN_0801d4dc
	ldr r0, _0801DD68 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #3
	bl FUN_0807c7c8
	ldr r0, _0801DD6C @ =0x000002E1
	bl PlaySound_082406e0
_0801DD0C:
	adds r0, r4, #0
	bl FUN_0801d540
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0823b8ac
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	subs r0, #0x1e
	cmp r0, #0x45
	bhi _0801DD56
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _0801DD56
	ldr r0, _0801DD68 @ =0x03002BE0
	ldr r0, [r0]
	add r3, sp, #8
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldrh r0, [r3]
	adds r0, #0xc8
	strh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #6
	str r3, [sp]
	movs r0, #2
	movs r1, #0
	movs r3, #0x40
	bl FUN_08015c90
	ldr r0, _0801DD70 @ =0x000001C5
	bl PlaySound_082406e0
_0801DD56:
	ldr r0, [r4, #0x44]
	cmp r0, #0x63
	bls _0801DD78
	ldr r1, _0801DD74 @ =FUN_0801dd84
	adds r0, r4, #0
	bl FUN_0801b8d0
	b _0801DD7C
	.align 2, 0
_0801DD68: .4byte 0x03002BE0
_0801DD6C: .4byte 0x000002E1
_0801DD70: .4byte 0x000001C5
_0801DD74: .4byte FUN_0801dd84
_0801DD78:
	adds r0, #1
	str r0, [r4, #0x44]
_0801DD7C:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801dd84
FUN_0801dd84: @ 0x0801DD84
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	ldr r7, _0801DF18 @ =0x03002BE0
	ldr r4, [r7]
	adds r5, r4, #0
	bl FUN_0801b8e8
	cmp r0, #0
	beq _0801DDC4
	adds r0, r6, #0
	bl FUN_0801bcd8
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	str r0, [r6, #0x28]
	str r1, [r6, #0x2c]
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r6, #0x30]
	str r1, [r6, #0x34]
	adds r1, r6, #0
	adds r1, #0x94
	movs r0, #4
	strb r0, [r1]
	ldr r0, [r7]
	movs r1, #4
	bl FUN_0807b910
_0801DDC4:
	adds r0, r6, #0
	bl FUN_0801d540
	ldr r3, [r6, #0x44]
	adds r4, r6, #0
	adds r4, #0x18
	cmp r3, #0x20
	bhi _0801DDE6
	adds r1, r6, #0
	adds r1, #0x28
	adds r2, r6, #0
	adds r2, #0x30
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08237970
_0801DDE6:
	adds r0, r4, #0
	bl FUN_0823b8ac
	ldr r0, [r6, #0x44]
	cmp r0, #0x1e
	bne _0801DE12
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	movs r0, #0
	str r0, [sp]
	add r0, sp, #0x1c
	movs r1, #0x40
	movs r2, #0x3c
	movs r3, #8
	bl FUN_08019814
	movs r0, #0xa7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0801DE12:
	ldr r0, [r6, #0x44]
	cmp r0, #0x5a
	bne _0801DE68
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r4, r6, r0
	ldr r0, [r7]
	add r2, sp, #0x24
	adds r3, r0, #0
	adds r3, #0x2c
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	ldrh r0, [r2]
	subs r0, #0x20
	strh r0, [r2]
	ldrh r0, [r2, #4]
	adds r0, #0x20
	strh r0, [r2, #4]
	ldrh r0, [r2, #2]
	adds r0, #0x80
	strh r0, [r2, #2]
	ldrb r1, [r4]
	str r2, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080177b4
	ldr r0, [r7]
	movs r1, #0
	movs r2, #0
	bl FUN_0807bbb0
	movs r0, #0x88
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0801DE68:
	ldr r0, [r6, #0x44]
	cmp r0, #0x60
	beq _0801DE70
	b _0801DF72
_0801DE70:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r5, r6, r0
	ldr r4, [r7]
	cmp r4, #0
	beq _0801DF72
	ldrb r0, [r5, #2]
	cmp r0, #4
	bne _0801DF72
	ldrh r0, [r4, #0x2c]
	ldr r3, _0801DF1C @ =0xFFFF0000
	ldr r2, [sp, #0x2c]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0x2c]
	movs r0, #0xbd
	lsls r0, r0, #1
	adds r1, r0, #0
	ldrh r0, [r4, #0x2e]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0801DF20 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x2c]
	ldrh r2, [r4, #0x30]
	add r1, sp, #0x2c
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldrb r0, [r5]
	mov sb, r1
	cmp r0, #5
	beq _0801DF72
	cmp r0, #0x18
	beq _0801DF72
	cmp r0, #0x2b
	beq _0801DF72
	cmp r0, #0x13
	beq _0801DECA
	cmp r0, #0x26
	beq _0801DECA
	cmp r0, #0x39
	bne _0801DF28
_0801DECA:
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _0801DF24 @ =0x00000FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #3
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
	movs r0, #0x58
	mov r8, r0
	movs r4, #8
	movs r7, #0
	movs r5, #2
_0801DEEA:
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	movs r0, #0xc
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #4
	movs r1, #0x86
	lsls r1, r1, #2
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080149dc
	adds r7, #0x58
	subs r5, #1
	cmp r5, #0
	bge _0801DEEA
	b _0801DF72
	.align 2, 0
_0801DF18: .4byte 0x03002BE0
_0801DF1C: .4byte 0xFFFF0000
_0801DF20: .4byte 0x0000FFFF
_0801DF24: .4byte 0x00000FFF
_0801DF28:
	movs r0, #7
	str r0, [sp]
	ldr r0, _0801DF90 @ =0x00000FFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #3
	movs r2, #0x1f
	movs r3, #0x17
	bl FUN_0823ce68
	movs r0, #0x58
	mov r8, r0
	movs r4, #8
	movs r7, #0
	movs r5, #2
_0801DF48:
	mov r0, r8
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	movs r0, #0xc
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #4
	movs r1, #0x86
	lsls r1, r1, #2
	mov r2, sb
	adds r3, r7, #0
	bl FUN_080149dc
	adds r7, #0x58
	subs r5, #1
	cmp r5, #0
	bge _0801DF48
_0801DF72:
	ldr r0, [r6, #0x44]
	cmp r0, #0xa3
	bls _0801DF9C
	ldr r1, _0801DF94 @ =FUN_0801dfb0
	adds r0, r6, #0
	bl FUN_0801b8d0
	ldr r0, _0801DF98 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r6, #0
	adds r1, #0x94
	ldrb r1, [r1]
	bl FUN_0807b910
	b _0801DFA0
	.align 2, 0
_0801DF90: .4byte 0x00000FFF
_0801DF94: .4byte FUN_0801dfb0
_0801DF98: .4byte 0x03002BE0
_0801DF9C:
	adds r0, #1
	str r0, [r6, #0x44]
_0801DFA0:
	add sp, #0x34
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801dfb0
FUN_0801dfb0: @ 0x0801DFB0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	adds r0, #1
	str r0, [r4, #0x44]
	cmp r0, #0x3c
	bne _0801DFD0
	adds r0, r4, #0
	adds r0, #0xba
	ldrh r0, [r0]
	cmp r0, #0
	beq _0801DFD0
	adds r0, r4, #0
	bl FUN_0801c01c
	b _0801DFDE
_0801DFD0:
	adds r0, r4, #0
	bl FUN_0801d540
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0823b8ac
_0801DFDE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801dfe4
FUN_0801dfe4: @ 0x0801DFE4
	push {lr}
	ldr r0, _0801DFFC @ =0x03000098
	ldr r0, [r0]
	cmp r0, #0
	beq _0801DFF8
	adds r1, r0, #0
	adds r1, #0x65
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801E000
_0801DFF8:
	movs r0, #0
	b _0801E006
	.align 2, 0
_0801DFFC: .4byte 0x03000098
_0801E000:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
_0801E006:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0801e00c
FUN_0801e00c: @ 0x0801E00C
	push {lr}
	ldr r0, _0801E01C @ =0x03000098
	ldr r0, [r0]
	cmp r0, #0
	beq _0801E020
	adds r0, #0x92
	ldrb r0, [r0]
	b _0801E022
	.align 2, 0
_0801E01C: .4byte 0x03000098
_0801E020:
	movs r0, #2
_0801E022:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityDA0B_Update
EntityDA0B_Update: @ 0x0801E028
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0824175c
	str r0, [r4, #0x6c]
	ldr r1, _0801E048 @ =0x00001304
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801E048: .4byte 0x00001304

	thumb_func_start EntityDA0B_Destroy
EntityDA0B_Destroy: @ 0x0801E04C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0801c5d0
	adds r0, r4, #0
	bl FUN_0801c434
	adds r0, r4, #0
	bl FUN_0801c454
	adds r0, r4, #0
	bl FUN_0801c474
	adds r0, r4, #0
	bl FUN_0801d6a0
	bl FUN_08049f84
	ldr r1, _0801E07C @ =0x03000098
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801E07C: .4byte 0x03000098

	thumb_func_start EntityDA0B_Init
EntityDA0B_Init: @ 0x0801E080
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r0, _0801E13C @ =0x03000098
	str r4, [r0]
	ldr r0, _0801E140 @ =0x0000CB05
	mov r8, r0
	ldr r1, _0801E144 @ =0x0000414C
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0801E09E
	b _0801E1A6
_0801E09E:
	adds r0, r4, #0
	adds r0, #0xd8
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6}
	stm r2!, {r5, r6}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801E148 @ =0x0000B343
	mov r0, r8
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801E1A6
	adds r0, r4, #0
	adds r0, #0xf8
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801E14C @ =0x00005D04
	mov r0, r8
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0801E1A6
	movs r6, #0x8c
	lsls r6, r6, #1
	adds r0, r4, r6
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r2!, {r5, r6, r7}
	ldm r1!, {r5, r7}
	stm r2!, {r5, r7}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0801E150 @ =0x0000B156
	movs r0, #0x6e
	bl Script_GetKeywordValue
	ldr r6, _0801E154 @ =0x0000131C
	adds r1, r4, r6
	strh r0, [r1]
	ldr r7, _0801E158 @ =0x0000131E
	adds r1, r4, r7
	movs r0, #5
	strh r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0801E15C
	bl Script_GetValue
	strh r0, [r4, #0x18]
	bl Script_GetValue
	strh r0, [r4, #0x1a]
	bl Script_GetValue
	b _0801E160
	.align 2, 0
_0801E13C: .4byte 0x03000098
_0801E140: .4byte 0x0000CB05
_0801E144: .4byte 0x0000414C
_0801E148: .4byte 0x0000B343
_0801E14C: .4byte 0x00005D04
_0801E150: .4byte 0x0000B156
_0801E154: .4byte 0x0000131C
_0801E158: .4byte 0x0000131E
_0801E15C:
	strh r0, [r4, #0x18]
	strh r0, [r4, #0x1a]
_0801E160:
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, [r4, #0x18]
	ldr r2, [r4, #0x1c]
	str r1, [r4, #0x20]
	str r2, [r4, #0x24]
	bl FUN_0823b8ac
	movs r0, #0x63
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0xb8
	strh r0, [r1]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r4, #0
	adds r1, #0xba
	strh r0, [r1]
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _0801E1A6
	bl FUN_0823d340
	ldr r2, _0801E1AC @ =0x00001308
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	bne _0801E1B0
_0801E1A6:
	movs r0, #1
	rsbs r0, r0, #0
	b _0801E206
	.align 2, 0
_0801E1AC: .4byte 0x00001308
_0801E1B0:
	movs r0, #0x6b
	bl prepare_08231510
	cmp r0, #0
	beq _0801E1A6
	bl FUN_0823d340
	ldr r5, _0801E210 @ =0x0000130C
	adds r1, r4, r5
	str r0, [r1]
	cmp r0, #0
	beq _0801E1A6
	adds r0, r4, #0
	bl FUN_0801c260
	adds r0, r4, #0
	bl FUN_0801c4bc
	adds r0, r4, #0
	bl FUN_0801c204
	adds r0, r4, #0
	bl FUN_0801c2bc
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r4, #0
	bl FUN_0801c910
	adds r0, r4, #0
	bl FUN_0801d084
	ldr r1, _0801E214 @ =FUN_0801c9e4
	adds r0, r4, #0
	bl FUN_0801b8d0
	bl FUN_08049f5c
	movs r0, #0
_0801E206:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801E210: .4byte 0x0000130C
_0801E214: .4byte FUN_0801c9e4

	thumb_func_start EntityDA0B_Create
EntityDA0B_Create: @ 0x0801E218
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _0801E254 @ =0x03000098
	ldr r0, [r0]
	cmp r0, #0
	bne _0801E266
	ldr r1, _0801E258 @ =0x00001364
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801E264
	ldr r1, _0801E25C @ =EntityDA0B_Update
	ldr r2, _0801E260 @ =EntityDA0B_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl EntityDA0B_Init
	cmp r0, #0
	bge _0801E264
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801E266
	.align 2, 0
_0801E254: .4byte 0x03000098
_0801E258: .4byte 0x00001364
_0801E25C: .4byte EntityDA0B_Update
_0801E260: .4byte EntityDA0B_Destroy
_0801E264:
	adds r0, r4, #0
_0801E266:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

