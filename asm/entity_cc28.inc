	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080917e4
FUN_080917e4: @ 0x080917E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r2
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r7, r2
	ldr r6, [r0]
	cmp r6, #0
	beq _08091856
	ldr r3, _0809182C @ =0x00000366
	adds r5, r6, r3
	ldrh r0, [r5]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	ldr r2, _08091830 @ =0x00003FA2
	adds r1, r7, r2
	strh r0, [r1]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r2, r6, r3
	ldrh r4, [r2]
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r3, r4, r0
	ldrh r0, [r5]
	cmp r3, r0
	ble _08091834
	subs r0, r0, r4
	strh r0, [r1]
	ldrh r0, [r5]
	strh r0, [r2]
	b _08091836
	.align 2, 0
_0809182C: .4byte 0x00000366
_08091830: .4byte 0x00003FA2
_08091834:
	strh r3, [r2]
_08091836:
	adds r0, r7, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	mov r0, r8
	cmp r0, #0
	ble _08091856
	lsls r2, r0, #4
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08063574
_08091856:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08091860
FUN_08091860: @ 0x08091860
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	mov sb, r1
	adds r7, r2, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	beq _0809192E
	ldr r4, _080918BC @ =0x0000036A
	add r4, r8
	ldrh r0, [r4]
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x64
	bl Div
	ldr r1, _080918C0 @ =0x00003FA2
	adds r6, r5, r1
	strh r0, [r6]
	ldrh r0, [r4]
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	movs r1, #0x64
	bl Div
	movs r2, #0xda
	lsls r2, r2, #2
	add r2, r8
	ldrh r3, [r2]
	adds r1, r3, r0
	ldrh r0, [r4]
	cmp r1, r0
	ble _080918C4
	subs r0, r0, r3
	strh r0, [r6]
	ldrh r0, [r4]
	strh r0, [r2]
	b _080918D0
	.align 2, 0
_080918BC: .4byte 0x0000036A
_080918C0: .4byte 0x00003FA2
_080918C4:
	cmp r1, #0
	bge _080918CE
	movs r0, #0
	strh r0, [r2]
	b _080918D0
_080918CE:
	strh r1, [r2]
_080918D0:
	ldr r0, _08091914 @ =0x00003FA2
	adds r1, r5, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _080918E0
	movs r0, #0
	strh r0, [r1]
_080918E0:
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	cmp r7, #0
	ble _0809192E
	ldr r1, _08091918 @ =0x00003F9C
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r2, _0809191C @ =0x00003AEE
	adds r1, r5, r2
	ldrb r1, [r1]
	bl GetItemID
	cmp r0, #0xb
	bne _08091920
	lsls r2, r7, #4
	subs r2, r2, r7
	lsls r2, r2, #2
	mov r0, r8
	movs r1, #2
	bl FUN_08063574
	b _0809192E
	.align 2, 0
_08091914: .4byte 0x00003FA2
_08091918: .4byte 0x00003F9C
_0809191C: .4byte 0x00003AEE
_08091920:
	lsls r2, r7, #4
	subs r2, r2, r7
	lsls r2, r2, #2
	mov r0, r8
	movs r1, #0
	bl FUN_08063574
_0809192E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809193c
FUN_0809193c: @ 0x0809193C
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	adds r6, r1, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _08091992
	ldr r0, _08091998 @ =0x00003FA2
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	movs r4, #0
	movs r7, #1
_0809195A:
	adds r0, r6, #0
	asrs r0, r4
	ands r0, r7
	cmp r0, #0
	beq _0809196C
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08063634
_0809196C:
	adds r4, #1
	cmp r4, #2
	ble _0809195A
	movs r0, #8
	ands r0, r6
	cmp r0, #0
	beq _08091992
	ldr r1, _0809199C @ =0x0000038E
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _080919A0 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
_08091992:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091998: .4byte 0x00003FA2
_0809199C: .4byte 0x0000038E
_080919A0: .4byte 0x030046A0

	thumb_func_start FUN_080919a4
FUN_080919a4: @ 0x080919A4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _08091A08
	ldr r2, _08091A10 @ =0x00003F9C
	adds r0, r5, r2
	ldrb r0, [r0]
	ldr r3, _08091A14 @ =0x00003AEE
	adds r1, r5, r3
	ldrb r1, [r1]
	bl GetItemID
	ldr r2, _08091A18 @ =0x00000444
	adds r1, r4, r2
	movs r2, #0
	strh r0, [r1]
	ldr r3, _08091A1C @ =0x00000442
	adds r0, r4, r3
	strh r7, [r0]
	lsls r0, r6, #4
	subs r0, r0, r6
	lsls r0, r0, #2
	adds r3, #4
	adds r1, r4, r3
	strh r0, [r1]
	ldr r0, _08091A20 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _08091A24 @ =0x00000121
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #0x30
	strh r0, [r1]
	ldr r1, _08091A28 @ =0x00003FA2
	adds r0, r5, r1
	strh r2, [r0]
	ldr r2, _08091A2C @ =0x00000A95
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08091A30 @ =0x00003AE4
	adds r0, r5, r3
	strb r1, [r0]
_08091A08:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091A10: .4byte 0x00003F9C
_08091A14: .4byte 0x00003AEE
_08091A18: .4byte 0x00000444
_08091A1C: .4byte 0x00000442
_08091A20: .4byte 0x0000095E
_08091A24: .4byte 0x00000121
_08091A28: .4byte 0x00003FA2
_08091A2C: .4byte 0x00000A95
_08091A30: .4byte 0x00003AE4

	thumb_func_start FUN_08091a34
FUN_08091a34: @ 0x08091A34
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r2, #0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r6, [r0]
	cmp r6, #0
	beq _08091ABC
	cmp r1, #3
	bgt _08091A58
	ldr r2, _08091A54 @ =0x00003F9E
	adds r0, r5, r2
	strb r1, [r0]
	b _08091A7A
	.align 2, 0
_08091A54: .4byte 0x00003F9E
_08091A58:
	ldr r2, _08091AC4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08091AC8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08091ACC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #4
	bl Mod
	ldr r2, _08091AD0 @ =0x00003F9E
	adds r1, r5, r2
	strb r0, [r1]
_08091A7A:
	ldr r1, _08091AD4 @ =0x00003F9F
	adds r0, r5, r1
	strb r4, [r0]
	ldrb r2, [r0]
	subs r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _08091AD8 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r1, r0, r1
	movs r0, #0x18
	ldrsh r4, [r1, r0]
	movs r0, #0x20
	ldrsh r3, [r1, r0]
	adds r0, r4, r3
	adds r0, r0, r2
	cmp r0, #0x63
	ble _08091AA6
	movs r0, #0x63
	subs r0, r0, r3
	subs r2, r0, r4
_08091AA6:
	ldrh r0, [r1, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	adds r0, r6, #0
	bl FUN_080612bc
	adds r0, r5, #0
	movs r1, #5
	movs r2, #3
	bl FUN_0808b604
_08091ABC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08091AC4: .4byte 0x030046B8
_08091AC8: .4byte 0x000003FF
_08091ACC: .4byte 0x0203B400
_08091AD0: .4byte 0x00003F9E
_08091AD4: .4byte 0x00003F9F
_08091AD8: .4byte 0x030046A0

	thumb_func_start FUN_08091adc
FUN_08091adc: @ 0x08091ADC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _08091B2C
	ldr r5, _08091B0C @ =0x00003FAD
	adds r3, r4, r5
	strb r1, [r3]
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #5
	bne _08091B18
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08091B10
	movs r0, #2
	b _08091B16
	.align 2, 0
_08091B0C: .4byte 0x00003FAD
_08091B10:
	cmp r0, #2
	bne _08091B18
	movs r0, #0
_08091B16:
	strb r0, [r3]
_08091B18:
	ldr r1, _08091B34 @ =0x00003FAE
	adds r0, r4, r1
	strh r2, [r0]
	ldr r2, _08091B38 @ =0x00003FAC
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08091B3C @ =0x00003AE4
	adds r0, r4, r3
	strb r1, [r0]
_08091B2C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08091B34: .4byte 0x00003FAE
_08091B38: .4byte 0x00003FAC
_08091B3C: .4byte 0x00003AE4

	thumb_func_start FUN_08091b40
FUN_08091b40: @ 0x08091B40
	push {r4, lr}
	ldr r3, _08091B5C @ =0x00003FB0
	adds r2, r0, r3
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08091B60 @ =0x00003FB1
	adds r2, r0, r4
	strb r1, [r2]
	ldr r1, _08091B64 @ =0x00003AE4
	adds r0, r0, r1
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091B5C: .4byte 0x00003FB0
_08091B60: .4byte 0x00003FB1
_08091B64: .4byte 0x00003AE4

	thumb_func_start FUN_08091b68
FUN_08091b68: @ 0x08091B68
	push {lr}
	ldr r1, _08091B8C @ =0x00003F9D
	adds r0, r0, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08091B98
	ldr r2, _08091B90 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xac
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
	ldr r0, [r2]
	ldr r1, _08091B94 @ =0x000002B2
	adds r0, r0, r1
	strh r3, [r0]
	b _08091BB0
	.align 2, 0
_08091B8C: .4byte 0x00003F9D
_08091B90: .4byte 0x030046A0
_08091B94: .4byte 0x000002B2
_08091B98:
	ldr r2, _08091BB4 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xac
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r2]
	ldr r1, _08091BB8 @ =0x000002B2
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
_08091BB0:
	pop {r0}
	bx r0
	.align 2, 0
_08091BB4: .4byte 0x030046A0
_08091BB8: .4byte 0x000002B2

	thumb_func_start FUN_08091bbc
FUN_08091bbc: @ 0x08091BBC
	ldr r1, _08091BD4 @ =0x00003FA2
	adds r2, r0, r1
	movs r1, #0
	strh r1, [r2]
	ldr r2, _08091BD8 @ =0x0000401D
	adds r1, r0, r2
	movs r2, #1
	strb r2, [r1]
	ldr r1, _08091BDC @ =0x00003AE4
	adds r0, r0, r1
	strb r2, [r0]
	bx lr
	.align 2, 0
_08091BD4: .4byte 0x00003FA2
_08091BD8: .4byte 0x0000401D
_08091BDC: .4byte 0x00003AE4

	thumb_func_start FUN_08091be0
FUN_08091be0: @ 0x08091BE0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r1, [r2]
	ldr r3, _08091C30 @ =0x00003FA6
	adds r0, r4, r3
	ldrh r0, [r0]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r5, #0
	strh r0, [r1]
	ldr r0, [r2]
	ldr r6, _08091C34 @ =0x00003FAA
	adds r1, r4, r6
	ldrh r1, [r1]
	movs r6, #0xda
	lsls r6, r6, #2
	adds r0, r0, r6
	strh r1, [r0]
	ldr r0, [r2]
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08091C40
	ldr r1, _08091C38 @ =0x00003AE4
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x30
	bl CheckItemOwn
	cmp r0, #0
	beq _08091C46
	ldr r3, _08091C3C @ =0x00003FBB
	adds r0, r4, r3
	b _08091C44
	.align 2, 0
_08091C30: .4byte 0x00003FA6
_08091C34: .4byte 0x00003FAA
_08091C38: .4byte 0x00003AE4
_08091C3C: .4byte 0x00003FBB
_08091C40:
	ldr r6, _08091C4C @ =0x00003FBB
	adds r0, r4, r6
_08091C44:
	strb r5, [r0]
_08091C46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08091C4C: .4byte 0x00003FBB

	thumb_func_start FUN_08091c50
FUN_08091c50: @ 0x08091C50
	push {r4, lr}
	ldr r3, _08091C6C @ =0x00003FB8
	adds r2, r0, r3
	movs r3, #1
	strb r3, [r2]
	ldr r4, _08091C70 @ =0x00003FB9
	adds r2, r0, r4
	strb r1, [r2]
	ldr r1, _08091C74 @ =0x00003AE4
	adds r0, r0, r1
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08091C6C: .4byte 0x00003FB8
_08091C70: .4byte 0x00003FB9
_08091C74: .4byte 0x00003AE4

	thumb_func_start FUN_08091c78
FUN_08091c78: @ 0x08091C78
	push {r4, lr}
	movs r4, #0
_08091C7C:
	adds r0, r4, #0
	movs r1, #0
	bl SetRotCount2
	adds r4, #1
	cmp r4, #0xf
	ble _08091C7C
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08091c90
FUN_08091c90: @ 0x08091C90
	push {lr}
	ldr r0, _08091CB4 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl GetWeapon
	movs r1, #0
	strh r1, [r0, #2]
	pop {r0}
	bx r0
	.align 2, 0
_08091CB4: .4byte 0x030046A0

	thumb_func_start FUN_08091cb8
FUN_08091cb8: @ 0x08091CB8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08091CE0 @ =0x03002BE0
	ldr r5, [r0]
	cmp r5, #0
	bne _08091CC6
	b _08091E26
_08091CC6:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08091CE4
	adds r0, r4, #0
	bl item_08091774
	cmp r0, #1
	bne _08091CFA
	b _08091E26
	.align 2, 0
_08091CE0: .4byte 0x03002BE0
_08091CE4:
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08091CFA
	adds r0, r4, #0
	bl item_08091774
	cmp r0, #0
	bne _08091CFA
	b _08091E26
_08091CFA:
	cmp r4, #0x1e
	bne _08091D06
	movs r0, #0
_08091D00:
	bl FUN_080916bc
	b _08091E22
_08091D06:
	cmp r4, #0x1f
	bne _08091D0E
	movs r0, #1
	b _08091D00
_08091D0E:
	adds r0, r4, #0
	subs r0, #0x1b
	cmp r0, #2
	bhi _08091D1A
	movs r0, #2
	b _08091D00
_08091D1A:
	cmp r4, #0x31
	bne _08091D22
	movs r0, #3
	b _08091D00
_08091D22:
	cmp r4, #1
	bne _08091D32
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _08091D82
_08091D32:
	adds r0, r4, #0
	bl item_08091788
	subs r0, #1
	cmp r0, #4
	bhi _08091E26
	lsls r0, r0, #2
	ldr r1, _08091D48 @ =_08091D4C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08091D48: .4byte _08091D4C
_08091D4C: @ jump table
	.4byte _08091D82 @ case 0
	.4byte _08091D60 @ case 1
	.4byte _08091D70 @ case 2
	.4byte _08091D8C @ case 3
	.4byte _08091DEC @ case 4
_08091D60:
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, _08091D6C @ =0x00000366
	b _08091D78
	.align 2, 0
_08091D6C: .4byte 0x00000366
_08091D70:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, _08091D88 @ =0x0000036A
_08091D78:
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08091E26
_08091D82:
	movs r0, #1
	b _08091E28
	.align 2, 0
_08091D88: .4byte 0x0000036A
_08091D8C:
	movs r2, #0
	ldr r1, _08091DDC @ =0x08DAA8D8
	lsls r0, r4, #4
	adds r3, r0, r1
	ldr r0, _08091DE0 @ =0x0000043C
	adds r1, r5, r0
	movs r6, #1
_08091D9A:
	ldrh r0, [r1]
	cmp r0, #0
	beq _08091DAA
	ldrh r0, [r3, #6]
	asrs r0, r2
	ands r0, r6
	cmp r0, #0
	bne _08091D82
_08091DAA:
	adds r1, #2
	adds r2, #1
	cmp r2, #2
	ble _08091D9A
	ldr r1, _08091DE4 @ =0x0000038E
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r1, _08091DE8 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	ble _08091E26
	ldr r1, _08091DDC @ =0x08DAA8D8
	lsls r0, r4, #4
	adds r0, r0, r1
	ldrh r1, [r0, #6]
	movs r0, #8
	ands r0, r1
	b _08091E22
	.align 2, 0
_08091DDC: .4byte 0x08DAA8D8
_08091DE0: .4byte 0x0000043C
_08091DE4: .4byte 0x0000038E
_08091DE8: .4byte 0x030046A0
_08091DEC:
	ldr r0, _08091E30 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x60
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _08091E26
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl GetWeapon
	adds r1, r0, #0
	movs r0, #1
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bgt _08091D82
	ldrb r0, [r1, #0x14]
	cmp r0, #0
	bne _08091D82
	ldrb r0, [r1, #0x18]
_08091E22:
	cmp r0, #0
	bne _08091D82
_08091E26:
	movs r0, #0
_08091E28:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08091E30: .4byte 0x030046A0

	thumb_func_start FUN_08091e34
FUN_08091e34: @ 0x08091E34
	push {lr}
	bl item_0809179c
	cmp r0, #1
	beq _08091E42
	movs r0, #0
	b _08091E44
_08091E42:
	movs r0, #1
_08091E44:
	pop {r1}
	bx r1

	thumb_func_start FUN_08091e48
FUN_08091e48: @ 0x08091E48
	push {lr}
	ldr r2, _08091E60 @ =0x00003F9C
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08091E5A
	adds r0, r1, #0
	bl RemoveItem
_08091E5A:
	pop {r0}
	bx r0
	.align 2, 0
_08091E60: .4byte 0x00003F9C

	thumb_func_start FUN_08091e64
FUN_08091e64: @ 0x08091E64
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	ldr r1, _08091EE8 @ =0x00003F9C
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r7, #0
	bl GetItemID
	adds r4, r0, #0
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08091F24
	cmp r4, #1
	bls _08091EB6
	cmp r4, #3
	beq _08091EB6
	cmp r4, #2
	beq _08091EB6
	cmp r4, #4
	beq _08091EB6
	cmp r4, #6
	beq _08091EB6
	cmp r4, #7
	beq _08091EB6
	cmp r4, #8
	beq _08091EB6
	cmp r4, #9
	beq _08091EB6
	cmp r4, #0xa
	bne _08091EF0
_08091EB6:
	movs r2, #0xe1
	lsls r2, r2, #3
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r3, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08091ED6
	lsls r2, r2, #1
_08091ED6:
	adds r0, r3, #0
	movs r1, #0
	bl FUN_08063574
	ldr r0, _08091EEC @ =0x00003FA2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	b _08091FEC
	.align 2, 0
_08091EE8: .4byte 0x00003F9C
_08091EEC: .4byte 0x00003FA2
_08091EF0:
	cmp r4, #0xb
	bne _08091F24
	movs r2, #0xe1
	lsls r2, r2, #2
	movs r1, #0x80
	lsls r1, r1, #5
	movs r4, #0xde
	lsls r4, r4, #2
	adds r0, r3, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08091F0C
	lsls r2, r2, #1
_08091F0C:
	adds r0, r3, #0
	movs r1, #2
	bl FUN_08063574
	ldr r0, _08091F20 @ =0x00003FA2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	b _08091FEC
	.align 2, 0
_08091F20: .4byte 0x00003FA2
_08091F24:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08091F50
	cmp r4, #0xd
	bne _08091F50
	movs r4, #8
	ldr r1, _08091F4C @ =0x08DAA8D8
	adds r0, r1, #0
	adds r0, #0x80
	ldrh r6, [r0, #6]
	ldrh r2, [r0, #8]
	adds r3, r1, #0
	b _08091FC0
	.align 2, 0
_08091F4C: .4byte 0x08DAA8D8
_08091F50:
	ldr r1, _08091FA4 @ =0x08DAA8D8
	lsls r0, r4, #4
	adds r0, r0, r1
	ldrh r6, [r0, #6]
	ldrh r2, [r0, #8]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r5, r3
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r3, r1, #0
	cmp r0, #5
	bne _08091F76
	cmp r4, #1
	bne _08091F76
	rsbs r6, r6, #0
_08091F76:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	mov ip, r1
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _08091FC0
	cmp r4, #1
	bls _08091FA0
	cmp r4, #8
	beq _08091FA0
	cmp r4, #0xb
	bne _08091FA8
_08091FA0:
	lsls r6, r6, #1
	b _08091FBE
	.align 2, 0
_08091FA4: .4byte 0x08DAA8D8
_08091FA8:
	subs r0, r4, #2
	cmp r0, #2
	bls _08091FBE
	cmp r4, #6
	beq _08091FBE
	cmp r4, #7
	beq _08091FBE
	cmp r4, #9
	beq _08091FBE
	cmp r4, #0xa
	bne _08091FC0
_08091FBE:
	lsls r2, r2, #1
_08091FC0:
	ldr r1, _08091FF8 @ =0x085ACF7C
	lsls r0, r4, #4
	adds r0, r0, r3
	ldrh r0, [r0, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	bl _call_via_r3
	cmp r4, #0x14
	bne _08091FFC
	adds r0, r7, #0
	bl UncoverChocolate
	movs r0, #0
	adds r1, r7, #0
	bl GetItemID
	cmp r0, #0x14
	bne _08092004
_08091FEC:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08091e48
	b _08092004
	.align 2, 0
_08091FF8: .4byte 0x085ACF7C
_08091FFC:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08091e48
_08092004:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809200c
FUN_0809200c: @ 0x0809200C
	push {lr}
	ldr r3, _08092024 @ =0x00003F9C
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08092028
	adds r0, r1, #0
	adds r1, r2, #0
	bl SwapNormalItem
	b _08092030
	.align 2, 0
_08092024: .4byte 0x00003F9C
_08092028:
	adds r0, r1, #0
	adds r1, r2, #0
	bl SwapValuable
_08092030:
	pop {r0}
	bx r0

	thumb_func_start item_08092034
item_08092034: @ 0x08092034
	push {r4, r5, lr}
	adds r5, r0, #0
	bl GetNormalItemID
	cmp r0, #0
	blt _0809204C
	ldr r1, _08092050 @ =0x08DAA8D8
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrh r4, [r0, #4]
	cmp r4, #0
	bne _08092054
_0809204C:
	movs r0, #0xcf
	b _0809206A
	.align 2, 0
_08092050: .4byte 0x08DAA8D8
_08092054:
	adds r0, r5, #0
	bl GetRotCount2
	lsls r0, r0, #2
	lsls r1, r4, #5
	bl Div
	cmp r0, #3
	ble _08092068
	movs r0, #3
_08092068:
	adds r0, #0xd0
_0809206A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08092070
FUN_08092070: @ 0x08092070
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0809209C @ =0x00003AEB
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, #0xf
	bhi _080920A4
	ldr r1, _080920A0 @ =0x00003F9C
	adds r4, r6, r1
	ldrb r0, [r4]
	ldrb r1, [r5]
	bl GetItemID
	adds r7, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	bne _080920A8
	ldrb r0, [r5]
	bl item_08092034
	adds r3, r0, #0
	b _080920AA
	.align 2, 0
_0809209C: .4byte 0x00003AEB
_080920A0: .4byte 0x00003F9C
_080920A4:
	movs r7, #1
	rsbs r7, r7, #0
_080920A8:
	movs r3, #0xcf
_080920AA:
	cmp r7, #0
	bge _080920C8
	ldr r1, _080920C4 @ =0x0000204C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080921A0
	.align 2, 0
_080920C4: .4byte 0x0000204C
_080920C8:
	ldr r0, _08092124 @ =0x0000204C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08092128 @ =0x00002044
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0xa0
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r6, #0x40]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r7, #0
	bl FUN_08047a28
	bl FUN_08049f5c
	ldr r0, [r6, #0x40]
	bl VM_ParseStringRef
	adds r2, r0, #0
	cmp r7, #0x32
	bne _08092130
	ldr r0, _0809212C @ =0x00003FA0
	adds r1, r6, r0
	adds r0, r2, #0
	adds r0, #0xeb
	ldrb r1, [r1]
	adds r0, r0, r1
	b _08092168
	.align 2, 0
_08092124: .4byte 0x0000204C
_08092128: .4byte 0x00002044
_0809212C: .4byte 0x00003FA0
_08092130:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0809214E
	cmp r7, #1
	bne _0809214E
	adds r0, r2, #0
	adds r0, #0xea
	b _08092168
_0809214E:
	ldr r0, _08092174 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #5
	bne _08092178
	cmp r7, #0xd
	bne _08092178
	adds r0, r2, #0
	adds r0, #0xa9
_08092168:
	bl Textbox_LookupString
	bl FUN_08049e30
	b _080921A0
	.align 2, 0
_08092174: .4byte 0x030046A0
_08092178:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08092190
	cmp r0, #5
	bne _08092194
_08092190:
	adds r2, #0x4e
	b _08092196
_08092194:
	adds r2, #0x9c
_08092196:
	adds r0, r2, r7
	bl Textbox_LookupString
	bl FUN_08049e30
_080921A0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080921a8
FUN_080921a8: @ 0x080921A8
	push {lr}
	ldr r2, _080921D4 @ =0x00003F9C
	adds r1, r0, r2
	ldrb r2, [r1]
	ldr r1, _080921D8 @ =0x00003AEE
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	bl GetItemID
	ldr r1, _080921DC @ =0x08DAA8D8
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _080921E0
	movs r0, #0
	b _080921E2
	.align 2, 0
_080921D4: .4byte 0x00003F9C
_080921D8: .4byte 0x00003AEE
_080921DC: .4byte 0x08DAA8D8
_080921E0:
	movs r0, #1
_080921E2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080921e8
FUN_080921e8: @ 0x080921E8
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _0809220C
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r3]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	b _08092236
_0809220C:
	cmp r2, #0x15
	bne _08092218
	movs r0, #0x78
	strh r0, [r3]
	movs r0, #0x68
	b _08092236
_08092218:
	cmp r2, #0x14
	bne _08092224
	movs r0, #0x75
	strh r0, [r3]
	movs r0, #0x46
	b _08092236
_08092224:
	cmp r2, #0x10
	bne _08092230
	movs r0, #0x1c
	strh r0, [r3]
	movs r0, #0x58
	b _08092236
_08092230:
	movs r0, #0x90
	strh r0, [r3]
	movs r0, #0x20
_08092236:
	strh r0, [r3, #2]
	pop {r0}
	bx r0

	thumb_func_start FUN_0809223c
FUN_0809223c: @ 0x0809223C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0
	mov r8, r0
	ldr r1, _08092278 @ =0x00003F9C
	adds r1, r1, r6
	mov sb, r1
	ldr r0, _0809227C @ =0x000015C4
	adds r5, r6, r0
	movs r7, #0xcc
	lsls r7, r7, #3
_08092258:
	mov r1, sb
	ldrb r0, [r1]
	mov r1, r8
	bl GetItemID
	adds r4, r0, #0
	cmp r4, #0
	bge _08092284
	ldr r1, _08092280 @ =0x00000F6C
	adds r0, r6, r1
	adds r0, r0, r7
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080922E0
	.align 2, 0
_08092278: .4byte 0x00003F9C
_0809227C: .4byte 0x000015C4
_08092280: .4byte 0x00000F6C
_08092284:
	ldr r0, _080922C4 @ =0x00000F6C
	adds r2, r6, r0
	adds r2, r2, r7
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r2, r4, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r6, #0
	adds r1, #0xa0
	movs r3, #1
	bl Sprite_SetSprite
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _080922D8
	adds r0, r4, #0
	bl FUN_08091cb8
	cmp r0, #0
	beq _080922CC
	adds r0, r5, #0
	ldr r1, _080922C8 @ =0x000002DF
	bl FUN_0808ba0c
	b _080922E0
	.align 2, 0
_080922C4: .4byte 0x00000F6C
_080922C8: .4byte 0x000002DF
_080922CC:
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
	b _080922E0
_080922D8:
	adds r0, r5, #0
	ldr r1, _080922FC @ =0x000002DF
	bl FUN_0808ba0c
_080922E0:
	adds r5, #0x60
	adds r7, #0x60
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #0xf
	ble _08092258
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080922FC: .4byte 0x000002DF

	thumb_func_start FUN_08092300
FUN_08092300: @ 0x08092300
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov sl, r3
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #5
	ldr r0, _08092390 @ =0x000020A4
	adds r4, r4, r0
	adds r4, r6, r4
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r1, #0xa0
	adds r1, r1, r6
	mov sb, r1
	ldr r1, _08092394 @ =0x00003F9C
	adds r0, r6, r1
	ldrb r0, [r0]
	mov r1, r8
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	adds r0, #0x20
	mov r1, r8
	bl FUN_080921e8
	lsls r5, r5, #3
	ldr r0, _08092398 @ =0x00003B68
	adds r5, r5, r0
	adds r5, r6, r5
	adds r0, r5, #0
	mov r1, sl
	bl FUN_080921e8
	movs r1, #0x11
	add r8, r1
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	lsls r0, r0, #5
	adds r6, r6, r0
	ldr r0, _0809239C @ =0x00000F9E
	adds r6, r6, r0
	ldrh r1, [r6]
	adds r0, r4, #0
	bl FUN_0808ba0c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092390: .4byte 0x000020A4
_08092394: .4byte 0x00003F9C
_08092398: .4byte 0x00003B68
_0809239C: .4byte 0x00000F9E

	thumb_func_start FUN_080923a0
FUN_080923a0: @ 0x080923A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _0809242C @ =0xFFFF0000
	movs r4, #0
	ands r5, r0
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r0, r0, r6
	mov r8, r0
	ldr r0, [r0]
	ldr r1, _08092430 @ =0x0000038E
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r1, _08092434 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	ble _08092400
	ldr r1, _08092438 @ =0x000026A4
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xad
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _0809243C @ =0x000026AC
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08092440 @ =0x000026C4
	adds r0, r6, r1
	str r4, [r0]
	str r5, [r0, #4]
	movs r4, #0xd0
	lsls r4, r4, #0xc
	movs r7, #1
_08092400:
	mov r2, r8
	ldr r1, [r2]
	ldr r2, _08092444 @ =0x000004C7
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08092484
	subs r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _08092448
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08092438 @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xab
	b _080924A0
	.align 2, 0
_0809242C: .4byte 0xFFFF0000
_08092430: .4byte 0x0000038E
_08092434: .4byte 0x030046A0
_08092438: .4byte 0x000026A4
_0809243C: .4byte 0x000026AC
_08092440: .4byte 0x000026C4
_08092444: .4byte 0x000004C7
_08092448:
	cmp r0, #2
	bne _08092464
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r2, _08092460 @ =0x000026A4
	adds r0, r0, r2
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xaa
	b _080924A0
	.align 2, 0
_08092460: .4byte 0x000026A4
_08092464:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08092480 @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xac
	movs r3, #1
	bl Sprite_SetSprite
	b _080924A6
	.align 2, 0
_08092480: .4byte 0x000026A4
_08092484:
	ldr r2, _080925B8 @ =0x0000043E
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080924DC
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _080925BC @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xae
_080924A0:
	movs r3, #1
	bl Sprite_SetSprite
_080924A6:
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _080925C0 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _080925C4 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r2, r4, #0
	asrs r0, r2, #0x10
	adds r0, #0xd
	lsls r0, r0, #0x10
	ldr r1, _080925C8 @ =0x0000FFFF
	ands r2, r1
	adds r4, r2, #0
	orrs r4, r0
	adds r7, #1
_080924DC:
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r0, r0, r6
	mov r8, r0
	ldr r0, [r0]
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08092540
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r2, _080925BC @ =0x000026A4
	adds r0, r0, r2
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xaf
	movs r3, #1
	bl Sprite_SetSprite
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _080925C0 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _080925C4 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r2, r4, #0
	asrs r0, r2, #0x10
	adds r0, #0xd
	lsls r0, r0, #0x10
	ldr r1, _080925C8 @ =0x0000FFFF
	ands r2, r1
	adds r4, r2, #0
	orrs r4, r0
	adds r7, #1
_08092540:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _080925CC @ =0x0000043C
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809258C
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _080925BC @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb0
	movs r3, #1
	bl Sprite_SetSprite
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _080925C0 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _080925C4 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r7, #1
_0809258C:
	cmp r7, #3
	bgt _080925AC
	movs r2, #1
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _080925D0 @ =0x000026AC
	adds r0, r0, r1
	adds r1, r0, r6
_0809259E:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	adds r7, #1
	cmp r7, #3
	ble _0809259E
_080925AC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080925B8: .4byte 0x0000043E
_080925BC: .4byte 0x000026A4
_080925C0: .4byte 0x00000F6C
_080925C4: .4byte 0x00000F84
_080925C8: .4byte 0x0000FFFF
_080925CC: .4byte 0x0000043C
_080925D0: .4byte 0x000026AC

	thumb_func_start FUN_080925d4
FUN_080925d4: @ 0x080925D4
	push {r4, r5, lr}
	adds r5, r0, #0
	cmp r5, #0
	bge _080925E0
	movs r0, #0
	b _08092600
_080925E0:
	adds r0, r5, #0
	bl FUN_08091e34
	rsbs r1, r0, #0
	orrs r1, r0
	asrs r4, r1, #0x1f
	movs r0, #0x10
	ands r4, r0
	adds r0, r5, #0
	bl FUN_08091cb8
	cmp r0, #0
	beq _080925FE
	movs r0, #1
	orrs r4, r0
_080925FE:
	adds r0, r4, #0
_08092600:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08092608
FUN_08092608: @ 0x08092608
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	cmp r1, #0
	bne _08092632
	ldr r1, _08092624 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08092628
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	b _080926BA
	.align 2, 0
_08092624: .4byte 0x00003AEB
_08092628:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	b _080926BA
_08092632:
	movs r5, #0
	ldr r2, _0809265C @ =0x00003F9C
	adds r6, r4, r2
	ldrb r0, [r6]
	ldr r1, _08092660 @ =0x00003AEE
	adds r7, r4, r1
	ldrb r1, [r7]
	bl GetItemID
	cmp r0, #0
	bge _08092668
	ldrb r0, [r6]
	ldr r2, _08092664 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl GetItemID
	cmp r0, #0
	blt _08092696
	b _08092694
	.align 2, 0
_0809265C: .4byte 0x00003F9C
_08092660: .4byte 0x00003AEE
_08092664: .4byte 0x00003AEB
_08092668:
	ldr r1, _08092678 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #0x10
	bne _0809267C
	movs r5, #1
	b _08092696
	.align 2, 0
_08092678: .4byte 0x00003AEB
_0809267C:
	ldrb r0, [r7]
	cmp r0, r1
	bne _08092694
	ldr r2, _08092690 @ =0x00003AE8
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r5, #1
	ands r5, r0
	b _08092696
	.align 2, 0
_08092690: .4byte 0x00003AE8
_08092694:
	movs r5, #3
_08092696:
	cmp r5, #1
	beq _080926A8
	cmp r5, #3
	beq _080926B2
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	b _080926BA
_080926A8:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #1
	b _080926BA
_080926B2:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #3
_080926BA:
	bl FUN_0808c658
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080926c4
FUN_080926c4: @ 0x080926C4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080926F0 @ =0x00003F9C
	adds r5, r4, r0
	ldrb r0, [r5]
	ldr r1, _080926F4 @ =0x00003AEE
	adds r6, r4, r1
	ldrb r1, [r6]
	bl GetItemID
	cmp r0, #0
	bge _080926FC
	ldrb r0, [r5]
	ldr r2, _080926F8 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl GetItemID
	cmp r0, #0
	bge _0809273C
	b _08092738
	.align 2, 0
_080926F0: .4byte 0x00003F9C
_080926F4: .4byte 0x00003AEE
_080926F8: .4byte 0x00003AEB
_080926FC:
	ldr r0, _0809270C @ =0x00003AEB
	adds r2, r4, r0
	ldrb r1, [r2]
	cmp r1, #0x14
	bne _08092710
	movs r0, #2
	b _0809273E
	.align 2, 0
_0809270C: .4byte 0x00003AEB
_08092710:
	cmp r1, #0x10
	bne _08092718
	movs r0, #1
	b _0809273E
_08092718:
	ldrb r0, [r6]
	cmp r0, r1
	bne _0809273C
	ldr r1, _08092734 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08092738
	movs r0, #0x10
	strb r0, [r2]
	movs r0, #1
	b _0809273E
	.align 2, 0
_08092734: .4byte 0x00003AE8
_08092738:
	movs r0, #0
	b _0809273E
_0809273C:
	movs r0, #3
_0809273E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08092744
FUN_08092744: @ 0x08092744
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080927AC @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080927B0 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0809223c
	ldr r2, _080927B4 @ =0x00003AE8
	adds r5, r4, r2
	adds r0, r5, #0
	bl FUN_0808fbcc
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_080916d0
	ldr r1, _080927B8 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _080927BC @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080921e8
	adds r0, r4, #0
	bl FUN_08092070
	adds r0, r4, #0
	bl FUN_080923a0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08092608
	ldr r1, _080927C0 @ =FUN_08094070
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080927AC: .4byte 0x000014AC
_080927B0: .4byte 0x0000144C
_080927B4: .4byte 0x00003AE8
_080927B8: .4byte 0x00001464
_080927BC: .4byte 0x00003AEB
_080927C0: .4byte FUN_08094070

	thumb_func_start FUN_080927c4
FUN_080927c4: @ 0x080927C4
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	ldr r0, _0809284C @ =0x00003AEE
	adds r5, r4, r0
	ldrb r0, [r5]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _08092850 @ =0x00000F6C
	adds r2, r4, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r5]
	add r0, sp, #0x10
	bl FUN_080921e8
	add r6, sp, #0x18
	ldr r1, _08092854 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_080921e8
	ldr r1, _08092858 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r5]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r4, r0
	ldr r1, _0809285C @ =0x00000F9E
	adds r0, r0, r1
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c334
	ldr r0, _08092860 @ =0x0000038A
	bl PlaySound_082406e0
	ldr r1, _08092864 @ =FUN_0809296c
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809284C: .4byte 0x00003AEE
_08092850: .4byte 0x00000F6C
_08092854: .4byte 0x00003AEB
_08092858: .4byte 0x00003F9C
_0809285C: .4byte 0x00000F9E
_08092860: .4byte 0x0000038A
_08092864: .4byte FUN_0809296c

	thumb_func_start FUN_08092868
FUN_08092868: @ 0x08092868
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	adds r5, r1, #0
	adds r6, r2, #0
	cmp r5, #0
	ble _08092956
	adds r0, r5, #0
	movs r1, #0x64
	bl Div
	str r0, [sp]
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	subs r4, r5, r4
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	str r1, [sp, #4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	subs r4, r4, r0
	str r4, [sp, #8]
	ldr r0, [sp]
	movs r2, #0
	str r2, [sp, #0xc]
	cmp r0, #0
	bgt _080928BC
	movs r0, #2
	str r0, [sp, #0xc]
	cmp r1, #0
	ble _080928BC
	movs r1, #1
	str r1, [sp, #0xc]
_080928BC:
	ldr r4, [r6]
	ldr r5, [r6, #4]
	movs r0, #3
	ldr r2, [sp, #0xc]
	subs r0, r0, r2
	lsls r0, r0, #2
	subs r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08092900 @ =0xFFFF0000
	ands r1, r4
	orrs r1, r0
	asrs r0, r1, #0x10
	subs r0, #4
	lsls r0, r0, #0x10
	ldr r2, _08092904 @ =0x0000FFFF
	ands r1, r2
	adds r4, r1, #0
	orrs r4, r0
	movs r0, #0
	mov sb, r0
	mov r8, sp
	ldr r6, _08092908 @ =0x0000216C
	add r6, sl
	ldr r7, _0809290C @ =0x00002164
	add r7, sl
_080928F0:
	ldr r1, [sp, #0xc]
	cmp sb, r1
	bge _08092910
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	b _08092944
	.align 2, 0
_08092900: .4byte 0xFFFF0000
_08092904: .4byte 0x0000FFFF
_08092908: .4byte 0x0000216C
_0809290C: .4byte 0x00002164
_08092910:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	mov r0, r8
	ldr r2, [r0]
	adds r2, #0xa
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	mov r1, sl
	adds r1, #0x60
	movs r3, #1
	bl Sprite_SetSprite
	str r4, [r6, #0x18]
	str r5, [r6, #0x1c]
	adds r1, r4, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08092968 @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
_08092944:
	movs r1, #4
	add r8, r1
	adds r6, #0x60
	adds r7, #0x60
	movs r2, #1
	add sb, r2
	mov r0, sb
	cmp r0, #2
	ble _080928F0
_08092956:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092968: .4byte 0xFFFF0000

	thumb_func_start FUN_0809296c
FUN_0809296c: @ 0x0809296C
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _080929F0
	ldr r0, _080929F8 @ =0x000009EE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080929F0
	ldr r1, _080929FC @ =0x000020AC
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _08092A00 @ =0x00003AEE
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_08091e64
	ldr r4, _08092A04 @ =0x00000121
	adds r0, r5, #0
	bl FUN_0808ba64
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #0x10
	bl FUN_0808c164
	ldr r1, _08092A08 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r1
	movs r1, #0x24
	orrs r0, r1
	ldr r1, _08092A0C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp]
	ldr r1, _08092A10 @ =0x00003FA2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	mov r2, sp
	bl FUN_08092868
	ldr r0, _08092A14 @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _08092A18 @ =FUN_08092a1c
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_080929F0:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080929F8: .4byte 0x000009EE
_080929FC: .4byte 0x000020AC
_08092A00: .4byte 0x00003AEE
_08092A04: .4byte 0x00000121
_08092A08: .4byte 0xFFFF0000
_08092A0C: .4byte 0x0000FFFF
_08092A10: .4byte 0x00003FA2
_08092A14: .4byte 0x0000010D
_08092A18: .4byte FUN_08092a1c

	thumb_func_start FUN_08092a1c
FUN_08092a1c: @ 0x08092A1C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08092A50 @ =0x000009EE
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0xf
	bhi _08092A7C
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bne _08092A58
	movs r3, #1
	ldr r0, _08092A54 @ =0x0000216C
	adds r1, r4, r0
	movs r2, #2
_08092A3E:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08092A3E
	b _08092A8C
	.align 2, 0
_08092A50: .4byte 0x000009EE
_08092A54: .4byte 0x0000216C
_08092A58:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bhi _08092A8C
	ldr r0, _08092A78 @ =0x00002186
	adds r1, r4, r0
	movs r2, #2
_08092A66:
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _08092A66
	b _08092A8C
	.align 2, 0
_08092A78: .4byte 0x00002186
_08092A7C:
	adds r0, r4, #0
	bl FUN_0808c1cc
	cmp r0, #0
	beq _08092A8C
	adds r0, r4, #0
	bl FUN_08092744
_08092A8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08092a94
FUN_08092a94: @ 0x08092A94
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r0, _08092B24 @ =0x00003AEE
	adds r5, r4, r0
	ldrb r0, [r5]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _08092B28 @ =0x00000F6C
	adds r2, r4, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r5]
	add r0, sp, #0x10
	bl FUN_080921e8
	add r6, sp, #0x18
	ldr r1, _08092B2C @ =0x00003AEB
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_080921e8
	ldr r1, _08092B30 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r5]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r4, r0
	ldr r1, _08092B34 @ =0x00000F9E
	adds r0, r0, r1
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c334
	ldr r1, _08092B38 @ =FUN_08092b3c
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08092B24: .4byte 0x00003AEE
_08092B28: .4byte 0x00000F6C
_08092B2C: .4byte 0x00003AEB
_08092B30: .4byte 0x00003F9C
_08092B34: .4byte 0x00000F9E
_08092B38: .4byte FUN_08092b3c

	thumb_func_start FUN_08092b3c
FUN_08092b3c: @ 0x08092B3C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _08092B98
	ldr r0, _08092BA0 @ =0x000009EE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08092B98
	ldr r1, _08092BA4 @ =0x000020AC
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08092BA8 @ =0x00003AEE
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_08091e64
	ldr r4, _08092BAC @ =0x00000121
	adds r0, r5, #0
	bl FUN_0808ba64
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #0x10
	bl FUN_0808c164
	ldr r0, _08092BB0 @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _08092BB4 @ =FUN_08092bb8
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_08092B98:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08092BA0: .4byte 0x000009EE
_08092BA4: .4byte 0x000020AC
_08092BA8: .4byte 0x00003AEE
_08092BAC: .4byte 0x00000121
_08092BB0: .4byte 0x0000010D
_08092BB4: .4byte FUN_08092bb8

	thumb_func_start FUN_08092bb8
FUN_08092bb8: @ 0x08092BB8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08092BCC @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _08092BD0
	adds r0, #1
	strh r0, [r1]
	b _08092BE4
	.align 2, 0
_08092BCC: .4byte 0x000009EE
_08092BD0:
	adds r0, r4, #0
	bl FUN_0808c1cc
	cmp r0, #0
	beq _08092BE4
	ldr r1, _08092BEC @ =FUN_08092bf0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_08092BE4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08092BEC: .4byte FUN_08092bf0

	thumb_func_start FUN_08092bf0
FUN_08092bf0: @ 0x08092BF0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08092C6C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08092C2E
	ldr r0, [r5, #0x40]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl FUN_08047b8c
	ldr r1, _08092C70 @ =0x00003F9E
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0xff
	bl FUN_08047a28
	ldr r1, _08092C74 @ =0x00003F9F
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #0
	bl FUN_08047c40
_08092C2E:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _08092C4C
	cmp r0, #0xf
	bls _08092C64
	ldr r0, _08092C78 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08092C64
_08092C4C:
	movs r0, #1
	bl FUN_080477e4
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	bl FUN_08092744
_08092C64:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08092C6C: .4byte 0x000009EE
_08092C70: .4byte 0x00003F9E
_08092C74: .4byte 0x00003F9F
_08092C78: .4byte 0x030044E0

	thumb_func_start FUN_08092c7c
FUN_08092c7c: @ 0x08092C7C
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _08092CA4 @ =0x00003F9D
	adds r0, r4, r2
	strb r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r1, _08092CA8 @ =FUN_080931cc
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08092CA4: .4byte 0x00003F9D
_08092CA8: .4byte FUN_080931cc

	thumb_func_start FUN_08092cac
FUN_08092cac: @ 0x08092CAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, _08092DF4 @ =0x00003AEE
	adds r5, r6, r0
	ldrb r0, [r5]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _08092DF8 @ =0x00000F6C
	adds r2, r6, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	mov r8, r1
	orrs r0, r1
	str r0, [r2]
	add r4, sp, #0x10
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_080921e8
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, #8
	strh r0, [r4, #2]
	ldr r2, _08092DFC @ =0x0203B400
	mov sl, r2
	ldr r4, _08092E00 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08092E04 @ =0x000003FF
	mov sb, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	movs r2, #6
	rsbs r2, r2, #0
	adds r1, r2, #0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08092E08 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	movs r2, #5
	rsbs r2, r2, #0
	adds r1, r2, #0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _08092E0C @ =0x0000FFFF
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	adds r0, #5
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, [r4]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08092D8A
	rsbs r0, r7, #0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
_08092D8A:
	ldr r2, _08092E10 @ =0x00003F9C
	adds r0, r6, r2
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r5]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, _08092E14 @ =0x00000F9E
	adds r0, r0, r1
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	add r0, sp, #0x18
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r0, r6, #0
	bl FUN_0808c334
	movs r2, #0xed
	lsls r2, r2, #6
	adds r0, r6, r2
	strh r7, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r0, _08092E18 @ =0x0000027D
	bl PlaySound_082406e0
	ldr r1, _08092E1C @ =FUN_0809312c
	adds r0, r6, #0
	movs r2, #1
	bl FUN_0808a354
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092DF4: .4byte 0x00003AEE
_08092DF8: .4byte 0x00000F6C
_08092DFC: .4byte 0x0203B400
_08092E00: .4byte 0x030046B8
_08092E04: .4byte 0x000003FF
_08092E08: .4byte 0xFFFF0000
_08092E0C: .4byte 0x0000FFFF
_08092E10: .4byte 0x00003F9C
_08092E14: .4byte 0x00000F9E
_08092E18: .4byte 0x0000027D
_08092E1C: .4byte FUN_0809312c

	thumb_func_start FUN_08092e20
FUN_08092e20: @ 0x08092E20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	ldr r0, _08092E88 @ =0x00003B28
	add r0, r8
	mov sb, r0
	ldr r7, _08092E8C @ =0x00003B30
	add r7, r8
	ldr r1, _08092E90 @ =0x00003B42
	add r1, r8
	str r1, [sp]
	movs r2, #0xed
	lsls r2, r2, #6
	add r2, r8
	mov sl, r2
	ldrh r0, [r7]
	mov r1, sb
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, sb
	strh r0, [r2]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r7, #2]
	adds r0, #1
	strh r0, [r7, #2]
	ldr r1, _08092E94 @ =0x000009EE
	add r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08092E98 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08092EA4
	ldrh r0, [r7]
	movs r2, #0
	ldrsh r1, [r7, r2]
	cmp r1, #0
	ble _08092E9C
	subs r0, #1
	b _08092EA2
	.align 2, 0
_08092E88: .4byte 0x00003B28
_08092E8C: .4byte 0x00003B30
_08092E90: .4byte 0x00003B42
_08092E94: .4byte 0x000009EE
_08092E98: .4byte 0x0000FFFF
_08092E9C:
	cmp r1, #0
	bge _08092EA4
	adds r0, #1
_08092EA2:
	strh r0, [r7]
_08092EA4:
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #7
	bgt _08092F10
	movs r0, #8
	strh r0, [r1]
	movs r0, #0
	ldrsh r1, [r7, r0]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08092EC0
	asrs r0, r0, #1
	b _08092EC4
_08092EC0:
	asrs r0, r1, #1
	rsbs r0, r0, #0
_08092EC4:
	strh r0, [r7]
	ldr r6, _08092F04 @ =0x0203B400
	ldr r4, _08092F08 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _08092F0C @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	adds r2, r0, #5
	mov r1, sl
	strh r2, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08092F6A
	rsbs r0, r2, #0
	mov r2, sl
	strh r0, [r2]
	b _08092F6A
	.align 2, 0
_08092F04: .4byte 0x0203B400
_08092F08: .4byte 0x030046B8
_08092F0C: .4byte 0x000003FF
_08092F10:
	cmp r0, #0xe8
	ble _08092F6A
	movs r0, #0xe8
	mov r1, sb
	strh r0, [r1]
	movs r2, #0
	ldrsh r1, [r7, r2]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08092F28
	asrs r0, r0, #1
	b _08092F2C
_08092F28:
	asrs r0, r1, #1
	rsbs r0, r0, #0
_08092F2C:
	strh r0, [r7]
	ldr r6, _08092F88 @ =0x0203B400
	ldr r4, _08092F8C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _08092F90 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	adds r2, r0, #5
	mov r0, sl
	strh r2, [r0]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08092F6A
	rsbs r0, r2, #0
	mov r1, sl
	strh r0, [r1]
_08092F6A:
	mov r2, sb
	movs r1, #2
	ldrsh r0, [r2, r1]
	cmp r0, #0x77
	ble _08093002
	movs r0, #0x78
	strh r0, [r2, #2]
	movs r2, #2
	ldrsh r1, [r7, r2]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08092F94
	asrs r1, r0, #1
	b _08092F98
	.align 2, 0
_08092F88: .4byte 0x0203B400
_08092F8C: .4byte 0x030046B8
_08092F90: .4byte 0x000003FF
_08092F94:
	asrs r0, r1, #1
	rsbs r1, r0, #0
_08092F98:
	movs r2, #0
	strh r1, [r7, #2]
	movs r0, #2
	rsbs r0, r0, #0
	cmp r1, r0
	ble _08092FC6
	strh r2, [r7]
	strh r2, [r7, #2]
	mov r0, sl
	strh r2, [r0]
	ldr r1, [sp]
	ldrh r0, [r1]
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bhi _08092FC0
	movs r0, #0x80
	strh r0, [r1]
	b _08093008
_08092FC0:
	ldr r0, [sp]
	strh r2, [r0]
	b _08093008
_08092FC6:
	ldr r6, _08093044 @ =0x0203B400
	ldr r4, _08093048 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _0809304C @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	adds r2, r0, #5
	mov r1, sl
	strh r2, [r1]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08093002
	rsbs r0, r2, #0
	mov r2, sl
	strh r0, [r2]
_08093002:
	movs r0, #0
	cmp r0, #0
	beq _08093078
_08093008:
	ldr r2, _08093050 @ =0x000020AC
	add r2, r8
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r1, sb
	ldrh r0, [r1]
	subs r0, #8
	ldr r1, _08093054 @ =0x000020C4
	add r1, r8
	strh r0, [r1]
	mov r2, sb
	ldrh r0, [r2, #2]
	subs r0, #8
	ldr r1, _08093058 @ =0x000020C6
	add r1, r8
	strh r0, [r1]
	ldr r1, [sp]
	ldrh r0, [r1]
	ldr r1, _0809305C @ =0x000020DA
	add r1, r8
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08093060
	movs r0, #0
	b _0809310C
	.align 2, 0
_08093044: .4byte 0x0203B400
_08093048: .4byte 0x030046B8
_0809304C: .4byte 0x000003FF
_08093050: .4byte 0x000020AC
_08093054: .4byte 0x000020C4
_08093058: .4byte 0x000020C6
_0809305C: .4byte 0x000020DA
_08093060:
	ldr r0, _08093074 @ =0x000020A4
	add r0, r8
	mov r1, r8
	adds r1, #0xa0
	movs r2, #0xce
	movs r3, #1
	bl Sprite_SetSprite
	movs r0, #1
	b _0809310C
	.align 2, 0
_08093074: .4byte 0x000020A4
_08093078:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	ldr r0, [sp]
	ldrh r0, [r0]
	adds r1, r1, r0
	mov r2, sl
	ldrh r0, [r2]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	ldr r1, [sp]
	strh r0, [r1]
	ldr r2, _080930B0 @ =0x085B0A08
	ldrh r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r1, r0, #3
	rsbs r0, r1, #0
	cmp r0, #0
	blt _080930B4
	asrs r0, r0, #0xc
	b _080930B8
	.align 2, 0
_080930B0: .4byte 0x085B0A08
_080930B4:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_080930B8:
	adds r4, r0, #0
	ldr r1, [sp]
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r2, r0, #3
	rsbs r0, r2, #0
	cmp r0, #0
	blt _080930D2
	asrs r3, r0, #0xc
	b _080930D6
_080930D2:
	asrs r0, r2, #0xc
	rsbs r3, r0, #0
_080930D6:
	ldr r2, _0809311C @ =0x000020AC
	add r2, r8
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	mov r1, sb
	ldrh r0, [r1]
	adds r0, r0, r3
	adds r0, r0, r4
	ldr r1, _08093120 @ =0x000020C4
	add r1, r8
	strh r0, [r1]
	mov r2, sb
	ldrh r0, [r2, #2]
	adds r0, r0, r4
	subs r0, r0, r3
	ldr r1, _08093124 @ =0x000020C6
	add r1, r8
	strh r0, [r1]
	ldr r0, [sp]
	ldrh r1, [r0]
	ldr r0, _08093128 @ =0x000020DA
	add r0, r8
	strh r1, [r0]
	movs r0, #1
	rsbs r0, r0, #0
_0809310C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0809311C: .4byte 0x000020AC
_08093120: .4byte 0x000020C4
_08093124: .4byte 0x000020C6
_08093128: .4byte 0x000020DA

	thumb_func_start FUN_0809312c
FUN_0809312c: @ 0x0809312C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08092e20
	adds r1, r0, #0
	cmp r1, #0
	blt _0809314A
	ldr r2, _08093150 @ =0x00003F9D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08093154 @ =FUN_08093158
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809314A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093150: .4byte 0x00003F9D
_08093154: .4byte FUN_08093158

	thumb_func_start FUN_08093158
FUN_08093158: @ 0x08093158
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080931BC @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _0809318A
	ldr r0, [r5, #0x40]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl FUN_08047b8c
	ldr r1, _080931C0 @ =0x00003F9D
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0xfb
	bl FUN_08047a28
_0809318A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _080931A8
	cmp r0, #0xf
	bls _080931B6
	ldr r0, _080931C4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080931B6
_080931A8:
	bl FUN_08047864
	ldr r1, _080931C8 @ =FUN_08093264
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_080931B6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080931BC: .4byte 0x000009EE
_080931C0: .4byte 0x00003F9D
_080931C4: .4byte 0x030044E0
_080931C8: .4byte FUN_08093264

	thumb_func_start FUN_080931cc
FUN_080931cc: @ 0x080931CC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809324C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080931FE
	ldr r0, [r5, #0x40]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl FUN_08047b8c
	ldr r1, _08093250 @ =0x00003F9D
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0xf9
	bl FUN_08047a28
_080931FE:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _0809321C
	cmp r0, #0xf
	bls _08093246
	ldr r0, _08093254 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093246
_0809321C:
	ldr r1, _08093258 @ =0x00003AEE
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _0809325C @ =0x00000F6C
	adds r2, r5, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	bl FUN_08047864
	ldr r1, _08093260 @ =FUN_08093264
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_08093246:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809324C: .4byte 0x000009EE
_08093250: .4byte 0x00003F9D
_08093254: .4byte 0x030044E0
_08093258: .4byte 0x00003AEE
_0809325C: .4byte 0x00000F6C
_08093260: .4byte FUN_08093264

	thumb_func_start FUN_08093264
FUN_08093264: @ 0x08093264
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809329C @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080932B6
	ldr r1, _080932A0 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e64
	ldr r0, _080932A4 @ =0x000020AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080932A8 @ =0x00003F9D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080932B0
	ldr r0, _080932AC @ =0x0000027F
	bl PlaySound_082406e0
	b _080932B6
	.align 2, 0
_0809329C: .4byte 0x000009EE
_080932A0: .4byte 0x00003AEE
_080932A4: .4byte 0x000020AC
_080932A8: .4byte 0x00003F9D
_080932AC: .4byte 0x0000027F
_080932B0:
	ldr r0, _080932D0 @ =0x0000027E
	bl PlaySound_082406e0
_080932B6:
	ldr r1, _080932D4 @ =0x00003F9D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080932DC
	ldr r1, _080932D8 @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, #0x10
	movs r1, #0
	bl FUN_0808a458
	b _080932EA
	.align 2, 0
_080932D0: .4byte 0x0000027E
_080932D4: .4byte 0x00003F9D
_080932D8: .4byte 0x000009EE
_080932DC:
	ldr r1, _0809330C @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, #0x10
	ldr r1, _08093310 @ =0x00007FFF
	bl FUN_0808a458
_080932EA:
	ldr r0, _0809330C @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x30
	bls _08093306
	ldr r1, _08093314 @ =FUN_08093318
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_08093306:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809330C: .4byte 0x000009EE
_08093310: .4byte 0x00007FFF
_08093314: .4byte FUN_08093318

	thumb_func_start FUN_08093318
FUN_08093318: @ 0x08093318
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080933A0 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809334A
	ldr r0, [r5, #0x40]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl FUN_08047b8c
	ldr r1, _080933A4 @ =0x00003F9D
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0xfd
	bl FUN_08047a28
_0809334A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _08093368
	cmp r0, #0xf
	bls _0809339A
	ldr r0, _080933A8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809339A
_08093368:
	ldr r0, _080933AC @ =0x000020DA
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _080933B0 @ =0x000020AC
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #1
	bl FUN_080477e4
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	bl FUN_08092744
_0809339A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080933A0: .4byte 0x000009EE
_080933A4: .4byte 0x00003F9D
_080933A8: .4byte 0x030044E0
_080933AC: .4byte 0x000020DA
_080933B0: .4byte 0x000020AC

	thumb_func_start FUN_080933b4
FUN_080933b4: @ 0x080933B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, _080934C8 @ =0x00003AEE
	adds r4, r7, r0
	ldrb r0, [r4]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r3, _080934CC @ =0x00000F6C
	adds r2, r7, r3
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	mov r8, r1
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r4]
	add r0, sp, #0x10
	bl FUN_080921e8
	add r5, sp, #0x18
	ldr r2, _080934D0 @ =0x00003AEB
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_080921e8
	ldr r3, _080934D4 @ =0x00003F9C
	adds r0, r7, r3
	ldrb r0, [r0]
	ldrb r1, [r4]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r4]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldr r4, _080934D8 @ =0x00000F9E
	adds r0, r0, r4
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_0808c334
	cmp r6, #0
	bne _080934FC
	ldr r1, _080934DC @ =0x00003FBB
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r2, r7, r3
	ldr r0, [r2]
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r3, _080934E0 @ =0x00003FA4
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, [r2]
	adds r4, #4
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r1, _080934E4 @ =0x00003FA8
	adds r4, r7, r1
	strh r0, [r4]
	ldr r1, [r2]
	ldr r2, _080934E8 @ =0x00000366
	adds r0, r1, r2
	ldrh r2, [r0]
	ldrh r0, [r4]
	muls r0, r2, r0
	ldr r3, _080934EC @ =0x0000036A
	adds r1, r1, r3
	ldrh r1, [r1]
	bl Div
	ldr r2, _080934F0 @ =0x00003FA6
	adds r1, r7, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08093488
	ldrh r0, [r4]
	cmp r0, #0
	beq _08093488
	mov r3, r8
	strh r3, [r1]
_08093488:
	movs r4, #0x9e
	lsls r4, r4, #4
	adds r0, r7, r4
	ldr r1, [r0]
	ldr r2, _080934EC @ =0x0000036A
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _080934E0 @ =0x00003FA4
	adds r4, r7, r3
	ldrh r0, [r4]
	muls r0, r2, r0
	ldr r2, _080934E8 @ =0x00000366
	adds r1, r1, r2
	ldrh r1, [r1]
	bl Div
	ldr r3, _080934F4 @ =0x00003FAA
	adds r1, r7, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080934BE
	ldrh r0, [r4]
	cmp r0, #0
	beq _080934BE
	movs r0, #1
	strh r0, [r1]
_080934BE:
	ldr r4, _080934F8 @ =0x00003F9D
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _08093548
	.align 2, 0
_080934C8: .4byte 0x00003AEE
_080934CC: .4byte 0x00000F6C
_080934D0: .4byte 0x00003AEB
_080934D4: .4byte 0x00003F9C
_080934D8: .4byte 0x00000F9E
_080934DC: .4byte 0x00003FBB
_080934E0: .4byte 0x00003FA4
_080934E4: .4byte 0x00003FA8
_080934E8: .4byte 0x00000366
_080934EC: .4byte 0x0000036A
_080934F0: .4byte 0x00003FA6
_080934F4: .4byte 0x00003FAA
_080934F8: .4byte 0x00003F9D
_080934FC:
	ldr r0, _08093564 @ =0x00003FBB
	adds r1, r7, r0
	movs r3, #0
	movs r0, #2
	strb r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r2, r7, r1
	ldr r0, [r2]
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrh r1, [r0]
	ldr r4, _08093568 @ =0x00003FA4
	adds r0, r7, r4
	strh r1, [r0]
	ldr r0, [r2]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r4, #4
	adds r0, r7, r4
	strh r1, [r0]
	ldr r1, _0809356C @ =0x00003FA6
	adds r0, r7, r1
	strh r3, [r0]
	ldr r0, [r2]
	ldr r2, _08093570 @ =0x0000036A
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r3, _08093574 @ =0x00003FAA
	adds r0, r7, r3
	strh r1, [r0]
	subs r4, #0xb
	adds r0, r7, r4
	mov r1, r8
	strb r1, [r0]
_08093548:
	ldr r0, _08093578 @ =0x0000038A
	bl PlaySound_082406e0
	ldr r1, _0809357C @ =FUN_08093580
	adds r0, r7, #0
	movs r2, #1
	bl FUN_0808a354
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08093564: .4byte 0x00003FBB
_08093568: .4byte 0x00003FA4
_0809356C: .4byte 0x00003FA6
_08093570: .4byte 0x0000036A
_08093574: .4byte 0x00003FAA
_08093578: .4byte 0x0000038A
_0809357C: .4byte FUN_08093580

	thumb_func_start FUN_08093580
FUN_08093580: @ 0x08093580
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _080935FE
	ldr r0, _080935DC @ =0x000009EE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080935FE
	ldr r1, _080935E0 @ =0x000020AC
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r4, _080935E4 @ =0x00000121
	adds r0, r5, #0
	bl FUN_0808ba64
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #0x10
	bl FUN_0808c164
	ldr r0, _080935E8 @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _080935EC @ =0x00003F9D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080935F4
	ldr r1, _080935F0 @ =FUN_08093710
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
	b _080935FE
	.align 2, 0
_080935DC: .4byte 0x000009EE
_080935E0: .4byte 0x000020AC
_080935E4: .4byte 0x00000121
_080935E8: .4byte 0x0000010D
_080935EC: .4byte 0x00003F9D
_080935F0: .4byte FUN_08093710
_080935F4:
	ldr r1, _08093604 @ =FUN_08093608
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_080935FE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093604: .4byte FUN_08093608

	thumb_func_start FUN_08093608
FUN_08093608: @ 0x08093608
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0809365C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08093622
	ldr r0, _08093660 @ =0x00000259
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_08093622:
	movs r6, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r4, r5, r1
	ldr r0, [r4]
	ldr r2, _08093664 @ =0x00000366
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x78
	bl Div
	adds r1, r0, #0
	cmp r1, #0
	bne _08093640
	movs r1, #1
_08093640:
	ldr r0, [r4]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r4, r0, r2
	ldrh r3, [r4]
	ldr r2, _08093668 @ =0x00003FA6
	adds r0, r5, r2
	ldrh r2, [r0]
	adds r0, r2, r1
	cmp r3, r0
	ble _0809366C
	subs r0, r3, r1
	strh r0, [r4]
	b _0809367C
	.align 2, 0
_0809365C: .4byte 0x000009EE
_08093660: .4byte 0x00000259
_08093664: .4byte 0x00000366
_08093668: .4byte 0x00003FA6
_0809366C:
	subs r0, r2, r1
	cmp r3, r0
	bge _08093678
	adds r0, r3, r1
	strh r0, [r4]
	b _0809367C
_08093678:
	strh r2, [r4]
	movs r6, #1
_0809367C:
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r1, _080936B4 @ =0x0000036A
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x78
	bl Div
	adds r1, r0, #0
	cmp r1, #0
	bne _08093698
	movs r1, #1
_08093698:
	ldr r0, [r4]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r4, r0, r2
	ldrh r3, [r4]
	ldr r2, _080936B8 @ =0x00003FAA
	adds r0, r5, r2
	ldrh r2, [r0]
	adds r0, r2, r1
	cmp r3, r0
	ble _080936BC
	subs r0, r3, r1
	strh r0, [r4]
	b _080936CC
	.align 2, 0
_080936B4: .4byte 0x0000036A
_080936B8: .4byte 0x00003FAA
_080936BC:
	subs r0, r2, r1
	cmp r3, r0
	bge _080936C8
	adds r0, r3, r1
	strh r0, [r4]
	b _080936CC
_080936C8:
	strh r2, [r4]
	adds r6, #1
_080936CC:
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	cmp r6, #1
	ble _08093700
	ldr r0, _08093708 @ =0x00000259
	bl sound_08240740
	ldr r1, _0809370C @ =0x00003AEE
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_08091e64
	adds r0, r5, #0
	bl FUN_08092744
_08093700:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093708: .4byte 0x00000259
_0809370C: .4byte 0x00003AEE

	thumb_func_start FUN_08093710
FUN_08093710: @ 0x08093710
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08093750 @ =0x000009EE
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0x10
	bls _08093724
	adds r0, r4, #0
	bl FUN_0808c1cc
_08093724:
	ldrh r0, [r5]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	bge _0809375C
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r2, r4, r1
	ldr r0, [r2]
	ldr r3, _08093754 @ =0x00003FA4
	adds r1, r4, r3
	ldrh r1, [r1]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r1, [r0]
	ldr r0, [r2]
	ldr r2, _08093758 @ =0x00003FA8
	b _08093776
	.align 2, 0
_08093750: .4byte 0x000009EE
_08093754: .4byte 0x00003FA4
_08093758: .4byte 0x00003FA8
_0809375C:
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	ldr r3, _080937C4 @ =0x00003FA6
	adds r1, r4, r3
	ldrh r1, [r1]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r1, [r0]
	ldr r0, [r2]
	ldr r2, _080937C8 @ =0x00003FAA
_08093776:
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r3, #4
	adds r0, r0, r3
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	ldr r0, _080937CC @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080937BC
	ldr r1, _080937D0 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e64
	adds r0, r4, #0
	bl FUN_08092744
_080937BC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080937C4: .4byte 0x00003FA6
_080937C8: .4byte 0x00003FAA
_080937CC: .4byte 0x000009EE
_080937D0: .4byte 0x00003AEE

	thumb_func_start FUN_080937d4
FUN_080937d4: @ 0x080937D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, _08093884 @ =0x00003AEE
	adds r4, r6, r0
	ldrb r0, [r4]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _08093888 @ =0x00000F6C
	adds r2, r6, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r7, #1
	orrs r0, r7
	str r0, [r2]
	ldrb r1, [r4]
	add r0, sp, #0x10
	bl FUN_080921e8
	add r5, sp, #0x18
	ldr r1, _0809388C @ =0x00003AEB
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_080921e8
	ldr r1, _08093890 @ =0x00003F9C
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r1, [r4]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r4]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, _08093894 @ =0x00000F9E
	adds r0, r0, r1
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0808c334
	ldr r0, _08093898 @ =0x0000038A
	bl PlaySound_082406e0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0809387C
	ldr r2, _0809389C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080938A0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080938A4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x64
	bl Mod
	cmp r0, #0x13
	bgt _080938AC
_0809387C:
	ldr r1, _080938A8 @ =0x00003F9D
	adds r0, r6, r1
	strb r7, [r0]
	b _080938B4
	.align 2, 0
_08093884: .4byte 0x00003AEE
_08093888: .4byte 0x00000F6C
_0809388C: .4byte 0x00003AEB
_08093890: .4byte 0x00003F9C
_08093894: .4byte 0x00000F9E
_08093898: .4byte 0x0000038A
_0809389C: .4byte 0x030046B8
_080938A0: .4byte 0x000003FF
_080938A4: .4byte 0x0203B400
_080938A8: .4byte 0x00003F9D
_080938AC:
	ldr r0, _080938C8 @ =0x00003F9D
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
_080938B4:
	ldr r1, _080938CC @ =FUN_080938d0
	adds r0, r6, #0
	movs r2, #1
	bl FUN_0808a354
	add sp, #0x20
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080938C8: .4byte 0x00003F9D
_080938CC: .4byte FUN_080938d0

	thumb_func_start FUN_080938d0
FUN_080938d0: @ 0x080938D0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _08093974
	ldr r0, _08093924 @ =0x000009EE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08093974
	ldr r1, _08093928 @ =0x000020AC
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r4, _0809392C @ =0x00000121
	adds r0, r5, #0
	bl FUN_0808ba64
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #0x10
	bl FUN_0808c164
	ldr r1, _08093930 @ =0x00003F9D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08093938
	movs r2, #0xd
	movs r3, #2
	ldr r6, _08093934 @ =0x000002ED
	b _0809393E
	.align 2, 0
_08093924: .4byte 0x000009EE
_08093928: .4byte 0x000020AC
_0809392C: .4byte 0x00000121
_08093930: .4byte 0x00003F9D
_08093934: .4byte 0x000002ED
_08093938:
	movs r2, #0
	movs r3, #1
	ldr r6, _0809397C @ =0x000002EE
_0809393E:
	ldr r0, _08093980 @ =0x00002524
	adds r4, r5, r0
	ldr r1, _08093984 @ =0x00003F9D
	adds r0, r5, r1
	ldrb r1, [r0]
	lsls r1, r1, #5
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r1, r5, r1
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_082370cc
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0808ba0c
	ldr r0, _08093988 @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _0809398C @ =FUN_08093990
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_08093974:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809397C: .4byte 0x000002EE
_08093980: .4byte 0x00002524
_08093984: .4byte 0x00003F9D
_08093988: .4byte 0x0000010D
_0809398C: .4byte FUN_08093990

	thumb_func_start FUN_08093990
FUN_08093990: @ 0x08093990
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080939CC @ =0x000009EE
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #7
	bls _080939A4
	adds r0, r4, #0
	bl FUN_0808c1cc
_080939A4:
	ldr r2, _080939D0 @ =0x00003F9D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _080939D8
	ldrh r0, [r5]
	cmp r0, #9
	bls _080939EC
	ldr r2, _080939D4 @ =0x00002524
	adds r0, r4, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r4, r1
	bl FUN_082372cc
	b _080939EC
	.align 2, 0
_080939CC: .4byte 0x000009EE
_080939D0: .4byte 0x00003F9D
_080939D4: .4byte 0x00002524
_080939D8:
	ldr r2, _08093A0C @ =0x00002524
	adds r0, r4, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r4, r1
	bl FUN_082372cc
_080939EC:
	ldr r1, _08093A10 @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	bge _08093A18
	ldr r2, _08093A14 @ =0x0000252C
	adds r0, r4, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08093A24
	.align 2, 0
_08093A0C: .4byte 0x00002524
_08093A10: .4byte 0x000009EE
_08093A14: .4byte 0x0000252C
_08093A18:
	ldr r1, _08093A48 @ =0x0000252C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08093A24:
	str r1, [r0]
	ldr r2, _08093A4C @ =0x000009EE
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _08093A42
	ldr r1, _08093A50 @ =FUN_08093a54
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_08093A42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093A48: .4byte 0x0000252C
_08093A4C: .4byte 0x000009EE
_08093A50: .4byte FUN_08093a54

	thumb_func_start FUN_08093a54
FUN_08093a54: @ 0x08093A54
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r1, _08093AB4 @ =0x00002524
	adds r0, r5, r1
	ldr r2, _08093AB8 @ =0x00003F9D
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r5, r1
	bl FUN_082372cc
	movs r0, #0
	mov sb, r0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r6, r5, r1
	ldr r0, [r6]
	ldr r4, _08093ABC @ =0x0000036A
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x78
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bgt _08093A96
	movs r2, #1
_08093A96:
	ldr r1, [r6]
	movs r0, #0xda
	lsls r0, r0, #2
	mov r8, r0
	adds r3, r1, r0
	ldrh r0, [r3]
	adds r7, r0, r2
	adds r1, r1, r4
	ldrh r0, [r1]
	cmp r7, r0
	blt _08093AC0
	strh r0, [r3]
	movs r1, #1
	mov sb, r1
	b _08093ADC
	.align 2, 0
_08093AB4: .4byte 0x00002524
_08093AB8: .4byte 0x00003F9D
_08093ABC: .4byte 0x0000036A
_08093AC0:
	ldr r2, _08093B14 @ =0x000009EE
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	bne _08093AD6
	ldr r0, _08093B18 @ =0x00000259
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_08093AD6:
	ldr r0, [r6]
	add r0, r8
	strh r7, [r0]
_08093ADC:
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	mov r0, sb
	cmp r0, #0
	beq _08093B08
	ldr r1, _08093B14 @ =0x000009EE
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08093AFE
	ldr r0, _08093B18 @ =0x00000259
	bl sound_08240740
_08093AFE:
	ldr r1, _08093B1C @ =FUN_08093b20
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_08093B08:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08093B14: .4byte 0x000009EE
_08093B18: .4byte 0x00000259
_08093B1C: .4byte FUN_08093b20

	thumb_func_start FUN_08093b20
FUN_08093b20: @ 0x08093B20
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08093B60 @ =0x00002524
	adds r0, r4, r1
	ldr r2, _08093B64 @ =0x00003F9D
	adds r1, r4, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r4, r1
	bl FUN_082372cc
	ldr r1, _08093B68 @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	bge _08093B70
	ldr r2, _08093B6C @ =0x0000252C
	adds r0, r4, r2
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08093B7A
	.align 2, 0
_08093B60: .4byte 0x00002524
_08093B64: .4byte 0x00003F9D
_08093B68: .4byte 0x000009EE
_08093B6C: .4byte 0x0000252C
_08093B70:
	ldr r1, _08093BA8 @ =0x0000252C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08093B7A:
	str r1, [r0]
	ldr r2, _08093BAC @ =0x000009EE
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _08093BA0
	ldr r1, _08093BB0 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e48
	adds r0, r4, #0
	bl FUN_08092744
_08093BA0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093BA8: .4byte 0x0000252C
_08093BAC: .4byte 0x000009EE
_08093BB0: .4byte 0x00003AEE

	thumb_func_start FUN_08093bb4
FUN_08093bb4: @ 0x08093BB4
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r0, _08093C48 @ =0x00003AEE
	adds r5, r4, r0
	ldrb r0, [r5]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _08093C4C @ =0x00000F6C
	adds r2, r4, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r5]
	add r0, sp, #0x10
	bl FUN_080921e8
	add r6, sp, #0x18
	ldr r1, _08093C50 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_080921e8
	ldr r1, _08093C54 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r5]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r4, r0
	ldr r1, _08093C58 @ =0x00000F9E
	adds r0, r0, r1
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c334
	ldr r0, _08093C5C @ =0x0000038A
	bl PlaySound_082406e0
	ldr r1, _08093C60 @ =FUN_08093c64
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093C48: .4byte 0x00003AEE
_08093C4C: .4byte 0x00000F6C
_08093C50: .4byte 0x00003AEB
_08093C54: .4byte 0x00003F9C
_08093C58: .4byte 0x00000F9E
_08093C5C: .4byte 0x0000038A
_08093C60: .4byte FUN_08093c64

	thumb_func_start FUN_08093c64
FUN_08093c64: @ 0x08093C64
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _08093CAC
	ldr r0, _08093CB4 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08093CAC
	ldr r0, _08093CB8 @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _08093CBC @ =0x000020AC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08093CC0 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e64
	ldr r1, _08093CC4 @ =FUN_08093cc8
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_08093CAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093CB4: .4byte 0x000009EE
_08093CB8: .4byte 0x0000010D
_08093CBC: .4byte 0x000020AC
_08093CC0: .4byte 0x00003AEE
_08093CC4: .4byte FUN_08093cc8

	thumb_func_start FUN_08093cc8
FUN_08093cc8: @ 0x08093CC8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08093D2C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08093CF4
	ldr r0, [r5, #0x40]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #4
	bl FUN_08047b8c
	ldr r0, _08093D30 @ =0x00000103
	bl FUN_08047a28
_08093CF4:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _08093D12
	cmp r0, #0xf
	bls _08093D24
	ldr r0, _08093D34 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093D24
_08093D12:
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	bl FUN_08092744
_08093D24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093D2C: .4byte 0x000009EE
_08093D30: .4byte 0x00000103
_08093D34: .4byte 0x030044E0

	thumb_func_start FUN_08093d38
FUN_08093d38: @ 0x08093D38
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r0, _08093DCC @ =0x00003AEE
	adds r5, r4, r0
	ldrb r0, [r5]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _08093DD0 @ =0x00000F6C
	adds r2, r4, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r5]
	add r0, sp, #0x10
	bl FUN_080921e8
	add r6, sp, #0x18
	ldr r1, _08093DD4 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r6, #0
	bl FUN_080921e8
	ldr r1, _08093DD8 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r5]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r4, r0
	ldr r1, _08093DDC @ =0x00000F9E
	adds r0, r0, r1
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	movs r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c334
	ldr r0, _08093DE0 @ =0x0000038A
	bl PlaySound_082406e0
	ldr r1, _08093DE4 @ =FUN_08093de8
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093DCC: .4byte 0x00003AEE
_08093DD0: .4byte 0x00000F6C
_08093DD4: .4byte 0x00003AEB
_08093DD8: .4byte 0x00003F9C
_08093DDC: .4byte 0x00000F9E
_08093DE0: .4byte 0x0000038A
_08093DE4: .4byte FUN_08093de8

	thumb_func_start FUN_08093de8
FUN_08093de8: @ 0x08093DE8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _08093E30
	ldr r0, _08093E38 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08093E30
	ldr r1, _08093E3C @ =0x000020AC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08093E40 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e64
	ldr r1, _08093E44 @ =FUN_08093e4c
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	ldr r0, _08093E48 @ =0x0000010D
	bl PlaySound_082406e0
_08093E30:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093E38: .4byte 0x000009EE
_08093E3C: .4byte 0x000020AC
_08093E40: .4byte 0x00003AEE
_08093E44: .4byte FUN_08093e4c
_08093E48: .4byte 0x0000010D

	thumb_func_start FUN_08093e4c
FUN_08093e4c: @ 0x08093E4C
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r0, _08093F14 @ =0x000009EE
	adds r6, r5, r0
	ldrh r0, [r6]
	cmp r0, #0
	bne _08093EB6
	bl FUN_08047864
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _08093F18 @ =0x030046A0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r1, sp, #4
	bl FUN_08242b14
	ldr r2, _08093F1C @ =0x00004018
	adds r4, r5, r2
	ldr r0, [r4]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	movs r2, #0x10
	movs r3, #0x1e
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r1, [r5, #0x44]
	bl FUN_0804a240
	ldr r0, [r4]
	ldr r1, _08093F20 @ =0x000009E4
	adds r2, r5, r1
	add r1, sp, #4
	bl FUN_08094d30
	ldr r0, [r4]
	bl FUN_0804a1f0
_08093EB6:
	ldrh r0, [r6]
	cmp r0, #8
	bne _08093ED0
	ldr r0, [r5, #0x40]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	movs r0, #0x82
	lsls r0, r0, #1
	bl FUN_08047a28
_08093ED0:
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bhi _08093EEE
	cmp r0, #0xf
	bls _08093F0A
	ldr r0, _08093F24 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08093F0A
_08093EEE:
	ldr r2, _08093F1C @ =0x00004018
	adds r0, r5, r2
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	bl FUN_08092744
_08093F0A:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08093F14: .4byte 0x000009EE
_08093F18: .4byte 0x030046A0
_08093F1C: .4byte 0x00004018
_08093F20: .4byte 0x000009E4
_08093F24: .4byte 0x030044E0

	thumb_func_start FUN_08093f28
FUN_08093f28: @ 0x08093F28
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08093F58 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _08093F5C @ =0x00003AEE
	adds r1, r4, r2
	ldrb r1, [r1]
	bl GetItemID
	adds r5, r0, #0
	ldr r1, _08093F60 @ =0x08DAA8D8
	lsls r0, r5, #4
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	subs r0, #1
	cmp r0, #0xe
	bls _08093F4E
	b _08094064
_08093F4E:
	lsls r0, r0, #2
	ldr r1, _08093F64 @ =_08093F68
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08093F58: .4byte 0x00003F9C
_08093F5C: .4byte 0x00003AEE
_08093F60: .4byte 0x08DAA8D8
_08093F64: .4byte _08093F68
_08093F68: @ jump table
	.4byte _08093FA4 @ case 0
	.4byte _08093FA4 @ case 1
	.4byte _08093FA4 @ case 2
	.4byte _08093FAC @ case 3
	.4byte _08093FA4 @ case 4
	.4byte _08094020 @ case 5
	.4byte _08093FC0 @ case 6
	.4byte _08093FE0 @ case 7
	.4byte _08093FA4 @ case 8
	.4byte _08094002 @ case 9
	.4byte _08094018 @ case 10
	.4byte _08094020 @ case 11
	.4byte _08094044 @ case 12
	.4byte _08094058 @ case 13
	.4byte _08094064 @ case 14
_08093FA4:
	adds r0, r4, #0
	bl FUN_080927c4
	b _08094064
_08093FAC:
	ldr r0, _08093FBC @ =0x0000038A
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08092a94
	b _08094064
	.align 2, 0
_08093FBC: .4byte 0x0000038A
_08093FC0:
	ldr r0, _08093FD8 @ =0x0000010D
	bl PlaySound_082406e0
	cmp r5, #0x1e
	bne _08093FD2
	movs r0, #0xc1
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08093FD2:
	ldr r2, _08093FDC @ =0x00003AEE
	adds r0, r4, r2
	b _0809402A
	.align 2, 0
_08093FD8: .4byte 0x0000010D
_08093FDC: .4byte 0x00003AEE
_08093FE0:
	ldr r0, _08093FF4 @ =0x08DAA8D8
	lsls r1, r5, #4
	adds r1, r1, r0
	ldrh r0, [r1, #6]
	cmp r0, #2
	bne _08093FF8
	adds r0, r4, #0
	bl FUN_08092cac
	b _08094064
	.align 2, 0
_08093FF4: .4byte 0x08DAA8D8
_08093FF8:
	ldrh r1, [r1, #6]
	adds r0, r4, #0
	bl FUN_08092c7c
	b _08094064
_08094002:
	ldr r0, _08094014 @ =0x08DAA8D8
	lsls r1, r5, #4
	adds r1, r1, r0
	ldrh r1, [r1, #6]
	adds r0, r4, #0
	bl FUN_080933b4
	b _08094064
	.align 2, 0
_08094014: .4byte 0x08DAA8D8
_08094018:
	adds r0, r4, #0
	bl FUN_080937d4
	b _08094064
_08094020:
	ldr r0, _0809403C @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _08094040 @ =0x00003AEE
	adds r0, r4, r1
_0809402A:
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e64
	adds r0, r4, #0
	bl FUN_08092744
	b _08094064
	.align 2, 0
_0809403C: .4byte 0x0000010D
_08094040: .4byte 0x00003AEE
_08094044:
	ldr r0, _08094054 @ =0x0000038A
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08093bb4
	b _08094064
	.align 2, 0
_08094054: .4byte 0x0000038A
_08094058:
	ldr r0, _0809406C @ =0x0000038A
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08093d38
_08094064:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809406C: .4byte 0x0000038A

	thumb_func_start FUN_08094070
FUN_08094070: @ 0x08094070
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_0808c548
	ldr r5, _080940C0 @ =0x030044E0
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080940CC
	ldr r0, _080940C4 @ =0x000009F8
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _080940C8 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a5b0
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a5e0
	b _080941EC
	.align 2, 0
_080940C0: .4byte 0x030044E0
_080940C4: .4byte 0x000009F8
_080940C8: .4byte 0x00001444
_080940CC:
	ldr r2, _08094170 @ =0x000009F8
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08094174 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl FUN_082372cc
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08092608
	ldrh r1, [r5, #2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080941CC
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _08094178 @ =0x00003AE8
	adds r7, r4, r2
	adds r0, r7, #0
	bl FUN_0808fbbc
	ldr r0, _0809417C @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094180 @ =0x000014C4
	adds r0, r4, r1
	ldr r2, _08094184 @ =0x00003AEE
	adds r5, r4, r2
	ldrb r1, [r5]
	bl FUN_080921e8
	ldr r1, _08094188 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08094198
	ldr r2, _0809418C @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, _08094190 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #4
	movs r2, #0
	bl FUN_0808c510
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808b6fc
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _08094194 @ =FUN_080944f4
	b _080941BA
	.align 2, 0
_08094170: .4byte 0x000009F8
_08094174: .4byte 0x00001444
_08094178: .4byte 0x00003AE8
_0809417C: .4byte 0x000014AC
_08094180: .4byte 0x000014C4
_08094184: .4byte 0x00003AEE
_08094188: .4byte 0x00003AEB
_0809418C: .4byte 0x0000144C
_08094190: .4byte 0x0000204C
_08094194: .4byte FUN_080944f4
_08094198:
	ldr r1, _080941C4 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl GetItemID
	bl FUN_080925d4
	adds r1, r0, #0
	adds r0, r7, #0
	bl FUN_080916d0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08092608
	ldr r1, _080941C8 @ =FUN_08094200
_080941BA:
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _080941EC
	.align 2, 0
_080941C4: .4byte 0x00003F9C
_080941C8: .4byte FUN_08094200
_080941CC:
	ldr r2, _080941F4 @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fb68
	cmp r0, #0
	beq _080941EC
	ldr r1, _080941F8 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _080941FC @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080921e8
	adds r0, r4, #0
	bl FUN_08092070
_080941EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080941F4: .4byte 0x00003AE8
_080941F8: .4byte 0x00001464
_080941FC: .4byte 0x00003AEB

	thumb_func_start FUN_08094200
FUN_08094200: @ 0x08094200
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _08094234 @ =0x00001444
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x60
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	adds r0, r4, #0
	bl FUN_0808c548
	ldr r0, _08094238 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809423C
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08092744
	b _0809442E
	.align 2, 0
_08094234: .4byte 0x00001444
_08094238: .4byte 0x030044E0
_0809423C:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080942B4
	ldr r1, _080942A0 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080942B4
	ldr r0, _080942A4 @ =0x00001C2C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080942A8 @ =0x00001464
	adds r0, r4, r1
	movs r1, #0x14
	bl FUN_080921e8
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _080942AC @ =0x0000204C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r4, #0x58]
	movs r1, #2
	movs r2, #1
	bl FUN_0808c510
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _080942B0 @ =FUN_0809458c
	b _080943D6
	.align 2, 0
_080942A0: .4byte 0x00003AE8
_080942A4: .4byte 0x00001C2C
_080942A8: .4byte 0x00001464
_080942AC: .4byte 0x0000204C
_080942B0: .4byte FUN_0809458c
_080942B4:
	ldr r0, _080942E4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _080942C4
	b _08094406
_080942C4:
	adds r0, r4, #0
	bl FUN_0808c700
	adds r0, r4, #0
	bl FUN_080926c4
	cmp r0, #1
	beq _08094320
	cmp r0, #1
	bgt _080942DA
	b _080943FC
_080942DA:
	cmp r0, #2
	beq _080942E8
	cmp r0, #3
	beq _0809435C
	b _080943FC
	.align 2, 0
_080942E4: .4byte 0x030044E0
_080942E8:
	ldr r2, _08094314 @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r0, _08094318 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	movs r2, #1
	bl FUN_0808c510
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _0809431C @ =FUN_0809458c
	b _080943D6
	.align 2, 0
_08094314: .4byte 0x0000144C
_08094318: .4byte 0x0000204C
_0809431C: .4byte FUN_0809458c
_08094320:
	ldr r2, _08094350 @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r0, _08094354 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #3
	movs r2, #1
	bl FUN_0808c510
	adds r0, r4, #0
	bl FUN_080921a8
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0808b6fc
	ldr r1, _08094358 @ =FUN_0809455c
	b _080943D6
	.align 2, 0
_08094350: .4byte 0x0000144C
_08094354: .4byte 0x0000204C
_08094358: .4byte FUN_0809455c
_0809435C:
	ldr r2, _080943E0 @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r0, _080943E4 @ =0x0000038A
	bl PlaySound_082406e0
	ldr r0, _080943E8 @ =0x00003F9C
	adds r5, r4, r0
	ldrb r0, [r5]
	ldr r1, _080943EC @ =0x00003AEE
	adds r6, r4, r1
	ldrb r1, [r6]
	bl GetItemID
	cmp r0, #0
	blt _08094390
	ldrb r2, [r6]
	ldr r1, _080943F0 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08092300
_08094390:
	ldrb r0, [r5]
	ldr r2, _080943F0 @ =0x00003AEB
	adds r5, r4, r2
	ldrb r1, [r5]
	bl GetItemID
	cmp r0, #0
	blt _080943AC
	ldrb r2, [r5]
	ldrb r3, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08092300
_080943AC:
	ldrb r0, [r6]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _080943F4 @ =0x00000F6C
	adds r2, r4, r0
	adds r1, r2, r1
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldrb r1, [r5]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r2, r2, r0
	ldr r0, [r2]
	orrs r0, r7
	str r0, [r2]
	ldr r1, _080943F8 @ =FUN_080946dc
_080943D6:
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _0809442E
	.align 2, 0
_080943E0: .4byte 0x0000144C
_080943E4: .4byte 0x0000038A
_080943E8: .4byte 0x00003F9C
_080943EC: .4byte 0x00003AEE
_080943F0: .4byte 0x00003AEB
_080943F4: .4byte 0x00000F6C
_080943F8: .4byte FUN_080946dc
_080943FC:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0809442E
_08094406:
	ldr r1, _08094434 @ =0x00003AE8
	adds r0, r4, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _0809442E
	ldr r2, _08094438 @ =0x00001464
	adds r0, r4, r2
	ldr r2, _0809443C @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080921e8
	adds r0, r4, #0
	bl FUN_08092070
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08092608
_0809442E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094434: .4byte 0x00003AE8
_08094438: .4byte 0x00001464
_0809443C: .4byte 0x00003AEB

	thumb_func_start FUN_08094440
FUN_08094440: @ 0x08094440
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08094490 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl FUN_082372cc
	ldr r2, _08094494 @ =0x00001C2C
	adds r1, r4, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08094498 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080944A8
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0809449C @ =0x00001464
	adds r0, r4, r1
	ldr r2, _080944A0 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080921e8
	adds r0, r4, #0
	bl FUN_08092070
	ldr r1, _080944A4 @ =FUN_08094200
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _080944E0
	.align 2, 0
_08094490: .4byte 0x00001444
_08094494: .4byte 0x00001C2C
_08094498: .4byte 0x030044E0
_0809449C: .4byte 0x00001464
_080944A0: .4byte 0x00003AEB
_080944A4: .4byte FUN_08094200
_080944A8:
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080944E0
	ldr r0, _080944E8 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080944EC @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	movs r2, #1
	bl FUN_0808c510
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _080944F0 @ =FUN_0809458c
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_080944E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080944E8: .4byte 0x0000144C
_080944EC: .4byte 0x0000204C
_080944F0: .4byte FUN_0809458c

	thumb_func_start FUN_080944f4
FUN_080944f4: @ 0x080944F4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0809450E
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08092744
	b _08094550
_0809450E:
	cmp r0, #1
	bne _08094550
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _0809452C @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08094530
	movs r0, #0
	bl SortInventory
	b _08094536
	.align 2, 0
_0809452C: .4byte 0x00003F9C
_08094530:
	movs r0, #0
	bl SortValuable
_08094536:
	ldr r2, _08094558 @ =0x00003AEC
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08092744
_08094550:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094558: .4byte 0x00003AEC

	thumb_func_start FUN_0809455c
FUN_0809455c: @ 0x0809455C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _08094576
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08092744
	b _08094584
_08094576:
	cmp r0, #1
	bne _08094584
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_08093f28
_08094584:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809458c
FUN_0809458c: @ 0x0809458C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0808b760
	adds r2, r0, #0
	cmp r2, #0
	bne _080945A8
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08092744
	b _080945E2
_080945A8:
	cmp r2, #1
	bne _080945E2
	ldr r0, _080945E8 @ =0x0000144C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	bl FUN_08047864
	ldr r0, _080945EC @ =0x00003AEE
	adds r4, r5, r0
	ldrb r2, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0x14
	bl FUN_08092300
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_08091e48
	adds r0, r5, #0
	bl FUN_0809223c
	ldr r1, _080945F0 @ =FUN_080945f4
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_080945E2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080945E8: .4byte 0x0000144C
_080945EC: .4byte 0x00003AEE
_080945F0: .4byte FUN_080945f4

	thumb_func_start FUN_080945f4
FUN_080945f4: @ 0x080945F4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809462C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08094608
	ldr r0, _08094630 @ =0x0000038A
	bl PlaySound_082406e0
_08094608:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _0809463C
	ldr r1, _08094634 @ =0x000020C4
	adds r0, r5, r1
	ldr r2, _08094638 @ =0x00003B68
	adds r1, r5, r2
	ldrh r3, [r4]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _08094652
	.align 2, 0
_0809462C: .4byte 0x000009EE
_08094630: .4byte 0x0000038A
_08094634: .4byte 0x000020C4
_08094638: .4byte 0x00003B68
_0809463C:
	ldr r0, _08094658 @ =0x000020AC
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0809465C @ =FUN_08094660
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_08094652:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08094658: .4byte 0x000020AC
_0809465C: .4byte FUN_08094660

	thumb_func_start FUN_08094660
FUN_08094660: @ 0x08094660
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08094698 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08094676
	movs r0, #0x87
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08094676:
	ldrh r0, [r4]
	adds r1, r0, #1
	strh r1, [r4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _080946B8
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080946A0
	ldr r2, _0809469C @ =0x00001BE6
	adds r1, r5, r2
	b _080946C4
	.align 2, 0
_08094698: .4byte 0x000009EE
_0809469C: .4byte 0x00001BE6
_080946A0:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x46
	subs r1, r1, r0
	ldr r2, _080946B4 @ =0x00001BE6
	adds r0, r5, r2
	strh r1, [r0]
	b _080946D6
	.align 2, 0
_080946B4: .4byte 0x00001BE6
_080946B8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080946D0
	ldr r0, _080946CC @ =0x00001BE6
	adds r1, r5, r0
_080946C4:
	movs r0, #0x46
	strh r0, [r1]
	b _080946D6
	.align 2, 0
_080946CC: .4byte 0x00001BE6
_080946D0:
	adds r0, r5, #0
	bl FUN_08092744
_080946D6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080946dc
FUN_080946dc: @ 0x080946DC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08094724 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080946F0
	ldr r0, _08094728 @ =0x0000038A
	bl PlaySound_082406e0
_080946F0:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _0809473C
	ldrh r0, [r4]
	movs r4, #0xc
	subs r4, r4, r0
	ldr r1, _0809472C @ =0x000020C4
	adds r0, r5, r1
	ldr r2, _08094730 @ =0x00003B68
	adds r1, r5, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	ldr r1, _08094734 @ =0x00002124
	adds r0, r5, r1
	ldr r2, _08094738 @ =0x00003B70
	adds r1, r5, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	b _0809476A
	.align 2, 0
_08094724: .4byte 0x000009EE
_08094728: .4byte 0x0000038A
_0809472C: .4byte 0x000020C4
_08094730: .4byte 0x00003B68
_08094734: .4byte 0x00002124
_08094738: .4byte 0x00003B70
_0809473C:
	ldr r0, _08094770 @ =0x000020AC
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08094774 @ =0x0000210C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08094778 @ =0x00003AEE
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _0809477C @ =0x00003AEB
	adds r0, r5, r2
	ldrb r2, [r0]
	adds r0, r5, #0
	bl FUN_0809200c
	adds r0, r5, #0
	bl FUN_08092744
_0809476A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08094770: .4byte 0x000020AC
_08094774: .4byte 0x0000210C
_08094778: .4byte 0x00003AEE
_0809477C: .4byte 0x00003AEB

	thumb_func_start FUN_08094780
FUN_08094780: @ 0x08094780
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b8a4
	adds r0, r4, #0
	bl FUN_0809223c
	ldr r1, _080947C0 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080947E0
	ldr r0, _080947C4 @ =0x00001BCC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080947C8 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080947D4
	ldr r1, _080947CC @ =0x00001BC4
	adds r0, r4, r1
	ldr r1, _080947D0 @ =0x000002DF
	bl FUN_0808ba0c
	b _080947E0
	.align 2, 0
_080947C0: .4byte 0x00003F9C
_080947C4: .4byte 0x00001BCC
_080947C8: .4byte 0x00003AE8
_080947CC: .4byte 0x00001BC4
_080947D0: .4byte 0x000002DF
_080947D4:
	ldr r1, _08094808 @ =0x00001BC4
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_080947E0:
	ldr r0, _0809480C @ =0x00001C8C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094810 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809481C
	ldr r1, _08094814 @ =0x00001C84
	adds r0, r4, r1
	ldr r1, _08094818 @ =0x000002DF
	bl FUN_0808ba0c
	b _08094828
	.align 2, 0
_08094808: .4byte 0x00001BC4
_0809480C: .4byte 0x00001C8C
_08094810: .4byte 0x00003AE8
_08094814: .4byte 0x00001C84
_08094818: .4byte 0x000002DF
_0809481C:
	ldr r1, _08094834 @ =0x00001C84
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_08094828:
	adds r0, r4, #0
	bl FUN_0808bac4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094834: .4byte 0x00001C84

	thumb_func_start FUN_08094838
FUN_08094838: @ 0x08094838
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08094898 @ =0x00003AE8
	adds r5, r4, r0
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_080916d0
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808fbdc
	ldr r1, _0809489C @ =0x00001464
	adds r6, r4, r1
	ldr r0, _080948A0 @ =0x00003AEB
	adds r5, r4, r0
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_080921e8
	ldr r1, _080948A4 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080948A8 @ =0x00001444
	adds r0, r4, r1
	adds r4, #0x60
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_080921e8
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08094898: .4byte 0x00003AE8
_0809489C: .4byte 0x00001464
_080948A0: .4byte 0x00003AEB
_080948A4: .4byte 0x0000144C
_080948A8: .4byte 0x00001444

	thumb_func_start FUN_080948ac
FUN_080948ac: @ 0x080948AC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0809496C @ =0x00003F9C
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08094970 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _08094974 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #6
	bl FUN_0808a3c4
	adds r0, r4, #0
	movs r1, #5
	movs r2, #3
	bl FUN_0808b604
	adds r0, r4, #0
	bl FUN_0808b38c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _08094978 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, _0809497C @ =0x0000156C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094980 @ =0x00001564
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0x9d
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08094838
	adds r0, r4, #0
	bl FUN_08094780
	adds r0, r4, #0
	bl FUN_080923a0
	bl FUN_08049f5c
	adds r0, r4, #0
	bl FUN_08092070
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808c61c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08092608
	ldr r1, _08094984 @ =FUN_08094070
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809496C: .4byte 0x00003F9C
_08094970: .4byte 0x00004014
_08094974: .4byte 0x00004018
_08094978: .4byte 0x00000F56
_0809497C: .4byte 0x0000156C
_08094980: .4byte 0x00001564
_08094984: .4byte FUN_08094070

	thumb_func_start FUN_08094988
FUN_08094988: @ 0x08094988
	push {r4, r5, lr}
	movs r4, #0
	ldr r0, _080949AC @ =0x0000F001
	adds r5, r0, #0
_08094990:
	adds r1, r4, #0
	adds r1, #0xe
	movs r0, #0
	movs r2, #8
	bl FUN_0808a420
	strh r5, [r0]
	adds r4, #1
	cmp r4, #2
	ble _08094990
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080949AC: .4byte 0x0000F001

	thumb_func_start FUN_080949b0
FUN_080949b0: @ 0x080949B0
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08094A74 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _08094A78 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r0, _08094A7C @ =0x00003F9C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #6
	bl FUN_0808a3c4
	bl FUN_08094988
	adds r0, r4, #0
	movs r1, #5
	movs r2, #3
	bl FUN_0808b604
	adds r0, r4, #0
	bl FUN_0808b38c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _08094A80 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, _08094A84 @ =0x0000156C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094A88 @ =0x00001564
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0xa0
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08094838
	adds r0, r4, #0
	bl FUN_08094780
	bl FUN_08049f5c
	ldr r0, _08094A8C @ =0x0000EFDA
	bl FUN_08047dc0
	adds r0, r4, #0
	bl FUN_08092070
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808c61c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08092608
	ldr r1, _08094A90 @ =FUN_08094070
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08094A74: .4byte 0x00004014
_08094A78: .4byte 0x00004018
_08094A7C: .4byte 0x00003F9C
_08094A80: .4byte 0x00000F56
_08094A84: .4byte 0x0000156C
_08094A88: .4byte 0x00001564
_08094A8C: .4byte 0x0000EFDA
_08094A90: .4byte FUN_08094070

	thumb_func_start FUN_08094a94
FUN_08094a94: @ 0x08094A94
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r2, r0, #0
	str r1, [sp, #0x10]
	ldr r0, _08094AF0 @ =0x00003AE8
	adds r0, r2, r0
	str r0, [sp, #0x14]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	bne _08094AF8
	movs r0, #0
	ldr r5, [sp, #0x14]
	strb r0, [r5]
	movs r4, #0
	ldr r0, _08094AF4 @ =0x00003AF0
	adds r5, r2, r0
	movs r2, #0xff
_08094ACC:
	adds r7, r4, #1
	adds r1, r4, r5
	movs r3, #8
_08094AD2:
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _08094AD2
	adds r4, r7, #0
	cmp r4, #3
	ble _08094ACC
	movs r0, #0
	ldr r1, [sp, #0x14]
	strb r0, [r1, #8]
	b _08094C5C
	.align 2, 0
_08094AF0: .4byte 0x00003AE8
_08094AF4: .4byte 0x00003AF0
_08094AF8:
	mov r4, sp
	ldrb r5, [r4, #0x10]
	ldr r4, [sp, #0x14]
	strb r5, [r4]
	movs r4, #0
	ldr r0, _08094B50 @ =0x00003AF0
	adds r0, r2, r0
	str r0, [sp, #0x18]
	ldr r1, _08094B54 @ =0x00003B10
	adds r1, r2, r1
	str r1, [sp, #0x1c]
	ldr r5, _08094B58 @ =0x00003B13
	adds r5, r2, r5
	str r5, [sp, #0x20]
	adds r2, r0, #0
_08094B16:
	adds r7, r4, #1
	lsls r0, r4, #2
	movs r3, #3
	adds r1, r0, #3
	adds r0, r4, r2
	adds r0, #0xc
_08094B22:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r3, #1
	cmp r3, #0
	bge _08094B22
	adds r4, r7, #0
	cmp r4, #3
	ble _08094B16
	movs r6, #0
	movs r3, #1
	movs r2, #1
	rsbs r2, r2, #0
	mov r1, sp
_08094B3E:
	ldr r0, [sp, #0x10]
	asrs r0, r6
	ands r0, r3
	cmp r0, #0
	beq _08094B5C
	adds r0, r6, #0
	adds r0, #0x10
	str r0, [r1]
	b _08094B5E
	.align 2, 0
_08094B50: .4byte 0x00003AF0
_08094B54: .4byte 0x00003B10
_08094B58: .4byte 0x00003B13
_08094B5C:
	str r2, [r1]
_08094B5E:
	adds r1, #4
	adds r6, #1
	cmp r6, #3
	ble _08094B3E
	movs r6, #0
	movs r4, #3
	mov r3, sp
_08094B6C:
	ldr r2, [r3]
	cmp r2, #0
	blt _08094B84
	adds r0, r6, #2
	ands r0, r4
	lsls r0, r0, #2
	mov r5, sp
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0
	bge _08094B84
	str r2, [r1]
_08094B84:
	adds r3, #4
	adds r6, #1
	cmp r6, #3
	ble _08094B6C
	movs r6, #0
	movs r4, #1
	mov r3, sp
_08094B92:
	ldr r2, [r3]
	cmp r2, #0
	blt _08094BB0
	asrs r0, r6, #1
	lsls r0, r0, #1
	adds r1, r6, #1
	ands r1, r4
	adds r0, r0, r1
	lsls r0, r0, #2
	mov r5, sp
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0
	bge _08094BB0
	str r2, [r1]
_08094BB0:
	adds r3, #4
	adds r6, #1
	cmp r6, #3
	ble _08094B92
	movs r6, #0
_08094BBA:
	movs r5, #1
	ands r5, r6
	lsls r0, r5, #1
	mov ip, r0
	cmp r6, #1
	bgt _08094C04
	movs r4, #0
	adds r1, r6, #1
	mov sl, r1
	lsls r5, r5, #3
	mov sb, r5
	ldr r5, [sp, #0x18]
	adds r5, #0x10
	mov r8, r5
_08094BD6:
	mov r3, ip
	adds r2, r3, #2
	adds r7, r4, #1
	cmp r3, r2
	bge _08094BFC
	lsls r0, r6, #2
	mov r1, sp
	adds r5, r1, r0
	mov r1, r8
	adds r0, r4, r1
	mov r4, sb
	adds r1, r4, r0
	subs r3, r2, r3
_08094BF0:
	ldr r0, [r5]
	strb r0, [r1]
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bne _08094BF0
_08094BFC:
	adds r4, r7, #0
	cmp r4, #2
	ble _08094BD6
	b _08094C2A
_08094C04:
	mov r3, ip
	adds r2, r3, #2
	adds r0, r6, #1
	mov sl, r0
	cmp r3, r2
	bge _08094C2A
	lsls r0, r6, #2
	add r0, sp
	ldr r1, [r0]
	lsls r0, r5, #3
	adds r0, #0x1b
	ldr r4, [sp, #0x14]
	adds r0, r0, r4
	subs r3, r2, r3
_08094C20:
	strb r1, [r0]
	adds r0, #4
	subs r3, #1
	cmp r3, #0
	bne _08094C20
_08094C2A:
	mov r6, sl
	cmp r6, #3
	ble _08094BBA
	movs r4, #0
	ldr r2, [sp, #0x1c]
	movs r3, #0xff
_08094C36:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #2
	ble _08094C36
	movs r0, #0x20
	ldr r5, [sp, #0x10]
	ands r0, r5
	cmp r0, #0
	beq _08094C56
	movs r0, #0x15
	ldr r1, [sp, #0x20]
	strb r0, [r1]
	b _08094C5C
_08094C56:
	movs r0, #0xff
	ldr r4, [sp, #0x20]
	strb r0, [r4]
_08094C5C:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08094c6c
FUN_08094c6c: @ 0x08094C6C
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _08094CAE
	cmp r0, #0
	ble _08094C82
	movs r0, #0x2b
	b _08094C84
_08094C82:
	movs r0, #0x2d
_08094C84:
	strb r0, [r5]
	movs r0, #8
	ldrsh r4, [r2, r0]
	cmp r4, #0
	bge _08094C90
	rsbs r4, r4, #0
_08094C90:
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	adds r0, #0x30
	strb r0, [r5, #1]
	adds r1, #0x30
	strb r1, [r5, #2]
	movs r0, #0
	strb r0, [r5, #3]
	b _08094CD4
_08094CAE:
	ldrb r0, [r2, #0x18]
	cmp r0, #0
	bne _08094CC4
	ldrb r0, [r2, #0x1c]
	cmp r0, #0
	bne _08094CC4
	adds r0, r2, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08094CD2
_08094CC4:
	movs r0, #0x53
	strb r0, [r5]
	movs r0, #0x50
	strb r0, [r5, #1]
	movs r0, #0
	strb r0, [r5, #2]
	b _08094CD4
_08094CD2:
	strb r0, [r5]
_08094CD4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08094cdc
FUN_08094cdc: @ 0x08094CDC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08094c6c
	cmp r4, #0
	beq _08094D06
	ldrb r1, [r5]
	adds r0, r7, #0
	bl FUN_0804a2f8
	adds r0, r7, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0804a40c
	b _08094D14
_08094D06:
	ldrb r0, [r5]
	bl FUN_08047a28
	movs r0, #0
	adds r1, r6, #0
	bl FUN_08047c84
_08094D14:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08094d1c
FUN_08094d1c: @ 0x08094D1C
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	bl FUN_08094cdc
	pop {r0}
	bx r0

	thumb_func_start FUN_08094d30
FUN_08094d30: @ 0x08094D30
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	movs r0, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_08094cdc
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08094d48
FUN_08094d48: @ 0x08094D48
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r0, r1, #0
	bl VM_ParseStringRef
	adds r4, r0, #0
	movs r0, #0x42
	adds r0, r0, r4
	mov r8, r0
	ldrb r0, [r7, #3]
	cmp r0, #0
	beq _08094D6E
	adds r1, r0, #0
	movs r0, #0
	bl FUN_08049e6c
_08094D6E:
	ldrb r1, [r7, #4]
	movs r0, #1
	bl FUN_08049e6c
	ldrb r0, [r7]
	add r0, r8
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r6, #0
	ldrb r0, [r7, #0x18]
	cmp r0, #0
	beq _08094D9C
	adds r0, #0x42
	add r0, r8
	bl Textbox_LookupString
	adds r1, r0, #0
	movs r0, #0
	bl FUN_08049eb0
	b _08094DAC
_08094D9C:
	adds r0, r4, #0
	adds r0, #0x84
	bl Textbox_LookupString
	adds r1, r0, #0
	movs r0, #0
	bl FUN_08049eb0
_08094DAC:
	adds r6, #1
	adds r4, r7, #0
	adds r4, #0x1c
	movs r5, #1
_08094DB4:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08094DCC
	adds r0, #0x42
	add r0, r8
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08049eb0
	adds r6, #1
_08094DCC:
	adds r4, #4
	subs r5, #1
	cmp r5, #0
	bge _08094DB4
	ldrb r2, [r7, #0xc]
	cmp r2, #0
	bne _08094DEC
	ldr r0, _08094DE8 @ =0x03002C20
	strb r2, [r0]
	adds r1, r6, #1
	mov sb, r1
	mov ip, r0
	b _08094E3A
	.align 2, 0
_08094DE8: .4byte 0x03002C20
_08094DEC:
	movs r3, #0
	movs r5, #0
	adds r0, r6, #1
	mov sb, r0
	ldr r1, _08094E6C @ =0x03002C20
	mov ip, r1
	mov r4, ip
	adds r2, r7, #0
	adds r2, #0xc
_08094DFE:
	adds r1, r3, r4
	ldrb r0, [r2]
	strb r0, [r1]
	adds r3, #1
	adds r2, #1
	adds r5, #1
	cmp r5, #0xb
	bgt _08094E14
	ldrb r0, [r2]
	cmp r0, #0
	bne _08094DFE
_08094E14:
	adds r1, r3, r4
	movs r0, #0x81
	strb r0, [r1]
	adds r3, #1
	adds r1, r3, r4
	movs r0, #0xf
	strb r0, [r1]
	adds r3, #1
	adds r1, r3, r4
	movs r0, #0x80
	strb r0, [r1]
	adds r3, #1
	adds r1, r3, r4
	movs r0, #0x56
	strb r0, [r1]
	adds r3, #1
	adds r1, r3, r4
	movs r0, #0
	strb r0, [r1]
_08094E3A:
	adds r0, r6, #0
	mov r1, ip
	bl FUN_08049eb0
	mov r6, sb
	cmp r6, #3
	bgt _08094E5E
_08094E48:
	mov r0, r8
	adds r0, #0x42
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_08049eb0
	adds r6, #1
	cmp r6, #3
	ble _08094E48
_08094E5E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08094E6C: .4byte 0x03002C20

	thumb_func_start FUN_08094e70
FUN_08094e70: @ 0x08094E70
	push {lr}
	adds r1, r0, #0
	movs r2, #8
	ldrsh r0, [r1, r2]
	cmp r0, #0
	ble _08094E84
	ldrh r0, [r1, #6]
	lsls r0, r0, #2
	movs r1, #0xc8
	b _08094E9C
_08094E84:
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	bne _08094E94
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	beq _08094EAA
_08094E94:
	ldrh r0, [r1, #6]
	lsls r0, r0, #2
	movs r1, #0xfa
	lsls r1, r1, #3
_08094E9C:
	bl Div
	cmp r0, #3
	ble _08094EA6
	movs r0, #3
_08094EA6:
	adds r0, #0xd0
	b _08094EAC
_08094EAA:
	movs r0, #0xcf
_08094EAC:
	pop {r1}
	bx r1

	thumb_func_start FUN_08094eb0
FUN_08094eb0: @ 0x08094EB0
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	ldr r0, _08094EC8 @ =0x00003AEB
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0xf
	bls _08094ED0
	ldr r1, _08094ECC @ =0x0000204C
	adds r0, r6, r1
	b _08094F06
	.align 2, 0
_08094EC8: .4byte 0x00003AEB
_08094ECC: .4byte 0x0000204C
_08094ED0:
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _08094EF2
	movs r1, #0xff
	lsls r1, r1, #6
	adds r0, r6, r1
	mov r1, sp
	bl FUN_08242a98
	b _08094EFA
_08094EF2:
	ldrb r0, [r1]
	mov r1, sp
	bl FUN_08242b14
_08094EFA:
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	bne _08094F1C
	ldr r2, _08094F18 @ =0x0000204C
	adds r0, r6, r2
_08094F06:
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _08094F72
	.align 2, 0
_08094F18: .4byte 0x0000204C
_08094F1C:
	ldr r0, _08094F7C @ =0x0000204C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094F80 @ =0x00002044
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0xa0
	mov r0, sp
	bl FUN_08094e70
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r6, #0x44]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r2, _08094F84 @ =0x000009E4
	adds r1, r6, r2
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r6, #0x44]
	mov r0, sp
	bl FUN_08094d48
_08094F72:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08094F7C: .4byte 0x0000204C
_08094F80: .4byte 0x00002044
_08094F84: .4byte 0x000009E4

	thumb_func_start weapon_08094f88
weapon_08094f88: @ 0x08094F88
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	str r0, [sp, #0x58]
	movs r2, #1
	ldr r3, _08094FF8 @ =0x0000216C
	adds r1, r0, r3
	movs r4, #5
_08094F9E:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08094F9E
	ldr r1, [sp, #0x58]
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _08095028
	movs r4, #0
_08094FC4:
	movs r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r5, r0, #1
	adds r1, r5, #5
	asrs r0, r4, #1
	adds r6, r0, #5
	movs r0, #0
	adds r2, r6, #0
	bl FUN_0808a420
	adds r1, r0, #0
	cmp r4, #2
	bgt _08095000
	adds r7, r4, #1
	ldr r2, _08094FFC @ =0x0000F001
	adds r0, r2, #0
	movs r5, #4
_08094FEA:
	strh r0, [r1]
	adds r1, #2
	subs r5, #1
	cmp r5, #0
	bge _08094FEA
	b _0809501C
	.align 2, 0
_08094FF8: .4byte 0x0000216C
_08094FFC: .4byte 0x0000F001
_08095000:
	ldr r3, _08095024 @ =0x0000F071
	adds r0, r3, #0
	strh r0, [r1]
	movs r0, #0
	bl FUN_0807a6cc
	adds r2, r5, #7
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	adds r3, r6, #0
	bl FUN_0808b30c
	adds r7, r4, #1
_0809501C:
	adds r4, r7, #0
	cmp r4, #3
	ble _08094FC4
	b _080952CE
	.align 2, 0
_08095024: .4byte 0x0000F071
_08095028:
	ldr r0, [sp, #0x58]
	ldr r1, _08095070 @ =0x00003AEB
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0xf
	bls _080950AC
	movs r4, #0
_08095036:
	adds r0, r4, #0
	add r1, sp, #4
	bl FUN_08242b28
	cmp r4, #3
	beq _0809504A
	add r0, sp, #4
	ldrb r0, [r0, #1]
	cmp r0, #3
	beq _08095074
_0809504A:
	add r0, sp, #4
	bl FUN_0807a6cc
	movs r1, #1
	ands r1, r4
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #1
	adds r2, #7
	asrs r3, r4, #1
	adds r3, #5
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	bl FUN_0808b30c
	adds r7, r4, #1
	b _0809509E
	.align 2, 0
_08095070: .4byte 0x00003AEB
_08095074:
	movs r0, #1
	ands r0, r4
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, #5
	asrs r2, r4, #1
	adds r2, #5
	movs r0, #0
	bl FUN_0808a420
	adds r1, r0, #0
	adds r7, r4, #1
	ldr r3, _080950A8 @ =0x0000F001
	adds r2, r3, #0
	movs r0, #4
_08095094:
	strh r2, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _08095094
_0809509E:
	adds r4, r7, #0
	cmp r4, #3
	ble _08095036
	b _080952CE
	.align 2, 0
_080950A8: .4byte 0x0000F001
_080950AC:
	ldrb r0, [r4]
	bl GetWeaponID
	cmp r0, #0
	bne _08095128
	movs r4, #0
_080950B8:
	adds r0, r4, #0
	add r1, sp, #4
	bl FUN_08242b28
	cmp r4, #3
	beq _080950CC
	add r0, sp, #4
	ldrb r0, [r0, #1]
	cmp r0, #3
	beq _080950F0
_080950CC:
	add r0, sp, #4
	bl FUN_0807a6cc
	movs r1, #1
	ands r1, r4
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #1
	adds r2, #7
	asrs r3, r4, #1
	adds r3, #5
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	bl FUN_0808b30c
	adds r7, r4, #1
	b _0809511A
_080950F0:
	movs r0, #1
	ands r0, r4
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, #5
	asrs r2, r4, #1
	adds r2, #5
	movs r0, #0
	bl FUN_0808a420
	adds r1, r0, #0
	adds r7, r4, #1
	ldr r0, _08095124 @ =0x0000F001
	adds r2, r0, #0
	movs r0, #4
_08095110:
	strh r2, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _08095110
_0809511A:
	adds r4, r7, #0
	cmp r4, #3
	ble _080950B8
	b _080952CE
	.align 2, 0
_08095124: .4byte 0x0000F001
_08095128:
	ldrb r0, [r4]
	add r1, sp, #4
	bl FUN_08242b14
	add r0, sp, #4
	bl FUN_0807a6cc
	str r0, [sp, #0x64]
	movs r1, #0x64
	bl Div
	add r5, sp, #0x28
	str r0, [sp, #0x28]
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	ldr r1, [sp, #0x64]
	subs r4, r1, r4
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [r5, #8]
	add r0, sp, #4
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _0809517E
	cmp r0, #1
	bgt _08095172
	cmp r0, #0
	beq _08095178
	b _0809518A
_08095172:
	cmp r0, #2
	beq _08095184
	b _0809518A
_08095178:
	movs r2, #0
	str r2, [sp, #0x68]
	b _0809518E
_0809517E:
	movs r3, #1
	str r3, [sp, #0x68]
	b _0809518E
_08095184:
	movs r0, #2
	str r0, [sp, #0x68]
	b _0809518E
_0809518A:
	movs r1, #3
	str r1, [sp, #0x68]
_0809518E:
	movs r4, #0
	mov r2, sp
	adds r2, #0x34
	str r2, [sp, #0x6c]
_08095196:
	adds r0, r4, #0
	ldr r1, [sp, #0x6c]
	bl FUN_08242b28
	ldr r0, [sp, #0x6c]
	bl FUN_0807a6cc
	mov r8, r0
	movs r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r6, r0, #1
	adds r3, r6, #7
	mov sb, r3
	asrs r0, r4, #1
	adds r5, r0, #5
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	movs r1, #0x64
	mov r2, sb
	adds r3, r5, #0
	bl FUN_0808b30c
	cmp r4, #3
	bne _080951FC
	movs r0, #0
	movs r1, #0xb
	movs r2, #6
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #1]
	cmp r0, #4
	bne _080951EC
	ldr r3, _080951E8 @ =0x0000F071
	adds r0, r3, #0
	b _080951F0
	.align 2, 0
_080951E8: .4byte 0x0000F071
_080951EC:
	ldr r2, _080951F8 @ =0x0000F070
	adds r0, r2, #0
_080951F0:
	strh r0, [r1]
	movs r7, #4
	b _08095222
	.align 2, 0
_080951F8: .4byte 0x0000F070
_080951FC:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3, #1]
	adds r7, r4, #1
	cmp r0, #3
	bne _08095222
	adds r1, r6, #5
	movs r0, #0
	adds r2, r5, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, _080952E0 @ =0x0000F001
	adds r2, r0, #0
	movs r0, #4
_08095218:
	strh r2, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _08095218
_08095222:
	movs r0, #0
	movs r6, #0
	ldr r1, [sp, #0x68]
	cmp r4, r1
	bne _0809523C
	ldr r2, [sp, #0x64]
	cmp r2, r8
	beq _0809523C
	movs r0, #1
	movs r6, #0xa
	cmp r2, r8
	ble _0809523C
	movs r6, #0
_0809523C:
	cmp r0, #0
	beq _080952C6
	mov r0, sb
	adds r1, r5, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808b97c
	mov r3, sb
	lsls r1, r3, #3
	ldr r0, _080952E4 @ =0xFFFF0000
	ldr r2, [sp, #0x5c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x5c]
	lsls r2, r5, #0x13
	ldr r1, _080952E8 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x58]
	adds r3, #0x60
	mov sl, r3
	adds r6, #0xa
	mov r8, r6
	add r0, sp, #0x28
	mov sb, r0
	ldr r1, [sp, #0x58]
	ldr r2, _080952EC @ =0x0000216C
	adds r4, r1, r2
	ldr r3, _080952F0 @ =0x00002164
	adds r6, r1, r3
	movs r5, #2
_0809527E:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x60]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	mov r1, sb
	adds r1, #4
	mov sb, r1
	subs r1, #4
	ldm r1!, {r2}
	add r2, r8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, [sp, #0x5c]
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080952E4 @ =0xFFFF0000
	ldr r2, [sp, #0x5c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x5c]
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809527E
_080952C6:
	adds r4, r7, #0
	cmp r4, #3
	bgt _080952CE
	b _08095196
_080952CE:
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080952E0: .4byte 0x0000F001
_080952E4: .4byte 0xFFFF0000
_080952E8: .4byte 0x0000FFFF
_080952EC: .4byte 0x0000216C
_080952F0: .4byte 0x00002164

	thumb_func_start FUN_080952f4
FUN_080952f4: @ 0x080952F4
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _08095318
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r3]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	b _08095366
_08095318:
	cmp r2, #0x15
	bne _08095324
	movs r0, #0x78
	strh r0, [r3]
	movs r0, #0x68
	b _08095366
_08095324:
	cmp r2, #0x14
	bne _08095330
	movs r0, #0x75
	strh r0, [r3]
	movs r0, #0x46
	b _08095366
_08095330:
	cmp r2, #0x10
	bne _0809533C
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x4c
	b _08095366
_0809533C:
	cmp r2, #0x11
	bne _08095348
	movs r0, #0x58
	strh r0, [r3]
	movs r0, #0x4c
	b _08095366
_08095348:
	cmp r2, #0x12
	bne _08095354
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x68
	b _08095366
_08095354:
	cmp r2, #0x13
	bne _08095360
	movs r0, #0x58
	strh r0, [r3]
	movs r0, #0x68
	b _08095366
_08095360:
	movs r0, #0x90
	strh r0, [r3]
	movs r0, #0x20
_08095366:
	strh r0, [r3, #2]
	pop {r0}
	bx r0

	thumb_func_start FUN_0809536c
FUN_0809536c: @ 0x0809536C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080953DC
	ldr r0, _080953CC @ =0x000015CC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080953D0 @ =0x000015C4
	adds r4, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	adds r0, r4, #0
	movs r2, #0x3c
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _080953D4 @ =0x000002DF
	adds r0, r4, #0
	bl FUN_0808ba0c
	movs r2, #1
	ldr r0, _080953D8 @ =0x0000162C
	adds r1, r7, r0
	movs r6, #0xe
_080953BA:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080953BA
	b _0809549A
	.align 2, 0
_080953CC: .4byte 0x000015CC
_080953D0: .4byte 0x000015C4
_080953D4: .4byte 0x000002DF
_080953D8: .4byte 0x0000162C
_080953DC:
	movs r6, #0
	ldr r1, _08095404 @ =0x000015C4
	adds r5, r7, r1
	movs r0, #0xcc
	lsls r0, r0, #3
	mov r8, r0
_080953E8:
	adds r0, r6, #0
	bl GetWeaponID
	adds r4, r0, #0
	cmp r4, #0
	bne _0809540C
	ldr r1, _08095408 @ =0x00000F6C
	adds r0, r7, r1
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0809548E
	.align 2, 0
_08095404: .4byte 0x000015C4
_08095408: .4byte 0x00000F6C
_0809540C:
	ldr r0, _08095450 @ =0x00000F6C
	adds r2, r7, r0
	add r2, r8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0xa0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r3, _08095454 @ =0x000002DF
	adds r0, r5, #0
	adds r1, r3, #0
	str r3, [sp]
	bl FUN_0808ba0c
	ldr r3, [sp]
	cmp r4, #0x3a
	beq _08095442
	cmp r4, #0x3e
	bne _08095458
_08095442:
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
	b _0809548E
	.align 2, 0
_08095450: .4byte 0x00000F6C
_08095454: .4byte 0x000002DF
_08095458:
	ldr r0, _0809547C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r1, _08095480 @ =0x08DA9E68
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #3]
	cmp r2, r0
	blt _08095484
	adds r0, r5, #0
	adds r1, r3, #0
	bl FUN_0808ba0c
	b _0809548E
	.align 2, 0
_0809547C: .4byte 0x030046A0
_08095480: .4byte 0x08DA9E68
_08095484:
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_0809548E:
	adds r5, #0x60
	movs r0, #0x60
	add r8, r0
	adds r6, #1
	cmp r6, #0xf
	ble _080953E8
_0809549A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080954a8
FUN_080954a8: @ 0x080954A8
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
	bl Sprite_SetSprite
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
	bl Sprite_SetSprite
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

	thumb_func_start FUN_080956c4
FUN_080956c4: @ 0x080956C4
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov sl, r3
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #5
	ldr r0, _0809574C @ =0x000020A4
	adds r4, r4, r0
	adds r4, r6, r4
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r1, #0xa0
	adds r1, r1, r6
	mov sb, r1
	mov r0, r8
	bl GetWeaponID
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	adds r0, #0x20
	mov r1, r8
	bl FUN_080952f4
	lsls r5, r5, #3
	ldr r0, _08095750 @ =0x00003B68
	adds r5, r5, r0
	adds r5, r6, r5
	adds r0, r5, #0
	mov r1, sl
	bl FUN_080952f4
	movs r1, #0x11
	add r8, r1
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	lsls r0, r0, #5
	adds r6, r6, r0
	ldr r0, _08095754 @ =0x00000F9E
	adds r6, r6, r0
	ldrh r1, [r6]
	adds r0, r4, #0
	bl FUN_0808ba0c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809574C: .4byte 0x000020A4
_08095750: .4byte 0x00003B68
_08095754: .4byte 0x00000F9E

	thumb_func_start GetWeaponPermission
GetWeaponPermission: @ 0x08095758
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r1, #0
	movs r6, #0
	adds r0, r5, #0
	bl GetWeaponKind
	mov sl, r0
	cmp r0, #3
	beq _08095782
	adds r0, r5, #0
	bl GetWeaponID
	adds r4, r0, #0
	cmp r4, #0x3a
	beq _08095782
	cmp r4, #0x3e
	bne _08095786
_08095782:
	movs r0, #0
	b _08095812
_08095786:
	movs r0, #1
	mov ip, r0
	ldr r1, _080957A4 @ =0x08DA9E68
	lsls r2, r4, #3
	adds r0, r2, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #0xa]
	mov sb, r1
	mov r8, r2
	cmp r0, #0
	bne _080957AC
	ldr r2, _080957A8 @ =0x030046A0
	b _080957D4
	.align 2, 0
_080957A4: .4byte 0x08DA9E68
_080957A8: .4byte 0x030046A0
_080957AC:
	ldr r2, _080957F4 @ =0x030046A0
	ldr r0, [r2]
	adds r1, r0, #0
	adds r1, #0x60
	movs r3, #3
_080957B6:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	bne _080957C2
	movs r0, #0
	mov ip, r0
_080957C2:
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _080957B6
	mov r7, ip
	cmp r7, #0
	beq _080957D4
	movs r0, #0x10
	orrs r6, r0
_080957D4:
	ldr r0, [r2]
	adds r0, #0x40
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r7, r8
	adds r0, r7, r4
	lsls r0, r0, #2
	add r0, sb
	ldrb r0, [r0, #3]
	cmp r1, r0
	blt _08095810
	mov r0, sl
	cmp r0, #0
	bne _080957F8
	movs r0, #1
	b _0809580E
	.align 2, 0
_080957F4: .4byte 0x030046A0
_080957F8:
	mov r2, sl
	cmp r2, #1
	bne _08095802
	movs r0, #2
	b _0809580E
_08095802:
	mov r7, sl
	cmp r7, #2
	bne _0809580C
	movs r0, #4
	b _0809580E
_0809580C:
	movs r0, #8
_0809580E:
	orrs r6, r0
_08095810:
	adds r0, r6, #0
_08095812:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start weapon_08095820
weapon_08095820: @ 0x08095820
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	cmp r1, #0
	bne _08095852
	ldr r1, _08095840 @ =0x00003AEB
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08095844
	adds r0, r5, #0
	movs r1, #0
	movs r2, #4
	bl FUN_0808c658
	b _08095964
	.align 2, 0
_08095840: .4byte 0x00003AEB
_08095844:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808c658
	b _08095964
_08095852:
	movs r1, #0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	beq _0809591A
	ldr r0, _08095890 @ =0x00003AEE
	adds r4, r5, r0
	ldrb r0, [r4]
	bl GetWeaponID
	cmp r0, #0
	bne _08095898
	ldr r2, _08095894 @ =0x00003AEB
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _080958D8
	bl GetWeaponID
	movs r1, #3
	cmp r0, #0
	bne _0809591A
	movs r1, #0
	b _0809591A
	.align 2, 0
_08095890: .4byte 0x00003AEE
_08095894: .4byte 0x00003AEB
_08095898:
	ldr r1, _080958DC @ =0x00003AEB
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0xf
	bhi _08095918
	ldrb r0, [r4]
	cmp r0, r1
	bne _08095914
	bl GetWeaponKind
	movs r6, #1
	rsbs r6, r6, #0
	movs r2, #0
	ldr r0, _080958E0 @ =0x030046A0
	ldr r0, [r0]
	ldrb r3, [r4]
	adds r1, r0, #0
	adds r1, #0x60
_080958BC:
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _080958C6
	adds r6, r2, #0
_080958C6:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _080958BC
	cmp r6, #0
	blt _080958E4
	movs r1, #0
	cmp r6, #3
	bne _0809591A
_080958D8:
	movs r1, #4
	b _0809591A
	.align 2, 0
_080958DC: .4byte 0x00003AEB
_080958E0: .4byte 0x030046A0
_080958E4:
	movs r2, #0
	ldr r0, _08095910 @ =0x00003AE8
	adds r3, r5, r0
	ldrb r0, [r3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08095908
	adds r1, r3, #0
	movs r3, #1
_080958F8:
	adds r2, #1
	cmp r2, #3
	bgt _08095908
	ldrb r0, [r1]
	asrs r0, r2
	ands r0, r3
	cmp r0, #0
	beq _080958F8
_08095908:
	movs r1, #0
	cmp r2, #3
	bgt _0809591A
	b _08095918
	.align 2, 0
_08095910: .4byte 0x00003AE8
_08095914:
	movs r1, #3
	b _0809591A
_08095918:
	movs r1, #1
_0809591A:
	cmp r1, #3
	beq _0809594A
	cmp r1, #3
	bgt _08095928
	cmp r1, #1
	beq _0809592E
	b _08095958
_08095928:
	cmp r1, #4
	beq _0809593C
	b _08095958
_0809592E:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #5
	bl FUN_0808c658
	b _08095964
_0809593C:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_0808c658
	b _08095964
_0809594A:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #3
	bl FUN_0808c658
	b _08095964
_08095958:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0808c658
_08095964:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809596c
FUN_0809596c: @ 0x0809596C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _08095A44
	ldr r0, _080959A8 @ =0x00003AEE
	adds r4, r5, r0
	ldrb r0, [r4]
	bl GetWeaponID
	cmp r0, #0
	bne _080959B0
	ldr r2, _080959AC @ =0x00003AEB
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _080959F6
	bl GetWeaponID
	cmp r0, #0
	beq _08095A44
	b _08095A48
	.align 2, 0
_080959A8: .4byte 0x00003AEE
_080959AC: .4byte 0x00003AEB
_080959B0:
	ldr r1, _080959FC @ =0x00003AEB
	adds r0, r5, r1
	ldrb r1, [r0]
	cmp r1, #0xf
	bhi _08095A4C
	ldrb r0, [r4]
	cmp r0, r1
	bne _08095A48
	bl GetWeaponKind
	movs r6, #1
	rsbs r6, r6, #0
	movs r2, #0
	ldr r0, _08095A00 @ =0x030046A0
	ldr r0, [r0]
	ldrb r3, [r4]
	adds r1, r0, #0
	adds r1, #0x60
_080959D4:
	movs r4, #0
	ldrsh r0, [r1, r4]
	cmp r0, r3
	bne _080959DE
	adds r6, r2, #0
_080959DE:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _080959D4
	cmp r6, #0
	blt _08095A04
	cmp r6, #3
	bne _08095A44
	ldr r0, _080959FC @ =0x00003AEB
	adds r1, r5, r0
	movs r0, #0x13
	strb r0, [r1]
_080959F6:
	movs r0, #4
	b _08095A56
	.align 2, 0
_080959FC: .4byte 0x00003AEB
_08095A00: .4byte 0x030046A0
_08095A04:
	movs r2, #0
	ldr r1, _08095A3C @ =0x00003AE8
	adds r3, r5, r1
	ldrb r0, [r3]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08095A28
	adds r1, r3, #0
	movs r3, #1
_08095A18:
	adds r2, #1
	cmp r2, #3
	bgt _08095A44
	ldrb r0, [r1]
	asrs r0, r2
	ands r0, r3
	cmp r0, #0
	beq _08095A18
_08095A28:
	cmp r2, #3
	bgt _08095A44
	adds r1, r2, #0
	adds r1, #0x10
	ldr r2, _08095A40 @ =0x00003AEB
	adds r0, r5, r2
	strb r1, [r0]
	movs r0, #1
	b _08095A56
	.align 2, 0
_08095A3C: .4byte 0x00003AE8
_08095A40: .4byte 0x00003AEB
_08095A44:
	movs r0, #0
	b _08095A56
_08095A48:
	movs r0, #3
	b _08095A56
_08095A4C:
	cmp r1, #0x14
	beq _08095A54
	movs r0, #1
	b _08095A56
_08095A54:
	movs r0, #2
_08095A56:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08095a5c
FUN_08095a5c: @ 0x08095A5C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08095AD0 @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0808de30
	adds r0, r4, #0
	bl FUN_0809536c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080954a8
	ldr r1, _08095AD4 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r2, _08095AD8 @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fbcc
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08094a94
	ldr r1, _08095ADC @ =0x00001464
	adds r0, r4, r1
	ldr r2, _08095AE0 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080952f4
	adds r0, r4, #0
	bl FUN_08094eb0
	adds r0, r4, #0
	bl weapon_08094f88
	adds r0, r4, #0
	movs r1, #0
	bl weapon_08095820
	ldr r1, _08095AE4 @ =FUN_08095ae8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08095AD0: .4byte 0x000014AC
_08095AD4: .4byte 0x0000144C
_08095AD8: .4byte 0x00003AE8
_08095ADC: .4byte 0x00001464
_08095AE0: .4byte 0x00003AEB
_08095AE4: .4byte FUN_08095ae8

	thumb_func_start FUN_08095ae8
FUN_08095ae8: @ 0x08095AE8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0808c548
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	ldr r6, _08095B28 @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08095B30
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #9
	bl FUN_0808c658
	ldr r1, _08095B2C @ =FUN_08095c60
	b _08095C12
	.align 2, 0
_08095B28: .4byte 0x030044E0
_08095B2C: .4byte FUN_08095c60
_08095B30:
	ldr r2, _08095BC4 @ =0x000009F8
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08095BC8 @ =0x00001444
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x60
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r2, _08095BCC @ =0x00001E64
	adds r0, r5, r2
	adds r1, r4, #0
	movs r2, #0x40
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r1, [r6, #2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08095C20
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _08095BD0 @ =0x00003AE8
	adds r0, r5, r1
	bl FUN_0808fbbc
	ldr r0, _08095BD4 @ =0x000014AC
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08095BD8 @ =0x000014C4
	adds r0, r5, r1
	ldr r2, _08095BDC @ =0x00003AEE
	adds r4, r5, r2
	ldrb r1, [r4]
	bl FUN_080952f4
	ldr r1, _08095BE0 @ =0x00003AEB
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08095BF0
	ldr r2, _08095BE4 @ =0x0000144C
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, _08095BE8 @ =0x0000204C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, [r5, #0x58]
	movs r1, #4
	movs r2, #0
	bl FUN_0808c510
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0808b6fc
	adds r0, r5, #0
	bl FUN_0808c700
	ldr r1, _08095BEC @ =FUN_080960c8
	b _08095C12
	.align 2, 0
_08095BC4: .4byte 0x000009F8
_08095BC8: .4byte 0x00001444
_08095BCC: .4byte 0x00001E64
_08095BD0: .4byte 0x00003AE8
_08095BD4: .4byte 0x000014AC
_08095BD8: .4byte 0x000014C4
_08095BDC: .4byte 0x00003AEE
_08095BE0: .4byte 0x00003AEB
_08095BE4: .4byte 0x0000144C
_08095BE8: .4byte 0x0000204C
_08095BEC: .4byte FUN_080960c8
_08095BF0:
	ldrb r1, [r4]
	adds r0, r5, #0
	bl GetWeaponPermission
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_08094a94
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080954a8
	adds r0, r5, #0
	movs r1, #1
	bl weapon_08095820
	ldr r1, _08095C1C @ =weapon_08095d4c
_08095C12:
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
	b _08095C4E
	.align 2, 0
_08095C1C: .4byte weapon_08095d4c
_08095C20:
	ldr r1, _08095C54 @ =0x00003AE8
	adds r0, r5, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _08095C4E
	ldr r2, _08095C58 @ =0x00001464
	adds r0, r5, r2
	ldr r2, _08095C5C @ =0x00003AEB
	adds r1, r5, r2
	ldrb r1, [r1]
	bl FUN_080952f4
	adds r0, r5, #0
	bl FUN_08094eb0
	adds r0, r5, #0
	bl weapon_08094f88
	adds r0, r5, #0
	movs r1, #0
	bl weapon_08095820
_08095C4E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08095C54: .4byte 0x00003AE8
_08095C58: .4byte 0x00001464
_08095C5C: .4byte 0x00003AEB

	thumb_func_start FUN_08095c60
FUN_08095c60: @ 0x08095C60
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a5b0
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a5e0
	ldr r6, _08095D10 @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08095D30
	ldr r1, _08095D14 @ =0x00001444
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x60
	adds r1, r4, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _08095D18 @ =0x00001E64
	adds r0, r5, r2
	adds r1, r4, #0
	bl FUN_082372cc
	ldrh r1, [r6, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08095D42
	ldr r1, _08095D1C @ =0x00000F41
	adds r0, r5, r1
	ldrb r6, [r0]
	cmp r6, #0
	bne _08095D42
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #1
	bls _08095D42
	ldr r0, _08095D20 @ =0x0000010B
	bl PlaySound_082406e0
	ldr r0, _08095D24 @ =0x00000D98
	adds r2, r5, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r4, [r4]
	cmp r0, r4
	blt _08095CE0
	strb r6, [r2]
_08095CE0:
	ldr r0, _08095D28 @ =0x030046A0
	ldr r1, [r0]
	adds r1, #0x58
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r0, #0x68
	muls r0, r2, r0
	adds r0, r5, r0
	ldr r2, _08095D2C @ =0x00000D9C
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080954a8
	adds r0, r5, #0
	bl FUN_0808de30
	b _08095D42
	.align 2, 0
_08095D10: .4byte 0x030044E0
_08095D14: .4byte 0x00001444
_08095D18: .4byte 0x00001E64
_08095D1C: .4byte 0x00000F41
_08095D20: .4byte 0x0000010B
_08095D24: .4byte 0x00000D98
_08095D28: .4byte 0x030046A0
_08095D2C: .4byte 0x00000D9C
_08095D30:
	adds r0, r5, #0
	movs r1, #0
	bl weapon_08095820
	ldr r1, _08095D48 @ =FUN_08095ae8
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0808a354
_08095D42:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08095D48: .4byte FUN_08095ae8

	thumb_func_start weapon_08095d4c
weapon_08095d4c: @ 0x08095D4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08095DE4 @ =0x00001444
	adds r5, r4, r0
	adds r6, r4, #0
	adds r6, #0x60
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_082372cc
	adds r0, r4, #0
	bl FUN_0808c548
	ldr r0, _08095DE8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08095D7E
	b _08095EC4
_08095D7E:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08095E00
	ldr r1, _08095DEC @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08095E00
	ldr r7, _08095DF0 @ =0x00001C2C
	adds r2, r4, r7
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08095DF4 @ =0x00001464
	adds r0, r4, r1
	movs r1, #0x14
	bl FUN_080921e8
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r6, _08095DF8 @ =0x0000204C
	adds r2, r4, r6
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r4, #0x58]
	movs r1, #2
	movs r2, #1
	bl FUN_0808c510
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _08095DFC @ =FUN_080962b0
	adds r0, r4, #0
	b _08095FAA
	.align 2, 0
_08095DE4: .4byte 0x00001444
_08095DE8: .4byte 0x030044E0
_08095DEC: .4byte 0x00003AE8
_08095DF0: .4byte 0x00001C2C
_08095DF4: .4byte 0x00001464
_08095DF8: .4byte 0x0000204C
_08095DFC: .4byte FUN_080962b0
_08095E00:
	ldr r0, _08095E2C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08095E0E
	b _08095FDA
_08095E0E:
	adds r0, r4, #0
	bl FUN_0808c700
	adds r0, r4, #0
	bl FUN_0809596c
	cmp r0, #4
	bls _08095E20
	b _08095FD0
_08095E20:
	lsls r0, r0, #2
	ldr r1, _08095E30 @ =_08095E34
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08095E2C: .4byte 0x030044E0
_08095E30: .4byte _08095E34
_08095E34: @ jump table
	.4byte _08095FD0 @ case 0
	.4byte _08095E80 @ case 1
	.4byte _08095E48 @ case 2
	.4byte _08095ED8 @ case 3
	.4byte _08095EB8 @ case 4
_08095E48:
	ldr r7, _08095E74 @ =0x0000144C
	adds r1, r4, r7
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08095E78 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	bl FUN_0808c510
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _08095E7C @ =FUN_080962b0
	adds r0, r4, #0
	b _08095FAA
	.align 2, 0
_08095E74: .4byte 0x0000144C
_08095E78: .4byte 0x0000204C
_08095E7C: .4byte FUN_080962b0
_08095E80:
	ldr r1, _08095EA8 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _08095EAC @ =0x00003AEE
	adds r0, r4, r2
	ldrb r2, [r0]
	ldr r6, _08095EB0 @ =0x00003AEB
	adds r0, r4, r6
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080956c4
	ldr r1, _08095EB4 @ =FUN_0809611c
	adds r0, r4, #0
	b _08095FAA
	.align 2, 0
_08095EA8: .4byte 0x0000144C
_08095EAC: .4byte 0x00003AEE
_08095EB0: .4byte 0x00003AEB
_08095EB4: .4byte FUN_0809611c
_08095EB8:
	ldr r7, _08095ED4 @ =0x00003AEB
	adds r0, r4, r7
	ldrb r0, [r0]
	subs r0, #0x10
	bl FUN_08242f84
_08095EC4:
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08095a5c
	b _08096008
	.align 2, 0
_08095ED4: .4byte 0x00003AEB
_08095ED8:
	ldr r0, _08095FB4 @ =0x0000144C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08095FB8 @ =0x00003AEE
	adds r7, r4, r1
	ldrb r0, [r7]
	bl GetWeaponID
	cmp r0, #0
	ble _08095F02
	ldrb r2, [r7]
	ldr r6, _08095FBC @ =0x00003AEB
	adds r0, r4, r6
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080956c4
_08095F02:
	ldr r0, _08095FBC @ =0x00003AEB
	adds r6, r4, r0
	ldrb r0, [r6]
	bl GetWeaponID
	cmp r0, #0
	ble _08095F1C
	ldrb r2, [r6]
	ldrb r3, [r7]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080956c4
_08095F1C:
	movs r5, #0
	ldr r1, _08095FC0 @ =FUN_0809620c
	mov sb, r1
	ldr r2, _08095FC4 @ =0x030046A0
	mov ip, r2
	ldr r0, [r2]
	mov r8, r7
	ldr r7, _08095FC8 @ =0x00001ECC
	adds r1, r4, r7
	adds r3, r0, #0
	adds r3, #0x60
	movs r0, #1
	mov sl, r0
	str r6, [sp]
_08095F38:
	lsls r2, r5, #1
	movs r6, #0
	ldrsh r0, [r3, r6]
	mov r7, r8
	ldrb r7, [r7]
	cmp r0, r7
	bne _08095F4E
	ldr r0, [r1]
	mov r6, sl
	orrs r0, r6
	str r0, [r1]
_08095F4E:
	mov r7, ip
	ldr r0, [r7]
	adds r0, r2, r0
	adds r0, #0x60
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r6, [sp]
	ldrb r6, [r6]
	cmp r0, r6
	bne _08095F6A
	ldr r0, [r1]
	mov r7, sl
	orrs r0, r7
	str r0, [r1]
_08095F6A:
	adds r1, #0x60
	adds r3, #2
	adds r5, #1
	cmp r5, #3
	ble _08095F38
	ldr r1, _08095FB8 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r6, _08095FCC @ =0x00000F6C
	adds r2, r4, r6
	adds r0, r2, r0
	ldr r1, [r0]
	movs r3, #1
	orrs r1, r3
	str r1, [r0]
	ldr r7, _08095FBC @ =0x00003AEB
	adds r0, r4, r7
	ldrb r1, [r0]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r2, r2, r0
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	adds r0, r4, #0
	mov r1, sb
_08095FAA:
	movs r2, #1
	bl FUN_0808a354
	b _08096008
	.align 2, 0
_08095FB4: .4byte 0x0000144C
_08095FB8: .4byte 0x00003AEE
_08095FBC: .4byte 0x00003AEB
_08095FC0: .4byte FUN_0809620c
_08095FC4: .4byte 0x030046A0
_08095FC8: .4byte 0x00001ECC
_08095FCC: .4byte 0x00000F6C
_08095FD0:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08096008
_08095FDA:
	ldr r1, _08096018 @ =0x00003AE8
	adds r0, r4, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _08096008
	ldr r2, _0809601C @ =0x00001464
	adds r0, r4, r2
	ldr r6, _08096020 @ =0x00003AEB
	adds r1, r4, r6
	ldrb r1, [r1]
	bl FUN_080952f4
	adds r0, r4, #0
	bl FUN_08094eb0
	adds r0, r4, #0
	bl weapon_08094f88
	adds r0, r4, #0
	movs r1, #1
	bl weapon_08095820
_08096008:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096018: .4byte 0x00003AE8
_0809601C: .4byte 0x00001464
_08096020: .4byte 0x00003AEB

	thumb_func_start FUN_08096024
FUN_08096024: @ 0x08096024
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809605C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809606C
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _08096060 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _08096064 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080952f4
	adds r0, r4, #0
	bl FUN_08094eb0
	ldr r1, _08096068 @ =weapon_08095d4c
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _080960A4
	.align 2, 0
_0809605C: .4byte 0x030044E0
_08096060: .4byte 0x00001464
_08096064: .4byte 0x00003AEB
_08096068: .4byte weapon_08095d4c
_0809606C:
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080960A4
	ldr r0, _080960B8 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080960BC @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	bl FUN_0808c510
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _080960C0 @ =FUN_080962b0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_080960A4:
	ldr r1, _080960C4 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl FUN_082372cc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080960B8: .4byte 0x0000144C
_080960BC: .4byte 0x0000204C
_080960C0: .4byte FUN_080962b0
_080960C4: .4byte 0x00001444

	thumb_func_start FUN_080960c8
FUN_080960c8: @ 0x080960C8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _080960E2
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08095a5c
	b _0809610C
_080960E2:
	cmp r0, #1
	bne _0809610C
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortWeapons
	ldr r1, _08096114 @ =0x00003AEC
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08096118 @ =0x00003AED
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08095a5c
_0809610C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096114: .4byte 0x00003AEC
_08096118: .4byte 0x00003AED

	thumb_func_start FUN_0809611c
FUN_0809611c: @ 0x0809611C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08096154 @ =0x000009EE
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _08096130
	ldr r0, _08096158 @ =0x0000038A
	bl PlaySound_082406e0
_08096130:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08096164
	ldr r1, _0809615C @ =0x000020C4
	adds r0, r4, r1
	ldr r2, _08096160 @ =0x00003B68
	adds r1, r4, r2
	ldrh r3, [r5]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _0809618E
	.align 2, 0
_08096154: .4byte 0x000009EE
_08096158: .4byte 0x0000038A
_0809615C: .4byte 0x000020C4
_08096160: .4byte 0x00003B68
_08096164:
	ldr r0, _08096194 @ =0x00000111
	bl PlaySound_082406e0
	ldr r0, _08096198 @ =0x000020AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0809619C @ =0x00003AEE
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _080961A0 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	subs r1, #0x10
	bl FUN_08242f44
	adds r0, r4, #0
	bl FUN_08095a5c
_0809618E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096194: .4byte 0x00000111
_08096198: .4byte 0x000020AC
_0809619C: .4byte 0x00003AEE
_080961A0: .4byte 0x00003AEB

	thumb_func_start FUN_080961a4
FUN_080961a4: @ 0x080961A4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080961CC @ =0x000009EE
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080961EC
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080961D4
	ldr r2, _080961D0 @ =0x00001BE6
	adds r1, r4, r2
	b _080961FA
	.align 2, 0
_080961CC: .4byte 0x000009EE
_080961D0: .4byte 0x00001BE6
_080961D4:
	ldrh r1, [r2]
	movs r0, #0x10
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x68
	subs r1, r1, r0
	ldr r2, _080961E8 @ =0x00001BE6
	adds r0, r4, r2
	strh r1, [r0]
	b _080961FE
	.align 2, 0
_080961E8: .4byte 0x00001BE6
_080961EC:
	ldr r1, _08096204 @ =FUN_08095ae8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	ldr r0, _08096208 @ =0x00001BE6
	adds r1, r4, r0
_080961FA:
	movs r0, #0x68
	strh r0, [r1]
_080961FE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096204: .4byte FUN_08095ae8
_08096208: .4byte 0x00001BE6

	thumb_func_start FUN_0809620c
FUN_0809620c: @ 0x0809620C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08096254 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08096220
	ldr r0, _08096258 @ =0x0000038A
	bl PlaySound_082406e0
_08096220:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _0809626C
	ldrh r0, [r4]
	movs r4, #0xc
	subs r4, r4, r0
	ldr r1, _0809625C @ =0x000020C4
	adds r0, r5, r1
	ldr r2, _08096260 @ =0x00003B68
	adds r1, r5, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	ldr r1, _08096264 @ =0x00002124
	adds r0, r5, r1
	ldr r2, _08096268 @ =0x00003B70
	adds r1, r5, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	b _08096298
	.align 2, 0
_08096254: .4byte 0x000009EE
_08096258: .4byte 0x0000038A
_0809625C: .4byte 0x000020C4
_08096260: .4byte 0x00003B68
_08096264: .4byte 0x00002124
_08096268: .4byte 0x00003B70
_0809626C:
	ldr r0, _080962A0 @ =0x000020AC
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080962A4 @ =0x0000210C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080962A8 @ =0x00003AEE
	adds r0, r5, r1
	ldrb r0, [r0]
	ldr r2, _080962AC @ =0x00003AEB
	adds r1, r5, r2
	ldrb r1, [r1]
	bl SwapWeaponSlot
	adds r0, r5, #0
	bl FUN_08095a5c
_08096298:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080962A0: .4byte 0x000020AC
_080962A4: .4byte 0x0000210C
_080962A8: .4byte 0x00003AEE
_080962AC: .4byte 0x00003AEB

	thumb_func_start FUN_080962b0
FUN_080962b0: @ 0x080962B0
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _080962CA
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08095a5c
	b _080962FC
_080962CA:
	cmp r0, #1
	bne _080962FC
	ldr r0, _08096304 @ =0x00003AEE
	adds r4, r5, r0
	ldrb r2, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0x14
	bl FUN_080956c4
	ldrb r0, [r4]
	bl FUN_08242c08
	adds r0, r5, #0
	bl FUN_0809536c
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080954a8
	ldr r1, _08096308 @ =FUN_0809630c
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_080962FC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096304: .4byte 0x00003AEE
_08096308: .4byte FUN_0809630c

	thumb_func_start FUN_0809630c
FUN_0809630c: @ 0x0809630C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08096344 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08096320
	ldr r0, _08096348 @ =0x0000038A
	bl PlaySound_082406e0
_08096320:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08096354
	ldr r1, _0809634C @ =0x000020C4
	adds r0, r5, r1
	ldr r2, _08096350 @ =0x00003B68
	adds r1, r5, r2
	ldrh r3, [r4]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _0809636A
	.align 2, 0
_08096344: .4byte 0x000009EE
_08096348: .4byte 0x0000038A
_0809634C: .4byte 0x000020C4
_08096350: .4byte 0x00003B68
_08096354:
	ldr r0, _08096370 @ =0x000020AC
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08096374 @ =FUN_08096378
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0808a354
_0809636A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08096370: .4byte 0x000020AC
_08096374: .4byte FUN_08096378

	thumb_func_start FUN_08096378
FUN_08096378: @ 0x08096378
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080963B0 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809638E
	movs r0, #0x87
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809638E:
	ldrh r0, [r4]
	adds r1, r0, #1
	strh r1, [r4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _080963D0
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080963B8
	ldr r2, _080963B4 @ =0x00001BE6
	adds r1, r5, r2
	b _080963DC
	.align 2, 0
_080963B0: .4byte 0x000009EE
_080963B4: .4byte 0x00001BE6
_080963B8:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x46
	subs r1, r1, r0
	ldr r2, _080963CC @ =0x00001BE6
	adds r0, r5, r2
	strh r1, [r0]
	b _080963EE
	.align 2, 0
_080963CC: .4byte 0x00001BE6
_080963D0:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080963E8
	ldr r0, _080963E4 @ =0x00001BE6
	adds r1, r5, r0
_080963DC:
	movs r0, #0x46
	strh r0, [r1]
	b _080963EE
	.align 2, 0
_080963E4: .4byte 0x00001BE6
_080963E8:
	adds r0, r5, #0
	bl FUN_08095a5c
_080963EE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080963f4
FUN_080963f4: @ 0x080963F4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b8a4
	adds r0, r4, #0
	bl FUN_0809536c
	adds r0, r4, #0
	bl FUN_0808b910
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080954a8
	ldr r0, _08096438 @ =0x00001BCC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0809643C @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08096448
	ldr r1, _08096440 @ =0x00001BC4
	adds r0, r4, r1
	ldr r1, _08096444 @ =0x000002DF
	bl FUN_0808ba0c
	b _08096454
	.align 2, 0
_08096438: .4byte 0x00001BCC
_0809643C: .4byte 0x00003AE8
_08096440: .4byte 0x00001BC4
_08096444: .4byte 0x000002DF
_08096448:
	ldr r1, _0809647C @ =0x00001BC4
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_08096454:
	ldr r0, _08096480 @ =0x00001C8C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08096484 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08096490
	ldr r1, _08096488 @ =0x00001C84
	adds r0, r4, r1
	ldr r1, _0809648C @ =0x000002DF
	bl FUN_0808ba0c
	b _0809649C
	.align 2, 0
_0809647C: .4byte 0x00001BC4
_08096480: .4byte 0x00001C8C
_08096484: .4byte 0x00003AE8
_08096488: .4byte 0x00001C84
_0809648C: .4byte 0x000002DF
_08096490:
	ldr r1, _080964A8 @ =0x00001C84
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_0809649C:
	adds r0, r4, #0
	bl FUN_0808bac4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080964A8: .4byte 0x00001C84

	thumb_func_start FUN_080964ac
FUN_080964ac: @ 0x080964AC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x20
	bl FUN_08094a94
	ldr r1, _08096508 @ =0x00003AE8
	adds r0, r4, r1
	movs r1, #0
	movs r2, #0
	bl FUN_0808fbdc
	ldr r0, _0809650C @ =0x00001464
	adds r6, r4, r0
	ldr r1, _08096510 @ =0x00003AEB
	adds r5, r4, r1
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_080952f4
	ldr r0, _08096514 @ =0x0000144C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08096518 @ =0x00001444
	adds r0, r4, r1
	adds r4, #0x60
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_080952f4
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096508: .4byte 0x00003AE8
_0809650C: .4byte 0x00001464
_08096510: .4byte 0x00003AEB
_08096514: .4byte 0x0000144C
_08096518: .4byte 0x00001444

	thumb_func_start FUN_0809651c
FUN_0809651c: @ 0x0809651C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08096614 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _08096618 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #7
	bl FUN_0808a3c4
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0809657E
	movs r0, #0x12
	movs r1, #4
	movs r2, #0xb
	movs r3, #0xb
	bl FUN_0808b9c4
	movs r0, #8
	movs r1, #9
	movs r2, #5
	movs r3, #6
	bl FUN_0808b9c4
_0809657E:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	adds r0, r4, #0
	bl FUN_0808b38c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _0809661C @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, _08096620 @ =0x0000156C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08096624 @ =0x00001564
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0x9f
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080964ac
	adds r0, r4, #0
	bl FUN_080963f4
	adds r0, r4, #0
	bl weapon_08094f88
	bl FUN_08049f5c
	ldr r0, _08096628 @ =0x0000EFDA
	bl FUN_08047dc0
	adds r0, r4, #0
	bl FUN_08094eb0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808c61c
	adds r0, r4, #0
	movs r1, #0
	bl weapon_08095820
	ldr r1, _0809662C @ =FUN_08095ae8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08096614: .4byte 0x00004014
_08096618: .4byte 0x00004018
_0809661C: .4byte 0x00000F56
_08096620: .4byte 0x0000156C
_08096624: .4byte 0x00001564
_08096628: .4byte 0x0000EFDA
_0809662C: .4byte FUN_08095ae8

	thumb_func_start FUN_08096630
FUN_08096630: @ 0x08096630
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	adds r7, r1, #0
	ldr r0, _08096680 @ =0x00003AE8
	adds r6, r2, r0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08096688
	movs r0, #0
	strb r0, [r6]
	movs r4, #0
	ldr r0, _08096684 @ =0x00003AF0
	adds r7, r2, r0
	movs r5, #0xff
_0809665E:
	adds r2, r4, #1
	adds r1, r4, r7
	movs r3, #8
_08096664:
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _08096664
	adds r4, r2, #0
	cmp r4, #3
	ble _0809665E
	movs r0, #0
	strb r0, [r6, #8]
	b _08096732
	.align 2, 0
_08096680: .4byte 0x00003AE8
_08096684: .4byte 0x00003AF0
_08096688:
	strb r7, [r6]
	movs r4, #0
	ldr r0, _080966E4 @ =0x00003AF0
	adds r1, r2, r0
	adds r0, #0x20
	adds r0, r0, r2
	mov r8, r0
	ldr r0, _080966E8 @ =0x00003B13
	adds r0, r0, r2
	mov ip, r0
	adds r5, r1, #0
_0809669E:
	lsls r0, r4, #2
	movs r3, #3
	adds r2, r0, #3
	adds r0, r4, r5
	adds r0, #0xc
_080966A8:
	strb r2, [r0]
	subs r2, #1
	subs r0, #4
	subs r3, #1
	cmp r3, #0
	bge _080966A8
	adds r4, #1
	cmp r4, #3
	ble _0809669E
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	beq _080966EC
	movs r4, #0
	movs r2, #0x10
	adds r5, r1, #0
	adds r5, #0x10
_080966CA:
	movs r3, #3
	adds r0, r4, r5
	adds r0, #0xc
_080966D0:
	strb r2, [r0]
	subs r0, #4
	subs r3, #1
	cmp r3, #0
	bge _080966D0
	adds r4, #1
	cmp r4, #3
	ble _080966CA
	b _0809670C
	.align 2, 0
_080966E4: .4byte 0x00003AF0
_080966E8: .4byte 0x00003B13
_080966EC:
	movs r4, #0
	movs r5, #0xff
	adds r6, r1, #0
	adds r6, #0x10
_080966F4:
	adds r2, r4, r6
	movs r3, #3
_080966F8:
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _080966F8
	adds r4, #1
	cmp r4, #3
	ble _080966F4
_0809670C:
	movs r4, #0
	mov r2, r8
	movs r3, #0xff
_08096712:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #2
	ble _08096712
	movs r0, #0x20
	ands r0, r7
	cmp r0, #0
	beq _0809672C
	movs r0, #0x15
	b _0809672E
_0809672C:
	movs r0, #0xff
_0809672E:
	mov r1, ip
	strb r0, [r1]
_08096732:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809673c
FUN_0809673c: @ 0x0809673C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _0809678C
	movs r3, #0
	ldr r6, _08096780 @ =0x030046A0
	ldr r0, _08096784 @ =0x00003FE0
	adds r4, r5, r0
	ldr r0, [r6]
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r2, r0, r1
_08096764:
	adds r1, r4, r3
	ldrh r0, [r2]
	strb r0, [r1]
	adds r2, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08096764
	ldr r0, [r6]
	adds r0, #0x5c
	ldrh r1, [r0]
	ldr r2, _08096788 @ =0x00003FDC
	adds r0, r5, r2
	strb r1, [r0]
	b _080967B0
	.align 2, 0
_08096780: .4byte 0x030046A0
_08096784: .4byte 0x00003FE0
_08096788: .4byte 0x00003FDC
_0809678C:
	ldr r0, _080967B8 @ =0x00003FE0
	adds r1, r5, r0
	movs r0, #0xa
	strb r0, [r1]
	movs r3, #1
	adds r2, r1, #0
	movs r4, #0xff
_0809679A:
	adds r1, r2, r3
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r3, #1
	cmp r3, #0xf
	ble _0809679A
	ldr r2, _080967BC @ =0x00003FDC
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_080967B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080967B8: .4byte 0x00003FE0
_080967BC: .4byte 0x00003FDC

	thumb_func_start FUN_080967c0
FUN_080967c0: @ 0x080967C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	mov r8, r0
	movs r0, #0
	str r0, [sp, #0x34]
	ldr r0, _080967E4 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _080967E8
	movs r0, #0
	b _08096802
	.align 2, 0
_080967E4: .4byte 0x030046A0
_080967E8:
	ldr r0, _08096828 @ =0x00003FDC
	add r0, r8
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, _0809682C @ =0x00003FE0
	add r0, r8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #3
	ldr r1, _08096830 @ =0x08DAA7B0
	adds r0, r0, r1
_08096802:
	bl FUN_0807a70c
	adds r7, r0, #0
	ldr r1, _08096834 @ =0x00003AEB
	add r1, r8
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _08096822
	ldr r0, _0809682C @ =0x00003FE0
	add r0, r8
	ldrb r1, [r1]
	adds r1, r0, r1
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08096838
_08096822:
	adds r6, r7, #0
	b _0809684C
	.align 2, 0
_08096828: .4byte 0x00003FDC
_0809682C: .4byte 0x00003FE0
_08096830: .4byte 0x08DAA7B0
_08096834: .4byte 0x00003AEB
_08096838:
	movs r0, #1
	str r0, [sp, #0x34]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #3
	ldr r1, _08096878 @ =0x08DAA7B0
	adds r0, r0, r1
	bl FUN_0807a70c
	adds r6, r0, #0
_0809684C:
	cmp r6, r7
	bne _08096880
	movs r2, #1
	ldr r1, _0809687C @ =0x0000216C
	add r1, r8
	movs r5, #2
_08096858:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _08096858
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0x64
	movs r2, #6
	movs r3, #6
	bl FUN_0808b30c
	b _08096908
	.align 2, 0
_08096878: .4byte 0x08DAA7B0
_0809687C: .4byte 0x0000216C
_08096880:
	movs r0, #6
	movs r1, #6
	movs r2, #3
	movs r3, #1
	bl FUN_0808b97c
	adds r0, r6, #0
	movs r1, #0x64
	bl Div
	add r5, sp, #0x28
	str r0, [sp, #0x28]
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	subs r4, r6, r4
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [r5, #8]
	movs r1, #0x14
	mov sl, r1
	adds r0, r5, #0
	cmp r6, r7
	ble _080968C2
	movs r1, #0xa
	mov sl, r1
_080968C2:
	movs r5, #0
	movs r1, #0x60
	add r1, r8
	mov sb, r1
	str r0, [sp, #0x3c]
	ldr r4, _0809692C @ =0x0000216C
	add r4, r8
	ldr r6, _08096930 @ =0x00002164
	add r6, r8
	movs r7, #0x30
_080968D6:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	strh r7, [r4, #0x18]
	movs r0, #0x30
	strh r0, [r4, #0x1a]
	ldr r0, [sp, #0x3c]
	ldm r0!, {r2}
	str r0, [sp, #0x3c]
	add r2, sl
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	adds r6, #0x60
	adds r7, #8
	adds r5, #1
	cmp r5, #2
	ble _080968D6
_08096908:
	ldr r0, _08096934 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r1, sp, #4
	bl FUN_08242b28
	add r0, sp, #4
	bl FUN_0807a6cc
	adds r7, r0, #0
	ldr r0, [sp, #0x34]
	cmp r0, #0
	bne _08096938
	adds r6, r7, #0
	b _08096956
	.align 2, 0
_0809692C: .4byte 0x0000216C
_08096930: .4byte 0x00002164
_08096934: .4byte 0x030046A0
_08096938:
	ldr r1, _08096984 @ =0x00003AEB
	add r1, r8
	ldr r0, _08096988 @ =0x00003FE0
	add r0, r8
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #3
	ldr r0, _0809698C @ =0x08DAA7B0
	adds r1, r1, r0
	add r0, sp, #4
	bl FUN_0807a5d8
	adds r6, r0, #0
_08096956:
	cmp r6, r7
	bne _08096994
	movs r2, #1
	ldr r1, _08096990 @ =0x0000228C
	add r1, r8
	movs r5, #2
_08096962:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _08096962
	movs r0, #0
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0x64
	movs r2, #6
	movs r3, #5
	bl FUN_0808b30c
	b _08096A1C
	.align 2, 0
_08096984: .4byte 0x00003AEB
_08096988: .4byte 0x00003FE0
_0809698C: .4byte 0x08DAA7B0
_08096990: .4byte 0x0000228C
_08096994:
	movs r0, #6
	movs r1, #5
	movs r2, #3
	movs r3, #1
	bl FUN_0808b97c
	adds r0, r6, #0
	movs r1, #0x64
	bl Div
	add r5, sp, #0x28
	str r0, [sp, #0x28]
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	subs r4, r6, r4
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [r5, #8]
	movs r1, #0x14
	mov sl, r1
	adds r0, r5, #0
	cmp r6, r7
	ble _080969D6
	movs r1, #0xa
	mov sl, r1
_080969D6:
	movs r5, #0
	movs r1, #0x60
	add r1, r8
	mov sb, r1
	str r0, [sp, #0x38]
	ldr r4, _08096A2C @ =0x0000228C
	add r4, r8
	ldr r6, _08096A30 @ =0x00002284
	add r6, r8
	movs r7, #0x30
_080969EA:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	strh r7, [r4, #0x18]
	movs r0, #0x28
	strh r0, [r4, #0x1a]
	ldr r0, [sp, #0x38]
	ldm r0!, {r2}
	str r0, [sp, #0x38]
	add r2, sl
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	adds r6, #0x60
	adds r7, #8
	adds r5, #1
	cmp r5, #2
	ble _080969EA
_08096A1C:
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096A2C: .4byte 0x0000228C
_08096A30: .4byte 0x00002284

	thumb_func_start FUN_08096a34
FUN_08096a34: @ 0x08096A34
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08096A68 @ =0x00003AEB
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _08096A52
	ldr r2, _08096A6C @ =0x00003FE0
	adds r0, r6, r2
	ldrb r1, [r1]
	adds r1, r0, r1
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08096A74
_08096A52:
	ldr r1, _08096A70 @ =0x0000204C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _08096ADC
	.align 2, 0
_08096A68: .4byte 0x00003AEB
_08096A6C: .4byte 0x00003FE0
_08096A70: .4byte 0x0000204C
_08096A74:
	movs r5, #0
	ldrsb r5, [r1, r5]
	ldr r0, _08096AE4 @ =0x0000204C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08096AE8 @ =0x00002044
	adds r0, r6, r1
	adds r1, r6, #0
	adds r1, #0xa0
	movs r2, #0xcf
	movs r3, #1
	bl Sprite_SetSprite
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r6, #0x48]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	bl FUN_08047a28
	ldr r0, _08096AEC @ =0x08DAA7B0
	lsls r4, r5, #3
	adds r4, r4, r0
	ldrb r1, [r4, #1]
	movs r0, #0
	bl FUN_08049e6c
	ldrb r1, [r4, #2]
	movs r0, #1
	bl FUN_08049e6c
	ldr r0, [r6, #0x48]
	bl VM_ParseStringRef
	adds r0, #0x25
	adds r0, r0, r5
	bl Textbox_LookupString
	bl FUN_08049e30
_08096ADC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096AE4: .4byte 0x0000204C
_08096AE8: .4byte 0x00002044
_08096AEC: .4byte 0x08DAA7B0

	thumb_func_start FUN_08096af0
FUN_08096af0: @ 0x08096AF0
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _08096B14
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r3]
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	b _08096B3E
_08096B14:
	cmp r2, #0x15
	bne _08096B20
	movs r0, #0x78
	strh r0, [r3]
	movs r0, #0x68
	b _08096B3E
_08096B20:
	cmp r2, #0x14
	bne _08096B2C
	movs r0, #0x75
	strh r0, [r3]
	movs r0, #0x46
	b _08096B3E
_08096B2C:
	cmp r2, #0x10
	bne _08096B38
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x4c
	b _08096B3E
_08096B38:
	movs r0, #0x90
	strh r0, [r3]
	movs r0, #0x20
_08096B3E:
	strh r0, [r3, #2]
	pop {r0}
	bx r0

	thumb_func_start FUN_08096b44
FUN_08096b44: @ 0x08096B44
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _08096B6C @ =0x000015C4
	adds r5, r6, r0
	ldr r1, _08096B70 @ =0x000015CC
	adds r4, r6, r1
_08096B52:
	ldr r1, _08096B74 @ =0x00003FE0
	adds r0, r6, r1
	adds r2, r0, r7
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bge _08096B78
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	b _08096BA2
	.align 2, 0
_08096B6C: .4byte 0x000015C4
_08096B70: .4byte 0x000015CC
_08096B74: .4byte 0x00003FE0
_08096B78:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r6, #0
	adds r1, #0xa0
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r5, #0
	ldr r1, _08096BB4 @ =0x000002DF
	bl FUN_0808ba0c
_08096BA2:
	adds r5, #0x60
	adds r4, #0x60
	adds r7, #1
	cmp r7, #0xf
	ble _08096B52
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096BB4: .4byte 0x000002DF

	thumb_func_start FUN_08096bb8
FUN_08096bb8: @ 0x08096BB8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, _08096C14 @ =0x00003FDC
	adds r3, r4, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _08096C88
	ldr r1, _08096C18 @ =0x00001CEC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _08096C1C @ =0x00001CE4
	adds r5, r4, r0
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	ldrsb r2, [r3, r2]
	ldr r3, _08096C20 @ =0x00003FE0
	adds r0, r4, r3
	adds r0, r0, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
	cmp r6, #0
	beq _08096C38
	ldr r1, _08096C24 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08096C2C
	ldr r1, _08096C28 @ =0x000002DF
	b _08096C30
	.align 2, 0
_08096C14: .4byte 0x00003FDC
_08096C18: .4byte 0x00001CEC
_08096C1C: .4byte 0x00001CE4
_08096C20: .4byte 0x00003FE0
_08096C24: .4byte 0x00003AE8
_08096C28: .4byte 0x000002DF
_08096C2C:
	movs r1, #0xb8
	lsls r1, r1, #2
_08096C30:
	adds r0, r5, #0
	bl FUN_0808ba0c
	b _08096C40
_08096C38:
	ldr r1, _08096C74 @ =0x000002DF
	adds r0, r5, #0
	bl FUN_0808ba0c
_08096C40:
	ldr r3, _08096C78 @ =0x00001ECC
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _08096C7C @ =0x00001EE4
	adds r2, r4, r0
	ldr r1, _08096C80 @ =0x00003FDC
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r4, r0
	ldr r3, _08096C84 @ =0x00000F84
	adds r0, r0, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	b _08096C9E
	.align 2, 0
_08096C74: .4byte 0x000002DF
_08096C78: .4byte 0x00001ECC
_08096C7C: .4byte 0x00001EE4
_08096C80: .4byte 0x00003FDC
_08096C84: .4byte 0x00000F84
_08096C88:
	ldr r0, _08096CA4 @ =0x00001CEC
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r3, _08096CA8 @ =0x00001ECC
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08096C9E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096CA4: .4byte 0x00001CEC
_08096CA8: .4byte 0x00001ECC

	thumb_func_start FUN_08096cac
FUN_08096cac: @ 0x08096CAC
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov sb, r3
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #5
	ldr r0, _08096D30 @ =0x000020A4
	adds r4, r4, r0
	adds r4, r6, r4
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	adds r1, r6, #0
	adds r1, #0xa0
	ldr r2, _08096D34 @ =0x00003FE0
	adds r0, r6, r2
	add r0, r8
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	adds r0, #0x20
	mov r1, r8
	bl FUN_08096af0
	lsls r5, r5, #3
	ldr r0, _08096D38 @ =0x00003B68
	adds r5, r5, r0
	adds r5, r6, r5
	adds r0, r5, #0
	mov r1, sb
	bl FUN_08096af0
	movs r1, #0x11
	add r8, r1
	mov r2, r8
	lsls r0, r2, #1
	add r0, r8
	lsls r0, r0, #5
	adds r6, r6, r0
	ldr r0, _08096D3C @ =0x00000F9E
	adds r6, r6, r0
	ldrh r1, [r6]
	adds r0, r4, #0
	bl FUN_0808ba0c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096D30: .4byte 0x000020A4
_08096D34: .4byte 0x00003FE0
_08096D38: .4byte 0x00003B68
_08096D3C: .4byte 0x00000F9E

	thumb_func_start FUN_08096d40
FUN_08096d40: @ 0x08096D40
	push {r4, lr}
	adds r2, r0, #0
	ldr r3, _08096D64 @ =0x00003FE0
	adds r0, r2, r3
	adds r3, r0, r1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _08096D60
	ldr r4, _08096D68 @ =0x00003FDC
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _08096D6C
_08096D60:
	movs r0, #0
	b _08096D8A
	.align 2, 0
_08096D64: .4byte 0x00003FE0
_08096D68: .4byte 0x00003FDC
_08096D6C:
	ldr r0, _08096D84 @ =0x08DAA7B0
	movs r1, #0
	ldrsb r1, [r3, r1]
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r2, #6
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _08096D88
	movs r0, #0x11
	b _08096D8A
	.align 2, 0
_08096D84: .4byte 0x08DAA7B0
_08096D88:
	movs r0, #1
_08096D8A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08096d90
FUN_08096d90: @ 0x08096D90
	push {r4, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _08096DC2
	ldr r1, _08096DB0 @ =0x00003AEB
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08096DB4
	adds r0, r3, #0
	movs r1, #0
	movs r2, #4
	bl FUN_0808c658
	b _08096EBC
	.align 2, 0
_08096DB0: .4byte 0x00003AEB
_08096DB4:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0808c658
	b _08096EBC
_08096DC2:
	movs r1, #0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r3, r2
	ldr r0, [r0]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	beq _08096E72
	ldr r1, _08096E20 @ =0x00003AEE
	adds r0, r3, r1
	ldrb r1, [r0]
	ldr r2, _08096E24 @ =0x00003FE0
	adds r0, r3, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08096E30
	ldr r4, _08096E28 @ =0x00003AEB
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _08096E06
	ldr r0, _08096E2C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _08096E5E
_08096E06:
	ldr r2, _08096E28 @ =0x00003AEB
	adds r0, r3, r2
	ldr r4, _08096E24 @ =0x00003FE0
	adds r1, r3, r4
	ldrb r0, [r0]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r1, #0
	cmp r0, #0
	blt _08096E72
	b _08096E70
	.align 2, 0
_08096E20: .4byte 0x00003AEE
_08096E24: .4byte 0x00003FE0
_08096E28: .4byte 0x00003AEB
_08096E2C: .4byte 0x030046A0
_08096E30:
	ldr r0, _08096E40 @ =0x00003AEB
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, #0x14
	bne _08096E44
	movs r1, #2
	b _08096E72
	.align 2, 0
_08096E40: .4byte 0x00003AEB
_08096E44:
	cmp r0, #0x10
	bne _08096E4C
	movs r1, #1
	b _08096E72
_08096E4C:
	cmp r0, r1
	bne _08096E70
	ldr r0, _08096E64 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bne _08096E68
_08096E5E:
	movs r1, #4
	b _08096E72
	.align 2, 0
_08096E64: .4byte 0x030046A0
_08096E68:
	movs r0, #0x10
	strb r0, [r2]
	movs r1, #1
	b _08096E72
_08096E70:
	movs r1, #3
_08096E72:
	cmp r1, #3
	beq _08096EA2
	cmp r1, #3
	bgt _08096E80
	cmp r1, #1
	beq _08096E86
	b _08096EB0
_08096E80:
	cmp r1, #4
	beq _08096E94
	b _08096EB0
_08096E86:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #5
	bl FUN_0808c658
	b _08096EBC
_08096E94:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #2
	bl FUN_0808c658
	b _08096EBC
_08096EA2:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #3
	bl FUN_0808c658
	b _08096EBC
_08096EB0:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0808c658
_08096EBC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08096ec4
FUN_08096ec4: @ 0x08096EC4
	push {lr}
	adds r1, r0, #0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _08096EE0
_08096EDC:
	movs r0, #0
	b _08096F8A
_08096EE0:
	ldr r2, _08096F14 @ =0x00003AEE
	adds r0, r1, r2
	ldrb r2, [r0]
	ldr r3, _08096F18 @ =0x00003FE0
	adds r0, r1, r3
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08096F44
	ldr r2, _08096F1C @ =0x00003AEB
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0x10
	bne _08096F24
	ldr r0, _08096F20 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _08096F24
	movs r0, #4
	b _08096F8A
	.align 2, 0
_08096F14: .4byte 0x00003AEE
_08096F18: .4byte 0x00003FE0
_08096F1C: .4byte 0x00003AEB
_08096F20: .4byte 0x030046A0
_08096F24:
	ldr r2, _08096F3C @ =0x00003AEB
	adds r0, r1, r2
	ldr r3, _08096F40 @ =0x00003FE0
	adds r1, r1, r3
	ldrb r0, [r0]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08096F88
	b _08096EDC
	.align 2, 0
_08096F3C: .4byte 0x00003AEB
_08096F40: .4byte 0x00003FE0
_08096F44:
	ldr r0, _08096F54 @ =0x00003AEB
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0x14
	bne _08096F58
	movs r0, #2
	b _08096F8A
	.align 2, 0
_08096F54: .4byte 0x00003AEB
_08096F58:
	cmp r0, #0x10
	bne _08096F60
	movs r0, #1
	b _08096F8A
_08096F60:
	cmp r0, r2
	bne _08096F88
	ldr r0, _08096F7C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5c
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r2, r0
	bne _08096F80
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #4
	b _08096F8A
	.align 2, 0
_08096F7C: .4byte 0x030046A0
_08096F80:
	movs r0, #0x10
	strb r0, [r1]
	movs r0, #1
	b _08096F8A
_08096F88:
	movs r0, #3
_08096F8A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08096f90
FUN_08096f90: @ 0x08096F90
	push {lr}
	adds r1, r0, #0
	ldr r2, _08096FA4 @ =0x00001444
	adds r0, r1, r2
	adds r1, #0x60
	bl FUN_082372cc
	pop {r0}
	bx r0
	.align 2, 0
_08096FA4: .4byte 0x00001444

	thumb_func_start FUN_08096fa8
FUN_08096fa8: @ 0x08096FA8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809701C @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08097020 @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0809673c
	adds r0, r4, #0
	bl FUN_08096b44
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08096bb8
	ldr r2, _08097024 @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fbcc
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08096630
	ldr r1, _08097028 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _0809702C @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08096af0
	adds r0, r4, #0
	bl FUN_08096a34
	adds r0, r4, #0
	bl FUN_080967c0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08096d90
	ldr r1, _08097030 @ =FUN_08097034
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809701C: .4byte 0x000014AC
_08097020: .4byte 0x0000144C
_08097024: .4byte 0x00003AE8
_08097028: .4byte 0x00001464
_0809702C: .4byte 0x00003AEB
_08097030: .4byte FUN_08097034

	thumb_func_start FUN_08097034
FUN_08097034: @ 0x08097034
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0808c548
	ldr r5, _08097084 @ =0x030044E0
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08097090
	ldr r0, _08097088 @ =0x000009F8
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _0809708C @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a5b0
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a5e0
	b _080971B2
	.align 2, 0
_08097084: .4byte 0x030044E0
_08097088: .4byte 0x000009F8
_0809708C: .4byte 0x00001444
_08097090:
	ldr r2, _08097134 @ =0x000009F8
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08097138 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl FUN_082372cc
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08096d90
	ldrh r1, [r5, #2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0809718C
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _0809713C @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fbbc
	ldr r0, _08097140 @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08097144 @ =0x000014C4
	adds r0, r4, r1
	ldr r2, _08097148 @ =0x00003AEE
	adds r5, r4, r2
	ldrb r1, [r5]
	bl FUN_08096af0
	ldr r1, _0809714C @ =0x00003AEB
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _0809715C
	ldr r2, _08097150 @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, _08097154 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #4
	movs r2, #0
	bl FUN_0808c510
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808b6fc
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _08097158 @ =FUN_08097530
	b _0809717E
	.align 2, 0
_08097134: .4byte 0x000009F8
_08097138: .4byte 0x00001444
_0809713C: .4byte 0x00003AE8
_08097140: .4byte 0x000014AC
_08097144: .4byte 0x000014C4
_08097148: .4byte 0x00003AEE
_0809714C: .4byte 0x00003AEB
_08097150: .4byte 0x0000144C
_08097154: .4byte 0x0000204C
_08097158: .4byte FUN_08097530
_0809715C:
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_08096d40
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08096630
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08096bb8
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08096d90
	ldr r1, _08097188 @ =FUN_080971c4
_0809717E:
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _080971B2
	.align 2, 0
_08097188: .4byte FUN_080971c4
_0809718C:
	ldr r1, _080971B8 @ =0x00003AE8
	adds r0, r4, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _080971B2
	ldr r2, _080971BC @ =0x00001464
	adds r0, r4, r2
	ldr r2, _080971C0 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08096af0
	adds r0, r4, #0
	bl FUN_08096a34
	adds r0, r4, #0
	bl FUN_080967c0
_080971B2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080971B8: .4byte 0x00003AE8
_080971BC: .4byte 0x00001464
_080971C0: .4byte 0x00003AEB

	thumb_func_start FUN_080971c4
FUN_080971c4: @ 0x080971C4
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
	bl FUN_082372cc
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
	bl Sprite_SetSprite
	ldr r0, _08097274 @ =0x0000204C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, [r4, #0x58]
	movs r1, #2
	movs r2, #1
	bl FUN_0808c510
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
	bl FUN_0808c510
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
	bl FUN_08064a64
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
	bl FUN_0808a354
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

	thumb_func_start FUN_0809748c
FUN_0809748c: @ 0x0809748C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080974C4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080974D4
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _080974C8 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _080974CC @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08096af0
	adds r0, r4, #0
	bl FUN_08096a34
	ldr r1, _080974D0 @ =FUN_080971c4
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _0809750C
	.align 2, 0
_080974C4: .4byte 0x030044E0
_080974C8: .4byte 0x00001464
_080974CC: .4byte 0x00003AEB
_080974D0: .4byte FUN_080971c4
_080974D4:
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0809750C
	ldr r0, _08097520 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08097524 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #2
	bl FUN_0808c510
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _08097528 @ =FUN_08097584
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809750C:
	ldr r1, _0809752C @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl FUN_082372cc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097520: .4byte 0x0000144C
_08097524: .4byte 0x0000204C
_08097528: .4byte FUN_08097584
_0809752C: .4byte 0x00001444

	thumb_func_start FUN_08097530
FUN_08097530: @ 0x08097530
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0809754A
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08096fa8
	b _08097574
_0809754A:
	cmp r0, #1
	bne _08097574
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0
	bl SortArmors
	ldr r1, _0809757C @ =0x00003AEC
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08097580 @ =0x00003AED
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08096fa8
_08097574:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809757C: .4byte 0x00003AEC
_08097580: .4byte 0x00003AED

	thumb_func_start FUN_08097584
FUN_08097584: @ 0x08097584
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0808b760
	adds r2, r0, #0
	cmp r2, #0
	bne _080975A0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08096fa8
	b _080975EC
_080975A0:
	cmp r2, #1
	bne _080975EC
	ldr r0, _080975F4 @ =0x0000144C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080975F8 @ =0x00003AEE
	adds r4, r5, r1
	ldrb r2, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0x14
	bl FUN_08096cac
	ldrb r0, [r4]
	ldr r1, _080975FC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_0809673c
	adds r0, r5, #0
	bl FUN_08096b44
	ldr r1, _08097600 @ =FUN_08097604
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_080975EC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080975F4: .4byte 0x0000144C
_080975F8: .4byte 0x00003AEE
_080975FC: .4byte 0x030046A0
_08097600: .4byte FUN_08097604

	thumb_func_start FUN_08097604
FUN_08097604: @ 0x08097604
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809763C @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08097618
	ldr r0, _08097640 @ =0x0000038A
	bl PlaySound_082406e0
_08097618:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _0809764C
	ldr r1, _08097644 @ =0x000020C4
	adds r0, r5, r1
	ldr r2, _08097648 @ =0x00003B68
	adds r1, r5, r2
	ldrh r3, [r4]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _08097662
	.align 2, 0
_0809763C: .4byte 0x000009EE
_08097640: .4byte 0x0000038A
_08097644: .4byte 0x000020C4
_08097648: .4byte 0x00003B68
_0809764C:
	ldr r0, _08097668 @ =0x000020AC
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0809766C @ =FUN_08097670
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_08097662:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08097668: .4byte 0x000020AC
_0809766C: .4byte FUN_08097670

	thumb_func_start FUN_08097670
FUN_08097670: @ 0x08097670
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080976A8 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08097686
	movs r0, #0x87
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08097686:
	ldrh r0, [r4]
	adds r1, r0, #1
	strh r1, [r4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _080976C8
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080976B0
	ldr r2, _080976AC @ =0x00001BE6
	adds r1, r5, r2
	b _080976D4
	.align 2, 0
_080976A8: .4byte 0x000009EE
_080976AC: .4byte 0x00001BE6
_080976B0:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x46
	subs r1, r1, r0
	ldr r2, _080976C4 @ =0x00001BE6
	adds r0, r5, r2
	strh r1, [r0]
	b _080976E6
	.align 2, 0
_080976C4: .4byte 0x00001BE6
_080976C8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080976E0
	ldr r0, _080976DC @ =0x00001BE6
	adds r1, r5, r0
_080976D4:
	movs r0, #0x46
	strh r0, [r1]
	b _080976E6
	.align 2, 0
_080976DC: .4byte 0x00001BE6
_080976E0:
	adds r0, r5, #0
	bl FUN_08096fa8
_080976E6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080976ec
FUN_080976ec: @ 0x080976EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08097724 @ =0x000009EE
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _08097700
	ldr r0, _08097728 @ =0x0000038A
	bl PlaySound_082406e0
_08097700:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08097734
	ldr r1, _0809772C @ =0x000020C4
	adds r0, r4, r1
	ldr r2, _08097730 @ =0x00003B68
	adds r1, r4, r2
	ldrh r3, [r5]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _08097786
	.align 2, 0
_08097724: .4byte 0x000009EE
_08097728: .4byte 0x0000038A
_0809772C: .4byte 0x000020C4
_08097730: .4byte 0x00003B68
_08097734:
	ldr r3, _0809778C @ =0x000020AC
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _08097790 @ =0x00000111
	bl PlaySound_082406e0
	ldr r2, _08097794 @ =0x030046A0
	ldr r0, [r2]
	adds r0, #0x5c
	ldr r3, _08097798 @ =0x00003AEE
	adds r1, r4, r3
	ldrb r1, [r1]
	strh r1, [r0]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r1, [r2]
	adds r1, #0x5c
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldr r3, _0809779C @ =0x00003FE0
	adds r1, r4, r3
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #3
	ldr r2, _080977A0 @ =0x08DAA7B0
	adds r1, r1, r2
	bl FUN_08064a64
	adds r0, r4, #0
	bl FUN_0808bac4
	adds r0, r4, #0
	bl FUN_08096fa8
_08097786:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809778C: .4byte 0x000020AC
_08097790: .4byte 0x00000111
_08097794: .4byte 0x030046A0
_08097798: .4byte 0x00003AEE
_0809779C: .4byte 0x00003FE0
_080977A0: .4byte 0x08DAA7B0

	thumb_func_start FUN_080977a4
FUN_080977a4: @ 0x080977A4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _080977EC @ =0x000009EE
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080977B8
	ldr r0, _080977F0 @ =0x0000038A
	bl PlaySound_082406e0
_080977B8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08097804
	ldrh r0, [r4]
	movs r4, #0xc
	subs r4, r4, r0
	ldr r1, _080977F4 @ =0x000020C4
	adds r0, r7, r1
	ldr r2, _080977F8 @ =0x00003B68
	adds r1, r7, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	ldr r1, _080977FC @ =0x00002124
	adds r0, r7, r1
	ldr r2, _08097800 @ =0x00003B70
	adds r1, r7, r2
	adds r2, r4, #0
	bl FUN_0808ba20
	b _08097882
	.align 2, 0
_080977EC: .4byte 0x000009EE
_080977F0: .4byte 0x0000038A
_080977F4: .4byte 0x000020C4
_080977F8: .4byte 0x00003B68
_080977FC: .4byte 0x00002124
_08097800: .4byte 0x00003B70
_08097804:
	ldr r0, _08097860 @ =0x000020AC
	adds r1, r7, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08097864 @ =0x0000210C
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08097868 @ =0x00003AEE
	adds r5, r7, r1
	ldrb r1, [r5]
	ldr r0, _0809786C @ =0x030046A0
	ldr r3, [r0]
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r4, [r1, r0]
	ldr r0, _08097870 @ =0x00003AEB
	adds r6, r7, r0
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r3
	adds r0, r0, r2
	strh r4, [r0]
	adds r3, #0x5c
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldrb r1, [r5]
	cmp r0, r1
	bne _08097874
	ldrb r0, [r6]
	strh r0, [r3]
	b _0809787C
	.align 2, 0
_08097860: .4byte 0x000020AC
_08097864: .4byte 0x0000210C
_08097868: .4byte 0x00003AEE
_0809786C: .4byte 0x030046A0
_08097870: .4byte 0x00003AEB
_08097874:
	ldrb r6, [r6]
	cmp r0, r6
	bne _0809787C
	strh r1, [r3]
_0809787C:
	adds r0, r7, #0
	bl FUN_08096fa8
_08097882:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08097888
FUN_08097888: @ 0x08097888
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b8a4
	adds r0, r4, #0
	bl FUN_08096b44
	ldr r1, _080978D0 @ =0x00001D04
	adds r0, r4, r1
	movs r1, #0x10
	bl FUN_08096af0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08096bb8
	ldr r0, _080978D4 @ =0x00001BCC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080978D8 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080978E4
	ldr r1, _080978DC @ =0x00001BC4
	adds r0, r4, r1
	ldr r1, _080978E0 @ =0x000002DF
	bl FUN_0808ba0c
	b _080978F0
	.align 2, 0
_080978D0: .4byte 0x00001D04
_080978D4: .4byte 0x00001BCC
_080978D8: .4byte 0x00003AE8
_080978DC: .4byte 0x00001BC4
_080978E0: .4byte 0x000002DF
_080978E4:
	ldr r1, _08097918 @ =0x00001BC4
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_080978F0:
	ldr r0, _0809791C @ =0x00001C8C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08097920 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809792C
	ldr r1, _08097924 @ =0x00001C84
	adds r0, r4, r1
	ldr r1, _08097928 @ =0x000002DF
	bl FUN_0808ba0c
	b _08097938
	.align 2, 0
_08097918: .4byte 0x00001BC4
_0809791C: .4byte 0x00001C8C
_08097920: .4byte 0x00003AE8
_08097924: .4byte 0x00001C84
_08097928: .4byte 0x000002DF
_0809792C:
	ldr r1, _08097944 @ =0x00001C84
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_08097938:
	adds r0, r4, #0
	bl FUN_0808bac4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097944: .4byte 0x00001C84

	thumb_func_start FUN_08097948
FUN_08097948: @ 0x08097948
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x20
	bl FUN_08096630
	ldr r1, _080979A4 @ =0x00003AE8
	adds r0, r4, r1
	movs r1, #0
	movs r2, #0
	bl FUN_0808fbdc
	ldr r0, _080979A8 @ =0x00001464
	adds r6, r4, r0
	ldr r1, _080979AC @ =0x00003AEB
	adds r5, r4, r1
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_08096af0
	ldr r0, _080979B0 @ =0x0000144C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080979B4 @ =0x00001444
	adds r0, r4, r1
	adds r4, #0x60
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_08096af0
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080979A4: .4byte 0x00003AE8
_080979A8: .4byte 0x00001464
_080979AC: .4byte 0x00003AEB
_080979B0: .4byte 0x0000144C
_080979B4: .4byte 0x00001444

	thumb_func_start FUN_080979b8
FUN_080979b8: @ 0x080979B8
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08097A9C @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _08097AA0 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	adds r0, r4, #0
	bl FUN_0809673c
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #8
	bl FUN_0808a3c4
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08097A14
	movs r0, #0x12
	movs r1, #4
	movs r2, #0xb
	movs r3, #0xb
	bl FUN_0808b9c4
_08097A14:
	adds r0, r4, #0
	movs r1, #5
	movs r2, #3
	bl FUN_0808b604
	adds r0, r4, #0
	bl FUN_0808b38c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _08097AA4 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, _08097AA8 @ =0x0000156C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08097AAC @ =0x00001564
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0x9e
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08097948
	adds r0, r4, #0
	bl FUN_08097888
	adds r0, r4, #0
	bl FUN_080967c0
	bl FUN_08049f5c
	ldr r0, _08097AB0 @ =0x0000EFDA
	bl FUN_08047dc0
	adds r0, r4, #0
	bl FUN_08096a34
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808c61c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08096d90
	ldr r1, _08097AB4 @ =FUN_08097034
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097A9C: .4byte 0x00004014
_08097AA0: .4byte 0x00004018
_08097AA4: .4byte 0x00000F56
_08097AA8: .4byte 0x0000156C
_08097AAC: .4byte 0x00001564
_08097AB0: .4byte 0x0000EFDA
_08097AB4: .4byte FUN_08097034

	thumb_func_start FUN_08097ab8
FUN_08097ab8: @ 0x08097AB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r2, r0, #0
	ldr r0, _08097B04 @ =0x00003AE8
	adds r0, r0, r2
	mov sb, r0
	strb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08097B4A
	movs r4, #0
	ldr r1, _08097B08 @ =0x00003AF0
	adds r1, r1, r2
	mov sl, r1
	ldr r0, _08097B0C @ =0x00003FF0
	adds r0, r0, r2
	mov sb, r0
	mov r8, sl
	movs r7, #0xff
_08097AE8:
	movs r3, #0
	mov r0, r8
	adds r1, r4, r0
	lsls r6, r4, #2
	mov r0, sb
	adds r2, r6, r0
_08097AF4:
	adds r5, r6, r3
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08097B10
	strb r5, [r1]
	b _08097B16
	.align 2, 0
_08097B04: .4byte 0x00003AE8
_08097B08: .4byte 0x00003AF0
_08097B0C: .4byte 0x00003FF0
_08097B10:
	ldrb r0, [r1]
	orrs r0, r7
	strb r0, [r1]
_08097B16:
	adds r1, #4
	adds r2, #1
	adds r3, #1
	cmp r3, #3
	ble _08097AF4
	adds r4, #1
	cmp r4, #3
	ble _08097AE8
	movs r4, #0
	movs r2, #0xff
	mov r6, sl
	adds r6, #0x10
_08097B2E:
	adds r5, r4, #1
	adds r1, r4, r6
	movs r3, #4
_08097B34:
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _08097B34
	adds r4, r5, #0
	cmp r4, #3
	ble _08097B2E
	b _08097BF4
_08097B4A:
	movs r4, #0
	ldr r1, _08097BB4 @ =0x00003AF0
	adds r1, r1, r2
	mov sl, r1
	ldr r0, _08097BB8 @ =0x00003B10
	adds r0, r2, r0
	str r0, [sp]
	mov r6, sl
_08097B5A:
	adds r5, r4, #1
	adds r2, r4, r6
	movs r3, #3
_08097B60:
	mov r1, sb
	ldrb r0, [r1, #6]
	strb r0, [r2]
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _08097B60
	adds r4, r5, #0
	cmp r4, #3
	ble _08097B5A
	movs r5, #0
_08097B76:
	adds r6, r5, #0
	adds r6, #0x10
	movs r0, #1
	ands r0, r5
	lsls r1, r0, #1
	cmp r5, #1
	bgt _08097BBC
	movs r4, #0
	adds r5, #1
	mov r8, r5
	lsls r0, r0, #3
	mov ip, r0
	mov r7, sl
	adds r7, #0x10
_08097B92:
	adds r3, r1, #0
	adds r2, r3, #2
	adds r5, r4, #1
	cmp r3, r2
	bge _08097BAC
	adds r0, r4, r7
	add r0, ip
	subs r3, r2, r3
_08097BA2:
	strb r6, [r0]
	adds r0, #4
	subs r3, #1
	cmp r3, #0
	bne _08097BA2
_08097BAC:
	adds r4, r5, #0
	cmp r4, #2
	ble _08097B92
	b _08097BDA
	.align 2, 0
_08097BB4: .4byte 0x00003AF0
_08097BB8: .4byte 0x00003B10
_08097BBC:
	adds r3, r1, #0
	adds r2, r3, #2
	adds r5, #1
	mov r8, r5
	cmp r3, r2
	bge _08097BDA
	lsls r0, r0, #3
	adds r0, #0x1b
	add r0, sb
	subs r3, r2, r3
_08097BD0:
	strb r6, [r0]
	adds r0, #4
	subs r3, #1
	cmp r3, #0
	bne _08097BD0
_08097BDA:
	mov r5, r8
	cmp r5, #3
	ble _08097B76
	movs r4, #0
	ldr r2, [sp]
	movs r3, #0xff
_08097BE6:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _08097BE6
_08097BF4:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08097c04
FUN_08097c04: @ 0x08097C04
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08097C38 @ =0x00003AEB
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _08097C22
	ldr r2, _08097C3C @ =0x00003FF0
	adds r0, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	cmp r5, #0
	bge _08097C44
_08097C22:
	ldr r1, _08097C40 @ =0x0000204C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _08097C92
	.align 2, 0
_08097C38: .4byte 0x00003AEB
_08097C3C: .4byte 0x00003FF0
_08097C40: .4byte 0x0000204C
_08097C44:
	ldr r0, _08097C98 @ =0x0000204C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08097C9C @ =0x00002044
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xcf
	movs r3, #1
	bl Sprite_SetSprite
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r4, #0x4c]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	bl FUN_08047a28
	ldr r0, [r4, #0x4c]
	bl VM_ParseStringRef
	adds r0, #0x12
	adds r0, r0, r5
	bl Textbox_LookupString
	bl FUN_08049e30
_08097C92:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08097C98: .4byte 0x0000204C
_08097C9C: .4byte 0x00002044

	thumb_func_start FUN_08097ca0
FUN_08097ca0: @ 0x08097CA0
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _08097CE4
	movs r1, #3
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r3]
	cmp r2, #7
	bgt _08097CC8
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x10
	b _08097D1A
_08097CC8:
	cmp r2, #0xb
	bgt _08097CD8
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x18
	b _08097D1A
_08097CD8:
	asrs r1, r2, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	b _08097D1A
_08097CE4:
	cmp r2, #0x10
	bne _08097CF0
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x4c
	b _08097D1A
_08097CF0:
	cmp r2, #0x11
	bne _08097CFC
	movs r0, #0x58
	strh r0, [r3]
	movs r0, #0x4c
	b _08097D1A
_08097CFC:
	cmp r2, #0x12
	bne _08097D08
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x68
	b _08097D1A
_08097D08:
	cmp r2, #0x13
	bne _08097D14
	movs r0, #0x58
	strh r0, [r3]
	movs r0, #0x68
	b _08097D1A
_08097D14:
	movs r0, #0x90
	strh r0, [r3]
	movs r0, #0x20
_08097D1A:
	strh r0, [r3, #2]
	pop {r0}
	bx r0

	thumb_func_start FUN_08097d20
FUN_08097d20: @ 0x08097D20
	push {r4, lr}
	movs r2, #0
	ldr r4, _08097D38 @ =0x00003FF0
	adds r3, r0, r4
_08097D28:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _08097D3C
	adds r0, r2, #0
	b _08097D46
	.align 2, 0
_08097D38: .4byte 0x00003FF0
_08097D3C:
	adds r2, #1
	cmp r2, #0xf
	ble _08097D28
	movs r0, #1
	rsbs r0, r0, #0
_08097D46:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08097d4c
FUN_08097d4c: @ 0x08097D4C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	ldr r0, _08097D94 @ =0x000015C4
	adds r6, r5, r0
	ldr r1, _08097D98 @ =0x000015CC
	adds r4, r5, r1
_08097D5A:
	ldr r1, _08097D9C @ =0x00003FF0
	adds r0, r5, r1
	adds r2, r0, r7
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _08097DA0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	adds r1, r5, #0
	adds r1, #0xa0
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0808ba0c
	b _08097DA8
	.align 2, 0
_08097D94: .4byte 0x000015C4
_08097D98: .4byte 0x000015CC
_08097D9C: .4byte 0x00003FF0
_08097DA0:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_08097DA8:
	adds r4, #0x60
	adds r6, #0x60
	adds r7, #1
	cmp r7, #0xf
	ble _08097D5A
	movs r7, #0
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _08097E06
	ldr r0, _08097E2C @ =0x00001EE4
	adds r4, r5, r0
	movs r6, #0xf6
	lsls r6, r6, #4
_08097DC8:
	movs r0, #0x64
	muls r0, r7, r0
	adds r0, r5, r0
	ldr r1, _08097E30 @ =0x00000C09
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r0, r5, #0
	bl FUN_08097d20
	adds r1, r0, #0
	ldr r0, _08097E34 @ =0x00000F6C
	adds r3, r5, r0
	adds r3, r3, r6
	ldr r0, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r3]
	adds r0, r4, #0
	bl FUN_08097ca0
	adds r4, #0x60
	adds r6, #0x60
	adds r7, #1
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08097DC8
_08097E06:
	cmp r7, #3
	bgt _08097E26
	movs r2, #1
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08097E38 @ =0x00001ECC
	adds r0, r0, r1
	adds r1, r0, r5
_08097E18:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	adds r7, #1
	cmp r7, #3
	ble _08097E18
_08097E26:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097E2C: .4byte 0x00001EE4
_08097E30: .4byte 0x00000C09
_08097E34: .4byte 0x00000F6C
_08097E38: .4byte 0x00001ECC

	thumb_func_start FUN_08097e3c
FUN_08097e3c: @ 0x08097E3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r1, _08097F24 @ =0x00001E6C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	ldr r3, _08097F28 @ =0x00001CEC
	adds r1, r6, r3
	movs r7, #3
_08097E5A:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r7, #1
	cmp r7, #0
	bge _08097E5A
	movs r7, #0
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _08097F16
	movs r2, #2
	rsbs r2, r2, #0
	mov sb, r2
	ldr r3, _08097F2C @ =0x00001E84
	adds r3, r3, r6
	mov sl, r3
_08097E82:
	movs r0, #0x64
	adds r2, r7, #0
	muls r2, r0, r2
	adds r2, r6, r2
	ldr r1, _08097F30 @ =0x00000C08
	adds r0, r2, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r1, r5, #0
	adds r1, #0x24
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	mov r8, r0
	ldr r3, _08097F34 @ =0x00000F6C
	adds r1, r6, r3
	add r1, r8
	ldr r0, [r1]
	mov r3, sb
	ands r0, r3
	str r0, [r1]
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #5
	ldr r0, _08097F38 @ =0x00001CE4
	adds r4, r4, r0
	adds r4, r6, r4
	ldr r1, _08097F3C @ =0x00000C09
	adds r2, r2, r1
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0xa0
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808ba0c
	ldr r2, _08097F40 @ =0x00000C04
	adds r0, r6, r2
	ldr r0, [r0]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r5, r0
	bne _08097F08
	ldr r0, _08097F24 @ =0x00001E6C
	adds r1, r6, r0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	mov r3, r8
	adds r0, r6, r3
	ldr r1, _08097F44 @ =0x00000F84
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, sl
	str r0, [r2]
	str r1, [r2, #4]
_08097F08:
	adds r7, #1
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r7, r0
	blt _08097E82
_08097F16:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097F24: .4byte 0x00001E6C
_08097F28: .4byte 0x00001CEC
_08097F2C: .4byte 0x00001E84
_08097F30: .4byte 0x00000C08
_08097F34: .4byte 0x00000F6C
_08097F38: .4byte 0x00001CE4
_08097F3C: .4byte 0x00000C09
_08097F40: .4byte 0x00000C04
_08097F44: .4byte 0x00000F84

	thumb_func_start FUN_08097f48
FUN_08097f48: @ 0x08097F48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r1, #0
	mov r8, r3
	ldr r7, [sp, #0x18]
	lsls r4, r5, #1
	adds r4, r4, r5
	lsls r4, r4, #5
	ldr r0, _08097FAC @ =0x000020A4
	adds r4, r4, r0
	adds r4, r6, r4
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	adds r1, r6, #0
	adds r1, #0xa0
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	adds r0, #0x20
	mov r1, r8
	bl FUN_08097ca0
	lsls r5, r5, #3
	ldr r0, _08097FB0 @ =0x00003B68
	adds r5, r5, r0
	adds r6, r6, r5
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08097ca0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808ba0c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097FAC: .4byte 0x000020A4
_08097FB0: .4byte 0x00003B68

	thumb_func_start FUN_08097fb4
FUN_08097fb4: @ 0x08097FB4
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _08097FC4
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	b _0809809E
_08097FC4:
	movs r7, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r1, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _0809807A
	ldr r0, _08098034 @ =0x00003AEE
	adds r5, r3, r0
	ldr r2, _08098038 @ =0x00003AEB
	adds r4, r3, r2
	ldrb r0, [r5]
	ldrb r2, [r4]
	cmp r0, r2
	bne _08098048
	ldr r2, _0809803C @ =0x00000285
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809807A
	movs r6, #1
	rsbs r6, r6, #0
	adds r4, r6, #0
	movs r2, #0
	ldr r0, _08098040 @ =0x030046A0
	ldr r1, [r0]
	ldr r7, _08098044 @ =0x00003FF0
	adds r0, r3, r7
	ldrb r5, [r5]
	adds r0, r0, r5
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r1, #0x68
_0809800E:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	bne _08098018
	adds r6, r2, #0
_08098018:
	cmp r4, #0
	bge _08098022
	cmp r0, #0
	bge _08098022
	adds r4, r2, #0
_08098022:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _0809800E
	movs r7, #4
	cmp r6, #0
	bge _0809807A
	b _08098078
	.align 2, 0
_08098034: .4byte 0x00003AEE
_08098038: .4byte 0x00003AEB
_0809803C: .4byte 0x00000285
_08098040: .4byte 0x030046A0
_08098044: .4byte 0x00003FF0
_08098048:
	ldr r5, _0809806C @ =0x00000285
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08098074
	ldrb r1, [r4]
	ldr r0, _08098070 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x5a
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #0x10
	cmp r1, r0
	beq _0809807A
	cmp r1, #0xf
	bls _0809807A
	b _08098078
	.align 2, 0
_0809806C: .4byte 0x00000285
_08098070: .4byte 0x030046A0
_08098074:
	cmp r2, #0xf
	bls _0809807A
_08098078:
	movs r7, #1
_0809807A:
	cmp r7, #1
	beq _0809808C
	cmp r7, #4
	beq _08098096
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	adds r1, r2, #0
	b _0809809E
_0809808C:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #5
	b _0809809E
_08098096:
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r3, #0
	movs r1, #2
_0809809E:
	bl FUN_0808c658
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080980a8
FUN_080980a8: @ 0x080980A8
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r2, [r0]
	movs r6, #0xd6
	lsls r6, r6, #2
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, #5
	bne _080980C2
	b _080981FE
_080980C2:
	ldr r7, _08098138 @ =0x00003AEE
	adds r5, r3, r7
	ldr r0, _0809813C @ =0x00003AEB
	adds r4, r3, r0
	ldrb r0, [r5]
	ldrb r1, [r4]
	cmp r0, r1
	bne _080981A4
	movs r4, #1
	rsbs r4, r4, #0
	adds r6, r4, #0
	movs r2, #0
	ldr r1, _08098140 @ =0x030046A0
	mov ip, r1
	ldr r1, [r1]
	ldr r7, _08098144 @ =0x00003FF0
	adds r0, r3, r7
	ldrb r5, [r5]
	adds r0, r0, r5
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r1, #0x68
_080980EE:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	bne _080980F8
	adds r6, r2, #0
_080980F8:
	cmp r4, #0
	bge _08098102
	cmp r0, #0
	bge _08098102
	adds r4, r2, #0
_08098102:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _080980EE
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r0, [r0]
	ldr r2, _08098148 @ =0x00000285
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08098160
	mov r7, ip
	ldr r0, [r7]
	adds r0, #0x5a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	beq _080981FE
	cmp r6, #0
	blt _0809814C
	adds r1, r6, #0
	adds r1, #0x10
	ldr r2, _0809813C @ =0x00003AEB
	adds r0, r3, r2
	b _0809816C
	.align 2, 0
_08098138: .4byte 0x00003AEE
_0809813C: .4byte 0x00003AEB
_08098140: .4byte 0x030046A0
_08098144: .4byte 0x00003FF0
_08098148: .4byte 0x00000285
_0809814C:
	cmp r4, #0
	blt _080981FE
	adds r1, r4, #0
	adds r1, #0x10
	ldr r6, _0809815C @ =0x00003AEB
	adds r0, r3, r6
	strb r1, [r0]
	b _08098202
	.align 2, 0
_0809815C: .4byte 0x00003AEB
_08098160:
	cmp r6, #0
	blt _08098178
	adds r1, r6, #0
	adds r1, #0x10
	ldr r7, _08098174 @ =0x00003AEB
	adds r0, r3, r7
_0809816C:
	strb r1, [r0]
	movs r0, #4
	b _08098204
	.align 2, 0
_08098174: .4byte 0x00003AEB
_08098178:
	cmp r4, #0
	blt _0809818C
	adds r1, r4, #0
	adds r1, #0x10
	ldr r2, _08098188 @ =0x00003AEB
	adds r0, r3, r2
	strb r1, [r0]
	b _08098202
	.align 2, 0
_08098188: .4byte 0x00003AEB
_0809818C:
	mov r6, ip
	ldr r0, [r6]
	adds r0, #0x5a
	ldrb r0, [r0]
	adds r0, #0x10
	ldr r7, _080981A0 @ =0x00003AEB
	adds r1, r3, r7
	strb r0, [r1]
	b _08098202
	.align 2, 0
_080981A0: .4byte 0x00003AEB
_080981A4:
	ldr r6, _080981E4 @ =0x00000285
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080981FA
	ldr r0, _080981E8 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5a
	movs r7, #0
	ldrsh r2, [r1, r7]
	lsls r1, r2, #1
	adds r1, r1, r0
	adds r1, #0x68
	ldr r6, _080981EC @ =0x00003FF0
	adds r0, r3, r6
	ldrb r5, [r5]
	adds r0, r0, r5
	movs r7, #0
	ldrsh r1, [r1, r7]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _080981F0
	ldrb r1, [r4]
	adds r0, r2, #0
	adds r0, #0x10
	cmp r1, r0
	beq _08098202
	b _080981FE
	.align 2, 0
_080981E4: .4byte 0x00000285
_080981E8: .4byte 0x030046A0
_080981EC: .4byte 0x00003FF0
_080981F0:
	ldrb r1, [r4]
	adds r0, r2, #0
	adds r0, #0x10
	cmp r1, r0
	beq _080981FE
_080981FA:
	cmp r1, #0xf
	bhi _08098202
_080981FE:
	movs r0, #0
	b _08098204
_08098202:
	movs r0, #1
_08098204:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809820c
FUN_0809820c: @ 0x0809820C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08098278 @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0808de50
	adds r0, r4, #0
	bl FUN_08097d4c
	adds r0, r4, #0
	bl FUN_08097e3c
	ldr r1, _0809827C @ =0x0000144C
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r2, _08098280 @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fbcc
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08097ab8
	ldr r1, _08098284 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _08098288 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08097ca0
	adds r0, r4, #0
	bl FUN_08097c04
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08097fb4
	ldr r1, _0809828C @ =FUN_08098290
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08098278: .4byte 0x000014AC
_0809827C: .4byte 0x0000144C
_08098280: .4byte 0x00003AE8
_08098284: .4byte 0x00001464
_08098288: .4byte 0x00003AEB
_0809828C: .4byte FUN_08098290

	thumb_func_start FUN_08098290
FUN_08098290: @ 0x08098290
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	ldr r6, _080982CC @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080982D4
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #8
	bl FUN_0808c658
	ldr r1, _080982D0 @ =FUN_080983a4
	b _0809833C
	.align 2, 0
_080982CC: .4byte 0x030044E0
_080982D0: .4byte FUN_080983a4
_080982D4:
	ldr r2, _08098348 @ =0x000009F8
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _0809834C @ =0x00001444
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x60
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r2, _08098350 @ =0x00001E64
	adds r0, r5, r2
	adds r1, r4, #0
	movs r2, #0x40
	movs r3, #1
	bl Sprite_SetSprite
	ldrh r1, [r6, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08098368
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _08098354 @ =0x00003AE8
	adds r0, r5, r1
	bl FUN_0808fbbc
	ldr r0, _08098358 @ =0x000014AC
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0809835C @ =0x000014C4
	adds r0, r5, r1
	ldr r2, _08098360 @ =0x00003AEE
	adds r1, r5, r2
	ldrb r1, [r1]
	bl FUN_08097ca0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08097ab8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08097fb4
	ldr r1, _08098364 @ =FUN_080984a0
_0809833C:
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
	b _08098390
	.align 2, 0
_08098348: .4byte 0x000009F8
_0809834C: .4byte 0x00001444
_08098350: .4byte 0x00001E64
_08098354: .4byte 0x00003AE8
_08098358: .4byte 0x000014AC
_0809835C: .4byte 0x000014C4
_08098360: .4byte 0x00003AEE
_08098364: .4byte FUN_080984a0
_08098368:
	ldr r1, _08098398 @ =0x00003AE8
	adds r0, r5, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _08098390
	ldr r2, _0809839C @ =0x00001464
	adds r0, r5, r2
	ldr r2, _080983A0 @ =0x00003AEB
	adds r1, r5, r2
	ldrb r1, [r1]
	bl FUN_08097ca0
	adds r0, r5, #0
	bl FUN_08097c04
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08097fb4
_08098390:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098398: .4byte 0x00003AE8
_0809839C: .4byte 0x00001464
_080983A0: .4byte 0x00003AEB

	thumb_func_start FUN_080983a4
FUN_080983a4: @ 0x080983A4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a5b0
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a5e0
	ldr r6, _0809841C @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08098484
	ldr r1, _08098420 @ =0x00001444
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x60
	adds r1, r4, #0
	movs r2, #0x38
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _08098424 @ =0x00001E64
	adds r0, r5, r2
	adds r1, r4, #0
	bl FUN_082372cc
	ldrh r1, [r6, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08098496
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #1
	bls _08098496
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r2, _08098428 @ =0x00000285
	adds r0, r0, r2
	ldrb r4, [r0]
	cmp r4, #0
	beq _0809842C
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08098496
	.align 2, 0
_0809841C: .4byte 0x030044E0
_08098420: .4byte 0x00001444
_08098424: .4byte 0x00001E64
_08098428: .4byte 0x00000285
_0809842C:
	ldr r0, _08098474 @ =0x0000010B
	bl PlaySound_082406e0
	ldr r0, _08098478 @ =0x00000C02
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r6, [r6]
	cmp r0, r6
	blt _08098448
	strb r4, [r1]
_08098448:
	ldr r2, _0809847C @ =0x00000C04
	adds r0, r5, r2
	ldr r2, [r0]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r5, r0
	ldr r1, _08098480 @ =0x00000C08
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_08097e3c
	adds r0, r5, #0
	bl FUN_0808de50
	b _08098496
	.align 2, 0
_08098474: .4byte 0x0000010B
_08098478: .4byte 0x00000C02
_0809847C: .4byte 0x00000C04
_08098480: .4byte 0x00000C08
_08098484:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08097fb4
	ldr r1, _0809849C @ =FUN_08098290
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0808a354
_08098496:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809849C: .4byte FUN_08098290

	thumb_func_start FUN_080984a0
FUN_080984a0: @ 0x080984A0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _080984C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080984C4
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_0809820c
	b _080985C6
	.align 2, 0
_080984C0: .4byte 0x030044E0
_080984C4:
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0809859E
	adds r0, r5, #0
	bl FUN_0808c700
	adds r0, r5, #0
	bl FUN_080980a8
	cmp r0, #1
	beq _080984E8
	cmp r0, #1
	ble _08098594
	cmp r0, #4
	beq _08098528
	b _08098594
_080984E8:
	ldr r0, _08098518 @ =0x0000144C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r1, _0809851C @ =0x00003AEE
	adds r0, r5, r1
	ldrb r3, [r0]
	ldr r2, _08098520 @ =0x00003FF0
	adds r0, r5, r2
	adds r0, r0, r3
	movs r2, #0
	ldrsb r2, [r0, r2]
	subs r1, #3
	adds r0, r5, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08097f48
	ldr r1, _08098524 @ =FUN_080985ec
	b _08098570
	.align 2, 0
_08098518: .4byte 0x0000144C
_0809851C: .4byte 0x00003AEE
_08098520: .4byte 0x00003FF0
_08098524: .4byte FUN_080985ec
_08098528:
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r2, _0809857C @ =0x0000144C
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, _08098580 @ =0x00003AEE
	adds r1, r5, r0
	ldr r2, _08098584 @ =0x00003FF0
	adds r0, r5, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldr r0, _08098588 @ =0x00003AEB
	adds r4, r5, r0
	ldrb r3, [r4]
	str r3, [sp]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08097f48
	ldrb r0, [r4]
	adds r0, #0x14
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _0809858C @ =0x00000F6C
	adds r2, r5, r0
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r6
	str r0, [r2]
	ldr r1, _08098590 @ =FUN_08098684
_08098570:
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
	b _080985C6
	.align 2, 0
_0809857C: .4byte 0x0000144C
_08098580: .4byte 0x00003AEE
_08098584: .4byte 0x00003FF0
_08098588: .4byte 0x00003AEB
_0809858C: .4byte 0x00000F6C
_08098590: .4byte FUN_08098684
_08098594:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080985C6
_0809859E:
	ldr r1, _080985DC @ =0x00003AE8
	adds r0, r5, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _080985C6
	ldr r2, _080985E0 @ =0x00001464
	adds r0, r5, r2
	ldr r2, _080985E4 @ =0x00003AEB
	adds r1, r5, r2
	ldrb r1, [r1]
	bl FUN_08097ca0
	adds r0, r5, #0
	bl FUN_08097c04
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08097fb4
_080985C6:
	ldr r1, _080985E8 @ =0x00001444
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x60
	bl FUN_082372cc
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080985DC: .4byte 0x00003AE8
_080985E0: .4byte 0x00001464
_080985E4: .4byte 0x00003AEB
_080985E8: .4byte 0x00001444

	thumb_func_start FUN_080985ec
FUN_080985ec: @ 0x080985EC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08098624 @ =0x000009EE
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _08098600
	ldr r0, _08098628 @ =0x0000038A
	bl PlaySound_082406e0
_08098600:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08098634
	ldr r1, _0809862C @ =0x000020C4
	adds r0, r4, r1
	ldr r2, _08098630 @ =0x00003B68
	adds r1, r4, r2
	ldrh r3, [r5]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _0809866A
	.align 2, 0
_08098624: .4byte 0x000009EE
_08098628: .4byte 0x0000038A
_0809862C: .4byte 0x000020C4
_08098630: .4byte 0x00003B68
_08098634:
	ldr r0, _08098670 @ =0x00000111
	bl PlaySound_082406e0
	ldr r3, _08098674 @ =0x000020AC
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08098678 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #0x10
	ldr r3, _0809867C @ =0x00003AEE
	adds r2, r4, r3
	ldr r3, _08098680 @ =0x00003FF0
	adds r1, r4, r3
	ldrb r2, [r2]
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl RegisterMagic
	adds r0, r4, #0
	bl FUN_0809820c
_0809866A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098670: .4byte 0x00000111
_08098674: .4byte 0x000020AC
_08098678: .4byte 0x00003AEB
_0809867C: .4byte 0x00003AEE
_08098680: .4byte 0x00003FF0

	thumb_func_start FUN_08098684
FUN_08098684: @ 0x08098684
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080986D8 @ =0x000009EE
	adds r3, r4, r0
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080986EC
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _080986B6
	ldr r2, _080986DC @ =0x000020C4
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080986E0 @ =0x000020C6
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080986B6:
	ldr r1, _080986E4 @ =0x000020AC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldrb r1, [r3]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _080986E8 @ =0x000020D8
	adds r1, r4, r2
	strb r0, [r1]
	adds r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	b _0809871C
	.align 2, 0
_080986D8: .4byte 0x000009EE
_080986DC: .4byte 0x000020C4
_080986E0: .4byte 0x000020C6
_080986E4: .4byte 0x000020AC
_080986E8: .4byte 0x000020D8
_080986EC:
	ldr r1, _08098724 @ =0x000020D8
	adds r0, r4, r1
	movs r1, #0x40
	strb r1, [r0]
	ldr r2, _08098728 @ =0x000020D9
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0809872C @ =0x000020AC
	adds r2, r4, r0
	ldr r0, [r2]
	subs r1, #0x43
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08098730 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #0x10
	bl UnregisterMagic
	adds r0, r4, #0
	bl FUN_0809820c
_0809871C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08098724: .4byte 0x000020D8
_08098728: .4byte 0x000020D9
_0809872C: .4byte 0x000020AC
_08098730: .4byte 0x00003AEB

	thumb_func_start FUN_08098734
FUN_08098734: @ 0x08098734
	push {r4, r5, lr}
	movs r5, #0
	ldr r1, _08098754 @ =0x000015E4
	adds r4, r0, r1
_0809873C:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08097ca0
	adds r4, #0x60
	adds r5, #1
	cmp r5, #0xf
	ble _0809873C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098754: .4byte 0x000015E4

	thumb_func_start FUN_08098758
FUN_08098758: @ 0x08098758
	push {r4, r5, lr}
	movs r5, #0
	ldr r1, _08098778 @ =0x00001D04
	adds r4, r0, r1
_08098760:
	adds r1, r5, #0
	adds r1, #0x10
	adds r0, r4, #0
	bl FUN_08097ca0
	adds r4, #0x60
	adds r5, #1
	cmp r5, #3
	ble _08098760
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08098778: .4byte 0x00001D04

	thumb_func_start FUN_0809877c
FUN_0809877c: @ 0x0809877C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08098734
	adds r0, r4, #0
	bl FUN_08097d4c
	adds r0, r4, #0
	bl FUN_08098758
	adds r0, r4, #0
	bl FUN_08097e3c
	adds r0, r4, #0
	bl FUN_0808bac4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080987a4
FUN_080987a4: @ 0x080987A4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080987E8
	ldr r0, _080987E0 @ =0x00003FF0
	adds r2, r6, r0
	movs r0, #8
	strb r0, [r2]
	ldr r0, _080987E4 @ =0x00003FF1
	adds r1, r6, r0
	movs r0, #9
	strb r0, [r1]
	movs r4, #2
	movs r3, #0xff
_080987D0:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xf
	ble _080987D0
	b _08098892
	.align 2, 0
_080987E0: .4byte 0x00003FF0
_080987E4: .4byte 0x00003FF1
_080987E8:
	movs r5, #0
	movs r4, #0
_080987EC:
	adds r0, r4, #0
	subs r0, #8
	cmp r0, #1
	bls _08098808
	adds r0, r4, #0
	bl IsMagicUnlocked
	cmp r0, #0
	beq _08098808
	ldr r1, _08098898 @ =0x00003FF0
	adds r0, r6, r1
	adds r0, r0, r5
	strb r4, [r0]
	adds r5, #1
_08098808:
	adds r4, #1
	cmp r4, #9
	ble _080987EC
	cmp r5, #7
	bgt _08098826
	ldr r0, _08098898 @ =0x00003FF0
	adds r2, r6, r0
	movs r3, #0xff
_08098818:
	adds r1, r2, r5
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r5, #1
	cmp r5, #7
	ble _08098818
_08098826:
	movs r5, #8
	movs r4, #0xa
	ldr r1, _08098898 @ =0x00003FF0
	adds r7, r6, r1
_0809882E:
	adds r0, r4, #0
	bl IsMagicUnlocked
	cmp r0, #0
	beq _0809883E
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #1
_0809883E:
	adds r4, #1
	cmp r4, #0xd
	ble _0809882E
	cmp r5, #0xb
	bgt _0809885C
	ldr r0, _08098898 @ =0x00003FF0
	adds r2, r6, r0
	movs r3, #0xff
_0809884E:
	adds r1, r2, r5
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r5, #1
	cmp r5, #0xb
	ble _0809884E
_0809885C:
	movs r5, #0xc
	movs r4, #0xe
	ldr r1, _08098898 @ =0x00003FF0
	adds r7, r6, r1
_08098864:
	adds r0, r4, #0
	bl IsMagicUnlocked
	cmp r0, #0
	beq _08098874
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #1
_08098874:
	adds r4, #1
	cmp r4, #0x11
	ble _08098864
	cmp r5, #0xf
	bgt _08098892
	ldr r0, _08098898 @ =0x00003FF0
	adds r2, r6, r0
	movs r3, #0xff
_08098884:
	adds r1, r2, r5
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r5, #1
	cmp r5, #0xf
	ble _08098884
_08098892:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098898: .4byte 0x00003FF0

	thumb_func_start FUN_0809889c
FUN_0809889c: @ 0x0809889C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0
	bl FUN_08097ab8
	ldr r1, _080988F8 @ =0x00003AE8
	adds r0, r4, r1
	movs r1, #0
	movs r2, #0
	bl FUN_0808fbdc
	ldr r0, _080988FC @ =0x00001464
	adds r6, r4, r0
	ldr r1, _08098900 @ =0x00003AEB
	adds r5, r4, r1
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_08097ca0
	ldr r0, _08098904 @ =0x0000144C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08098908 @ =0x00001444
	adds r0, r4, r1
	adds r4, #0x60
	movs r1, #0
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldrb r1, [r5]
	adds r0, r6, #0
	bl FUN_08097ca0
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080988F8: .4byte 0x00003AE8
_080988FC: .4byte 0x00001464
_08098900: .4byte 0x00003AEB
_08098904: .4byte 0x0000144C
_08098908: .4byte 0x00001444

	thumb_func_start FUN_0809890c
FUN_0809890c: @ 0x0809890C
	push {lr}
	movs r1, #8
	ldr r3, _08098924 @ =0x00003FF0
	adds r2, r0, r3
_08098914:
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08098928
	movs r0, #1
	b _08098930
	.align 2, 0
_08098924: .4byte 0x00003FF0
_08098928:
	adds r1, #1
	cmp r1, #0xb
	ble _08098914
	movs r0, #0
_08098930:
	pop {r1}
	bx r1

	thumb_func_start FUN_08098934
FUN_08098934: @ 0x08098934
	push {lr}
	movs r1, #0xc
	ldr r3, _0809894C @ =0x00003FF0
	adds r2, r0, r3
_0809893C:
	adds r0, r2, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08098950
	movs r0, #1
	b _08098958
	.align 2, 0
_0809894C: .4byte 0x00003FF0
_08098950:
	adds r1, #1
	cmp r1, #0xf
	ble _0809893C
	movs r0, #0
_08098958:
	pop {r1}
	bx r1

	thumb_func_start FUN_0809895c
FUN_0809895c: @ 0x0809895C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_0809890c
	cmp r0, #0
	bne _0809898C
	movs r4, #7
	ldr r0, _080989C0 @ =0x0000F002
	adds r5, r0, #0
_0809896E:
	movs r0, #0
	movs r1, #0x12
	adds r2, r4, #0
	bl FUN_0808a420
	adds r2, r4, #1
	movs r1, #0xa
_0809897C:
	strh r5, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0809897C
	adds r4, r2, #0
	cmp r4, #0xa
	ble _0809896E
_0809898C:
	adds r0, r6, #0
	bl FUN_08098934
	cmp r0, #0
	bne _080989BA
	movs r4, #0xb
	ldr r0, _080989C0 @ =0x0000F002
	adds r5, r0, #0
_0809899C:
	movs r0, #0
	movs r1, #0x12
	adds r2, r4, #0
	bl FUN_0808a420
	adds r2, r4, #1
	movs r1, #0xa
_080989AA:
	strh r5, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _080989AA
	adds r4, r2, #0
	cmp r4, #0xe
	ble _0809899C
_080989BA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080989C0: .4byte 0x0000F002

	thumb_func_start FUN_080989c4
FUN_080989c4: @ 0x080989C4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _08098A84 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _08098A88 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	adds r0, r4, #0
	bl FUN_080987a4
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #9
	bl FUN_0808a3c4
	adds r0, r4, #0
	movs r1, #5
	movs r2, #3
	bl FUN_0808b604
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08098A2A
	movs r0, #8
	movs r1, #9
	movs r2, #5
	movs r3, #6
	bl FUN_0808b9c4
_08098A2A:
	adds r0, r4, #0
	bl FUN_0809895c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _08098A8C @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0809889c
	adds r0, r4, #0
	bl FUN_0809877c
	bl FUN_08049f5c
	ldr r0, _08098A90 @ =0x0000EFDA
	bl FUN_08047dc0
	adds r0, r4, #0
	bl FUN_08097c04
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808c61c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08097fb4
	ldr r1, _08098A94 @ =FUN_08098290
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08098A84: .4byte 0x00004014
_08098A88: .4byte 0x00004018
_08098A8C: .4byte 0x00000F56
_08098A90: .4byte 0x0000EFDA
_08098A94: .4byte FUN_08098290

	thumb_func_start FUN_08098a98
FUN_08098a98: @ 0x08098A98
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	mov r8, r3
	adds r4, r4, r5
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	subs r6, r4, r0
	movs r4, #0xa
	cmp r5, #0
	bgt _08098AC8
	movs r4, #0
	cmp r5, #0
	bge _08098AC8
	movs r4, #0x14
_08098AC8:
	adds r2, r4, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, r8
	adds r1, r7, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r2, r4, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x18]
	adds r1, r7, #0
	movs r3, #1
	bl Sprite_SetSprite
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08098af4
FUN_08098af4: @ 0x08098AF4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	movs r2, #0xe
	movs r3, #0xc
	bl FUN_0808b30c
	movs r2, #0
	mov sb, r2
	ldr r0, _08098B64 @ =0x000021C4
	adds r0, r0, r6
	mov r8, r0
	ldr r1, _08098B68 @ =0x00002164
	adds r7, r6, r1
	movs r5, #0
	ldr r2, _08098B6C @ =0x00004004
	adds r4, r6, r2
_08098B2A:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r3, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08098B70
	movs r0, #0xd7
	lsls r0, r0, #2
	adds r1, r3, r0
	adds r1, r1, r5
	subs r2, #0xec
	adds r0, r3, r2
	adds r0, r0, r5
	ldrb r2, [r0]
	ldrb r1, [r1]
	adds r2, r2, r1
	movs r1, #0x9d
	lsls r1, r1, #2
	adds r0, r3, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, r0, r2
	strb r0, [r4]
	b _08098B94
	.align 2, 0
_08098B64: .4byte 0x000021C4
_08098B68: .4byte 0x00002164
_08098B6C: .4byte 0x00004004
_08098B70:
	movs r0, #0xd7
	lsls r0, r0, #2
	adds r2, r3, r0
	adds r2, r2, r5
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r3, r1
	adds r0, r0, r5
	ldrb r1, [r0]
	ldrb r2, [r2]
	adds r1, r1, r2
	movs r2, #0x9d
	lsls r2, r2, #2
	adds r0, r3, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r4]
_08098B94:
	ldrb r0, [r4]
	cmp r0, #0x63
	bls _08098B9E
	movs r0, #0x63
	strb r0, [r4]
_08098B9E:
	ldrb r0, [r4]
	ldr r2, _08098BD8 @ =0x00004008
	adds r1, r6, r2
	add r1, sb
	ldrb r1, [r1]
	mov r2, r8
	str r2, [sp]
	adds r2, r6, #0
	adds r2, #0x60
	adds r3, r7, #0
	bl FUN_08098a98
	movs r0, #0xc0
	add r8, r0
	adds r7, #0xc0
	adds r5, #2
	adds r4, #1
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #3
	ble _08098B2A
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098BD8: .4byte 0x00004008

	thumb_func_start FUN_08098bdc
FUN_08098bdc: @ 0x08098BDC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #2
	rsbs r6, r6, #0
	ldr r0, _08098C20 @ =0x000021CC
	adds r2, r5, r0
	movs r3, #0x68
	subs r0, #0x60
	adds r1, r5, r0
	movs r4, #3
_08098BF0:
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	movs r0, #0x28
	strh r0, [r1, #0x18]
	strh r3, [r1, #0x1a]
	ldr r0, [r1, #0x60]
	ands r0, r6
	str r0, [r1, #0x60]
	movs r0, #0x30
	strh r0, [r2, #0x18]
	strh r3, [r2, #0x1a]
	adds r2, #0xc0
	adds r3, #8
	adds r1, #0xc0
	subs r4, #1
	cmp r4, #0
	bge _08098BF0
	adds r0, r5, #0
	bl FUN_08098af4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098C20: .4byte 0x000021CC

	thumb_func_start FUN_08098c24
FUN_08098c24: @ 0x08098C24
	push {r4, r5, r6, lr}
	sub sp, #0x2c
	adds r5, r0, #0
	ldr r1, _08098CC8 @ =0x00004004
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _08098CCC @ =0x00004008
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	cmp r1, #0x63
	ble _08098C3E
	movs r1, #0x63
_08098C3E:
	lsls r3, r1, #2
	adds r3, r3, r1
	lsls r3, r3, #1
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r6, #5
	str r6, [sp]
	movs r0, #7
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0808a4ac
	ldr r2, _08098CD0 @ =0x00004005
	adds r0, r5, r2
	ldrb r1, [r0]
	ldr r3, _08098CD4 @ =0x00004009
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r1, r1, r0
	cmp r1, #0x63
	ble _08098C78
	movs r1, #0x63
_08098C78:
	lsls r3, r1, #2
	adds r3, r3, r1
	adds r3, #0x64
	ldr r0, [r4]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r2, [r0]
	str r6, [sp]
	movs r0, #8
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0808a4ac
	ldr r6, _08098CD8 @ =0x030046A0
	ldr r0, [r6]
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	add r1, sp, #8
	bl FUN_08242b28
	add r0, sp, #8
	ldrb r0, [r0, #1]
	adds r2, r0, #0
	cmp r2, #4
	bne _08098CDC
	add r0, sp, #8
	bl FUN_0807a6cc
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	movs r2, #6
	movs r3, #9
	bl FUN_0808b30c
	b _08098D40
	.align 2, 0
_08098CC8: .4byte 0x00004004
_08098CCC: .4byte 0x00004008
_08098CD0: .4byte 0x00004005
_08098CD4: .4byte 0x00004009
_08098CD8: .4byte 0x030046A0
_08098CDC:
	ldr r3, _08098D18 @ =0x00004006
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, #4
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r1, r1, r0
	cmp r1, #0x63
	ble _08098CF0
	movs r1, #0x63
_08098CF0:
	ldr r0, [r6]
	adds r0, #0x40
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r1, r0
	asrs r4, r0, #1
	cmp r2, #3
	bne _08098D1C
	movs r0, #3
	bl GetWeaponSkillLevel
	ldr r1, [r6]
	adds r1, #0x40
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	asrs r0, r0, #2
	adds r4, r4, r0
	b _08098D30
	.align 2, 0
_08098D18: .4byte 0x00004006
_08098D1C:
	add r0, sp, #8
	adds r1, r0, #0
	movs r3, #8
	ldrsh r1, [r1, r3]
	ldrb r0, [r0, #4]
	adds r1, r1, r0
	cmp r1, #0
	bge _08098D2E
	movs r1, #0
_08098D2E:
	adds r4, r4, r1
_08098D30:
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0x64
	movs r2, #6
	movs r3, #9
	bl FUN_0808b30c
_08098D40:
	ldr r1, _08098D88 @ =0x00004007
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _08098D8C @ =0x0000400B
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	cmp r1, #0x63
	ble _08098D54
	movs r1, #0x63
_08098D54:
	ldr r0, _08098D90 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, r1, r0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r1, r5, r2
	ldr r1, [r1]
	ldr r3, _08098D94 @ =0x00000266
	adds r1, r1, r3
	asrs r0, r0, #1
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	movs r2, #6
	movs r3, #0xa
	bl FUN_0808b30c
	add sp, #0x2c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08098D88: .4byte 0x00004007
_08098D8C: .4byte 0x0000400B
_08098D90: .4byte 0x030046A0
_08098D94: .4byte 0x00000266

	thumb_func_start FUN_08098d98
FUN_08098d98: @ 0x08098D98
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r4, #0
	ldr r0, _08098E2C @ =0x00004004
	adds r6, r5, r0
	movs r1, #0xcc
	lsls r1, r1, #5
	adds r3, r5, r1
	ldr r7, _08098E30 @ =0x000028EC
	adds r2, r5, r7
	movs r0, #2
	rsbs r0, r0, #0
	mov ip, r0
	ldr r1, _08098E34 @ =0x00000F84
	mov r8, r1
_08098DBA:
	ldr r0, [r2]
	mov r7, ip
	ands r0, r7
	str r0, [r2]
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r0, #0x68
	mov r7, r8
	adds r1, r3, r7
	strh r0, [r1]
	lsls r1, r4, #3
	ldr r7, _08098E38 @ =0x00000F86
	adds r0, r3, r7
	strh r1, [r0]
	adds r3, #0x60
	adds r2, #0x60
	adds r4, #1
	cmp r4, #3
	ble _08098DBA
	movs r4, #0
	ldr r0, _08098E3C @ =0x00004008
	adds r0, r0, r5
	mov r8, r0
	ldr r1, _08098E40 @ =0x00002904
	adds r6, r5, r1
	movs r7, #0xd8
	lsls r7, r7, #5
	adds r3, r5, r7
	ldr r0, _08098E44 @ =0x00002A6C
	adds r2, r5, r0
	movs r5, #2
	rsbs r5, r5, #0
_08098DFA:
	ldr r0, [r2]
	ands r0, r5
	str r0, [r2]
	mov r7, r8
	adds r1, r7, r4
	ldrh r0, [r6]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	lsls r1, r4, #3
	ldr r7, _08098E38 @ =0x00000F86
	adds r0, r3, r7
	strh r1, [r0]
	adds r6, #0x60
	adds r3, #0x60
	adds r2, #0x60
	adds r4, #1
	cmp r4, #3
	ble _08098DFA
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098E2C: .4byte 0x00004004
_08098E30: .4byte 0x000028EC
_08098E34: .4byte 0x00000F84
_08098E38: .4byte 0x00000F86
_08098E3C: .4byte 0x00004008
_08098E40: .4byte 0x00002904
_08098E44: .4byte 0x00002A6C

	thumb_func_start FUN_08098e48
FUN_08098e48: @ 0x08098E48
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _08098E78 @ =0x00001464
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	ldr r2, _08098E7C @ =0x00004002
	adds r3, r1, r2
	ldrb r0, [r3]
	lsls r0, r0, #3
	ldr r4, _08098E80 @ =0x00001466
	adds r2, r1, r4
	strh r0, [r2]
	ldr r2, _08098E84 @ =0x000020A4
	adds r0, r1, r2
	adds r1, #0x60
	ldrb r2, [r3]
	adds r2, #0x42
	movs r3, #1
	bl Sprite_SetSprite
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08098E78: .4byte 0x00001464
_08098E7C: .4byte 0x00004002
_08098E80: .4byte 0x00001466
_08098E84: .4byte 0x000020A4

	thumb_func_start FUN_08098e88
FUN_08098e88: @ 0x08098E88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r3, #0
	ldr r0, _08098ED4 @ =0x030046A0
	mov ip, r0
	mov r8, ip
	ldr r1, _08098ED8 @ =0x00004008
	adds r4, r5, r1
	movs r6, #0
_08098E9E:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r3, #1
	adds r1, r1, r0
	adds r2, r4, r3
	ldrh r0, [r1, #0x18]
	ldrb r7, [r2]
	adds r0, r0, r7
	strh r0, [r1, #0x18]
	strb r6, [r2]
	adds r3, #1
	cmp r3, #3
	ble _08098E9E
	mov r1, ip
	ldr r0, [r1]
	adds r0, #0x42
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r5, r2
	ldrh r1, [r1]
	strh r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098ED4: .4byte 0x030046A0
_08098ED8: .4byte 0x00004008

	thumb_func_start FUN_08098edc
FUN_08098edc: @ 0x08098EDC
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _08098F20
	ldr r4, _08098F1C @ =0x030046A0
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0x42
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x93
	lsls r0, r0, #1
	cmp r1, r0
	ble _08098F0C
	movs r0, #0
	strh r0, [r2]
_08098F0C:
	ldr r0, [r4]
	adds r0, #0x42
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r3, r2
	strh r1, [r0]
	b _08098F2A
	.align 2, 0
_08098F1C: .4byte 0x030046A0
_08098F20:
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r3, r4
	movs r0, #0
	strh r0, [r1]
_08098F2A:
	movs r2, #0
	movs r1, #3
	ldr r4, _08098F44 @ =0x0000400B
	adds r0, r3, r4
_08098F32:
	strb r2, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _08098F32
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08098F44: .4byte 0x0000400B

	thumb_func_start FUN_08098f48
FUN_08098f48: @ 0x08098F48
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r5, #0
	bge _08098F58
	bl FUN_08047864
	b _08098F76
_08098F58:
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r4, #0x58]
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x12
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	bl FUN_08047a28
_08098F76:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08098f7c
FUN_08098f7c: @ 0x08098F7C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08098FB8 @ =0x000009F8
	adds r2, r4, r0
	movs r0, #0
	strb r0, [r2]
	ldr r0, _08098FBC @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08098FC0
	movs r0, #1
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #7
	bl FUN_0808a5b0
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #8
	bl FUN_0808a5e0
	adds r0, r4, #0
	bl FUN_0808c700
	b _08098FE4
	.align 2, 0
_08098FB8: .4byte 0x000009F8
_08098FBC: .4byte 0x030044E0
_08098FC0:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #7
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #8
	bl FUN_0808a768
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
_08098FE4:
	ldr r0, _08099000 @ =0x0000282C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08099004 @ =0x0000288C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099000: .4byte 0x0000282C
_08099004: .4byte 0x0000288C

	thumb_func_start FUN_08099008
FUN_08099008: @ 0x08099008
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08099074 @ =0x000009F8
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	movs r1, #0
	ldr r0, _08099078 @ =0x00004008
	adds r2, r5, r0
_0809901C:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08099026
	movs r3, #1
_08099026:
	adds r1, #1
	cmp r1, #3
	ble _0809901C
	cmp r3, #0
	bne _08099090
	ldr r0, _0809907C @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08099090
	ldr r1, _08099074 @ =0x000009F8
	adds r0, r5, r1
	movs r2, #1
	strb r2, [r0]
	ldr r3, _08099080 @ =0x0000282C
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08099084 @ =0x0000288C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _08099088 @ =0x0000144C
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809908C @ =0x000020AC
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_0808c700
	b _08099288
	.align 2, 0
_08099074: .4byte 0x000009F8
_08099078: .4byte 0x00004008
_0809907C: .4byte 0x030044E0
_08099080: .4byte 0x0000282C
_08099084: .4byte 0x0000288C
_08099088: .4byte 0x0000144C
_0809908C: .4byte 0x000020AC
_08099090:
	ldr r1, _080990CC @ =0x000009F8
	adds r4, r5, r1
	strb r3, [r4]
	adds r0, r5, #0
	bl FUN_0808b6a4
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080990D8
	ldr r2, _080990D0 @ =0x00004002
	adds r4, r5, r2
	ldrb r0, [r4]
	adds r0, #3
	movs r1, #3
	ands r0, r1
	strb r0, [r4]
	adds r0, r5, #0
	bl FUN_08098e48
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldrb r0, [r4]
	adds r0, #0x14
	ldr r3, _080990D4 @ =0x00004003
	adds r1, r5, r3
	strb r0, [r1]
	b _0809921A
	.align 2, 0
_080990CC: .4byte 0x000009F8
_080990D0: .4byte 0x00004002
_080990D4: .4byte 0x00004003
_080990D8:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08099110
	ldr r0, _08099108 @ =0x00004002
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r4]
	adds r0, r5, #0
	bl FUN_08098e48
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldrb r0, [r4]
	adds r0, #0x14
	ldr r2, _0809910C @ =0x00004003
	adds r1, r5, r2
	strb r0, [r1]
	b _0809921A
	.align 2, 0
_08099108: .4byte 0x00004002
_0809910C: .4byte 0x00004003
_08099110:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08099144
	ldr r3, _0809913C @ =0x00004002
	adds r1, r5, r3
	ldr r2, _08099140 @ =0x00004008
	adds r0, r5, r2
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809921A
	subs r0, #1
	strb r0, [r1]
	subs r3, #2
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08099196
	.align 2, 0
_0809913C: .4byte 0x00004002
_08099140: .4byte 0x00004008
_08099144:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080991B8
	movs r0, #0x80
	lsls r0, r0, #7
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _0809921A
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r2, _080991AC @ =0x00004002
	adds r1, r5, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	movs r3, #0xd7
	lsls r3, r3, #2
	adds r0, r0, r3
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r3, _080991B0 @ =0x00004008
	adds r0, r5, r3
	adds r6, r0, r2
	ldrb r3, [r6]
	adds r1, r1, r3
	cmp r1, #0x62
	bgt _0809921A
	ldr r1, _080991B4 @ =0x00004004
	adds r0, r5, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x62
	bhi _0809921A
	adds r0, r3, #1
	strb r0, [r6]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
_08099196:
	adds r0, r5, #0
	bl FUN_08098af4
	adds r0, r5, #0
	bl FUN_08098d98
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0809921A
	.align 2, 0
_080991AC: .4byte 0x00004002
_080991B0: .4byte 0x00004008
_080991B4: .4byte 0x00004004
_080991B8:
	ldr r2, _080991EC @ =0x030044E0
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080991F8
	ldrb r0, [r4]
	cmp r0, #0
	beq _080991F8
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080991F0 @ =0x00004003
	adds r0, r5, r2
	movs r1, #0x18
	strb r1, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _080991F4 @ =FUN_080992c0
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
	b _0809921A
	.align 2, 0
_080991EC: .4byte 0x030044E0
_080991F0: .4byte 0x00004003
_080991F4: .4byte FUN_080992c0
_080991F8:
	ldrh r1, [r2, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809921A
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08098edc
	adds r0, r5, #0
	bl FUN_08098af4
	adds r0, r5, #0
	bl FUN_08098d98
_0809921A:
	ldr r3, _08099244 @ =0x0000282C
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r1, _08099248 @ =0x000009F8
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809924C
	adds r3, #0x60
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_0808c700
	b _08099264
	.align 2, 0
_08099244: .4byte 0x0000282C
_08099248: .4byte 0x000009F8
_0809924C:
	ldr r0, _080992AC @ =0x0000288C
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808c658
_08099264:
	ldr r2, _080992B0 @ =0x000020AC
	adds r1, r5, r2
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r3, _080992B4 @ =0x0000144C
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r1, _080992B8 @ =0x00001444
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x60
	bl FUN_082372cc
_08099288:
	adds r0, r5, #0
	bl FUN_08098c24
	ldr r2, _080992BC @ =0x00004003
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _080992A6
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_08098f48
	movs r0, #0xff
	strb r0, [r4]
_080992A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080992AC: .4byte 0x0000288C
_080992B0: .4byte 0x000020AC
_080992B4: .4byte 0x0000144C
_080992B8: .4byte 0x00001444
_080992BC: .4byte 0x00004003

	thumb_func_start FUN_080992c0
FUN_080992c0: @ 0x080992C0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	adds r5, r0, #0
	cmp r5, #0
	bne _08099304
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _080992FC @ =0x00004002
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #0x14
	adds r0, r4, #0
	bl FUN_08098f48
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _08099300 @ =FUN_08099008
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _080993B4
	.align 2, 0
_080992FC: .4byte 0x00004002
_08099300: .4byte FUN_08099008
_08099304:
	cmp r5, #1
	bne _080993B4
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08098e88
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080612bc
	adds r0, r4, #0
	bl FUN_08098af4
	adds r0, r4, #0
	bl FUN_08098d98
	adds r0, r4, #0
	movs r1, #5
	movs r2, #7
	bl FUN_0808b604
	movs r6, #1
	rsbs r6, r6, #0
	adds r0, r4, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0808c658
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08099384
	ldr r0, _08099378 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	ldr r0, _0809937C @ =0x000020AC
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08098f48
	ldr r1, _08099380 @ =FUN_08098f7c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	b _080993B4
	.align 2, 0
_08099378: .4byte 0x0000144C
_0809937C: .4byte 0x000020AC
_08099380: .4byte FUN_08098f7c
_08099384:
	ldr r1, _080993BC @ =0x00004002
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r1, #0x14
	adds r0, r4, #0
	bl FUN_08098f48
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #7
	bl FUN_0808a5b0
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #8
	bl FUN_0808a5e0
	ldr r1, _080993C0 @ =FUN_08099008
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
_080993B4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080993BC: .4byte 0x00004002
_080993C0: .4byte FUN_08099008

	thumb_func_start weapon_080993c4
weapon_080993c4: @ 0x080993C4
	ldr r1, [r0, #0x5c]
	ldr r0, _080993E0 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r1, [r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	bx lr
	.align 2, 0
_080993E0: .4byte 0x030046A0

	thumb_func_start weapon_080993e4
weapon_080993e4: @ 0x080993E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _08099404
	b _08099534
_08099404:
	ldr r4, _08099464 @ =0x030046A0
	ldr r0, [r4]
	adds r0, #0x40
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0x63
	bl min
	movs r5, #0
	str r5, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #3
	bl FUN_0808b30c
	ldr r0, [r4]
	ldr r0, [r0, #0x50]
	ldr r7, _08099468 @ =0x000F423F
	adds r1, r7, #0
	bl min
	ldr r1, _0809946C @ =0x000186A0
	mov r8, r1
	str r5, [sp]
	movs r2, #0x17
	movs r3, #4
	bl FUN_0808b30c
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0x62
	ble _08099474
	movs r0, #0
	movs r1, #0x17
	movs r2, #5
	bl FUN_0808a420
	ldr r3, _08099470 @ =0x0000F0BC
	adds r1, r3, #0
	movs r4, #5
_08099458:
	strh r1, [r0]
	adds r0, #2
	subs r4, #1
	cmp r4, #0
	bge _08099458
	b _0809948C
	.align 2, 0
_08099464: .4byte 0x030046A0
_08099468: .4byte 0x000F423F
_0809946C: .4byte 0x000186A0
_08099470: .4byte 0x0000F0BC
_08099474:
	adds r0, r6, #0
	bl weapon_080993c4
	adds r1, r7, #0
	bl min
	str r5, [sp]
	mov r1, r8
	movs r2, #0x17
	movs r3, #5
	bl FUN_0808b30c
_0809948C:
	movs r4, #0
_0809948E:
	movs r5, #0
	cmp r4, #0
	bne _080994B4
	ldr r0, _080994B0 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x60
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _080994D6
	bl GetWeaponKind
	cmp r0, #0
	bne _080994D6
	b _080994DA
	.align 2, 0
_080994B0: .4byte 0x030046A0
_080994B4:
	subs r0, r4, #1
	cmp r0, #1
	bhi _080994D4
	ldr r0, _080994D0 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r1
	adds r0, #0x60
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080994D6
	b _080994DA
	.align 2, 0
_080994D0: .4byte 0x030046A0
_080994D4:
	movs r5, #1
_080994D6:
	cmp r5, #0
	beq _08099502
_080994DA:
	adds r0, r4, #0
	bl GetWeaponSkillLevel
	movs r1, #0x63
	bl min
	movs r1, #1
	ands r1, r4
	lsls r2, r1, #2
	adds r2, r2, r1
	adds r2, #0x14
	asrs r3, r4, #1
	adds r3, #8
	movs r1, #0
	str r1, [sp]
	movs r1, #0xa
	bl FUN_0808b30c
	adds r1, r4, #1
	b _08099528
_08099502:
	movs r0, #1
	ands r0, r4
	lsls r1, r0, #2
	adds r1, r1, r0
	adds r1, #0x12
	asrs r2, r4, #1
	adds r2, #8
	movs r0, #0
	bl FUN_0808a420
	adds r1, r4, #1
	ldr r3, _08099530 @ =0x0000F001
	adds r2, r3, #0
	movs r4, #1
_0809951E:
	strh r2, [r0]
	adds r0, #2
	subs r4, #1
	cmp r4, #0
	bge _0809951E
_08099528:
	adds r4, r1, #0
	cmp r4, #4
	ble _0809948E
	b _0809959E
	.align 2, 0
_08099530: .4byte 0x0000F001
_08099534:
	ldr r0, _080995AC @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0xa
	movs r1, #0x63
	bl min
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x15
	movs r3, #3
	bl FUN_0808b30c
	movs r0, #6
	movs r1, #0x17
	movs r2, #4
	bl FUN_0808b360
	movs r0, #6
	movs r1, #0x17
	movs r2, #5
	bl FUN_0808b360
	movs r0, #2
	movs r1, #0x14
	movs r2, #8
	bl FUN_0808b360
	movs r0, #2
	movs r1, #0x19
	movs r2, #8
	bl FUN_0808b360
	movs r0, #2
	movs r1, #0x14
	movs r2, #9
	bl FUN_0808b360
	movs r0, #2
	movs r1, #0x19
	movs r2, #9
	bl FUN_0808b360
	str r4, [sp]
	movs r0, #0x63
	movs r1, #0xa
	movs r2, #0x14
	movs r3, #0xa
	bl FUN_0808b30c
_0809959E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080995AC: .4byte 0x030046A0

	thumb_func_start FUN_080995b0
FUN_080995b0: @ 0x080995B0
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	adds r4, r0, #0
	mov sb, r1
	ldr r0, _08099634 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r6, #2
	rsbs r6, r6, #0
	ands r0, r6
	str r0, [r1]
	ldr r1, _08099638 @ =0x00001444
	adds r0, r4, r1
	movs r1, #0x60
	adds r1, r1, r4
	mov r8, r1
	movs r5, #0
	str r5, [sp]
	movs r2, #2
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _0809963C @ =0x000020AC
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	ldr r1, _08099640 @ =0x000020A4
	adds r6, r4, r1
	adds r0, r6, #0
	mov r1, r8
	movs r2, #0x42
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _08099644 @ =0x000020C4
	adds r0, r4, r1
	strh r5, [r0]
	adds r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	adds r1, #2
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, _08099648 @ =0x000002A5
	adds r0, r6, #0
	bl FUN_0808ba0c
	ldr r1, _0809964C @ =0x00004002
	adds r0, r4, r1
	mov r1, sb
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08098e48
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08099634: .4byte 0x0000144C
_08099638: .4byte 0x00001444
_0809963C: .4byte 0x000020AC
_08099640: .4byte 0x000020A4
_08099644: .4byte 0x000020C4
_08099648: .4byte 0x000002A5
_0809964C: .4byte 0x00004002

	thumb_func_start FUN_08099650
FUN_08099650: @ 0x08099650
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	movs r6, #0
	cmp r0, #0
	beq _08099672
	movs r6, #1
	cmp r0, #5
	bne _08099672
	movs r6, #2
_08099672:
	movs r0, #0
	movs r1, #6
	movs r2, #3
	bl FUN_0808a420
	adds r2, r0, #0
	lsls r0, r6, #1
	ldr r1, _080996BC @ =0x085ACFB8
	adds r0, r0, r6
	lsls r0, r0, #2
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r4, r3, #0
	adds r1, r0, r1
	movs r3, #0xa
_08099690:
	ldrb r0, [r1]
	orrs r0, r4
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	subs r3, #1
	cmp r3, #0
	bge _08099690
	ldr r0, _080996C0 @ =0x00004014
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r1, [r5, #0x58]
	bl FUN_0804a240
	cmp r6, #2
	bne _080996C4
	ldr r0, [r4]
	movs r1, #1
	bl FUN_0804a2f8
	b _080996CC
	.align 2, 0
_080996BC: .4byte 0x085ACFB8
_080996C0: .4byte 0x00004014
_080996C4:
	ldr r0, [r4]
	movs r1, #0
	bl FUN_0804a2f8
_080996CC:
	ldr r1, _080996DC @ =0x00004014
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a1f0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080996DC: .4byte 0x00004014

	thumb_func_start FUN_080996e0
FUN_080996e0: @ 0x080996E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _08099770 @ =0xFFFF0000
	mov sb, r0
	movs r4, #0
	ands r5, r0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r1, r1, r6
	mov r8, r1
	ldr r0, [r1]
	ldr r2, _08099774 @ =0x0000038E
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r1, _08099778 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _08099742
	ldr r2, _0809977C @ =0x000026A4
	adds r0, r6, r2
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb4
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _08099780 @ =0x000026AC
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08099784 @ =0x000026C4
	adds r0, r6, r1
	str r4, [r0]
	str r5, [r0, #4]
	movs r4, #0xc
	movs r7, #1
_08099742:
	mov r2, r8
	ldr r1, [r2]
	ldr r2, _08099788 @ =0x000004C7
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08099808
	subs r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809978C
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _0809977C @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb2
	b _080997A2
	.align 2, 0
_08099770: .4byte 0xFFFF0000
_08099774: .4byte 0x0000038E
_08099778: .4byte 0x030046A0
_0809977C: .4byte 0x000026A4
_08099780: .4byte 0x000026AC
_08099784: .4byte 0x000026C4
_08099788: .4byte 0x000004C7
_0809978C:
	cmp r0, #2
	bne _080997B0
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r2, _080997AC @ =0x000026A4
	adds r0, r0, r2
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb1
_080997A2:
	movs r3, #1
	bl Sprite_SetSprite
	b _080997C8
	.align 2, 0
_080997AC: .4byte 0x000026A4
_080997B0:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _080997F8 @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb3
	movs r3, #1
	bl Sprite_SetSprite
_080997C8:
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _080997FC @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _08099800 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r1, r4, #0
	adds r1, #0xc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08099804 @ =0xFFFF0000
	b _08099858
	.align 2, 0
_080997F8: .4byte 0x000026A4
_080997FC: .4byte 0x00000F6C
_08099800: .4byte 0x00000F84
_08099804: .4byte 0xFFFF0000
_08099808:
	ldr r2, _0809994C @ =0x0000043E
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08099860
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08099950 @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb5
	movs r3, #1
	bl Sprite_SetSprite
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08099954 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _08099958 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r1, r4, #0
	adds r1, #0xc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r0, sb
_08099858:
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	adds r7, #1
_08099860:
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r0, r0, r6
	mov r8, r0
	ldr r0, [r0]
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080998C4
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r2, _08099950 @ =0x000026A4
	adds r0, r0, r2
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb6
	movs r3, #1
	bl Sprite_SetSprite
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08099954 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _08099958 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r1, r4, #0
	adds r1, #0xc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0809995C @ =0xFFFF0000
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	adds r7, #1
_080998C4:
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _08099960 @ =0x0000043C
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08099910
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08099950 @ =0x000026A4
	adds r0, r0, r1
	adds r0, r6, r0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0xb7
	movs r3, #1
	bl Sprite_SetSprite
	adds r1, r7, #0
	adds r1, #0x3e
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _08099954 @ =0x00000F6C
	adds r2, r6, r1
	adds r2, r2, r0
	ldr r1, [r2]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r2]
	adds r0, r6, r0
	ldr r2, _08099958 @ =0x00000F84
	adds r0, r0, r2
	str r4, [r0]
	str r5, [r0, #4]
	adds r7, #1
_08099910:
	cmp r7, #0
	bne _08099920
	movs r0, #0xa
	movs r1, #9
	movs r2, #6
	movs r3, #1
	bl FUN_0808b97c
_08099920:
	cmp r7, #3
	bgt _08099940
	movs r2, #1
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	ldr r1, _08099964 @ =0x000026AC
	adds r0, r0, r1
	adds r1, r0, r6
_08099932:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	adds r7, #1
	cmp r7, #3
	ble _08099932
_08099940:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809994C: .4byte 0x0000043E
_08099950: .4byte 0x000026A4
_08099954: .4byte 0x00000F6C
_08099958: .4byte 0x00000F84
_0809995C: .4byte 0xFFFF0000
_08099960: .4byte 0x0000043C
_08099964: .4byte 0x000026AC

	thumb_func_start FUN_08099968
FUN_08099968: @ 0x08099968
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r1, _080999F4 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r2, _080999F8 @ =0x00004018
	adds r0, r4, r2
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0xa
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl weapon_080993e4
	adds r0, r4, #0
	movs r1, #5
	movs r2, #7
	bl FUN_0808b604
	adds r0, r4, #0
	bl FUN_0808b38c
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _080999FC @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, _08099A00 @ =0x0000264C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08099A08
	ldr r1, _08099A04 @ =0x00002644
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xe0
	movs r2, #0
	b _08099A16
	.align 2, 0
_080999F4: .4byte 0x00004014
_080999F8: .4byte 0x00004018
_080999FC: .4byte 0x00000F56
_08099A00: .4byte 0x0000264C
_08099A04: .4byte 0x00002644
_08099A08:
	cmp r0, #5
	bne _08099A24
	ldr r2, _08099A20 @ =0x00002644
	adds r0, r4, r2
	adds r1, r4, #0
	adds r1, #0xe0
	movs r2, #3
_08099A16:
	movs r3, #1
	bl Sprite_SetSprite
	b _08099A34
	.align 2, 0
_08099A20: .4byte 0x00002644
_08099A24:
	ldr r1, _08099AB4 @ =0x00002644
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xe0
	movs r2, #1
	movs r3, #1
	bl Sprite_SetSprite
_08099A34:
	adds r0, r4, #0
	bl FUN_08098edc
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080995b0
	adds r0, r4, #0
	bl FUN_08098bdc
	adds r0, r4, #0
	bl FUN_08098d98
	adds r0, r4, #0
	bl FUN_080996e0
	adds r0, r4, #0
	bl FUN_08099650
	movs r1, #0x10
	rsbs r1, r1, #0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808c61c
	movs r5, #1
	rsbs r5, r5, #0
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0808c658
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08099AC8
	ldr r0, _08099AB8 @ =0x0000144C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08099ABC @ =0x000020AC
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08099AC0 @ =0x00004003
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08098f48
	ldr r1, _08099AC4 @ =FUN_08098f7c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	b _08099B12
	.align 2, 0
_08099AB4: .4byte 0x00002644
_08099AB8: .4byte 0x0000144C
_08099ABC: .4byte 0x000020AC
_08099AC0: .4byte 0x00004003
_08099AC4: .4byte FUN_08098f7c
_08099AC8:
	ldr r0, _08099B24 @ =0x0000282C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #7
	bl FUN_0808a5b0
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #8
	bl FUN_0808a5e0
	ldr r1, _08099B28 @ =0x00004002
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x14
	ldr r2, _08099B2C @ =0x00004003
	adds r1, r4, r2
	strb r0, [r1]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r4, #0
	bl FUN_08098f48
	ldr r1, _08099B30 @ =FUN_08099008
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
_08099B12:
	ldr r0, _08099B34 @ =0x03003E78
	ldr r1, _08099B38 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099B24: .4byte 0x0000282C
_08099B28: .4byte 0x00004002
_08099B2C: .4byte 0x00004003
_08099B30: .4byte FUN_08099008
_08099B34: .4byte 0x03003E78
_08099B38: .4byte 0xFFFFFDFF

	thumb_func_start FUN_08099b3c
FUN_08099b3c: @ 0x08099B3C
	push {r4, lr}
	adds r4, r0, #0
	cmp r4, #0
	bge _08099B4A
	bl FUN_08047864
	b _08099B56
_08099B4A:
	movs r0, #1
	bl FUN_080477e4
	adds r0, r4, #0
	bl FUN_08047a28
_08099B56:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08099b5c
FUN_08099b5c: @ 0x08099B5C
	push {lr}
	ldr r0, _08099B70 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne _08099B74
	movs r0, #2
	b _08099B7E
	.align 2, 0
_08099B70: .4byte 0x030046A0
_08099B74:
	cmp r0, #2
	beq _08099B7C
	movs r0, #0
	b _08099B7E
_08099B7C:
	movs r0, #1
_08099B7E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08099b84
FUN_08099b84: @ 0x08099B84
	push {lr}
	cmp r0, #0
	bne _08099B8E
	movs r0, #4
	b _08099B98
_08099B8E:
	cmp r0, #1
	beq _08099B96
	movs r0, #1
	b _08099B98
_08099B96:
	movs r0, #2
_08099B98:
	pop {r1}
	bx r1

	thumb_func_start FUN_08099b9c
FUN_08099b9c: @ 0x08099B9C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08099C08 @ =0x030046A0
	ldr r1, [r5]
	ldr r2, _08099C0C @ =0x0000400E
	adds r0, r4, r2
	ldrb r0, [r0]
	strh r0, [r1, #0x10]
	ldr r1, _08099C10 @ =0x0000400F
	adds r0, r4, r1
	ldrb r0, [r0]
	bl FUN_08099b84
	ldr r1, [r5]
	strh r0, [r1, #0x12]
	ldr r1, [r5]
	ldr r2, _08099C14 @ =0x00004010
	adds r0, r4, r2
	ldrb r0, [r0]
	strh r0, [r1, #0x14]
	ldr r0, [r5]
	adds r0, #0x10
	movs r1, #2
	bl FUN_08231d5c
	ldr r0, [r5]
	adds r0, #0x12
	movs r1, #2
	bl FUN_08231d5c
	ldr r0, [r5]
	adds r0, #0x14
	movs r1, #2
	bl FUN_08231d5c
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r4, r4, r0
	ldr r4, [r4]
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08099C00
	ldr r0, [r5]
	ldrh r1, [r0, #0x10]
	ldr r2, _08099C18 @ =0x00000456
	adds r0, r4, r2
	strb r1, [r0]
_08099C00:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099C08: .4byte 0x030046A0
_08099C0C: .4byte 0x0000400E
_08099C10: .4byte 0x0000400F
_08099C14: .4byte 0x00004010
_08099C18: .4byte 0x00000456

	thumb_func_start FUN_08099c1c
FUN_08099c1c: @ 0x08099C1C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08099C50 @ =0x0000400D
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r5, _08099C54 @ =0x030046A0
	ldr r0, [r5]
	ldrh r1, [r0, #0x10]
	ldr r2, _08099C58 @ =0x0000400E
	adds r0, r4, r2
	strb r1, [r0]
	bl FUN_08099b5c
	ldr r2, _08099C5C @ =0x0000400F
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, [r5]
	ldrh r0, [r0, #0x14]
	ldr r1, _08099C60 @ =0x00004010
	adds r4, r4, r1
	strb r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08099C50: .4byte 0x0000400D
_08099C54: .4byte 0x030046A0
_08099C58: .4byte 0x0000400E
_08099C5C: .4byte 0x0000400F
_08099C60: .4byte 0x00004010

	thumb_func_start FUN_08099c64
FUN_08099c64: @ 0x08099C64
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	cmp r1, #0
	bne _08099C80
	ldr r1, _08099C7C @ =0x0000144C
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r3, #0x4f
	b _08099CA4
	.align 2, 0
_08099C7C: .4byte 0x0000144C
_08099C80:
	ldr r3, _08099CAC @ =0x0000144C
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _08099CB0 @ =0x0000400D
	adds r2, r5, r0
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r3, #0x1a
	adds r1, r5, r3
	strh r0, [r1]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08099CB4
	movs r3, #0x57
_08099CA4:
	movs r6, #0x52
	movs r7, #0x55
	b _08099CC6
	.align 2, 0
_08099CAC: .4byte 0x0000144C
_08099CB0: .4byte 0x0000400D
_08099CB4:
	cmp r0, #1
	bne _08099CC0
	movs r3, #0x4f
	movs r6, #0x5a
	movs r7, #0x55
	b _08099CC6
_08099CC0:
	movs r3, #0x4f
	movs r6, #0x52
	movs r7, #0x5d
_08099CC6:
	ldr r1, _08099D14 @ =0x00001CE4
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x60
	ldr r2, _08099D18 @ =0x0000400E
	adds r1, r5, r2
	ldrb r2, [r1]
	adds r2, r2, r3
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r3, _08099D1C @ =0x00001D44
	adds r0, r5, r3
	ldr r2, _08099D20 @ =0x0000400F
	adds r1, r5, r2
	ldrb r2, [r1]
	adds r2, r2, r6
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r3, _08099D24 @ =0x00001DA4
	adds r0, r5, r3
	adds r2, r7, #1
	ldr r3, _08099D28 @ =0x00004010
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08099D14: .4byte 0x00001CE4
_08099D18: .4byte 0x0000400E
_08099D1C: .4byte 0x00001D44
_08099D20: .4byte 0x0000400F
_08099D24: .4byte 0x00001DA4
_08099D28: .4byte 0x00004010

	thumb_func_start FUN_08099d2c
FUN_08099d2c: @ 0x08099D2C
	push {lr}
	adds r2, r0, #0
	ldr r0, _08099D5C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08099D88
	ldr r0, _08099D60 @ =0x0000400D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #1
	bhi _08099D6E
	ldr r3, _08099D64 @ =0x0000400E
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #1
	bls _08099D68
	movs r0, #0
	strb r0, [r1]
	b _08099D7E
	.align 2, 0
_08099D5C: .4byte 0x030044E0
_08099D60: .4byte 0x0000400D
_08099D64: .4byte 0x0000400E
_08099D68:
	adds r0, #1
	strb r0, [r1]
	b _08099D7E
_08099D6E:
	ldr r3, _08099D84 @ =0x0000400E
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r1, #1
	subs r1, r1, r2
	strb r1, [r0]
_08099D7E:
	movs r0, #0xcd
	lsls r0, r0, #1
	b _08099E1E
	.align 2, 0
_08099D84: .4byte 0x0000400E
_08099D88:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08099DD8
	ldr r0, _08099DB0 @ =0x0000400D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #1
	bhi _08099DBE
	ldr r3, _08099DB4 @ =0x0000400E
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _08099DB8
	movs r0, #2
	strb r0, [r1]
	b _08099DCE
	.align 2, 0
_08099DB0: .4byte 0x0000400D
_08099DB4: .4byte 0x0000400E
_08099DB8:
	subs r0, #1
	strb r0, [r1]
	b _08099DCE
_08099DBE:
	ldr r3, _08099DD4 @ =0x0000400E
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r1, #1
	subs r1, r1, r2
	strb r1, [r0]
_08099DCE:
	movs r0, #0xcd
	lsls r0, r0, #1
	b _08099E1E
	.align 2, 0
_08099DD4: .4byte 0x0000400E
_08099DD8:
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08099DFC
	ldr r0, _08099DF4 @ =0x0000400D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08099DF8
	movs r0, #2
	b _08099E1A
	.align 2, 0
_08099DF4: .4byte 0x0000400D
_08099DF8:
	subs r0, #1
	b _08099E1A
_08099DFC:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08099E26
	ldr r0, _08099E14 @ =0x0000400D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #2
	bne _08099E18
	strb r3, [r1]
	b _08099E1C
	.align 2, 0
_08099E14: .4byte 0x0000400D
_08099E18:
	adds r0, #1
_08099E1A:
	strb r0, [r1]
_08099E1C:
	movs r0, #0xdc
_08099E1E:
	bl PlaySound_082406e0
	movs r0, #1
	b _08099E28
_08099E26:
	movs r0, #0
_08099E28:
	pop {r1}
	bx r1

	thumb_func_start FUN_08099e2c
FUN_08099e2c: @ 0x08099E2C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08099E68 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08099E60
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08099c64
	movs r0, #6
	bl FUN_08099b3c
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _08099E6C @ =FUN_08099e70
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_08099E60:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099E68: .4byte 0x030044E0
_08099E6C: .4byte FUN_08099e70

	thumb_func_start FUN_08099e70
FUN_08099e70: @ 0x08099E70
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08099EA8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08099EB0
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08099b9c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08099c64
	movs r0, #7
	bl FUN_08099b3c
	ldr r1, _08099EAC @ =FUN_08099f18
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _08099F0E
	.align 2, 0
_08099EA8: .4byte 0x030044E0
_08099EAC: .4byte FUN_08099f18
_08099EB0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08099EF0
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_08099c1c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08099c64
	movs r0, #5
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _08099EEC @ =FUN_08099e2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	b _08099F0E
	.align 2, 0
_08099EEC: .4byte FUN_08099e2c
_08099EF0:
	adds r0, r4, #0
	bl FUN_08099d2c
	cmp r0, #0
	beq _08099F02
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08099c64
_08099F02:
	ldr r1, _08099F14 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl FUN_082372cc
_08099F0E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099F14: .4byte 0x00001444

	thumb_func_start FUN_08099f18
FUN_08099f18: @ 0x08099F18
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08099F50 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _08099F4A
	movs r0, #5
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _08099F54 @ =FUN_08099e2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
_08099F4A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099F50: .4byte 0x000009EE
_08099F54: .4byte FUN_08099e2c

	thumb_func_start FUN_08099f58
FUN_08099f58: @ 0x08099F58
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_08099c1c
	ldr r0, _0809A054 @ =0x00001CEC
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	mov sb, r2
	ands r0, r2
	str r0, [r1]
	ldr r1, _0809A058 @ =0x00001D04
	adds r0, r4, r1
	movs r6, #0
	strh r6, [r0]
	ldr r2, _0809A05C @ =0x00001D06
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x22
	adds r5, r4, r2
	ldr r0, _0809A060 @ =0x000002A5
	mov r8, r0
	adds r0, r5, #0
	mov r1, r8
	bl FUN_0808ba0c
	movs r1, #0x60
	adds r1, r1, r4
	mov sl, r1
	adds r0, r5, #0
	movs r2, #0x4f
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _0809A064 @ =0x00001D4C
	adds r1, r4, r2
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	ldr r1, _0809A068 @ =0x00001D64
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _0809A06C @ =0x00001D66
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x22
	adds r5, r4, r2
	adds r0, r5, #0
	mov r1, r8
	bl FUN_0808ba0c
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x52
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _0809A070 @ =0x00001DAC
	adds r1, r4, r0
	ldr r0, [r1]
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	ldr r1, _0809A074 @ =0x00001DC4
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _0809A078 @ =0x00001DC6
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x22
	adds r5, r4, r2
	adds r0, r5, #0
	mov r1, r8
	bl FUN_0808ba0c
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x55
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _0809A07C @ =0x00001464
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _0809A080 @ =0x00001466
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x22
	adds r0, r4, r2
	str r6, [sp]
	mov r1, sl
	movs r2, #3
	movs r3, #1
	bl FUN_082370cc
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08099c64
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A054: .4byte 0x00001CEC
_0809A058: .4byte 0x00001D04
_0809A05C: .4byte 0x00001D06
_0809A060: .4byte 0x000002A5
_0809A064: .4byte 0x00001D4C
_0809A068: .4byte 0x00001D64
_0809A06C: .4byte 0x00001D66
_0809A070: .4byte 0x00001DAC
_0809A074: .4byte 0x00001DC4
_0809A078: .4byte 0x00001DC6
_0809A07C: .4byte 0x00001464
_0809A080: .4byte 0x00001466

	thumb_func_start FUN_0809a084
FUN_0809a084: @ 0x0809A084
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r1, _0809A11C @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _0809A120 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0xb
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _0809A124 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	adds r0, r4, #0
	bl FUN_08099f58
	ldr r0, [r4, #0x58]
	bl FUN_080478f0
	ldr r0, _0809A128 @ =0x0000EFDA
	bl FUN_08047dc0
	movs r0, #5
	bl FUN_08099b3c
	movs r2, #0x10
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c61c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A12C @ =FUN_08099e2c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A11C: .4byte 0x00004014
_0809A120: .4byte 0x00004018
_0809A124: .4byte 0x00000F56
_0809A128: .4byte 0x0000EFDA
_0809A12C: .4byte FUN_08099e2c

	thumb_func_start FUN_0809a130
FUN_0809a130: @ 0x0809A130
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0809A198 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809A190
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808b6fc
	movs r0, #0x12
	bl FUN_08099b3c
	adds r0, r5, #0
	bl FUN_0808c700
	ldr r1, _0809A19C @ =FUN_0809a1a4
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
	ldr r0, _0809A1A0 @ =0x00004018
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #4
	movs r2, #6
	movs r3, #0x16
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r1, [r5, #0x58]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0x10
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
_0809A190:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A198: .4byte 0x030044E0
_0809A19C: .4byte FUN_0809a1a4
_0809A1A0: .4byte 0x00004018

	thumb_func_start FUN_0809a1a4
FUN_0809a1a4: @ 0x0809A1A4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0809A1E8
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #0x11
	bl FUN_08099b3c
	ldr r1, _0809A1E0 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A1E4 @ =FUN_0809a130
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	b _0809A202
	.align 2, 0
_0809A1E0: .4byte 0x00004018
_0809A1E4: .4byte FUN_0809a130
_0809A1E8:
	cmp r0, #1
	bne _0809A202
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0x13
	bl FUN_08099b3c
	ldr r1, _0809A208 @ =FUN_0809a20c
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809A202:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A208: .4byte FUN_0809a20c

	thumb_func_start FUN_0809a20c
FUN_0809a20c: @ 0x0809A20C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809A260 @ =0x030047B8
	movs r0, #1
	str r0, [r1]
	ldr r0, _0809A264 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _0809A25A
	movs r0, #0x11
	bl FUN_08099b3c
	ldr r1, _0809A268 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A26C @ =FUN_0809a130
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	ldr r0, _0809A270 @ =0x0000400C
	adds r1, r4, r0
	movs r0, #0x1e
	strb r0, [r1]
	bl FUN_0823d22c
_0809A25A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A260: .4byte 0x030047B8
_0809A264: .4byte 0x000009EE
_0809A268: .4byte 0x00004018
_0809A26C: .4byte FUN_0809a130
_0809A270: .4byte 0x0000400C

	thumb_func_start FUN_0809a274
FUN_0809a274: @ 0x0809A274
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r1, _0809A30C @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _0809A310 @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0xb
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _0809A314 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, [r4, #0x58]
	bl FUN_080478f0
	ldr r0, _0809A318 @ =0x0000EFDA
	bl FUN_08047dc0
	movs r0, #0x11
	bl FUN_08099b3c
	ldr r0, _0809A31C @ =0x0000400C
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r2, #0x10
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c61c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A320 @ =FUN_0809a130
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A30C: .4byte 0x00004014
_0809A310: .4byte 0x00004018
_0809A314: .4byte 0x00000F56
_0809A318: .4byte 0x0000EFDA
_0809A31C: .4byte 0x0000400C
_0809A320: .4byte FUN_0809a130

	thumb_func_start FUN_0809a324
FUN_0809a324: @ 0x0809A324
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809A360 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809A358
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808b6fc
	movs r0, #9
	bl FUN_08099b3c
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _0809A364 @ =FUN_0809a368
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809A358:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A360: .4byte 0x030044E0
_0809A364: .4byte FUN_0809a368

	thumb_func_start FUN_0809a368
FUN_0809a368: @ 0x0809A368
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0809A39C
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A398 @ =FUN_0809a324
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	b _0809A3E8
	.align 2, 0
_0809A398: .4byte FUN_0809a324
_0809A39C:
	cmp r0, #1
	bne _0809A3E8
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r0, _0809A3C4 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809A3C8 @ =0x0000093A
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0809A3D0
	ldr r1, _0809A3CC @ =FUN_0809a448
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _0809A3E8
	.align 2, 0
_0809A3C4: .4byte 0x030046A0
_0809A3C8: .4byte 0x0000093A
_0809A3CC: .4byte FUN_0809a448
_0809A3D0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808b6fc
	movs r0, #0xa
	bl FUN_08099b3c
	ldr r1, _0809A3F0 @ =FUN_0809a3f4
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809A3E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A3F0: .4byte FUN_0809a3f4

	thumb_func_start FUN_0809a3f4
FUN_0809a3f4: @ 0x0809A3F4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0809A428
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #8
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A424 @ =FUN_0809a324
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	b _0809A43C
	.align 2, 0
_0809A424: .4byte FUN_0809a324
_0809A428:
	cmp r0, #1
	bne _0809A43C
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _0809A444 @ =FUN_0809a448
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809A43C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A444: .4byte FUN_0809a448

	thumb_func_start FUN_0809a448
FUN_0809a448: @ 0x0809A448
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _0809A4B0 @ =0x030047B8
	movs r1, #1
	str r1, [r0]
	ldr r0, _0809A4B4 @ =0x000009EE
	adds r5, r6, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _0809A48E
	ldr r0, _0809A4B8 @ =0x00004018
	adds r4, r6, r0
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #2
	movs r2, #6
	movs r3, #0x1a
	bl FUN_0804a38c
	ldr r0, [r4]
	ldr r1, [r6, #0x58]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xd
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r0, #0xc
	bl FUN_08099b3c
_0809A48E:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0809A4A6
	ldr r1, _0809A4BC @ =FUN_0809a4c0
	adds r0, r6, #0
	movs r2, #1
	bl FUN_0808a354
_0809A4A6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A4B0: .4byte 0x030047B8
_0809A4B4: .4byte 0x000009EE
_0809A4B8: .4byte 0x00004018
_0809A4BC: .4byte FUN_0809a4c0

	thumb_func_start FUN_0809a4c0
FUN_0809a4c0: @ 0x0809A4C0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0809A4EC @ =0x030047B8
	movs r5, #1
	str r5, [r0]
	bl FUN_08241360
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0809A4FC
	ldr r0, _0809A4F0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809A4F4 @ =0x0000093A
	adds r0, r0, r1
	strh r5, [r0]
	ldr r1, _0809A4F8 @ =FUN_0809a510
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _0809A506
	.align 2, 0
_0809A4EC: .4byte 0x030047B8
_0809A4F0: .4byte 0x030046A0
_0809A4F4: .4byte 0x0000093A
_0809A4F8: .4byte FUN_0809a510
_0809A4FC:
	ldr r1, _0809A50C @ =FUN_0809a574
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_0809A506:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A50C: .4byte FUN_0809a574

	thumb_func_start FUN_0809a510
FUN_0809a510: @ 0x0809A510
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809A564 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809A534
	ldr r0, _0809A568 @ =0x000002AE
	bl PlaySound_082406e0
	ldr r1, _0809A56C @ =0x00004018
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #0xe
	bl FUN_08099b3c
_0809A534:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _0809A55E
	movs r0, #8
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A570 @ =FUN_0809a324
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0808a354
_0809A55E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A564: .4byte 0x000009EE
_0809A568: .4byte 0x000002AE
_0809A56C: .4byte 0x00004018
_0809A570: .4byte FUN_0809a324

	thumb_func_start FUN_0809a574
FUN_0809a574: @ 0x0809A574
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809A5CC @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809A59A
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0809A5D0 @ =0x00004018
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #0xf
	bl FUN_08099b3c
_0809A59A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _0809A5C4
	movs r0, #8
	bl FUN_08099b3c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A5D4 @ =FUN_0809a324
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0808a354
_0809A5C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809A5CC: .4byte 0x000009EE
_0809A5D0: .4byte 0x00004018
_0809A5D4: .4byte FUN_0809a324

	thumb_func_start FUN_0809a5d8
FUN_0809a5d8: @ 0x0809A5D8
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r1, _0809A668 @ =0x00004014
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	ldr r1, _0809A66C @ =0x00004018
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_0804a210
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0xb
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r1, _0809A670 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808b86c
	ldr r0, [r4, #0x58]
	bl FUN_080478f0
	ldr r0, _0809A674 @ =0x0000EFDA
	bl FUN_08047dc0
	movs r0, #8
	bl FUN_08099b3c
	movs r2, #0x10
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c61c
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808c658
	ldr r1, _0809A678 @ =FUN_0809a324
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A668: .4byte 0x00004014
_0809A66C: .4byte 0x00004018
_0809A670: .4byte 0x00000F56
_0809A674: .4byte 0x0000EFDA
_0809A678: .4byte FUN_0809a324

	thumb_func_start FUN_0809a67c
FUN_0809a67c: @ 0x0809A67C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809A6A0 @ =0x085ACFDC
	ldr r2, _0809A6A4 @ =0x00000F56
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_0808b4c0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A6A0: .4byte 0x085ACFDC
_0809A6A4: .4byte 0x00000F56

	thumb_func_start FUN_0809a6a8
FUN_0809a6a8: @ 0x0809A6A8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r1, _0809A7A4 @ =0x000009FC
	adds r0, r7, r1
	movs r2, #0
	mov r8, r2
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0809A7A8 @ =0x03003530
	str r1, [r0]
	ldr r5, _0809A7AC @ =0x03003E78
	ldrh r0, [r5]
	ldr r3, _0809A7B0 @ =0x00003B14
	adds r1, r7, r3
	strh r0, [r1]
	movs r4, #0x80
	lsls r4, r4, #1
	bics r0, r4
	ldr r1, _0809A7B4 @ =0xFFFFFDFF
	ands r0, r1
	ldr r1, _0809A7B8 @ =0xFFFFFBFF
	ands r0, r1
	ldr r1, _0809A7BC @ =0xFFFFF7FF
	ands r0, r1
	strh r0, [r5]
	movs r0, #1
	bl GetTilemapBuffer
	movs r6, #0xd8
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r2, _0809A7C0 @ =0x04000200
	bl CpuSet
	ldr r1, _0809A7C4 @ =0x03003ED0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	adds r1, #0x30
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldm r1!, {r2, r3, r6}
	stm r0!, {r2, r3, r6}
	ldr r2, _0809A7C8 @ =0x04000050
	ldrh r1, [r2]
	movs r3, #0x9b
	lsls r3, r3, #4
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, _0809A7CC @ =0x0400000A
	ldrh r1, [r0]
	ldr r6, _0809A7D0 @ =0x000009B4
	adds r0, r7, r6
	strh r1, [r0]
	mov r0, r8
	strh r0, [r2]
	ldr r1, _0809A7D4 @ =0x03004460
	movs r0, #0x40
	str r0, [r1]
	movs r0, #1
	movs r1, #2
	bl SetBGCharBaseDirect
	movs r0, #1
	movs r1, #1
	bl SetBGPrioDirect
	ldr r0, _0809A7D8 @ =0x0300449C
	ldrh r1, [r0]
	ldr r2, _0809A7DC @ =0x00003B16
	adds r0, r7, r2
	strh r1, [r0]
	ldr r0, _0809A7E0 @ =0x030044B4
	ldrh r1, [r0]
	ldr r3, _0809A7E4 @ =0x00003B18
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, _0809A7E8 @ =0x030044B0
	ldrb r1, [r0]
	ldr r6, _0809A7EC @ =0x00003B1A
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, _0809A7F0 @ =0x03004498
	ldrb r1, [r0]
	adds r2, #5
	adds r0, r7, r2
	strb r1, [r0]
	bl FUN_0822ed10
	ldrh r0, [r5]
	orrs r4, r0
	strh r4, [r5]
	movs r3, #1
	ldr r6, _0809A7F4 @ =0x0000108C
	adds r1, r7, r6
	movs r2, #9
_0809A774:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809A774
	movs r1, #0
	ldr r2, _0809A7F8 @ =0x00003AE4
	adds r0, r7, r2
	strb r1, [r0]
	adds r0, r7, #0
	bl FUN_0809a67c
	ldr r3, _0809A7FC @ =0x00004003
	adds r1, r7, r3
	movs r0, #0xff
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809A7A4: .4byte 0x000009FC
_0809A7A8: .4byte 0x03003530
_0809A7AC: .4byte 0x03003E78
_0809A7B0: .4byte 0x00003B14
_0809A7B4: .4byte 0xFFFFFDFF
_0809A7B8: .4byte 0xFFFFFBFF
_0809A7BC: .4byte 0xFFFFF7FF
_0809A7C0: .4byte 0x04000200
_0809A7C4: .4byte 0x03003ED0
_0809A7C8: .4byte 0x04000050
_0809A7CC: .4byte 0x0400000A
_0809A7D0: .4byte 0x000009B4
_0809A7D4: .4byte 0x03004460
_0809A7D8: .4byte 0x0300449C
_0809A7DC: .4byte 0x00003B16
_0809A7E0: .4byte 0x030044B4
_0809A7E4: .4byte 0x00003B18
_0809A7E8: .4byte 0x030044B0
_0809A7EC: .4byte 0x00003B1A
_0809A7F0: .4byte 0x03004498
_0809A7F4: .4byte 0x0000108C
_0809A7F8: .4byte 0x00003AE4
_0809A7FC: .4byte 0x00004003

	thumb_func_start FUN_0809a800
FUN_0809a800: @ 0x0809A800
	push {lr}
	ldr r0, _0809A814 @ =0x0000CEAA
	ldr r1, _0809A818 @ =0x00003002
	bl GetFile
	bl LoadParticleFile
	pop {r0}
	bx r0
	.align 2, 0
_0809A814: .4byte 0x0000CEAA
_0809A818: .4byte 0x00003002

	thumb_func_start FUN_0809a81c
FUN_0809a81c: @ 0x0809A81C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0809A8F4 @ =0x000009FC
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0809A8F8 @ =0x03003530
	str r1, [r0]
	ldr r2, _0809A8FC @ =0x03003E78
	ldr r0, _0809A900 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	ldr r1, _0809A904 @ =0xFFFFFDFF
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	movs r1, #0
	bl SetBGCharBaseDirect
	movs r0, #1
	bl GetTilemapBuffer
	adds r1, r0, #0
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, _0809A908 @ =0x04000200
	bl CpuSet
	ldr r1, _0809A90C @ =0x03003ED0
	adds r1, #0x30
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r1, _0809A910 @ =0x0400000A
	ldr r4, _0809A914 @ =0x000009B4
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809A918 @ =0x0300449C
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0809A91C @ =0x030044B4
	ldr r2, _0809A920 @ =0x00003B18
	adds r0, r5, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809A924 @ =0x030044B0
	ldr r3, _0809A928 @ =0x00003B1A
	adds r0, r5, r3
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0809A92C @ =0x03004498
	ldr r4, _0809A930 @ =0x00003B1B
	adds r0, r5, r4
	ldrb r0, [r0]
	strb r0, [r1]
	bl FUN_08047864
	bl FUN_08049f84
	ldr r0, _0809A934 @ =0x00004014
	adds r6, r5, r0
	movs r4, #1
_0809A8AE:
	ldm r6!, {r0}
	bl FUN_0804a210
	subs r4, #1
	cmp r4, #0
	bge _0809A8AE
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, _0809A8FC @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, [r5, #0x18]
	ldr r0, [r5, #0x30]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0808a3c4
	movs r1, #0xa3
	lsls r1, r1, #4
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0809A938 @ =0x00000A31
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_0808ce98
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809A8F4: .4byte 0x000009FC
_0809A8F8: .4byte 0x03003530
_0809A8FC: .4byte 0x03003E78
_0809A900: .4byte 0xFFFFFEFF
_0809A904: .4byte 0xFFFFFDFF
_0809A908: .4byte 0x04000200
_0809A90C: .4byte 0x03003ED0
_0809A910: .4byte 0x0400000A
_0809A914: .4byte 0x000009B4
_0809A918: .4byte 0x0300449C
_0809A91C: .4byte 0x030044B4
_0809A920: .4byte 0x00003B18
_0809A924: .4byte 0x030044B0
_0809A928: .4byte 0x00003B1A
_0809A92C: .4byte 0x03004498
_0809A930: .4byte 0x00003B1B
_0809A934: .4byte 0x00004014
_0809A938: .4byte 0x00000A31

	thumb_func_start FUN_0809a93c
FUN_0809a93c: @ 0x0809A93C
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r2, r4, #1
	cmp r2, #9
	ble _0809A948
	movs r2, #0
_0809A948:
	movs r3, #0
	ldr r5, _0809A95C @ =0x00000F58
	adds r1, r0, r5
_0809A94E:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A960
	adds r0, r2, #0
	b _0809A970
	.align 2, 0
_0809A95C: .4byte 0x00000F58
_0809A960:
	adds r2, #1
	cmp r2, #9
	ble _0809A968
	movs r2, #0
_0809A968:
	adds r3, #1
	cmp r3, #9
	ble _0809A94E
	adds r0, r4, #0
_0809A970:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809a978
FUN_0809a978: @ 0x0809A978
	push {r4, r5, lr}
	subs r2, r1, #1
	cmp r1, #0
	bne _0809A982
	movs r2, #9
_0809A982:
	movs r3, #0
	ldr r5, _0809A994 @ =0x00000F58
	adds r4, r0, r5
_0809A988:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809A998
	adds r0, r2, #0
	b _0809A9AA
	.align 2, 0
_0809A994: .4byte 0x00000F58
_0809A998:
	cmp r2, #0
	bne _0809A9A0
	movs r2, #9
	b _0809A9A2
_0809A9A0:
	subs r2, #1
_0809A9A2:
	adds r3, #1
	cmp r3, #9
	ble _0809A988
	adds r0, r1, #0
_0809A9AA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809a9b0
FUN_0809a9b0: @ 0x0809A9B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	movs r0, #0
	mov sl, r0
	ldr r2, _0809AA38 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	ldr r1, _0809AA3C @ =0x0000FF88
	orrs r0, r1
	adds r1, #0x77
	adds r4, r0, #0
	ands r4, r1
	ands r5, r2
	movs r1, #0
	mov r8, r1
	ldr r7, _0809AA40 @ =0x0000108C
	add r7, sb
	ldr r2, _0809AA44 @ =0x00001084
	add r2, sb
	str r2, [sp]
_0809A9E2:
	ldr r0, _0809AA48 @ =0x00000F58
	add r0, sb
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809AA6C
	ldr r6, [sp]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	mov r2, r8
	adds r2, #0x64
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	adds r1, #0x60
	movs r3, #1
	bl Sprite_SetSprite
	mov r0, sl
	mov r2, r8
	subs r1, r0, r2
	lsls r1, r1, #0x14
	ldr r0, _0809AA4C @ =0x0000FFFF
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	str r4, [r7, #0x18]
	str r5, [r7, #0x1c]
	ldr r0, _0809AA50 @ =0x00000F57
	add r0, sb
	ldrb r0, [r0]
	cmp r8, r0
	bne _0809AA58
	adds r0, r6, #0
	ldr r1, _0809AA54 @ =0x000002A5
	bl FUN_0808ba0c
	b _0809AA60
	.align 2, 0
_0809AA38: .4byte 0xFFFF0000
_0809AA3C: .4byte 0x0000FF88
_0809AA40: .4byte 0x0000108C
_0809AA44: .4byte 0x00001084
_0809AA48: .4byte 0x00000F58
_0809AA4C: .4byte 0x0000FFFF
_0809AA50: .4byte 0x00000F57
_0809AA54: .4byte 0x000002A5
_0809AA58:
	adds r0, r6, #0
	ldr r1, _0809AAE0 @ =0x000002A6
	bl FUN_0808ba0c
_0809AA60:
	adds r7, #0x60
	ldr r0, [sp]
	adds r0, #0x60
	str r0, [sp]
	movs r1, #1
	add sl, r1
_0809AA6C:
	movs r2, #1
	add r8, r2
	mov r0, r8
	cmp r0, #9
	ble _0809A9E2
	mov r1, sl
	cmp r1, #9
	bgt _0809AACE
	lsls r0, r1, #1
	add r0, sl
	lsls r0, r0, #5
	ldr r2, _0809AAE4 @ =0x0000108C
	adds r1, r0, r2
	mov r2, sb
	adds r6, r1, r2
	ldr r1, _0809AAE8 @ =0x00001084
	adds r0, r0, r1
	adds r7, r0, r2
_0809AA90:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	mov r2, sl
	lsls r1, r2, #0x14
	ldr r0, _0809AAEC @ =0x0000FFFF
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	str r4, [r6, #0x18]
	str r5, [r6, #0x1c]
	adds r0, r7, #0
	mov r1, sb
	adds r1, #0x60
	movs r2, #0x63
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r7, #0
	ldr r1, _0809AAF0 @ =0x000002A5
	bl FUN_0808ba0c
	adds r6, #0x60
	adds r7, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #9
	ble _0809AA90
_0809AACE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809AAE0: .4byte 0x000002A6
_0809AAE4: .4byte 0x0000108C
_0809AAE8: .4byte 0x00001084
_0809AAEC: .4byte 0x0000FFFF
_0809AAF0: .4byte 0x000002A5

	thumb_func_start FUN_0809aaf4
FUN_0809aaf4: @ 0x0809AAF4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809AB2C @ =0x000009EC
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #1
	bne _0809AB06
	bl FUN_082407e0
_0809AB06:
	ldrh r0, [r4]
	cmp r0, #2
	bne _0809AB14
	movs r0, #0x8c
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809AB14:
	ldrh r0, [r4]
	cmp r0, #0xf
	bhi _0809AB34
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	ldr r1, _0809AB30 @ =0x00001084
	bl FUN_0808a458
	b _0809AB3C
	.align 2, 0
_0809AB2C: .4byte 0x000009EC
_0809AB30: .4byte 0x00001084
_0809AB34:
	ldr r1, _0809AB64 @ =0x00001084
	movs r0, #0
	bl FUN_0808a458
_0809AB3C:
	ldr r0, _0809AB68 @ =0x000009EC
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x12
	bls _0809AB5C
	adds r0, r5, #0
	bl FUN_0809a6a8
	ldr r1, _0809AB6C @ =FUN_0809ab70
	adds r0, r5, #0
	bl FUN_0808a33c
_0809AB5C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AB64: .4byte 0x00001084
_0809AB68: .4byte 0x000009EC
_0809AB6C: .4byte FUN_0809ab70

	thumb_func_start FUN_0809ab70
FUN_0809ab70: @ 0x0809AB70
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0808b4c0
	ldr r0, _0809ABAC @ =0x000009EC
	adds r4, r5, r0
	ldrh r0, [r4]
	lsls r0, r0, #2
	ldr r1, _0809ABB0 @ =0x00001084
	bl FUN_0808a458
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bls _0809ABA4
	ldr r1, _0809ABB4 @ =0x000009F8
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r1, _0809ABB8 @ =FUN_0809ac30
	adds r0, r5, #0
	bl FUN_0808a33c
_0809ABA4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809ABAC: .4byte 0x000009EC
_0809ABB0: .4byte 0x00001084
_0809ABB4: .4byte 0x000009F8
_0809ABB8: .4byte FUN_0809ac30

	thumb_func_start FUN_0809abbc
FUN_0809abbc: @ 0x0809ABBC
	push {lr}
	ldr r0, _0809ABD8 @ =0x030044E0
	ldr r0, [r0]
	ldr r1, _0809ABDC @ =0x00020004
	ands r0, r1
	cmp r0, r1
	bne _0809ABE8
	ldr r0, _0809ABE0 @ =0x03004864
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809ABE4
	bl FUN_082416c8
	b _0809ABE8
	.align 2, 0
_0809ABD8: .4byte 0x030044E0
_0809ABDC: .4byte 0x00020004
_0809ABE0: .4byte 0x03004864
_0809ABE4:
	bl FUN_082416bc
_0809ABE8:
	movs r0, #0
	movs r1, #0x1b
	movs r2, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, _0809AC10 @ =0x03004864
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809AC18
	ldr r2, _0809AC14 @ =0x0000F001
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x90
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #0x20
	adds r0, r2, #0
	b _0809AC26
	.align 2, 0
_0809AC10: .4byte 0x03004864
_0809AC14: .4byte 0x0000F001
_0809AC18:
	ldr r2, _0809AC2C @ =0x0000F091
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #0x1f
	adds r0, r2, #0
	strh r0, [r1]
_0809AC26:
	strh r0, [r1, #2]
	pop {r0}
	bx r0
	.align 2, 0
_0809AC2C: .4byte 0x0000F091

	thumb_func_start FUN_0809ac30
FUN_0809ac30: @ 0x0809AC30
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r1, _0809AC50 @ =0x00001084
	movs r0, #0x40
	bl FUN_0808a458
	adds r0, r5, #0
	bl FUN_0808b4c0
	ldr r1, _0809AC54 @ =0x00003AE4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809AC5C
	ldr r1, _0809AC58 @ =FUN_0809ae0c
	b _0809AD04
	.align 2, 0
_0809AC50: .4byte 0x00001084
_0809AC54: .4byte 0x00003AE4
_0809AC58: .4byte FUN_0809ae0c
_0809AC5C:
	ldr r2, _0809AC8C @ =0x000009F8
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809AC9C
	ldr r0, _0809AC90 @ =0x00000FCC
	adds r1, r5, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809AC94 @ =0x0000102C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0809AC98 @ =0x000009F4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _0809ADFC
	.align 2, 0
_0809AC8C: .4byte 0x000009F8
_0809AC90: .4byte 0x00000FCC
_0809AC94: .4byte 0x0000102C
_0809AC98: .4byte 0x000009F4
_0809AC9C:
	ldr r2, _0809ACCC @ =0x00000FCC
	adds r1, r5, r2
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, _0809ACD0 @ =0x0000102C
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r7, _0809ACD4 @ =0x030044E0
	ldrh r2, [r7, #2]
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0809ACE0
	ldr r0, _0809ACD8 @ =0x00000119
	bl PlaySound_082406e0
	ldr r1, _0809ACDC @ =FUN_0809ae0c
	b _0809AD04
	.align 2, 0
_0809ACCC: .4byte 0x00000FCC
_0809ACD0: .4byte 0x0000102C
_0809ACD4: .4byte 0x030044E0
_0809ACD8: .4byte 0x00000119
_0809ACDC: .4byte FUN_0809ae0c
_0809ACE0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0809AD18
	ldr r1, _0809AD0C @ =0x00000F56
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _0809AD10 @ =0x00000F57
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_0809a9b0
	movs r0, #0x86
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0809AD14 @ =FUN_0809b12c
_0809AD04:
	adds r0, r5, #0
	bl FUN_0808a33c
	b _0809AE02
	.align 2, 0
_0809AD0C: .4byte 0x00000F56
_0809AD10: .4byte 0x00000F57
_0809AD14: .4byte FUN_0809b12c
_0809AD18:
	ldr r0, _0809AD3C @ =0x0000400C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809ADEC
	movs r3, #0
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r6, #0
	ands r0, r2
	cmp r0, #0
	beq _0809AD44
	ldr r1, _0809AD40 @ =0x00003AE5
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #1
	b _0809ADA2
	.align 2, 0
_0809AD3C: .4byte 0x0000400C
_0809AD40: .4byte 0x00003AE5
_0809AD44:
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	ands r0, r2
	cmp r0, #0
	beq _0809AD5C
	ldr r2, _0809AD58 @ =0x00003AE5
	adds r0, r5, r2
	strb r3, [r0]
	b _0809ADA0
	.align 2, 0
_0809AD58: .4byte 0x00003AE5
_0809AD5C:
	ldrh r1, [r7]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0809AD84
	ldr r0, _0809AD80 @ =0x00003AE5
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0809ADA2
	strb r3, [r1]
	movs r3, #1
	b _0809ADA2
	.align 2, 0
_0809AD80: .4byte 0x00003AE5
_0809AD84:
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0809ADA2
	ldr r2, _0809ADBC @ =0x00003AE5
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0809ADA2
	strb r3, [r1]
_0809ADA0:
	movs r3, #2
_0809ADA2:
	cmp r3, #1
	bne _0809ADC4
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _0809ADC0 @ =0x00000F56
	adds r4, r5, r0
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_0809a93c
	b _0809ADDC
	.align 2, 0
_0809ADBC: .4byte 0x00003AE5
_0809ADC0: .4byte 0x00000F56
_0809ADC4:
	cmp r3, #2
	bne _0809ADF0
	movs r0, #0x85
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0809ADE8 @ =0x00000F56
	adds r4, r5, r1
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_0809a978
_0809ADDC:
	strb r0, [r4]
	adds r0, r5, #0
	bl FUN_0809a67c
	b _0809AE02
	.align 2, 0
_0809ADE8: .4byte 0x00000F56
_0809ADEC:
	subs r0, #1
	strb r0, [r1]
_0809ADF0:
	ldr r2, _0809AE08 @ =0x000009F4
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_0809ADFC:
	adds r0, r5, #0
	bl FUN_0808c028
_0809AE02:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809AE08: .4byte 0x000009F4

	thumb_func_start FUN_0809ae0c
FUN_0809ae0c: @ 0x0809AE0C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809AE2C @ =0x000009EC
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0809AE34
	adds r1, r0, #0
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	ldr r1, _0809AE30 @ =0x00001084
	bl FUN_0808a458
	b _0809AE3C
	.align 2, 0
_0809AE2C: .4byte 0x000009EC
_0809AE30: .4byte 0x00001084
_0809AE34:
	ldr r1, _0809AE78 @ =0x00001084
	movs r0, #0
	bl FUN_0808a458
_0809AE3C:
	ldr r2, _0809AE7C @ =0x000009EC
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0xf
	bne _0809AE52
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
_0809AE52:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x12
	bls _0809AE9C
	ldr r0, _0809AE80 @ =0x0000401D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809AE84
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_0808f95c
	b _0809AE9C
	.align 2, 0
_0809AE78: .4byte 0x00001084
_0809AE7C: .4byte 0x000009EC
_0809AE80: .4byte 0x0000401D
_0809AE84:
	adds r0, r5, #0
	bl FUN_0809a81c
	ldr r1, _0809AEA4 @ =0x03004460
	ldr r2, _0809AEA8 @ =0x000009B2
	adds r0, r5, r2
	ldrh r0, [r0]
	str r0, [r1]
	ldr r1, _0809AEAC @ =FUN_0809aeb0
	adds r0, r5, #0
	bl FUN_0808a33c
_0809AE9C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809AEA4: .4byte 0x03004460
_0809AEA8: .4byte 0x000009B2
_0809AEAC: .4byte FUN_0809aeb0

	thumb_func_start FUN_0809aeb0
FUN_0809aeb0: @ 0x0809AEB0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x34
	adds r6, r0, #0
	ldr r0, _0809B0C4 @ =0x000009EC
	adds r4, r6, r0
	ldrh r0, [r4]
	lsls r0, r0, #2
	ldr r1, _0809B0C8 @ =0x00001084
	bl FUN_0808a458
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809AF20
	ldr r1, _0809B0CC @ =0x04000050
	movs r2, #0x9b
	lsls r2, r2, #4
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r0, _0809B0D0 @ =0x00003B14
	adds r3, r6, r0
	ldrh r1, [r3]
	movs r4, #0x80
	lsls r4, r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0809AEF2
	ldr r2, _0809B0D4 @ =0x03003E78
	ldrh r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
_0809AEF2:
	ldrh r3, [r3]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r4, #0
	ands r0, r3
	cmp r0, #0
	beq _0809AF0A
	ldr r2, _0809B0D4 @ =0x03003E78
	ldrh r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
_0809AF0A:
	movs r4, #0x80
	lsls r4, r4, #4
	adds r0, r4, #0
	ands r0, r3
	cmp r0, #0
	beq _0809AF20
	ldr r2, _0809B0D4 @ =0x03003E78
	ldrh r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r2]
_0809AF20:
	ldr r2, _0809B0C4 @ =0x000009EC
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bhi _0809AF36
	b _0809B0BC
_0809AF36:
	ldr r1, _0809B0D8 @ =FUN_0808cf14
	adds r0, r6, #0
	bl FUN_0808a33c
	ldr r1, _0809B0DC @ =0x03004494
	ldr r2, _0809B0E0 @ =0x00003B1C
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809B0E4 @ =0x03004454
	adds r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809B0E8 @ =0x03004464
	adds r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r1, _0809B0EC @ =0x03004490
	adds r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r2, _0809B0F0 @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bl FUN_0824082c
	ldr r0, _0809B0F4 @ =0x00003FB8
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0809AF94
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _0809B0F8 @ =0x00003FB9
	adds r1, r6, r2
	ldrb r1, [r1]
	bl FUN_080aace8
	strb r5, [r4]
_0809AF94:
	ldr r0, _0809B0FC @ =0x00003FB0
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0809AFD0
	ldr r1, _0809B100 @ =0x00003FB4
	adds r0, r6, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _0809AFC8
	ldr r1, _0809B104 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _0809B108 @ =0x00003FB1
	adds r0, r6, r1
	ldrb r0, [r0]
	str r0, [sp, #0xc]
	add r1, sp, #0x10
	add r0, sp, #0xc
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_0809AFC8:
	ldr r1, _0809B108 @ =0x00003FB1
	adds r0, r6, r1
	strb r5, [r0]
	strb r5, [r4]
_0809AFD0:
	ldr r2, _0809B10C @ =0x00003FAC
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809B082
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, _0809B110 @ =0xFFFFFE00
	adds r2, r0, #0
	add r4, sp, #0x18
	ldrh r0, [r4]
	adds r1, r2, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0809B104 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	ldrh r1, [r4, #4]
	adds r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [r4, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r4, #4]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	ldr r0, _0809B114 @ =0xFFFFFF00
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r5, _0809B118 @ =0x0000FFFF
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x20]
	ands r0, r3
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x20]
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0x12
	orrs r0, r1
	str r0, [sp, #0x20]
	adds r7, r4, #0
	adds r4, r2, #0
	movs r5, #2
_0809B04E:
	ldr r1, _0809B11C @ =0x00003FAD
	adds r0, r6, r1
	ldrb r1, [r0]
	ldr r2, _0809B120 @ =0x00003FAE
	adds r0, r6, r2
	ldrh r2, [r0]
	str r4, [sp]
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [sp, #4]
	movs r0, #0x78
	str r0, [sp, #8]
	movs r0, #4
	adds r3, r7, #0
	bl FUN_0800a8e0
	subs r5, #1
	cmp r5, #0
	bge _0809B04E
	ldr r1, _0809B11C @ =0x00003FAD
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0809B10C @ =0x00003FAC
	adds r0, r6, r2
	strb r1, [r0]
_0809B082:
	ldr r0, _0809B124 @ =0x00003FBB
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0809B0BC
	ldr r1, _0809B100 @ =0x00003FB4
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0809B0B8
	ldr r1, _0809B104 @ =0xFFFF0000
	ldr r0, [sp, #0x2c]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #0x2c]
	ldrb r0, [r4]
	subs r0, #1
	str r0, [sp, #0x28]
	add r0, sp, #0x28
	add r1, sp, #0x2c
	str r0, [r1, #4]
	ldr r2, _0809B128 @ =0x00003FBC
	adds r0, r6, r2
	ldr r0, [r0]
	bl Script_ExecById
_0809B0B8:
	movs r0, #0
	strb r0, [r4]
_0809B0BC:
	add sp, #0x34
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809B0C4: .4byte 0x000009EC
_0809B0C8: .4byte 0x00001084
_0809B0CC: .4byte 0x04000050
_0809B0D0: .4byte 0x00003B14
_0809B0D4: .4byte 0x03003E78
_0809B0D8: .4byte FUN_0808cf14
_0809B0DC: .4byte 0x03004494
_0809B0E0: .4byte 0x00003B1C
_0809B0E4: .4byte 0x03004454
_0809B0E8: .4byte 0x03004464
_0809B0EC: .4byte 0x03004490
_0809B0F0: .4byte 0x030044BC
_0809B0F4: .4byte 0x00003FB8
_0809B0F8: .4byte 0x00003FB9
_0809B0FC: .4byte 0x00003FB0
_0809B100: .4byte 0x00003FB4
_0809B104: .4byte 0xFFFF0000
_0809B108: .4byte 0x00003FB1
_0809B10C: .4byte 0x00003FAC
_0809B110: .4byte 0xFFFFFE00
_0809B114: .4byte 0xFFFFFF00
_0809B118: .4byte 0x0000FFFF
_0809B11C: .4byte 0x00003FAD
_0809B120: .4byte 0x00003FAE
_0809B124: .4byte 0x00003FBB
_0809B128: .4byte 0x00003FBC

	thumb_func_start FUN_0809b12c
FUN_0809b12c: @ 0x0809B12C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0809B170 @ =0x00001084
	movs r0, #0x40
	bl FUN_0808a458
	ldr r0, _0809B174 @ =0x000010A4
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #0xf
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _0809B154
	movs r0, #0
	strh r0, [r4]
	ldr r1, _0809B178 @ =FUN_0809b180
	adds r0, r5, #0
	bl FUN_0808a33c
_0809B154:
	adds r3, r4, #0
	ldr r0, _0809B17C @ =0x00001104
	adds r1, r5, r0
	movs r2, #8
_0809B15C:
	ldrh r0, [r3]
	strh r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809B15C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809B170: .4byte 0x00001084
_0809B174: .4byte 0x000010A4
_0809B178: .4byte FUN_0809b180
_0809B17C: .4byte 0x00001104

	thumb_func_start FUN_0809b180
FUN_0809b180: @ 0x0809B180
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _0809B1AC @ =0x00001084
	movs r0, #0x40
	bl FUN_0808a458
	adds r0, r6, #0
	bl FUN_0808b4c0
	ldr r0, _0809B1B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0809B1B8
	movs r0, #0x86
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0809B1B4 @ =FUN_0809b2b8
	b _0809B208
	.align 2, 0
_0809B1AC: .4byte 0x00001084
_0809B1B0: .4byte 0x030044E0
_0809B1B4: .4byte FUN_0809b2b8
_0809B1B8:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809B21C
	ldr r0, _0809B1E0 @ =0x00000F56
	adds r2, r6, r0
	ldr r1, _0809B1E4 @ =0x00000F57
	adds r0, r6, r1
	ldrb r1, [r0]
	ldrb r0, [r2]
	cmp r0, r1
	beq _0809B1E8
	strb r1, [r2]
	adds r0, r6, #0
	bl FUN_0809a67c
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _0809B1EE
	.align 2, 0
_0809B1E0: .4byte 0x00000F56
_0809B1E4: .4byte 0x00000F57
_0809B1E8:
	ldr r0, _0809B210 @ =0x00000119
	bl PlaySound_082406e0
_0809B1EE:
	ldr r1, _0809B214 @ =FUN_0809b2b8
	movs r4, #2
	rsbs r4, r4, #0
	ldr r0, _0809B218 @ =0x0000108C
	adds r2, r6, r0
	movs r3, #9
_0809B1FA:
	ldr r0, [r2]
	ands r0, r4
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0809B1FA
_0809B208:
	adds r0, r6, #0
	bl FUN_0808a33c
	b _0809B2AC
	.align 2, 0
_0809B210: .4byte 0x00000119
_0809B214: .4byte FUN_0809b2b8
_0809B218: .4byte 0x0000108C
_0809B21C:
	adds r0, r6, #0
	bl FUN_0808b6a4
	adds r1, r0, #0
	movs r2, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0809B244
	ldr r1, _0809B240 @ =0x00000F57
	adds r4, r6, r1
	ldrb r1, [r4]
	adds r0, r6, #0
	bl FUN_0809a978
	strb r0, [r4]
	b _0809B260
	.align 2, 0
_0809B240: .4byte 0x00000F57
_0809B244:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0809B25C
	ldr r0, _0809B28C @ =0x00000F57
	adds r4, r6, r0
	ldrb r1, [r4]
	adds r0, r6, #0
	bl FUN_0809a93c
	strb r0, [r4]
	movs r2, #1
_0809B25C:
	cmp r2, #0
	beq _0809B2AC
_0809B260:
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r5, #0
	ldr r1, _0809B290 @ =0x00001084
	adds r4, r6, r1
_0809B26C:
	ldr r1, _0809B294 @ =0x00000F58
	adds r0, r6, r1
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809B2A6
	subs r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r5, r0
	bne _0809B29C
	adds r0, r4, #0
	ldr r1, _0809B298 @ =0x000002A5
	bl FUN_0808ba0c
	b _0809B2A4
	.align 2, 0
_0809B28C: .4byte 0x00000F57
_0809B290: .4byte 0x00001084
_0809B294: .4byte 0x00000F58
_0809B298: .4byte 0x000002A5
_0809B29C:
	adds r0, r4, #0
	ldr r1, _0809B2B4 @ =0x000002A6
	bl FUN_0808ba0c
_0809B2A4:
	adds r4, #0x60
_0809B2A6:
	adds r5, #1
	cmp r5, #9
	ble _0809B26C
_0809B2AC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B2B4: .4byte 0x000002A6

	thumb_func_start FUN_0809b2b8
FUN_0809b2b8: @ 0x0809B2B8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0809B318 @ =0x00001084
	movs r0, #0x40
	bl FUN_0808a458
	adds r0, r5, #0
	bl FUN_0808b4c0
	ldr r0, _0809B31C @ =0x00004003
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0809B2E2
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_08098f48
	movs r0, #0xff
	strb r0, [r4]
_0809B2E2:
	ldr r0, _0809B320 @ =0x000010A4
	adds r2, r5, r0
	ldrh r0, [r2]
	subs r0, #0xf
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x78
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0809B32C
	ldr r1, _0809B324 @ =FUN_0809ac30
	movs r4, #1
	ldr r0, _0809B328 @ =0x0000108C
	adds r2, r5, r0
	movs r3, #9
_0809B302:
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0809B302
	adds r0, r5, #0
	bl FUN_0808a33c
	b _0809B33E
	.align 2, 0
_0809B318: .4byte 0x00001084
_0809B31C: .4byte 0x00004003
_0809B320: .4byte 0x000010A4
_0809B324: .4byte FUN_0809ac30
_0809B328: .4byte 0x0000108C
_0809B32C:
	ldr r0, _0809B344 @ =0x00001104
	adds r1, r5, r0
	movs r3, #8
_0809B332:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0809B332
_0809B33E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809B344: .4byte 0x00001104

	thumb_func_start FUN_0809b348
FUN_0809b348: @ 0x0809B348
	push {lr}
	adds r2, r0, #0
	ldr r0, _0809B394 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0809B3A8
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0809B3A8
	ldr r1, [r0, #0x1c]
	cmp r1, #1
	bne _0809B3A8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0809B3A8
	ldr r1, _0809B398 @ =0x000009FE
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0809B3A8
	ldr r2, _0809B39C @ =0x00000201
	ldr r0, _0809B3A0 @ =0x030047A4
	ldr r1, _0809B3A4 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _0809B3A8
	movs r0, #1
	b _0809B3AA
	.align 2, 0
_0809B394: .4byte 0x030044E0
_0809B398: .4byte 0x000009FE
_0809B39C: .4byte 0x00000201
_0809B3A0: .4byte 0x030047A4
_0809B3A4: .4byte 0x030047A0
_0809B3A8:
	movs r0, #0
_0809B3AA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809b3b0
FUN_0809b3b0: @ 0x0809B3B0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0809b348
	cmp r0, #0
	bne _0809B3C0
	movs r0, #0
	b _0809B406
_0809B3C0:
	movs r2, #4
	ldr r1, _0809B40C @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809B410 @ =0x03004460
	ldr r1, [r0]
	ldr r2, _0809B414 @ =0x000009B2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0809B418 @ =0x03004494
	ldrh r1, [r0]
	ldr r2, _0809B41C @ =0x00003B1C
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0809B420 @ =0x03004454
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0809B424 @ =0x03004464
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _0809B428 @ =0x03004490
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, _0809B42C @ =FUN_0809aaf4
	adds r0, r4, #0
	bl FUN_0808a33c
	movs r0, #1
_0809B406:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809B40C: .4byte 0x030044BC
_0809B410: .4byte 0x03004460
_0809B414: .4byte 0x000009B2
_0809B418: .4byte 0x03004494
_0809B41C: .4byte 0x00003B1C
_0809B420: .4byte 0x03004454
_0809B424: .4byte 0x03004464
_0809B428: .4byte 0x03004490
_0809B42C: .4byte FUN_0809aaf4

	thumb_func_start FUN_0809b430
FUN_0809b430: @ 0x0809B430
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0809B460 @ =0x00000F64
	adds r4, r6, r0
	movs r5, #0x73
_0809B43A:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B43A
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r0, r6, r1
	bl FUN_0822a4e0
	ldr r1, _0809B464 @ =0x00000BB8
	adds r0, r6, r1
	bl FUN_0822a4e0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809B460: .4byte 0x00000F64
_0809B464: .4byte 0x00000BB8

	thumb_func_start FUN_0809b468
FUN_0809b468: @ 0x0809B468
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	adds r7, r0, #0
	movs r1, #0
	ldr r2, _0809B84C @ =0xFFFF0000
	movs r4, #0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r2, _0809B850 @ =0x00000F64
	adds r0, r7, r2
	adds r6, r7, #0
	adds r6, #0x60
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x29
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldr r1, _0809B854 @ =0x00000FC4
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x89
	movs r3, #0xb1
	bl FUN_0822f3fc
	ldr r2, _0809B858 @ =0x00001024
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x8a
	movs r3, #0xb1
	bl FUN_0822f3fc
	ldr r1, _0809B85C @ =0x00001564
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x9d
	movs r3, #0xb1
	bl FUN_0822f3fc
	ldr r2, _0809B860 @ =0x000014A4
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x3c
	movs r3, #0xb1
	bl FUN_0822f3fc
	ldr r0, _0809B864 @ =0x00001E64
	adds r5, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x40
	movs r3, #0xb1
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #1
	movs r3, #1
	bl FUN_082370cc
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x40
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _0809B868 @ =0x00001444
	adds r5, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x39
	movs r3, #0xb1
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _0809B86C @ =0x00002584
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x93
	movs r3, #0xb1
	bl FUN_0822f3fc
	ldr r2, _0809B870 @ =0x000025E4
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r1, r6, #0
	movs r2, #0x93
	movs r3, #0xb1
	bl FUN_0822f3fc
	movs r6, #0
	movs r0, #0xa0
	adds r0, r0, r7
	mov sl, r0
	ldr r1, _0809B874 @ =0x000015C4
	adds r4, r7, r1
	movs r5, #0xf
_0809B5AE:
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	adds r1, #0xa0
	movs r2, #0x68
	movs r3, #0xb1
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B5AE
	adds r0, r7, #0
	adds r0, #0x60
	str r0, [sp, #0x18]
	adds r1, r7, #0
	adds r1, #0xe0
	str r1, [sp, #0x24]
	adds r2, r7, #0
	adds r2, #0x80
	str r2, [sp, #0x1c]
	adds r0, #0x60
	str r0, [sp, #0x20]
	movs r1, #0
	mov r8, r1
	add r2, sp, #0x10
	mov sb, r2
	ldr r0, _0809B878 @ =0x00001EC4
	adds r6, r7, r0
	ldr r1, _0809B87C @ =0x00001CE4
	adds r4, r7, r1
	movs r5, #3
_0809B5F8:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x68
	movs r3, #0xb1
	bl FUN_0822f3fc
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	adds r0, r6, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x41
	movs r3, #0xb1
	bl FUN_0822f3fc
	adds r6, #0x60
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B5F8
	movs r4, #0
	movs r1, #0x75
	add r0, sp, #0x10
	strh r1, [r0]
	adds r6, r0, #0
	movs r0, #0x46
	strh r0, [r6, #2]
	ldr r2, _0809B880 @ =0x00001BC4
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	str r6, [sp, #0xc]
	mov r1, sl
	movs r2, #0xca
	movs r3, #0xb1
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r6, #2]
	ldr r1, _0809B884 @ =0x00001C24
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x9c
	movs r3, #0xb1
	bl FUN_0822f3fc
	movs r1, #0x78
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x68
	strh r0, [r6, #2]
	ldr r1, _0809B888 @ =0x00001C84
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0xcb
	movs r3, #0xb1
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	movs r0, #0x80
	strh r0, [r6, #2]
	ldr r1, _0809B88C @ =0x00002044
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	mov r1, sl
	movs r2, #0xcf
	movs r3, #0xb1
	bl FUN_0822f3fc
	movs r6, #0
	ldr r0, _0809B890 @ =0x000020A4
	adds r4, r7, r0
	movs r5, #1
_0809B6C4:
	str r6, [sp]
	str r6, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x68
	movs r3, #0xb1
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B6C4
	movs r4, #0
	movs r0, #0x24
	mov sl, r0
	add r0, sp, #0x10
	mov r1, sl
	strh r1, [r0]
	add r2, sp, #0x10
	mov r8, r2
	movs r0, #0x70
	mov sb, r0
	mov r1, sb
	strh r1, [r2, #2]
	ldr r2, _0809B894 @ =0x000024C4
	adds r5, r7, r2
	adds r0, #0x90
	adds r6, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x90
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _0809B898 @ =0x00000B8C
	adds r5, r7, r0
	ldr r1, _0809B89C @ =0x0000DA6D
	adds r0, r5, #0
	bl Video_GetActorSprite
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #0x91
	bl FUN_0822a470
	ldr r2, _0809B8A0 @ =0x00000B67
	adds r0, r7, r2
	movs r1, #0
	strb r1, [r0]
	adds r2, #0x15
	adds r0, r7, r2
	mov r1, sl
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	mov r1, sb
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r4, [r0]
	movs r1, #0x34
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x64
	mov r1, r8
	strh r0, [r1, #2]
	ldr r2, _0809B8A4 @ =0x00002524
	adds r5, r7, r2
	adds r0, #0xbc
	adds r6, r7, r0
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0x94
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0xd
	movs r3, #1
	bl FUN_082370cc
	add r0, sp, #0x10
	strh r4, [r0]
	mov r0, r8
	strh r4, [r0, #2]
	movs r6, #0
	ldr r1, _0809B8A8 @ =0x00002164
	adds r4, r7, r1
	movs r5, #8
_0809B7AC:
	str r6, [sp]
	str r6, [sp, #4]
	movs r2, #0x3c
	mov r8, r2
	str r2, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	movs r2, #0xa
	movs r3, #0xb1
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B7AC
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	strh r4, [r5, #2]
	ldr r1, _0809B8AC @ =0x00001504
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x94
	movs r3, #0x91
	bl FUN_0822f3fc
	movs r1, #8
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x14
	strh r0, [r5, #2]
	ldr r1, _0809B8B0 @ =0x00002644
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0
	movs r3, #0x91
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	adds r6, r0, #0
	ldr r2, _0809B8B4 @ =0x000026A4
	adds r4, r7, r2
	movs r0, #0
	mov r8, r0
	movs r5, #3
_0809B826:
	mov r1, r8
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	movs r2, #0xaa
	movs r3, #0x91
	bl FUN_0822f3fc
	ldrh r0, [r6, #2]
	adds r0, #0xd
	strh r0, [r6, #2]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	b _0809B8B8
	.align 2, 0
_0809B84C: .4byte 0xFFFF0000
_0809B850: .4byte 0x00000F64
_0809B854: .4byte 0x00000FC4
_0809B858: .4byte 0x00001024
_0809B85C: .4byte 0x00001564
_0809B860: .4byte 0x000014A4
_0809B864: .4byte 0x00001E64
_0809B868: .4byte 0x00001444
_0809B86C: .4byte 0x00002584
_0809B870: .4byte 0x000025E4
_0809B874: .4byte 0x000015C4
_0809B878: .4byte 0x00001EC4
_0809B87C: .4byte 0x00001CE4
_0809B880: .4byte 0x00001BC4
_0809B884: .4byte 0x00001C24
_0809B888: .4byte 0x00001C84
_0809B88C: .4byte 0x00002044
_0809B890: .4byte 0x000020A4
_0809B894: .4byte 0x000024C4
_0809B898: .4byte 0x00000B8C
_0809B89C: .4byte 0x0000DA6D
_0809B8A0: .4byte 0x00000B67
_0809B8A4: .4byte 0x00002524
_0809B8A8: .4byte 0x00002164
_0809B8AC: .4byte 0x00001504
_0809B8B0: .4byte 0x00002644
_0809B8B4: .4byte 0x000026A4
_0809B8B8:
	bge _0809B826
	movs r0, #0
	add r1, sp, #0x10
	strh r0, [r1]
	strh r0, [r1, #2]
	movs r6, #0
	ldr r2, _0809BC94 @ =0x00001084
	adds r4, r7, r2
	movs r5, #9
_0809B8CA:
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	mov r8, r0
	str r0, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x64
	movs r3, #0xb1
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B8CA
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	strh r4, [r5, #2]
	ldr r2, _0809BC98 @ =0x00002824
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x4d
	movs r3, #0x91
	bl FUN_0822f3fc
	ldr r2, _0809BC9C @ =0x00002884
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x4e
	movs r3, #0x91
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	ldr r0, [sp, #0x18]
	mov sb, r0
	movs r1, #0x3c
	mov sl, r1
	ldr r2, _0809BCA0 @ =0x00002A64
	adds r2, r2, r7
	mov r8, r2
	ldr r0, _0809BCA4 @ =0x000028E4
	adds r6, r7, r0
	add r4, sp, #0x10
	movs r5, #3
_0809B944:
	movs r1, #1
	str r1, [sp]
	movs r2, #0
	str r2, [sp, #4]
	mov r0, sl
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0x47
	movs r3, #0x91
	bl FUN_0822f3fc
	movs r1, #1
	str r1, [sp]
	movs r2, #0
	str r2, [sp, #4]
	mov r0, sl
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, r8
	mov r1, sb
	movs r2, #0x46
	movs r3, #0x91
	bl FUN_0822f3fc
	ldrh r0, [r4, #2]
	adds r0, #8
	strh r0, [r4, #2]
	movs r1, #0x60
	add r8, r1
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809B944
	movs r0, #0
	add r1, sp, #0x10
	strh r0, [r1]
	strh r0, [r1, #2]
	movs r5, #0
	ldr r6, [sp, #0x1c]
	mov sb, r5
_0809B998:
	lsls r2, r5, #1
	adds r4, r2, r5
	lsls r4, r4, #5
	ldr r0, _0809BCA8 @ =0x00002CA4
	adds r4, r4, r0
	adds r4, r7, r4
	adds r2, #9
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #1
	mov sl, r1
	str r1, [sp]
	mov r0, sb
	str r0, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #0x91
	bl FUN_0822f3fc
	adds r5, #1
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	mov r1, sb
	str r1, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #1
	bl FUN_082370cc
	cmp r5, #3
	ble _0809B998
	ldr r2, _0809BCAC @ =0x00002BE4
	adds r0, r7, r2
	mov r1, sl
	str r1, [sp]
	movs r4, #0
	str r4, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r5, sp, #0x10
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0
	movs r3, #0x91
	bl FUN_0822f3fc
	ldr r1, _0809BCB0 @ =0x00002C44
	adds r0, r7, r1
	mov r2, sl
	str r2, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #3
	movs r3, #0x91
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	movs r5, #0
	movs r6, #0x90
	lsls r6, r6, #0xd
	ldr r0, _0809BCB4 @ =0x00002FA4
	adds r4, r7, r0
_0809BA2A:
	lsrs r2, r6, #0x10
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	movs r3, #0x91
	bl FUN_0822f3fc
	movs r2, #0x80
	lsls r2, r2, #9
	adds r6, r6, r2
	adds r4, #0x60
	adds r5, #1
	cmp r5, #5
	ble _0809BA2A
	ldr r0, _0809BCB8 @ =0x000031E4
	adds r4, r7, r0
	movs r5, #7
_0809BA5A:
	movs r0, #1
	str r0, [sp]
	movs r6, #0
	str r6, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x11
	movs r3, #0x91
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809BA5A
	add r0, sp, #0x10
	strh r6, [r0]
	adds r4, r0, #0
	strh r6, [r4, #2]
	ldr r1, _0809BCBC @ =0x00002E24
	adds r0, r7, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x36
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldr r1, _0809BCC0 @ =0x00002E84
	adds r0, r7, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x37
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldr r2, _0809BCC4 @ =0x00002EE4
	adds r0, r7, r2
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x34
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldr r1, _0809BCC8 @ =0x00002F44
	adds r0, r7, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x35
	movs r3, #0xb0
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r6, [r0]
	strh r6, [r4, #2]
	ldr r2, _0809BCCC @ =0x000034E4
	adds r0, r7, r2
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #4
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldr r1, _0809BCD0 @ =0x00003544
	adds r0, r7, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x19
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldr r2, _0809BCD4 @ =0x000035A4
	adds r0, r7, r2
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x1b
	movs r3, #0xb0
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r6, [r0]
	strh r6, [r4, #2]
	adds r6, r0, #0
	ldr r0, _0809BCD8 @ =0x00003664
	adds r4, r7, r0
	movs r1, #0
	mov r8, r1
	movs r5, #2
_0809BB54:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	mov sb, r0
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r2, #8
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809BB54
	movs r2, #0
	movs r1, #0x10
	add r0, sp, #0x10
	strh r1, [r0]
	adds r4, r0, #0
	ldr r0, _0809BCDC @ =0x0000FFFC
	strh r0, [r4, #2]
	ldr r1, _0809BCE0 @ =0x00003604
	adds r0, r7, r1
	str r2, [sp]
	str r2, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #0x12
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldr r1, _0809BCE4 @ =0x0000FFC8
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x38
	strh r0, [r4, #2]
	add r6, sp, #0x10
	ldr r0, _0809BCE8 @ =0x00003784
	adds r4, r7, r0
	movs r1, #0
	mov r8, r1
	movs r5, #3
_0809BBB8:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	mov sb, r0
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r2, #8
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809BBB8
	movs r2, #0
	movs r1, #0x58
	add r0, sp, #0x10
	strh r1, [r0]
	adds r4, r0, #0
	movs r0, #0x38
	strh r0, [r4, #2]
	ldr r1, _0809BCEC @ =0x00003904
	adds r0, r7, r1
	str r2, [sp]
	str r2, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r2, #8
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldr r1, _0809BCF0 @ =0x0000FFD0
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x48
	strh r0, [r4, #2]
	add r6, sp, #0x10
	ldr r0, _0809BCF4 @ =0x00003964
	adds r4, r7, r0
	movs r1, #0
	mov r8, r1
	movs r5, #3
_0809BC1C:
	mov r2, r8
	str r2, [sp]
	str r2, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x20]
	movs r2, #8
	movs r3, #0xb0
	bl FUN_0822f3fc
	ldrh r0, [r6]
	adds r0, #8
	strh r0, [r6]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809BC1C
	movs r5, #0
	ldr r0, _0809BCF8 @ =0x00000BE4
	adds r4, r7, r0
	ldr r1, _0809BCFC @ =0x0000A47C
	adds r0, r4, #0
	bl Video_GetActorSprite
	ldr r1, _0809BD00 @ =0x00000BB8
	adds r0, r7, r1
	adds r1, r4, #0
	movs r2, #0x91
	bl FUN_0822a470
	ldr r1, _0809BD04 @ =0x00000143
	adds r0, r4, #0
	bl FUN_0822b20c
	ldr r2, _0809BD08 @ =0x00000BBF
	adds r0, r7, r2
	strb r5, [r0]
	ldr r0, _0809BD0C @ =0x00000BD4
	adds r1, r7, r0
	movs r0, #0xa0
	strh r0, [r1]
	adds r2, #0x17
	adds r1, r7, r2
	movs r0, #0x58
	strh r0, [r1]
	ldr r1, _0809BD10 @ =0x00000BD8
	adds r0, r7, r1
	strh r5, [r0]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0809BC90: .4byte 0x0000E040
_0809BC94: .4byte 0x00001084
_0809BC98: .4byte 0x00002824
_0809BC9C: .4byte 0x00002884
_0809BCA0: .4byte 0x00002A64
_0809BCA4: .4byte 0x000028E4
_0809BCA8: .4byte 0x00002CA4
_0809BCAC: .4byte 0x00002BE4
_0809BCB0: .4byte 0x00002C44
_0809BCB4: .4byte 0x00002FA4
_0809BCB8: .4byte 0x000031E4
_0809BCBC: .4byte 0x00002E24
_0809BCC0: .4byte 0x00002E84
_0809BCC4: .4byte 0x00002EE4
_0809BCC8: .4byte 0x00002F44
_0809BCCC: .4byte 0x000034E4
_0809BCD0: .4byte 0x00003544
_0809BCD4: .4byte 0x000035A4
_0809BCD8: .4byte 0x00003664
_0809BCDC: .4byte 0x0000FFFC
_0809BCE0: .4byte 0x00003604
_0809BCE4: .4byte 0x0000FFC8
_0809BCE8: .4byte 0x00003784
_0809BCEC: .4byte 0x00003904
_0809BCF0: .4byte 0x0000FFD0
_0809BCF4: .4byte 0x00003964
_0809BCF8: .4byte 0x00000BE4
_0809BCFC: .4byte 0x0000A47C
_0809BD00: .4byte 0x00000BB8
_0809BD04: .4byte 0x00000143
_0809BD08: .4byte 0x00000BBF
_0809BD0C: .4byte 0x00000BD4
_0809BD10: .4byte 0x00000BD8

	thumb_func_start FUN_0809bd14
FUN_0809bd14: @ 0x0809BD14
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r5, _0809BEB0 @ =0x0000CB05
	ldr r1, _0809BEB4 @ =0x0000B343
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0809BD2A
	b _0809BEA8
_0809BD2A:
	adds r1, r4, #0
	adds r1, #0x60
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	ldm r0!, {r2, r6}
	stm r1!, {r2, r6}
	adds r0, r4, #0
	adds r0, #0x60
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0809BEB8 @ =0x00005D04
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0809BD54
	b _0809BEA8
_0809BD54:
	movs r7, #0xa0
	adds r7, r7, r4
	mov ip, r7
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6}
	stm r2!, {r0, r6}
	mov r0, ip
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0809BEBC @ =0x00000312
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0809BD82
	b _0809BEA8
_0809BD82:
	adds r1, r4, #0
	adds r1, #0x80
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	ldm r0!, {r2, r7}
	stm r1!, {r2, r7}
	adds r0, r4, #0
	adds r0, #0x80
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0809BEC0 @ =0x000092F0
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r6, #0xc0
	adds r6, r6, r4
	mov ip, r6
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r7}
	stm r2!, {r0, r7}
	mov r0, ip
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0809BEC4 @ =0x0000DE23
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r1, r1, r4
	mov ip, r1
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r6, r7}
	stm r2!, {r6, r7}
	mov r0, ip
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0809BEC8 @ =0x0000DFDE
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r0, #0x90
	lsls r0, r0, #1
	adds r0, r0, r4
	mov ip, r0
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r6, r7}
	stm r2!, {r6, r7}
	mov r0, ip
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0809BECC @ =0x0000E2DE
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r0, r0, r4
	mov ip, r0
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r6, r7}
	stm r2!, {r6, r7}
	mov r0, ip
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0809BED0 @ =0x0000D27A
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r0, #0xe0
	adds r0, r0, r4
	mov ip, r0
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r6, r7}
	stm r2!, {r6, r7}
	mov r0, ip
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0809BED4 @ =0x0000DCC1
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldm r1!, {r6, r7}
	stm r2!, {r6, r7}
	adds r1, r3, #0
	bl OpenSpriteSetFile
_0809BEA8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809BEB0: .4byte 0x0000CB05
_0809BEB4: .4byte 0x0000B343
_0809BEB8: .4byte 0x00005D04
_0809BEBC: .4byte 0x00000312
_0809BEC0: .4byte 0x000092F0
_0809BEC4: .4byte 0x0000DE23
_0809BEC8: .4byte 0x0000DFDE
_0809BECC: .4byte 0x0000E2DE
_0809BED0: .4byte 0x0000D27A
_0809BED4: .4byte 0x0000DCC1

	thumb_func_start FUN_0809bed8
FUN_0809bed8: @ 0x0809BED8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809BEEC
	bl FUN_0823d340
	str r0, [r4, #0x40]
_0809BEEC:
	movs r0, #0x77
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809BEFC
	bl FUN_0823d340
	str r0, [r4, #0x44]
_0809BEFC:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809BF0C
	bl FUN_0823d340
	str r0, [r4, #0x48]
_0809BF0C:
	movs r0, #0x6d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809BF1C
	bl FUN_0823d340
	str r0, [r4, #0x4c]
_0809BF1C:
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809BF2C
	bl FUN_0823d340
	str r0, [r4, #0x50]
_0809BF2C:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809BF3C
	bl FUN_0823d340
	str r0, [r4, #0x54]
_0809BF3C:
	movs r0, #0x45
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809BF4C
	bl FUN_0823d340
	str r0, [r4, #0x58]
_0809BF4C:
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809BF5C
	bl VM_GetValueSafe2
	str r0, [r4, #0x5c]
_0809BF5C:
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0809BF78
	bl Script_GetValue
	ldr r2, _0809BF74 @ =0x00003FA0
	adds r1, r4, r2
	strb r0, [r1]
	b _0809BF7E
	.align 2, 0
_0809BF74: .4byte 0x00003FA0
_0809BF78:
	ldr r2, _0809BF84 @ =0x00003FA0
	adds r0, r4, r2
	strb r1, [r0]
_0809BF7E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809BF84: .4byte 0x00003FA0

	thumb_func_start FUN_0809bf88
FUN_0809bf88: @ 0x0809BF88
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0x6f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809BFB0
	movs r4, #0
	ldr r0, _0809BFAC @ =0x00000F58
	adds r5, r6, r0
_0809BF9C:
	bl Script_GetValue
	adds r1, r5, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, #9
	ble _0809BF9C
	b _0809BFC2
	.align 2, 0
_0809BFAC: .4byte 0x00000F58
_0809BFB0:
	movs r1, #1
	movs r4, #9
	ldr r2, _0809C008 @ =0x00000F61
	adds r0, r6, r2
_0809BFB8:
	strb r1, [r0]
	subs r0, #1
	subs r4, #1
	cmp r4, #0
	bge _0809BFB8
_0809BFC2:
	ldr r3, _0809C00C @ =0x00000F56
	adds r1, r6, r3
	ldrb r0, [r1]
	adds r3, #2
	adds r2, r6, r3
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809C000
	movs r4, #0
	movs r7, #0
	adds r3, r2, #0
	movs r5, #0xff
_0809BFDC:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ands r0, r5
	cmp r0, #9
	bls _0809BFEA
	strb r7, [r1]
_0809BFEA:
	ldrb r0, [r1]
	adds r0, r3, r0
	ldrb r2, [r0]
	cmp r2, #0
	bne _0809C000
	adds r4, #1
	cmp r4, #9
	ble _0809BFDC
	ldr r1, _0809C00C @ =0x00000F56
	adds r0, r6, r1
	strb r2, [r0]
_0809C000:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809C008: .4byte 0x00000F61
_0809C00C: .4byte 0x00000F56

	thumb_func_start FUN_0809c010
FUN_0809c010: @ 0x0809C010
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x71
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809C02C
	bl Script_GetValue
	ldr r2, _0809C028 @ =0x00000F3D
	adds r1, r4, r2
	b _0809C032
	.align 2, 0
_0809C028: .4byte 0x00000F3D
_0809C02C:
	ldr r0, _0809C03C @ =0x00000F3D
	adds r1, r4, r0
	movs r0, #1
_0809C032:
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C03C: .4byte 0x00000F3D

	thumb_func_start FUN_0809c040
FUN_0809c040: @ 0x0809C040
	ldr r0, _0809C058 @ =0x0300013C
	movs r2, #0
	str r2, [r0]
	ldr r0, _0809C05C @ =0x03002C14
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0809C060 @ =0x03002C10
	strh r2, [r0]
	ldr r0, _0809C064 @ =0x03002C18
	strh r1, [r0]
	bx lr
	.align 2, 0
_0809C058: .4byte 0x0300013C
_0809C05C: .4byte 0x03002C14
_0809C060: .4byte 0x03002C10
_0809C064: .4byte 0x03002C18

	thumb_func_start FUN_0809c068
FUN_0809c068: @ 0x0809C068
	push {lr}
	ldr r0, _0809C07C @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C084
	ldr r1, _0809C080 @ =0x000009FC
	adds r0, r0, r1
	ldrh r0, [r0]
	b _0809C088
	.align 2, 0
_0809C07C: .4byte 0x0300013C
_0809C080: .4byte 0x000009FC
_0809C084:
	movs r0, #1
	rsbs r0, r0, #0
_0809C088:
	pop {r1}
	bx r1

	thumb_func_start FUN_0809c08c
FUN_0809c08c: @ 0x0809C08C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r1, r0, #0
	ldr r0, _0809C0E8 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	bne _0809C09C
	b _0809C1A0
_0809C09C:
	ldr r0, _0809C0EC @ =0x000009FE
	adds r5, r4, r0
	strb r1, [r5]
	ldr r2, _0809C0F0 @ =0x000009FC
	adds r0, r4, r2
	ldrh r6, [r0]
	cmp r6, #0
	bne _0809C1A0
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bne _0809C104
	adds r0, r4, #0
	bl FUN_0808d39c
	ldr r0, _0809C0F4 @ =0x00000A3C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809C0F8 @ =0x00000AA8
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809C0FC @ =0x00000B08
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0809C100 @ =0x00000A31
	adds r0, r4, r1
	strb r6, [r0]
	movs r0, #0
	bl FUN_0822b644
	b _0809C198
	.align 2, 0
_0809C0E8: .4byte 0x0300013C
_0809C0EC: .4byte 0x000009FE
_0809C0F0: .4byte 0x000009FC
_0809C0F4: .4byte 0x00000A3C
_0809C0F8: .4byte 0x00000AA8
_0809C0FC: .4byte 0x00000B08
_0809C100: .4byte 0x00000A31
_0809C104:
	cmp r0, #2
	bhi _0809C14C
	ldr r0, _0809C140 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0809C11C
	adds r0, r4, #0
	bl FUN_0808d3d4
_0809C11C:
	ldr r1, [r4, #0x18]
	movs r0, #0
	movs r2, #0
	bl FUN_0822c398
	ldrb r0, [r5]
	cmp r0, #1
	bne _0809C18A
	ldr r0, _0809C144 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r1, [r0]
	ldr r2, _0809C148 @ =0x00000A1E
	adds r0, r4, r2
	strh r1, [r0]
	b _0809C18A
	.align 2, 0
_0809C140: .4byte 0x030047A4
_0809C144: .4byte 0x030046A0
_0809C148: .4byte 0x00000A1E
_0809C14C:
	adds r0, r4, #0
	bl FUN_0808d39c
	ldr r0, _0809C1A8 @ =0x00000A3C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809C1AC @ =0x00000AA8
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809C1B0 @ =0x00000B08
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, [r4, #0x18]
	ldrb r2, [r5]
	subs r2, #2
	movs r0, #0
	bl FUN_0822c398
	ldr r0, _0809C1B4 @ =0x0000EFDA
	bl FUN_08047dc0
	ldr r1, _0809C1B8 @ =0x00000A31
	adds r0, r4, r1
	strb r6, [r0]
_0809C18A:
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
_0809C198:
	ldr r2, _0809C1BC @ =0x00000A24
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0809C1A0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809C1A8: .4byte 0x00000A3C
_0809C1AC: .4byte 0x00000AA8
_0809C1B0: .4byte 0x00000B08
_0809C1B4: .4byte 0x0000EFDA
_0809C1B8: .4byte 0x00000A31
_0809C1BC: .4byte 0x00000A24

	thumb_func_start FUN_0809c1c0
FUN_0809c1c0: @ 0x0809C1C0
	push {lr}
	ldr r0, _0809C1DC @ =0x0300013C
	ldr r2, [r0]
	cmp r2, #0
	beq _0809C1D6
	ldr r1, _0809C1E0 @ =0x000009FE
	adds r0, r2, r1
	ldrb r1, [r0]
	ldr r3, _0809C1E4 @ =0x000009FF
	adds r0, r2, r3
	strb r1, [r0]
_0809C1D6:
	pop {r0}
	bx r0
	.align 2, 0
_0809C1DC: .4byte 0x0300013C
_0809C1E0: .4byte 0x000009FE
_0809C1E4: .4byte 0x000009FF

	thumb_func_start FUN_0809c1e8
FUN_0809c1e8: @ 0x0809C1E8
	push {r4, lr}
	ldr r0, _0809C20C @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C206
	ldr r1, _0809C210 @ =0x000009FF
	adds r4, r0, r1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0809C206
	bl FUN_0809c08c
	movs r0, #0xff
	strb r0, [r4]
_0809C206:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C20C: .4byte 0x0300013C
_0809C210: .4byte 0x000009FF

	thumb_func_start FUN_0809c214
FUN_0809c214: @ 0x0809C214
	push {lr}
	bl FUN_0809c1c0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809c220
FUN_0809c220: @ 0x0809C220
	push {lr}
	bl FUN_0809c1e8
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Textbox_CloseBox
Textbox_CloseBox: @ 0x0809C22C
	push {lr}
	movs r0, #0x6d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809C240
	bl Script_GetValue
	bl FUN_0809c08c
_0809C240:
	pop {r0}
	bx r0

	thumb_func_start FUN_0809c244
FUN_0809c244: @ 0x0809C244
	push {lr}
	ldr r0, _0809C25C @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C258
	ldr r1, _0809C260 @ =0x000009FE
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0809c08c
_0809C258:
	pop {r0}
	bx r0
	.align 2, 0
_0809C25C: .4byte 0x0300013C
_0809C260: .4byte 0x000009FE

	thumb_func_start FUN_0809c264
FUN_0809c264: @ 0x0809C264
	push {lr}
	ldr r0, _0809C284 @ =0x0300013C
	ldr r1, [r0]
	cmp r1, #0
	beq _0809C27E
	ldr r2, _0809C288 @ =0x000009FC
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809C27E
	adds r0, r1, #0
	bl FUN_0809bf88
_0809C27E:
	pop {r0}
	bx r0
	.align 2, 0
_0809C284: .4byte 0x0300013C
_0809C288: .4byte 0x000009FC

	thumb_func_start FUN_0809c28c
FUN_0809c28c: @ 0x0809C28C
	push {r4, lr}
	ldr r4, _0809C2C8 @ =0x0300013C
	ldr r1, [r4]
	cmp r1, #0
	beq _0809C2C0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C2C0
	adds r0, r1, #0
	bl FUN_0808d5cc
	ldr r0, [r4]
	bl FUN_0808d4dc
	ldr r1, [r4]
	ldr r2, _0809C2CC @ =0x000009FE
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0809C2C0
	adds r0, r1, #0
	bl FUN_0808d3d4
_0809C2C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C2C8: .4byte 0x0300013C
_0809C2CC: .4byte 0x000009FE

	thumb_func_start FUN_0809c2d0
FUN_0809c2d0: @ 0x0809C2D0
	push {r4, lr}
	ldr r4, _0809C30C @ =0x0300013C
	ldr r1, [r4]
	cmp r1, #0
	beq _0809C304
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C304
	adds r0, r1, #0
	bl FUN_0808d774
	ldr r0, [r4]
	bl FUN_0808d564
	ldr r1, [r4]
	ldr r2, _0809C310 @ =0x000009FE
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0809C304
	adds r0, r1, #0
	bl FUN_0808d3d4
_0809C304:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C30C: .4byte 0x0300013C
_0809C310: .4byte 0x000009FE

	thumb_func_start FUN_0809c314
FUN_0809c314: @ 0x0809C314
	push {r4, lr}
	ldr r4, _0809C33C @ =0x0300013C
	ldr r0, [r4]
	cmp r0, #0
	beq _0809C334
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809C334
	bl Script_GetValue
	ldr r1, [r4]
	ldr r2, _0809C340 @ =0x00000F3D
	adds r1, r1, r2
	strb r0, [r1]
_0809C334:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C33C: .4byte 0x0300013C
_0809C340: .4byte 0x00000F3D

	thumb_func_start FUN_0809c344
FUN_0809c344: @ 0x0809C344
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r0, _0809C368 @ =0x0300013C
	ldr r2, [r0]
	cmp r2, #0
	beq _0809C3B4
	ldr r1, _0809C36C @ =0x000009FE
	adds r0, r2, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _0809C3B4
	cmp r4, #0
	bge _0809C374
	ldr r4, _0809C370 @ =0x00000A06
	adds r0, r2, r4
	strh r1, [r0]
	b _0809C37A
	.align 2, 0
_0809C368: .4byte 0x0300013C
_0809C36C: .4byte 0x000009FE
_0809C370: .4byte 0x00000A06
_0809C374:
	ldr r1, _0809C39C @ =0x00000A06
	adds r0, r2, r1
	strh r4, [r0]
_0809C37A:
	ldr r4, _0809C3A0 @ =0x00000A08
	adds r0, r2, r4
	strh r5, [r0]
	ldr r1, _0809C3A4 @ =0x00000A0C
	adds r0, r2, r1
	strb r3, [r0]
	adds r4, #2
	adds r1, r2, r4
	movs r0, #0xb4
	strh r0, [r1]
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq _0809C3AC
	ldr r0, _0809C3A8 @ =0x00000A0D
	adds r1, r2, r0
	movs r0, #6
	b _0809C3B2
	.align 2, 0
_0809C39C: .4byte 0x00000A06
_0809C3A0: .4byte 0x00000A08
_0809C3A4: .4byte 0x00000A0C
_0809C3A8: .4byte 0x00000A0D
_0809C3AC:
	ldr r4, _0809C3BC @ =0x00000A0D
	adds r1, r2, r4
	movs r0, #0
_0809C3B2:
	strb r0, [r1]
_0809C3B4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C3BC: .4byte 0x00000A0D

	thumb_func_start FUN_0809c3c0
FUN_0809c3c0: @ 0x0809C3C0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0809C3E4 @ =0x0300013C
	ldr r3, [r0]
	cmp r3, #0
	beq _0809C424
	ldr r1, _0809C3E8 @ =0x000009FE
	adds r0, r3, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _0809C424
	cmp r4, #0
	bge _0809C3F0
	ldr r4, _0809C3EC @ =0x00000A0E
	adds r0, r3, r4
	strh r1, [r0]
	b _0809C3F6
	.align 2, 0
_0809C3E4: .4byte 0x0300013C
_0809C3E8: .4byte 0x000009FE
_0809C3EC: .4byte 0x00000A0E
_0809C3F0:
	ldr r1, _0809C414 @ =0x00000A0E
	adds r0, r3, r1
	strh r4, [r0]
_0809C3F6:
	movs r4, #0xa1
	lsls r4, r4, #4
	adds r0, r3, r4
	strh r5, [r0]
	ldr r0, _0809C418 @ =0x00000A12
	adds r1, r3, r0
	movs r0, #0xb4
	strh r0, [r1]
	cmp r2, #0
	beq _0809C41C
	adds r4, #4
	adds r1, r3, r4
	movs r0, #6
	b _0809C422
	.align 2, 0
_0809C414: .4byte 0x00000A0E
_0809C418: .4byte 0x00000A12
_0809C41C:
	ldr r0, _0809C42C @ =0x00000A14
	adds r1, r3, r0
	movs r0, #0
_0809C422:
	strb r0, [r1]
_0809C424:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C42C: .4byte 0x00000A14

	thumb_func_start FUN_0809c430
FUN_0809c430: @ 0x0809C430
	push {lr}
	ldr r0, _0809C458 @ =0x0300013C
	ldr r1, [r0]
	cmp r1, #0
	beq _0809C452
	ldr r2, _0809C45C @ =0x000009FE
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0809C452
	ldr r0, _0809C460 @ =0x00000A22
	adds r1, r1, r0
	movs r0, #4
	strh r0, [r1]
_0809C452:
	pop {r0}
	bx r0
	.align 2, 0
_0809C458: .4byte 0x0300013C
_0809C45C: .4byte 0x000009FE
_0809C460: .4byte 0x00000A22

	thumb_func_start FUN_0809c464
FUN_0809c464: @ 0x0809C464
	push {r4, lr}
	ldr r4, _0809C4C0 @ =0x0300013C
	ldr r2, [r4]
	cmp r2, #0
	beq _0809C4E8
	ldr r0, _0809C4C4 @ =0x03002BE0
	ldr r1, [r0]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r2, r3
	str r1, [r0]
	cmp r1, #0
	beq _0809C4E8
	adds r0, r2, #0
	bl FUN_0808d774
	ldr r0, [r4]
	bl FUN_0808d564
	ldr r0, [r4]
	bl FUN_0808d5cc
	ldr r0, [r4]
	bl FUN_0808d4dc
	ldr r0, _0809C4C8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0809C4D0
	ldr r1, [r4]
	ldr r2, _0809C4CC @ =0x000009FE
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809C4B6
	adds r0, r1, #0
	bl FUN_0808e224
_0809C4B6:
	ldr r0, [r4]
	bl FUN_0808d39c
	b _0809C4E8
	.align 2, 0
_0809C4C0: .4byte 0x0300013C
_0809C4C4: .4byte 0x03002BE0
_0809C4C8: .4byte 0x030047A4
_0809C4CC: .4byte 0x000009FE
_0809C4D0:
	ldr r1, [r4]
	ldr r3, _0809C4F0 @ =0x000009FE
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809C4E8
	adds r0, r1, #0
	bl FUN_0808d3d4
	ldr r0, [r4]
	bl FUN_0808ce98
_0809C4E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C4F0: .4byte 0x000009FE

	thumb_func_start FUN_0809c4f4
FUN_0809c4f4: @ 0x0809C4F4
	push {r4, lr}
	ldr r0, _0809C534 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	beq _0809C52C
	ldr r1, _0809C538 @ =0x000009FC
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809C52C
	adds r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0809C52C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xe0
	movs r3, #0x90
	bl FUN_0808c95c
	ldr r1, _0809C53C @ =0x00000D99
	adds r0, r4, r1
	movs r1, #6
	strb r1, [r0]
	ldr r0, _0809C540 @ =0x00000382
	bl PlaySound_082406e0
_0809C52C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C534: .4byte 0x0300013C
_0809C538: .4byte 0x000009FC
_0809C53C: .4byte 0x00000D99
_0809C540: .4byte 0x00000382

	thumb_func_start FUN_0809c544
FUN_0809c544: @ 0x0809C544
	push {lr}
	adds r1, r0, #0
	ldr r0, _0809C578 @ =0x0300013C
	ldr r2, [r0]
	cmp r2, #0
	beq _0809C572
	ldr r3, _0809C57C @ =0x00000A9C
	adds r0, r2, r3
	str r1, [r0]
	ldr r1, _0809C580 @ =0x00000A97
	adds r0, r2, r1
	movs r3, #1
	strb r3, [r0]
	ldr r0, _0809C584 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809C572
	ldr r1, _0809C588 @ =0x00000A98
	adds r0, r2, r1
	strb r3, [r0]
_0809C572:
	pop {r0}
	bx r0
	.align 2, 0
_0809C578: .4byte 0x0300013C
_0809C57C: .4byte 0x00000A9C
_0809C580: .4byte 0x00000A97
_0809C584: .4byte 0x030047A4
_0809C588: .4byte 0x00000A98

	thumb_func_start FUN_0809c58c
FUN_0809c58c: @ 0x0809C58C
	push {r4, lr}
	ldr r0, _0809C5C8 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	beq _0809C5C0
	ldr r1, _0809C5CC @ =0x00000A9C
	adds r0, r4, r1
	movs r3, #0
	str r3, [r0]
	ldr r0, _0809C5D0 @ =0x00000AA8
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809C5D4 @ =0x00000B08
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0809C5D8 @ =0x00000A97
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
_0809C5C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C5C8: .4byte 0x0300013C
_0809C5CC: .4byte 0x00000A9C
_0809C5D0: .4byte 0x00000AA8
_0809C5D4: .4byte 0x00000B08
_0809C5D8: .4byte 0x00000A97

	thumb_func_start FUN_0809c5dc
FUN_0809c5dc: @ 0x0809C5DC
	push {lr}
	ldr r0, _0809C5F0 @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C5EC
	movs r1, #2
	bl FUN_0808abec
_0809C5EC:
	pop {r0}
	bx r0
	.align 2, 0
_0809C5F0: .4byte 0x0300013C

	thumb_func_start FUN_0809c5f4
FUN_0809c5f4: @ 0x0809C5F4
	push {r4, lr}
	ldr r0, _0809C62C @ =0x0300013C
	ldr r3, [r0]
	cmp r3, #0
	beq _0809C624
	movs r1, #0xa1
	lsls r1, r1, #4
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0xa
	strh r1, [r0]
	ldr r4, _0809C630 @ =0x00000A0E
	adds r0, r3, r4
	strh r1, [r0]
	ldr r0, _0809C634 @ =0x00000A12
	adds r1, r3, r0
	movs r0, #0xb4
	strh r0, [r1]
	ldr r1, _0809C638 @ =0x00000A14
	adds r0, r3, r1
	strb r2, [r0]
	adds r0, r3, #0
	bl FUN_0808ad5c
_0809C624:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C62C: .4byte 0x0300013C
_0809C630: .4byte 0x00000A0E
_0809C634: .4byte 0x00000A12
_0809C638: .4byte 0x00000A14

	thumb_func_start FUN_0809c63c
FUN_0809c63c: @ 0x0809C63C
	push {r4, lr}
	ldr r0, _0809C660 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	beq _0809C65A
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809C65A
	bl Script_GetValue
	ldr r2, _0809C664 @ =0x00003FA0
	adds r1, r4, r2
	strb r0, [r1]
_0809C65A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C660: .4byte 0x0300013C
_0809C664: .4byte 0x00003FA0

	thumb_func_start FUN_0809c668
FUN_0809c668: @ 0x0809C668
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r2, _0809C6AC @ =0x00000283
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809C6BC
	ldr r0, _0809C6B0 @ =0x000009EE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _0809C6B4 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0809C6BC
	ldr r1, _0809C6B8 @ =0x00000C0C
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xa0
	adds r1, r4, #0
	movs r2, #0xc9
	movs r3, #1
	bl Sprite_SetSprite
	b _0809C6E4
	.align 2, 0
_0809C6AC: .4byte 0x00000283
_0809C6B0: .4byte 0x000009EE
_0809C6B4: .4byte 0x0000FFFF
_0809C6B8: .4byte 0x00000C0C
_0809C6BC:
	ldr r2, _0809C704 @ =0x00000C0C
	adds r0, r5, r2
	adds r4, r5, #0
	adds r4, #0xa0
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
_0809C6E4:
	ldr r1, _0809C708 @ =0x00000DA4
	adds r0, r5, r1
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r1, r5, r2
	ldr r1, [r1]
	adds r2, #0x94
	adds r1, r1, r2
	ldrb r2, [r1]
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C704: .4byte 0x00000C0C
_0809C708: .4byte 0x00000DA4

	thumb_func_start FUN_0809c70c
FUN_0809c70c: @ 0x0809C70C
	push {r4, lr}
	ldr r0, _0809C738 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r4, r0, r1
	cmp r0, #0
	bne _0809C71E
	movs r4, #0
_0809C71E:
	movs r0, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_0808a420
	adds r1, r0, #0
	movs r2, #4
_0809C72C:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0809C740
	ldr r3, _0809C73C @ =0x0000E0C0
	b _0809C766
	.align 2, 0
_0809C738: .4byte 0x03002C68
_0809C73C: .4byte 0x0000E0C0
_0809C740:
	cmp r0, #1
	bne _0809C74C
	ldr r3, _0809C748 @ =0x0000E0C3
	b _0809C766
	.align 2, 0
_0809C748: .4byte 0x0000E0C3
_0809C74C:
	cmp r0, #2
	bne _0809C758
	ldr r3, _0809C754 @ =0x0000E0C2
	b _0809C766
	.align 2, 0
_0809C754: .4byte 0x0000E0C2
_0809C758:
	cmp r0, #3
	bne _0809C764
	ldr r3, _0809C760 @ =0x0000E0C1
	b _0809C766
	.align 2, 0
_0809C760: .4byte 0x0000E0C1
_0809C764:
	ldr r3, _0809C77C @ =0x0000E0C4
_0809C766:
	adds r0, r3, #0
	strh r0, [r1]
	adds r1, #2
	adds r4, #1
	subs r2, #1
	cmp r2, #0
	bge _0809C72C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809C77C: .4byte 0x0000E0C4

	thumb_func_start FUN_0809c780
FUN_0809c780: @ 0x0809C780
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	movs r0, #0
	bl FUN_0808a420
	adds r2, r0, #0
	cmp r4, #1
	bne _0809C7A0
	ldr r3, _0809C79C @ =0x0000029F
	b _0809C7F6
	.align 2, 0
_0809C79C: .4byte 0x0000029F
_0809C7A0:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809C7EC
	ldr r3, _0809C7E4 @ =0x00000A04
	adds r0, r5, r3
	ldrh r0, [r0]
	ldr r3, _0809C7E8 @ =0x0000029F
	cmp r0, #0x24
	bls _0809C7CA
	subs r3, #0xa4
	cmp r0, #0x2c
	bls _0809C7CA
	cmp r0, #0x34
	bhi _0809C7CA
	subs r3, #0x84
_0809C7CA:
	ldr r0, _0809C7E4 @ =0x00000A04
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0809C7F6
	movs r0, #0
	strh r0, [r1]
	b _0809C7F6
	.align 2, 0
_0809C7E4: .4byte 0x00000A04
_0809C7E8: .4byte 0x0000029F
_0809C7EC:
	ldr r3, _0809C818 @ =0x00000A04
	adds r1, r5, r3
	movs r0, #0x34
	strh r0, [r1]
	ldr r3, _0809C81C @ =0x00000177
_0809C7F6:
	ldr r1, _0809C820 @ =0x03004404
	ldrh r0, [r1]
	cmp r0, r3
	beq _0809C800
	strh r3, [r1]
_0809C800:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x18]
	ldr r0, _0809C824 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809C828
	movs r0, #0
	b _0809C82E
	.align 2, 0
_0809C818: .4byte 0x00000A04
_0809C81C: .4byte 0x00000177
_0809C820: .4byte 0x03004404
_0809C824: .4byte 0x03002C68
_0809C828:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_0809C82E:
	adds r1, r0, #0
	ldr r3, _0809C870 @ =0x0000D05C
	adds r0, r3, #0
	strh r0, [r2]
	adds r2, #2
	movs r0, #0
	cmp r0, r1
	bge _0809C850
	ldr r0, _0809C874 @ =0x0000D05D
	adds r3, r0, #0
	adds r0, r1, #0
_0809C844:
	strh r3, [r2]
	adds r2, #2
	subs r0, #1
	cmp r0, #0
	bne _0809C844
	adds r0, r1, #0
_0809C850:
	cmp r0, #9
	bgt _0809C862
	ldr r3, _0809C878 @ =0x0000D05E
	adds r1, r3, #0
_0809C858:
	strh r1, [r2]
	adds r2, #2
	adds r0, #1
	cmp r0, #9
	ble _0809C858
_0809C862:
	ldr r1, _0809C87C @ =0x0000D05F
	adds r0, r1, #0
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809C870: .4byte 0x0000D05C
_0809C874: .4byte 0x0000D05D
_0809C878: .4byte 0x0000D05E
_0809C87C: .4byte 0x0000D05F

	thumb_func_start FUN_0809c880
FUN_0809c880: @ 0x0809C880
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0809C8E0
	adds r1, #0x1e
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _0809C8E0
	cmp r0, #2
	bhi _0809C8E0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a768
	adds r0, r4, #0
	movs r1, #0
	movs r2, #9
	movs r3, #0x12
	bl FUN_0809c780
	adds r0, r4, #0
	bl FUN_0808afac
	adds r0, r4, #0
	bl FUN_0808ad5c
	adds r0, r4, #0
	bl FUN_0809c668
	adds r0, r4, #0
	bl FUN_0809c70c
	adds r0, r4, #0
	bl FUN_0808b1bc
_0809C8E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809c8e8
FUN_0809c8e8: @ 0x0809C8E8
	push {lr}
	adds r2, r0, #0
	ldr r0, _0809C91C @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0809C914
	ldr r1, _0809C920 @ =0x000009DF
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r1, _0809C924 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r2, r3
	str r1, [r0]
	adds r0, r2, #0
	bl FUN_0809c880
_0809C914:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_0809C91C: .4byte 0x030044BC
_0809C920: .4byte 0x000009DF
_0809C924: .4byte 0x03002BE0

	thumb_func_start FUN_0809c928
FUN_0809c928: @ 0x0809C928
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808cf50
	adds r0, r4, #0
	bl FUN_0808cffc
	ldr r1, _0809C954 @ =0x00000C0C
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r0, _0809C958 @ =0x00000DA4
	adds r4, r4, r0
	adds r0, r4, #0
	bl FUN_0822f1c0
	ldr r1, _0809C95C @ =0x0300013C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809C954: .4byte 0x00000C0C
_0809C958: .4byte 0x00000DA4
_0809C95C: .4byte 0x0300013C

	thumb_func_start FUN_0809c960
FUN_0809c960: @ 0x0809C960
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r2, _0809C9F8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #8
	orrs r0, r1
	ldr r1, _0809C9FC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x88
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov sb, r0
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r1, _0809CA00 @ =0x00000C0C
	adds r6, r5, r1
	movs r0, #0xa0
	adds r0, r0, r5
	mov sl, r0
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r6, #0
	mov r1, sl
	movs r2, #0xb6
	movs r3, #0x10
	bl FUN_0822f3fc
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0808ba0c
	movs r1, #0xd8
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x88
	mov r1, sb
	strh r0, [r1, #2]
	strh r4, [r1, #4]
	ldr r0, _0809CA04 @ =0x00000DA4
	adds r5, r5, r0
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809C9F8: .4byte 0xFFFF0000
_0809C9FC: .4byte 0x0000FFFF
_0809CA00: .4byte 0x00000C0C
_0809CA04: .4byte 0x00000DA4

	thumb_func_start FUN_0809ca08
FUN_0809ca08: @ 0x0809CA08
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0809CABC @ =0x000009FE
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	ldr r0, _0809CAC0 @ =0x0000C091
	ldr r1, _0809CAC4 @ =0x0000A413
	bl GetFile
	str r0, [r5, #0x18]
	ldr r0, _0809CAC8 @ =0x000092B3
	ldr r1, _0809CACC @ =0x0000EFDA
	bl GetFile
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r5, #0x30]
	ldr r1, [r5, #0x18]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0808a3c4
	ldr r6, _0809CAD0 @ =0x00000A2A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r7, _0809CAD4 @ =0x0000CB05
	mov r8, r7
	ldr r1, _0809CAD8 @ =0x00005D04
	mov r0, r8
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809CAB0
	adds r0, r5, #0
	adds r0, #0xa0
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r6, r7}
	stm r2!, {r4, r6, r7}
	ldm r1!, {r4, r6, r7}
	stm r2!, {r4, r6, r7}
	ldm r1!, {r4, r6}
	stm r2!, {r4, r6}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	ldr r1, _0809CADC @ =0x0000B343
	mov r0, r8
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809CAB0
	adds r0, r5, #0
	adds r0, #0x60
	adds r1, r3, #0
	ldm r1!, {r2, r4, r7}
	stm r0!, {r2, r4, r7}
	ldm r1!, {r2, r6, r7}
	stm r0!, {r2, r6, r7}
	ldm r1!, {r4, r6}
	stm r0!, {r4, r6}
	adds r0, r5, #0
	adds r0, #0x60
	adds r1, r3, #0
	bl OpenSpriteSetFile
	adds r0, r5, #0
	bl FUN_0808cf64
	adds r0, r5, #0
	bl FUN_0808d01c
	adds r0, r5, #0
	bl FUN_0809c960
_0809CAB0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809CABC: .4byte 0x000009FE
_0809CAC0: .4byte 0x0000C091
_0809CAC4: .4byte 0x0000A413
_0809CAC8: .4byte 0x000092B3
_0809CACC: .4byte 0x0000EFDA
_0809CAD0: .4byte 0x00000A2A
_0809CAD4: .4byte 0x0000CB05
_0809CAD8: .4byte 0x00005D04
_0809CADC: .4byte 0x0000B343

	thumb_func_start FUN_0809cae0
FUN_0809cae0: @ 0x0809CAE0
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0
	bl SetBGPrioDirect
	ldr r0, _0809CAFC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809CB00
	movs r0, #1
	rsbs r0, r0, #0
	b _0809CB04
	.align 2, 0
_0809CAFC: .4byte 0x03002C68
_0809CB00:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_0809CB04:
	ldr r3, _0809CB5C @ =0x000009DF
	adds r2, r4, r3
	movs r1, #0
	strb r0, [r2]
	adds r3, #0x1d
	adds r0, r4, r3
	strh r1, [r0]
	ldrb r0, [r2]
	ldr r1, _0809CB60 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	str r1, [r0]
	adds r0, r4, #0
	bl FUN_0809bd14
	adds r0, r4, #0
	bl FUN_0809ca08
	adds r0, r4, #0
	bl FUN_0809c880
	ldr r3, _0809CB64 @ =0x00000A9A
	adds r1, r4, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, _0809CB68 @ =0x00000A9B
	adds r1, r4, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r2, _0809CB6C @ =0x000009FF
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0809CB70 @ =0x0300013C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809CB5C: .4byte 0x000009DF
_0809CB60: .4byte 0x03002BE0
_0809CB64: .4byte 0x00000A9A
_0809CB68: .4byte 0x00000A9B
_0809CB6C: .4byte 0x000009FF
_0809CB70: .4byte 0x0300013C

	thumb_func_start EntityCC28_Create_0809cb74
EntityCC28_Create_0809cb74: @ 0x0809CB74
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809CBB4 @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	bne _0809CBCA
	ldr r1, _0809CBB8 @ =0x0000405C
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809CBC8
	ldr r1, _0809CBBC @ =FUN_0809c8e8
	ldr r2, _0809CBC0 @ =FUN_0809c928
	bl SetEntityRoutine
	ldr r1, _0809CBC4 @ =0x000009FA
	adds r0, r4, r1
	strh r5, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0809cae0
	cmp r0, #0
	bge _0809CBC8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809CBCA
	.align 2, 0
_0809CBB4: .4byte 0x0300013C
_0809CBB8: .4byte 0x0000405C
_0809CBBC: .4byte FUN_0809c8e8
_0809CBC0: .4byte FUN_0809c928
_0809CBC4: .4byte 0x000009FA
_0809CBC8:
	adds r0, r4, #0
_0809CBCA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809cbd0
FUN_0809cbd0: @ 0x0809CBD0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809CC00 @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	str r1, [r0]
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0809CBF2
	adds r0, r4, #0
	bl _call_via_r1
_0809CBF2:
	adds r0, r4, #0
	bl FUN_0808c7c4
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809CC00: .4byte 0x03002BE0

	thumb_func_start FUN_0809cc04
FUN_0809cc04: @ 0x0809CC04
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808dda4
	adds r0, r4, #0
	bl FUN_0808cf50
	adds r0, r4, #0
	bl FUN_0808cacc
	adds r0, r4, #0
	bl FUN_0809b430
	adds r0, r4, #0
	bl FUN_0808cffc
	ldr r1, _0809CC3C @ =0x03002C14
	ldr r0, _0809CC40 @ =0x00000F56
	adds r4, r4, r0
	ldrb r0, [r4]
	strh r0, [r1]
	ldr r1, _0809CC44 @ =0x0300013C
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809CC3C: .4byte 0x03002C14
_0809CC40: .4byte 0x00000F56
_0809CC44: .4byte 0x0300013C

	thumb_func_start FUN_0809cc48
FUN_0809cc48: @ 0x0809CC48
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0
	bl SetBGPrioDirect
	ldr r0, _0809CCBC @ =0x000009FC
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0809CCC0 @ =0x03002C14
	ldrh r1, [r0]
	ldr r2, _0809CCC4 @ =0x00000F56
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0809CCC8 @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _0809CCCC @ =0x08DAA6D8
	movs r2, #0xff
	lsls r2, r2, #6
	adds r1, r4, r2
	bl FUN_08242a38
	adds r0, r4, #0
	bl FUN_0809bed8
	adds r0, r4, #0
	bl FUN_0809bf88
	adds r0, r4, #0
	bl FUN_0809c010
	adds r0, r4, #0
	bl FUN_0809bd14
	adds r0, r4, #0
	bl FUN_0808dddc
	adds r0, r4, #0
	bl FUN_0809b468
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CCD4
	bl Script_GetValue
	ldr r2, _0809CCD0 @ =0x00004028
	adds r1, r4, r2
	str r0, [r1]
	b _0809CCDA
	.align 2, 0
_0809CCBC: .4byte 0x000009FC
_0809CCC0: .4byte 0x03002C14
_0809CCC4: .4byte 0x00000F56
_0809CCC8: .4byte 0x03002BE0
_0809CCCC: .4byte 0x08DAA6D8
_0809CCD0: .4byte 0x00004028
_0809CCD4:
	ldr r2, _0809CCF4 @ =0x00004028
	adds r0, r4, r2
	str r1, [r0]
_0809CCDA:
	movs r0, #0x56
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CCFC
	bl Script_GetValue
	ldr r2, _0809CCF8 @ =0x0000401F
	adds r1, r4, r2
	strb r0, [r1]
	b _0809CD02
	.align 2, 0
_0809CCF4: .4byte 0x00004028
_0809CCF8: .4byte 0x0000401F
_0809CCFC:
	ldr r2, _0809CD1C @ =0x0000401F
	adds r0, r4, r2
	strb r1, [r0]
_0809CD02:
	movs r0, #0x52
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CD24
	bl Script_GetValue
	ldr r2, _0809CD20 @ =0x00003FB4
	adds r1, r4, r2
	str r0, [r1]
	b _0809CD2A
	.align 2, 0
_0809CD1C: .4byte 0x0000401F
_0809CD20: .4byte 0x00003FB4
_0809CD24:
	ldr r2, _0809CD44 @ =0x00003FB4
	adds r0, r4, r2
	str r1, [r0]
_0809CD2A:
	movs r0, #0x44
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CD4C
	bl Script_GetValue
	ldr r2, _0809CD48 @ =0x00003FBC
	adds r1, r4, r2
	str r0, [r1]
	b _0809CD52
	.align 2, 0
_0809CD44: .4byte 0x00003FB4
_0809CD48: .4byte 0x00003FBC
_0809CD4C:
	ldr r2, _0809CD9C @ =0x00003FBC
	adds r0, r4, r2
	str r1, [r0]
_0809CD52:
	movs r0, #6
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	ldr r2, _0809CDA0 @ =0x00004014
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #4
	movs r1, #6
	movs r2, #0x16
	movs r3, #6
	bl FUN_0804a084
	ldr r2, _0809CDA4 @ =0x00004018
	adds r1, r4, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_0808d0c0
	ldr r0, _0809CDA8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0809CDB0
	adds r0, r4, #0
	bl FUN_0808e224
	ldr r1, _0809CDAC @ =FUN_0808e400
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0809CDBE
	.align 2, 0
_0809CD9C: .4byte 0x00003FBC
_0809CDA0: .4byte 0x00004014
_0809CDA4: .4byte 0x00004018
_0809CDA8: .4byte 0x030047A4
_0809CDAC: .4byte FUN_0808e400
_0809CDB0:
	adds r0, r4, #0
	bl FUN_0808ce98
	ldr r1, _0809CDF0 @ =FUN_0808cf14
	adds r0, r4, #0
	bl FUN_0808a33c
_0809CDBE:
	adds r0, r4, #0
	bl FUN_0808cb00
	ldr r0, _0809CDF4 @ =0x00000A99
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _0809CDF8 @ =0x00000A9A
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, _0809CDFC @ =0x00000A9B
	adds r1, r4, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	subs r2, #0x9b
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0809CE00 @ =0x0300013C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809CDF0: .4byte FUN_0808cf14
_0809CDF4: .4byte 0x00000A99
_0809CDF8: .4byte 0x00000A9A
_0809CDFC: .4byte 0x00000A9B
_0809CE00: .4byte 0x0300013C

	thumb_func_start EntityCC28_Create_0809ce04
EntityCC28_Create_0809ce04: @ 0x0809CE04
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809CE44 @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	bne _0809CE5A
	ldr r1, _0809CE48 @ =0x0000405C
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809CE58
	ldr r1, _0809CE4C @ =FUN_0809cbd0
	ldr r2, _0809CE50 @ =FUN_0809cc04
	bl SetEntityRoutine
	ldr r1, _0809CE54 @ =0x000009FA
	adds r0, r4, r1
	strh r5, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0809cc48
	cmp r0, #0
	bge _0809CE58
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809CE5A
	.align 2, 0
_0809CE44: .4byte 0x0300013C
_0809CE48: .4byte 0x0000405C
_0809CE4C: .4byte FUN_0809cbd0
_0809CE50: .4byte FUN_0809cc04
_0809CE54: .4byte 0x000009FA
_0809CE58:
	adds r0, r4, #0
_0809CE5A:
	pop {r4, r5}
	pop {r1}
	bx r1

