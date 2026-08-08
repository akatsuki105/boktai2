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
	ldr r1, _08091DDC @ =gItemDB
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
	ldr r1, _08091DDC @ =gItemDB
	lsls r0, r4, #4
	adds r0, r0, r1
	ldrh r1, [r0, #6]
	movs r0, #8
	ands r0, r1
	b _08091E22
	.align 2, 0
_08091DDC: .4byte gItemDB
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
	ldr r1, _08091F4C @ =gItemDB
	adds r0, r1, #0
	adds r0, #0x80
	ldrh r6, [r0, #6]
	ldrh r2, [r0, #8]
	adds r3, r1, #0
	b _08091FC0
	.align 2, 0
_08091F4C: .4byte gItemDB
_08091F50:
	ldr r1, _08091FA4 @ =gItemDB
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
_08091FA4: .4byte gItemDB
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
	ldr r1, _08092050 @ =gItemDB
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrh r4, [r0, #4]
	cmp r4, #0
	bne _08092054
_0809204C:
	movs r0, #0xcf
	b _0809206A
	.align 2, 0
_08092050: .4byte gItemDB
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
	bl FUN_0822f3cc
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
	bl FUN_08231660
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
	bl FUN_08231978
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
	bl FUN_08231978
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
	ldr r1, _080921DC @ =gItemDB
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
_080921DC: .4byte gItemDB
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	ldr r1, _08093F60 @ =gItemDB
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
_08093F60: .4byte gItemDB
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
	ldr r0, _08093FF4 @ =gItemDB
	lsls r1, r5, #4
	adds r1, r1, r0
	ldrh r0, [r1, #6]
	cmp r0, #2
	bne _08093FF8
	adds r0, r4, #0
	bl FUN_08092cac
	b _08094064
	.align 2, 0
_08093FF4: .4byte gItemDB
_08093FF8:
	ldrh r1, [r1, #6]
	adds r0, r4, #0
	bl FUN_08092c7c
	b _08094064
_08094002:
	ldr r0, _08094014 @ =gItemDB
	lsls r1, r5, #4
	adds r1, r1, r0
	ldrh r1, [r1, #6]
	adds r0, r4, #0
	bl FUN_080933b4
	b _08094064
	.align 2, 0
_08094014: .4byte gItemDB
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_08231660
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
	bl FUN_08231978
	bl FUN_08049e30
	movs r6, #0
	ldrb r0, [r7, #0x18]
	cmp r0, #0
	beq _08094D9C
	adds r0, #0x42
	add r0, r8
	bl FUN_08231978
	adds r1, r0, #0
	movs r0, #0
	bl FUN_08049eb0
	b _08094DAC
_08094D9C:
	adds r0, r4, #0
	adds r0, #0x84
	bl FUN_08231978
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
	bl FUN_08231978
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
	bl FUN_08231978
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	ldr r1, _08095480 @ =gWeaponDB
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
_08095480: .4byte gWeaponDB
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	ldr r1, _080957A4 @ =gWeaponDB
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
_080957A4: .4byte gWeaponDB
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	ldr r1, _08096830 @ =gArmorDB
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
_08096830: .4byte gArmorDB
_08096834: .4byte 0x00003AEB
_08096838:
	movs r0, #1
	str r0, [sp, #0x34]
	movs r0, #0
	ldrsb r0, [r1, r0]
	lsls r0, r0, #3
	ldr r1, _08096878 @ =gArmorDB
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
_08096878: .4byte gArmorDB
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
	bl FUN_0822f3cc
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
	ldr r0, _0809698C @ =gArmorDB
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
_0809698C: .4byte gArmorDB
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	ldr r0, _08096AEC @ =gArmorDB
	lsls r4, r5, #3
	adds r4, r4, r0
	ldrb r1, [r4, #1]
	movs r0, #0
	bl FUN_08049e6c
	ldrb r1, [r4, #2]
	movs r0, #1
	bl FUN_08049e6c
	ldr r0, [r6, #0x48]
	bl FUN_08231660
	adds r0, #0x25
	adds r0, r0, r5
	bl FUN_08231978
	bl FUN_08049e30
_08096ADC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096AE4: .4byte 0x0000204C
_08096AE8: .4byte 0x00002044
_08096AEC: .4byte gArmorDB

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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	ldr r0, _08096D84 @ =gArmorDB
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
_08096D84: .4byte gArmorDB
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
_08096F90:
	.byte 0x00, 0xB5, 0x01, 0x1C, 0x03, 0x4A, 0x88, 0x18, 0x60, 0x31, 0xA0, 0xF1, 0x97, 0xF9, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0x44, 0x14, 0x00, 0x00

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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	ldr r2, _080977A0 @ =gArmorDB
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
_080977A0: .4byte gArmorDB

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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_08231660
	adds r0, #0x12
	adds r0, r0, r5
	bl FUN_08231978
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
	adds r2, r4, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x18]
	adds r1, r7, #0
	movs r3, #1
	bl FUN_0822f3cc
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
	bl FUN_0807a8c0
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
	bl FUN_0822f3cc
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
	bl FUN_0807a8c0
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
	ldr r3, _08099D1C @ =0x00001D44
	adds r0, r5, r3
	ldr r2, _08099D20 @ =0x0000400F
	adds r1, r5, r2
	ldrb r2, [r1]
	adds r2, r2, r6
	adds r1, r4, #0
	movs r3, #1
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822ba50
	movs r0, #1
	movs r1, #1
	bl FUN_0822ba00
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
	bl FUN_082310cc
	bl FUN_0822b0d0
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
	bl FUN_0822ba50
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_082318ac
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
	bl FUN_082318ac
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
	bl FUN_0822f3cc
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
	bl FUN_0822b16c
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
	bl FUN_0822b16c
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
_0809BC90:
	.byte 0x40, 0xE0, 0x00, 0x00
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
	bl FUN_082310cc
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
	bl FUN_0822f284
	ldr r1, _0809BEB8 @ =0x00005D04
	adds r0, r5, #0
	bl FUN_082310cc
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
	bl FUN_0822f284
	ldr r1, _0809BEBC @ =0x00000312
	adds r0, r5, #0
	bl FUN_082310cc
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
	bl FUN_0822f284
	ldr r1, _0809BEC0 @ =0x000092F0
	adds r0, r5, #0
	bl FUN_082310cc
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
	bl FUN_0822f284
	ldr r1, _0809BEC4 @ =0x0000DE23
	adds r0, r5, #0
	bl FUN_082310cc
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
	bl FUN_0822f284
	ldr r1, _0809BEC8 @ =0x0000DFDE
	adds r0, r5, #0
	bl FUN_082310cc
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
	bl FUN_0822f284
	ldr r1, _0809BECC @ =0x0000E2DE
	adds r0, r5, #0
	bl FUN_082310cc
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
	bl FUN_0822f284
	ldr r1, _0809BED0 @ =0x0000D27A
	adds r0, r5, #0
	bl FUN_082310cc
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
	bl FUN_0822f284
	ldr r1, _0809BED4 @ =0x0000DCC1
	adds r0, r5, #0
	bl FUN_082310cc
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
	bl FUN_0822f284
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
	bl prepare_08231510
	cmp r0, #0
	beq _0809BEEC
	bl FUN_0823d340
	str r0, [r4, #0x40]
_0809BEEC:
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _0809BEFC
	bl FUN_0823d340
	str r0, [r4, #0x44]
_0809BEFC:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _0809BF0C
	bl FUN_0823d340
	str r0, [r4, #0x48]
_0809BF0C:
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _0809BF1C
	bl FUN_0823d340
	str r0, [r4, #0x4c]
_0809BF1C:
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _0809BF2C
	bl FUN_0823d340
	str r0, [r4, #0x50]
_0809BF2C:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _0809BF3C
	bl FUN_0823d340
	str r0, [r4, #0x54]
_0809BF3C:
	movs r0, #0x45
	bl prepare_08231510
	cmp r0, #0
	beq _0809BF4C
	bl FUN_0823d340
	str r0, [r4, #0x58]
_0809BF4C:
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _0809BF5C
	bl FUN_0823172c
	str r0, [r4, #0x5c]
_0809BF5C:
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0809BF78
	bl fetch_082316e4
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
	bl prepare_08231510
	cmp r0, #0
	beq _0809BFB0
	movs r4, #0
	ldr r0, _0809BFAC @ =0x00000F58
	adds r5, r6, r0
_0809BF9C:
	bl fetch_082316e4
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
	bl prepare_08231510
	cmp r0, #0
	beq _0809C02C
	bl fetch_082316e4
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
_0809C040:
	.byte 0x05, 0x48, 0x00, 0x22, 0x02, 0x60, 0x05, 0x48, 0x01, 0x21, 0x01, 0x80, 0x04, 0x48, 0x02, 0x80
	.byte 0x04, 0x48, 0x01, 0x80, 0x70, 0x47, 0x00, 0x00, 0x3C, 0x01, 0x00, 0x03, 0x14, 0x2C, 0x00, 0x03
	.byte 0x10, 0x2C, 0x00, 0x03, 0x18, 0x2C, 0x00, 0x03

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
	bl FUN_0822c40c
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

	thumb_func_start FUN_0809c22c
FUN_0809c22c: @ 0x0809C22C
	push {lr}
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _0809C240
	bl fetch_082316e4
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
	bl prepare_08231510
	cmp r0, #0
	beq _0809C334
	bl fetch_082316e4
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
	bl prepare_08231510
	cmp r0, #0
	beq _0809C65A
	bl fetch_082316e4
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
	bl FUN_0822f3cc
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
_0809C8E8:
	.byte 0x00, 0xB5, 0x02, 0x1C, 0x0B, 0x48, 0x00, 0x68
	.byte 0x01, 0x21, 0x08, 0x40, 0x00, 0x28, 0x0D, 0xD1, 0x09, 0x49, 0x50, 0x18, 0x00, 0x78, 0x09, 0x49
	.byte 0x80, 0x00, 0x40, 0x18, 0x01, 0x68, 0x9E, 0x23, 0x1B, 0x01, 0xD0, 0x18, 0x01, 0x60, 0x10, 0x1C
	.byte 0xFF, 0xF7, 0xB6, 0xFF, 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00, 0xBC, 0x44, 0x00, 0x03
	.byte 0xDF, 0x09, 0x00, 0x00, 0xE0, 0x2B, 0x00, 0x03

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
	bl FUN_082310cc
	str r0, [r5, #0x18]
	ldr r0, _0809CAC8 @ =0x000092B3
	ldr r1, _0809CACC @ =0x0000EFDA
	bl FUN_082310cc
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
	bl FUN_082310cc
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
	bl FUN_0822f284
	ldr r1, _0809CADC @ =0x0000B343
	mov r0, r8
	bl FUN_082310cc
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
	bl FUN_0822f284
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
	bl FUN_0822ba00
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

	thumb_func_start FUN_0809cb74
FUN_0809cb74: @ 0x0809CB74
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
	ldr r1, _0809CBBC @ =0x0809C8E9
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
_0809CBBC: .4byte 0x0809C8E9
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
	bl FUN_0822ba00
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
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CCD4
	bl fetch_082316e4
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
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CCFC
	bl fetch_082316e4
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
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CD24
	bl fetch_082316e4
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
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0809CD4C
	bl fetch_082316e4
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

	thumb_func_start CreateUIState_0809ce04
CreateUIState_0809ce04: @ 0x0809CE04
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

	thumb_func_start FUN_0809ce60
FUN_0809ce60: @ 0x0809CE60
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, _0809CE80 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0809CE84
	adds r0, r2, #0
	adds r1, r3, #0
	bl CreateUIState_0809ce04
	b _0809CE8C
	.align 2, 0
_0809CE80: .4byte 0x030047A4
_0809CE84:
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0809cb74
_0809CE8C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ce90
FUN_0809ce90: @ 0x0809CE90
	ldr r3, _0809CEA0 @ =0x00000F8C
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _0809CEA4 @ =0x00000F72
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_0809CEA0: .4byte 0x00000F8C
_0809CEA4: .4byte 0x00000F72

	thumb_func_start FUN_0809cea8
FUN_0809cea8: @ 0x0809CEA8
	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809CEFC
	ldr r1, _0809CEF4 @ =0x00000E2B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809CF0A
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r6, #0x24]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _0809CEF8 @ =0x00000F4C
	adds r4, r6, r0
	adds r0, #0x2c
	adds r1, r6, r0
	adds r0, r4, #0
	bl FUN_08094d1c
	ldr r1, [r6, #0x24]
	adds r0, r4, #0
	bl FUN_08094d48
	b _0809CF8A
	.align 2, 0
_0809CEF4: .4byte 0x00000E2B
_0809CEF8: .4byte 0x00000F4C
_0809CEFC:
	ldr r0, _0809CF24 @ =0x00000E2B
	adds r4, r6, r0
	ldrb r0, [r4]
	bl GetWeaponID
	cmp r0, #0
	bne _0809CF28
_0809CF0A:
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _0809CF8A
	.align 2, 0
_0809CF24: .4byte 0x00000E2B
_0809CF28:
	ldrb r0, [r4]
	mov r1, sp
	bl FUN_08242b14
	movs r0, #0xe2
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x48
	mov r0, sp
	bl FUN_08094e70
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_0822f3cc
	movs r0, #1
	bl FUN_080477e4
	ldr r0, [r6, #0x24]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	ldr r0, _0809CF94 @ =0x00000F78
	adds r1, r6, r0
	mov r0, sp
	bl FUN_08094d1c
	ldr r1, [r6, #0x24]
	mov r0, sp
	bl FUN_08094d48
_0809CF8A:
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809CF94: .4byte 0x00000F78

	thumb_func_start FUN_0809cf98
FUN_0809cf98: @ 0x0809CF98
	push {lr}
	bl GetWeaponID
	cmp r0, #0
	beq _0809CFB6
	cmp r0, #0x3a
	beq _0809CFB6
	cmp r0, #0x3e
	beq _0809CFB6
	cmp r0, #0x3f
	beq _0809CFB6
	cmp r0, #0x40
	beq _0809CFB6
	cmp r0, #0x41
	bne _0809CFBA
_0809CFB6:
	movs r0, #0
	b _0809CFBC
_0809CFBA:
	movs r0, #1
_0809CFBC:
	pop {r1}
	bx r1

	thumb_func_start FUN_0809cfc0
FUN_0809cfc0: @ 0x0809CFC0
	push {r4, lr}
	adds r4, r1, #0
	ldrb r1, [r4, #1]
	cmp r1, #0
	blt _0809D004
	cmp r1, #2
	ble _0809CFD4
	cmp r1, #4
	beq _0809CFEC
	b _0809D004
_0809CFD4:
	movs r1, #0xf8
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0x63
	asrs r0, r0, #1
	ldrb r2, [r4, #4]
	adds r0, r0, r2
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	b _0809D006
_0809CFEC:
	movs r0, #0x28
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	subs r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	lsls r0, r0, #1
	b _0809D006
_0809D004:
	movs r0, #0
_0809D006:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809d00c
FUN_0809d00c: @ 0x0809D00C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	mov r8, r0
	movs r0, #0
	mov r1, sp
	adds r1, #0x24
	str r1, [sp, #0x40]
	movs r2, #0x28
	add r2, r8
	mov sb, r2
_0809D028:
	lsls r1, r0, #1
	lsls r2, r0, #2
	adds r7, r0, #1
	adds r0, #0x16
	adds r1, r1, r0
	ldr r0, [sp, #0x40]
	adds r6, r0, r2
	movs r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, #0xa8
	mov r1, r8
	adds r4, r0, r1
_0809D044:
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #1
	bl FUN_0822f3cc
	movs r0, #0
	str r0, [r6]
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D044
	adds r0, r7, #0
	cmp r0, #3
	ble _0809D028
	mov r2, r8
	ldr r0, [r2, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D0CC
	ldr r1, _0809D0C4 @ =0x00000F4C
	add r1, r8
	mov r0, r8
	bl FUN_0809cfc0
	ldr r1, [sp, #0x40]
	str r0, [r1, #0xc]
	movs r1, #0x64
	bl Div
	add r4, sp, #0x34
	str r0, [sp, #0x34]
	movs r1, #0x64
	muls r1, r0, r1
	ldr r2, [sp, #0x40]
	ldr r0, [r2, #0xc]
	subs r6, r0, r1
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	str r0, [r4, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r6, r1
	str r1, [r4, #8]
	ldr r6, _0809D0C8 @ =0x00000C48
	add r6, r8
	movs r5, #2
_0809D0AA:
	ldm r4!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl FUN_0822f3cc
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D0AA
	b _0809D21E
	.align 2, 0
_0809D0C4: .4byte 0x00000F4C
_0809D0C8: .4byte 0x00000C48
_0809D0CC:
	movs r7, #1
	rsbs r7, r7, #0
	movs r1, #0xf7
	lsls r1, r1, #4
	add r1, r8
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0809D162
	mov r1, sp
	bl FUN_08242b14
	mov r0, sp
	ldrb r0, [r0, #1]
	movs r7, #0
	cmp r0, #0
	beq _0809D0FC
	movs r7, #1
	cmp r0, #1
	beq _0809D0FC
	movs r7, #3
	cmp r0, #2
	bne _0809D0FC
	movs r7, #2
_0809D0FC:
	mov r0, r8
	mov r1, sp
	bl FUN_0809cfc0
	lsls r4, r7, #2
	ldr r1, [sp, #0x40]
	adds r4, r1, r4
	str r0, [r4]
	movs r1, #0x64
	bl Div
	add r5, sp, #0x34
	str r0, [sp, #0x34]
	movs r1, #0x64
	muls r1, r0, r1
	ldr r0, [r4]
	subs r6, r0, r1
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r6, r1
	str r1, [r5, #8]
	lsls r1, r7, #1
	adds r6, r5, #0
	adds r0, r7, #0
	adds r0, #0x16
	adds r1, r1, r0
	movs r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, #0xa8
	mov r2, r8
	adds r4, r0, r2
_0809D14A:
	ldm r6!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sb
	movs r3, #1
	bl FUN_0822f3cc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D14A
_0809D162:
	ldr r4, _0809D1AC @ =0x00000E2B
	add r4, r8
	ldrb r0, [r4]
	bl FUN_0809cf98
	cmp r0, #0
	beq _0809D21E
	ldrb r0, [r4]
	mov r1, sp
	bl FUN_08242b14
	mov r0, sp
	ldrb r0, [r0, #1]
	movs r1, #0
	mov sl, r1
	cmp r0, #0
	beq _0809D198
	movs r2, #1
	mov sl, r2
	cmp r0, #1
	beq _0809D198
	movs r1, #3
	mov sl, r1
	cmp r0, #2
	bne _0809D198
	movs r2, #2
	mov sl, r2
_0809D198:
	mov r0, r8
	mov r1, sp
	bl FUN_0809cfc0
	adds r5, r0, #0
	cmp r7, #0
	bge _0809D1B0
	movs r7, #0xa
	b _0809D1C6
	.align 2, 0
_0809D1AC: .4byte 0x00000E2B
_0809D1B0:
	lsls r0, r7, #2
	ldr r1, [sp, #0x40]
	adds r0, r1, r0
	ldr r0, [r0]
	movs r7, #0xa
	cmp r5, r0
	bgt _0809D1C6
	movs r7, #0
	cmp r5, r0
	bge _0809D1C6
	movs r7, #0x14
_0809D1C6:
	adds r0, r5, #0
	movs r1, #0x64
	bl Div
	add r4, sp, #0x34
	str r0, [sp, #0x34]
	movs r1, #0x64
	muls r0, r1, r0
	subs r6, r5, r0
	adds r0, r6, #0
	movs r1, #0xa
	bl Div
	str r0, [r4, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r6, r1
	str r1, [r4, #8]
	mov r2, sl
	lsls r1, r2, #1
	mov r0, sl
	adds r0, #0x16
	adds r1, r1, r0
	movs r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, #0xa8
	mov r1, r8
	adds r6, r0, r1
_0809D204:
	ldm r4!, {r2}
	adds r2, r2, r7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl FUN_0822f3cc
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D204
_0809D21E:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809d230
FUN_0809d230: @ 0x0809D230
	push {lr}
	bl FUN_08047864
	bl FUN_08049e5c
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809d240
FUN_0809d240: @ 0x0809D240
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	cmp r2, #0xf
	bgt _0809D264
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
	b _0809D26A
_0809D264:
	movs r0, #0x40
	strh r0, [r3]
	movs r0, #0x4c
_0809D26A:
	strh r0, [r3, #2]
	pop {r0}
	bx r0

	thumb_func_start FUN_0809d270
FUN_0809d270: @ 0x0809D270
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r1, _0809D2F0 @ =0x00000E2B
	adds r0, r5, r1
	ldrb r0, [r0]
	bl GetWeaponID
	str r0, [sp, #0x34]
	ldr r0, _0809D2F4 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	movs r1, #0xf7
	lsls r1, r1, #4
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	add r0, sp, #0xc
	bl FUN_0809d240
	add r4, sp, #0x1c
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_0809d240
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	add r6, sp, #0x34
	str r2, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r0, _0809D2F8 @ =0x00000E58
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _0809D2FC @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D2F0: .4byte 0x00000E2B
_0809D2F4: .4byte 0x000002DF
_0809D2F8: .4byte 0x00000E58
_0809D2FC: .4byte 0x0000038A

	thumb_func_start FUN_0809d300
FUN_0809d300: @ 0x0809D300
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r3, r6, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _0809D338
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xfa
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	b _0809D3C2
_0809D338:
	movs r1, #0xd6
	lsls r1, r1, #3
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D366
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r1, r6, #0
	adds r1, #0x48
	movs r2, #0x3c
	movs r3, #1
	bl FUN_0822f3cc
	b _0809D388
_0809D366:
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r4, r6, r0
	adds r5, r6, #0
	adds r5, #0x48
	movs r0, #0
	ldrsb r0, [r3, r0]
	bl GetWeaponID
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_0822f3cc
_0809D388:
	movs r2, #0x83
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r0, [r1]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r1]
	ldr r1, _0809D3CC @ =0x00000848
	adds r0, r6, r1
	movs r2, #0xf7
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl FUN_0809d240
	movs r0, #0xfa
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r2, #0xdd
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r0, [r1]
	ands r0, r4
_0809D3C2:
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D3CC: .4byte 0x00000848

	thumb_func_start FUN_0809d3d0
FUN_0809d3d0: @ 0x0809D3D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xed
	lsls r0, r0, #3
	adds r5, r6, r0
	adds r1, r6, #0
	adds r1, #0x28
	adds r0, r5, #0
	bl FUN_082372cc
	ldr r2, _0809D3FC @ =0x00000F74
	adds r1, r6, r2
	ldr r0, [r1]
	cmp r0, #0
	beq _0809D400
	subs r0, #1
	str r0, [r1]
	b _0809D792
	.align 2, 0
_0809D3FC: .4byte 0x00000F74
_0809D400:
	ldr r0, _0809D458 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809D468
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D418
	b _0809D574
_0809D418:
	ldr r3, _0809D45C @ =0x00000E2B
	adds r4, r6, r3
	ldrb r0, [r4]
	bl FUN_0809cf98
	cmp r0, #0
	bne _0809D428
	b _0809D574
_0809D428:
	ldrb r2, [r4]
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bne _0809D43A
	b _0809D574
_0809D43A:
	strb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r2, _0809D460 @ =0x00000F4C
	adds r1, r6, r2
	bl FUN_08242b14
	adds r0, r6, #0
	bl FUN_0809d270
	ldr r1, _0809D464 @ =FUN_0809d7a4
	adds r0, r6, #0
	bl FUN_0809ce90
	b _0809D792
	.align 2, 0
_0809D458: .4byte 0x030044E0
_0809D45C: .4byte 0x00000E2B
_0809D460: .4byte 0x00000F4C
_0809D464: .4byte FUN_0809d7a4
_0809D468:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809D55C
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r0, [r6, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	movs r3, #0xb0
	adds r3, r3, r6
	mov r8, r3
	cmp r0, #2
	beq _0809D51C
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0809D51C
	ldr r2, _0809D54C @ =0x00000F4C
	adds r4, r6, r2
	adds r1, r0, #0
	mov ip, r1
	ldr r0, _0809D550 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _0809D51C
	movs r3, #0xae
	lsls r3, r3, #1
	adds r5, r2, r3
	cmp r5, #0
	beq _0809D51C
	ldrb r0, [r4]
	strb r0, [r5, #0x1c]
	ldrb r0, [r4, #1]
	strb r0, [r5, #0x1d]
	ldrb r0, [r4, #2]
	strb r0, [r5, #0x1e]
	ldrb r0, [r4, #3]
	strb r0, [r5, #0x1f]
	ldrb r1, [r4, #4]
	adds r3, #0x20
	adds r0, r2, r3
	strb r1, [r0]
	ldrb r0, [r4, #5]
	adds r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	ldrh r0, [r4, #6]
	strh r0, [r5, #0x22]
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x24]
	ldrh r0, [r4, #0xa]
	strh r0, [r5, #0x26]
	movs r3, #0
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r2, r0
	ldr r1, _0809D554 @ =0x00000F58
	adds r2, r6, r1
_0809D4E6:
	adds r0, r7, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #0xb
	ble _0809D4E6
	adds r2, r5, #0
	adds r2, #0x34
	adds r1, r4, #0
	adds r1, #0x18
	movs r3, #2
_0809D4FE:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #1]
	ldrb r0, [r1, #2]
	strb r0, [r2, #2]
	ldrb r0, [r1, #3]
	strb r0, [r2, #3]
	adds r2, #4
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _0809D4FE
	mov r2, ip
	strb r2, [r5, #0x17]
_0809D51C:
	adds r0, r6, #0
	bl FUN_0809d230
	movs r3, #1
	mov r1, r8
	movs r2, #0x23
_0809D528:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809D528
	ldr r3, _0809D558 @ =0x00000F84
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r0, #0
	bne _0809D542
	b _0809D762
_0809D542:
	movs r1, #0
	bl FUN_082318ac
	b _0809D762
	.align 2, 0
_0809D54C: .4byte 0x00000F4C
_0809D550: .4byte 0x03002C68
_0809D554: .4byte 0x00000F58
_0809D558: .4byte 0x00000F84
_0809D55C:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0809D566
	b _0809D770
_0809D566:
	movs r0, #0xf7
	lsls r0, r0, #4
	adds r5, r6, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bge _0809D57E
_0809D574:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0809D792
_0809D57E:
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, [r6, #0x18]
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809D634
	ldr r2, _0809D628 @ =0x00000F4C
	adds r4, r6, r2
	ldrb r1, [r1, #0x17]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	mov ip, r1
	ldr r0, _0809D62C @ =0x03002C68
	ldr r2, [r0]
	mov sb, r0
	movs r3, #0xb0
	adds r3, r3, r6
	mov r8, r3
	cmp r2, #0
	bne _0809D5AE
	b _0809D6CA
_0809D5AE:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r5, r2, r0
	cmp r5, #0
	bne _0809D5BA
	b _0809D6CA
_0809D5BA:
	ldrb r0, [r4]
	strb r0, [r5, #0x1c]
	ldrb r0, [r4, #1]
	strb r0, [r5, #0x1d]
	ldrb r0, [r4, #2]
	strb r0, [r5, #0x1e]
	ldrb r0, [r4, #3]
	strb r0, [r5, #0x1f]
	ldrb r1, [r4, #4]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	ldrb r0, [r4, #5]
	adds r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	ldrh r0, [r4, #6]
	strh r0, [r5, #0x22]
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x24]
	ldrh r0, [r4, #0xa]
	strh r0, [r5, #0x26]
	movs r3, #0
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r2, r0
	ldr r1, _0809D630 @ =0x00000F58
	adds r2, r6, r1
_0809D5F4:
	adds r0, r7, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #0xb
	ble _0809D5F4
	adds r2, r5, #0
	adds r2, #0x34
	adds r1, r4, #0
	adds r1, #0x18
	movs r3, #2
_0809D60C:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #1]
	ldrb r0, [r1, #2]
	strb r0, [r2, #2]
	ldrb r0, [r1, #3]
	strb r0, [r2, #3]
	adds r2, #4
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _0809D60C
	b _0809D6C6
	.align 2, 0
_0809D628: .4byte 0x00000F4C
_0809D62C: .4byte 0x03002C68
_0809D630: .4byte 0x00000F58
_0809D634:
	ldr r3, _0809D6E0 @ =0x00000F4C
	adds r4, r6, r3
	ldrb r5, [r5]
	lsls r5, r5, #0x18
	asrs r5, r5, #0x18
	mov ip, r5
	ldr r0, _0809D6E4 @ =0x03002C68
	ldr r2, [r0]
	mov sb, r0
	movs r0, #0xb0
	adds r0, r0, r6
	mov r8, r0
	cmp r2, #0
	beq _0809D6CA
	movs r1, #0xae
	lsls r1, r1, #1
	adds r5, r2, r1
	cmp r5, #0
	beq _0809D6CA
	ldrb r0, [r4]
	strb r0, [r5, #0x1c]
	ldrb r0, [r4, #1]
	strb r0, [r5, #0x1d]
	ldrb r0, [r4, #2]
	strb r0, [r5, #0x1e]
	ldrb r0, [r4, #3]
	strb r0, [r5, #0x1f]
	ldrb r1, [r4, #4]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	ldrb r0, [r4, #5]
	adds r3, #1
	adds r1, r2, r3
	strb r0, [r1]
	ldrh r0, [r4, #6]
	strh r0, [r5, #0x22]
	ldrh r0, [r4, #8]
	strh r0, [r5, #0x24]
	ldrh r0, [r4, #0xa]
	strh r0, [r5, #0x26]
	movs r3, #0
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r2, r0
	ldr r1, _0809D6E8 @ =0x00000F58
	adds r2, r6, r1
_0809D694:
	adds r0, r7, r3
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #0xb
	ble _0809D694
	adds r2, r5, #0
	adds r2, #0x34
	adds r1, r4, #0
	adds r1, #0x18
	movs r3, #2
_0809D6AC:
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r0, [r1, #1]
	strb r0, [r2, #1]
	ldrb r0, [r1, #2]
	strb r0, [r2, #2]
	ldrb r0, [r1, #3]
	strb r0, [r2, #3]
	adds r2, #4
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _0809D6AC
_0809D6C6:
	mov r2, ip
	strb r2, [r5, #0x17]
_0809D6CA:
	mov r3, sb
	ldr r0, [r3]
	cmp r0, #0
	beq _0809D6EC
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809D6EC
	movs r0, #1
	b _0809D6EE
	.align 2, 0
_0809D6E0: .4byte 0x00000F4C
_0809D6E4: .4byte 0x03002C68
_0809D6E8: .4byte 0x00000F58
_0809D6EC:
	movs r0, #0
_0809D6EE:
	cmp r0, #0
	beq _0809D71A
	bl FUN_081df8d4
	adds r0, r6, #0
	bl FUN_0809d230
	bl FUN_08049fa8
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	b _0809D74E
_0809D71A:
	movs r0, #3
	bl FUN_081df95c
	adds r0, r6, #0
	bl FUN_0809d230
	movs r0, #0
	bl FUN_0822b644
	movs r0, #1
	bl FUN_0822b644
	movs r0, #2
	bl FUN_0822b644
	movs r0, #3
	bl FUN_0822b644
	ldr r1, _0809D76C @ =0x00000F88
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0809D74E
	movs r1, #0
	bl FUN_082318ac
_0809D74E:
	movs r3, #1
	mov r1, r8
	movs r2, #0x23
_0809D754:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809D754
_0809D762:
	adds r0, r6, #0
	bl KillEntity
	b _0809D792
	.align 2, 0
_0809D76C: .4byte 0x00000F88
_0809D770:
	ldr r2, _0809D7A0 @ =0x00000E28
	adds r4, r6, r2
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _0809D792
	adds r0, r6, #0
	bl FUN_0809cea8
	adds r0, r6, #0
	bl FUN_0809d00c
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080b9fc4
_0809D792:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809D7A0: .4byte 0x00000E28

	thumb_func_start FUN_0809d7a4
FUN_0809d7a4: @ 0x0809D7A4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809D7D4 @ =0x00000E58
	adds r0, r4, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _0809D7CE
	ldr r0, _0809D7D8 @ =0x00000111
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0809d300
	adds r0, r4, #0
	bl FUN_0809d00c
	ldr r1, _0809D7DC @ =FUN_0809d3d0
	adds r0, r4, #0
	bl FUN_0809ce90
_0809D7CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809D7D4: .4byte 0x00000E58
_0809D7D8: .4byte 0x00000111
_0809D7DC: .4byte FUN_0809d3d0

	thumb_func_start FUN_0809d7e0
FUN_0809d7e0: @ 0x0809D7E0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _0809D812
	bl FUN_08049fa8
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0xb0
	movs r2, #0x23
_0809D7F8:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0809D7F8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _0809D820
_0809D812:
	ldr r1, _0809D828 @ =0x00000F8C
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
_0809D820:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809D828: .4byte 0x00000F8C

	thumb_func_start FUN_0809d82c
FUN_0809d82c: @ 0x0809D82C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xa8
	movs r5, #0x23
_0809D836:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809D836
	ldr r1, _0809D854 @ =0x00000E58
	adds r0, r6, r1
	bl FUN_080b9a0c
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809D854: .4byte 0x00000E58

	thumb_func_start FUN_0809d858
FUN_0809d858: @ 0x0809D858
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _0809D874 @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	movs r3, #0x1f
	ands r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	ands r2, r3
	lsls r2, r2, #6
	adds r0, r0, r2
	bx lr
	.align 2, 0
_0809D874: .4byte 0x03003ED0

	thumb_func_start FUN_0809d878
FUN_0809d878: @ 0x0809D878
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _0809D918 @ =0x0000C091
	ldr r1, _0809D91C @ =0x0000CD91
	bl FUN_082310cc
	adds r2, r0, #0
	str r2, [r6, #0x1c]
	movs r0, #6
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	movs r2, #0
	movs r5, #1
_0809D8B6:
	ldr r1, _0809D920 @ =0x00000F71
	adds r0, r6, r1
	ldrb r0, [r0]
	asrs r0, r2
	ands r0, r5
	adds r4, r2, #1
	cmp r0, #0
	bne _0809D8EA
	adds r0, r2, #0
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, #2
	asrs r2, r2, #1
	adds r2, #4
	movs r0, #3
	bl FUN_0809d858
	movs r2, #1
	movs r1, #1
_0809D8E0:
	strh r2, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0809D8E0
_0809D8EA:
	adds r2, r4, #0
	cmp r2, #3
	ble _0809D8B6
	ldr r4, _0809D924 @ =0x000092B3
	ldr r0, _0809D928 @ =0x08251D6C
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_082310cc
	adds r0, #0x14
	str r0, [r6, #0x20]
	ldr r1, _0809D92C @ =0x03004250
	ldr r2, _0809D930 @ =0x04000018
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D918: .4byte 0x0000C091
_0809D91C: .4byte 0x0000CD91
_0809D920: .4byte 0x00000F71
_0809D924: .4byte 0x000092B3
_0809D928: .4byte 0x08251D6C
_0809D92C: .4byte 0x03004250
_0809D930: .4byte 0x04000018

	thumb_func_start FUN_0809d934
FUN_0809d934: @ 0x0809D934
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	ldr r5, _0809DA1C @ =0x0000CB05
	ldr r1, _0809DA20 @ =0x0000B343
	adds r0, r5, #0
	bl FUN_082310cc
	adds r2, r0, #0
	cmp r2, #0
	bne _0809D954
	b _0809DD12
_0809D954:
	mov r1, r8
	adds r1, #0x28
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	mov r4, r8
	adds r4, #0x28
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _0809DA24 @ =0x00005D04
	adds r0, r5, #0
	bl FUN_082310cc
	adds r2, r0, #0
	str r4, [sp, #0x24]
	cmp r2, #0
	bne _0809D982
	b _0809DD12
_0809D982:
	mov r1, r8
	adds r1, #0x48
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	mov r4, r8
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _0809DA28 @ =0x0000DCC1
	adds r0, r5, #0
	bl FUN_082310cc
	adds r2, r0, #0
	str r4, [sp, #0x28]
	cmp r2, #0
	bne _0809D9B0
	b _0809DD12
_0809D9B0:
	mov r1, r8
	adds r1, #0x68
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r4, r6}
	stm r1!, {r4, r6}
	mov r4, r8
	adds r4, #0x68
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _0809DA2C @ =0x0000DE23
	adds r0, r5, #0
	bl FUN_082310cc
	adds r2, r0, #0
	str r4, [sp, #0x1c]
	cmp r2, #0
	bne _0809D9DE
	b _0809DD12
_0809D9DE:
	adds r4, #0x20
	adds r1, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	movs r6, #0
	str r4, [sp, #0x20]
	add r0, sp, #0x10
	mov sl, r0
	mov r5, r8
	adds r5, #0xa8
	mov sb, r6
_0809DA04:
	mov r1, r8
	ldr r0, [r1, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809DA5A
	cmp r6, #0
	bne _0809DA30
	movs r4, #0x3c
	movs r7, #0x30
	b _0809DA34
	.align 2, 0
_0809DA1C: .4byte 0x0000CB05
_0809DA20: .4byte 0x0000B343
_0809DA24: .4byte 0x00005D04
_0809DA28: .4byte 0x0000DCC1
_0809DA2C: .4byte 0x0000DE23
_0809DA30:
	movs r4, #0
	movs r7, #0x31
_0809DA34:
	add r0, sp, #0x10
	adds r1, r6, #0
	bl FUN_0809d240
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	mov r3, sb
	str r3, [sp]
	str r3, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r4, sl
	str r4, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x28]
	adds r3, r7, #0
	bl FUN_0822f3fc
	b _0809DAB2
_0809DA5A:
	adds r0, r6, #0
	bl GetWeaponID
	adds r4, r0, #0
	movs r7, #0x30
	cmp r4, #0
	bne _0809DA6A
	movs r7, #0x31
_0809DA6A:
	add r0, sp, #0x10
	adds r1, r6, #0
	bl FUN_0809d240
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	mov r0, sb
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r1, sl
	str r1, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x28]
	adds r3, r7, #0
	bl FUN_0822f3fc
	adds r0, r6, #0
	bl FUN_0809cf98
	cmp r0, #0
	beq _0809DAA8
	adds r0, r5, #0
	ldr r1, _0809DAA4 @ =0x000002DF
	bl FUN_080b95bc
	b _0809DAB2
	.align 2, 0
_0809DAA4: .4byte 0x000002DF
_0809DAA8:
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
_0809DAB2:
	adds r5, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _0809DA04
	add r5, sp, #0x10
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_0809d240
	movs r0, #0xd5
	lsls r0, r0, #3
	add r0, r8
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x28]
	movs r2, #0
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r0, #0xf9
	lsls r0, r0, #3
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0x40
	movs r3, #0x31
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	strh r4, [r5, #4]
	movs r5, #0xed
	lsls r5, r5, #3
	add r5, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	movs r2, #0x39
	movs r3, #0x30
	bl FUN_0822f3fc
	str r4, [sp]
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r0, _0809DC58 @ =0x00000828
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0x41
	movs r3, #0x31
	bl FUN_0822f3fc
	movs r6, #0
	add r4, sp, #0x10
	mov sl, r4
_0809DB4A:
	adds r1, r6, #0
	movs r5, #1
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x20
	mov r1, sl
	strh r0, [r1]
	asrs r0, r6, #1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r1, #2]
	movs r3, #0
	strh r3, [r1, #4]
	ldr r0, _0809DC5C @ =0x00000F71
	add r0, r8
	ldrb r0, [r0]
	asrs r0, r6
	ands r0, r5
	movs r4, #0x31
	str r4, [sp, #0x18]
	cmp r0, #0
	beq _0809DB7E
	movs r5, #0x30
	str r5, [sp, #0x18]
_0809DB7E:
	movs r7, #0
	lsls r1, r6, #1
	adds r0, r6, #1
	mov sb, r0
	add r5, sp, #0x10
	adds r0, #0x15
	adds r4, r1, r0
_0809DB8C:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0xa8
	add r0, r8
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r3, #0x3c
	str r3, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0
	ldr r3, [sp, #0x18]
	bl FUN_0822f3fc
	ldrh r0, [r5]
	adds r0, #8
	strh r0, [r5]
	adds r4, #1
	adds r7, #1
	cmp r7, #2
	ble _0809DB8C
	mov r6, sb
	cmp r6, #3
	ble _0809DB4A
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	movs r0, #0x80
	strh r0, [r5, #2]
	movs r0, #0xe1
	lsls r0, r0, #3
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	ldr r1, [sp, #0x28]
	movs r2, #0xcf
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	ldr r0, _0809DC60 @ =0x00000D68
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x24]
	movs r2, #0x93
	movs r3, #0x30
	bl FUN_0822f3fc
	add r0, sp, #0x10
	strh r4, [r0]
	strh r4, [r5, #2]
	ldr r0, _0809DC64 @ =0x00000DC8
	add r0, r8
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x15
	movs r3, #0x30
	bl FUN_0822f3fc
	movs r0, #0xf7
	lsls r0, r0, #4
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0809DC40
	movs r0, #0xdd
	lsls r0, r0, #4
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_0809DC40:
	mov r4, r8
	ldr r0, [r4, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _0809DC68
	cmp r0, #1
	ble _0809DC80
	cmp r0, #2
	beq _0809DC74
	b _0809DC80
	.align 2, 0
_0809DC58: .4byte 0x00000828
_0809DC5C: .4byte 0x00000F71
_0809DC60: .4byte 0x00000D68
_0809DC64: .4byte 0x00000DC8
_0809DC68:
	ldr r2, _0809DC70 @ =0x0000016B
	movs r4, #0x26
	b _0809DC84
	.align 2, 0
_0809DC70: .4byte 0x0000016B
_0809DC74:
	ldr r2, _0809DC7C @ =0x000002F9
	movs r4, #0x27
	b _0809DC84
	.align 2, 0
_0809DC7C: .4byte 0x000002F9
_0809DC80:
	movs r2, #4
	movs r4, #0x1d
_0809DC84:
	ldr r0, _0809DC9C @ =0x03002C68
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _0809DCA0
	adds r0, r1, #0
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809DCA0
	movs r0, #1
	b _0809DCA2
	.align 2, 0
_0809DC9C: .4byte 0x03002C68
_0809DCA0:
	movs r0, #0
_0809DCA2:
	cmp r0, #0
	beq _0809DCC0
	ldr r0, [r3]
	cmp r0, #0
	bne _0809DCB2
	movs r0, #1
	rsbs r0, r0, #0
	b _0809DCB6
_0809DCB2:
	movs r5, #0x18
	ldrsh r0, [r0, r5]
_0809DCB6:
	adds r4, r0, #0
	adds r4, #0x22
	cmp r0, #0
	bge _0809DCC0
	movs r4, #0x22
_0809DCC0:
	movs r3, #0
	movs r1, #0x24
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x70
	strh r0, [r1, #2]
	ldr r0, _0809DD24 @ =0x00000888
	add r0, r8
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	ldr r1, [sp, #0x20]
	movs r3, #0x10
	bl FUN_0822f3fc
	ldr r0, _0809DD28 @ =0x000008C2
	add r0, r8
	strh r4, [r0]
	movs r3, #0x8d
	lsls r3, r3, #4
	add r3, r8
	ldr r2, _0809DD2C @ =0x03003584
	ldrh r1, [r0]
	lsls r1, r1, #5
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r3]
	ldr r0, _0809DD30 @ =0x00000E58
	add r0, r8
	bl FUN_080b99a0
	mov r0, r8
	bl FUN_0809d300
	mov r0, r8
	bl FUN_0809d00c
_0809DD12:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809DD24: .4byte 0x00000888
_0809DD28: .4byte 0x000008C2
_0809DD2C: .4byte 0x03003584
_0809DD30: .4byte 0x00000E58

	thumb_func_start FUN_0809dd34
FUN_0809dd34: @ 0x0809DD34
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0809DD64 @ =0x00000E28
	adds r5, r4, r0
	movs r0, #0x1e
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080b9ff8
	movs r0, #0xed
	lsls r0, r0, #3
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080b9fc4
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809DD64: .4byte 0x00000E28

	thumb_func_start FUN_0809dd68
FUN_0809dd68: @ 0x0809DD68
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _0809DD7C
	bl FUN_0823d340
	str r0, [r4, #0x24]
_0809DD7C:
	adds r0, r4, #0
	bl FUN_0809cea8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809dd88
FUN_0809dd88: @ 0x0809DD88
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0809DDA8
	bl fetch_082316e4
	ldr r2, _0809DDA4 @ =0x00000F84
	adds r1, r4, r2
	str r0, [r1]
	b _0809DDAE
	.align 2, 0
_0809DDA4: .4byte 0x00000F84
_0809DDA8:
	ldr r2, _0809DDC8 @ =0x00000F84
	adds r0, r4, r2
	str r1, [r0]
_0809DDAE:
	movs r0, #0x6e
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0809DDD0
	bl fetch_082316e4
	ldr r2, _0809DDCC @ =0x00000F88
	adds r1, r4, r2
	str r0, [r1]
	b _0809DDD6
	.align 2, 0
_0809DDC8: .4byte 0x00000F84
_0809DDCC: .4byte 0x00000F88
_0809DDD0:
	ldr r2, _0809DDDC @ =0x00000F88
	adds r0, r4, r2
	str r1, [r0]
_0809DDD6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809DDDC: .4byte 0x00000F88

	thumb_func_start FUN_0809dde0
FUN_0809dde0: @ 0x0809DDE0
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809DDFC
	ldr r0, _0809DDF8 @ =0x00000F71
	adds r1, r2, r0
	movs r0, #0xf
	strb r0, [r1]
	b _0809DE46
	.align 2, 0
_0809DDF8: .4byte 0x00000F71
_0809DDFC:
	ldr r0, _0809DE1C @ =0x00000F71
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	movs r5, #0
	ldr r0, _0809DE1C @ =0x00000F71
	adds r4, r2, r0
_0809DE0A:
	adds r0, r5, #0
	bl GetWeaponKind
	cmp r0, #0
	bne _0809DE20
	ldrb r0, [r4]
	movs r1, #1
	b _0809DE3C
	.align 2, 0
_0809DE1C: .4byte 0x00000F71
_0809DE20:
	cmp r0, #1
	bne _0809DE2A
	ldrb r0, [r4]
	movs r1, #2
	b _0809DE3C
_0809DE2A:
	cmp r0, #2
	bne _0809DE34
	ldrb r0, [r4]
	movs r1, #4
	b _0809DE3C
_0809DE34:
	cmp r0, #4
	bne _0809DE40
	ldrb r0, [r4]
	movs r1, #8
_0809DE3C:
	orrs r0, r1
	strb r0, [r4]
_0809DE40:
	adds r5, #1
	cmp r5, #0xf
	ble _0809DE0A
_0809DE46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809de4c
FUN_0809de4c: @ 0x0809DE4C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _0809DE70 @ =0x03002C68
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r0, r2
	cmp r0, #0
	bne _0809DE62
	movs r1, #0
_0809DE62:
	str r1, [r4, #0x18]
	cmp r1, #0
	bne _0809DE74
	movs r0, #1
	rsbs r0, r0, #0
	b _0809DF16
	.align 2, 0
_0809DE70: .4byte 0x03002C68
_0809DE74:
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #2
	bne _0809DEAC
	movs r3, #0xf7
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0809DEA4 @ =gWeaponDB
	ldr r5, _0809DEA8 @ =0x00000F4C
	adds r0, r4, r5
	movs r2, #0x87
	lsls r2, r2, #4
	adds r1, r1, r2
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	b _0809DEC8
	.align 2, 0
_0809DEA4: .4byte gWeaponDB
_0809DEA8: .4byte 0x00000F4C
_0809DEAC:
	ldrb r0, [r1, #0x17]
	movs r3, #0xf7
	lsls r3, r3, #4
	adds r1, r4, r3
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _0809DEC8
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r5, _0809DF20 @ =0x00000F4C
	adds r1, r4, r5
	bl FUN_08242b14
_0809DEC8:
	ldr r0, [r4, #0x18]
	adds r0, #0x41
	ldrb r0, [r0]
	movs r2, #0xf8
	lsls r2, r2, #4
	adds r1, r4, r2
	add r3, sp, #8
	add r2, sp, #0xc
	str r2, [sp]
	add r2, sp, #4
	bl FUN_081dfa20
	adds r0, r4, #0
	bl FUN_0809dde0
	adds r0, r4, #0
	bl FUN_0809d878
	adds r0, r4, #0
	bl FUN_0809d934
	adds r0, r4, #0
	bl FUN_0809dd34
	adds r0, r4, #0
	bl FUN_0809dd68
	adds r0, r4, #0
	bl FUN_0809dd88
	ldr r3, _0809DF24 @ =0x00000F74
	adds r1, r4, r3
	movs r0, #0x1e
	str r0, [r1]
	ldr r1, _0809DF28 @ =FUN_0809d3d0
	adds r0, r4, #0
	bl FUN_0809ce90
	movs r0, #0
_0809DF16:
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809DF20: .4byte 0x00000F4C
_0809DF24: .4byte 0x00000F74
_0809DF28: .4byte FUN_0809d3d0
_0809DF2C:
	.byte 0x10, 0xB5, 0xF9, 0x21
	.byte 0x09, 0x01, 0x08, 0x20, 0x92, 0xF1, 0x3C, 0xFE, 0x04, 0x1C, 0x00, 0x2C, 0x12, 0xD0, 0x07, 0x49
	.byte 0x07, 0x4A, 0x92, 0xF1, 0x59, 0xFE, 0x20, 0x1C, 0xFF, 0xF7, 0x80, 0xFF, 0x00, 0x28, 0x09, 0xDA
	.byte 0x20, 0x1C, 0x92, 0xF1, 0x8B, 0xFE, 0x00, 0x20, 0x05, 0xE0, 0x00, 0x00, 0xE1, 0xD7, 0x09, 0x08
	.byte 0x2D, 0xD8, 0x09, 0x08, 0x20, 0x1C, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x01, 0x49, 0x00, 0x20
	.byte 0x08, 0x60, 0x70, 0x47, 0x40, 0x01, 0x00, 0x03

	thumb_func_start FUN_0809df78
FUN_0809df78: @ 0x0809DF78
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0809DF88 @ =0x03000140
	ldr r5, [r0]
	cmp r5, #0
	bne _0809DF90
	b _0809DFE4
	.align 2, 0
_0809DF88: .4byte 0x03000140
_0809DF8C:
	movs r0, #1
	b _0809DFE6
_0809DF90:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r4, r0
	bge _0809DFE4
	adds r7, r0, #0
_0809DF9E:
	movs r0, #0xa8
	muls r0, r4, r0
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809DFDE
	movs r0, #0
	ldrsh r3, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	cmp r3, r0
	blt _0809DFDE
	movs r0, #4
	ldrsh r2, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xce
	ldrh r0, [r0]
	cmp r2, r0
	blt _0809DFDE
	adds r0, r1, #0
	adds r0, #0xd0
	ldrh r0, [r0]
	cmp r3, r0
	bgt _0809DFDE
	adds r0, r1, #0
	adds r0, #0xd2
	ldrh r0, [r0]
	cmp r2, r0
	ble _0809DF8C
_0809DFDE:
	adds r4, #1
	cmp r4, r7
	blt _0809DF9E
_0809DFE4:
	movs r0, #0
_0809DFE6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809dfec
FUN_0809dfec: @ 0x0809DFEC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809E004 @ =0x03000140
	ldr r1, [r0]
	cmp r1, #0
	beq _0809E02C
	adds r3, r1, #0
	adds r3, #0x26
	ldrb r0, [r3]
	cmp r0, #0
	bne _0809E00C
	b _0809E02C
	.align 2, 0
_0809E004: .4byte 0x03000140
_0809E008:
	movs r0, #1
	b _0809E02E
_0809E00C:
	movs r2, #0
	ldrb r0, [r3]
	cmp r2, r0
	bge _0809E02C
	adds r3, r0, #0
	adds r1, #0xc6
_0809E018:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809E024
	ldrh r0, [r1, #4]
	cmp r0, r4
	beq _0809E008
_0809E024:
	adds r1, #0xa8
	adds r2, #1
	cmp r2, r3
	blt _0809E018
_0809E02C:
	movs r0, #0
_0809E02E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e034
FUN_0809e034: @ 0x0809E034
	push {lr}
	ldr r1, _0809E054 @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _0809E058 @ =0x00000942
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	movs r1, #0xa
	bl Div
	cmp r0, #0
	bgt _0809E050
	movs r0, #1
_0809E050:
	pop {r1}
	bx r1
	.align 2, 0
_0809E054: .4byte 0x030046A0
_0809E058: .4byte 0x00000942

	thumb_func_start FUN_0809e05c
FUN_0809e05c: @ 0x0809E05C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _0809E06C @ =0x03000140
	ldr r5, [r0]
	cmp r5, #0
	bne _0809E074
	b _0809E0C8
	.align 2, 0
_0809E06C: .4byte 0x03000140
_0809E070:
	adds r0, r4, #0
	b _0809E0CC
_0809E074:
	movs r4, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r4, r0
	bge _0809E0C8
	adds r7, r0, #0
_0809E082:
	movs r0, #0xa8
	muls r0, r4, r0
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0xc6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E0C2
	movs r0, #0
	ldrsh r3, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xcc
	ldrh r0, [r0]
	cmp r3, r0
	blt _0809E0C2
	movs r0, #4
	ldrsh r2, [r6, r0]
	adds r0, r1, #0
	adds r0, #0xce
	ldrh r0, [r0]
	cmp r2, r0
	blt _0809E0C2
	adds r0, r1, #0
	adds r0, #0xd0
	ldrh r0, [r0]
	cmp r3, r0
	bgt _0809E0C2
	adds r0, r1, #0
	adds r0, #0xd2
	ldrh r0, [r0]
	cmp r2, r0
	ble _0809E070
_0809E0C2:
	adds r4, #1
	cmp r4, r7
	blt _0809E082
_0809E0C8:
	movs r0, #1
	rsbs r0, r0, #0
_0809E0CC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809e0d4
FUN_0809e0d4: @ 0x0809E0D4
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _0809E0FC @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _0809E100 @ =0x00000942
	adds r0, r2, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq _0809E124
	movs r1, #2
	ldr r5, _0809E104 @ =0x00000934
	adds r0, r2, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809E108
	movs r0, #1
	b _0809E10A
	.align 2, 0
_0809E0FC: .4byte 0x030046A0
_0809E100: .4byte 0x00000942
_0809E104: .4byte 0x00000934
_0809E108:
	movs r0, #0
_0809E10A:
	cmp r0, #0
	bne _0809E12C
	adds r0, r3, #0
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809E12C
	ldr r0, _0809E128 @ =0x03000140
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809E12C
_0809E124:
	movs r0, #0
	b _0809E132
	.align 2, 0
_0809E128: .4byte 0x03000140
_0809E12C:
	adds r0, r4, #0
	bl FUN_0809e034
_0809E132:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e138
FUN_0809e138: @ 0x0809E138
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0809E160 @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _0809E164 @ =0x00000942
	adds r0, r2, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _0809E186
	movs r1, #2
	ldr r4, _0809E168 @ =0x00000934
	adds r0, r2, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809E16C
	movs r0, #1
	b _0809E16E
	.align 2, 0
_0809E160: .4byte 0x030046A0
_0809E164: .4byte 0x00000942
_0809E168: .4byte 0x00000934
_0809E16C:
	movs r0, #0
_0809E16E:
	cmp r0, #0
	bne _0809E190
	ldr r0, _0809E18C @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	beq _0809E186
	adds r0, r3, #0
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809E190
_0809E186:
	movs r0, #0
	b _0809E192
	.align 2, 0
_0809E18C: .4byte 0x03000140
_0809E190:
	movs r0, #1
_0809E192:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e198
FUN_0809e198: @ 0x0809E198
	push {r4, r5, r6, lr}
	mov ip, r0
	adds r6, r2, #0
	cmp r3, #0
	beq _0809E1B8
	ldr r0, _0809E1B0 @ =0x085AD004
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r5, [r0]
	ldr r0, _0809E1B4 @ =0x085AD00C
	b _0809E1C2
	.align 2, 0
_0809E1B0: .4byte 0x085AD004
_0809E1B4: .4byte 0x085AD00C
_0809E1B8:
	ldr r0, _0809E1F0 @ =0x085AD00C
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r5, [r0]
	ldr r0, _0809E1F4 @ =0x085AD004
_0809E1C2:
	adds r1, r1, r0
	ldrh r4, [r1]
	ldrh r2, [r6]
	subs r1, r2, r5
	mov r0, ip
	adds r0, #0xa0
	strh r1, [r0]
	ldrh r1, [r6, #4]
	subs r0, r1, r4
	mov r3, ip
	adds r3, #0xa2
	strh r0, [r3]
	adds r2, r5, r2
	mov r0, ip
	adds r0, #0xa4
	strh r2, [r0]
	adds r1, r4, r1
	adds r0, #2
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E1F0: .4byte 0x085AD00C
_0809E1F4: .4byte 0x085AD004

	thumb_func_start FUN_0809e1f8
FUN_0809e1f8: @ 0x0809E1F8
	push {r4, lr}
	ldr r0, _0809E21C @ =0x03000140
	ldr r4, [r0]
	cmp r4, #0
	beq _0809E226
	movs r0, #0x74
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _0809E220
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x27
	strb r0, [r1]
	b _0809E226
	.align 2, 0
_0809E21C: .4byte 0x03000140
_0809E220:
	adds r0, r4, #0
	adds r0, #0x27
	strb r1, [r0]
_0809E226:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e22c
FUN_0809e22c: @ 0x0809E22C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	mov sl, r1
	str r2, [sp]
	mov sb, r3
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7]
	str r1, [r7, #4]
	rsbs r4, r3, #0
	orrs r4, r3
	asrs r4, r4, #0x1f
	movs r0, #4
	ands r4, r0
	mov r1, sl
	lsls r0, r1, #2
	movs r2, #0x9c
	adds r2, r2, r7
	mov r8, r2
	strb r0, [r2]
	adds r5, r7, #0
	adds r5, #0x60
	movs r1, #0xd9
	lsls r1, r1, #6
	adds r0, r5, #0
	bl FUN_0822b16c
	adds r6, r7, #0
	adds r6, #8
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0822a470
	mov r1, r8
	ldrb r0, [r1]
	strh r0, [r6, #0x10]
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	bl FUN_0822b20c
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r7, #0x24]
	str r1, [r7, #0x28]
	movs r0, #3
	strb r0, [r7, #0xf]
	adds r1, r7, #0
	adds r1, #0x9d
	movs r0, #1
	strb r0, [r1]
	adds r0, r7, #0
	mov r1, sl
	ldr r2, [sp]
	mov r3, sb
	bl FUN_0809e198
	adds r0, r7, #0
	bl FUN_08241574
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e2c4
FUN_0809e2c4: @ 0x0809E2C4
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r0, _0809E2FC @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	beq _0809E392
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0xf
	bhi _0809E392
	movs r0, #0x6e
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _0809E300
	bl fetch_082316e4
	ldrb r2, [r5]
	movs r1, #0xa8
	muls r1, r2, r1
	adds r1, r6, r1
	adds r1, #0xc4
	strh r0, [r1]
	b _0809E30C
	.align 2, 0
_0809E2FC: .4byte 0x03000140
_0809E300:
	ldrb r1, [r5]
	movs r0, #0xa8
	muls r0, r1, r0
	adds r0, r6, r0
	adds r0, #0xc4
	strh r2, [r0]
_0809E30C:
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _0809E392
	bl fetch_082316e4
	ldrb r1, [r5]
	movs r4, #0xa8
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xcc
	strh r0, [r1]
	bl fetch_082316e4
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xce
	strh r0, [r1]
	bl fetch_082316e4
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xd0
	strh r0, [r1]
	bl fetch_082316e4
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xd2
	strh r0, [r1]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xcc
	ldr r2, _0809E39C @ =0xFFFF0000
	ldrh r0, [r0]
	str r0, [sp]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xce
	ldrh r1, [r0]
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl FUN_08241574
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xca
	strh r0, [r1]
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xc6
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
_0809E392:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E39C: .4byte 0xFFFF0000

	thumb_func_start FUN_0809e3a0
FUN_0809e3a0: @ 0x0809E3A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	ldr r0, _0809E3E0 @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	bne _0809E3B2
	b _0809E53E
_0809E3B2:
	adds r0, r6, #0
	adds r0, #0x26
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0xf
	bls _0809E3C0
	b _0809E53E
_0809E3C0:
	movs r0, #0x6e
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _0809E3E4
	bl fetch_082316e4
	mov r1, r8
	ldrb r2, [r1]
	movs r1, #0xa8
	muls r1, r2, r1
	adds r1, r6, r1
	adds r1, #0xc4
	strh r0, [r1]
	b _0809E3F2
	.align 2, 0
_0809E3E0: .4byte 0x03000140
_0809E3E4:
	mov r0, r8
	ldrb r1, [r0]
	movs r0, #0xa8
	muls r0, r1, r0
	adds r0, r6, r0
	adds r0, #0xc4
	strh r2, [r0]
_0809E3F2:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0809E438
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0809E430 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _0809E434 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0809E442
	.align 2, 0
_0809E430: .4byte 0xFFFF0000
_0809E434: .4byte 0x0000FFFF
_0809E438:
	ldr r1, _0809E470 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0809E442:
	add r5, sp, #4
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0809E46A
	cmp r1, #0
	blt _0809E46A
	ldr r0, _0809E474 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0809E46A
	ldr r0, _0809E478 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0809E47C
_0809E46A:
	movs r4, #0
	b _0809E48A
	.align 2, 0
_0809E470: .4byte 0xFFFF0000
_0809E474: .4byte 0x030046A8
_0809E478: .4byte 0x030046AC
_0809E47C:
	ldr r0, _0809E49C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0809E48A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0809E4A0
	adds r0, #4
	b _0809E4AC
	.align 2, 0
_0809E49C: .4byte 0x030046A4
_0809E4A0:
	ldr r0, _0809E4C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0809E4AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0809E4C4
	cmp r2, #2
	beq _0809E4C8
	b _0809E4CC
	.align 2, 0
_0809E4C0: .4byte 0x030046A4
_0809E4C4:
	ldrb r0, [r5, #4]
	b _0809E4CA
_0809E4C8:
	ldrb r0, [r5]
_0809E4CA:
	subs r1, r1, r0
_0809E4CC:
	add r0, sp, #4
	strh r1, [r0, #2]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0809E4E2
	bl fetch_082316e4
	adds r7, r0, #0
	b _0809E4E4
_0809E4E2:
	movs r7, #0
_0809E4E4:
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _0809E4F6
	bl fetch_082316e4
	adds r3, r0, #0
	b _0809E4F8
_0809E4F6:
	movs r3, #0
_0809E4F8:
	mov r4, r8
	ldrb r0, [r4]
	movs r5, #0xa8
	muls r0, r5, r0
	adds r0, #0x2c
	adds r0, r6, r0
	ldrh r1, [r6, #0x24]
	str r1, [sp]
	adds r1, r7, #0
	add r2, sp, #4
	bl FUN_0809e22c
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r6, r0
	adds r0, #0xc6
	movs r2, #1
	strb r2, [r0]
	adds r0, r6, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809E536
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r1, r6, #0
	adds r1, #0x34
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0809E536:
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0809E53E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e54c
FUN_0809e54c: @ 0x0809E54C
	push {r4, r5, r6, r7, lr}
	ldr r0, _0809E570 @ =0x03000140
	ldr r4, [r0]
	cmp r4, #0
	beq _0809E5BE
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0809E5BE
	bl fetch_082316e4
	adds r7, r0, #0
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x26
	adds r6, r0, #0
	b _0809E5B8
	.align 2, 0
_0809E570: .4byte 0x03000140
_0809E574:
	movs r0, #0xa8
	adds r5, r3, #0
	muls r5, r0, r5
	adds r2, r4, r5
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809E5B6
	cmp r0, r7
	bne _0809E5B6
	adds r1, #2
	movs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E5BE
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E5BE
	adds r0, r4, #0
	adds r0, #0x34
	adds r0, r0, r5
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	b _0809E5BE
_0809E5B6:
	adds r3, #1
_0809E5B8:
	ldrb r0, [r6]
	cmp r3, r0
	blt _0809E574
_0809E5BE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e5c4
FUN_0809e5c4: @ 0x0809E5C4
	push {r4, r5, r6, r7, lr}
	ldr r0, _0809E5E8 @ =0x03000140
	ldr r6, [r0]
	cmp r6, #0
	beq _0809E62A
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0809E62A
	bl fetch_082316e4
	adds r7, r0, #0
	movs r3, #0
	adds r0, r6, #0
	adds r0, #0x26
	adds r5, r0, #0
	b _0809E624
	.align 2, 0
_0809E5E8: .4byte 0x03000140
_0809E5EC:
	movs r0, #0xa8
	adds r4, r3, #0
	muls r4, r0, r4
	adds r2, r6, r4
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809E622
	cmp r0, r7
	bne _0809E622
	adds r1, #2
	movs r0, #0
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809E62A
	adds r0, r6, #0
	adds r0, #0x34
	adds r0, r0, r4
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0809E62A
_0809E622:
	adds r3, #1
_0809E624:
	ldrb r0, [r5]
	cmp r3, r0
	blt _0809E5EC
_0809E62A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e630
FUN_0809e630: @ 0x0809E630
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r1, _0809E648 @ =0x030047A4
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0809E64C
	movs r0, #0
	b _0809E666
	.align 2, 0
_0809E648: .4byte 0x030047A4
_0809E64C:
	ldr r0, _0809E658 @ =0x030044E0
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809E65C
	strh r2, [r4, #0x20]
	b _0809E668
	.align 2, 0
_0809E658: .4byte 0x030044E0
_0809E65C:
	ldrh r2, [r4, #0x20]
	ldr r0, _0809E6A0 @ =0x00000383
	cmp r2, r0
	bhi _0809E668
	adds r0, r2, #1
_0809E666:
	strh r0, [r4, #0x20]
_0809E668:
	ldr r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	beq _0809E722
	movs r1, #4
	ldr r0, _0809E6A4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0809E722
	ldr r0, [r4, #0x18]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #5
	bne _0809E6C0
	cmp r3, #2
	bne _0809E6A8
	ldrh r0, [r4, #0x1e]
	adds r0, #0x28
	b _0809E6FC
	.align 2, 0
_0809E6A0: .4byte 0x00000383
_0809E6A4: .4byte 0x03002BC0
_0809E6A8:
	cmp r3, #0
	bne _0809E6FE
	ldrh r1, [r4, #0x20]
	ldr r0, _0809E6BC @ =0x00000383
	cmp r1, r0
	bhi _0809E6FE
	ldrh r0, [r4, #0x1e]
	adds r0, #5
	b _0809E6FC
	.align 2, 0
_0809E6BC: .4byte 0x00000383
_0809E6C0:
	cmp r3, #2
	bne _0809E6E0
	ldr r0, _0809E6D8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809E6DC @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	b _0809E6FC
	.align 2, 0
_0809E6D8: .4byte 0x030046A0
_0809E6DC: .4byte 0x00000942
_0809E6E0:
	cmp r3, #1
	bne _0809E6FE
	ldrh r1, [r4, #0x20]
	ldr r0, _0809E728 @ =0x00000383
	cmp r1, r0
	bhi _0809E6FE
	ldr r0, _0809E72C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0809E730 @ =0x00000942
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
_0809E6FC:
	strh r0, [r4, #0x1e]
_0809E6FE:
	movs r1, #0
	ldrh r3, [r4, #0x1e]
	cmp r3, #0x77
	bls _0809E718
_0809E706:
	adds r2, r3, #0
	subs r2, #0x78
	adds r1, #1
	adds r3, r2, #0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _0809E706
	strh r2, [r4, #0x1e]
_0809E718:
	cmp r1, #0
	ble _0809E722
	adds r0, r5, #0
	bl FUN_0807aa30
_0809E722:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809E728: .4byte 0x00000383
_0809E72C: .4byte 0x030046A0
_0809E730: .4byte 0x00000942

	thumb_func_start FUN_0809e734
FUN_0809e734: @ 0x0809E734
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x18]
	movs r0, #0x20
	ldr r1, [r1, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809E748
	movs r1, #2
	b _0809E750
_0809E748:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809E750:
	adds r0, r2, #0
	bl FUN_0809e630
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e75c
FUN_0809e75c: @ 0x0809E75C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r1, #0xce
	lsls r1, r1, #1
	ldrh r0, [r6, #0x24]
	cmp r0, r1
	beq _0809E7B6
	strh r1, [r6, #0x24]
	movs r2, #0
	adds r0, r6, #0
	adds r0, #0x26
	mov r8, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _0809E7B6
	movs r1, #0xa8
	mov sb, r1
_0809E784:
	mov r1, sb
	muls r1, r2, r1
	adds r0, r6, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	adds r7, r2, #1
	cmp r0, #0
	beq _0809E7AC
	adds r0, r1, #0
	adds r0, #0x8c
	adds r4, r6, r0
	movs r5, #1
_0809E79C:
	ldrh r1, [r6, #0x24]
	adds r0, r4, #0
	bl FUN_0822b20c
	adds r4, #0x1c
	subs r5, #1
	cmp r5, #0
	bge _0809E79C
_0809E7AC:
	adds r2, r7, #0
	mov r0, r8
	ldrb r0, [r0]
	cmp r2, r0
	blt _0809E784
_0809E7B6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e7c4
FUN_0809e7c4: @ 0x0809E7C4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809E816
	movs r0, #1
	strb r0, [r1]
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0x26
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r5, r0
	bge _0809E816
	adds r3, r4, #0
	adds r3, #0xc6
	movs r7, #0
	movs r1, #0x34
	adds r1, r1, r4
	mov ip, r1
_0809E7F0:
	ldrb r0, [r3, #3]
	cmp r0, #0
	beq _0809E80A
	ldrb r0, [r3]
	cmp r0, #0
	beq _0809E80A
	mov r1, ip
	adds r0, r1, r7
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0809E80A:
	adds r3, #0xa8
	adds r7, #0xa8
	adds r5, #1
	ldrb r0, [r6]
	cmp r5, r0
	blt _0809E7F0
_0809E816:
	adds r0, r4, #0
	bl FUN_0809e75c
	ldr r1, [r4, #0x18]
	movs r0, #0x20
	ldr r1, [r1, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809E82C
	movs r1, #2
	b _0809E834
_0809E82C:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809E834:
	adds r0, r4, #0
	bl FUN_0809e630
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e840
FUN_0809e840: @ 0x0809E840
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #1
	bne _0809E880
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	adds r0, r4, #0
	adds r0, #0x26
	ldrb r1, [r0]
	cmp r3, r1
	bge _0809E880
	movs r6, #1
	adds r2, r4, #0
	adds r2, #0xc9
	adds r1, r4, #0
	adds r5, r0, #0
_0809E868:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809E874
	ldr r0, [r1, #0x34]
	orrs r0, r6
	str r0, [r1, #0x34]
_0809E874:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r3, #1
	ldrb r0, [r5]
	cmp r3, r0
	blt _0809E868
_0809E880:
	ldr r0, [r4, #0x18]
	movs r2, #0x20
	ldr r1, [r0, #0x20]
	ands r1, r2
	rsbs r1, r1, #0
	asrs r1, r1, #0x1f
	movs r0, #2
	ands r1, r0
	adds r0, r4, #0
	bl FUN_0809e630
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809e89c
FUN_0809e89c: @ 0x0809E89C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x28
	ldrb r0, [r1]
	ldr r7, _0809E9A8 @ =0x030046A0
	cmp r0, #0
	bne _0809E8E2
	movs r0, #1
	strb r0, [r1]
	movs r3, #0
	adds r0, r5, #0
	adds r0, #0x26
	ldrb r1, [r0]
	cmp r3, r1
	bge _0809E8E2
	movs r6, #2
	rsbs r6, r6, #0
	adds r2, r5, #0
	adds r2, #0xc6
	adds r1, r5, #0
	adds r4, r0, #0
_0809E8CA:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809E8D6
	ldr r0, [r1, #0x34]
	ands r0, r6
	str r0, [r1, #0x34]
_0809E8D6:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r3, #1
	ldrb r0, [r4]
	cmp r3, r0
	blt _0809E8CA
_0809E8E2:
	movs r4, #0
	ldr r0, [r7]
	ldr r1, _0809E9AC @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _0809E906
	ldr r0, [r5, #0x18]
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	blt _0809E902
	movs r4, #1
_0809E902:
	cmp r4, #0
	beq _0809E9BE
_0809E906:
	ldr r2, [r5, #0x18]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r1, [r0]
	cmp r1, #7
	bne _0809E9B8
	adds r3, #1
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0809E9B8
	cmp r0, #3
	bne _0809E9C0
	ldrh r0, [r5, #0x22]
	cmp r0, #0x3e
	bhi _0809E9C0
	ands r1, r0
	cmp r1, #0
	bne _0809E99E
	ldr r0, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0xc
	ldrh r0, [r0]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0809E9B0 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0xc]
	add r0, sp, #0xc
	ldrh r0, [r0, #4]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x10]
	asrs r1, r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r4, _0809E9B4 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x14]
	ands r0, r3
	movs r2, #0x80
	lsls r2, r2, #1
	orrs r0, r2
	ands r0, r4
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	str r1, [sp]
	movs r0, #0xb4
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #1
	movs r2, #0x19
	add r3, sp, #0xc
	bl FUN_0800a8e0
_0809E99E:
	ldrh r0, [r5, #0x22]
	adds r0, #1
	strh r0, [r5, #0x22]
	b _0809E9C0
	.align 2, 0
_0809E9A8: .4byte 0x030046A0
_0809E9AC: .4byte 0x00000934
_0809E9B0: .4byte 0xFFFF0000
_0809E9B4: .4byte 0x0000FFFF
_0809E9B8:
	movs r0, #0
	strh r0, [r5, #0x22]
	b _0809E9C0
_0809E9BE:
	strh r4, [r5, #0x22]
_0809E9C0:
	adds r0, r5, #0
	bl FUN_0809e75c
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809e9d0
FUN_0809e9d0: @ 0x0809E9D0
	push {lr}
	ldrh r0, [r0, #0x1c]
	cmp r0, #0
	beq _0809E9E6
	bl FUN_0823e1b0
	subs r0, #1
	cmp r0, #2
	bls _0809E9E6
	movs r0, #1
	b _0809E9E8
_0809E9E6:
	movs r0, #0
_0809E9E8:
	pop {r1}
	bx r1

	thumb_func_start FUN_0809e9ec
FUN_0809e9ec: @ 0x0809E9EC
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809E9FE
	movs r0, #0
	strb r0, [r1]
_0809E9FE:
	ldr r0, _0809EA2C @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r4, #0x18]
	cmp r0, #0
	beq _0809EA7E
	ldr r0, _0809EA30 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x94
	lsls r2, r2, #4
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0809EA3C
	adds r0, r4, #0
	bl FUN_0809e9d0
	cmp r0, #0
	beq _0809EA34
	adds r0, r4, #0
	bl FUN_0809e89c
	b _0809EA5E
	.align 2, 0
_0809EA2C: .4byte 0x03002BE0
_0809EA30: .4byte 0x030046A0
_0809EA34:
	adds r0, r4, #0
	bl FUN_0809e840
	b _0809EA5E
_0809EA3C:
	ldr r2, _0809EA54 @ =0x00000934
	adds r0, r1, r2
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809EA58
	adds r0, r4, #0
	bl FUN_0809e734
	b _0809EA5E
	.align 2, 0
_0809EA54: .4byte 0x00000934
_0809EA58:
	adds r0, r4, #0
	bl FUN_0809e7c4
_0809EA5E:
	ldr r0, _0809EA88 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _0809EA6A
	movs r1, #1
_0809EA6A:
	cmp r1, #0
	beq _0809EA7E
	ldr r0, _0809EA8C @ =0x03002BF0
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809EA7E
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
_0809EA7E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809EA88: .4byte 0x03002B80
_0809EA8C: .4byte 0x03002BF0

	thumb_func_start FUN_0809ea90
FUN_0809ea90: @ 0x0809EA90
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _0809EAB4
_0809EA98:
	movs r0, #0xa8
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809EAB0
	adds r0, r1, r4
	adds r0, #0x34
	bl FUN_0822a4e0
_0809EAB0:
	adds r5, #1
	adds r0, r4, #0
_0809EAB4:
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r5, r0
	blt _0809EA98
	ldr r1, _0809EAC8 @ =0x03000140
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809EAC8: .4byte 0x03000140

	thumb_func_start FUN_0809eacc
FUN_0809eacc: @ 0x0809EACC
	push {lr}
	ldr r0, _0809EAE8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0809EAE4
	bl FUN_0823e4d4
	cmp r0, #4
	beq _0809EAEC
_0809EAE4:
	movs r0, #0
	b _0809EAEE
	.align 2, 0
_0809EAE8: .4byte 0x030047A4
_0809EAEC:
	movs r0, #1
_0809EAEE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809eaf4
FUN_0809eaf4: @ 0x0809EAF4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0809eacc
	movs r1, #0
	strh r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x26
	strb r1, [r0]
	movs r0, #0xcd
	lsls r0, r0, #1
	strh r0, [r4, #0x24]
	adds r0, r4, #0
	adds r0, #0x28
	strb r1, [r0]
	ldr r0, _0809EB20 @ =0x03000140
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809EB20: .4byte 0x03000140

	thumb_func_start FUN_0809eb24
FUN_0809eb24: @ 0x0809EB24
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _0809EB58 @ =0x00000AB4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809EB64
	ldr r1, _0809EB5C @ =FUN_0809e9ec
	ldr r2, _0809EB60 @ =FUN_0809ea90
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0809eaf4
	cmp r0, #0
	bge _0809EB64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809EB66
	.align 2, 0
_0809EB58: .4byte 0x00000AB4
_0809EB5C: .4byte FUN_0809e9ec
_0809EB60: .4byte FUN_0809ea90
_0809EB64:
	adds r0, r4, #0
_0809EB66:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809eb6c
FUN_0809eb6c: @ 0x0809EB6C
	push {lr}
	adds r1, r0, #0
	ldr r0, _0809EB7C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EB80
	movs r0, #0
	b _0809EB84
	.align 2, 0
_0809EB7C: .4byte 0x03002C68
_0809EB80:
	adds r0, #0x66
	ldrh r0, [r0]
_0809EB84:
	adds r2, r0, #0
	muls r2, r1, r2
	adds r0, r2, #0
	movs r1, #0x8c
	bl Div
	pop {r1}
	bx r1

	thumb_func_start FUN_0809eb94
FUN_0809eb94: @ 0x0809EB94
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, _0809EBA8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EBAC
	movs r0, #0
	b _0809EBB0
	.align 2, 0
_0809EBA8: .4byte 0x03002C68
_0809EBAC:
	adds r0, #0x66
	ldrh r0, [r0]
_0809EBB0:
	cmp r0, #0
	beq _0809EBE4
	movs r1, #2
	ldr r0, _0809EBCC @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _0809EBD0 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809EBD4
	movs r0, #1
	b _0809EBD6
	.align 2, 0
_0809EBCC: .4byte 0x030046A0
_0809EBD0: .4byte 0x00000934
_0809EBD4:
	movs r0, #0
_0809EBD6:
	cmp r0, #0
	bne _0809EBE8
	adds r0, r2, #0
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809EBE8
_0809EBE4:
	movs r0, #0
	b _0809EBEE
_0809EBE8:
	adds r0, r4, #0
	bl FUN_0809eb6c
_0809EBEE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ebf4
FUN_0809ebf4: @ 0x0809EBF4
	push {lr}
	adds r2, r0, #0
	ldr r1, [r2, #0x18]
	ldr r0, _0809EC08 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EC0C
	movs r0, #0
	b _0809EC12
	.align 2, 0
_0809EC08: .4byte 0x03002C68
_0809EC0C:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_0809EC12:
	cmp r0, #0
	beq _0809EC4E
	movs r1, #2
	ldr r0, _0809EC2C @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _0809EC30 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809EC34
	movs r0, #1
	b _0809EC36
	.align 2, 0
_0809EC2C: .4byte 0x030046A0
_0809EC30: .4byte 0x00000934
_0809EC34:
	movs r0, #0
_0809EC36:
	cmp r0, #0
	bne _0809EC58
	ldr r0, _0809EC54 @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	beq _0809EC4E
	adds r0, r2, #0
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809EC58
_0809EC4E:
	movs r0, #0
	b _0809EC5A
	.align 2, 0
_0809EC54: .4byte 0x03000140
_0809EC58:
	movs r0, #1
_0809EC5A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809ec60
FUN_0809ec60: @ 0x0809EC60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r3, #0
	ldr r7, _0809EC90 @ =0x00000AAC
	add r7, r8
_0809EC6E:
	ldr r1, _0809EC94 @ =0x03002BE0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r6, [r0]
	adds r5, r3, #1
	cmp r6, #0
	beq _0809ED3E
	ldr r0, [r6, #0x1c]
	cmp r0, #1
	bne _0809ED3E
	movs r0, #0x20
	ldr r1, [r6, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809EC98
	movs r1, #2
	b _0809ECA0
	.align 2, 0
_0809EC90: .4byte 0x00000AAC
_0809EC94: .4byte 0x03002BE0
_0809EC98:
	movs r0, #0x10
	ands r1, r0
	rsbs r0, r1, #0
	lsrs r1, r0, #0x1f
_0809ECA0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _0809ECC8
	cmp r1, #2
	bne _0809ECBA
	lsls r2, r3, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0x28
	b _0809ED0E
_0809ECBA:
	lsls r2, r3, #1
	cmp r1, #0
	bne _0809ED10
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #5
	b _0809ED0E
_0809ECC8:
	cmp r1, #2
	bne _0809ECEA
	ldr r0, _0809ECD8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ECDC
	movs r0, #0
	b _0809ECE2
	.align 2, 0
_0809ECD8: .4byte 0x03002C68
_0809ECDC:
	adds r0, #0x60
	adds r0, r0, r3
	ldrb r0, [r0]
_0809ECE2:
	lsls r2, r3, #1
	adds r1, r7, r2
	lsls r0, r0, #3
	b _0809ED0A
_0809ECEA:
	lsls r2, r3, #1
	cmp r1, #1
	bne _0809ED10
	ldr r0, _0809ECFC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ED00
	movs r0, #0
	b _0809ED06
	.align 2, 0
_0809ECFC: .4byte 0x03002C68
_0809ED00:
	adds r0, #0x60
	adds r0, r0, r3
	ldrb r0, [r0]
_0809ED06:
	lsls r2, r3, #1
	adds r1, r7, r2
_0809ED0A:
	ldrh r4, [r1]
	adds r0, r0, r4
_0809ED0E:
	strh r0, [r1]
_0809ED10:
	movs r4, #0
	adds r0, r7, r2
	ldrh r0, [r0]
	adds r5, r3, #1
	cmp r0, #0x77
	bls _0809ED32
	ldr r3, _0809ED50 @ =0x00000AAC
	add r3, r8
_0809ED20:
	adds r1, r3, r2
	ldrh r0, [r1]
	subs r0, #0x78
	strh r0, [r1]
	adds r4, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _0809ED20
_0809ED32:
	cmp r4, #0
	ble _0809ED3E
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0807aa30
_0809ED3E:
	adds r3, r5, #0
	cmp r3, #3
	ble _0809EC6E
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809ED50: .4byte 0x00000AAC

	thumb_func_start FUN_0809ed54
FUN_0809ed54: @ 0x0809ED54
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809ed58
FUN_0809ed58: @ 0x0809ED58
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r0, _0809ED6C @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _0809ED70
	movs r1, #1
	rsbs r1, r1, #0
	b _0809ED74
	.align 2, 0
_0809ED6C: .4byte 0x03002C68
_0809ED70:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_0809ED74:
	ldr r0, [r0]
	cmp r0, #0
	bne _0809ED7E
	movs r0, #0
	b _0809ED84
_0809ED7E:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_0809ED84:
	adds r2, r0, #0
	cmp r2, #0
	beq _0809EDD6
	mov r1, ip
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #0
	bne _0809EE12
	movs r0, #1
	strb r0, [r1]
	movs r4, #0
	mov r0, ip
	adds r0, #0x26
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	bge _0809EE12
	mov r3, ip
	adds r3, #0xc6
	movs r6, #0
	mov r7, ip
	adds r7, #0x34
_0809EDB0:
	ldrb r0, [r3, #3]
	cmp r0, #0
	beq _0809EDC8
	ldrb r0, [r3]
	cmp r0, #0
	beq _0809EDC8
	adds r0, r7, r6
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0809EDC8:
	adds r3, #0xa8
	adds r6, #0xa8
	adds r4, #1
	ldrb r2, [r5]
	cmp r4, r2
	blt _0809EDB0
	b _0809EE12
_0809EDD6:
	mov r1, ip
	adds r1, #0x28
	ldrb r0, [r1]
	cmp r0, #1
	bne _0809EE12
	strb r2, [r1]
	movs r4, #0
	mov r0, ip
	adds r0, #0x26
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	bge _0809EE12
	movs r6, #1
	mov r2, ip
	adds r2, #0xc9
	mov r1, ip
	adds r3, r5, #0
_0809EDFA:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0809EE06
	ldr r0, [r1, #0x34]
	orrs r0, r6
	str r0, [r1, #0x34]
_0809EE06:
	adds r2, #0xa8
	adds r1, #0xa8
	adds r4, #1
	ldrb r0, [r3]
	cmp r4, r0
	blt _0809EDFA
_0809EE12:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809ee18
FUN_0809ee18: @ 0x0809EE18
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0809EE38 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809EE3C @ =0x00000934
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809EE40
	adds r0, r4, #0
	bl FUN_0809ed54
	b _0809EE46
	.align 2, 0
_0809EE38: .4byte 0x030046A0
_0809EE3C: .4byte 0x00000934
_0809EE40:
	adds r0, r4, #0
	bl FUN_0809ed58
_0809EE46:
	adds r0, r4, #0
	bl FUN_0809ec60
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ee54
FUN_0809ee54: @ 0x0809EE54
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _0809EE78
_0809EE5C:
	movs r0, #0xa8
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809EE74
	adds r0, r1, r4
	adds r0, #0x34
	bl FUN_0822a4e0
_0809EE74:
	adds r5, #1
	adds r0, r4, #0
_0809EE78:
	adds r0, #0x26
	ldrb r0, [r0]
	cmp r5, r0
	blt _0809EE5C
	ldr r1, _0809EE8C @ =0x03000140
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809EE8C: .4byte 0x03000140

	thumb_func_start FUN_0809ee90
FUN_0809ee90: @ 0x0809EE90
	adds r2, r0, #0
	adds r2, #0x26
	movs r1, #0
	strb r1, [r2]
	movs r2, #0
	movs r1, #0xcd
	lsls r1, r1, #1
	strh r1, [r0, #0x24]
	adds r1, r0, #0
	adds r1, #0x28
	strb r2, [r1]
	ldr r1, _0809EEB0 @ =0x03000140
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_0809EEB0: .4byte 0x03000140

	thumb_func_start FUN_0809eeb4
FUN_0809eeb4: @ 0x0809EEB4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _0809EEE8 @ =0x00000AB4
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809EEF4
	ldr r1, _0809EEEC @ =FUN_0809ee18
	ldr r2, _0809EEF0 @ =FUN_0809ee54
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0809ee90
	cmp r0, #0
	bge _0809EEF4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809EEF6
	.align 2, 0
_0809EEE8: .4byte 0x00000AB4
_0809EEEC: .4byte FUN_0809ee18
_0809EEF0: .4byte FUN_0809ee54
_0809EEF4:
	adds r0, r4, #0
_0809EEF6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809eefc
FUN_0809eefc: @ 0x0809EEFC
	push {lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldr r0, _0809EF24 @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	bne _0809EF34
	ldr r0, _0809EF28 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0809EF2C
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0809eb24
	b _0809EF34
	.align 2, 0
_0809EF24: .4byte 0x03000140
_0809EF28: .4byte 0x030047A4
_0809EF2C:
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0809eeb4
_0809EF34:
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ef38
FUN_0809ef38: @ 0x0809EF38
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0809EF98 @ =0x00000252
	adds r0, r4, r2
	movs r5, #0x2e
	ldrsh r1, [r3, r5]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bne _0809F024
	movs r5, #0x2c
	ldrsh r0, [r3, r5]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r2, r0, r1
	cmp r2, #0
	bge _0809EF6A
	rsbs r2, r2, #0
_0809EF6A:
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	movs r5, #0x95
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _0809EF80
	rsbs r0, r0, #0
_0809EF80:
	cmp r2, #0x80
	bgt _0809F024
	cmp r0, #0x80
	bgt _0809F024
	ldr r1, [r3, #0x1c]
	cmp r1, #1
	beq _0809EF9C
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r4, r2
	b _0809F02A
	.align 2, 0
_0809EF98: .4byte 0x00000252
_0809EF9C:
	movs r5, #0x98
	lsls r5, r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	ldr r0, _0809F018 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0809EFB8
	ldr r0, _0809F01C @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _0809EFB8
	movs r1, #1
_0809EFB8:
	cmp r1, #0
	bne _0809F02E
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0809F02E
	cmp r0, #3
	beq _0809F02E
	cmp r0, #4
	beq _0809F02E
	movs r5, #0xe0
	lsls r5, r5, #2
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F02E
	adds r1, #0x34
	adds r0, r3, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809F02E
	adds r2, #0x24
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #7
	bne _0809F02E
	movs r5, #0x94
	lsls r5, r5, #2
	adds r1, r4, r5
	ldr r2, _0809F020 @ =0x00000262
	adds r0, r4, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl FUN_0807a528
	adds r5, #0xe
	adds r1, r4, r5
	movs r0, #1
	b _0809F02C
	.align 2, 0
_0809F018: .4byte 0x03002B8C
_0809F01C: .4byte 0x03002B60
_0809F020: .4byte 0x00000262
_0809F024:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r4, r0
_0809F02A:
	movs r0, #0
_0809F02C:
	strb r0, [r1]
_0809F02E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809f034
FUN_0809f034: @ 0x0809F034
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0x96
	lsls r0, r0, #2
	adds r6, r4, r0
	ldr r2, [r6]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _0809F090
	movs r1, #0x40
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809F0A2
	ldr r0, _0809F08C @ =0x030046A0
	ldr r0, [r0]
	movs r7, #0xef
	lsls r7, r7, #2
	adds r5, r0, r7
	ldr r3, [r5]
	cmp r3, #0
	ble _0809F0A2
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	subs r7, #0x52
	adds r1, r2, r7
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0809F0A2
	subs r0, r3, #1
	str r0, [r5]
	ldr r1, [r6]
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0809F0A2
	.align 2, 0
_0809F08C: .4byte 0x030046A0
_0809F090:
	adds r0, r4, #0
	adds r0, #0x44
	ldr r1, _0809F0B4 @ =0x0000013D
	bl FUN_0822b20c
	ldr r7, _0809F0B8 @ =0x0000025E
	adds r1, r4, r7
	movs r0, #0
	strb r0, [r1]
_0809F0A2:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809F0B4: .4byte 0x0000013D
_0809F0B8: .4byte 0x0000025E

	thumb_func_start FUN_0809f0bc
FUN_0809f0bc: @ 0x0809F0BC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x40
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0809F138
	ldr r1, _0809F0EC @ =0x0000025F
	adds r0, r5, r1
	ldrb r0, [r0]
	lsrs r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	beq _0809F0FA
	cmp r1, #1
	bgt _0809F0F0
	cmp r1, #0
	beq _0809F10C
	b _0809F124
	.align 2, 0
_0809F0EC: .4byte 0x0000025F
_0809F0F0:
	cmp r1, #2
	beq _0809F10C
	cmp r1, #3
	beq _0809F11A
	b _0809F124
_0809F0FA:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F108 @ =0x0000013F
	bl FUN_0822b20c
	b _0809F124
	.align 2, 0
_0809F108: .4byte 0x0000013F
_0809F10C:
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #0x9f
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _0809F124
_0809F11A:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F130 @ =0x0000013D
	bl FUN_0822b20c
_0809F124:
	ldr r0, _0809F134 @ =0x0000025F
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0809F170
	.align 2, 0
_0809F130: .4byte 0x0000013D
_0809F134: .4byte 0x0000025F
_0809F138:
	ldr r1, _0809F160 @ =0x0000025F
	adds r4, r5, r1
	ldrb r0, [r4]
	cmp r0, #4
	bls _0809F146
	movs r0, #4
	strb r0, [r4]
_0809F146:
	ldrb r6, [r4]
	cmp r6, #0
	beq _0809F164
	adds r0, r5, #0
	adds r0, #0x44
	movs r1, #0x9f
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _0809F170
	.align 2, 0
_0809F160: .4byte 0x0000025F
_0809F164:
	adds r0, r5, #0
	adds r0, #0x44
	ldr r1, _0809F178 @ =0x0000013D
	bl FUN_0822b20c
	strb r6, [r4]
_0809F170:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F178: .4byte 0x0000013D

	thumb_func_start FUN_0809f17c
FUN_0809f17c: @ 0x0809F17C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	movs r0, #0x98
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	cmp r0, #0
	bne _0809F198
	b _0809F2E4
_0809F198:
	ldr r5, _0809F218 @ =0x030046A0
	ldr r0, [r5]
	movs r4, #0xef
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	ldr r2, _0809F21C @ =0x0000270F
	cmp r0, r2
	ble _0809F1AC
	str r2, [r1]
_0809F1AC:
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	bl Div
	str r0, [sp]
	ldr r2, [r5]
	adds r2, r2, r4
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r4, [r2]
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #0xc]
	add r5, sp, #0x10
	mov r6, r8
	adds r6, #0x34
	mov r1, r8
	ldrh r0, [r1, #0x34]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0809F220
	asrs r0, r0, #8
	b _0809F226
	.align 2, 0
_0809F218: .4byte 0x030046A0
_0809F21C: .4byte 0x0000270F
_0809F220:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F226:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0809F238
	asrs r0, r0, #8
	b _0809F23E
_0809F238:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F23E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0809F252
	asrs r0, r0, #8
	b _0809F258
_0809F252:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0809F258:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0809F2E0 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	mov r1, sp
	ldrh r0, [r1, #0x10]
	subs r0, #0x10
	add r1, sp, #0x10
	strh r0, [r1]
	ldrh r0, [r1, #2]
	subs r0, #0x2c
	strh r0, [r1, #2]
	movs r0, #0x60
	add r0, r8
	mov sl, r0
	mov r7, r8
	adds r7, #0xa0
	mov sb, sp
	mov r6, r8
	adds r6, #0x80
	mov r4, r8
	adds r4, #0x88
	movs r5, #3
_0809F29C:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, sb
	adds r1, #4
	mov sb, r1
	subs r1, #4
	ldm r1!, {r2}
	adds r2, #0x1e
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	movs r3, #1
	bl FUN_0822f3cc
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r7]
	str r1, [r7, #4]
	mov r1, sp
	ldrh r0, [r1, #0x10]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	adds r7, #0x60
	adds r6, #0x60
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F29C
	b _0809F2FA
	.align 2, 0
_0809F2E0: .4byte 0x030047C8
_0809F2E4:
	movs r2, #1
	mov r1, r8
	adds r1, #0x88
	movs r5, #3
_0809F2EC:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F2EC
_0809F2FA:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809f30c
FUN_0809f30c: @ 0x0809F30C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	mov r1, sp
	bl FUN_08230f94
	adds r2, r0, #0
	subs r2, #1
	cmp r0, #0
	ble _0809F356
	ldr r0, _0809F340 @ =0x00000261
	adds r3, r4, r0
	ldr r1, [sp]
	movs r5, #1
	movs r4, #0
_0809F332:
	ldr r0, [r1, #4]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809F344
	cmp r0, #1
	beq _0809F348
	b _0809F34A
	.align 2, 0
_0809F340: .4byte 0x00000261
_0809F344:
	strb r5, [r3]
	b _0809F34A
_0809F348:
	strb r4, [r3]
_0809F34A:
	adds r1, #8
	adds r0, r2, #0
	subs r2, #1
	cmp r0, #0
	bgt _0809F332
	str r1, [sp]
_0809F356:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F360:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0xFF, 0xF7, 0xD2, 0xFF, 0x03, 0x49, 0x60, 0x18, 0x00, 0x78, 0x00, 0x28
	.byte 0x04, 0xD0, 0x01, 0x28, 0x06, 0xD0, 0x08, 0xE0, 0x5E, 0x02, 0x00, 0x00, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0xDB, 0xFD, 0x02, 0xE0, 0x20, 0x1C, 0xFF, 0xF7, 0x55, 0xFE, 0x20, 0x1C, 0xFF, 0xF7, 0x96, 0xFE
	.byte 0x20, 0x1C, 0xFF, 0xF7, 0xF3, 0xFE, 0x00, 0x20, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	.byte 0x70, 0xB5, 0x06, 0x1C, 0x18, 0x30, 0x8B, 0xF1, 0x9B, 0xF8, 0x34, 0x1C, 0x80, 0x34, 0x03, 0x25
	.byte 0x20, 0x1C, 0x8F, 0xF1, 0x05, 0xFF, 0x60, 0x34, 0x01, 0x3D, 0x00, 0x2D, 0xF8, 0xDA, 0x80, 0x21
	.byte 0x89, 0x00, 0x70, 0x18, 0x97, 0xF1, 0x2E, 0xF8, 0x00, 0x20, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_0809f3d0
FUN_0809f3d0: @ 0x0809F3D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x18
	adds r4, #0x44
	ldr r1, _0809F40C @ =0x0000A47C
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r5, #0x10]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0809F410
	bl fetch_082316e4
	strh r0, [r5, #0x1c]
	bl fetch_082316e4
	strh r0, [r5, #0x1e]
	bl fetch_082316e4
	b _0809F414
	.align 2, 0
_0809F40C: .4byte 0x0000A47C
_0809F410:
	strh r0, [r5, #0x1c]
	strh r0, [r5, #0x1e]
_0809F414:
	strh r0, [r5, #0x20]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0809F42A
	bl fetch_082316e4
	cmp r0, #0
	beq _0809F42A
	movs r0, #4
_0809F42A:
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809f434
FUN_0809f434: @ 0x0809F434
	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _0809F4A4 @ =0x0000CB05
	ldr r1, _0809F4A8 @ =0x0000B343
	bl FUN_082310cc
	adds r2, r0, #0
	cmp r2, #0
	beq _0809F49A
	adds r1, r5, #0
	adds r1, #0x60
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x60
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _0809F4AC @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	adds r6, r4, #0
	adds r4, #0x20
	movs r5, #3
_0809F476:
	movs r0, #1
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x1e
	movs r3, #0x31
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809F476
_0809F49A:
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809F4A4: .4byte 0x0000CB05
_0809F4A8: .4byte 0x0000B343
_0809F4AC: .4byte 0xFFFF0000

	thumb_func_start FUN_0809f4b0
FUN_0809f4b0: @ 0x0809F4B0
	push {lr}
	adds r2, r0, #0
	movs r0, #0x94
	lsls r0, r0, #2
	adds r3, r2, r0
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r0, [r2, #0x18]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809F4D8
	adds r1, #0xfc
	adds r0, r1, #0
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	b _0809F4EA
_0809F4D8:
	movs r0, #0x95
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_0809F4EA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0809f4f0
FUN_0809f4f0: @ 0x0809F4F0
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r2, _0809F570 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _0809F574 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x96
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0809F578 @ =0x00004001
	movs r0, #0
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0x34
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809F570: .4byte 0xFFFF0000
_0809F574: .4byte 0x0000FFFF
_0809F578: .4byte 0x00004001

	thumb_func_start FUN_0809f57c
FUN_0809f57c: @ 0x0809F57C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r2, r1, #0
	ldr r0, _0809F598 @ =0x03002BE0
	ldr r1, [r0]
	movs r3, #0x96
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	cmp r1, #0
	bne _0809F59C
	movs r0, #1
	rsbs r0, r0, #0
	b _0809F5FA
	.align 2, 0
_0809F598: .4byte 0x03002BE0
_0809F59C:
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r4, #0
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_0809f3d0
	adds r0, r5, #0
	bl FUN_0809f4b0
	adds r0, r5, #0
	bl FUN_0809f4f0
	adds r0, r5, #0
	bl FUN_0809f434
	ldr r3, _0809F5EC @ =0x0000025E
	adds r0, r5, r3
	strb r4, [r0]
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	subs r1, #1
	adds r0, r5, r1
	strb r4, [r0]
	ldr r0, [r5, #0x18]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0809F5F0
	adds r3, #1
	adds r1, r5, r3
	movs r0, #7
	b _0809F5F6
	.align 2, 0
_0809F5EC: .4byte 0x0000025E
_0809F5F0:
	ldr r0, _0809F600 @ =0x00000262
	adds r1, r5, r0
	movs r0, #1
_0809F5F6:
	strh r0, [r1]
	movs r0, #0
_0809F5FA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0809F600: .4byte 0x00000262

	thumb_func_start FUN_0809f604
FUN_0809f604: @ 0x0809F604
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x99
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809F644
	ldr r1, _0809F63C @ =0x0809F361
	ldr r2, _0809F640 @ =0x0809F3A1
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0809f57c
	cmp r0, #0
	bge _0809F644
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809F646
	.align 2, 0
_0809F63C: .4byte 0x0809F361
_0809F640: .4byte 0x0809F3A1
_0809F644:
	adds r0, r4, #0
_0809F646:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_0809F64C:
	.byte 0x01, 0x49, 0x00, 0x20
	.byte 0x08, 0x60, 0x70, 0x47, 0x44, 0x01, 0x00, 0x03

	thumb_func_start FUN_0809f658
FUN_0809f658: @ 0x0809F658
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _0809F668 @ =0x03000144
	ldr r0, [r0]
	cmp r0, #0
	bne _0809F676
	b _0809F6E4
	.align 2, 0
_0809F668: .4byte 0x03000144
_0809F66C:
	adds r1, r3, #0
	adds r1, #0xdf
	movs r0, #1
	strb r0, [r1]
	b _0809F6E6
_0809F676:
	movs r4, #0
	ldrh r1, [r0, #0x18]
	cmp r4, r1
	bge _0809F6E4
	mov ip, r0
	adds r6, r1, #0
_0809F682:
	movs r0, #0xf4
	muls r0, r4, r0
	adds r0, #0x1c
	mov r1, ip
	adds r3, r1, r0
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F6DE
	movs r2, #0x1e
	ldrsh r1, [r3, r2]
	movs r7, #2
	ldrsh r0, [r5, r7]
	cmp r1, r0
	blt _0809F6DE
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r2, #0x1c
	ldrsh r0, [r3, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _0809F6B2
	rsbs r2, r2, #0
_0809F6B2:
	cmp r2, #0x80
	bgt _0809F6DE
	movs r7, #4
	ldrsh r1, [r5, r7]
	movs r7, #0x20
	ldrsh r0, [r3, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _0809F6C6
	rsbs r1, r1, #0
_0809F6C6:
	cmp r1, #0x80
	bgt _0809F6DE
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	ble _0809F66C
_0809F6DE:
	adds r4, #1
	cmp r4, r6
	blt _0809F682
_0809F6E4:
	movs r0, #0
_0809F6E6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809f6ec
FUN_0809f6ec: @ 0x0809F6EC
	push {r4, r5, lr}
	ldr r4, _0809F704 @ =0x03000144
	ldr r0, [r4]
	cmp r0, #0
	beq _0809F738
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _0809F710
	b _0809F738
	.align 2, 0
_0809F704: .4byte 0x03000144
_0809F708:
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r0, [r0]
	b _0809F73C
_0809F710:
	bl fetch_082316e4
	adds r5, r0, #0
	movs r3, #0
	ldr r0, [r4]
	ldrh r1, [r0, #0x18]
	cmp r3, r1
	bge _0809F738
	adds r4, r1, #0
	adds r1, r0, #0
	adds r1, #0xfc
	adds r2, r0, #0
_0809F728:
	ldrh r0, [r1]
	cmp r0, r5
	beq _0809F708
	adds r1, #0xf4
	adds r2, #0xf4
	adds r3, #1
	cmp r3, r4
	blt _0809F728
_0809F738:
	movs r0, #1
	rsbs r0, r0, #0
_0809F73C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809f744
FUN_0809f744: @ 0x0809F744
	mov ip, r0
	adds r0, #0xdc
	movs r3, #0
	strb r1, [r0]
	adds r0, #0x14
	str r2, [r0]
	subs r0, #4
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809f75c
FUN_0809f75c: @ 0x0809F75C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r3, r2, #0
	adds r5, r3, #0
	adds r6, r7, #0
	adds r6, #0x44
	ldrh r0, [r6]
	cmp r0, #0
	bne _0809F7F6
	movs r1, #4
	ldr r0, [r4, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0809F7F6
	ldr r2, [r4, #0x38]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0809F7BC
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7A0
	ldr r2, _0809F79C @ =FUN_0809f938
	adds r0, r3, #0
	movs r1, #2
	bl FUN_0809f744
	b _0809F7AE
	.align 2, 0
_0809F79C: .4byte FUN_0809f938
_0809F7A0:
	cmp r0, #1
	bne _0809F7AE
	ldr r2, _0809F7B8 @ =FUN_0809f890
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809F7AE:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0x1e
	strh r0, [r1]
	b _0809F7F6
	.align 2, 0
_0809F7B8: .4byte FUN_0809f890
_0809F7BC:
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _0809F7E4
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7D8
	ldr r2, _0809F7E0 @ =FUN_0809f840
	adds r0, r3, #0
	movs r1, #1
	bl FUN_0809f744
_0809F7D8:
	movs r0, #0x1e
	strh r0, [r6]
	b _0809F7F6
	.align 2, 0
_0809F7E0: .4byte FUN_0809f840
_0809F7E4:
	adds r0, r5, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7F6
	adds r1, r5, #0
	adds r1, #0xdf
	movs r0, #1
	strb r0, [r1]
_0809F7F6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809f7fc
FUN_0809f7fc: @ 0x0809F7FC
	push {lr}
	adds r3, r0, #0
	ldr r0, _0809F830 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809F834 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0809F82C
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _0809F838 @ =0x012B0000
	cmp r1, r0
	ble _0809F82C
	ldr r2, _0809F83C @ =FUN_0809f890
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809F82C:
	pop {r0}
	bx r0
	.align 2, 0
_0809F830: .4byte 0x030046A0
_0809F834: .4byte 0x00000942
_0809F838: .4byte 0x012B0000
_0809F83C: .4byte FUN_0809f890

	thumb_func_start FUN_0809f840
FUN_0809f840: @ 0x0809F840
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xee
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809F854
	ldr r0, _0809F868 @ =0x0000019F
	bl PlaySound_082406e0
_0809F854:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F86C
	movs r0, #3
	strh r0, [r5, #0x10]
	b _0809F884
	.align 2, 0
_0809F868: .4byte 0x0000019F
_0809F86C:
	cmp r0, #0xf
	bhi _0809F876
	movs r0, #4
	strh r0, [r5, #0x10]
	b _0809F884
_0809F876:
	movs r0, #5
	strh r0, [r5, #0x10]
	ldr r2, _0809F88C @ =FUN_0809f7fc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0809f744
_0809F884:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F88C: .4byte FUN_0809f7fc

	thumb_func_start FUN_0809f890
FUN_0809f890: @ 0x0809F890
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xee
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809F8A6
	movs r0, #0xd0
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809F8A6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F8BA
	movs r0, #4
	strh r0, [r5, #0x10]
	b _0809F8DA
_0809F8BA:
	cmp r0, #0xf
	bhi _0809F8C4
	movs r0, #3
	strh r0, [r5, #0x10]
	b _0809F8DA
_0809F8C4:
	movs r0, #2
	strh r0, [r5, #0x10]
	movs r0, #0xd0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _0809F8E0 @ =FUN_0809fabc
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0809f744
_0809F8DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F8E0: .4byte FUN_0809fabc

	thumb_func_start FUN_0809f8e4
FUN_0809f8e4: @ 0x0809F8E4
	push {lr}
	adds r3, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _0809F900 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0809F904 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809F908
	movs r0, #1
	b _0809F90A
	.align 2, 0
_0809F900: .4byte 0x030046A0
_0809F904: .4byte 0x00000934
_0809F908:
	movs r0, #0
_0809F90A:
	cmp r0, #0
	beq _0809F92A
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _0809F930 @ =0x012B0000
	cmp r1, r0
	ble _0809F92A
	ldr r2, _0809F934 @ =FUN_0809fa80
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809F92A:
	pop {r0}
	bx r0
	.align 2, 0
_0809F930: .4byte 0x012B0000
_0809F934: .4byte FUN_0809fa80

	thumb_func_start FUN_0809f938
FUN_0809f938: @ 0x0809F938
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xee
	ldrh r0, [r5]
	cmp r0, #0
	bne _0809F954
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809F954:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F9D8
	movs r0, #6
	strh r0, [r4, #0x10]
	ldrh r1, [r5]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0809F972
	b _0809FA6E
_0809F972:
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r6, _0809F9C8 @ =0x0203B400
	ldr r5, _0809F9CC @ =0x030046B8
	ldr r2, [r5]
	adds r2, #1
	ldr r4, _0809F9D0 @ =0x000003FF
	ands r2, r4
	lsls r3, r2, #1
	adds r3, r3, r6
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x7f
	ldrb r3, [r3]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0809F9D4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r2, r2, #1
	adds r2, r2, r6
	add r0, sp, #4
	ldrh r0, [r0, #4]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	add r0, sp, #4
	str r0, [sp]
	b _0809FA40
	.align 2, 0
_0809F9C8: .4byte 0x0203B400
_0809F9CC: .4byte 0x030046B8
_0809F9D0: .4byte 0x000003FF
_0809F9D4: .4byte 0xFFFF0000
_0809F9D8:
	cmp r0, #0xf
	bhi _0809FA60
	movs r0, #7
	strh r0, [r4, #0x10]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0809FA6E
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, _0809FA50 @ =0x0203B400
	mov r8, r0
	ldr r6, _0809FA54 @ =0x030046B8
	ldr r2, [r6]
	adds r2, #1
	ldr r4, _0809FA58 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	add r0, r8
	add r3, sp, #0xc
	ldrh r1, [r3]
	subs r1, #0x7f
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _0809FA5C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r2, #1
	ands r2, r4
	str r2, [r6]
	lsls r2, r2, #1
	add r2, r8
	ldrh r0, [r3, #4]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [r3, #4]
	str r3, [sp]
_0809FA40:
	movs r0, #1
	movs r1, #0
	movs r2, #1
	movs r3, #0x40
	bl FUN_08015c90
	b _0809FA6E
	.align 2, 0
_0809FA50: .4byte 0x0203B400
_0809FA54: .4byte 0x030046B8
_0809FA58: .4byte 0x000003FF
_0809FA5C: .4byte 0xFFFF0000
_0809FA60:
	movs r0, #8
	strh r0, [r4, #0x10]
	ldr r2, _0809FA7C @ =FUN_0809f8e4
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809f744
_0809FA6E:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809FA7C: .4byte FUN_0809f8e4

	thumb_func_start FUN_0809fa80
FUN_0809fa80: @ 0x0809FA80
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xee
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809FA9C
	movs r0, #7
	strh r0, [r3, #0x10]
	b _0809FAB4
_0809FA9C:
	cmp r0, #0xf
	bhi _0809FAA6
	movs r0, #6
	strh r0, [r3, #0x10]
	b _0809FAB4
_0809FAA6:
	movs r0, #2
	strh r0, [r3, #0x10]
	ldr r2, _0809FAB8 @ =FUN_0809fabc
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809FAB4:
	pop {r0}
	bx r0
	.align 2, 0
_0809FAB8: .4byte FUN_0809fabc

	thumb_func_start FUN_0809fabc
FUN_0809fabc: @ 0x0809FABC
	push {lr}
	adds r3, r0, #0
	movs r0, #0xdf
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FAF4
	adds r2, r3, #0
	adds r2, #0xe5
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	mov r0, ip
	strb r1, [r0]
	adds r2, #9
	ldrh r1, [r2]
	cmp r1, #0x3f
	bls _0809FAEE
	ldrh r0, [r2]
	subs r0, #0x40
	movs r1, #0x1f
	ands r0, r1
	asrs r0, r0, #1
	b _0809FAF2
_0809FAEE:
	movs r0, #0xf
	ands r0, r1
_0809FAF2:
	strh r0, [r2]
_0809FAF4:
	movs r1, #0xe5
	adds r1, r1, r3
	mov ip, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809FB46
	adds r2, r3, #0
	adds r2, #0xee
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bls _0809FB22
	movs r0, #2
	strh r0, [r3, #0x10]
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	movs r0, #0
	strh r0, [r2]
	b _0809FB46
_0809FB22:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bhi _0809FB36
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bhi _0809FB42
	movs r0, #1
	b _0809FB44
_0809FB36:
	movs r0, #0x1f
	ands r1, r0
	cmp r1, #0xf
	bhi _0809FB42
	movs r0, #1
	b _0809FB44
_0809FB42:
	movs r0, #2
_0809FB44:
	strh r0, [r3, #0x10]
_0809FB46:
	ldr r0, _0809FB78 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809FB7C @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	cmp r2, #0
	bne _0809FBA8
	adds r0, r3, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809FB80
	adds r1, r3, #0
	adds r1, #0xec
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0809FBEE
	strh r2, [r1]
	b _0809FBEE
	.align 2, 0
_0809FB78: .4byte 0x030046A0
_0809FB7C: .4byte 0x00000942
_0809FB80:
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r0, _0809FBA0 @ =0xFFFFFED4
	cmp r1, r0
	bge _0809FBEE
	ldr r2, _0809FBA4 @ =FUN_0809f840
	adds r0, r3, #0
	movs r1, #1
	bl FUN_0809f744
	b _0809FBEE
	.align 2, 0
_0809FBA0: .4byte 0xFFFFFED4
_0809FBA4: .4byte FUN_0809f840
_0809FBA8:
	cmp r2, #7
	ble _0809FBEE
	adds r0, r3, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809FBD0
	adds r1, r3, #0
	adds r1, #0xec
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0809FBEE
	movs r0, #0
	strh r0, [r1]
	b _0809FBEE
_0809FBD0:
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0x96
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _0809FBEE
	ldr r2, _0809FBF4 @ =FUN_0809f938
	adds r0, r3, #0
	movs r1, #2
	bl FUN_0809f744
_0809FBEE:
	pop {r0}
	bx r0
	.align 2, 0
_0809FBF4: .4byte FUN_0809f938

	thumb_func_start FUN_0809fbf8
FUN_0809fbf8: @ 0x0809FBF8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0xe6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FCC4
	adds r0, r4, #0
	adds r0, #0xe8
	ldrh r1, [r0]
	ldr r0, _0809FC40 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	bne _0809FC48
	adds r0, r4, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809FC30
	adds r2, r4, #0
	adds r2, #0x92
	ldrh r1, [r2]
	ldr r0, _0809FC44 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0809FC30:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _0809FCD0
	.align 2, 0
_0809FC40: .4byte 0x030046A0
_0809FC44: .4byte 0x0000FFFB
_0809FC48:
	adds r0, r4, #0
	adds r0, #0xe7
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _0809FCD0
	subs r0, #0xb
	ldrb r5, [r0]
	cmp r5, #0
	bne _0809FC7C
	ldr r2, _0809FC78 @ =FUN_0809fabc
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0809f744
	movs r0, #0
	strh r5, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0xe5
	strb r0, [r1]
	subs r1, #6
	strb r0, [r1]
	b _0809FCAE
	.align 2, 0
_0809FC78: .4byte FUN_0809fabc
_0809FC7C:
	cmp r5, #2
	bne _0809FC94
	ldr r2, _0809FC90 @ =FUN_0809f8e4
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809f744
	movs r0, #8
	b _0809FCA4
	.align 2, 0
_0809FC90: .4byte FUN_0809f8e4
_0809FC94:
	cmp r5, #1
	bne _0809FCAE
	ldr r2, _0809FCC0 @ =FUN_0809f7fc
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809f744
	movs r0, #5
_0809FCA4:
	strh r0, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0xe2
	movs r0, #0x10
	strh r0, [r1]
_0809FCAE:
	adds r3, r4, #0
	adds r3, #0x92
	ldrh r0, [r3]
	movs r1, #4
	movs r2, #0
	orrs r1, r0
	strh r1, [r3]
	strb r2, [r6]
	b _0809FCD0
	.align 2, 0
_0809FCC0: .4byte FUN_0809f7fc
_0809FCC4:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0809FCD0:
	adds r1, r4, #0
	adds r1, #0xd0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809FCDE
	subs r0, #1
	strh r0, [r1]
_0809FCDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809fce4
FUN_0809fce4: @ 0x0809FCE4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r2, #0
	ldr r2, [sp, #0x18]
	adds r0, #0xe0
	movs r5, #0
	movs r4, #0
	strh r1, [r0]
	subs r0, #4
	strb r3, [r0]
	adds r0, #6
	strh r4, [r0]
	adds r0, #3
	strb r5, [r0]
	subs r0, #6
	strb r5, [r0]
	subs r0, #2
	mov r1, sp
	ldrb r1, [r1, #0x14]
	strb r1, [r0]
	adds r0, #9
	strb r2, [r0]
	lsls r2, r2, #0x18
	cmp r2, #0
	beq _0809FD22
	adds r0, r6, #0
	bl FUN_08241574
	adds r1, r7, #0
	adds r1, #0xe8
	strh r0, [r1]
_0809FD22:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809fd28
FUN_0809fd28: @ 0x0809FD28
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r4, r7, #0
	adds r4, #0x2c
	ldr r1, _0809FD90 @ =0x0000A680
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r4, #0
	movs r1, #0x43
	bl FUN_0822b20c
	movs r0, #3
	strb r0, [r7, #7]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0xe4
	strb r5, [r0]
	lsls r5, r5, #0x18
	cmp r5, #0
	beq _0809FD86
	adds r4, #0x1c
	subs r0, #4
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	bl FUN_08002a48
_0809FD86:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809FD90: .4byte 0x0000A680

	thumb_func_start FUN_0809fd94
FUN_0809fd94: @ 0x0809FD94
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r2, _0809FE0C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _0809FE10 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0xe0
	ldrh r1, [r0]
	ldr r2, _0809FE14 @ =0x00004003
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0809FE18 @ =FUN_0809f75c
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r5, #0x3e]
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809FE0C: .4byte 0xFFFF0000
_0809FE10: .4byte 0x0000FFFF
_0809FE14: .4byte 0x00004003
_0809FE18: .4byte FUN_0809f75c

	thumb_func_start FUN_0809fe1c
FUN_0809fe1c: @ 0x0809FE1C
	push {lr}
	adds r1, r0, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809FE3C
	strh r0, [r1, #0x10]
	ldr r2, _0809FE38 @ =FUN_0809fabc
	adds r0, r1, #0
	movs r1, #0
	bl FUN_0809f744
	b _0809FE66
	.align 2, 0
_0809FE38: .4byte FUN_0809fabc
_0809FE3C:
	cmp r0, #2
	bne _0809FE54
	movs r0, #8
	strh r0, [r1, #0x10]
	ldr r2, _0809FE50 @ =FUN_0809f8e4
	adds r0, r1, #0
	movs r1, #2
	bl FUN_0809f744
	b _0809FE66
	.align 2, 0
_0809FE50: .4byte FUN_0809f8e4
_0809FE54:
	cmp r0, #1
	bne _0809FE66
	movs r0, #5
	strh r0, [r1, #0x10]
	ldr r2, _0809FE6C @ =FUN_0809f7fc
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0809f744
_0809FE66:
	pop {r0}
	bx r0
	.align 2, 0
_0809FE6C: .4byte FUN_0809f7fc

	thumb_func_start FUN_0809fe70
FUN_0809fe70: @ 0x0809FE70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r2
	ldr r7, [sp, #0x20]
	ldr r5, [sp, #0x24]
	ldr r6, [sp, #0x28]
	ldrh r2, [r4, #0x18]
	movs r0, #0xf4
	muls r0, r2, r0
	adds r0, #0x1c
	adds r4, r4, r0
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r2, r8
	bl FUN_0809fce4
	adds r0, r4, #0
	mov r1, r8
	adds r2, r7, #0
	bl FUN_0809fd28
	adds r0, r4, #0
	bl FUN_0809fd94
	adds r0, r4, #0
	bl FUN_0809fe1c
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809FEBC:
	.byte 0x70, 0xB5, 0x06, 0x1C
	.byte 0x00, 0x25, 0x30, 0x8B, 0x85, 0x42, 0x09, 0xDA, 0x34, 0x1C, 0x1C, 0x34, 0x20, 0x1C, 0xFF, 0xF7
	.byte 0x93, 0xFE, 0xF4, 0x34, 0x01, 0x35, 0x30, 0x8B, 0x85, 0x42, 0xF7, 0xDB, 0x00, 0x20, 0x70, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_0809fee4
FUN_0809fee4: @ 0x0809FEE4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	b _0809FF1C
_0809FEEC:
	movs r0, #0xf4
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r5, r4
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FF08
	adds r0, r4, r5
	adds r0, #0x64
	bl FUN_0823b284
_0809FF08:
	adds r4, #0x1c
	adds r4, r5, r4
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x8c
	adds r0, r4, #0
	bl FUN_08236424
	adds r6, #1
_0809FF1C:
	ldrh r0, [r5, #0x18]
	cmp r6, r0
	blt _0809FEEC
	ldr r1, _0809FF30 @ =0x03000144
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809FF30: .4byte 0x03000144

	thumb_func_start FUN_0809ff34
FUN_0809ff34: @ 0x0809FF34
	movs r1, #0
	strh r1, [r0, #0x18]
	ldr r1, _0809FF40 @ =0x03000144
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_0809FF40: .4byte 0x03000144

	thumb_func_start FUN_0809ff44
FUN_0809ff44: @ 0x0809FF44
	push {r4, lr}
	ldr r1, _0809FF70 @ =0x000007BC
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809FF7C
	ldr r1, _0809FF74 @ =0x0809FEBD
	ldr r2, _0809FF78 @ =FUN_0809fee4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0809ff34
	cmp r0, #0
	bge _0809FF7C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809FF7E
	.align 2, 0
_0809FF70: .4byte 0x000007BC
_0809FF74: .4byte 0x0809FEBD
_0809FF78: .4byte FUN_0809fee4
_0809FF7C:
	adds r0, r4, #0
_0809FF7E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ff84
FUN_0809ff84: @ 0x0809FF84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	ldr r0, _0809FFB0 @ =0x03000144
	ldr r6, [r0]
	cmp r6, #0
	bne _0809FF9A
	bl FUN_0809ff44
	adds r6, r0, #0
_0809FF9A:
	ldrh r0, [r6, #0x18]
	cmp r0, #7
	bhi _080A0074
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0809FFB4
	bl fetch_082316e4
	b _0809FFB6
	.align 2, 0
_0809FFB0: .4byte 0x03000144
_0809FFB4:
	movs r0, #0
_0809FFB6:
	mov r8, r0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A0000
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0809FFF8 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _0809FFFC @ =0x0000FFFF
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	b _080A000A
	.align 2, 0
_0809FFF8: .4byte 0xFFFF0000
_0809FFFC: .4byte 0x0000FFFF
_080A0000:
	ldr r1, _080A001C @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_080A000A:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080A0020
	bl fetch_082316e4
	adds r7, r0, #0
	b _080A0022
	.align 2, 0
_080A001C: .4byte 0xFFFF0000
_080A0020:
	movs r7, #0
_080A0022:
	movs r0, #0x68
	bl prepare_08231510
	cmp r0, #0
	beq _080A0034
	bl fetch_082316e4
	adds r5, r0, #0
	b _080A0036
_080A0034:
	movs r5, #0
_080A0036:
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A0048
	bl fetch_082316e4
	adds r4, r0, #0
	b _080A004A
_080A0048:
	movs r4, #0
_080A004A:
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A005A
	bl fetch_082316e4
	b _080A005C
_080A005A:
	movs r0, #0
_080A005C:
	str r5, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	mov r1, r8
	add r2, sp, #0xc
	adds r3, r7, #0
	bl FUN_0809fe70
	ldrh r0, [r6, #0x18]
	adds r0, #1
	strh r0, [r6, #0x18]
_080A0074:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a0080
FUN_080a0080: @ 0x080A0080
	push {lr}
	adds r3, r0, #0
	ldr r0, _080A00B0 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A00AC
	cmp r1, #0
	blt _080A00AC
	ldr r0, _080A00B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A00AC
	ldr r0, _080A00B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A00BC
_080A00AC:
	movs r0, #0
	b _080A00CA
	.align 2, 0
_080A00B0: .4byte 0x03002BE0
_080A00B4: .4byte 0x030046A8
_080A00B8: .4byte 0x030046AC
_080A00BC:
	ldr r0, _080A00D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A00CA:
	ldrh r3, [r3, #0x1e]
	cmp r0, r3
	beq _080A00D8
	movs r0, #0
	b _080A00DA
	.align 2, 0
_080A00D4: .4byte 0x030046A4
_080A00D8:
	movs r0, #1
_080A00DA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a00e0
FUN_080a00e0: @ 0x080A00E0
	push {lr}
	ldr r1, _080A00F8 @ =0x03002BE0
	ldr r1, [r1]
	movs r2, #0x2e
	ldrsh r1, [r1, r2]
	ldrh r0, [r0, #0x20]
	lsls r0, r0, #8
	cmp r1, r0
	beq _080A00FC
	movs r0, #0
	b _080A00FE
	.align 2, 0
_080A00F8: .4byte 0x03002BE0
_080A00FC:
	movs r0, #1
_080A00FE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0104
FUN_080a0104: @ 0x080A0104
	push {lr}
	adds r2, r1, #0
	ldrb r1, [r0, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A0120
	ldr r0, _080A011C @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x2c]
	b _080A0126
	.align 2, 0
_080A011C: .4byte 0x03002BE0
_080A0120:
	ldr r0, _080A0134 @ =0x03002BE0
	ldr r0, [r0]
	ldrh r1, [r0, #0x30]
_080A0126:
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	ble _080A0138
	movs r0, #0
	b _080A013A
	.align 2, 0
_080A0134: .4byte 0x03002BE0
_080A0138:
	movs r0, #1
_080A013A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a0140
FUN_080a0140: @ 0x080A0140
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080A017C @ =0x03002BE0
	ldr r2, [r0]
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #4
	bne _080A0184
	ldr r1, _080A0180 @ =0x000003BD
	adds r0, r2, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080A016A
	ldrb r1, [r3, #0x1c]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A01C2
_080A016A:
	cmp r2, #7
	bne _080A01D0
	ldrb r1, [r3, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A01C2
	b _080A01D0
	.align 2, 0
_080A017C: .4byte 0x03002BE0
_080A0180: .4byte 0x000003BD
_080A0184:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A01C2
	ldr r0, _080A01C8 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A01A4
	ldr r0, _080A01CC @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A01A4
	movs r1, #1
_080A01A4:
	cmp r1, #0
	bne _080A01B6
	ldr r0, [r4]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #3
	bne _080A01D0
_080A01B6:
	adds r0, r3, #0
	movs r1, #0x28
	bl FUN_080a0104
	cmp r0, #0
	beq _080A01D0
_080A01C2:
	movs r0, #1
	b _080A01D2
	.align 2, 0
_080A01C8: .4byte 0x03002B8C
_080A01CC: .4byte 0x03002B60
_080A01D0:
	movs r0, #0
_080A01D2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a01d8
FUN_080a01d8: @ 0x080A01D8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl FUN_080a00e0
	adds r5, r0, #0
	cmp r5, #0
	beq _080A0250
	adds r0, r4, #0
	bl FUN_080a0080
	cmp r0, #0
	beq _080A0228
	adds r0, r4, #0
	bl FUN_080a0140
	adds r5, r0, #0
	cmp r5, #0
	bne _080A0228
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	strb r5, [r4, #0x1d]
	ldr r0, _080A0224 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a334
	ldr r0, [r4, #0x34]
	cmp r0, #0
	beq _080A0260
	movs r1, #0
	bl FUN_082318ac
	b _080A0260
	.align 2, 0
_080A0224: .4byte 0x03002BE0
_080A0228:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A024C @ =0x0000082A
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A0260
	.align 2, 0
_080A024C: .4byte 0x0000082A
_080A0250:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A0260
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	strb r5, [r4, #0x1d]
_080A0260:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a0268
FUN_080a0268: @ 0x080A0268
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _080A02A4 @ =0x03002BE0
	ldr r2, [r0]
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrb r1, [r1]
	adds r4, r0, #0
	cmp r1, #4
	bne _080A02AC
	ldr r1, _080A02A8 @ =0x000003BD
	adds r0, r2, r1
	ldrb r2, [r0]
	cmp r2, #1
	bne _080A0292
	ldrb r1, [r3, #0x1c]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080A02E2
_080A0292:
	cmp r2, #7
	bne _080A02F0
	ldrb r1, [r3, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A02E2
	b _080A02F0
	.align 2, 0
_080A02A4: .4byte 0x03002BE0
_080A02A8: .4byte 0x000003BD
_080A02AC:
	ldr r0, _080A02E8 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A02C0
	ldr r0, _080A02EC @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A02C0
	movs r1, #1
_080A02C0:
	cmp r1, #0
	bne _080A02D6
	ldr r0, [r4]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A02D6
	cmp r0, #3
	bne _080A02F0
_080A02D6:
	adds r0, r3, #0
	movs r1, #0x28
	bl FUN_080a0104
	cmp r0, #0
	beq _080A02F0
_080A02E2:
	movs r0, #1
	b _080A02F2
	.align 2, 0
_080A02E8: .4byte 0x03002B8C
_080A02EC: .4byte 0x03002B60
_080A02F0:
	movs r0, #0
_080A02F2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a02f8
FUN_080a02f8: @ 0x080A02F8
	push {r4, lr}
	adds r2, r1, #0
	ldrb r1, [r0, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A032C
	ldr r4, _080A0328 @ =0x03002BE0
	ldr r3, [r4]
	ldrh r1, [r3, #0x2c]
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	blt _080A0350
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, r0, r2
	strh r0, [r3, #0x2c]
	ldr r0, [r4]
	ldrh r1, [r0, #0x2c]
	movs r2, #0x82
	lsls r2, r2, #1
	b _080A034C
	.align 2, 0
_080A0328: .4byte 0x03002BE0
_080A032C:
	ldr r4, _080A0358 @ =0x03002BE0
	ldr r3, [r4]
	ldrh r1, [r3, #0x30]
	movs r0, #0xff
	ands r0, r1
	cmp r0, r2
	blt _080A0350
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, r0, r2
	strh r0, [r3, #0x30]
	ldr r0, [r4]
	ldrh r1, [r0, #0x30]
	movs r2, #0x84
	lsls r2, r2, #1
_080A034C:
	adds r0, r0, r2
	strh r1, [r0]
_080A0350:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A0358: .4byte 0x03002BE0

	thumb_func_start FUN_080a035c
FUN_080a035c: @ 0x080A035C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	bl FUN_080a00e0
	adds r5, r0, #0
	cmp r5, #0
	bne _080A036E
	b _080A0490
_080A036E:
	adds r0, r4, #0
	bl FUN_080a0080
	adds r5, r0, #0
	cmp r5, #0
	beq _080A0442
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A03BE
	ldr r2, _080A03A4 @ =0x03002BE0
	ldr r1, [r2]
	ldr r0, _080A03A8 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r1, [r4, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A03B0
	ldr r0, [r2]
	ldr r1, _080A03AC @ =0x000003BD
	adds r0, r0, r1
	movs r1, #7
	b _080A03B8
	.align 2, 0
_080A03A4: .4byte 0x03002BE0
_080A03A8: .4byte 0x000003F3
_080A03AC: .4byte 0x000003BD
_080A03B0:
	ldr r0, [r2]
	ldr r1, _080A0428 @ =0x000003BD
	adds r0, r0, r1
	movs r1, #1
_080A03B8:
	strb r1, [r0]
	movs r0, #1
	strh r0, [r4, #0x22]
_080A03BE:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A03D0
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	movs r0, #0
	strb r0, [r4, #0x1d]
_080A03D0:
	adds r0, r4, #0
	movs r1, #0x28
	bl FUN_080a02f8
	ldr r0, _080A042C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _080A04B6
	ldr r0, _080A0430 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A03FC
	ldr r0, _080A0434 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A03FC
	movs r1, #1
_080A03FC:
	cmp r1, #0
	bne _080A04B6
	ldr r0, _080A042C @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A04B6
	cmp r0, #3
	beq _080A04B6
	ldrb r1, [r4, #0x1c]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080A0438
	adds r0, r2, #0
	movs r1, #7
	bl FUN_0807a44c
	b _080A04B6
	.align 2, 0
_080A0428: .4byte 0x000003BD
_080A042C: .4byte 0x03002BE0
_080A0430: .4byte 0x03002B8C
_080A0434: .4byte 0x03002B60
_080A0438:
	adds r0, r2, #0
	movs r1, #1
	bl FUN_0807a44c
	b _080A04B6
_080A0442:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	beq _080A0458
	ldr r0, _080A0484 @ =0x03002BE0
	ldr r1, [r0]
	ldr r0, _080A0488 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	strh r5, [r4, #0x22]
_080A0458:
	adds r0, r4, #0
	bl FUN_080a0268
	cmp r0, #0
	bne _080A04A6
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A04B6
	adds r0, r4, #0
	adds r0, #0x24
	ldrh r1, [r4, #0x1e]
	ldrh r3, [r4, #0x20]
	movs r2, #0xff
	str r2, [sp]
	ldr r2, _080A048C @ =0x0000080B
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	movs r0, #1
	strb r0, [r4, #0x1d]
	b _080A04B6
	.align 2, 0
_080A0484: .4byte 0x03002BE0
_080A0488: .4byte 0x000003F3
_080A048C: .4byte 0x0000080B
_080A0490:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	beq _080A04A6
	ldr r0, _080A04C0 @ =0x03002BE0
	ldr r1, [r0]
	ldr r0, _080A04C4 @ =0x000003F3
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	strh r5, [r4, #0x22]
_080A04A6:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A04B6
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_082342a8
	strb r5, [r4, #0x1d]
_080A04B6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A04C0: .4byte 0x03002BE0
_080A04C4: .4byte 0x000003F3

	thumb_func_start FUN_080a04c8
FUN_080a04c8: @ 0x080A04C8
	push {lr}
	ldr r0, _080A04FC @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080A04DE
	ldr r0, _080A0500 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #5
	bne _080A04DE
	movs r1, #1
_080A04DE:
	cmp r1, #0
	bne _080A04F6
	ldr r0, _080A0504 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080A04F6
	cmp r0, #3
	bne _080A0508
_080A04F6:
	movs r0, #1
	b _080A050A
	.align 2, 0
_080A04FC: .4byte 0x03002B8C
_080A0500: .4byte 0x03002B60
_080A0504: .4byte 0x03002BE0
_080A0508:
	movs r0, #0
_080A050A:
	pop {r1}
	bx r1
	.align 2, 0
_080A0510:
	.byte 0x30, 0xB5, 0x82, 0xB0, 0x04, 0x1C, 0xFF, 0xF7, 0xE3, 0xFD, 0x05, 0x1C, 0x00, 0x2D, 0x57, 0xD0
	.byte 0x20, 0x1C, 0xFF, 0xF7, 0xAD, 0xFD, 0x00, 0x28, 0x2A, 0xD0, 0x20, 0x1C, 0xFF, 0xF7, 0xCC, 0xFF
	.byte 0x00, 0x28, 0x04, 0xD0, 0x20, 0x1C, 0x40, 0x21, 0xFF, 0xF7, 0xDE, 0xFE, 0x50, 0xE0, 0x60, 0x7F
	.byte 0x00, 0x28, 0x4D, 0xD0, 0x21, 0x7F, 0x20, 0x20, 0x08, 0x40, 0x00, 0x06, 0x05, 0x0E, 0x00, 0x2D
	.byte 0x04, 0xD0, 0x61, 0x8D, 0x40, 0x20, 0x08, 0x43, 0x60, 0x85, 0x08, 0xE0, 0x20, 0x1C, 0x24, 0x30
	.byte 0x93, 0xF1, 0xA2, 0xFE, 0x65, 0x77, 0x05, 0x48, 0x00, 0x68, 0xD9, 0xF7, 0xE3, 0xFE, 0x60, 0x6B
	.byte 0x00, 0x28, 0x35, 0xD0, 0x00, 0x21, 0x91, 0xF1, 0x99, 0xF9, 0x31, 0xE0, 0xE0, 0x2B, 0x00, 0x03
	.byte 0x20, 0x1C, 0xFF, 0xF7, 0xA1, 0xFF, 0x00, 0x28, 0x18, 0xD0, 0x20, 0x1C, 0x40, 0x21, 0xFF, 0xF7
	.byte 0xB9, 0xFD, 0x00, 0x28, 0x12, 0xD0, 0x60, 0x7F, 0x00, 0x28, 0x21, 0xD1, 0x20, 0x1C, 0x24, 0x30
	.byte 0xE1, 0x8B, 0x23, 0x8C, 0xFF, 0x22, 0x00, 0x92, 0x03, 0x4A, 0x01, 0x92, 0x00, 0x22, 0x93, 0xF1
	.byte 0x5F, 0xFE, 0x01, 0x20, 0x60, 0x77, 0x13, 0xE0, 0x2A, 0x08, 0x00, 0x00, 0x60, 0x7F, 0x00, 0x28
	.byte 0x0E, 0xD0, 0x20, 0x1C, 0x24, 0x30, 0x93, 0xF1, 0x6F, 0xFE, 0x00, 0x20, 0x60, 0x77, 0x07, 0xE0
	.byte 0x60, 0x7F, 0x00, 0x28, 0x04, 0xD0, 0x20, 0x1C, 0x24, 0x30, 0x93, 0xF1, 0x65, 0xFE, 0x65, 0x77
	.byte 0x02, 0xB0, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080a05e8
FUN_080a05e8: @ 0x080A05E8
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A0608 @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080A0602
	ldr r1, [r2, #0x38]
	adds r0, r2, #0
	bl _call_via_r1
_080A0602:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080A0608: .4byte 0x03002BE0

	thumb_func_start FUN_080a060c
FUN_080a060c: @ 0x080A060C
	push {lr}
	adds r2, r0, #0
	ldrb r1, [r2, #0x1d]
	cmp r1, #0
	beq _080A061C
	adds r0, #0x24
	bl FUN_082342a8
_080A061C:
	pop {r1}
	bx r1

	thumb_func_start FUN_080a0620
FUN_080a0620: @ 0x080A0620
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0
	strh r1, [r5, #0x18]
	strb r0, [r5, #0x1d]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A063C
	bl fetch_082316e4
	b _080A063E
_080A063C:
	movs r0, #9
_080A063E:
	strb r0, [r5, #0x1c]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A0688
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A0680 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _080A0684 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	b _080A0692
	.align 2, 0
_080A0680: .4byte 0xFFFF0000
_080A0684: .4byte 0x0000FFFF
_080A0688:
	ldr r1, _080A06C0 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_080A0692:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A06BA
	cmp r1, #0
	blt _080A06BA
	ldr r0, _080A06C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A06BA
	ldr r0, _080A06C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A06CC
_080A06BA:
	movs r0, #0
	b _080A06DA
	.align 2, 0
_080A06C0: .4byte 0xFFFF0000
_080A06C4: .4byte 0x030046A8
_080A06C8: .4byte 0x030046AC
_080A06CC:
	ldr r0, _080A0704 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A06DA:
	strh r0, [r5, #0x1e]
	mov r0, sp
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _080A06F4
	bl fetch_082316e4
_080A06F4:
	str r0, [r5, #0x34]
	ldrb r1, [r5, #0x1c]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A070C
	ldr r0, _080A0708 @ =FUN_080a01d8
	b _080A071E
	.align 2, 0
_080A0704: .4byte 0x030046A4
_080A0708: .4byte FUN_080a01d8
_080A070C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080A071C
	ldr r0, _080A0718 @ =FUN_080a035c
	b _080A071E
	.align 2, 0
_080A0718: .4byte FUN_080a035c
_080A071C:
	ldr r0, _080A072C @ =0x080A0511
_080A071E:
	str r0, [r5, #0x38]
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A072C: .4byte 0x080A0511

	thumb_func_start FUN_080a0730
FUN_080a0730: @ 0x080A0730
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0x3c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A076C
	ldr r1, _080A0764 @ =FUN_080a05e8
	ldr r2, _080A0768 @ =FUN_080a060c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a0620
	cmp r0, #0
	bge _080A076C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A076E
	.align 2, 0
_080A0764: .4byte FUN_080a05e8
_080A0768: .4byte FUN_080a060c
_080A076C:
	adds r0, r4, #0
_080A076E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a0774
FUN_080a0774: @ 0x080A0774
	push {lr}
	ldr r3, _080A0790 @ =0x03002C3C
	ldr r1, [r3]
	cmp r1, #0
	beq _080A078A
	adds r1, #0x36
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r3]
	strh r2, [r0, #0x34]
_080A078A:
	pop {r0}
	bx r0
	.align 2, 0
_080A0790: .4byte 0x03002C3C

	thumb_func_start FUN_080a0794
FUN_080a0794: @ 0x080A0794
	push {lr}
	ldr r2, _080A07B0 @ =0x03002C3C
	ldr r1, [r2]
	cmp r1, #0
	beq _080A07AA
	adds r1, #0x36
	movs r0, #0
	strb r0, [r1]
	ldr r1, [r2]
	movs r0, #8
	strh r0, [r1, #0x34]
_080A07AA:
	pop {r0}
	bx r0
	.align 2, 0
_080A07B0: .4byte 0x03002C3C

	thumb_func_start FUN_080a07b4
FUN_080a07b4: @ 0x080A07B4
	push {lr}
	bl FUN_080a0774
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a07c0
FUN_080a07c0: @ 0x080A07C0
	push {lr}
	bl FUN_080a0794
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a07cc
FUN_080a07cc: @ 0x080A07CC
	push {r4, lr}
	ldr r0, _080A07EC @ =0x03002C3C
	ldr r4, [r0]
	cmp r4, #0
	beq _080A07E6
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A07E6
	adds r0, r4, #0
	bl FUN_080a0844
	movs r0, #1
	strb r0, [r4, #0x1f]
_080A07E6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A07EC: .4byte 0x03002C3C

	thumb_func_start FUN_080a07f0
FUN_080a07f0: @ 0x080A07F0
	push {lr}
	ldr r0, _080A0804 @ =0x03002C3C
	ldr r1, [r0]
	cmp r1, #0
	beq _080A07FE
	movs r0, #0
	strb r0, [r1, #0x1f]
_080A07FE:
	pop {r0}
	bx r0
	.align 2, 0
_080A0804: .4byte 0x03002C3C

	thumb_func_start FUN_080a0808
FUN_080a0808: @ 0x080A0808
	push {lr}
	ldr r0, _080A0828 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _080A0816
	movs r1, #1
_080A0816:
	cmp r1, #0
	bne _080A0830
	ldr r0, _080A082C @ =0x03002C3C
	ldr r0, [r0]
	cmp r0, #0
	beq _080A0830
	ldrb r0, [r0, #0x1f]
	b _080A0832
	.align 2, 0
_080A0828: .4byte 0x03002B80
_080A082C: .4byte 0x03002C3C
_080A0830:
	movs r0, #0
_080A0832:
	pop {r1}
	bx r1
	.align 2, 0
_080A0838:
	.byte 0x00, 0xB5, 0xFF, 0xF7, 0xE5, 0xFF, 0x02, 0xBC
	.byte 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a0844
FUN_080a0844: @ 0x080A0844
	ldr r1, _080A085C @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _080A0860 @ =0x00000932
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0
	strh r1, [r0, #0x30]
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	bx lr
	.align 2, 0
_080A085C: .4byte 0x030046A0
_080A0860: .4byte 0x00000932

	thumb_func_start FUN_080a0864
FUN_080a0864: @ 0x080A0864
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A0884 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A08C0
	ldr r0, _080A0888 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	bne _080A088C
	movs r1, #1
	rsbs r1, r1, #0
	b _080A0890
	.align 2, 0
_080A0884: .4byte 0x030047A4
_080A0888: .4byte 0x03002C68
_080A088C:
	movs r2, #0x18
	ldrsh r1, [r1, r2]
_080A0890:
	ldr r0, [r0]
	cmp r0, #0
	bne _080A089A
	movs r0, #0
	b _080A08A0
_080A089A:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080A08A0:
	cmp r0, #0
	beq _080A08A8
	movs r0, #0
	b _080A08B6
_080A08A8:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A090E
	adds r0, r4, #0
	bl FUN_080a0844
	movs r0, #1
_080A08B6:
	strb r0, [r4, #0x1f]
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	bne _080A090E
	b _080A0920
_080A08C0:
	ldr r0, _080A08E4 @ =0x03002B80
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #1
	bne _080A08CC
	movs r2, #1
_080A08CC:
	cmp r2, #0
	beq _080A08E8
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _080A0902
	movs r0, #1
	strb r0, [r5]
	b _080A0902
	.align 2, 0
_080A08E4: .4byte 0x03002B80
_080A08E8:
	adds r0, r4, #0
	adds r0, #0x37
	ldrb r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	beq _080A0902
	strb r2, [r5]
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0920
	adds r0, r4, #0
	bl FUN_080a0844
_080A0902:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0920
	ldrb r0, [r5]
	cmp r0, #0
	bne _080A0920
_080A090E:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080A091C @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080A092A
	.align 2, 0
_080A091C: .4byte 0x03003E78
_080A0920:
	ldr r0, _080A0930 @ =0x03003E78
	ldr r1, _080A0934 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080A092A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0930: .4byte 0x03003E78
_080A0934: .4byte 0xFFFFFDFF

	thumb_func_start FUN_080a0938
FUN_080a0938: @ 0x080A0938
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r0, #0x36
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A09B0
	ldrh r0, [r7, #0x34]
	cmp r0, #6
	bhi _080A0998
	adds r0, #1
	strh r0, [r7, #0x34]
	ldrh r0, [r7, #0x34]
	movs r4, #8
	subs r4, r4, r0
	adds r6, r4, #1
	movs r1, #0x28
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	ldr r5, _080A0994 @ =0x03003540
	movs r2, #0
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	movs r2, #2
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r3, #0x2c
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	movs r4, #4
	ldrsh r1, [r5, r4]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	b _080A0CFE
	.align 2, 0
_080A0994: .4byte 0x03003540
_080A0998:
	movs r0, #8
	strh r0, [r7, #0x34]
	ldr r1, _080A09AC @ =0x03003540
	ldrh r0, [r1]
	strh r0, [r7, #0x28]
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x2a]
	ldrh r0, [r1, #4]
	b _080A0CFE
	.align 2, 0
_080A09AC: .4byte 0x03003540
_080A09B0:
	ldr r1, _080A09EC @ =0x03002BE0
	ldrb r2, [r7, #0x1e]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r4, _080A09F0 @ =0x000003CE
	adds r0, r3, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r6, r1, #0
	mov ip, r2
	cmp r0, #0
	bne _080A09CC
	b _080A0AC8
_080A09CC:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _080A09FC
	ldr r0, _080A09F4 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080A09F8 @ =0x00000932
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	b _080A0A06
	.align 2, 0
_080A09EC: .4byte 0x03002BE0
_080A09F0: .4byte 0x000003CE
_080A09F4: .4byte 0x030046A0
_080A09F8: .4byte 0x00000932
_080A09FC:
	ldr r0, _080A0A80 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080A0A84 @ =0x00000932
	adds r0, r0, r3
	ldrh r0, [r0]
_080A0A06:
	strh r0, [r7, #0x30]
	ldrh r0, [r7, #0x34]
	cmp r0, #6
	bhi _080A0A8C
	adds r0, #1
	strh r0, [r7, #0x34]
	ldrh r0, [r7, #0x34]
	movs r4, #8
	subs r4, r4, r0
	adds r5, r4, #1
	movs r1, #0x28
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	mov r2, ip
	lsls r1, r2, #2
	adds r1, r1, r6
	ldr r1, [r1]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r0, [r7, r3]
	muls r0, r4, r0
	ldrb r1, [r7, #0x1e]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r1, [r1]
	ldr r2, _080A0A88 @ =0x000003C2
	adds r1, r1, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	muls r0, r4, r0
	ldrb r1, [r7, #0x1e]
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r1, [r1]
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r1, r1, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	adds r1, r5, #0
	bl Div
	b _080A0CFE
	.align 2, 0
_080A0A80: .4byte 0x030046A0
_080A0A84: .4byte 0x00000932
_080A0A88: .4byte 0x000003C2
_080A0A8C:
	movs r0, #8
	strh r0, [r7, #0x34]
	mov r4, ip
	lsls r0, r4, #2
	adds r0, r0, r6
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0x28]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldr r2, _080A0AC4 @ =0x000003C2
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r7, #0x2a]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	movs r3, #0xf1
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrh r0, [r0]
	b _080A0CFE
	.align 2, 0
_080A0AC4: .4byte 0x000003C2
_080A0AC8:
	ldr r2, _080A0B00 @ =0x030046A0
	ldr r0, [r2]
	ldr r4, _080A0B04 @ =0x00000932
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r4, [r7, #0x30]
	ldr r3, _080A0B08 @ =0xFFFFFF00
	adds r0, r4, r3
	subs r1, r1, r0
	movs r0, #0xff
	ands r1, r0
	movs r0, #0x80
	subs r0, r0, r1
	adds r3, r0, #0
	cmp r0, #0
	bge _080A0AEC
	rsbs r3, r0, #0
_080A0AEC:
	cmp r3, #0x10
	bgt _080A0B4C
	cmp r1, #0x80
	beq _080A0B1C
	cmp r1, #0x7f
	bgt _080A0B0C
	asrs r0, r0, #2
	adds r1, r0, #1
	adds r0, r4, r1
	b _080A0B16
	.align 2, 0
_080A0B00: .4byte 0x030046A0
_080A0B04: .4byte 0x00000932
_080A0B08: .4byte 0xFFFFFF00
_080A0B0C:
	adds r0, r1, #0
	subs r0, #0x80
	asrs r0, r0, #2
	subs r0, r4, r0
	adds r0, #0xff
_080A0B16:
	movs r1, #0xff
	ands r0, r1
	strh r0, [r7, #0x30]
_080A0B1C:
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, _080A0B44 @ =0xFFFFFED4
	adds r1, r1, r0
	asrs r1, r1, #2
	strh r1, [r7, #0x32]
	lsls r0, r1, #0x10
	cmp r0, #0
	bge _080A0B88
	rsbs r0, r1, #0
	strh r0, [r7, #0x32]
	ldr r0, [r2]
	ldr r1, _080A0B48 @ =0x00000932
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r7, #0x30]
	b _080A0B88
	.align 2, 0
_080A0B44: .4byte 0xFFFFFED4
_080A0B48: .4byte 0x00000932
_080A0B4C:
	cmp r1, #0
	beq _080A0B70
	cmp r1, #0x7f
	bgt _080A0B5C
	asrs r0, r1, #2
	adds r1, r0, #1
	adds r0, r4, r1
	b _080A0B6A
_080A0B5C:
	movs r0, #0x80
	lsls r0, r0, #1
	subs r1, r0, r1
	asrs r1, r1, #2
	adds r1, #1
	adds r0, r4, r0
	subs r0, r0, r1
_080A0B6A:
	movs r1, #0xff
	ands r0, r1
	strh r0, [r7, #0x30]
_080A0B70:
	movs r2, #0x32
	ldrsh r1, [r7, r2]
	ldr r0, _080A0BB4 @ =0x0000012B
	cmp r1, r0
	bgt _080A0B88
	lsls r0, r1, #1
	adds r0, r0, r1
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r0, r4
	asrs r0, r0, #2
	strh r0, [r7, #0x32]
_080A0B88:
	ldrh r0, [r7, #0x34]
	adds r3, r0, #0
	cmp r3, #1
	bls _080A0C6C
	ldr r2, _080A0BB8 @ =0x085B0A08
	ldrh r0, [r7, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080A0BBC
	asrs r1, r0, #0xc
	b _080A0BC2
	.align 2, 0
_080A0BB4: .4byte 0x0000012B
_080A0BB8: .4byte 0x085B0A08
_080A0BBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0BC2:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	ldr r1, _080A0C0C @ =0x0000097A
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r7, #0x22]
	ldrh r1, [r7, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0C10
	asrs r1, r0, #0xc
	b _080A0C16
	.align 2, 0
_080A0C0C: .4byte 0x0000097A
_080A0C10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0C16:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	adds r0, r0, r1
	strh r0, [r7, #0x24]
	subs r0, r3, #1
	strh r0, [r7, #0x34]
	ldrh r1, [r7, #0x34]
	adds r4, r1, #1
	movs r3, #0x28
	ldrsh r0, [r7, r3]
	muls r0, r1, r0
	movs r2, #0x20
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	strh r0, [r7, #0x28]
	movs r3, #0x2a
	ldrsh r1, [r7, r3]
	ldrh r0, [r7, #0x34]
	muls r0, r1, r0
	movs r2, #0x22
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	strh r0, [r7, #0x2a]
	movs r3, #0x2c
	ldrsh r1, [r7, r3]
	ldrh r0, [r7, #0x34]
	muls r0, r1, r0
	movs r2, #0x24
	ldrsh r1, [r7, r2]
	adds r0, r0, r1
	adds r1, r4, #0
	bl Div
	b _080A0CFE
_080A0C6C:
	movs r0, #0
	strh r0, [r7, #0x34]
	ldr r2, _080A0C94 @ =0x085B0A08
	ldrh r0, [r7, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0x32
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080A0C98
	asrs r1, r0, #0xc
	b _080A0C9E
	.align 2, 0
_080A0C94: .4byte 0x085B0A08
_080A0C98:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0C9E:
	mov r2, ip
	lsls r0, r2, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	adds r0, r0, r1
	strh r0, [r7, #0x28]
	ldrb r0, [r7, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	ldr r3, _080A0CE8 @ =0x0000097A
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r7, #0x2a]
	ldrh r1, [r7, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r2, #0x32
	ldrsh r0, [r7, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0CEC
	asrs r1, r0, #0xc
	b _080A0CF2
	.align 2, 0
_080A0CE8: .4byte 0x0000097A
_080A0CEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0CF2:
	mov r3, ip
	lsls r0, r3, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	adds r0, r0, r1
_080A0CFE:
	strh r0, [r7, #0x2c]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a0d08
FUN_080a0d08: @ 0x080A0D08
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl FUN_080a0864
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0DDC
	adds r0, r4, #0
	bl FUN_080a0938
	add r5, sp, #4
	adds r6, r4, #0
	adds r6, #0x28
	ldrh r0, [r4, #0x28]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A0D40
	asrs r0, r0, #8
	b _080A0D46
_080A0D40:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A0D46:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A0D58
	asrs r0, r0, #8
	b _080A0D5E
_080A0D58:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A0D5E:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080A0D72
	asrs r1, r0, #8
	b _080A0D78
_080A0D72:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_080A0D78:
	subs r0, r2, r1
	strh r0, [r5, #2]
	adds r0, r2, r1
	strh r0, [r5, #4]
	ldr r2, _080A0DAC @ =0x030047C8
	movs r3, #0
	ldrsh r1, [r2, r3]
	add r0, sp, #4
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r4, r1, r0
	adds r3, r4, #0
	adds r3, #0x80
	movs r1, #2
	ldrsh r0, [r2, r1]
	add r1, sp, #4
	movs r2, #2
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	adds r5, r0, #0
	adds r5, #0x80
	cmp r4, #0
	blt _080A0DB0
	asrs r1, r4, #3
	b _080A0DB6
	.align 2, 0
_080A0DAC: .4byte 0x030047C8
_080A0DB0:
	rsbs r0, r4, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_080A0DB6:
	adds r0, r5, #0
	subs r0, #0x80
	cmp r0, #0
	blt _080A0DC2
	asrs r2, r0, #3
	b _080A0DC8
_080A0DC2:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r2, r0, #0
_080A0DC8:
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	subs r3, #0x78
	adds r0, r5, #0
	subs r0, #0x5a
	str r0, [sp]
	movs r0, #1
	bl FUN_0822c40c
_080A0DDC:
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A0DE8:
	.byte 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47
	.byte 0x3C, 0x2C, 0x00, 0x03

	thumb_func_start FUN_080a0df4
FUN_080a0df4: @ 0x080A0DF4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080A0E48 @ =0x0000C091
	ldr r1, _080A0E4C @ =0x00000B12
	bl FUN_082310cc
	adds r2, r0, #0
	str r2, [r4, #0x18]
	movs r0, #0
	str r0, [sp, #0xc]
	str r0, [sp]
	movs r5, #1
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #2
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #1
	movs r1, #1
	bl FUN_0822ba00
	ldr r0, _080A0E50 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _080A0E32
	movs r1, #1
_080A0E32:
	cmp r1, #0
	beq _080A0E5C
	ldr r2, _080A0E54 @ =0x03003E78
	ldr r0, _080A0E58 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	adds r0, #0x37
	strb r5, [r0]
	b _080A0E86
	.align 2, 0
_080A0E48: .4byte 0x0000C091
_080A0E4C: .4byte 0x00000B12
_080A0E50: .4byte 0x03002B80
_080A0E54: .4byte 0x03003E78
_080A0E58: .4byte 0xFFFFFDFF
_080A0E5C:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _080A0E74
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, _080A0E70 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _080A0E7E
	.align 2, 0
_080A0E70: .4byte 0x03003E78
_080A0E74:
	ldr r0, _080A0E90 @ =0x03003E78
	ldr r1, _080A0E94 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_080A0E7E:
	adds r1, r4, #0
	adds r1, #0x37
	movs r0, #0
	strb r0, [r1]
_080A0E86:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A0E90: .4byte 0x03003E78
_080A0E94: .4byte 0xFFFFFDFF

	thumb_func_start FUN_080a0e98
FUN_080a0e98: @ 0x080A0E98
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x1c]
	strb r2, [r4, #0x1e]
	strb r3, [r4, #0x1f]
	bl FUN_080a0df4
	adds r0, r4, #0
	bl FUN_080a0844
	ldr r2, _080A0ECC @ =0x085B0A08
	ldrh r0, [r4, #0x30]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A0ED0
	asrs r1, r0, #0xc
	b _080A0ED6
	.align 2, 0
_080A0ECC: .4byte 0x085B0A08
_080A0ED0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0ED6:
	ldr r3, _080A0F24 @ =0x03002BE0
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r0, [r0, #0x2c]
	subs r0, r0, r1
	strh r0, [r4, #0x28]
	ldrb r0, [r4, #0x1e]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r2, [r0]
	ldr r1, _080A0F28 @ =0x0000097A
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	movs r1, #0x96
	muls r0, r1, r0
	asrs r0, r0, #7
	ldrh r2, [r2, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #0x2a]
	ldr r2, _080A0F2C @ =0x085B0A08
	ldrh r1, [r4, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	muls r0, r1, r0
	ldrb r2, [r4, #0x1e]
	cmp r0, #0
	blt _080A0F30
	asrs r1, r0, #0xc
	b _080A0F36
	.align 2, 0
_080A0F24: .4byte 0x03002BE0
_080A0F28: .4byte 0x0000097A
_080A0F2C: .4byte 0x085B0A08
_080A0F30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A0F36:
	lsls r0, r2, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrh r0, [r0, #0x30]
	subs r0, r0, r1
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl FUN_080a0d08
	ldr r0, _080A0F54 @ =0x03002C3C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A0F54: .4byte 0x03002C3C

	thumb_func_start FUN_080a0f58
FUN_080a0f58: @ 0x080A0F58
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, _080A0F98 @ =0x03002C3C
	ldr r4, [r0]
	cmp r4, #0
	bne _080A0FA4
	movs r0, #9
	movs r1, #0x38
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A0FA4
	ldr r1, _080A0F9C @ =FUN_080a0d08
	ldr r2, _080A0FA0 @ =0x080A0DE9
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_080a0e98
	cmp r0, #0
	bge _080A0FA4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A0FA6
	.align 2, 0
_080A0F98: .4byte 0x03002C3C
_080A0F9C: .4byte FUN_080a0d08
_080A0FA0: .4byte 0x080A0DE9
_080A0FA4:
	adds r0, r4, #0
_080A0FA6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a0fac
FUN_080a0fac: @ 0x080A0FAC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080A0FCC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A0FDA
	ldr r0, _080A0FD0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080A0FD4
	movs r4, #1
	rsbs r4, r4, #0
	b _080A0FEE
	.align 2, 0
_080A0FCC: .4byte 0x030047A4
_080A0FD0: .4byte 0x03002C68
_080A0FD4:
	movs r1, #0x18
	ldrsh r4, [r0, r1]
	b _080A0FEE
_080A0FDA:
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080A0FEC
	bl fetch_082316e4
	adds r4, r0, #0
	b _080A0FEE
_080A0FEC:
	movs r4, #0
_080A0FEE:
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A1000
	bl fetch_082316e4
	adds r2, r0, #0
	b _080A1002
_080A1000:
	movs r2, #1
_080A1002:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080a0f58
	pop {r4, r5}
	pop {r1}
	bx r1
_080A1010:
	.byte 0x10, 0xB5, 0x63, 0x20, 0x90, 0xF1, 0x7C, 0xFA, 0x00, 0x28, 0x03, 0xD0, 0x90, 0xF1, 0x62, 0xFB
	.byte 0x01, 0x1C, 0x01, 0xE0, 0xE1, 0x21, 0xC9, 0x00, 0x0A, 0x4C, 0x20, 0x68, 0x01, 0x83, 0x08, 0x04
	.byte 0x00, 0x28, 0x0C, 0xD0, 0x49, 0x20, 0xA1, 0xF1, 0x3D, 0xFA, 0x00, 0x28, 0x03, 0xD1, 0x49, 0x20
	.byte 0x00, 0x21, 0xA1, 0xF1, 0x9F, 0xF9, 0x20, 0x68, 0x18, 0x30, 0xFB, 0xF7, 0x7B, 0xFA, 0x10, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x40, 0x2C, 0x00, 0x03

	thumb_func_start FUN_080a1058
FUN_080a1058: @ 0x080A1058
	push {lr}
	ldr r0, _080A1068 @ =0x03002C40
	ldr r0, [r0]
	cmp r0, #0
	beq _080A106C
	ldrh r0, [r0, #0x18]
	b _080A106E
	.align 2, 0
_080A1068: .4byte 0x03002C40
_080A106C:
	movs r0, #0
_080A106E:
	pop {r1}
	bx r1
	.align 2, 0
_080A1074:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x20, 0x8B, 0x00, 0x28, 0x0E, 0xD1, 0x80, 0x22
	.byte 0x52, 0x01, 0x04, 0x48, 0x00, 0x68, 0x04, 0x49, 0x40, 0x18, 0x01, 0x88, 0x0A, 0x43, 0x02, 0x80
	.byte 0x22, 0xE0, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03, 0x34, 0x09, 0x00, 0x00, 0x10, 0x48, 0x01, 0x68
	.byte 0x10, 0x48, 0x09, 0x18, 0x10, 0x48, 0x0A, 0x88, 0x10, 0x40, 0x08, 0x80, 0x20, 0x8B, 0x01, 0x38
	.byte 0x20, 0x83, 0x00, 0x04, 0x00, 0x28, 0x0F, 0xD1, 0x49, 0x20, 0xA1, 0xF1, 0xFB, 0xF9, 0x00, 0x28
	.byte 0x02, 0xD0, 0x49, 0x20, 0xA1, 0xF1, 0xB4, 0xF9, 0xFB, 0xF7, 0x60, 0xFA, 0xE0, 0x69, 0x00, 0x28
	.byte 0x02, 0xD0, 0x00, 0x21, 0x90, 0xF1, 0xEA, 0xFB, 0x00, 0x20, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47
	.byte 0xA0, 0x46, 0x00, 0x03, 0x34, 0x09, 0x00, 0x00, 0xFF, 0xEF, 0xFF, 0xFF, 0x00, 0xB5, 0x49, 0x20
	.byte 0xA1, 0xF1, 0xE0, 0xF9, 0x00, 0x28, 0x02, 0xD0, 0x49, 0x20, 0xA1, 0xF1, 0x99, 0xF9, 0x02, 0x49
	.byte 0x00, 0x20, 0x08, 0x60, 0x02, 0xBC, 0x08, 0x47, 0x40, 0x2C, 0x00, 0x03

	thumb_func_start FUN_080a110c
FUN_080a110c: @ 0x080A110C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080A1120
	bl fetch_082316e4
	b _080A1124
_080A1120:
	movs r0, #0xe1
	lsls r0, r0, #3
_080A1124:
	strh r0, [r4, #0x18]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1134
	bl fetch_082316e4
_080A1134:
	str r0, [r4, #0x1c]
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080A1156
	movs r0, #0x49
	bl CheckItemOwn
	cmp r0, #0
	bne _080A114E
	movs r0, #0x49
	movs r1, #0
	bl TryAddItem
_080A114E:
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0809c544
_080A1156:
	ldr r0, _080A1164 @ =0x03002C40
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A1164: .4byte 0x03002C40

	thumb_func_start FUN_080a1168
FUN_080a1168: @ 0x080A1168
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080A11A4 @ =0x03002C40
	ldr r0, [r0]
	cmp r0, #0
	bne _080A11B2
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A11B0
	ldr r1, _080A11A8 @ =0x080A1075
	ldr r2, _080A11AC @ =0x080A10ED
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a110c
	cmp r0, #0
	bge _080A11B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A11B2
	.align 2, 0
_080A11A4: .4byte 0x03002C40
_080A11A8: .4byte 0x080A1075
_080A11AC: .4byte 0x080A10ED
_080A11B0:
	adds r0, r4, #0
_080A11B2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a11b8
FUN_080a11b8: @ 0x080A11B8
	push {lr}
	ldr r0, _080A11D0 @ =0x03000148
	ldr r1, [r0]
	cmp r1, #0
	beq _080A11CC
	movs r0, #0
	strh r0, [r1, #0x1a]
	strh r0, [r1, #0x2a]
	strh r0, [r1, #0x26]
	strh r0, [r1, #0x2c]
_080A11CC:
	pop {r0}
	bx r0
	.align 2, 0
_080A11D0: .4byte 0x03000148

	thumb_func_start FUN_080a11d4
FUN_080a11d4: @ 0x080A11D4
	push {r4, lr}
	ldr r4, _080A11FC @ =0x03000148
	ldr r1, [r4]
	cmp r1, #0
	beq _080A123A
	movs r0, #1
	strh r0, [r1, #0x1a]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1200
	bl fetch_082316e4
	ldr r1, [r4]
	strh r0, [r1, #0x1c]
	bl fetch_082316e4
	ldr r1, [r4]
	b _080A1206
	.align 2, 0
_080A11FC: .4byte 0x03000148
_080A1200:
	ldr r1, [r4]
	movs r0, #3
	strh r0, [r1, #0x1c]
_080A1206:
	strh r0, [r1, #0x1e]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A1228
	bl fetch_082316e4
	ldr r4, _080A1224 @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x20]
	bl fetch_082316e4
	ldr r1, [r4]
	b _080A1230
	.align 2, 0
_080A1224: .4byte 0x03000148
_080A1228:
	ldr r0, _080A1240 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0x78
	strh r0, [r1, #0x20]
_080A1230:
	strh r0, [r1, #0x22]
	ldr r0, _080A1240 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x2c]
_080A123A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A1240: .4byte 0x03000148

	thumb_func_start FUN_080a1244
FUN_080a1244: @ 0x080A1244
	push {r4, lr}
	ldr r4, _080A1268 @ =0x03000148
	ldr r1, [r4]
	cmp r1, #0
	beq _080A12CE
	movs r0, #2
	strh r0, [r1, #0x1a]
	movs r0, #0x64
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A126C
	bl fetch_082316e4
	ldr r1, [r4]
	strh r0, [r1, #0x2a]
	b _080A1270
	.align 2, 0
_080A1268: .4byte 0x03000148
_080A126C:
	ldr r0, [r4]
	strh r1, [r0, #0x2a]
_080A1270:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1290
	bl fetch_082316e4
	ldr r4, _080A128C @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x1c]
	bl fetch_082316e4
	ldr r1, [r4]
	b _080A1298
	.align 2, 0
_080A128C: .4byte 0x03000148
_080A1290:
	ldr r0, _080A12B8 @ =0x03000148
	ldr r1, [r0]
	movs r0, #3
	strh r0, [r1, #0x1c]
_080A1298:
	strh r0, [r1, #0x1e]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A12BC
	bl fetch_082316e4
	ldr r4, _080A12B8 @ =0x03000148
	ldr r1, [r4]
	strh r0, [r1, #0x20]
	bl fetch_082316e4
	ldr r1, [r4]
	b _080A12C4
	.align 2, 0
_080A12B8: .4byte 0x03000148
_080A12BC:
	ldr r0, _080A12D4 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0x78
	strh r0, [r1, #0x20]
_080A12C4:
	strh r0, [r1, #0x22]
	ldr r0, _080A12D4 @ =0x03000148
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x2c]
_080A12CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A12D4: .4byte 0x03000148

	thumb_func_start FUN_080a12d8
FUN_080a12d8: @ 0x080A12D8
	push {r4, lr}
	ldr r0, _080A12FC @ =0x03000148
	ldr r0, [r0]
	cmp r0, #0
	beq _080A12F4
	movs r0, #0x48
	bl prepare_08231510
	cmp r0, #0
	beq _080A12F4
	ldr r4, _080A1300 @ =0x03002B84
	bl fetch_082316e4
	strh r0, [r4]
_080A12F4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A12FC: .4byte 0x03000148
_080A1300: .4byte 0x03002B84

	thumb_func_start FUN_080a1304
FUN_080a1304: @ 0x080A1304
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x24]
	lsls r0, r1, #4
	subs r0, r0, r1
	ldrh r1, [r4, #0x26]
	adds r0, r0, r1
	asrs r0, r0, #4
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x2a]
	lsls r0, r0, #4
	ldrh r2, [r4, #0x28]
	ldr r3, _080A133C @ =0xFFFFF000
	adds r1, r2, r3
	subs r1, r0, r1
	ldr r3, _080A1340 @ =0x00000FFF
	ands r1, r3
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _080A1344
	movs r0, #0x80
	lsls r0, r0, #5
	subs r1, r0, r1
	adds r0, r2, r0
	asrs r1, r1, #4
	subs r0, r0, r1
	b _080A1348
	.align 2, 0
_080A133C: .4byte 0xFFFFF000
_080A1340: .4byte 0x00000FFF
_080A1344:
	asrs r0, r1, #4
	adds r0, r2, r0
_080A1348:
	ands r0, r3
	strh r0, [r4, #0x28]
	ldr r1, _080A1370 @ =0x03002BAC
	ldrh r0, [r4, #0x24]
	lsrs r0, r0, #4
	strh r0, [r1]
	ldr r1, _080A1374 @ =0x03002B90
	ldrh r0, [r4, #0x28]
	lsrs r0, r0, #4
	strh r0, [r1]
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	beq _080A1378
	cmp r0, #1
	bgt _080A1368
	b _080A1470
_080A1368:
	cmp r0, #2
	beq _080A13F0
	b _080A1470
	.align 2, 0
_080A1370: .4byte 0x03002BAC
_080A1374: .4byte 0x03002B90
_080A1378:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	bne _080A146C
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A138C
	ldrh r0, [r4, #0x1c]
	lsls r0, r0, #4
	strh r0, [r4, #0x26]
	b _080A13AE
_080A138C:
	ldr r2, _080A13D0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A13D4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _080A13D8 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1e]
	bl Mod
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	lsls r1, r1, #4
	strh r1, [r4, #0x26]
_080A13AE:
	ldr r2, _080A13D0 @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _080A13D4 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	ldr r5, _080A13D8 @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A13DC
	ldrh r0, [r4, #0x20]
	b _080A146E
	.align 2, 0
_080A13D0: .4byte 0x030046B8
_080A13D4: .4byte 0x000003FF
_080A13D8: .4byte 0x0203B400
_080A13DC:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A13EC @ =0x0203B400
	adds r0, r0, r1
	b _080A144E
	.align 2, 0
_080A13EC: .4byte 0x0203B400
_080A13F0:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	bne _080A146C
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A1404
	ldrh r0, [r4, #0x1c]
	lsls r0, r0, #4
	strh r0, [r4, #0x26]
	b _080A1426
_080A1404:
	ldr r2, _080A1430 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1434 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080A1438 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldrh r1, [r4, #0x1e]
	bl Mod
	ldrh r1, [r4, #0x1c]
	adds r1, r1, r0
	lsls r1, r1, #4
	strh r1, [r4, #0x26]
_080A1426:
	ldrh r0, [r4, #0x22]
	cmp r0, #0
	bne _080A143C
	ldrh r0, [r4, #0x20]
	b _080A146E
	.align 2, 0
_080A1430: .4byte 0x030046B8
_080A1434: .4byte 0x000003FF
_080A1438: .4byte 0x0203B400
_080A143C:
	ldr r2, _080A1460 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1464 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _080A1468 @ =0x0203B400
	adds r0, r0, r5
_080A144E:
	ldrh r0, [r0]
	ldrh r1, [r4, #0x22]
	bl Mod
	ldrh r1, [r4, #0x20]
	adds r1, r1, r0
	strh r1, [r4, #0x2c]
	b _080A1470
	.align 2, 0
_080A1460: .4byte 0x030046B8
_080A1464: .4byte 0x000003FF
_080A1468: .4byte 0x0203B400
_080A146C:
	subs r0, #1
_080A146E:
	strh r0, [r4, #0x2c]
_080A1470:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
_080A1478:
	.byte 0x05, 0x48, 0x00, 0x21, 0x01, 0x80, 0x05, 0x48
	.byte 0x01, 0x80, 0x05, 0x48, 0x01, 0x80, 0x05, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47, 0x00, 0x00
	.byte 0x84, 0x2B, 0x00, 0x03, 0xAC, 0x2B, 0x00, 0x03, 0x90, 0x2B, 0x00, 0x03, 0x48, 0x01, 0x00, 0x03

	thumb_func_start FUN_080a14a0
FUN_080a14a0: @ 0x080A14A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	strh r1, [r5, #0x18]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A14B6
	bl fetch_082316e4
	b _080A14B8
_080A14B6:
	movs r0, #1
_080A14B8:
	strh r0, [r5, #0x1a]
	movs r0, #0x48
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A14D8
	ldr r4, _080A14D4 @ =0x03002B84
	bl fetch_082316e4
	adds r1, r0, #0
	strh r1, [r4]
	b _080A14DC
	.align 2, 0
_080A14D4: .4byte 0x03002B84
_080A14D8:
	ldr r1, _080A14EC @ =0x03002B84
	strh r2, [r1]
_080A14DC:
	ldrh r1, [r5, #0x1a]
	cmp r1, #1
	beq _080A14FC
	cmp r1, #1
	bgt _080A14F0
	cmp r1, #0
	beq _080A14F6
	b _080A164A
	.align 2, 0
_080A14EC: .4byte 0x03002B84
_080A14F0:
	cmp r1, #2
	beq _080A1598
	b _080A164A
_080A14F6:
	strh r1, [r5, #0x2a]
	strh r1, [r5, #0x26]
	b _080A164A
_080A14FC:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1512
	bl fetch_082316e4
	strh r0, [r5, #0x1c]
	bl fetch_082316e4
	b _080A1516
_080A1512:
	movs r0, #3
	strh r0, [r5, #0x1c]
_080A1516:
	strh r0, [r5, #0x1e]
	movs r0, #0x74
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A1532
	bl fetch_082316e4
	strh r0, [r5, #0x20]
	bl fetch_082316e4
	adds r1, r0, #0
	b _080A1536
_080A1532:
	movs r1, #0x78
	strh r1, [r5, #0x20]
_080A1536:
	strh r1, [r5, #0x22]
	ldr r3, _080A1558 @ =0x030046B8
	ldr r1, [r3]
	adds r2, r1, #1
	ldr r4, _080A155C @ =0x000003FF
	ands r2, r4
	str r2, [r3]
	lsls r1, r2, #1
	ldr r6, _080A1560 @ =0x0203B400
	adds r1, r1, r6
	ldrb r1, [r1]
	strh r1, [r5, #0x2a]
	ldrh r1, [r5, #0x1e]
	cmp r1, #0
	bne _080A1564
	ldrh r1, [r5, #0x1c]
	b _080A157E
	.align 2, 0
_080A1558: .4byte 0x030046B8
_080A155C: .4byte 0x000003FF
_080A1560: .4byte 0x0203B400
_080A1564:
	adds r0, r2, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	ldr r1, _080A1594 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1e]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r2
_080A157E:
	lsls r1, r1, #4
	strh r1, [r5, #0x26]
	ldrh r1, [r5, #0x1c]
	lsls r1, r1, #4
	strh r1, [r5, #0x24]
	ldrh r1, [r5, #0x22]
	cmp r1, #0
	bne _080A1628
	ldrh r1, [r5, #0x20]
	b _080A1648
	.align 2, 0
_080A1594: .4byte 0x0203B400
_080A1598:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080A15A6
	bl fetch_082316e4
_080A15A6:
	strh r0, [r5, #0x2a]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A15BE
	bl fetch_082316e4
	strh r0, [r5, #0x1c]
	bl fetch_082316e4
	b _080A15C2
_080A15BE:
	movs r0, #3
	strh r0, [r5, #0x1c]
_080A15C2:
	strh r0, [r5, #0x1e]
	movs r0, #0x74
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A15DE
	bl fetch_082316e4
	strh r0, [r5, #0x20]
	bl fetch_082316e4
	adds r1, r0, #0
	b _080A15E2
_080A15DE:
	movs r1, #0x78
	strh r1, [r5, #0x20]
_080A15E2:
	strh r1, [r5, #0x22]
	ldrh r1, [r5, #0x1e]
	cmp r1, #0
	bne _080A15EE
	ldrh r1, [r5, #0x1c]
	b _080A160E
_080A15EE:
	ldr r2, _080A161C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1620 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080A1624 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r5, #0x1e]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x1c]
	adds r1, r1, r2
_080A160E:
	lsls r1, r1, #4
	strh r1, [r5, #0x26]
	ldrh r1, [r5, #0x22]
	cmp r1, #0
	bne _080A1628
	ldrh r1, [r5, #0x20]
	b _080A1648
	.align 2, 0
_080A161C: .4byte 0x030046B8
_080A1620: .4byte 0x000003FF
_080A1624: .4byte 0x0203B400
_080A1628:
	ldr r2, _080A1654 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080A1658 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _080A165C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	ldrh r1, [r5, #0x22]
	bl Mod
	adds r2, r0, #0
	ldrh r1, [r5, #0x20]
	adds r1, r1, r2
_080A1648:
	strh r1, [r5, #0x2c]
_080A164A:
	ldr r1, _080A1660 @ =0x03000148
	str r5, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A1654: .4byte 0x030046B8
_080A1658: .4byte 0x000003FF
_080A165C: .4byte 0x0203B400
_080A1660: .4byte 0x03000148

	thumb_func_start FUN_080a1664
FUN_080a1664: @ 0x080A1664
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080A169C @ =0x03000148
	ldr r0, [r0]
	cmp r0, #0
	bne _080A16AA
	movs r0, #9
	movs r1, #0x30
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A16A8
	ldr r1, _080A16A0 @ =FUN_080a1304
	ldr r2, _080A16A4 @ =0x080A1479
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a14a0
	cmp r0, #0
	bge _080A16A8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A16AA
	.align 2, 0
_080A169C: .4byte 0x03000148
_080A16A0: .4byte FUN_080a1304
_080A16A4: .4byte 0x080A1479
_080A16A8:
	adds r0, r4, #0
_080A16AA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a16b0
FUN_080a16b0: @ 0x080A16B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A16FC @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1700 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _080A170C
	ldr r0, _080A1704 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	movs r3, #0x28
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r3, #0x7f
	bgt _080A170C
	cmp r1, #0x7f
	bgt _080A170C
	adds r0, r3, #0
	muls r0, r3, r0
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	ldr r1, _080A1708 @ =0x00003FFF
	cmp r0, r1
	bgt _080A170C
	movs r0, #1
	b _080A170E
	.align 2, 0
_080A16FC: .4byte 0x030046A0
_080A1700: .4byte 0x00000942
_080A1704: .4byte 0x03002BE0
_080A1708: .4byte 0x00003FFF
_080A170C:
	movs r0, #0
_080A170E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1714
FUN_080a1714: @ 0x080A1714
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080A1740 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1744 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r5, [r0, r2]
	cmp r5, #0
	bne _080A174C
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne _080A1738
	ldr r0, _080A1748 @ =0x00000237
	bl sound_08240740
	strh r5, [r4, #0x1e]
_080A1738:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x46
	b _080A17FC
	.align 2, 0
_080A1740: .4byte 0x030046A0
_080A1744: .4byte 0x00000942
_080A1748: .4byte 0x00000237
_080A174C:
	adds r0, r4, #0
	bl FUN_080a16b0
	adds r5, r0, #0
	cmp r5, #0
	beq _080A17E8
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A1778
	ldr r0, _080A17A4 @ =0x00000237
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0xf4
	ldr r0, [r0]
	cmp r0, #0
	beq _080A1778
	movs r1, #0
	bl FUN_082318ac
_080A1778:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x45
	bl FUN_0822b20c
	adds r3, r4, #0
	adds r3, #0xac
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrh r0, [r4, #0x1a]
	lsrs r0, r0, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A17A8
	movs r0, #4
	orrs r2, r0
	b _080A17AE
	.align 2, 0
_080A17A4: .4byte 0x00000237
_080A17A8:
	movs r0, #5
	rsbs r0, r0, #0
	ands r2, r0
_080A17AE:
	str r2, [r3]
	ldrh r1, [r4, #0x1a]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080A17DC
	adds r0, r4, #0
	adds r0, #0x80
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	adds r1, #0x84
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #0x80
	str r3, [sp]
	ldr r3, _080A17E4 @ =0x0000B546
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
_080A17DC:
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	strh r0, [r4, #0x1a]
	b _080A180E
	.align 2, 0
_080A17E4: .4byte 0x0000B546
_080A17E8:
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne _080A17F6
	ldr r0, _080A1818 @ =0x00000237
	bl sound_08240740
	strh r5, [r4, #0x1e]
_080A17F6:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x44
_080A17FC:
	bl FUN_0822b20c
	adds r2, r4, #0
	adds r2, #0xac
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	strh r5, [r4, #0x1a]
_080A180E:
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A1818: .4byte 0x00000237

	thumb_func_start FUN_080a181c
FUN_080a181c: @ 0x080A181C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A182E
	adds r0, r4, #0
	adds r0, #0x20
	bl FUN_0823b284
_080A182E:
	adds r0, r4, #0
	adds r0, #0x64
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xac
	bl FUN_0822a4e0
	ldr r0, _080A184C @ =0x00000237
	bl sound_08240740
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A184C: .4byte 0x00000237

	thumb_func_start FUN_080a1850
FUN_080a1850: @ 0x080A1850
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	strh r1, [r6, #0x18]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1874
	bl fetch_082316e4
	strh r0, [r6, #0x28]
	bl fetch_082316e4
	strh r0, [r6, #0x2a]
	bl fetch_082316e4
	b _080A1878
_080A1874:
	strh r0, [r6, #0x28]
	strh r0, [r6, #0x2a]
_080A1878:
	strh r0, [r6, #0x2c]
	adds r5, r6, #0
	adds r5, #0x64
	adds r4, r6, #0
	adds r4, #0x90
	ldr r1, _080A1900 @ =0x0000A680
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0xa
	strh r0, [r5, #0x10]
	movs r0, #3
	strb r0, [r5, #7]
	adds r0, r4, #0
	movs r1, #0x46
	bl FUN_0822b20c
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A18BE
	bl fetch_082316e4
	cmp r0, #0
	beq _080A18BE
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	str r0, [r6, #0x64]
_080A18BE:
	movs r0, #0
	strh r0, [r6, #0x1e]
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #0x68
	bl prepare_08231510
	cmp r0, #0
	beq _080A1904
	bl fetch_082316e4
	strh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080A1906
	adds r4, r6, #0
	adds r4, #0x20
	ldrh r1, [r6, #0x18]
	adds r2, r5, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	bl FUN_08002a48
	b _080A1906
	.align 2, 0
_080A1900: .4byte 0x0000A680
_080A1904:
	strh r0, [r6, #0x1c]
_080A1906:
	adds r5, r6, #0
	adds r5, #0xac
	adds r4, r6, #0
	adds r4, #0xd8
	ldr r1, _080A196C @ =0x0000A680
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0xb
	strh r0, [r5, #0x10]
	movs r0, #1
	strb r0, [r5, #7]
	adds r0, r4, #0
	movs r1, #0x45
	bl FUN_0822b20c
	ldr r0, [r5]
	ldr r1, _080A1970 @ =0x00000201
	orrs r0, r1
	str r0, [r5]
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	ldrh r0, [r5, #0x1c]
	subs r0, #0x80
	strh r0, [r5, #0x1c]
	ldrh r0, [r5, #0x20]
	subs r0, #0x80
	strh r0, [r5, #0x20]
	movs r0, #0x52
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A195E
	bl fetch_082316e4
	adds r2, r0, #0
_080A195E:
	adds r1, r6, #0
	adds r1, #0xf4
	str r2, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A196C: .4byte 0x0000A680
_080A1970: .4byte 0x00000201

	thumb_func_start FUN_080a1974
FUN_080a1974: @ 0x080A1974
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0xf8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A19AC
	ldr r1, _080A19A4 @ =FUN_080a1714
	ldr r2, _080A19A8 @ =FUN_080a181c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a1850
	cmp r0, #0
	bge _080A19AC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A19AE
	.align 2, 0
_080A19A4: .4byte FUN_080a1714
_080A19A8: .4byte FUN_080a181c
_080A19AC:
	adds r0, r4, #0
_080A19AE:
	pop {r4, r5}
	pop {r1}
	bx r1
_080A19B4:
	.byte 0x00, 0xB5, 0x40, 0x21, 0x40, 0x6B, 0x08, 0x40, 0x00, 0x28, 0x03, 0xD0
	.byte 0x11, 0x1C, 0xC4, 0x31, 0x01, 0x20, 0x08, 0x70, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080a19cc
FUN_080a19cc: @ 0x080A19CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	str r0, [sp, #0x30]
	mov r0, sp
	movs r3, #0
	movs r2, #2
	strh r2, [r0]
	strh r3, [r0, #2]
	mov r1, sp
	movs r0, #0x40
	strh r0, [r1, #6]
	movs r0, #3
	strh r0, [r1, #8]
	movs r0, #6
	strh r0, [r1, #0xa]
	mov r0, sp
	strh r2, [r0, #0xc]
	strh r2, [r0, #0xe]
	movs r0, #0x3c
	strh r0, [r1, #0x10]
	movs r0, #8
	strh r0, [r1, #0x12]
	mov r0, sp
	strh r3, [r0, #0x14]
	movs r1, #0xff
	strh r1, [r0, #0x16]
	strh r1, [r0, #0x18]
	strh r3, [r0, #0x1a]
	strh r1, [r0, #0x1c]
	strh r3, [r0, #0x1e]
	strh r1, [r0, #0x20]
	strh r3, [r0, #0x22]
	strh r1, [r0, #0x24]
	strh r3, [r0, #0x26]
	add r6, sp, #0x28
	ldr r0, _080A1AD4 @ =0x0203B400
	mov sl, r0
	ldr r4, _080A1AD8 @ =0x030046B8
	ldr r1, _080A1ADC @ =0x000003FF
	mov sb, r1
	movs r2, #0x96
	lsls r2, r2, #1
	mov r8, r2
	movs r7, #5
	adds r5, r6, #0
_080A1A2E:
	ldr r2, [sp, #0x30]
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldrh r1, [r6]
	subs r1, #0x96
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x28]
	ldr r2, _080A1AE0 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldr r2, [sp, #0x28]
	asrs r1, r2, #0x10
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _080A1AE4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x28]
	ldr r0, [r4]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	bl Mod
	ldrh r1, [r5, #4]
	subs r1, #0x96
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ldr r2, _080A1AE0 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #1
	adds r1, r5, #0
	mov r2, sp
	bl FUN_080155e4
	subs r7, #1
	cmp r7, #0
	bge _080A1A2E
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1AD4: .4byte 0x0203B400
_080A1AD8: .4byte 0x030046B8
_080A1ADC: .4byte 0x000003FF
_080A1AE0: .4byte 0xFFFF0000
_080A1AE4: .4byte 0x0000FFFF

	thumb_func_start FUN_080a1ae8
FUN_080a1ae8: @ 0x080A1AE8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A1B1E
	ldr r0, [r4, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x18]
	adds r0, r4, #0
	bl FUN_080a19cc
	adds r1, r4, #0
	adds r1, #0xc8
	ldr r2, [r1]
	cmp r2, #0
	beq _080A1B18
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_082318ac
_080A1B18:
	adds r0, r4, #0
	bl KillEntity
_080A1B1E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A1B28:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x18, 0x30, 0x88, 0xF1
	.byte 0xD7, 0xFC, 0x20, 0x1C, 0x60, 0x30, 0x94, 0xF1, 0x75, 0xFC, 0x20, 0x1C, 0xB0, 0x30, 0x92, 0xF1
	.byte 0xB3, 0xFB, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080a1b48
FUN_080a1b48: @ 0x080A1B48
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	adds r5, r0, #0
	adds r5, #0x18
	adds r4, r0, #0
	adds r4, #0x44
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A1B6C
	bl fetch_082316e4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_0822b16c
	b _080A1B74
_080A1B6C:
	ldr r1, _080A1BB8 @ =0x00009D41
	adds r0, r4, #0
	bl FUN_0822b16c
_080A1B74:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080A1B8C
	bl fetch_082316e4
_080A1B8C:
	strh r0, [r5, #0x10]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A1BB0
	bl fetch_082316e4
	cmp r0, #0
	beq _080A1BB0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080A1BB0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1BB8: .4byte 0x00009D41

	thumb_func_start FUN_080a1bbc
FUN_080a1bbc: @ 0x080A1BBC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x1c
	adds r6, r0, #0
	mov r8, r2
	adds r5, r6, #0
	adds r5, #0x60
	ldr r4, _080A1C34 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r3, #0x80
	orrs r0, r3
	ldr r2, _080A1C38 @ =0x0000FFFF
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #0x10
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080A1C3C @ =0x00004001
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _080A1C40 @ =0x080A19B5
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A1C34: .4byte 0xFFFF0000
_080A1C38: .4byte 0x0000FFFF
_080A1C3C: .4byte 0x00004001
_080A1C40: .4byte 0x080A19B5

	thumb_func_start FUN_080a1c44
FUN_080a1c44: @ 0x080A1C44
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r7, r1, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A1CA0
	bl fetch_082316e4
	asrs r0, r0, #8
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A1C98 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _080A1C9C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl fetch_082316e4
	asrs r0, r0, #8
	lsls r0, r0, #8
	adds r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080A1CAA
	.align 2, 0
_080A1C98: .4byte 0xFFFF0000
_080A1C9C: .4byte 0x0000FFFF
_080A1CA0:
	ldr r1, _080A1CD8 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080A1CAA:
	add r6, sp, #8
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A1CD2
	cmp r1, #0
	blt _080A1CD2
	ldr r0, _080A1CDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A1CD2
	ldr r0, _080A1CE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A1CE4
_080A1CD2:
	movs r4, #0
	b _080A1CF2
	.align 2, 0
_080A1CD8: .4byte 0xFFFF0000
_080A1CDC: .4byte 0x030046A8
_080A1CE0: .4byte 0x030046AC
_080A1CE4:
	ldr r0, _080A1D04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A1CF2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A1D08
	adds r0, #4
	b _080A1D14
	.align 2, 0
_080A1D04: .4byte 0x030046A4
_080A1D08:
	ldr r0, _080A1D28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A1D14:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080A1D2C
	cmp r3, #2
	beq _080A1D30
	b _080A1D34
	.align 2, 0
_080A1D28: .4byte 0x030046A4
_080A1D2C:
	ldrb r0, [r6, #4]
	b _080A1D32
_080A1D30:
	ldrb r0, [r6]
_080A1D32:
	subs r2, r2, r0
_080A1D34:
	add r1, sp, #8
	strh r2, [r1, #2]
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A1D5E
	cmp r1, #0
	blt _080A1D5E
	ldr r0, _080A1D64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A1D5E
	ldr r0, _080A1D68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A1D6C
_080A1D5E:
	movs r0, #0
	b _080A1D7A
	.align 2, 0
_080A1D64: .4byte 0x030046A8
_080A1D68: .4byte 0x030046AC
_080A1D6C:
	ldr r0, _080A1DD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A1D7A:
	adds r1, r5, #0
	adds r1, #0xc2
	strh r0, [r1]
	add r0, sp, #8
	ldrh r0, [r0, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	adds r2, r5, #0
	adds r2, #0xc1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xb0
	ldrh r1, [r1]
	ldrb r3, [r2]
	movs r2, #0xff
	str r2, [sp]
	adds r2, #4
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_08234270
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_080a1b48
	adds r0, r5, #0
	adds r1, r7, #0
	add r2, sp, #8
	bl FUN_080a1bbc
	movs r0, #0x52
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A1DD4
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xc8
	str r0, [r1]
	b _080A1DDA
	.align 2, 0
_080A1DD0: .4byte 0x030046A4
_080A1DD4:
	adds r0, r5, #0
	adds r0, #0xc8
	str r1, [r0]
_080A1DDA:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1de4
FUN_080a1de4: @ 0x080A1DE4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A1E20
	ldr r1, _080A1E18 @ =FUN_080a1ae8
	ldr r2, _080A1E1C @ =0x080A1B29
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a1c44
	cmp r0, #0
	bge _080A1E20
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A1E22
	.align 2, 0
_080A1E18: .4byte FUN_080a1ae8
_080A1E1C: .4byte 0x080A1B29
_080A1E20:
	adds r0, r4, #0
_080A1E22:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a1e28
FUN_080a1e28: @ 0x080A1E28
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x32]
	adds r2, r0, #1
	strh r2, [r3, #0x32]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A1E48
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r0, #0
	strh r0, [r3, #0x30]
	b _080A1E70
_080A1E48:
	ldrh r0, [r3, #0x28]
	ldrh r4, [r3, #0x18]
	adds r0, r0, r4
	strh r0, [r3, #0x18]
	ldrh r0, [r3, #0x2a]
	ldrh r4, [r3, #0x1a]
	adds r0, r0, r4
	strh r0, [r3, #0x1a]
	ldrh r0, [r3, #0x2c]
	ldrh r4, [r3, #0x1c]
	adds r0, r0, r4
	strh r0, [r3, #0x1c]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r3, #0
	bl FUN_0822dafc
_080A1E70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a1e78
FUN_080a1e78: @ 0x080A1E78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0xbd
	adds r0, r0, r7
	mov sl, r0
	ldrb r2, [r0]
	movs r0, #0x34
	adds r4, r2, #0
	muls r4, r0, r4
	adds r4, #0xc0
	adds r4, r7, r4
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r5, _080A1F50 @ =0x0203B400
	ldr r1, _080A1F54 @ =0x030046B8
	mov sb, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r3, _080A1F58 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0xac
	asrs r0, r0, #4
	movs r6, #0xff
	mov r8, r6
	mov r6, r8
	ands r0, r6
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r0, #0x7f
	strh r0, [r4, #0x18]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0xae
	adds r2, r2, r7
	mov ip, r2
	movs r2, #0x3f
	ands r0, r2
	mov r6, ip
	ldrh r6, [r6]
	adds r0, r0, r6
	strh r0, [r4, #0x1a]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	adds r2, r7, #0
	adds r2, #0xb0
	asrs r0, r0, #4
	mov r6, r8
	ands r0, r6
	ldrh r2, [r2]
	adds r0, r0, r2
	subs r0, #0x7f
	strh r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x28]
	adds r1, #1
	ands r1, r3
	mov r2, sb
	str r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strh r0, [r4, #0x2a]
	movs r6, #0
	strh r6, [r4, #0x2c]
	strh r6, [r4, #0x32]
	movs r0, #1
	strh r0, [r4, #0x30]
	mov r1, sl
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080A1F42
	movs r0, #0
	strb r0, [r1]
_080A1F42:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A1F50: .4byte 0x0203B400
_080A1F54: .4byte 0x030046B8
_080A1F58: .4byte 0x000003FF

	thumb_func_start FUN_080a1f5c
FUN_080a1f5c: @ 0x080A1F5C
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _080A1FA2
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r2, r5, #0
	adds r2, #0xac
	movs r4, #0
	ldrsh r2, [r2, r4]
	subs r1, r1, r2
	cmp r1, #0
	bge _080A1F7E
	rsbs r1, r1, #0
_080A1F7E:
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r1, #4
	ldrsh r2, [r3, r1]
	adds r1, r5, #0
	adds r1, #0xb0
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r2, r1
	cmp r1, #0
	bge _080A1F96
	rsbs r1, r1, #0
_080A1F96:
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r4, #0x7f
	bhi _080A1FA2
	cmp r2, #0x7f
	bls _080A1FA6
_080A1FA2:
	movs r0, #0
	b _080A1FBA
_080A1FA6:
	adds r1, r4, #0
	muls r1, r4, r1
	adds r4, r2, #0
	muls r4, r2, r4
	adds r2, r4, #0
	adds r1, r1, r2
	ldr r2, _080A1FC0 @ =0x00003FFF
	cmp r1, r2
	bgt _080A1FBA
	movs r0, #1
_080A1FBA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A1FC0: .4byte 0x00003FFF

	thumb_func_start FUN_080a1fc4
FUN_080a1fc4: @ 0x080A1FC4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xa8
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A2040
	adds r0, r4, #0
	bl FUN_080a1f5c
	cmp r0, #0
	beq _080A200C
	ldr r0, _080A2034 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080A2038 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080A200C
	strh r0, [r5]
	movs r2, #0x98
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080A1FFE
	movs r1, #0
	bl FUN_082318ac
_080A1FFE:
	movs r0, #1
	bl FUN_0808670c
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A200C:
	adds r1, r4, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080A203C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080A2090
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_080a1e78
	b _080A2090
	.align 2, 0
_080A2034: .4byte 0x03002C00
_080A2038: .4byte 0x000001F5
_080A203C: .4byte 0x0000FFFF
_080A2040:
	adds r0, r4, #0
	bl FUN_080a1f5c
	adds r6, r0, #0
	cmp r6, #0
	bne _080A206C
	movs r1, #0x99
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080A205E
	movs r1, #0
	bl FUN_082318ac
_080A205E:
	movs r0, #0
	bl FUN_0808670c
	strh r6, [r5]
	ldr r0, _080A2098 @ =0x00000199
	bl PlaySound_082406e0
_080A206C:
	adds r1, r4, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080A209C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080A2090
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_080a1e78
_080A2090:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2098: .4byte 0x00000199
_080A209C: .4byte 0x0000FFFF

	thumb_func_start FUN_080a20a0
FUN_080a20a0: @ 0x080A20A0
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x18]
	adds r3, r2, #0
	adds r3, #0xaa
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080A20DC
	adds r0, r2, #0
	adds r0, #0xae
	ldrh r0, [r0]
	adds r0, #0x1e
	strh r0, [r2, #0x36]
	movs r0, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r0, _080A20D8 @ =FUN_080a1fc4
	str r0, [r1]
	b _080A20E8
	.align 2, 0
_080A20D8: .4byte FUN_080a1fc4
_080A20DC:
	adds r3, r2, #0
	adds r3, #0xae
	lsls r0, r1, #1
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r2, #0x36]
_080A20E8:
	adds r1, r2, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r3, _080A2110 @ =0x0000FFFF
	adds r1, r3, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A210C
	adds r0, r2, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r2, #0
	bl FUN_080a1e78
_080A210C:
	pop {r0}
	bx r0
	.align 2, 0
_080A2110: .4byte 0x0000FFFF

	thumb_func_start FUN_080a2114
FUN_080a2114: @ 0x080A2114
	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x18]
	ldr r0, [r2, #0x60]
	subs r1, #3
	ands r0, r1
	str r0, [r2, #0x60]
	adds r3, r2, #0
	adds r3, #0xaa
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _080A216C
	ldr r0, [r2, #0x60]
	subs r1, #1
	ands r0, r1
	str r0, [r2, #0x60]
	adds r0, r2, #0
	adds r0, #0x68
	movs r1, #0x40
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r0, _080A2164 @ =FUN_080a20a0
	str r0, [r1]
	ldr r0, _080A2168 @ =0x0000032F
	bl PlaySound_082406e0
	b _080A218C
	.align 2, 0
_080A2164: .4byte FUN_080a20a0
_080A2168: .4byte 0x0000032F
_080A216C:
	ldr r0, [r2, #0x60]
	movs r1, #2
	orrs r0, r1
	str r0, [r2, #0x60]
	ldrh r1, [r3]
	adds r0, r2, #0
	adds r0, #0x68
	strb r1, [r0]
	ldrh r0, [r3]
	adds r1, r2, #0
	adds r1, #0x69
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #2
	subs r1, #3
	strb r0, [r1]
_080A218C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a2190
FUN_080a2190: @ 0x080A2190
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
_080A2196:
	movs r0, #0x34
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	adds r0, #0xf0
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A21B6
	adds r0, r1, #0
	adds r0, #0xc0
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0xb8
	ldr r1, [r1]
	bl FUN_080a1e28
_080A21B6:
	adds r5, #1
	cmp r5, #7
	ble _080A2196
	adds r0, r4, #0
	adds r0, #0xb4
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a21d0
FUN_080a21d0: @ 0x080A21D0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x60
	bl FUN_0822a4e0
	adds r4, #0xc0
	movs r5, #7
_080A21E6:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080A21E6
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a21fc
FUN_080a21fc: @ 0x080A21FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r0, _080A2290 @ =0x00001C1E
	bl FUN_0822b10c
	adds r1, r6, #0
	adds r1, #0xb8
	str r0, [r1]
	movs r7, #0
	mov r8, r1
	movs r0, #4
	rsbs r0, r0, #0
	mov sl, r0
	movs r1, #1
	mov sb, r1
_080A2222:
	movs r0, #0x34
	adds r5, r7, #0
	muls r5, r0, r5
	adds r4, r5, #0
	adds r4, #0xc0
	adds r4, r6, r4
	mov r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, sl
	mov r2, sl
	bl FUN_0822dad4
	mov r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r1, sb
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	mov r1, sb
	orrs r0, r1
	str r0, [r4]
	adds r5, r6, r5
	adds r5, #0xf0
	movs r0, #0
	strh r0, [r5]
	adds r7, #1
	cmp r7, #7
	ble _080A2222
	adds r0, r6, #0
	adds r0, #0xbd
	movs r1, #0
	strb r1, [r0]
	adds r0, #1
	strh r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A2290: .4byte 0x00001C1E

	thumb_func_start FUN_080a2294
FUN_080a2294: @ 0x080A2294
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A2350
	bl fetch_082316e4
	adds r4, r7, #0
	adds r4, #0xac
	strh r0, [r4]
	bl fetch_082316e4
	adds r5, r7, #0
	adds r5, #0xae
	strh r0, [r5]
	bl fetch_082316e4
	adds r1, r7, #0
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sl, r4
	cmp r2, #0
	blt _080A22F0
	cmp r1, #0
	blt _080A22F0
	ldr r0, _080A22F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A22F0
	ldr r0, _080A22F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A22FC
_080A22F0:
	movs r6, #0
	b _080A230A
	.align 2, 0
_080A22F4: .4byte 0x030046A8
_080A22F8: .4byte 0x030046AC
_080A22FC:
	ldr r0, _080A231C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A230A:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A2320
	adds r0, #4
	b _080A232C
	.align 2, 0
_080A231C: .4byte 0x030046A4
_080A2320:
	ldr r0, _080A2340 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A232C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A2344
	cmp r2, #2
	beq _080A2348
	b _080A234C
	.align 2, 0
_080A2340: .4byte 0x030046A4
_080A2344:
	ldrb r0, [r4, #4]
	b _080A234A
_080A2348:
	ldrb r0, [r4]
_080A234A:
	subs r1, r1, r0
_080A234C:
	strh r1, [r5]
	b _080A2362
_080A2350:
	adds r1, r7, #0
	adds r1, #0xac
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0xae
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	mov sl, r1
_080A2362:
	adds r4, r7, #0
	adds r4, #0x44
	ldr r0, _080A2428 @ =0x00000BA8
	mov sb, r0
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0822b16c
	adds r5, r7, #0
	adds r5, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r6, #6
	strh r6, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0x63
	bl FUN_0822b20c
	ldr r0, [r7, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x18]
	movs r1, #3
	mov r8, r1
	mov r2, r8
	strb r2, [r7, #0x1f]
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r0, [r7, #0x36]
	adds r0, #0x1e
	strh r0, [r7, #0x36]
	adds r4, #0x48
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0822b16c
	adds r5, #0x48
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	strh r6, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0x61
	bl FUN_0822b20c
	ldr r0, [r7, #0x60]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x67
	mov r1, r8
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0x7c
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_080a21fc
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A2430
	bl fetch_082316e4
	cmp r0, #0
	beq _080A2430
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	ldr r0, [r7, #0x60]
	orrs r0, r1
	str r0, [r7, #0x60]
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _080A242C @ =FUN_080a2114
	str r0, [r1]
	movs r0, #0xaf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080A2438
	.align 2, 0
_080A2428: .4byte 0x00000BA8
_080A242C: .4byte FUN_080a2114
_080A2430:
	adds r1, r7, #0
	adds r1, #0xb4
	ldr r0, _080A2458 @ =FUN_080a1fc4
	str r0, [r1]
_080A2438:
	adds r1, r7, #0
	adds r1, #0xaa
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080a1f5c
	adds r1, r0, #0
	cmp r1, #0
	beq _080A245C
	adds r1, r7, #0
	adds r1, #0xa8
	movs r0, #1
	strh r0, [r1]
	adds r4, r1, #0
	b _080A2464
	.align 2, 0
_080A2458: .4byte FUN_080a1fc4
_080A245C:
	adds r0, r7, #0
	adds r0, #0xa8
	strh r1, [r0]
	adds r4, r0, #0
_080A2464:
	movs r0, #0x69
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A247E
	bl fetch_082316e4
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A2486
_080A247E:
	movs r3, #0x98
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A2486:
	movs r0, #0x6f
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A24A0
	bl fetch_082316e4
	movs r2, #0x99
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A24A8
_080A24A0:
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A24A8:
	adds r0, r7, #0
	bl FUN_080a1f5c
	cmp r0, #0
	beq _080A24BC
	movs r0, #1
	strh r0, [r4]
	bl FUN_0808670c
	b _080A24C4
_080A24BC:
	strh r0, [r4]
	movs r0, #0
	bl FUN_0808670c
_080A24C4:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a24d4
FUN_080a24d4: @ 0x080A24D4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x9a
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A2514
	ldr r1, _080A250C @ =FUN_080a2190
	ldr r2, _080A2510 @ =FUN_080a21d0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a2294
	cmp r0, #0
	bge _080A2514
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A2516
	.align 2, 0
_080A250C: .4byte FUN_080a2190
_080A2510: .4byte FUN_080a21d0
_080A2514:
	adds r0, r4, #0
_080A2516:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a251c
FUN_080a251c: @ 0x080A251C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x29
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _080A2542
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	adds r0, #0x28
	strb r2, [r0]
	b _080A25C0
_080A2542:
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x30]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldr r0, _080A2584 @ =0x00001C1E
	bl FUN_0822b10c
	adds r1, r0, #0
	ldrb r2, [r5]
	lsrs r2, r2, #2
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	movs r0, #0x2c
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A2588
	asrs r0, r0, #4
	b _080A258E
	.align 2, 0
_080A2584: .4byte 0x00001C1E
_080A2588:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A258E:
	strh r0, [r4, #0x2c]
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A25A0
	asrs r0, r0, #4
	b _080A25A6
_080A25A0:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A25A6:
	strh r0, [r4, #0x2e]
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	cmp r0, #0
	blt _080A25B8
	asrs r0, r0, #4
	b _080A25BE
_080A25B8:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_080A25BE:
	strh r0, [r4, #0x30]
_080A25C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a25c8
FUN_080a25c8: @ 0x080A25C8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	ldr r6, _080A266C @ =0x0203B400
	ldr r1, _080A2670 @ =0x030046B8
	mov sb, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r4, _080A2674 @ =0x000003FF
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r3, [r1]
	ldrh r1, [r0, #0x18]
	subs r1, #0xf
	movs r5, #0x1f
	ands r3, r5
	adds r1, r1, r3
	movs r3, #0
	mov r8, r3
	strh r1, [r0, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r3, r2, #1
	adds r3, r3, r6
	movs r7, #0xc0
	lsls r7, r7, #2
	adds r1, r7, #0
	ldrh r7, [r0, #0x1a]
	adds r1, r1, r7
	ldrb r3, [r3]
	adds r1, r1, r3
	strh r1, [r0, #0x1a]
	adds r2, #1
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r3, [r1]
	ldrh r1, [r0, #0x1c]
	subs r1, #0xf
	ands r3, r5
	adds r1, r1, r3
	strh r1, [r0, #0x1c]
	adds r3, r0, #0
	adds r3, #0x29
	movs r1, #0x18
	strb r1, [r3]
	mov r1, r8
	strh r1, [r0, #0x2c]
	adds r2, #1
	ands r2, r4
	mov r3, sb
	str r2, [r3]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r1, [r2]
	ands r1, r5
	adds r1, #0x20
	rsbs r1, r1, #0
	strh r1, [r0, #0x2e]
	mov r7, r8
	strh r7, [r0, #0x30]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, #0x28
	movs r1, #1
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A266C: .4byte 0x0203B400
_080A2670: .4byte 0x030046B8
_080A2674: .4byte 0x000003FF

	thumb_func_start FUN_080a2678
FUN_080a2678: @ 0x080A2678
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	ldr r6, _080A2710 @ =0x0203B400
	ldr r1, _080A2714 @ =0x030046B8
	mov sb, r1
	ldr r3, [r1]
	adds r3, #1
	ldr r4, _080A2718 @ =0x000003FF
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r6
	ldrh r2, [r1]
	ldrh r1, [r0, #0x18]
	subs r1, #0xf
	movs r5, #0x1f
	ands r2, r5
	adds r1, r1, r2
	movs r2, #0
	mov r8, r2
	strh r1, [r0, #0x18]
	adds r3, #1
	ands r3, r4
	lsls r2, r3, #1
	adds r2, r2, r6
	ldrh r1, [r0, #0x1a]
	ldrb r2, [r2]
	adds r1, r1, r2
	strh r1, [r0, #0x1a]
	adds r3, #1
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r6
	ldrh r2, [r1]
	ldrh r1, [r0, #0x1c]
	subs r1, #0xf
	ands r2, r5
	adds r1, r1, r2
	strh r1, [r0, #0x1c]
	adds r2, r0, #0
	adds r2, #0x29
	movs r1, #0x18
	strb r1, [r2]
	mov r1, r8
	strh r1, [r0, #0x2c]
	adds r3, #1
	ands r3, r4
	mov r2, sb
	str r3, [r2]
	lsls r3, r3, #1
	adds r3, r3, r6
	ldrh r1, [r3]
	ands r1, r5
	adds r1, #0x18
	strh r1, [r0, #0x2e]
	mov r1, r8
	strh r1, [r0, #0x30]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, #0x28
	movs r1, #1
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2710: .4byte 0x0203B400
_080A2714: .4byte 0x030046B8
_080A2718: .4byte 0x000003FF

	thumb_func_start FUN_080a271c
FUN_080a271c: @ 0x080A271C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A276C @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x98
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _080A2738
	rsbs r2, r2, #0
_080A2738:
	movs r1, #0x34
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0x9c
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A274C
	rsbs r1, r1, #0
_080A274C:
	cmp r2, #0x60
	bgt _080A2770
	cmp r1, #0x60
	bgt _080A2770
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A2770
	movs r0, #1
	b _080A2772
	.align 2, 0
_080A276C: .4byte 0x030046A0
_080A2770:
	movs r0, #0
_080A2772:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a2778
FUN_080a2778: @ 0x080A2778
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _080A27FC
	ldr r0, _080A27F0 @ =0x03002C00
	ldr r1, [r0]
	ldrb r0, [r1, #0x1a]
	cmp r0, #4
	bne _080A27FC
	ldr r2, _080A27F4 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bhi _080A27FC
	movs r0, #2
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080A27AE
	rsbs r1, r1, #0
_080A27AE:
	cmp r1, #0xff
	bgt _080A27FC
	movs r0, #0
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x98
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	movs r0, #4
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x9c
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	movs r0, #0xbe
	lsls r0, r0, #1
	cmp r2, r0
	bgt _080A27FC
	cmp r1, r0
	bgt _080A27FC
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	ldr r1, _080A27F8 @ =0x00023410
	cmp r0, r1
	bgt _080A27FC
	movs r0, #1
	b _080A27FE
	.align 2, 0
_080A27F0: .4byte 0x03002C00
_080A27F4: .4byte 0x000001F5
_080A27F8: .4byte 0x00023410
_080A27FC:
	movs r0, #0
_080A27FE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a2804
FUN_080a2804: @ 0x080A2804
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A2816
	b _080A29E8
_080A2816:
	cmp r0, #2
	bhi _080A2864
	adds r2, r3, #0
	adds r2, #0xe8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	subs r2, #0x4e
	ldrh r1, [r4]
	movs r0, #2
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	ldr r1, _080A2860 @ =0x00000402
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r3, r2
	strh r0, [r1]
	movs r4, #0x8a
	lsls r4, r4, #1
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r5, #0xa0
	lsls r5, r5, #1
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080A28C4
	.align 2, 0
_080A2860: .4byte 0x00000402
_080A2864:
	cmp r0, #4
	bhi _080A28D4
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0x9a
	adds r0, r0, r3
	mov ip, r0
	ldr r1, _080A28D0 @ =0x00000402
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r4]
	movs r0, #4
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r0, r1
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0x99
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r5, #0x3a
	adds r2, r3, r5
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080A28C4:
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0, #0x10]
	b _080A2A0C
	.align 2, 0
_080A28D0: .4byte 0x00000402
_080A28D4:
	cmp r0, #6
	bhi _080A2960
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0x9a
	adds r0, r0, r3
	mov ip, r0
	ldr r1, _080A295C @ =0x00000402
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r1, #0
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r5, #0x99
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldrh r1, [r4]
	movs r0, #6
	subs r0, r0, r1
	movs r1, #0xab
	muls r0, r1, r0
	adds r1, #0xab
	adds r0, r0, r1
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	adds r0, #2
	strh r1, [r0, #0x10]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	b _080A2A0C
	.align 2, 0
_080A295C: .4byte 0x00000402
_080A2960:
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r5, #0x9a
	adds r5, r5, r3
	mov ip, r5
	ldr r1, _080A29E4 @ =0x00000402
	adds r0, r1, #0
	ldrh r4, [r5]
	adds r0, r0, r4
	movs r5, #0x83
	lsls r5, r5, #1
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #2
	adds r0, r1, #0
	mov r4, ip
	ldrh r4, [r4]
	adds r0, r0, r4
	adds r5, #0x2c
	adds r1, r3, r5
	strh r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xab
	lsls r1, r1, #1
	adds r0, r1, #0
	mov r2, ip
	ldrh r2, [r2]
	adds r0, r0, r2
	movs r4, #0xaf
	lsls r4, r4, #1
	adds r1, r3, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x4e
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0x50
	adds r0, #8
	strh r0, [r1, #0x10]
	ldr r0, [r3, #0x50]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r3, #0x50]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #1
	strb r0, [r1]
	b _080A2A0C
	.align 2, 0
_080A29E4: .4byte 0x00000402
_080A29E8:
	adds r1, r3, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x8a
	lsls r5, r5, #1
	adds r1, r3, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_080A2A0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a2a14
FUN_080a2a14: @ 0x080A2A14
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080A2A28 @ =0x00000382
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080A2A28: .4byte 0x00000382
_080A2A2C:
	.byte 0x00, 0xB5, 0x02, 0x1C
	.byte 0x10, 0x6D, 0x01, 0x21, 0x08, 0x43, 0x10, 0x65, 0x10, 0x1C, 0x7C, 0x30, 0xE2, 0x23, 0x5B, 0x00
	.byte 0xD1, 0x18, 0x09, 0x88, 0x88, 0xF1, 0xE2, 0xFB, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080a2a4c
FUN_080a2a4c: @ 0x080A2A4C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A2A88 @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A2A68
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080A2A68:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #7
	bhi _080A2A78
	adds r0, #1
	strh r0, [r1]
_080A2A78:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x16
	bhi _080A2A8C
	adds r0, #2
	b _080A2A8E
	.align 2, 0
_080A2A88: .4byte 0x00000382
_080A2A8C:
	movs r0, #0x18
_080A2A8E:
	strb r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A2AA6
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	b _080A2AC0
_080A2AA6:
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
_080A2AC0:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #7
	bls _080A2ADE
	adds r0, r4, #0
	adds r0, #0x7c
	subs r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	b _080A2B06
_080A2ADE:
	cmp r0, #0
	beq _080A2AF6
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _080A2B06
_080A2AF6:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
_080A2B06:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x17
	bls _080A2B24
	ldr r1, _080A2B2C @ =FUN_080a2b30
	adds r0, r4, #0
	bl FUN_080a2a14
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl FUN_08022488
_080A2B24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2B2C: .4byte FUN_080a2b30

	thumb_func_start FUN_080a2b30
FUN_080a2b30: @ 0x080A2B30
	push {lr}
	adds r3, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r3, r0
	movs r0, #0x18
	strb r0, [r2]
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #8
	strh r0, [r1]
	ldr r0, [r3, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x50]
	adds r0, r3, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x6e
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	pop {r0}
	bx r0

	thumb_func_start FUN_080a2b78
FUN_080a2b78: @ 0x080A2B78
	push {lr}
	adds r3, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _080A2B8C
	subs r0, #2
	b _080A2B8E
_080A2B8C:
	movs r0, #0
_080A2B8E:
	strb r0, [r1]
	adds r1, r3, #0
	adds r1, #0x9a
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrh r1, [r1]
	ldrb r2, [r0]
	adds r1, r1, r2
	adds r2, r3, #0
	adds r2, #0x6e
	strh r1, [r2]
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2BCE
	ldr r0, [r3, #0x50]
	ldr r1, _080A2BD4 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r3, #0x50]
	adds r1, r3, #0
	adds r1, #0x57
	movs r0, #3
	strb r0, [r1]
	adds r2, #0x32
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A2BD8 @ =FUN_080a2bdc
	adds r0, r3, #0
	bl FUN_080a2a14
_080A2BCE:
	pop {r0}
	bx r0
	.align 2, 0
_080A2BD4: .4byte 0xFFFFFDFF
_080A2BD8: .4byte FUN_080a2bdc

	thumb_func_start FUN_080a2bdc
FUN_080a2bdc: @ 0x080A2BDC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #6
	bhi _080A2BF8
	adds r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A2C18
_080A2BF8:
	ldr r0, _080A2C20 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A2C18
	ldr r0, _080A2C24 @ =0x0000015F
	bl PlaySound_082406e0
	ldr r1, _080A2C28 @ =FUN_080a2c2c
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2C18:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2C20: .4byte 0x00000382
_080A2C24: .4byte 0x0000015F
_080A2C28: .4byte FUN_080a2c2c

	thumb_func_start FUN_080a2c2c
FUN_080a2c2c: @ 0x080A2C2C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A2C50 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A2C4A
	ldr r1, _080A2C54 @ =FUN_080a2c58
	adds r0, r2, #0
	bl FUN_080a2a14
_080A2C4A:
	pop {r0}
	bx r0
	.align 2, 0
_080A2C50: .4byte 0x00000382
_080A2C54: .4byte FUN_080a2c58

	thumb_func_start FUN_080a2c58
FUN_080a2c58: @ 0x080A2C58
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A2CA8 @ =0x00000382
	adds r0, r4, r1
	ldrh r2, [r0]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A2C88
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A2C88
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a2678
_080A2C88:
	ldr r0, _080A2CA8 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bne _080A2CA2
	ldr r1, _080A2CAC @ =FUN_080a2cb0
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2CA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2CA8: .4byte 0x00000382
_080A2CAC: .4byte FUN_080a2cb0

	thumb_func_start FUN_080a2cb0
FUN_080a2cb0: @ 0x080A2CB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r4, #0x50]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r0, #0x16
	cmp r1, r0
	bge _080A2CDA
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
_080A2CDA:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A2CF2
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A2D0E
_080A2CF2:
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	ldr r1, _080A2D14 @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
	adds r0, r4, #0
	adds r0, #0x18
	movs r1, #1
	bl FUN_08022488
_080A2D0E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2D14: .4byte FUN_080a2e20

	thumb_func_start FUN_080a2d18
FUN_080a2d18: @ 0x080A2D18
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A2D94 @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x3f
	bhi _080A2D98
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r2, #2
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	ldrh r0, [r5]
	adds r2, r4, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r3, r4, #0
	adds r3, #0x56
	strb r0, [r3]
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xa8
	strb r1, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa9
	strb r0, [r1]
	ldrb r0, [r3]
	subs r1, #3
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	adds r0, #0x16
	subs r1, #0x38
	strh r0, [r1]
	b _080A2E14
	.align 2, 0
_080A2D94: .4byte 0x00000382
_080A2D98:
	cmp r3, #0x40
	bne _080A2DC4
	ldr r0, [r4, #0x50]
	movs r2, #3
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0x58
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x4f
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	b _080A2E14
_080A2DC4:
	cmp r3, #0x4f
	bls _080A2E14
	adds r1, r4, #0
	adds r1, #0x6e
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r1, #0x2c
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0
	ldrsh r1, [r1, r2]
	cmp r0, r1
	ble _080A2DF4
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _080A2E14
_080A2DF4:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	ldr r1, _080A2E1C @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2E14:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A2E1C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a2e20
FUN_080a2e20: @ 0x080A2E20
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A2E94 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A2E40
	ldr r0, _080A2E98 @ =0x0000036A
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A2E40
	adds r0, #1
	strh r0, [r1]
_080A2E40:
	adds r0, r4, #0
	bl FUN_080a271c
	adds r6, r0, #0
	cmp r6, #0
	bne _080A2E4E
	b _080A2F4C
_080A2E4E:
	ldr r1, _080A2E9C @ =0x00000369
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2EAC
	movs r2, #1
	ldr r0, _080A2EA0 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	bne _080A2E66
	b _080A2F86
_080A2E66:
	ldr r0, _080A2EA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r1, #0x13
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	bne _080A2E76
	b _080A2F86
_080A2E76:
	cmp r0, #0x19
	bne _080A2E7C
	b _080A2F86
_080A2E7C:
	ldr r0, _080A2EA8 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _080A2E8A
	b _080A2F86
_080A2E8A:
	movs r0, #0x92
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080A2F86
	.align 2, 0
_080A2E94: .4byte 0x030047A4
_080A2E98: .4byte 0x0000036A
_080A2E9C: .4byte 0x00000369
_080A2EA0: .4byte 0x03002BC0
_080A2EA4: .4byte 0x03002BE0
_080A2EA8: .4byte 0x030044E0
_080A2EAC:
	adds r5, r4, #0
	adds r5, #0x4c
	ldrh r0, [r5]
	cmp r0, #1
	beq _080A2EC2
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r5]
_080A2EC2:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #7
	bhi _080A2ED2
	adds r0, #1
	strh r0, [r1]
_080A2ED2:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0x16
	bhi _080A2EE2
	adds r0, #2
	b _080A2EE4
_080A2EE2:
	movs r0, #0x18
_080A2EE4:
	strb r0, [r1]
	movs r2, #1
	ldr r0, _080A2F3C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A2F86
	ldr r0, _080A2F40 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A2F86
	ldr r0, _080A2F44 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A2F86
	subs r1, #0x16
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A2F86
	movs r0, #0xe3
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #8
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0x98
	adds r0, r2, #0
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A2F48 @ =0x080A3005
	adds r0, r4, #0
	bl FUN_080a2a14
	b _080A2F86
	.align 2, 0
_080A2F3C: .4byte 0x03002BC0
_080A2F40: .4byte 0x030044E0
_080A2F44: .4byte 0x03002BE0
_080A2F48: .4byte 0x080A3005
_080A2F4C:
	adds r5, r4, #0
	adds r5, #0x4c
	ldrh r0, [r5]
	cmp r0, #0
	beq _080A2F5E
	ldr r0, _080A2F80 @ =0x00000199
	bl PlaySound_082406e0
	strh r6, [r5]
_080A2F5E:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A2F6E
	subs r0, #1
	strh r0, [r1]
_080A2F6E:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bls _080A2F84
	subs r0, #2
	strb r0, [r1]
	b _080A2F86
	.align 2, 0
_080A2F80: .4byte 0x00000199
_080A2F84:
	strb r6, [r1]
_080A2F86:
	movs r1, #0xda
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A2F9C
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
	b _080A2FB6
_080A2F9C:
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
_080A2FB6:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #7
	bls _080A2FD4
	adds r0, r4, #0
	adds r0, #0x7c
	subs r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	b _080A2FFC
_080A2FD4:
	cmp r0, #0
	beq _080A2FEC
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _080A2FFC
_080A2FEC:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
_080A2FFC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A3004:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0xDA, 0x20, 0x80, 0x00, 0x21, 0x18, 0x08, 0x78
	.byte 0x01, 0x28, 0x01, 0xD9, 0x02, 0x38, 0x00, 0xE0, 0x00, 0x20, 0x08, 0x70, 0x21, 0x1C, 0x9A, 0x31
	.byte 0xDA, 0x22, 0x92, 0x00, 0xA0, 0x18, 0x09, 0x88, 0x02, 0x78, 0x89, 0x18, 0x22, 0x1C, 0x6E, 0x32
	.byte 0x11, 0x80, 0x00, 0x78, 0x00, 0x28, 0x36, 0xD1, 0x1C, 0x48, 0x01, 0x68, 0xDF, 0x22, 0x92, 0x00
	.byte 0x88, 0x18, 0x00, 0x78, 0x00, 0x28, 0x2E, 0xD1, 0x08, 0x1C, 0x04, 0x21, 0x00, 0x22, 0xD9, 0xF7
	.byte 0xD7, 0xF8, 0x17, 0x48, 0x25, 0x18, 0x00, 0x20, 0x28, 0x70, 0x20, 0x1C, 0xFF, 0xF7, 0x8C, 0xFB
	.byte 0x00, 0x28, 0x05, 0xD0, 0xE3, 0xF7, 0x28, 0xFD, 0x00, 0x28, 0x01, 0xD0, 0x01, 0x20, 0x28, 0x70
	.byte 0x20, 0x6D, 0x10, 0x49, 0x08, 0x40, 0x20, 0x65, 0x21, 0x1C, 0x57, 0x31, 0x03, 0x20, 0x08, 0x70
	.byte 0x22, 0x1C, 0xA0, 0x32, 0x10, 0x68, 0x01, 0x21, 0x08, 0x43, 0x10, 0x60, 0x0A, 0x49, 0x20, 0x1C
	.byte 0xFF, 0xF7, 0xC0, 0xFC, 0xDB, 0x21, 0x89, 0x00, 0x60, 0x18, 0x00, 0x68, 0x00, 0x28, 0x02, 0xD0
	.byte 0x00, 0x21, 0x8E, 0xF1, 0x03, 0xFC, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xE0, 0x2B, 0x00, 0x03
	.byte 0xC3, 0x01, 0x00, 0x00, 0xFF, 0xFD, 0xFF, 0xFF, 0xBD, 0x30, 0x0A, 0x08

	thumb_func_start FUN_080a30bc
FUN_080a30bc: @ 0x080A30BC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #6
	bhi _080A30D8
	adds r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A30F8
_080A30D8:
	ldr r0, _080A3100 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A30F8
	ldr r0, _080A3104 @ =0x0000015F
	bl PlaySound_082406e0
	ldr r1, _080A3108 @ =FUN_080a310c
	adds r0, r4, #0
	bl FUN_080a2a14
_080A30F8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3100: .4byte 0x00000382
_080A3104: .4byte 0x0000015F
_080A3108: .4byte FUN_080a310c

	thumb_func_start FUN_080a310c
FUN_080a310c: @ 0x080A310C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A3130 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A312A
	ldr r1, _080A3134 @ =FUN_080a3138
	adds r0, r2, #0
	bl FUN_080a2a14
_080A312A:
	pop {r0}
	bx r0
	.align 2, 0
_080A3130: .4byte 0x00000382
_080A3134: .4byte FUN_080a3138

	thumb_func_start FUN_080a3138
FUN_080a3138: @ 0x080A3138
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080A31D0 @ =0x00000382
	adds r0, r4, r1
	ldrh r2, [r0]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A316A
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A316A
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a2678
_080A316A:
	ldr r0, _080A31D0 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bne _080A31C6
	movs r1, #0xdd
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A31AA
	ldr r1, _080A31D4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	str r0, [sp]
	adds r0, r2, #0
	bl FUN_082318ac
_080A31AA:
	ldr r1, _080A31D8 @ =0x000001C3
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A31C6
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080A31C6
	movs r1, #0
	bl FUN_082318ac
_080A31C6:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A31D0: .4byte 0x00000382
_080A31D4: .4byte 0xFFFF0000
_080A31D8: .4byte 0x000001C3

	thumb_func_start FUN_080a31dc
FUN_080a31dc: @ 0x080A31DC
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A3200 @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080A31FA
	ldr r1, _080A3204 @ =FUN_080a3208
	adds r0, r2, #0
	bl FUN_080a2a14
_080A31FA:
	pop {r0}
	bx r0
	.align 2, 0
_080A3200: .4byte 0x00000382
_080A3204: .4byte FUN_080a3208

	thumb_func_start FUN_080a3208
FUN_080a3208: @ 0x080A3208
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A326C @ =0x00000382
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0x10
	bne _080A3222
	ldr r0, _080A3270 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0
	bl FUN_0807c36c
_080A3222:
	ldrh r2, [r5]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A324A
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A324A
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a25c8
_080A324A:
	ldr r0, _080A326C @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080A3264
	ldr r1, _080A3274 @ =FUN_080a3278
	adds r0, r4, #0
	bl FUN_080a2a14
_080A3264:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A326C: .4byte 0x00000382
_080A3270: .4byte 0x03002BE0
_080A3274: .4byte FUN_080a3278

	thumb_func_start FUN_080a3278
FUN_080a3278: @ 0x080A3278
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A329C @ =0x00000382
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A3296
	ldr r1, _080A32A0 @ =FUN_080a32a4
	adds r0, r2, #0
	bl FUN_080a2a14
_080A3296:
	pop {r0}
	bx r0
	.align 2, 0
_080A329C: .4byte 0x00000382
_080A32A0: .4byte FUN_080a32a4

	thumb_func_start FUN_080a32a4
FUN_080a32a4: @ 0x080A32A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x50]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r4, #0x50]
	adds r2, r4, #0
	adds r2, #0x6e
	movs r0, #0
	ldrsh r1, [r2, r0]
	adds r0, r4, #0
	adds r0, #0x9a
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r0, #0x16
	cmp r1, r0
	bge _080A32CE
	ldrh r0, [r2]
	adds r0, #2
	strh r0, [r2]
_080A32CE:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A32E6
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080a2804
	b _080A3336
_080A32E6:
	ldr r0, _080A3314 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807d118
	bl FUN_080a6edc
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A331C
	ldr r1, _080A3318 @ =FUN_080a3340
	adds r0, r4, #0
	bl FUN_080a2a14
	b _080A3324
	.align 2, 0
_080A3314: .4byte 0x03002BE0
_080A3318: .4byte FUN_080a3340
_080A331C:
	ldr r1, _080A333C @ =FUN_080a2e20
	adds r0, r4, #0
	bl FUN_080a2a14
_080A3324:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080A3336
	movs r1, #0
	bl FUN_082318ac
_080A3336:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A333C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a3340
FUN_080a3340: @ 0x080A3340
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #2
	bls _080A3370
	subs r0, #2
	strb r0, [r2]
	ldr r0, [r4, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x50]
	adds r0, r4, #0
	adds r0, #0x9a
	ldrh r0, [r0]
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0x6e
	strh r0, [r1]
	b _080A3378
_080A3370:
	ldr r0, [r4, #0x50]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x50]
_080A3378:
	movs r2, #0xe3
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A3388
	subs r0, #1
	strh r0, [r1]
_080A3388:
	ldrh r0, [r1]
	cmp r0, #7
	bls _080A33A2
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	b _080A33CA
_080A33A2:
	cmp r0, #0
	beq _080A33BA
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _080A33CA
_080A33BA:
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
_080A33CA:
	ldr r0, _080A3424 @ =0x00000382
	adds r3, r4, r0
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bhi _080A3428
	ldr r0, [r4, #0x50]
	movs r2, #2
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r1, [r3]
	movs r0, #0x40
	subs r0, r0, r1
	adds r2, r4, #0
	adds r2, #0x58
	strb r0, [r2]
	adds r1, r4, #0
	adds r1, #0x59
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r3, r4, #0
	adds r3, #0x56
	strb r0, [r3]
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0xa8
	strb r1, [r0]
	ldrb r0, [r2]
	adds r1, r4, #0
	adds r1, #0xa9
	strb r0, [r1]
	ldrb r1, [r3]
	adds r0, r4, #0
	adds r0, #0xa6
	strb r1, [r0]
	b _080A3440
	.align 2, 0
_080A3424: .4byte 0x00000382
_080A3428:
	ldr r0, [r4, #0x50]
	movs r2, #1
	orrs r0, r2
	str r0, [r4, #0x50]
	adds r1, r4, #0
	adds r1, #0xa0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl KillEntity
_080A3440:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a3448
FUN_080a3448: @ 0x080A3448
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r7, #0
	adds r6, #0x18
	movs r5, #0
	ldr r2, _080A3494 @ =0x03002B4C
	ldr r1, [r2]
	adds r1, #0x24
	adds r0, #0x1e
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _080A34C4
	mov r8, r2
_080A346A:
	mov r1, r8
	ldr r0, [r1]
	lsls r1, r5, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #7
	beq _080A3498
	cmp r0, #8
	beq _080A34A8
	b _080A34B0
	.align 2, 0
_080A3494: .4byte 0x03002B4C
_080A3498:
	adds r0, r7, #0
	ldr r1, _080A34A4 @ =FUN_080a2a4c
	bl FUN_080a2a14
	b _080A34B0
	.align 2, 0
_080A34A4: .4byte FUN_080a2a4c
_080A34A8:
	adds r0, r7, #0
	ldr r1, _080A34D0 @ =FUN_080a2b78
	bl FUN_080a2a14
_080A34B0:
	adds r5, #1
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #6
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r5, r0
	blt _080A346A
_080A34C4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A34D0: .4byte FUN_080a2b78

	thumb_func_start FUN_080a34d4
FUN_080a34d4: @ 0x080A34D4
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080a3448
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r5, #0
_080A34EC:
	movs r0, #0x34
	adds r1, r5, #0
	muls r1, r0, r1
	adds r0, r4, r1
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A350A
	subs r2, #0x28
	adds r0, r1, r2
	adds r0, r4, r0
	bl FUN_080a251c
_080A350A:
	adds r5, #1
	cmp r5, #7
	ble _080A34EC
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3518
FUN_080a3518: @ 0x080A3518
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r0, #0x50
	bl FUN_0822a4e0
	adds r0, r6, #0
	adds r0, #0xa0
	bl FUN_0822a4e0
	adds r4, r6, #0
	adds r4, #0xe8
	movs r5, #2
_080A3530:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080A3530
	adds r7, r6, #0
	adds r7, #0x18
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #7
_080A354A:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080A354A
	adds r0, r7, #0
	bl FUN_08022428
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a3568
FUN_080a3568: @ 0x080A3568
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _080A35F8 @ =0x00001C1E
	mov sb, r0
	movs r0, #0
	mov sl, r0
	subs r0, #4
	mov r8, r0
_080A3582:
	movs r0, #0x34
	adds r5, r7, #0
	muls r5, r0, r5
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r4, r6, r4
	mov r0, sb
	bl FUN_0822b10c
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r0, sb
	bl FUN_0822b10c
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	adds r0, r6, #0
	adds r0, #0x98
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	adds r5, r6, r5
	movs r0, #0xf8
	lsls r0, r0, #1
	adds r5, r5, r0
	mov r0, sl
	strb r0, [r5]
	adds r7, #1
	cmp r7, #7
	ble _080A3582
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A35F8: .4byte 0x00001C1E

	thumb_func_start FUN_080a35fc
FUN_080a35fc: @ 0x080A35FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	str r1, [sp]
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A36BC
	bl fetch_082316e4
	adds r4, r7, #0
	adds r4, #0x98
	strh r0, [r4]
	bl fetch_082316e4
	adds r5, r7, #0
	adds r5, #0x9a
	strh r0, [r5]
	bl fetch_082316e4
	adds r1, r7, #0
	adds r1, #0x9c
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xc]
	cmp r2, #0
	blt _080A365C
	cmp r1, #0
	blt _080A365C
	ldr r0, _080A3660 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A365C
	ldr r0, _080A3664 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A3668
_080A365C:
	movs r6, #0
	b _080A3676
	.align 2, 0
_080A3660: .4byte 0x030046A8
_080A3664: .4byte 0x030046AC
_080A3668:
	ldr r0, _080A3688 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A3676:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A368C
	adds r0, #4
	b _080A3698
	.align 2, 0
_080A3688: .4byte 0x030046A4
_080A368C:
	ldr r0, _080A36AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A3698:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A36B0
	cmp r2, #2
	beq _080A36B4
	b _080A36B8
	.align 2, 0
_080A36AC: .4byte 0x030046A4
_080A36B0:
	ldrb r0, [r4, #4]
	b _080A36B6
_080A36B4:
	ldrb r0, [r4]
_080A36B6:
	subs r1, r1, r0
_080A36B8:
	strh r1, [r5]
	b _080A36CE
_080A36BC:
	adds r1, r7, #0
	adds r1, #0x98
	strh r2, [r1]
	adds r0, r7, #0
	adds r0, #0x9a
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	str r1, [sp, #0xc]
_080A36CE:
	movs r0, #0x43
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A36E8
	bl fetch_082316e4
	movs r2, #0xdb
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A36F0
_080A36E8:
	movs r3, #0xdb
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A36F0:
	movs r0, #0x63
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A370A
	bl fetch_082316e4
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3712
_080A370A:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3712:
	movs r0, #0x69
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A372C
	bl fetch_082316e4
	movs r2, #0xdc
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3734
_080A372C:
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3734:
	movs r0, #0x6f
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A374E
	bl fetch_082316e4
	movs r2, #0xdd
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A3756
_080A374E:
	movs r3, #0xdd
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A3756:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080A376A
	bl fetch_082316e4
	adds r1, r7, #0
	adds r1, #0x4e
	b _080A3770
_080A376A:
	adds r1, r7, #0
	adds r1, #0x4e
	movs r0, #6
_080A3770:
	strh r0, [r1]
	mov sl, r1
	movs r0, #0x61
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3790
	bl fetch_082316e4
	ldr r2, _080A378C @ =0x00000369
	adds r1, r7, r2
	strb r0, [r1]
	b _080A3796
	.align 2, 0
_080A378C: .4byte 0x00000369
_080A3790:
	ldr r3, _080A37B0 @ =0x00000369
	adds r0, r7, r3
	strb r1, [r0]
_080A3796:
	movs r0, #0x6e
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A37B4
	bl fetch_082316e4
	movs r2, #0xde
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _080A37BC
	.align 2, 0
_080A37B0: .4byte 0x00000369
_080A37B4:
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r7, r3
	str r1, [r0]
_080A37BC:
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #1
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #0x61
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r6, r7, r2
	strh r1, [r6]
	movs r3, #0x7c
	adds r3, r3, r7
	mov r8, r3
	ldr r5, _080A3930 @ =0x00000BA8
	mov r0, r8
	adds r1, r5, #0
	bl FUN_0822b16c
	adds r4, r7, #0
	adds r4, #0x50
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_0822a470
	mov r1, sl
	ldrh r0, [r1]
	strh r0, [r4, #0x10]
	ldrh r1, [r6]
	mov r0, r8
	bl FUN_0822b20c
	ldr r0, [r7, #0x50]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x50]
	adds r0, r7, #0
	adds r0, #0x57
	movs r2, #3
	mov sb, r2
	mov r3, sb
	strb r3, [r0]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x6c]
	str r1, [r7, #0x70]
	adds r4, #0x7c
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822b16c
	adds r5, r7, #0
	adds r5, #0xa0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	mov r3, sl
	ldrh r0, [r3]
	strh r0, [r5, #0x10]
	ldrh r1, [r6]
	adds r0, r4, #0
	bl FUN_0822b20c
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r5]
	adds r0, r7, #0
	adds r0, #0xa7
	mov r1, sb
	strb r1, [r0]
	adds r2, r7, #0
	adds r2, #0xbc
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	mov sb, r0
	mov r1, r8
	str r1, [sp, #8]
	mov r8, r5
	adds r2, #0x2c
	str r2, [sp, #0x10]
	adds r3, r7, #0
	adds r3, #0x18
	str r3, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x4c
	str r0, [sp, #4]
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r6, r7, r1
_080A3882:
	adds r0, r6, #0
	ldr r1, _080A3930 @ =0x00000BA8
	bl FUN_0822b16c
	movs r0, #0x2c
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0xe8
	adds r0, r7, r0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a470
	mov r2, sl
	ldrh r0, [r2]
	movs r5, #1
	adds r1, r5, #0
	ands r1, r0
	adds r0, r4, r7
	adds r0, #0xe8
	adds r1, #0x10
	strh r1, [r0, #0x10]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r1, #2
	adds r0, r6, #0
	bl FUN_0822b20c
	ldr r0, [sp, #0x10]
	adds r2, r0, r4
	ldr r0, [r2]
	ldr r1, _080A3934 @ =0x00000201
	orrs r0, r1
	str r0, [r2]
	adds r1, r7, r4
	adds r0, r1, #0
	adds r0, #0xef
	movs r2, #1
	strb r2, [r0]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r1, r3
	ldr r3, [sp, #0xc]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, #0x1c
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #2
	ble _080A3882
	adds r0, r7, #0
	bl FUN_080a3568
	ldr r0, [sp, #0x14]
	ldr r1, [sp]
	movs r2, #0xa
	bl FUN_080223f4
	movs r0, #0x44
	bl prepare_08231510
	cmp r0, #0
	beq _080A3940
	movs r2, #0
	movs r1, #0
	ldr r3, [sp, #4]
	strh r1, [r3]
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	ldr r3, _080A3938 @ =0x0000036A
	adds r0, r7, r3
	strh r1, [r0]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, _080A393C @ =0x080A2A2D
	b _080A3A70
	.align 2, 0
_080A3930: .4byte 0x00000BA8
_080A3934: .4byte 0x00000201
_080A3938: .4byte 0x0000036A
_080A393C: .4byte 0x080A2A2D
_080A3940:
	movs r4, #0
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A3952
	bl fetch_082316e4
	adds r4, r0, #0
_080A3952:
	movs r6, #0
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080A3964
	bl fetch_082316e4
	adds r6, r0, #0
_080A3964:
	cmp r4, #0
	beq _080A3A24
	movs r0, #0xb0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r5, [r0]
	movs r0, #0
	bl FUN_080a6e88
	ldr r4, _080A3A18 @ =0x03002BE0
	ldr r0, [r4]
	ldr r1, [sp, #0xc]
	bl FUN_0807a91c
	ldr r0, [r4]
	bl FUN_0807b8dc
	ldr r0, [r7, #0x50]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x50]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrh r1, [r0]
	adds r1, #2
	ldr r0, [sp, #8]
	bl FUN_0822b20c
	mov r1, r8
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #7
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_080a2804
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #8
	strh r0, [r1]
	ldr r0, [sp, #4]
	strh r5, [r0]
	ldr r2, _080A3A1C @ =0x0000036A
	adds r1, r7, r2
	movs r0, #0xa
	strh r0, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r0, #0x18
	strb r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r6, [r0]
	ldr r1, _080A3A20 @ =FUN_080a31dc
	adds r0, r7, #0
	bl FUN_080a2a14
	movs r4, #0
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _080A3A02
	bl fetch_082316e4
	adds r4, r0, #0
_080A3A02:
	cmp r4, #0
	beq _080A3A88
	bl FUN_08086af0
	cmp r0, #0
	beq _080A3A88
	ldr r0, [sp, #0xc]
	bl FUN_08086a4c
	b _080A3A88
	.align 2, 0
_080A3A18: .4byte 0x03002BE0
_080A3A1C: .4byte 0x0000036A
_080A3A20: .4byte FUN_080a31dc
_080A3A24:
	movs r0, #0
	ldr r2, [sp, #4]
	strh r4, [r2]
	movs r3, #0xe3
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r4, [r1]
	ldr r2, _080A3A78 @ =0x0000036A
	adds r1, r7, r2
	strh r4, [r1]
	movs r3, #0xda
	lsls r3, r3, #2
	adds r1, r7, r3
	strb r0, [r1]
	cmp r6, #0
	beq _080A3A80
	movs r0, #0xaf
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r7, #0x50]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x50]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r7, #0
	adds r0, #0x58
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #0x4f
	strb r5, [r0]
	adds r0, #1
	strb r5, [r0]
	ldr r1, _080A3A7C @ =FUN_080a2d18
_080A3A70:
	adds r0, r7, #0
	bl FUN_080a2a14
	b _080A3A88
	.align 2, 0
_080A3A78: .4byte 0x0000036A
_080A3A7C: .4byte FUN_080a2d18
_080A3A80:
	ldr r1, _080A3A9C @ =FUN_080a2e20
	adds r0, r7, #0
	bl FUN_080a2a14
_080A3A88:
	movs r0, #0
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A3A9C: .4byte FUN_080a2e20

	thumb_func_start FUN_080a3aa0
FUN_080a3aa0: @ 0x080A3AA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xe2
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A3AE0
	ldr r1, _080A3AD8 @ =FUN_080a34d4
	ldr r2, _080A3ADC @ =FUN_080a3518
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a35fc
	cmp r0, #0
	bge _080A3AE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A3AE2
	.align 2, 0
_080A3AD8: .4byte FUN_080a34d4
_080A3ADC: .4byte FUN_080a3518
_080A3AE0:
	adds r0, r4, #0
_080A3AE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3ae8
FUN_080a3ae8: @ 0x080A3AE8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A3B5C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080A3B64
	ldr r0, _080A3B60 @ =0x03002BE0
	ldr r3, [r0]
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A3B64
	movs r1, #0x2c
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0xac
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r2, r0, r1
	cmp r2, #0
	bge _080A3B26
	rsbs r2, r2, #0
_080A3B26:
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0xb0
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A3B3A
	rsbs r1, r1, #0
_080A3B3A:
	cmp r2, #0x60
	bgt _080A3B64
	cmp r1, #0x60
	bgt _080A3B64
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A3B64
	movs r0, #1
	b _080A3B66
	.align 2, 0
_080A3B5C: .4byte 0x030046A0
_080A3B60: .4byte 0x03002BE0
_080A3B64:
	movs r0, #0
_080A3B66:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3b6c
FUN_080a3b6c: @ 0x080A3B6C
	adds r2, r0, #0
	movs r3, #0x88
	lsls r3, r3, #1
	adds r0, r2, r3
	str r1, [r0]
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a3b84
FUN_080a3b84: @ 0x080A3B84
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A3BE4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A3BA6
	movs r0, #0x81
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A3BA6
	adds r0, #1
	strh r0, [r1]
_080A3BA6:
	adds r0, r4, #0
	bl FUN_080a3ae8
	adds r5, r0, #0
	cmp r5, #0
	beq _080A3C44
	ldrb r0, [r4, #0x1a]
	cmp r0, #1
	beq _080A3BC4
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4, #0x1a]
_080A3BC4:
	adds r0, r4, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #7
	bhi _080A3BD4
	adds r0, r1, #1
	strh r0, [r6]
_080A3BD4:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x16
	bhi _080A3BE8
	adds r0, #2
	b _080A3BEA
	.align 2, 0
_080A3BE4: .4byte 0x030047A4
_080A3BE8:
	movs r0, #0x18
_080A3BEA:
	strh r0, [r1]
	movs r2, #1
	ldr r0, _080A3C34 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A3C7A
	ldr r0, _080A3C38 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A3C7A
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A3C7A
	movs r0, #8
	strh r0, [r6]
	movs r0, #1
	bl FUN_080a6e88
	ldr r0, _080A3C3C @ =0x03002BE0
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #0xac
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A3C40 @ =FUN_080a3cec
	adds r0, r4, #0
	bl FUN_080a3b6c
	b _080A3C7A
	.align 2, 0
_080A3C34: .4byte 0x03002BC0
_080A3C38: .4byte 0x030044E0
_080A3C3C: .4byte 0x03002BE0
_080A3C40: .4byte FUN_080a3cec
_080A3C44:
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _080A3C52
	ldr r0, _080A3C74 @ =0x00000199
	bl PlaySound_082406e0
	strb r5, [r4, #0x1a]
_080A3C52:
	adds r0, r4, #0
	adds r0, #0xfe
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _080A3C62
	subs r0, r1, #1
	strh r0, [r6]
_080A3C62:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #2
	bls _080A3C78
	subs r0, #2
	strh r0, [r1]
	b _080A3C7A
	.align 2, 0
_080A3C74: .4byte 0x00000199
_080A3C78:
	strh r5, [r1]
_080A3C7A:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r0, [r2]
	cmp r0, #0
	bne _080A3C90
	ldr r0, [r4, #0x64]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x64]
	b _080A3CAA
_080A3C90:
	ldr r0, [r4, #0x64]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0xae
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x82
	strh r0, [r1]
_080A3CAA:
	ldrh r0, [r6]
	cmp r0, #7
	bls _080A3CC2
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	adds r1, #2
	bl FUN_0822b20c
	b _080A3CE6
_080A3CC2:
	cmp r0, #0
	beq _080A3CD8
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	adds r1, #1
	bl FUN_0822b20c
	b _080A3CE6
_080A3CD8:
	adds r0, r4, #0
	adds r0, #0x90
	adds r1, r4, #0
	adds r1, #0xfc
	ldrh r1, [r1]
	bl FUN_0822b20c
_080A3CE6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a3cec
FUN_080a3cec: @ 0x080A3CEC
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #1
	bls _080A3D02
	subs r0, #2
	b _080A3D04
_080A3D02:
	movs r0, #0
_080A3D04:
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xae
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	adds r2, r4, #0
	adds r2, #0x82
	strh r1, [r2]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A3D8A
	ldr r0, _080A3D94 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A3D8A
	ldr r0, [r4, #0x64]
	ldr r1, _080A3D98 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x64]
	adds r1, r4, #0
	adds r1, #0x6b
	movs r0, #3
	strb r0, [r1]
	adds r2, #0x32
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080A3D9C @ =0x080A3DA5
	adds r0, r4, #0
	bl FUN_080a3b6c
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A3D8A
	ldr r1, _080A3DA0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r2, #0
	bl FUN_082318ac
_080A3D8A:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A3D94: .4byte 0x03002BE0
_080A3D98: .4byte 0xFFFFFDFF
_080A3D9C: .4byte 0x080A3DA5
_080A3DA0: .4byte 0xFFFF0000
_080A3DA4:
	.byte 0x70, 0x47, 0x00, 0x00, 0x00, 0xB5, 0x88, 0x22, 0x52, 0x00, 0x81, 0x18
	.byte 0x09, 0x68, 0xA9, 0xF1, 0x57, 0xF8, 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080a3dbc
FUN_080a3dbc: @ 0x080A3DBC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x64
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xb4
	bl FUN_0822a4e0
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080A3DDC
	adds r0, r4, #0
	adds r0, #0x20
	bl FUN_0823b284
_080A3DDC:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a3de4
FUN_080a3de4: @ 0x080A3DE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	strh r1, [r7, #0x18]
	movs r0, #0x70
	bl prepare_08231510
	adds r3, r0, #0
	cmp r3, #0
	beq _080A3EA4
	bl fetch_082316e4
	adds r4, r7, #0
	adds r4, #0xac
	strh r0, [r4]
	bl fetch_082316e4
	adds r5, r7, #0
	adds r5, #0xae
	strh r0, [r5]
	bl fetch_082316e4
	adds r1, r7, #0
	adds r1, #0xb0
	strh r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r4, [sp, #0xc]
	cmp r2, #0
	blt _080A3E44
	cmp r1, #0
	blt _080A3E44
	ldr r0, _080A3E48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A3E44
	ldr r0, _080A3E4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A3E50
_080A3E44:
	movs r6, #0
	b _080A3E5E
	.align 2, 0
_080A3E48: .4byte 0x030046A8
_080A3E4C: .4byte 0x030046AC
_080A3E50:
	ldr r0, _080A3E70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080A3E5E:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A3E74
	adds r0, #4
	b _080A3E80
	.align 2, 0
_080A3E70: .4byte 0x030046A4
_080A3E74:
	ldr r0, _080A3E94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A3E80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A3E98
	cmp r2, #2
	beq _080A3E9C
	b _080A3EA0
	.align 2, 0
_080A3E94: .4byte 0x030046A4
_080A3E98:
	ldrb r0, [r4, #4]
	b _080A3E9E
_080A3E9C:
	ldrb r0, [r4]
_080A3E9E:
	subs r1, r1, r0
_080A3EA0:
	strh r1, [r5]
	b _080A3EB6
_080A3EA4:
	adds r1, r7, #0
	adds r1, #0xac
	strh r3, [r1]
	adds r0, r7, #0
	adds r0, #0xae
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	str r1, [sp, #0xc]
_080A3EB6:
	movs r0, #0x73
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A3ED0
	bl fetch_082316e4
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	b _080A3ED8
_080A3ED0:
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r7, r2
	str r1, [r0]
_080A3ED8:
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080A3F2C
	adds r0, r7, #0
	adds r0, #0xfc
	str r0, [sp, #8]
	movs r1, #0x90
	adds r1, r1, r7
	mov r8, r1
	adds r2, r7, #0
	adds r2, #0x64
	str r2, [sp, #0x18]
	subs r0, #0x91
	str r0, [sp, #0x1c]
	adds r1, r7, #0
	adds r1, #0x80
	str r1, [sp, #0x20]
	movs r2, #0xe0
	adds r2, r2, r7
	mov sl, r2
	movs r0, #0xb4
	adds r0, r0, r7
	mov sb, r0
	adds r1, #0x3b
	str r1, [sp, #0x10]
	adds r2, r7, #0
	adds r2, #0xd0
	str r2, [sp, #0x14]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r7, r0
	movs r5, #1
_080A3F1C:
	bl fetch_082316e4
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080A3F1C
	b _080A3F72
_080A3F2C:
	adds r1, r7, #0
	adds r1, #0xfc
	str r1, [sp, #8]
	movs r2, #0x90
	adds r2, r2, r7
	mov r8, r2
	adds r0, r7, #0
	adds r0, #0x64
	str r0, [sp, #0x18]
	subs r1, #0x91
	str r1, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x80
	str r2, [sp, #0x20]
	movs r0, #0xe0
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0xb4
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0x3b
	str r2, [sp, #0x10]
	adds r0, r7, #0
	adds r0, #0xd0
	str r0, [sp, #0x14]
	movs r1, #0
	movs r5, #1
	movs r2, #0x83
	lsls r2, r2, #1
	adds r0, r7, r2
_080A3F68:
	strh r1, [r0]
	subs r0, #2
	subs r5, #1
	cmp r5, #0
	bge _080A3F68
_080A3F72:
	movs r0, #0x68
	bl prepare_08231510
	cmp r0, #0
	beq _080A3F80
	bl fetch_082316e4
_080A3F80:
	strb r0, [r7, #0x1b]
	ldrb r0, [r7, #0x1b]
	cmp r0, #0
	beq _080A3FA4
	adds r4, r7, #0
	adds r4, #0x20
	ldrh r1, [r7, #0x18]
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0xc]
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	bl FUN_08002a48
_080A3FA4:
	movs r0, #0x6a
	ldr r1, [sp, #8]
	strh r0, [r1]
	ldr r6, _080A4044 @ =0x00000BA8
	mov r0, r8
	adds r1, r6, #0
	bl FUN_0822b16c
	ldr r0, [sp, #0x18]
	mov r1, r8
	movs r2, #0
	bl FUN_0822a470
	movs r5, #7
	ldr r2, [sp, #0x18]
	strh r5, [r2, #0x10]
	ldr r0, [sp, #8]
	ldrh r1, [r0]
	mov r0, r8
	bl FUN_0822b20c
	ldr r0, [r7, #0x64]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r7, #0x64]
	movs r4, #3
	ldr r1, [sp, #0x1c]
	strb r4, [r1]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [sp, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, sl
	adds r1, r6, #0
	bl FUN_0822b16c
	mov r0, sb
	mov r1, sl
	movs r2, #0
	bl FUN_0822a470
	mov r0, sb
	strh r5, [r0, #0x10]
	ldr r2, [sp, #8]
	ldrh r1, [r2]
	mov r0, sl
	bl FUN_0822b20c
	mov r1, sb
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	mov r2, sb
	str r0, [r2]
	ldr r0, [sp, #0x10]
	strb r4, [r0]
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	ldr r2, [sp, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A4048 @ =FUN_080a3b84
	adds r0, r7, #0
	bl FUN_080a3b6c
	movs r0, #0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4044: .4byte 0x00000BA8
_080A4048: .4byte FUN_080a3b84

	thumb_func_start FUN_080a404c
FUN_080a404c: @ 0x080A404C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x8a
	lsls r1, r1, #1
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A408C
	ldr r1, _080A4084 @ =0x080A3DA9
	ldr r2, _080A4088 @ =FUN_080a3dbc
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a3de4
	cmp r0, #0
	bge _080A408C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A408E
	.align 2, 0
_080A4084: .4byte 0x080A3DA9
_080A4088: .4byte FUN_080a3dbc
_080A408C:
	adds r0, r4, #0
_080A408E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4094
FUN_080a4094: @ 0x080A4094
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A40E4 @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	adds r0, r4, #0
	adds r0, #0x64
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _080A40B0
	rsbs r2, r2, #0
_080A40B0:
	movs r1, #0x34
	ldrsh r0, [r3, r1]
	adds r1, r4, #0
	adds r1, #0x68
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r0, r1
	cmp r1, #0
	bge _080A40C4
	rsbs r1, r1, #0
_080A40C4:
	cmp r2, #0x60
	bgt _080A40E8
	cmp r1, #0x60
	bgt _080A40E8
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x90
	lsls r1, r1, #6
	cmp r0, r1
	bgt _080A40E8
	movs r0, #1
	b _080A40EA
	.align 2, 0
_080A40E4: .4byte 0x030046A0
_080A40E8:
	movs r0, #0
_080A40EA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a40f0
FUN_080a40f0: @ 0x080A40F0
	adds r2, r0, #0
	adds r2, #0xc8
	str r1, [r2]
	adds r0, #0xc4
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a4100
FUN_080a4100: @ 0x080A4100
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _080A4160 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080A4120
	adds r1, r4, #0
	adds r1, #0xba
	ldrh r0, [r1]
	cmp r0, #9
	bhi _080A4120
	adds r0, #1
	strh r0, [r1]
_080A4120:
	adds r0, r4, #0
	bl FUN_080a4094
	adds r6, r0, #0
	cmp r6, #0
	beq _080A41CC
	ldrh r0, [r4, #0x18]
	cmp r0, #1
	beq _080A413E
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r4, #0x18]
_080A413E:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #7
	bhi _080A414E
	adds r0, r1, #1
	strh r0, [r7]
_080A414E:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #0x16
	bhi _080A4164
	adds r0, r1, #2
	b _080A4166
	.align 2, 0
_080A4160: .4byte 0x030047A4
_080A4164:
	movs r0, #0x18
_080A4166:
	strh r0, [r5]
	movs r2, #1
	ldr r0, _080A41BC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _080A4202
	ldr r0, _080A41C0 @ =0x030044E0
	ldrh r1, [r0, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080A4202
	ldr r6, _080A41C4 @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A4202
	adds r0, r4, #0
	adds r0, #0xba
	ldrh r0, [r0]
	cmp r0, #9
	bls _080A4202
	movs r0, #8
	strh r0, [r7]
	movs r0, #1
	bl FUN_080a6e88
	ldr r0, [r6]
	adds r1, r4, #0
	adds r1, #0x64
	movs r2, #0
	movs r3, #4
	bl FUN_0807ba94
	ldr r1, _080A41C8 @ =FUN_080a4250
	adds r0, r4, #0
	bl FUN_080a40f0
	b _080A4202
	.align 2, 0
_080A41BC: .4byte 0x03002BC0
_080A41C0: .4byte 0x030044E0
_080A41C4: .4byte 0x03002BE0
_080A41C8: .4byte FUN_080a4250
_080A41CC:
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080A41DA
	ldr r0, _080A41FC @ =0x00000199
	bl PlaySound_082406e0
	strh r6, [r4, #0x18]
_080A41DA:
	adds r0, r4, #0
	adds r0, #0xb6
	ldrh r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	beq _080A41EA
	subs r0, r1, #1
	strh r0, [r7]
_080A41EA:
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	adds r5, r0, #0
	cmp r1, #2
	bls _080A4200
	subs r0, r1, #2
	strh r0, [r5]
	b _080A4202
	.align 2, 0
_080A41FC: .4byte 0x00000199
_080A4200:
	strh r6, [r5]
_080A4202:
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A4212
	ldr r0, [r4, #0x1c]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x1c]
	b _080A4228
_080A4212:
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x66
	ldrh r0, [r5]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x3a]
_080A4228:
	ldrh r0, [r7]
	cmp r0, #7
	bls _080A423C
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0x8f
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _080A424A
_080A423C:
	adds r0, r4, #0
	adds r0, #0x48
	adds r1, r4, #0
	adds r1, #0xb4
	ldrh r1, [r1]
	bl FUN_0822b20c
_080A424A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4250
FUN_080a4250: @ 0x080A4250
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xb8
	ldrh r0, [r1]
	cmp r0, #1
	bls _080A4264
	subs r0, #2
	b _080A4266
_080A4264:
	movs r0, #0
_080A4266:
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0x66
	adds r0, r4, #0
	adds r0, #0xb8
	ldrh r1, [r0]
	ldrh r2, [r2]
	adds r1, r1, r2
	strh r1, [r4, #0x3a]
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A42E0
	ldr r0, _080A42E8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A42E0
	ldr r0, [r4, #0x1c]
	ldr r1, _080A42EC @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0x23
	movs r0, #3
	strb r0, [r1]
	ldr r0, [r4, #0x6c]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x6c]
	ldr r1, _080A42F0 @ =0x080A42F9
	adds r0, r4, #0
	bl FUN_080a40f0
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r2, [r0]
	cmp r2, #0
	beq _080A42E0
	ldr r1, _080A42F4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0xbc
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r0, #0xbe
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r2, #0
	bl FUN_082318ac
_080A42E0:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A42E8: .4byte 0x03002BE0
_080A42EC: .4byte 0xFFFFFDFF
_080A42F0: .4byte 0x080A42F9
_080A42F4: .4byte 0xFFFF0000
_080A42F8:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a42fc
FUN_080a42fc: @ 0x080A42FC
	push {lr}
	adds r1, r0, #0
	adds r1, #0xc8
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080A4310:
	.byte 0x10, 0xB5, 0x04, 0x1C, 0x1C, 0x30, 0x86, 0xF1, 0xE3, 0xF8, 0x6C, 0x34, 0x20, 0x1C, 0x86, 0xF1
	.byte 0xDF, 0xF8, 0x00, 0x20, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a432c
FUN_080a432c: @ 0x080A432C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A4348
	bl fetch_082316e4
_080A4348:
	strb r0, [r6, #0x1a]
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A43FC
	bl fetch_082316e4
	adds r4, r6, #0
	adds r4, #0x64
	strh r0, [r4]
	bl fetch_082316e4
	adds r5, r6, #0
	adds r5, #0x66
	strh r0, [r5]
	bl fetch_082316e4
	adds r1, r6, #0
	adds r1, #0x68
	strh r0, [r1]
	adds r7, r4, #0
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A439A
	cmp r1, #0
	blt _080A439A
	ldr r0, _080A43A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A439A
	ldr r0, _080A43A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A43A8
_080A439A:
	movs r4, #0
	b _080A43B6
	.align 2, 0
_080A43A0: .4byte 0x030046A8
_080A43A4: .4byte 0x030046AC
_080A43A8:
	ldr r0, _080A43C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A43B6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A43CC
	adds r0, #4
	b _080A43D8
	.align 2, 0
_080A43C8: .4byte 0x030046A4
_080A43CC:
	ldr r0, _080A43EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A43D8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A43F0
	cmp r2, #2
	beq _080A43F4
	b _080A43F8
	.align 2, 0
_080A43EC: .4byte 0x030046A4
_080A43F0:
	ldrb r0, [r7, #4]
	b _080A43F6
_080A43F4:
	ldrb r0, [r7]
_080A43F6:
	subs r1, r1, r0
_080A43F8:
	strh r1, [r5]
	b _080A440A
_080A43FC:
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A440A:
	movs r0, #0x52
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4422
	bl fetch_082316e4
	adds r1, r6, #0
	adds r1, #0xc0
	str r0, [r1]
	b _080A4428
_080A4422:
	adds r0, r6, #0
	adds r0, #0xc0
	str r1, [r0]
_080A4428:
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080A4474
	movs r0, #0xb4
	adds r0, r0, r6
	mov r8, r0
	adds r7, r6, #0
	adds r7, #0x48
	movs r1, #0x1c
	adds r1, r1, r6
	mov sl, r1
	adds r2, r6, #0
	adds r2, #0x23
	str r2, [sp, #0xc]
	movs r0, #0x98
	adds r0, r0, r6
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x6c
	str r1, [sp]
	adds r2, #0x50
	str r2, [sp, #4]
	adds r0, r6, #0
	adds r0, #0x88
	str r0, [sp, #8]
	adds r4, r6, #0
	adds r4, #0xbc
	movs r5, #1
_080A4464:
	bl fetch_082316e4
	strh r0, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080A4464
	b _080A44AE
_080A4474:
	movs r1, #0xb4
	adds r1, r1, r6
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0x48
	movs r2, #0x1c
	adds r2, r2, r6
	mov sl, r2
	adds r0, r6, #0
	adds r0, #0x23
	str r0, [sp, #0xc]
	movs r1, #0x98
	adds r1, r1, r6
	mov sb, r1
	adds r2, r6, #0
	adds r2, #0x6c
	str r2, [sp]
	adds r0, #0x50
	str r0, [sp, #4]
	adds r1, r6, #0
	adds r1, #0x88
	str r1, [sp, #8]
	adds r1, #0x34
	movs r2, #0
	adds r0, #0x4b
_080A44A6:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080A44A6
_080A44AE:
	ldrb r0, [r6, #0x1a]
	cmp r0, #0
	bne _080A44BE
	movs r0, #0x8e
	lsls r0, r0, #1
	mov r2, r8
	strh r0, [r2]
	b _080A44C4
_080A44BE:
	ldr r0, _080A4548 @ =0x0000011D
	mov r1, r8
	strh r0, [r1]
_080A44C4:
	ldr r5, _080A454C @ =0x0000A152
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_0822b16c
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0822a470
	mov r2, r8
	ldrh r1, [r2]
	adds r0, r7, #0
	bl FUN_0822b20c
	ldr r0, [r6, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r6, #0x1c]
	movs r4, #3
	ldr r0, [sp, #0xc]
	strb r4, [r0]
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	mov r0, sb
	adds r1, r5, #0
	bl FUN_0822b16c
	ldr r0, [sp]
	mov r1, sb
	movs r2, #0
	bl FUN_0822a470
	mov r2, r8
	ldrh r1, [r2]
	mov r0, sb
	bl FUN_0822b20c
	ldr r0, [r6, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r6, #0x6c]
	ldr r0, [sp, #4]
	strb r4, [r0]
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	ldr r2, [sp, #8]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A4550 @ =FUN_080a4100
	adds r0, r6, #0
	bl FUN_080a40f0
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
_080A4548: .4byte 0x0000011D
_080A454C: .4byte 0x0000A152
_080A4550: .4byte FUN_080a4100

	thumb_func_start FUN_080a4554
FUN_080a4554: @ 0x080A4554
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #9
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4590
	ldr r1, _080A4588 @ =FUN_080a42fc
	ldr r2, _080A458C @ =0x080A4311
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a432c
	cmp r0, #0
	bge _080A4590
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A4592
	.align 2, 0
_080A4588: .4byte FUN_080a42fc
_080A458C: .4byte 0x080A4311
_080A4590:
	adds r0, r4, #0
_080A4592:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4598
FUN_080a4598: @ 0x080A4598
	movs r3, #0x84
	lsls r3, r3, #1
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0xec
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_080a45a8
FUN_080a45a8: @ 0x080A45A8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r0, #0xe4
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A45DE
	ldr r0, [r4]
	movs r1, #4
	ands r0, r1
	movs r5, #1
	cmp r0, #0
	beq _080A45C4
	movs r5, #2
_080A45C4:
	adds r0, r4, #0
	adds r0, #0xde
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080A45D4
	asrs r0, r0, #8
	b _080A45DA
_080A45D4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A45DA:
	adds r3, r0, #1
	b _080A45F6
_080A45DE:
	movs r5, #0
	adds r0, r4, #0
	adds r0, #0xde
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080A45F0
	asrs r3, r0, #8
	b _080A45F6
_080A45F0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r3, r0, #0
_080A45F6:
	adds r0, r4, #0
	adds r0, #0xf8
	adds r1, r4, #0
	adds r1, #0xea
	ldrh r1, [r1]
	movs r2, #0xff
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	adds r2, r5, #0
	bl FUN_08234270
	adds r1, r4, #0
	adds r1, #0xf7
	movs r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4620:
	.byte 0x10, 0xB5, 0x03, 0x1C, 0x14, 0x1C, 0xF4, 0x34, 0x20, 0x78, 0x00, 0x28, 0x16, 0xD1, 0x80, 0x21
	.byte 0x09, 0x02, 0x58, 0x6B, 0x08, 0x40, 0x00, 0x28, 0x10, 0xD0, 0x0A, 0x48, 0x00, 0x68, 0x0A, 0x49
	.byte 0x40, 0x18, 0x11, 0x1C, 0xF0, 0x31, 0x00, 0x22, 0x80, 0x5E, 0x0A, 0x88, 0x80, 0x18, 0x08, 0x80
	.byte 0x20, 0x20, 0x20, 0x70, 0x05, 0x48, 0x01, 0x68, 0x01, 0x20, 0x48, 0x76, 0x10, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03, 0x42, 0x09, 0x00, 0x00, 0x44, 0x2C, 0x00, 0x03

	thumb_func_start FUN_080a4670
FUN_080a4670: @ 0x080A4670
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xf0
	adds r1, r4, #0
	adds r1, #0xf2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A46A4
	adds r1, r4, #0
	adds r1, #0xf6
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080a45a8
	adds r2, r4, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A46AC @ =FUN_080a46b0
	adds r0, r4, #0
	bl FUN_080a4598
_080A46A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A46AC: .4byte FUN_080a46b0

	thumb_func_start FUN_080a46b0
FUN_080a46b0: @ 0x080A46B0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r6, #2
	strb r6, [r5, #7]
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A46CC
	movs r0, #0xd5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A46CC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A46E0
	movs r0, #1
	strh r0, [r5, #0x10]
	b _080A4718
_080A46E0:
	strh r6, [r5, #0x10]
	ldr r1, _080A4720 @ =0x080A4729
	adds r0, r5, #0
	bl FUN_080a4598
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A4718
	ldr r1, _080A4724 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r2, #0
	bl FUN_082318ac
_080A4718:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A4720: .4byte 0x080A4729
_080A4724: .4byte 0xFFFF0000
_080A4728:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a472c
FUN_080a472c: @ 0x080A472C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r2, r5, #0
	adds r2, #0xee
	ldrh r0, [r2]
	cmp r0, #0
	beq _080A4794
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r1, [r4]
	lsls r0, r1, #8
	subs r0, r0, r1
	ldrh r1, [r2]
	bl Div
	ldr r2, _080A4768 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r1, [r1, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080A476C
	asrs r1, r0, #0xc
	b _080A4772
	.align 2, 0
_080A4768: .4byte 0x085B0A08
_080A476C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A4772:
	adds r0, r5, #0
	adds r0, #0xde
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r1, r5, #0
	adds r1, #0xee
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A4794
	movs r0, #0
	strh r0, [r4]
_080A4794:
	adds r0, r5, #0
	adds r0, #0xf0
	adds r1, r5, #0
	adds r1, #0xf2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	blo _080A47C6
	adds r1, r5, #0
	adds r1, #0xf6
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080a45a8
	adds r2, r5, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _080A47CC @ =FUN_080a47d0
	adds r0, r5, #0
	bl FUN_080a4598
_080A47C6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A47CC: .4byte FUN_080a47d0

	thumb_func_start FUN_080a47d0
FUN_080a47d0: @ 0x080A47D0
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xec
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A47E8
	movs r0, #0xd5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A47E8:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A4808
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r0, #1
	strh r0, [r5, #0x10]
	b _080A4842
_080A4808:
	movs r0, #2
	strh r0, [r5, #0x10]
	ldr r1, _080A484C @ =FUN_080a4854
	adds r0, r5, #0
	bl FUN_080a4598
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A4842
	ldr r1, _080A4850 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r5, #0
	adds r0, #0xe8
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r2, #0
	bl FUN_082318ac
_080A4842:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A484C: .4byte FUN_080a4854
_080A4850: .4byte 0xFFFF0000

	thumb_func_start FUN_080a4854
FUN_080a4854: @ 0x080A4854
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080A4898 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xea
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _080A48A0
	adds r5, r4, #0
	adds r5, #0xde
	movs r2, #0x1e
	ldrsh r1, [r4, r2]
	movs r3, #0
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bne _080A4884
	ldr r0, _080A489C @ =0x000002B3
	bl PlaySound_082406e0
_080A4884:
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	subs r0, #0x10
	cmp r1, r0
	ble _080A48B6
	ldrh r0, [r4, #0x1e]
	subs r0, #2
	b _080A48B4
	.align 2, 0
_080A4898: .4byte 0x03002BE0
_080A489C: .4byte 0x000002B3
_080A48A0:
	adds r0, r4, #0
	adds r0, #0xde
	ldrh r2, [r4, #0x1e]
	movs r3, #0x1e
	ldrsh r1, [r4, r3]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bge _080A48B6
	adds r0, r2, #2
_080A48B4:
	strh r0, [r4, #0x1e]
_080A48B6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a48bc
FUN_080a48bc: @ 0x080A48BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _080A48DE
	ldr r0, _080A48FC @ =0x000001A9
	bl PlaySound_082406e0
	movs r1, #0
	movs r0, #0x20
	strb r0, [r4, #0x1b]
	strb r1, [r4, #0x19]
_080A48DE:
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _080A49BC
	subs r0, #1
	strb r0, [r4, #0x1b]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _080A4904
	ldr r0, _080A4900 @ =0x03003584
	ldr r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r0, r0, r1
	b _080A4912
	.align 2, 0
_080A48FC: .4byte 0x000001A9
_080A4900: .4byte 0x03003584
_080A4904:
	cmp r0, #0xf
	bls _080A4928
	ldr r0, _080A4920 @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r0, r2
_080A4912:
	adds r1, r4, #0
	adds r1, #0x1c
	ldr r2, _080A4924 @ =0x04000008
	bl CpuSet
	b _080A49BC
	.align 2, 0
_080A4920: .4byte 0x03003584
_080A4924: .4byte 0x04000008
_080A4928:
	ldrb r7, [r4, #0x1b]
	movs r0, #0x10
	subs r0, r0, r7
	str r0, [sp]
	ldr r0, _080A49CC @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r3, r3, r0
	mov sl, r3
	movs r5, #0xbe
	lsls r5, r5, #4
	adds r5, r5, r0
	mov r8, r5
	movs r6, #0
	mov sb, r6
	adds r4, #0x1c
	str r4, [sp, #4]
	movs r0, #0x1f
	mov ip, r0
_080A4950:
	mov r1, sl
	ldrh r3, [r1]
	movs r2, #0x1f
	ands r2, r3
	lsls r3, r3, #0x10
	lsrs r6, r3, #0x15
	mov r5, ip
	ands r6, r5
	lsrs r3, r3, #0x1a
	ands r3, r5
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x15
	ands r4, r5
	lsrs r1, r1, #0x1a
	ands r1, r5
	adds r5, r2, #0
	muls r5, r7, r5
	ldr r2, [sp]
	muls r0, r2, r0
	adds r5, r5, r0
	asrs r5, r5, #4
	adds r2, r6, #0
	muls r2, r7, r2
	ldr r6, [sp]
	adds r0, r4, #0
	muls r0, r6, r0
	adds r2, r2, r0
	asrs r2, r2, #4
	adds r0, r3, #0
	muls r0, r7, r0
	muls r1, r6, r1
	adds r0, r0, r1
	asrs r0, r0, #4
	mov r3, sb
	lsls r1, r3, #1
	ldr r6, [sp, #4]
	adds r1, r6, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r5
	strh r0, [r1]
	movs r0, #2
	add sl, r0
	add r8, r0
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #0xf
	ble _080A4950
_080A49BC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A49CC: .4byte 0x03003584

	thumb_func_start FUN_080a49d0
FUN_080a49d0: @ 0x080A49D0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl FUN_080a48bc
	movs r0, #0
	mov r8, r0
	ldrb r0, [r6, #0x18]
	cmp r8, r0
	bge _080A4A34
	adds r5, r6, #0
	adds r5, #0x68
	movs r0, #0x98
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r7, r6, #0
	adds r7, #0x3c
_080A49F4:
	ldr r1, [r4, #0x14]
	adds r0, r7, #0
	bl _call_via_r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A4A20
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A4A18
	movs r0, #0x60
	strh r0, [r5, #6]
	adds r0, r6, #0
	adds r0, #0x1c
	str r0, [r5, #0xc]
	b _080A4A20
_080A4A18:
	adds r0, r5, #0
	movs r1, #0x5f
	bl FUN_0822b20c
_080A4A20:
	movs r0, #0x88
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r0, #1
	add r8, r0
	ldrb r0, [r6, #0x18]
	cmp r8, r0
	blt _080A49F4
_080A4A34:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4a40
FUN_080a4a40: @ 0x080A4A40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	ldrb r0, [r5, #0x18]
	cmp sl, r0
	bge _080A4AAC
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sb, r0
	movs r0, #0x84
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0xd4
	ldr r0, _080A4AC0 @ =0x00000121
	adds r4, r5, r0
	adds r6, r5, #0
	adds r6, #0x3c
_080A4A70:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A4A7C
	adds r0, r7, #0
	bl FUN_0823b284
_080A4A7C:
	adds r0, r6, #0
	bl FUN_0822a4e0
	mov r0, r8
	bl FUN_08236424
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A4A94
	mov r0, sb
	bl FUN_082342a8
_080A4A94:
	movs r0, #0x88
	lsls r0, r0, #1
	add sb, r0
	add r8, r0
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, r6, r0
	movs r0, #1
	add sl, r0
	ldrb r0, [r5, #0x18]
	cmp sl, r0
	blt _080A4A70
_080A4AAC:
	ldr r1, _080A4AC4 @ =0x03002C44
	movs r0, #0
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4AC0: .4byte 0x00000121
_080A4AC4: .4byte 0x03002C44

	thumb_func_start FUN_080a4ac8
FUN_080a4ac8: @ 0x080A4AC8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r2, _080A4B3C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _080A4B40 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0xe6
	ldrh r1, [r0]
	ldr r2, _080A4B44 @ =0x00004002
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _080A4B48 @ =0x080A4621
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r4, #0xdc
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A4B3C: .4byte 0xFFFF0000
_080A4B40: .4byte 0x0000FFFF
_080A4B44: .4byte 0x00004002
_080A4B48: .4byte 0x080A4621

	thumb_func_start FUN_080a4b4c
FUN_080a4b4c: @ 0x080A4B4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	ldrb r1, [r0, #0x18]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, #0x3c
	mov r1, sb
	adds r5, r1, r0
	movs r0, #0x6e
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4B82
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xe6
	strh r0, [r1]
	mov sl, r1
	b _080A4B8A
_080A4B82:
	adds r0, r5, #0
	adds r0, #0xe6
	strh r1, [r0]
	mov sl, r0
_080A4B8A:
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4BB8
	bl fetch_082316e4
	adds r4, r5, #0
	adds r4, #0xdc
	strh r0, [r4]
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xde
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xe0
	strh r0, [r1]
	adds r6, r4, #0
	b _080A4BCA
_080A4BB8:
	adds r1, r5, #0
	adds r1, #0xdc
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0xde
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r6, r1, #0
_080A4BCA:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A4BEE
	cmp r1, #0
	blt _080A4BEE
	ldr r0, _080A4BF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A4BEE
	ldr r0, _080A4BF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A4BFC
_080A4BEE:
	movs r0, #0
	b _080A4C0A
	.align 2, 0
_080A4BF4: .4byte 0x030046A8
_080A4BF8: .4byte 0x030046AC
_080A4BFC:
	ldr r0, _080A4C24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080A4C0A:
	adds r2, r5, #0
	adds r2, #0xea
	strh r0, [r2]
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A4C28
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xe4
	b _080A4C2E
	.align 2, 0
_080A4C24: .4byte 0x030046A4
_080A4C28:
	adds r1, r5, #0
	adds r1, #0xe4
	movs r0, #0
_080A4C2E:
	strb r0, [r1]
	mov r8, r1
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, _080A4CB8 @ =0x0000D166
	cmp r0, #0
	bne _080A4C3E
	ldr r1, _080A4CBC @ =0x0000C3C3
_080A4C3E:
	adds r7, r5, #0
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #3
	strb r0, [r5, #7]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A4C72
	bl fetch_082316e4
	cmp r0, #0
	beq _080A4C72
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	str r0, [r5]
_080A4C72:
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r0, #0x68
	bl prepare_08231510
	cmp r0, #0
	beq _080A4CC0
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A4CC6
	adds r4, r5, #0
	adds r4, #0x98
	mov r0, sl
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	bl FUN_08002a48
	b _080A4CC6
	.align 2, 0
_080A4CB8: .4byte 0x0000D166
_080A4CBC: .4byte 0x0000C3C3
_080A4CC0:
	adds r1, r5, #0
	adds r1, #0xe5
	strb r0, [r1]
_080A4CC6:
	adds r0, r5, #0
	adds r0, #0xf0
	movs r1, #0
	strh r1, [r0]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _080A4CE2
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xf2
	b _080A4CE8
_080A4CE2:
	adds r1, r5, #0
	adds r1, #0xf2
	movs r0, #0xa
_080A4CE8:
	strh r0, [r1]
	movs r0, #0x57
	bl prepare_08231510
	cmp r0, #0
	beq _080A4CF8
	bl fetch_082316e4
_080A4CF8:
	adds r1, r5, #0
	adds r1, #0xee
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080a4ac8
	adds r1, r5, #0
	adds r1, #0xf4
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x73
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A4D26
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xf6
	strb r0, [r1]
	adds r0, r1, #0
	b _080A4D2C
_080A4D26:
	adds r0, r5, #0
	adds r0, #0xf6
	strb r1, [r0]
_080A4D2C:
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A4D64
	adds r0, r5, #0
	bl FUN_080a45a8
	adds r2, r5, #0
	adds r2, #0x4e
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r0, #2
	strh r0, [r7, #0x10]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _080A4D5C
	movs r0, #2
	strb r0, [r7, #7]
	ldr r1, _080A4D58 @ =0x080A4729
	b _080A4D7A
	.align 2, 0
_080A4D58: .4byte 0x080A4729
_080A4D5C:
	ldr r1, _080A4D60 @ =FUN_080a4854
	b _080A4D7A
	.align 2, 0
_080A4D60: .4byte FUN_080a4854
_080A4D64:
	adds r1, r5, #0
	adds r1, #0xf7
	strb r0, [r1]
	strh r0, [r7, #0x10]
	movs r0, #3
	strb r0, [r7, #7]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	bne _080A4D88
	ldr r1, _080A4D84 @ =FUN_080a4670
_080A4D7A:
	adds r0, r5, #0
	bl FUN_080a4598
	b _080A4D90
	.align 2, 0
_080A4D84: .4byte FUN_080a4670
_080A4D88:
	ldr r1, _080A4DB4 @ =FUN_080a472c
	adds r0, r5, #0
	bl FUN_080a4598
_080A4D90:
	movs r0, #0x67
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4DB8
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xe8
	strh r0, [r1]
	bl fetch_082316e4
	movs r2, #0x86
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	b _080A4DC8
	.align 2, 0
_080A4DB4: .4byte FUN_080a472c
_080A4DB8:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, _080A4DE0 @ =0x0000FFFF
	strh r1, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	str r2, [r0]
_080A4DC8:
	mov r2, sb
	ldrb r0, [r2, #0x18]
	adds r0, #1
	strb r0, [r2, #0x18]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A4DE0: .4byte 0x0000FFFF

	thumb_func_start FUN_080a4de4
FUN_080a4de4: @ 0x080A4DE4
	push {r4, lr}
	ldr r1, _080A4E0C @ =0x000008BC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4E00
	ldr r1, _080A4E10 @ =FUN_080a49d0
	ldr r2, _080A4E14 @ =FUN_080a4a40
	bl SetEntityRoutine
	movs r0, #0
	strb r0, [r4, #0x18]
_080A4E00:
	ldr r0, _080A4E18 @ =0x03002C44
	str r4, [r0]
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A4E0C: .4byte 0x000008BC
_080A4E10: .4byte FUN_080a49d0
_080A4E14: .4byte FUN_080a4a40
_080A4E18: .4byte 0x03002C44

	thumb_func_start FUN_080a4e1c
FUN_080a4e1c: @ 0x080A4E1C
	push {r4, r5, r6, r7, lr}
	ldr r0, _080A4E38 @ =0x03002C44
	ldr r4, [r0]
	cmp r4, #0
	beq _080A4E70
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _080A4E46
	bl fetch_082316e4
	adds r5, r0, #0
	b _080A4E48
	.align 2, 0
_080A4E38: .4byte 0x03002C44
_080A4E3C:
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	b _080A4E72
_080A4E46:
	movs r5, #0
_080A4E48:
	movs r3, #0
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	bge _080A4E70
	adds r6, r0, #0
	movs r7, #0x92
	lsls r7, r7, #1
	adds r1, r4, r7
	adds r2, r4, #0
	movs r4, #0x88
	lsls r4, r4, #1
_080A4E5E:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	beq _080A4E3C
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	cmp r3, r6
	blt _080A4E5E
_080A4E70:
	movs r0, #0
_080A4E72:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a4e78
FUN_080a4e78: @ 0x080A4E78
	push {lr}
	ldr r0, _080A4E90 @ =0x03002C44
	ldr r0, [r0]
	cmp r0, #0
	bne _080A4E86
	bl FUN_080a4de4
_080A4E86:
	bl FUN_080a4b4c
	pop {r1}
	bx r1
	.align 2, 0
_080A4E90: .4byte 0x03002C44

	thumb_func_start FUN_080a4e94
FUN_080a4e94: @ 0x080A4E94
	push {r4, r5, r6, lr}
	ldr r4, _080A4EAC @ =0x03002C48
	ldr r0, [r4]
	cmp r0, #0
	beq _080A4EE0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _080A4EB8
	b _080A4EE0
	.align 2, 0
_080A4EAC: .4byte 0x03002C48
_080A4EB0:
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r5, r0
	b _080A4EE2
_080A4EB8:
	bl fetch_082316e4
	adds r6, r0, #0
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	cmp r2, r1
	bge _080A4EE0
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r5, #0
	movs r3, #0
_080A4ED0:
	ldrh r0, [r1, #0x1c]
	cmp r0, r6
	beq _080A4EB0
	adds r1, #0xb8
	adds r3, #0xb8
	adds r2, #1
	cmp r2, r4
	blt _080A4ED0
_080A4EE0:
	movs r0, #0
_080A4EE2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080A4EE8:
	.byte 0x10, 0xB5, 0xFF, 0xF7, 0xD3, 0xFF, 0x04, 0x1C
	.byte 0x00, 0x2C, 0x2C, 0xD0, 0x70, 0x20, 0x8C, 0xF1, 0x0B, 0xFB, 0x00, 0x28, 0x27, 0xD0, 0x8C, 0xF1
	.byte 0xF1, 0xFB, 0x21, 0x1C, 0x78, 0x31, 0x08, 0x80, 0x8C, 0xF1, 0xEC, 0xFB, 0x21, 0x1C, 0x7A, 0x31
	.byte 0x08, 0x80, 0x8C, 0xF1, 0xE7, 0xFB, 0x21, 0x1C, 0x7C, 0x31, 0x08, 0x80, 0x66, 0x20, 0x8C, 0xF1
	.byte 0xF7, 0xFA, 0x00, 0x28, 0x13, 0xD0, 0x8C, 0xF1, 0xDD, 0xFB, 0x21, 0x1C, 0x80, 0x31, 0x08, 0x80
	.byte 0x00, 0x04, 0x00, 0x28, 0x0B, 0xD0, 0xA1, 0x78, 0x01, 0x20, 0x08, 0x43, 0xA0, 0x70, 0x60, 0x6C
	.byte 0xA1, 0x6C, 0x20, 0x67, 0x61, 0x67, 0x21, 0x1C, 0x82, 0x31, 0x00, 0x20, 0x08, 0x80, 0x10, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080a4f54
FUN_080a4f54: @ 0x080A4F54
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4F70
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A4F70
	bl fetch_082316e4
	strh r0, [r4, #0x38]
_080A4F70:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4f78
FUN_080a4f78: @ 0x080A4F78
	push {lr}
	bl FUN_080a4e94
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4F8C
	ldr r0, [r2, #0x28]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x28]
_080A4F8C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a4f90
FUN_080a4f90: @ 0x080A4F90
	push {lr}
	bl FUN_080a4e94
	adds r2, r0, #0
	cmp r2, #0
	beq _080A4FA6
	ldr r0, [r2, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x28]
_080A4FA6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4fac
FUN_080a4fac: @ 0x080A4FAC
	push {r4, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A4FCC
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A4FCC
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x2f
	strb r0, [r1]
_080A4FCC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a4fd4
FUN_080a4fd4: @ 0x080A4FD4
	push {r4, r5, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5046
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080A5046
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x86
	strh r0, [r1]
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080A5046
	bl fetch_082316e4
	adds r5, r4, #0
	adds r5, #0x88
	strh r0, [r5]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A5046
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x8c
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _080A5036
	adds r0, r4, #0
	adds r0, #0x54
	subs r1, #8
	ldrh r1, [r1]
	ldrh r2, [r5]
	adds r1, r1, r2
	bl FUN_0822b20c
	b _080A5046
_080A5036:
	adds r1, r4, #0
	adds r1, #0x8a
	movs r0, #0
	strh r0, [r1]
	ldrb r1, [r4, #2]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #2]
_080A5046:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a504c
FUN_080a504c: @ 0x080A504C
	push {r4, r5, lr}
	bl FUN_080a4e94
	adds r4, r0, #0
	cmp r4, #0
	beq _080A50D2
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _080A50D2
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x90
	strh r0, [r1]
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080A50D2
	bl fetch_082316e4
	adds r5, r4, #0
	adds r5, #0x92
	strh r0, [r5]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A50D2
	bl fetch_082316e4
	adds r2, r4, #0
	adds r2, #0x96
	strh r0, [r2]
	ldrh r0, [r5]
	adds r3, r4, #0
	adds r3, #0x30
	strb r0, [r3]
	adds r1, r4, #0
	adds r1, #0x31
	strb r0, [r1]
	ldrh r0, [r2]
	cmp r0, #1
	bhi _080A50BA
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0x40
	beq _080A50D2
	ldr r0, [r4, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #0x28]
	b _080A50D2
_080A50BA:
	ldr r0, [r4, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #0x28]
	adds r1, r4, #0
	adds r1, #0x94
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4, #2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4, #2]
_080A50D2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a50d8
FUN_080a50d8: @ 0x080A50D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	bl FUN_080a4e94
	adds r5, r0, #0
	cmp r5, #0
	beq _080A51CC
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A51CC
	bl fetch_082316e4
	adds r7, r5, #0
	adds r7, #0x98
	strb r0, [r7]
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080A51CC
	bl fetch_082316e4
	adds r6, r5, #0
	adds r6, #0x99
	strb r0, [r6]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A51CC
	bl fetch_082316e4
	strb r0, [r5, #3]
	movs r4, #0
	movs r0, #0x45
	bl prepare_08231510
	cmp r0, #0
	beq _080A5130
	bl fetch_082316e4
	adds r4, r0, #0
_080A5130:
	cmp r4, #0
	beq _080A514E
	adds r4, r5, #0
	adds r4, #0x9c
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	ldrb r2, [r7]
	ldrb r3, [r6]
	ldrb r0, [r5, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08237040
	b _080A5166
_080A514E:
	adds r4, r5, #0
	adds r4, #0x9c
	adds r0, r5, #0
	adds r0, #0xac
	ldr r1, [r0]
	ldrb r2, [r7]
	ldrb r3, [r6]
	ldrb r0, [r5, #3]
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
_080A5166:
	movs r0, #0x50
	bl prepare_08231510
	cmp r0, #0
	beq _080A5180
	bl fetch_082316e4
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
_080A5180:
	movs r0, #0x6f
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A519A
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0x9a
	strb r0, [r1]
	adds r0, r1, #0
	b _080A51A0
_080A519A:
	adds r0, r5, #0
	adds r0, #0x9a
	strb r1, [r0]
_080A51A0:
	ldrb r1, [r0]
	cmp r1, #0
	beq _080A51BE
	movs r0, #0x65
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A51BE
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xb0
	str r0, [r1]
	b _080A51C4
_080A51BE:
	adds r0, r5, #0
	adds r0, #0xb0
	str r1, [r0]
_080A51C4:
	ldrb r1, [r5, #2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r5, #2]
_080A51CC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a51d4
FUN_080a51d4: @ 0x080A51D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldrb r1, [r7, #2]
	cmp r1, #0
	bne _080A51EA
	b _080A5556
_080A51EA:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A5284
	adds r6, r7, #0
	adds r6, #0x82
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0x80
	ldrh r1, [r5]
	ldrh r3, [r6]
	subs r4, r1, r3
	adds r0, r7, #0
	adds r0, #0x70
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r2, r0, #0
	muls r2, r4, r2
	mov r8, r2
	adds r2, r7, #0
	adds r2, #0x78
	movs r0, #0
	ldrsh r2, [r2, r0]
	muls r2, r3, r2
	mov r3, r8
	adds r0, r3, r2
	bl Div
	adds r1, r7, #0
	adds r1, #0x44
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x72
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r1, r7, #0
	adds r1, #0x7a
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldrh r1, [r6]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5]
	bl Div
	adds r1, r7, #0
	adds r1, #0x46
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0x74
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	adds r1, r7, #0
	adds r1, #0x7c
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldrh r1, [r6]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5]
	bl Div
	adds r1, r7, #0
	adds r1, #0x48
	strh r0, [r1]
	ldrh r0, [r6]
	ldrh r5, [r5]
	cmp r0, r5
	blo _080A5284
	ldrb r1, [r7, #2]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r7, #2]
_080A5284:
	ldrb r1, [r7, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080A5290
	b _080A53B6
_080A5290:
	adds r3, r7, #0
	adds r3, #0x8a
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x8c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	cmp r0, r1
	blo _080A52C8
	adds r0, r7, #0
	adds r0, #0x54
	adds r1, r7, #0
	adds r1, #0x84
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0x88
	ldrh r2, [r2]
	adds r1, r1, r2
	bl FUN_0822b20c
	ldrb r1, [r7, #2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r7, #2]
	b _080A53B6
_080A52C8:
	ldr r2, _080A5408 @ =0x03003584
	adds r0, r7, #0
	adds r0, #0x84
	ldrh r1, [r0]
	adds r0, #2
	ldrh r0, [r0]
	adds r0, r1, r0
	lsls r0, r0, #5
	ldr r2, [r2]
	adds r0, r2, r0
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r0, #0x88
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r2, r1
	str r2, [sp, #8]
	ldrh r1, [r4]
	ldrh r0, [r3]
	subs r1, r1, r0
	str r1, [sp, #0xc]
	adds r2, r7, #0
	adds r2, #8
	str r2, [sp, #0x14]
	adds r0, r7, #0
	adds r0, #0x5a
	str r0, [sp, #0x18]
	str r3, [sp, #0x10]
	mov sb, r4
	mov sl, r2
	movs r1, #0xf
	str r1, [sp]
_080A530A:
	ldr r2, [sp, #4]
	ldrh r5, [r2]
	movs r0, #0x1f
	ands r0, r5
	lsls r5, r5, #0x10
	lsrs r3, r5, #0x15
	movs r1, #0x1f
	ands r3, r1
	lsrs r5, r5, #0x1a
	ands r5, r1
	ldr r2, [sp, #8]
	ldrh r4, [r2]
	movs r2, #0x1f
	ands r2, r4
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x15
	ands r6, r1
	lsrs r4, r4, #0x1a
	ands r4, r1
	ldr r1, [sp, #0xc]
	muls r0, r1, r0
	ldr r1, [sp, #0x10]
	ldrh r1, [r1]
	mov r8, r1
	mov r1, r8
	muls r1, r2, r1
	adds r0, r0, r1
	mov r2, sb
	ldrh r1, [r2]
	str r3, [sp, #0x1c]
	bl Div
	mov r8, r0
	ldr r3, [sp, #0x1c]
	ldr r1, [sp, #0xc]
	adds r0, r3, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	muls r1, r6, r1
	adds r0, r0, r1
	mov r3, sb
	ldrh r1, [r3]
	bl Div
	adds r6, r0, #0
	ldr r1, [sp, #0xc]
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r3, sb
	ldrh r1, [r3]
	bl Div
	lsls r0, r0, #0xa
	lsls r6, r6, #5
	orrs r0, r6
	mov r1, r8
	orrs r0, r1
	mov r2, sl
	strh r0, [r2]
	ldr r3, [sp, #4]
	adds r3, #2
	str r3, [sp, #4]
	ldr r0, [sp, #8]
	adds r0, #2
	str r0, [sp, #8]
	movs r1, #2
	add sl, r1
	ldr r2, [sp]
	subs r2, #1
	str r2, [sp]
	cmp r2, #0
	bge _080A530A
	ldr r3, [sp, #0x14]
	str r3, [r7, #0x60]
	movs r1, #0x96
	lsls r1, r1, #2
	adds r0, r1, #0
	ldrh r2, [r7]
	adds r0, r0, r2
	ldr r3, [sp, #0x18]
	strh r0, [r3]
_080A53B6:
	ldrb r1, [r7, #2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080A543A
	adds r3, r7, #0
	adds r3, #0x94
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	adds r4, r7, #0
	adds r4, #0x96
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r4]
	cmp r0, r1
	blo _080A540C
	adds r0, r7, #0
	adds r0, #0x92
	ldrh r0, [r0]
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	adds r2, r7, #0
	adds r2, #0x31
	strb r0, [r2]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0x40
	bne _080A53FC
	ldr r0, [r7, #0x28]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x28]
_080A53FC:
	ldrb r1, [r7, #2]
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r7, #2]
	b _080A543A
	.align 2, 0
_080A5408: .4byte 0x03003584
_080A540C:
	ldr r0, [r7, #0x28]
	movs r1, #2
	orrs r0, r1
	str r0, [r7, #0x28]
	adds r0, r7, #0
	adds r0, #0x90
	ldrh r2, [r0]
	ldrh r1, [r4]
	ldrh r3, [r3]
	subs r0, r1, r3
	muls r0, r2, r0
	adds r2, r7, #0
	adds r2, #0x92
	ldrh r2, [r2]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	adds r1, r7, #0
	adds r1, #0x30
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
_080A543A:
	ldrb r1, [r7, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080A5446
	b _080A5556
_080A5446:
	adds r6, r7, #0
	adds r6, #0x28
	adds r4, r7, #0
	adds r4, #0x9c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080A547A
	ldr r0, [r7, #0x28]
	movs r1, #4
	orrs r0, r1
	b _080A5482
_080A547A:
	ldr r0, [r7, #0x28]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5482:
	str r0, [r7, #0x28]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080A54A6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080A54AE
_080A54A6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080A54AE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080A54E8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080A552E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080A54F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080A54EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080A5508
	.align 2, 0
_080A54E8: .4byte 0x0000FFFF
_080A54EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _080A5506
_080A54F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080A5506
	strh r1, [r4, #8]
	movs r2, #1
	b _080A5508
_080A5506:
	movs r2, #0
_080A5508:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A5530
	movs r0, #1
	strb r0, [r4, #7]
	b _080A5530
_080A552E:
	movs r2, #0
_080A5530:
	cmp r2, #0
	beq _080A5556
	adds r0, r7, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A5556
	ldrb r0, [r7, #2]
	movs r1, #0xf7
	ands r1, r0
	strb r1, [r7, #2]
	adds r0, r7, #0
	adds r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5556
	movs r1, #0
	bl FUN_082318ac
_080A5556:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5568:
	.byte 0xF0, 0xB5, 0x4F, 0x46, 0x46, 0x46, 0xC0, 0xB4
	.byte 0x81, 0xB0, 0x17, 0x48, 0x04, 0x68, 0x00, 0x2C, 0x00, 0xD1, 0x5F, 0xE1, 0x60, 0x7E, 0x21, 0x7E
	.byte 0x88, 0x42, 0x00, 0xD3, 0x5A, 0xE1, 0x01, 0x1C, 0xB8, 0x20, 0x48, 0x43, 0x1C, 0x30, 0x27, 0x18
	.byte 0x6E, 0x20, 0x8B, 0xF1, 0xBD, 0xFF, 0x00, 0x28, 0x01, 0xD0, 0x8C, 0xF1, 0xA3, 0xF8, 0x38, 0x80
	.byte 0x3C, 0x1C, 0x28, 0x34, 0x3D, 0x1C, 0x54, 0x35, 0x74, 0x20, 0x8B, 0xF1, 0xB1, 0xFF, 0xA1, 0x46
	.byte 0x00, 0x28, 0x00, 0xD1, 0x42, 0xE1, 0x8C, 0xF1, 0x95, 0xF8, 0x80, 0x46, 0x69, 0x20, 0x8B, 0xF1
	.byte 0xA7, 0xFF, 0x00, 0x28, 0x06, 0xD0, 0x8C, 0xF1, 0x8D, 0xF8, 0x06, 0x1C, 0x03, 0xE0, 0x00, 0x00
	.byte 0x48, 0x2C, 0x00, 0x03, 0x00, 0x26, 0x28, 0x1C, 0x41, 0x46, 0x85, 0xF1, 0xC7, 0xFD, 0x20, 0x1C
	.byte 0x29, 0x1C, 0x00, 0x22, 0x84, 0xF1, 0x44, 0xFF, 0x00, 0x22, 0x26, 0x82, 0xE9, 0x88, 0x38, 0x1C
	.byte 0x84, 0x30, 0x01, 0x80, 0xFA, 0x70, 0x66, 0x20, 0x8B, 0xF1, 0x8A, 0xFF, 0x00, 0x28, 0x02, 0xD0
	.byte 0x8C, 0xF1, 0x70, 0xF8, 0xF8, 0x70, 0xF8, 0x78, 0x00, 0x28, 0x03, 0xD0, 0x20, 0x68, 0x04, 0x21
	.byte 0x08, 0x43, 0x20, 0x60, 0x70, 0x20, 0x8B, 0xF1, 0x7B, 0xFF, 0x00, 0x28, 0x08, 0xD0, 0x8C, 0xF1
	.byte 0x61, 0xF8, 0xA0, 0x83, 0x8C, 0xF1, 0x5E, 0xF8, 0xE0, 0x83, 0x8C, 0xF1, 0x5B, 0xF8, 0x01, 0xE0
	.byte 0xA0, 0x83, 0xE0, 0x83, 0x20, 0x84, 0x41, 0x20, 0x8B, 0xF1, 0x6A, 0xFF, 0x00, 0x28, 0x01, 0xD0
	.byte 0x8C, 0xF1, 0x50, 0xF8, 0x38, 0x71, 0x52, 0x20, 0x8B, 0xF1, 0x62, 0xFF, 0x00, 0x28, 0x02, 0xD0
	.byte 0x8C, 0xF1, 0x48, 0xF8, 0xE0, 0x71, 0x6D, 0x20, 0x8B, 0xF1, 0x5A, 0xFF, 0x01, 0x1C, 0x00, 0x29
	.byte 0x00, 0xD1, 0xC0, 0xE0, 0x12, 0x4C, 0x8C, 0xF1, 0x3D, 0xF8, 0x01, 0x1C, 0x09, 0x04, 0x09, 0x0C
	.byte 0x20, 0x1C, 0x8B, 0xF1, 0x2B, 0xFD, 0x3E, 0x1C, 0xAC, 0x36, 0x30, 0x60, 0x8C, 0xF1, 0x32, 0xF8
	.byte 0x3D, 0x1C, 0x98, 0x35, 0x28, 0x70, 0x8C, 0xF1, 0x2D, 0xF8, 0x3C, 0x1C, 0x99, 0x34, 0x20, 0x70
	.byte 0x6F, 0x20, 0x8B, 0xF1, 0x3D, 0xFF, 0x01, 0x1C, 0xB0, 0x46, 0x26, 0x1C, 0x00, 0x29, 0x09, 0xD0
	.byte 0x8C, 0xF1, 0x20, 0xF8, 0x39, 0x1C, 0x9A, 0x31, 0x08, 0x70, 0x08, 0x1C, 0x05, 0xE0, 0x00, 0x00
	.byte 0x2E, 0x92, 0x00, 0x00, 0x38, 0x1C, 0x9A, 0x30, 0x01, 0x70, 0x01, 0x78, 0x00, 0x29, 0x0B, 0xD0
	.byte 0x65, 0x20, 0x8B, 0xF1, 0x25, 0xFF, 0x01, 0x1C, 0x00, 0x29, 0x05, 0xD0, 0x8C, 0xF1, 0x0A, 0xF8
	.byte 0x39, 0x1C, 0xB0, 0x31, 0x08, 0x60, 0x02, 0xE0, 0x38, 0x1C, 0xB0, 0x30, 0x01, 0x60, 0x3C, 0x1C
	.byte 0x9C, 0x34, 0x42, 0x46, 0x11, 0x68, 0x2A, 0x78, 0x33, 0x78, 0xF8, 0x78, 0x00, 0x90, 0x20, 0x1C
	.byte 0x91, 0xF1, 0x5C, 0xFC, 0x50, 0x20, 0x8B, 0xF1, 0x0B, 0xFF, 0x00, 0x28, 0x07, 0xD0, 0x8B, 0xF1
	.byte 0xF1, 0xFF, 0x01, 0x1C, 0x09, 0x04, 0x09, 0x0C, 0x20, 0x1C, 0x91, 0xF1, 0xC5, 0xFC, 0x4E, 0x46
	.byte 0x20, 0x89, 0x40, 0x00, 0x21, 0x68, 0x0D, 0x18, 0x28, 0x88, 0x80, 0x09, 0x30, 0x82, 0x20, 0x79
	.byte 0x01, 0x23, 0x19, 0x1C, 0x01, 0x40, 0x2A, 0x88, 0x30, 0x20, 0x10, 0x40, 0x00, 0x09, 0x18, 0x40
	.byte 0x81, 0x42, 0x03, 0xD0, 0xB8, 0x6A, 0x04, 0x21, 0x08, 0x43, 0x03, 0xE0, 0xB8, 0x6A, 0x05, 0x21
	.byte 0x49, 0x42, 0x08, 0x40, 0xB8, 0x62, 0x20, 0x79, 0x02, 0x23, 0x19, 0x1C, 0x01, 0x40, 0x09, 0x06
	.byte 0x09, 0x0E, 0x2A, 0x88, 0x30, 0x20, 0x10, 0x40, 0x00, 0x09, 0x18, 0x40, 0x81, 0x42, 0x03, 0xD0
	.byte 0x30, 0x68, 0x08, 0x21, 0x08, 0x43, 0x03, 0xE0, 0x30, 0x68, 0x09, 0x21, 0x49, 0x42, 0x08, 0x40
	.byte 0x30, 0x60, 0xE0, 0x89, 0x01, 0x30, 0xE0, 0x81, 0x0B, 0x49, 0x0A, 0x1C, 0x00, 0x04, 0x00, 0x0C
	.byte 0xE1, 0x79, 0x88, 0x42, 0x2C, 0xD3, 0x00, 0x20, 0xE0, 0x81, 0x21, 0x79, 0x04, 0x20, 0x08, 0x40
	.byte 0x00, 0x06, 0x01, 0x0E, 0x00, 0x29, 0x09, 0xD0, 0x20, 0x89, 0x00, 0x28, 0x00, 0xD1, 0x60, 0x79
	.byte 0x01, 0x38, 0x20, 0x81, 0x0A, 0xE0, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x20, 0x89, 0x01, 0x30
	.byte 0x20, 0x81, 0x10, 0x40, 0x62, 0x79, 0x90, 0x42, 0x00, 0xD3, 0x21, 0x81, 0x20, 0x89, 0x40, 0x00
	.byte 0x21, 0x68, 0x0D, 0x18, 0x29, 0x88, 0x0F, 0x20, 0x08, 0x40, 0xA0, 0x71, 0xA1, 0x79, 0xA0, 0x89
	.byte 0x48, 0x43, 0x80, 0x11, 0xE0, 0x71, 0x00, 0x06, 0x00, 0x28, 0x01, 0xD1, 0x01, 0x20, 0xE0, 0x71
	.byte 0x08, 0x20, 0xB8, 0x70, 0x07, 0xE0, 0x38, 0x1C, 0xAC, 0x30, 0x01, 0x60, 0x12, 0x38, 0x01, 0x70
	.byte 0x16, 0x30, 0x01, 0x60, 0xB9, 0x70, 0x00, 0x25, 0x73, 0x20, 0x8B, 0xF1, 0x89, 0xFE, 0x00, 0x28
	.byte 0x02, 0xD0, 0x8B, 0xF1, 0x6F, 0xFF, 0x05, 0x1C, 0x3C, 0x1C, 0xB4, 0x34, 0x00, 0x20, 0x20, 0x60
	.byte 0x00, 0x2D, 0x0E, 0xD0, 0x40, 0x20, 0x8B, 0xF1, 0x51, 0xF8, 0x20, 0x60, 0x00, 0x28, 0x08, 0xD0
	.byte 0x40, 0x21, 0x8B, 0xF1, 0xD3, 0xF8, 0x20, 0x68, 0x39, 0x1C, 0x44, 0x31, 0x00, 0x22, 0x6E, 0xF7
	.byte 0x15, 0xF8, 0x06, 0x48, 0x01, 0x68, 0x48, 0x7E, 0x01, 0x30, 0x48, 0x76, 0x01, 0xB0, 0x18, 0xBC
	.byte 0x98, 0x46, 0xA1, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x48, 0x2C, 0x00, 0x03

	thumb_func_start FUN_080a5850
FUN_080a5850: @ 0x080A5850
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A587E
	adds r4, r6, #0
	adds r4, #0x1c
_080A5860:
	ldr r0, _080A5888 @ =0x030044BC
	ldr r0, [r0]
	cmp r0, #0
	beq _080A586E
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _080A5874
_080A586E:
	adds r0, r4, #0
	bl FUN_080a51d4
_080A5874:
	adds r4, #0xb8
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5860
_080A587E:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A5888: .4byte 0x030044BC

	thumb_func_start FUN_080a588c
FUN_080a588c: @ 0x080A588C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	b _080A58BA
_080A5894:
	movs r0, #0xb8
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r4, r5
	adds r0, #0x44
	bl FUN_0822a4e0
	adds r0, r5, #0
	adds r0, #0xd0
	adds r4, r0, r4
	ldr r0, [r4]
	cmp r0, #0
	beq _080A58B8
	bl FUN_080138fc
	ldr r0, [r4]
	bl Free
_080A58B8:
	adds r6, #1
_080A58BA:
	ldrb r0, [r5, #0x19]
	cmp r6, r0
	blt _080A5894
	ldr r1, _080A58CC @ =0x03002C48
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A58CC: .4byte 0x03002C48

	thumb_func_start FUN_080a58d0
FUN_080a58d0: @ 0x080A58D0
	movs r1, #0
	strb r3, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r1, _080A58E0 @ =0x03002C48
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_080A58E0: .4byte 0x03002C48
_080A58E4:
	.byte 0xF0, 0xB5, 0x06, 0x1C, 0x0F, 0x1C, 0x06, 0x48, 0x00, 0x68, 0x00, 0x28
	.byte 0x2B, 0xD1, 0x6D, 0x20, 0x8B, 0xF1, 0x0C, 0xFE, 0x00, 0x28, 0x05, 0xD0, 0x8B, 0xF1, 0xF2, 0xFE
	.byte 0x05, 0x1C, 0x02, 0xE0, 0x48, 0x2C, 0x00, 0x03, 0x01, 0x25, 0xB8, 0x20, 0x29, 0x1C, 0x41, 0x43
	.byte 0x1C, 0x31, 0x09, 0x20, 0x8B, 0xF1, 0x4C, 0xF9, 0x04, 0x1C, 0x00, 0x2C, 0x14, 0xD0, 0x08, 0x49
	.byte 0x08, 0x4A, 0x8B, 0xF1, 0x69, 0xF9, 0x20, 0x1C, 0x31, 0x1C, 0x3A, 0x1C, 0x2B, 0x1C, 0xFF, 0xF7
	.byte 0xCF, 0xFF, 0x00, 0x28, 0x08, 0xDA, 0x20, 0x1C, 0x8B, 0xF1, 0x98, 0xF9, 0x00, 0x20, 0x04, 0xE0
	.byte 0x51, 0x58, 0x0A, 0x08, 0x8D, 0x58, 0x0A, 0x08, 0x20, 0x1C, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080a5950
FUN_080a5950: @ 0x080A5950
	push {r4, r5, r6, lr}
	ldr r4, _080A5968 @ =0x03002C4C
	ldr r0, [r4]
	cmp r0, #0
	beq _080A599E
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	bne _080A5974
	b _080A599E
	.align 2, 0
_080A5968: .4byte 0x03002C4C
_080A596C:
	adds r0, r3, #0
	adds r0, #0x1c
	adds r0, r5, r0
	b _080A59A0
_080A5974:
	bl fetch_082316e4
	adds r6, r0, #0
	movs r2, #0
	ldr r0, [r4]
	ldrb r1, [r0, #0x19]
	cmp r2, r1
	bge _080A599E
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r5, #0
	adds r1, #0xb4
	movs r3, #0
_080A598E:
	ldrh r0, [r1]
	cmp r0, r6
	beq _080A596C
	adds r1, #0xbc
	adds r3, #0xbc
	adds r2, #1
	cmp r2, r4
	blt _080A598E
_080A599E:
	movs r0, #0
_080A59A0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A59A8:
	.byte 0x30, 0xB5, 0xFF, 0xF7, 0xD1, 0xFF, 0x05, 0x1C
	.byte 0x00, 0x2D, 0x11, 0xD0, 0x70, 0x20, 0x8B, 0xF1, 0xAB, 0xFD, 0x00, 0x28, 0x0C, 0xD0, 0x2C, 0x1C
	.byte 0x38, 0x34, 0x18, 0x35, 0x8B, 0xF1, 0x8E, 0xFE, 0x02, 0x1C, 0x12, 0x04, 0x12, 0x0C, 0x20, 0x1C
	.byte 0x29, 0x1C, 0x00, 0x23, 0x89, 0xF1, 0xFA, 0xFC, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a59e0
FUN_080a59e0: @ 0x080A59E0
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5A10
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A5A10
	bl fetch_082316e4
	cmp r0, #0
	beq _080A5A06
	ldr r0, [r4, #0x40]
	movs r1, #4
	orrs r0, r1
	b _080A5A0E
_080A5A06:
	ldr r0, [r4, #0x40]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080A5A0E:
	str r0, [r4, #0x40]
_080A5A10:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5a18
FUN_080a5a18: @ 0x080A5A18
	push {lr}
	bl FUN_080a5950
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5A3C
	ldr r0, [r1, #0x40]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #0x40]
	adds r0, r1, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5A3C
	adds r0, r1, #0
	adds r0, #0x9e
	strh r2, [r0]
_080A5A3C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5a40
FUN_080a5a40: @ 0x080A5A40
	push {lr}
	bl FUN_080a5950
	adds r2, r0, #0
	cmp r2, #0
	beq _080A5A68
	ldr r0, [r2, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x40]
	adds r0, r2, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5A68
	adds r1, r2, #0
	adds r1, #0x9e
	movs r0, #0
	strh r0, [r1]
_080A5A68:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5a6c
FUN_080a5a6c: @ 0x080A5A6C
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5A8C
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A5A8C
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x52
	strb r0, [r1]
_080A5A8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5a94
FUN_080a5a94: @ 0x080A5A94
	push {r4, lr}
	bl FUN_080a5950
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5AFA
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A5AC8
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0xb4
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0xb6
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0xb8
	strh r0, [r1]
_080A5AC8:
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A5ADC
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0xa2
	strh r0, [r1]
_080A5ADC:
	adds r2, r4, #0
	adds r2, #0xac
	adds r0, r4, #0
	adds r0, #0xa4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r4, #0
	adds r1, #0xa0
	movs r0, #0
	strh r0, [r1]
	subs r1, #6
	movs r0, #1
	strh r0, [r1]
_080A5AFA:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5b00
FUN_080a5b00: @ 0x080A5B00
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x9a
	ldrh r0, [r3]
	cmp r0, #0
	beq _080A5BC0
	adds r7, r6, #0
	adds r7, #0xa0
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	movs r1, #0xa2
	adds r1, r1, r6
	mov r8, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r1]
	cmp r0, r2
	blo _080A5B42
	adds r2, r6, #0
	adds r2, #0xa4
	adds r0, r6, #0
	adds r0, #0xb4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0
	strh r0, [r3]
	b _080A5BB8
_080A5B42:
	mov r3, r8
	ldrh r1, [r3]
	ldrh r2, [r7]
	subs r4, r1, r2
	adds r0, r6, #0
	adds r0, #0xb4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0xac
	movs r3, #0
	ldrsh r2, [r2, r3]
	muls r2, r4, r2
	adds r0, r0, r2
	bl Div
	adds r5, r6, #0
	adds r5, #0xa4
	strh r0, [r5]
	adds r0, r6, #0
	adds r0, #0xb6
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r7]
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xae
	movs r3, #0
	ldrsh r1, [r1, r3]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r2, r8
	ldrh r1, [r2]
	bl Div
	adds r1, r6, #0
	adds r1, #0xa6
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0xb8
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldrh r0, [r7]
	muls r0, r1, r0
	adds r1, r6, #0
	adds r1, #0xb0
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r1, r4, r1
	adds r0, r0, r1
	mov r3, r8
	ldrh r1, [r3]
	bl Div
	adds r1, r6, #0
	adds r1, #0xa8
	strh r0, [r1]
	adds r2, r5, #0
_080A5BB8:
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x58]
	str r1, [r6, #0x5c]
_080A5BC0:
	adds r0, r6, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A5BF8
	adds r0, r6, #0
	adds r0, #0x9e
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A5BF0
	ldr r0, _080A5BEC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x14
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080A5BF0
	ldr r0, [r6, #0x40]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _080A5BF6
	.align 2, 0
_080A5BEC: .4byte 0x030046A0
_080A5BF0:
	ldr r0, [r6, #0x40]
	movs r1, #1
	orrs r0, r1
_080A5BF6:
	str r0, [r6, #0x40]
_080A5BF8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a5c04
FUN_080a5c04: @ 0x080A5C04
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	ldr r0, _080A5C44 @ =0x03002C4C
	ldr r2, [r0]
	cmp r2, #0
	bne _080A5C18
	b _080A5D62
_080A5C18:
	ldrb r0, [r2, #0x19]
	ldrb r1, [r2, #0x18]
	cmp r0, r1
	blo _080A5C22
	b _080A5D62
_080A5C22:
	adds r1, r0, #0
	movs r0, #0xbc
	muls r0, r1, r0
	adds r0, #0x1c
	adds r5, r2, r0
	movs r0, #0x6e
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5C48
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	b _080A5C4E
	.align 2, 0
_080A5C44: .4byte 0x03002C4C
_080A5C48:
	adds r0, r5, #0
	adds r0, #0x98
	strh r1, [r0]
_080A5C4E:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	bne _080A5C5A
	b _080A5D62
_080A5C5A:
	bl fetch_082316e4
	adds r1, r0, #0
	ldr r0, _080A5C9C @ =0x0000CB05
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl FUN_082310cc
	adds r1, r0, #0
	adds r2, r5, #0
	adds r2, #0x18
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	bl FUN_0822f284
	movs r0, #0x69
	bl prepare_08231510
	mov r8, r4
	cmp r0, #0
	beq _080A5CA0
	bl fetch_082316e4
	adds r7, r0, #0
	b _080A5CA2
	.align 2, 0
_080A5C9C: .4byte 0x0000CB05
_080A5CA0:
	movs r7, #0
_080A5CA2:
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A5CB2
	bl fetch_082316e4
	b _080A5CB4
_080A5CB2:
	movs r0, #0
_080A5CB4:
	movs r6, #0
	mov sb, r6
	cmp r0, #1
	bne _080A5CC0
	movs r0, #0x10
	mov sb, r0
_080A5CC0:
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _080A5CD2
	bl fetch_082316e4
	adds r6, r0, #0
	b _080A5CD4
_080A5CD2:
	movs r6, #2
_080A5CD4:
	movs r0, #0x70
	bl prepare_08231510
	adds r2, r0, #0
	cmp r2, #0
	beq _080A5D00
	bl fetch_082316e4
	adds r4, r5, #0
	adds r4, #0xa4
	strh r0, [r4]
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xa6
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xa8
	strh r0, [r1]
	b _080A5D12
_080A5D00:
	adds r1, r5, #0
	adds r1, #0xa4
	strh r2, [r1]
	adds r0, r5, #0
	adds r0, #0xa6
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r4, r1, #0
_080A5D12:
	adds r0, r5, #0
	adds r0, #0x38
	lsls r2, r7, #0x10
	lsrs r2, r2, #0x10
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	mov r1, r8
	mov r3, sb
	bl FUN_0822f3fc
	movs r0, #0x41
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A5D4A
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	b _080A5D50
_080A5D4A:
	adds r0, r5, #0
	adds r0, #0x9c
	strh r1, [r0]
_080A5D50:
	adds r1, r5, #0
	adds r1, #0x9e
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080A5D70 @ =0x03002C4C
	ldr r1, [r0]
	ldrb r0, [r1, #0x19]
	adds r0, #1
	strb r0, [r1, #0x19]
_080A5D62:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5D70: .4byte 0x03002C4C

	thumb_func_start FUN_080a5d74
FUN_080a5d74: @ 0x080A5D74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A5D94
	adds r4, r6, #0
	adds r4, #0x1c
_080A5D84:
	adds r0, r4, #0
	bl FUN_080a5b00
	adds r4, #0xbc
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5D84
_080A5D94:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a5d9c
FUN_080a5d9c: @ 0x080A5D9C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	bge _080A5DBC
	adds r4, r6, #0
	adds r4, #0x54
_080A5DAC:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0xbc
	adds r5, #1
	ldrb r0, [r6, #0x19]
	cmp r5, r0
	blt _080A5DAC
_080A5DBC:
	ldr r1, _080A5DC8 @ =0x03002C4C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A5DC8: .4byte 0x03002C4C

	thumb_func_start FUN_080a5dcc
FUN_080a5dcc: @ 0x080A5DCC
	movs r1, #0
	strb r3, [r0, #0x18]
	strb r1, [r0, #0x19]
	ldr r1, _080A5DDC @ =0x03002C4C
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_080A5DDC: .4byte 0x03002C4C
_080A5DE0:
	.byte 0xF0, 0xB5, 0x06, 0x1C, 0x0F, 0x1C, 0x06, 0x48, 0x00, 0x68, 0x00, 0x28, 0x2B, 0xD1, 0x6D, 0x20
	.byte 0x8B, 0xF1, 0x8E, 0xFB, 0x00, 0x28, 0x05, 0xD0, 0x8B, 0xF1, 0x74, 0xFC, 0x05, 0x1C, 0x02, 0xE0
	.byte 0x4C, 0x2C, 0x00, 0x03, 0x01, 0x25, 0xBC, 0x20, 0x29, 0x1C, 0x41, 0x43, 0x1C, 0x31, 0x08, 0x20
	.byte 0x8A, 0xF1, 0xCE, 0xFE, 0x04, 0x1C, 0x00, 0x2C, 0x14, 0xD0, 0x08, 0x49, 0x08, 0x4A, 0x8A, 0xF1
	.byte 0xEB, 0xFE, 0x20, 0x1C, 0x31, 0x1C, 0x3A, 0x1C, 0x2B, 0x1C, 0xFF, 0xF7, 0xCF, 0xFF, 0x00, 0x28
	.byte 0x08, 0xDA, 0x20, 0x1C, 0x8A, 0xF1, 0x1A, 0xFF, 0x00, 0x20, 0x04, 0xE0, 0x75, 0x5D, 0x0A, 0x08
	.byte 0x9D, 0x5D, 0x0A, 0x08, 0x20, 0x1C, 0xF0, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080a5e4c
FUN_080a5e4c: @ 0x080A5E4C
	push {lr}
	ldr r0, _080A5E64 @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5E5E
	adds r1, r0, #0
	adds r1, #0x9c
	movs r0, #1
	str r0, [r1]
_080A5E5E:
	pop {r0}
	bx r0
	.align 2, 0
_080A5E64: .4byte 0x0300014C

	thumb_func_start FUN_080a5e68
FUN_080a5e68: @ 0x080A5E68
	adds r2, r0, #0
	adds r2, #0xac
	str r1, [r2]
	adds r0, #0x9a
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a5e78
FUN_080a5e78: @ 0x080A5E78
	push {lr}
	adds r1, r0, #0
	adds r0, #0xa0
	ldr r2, [r0]
	cmp r2, #0
	beq _080A5E8C
	adds r0, #4
	ldr r0, [r0]
	bl _call_via_r2
_080A5E8C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5e90
FUN_080a5e90: @ 0x080A5E90
	push {lr}
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5EA0
	movs r1, #0
	bl FUN_082318ac
_080A5EA0:
	pop {r0}
	bx r0

	thumb_func_start FUN_080a5ea4
FUN_080a5ea4: @ 0x080A5EA4
	push {lr}
	adds r1, r0, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A5EB8
	adds r0, r1, #0
	bl FUN_080a5e78
	b _080A5EBE
_080A5EB8:
	adds r0, r1, #0
	bl FUN_080a5e90
_080A5EBE:
	pop {r0}
	bx r0
	.align 2, 0
_080A5EC4:
	.byte 0x70, 0xB5, 0x04, 0x1C, 0x9A, 0x30, 0x00, 0x88, 0x00, 0x28, 0x02, 0xD1
	.byte 0x19, 0x48, 0x9A, 0xF1, 0x05, 0xFC, 0x20, 0x1C, 0x4C, 0x30, 0x00, 0x88, 0x01, 0x38, 0x00, 0x04
	.byte 0x00, 0x0C, 0x02, 0x28, 0x08, 0xD8, 0x20, 0x1C, 0x44, 0x30, 0x00, 0x88, 0x00, 0x28, 0x03, 0xD1
	.byte 0x87, 0x20, 0x80, 0x00, 0x9A, 0xF1, 0xF4, 0xFB, 0x21, 0x1C, 0x9A, 0x31, 0x08, 0x88, 0x01, 0x30
	.byte 0x08, 0x80, 0x25, 0x1C, 0x38, 0x35, 0x26, 0x1C, 0x18, 0x36, 0x28, 0x1C, 0x31, 0x1C, 0x91, 0xF1
	.byte 0xDD, 0xF9, 0x00, 0x28, 0x0C, 0xD0, 0x28, 0x1C, 0x31, 0x1C, 0x24, 0x22, 0x01, 0x23, 0x89, 0xF1
	.byte 0x55, 0xFA, 0x06, 0x49, 0x20, 0x1C, 0xFF, 0xF7, 0x9F, 0xFF, 0x20, 0x1C, 0xFF, 0xF7, 0xBA, 0xFF
	.byte 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xC2, 0x02, 0x00, 0x00, 0x41, 0x5F, 0x0A, 0x08

	thumb_func_start FUN_080a5f40
FUN_080a5f40: @ 0x080A5F40
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x9a
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A5F54
	ldr r0, _080A5F90 @ =0x000002C3
	bl PlaySound_082406e0
_080A5F54:
	ldrh r0, [r4]
	cmp r0, #7
	bhi _080A5FA0
	ldr r6, _080A5F94 @ =0x0203B400
	ldr r5, _080A5F98 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _080A5F9C @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #3
	ands r0, r4
	subs r0, #2
	adds r2, r7, #0
	adds r2, #0x58
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #2
	adds r1, r7, #0
	adds r1, #0x5a
	strh r0, [r1]
	b _080A5FB0
	.align 2, 0
_080A5F90: .4byte 0x000002C3
_080A5F94: .4byte 0x0203B400
_080A5F98: .4byte 0x030046B8
_080A5F9C: .4byte 0x000003FF
_080A5FA0:
	cmp r0, #8
	bne _080A5FB0
	adds r0, r7, #0
	adds r0, #0x58
	movs r1, #0
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_080A5FB0:
	adds r1, r7, #0
	adds r1, #0x9a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080A5FC8
	adds r0, r7, #0
	bl KillEntity
_080A5FC8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A5FD0:
	.byte 0x30, 0xB5, 0x05, 0x1C, 0x2C, 0x1C, 0x9A, 0x34, 0x20, 0x88, 0x00, 0x28, 0x03, 0xD1, 0xA5, 0x20
	.byte 0x80, 0x00, 0x9A, 0xF1, 0x7D, 0xFB, 0x20, 0x88, 0x01, 0x30, 0x20, 0x80, 0x00, 0x04, 0x00, 0x0C
	.byte 0x59, 0x28, 0x05, 0xD9, 0x28, 0x1C, 0xFF, 0xF7, 0x55, 0xFF, 0x28, 0x1C, 0x8A, 0xF1, 0x36, 0xFE
	.byte 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x00, 0xB5, 0x02, 0x1C, 0x9C, 0x30, 0x00, 0x68
	.byte 0x00, 0x28, 0x03, 0xD0, 0x10, 0x1C, 0x8A, 0xF1, 0x29, 0xFE, 0x05, 0xE0, 0x10, 0x1C, 0xAC, 0x30
	.byte 0x01, 0x68, 0x10, 0x1C, 0xA6, 0xF1, 0x1E, 0xFF, 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	.byte 0x00, 0xB5, 0x38, 0x30, 0x89, 0xF1, 0xC4, 0xF8, 0x02, 0x49, 0x00, 0x20, 0x08, 0x60, 0x02, 0xBC
	.byte 0x08, 0x47, 0x00, 0x00, 0x4C, 0x01, 0x00, 0x03

	thumb_func_start FUN_080a6048
FUN_080a6048: @ 0x080A6048
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _080A60B4 @ =0x0000CB05
	ldr r1, _080A60B8 @ =0x0000DCC1
	bl FUN_082310cc
	adds r2, r0, #0
	cmp r2, #0
	beq _080A6108
	adds r1, r4, #0
	adds r1, #0x18
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r7, r4, #0
	adds r7, #0x18
	adds r0, r7, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r1, _080A60BC @ =0xFFFF0000
	movs r6, #0
	str r6, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	cmp r5, #0
	bne _080A60C0
	adds r4, #0x38
	str r5, [sp]
	str r5, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	movs r3, #0x30
	bl FUN_0822f3fc
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #2
	bl FUN_082370cc
	b _080A6108
	.align 2, 0
_080A60B4: .4byte 0x0000CB05
_080A60B8: .4byte 0x0000DCC1
_080A60BC: .4byte 0xFFFF0000
_080A60C0:
	cmp r5, #1
	bne _080A60E0
	adds r0, r4, #0
	adds r0, #0x38
	str r6, [sp]
	str r6, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #0x25
	movs r3, #0x30
	bl FUN_0822f3fc
	b _080A6108
_080A60E0:
	adds r4, #0x38
	str r6, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0x20
	movs r3, #0x30
	bl FUN_0822f3fc
	str r6, [sp]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	movs r3, #2
	bl FUN_082370cc
_080A6108:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a6110
FUN_080a6110: @ 0x080A6110
	push {lr}
	cmp r1, #0
	bne _080A6124
	ldr r1, _080A6120 @ =0x080A5EC5
	bl FUN_080a5e68
	b _080A613A
	.align 2, 0
_080A6120: .4byte 0x080A5EC5
_080A6124:
	cmp r1, #1
	bne _080A6134
	ldr r1, _080A6130 @ =0x080A5FD1
	bl FUN_080a5e68
	b _080A613A
	.align 2, 0
_080A6130: .4byte 0x080A5FD1
_080A6134:
	ldr r1, _080A6140 @ =0x080A5EC5
	bl FUN_080a5e68
_080A613A:
	pop {r0}
	bx r0
	.align 2, 0
_080A6140: .4byte 0x080A5EC5

	thumb_func_start FUN_080a6144
FUN_080a6144: @ 0x080A6144
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r5, [sp, #0x10]
	adds r1, r4, #0
	adds r1, #0x98
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0xa0
	str r3, [r0]
	adds r0, #4
	str r5, [r0]
	subs r0, #0xb
	strb r2, [r0]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080a6048
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080a6110
	ldr r1, _080A617C @ =0x0300014C
	str r4, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A617C: .4byte 0x0300014C

	thumb_func_start FUN_080a6180
FUN_080a6180: @ 0x080A6180
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	ldr r0, _080A61CC @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A61DA
	movs r0, #4
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A61D8
	ldr r1, _080A61D0 @ =0x080A6009
	ldr r2, _080A61D4 @ =0x080A6031
	bl SetEntityRoutine
	str r5, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080a6144
	cmp r0, #0
	bge _080A61D8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A61DA
	.align 2, 0
_080A61CC: .4byte 0x0300014C
_080A61D0: .4byte 0x080A6009
_080A61D4: .4byte 0x080A6031
_080A61D8:
	adds r0, r4, #0
_080A61DA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a61e8
FUN_080a61e8: @ 0x080A61E8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x98
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _080A6204
	bl fetch_082316e4
	adds r5, r0, #0
	b _080A6206
_080A6204:
	movs r5, #0
_080A6206:
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A6214
	bl fetch_082316e4
_080A6214:
	adds r1, r4, #0
	adds r1, #0x99
	strb r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A6232
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0xa8
	str r0, [r1]
	b _080A6238
_080A6232:
	adds r0, r4, #0
	adds r0, #0xa8
	str r1, [r0]
_080A6238:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a6048
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a6110
	ldr r1, _080A6254 @ =0x0300014C
	str r4, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A6254: .4byte 0x0300014C

	thumb_func_start FUN_080a6258
FUN_080a6258: @ 0x080A6258
	push {r4, lr}
	ldr r0, _080A628C @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A629A
	movs r0, #4
	movs r1, #0xb0
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A6298
	ldr r1, _080A6290 @ =0x080A6009
	ldr r2, _080A6294 @ =0x080A6031
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080a61e8
	cmp r0, #0
	bge _080A6298
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A629A
	.align 2, 0
_080A628C: .4byte 0x0300014C
_080A6290: .4byte 0x080A6009
_080A6294: .4byte 0x080A6031
_080A6298:
	adds r0, r4, #0
_080A629A:
	pop {r4}
	pop {r1}
	bx r1
_080A62A0:
	.byte 0x10, 0xB5, 0x6D, 0x20, 0x8B, 0xF1, 0x34, 0xF9, 0x00, 0x28, 0x1D, 0xD0, 0x10, 0x48, 0x8A, 0xF1
	.byte 0xDF, 0xFD, 0x04, 0x1C, 0x00, 0x2C, 0x17, 0xD0, 0x8B, 0xF1, 0x14, 0xFA, 0x20, 0x83, 0x00, 0x04
	.byte 0x00, 0x0C, 0x01, 0x28, 0x10, 0xD1, 0x00, 0x22, 0xA0, 0x8B, 0x82, 0x42, 0x0A, 0xDA, 0x01, 0x23
	.byte 0x21, 0x1C, 0x20, 0x31, 0x08, 0x68, 0x18, 0x43, 0x08, 0x60, 0x28, 0x31, 0x01, 0x32, 0xA0, 0x8B
	.byte 0x82, 0x42, 0xF7, 0xDB, 0x00, 0x20, 0xE0, 0x83, 0x10, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x22, 0xFD, 0x00, 0x00

	thumb_func_start FUN_080a62f4
FUN_080a62f4: @ 0x080A62F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	mov sb, r1
	adds r7, r2, #0
	mov sl, r3
	ldr r0, _080A6348 @ =0x0000FD22
	bl FUN_08230e70
	mov r8, r0
	cmp r0, #0
	bne _080A6314
	b _080A640E
_080A6314:
	ldr r0, _080A634C @ =0x00001C1A
	bl FUN_0822b10c
	adds r4, r0, #0
	mov r0, r8
	ldrh r1, [r0, #0x1c]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	mov r1, r8
	adds r5, r1, r0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	cmp r7, #0
	bne _080A6350
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x33
	bl FUN_0822dafc
	b _080A635C
	.align 2, 0
_080A6348: .4byte 0x0000FD22
_080A634C: .4byte 0x00001C1A
_080A6350:
	adds r2, r7, #0
	adds r2, #0x34
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0822dafc
_080A635C:
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	mov r0, sl
	cmp r0, #0
	bne _080A63DE
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080A639A
	cmp r1, #0
	blt _080A639A
	ldr r0, _080A63A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080A639A
	ldr r0, _080A63A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A63AC
_080A639A:
	movs r3, #0
	ldr r2, _080A63A8 @ =0x030046A4
	b _080A63BA
	.align 2, 0
_080A63A0: .4byte 0x030046A8
_080A63A4: .4byte 0x030046AC
_080A63A8: .4byte 0x030046A4
_080A63AC:
	ldr r2, _080A63C8 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_080A63BA:
	ldr r0, [r2]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A63CC
	movs r0, #0
	b _080A63D2
	.align 2, 0
_080A63C8: .4byte 0x030046A4
_080A63CC:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r0, r1, r0
_080A63D2:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	adds r0, #0x80
	strh r0, [r5, #0x1a]
_080A63DE:
	movs r0, #1
	strb r0, [r5, #0xf]
	mov r1, sb
	cmp r1, #0
	beq _080A6406
	cmp r1, #1
	bne _080A63F2
	ldr r0, [r5]
	movs r1, #4
	b _080A6402
_080A63F2:
	mov r0, sb
	cmp r0, #2
	bne _080A63FE
	ldr r0, [r5]
	movs r1, #0xc
	b _080A6402
_080A63FE:
	ldr r0, [r5]
	movs r1, #8
_080A6402:
	orrs r0, r1
	str r0, [r5]
_080A6406:
	mov r1, r8
	ldrh r0, [r1, #0x1c]
	adds r0, #1
	strh r0, [r1, #0x1c]
_080A640E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a641c
FUN_080a641c: @ 0x080A641C
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A6468
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080A6460 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r2, _080A6464 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	b _080A6472
	.align 2, 0
_080A6460: .4byte 0xFFFF0000
_080A6464: .4byte 0x0000FFFF
_080A6468:
	ldr r1, _080A6484 @ =0xFFFF0000
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r1
	str r0, [sp, #4]
_080A6472:
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A6488
	bl fetch_082316e4
	adds r5, r0, #0
	b _080A648A
	.align 2, 0
_080A6484: .4byte 0xFFFF0000
_080A6488:
	movs r5, #0
_080A648A:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080A649C
	bl fetch_082316e4
	adds r4, r0, #0
	b _080A649E
_080A649C:
	movs r4, #0
_080A649E:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A64B0
	bl fetch_082316e4
	adds r2, r0, #0
	b _080A64B2
_080A64B0:
	movs r2, #0
_080A64B2:
	asrs r1, r4, #1
	adds r1, #1
	movs r0, #3
	ands r1, r0
	mov r0, sp
	adds r3, r5, #0
	bl FUN_080a62f4
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a64cc
FUN_080a64cc: @ 0x080A64CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov ip, r0
	ldrh r1, [r0, #4]
	subs r1, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080A654C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, ip
	movs r3, #6
	ldrsh r1, [r0, r3]
	movs r4, #2
	ldrsh r0, [r0, r4]
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	mov r4, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r3, sp, #8
	ldrh r0, [r3]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r3
	cmp r2, #0
	blt _080A6546
	cmp r1, #0
	blt _080A6546
	ldr r0, _080A6550 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A6546
	ldr r0, _080A6554 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6558
_080A6546:
	movs r4, #0
	b _080A6566
	.align 2, 0
_080A654C: .4byte 0xFFFF0000
_080A6550: .4byte 0x030046A8
_080A6554: .4byte 0x030046AC
_080A6558:
	ldr r0, _080A6594 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A6566:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sb
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A658E
	cmp r1, #0
	blt _080A658E
	ldr r0, _080A6598 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A658E
	ldr r0, _080A659C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A65A0
_080A658E:
	movs r3, #0
	b _080A65AE
	.align 2, 0
_080A6594: .4byte 0x030046A4
_080A6598: .4byte 0x030046A8
_080A659C: .4byte 0x030046AC
_080A65A0:
	ldr r0, _080A65C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_080A65AE:
	cmp r4, r3
	beq _080A6650
	ldr r1, _080A65C4 @ =0x030046A4
	ldr r0, [r1]
	ldr r2, [r0, #4]
	mov r8, r1
	cmp r2, #0
	bne _080A65C8
	movs r2, #0
	b _080A65CE
	.align 2, 0
_080A65C4: .4byte 0x030046A4
_080A65C8:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r2, r0
_080A65CE:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A65DC
	movs r7, #0
	b _080A65E2
_080A65DC:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A65E2:
	ldrb r0, [r2]
	movs r4, #0xf
	lsrs r2, r0, #4
	adds r5, r0, #0
	cmp r2, #1
	beq _080A6654
	cmp r2, #1
	blo _080A65F8
	cmp r2, #2
	beq _080A662A
	b _080A6654
_080A65F8:
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r4
	adds r2, r1, #0
	cmp r0, #0
	bne _080A661A
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A661A
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A6650
_080A661A:
	lsrs r0, r2, #4
	cmp r0, #2
	bne _080A6654
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	b _080A6642
_080A662A:
	ldrb r2, [r7]
	lsrs r0, r2, #4
	ands r0, r4
	cmp r0, #0
	beq _080A6638
	cmp r0, #2
	bne _080A6654
_080A6638:
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	adds r0, #1
_080A6642:
	cmp r1, r0
	bne _080A6654
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A6654
_080A6650:
	movs r0, #0
	b _080A6A64
_080A6654:
	mov r1, ip
	movs r2, #4
	ldrsh r0, [r1, r2]
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, ip
	ldrh r0, [r4, #6]
	subs r0, #0x10
	mov r2, sp
	strh r0, [r2, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sb
	ldrh r0, [r1, #4]
	adds r0, #0x20
	strh r0, [r1, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080A66A6
	cmp r1, #0
	blt _080A66A6
	ldr r0, _080A66AC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080A66A6
	ldr r0, _080A66B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A66B4
_080A66A6:
	movs r4, #0
	b _080A66C2
	.align 2, 0
_080A66AC: .4byte 0x030046A8
_080A66B0: .4byte 0x030046AC
_080A66B4:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080A66C2:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sb
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A66EA
	cmp r1, #0
	blt _080A66EA
	ldr r0, _080A66F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A66EA
	ldr r0, _080A66F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A66F8
_080A66EA:
	movs r3, #0
	b _080A6706
	.align 2, 0
_080A66F0: .4byte 0x030046A8
_080A66F4: .4byte 0x030046AC
_080A66F8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_080A6706:
	cmp r4, r3
	beq _080A67A0
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A6718
	movs r2, #0
	b _080A671E
_080A6718:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r1, r0
_080A671E:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A672C
	movs r7, #0
	b _080A6732
_080A672C:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A6732:
	ldrb r0, [r2]
	movs r3, #0xf
	lsrs r2, r0, #4
	adds r5, r0, #0
	cmp r2, #1
	beq _080A677C
	cmp r2, #1
	bhs _080A67A4
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r3
	adds r2, r1, #0
	cmp r0, #0
	bne _080A6764
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A6764
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A67A0
_080A6764:
	lsrs r4, r2, #4
	cmp r4, #1
	bne _080A67A4
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A67A4
	ldrh r0, [r7, #2]
	ands r0, r4
	b _080A679C
_080A677C:
	ldrb r4, [r7]
	lsrs r0, r4, #4
	ands r0, r3
	cmp r0, #0
	beq _080A678A
	cmp r0, #1
	bne _080A67A4
_080A678A:
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r4
	adds r0, #1
	cmp r1, r0
	bne _080A67A4
	ldrh r0, [r7, #2]
	ands r0, r2
_080A679C:
	cmp r0, #0
	bne _080A67A4
_080A67A0:
	movs r0, #1
	b _080A6A64
_080A67A4:
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #0x10
	mov r1, sp
	strh r0, [r1]
	mov r2, ip
	movs r3, #6
	ldrsh r0, [r2, r3]
	movs r4, #2
	ldrsh r1, [r2, r4]
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sb
	ldrh r0, [r1]
	subs r0, #0x20
	add r1, sp, #8
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080A67F8
	cmp r1, #0
	blt _080A67F8
	ldr r0, _080A67FC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080A67F8
	ldr r0, _080A6800 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6804
_080A67F8:
	movs r4, #0
	b _080A6812
	.align 2, 0
_080A67FC: .4byte 0x030046A8
_080A6800: .4byte 0x030046AC
_080A6804:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080A6812:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sb
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A683A
	cmp r1, #0
	blt _080A683A
	ldr r0, _080A6840 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A683A
	ldr r0, _080A6844 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6848
_080A683A:
	movs r3, #0
	b _080A6856
	.align 2, 0
_080A6840: .4byte 0x030046A8
_080A6844: .4byte 0x030046AC
_080A6848:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_080A6856:
	cmp r4, r3
	beq _080A68FE
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A6868
	movs r2, #0
	b _080A686E
_080A6868:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r1, r0
_080A686E:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A687C
	movs r7, #0
	b _080A6882
_080A687C:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A6882:
	ldrb r0, [r2]
	movs r6, #0xf
	lsrs r2, r0, #4
	adds r5, r0, #0
	cmp r2, #1
	beq _080A6902
	cmp r2, #1
	blo _080A6898
	cmp r2, #2
	beq _080A68CC
	b _080A6902
_080A6898:
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	bne _080A68BA
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A68BA
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A68FE
_080A68BA:
	lsrs r0, r2, #4
	cmp r0, #2
	bne _080A6902
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r5
	adds r0, #1
	ands r1, r2
	b _080A68F0
_080A68CC:
	ldrb r4, [r7]
	lsrs r2, r4, #4
	ands r2, r6
	cmp r2, #0
	bne _080A68E2
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r4
	cmp r1, r0
	beq _080A68F4
_080A68E2:
	cmp r2, #2
	bne _080A6902
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r5
	adds r0, #1
	ands r1, r4
_080A68F0:
	cmp r0, r1
	bne _080A6902
_080A68F4:
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A6902
_080A68FE:
	movs r0, #2
	b _080A6A64
_080A6902:
	mov r1, ip
	movs r2, #4
	ldrsh r0, [r1, r2]
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, ip
	ldrh r0, [r4, #2]
	adds r0, #0x10
	mov r2, sp
	strh r0, [r2, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sb
	ldrh r0, [r1, #4]
	subs r0, #0x20
	strh r0, [r1, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080A6954
	cmp r1, #0
	blt _080A6954
	ldr r0, _080A6958 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080A6954
	ldr r0, _080A695C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6960
_080A6954:
	movs r4, #0
	b _080A696E
	.align 2, 0
_080A6958: .4byte 0x030046A8
_080A695C: .4byte 0x030046AC
_080A6960:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080A696E:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	mov r1, sb
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080A6996
	cmp r1, #0
	blt _080A6996
	ldr r0, _080A699C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080A6996
	ldr r0, _080A69A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A69A4
_080A6996:
	movs r3, #0
	b _080A69B2
	.align 2, 0
_080A699C: .4byte 0x030046A8
_080A69A0: .4byte 0x030046AC
_080A69A4:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_080A69B2:
	cmp r4, r3
	beq _080A6A5C
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A69C4
	movs r2, #0
	b _080A69CA
_080A69C4:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r1, r0
_080A69CA:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A69D8
	movs r7, #0
	b _080A69DE
_080A69D8:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A69DE:
	ldrb r3, [r2]
	movs r6, #0xf
	lsrs r0, r3, #4
	adds r5, r3, #0
	cmp r0, #1
	beq _080A6A2A
	cmp r0, #1
	bhs _080A6A60
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	bne _080A6A10
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bne _080A6A10
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A6A5C
_080A6A10:
	lsrs r4, r2, #4
	cmp r4, #1
	bne _080A6A60
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r5
	adds r0, #1
	ands r1, r2
	cmp r0, r1
	bne _080A6A60
	ldrh r0, [r7, #2]
	ands r0, r4
	b _080A6A58
_080A6A2A:
	ldrb r4, [r7]
	lsrs r2, r4, #4
	ands r2, r6
	cmp r2, #0
	bne _080A6A40
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r3
	ands r0, r4
	cmp r1, r0
	beq _080A6A52
_080A6A40:
	cmp r2, #1
	bne _080A6A60
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r3
	adds r0, #1
	ands r1, r4
	cmp r0, r1
	bne _080A6A60
_080A6A52:
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
_080A6A58:
	cmp r0, #0
	bne _080A6A60
_080A6A5C:
	movs r0, #3
	b _080A6A64
_080A6A60:
	movs r0, #1
	rsbs r0, r0, #0
_080A6A64:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A6A74:
	.byte 0xF0, 0xB5, 0x83, 0xB0, 0x6E, 0x20, 0x8A, 0xF1, 0x49, 0xFD, 0x00, 0x28
	.byte 0x02, 0xD0, 0x8A, 0xF1, 0x2F, 0xFE, 0x00, 0xE0, 0x00, 0x20, 0x00, 0x04, 0x00, 0x0C, 0x69, 0x46
	.byte 0x8D, 0xF1, 0x4C, 0xFF, 0x05, 0x1C, 0x00, 0x2D, 0x72, 0xD0, 0x00, 0x20, 0x29, 0x5E, 0x04, 0x22
	.byte 0xA8, 0x5E, 0x09, 0x18, 0xC9, 0x03, 0x09, 0x0C, 0x13, 0x4B, 0x01, 0x98, 0x18, 0x40, 0x08, 0x43
	.byte 0x01, 0x90, 0x02, 0x20, 0x29, 0x5E, 0x06, 0x22, 0xA8, 0x5E, 0x09, 0x18, 0xC9, 0x03, 0x09, 0x0C
	.byte 0x01, 0xAA, 0x50, 0x68, 0x18, 0x40, 0x08, 0x43, 0x50, 0x60, 0x16, 0x1C, 0x30, 0x88, 0x00, 0x04
	.byte 0x02, 0x16, 0xB0, 0x88, 0x00, 0x04, 0x01, 0x16, 0x37, 0x1C, 0x00, 0x2A, 0x09, 0xDB, 0x00, 0x29
	.byte 0x07, 0xDB, 0x06, 0x48, 0x00, 0x68, 0x82, 0x42, 0x03, 0xD2, 0x05, 0x48, 0x00, 0x68, 0x81, 0x42
	.byte 0x08, 0xD3, 0x00, 0x24, 0x0D, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xA8, 0x46, 0x00, 0x03
	.byte 0xAC, 0x46, 0x00, 0x03, 0x07, 0x48, 0x00, 0x68, 0x49, 0x00, 0x24, 0x30, 0x40, 0x18, 0x00, 0x88
	.byte 0x84, 0x18, 0x20, 0x1C, 0x01, 0x21, 0x8D, 0xF1, 0x85, 0xFB, 0x00, 0x28, 0x04, 0xD0, 0x04, 0x30
	.byte 0x08, 0xE0, 0x00, 0x00, 0xA4, 0x46, 0x00, 0x03, 0x07, 0x48, 0x01, 0x68, 0xA0, 0x00, 0x0C, 0x30
	.byte 0x49, 0x68, 0x08, 0x18, 0x01, 0x78, 0x0A, 0x09, 0x0F, 0x20, 0x08, 0x40, 0x01, 0x02, 0x01, 0x2A
	.byte 0x04, 0xD0, 0x02, 0x2A, 0x04, 0xD0, 0x05, 0xE0, 0xA4, 0x46, 0x00, 0x03, 0x30, 0x79, 0x00, 0xE0
	.byte 0x30, 0x78, 0x09, 0x1A, 0x79, 0x80, 0x28, 0x1C, 0xFF, 0xF7, 0xB8, 0xFC, 0x04, 0x1C, 0x00, 0x2C
	.byte 0x0E, 0xDB, 0x74, 0x20, 0x8A, 0xF1, 0xD4, 0xFC, 0x00, 0x28, 0x03, 0xD0, 0x8A, 0xF1, 0xBA, 0xFD
	.byte 0x02, 0x1C, 0x00, 0xE0, 0x00, 0x22, 0x38, 0x1C, 0x21, 0x1C, 0x00, 0x23, 0xFF, 0xF7, 0xBA, 0xFB
	.byte 0x03, 0xB0, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080a6b88
FUN_080a6b88: @ 0x080A6B88
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0
	ldrh r2, [r3, #0x18]
	cmp r2, #0
	bne _080A6BBC
	ldr r0, _080A6BB8 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x14
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _080A6BBC
	ldrh r0, [r3, #0x1e]
	cmp r0, #0x2f
	bhi _080A6BA8
	movs r1, #1
_080A6BA8:
	adds r0, #1
	strh r0, [r3, #0x1e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x47
	bls _080A6BBE
	strh r2, [r3, #0x1e]
	b _080A6BBE
	.align 2, 0
_080A6BB8: .4byte 0x030046A0
_080A6BBC:
	strh r1, [r3, #0x1e]
_080A6BBE:
	cmp r1, #0
	beq _080A6BE4
	movs r2, #0
	ldrh r0, [r3, #0x1c]
	cmp r2, r0
	bge _080A6C02
	movs r4, #2
	rsbs r4, r4, #0
	adds r1, r3, #0
	adds r1, #0x20
_080A6BD2:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, #0x28
	adds r2, #1
	ldrh r0, [r3, #0x1c]
	cmp r2, r0
	blt _080A6BD2
	b _080A6C02
_080A6BE4:
	movs r2, #0
	ldrh r4, [r3, #0x1c]
	cmp r2, r4
	bge _080A6C02
	movs r4, #1
	adds r1, r3, #0
	adds r1, #0x20
_080A6BF2:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x28
	adds r2, #1
	ldrh r0, [r3, #0x1c]
	cmp r2, r0
	blt _080A6BF2
_080A6C02:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a6c0c
FUN_080a6c0c: @ 0x080A6C0C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrh r0, [r6, #0x1c]
	cmp r5, r0
	bge _080A6C2C
	adds r4, r6, #0
	adds r4, #0x20
_080A6C1C:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x28
	adds r5, #1
	ldrh r0, [r6, #0x1c]
	cmp r5, r0
	blt _080A6C1C
_080A6C2C:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a6c34
FUN_080a6c34: @ 0x080A6C34
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	strh r0, [r1, #0x18]
	strh r0, [r1, #0x1c]
	strh r0, [r1, #0x1e]
	ldr r0, _080A6C50 @ =0x0000FD22
	movs r2, #0
	bl FUN_08230e30
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080A6C50: .4byte 0x0000FD22

	thumb_func_start FUN_080a6c54
FUN_080a6c54: @ 0x080A6C54
	push {r4, lr}
	movs r1, #0xb2
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A6C8C
	ldr r1, _080A6C84 @ =FUN_080a6b88
	ldr r2, _080A6C88 @ =FUN_080a6c0c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080a6c34
	cmp r0, #0
	bge _080A6C8C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A6C8E
	.align 2, 0
_080A6C84: .4byte FUN_080a6b88
_080A6C88: .4byte FUN_080a6c0c
_080A6C8C:
	adds r0, r4, #0
_080A6C8E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a6c94
FUN_080a6c94: @ 0x080A6C94
	push {r4, lr}
	sub sp, #8
	mov r0, sp
	bl FUN_0823167c
	movs r4, #0
	b _080A6CB2
_080A6CA2:
	bl fetch_082316e4
	adds r2, r0, #0
	mov r0, sp
	adds r1, r4, #0
	bl FUN_0823206c
	adds r4, #1
_080A6CB2:
	bl FUN_082316bc
	cmp r0, #0
	bne _080A6CA2
	movs r0, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a6cc4
FUN_080a6cc4: @ 0x080A6CC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r7, sp
	mov r1, sp
	adds r0, r1, #0
	str r0, [r7, #0xc]
	movs r0, #0x61
	bl prepare_08231510
	bl fetch_082316e4
	mov r8, r0
	movs r0, #0x72
	bl prepare_08231510
	bl fetch_082316e4
	mov sb, r0
	mov r1, r8
	lsls r0, r1, #5
	lsrs r0, r0, #3
	mov r1, sp
	subs r1, r1, r0
	mov sp, r1
	mov r0, sp
	str r0, [r7, #8]
	mov r0, r8
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080A6D7C @ =0xFFFF0000
	ldr r0, [r7]
	ands r0, r2
	orrs r0, r1
	str r0, [r7]
	mov r1, sp
	str r1, [r7, #4]
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080A6D66
	bl fetch_082316e4
	mov sl, r0
	movs r0, #0x64
	bl prepare_08231510
	bl FUN_082316bc
	adds r6, r0, #0
	movs r0, #0
	cmp r0, sb
	bge _080A6D66
_080A6D36:
	adds r0, #1
	str r0, [r7, #0x10]
	mov r0, r8
	cmp r0, #0
	ble _080A6D58
	ldr r5, [r7, #8]
	mov r4, r8
_080A6D44:
	adds r0, r6, #0
	bl FUN_082315a4
	stm r5!, {r0}
	bl FUN_082316bc
	adds r6, r0, #0
	subs r4, #1
	cmp r4, #0
	bne _080A6D44
_080A6D58:
	mov r0, sl
	adds r1, r7, #0
	bl FUN_08231b58
	ldr r0, [r7, #0x10]
	cmp r0, sb
	blt _080A6D36
_080A6D66:
	movs r0, #0
	ldr r1, [r7, #0xc]
	mov sp, r1
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A6D7C: .4byte 0xFFFF0000
_080A6D80:
	.byte 0x00, 0xB5, 0x70, 0x20, 0x8A, 0xF1, 0xC4, 0xFB, 0x00, 0x28, 0x19, 0xD0, 0x8A, 0xF1, 0xAA, 0xFC
	.byte 0x03, 0x1C, 0x00, 0x2B, 0x14, 0xDD, 0x07, 0x4A, 0x10, 0x68, 0x01, 0x30, 0x06, 0x49, 0x08, 0x40
	.byte 0x10, 0x60, 0x40, 0x00, 0x05, 0x49, 0x40, 0x18, 0x00, 0x88, 0xC0, 0x10, 0x19, 0x1C, 0xA5, 0xF1
	.byte 0x09, 0xFA, 0x0F, 0xE0, 0xB8, 0x46, 0x00, 0x03, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xB4, 0x03, 0x02
	.byte 0x05, 0x4A, 0x10, 0x68, 0x01, 0x30, 0x05, 0x49, 0x08, 0x40, 0x10, 0x60, 0x40, 0x00, 0x04, 0x49
	.byte 0x40, 0x18, 0x00, 0x88, 0x02, 0xBC, 0x08, 0x47, 0xB8, 0x46, 0x00, 0x03, 0xFF, 0x03, 0x00, 0x00
	.byte 0x00, 0xB4, 0x03, 0x02, 0x00, 0xB5, 0x70, 0x20, 0x8A, 0xF1, 0x92, 0xFB, 0x00, 0x28, 0x05, 0xD0
	.byte 0x01, 0x48, 0x40, 0x88, 0x18, 0xE0, 0x00, 0x00, 0xE0, 0x44, 0x00, 0x03, 0x73, 0x20, 0x8A, 0xF1
	.byte 0x87, 0xFB, 0x00, 0x28, 0x04, 0xD0, 0x01, 0x48, 0x00, 0x88, 0x0D, 0xE0, 0xE0, 0x44, 0x00, 0x03
	.byte 0x72, 0x20, 0x8A, 0xF1, 0x7D, 0xFB, 0x00, 0x28, 0x04, 0xD1, 0x01, 0x48, 0x40, 0x88, 0x03, 0xE0
	.byte 0xE0, 0x44, 0x00, 0x03, 0x01, 0x48, 0x80, 0x88, 0x02, 0xBC, 0x08, 0x47, 0xE0, 0x44, 0x00, 0x03
	.byte 0x30, 0xB5, 0x72, 0x20, 0x8A, 0xF1, 0x6C, 0xFB, 0x00, 0x28, 0x0F, 0xD0, 0x8A, 0xF1, 0x76, 0xFC
	.byte 0x05, 0x1C, 0x69, 0x20, 0x8A, 0xF1, 0x64, 0xFB, 0x00, 0x28, 0x07, 0xD0, 0x8A, 0xF1, 0x4A, 0xFC
	.byte 0x04, 0x1C, 0x73, 0x20, 0x8A, 0xF1, 0x5C, 0xFB, 0x00, 0x28, 0x02, 0xD1, 0x01, 0x20, 0x40, 0x42
	.byte 0x0E, 0xE0, 0x8A, 0xF1, 0x3F, 0xFC, 0x00, 0x28, 0x02, 0xD1, 0x28, 0x19, 0x00, 0x78, 0x07, 0xE0
	.byte 0x01, 0x28, 0x01, 0xD0, 0xA0, 0x00, 0x00, 0xE0, 0x60, 0x00, 0x28, 0x18, 0x00, 0x21, 0x40, 0x5E
	.byte 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a6e88
FUN_080a6e88: @ 0x080A6E88
	push {r4, r5, lr}
	ldr r3, _080A6EB8 @ =0x030047A4
	ldr r1, [r3]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r3]
	cmp r0, #0
	beq _080A6EB0
	ldr r4, _080A6EBC @ =0x030044BC
	ldr r0, [r4]
	movs r5, #8
	ands r0, r5
	cmp r0, #0
	bne _080A6EB0
	bl FUN_08240918
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
_080A6EB0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A6EB8: .4byte 0x030047A4
_080A6EBC: .4byte 0x030044BC
_080A6EC0:
	.byte 0x00, 0xB5, 0x70, 0x20, 0x8A, 0xF1, 0x24, 0xFB, 0x00, 0x28, 0x02, 0xD0, 0x8A, 0xF1, 0x0A, 0xFC
	.byte 0x00, 0xE0, 0x00, 0x20, 0xFF, 0xF7, 0xD8, 0xFF, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080a6edc
FUN_080a6edc: @ 0x080A6EDC
	push {r4, lr}
	ldr r2, _080A6F08 @ =0x030047A4
	ldr r0, [r2]
	ldr r1, _080A6F0C @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r2]
	ldr r4, _080A6F10 @ =0x030044BC
	ldr r0, [r4]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _080A6F02
	bl FUN_08240930
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_080A6F02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A6F08: .4byte 0x030047A4
_080A6F0C: .4byte 0xFFFFFDFF
_080A6F10: .4byte 0x030044BC
_080A6F14:
	.byte 0x00, 0xB5, 0xFF, 0xF7, 0xE1, 0xFF, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x00, 0xB5, 0x04, 0x48, 0x00, 0x68, 0x80, 0x21, 0x89, 0x00, 0x08, 0x40, 0x00, 0x28, 0x03, 0xD1
	.byte 0x00, 0x20, 0x02, 0xE0, 0xA4, 0x47, 0x00, 0x03, 0x01, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00
	.byte 0x03, 0x49, 0x0A, 0x68, 0x80, 0x23, 0x1B, 0x01, 0x1A, 0x43, 0x0A, 0x60, 0x70, 0x47, 0x00, 0x00
	.byte 0xA4, 0x47, 0x00, 0x03, 0x00, 0xB5, 0x03, 0x1C, 0x9A, 0x30, 0x00, 0x88, 0x05, 0x28, 0x17, 0xD8
	.byte 0x08, 0x4A, 0x10, 0x68, 0x01, 0x30, 0x08, 0x49, 0x08, 0x40, 0x10, 0x60, 0x40, 0x00, 0x07, 0x49
	.byte 0x40, 0x18, 0x00, 0x88, 0x00, 0x11, 0x0F, 0x21, 0x08, 0x40, 0x07, 0x38, 0x19, 0x1C, 0x58, 0x31
	.byte 0x08, 0x80, 0x0B, 0xE0, 0xB8, 0x46, 0x00, 0x03, 0xFF, 0x03, 0x00, 0x00, 0x00, 0xB4, 0x03, 0x02
	.byte 0x18, 0x1C, 0x58, 0x30, 0x00, 0x21, 0x01, 0x80, 0x02, 0x30, 0x01, 0x80, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_080a6fa0
FUN_080a6fa0: @ 0x080A6FA0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xac
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r2, r4, #0
	adds r2, #0x9a
	ldrh r1, [r2]
	adds r1, #1
	strh r1, [r2]
	adds r2, #2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r2, [r2]
	cmp r1, r2
	blo _080A6FDA
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r0, [r0]
	cmp r0, #0
	beq _080A6FD4
	movs r1, #0
	bl FUN_082318ac
_080A6FD4:
	adds r0, r4, #0
	bl KillEntity
_080A6FDA:
	pop {r4}
	pop {r1}
	bx r1
_080A6FE0:
	.byte 0x00, 0xB5, 0x38, 0x30, 0x88, 0xF1, 0xEC, 0xF8, 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_080a6ff0
FUN_080a6ff0: @ 0x080A6FF0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _080A700C @ =0x0000CB05
	ldr r1, _080A7010 @ =0x000082F1
	bl FUN_082310cc
	adds r2, r0, #0
	cmp r2, #0
	bne _080A7014
	movs r0, #1
	rsbs r0, r0, #0
	b _080A70C0
	.align 2, 0
_080A700C: .4byte 0x0000CB05
_080A7010: .4byte 0x000082F1
_080A7014:
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r2, #0
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r5, #0
	adds r4, #0x18
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	movs r0, #0x74
	bl prepare_08231510
	adds r7, r4, #0
	cmp r0, #0
	beq _080A7046
	bl fetch_082316e4
	adds r6, r0, #0
	b _080A7048
_080A7046:
	movs r6, #0
_080A7048:
	movs r0, #0x49
	bl prepare_08231510
	cmp r0, #0
	beq _080A705C
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0x9c
	b _080A7062
_080A705C:
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #0x3c
_080A7062:
	strh r0, [r1]
	adds r1, r5, #0
	adds r1, #0xac
	ldr r0, _080A70B4 @ =0x080A6F55
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0xa0
	movs r3, #0
	strh r3, [r4]
	adds r0, r5, #0
	adds r0, #0xa2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	subs r0, #0x6c
	adds r2, r6, #0
	adds r2, #0xb
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r1, #1
	str r1, [sp]
	str r3, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	adds r1, r7, #0
	movs r3, #0x10
	bl FUN_0822f3fc
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A70B8
	bl fetch_082316e4
	adds r1, r5, #0
	adds r1, #0xa8
	str r0, [r1]
	b _080A70BE
	.align 2, 0
_080A70B4: .4byte 0x080A6F55
_080A70B8:
	adds r0, r5, #0
	adds r0, #0xa8
	str r1, [r0]
_080A70BE:
	movs r0, #0
_080A70C0:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080A70C8:
	.byte 0x10, 0xB5, 0x09, 0x20, 0xB0, 0x21, 0x89, 0xF1
	.byte 0x6F, 0xFD, 0x04, 0x1C, 0x00, 0x2C, 0x11, 0xD0, 0x06, 0x49, 0x07, 0x4A, 0x89, 0xF1, 0x8C, 0xFD
	.byte 0x20, 0x1C, 0xFF, 0xF7, 0x85, 0xFF, 0x00, 0x28, 0x08, 0xD0, 0x20, 0x1C, 0x89, 0xF1, 0xBE, 0xFD
	.byte 0x00, 0x20, 0x04, 0xE0, 0xA1, 0x6F, 0x0A, 0x08, 0xE1, 0x6F, 0x0A, 0x08, 0x20, 0x1C, 0x10, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080a7104
FUN_080a7104: @ 0x080A7104
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_082407b8
	movs r0, #2
	bl PlaySound_082406e0
	movs r0, #0x96
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _080A713C @ =0x0000033E
	adds r1, r4, r0
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080A7140 @ =0x00000341
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A713C: .4byte 0x0000033E
_080A7140: .4byte 0x00000341

	thumb_func_start FUN_080a7144
FUN_080a7144: @ 0x080A7144
	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080A7178 @ =0x0000033E
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #0x1e
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7e
	ble _080A7172
	movs r0, #0x7f
	strh r0, [r1]
	ldr r0, _080A717C @ =0x00000341
	adds r1, r2, r0
	movs r0, #2
	strb r0, [r1]
_080A7172:
	pop {r0}
	bx r0
	.align 2, 0
_080A7178: .4byte 0x0000033E
_080A717C: .4byte 0x00000341

	thumb_func_start FUN_080a7180
FUN_080a7180: @ 0x080A7180
	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080A71B4 @ =0x0000033E
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x60
	bgt _080A71AE
	movs r0, #0x60
	strh r0, [r1]
	ldr r0, _080A71B8 @ =0x00000341
	adds r1, r2, r0
	movs r0, #3
	strb r0, [r1]
_080A71AE:
	pop {r0}
	bx r0
	.align 2, 0
_080A71B4: .4byte 0x0000033E
_080A71B8: .4byte 0x00000341

	thumb_func_start FUN_080a71bc
FUN_080a71bc: @ 0x080A71BC
	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	ldr r0, _080A71F0 @ =0x0000033E
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x40
	bgt _080A71EA
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080A71F4 @ =0x00000341
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
_080A71EA:
	pop {r0}
	bx r0
	.align 2, 0
_080A71F0: .4byte 0x0000033E
_080A71F4: .4byte 0x00000341

	thumb_func_start FUN_080a71f8
FUN_080a71f8: @ 0x080A71F8
	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	ble _080A7224
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080A7228 @ =0x00000341
	adds r1, r2, r0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _080A722C @ =0x00000346
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
_080A7224:
	pop {r0}
	bx r0
	.align 2, 0
_080A7228: .4byte 0x00000341
_080A722C: .4byte 0x00000346

	thumb_func_start FUN_080a7230
FUN_080a7230: @ 0x080A7230
	push {lr}
	adds r1, r0, #0
	ldr r0, _080A7258 @ =0x00000346
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _080A7252
	ldr r3, _080A725C @ =0x00000341
	adds r0, r1, r3
	movs r1, #6
	strb r1, [r0]
	movs r0, #0
	strh r0, [r2]
_080A7252:
	pop {r0}
	bx r0
	.align 2, 0
_080A7258: .4byte 0x00000346
_080A725C: .4byte 0x00000341

	thumb_func_start FUN_080a7260
FUN_080a7260: @ 0x080A7260
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A7280 @ =0x00000346
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1e
	bne _080A7288
	ldr r0, _080A7284 @ =0x000002F9
	bl PlaySound_082406e0
	b _080A72E0
	.align 2, 0
_080A7280: .4byte 0x00000346
_080A7284: .4byte 0x000002F9
_080A7288:
	cmp r0, #0x95
	bls _080A72E0
	cmp r0, #0x96
	bne _080A7296
	ldr r0, _080A72E8 @ =0x0000012D
	bl PlaySound_082406e0
_080A7296:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r2, r4, r1
	ldrh r0, [r2]
	adds r0, #5
	strh r0, [r2]
	ldr r3, _080A72EC @ =0x0000033E
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #5
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0x7f
	ble _080A72E0
	movs r0, #1
	strh r0, [r2]
	strh r0, [r1]
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #7
_080A72C2:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x50
	subs r2, #1
	cmp r2, #0
	bge _080A72C2
	movs r2, #0
	ldr r0, _080A72F0 @ =0x00000341
	adds r1, r4, r0
	movs r0, #7
	strb r0, [r1]
	ldr r1, _080A72F4 @ =0x00000346
	adds r0, r4, r1
	strh r2, [r0]
_080A72E0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A72E8: .4byte 0x0000012D
_080A72EC: .4byte 0x0000033E
_080A72F0: .4byte 0x00000341
_080A72F4: .4byte 0x00000346

	thumb_func_start FUN_080a72f8
FUN_080a72f8: @ 0x080A72F8
	push {lr}
	adds r2, r0, #0
	ldr r0, _080A731C @ =0x00000346
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080A7316
	ldr r0, _080A7320 @ =0x00000341
	adds r1, r2, r0
	movs r0, #8
	strb r0, [r1]
_080A7316:
	pop {r0}
	bx r0
	.align 2, 0
_080A731C: .4byte 0x00000346
_080A7320: .4byte 0x00000341

	thumb_func_start FUN_080a7324
FUN_080a7324: @ 0x080A7324
	push {r4, r5, lr}
	mov ip, r0
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, ip
	ldr r2, _080A7374 @ =0x0000033E
	add r2, ip
	mov r1, ip
	adds r1, #0x20
	movs r3, #7
_080A7338:
	ldrh r0, [r4]
	strb r0, [r1]
	ldrh r0, [r2]
	strb r0, [r1, #1]
	adds r1, #0x50
	subs r3, #1
	cmp r3, #0
	bge _080A7338
	movs r3, #3
	movs r1, #0
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, ip
	movs r2, #0x92
	lsls r2, r2, #1
	add r2, ip
_080A7358:
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r0, #0x40
	ble _080A7378
	ldrh r0, [r2, #0x2c]
	subs r0, r0, r1
	strh r0, [r2]
	subs r1, #0x10
	movs r5, #0
	ldrsh r0, [r4, r5]
	asrs r0, r0, #2
	adds r1, r1, r0
	b _080A737C
	.align 2, 0
_080A7374: .4byte 0x0000033E
_080A7378:
	ldrh r0, [r2, #0x2c]
	strh r0, [r2]
_080A737C:
	subs r2, #0x50
	subs r3, #1
	cmp r3, #0
	bge _080A7358
	movs r1, #0
	movs r4, #0xcf
	lsls r4, r4, #2
	add r4, ip
	movs r2, #0xba
	lsls r2, r2, #1
	add r2, ip
	movs r3, #3
_080A7394:
	movs r5, #0
	ldrsh r0, [r4, r5]
	cmp r0, #0x40
	ble _080A73AE
	ldrh r0, [r2, #0x2c]
	adds r0, r0, r1
	strh r0, [r2]
	subs r1, #0x10
	movs r5, #0
	ldrsh r0, [r4, r5]
	asrs r0, r0, #2
	adds r1, r1, r0
	b _080A73B2
_080A73AE:
	ldrh r0, [r2, #0x2c]
	strh r0, [r2]
_080A73B2:
	adds r2, #0x50
	subs r3, #1
	cmp r3, #0
	bge _080A7394
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a73c0
FUN_080a73c0: @ 0x080A73C0
	push {lr}
	ldr r0, _080A73DC @ =0x030047A4
	ldr r1, [r0]
	ldr r2, _080A73E0 @ =0xFFFFFBFF
	ands r1, r2
	str r1, [r0]
	movs r0, #2
	bl sound_08240740
	movs r0, #0
	bl FUN_0823a8f4
	pop {r0}
	bx r0
	.align 2, 0
_080A73DC: .4byte 0x030047A4
_080A73E0: .4byte 0xFFFFFBFF

	thumb_func_start FUN_080a73e4
FUN_080a73e4: @ 0x080A73E4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A7408 @ =0x085AD014
	ldr r2, _080A740C @ =0x00000341
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080a7324
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7408: .4byte 0x085AD014
_080A740C: .4byte 0x00000341

	thumb_func_start FUN_080a7410
FUN_080a7410: @ 0x080A7410
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #7
_080A741A:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a340
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _080A741A
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #0
	bl FUN_0822a3f0
	ldr r0, _080A7444 @ =0x00000342
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A7444: .4byte 0x00000342

	thumb_func_start FUN_080a7448
FUN_080a7448: @ 0x080A7448
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #1
	strh r1, [r0]
	ldr r2, _080A74F0 @ =0x0000033E
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0
	movs r0, #0
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0x28
	adds r5, r7, #0
	adds r5, #0x18
	adds r6, r7, #0
	adds r6, #0x44
	mov r8, r5
	movs r1, #0x38
	mov sb, r1
_080A747E:
	mov r2, sb
	strh r2, [r4, #0x38]
	movs r0, #0x48
	strh r0, [r4, #0x3a]
	cmp r3, #3
	ble _080A7490
	mov r0, sb
	adds r0, #0x10
	strh r0, [r4, #0x38]
_080A7490:
	adds r0, r6, #0
	ldr r1, _080A74F4 @ =0x0000654B
	str r3, [sp]
	bl FUN_0822b16c
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0822a4b0
	mov r0, sl
	strb r0, [r5, #7]
	ldr r0, _080A74F8 @ =0x00001033
	str r0, [r5]
	ldrh r0, [r4, #0x38]
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0x3a]
	strh r0, [r4, #0xe]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	strb r0, [r5, #8]
	ldr r2, _080A74F0 @ =0x0000033E
	adds r0, r7, r2
	ldrh r0, [r0]
	strb r0, [r5, #9]
	ldr r3, [sp]
	strh r3, [r4]
	adds r4, #0x50
	adds r5, #0x50
	adds r6, #0x50
	movs r0, #0x50
	add r8, r0
	movs r1, #0x10
	add sb, r1
	adds r3, #1
	cmp r3, #7
	ble _080A747E
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A74F0: .4byte 0x0000033E
_080A74F4: .4byte 0x0000654B
_080A74F8: .4byte 0x00001033

	thumb_func_start FUN_080a74fc
FUN_080a74fc: @ 0x080A74FC
	push {lr}
	adds r3, r0, #0
	movs r1, #0xd1
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _080A7528
	movs r2, #0x1b
	cmp r0, #0x11
	bls _080A7528
	movs r2, #0x12
	cmp r0, #0x19
	bls _080A7528
	movs r2, #0xa
	cmp r0, #0x21
	bls _080A7528
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _080A7528
	movs r2, #0x12
_080A7528:
	movs r0, #0xd1
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _080A7540
	movs r0, #0
	strh r0, [r1]
_080A7540:
	ldr r1, _080A754C @ =0x00000336
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_080A754C: .4byte 0x00000336

	thumb_func_start FUN_080a7550
FUN_080a7550: @ 0x080A7550
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _080A75F0 @ =0x0000CB05
	ldr r1, _080A75F4 @ =0x0000B343
	bl FUN_082310cc
	adds r2, r0, #0
	cmp r2, #0
	beq _080A75E8
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r4, r5, r0
	adds r1, r4, #0
	adds r0, r2, #0
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6}
	stm r1!, {r3, r6}
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822f284
	ldr r2, _080A75F8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	ldr r1, _080A75FC @ =0x0000FFF8
	orrs r0, r1
	adds r1, #7
	ands r0, r1
	ldr r1, _080A7600 @ =0xFFF80000
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r7, #0xae
	lsls r7, r7, #2
	adds r0, r5, r7
	ldr r3, _080A7604 @ =0x00001091
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r1, sp, #0x10
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x87
	bl FUN_0822f4d8
	ldr r0, _080A7608 @ =0x03003584
	ldr r0, [r0]
	ldr r3, _080A760C @ =0x00005520
	adds r0, r0, r3
	movs r6, #0xc6
	lsls r6, r6, #2
	adds r4, r5, r6
	ldr r2, _080A7610 @ =0x04000008
	adds r1, r4, #0
	bl CpuSet
	adds r7, #0x3a
	adds r1, r5, r7
	movs r2, #0
	ldr r0, _080A7614 @ =0x000002A9
	strh r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r0, r5, r1
	str r4, [r0]
	ldr r3, _080A7618 @ =0x00000343
	adds r0, r5, r3
	strb r2, [r0]
_080A75E8:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A75F0: .4byte 0x0000CB05
_080A75F4: .4byte 0x0000B343
_080A75F8: .4byte 0xFFFF0000
_080A75FC: .4byte 0x0000FFF8
_080A7600: .4byte 0xFFF80000
_080A7604: .4byte 0x00001091
_080A7608: .4byte 0x03003584
_080A760C: .4byte 0x00005520
_080A7610: .4byte 0x04000008
_080A7614: .4byte 0x000002A9
_080A7618: .4byte 0x00000343

	thumb_func_start FUN_080a761c
FUN_080a761c: @ 0x080A761C
	push {r4, lr}
	sub sp, #0xc
	ldr r0, _080A7670 @ =0x03000150
	ldr r4, [r0]
	cmp r4, #0
	beq _080A7668
	adds r0, r4, #0
	bl FUN_080a7410
	movs r0, #7
	bl FUN_0809c08c
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _080A7668
	bl fetch_082316e4
	cmp r0, #0
	beq _080A7668
	movs r0, #4
	str r0, [sp]
	ldr r0, _080A7674 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080A7668:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7670: .4byte 0x03000150
_080A7674: .4byte 0x00001FFF

	thumb_func_start FUN_080a7678
FUN_080a7678: @ 0x080A7678
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080A76C0 @ =0x030047A4
	ldr r1, _080A76C4 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _080A76EE
	adds r0, r4, #0
	bl FUN_080a7410
	movs r0, #7
	bl FUN_0809c08c
	ldr r0, _080A76C8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #0x1c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080A76CC
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080A76E4
	.align 2, 0
_080A76C0: .4byte 0x030047A4
_080A76C4: .4byte 0x030047A0
_080A76C8: .4byte 0x03002BE0
_080A76CC:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080A76F8 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080A76E4:
	movs r0, #0xd0
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080A76EE:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A76F8: .4byte 0x00001FFF

	thumb_func_start FUN_080a76fc
FUN_080a76fc: @ 0x080A76FC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _080A774C @ =0x00000346
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A7746
	ldr r5, _080A7750 @ =FUN_0822e110
	ldr r6, _080A7754 @ =FUN_0822adac
	ldr r7, _080A7758 @ =FUN_0822f244
	movs r3, #2
	rsbs r3, r3, #0
	adds r1, r4, #0
	adds r1, #0x18
	movs r2, #7
_080A7722:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x50
	subs r2, #1
	cmp r2, #0
	bge _080A7722
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_0822a448
	movs r0, #0xd0
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
_080A7746:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A774C: .4byte 0x00000346
_080A7750: .4byte FUN_0822e110
_080A7754: .4byte FUN_0822adac
_080A7758: .4byte FUN_0822f244

	thumb_func_start FUN_080a775c
FUN_080a775c: @ 0x080A775C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_080a73e4
	ldr r1, _080A77E0 @ =0x00000341
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _080A77F8
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #3
	bl FUN_0809c08c
	movs r0, #1
	movs r1, #0xd
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	movs r1, #0xce
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_080478f0
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r5, r6, r2
	ldrb r0, [r5]
	lsls r0, r0, #1
	movs r1, #0xd2
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, #0
	bl FUN_08047c40
	ldr r0, _080A77E4 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r4, [r4]
	cmp r1, r4
	blt _080A77E8
	movs r0, #0
	bl FUN_08047a28
	b _080A77EE
	.align 2, 0
_080A77E0: .4byte 0x00000341
_080A77E4: .4byte 0x030046A0
_080A77E8:
	movs r0, #1
	bl FUN_08047a28
_080A77EE:
	movs r0, #0xd0
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #3
	strb r0, [r1]
_080A77F8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a7800
FUN_080a7800: @ 0x080A7800
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r6, #1
	rsbs r6, r6, #0
	ldr r0, _080A782C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A7834
	ldr r1, _080A7830 @ =0x00000343
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r6, #1
	cmp r0, #0
	beq _080A7824
	movs r6, #0
_080A7824:
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _080A7844
	.align 2, 0
_080A782C: .4byte 0x030044E0
_080A7830: .4byte 0x00000343
_080A7834:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080A7844
	movs r6, #0
	movs r0, #0xde
	bl PlaySound_082406e0
_080A7844:
	cmp r6, #0
	bne _080A789C
	movs r2, #0xb0
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	bl FUN_08047864
	movs r0, #7
	bl FUN_0809c08c
	ldr r0, _080A788C @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807adc0
	movs r0, #2
	bl sound_fadeout_08240440
	ldr r3, _080A7890 @ =0x00000346
	adds r0, r5, r3
	strh r6, [r0]
	ldr r1, _080A7894 @ =0x00000343
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _080A7898 @ =0x00000341
	adds r1, r5, r2
	movs r0, #6
	strb r0, [r1]
	subs r3, #6
	adds r1, r5, r3
	movs r0, #4
	strb r0, [r1]
	b _080A79A2
	.align 2, 0
_080A788C: .4byte 0x03002BE0
_080A7890: .4byte 0x00000346
_080A7894: .4byte 0x00000343
_080A7898: .4byte 0x00000341
_080A789C:
	cmp r6, #1
	bne _080A7918
	movs r0, #2
	bl sound_fadeout_08240440
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	movs r3, #1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #7
_080A78BA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x50
	subs r2, #1
	cmp r2, #0
	bge _080A78BA
	bl FUN_08047864
	movs r0, #7
	bl FUN_0809c08c
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080A790A
	ldr r1, _080A7914 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r1, [r0]
	lsls r1, r1, #1
	subs r3, #4
	adds r0, r5, r3
	adds r0, r0, r1
	ldrh r0, [r0]
	str r0, [sp]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl FUN_082318ac
_080A790A:
	adds r0, r5, #0
	bl KillEntity
	b _080A79A2
	.align 2, 0
_080A7914: .4byte 0xFFFF0000
_080A7918:
	movs r2, #0
	ldr r0, _080A7934 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080A793C
	ldr r1, _080A7938 @ =0x00000343
	adds r0, r5, r1
	ldrb r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r2, r0, #0x1f
	b _080A7950
	.align 2, 0
_080A7934: .4byte 0x030044E0
_080A7938: .4byte 0x00000343
_080A793C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080A7950
	ldr r3, _080A7984 @ =0x00000343
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080A7950
	movs r2, #1
_080A7950:
	cmp r2, #0
	beq _080A799C
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080A7984 @ =0x00000343
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A7988
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xa6
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0x88
	movs r3, #1
	bl FUN_0822f3cc
	b _080A799C
	.align 2, 0
_080A7984: .4byte 0x00000343
_080A7988:
	movs r3, #0xae
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r2, #0xa6
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0x87
	movs r3, #1
	bl FUN_0822f3cc
_080A799C:
	adds r0, r5, #0
	bl FUN_080a74fc
_080A79A2:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a79ac
FUN_080a79ac: @ 0x080A79AC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a73e4
	ldr r1, _080A79E4 @ =0x00000341
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _080A79DE
	ldr r2, _080A79E8 @ =0x030047A4
	ldr r0, [r2]
	ldr r1, _080A79EC @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r2]
	ldr r1, _080A79F0 @ =0x03004788
	movs r0, #0
	str r0, [r1]
	ldr r1, _080A79F4 @ =0x00000343
	adds r0, r4, r1
	ldrb r0, [r0]
	bl FUN_0823a8f4
	adds r0, r4, #0
	bl KillEntity
_080A79DE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A79E4: .4byte 0x00000341
_080A79E8: .4byte 0x030047A4
_080A79EC: .4byte 0xFFFFFBFF
_080A79F0: .4byte 0x03004788
_080A79F4: .4byte 0x00000343

	thumb_func_start FUN_080a79f8
FUN_080a79f8: @ 0x080A79F8
	push {lr}
	ldr r2, _080A7A14 @ =0x085AD034
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r0, r3
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080A7A14: .4byte 0x085AD034

	thumb_func_start FUN_080a7a18
FUN_080a7a18: @ 0x080A7A18
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _080A7A50 @ =0x00000342
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080A7A44
	adds r4, r6, #0
	adds r4, #0x18
	movs r5, #7
_080A7A2C:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _080A7A2C
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_0822f1c0
_080A7A44:
	ldr r1, _080A7A54 @ =0x03000150
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A7A50: .4byte 0x00000342
_080A7A54: .4byte 0x03000150

	thumb_func_start FUN_080a7a58
FUN_080a7a58: @ 0x080A7A58
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a7448
	adds r0, r4, #0
	bl FUN_080a7550
	movs r1, #0xd0
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080A7ABC @ =0x00000341
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #5
	adds r0, r4, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _080A7AC0 @ =0x00000342
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x72
	bl prepare_08231510
	cmp r0, #0
	beq _080A7A9A
	bl FUN_0823d340
	movs r2, #0xce
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
_080A7A9A:
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _080A7AC8
	bl fetch_082316e4
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	bl fetch_082316e4
	ldr r2, _080A7AC4 @ =0x0000034A
	adds r1, r4, r2
	b _080A7ADA
	.align 2, 0
_080A7ABC: .4byte 0x00000341
_080A7AC0: .4byte 0x00000342
_080A7AC4: .4byte 0x0000034A
_080A7AC8:
	movs r0, #0xd2
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0xfa
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r2, _080A7B00 @ =0x0000034A
	adds r1, r4, r2
	movs r0, #0xfa
_080A7ADA:
	strh r0, [r1]
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	adds r1, r0, #0
	cmp r1, #0
	beq _080A7B04
	bl fetch_082316e4
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	b _080A7B0C
	.align 2, 0
_080A7B00: .4byte 0x0000034A
_080A7B04:
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
_080A7B0C:
	ldr r0, _080A7B18 @ =0x03000150
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A7B18: .4byte 0x03000150

	thumb_func_start FUN_080a7b1c
FUN_080a7b1c: @ 0x080A7B1C
	push {r4, lr}
	ldr r0, _080A7B54 @ =0x03000150
	ldr r0, [r0]
	cmp r0, #0
	bne _080A7B62
	movs r1, #0xd5
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A7B60
	ldr r1, _080A7B58 @ =FUN_080a79f8
	ldr r2, _080A7B5C @ =FUN_080a7a18
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080a7a58
	cmp r0, #0
	bge _080A7B60
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A7B62
	.align 2, 0
_080A7B54: .4byte 0x03000150
_080A7B58: .4byte FUN_080a79f8
_080A7B5C: .4byte FUN_080a7a18
_080A7B60:
	adds r0, r4, #0
_080A7B62:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a7b68
FUN_080a7b68: @ 0x080A7B68
	movs r3, #0x82
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080A7B7C @ =0x00000206
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080A7B7C: .4byte 0x00000206

	thumb_func_start FUN_080a7b80
FUN_080a7b80: @ 0x080A7B80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	movs r0, #0
	str r0, [sp]
_080A7B92:
	movs r0, #0x2c
	ldr r2, [sp]
	adds r1, r2, #0
	muls r1, r0, r1
	mov sl, r1
	mov r7, sb
	add r7, sl
	adds r3, r7, #0
	adds r3, #0xc8
	ldrb r0, [r3]
	cmp r0, #0
	beq _080A7C48
	movs r0, #0xc9
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	adds r0, #1
	movs r4, #0
	mov r1, r8
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080A7BD4
	mov r0, sb
	adds r0, #0xa0
	add r0, sl
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	strb r4, [r3]
	b _080A7C48
_080A7BD4:
	mov r2, r8
	ldrb r0, [r2]
	movs r4, #8
	subs r4, r4, r0
	adds r6, r4, #1
	adds r5, r7, #0
	adds r5, #0xb8
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r1, sb
	adds r1, #0x88
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	adds r5, #2
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r1, sb
	adds r1, #0x8a
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	adds r5, #2
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r1, sb
	adds r1, #0x8c
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #4
	bne _080A7C48
	mov r0, sl
	adds r0, #0xa0
	add r0, sb
	mov r1, sb
	adds r1, #0x9c
	ldr r1, [r1]
	movs r2, #9
	bl FUN_0822dafc
_080A7C48:
	ldr r2, [sp]
	adds r2, #1
	str r2, [sp]
	cmp r2, #7
	ble _080A7B92
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a7c64
FUN_080a7c64: @ 0x080A7C64
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _080A7D68 @ =0x00000201
	adds r0, r0, r6
	mov sb, r0
	ldrb r0, [r0]
	adds r0, #1
	mov r1, sb
	strb r0, [r1]
	movs r3, #0xff
	mov r2, sp
	strb r3, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080A7D58
	movs r0, #0x80
	lsls r0, r0, #2
	adds r7, r6, r0
	ldrb r0, [r7]
	movs r4, #0x2c
	muls r0, r4, r0
	adds r1, r6, #0
	adds r1, #0xa0
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldrb r0, [r7]
	muls r0, r4, r0
	adds r2, r6, #0
	adds r2, #0xb8
	adds r2, r2, r0
	adds r0, r6, #0
	adds r0, #0x88
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _080A7D6C @ =0x0203B400
	mov ip, r1
	ldr r2, _080A7D70 @ =0x030046B8
	mov r8, r2
	ldr r2, [r2]
	adds r2, #1
	ldr r5, _080A7D74 @ =0x000003FF
	ands r2, r5
	lsls r3, r2, #1
	add r3, ip
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xb8
	ldrh r0, [r1]
	subs r0, #0x7f
	ldrb r3, [r3]
	adds r0, r0, r3
	movs r3, #0
	mov sl, r3
	strh r0, [r1]
	adds r2, #1
	ands r2, r5
	lsls r3, r2, #1
	add r3, ip
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xba
	ldrh r0, [r1]
	subs r0, #0x7f
	ldrb r3, [r3]
	adds r0, r0, r3
	strh r0, [r1]
	adds r2, #1
	ands r2, r5
	mov r0, r8
	str r2, [r0]
	lsls r2, r2, #1
	add r2, ip
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r6, r1
	adds r1, #0xbc
	ldrh r0, [r1]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r7]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xc8
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r7]
	muls r0, r4, r0
	adds r0, r6, r0
	adds r0, #0xc9
	mov r1, sl
	strb r1, [r0]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	mov r2, sp
	ldrb r2, [r2]
	ands r0, r2
	cmp r0, #7
	bls _080A7D52
	strb r1, [r7]
_080A7D52:
	mov r0, sl
	mov r3, sb
	strb r0, [r3]
_080A7D58:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7D68: .4byte 0x00000201
_080A7D6C: .4byte 0x0203B400
_080A7D70: .4byte 0x030046B8
_080A7D74: .4byte 0x000003FF

	thumb_func_start FUN_080a7d78
FUN_080a7d78: @ 0x080A7D78
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a7b80
	adds r0, r4, #0
	bl FUN_080a7c64
	ldr r0, _080A7DB8 @ =0x00000206
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080A7DB0
	ldr r0, [r4, #0x70]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x70]
	ldr r0, _080A7DBC @ =0x00000133
	bl PlaySound_082406e0
	ldr r1, _080A7DC0 @ =FUN_080a7dc4
	adds r0, r4, #0
	bl FUN_080a7b68
_080A7DB0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A7DB8: .4byte 0x00000206
_080A7DBC: .4byte 0x00000133
_080A7DC0: .4byte FUN_080a7dc4

	thumb_func_start FUN_080a7dc4
FUN_080a7dc4: @ 0x080A7DC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	bl FUN_080a7b80
	adds r0, r7, #0
	adds r0, #0x20
	bl FUN_08236400
	ldr r0, _080A7E28 @ =0x00000206
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080A7DF2
	b _080A7F2A
_080A7DF2:
	adds r0, r7, #0
	adds r0, #0x8a
	movs r1, #0
	ldrsh r6, [r0, r1]
	adds r5, r7, #0
	adds r5, #0x18
	ldrh r0, [r7, #0x18]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A7E22
	cmp r1, #0
	blt _080A7E22
	ldr r0, _080A7E2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A7E22
	ldr r0, _080A7E30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A7E34
_080A7E22:
	movs r4, #0
	b _080A7E42
	.align 2, 0
_080A7E28: .4byte 0x00000206
_080A7E2C: .4byte 0x030046A8
_080A7E30: .4byte 0x030046AC
_080A7E34:
	ldr r0, _080A7E54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A7E42:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A7E58
	adds r0, #4
	b _080A7E64
	.align 2, 0
_080A7E54: .4byte 0x030046A4
_080A7E58:
	ldr r0, _080A7E78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A7E64:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A7E7C
	cmp r2, #2
	beq _080A7E80
	b _080A7E84
	.align 2, 0
_080A7E78: .4byte 0x030046A4
_080A7E7C:
	ldrb r0, [r5, #4]
	b _080A7E82
_080A7E80:
	ldrb r0, [r5]
_080A7E82:
	subs r1, r1, r0
_080A7E84:
	cmp r6, r1
	bls _080A7F24
	ldr r6, _080A7F3C @ =0x0203B400
	ldr r0, _080A7F40 @ =0x030046B8
	mov sl, r0
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _080A7F44 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0xf
	mov sb, r1
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080A7F48 @ =0xFFFF0000
	ldr r3, [sp, #0xc]
	ands r3, r5
	orrs r3, r0
	str r3, [sp, #0xc]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	subs r1, #0x10
	lsls r1, r1, #0x10
	ldr r0, _080A7F4C @ =0x0000FFFF
	mov r8, r0
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r2, #1
	ands r2, r4
	mov r1, sl
	str r2, [r1]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r0, [r2]
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r5
	movs r2, #5
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r2
	str r0, [r1, #4]
	adds r2, r7, #0
	adds r2, #0x88
	str r1, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #4
	movs r1, #2
	add r3, sp, #0xc
	bl FUN_08014730
_080A7F24:
	adds r0, r7, #0
	bl KillEntity
_080A7F2A:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A7F3C: .4byte 0x0203B400
_080A7F40: .4byte 0x030046B8
_080A7F44: .4byte 0x000003FF
_080A7F48: .4byte 0xFFFF0000
_080A7F4C: .4byte 0x0000FFFF
_080A7F50:
	.byte 0x00, 0xB5, 0x82, 0x22, 0x92, 0x00, 0x81, 0x18, 0x09, 0x68, 0xA4, 0xF1, 0x83, 0xFF, 0x00, 0x20
	.byte 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080a7f64
FUN_080a7f64: @ 0x080A7F64
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x70
	bl FUN_0822dabc
	adds r4, #0xa0
	movs r5, #7
_080A7F72:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080A7F72
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a7f88
FUN_080a7f88: @ 0x080A7F88
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x1c
	adds r6, r0, #0
	mov sb, r2
	mov sl, r3
	movs r0, #0x20
	adds r0, r0, r6
	mov r8, r0
	ldr r4, _080A8024 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r3, #0x64
	orrs r0, r3
	ldr r2, _080A8028 @ =0x0000FFFF
	ands r0, r2
	movs r2, #0xc8
	lsls r2, r2, #0xf
	orrs r0, r2
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r5, #0
	str r5, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	movs r2, #0x84
	lsls r2, r2, #6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	mov r0, r8
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0x80
	lsls r3, r3, #7
	str r5, [sp]
	str r5, [sp, #4]
	mov r0, r8
	mov r1, sb
	movs r2, #0
	bl FUN_082364f8
	adds r0, r6, #0
	adds r0, #0x62
	mov r1, sl
	strb r1, [r0]
	mov r0, r8
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r6, #0x88
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A8024: .4byte 0xFFFF0000
_080A8028: .4byte 0x0000FFFF

	thumb_func_start FUN_080a802c
FUN_080a802c: @ 0x080A802C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x70
	ldr r0, _080A807C @ =0x00001C1A
	bl FUN_0822b10c
	adds r1, r0, #0
	adds r5, r6, #0
	adds r5, #0x98
	str r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #0xa
	bl FUN_0822dafc
	ldr r0, [r6, #0x18]
	ldr r1, [r6, #0x1c]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	ldrh r0, [r4, #0x1a]
	adds r0, #0xd7
	strh r0, [r4, #0x1a]
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A807C: .4byte 0x00001C1A

	thumb_func_start FUN_080a8080
FUN_080a8080: @ 0x080A8080
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	ldr r0, _080A8100 @ =0x00001C1E
	bl FUN_0822b10c
	mov r1, r8
	adds r1, #0x9c
	str r0, [r1]
	movs r6, #0
	adds r7, r1, #0
	mov sl, r6
	movs r0, #4
	rsbs r0, r0, #0
	mov sb, r0
_080A80A4:
	movs r0, #0x2c
	adds r5, r6, #0
	muls r5, r0, r5
	adds r4, r5, #0
	adds r4, #0xa0
	add r4, r8
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	ldr r1, [r7]
	adds r0, r4, #0
	movs r2, #8
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #2
	strb r0, [r4, #0xf]
	movs r0, #0xec
	strb r0, [r4, #0x10]
	add r5, r8
	adds r0, r5, #0
	adds r0, #0xc8
	mov r1, sl
	strb r1, [r0]
	adds r5, #0xc9
	strb r1, [r5]
	adds r6, #1
	cmp r6, #7
	ble _080A80A4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8100: .4byte 0x00001C1E

	thumb_func_start FUN_080a8104
FUN_080a8104: @ 0x080A8104
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x14]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	adds r0, r4, #0
	bl FUN_080a802c
	adds r0, r4, #0
	bl FUN_080a8080
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_080a7f88
	ldr r0, _080A815C @ =0x00000202
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r0, r4, r1
	mov r2, sp
	ldrh r2, [r2, #0x18]
	strh r2, [r0]
	movs r0, #0xe6
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r1, _080A8160 @ =FUN_080a7d78
	adds r0, r4, #0
	bl FUN_080a7b68
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A815C: .4byte 0x00000202
_080A8160: .4byte FUN_080a7d78

	thumb_func_start FUN_080a8164
FUN_080a8164: @ 0x080A8164
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0x83
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A81B4
	ldr r1, _080A81AC @ =0x080A7F51
	ldr r2, _080A81B0 @ =FUN_080a7f64
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_080a8104
	cmp r0, #0
	bge _080A81B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A81B6
	.align 2, 0
_080A81AC: .4byte 0x080A7F51
_080A81B0: .4byte FUN_080a7f64
_080A81B4:
	adds r0, r4, #0
_080A81B6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a81c4
FUN_080a81c4: @ 0x080A81C4
	ldr r0, [r0, #0x78]
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	bx lr

	thumb_func_start FUN_080a81d4
FUN_080a81d4: @ 0x080A81D4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r3, _080A81F8 @ =0x030046A0
	ldr r1, [r3]
	adds r2, r1, #0
	adds r2, #0x40
	ldrh r5, [r2]
	movs r6, #0
	ldrsh r0, [r2, r6]
	cmp r0, #0x62
	bgt _080A81F2
	ldr r1, [r1, #0x50]
	ldr r0, [r4, #0x74]
	cmp r1, r0
	bhs _080A81FC
_080A81F2:
	movs r0, #0
	b _080A821C
	.align 2, 0
_080A81F8: .4byte 0x030046A0
_080A81FC:
	adds r0, r5, #1
	strh r0, [r2]
	ldr r1, [r3]
	adds r1, #0x42
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r0, [r3]
	adds r0, #0x40
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	bl FUN_080a81c4
	str r0, [r4, #0x74]
	movs r0, #1
_080A821C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a8224
FUN_080a8224: @ 0x080A8224
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
_080A822A:
	lsls r1, r5, #1
	adds r0, r6, #0
	adds r0, #0x68
	adds r0, r0, r1
	ldrh r4, [r0]
	adds r0, r5, #0
	bl FUN_0807a8c0
	cmp r4, r0
	beq _080A8242
	movs r0, #1
	b _080A824A
_080A8242:
	adds r5, #1
	cmp r5, #4
	ble _080A822A
	movs r0, #0
_080A824A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a8250
FUN_080a8250: @ 0x080A8250
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldr r1, _080A8304 @ =0x0203B400
	mov sb, r1
	ldr r1, _080A8308 @ =0x030046B8
	mov ip, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r1, _080A830C @ =0x000003FF
	mov r8, r1
	ands r2, r1
	lsls r1, r2, #1
	add r1, sb
	ldrh r6, [r1]
	asrs r6, r6, #3
	movs r5, #0x7f
	ands r6, r5
	subs r6, #0x3f
	movs r1, #0
	mov sl, r1
	strh r6, [r0, #0x28]
	adds r2, #1
	mov r1, r8
	ands r2, r1
	lsls r1, r2, #1
	add r1, sb
	ldrh r4, [r1]
	asrs r4, r4, #3
	movs r1, #0x3f
	ands r4, r1
	adds r4, #0x40
	strh r4, [r0, #0x2a]
	adds r2, #1
	mov r1, r8
	ands r2, r1
	mov r1, ip
	str r2, [r1]
	lsls r1, r2, #1
	add r1, sb
	ldrh r3, [r1]
	asrs r3, r3, #3
	ands r3, r5
	subs r3, #0x3f
	strh r3, [r0, #0x2c]
	ldr r1, _080A8310 @ =0x03002BE0
	ldr r5, [r1]
	ldrh r1, [r5, #0x2c]
	adds r1, r1, r6
	strh r1, [r0, #0x18]
	ldrh r1, [r5, #0x2e]
	adds r1, r1, r4
	strh r1, [r0, #0x1a]
	ldrh r1, [r5, #0x30]
	adds r1, r1, r3
	strh r1, [r0, #0x1c]
	mov r1, sl
	strh r1, [r0, #0x30]
	adds r2, #1
	mov r1, r8
	ands r2, r1
	mov r1, ip
	str r2, [r1]
	lsls r2, r2, #1
	add r2, sb
	ldrh r1, [r2]
	movs r2, #7
	ands r1, r2
	adds r1, #0xc
	strh r1, [r0, #0x32]
	mov r1, sl
	strh r1, [r0, #0x34]
	strh r1, [r0, #0x3a]
	movs r1, #1
	strh r1, [r0, #0x38]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A8304: .4byte 0x0203B400
_080A8308: .4byte 0x030046B8
_080A830C: .4byte 0x000003FF
_080A8310: .4byte 0x03002BE0

	thumb_func_start FUN_080a8314
FUN_080a8314: @ 0x080A8314
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldrh r0, [r3, #0x3a]
	adds r4, r0, #1
	strh r4, [r3, #0x3a]
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A8336
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r0, #0
	strh r0, [r3, #0x38]
	b _080A837E
_080A8336:
	ldrh r1, [r3, #0x32]
	ldrh r0, [r3, #0x2a]
	adds r1, r1, r0
	strh r1, [r3, #0x2a]
	ldr r0, _080A8370 @ =0x03002BE0
	ldr r2, [r0]
	ldrh r0, [r3, #0x28]
	ldrh r6, [r2, #0x2c]
	adds r0, r0, r6
	strh r0, [r3, #0x18]
	ldrh r0, [r2, #0x2e]
	adds r0, r0, r1
	strh r0, [r3, #0x1a]
	ldrh r0, [r3, #0x2c]
	ldrh r2, [r2, #0x30]
	adds r0, r0, r2
	strh r0, [r3, #0x1c]
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A8374
	adds r0, r3, #0
	adds r1, r5, #0
	movs r2, #3
	bl FUN_0822dafc
	b _080A837E
	.align 2, 0
_080A8370: .4byte 0x03002BE0
_080A8374:
	adds r0, r3, #0
	adds r1, r5, #0
	movs r2, #2
	bl FUN_0822dafc
_080A837E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a8384
FUN_080a8384: @ 0x080A8384
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x18]
	movs r2, #0
	strh r2, [r4, #0x28]
	ldr r0, _080A83D8 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
	ldrh r0, [r4, #0x36]
	adds r0, #0xfa
	strh r0, [r4, #0x36]
	adds r0, r4, #0
	adds r0, #0x64
	strh r2, [r0]
	subs r0, #2
	movs r1, #1
	strh r1, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r5, r4, #0
	adds r5, #0x80
	movs r6, #7
_080A83BE:
	ldr r1, [r4, #0x7c]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r5, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _080A83BE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A83D8: .4byte 0x03002BE0

	thumb_func_start FUN_080a83dc
FUN_080a83dc: @ 0x080A83DC
	adds r3, r0, #0
	ldr r0, [r3, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x18]
	movs r0, #3
	movs r2, #0
	strh r0, [r3, #0x28]
	ldr r0, _080A8418 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	ldrh r0, [r3, #0x36]
	adds r0, #0xfa
	strh r0, [r3, #0x36]
	adds r0, r3, #0
	adds r0, #0x64
	strh r2, [r0]
	adds r1, r3, #0
	adds r1, #0x62
	movs r0, #1
	strh r0, [r1]
	subs r1, #2
	movs r0, #2
	strh r0, [r1]
	bx lr
	.align 2, 0
_080A8418: .4byte 0x03002BE0

	thumb_func_start FUN_080a841c
FUN_080a841c: @ 0x080A841C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r5, r7, #0
	adds r5, #0x62
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A8430
	b _080A85E6
_080A8430:
	adds r4, r7, #0
	adds r4, #0x60
	ldrh r3, [r4]
	mov r8, r4
	cmp r3, #1
	bne _080A84F8
	adds r6, r7, #0
	adds r6, #0x64
	adds r4, #0x20
	movs r5, #7
_080A8444:
	ldrh r0, [r4, #0x38]
	cmp r0, #0
	beq _080A8452
	ldr r1, [r7, #0x7c]
	adds r0, r4, #0
	bl FUN_080a8314
_080A8452:
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080A8444
	ldrh r2, [r6]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x3f
	bhi _080A8480
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A8480
	lsrs r1, r1, #0x12
	movs r0, #7
	ands r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x80
	adds r0, r7, r0
	bl FUN_080a8250
_080A8480:
	ldrh r0, [r6]
	adds r0, #1
	movs r2, #0
	strh r0, [r6]
	ldr r0, _080A84B4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r0, [r6]
	cmp r0, #0x77
	bhi _080A84B8
	adds r0, r7, #0
	adds r0, #0x18
	strh r2, [r0, #0x10]
	ldrh r0, [r6]
	cmp r0, #4
	bhi _080A8538
	ldrh r0, [r7, #0x36]
	adds r0, #0xfa
	ldrh r2, [r6]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #1
	b _080A858C
	.align 2, 0
_080A84B4: .4byte 0x03002BE0
_080A84B8:
	cmp r0, #0x7a
	bhi _080A84CE
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r7, #0x36]
	adds r0, r0, r1
	strh r0, [r7, #0x36]
	movs r0, #1
	strh r0, [r7, #0x28]
	b _080A85E6
_080A84CE:
	cmp r0, #0x7d
	bhi _080A84E4
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r7, #0x36]
	adds r0, r0, r1
	strh r0, [r7, #0x36]
	movs r0, #2
	strh r0, [r7, #0x28]
	b _080A85E6
_080A84E4:
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	adds r0, r7, #0
	adds r0, #0x62
	strh r2, [r0]
	mov r0, r8
	strh r2, [r0]
	b _080A85E6
_080A84F8:
	cmp r3, #2
	bne _080A85D8
	adds r2, r7, #0
	adds r2, #0x64
	ldrh r0, [r2]
	adds r0, #1
	movs r6, #0
	strh r0, [r2]
	ldr r0, _080A8534 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	ldrh r0, [r2]
	cmp r0, #0x77
	bhi _080A85A0
	movs r0, #3
	strh r0, [r7, #0x28]
	ldrh r0, [r2]
	cmp r0, #4
	bhi _080A8538
	ldrh r0, [r7, #0x36]
	adds r0, #0xfa
	ldrh r2, [r2]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #1
	b _080A858C
	.align 2, 0
_080A8534: .4byte 0x03002BE0
_080A8538:
	cmp r0, #0x13
	bhi _080A8584
	ldr r5, _080A8594 @ =0x0203B400
	ldr r6, _080A8598 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r3, _080A859C @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrh r0, [r7, #0x34]
	subs r0, #0xf
	movs r4, #0x1f
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r7, #0x34]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r2, [r0]
	ldrh r0, [r7, #0x36]
	subs r0, #0xf
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r7, #0x36]
	adds r1, #1
	ands r1, r3
	str r1, [r6]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldrh r0, [r7, #0x38]
	subs r0, #0xf
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r7, #0x38]
_080A8584:
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r7, #0x36]
_080A858C:
	adds r0, r0, r1
	strh r0, [r7, #0x36]
	b _080A85E6
	.align 2, 0
_080A8594: .4byte 0x0203B400
_080A8598: .4byte 0x030046B8
_080A859C: .4byte 0x000003FF
_080A85A0:
	cmp r0, #0x7a
	bhi _080A85B6
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r7, #0x36]
	adds r0, r0, r1
	strh r0, [r7, #0x36]
	movs r0, #4
	strh r0, [r7, #0x28]
	b _080A85E6
_080A85B6:
	cmp r0, #0x7d
	bhi _080A85CA
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r1, [r7, #0x36]
	adds r0, r0, r1
	strh r0, [r7, #0x36]
	strh r3, [r7, #0x28]
	b _080A85E6
_080A85CA:
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	strh r6, [r5]
	strh r6, [r4]
	b _080A85E6
_080A85D8:
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	movs r0, #0
	strh r0, [r5]
	strh r0, [r4]
_080A85E6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a85f0
FUN_080a85f0: @ 0x080A85F0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A8638 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _080A8690
	ldr r0, [r0, #0x1c]
	cmp r0, #4
	bne _080A863C
	adds r2, r4, #0
	adds r2, #0x62
	ldrh r1, [r2]
	cmp r1, #1
	bne _080A8690
	ldr r0, [r4, #0x18]
	orrs r0, r1
	str r0, [r4, #0x18]
	movs r0, #0
	strh r0, [r2]
	movs r6, #1
	movs r5, #0
	adds r2, #0x56
	adds r1, r4, #0
	adds r1, #0x80
	movs r3, #7
_080A8622:
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	strh r5, [r2]
	adds r2, #0x3c
	adds r1, #0x3c
	subs r3, #1
	cmp r3, #0
	bge _080A8622
	b _080A8690
	.align 2, 0
_080A8638: .4byte 0x03002BE0
_080A863C:
	adds r0, r4, #0
	bl FUN_080a841c
	adds r0, r4, #0
	bl FUN_080a81d4
	cmp r0, #0
	beq _080A865C
	adds r0, r4, #0
	bl FUN_080a8384
	movs r0, #0xe2
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080A867C
_080A865C:
	adds r0, r4, #0
	adds r0, #0x60
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A867C
	adds r0, r4, #0
	bl FUN_080a8224
	cmp r0, #0
	beq _080A867C
	adds r0, r4, #0
	bl FUN_080a83dc
	ldr r0, _080A8698 @ =0x00000381
	bl PlaySound_082406e0
_080A867C:
	movs r5, #0
	adds r4, #0x68
_080A8680:
	adds r0, r5, #0
	bl FUN_0807a8c0
	strh r0, [r4]
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble _080A8680
_080A8690:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A8698: .4byte 0x00000381

	thumb_func_start FUN_080a869c
FUN_080a869c: @ 0x080A869C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl FUN_0822a4e0
	adds r4, #0x80
	movs r5, #7
_080A86AA:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080A86AA
	movs r1, #0
	ldr r0, _080A86C8 @ =0x03000154
	str r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A86C8: .4byte 0x03000154

	thumb_func_start FUN_080a86cc
FUN_080a86cc: @ 0x080A86CC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x44
	ldr r1, _080A8700 @ =0x00001C1D
	adds r0, r4, #0
	bl FUN_0822b16c
	adds r0, r5, #0
	adds r0, #0x18
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822b20c
	ldr r0, [r5, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x18]
	strb r1, [r5, #0x1f]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A8700: .4byte 0x00001C1D

	thumb_func_start FUN_080a8704
FUN_080a8704: @ 0x080A8704
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _080A8750 @ =0x00001C1E
	bl FUN_0822b10c
	str r0, [r5, #0x7c]
	movs r7, #4
	rsbs r7, r7, #0
	adds r4, r5, #0
	adds r4, #0x80
	movs r6, #7
_080A871A:
	ldr r1, [r5, #0x7c]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	ldr r1, [r5, #0x7c]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	adds r4, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _080A871A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8750: .4byte 0x00001C1E

	thumb_func_start FUN_080a8754
FUN_080a8754: @ 0x080A8754
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080A8768
	bl FUN_0823172c
	str r0, [r6, #0x78]
_080A8768:
	ldr r0, _080A87B0 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0x62
	bgt _080A8782
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_080a81c4
	str r0, [r6, #0x74]
_080A8782:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x68
_080A8788:
	adds r0, r5, #0
	bl FUN_0807a8c0
	strh r0, [r4]
	adds r4, #2
	adds r5, #1
	cmp r5, #4
	ble _080A8788
	adds r0, r6, #0
	bl FUN_080a86cc
	adds r0, r6, #0
	bl FUN_080a8704
	ldr r0, _080A87B4 @ =0x03000154
	str r6, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A87B0: .4byte 0x030046A0
_080A87B4: .4byte 0x03000154

	thumb_func_start FUN_080a87b8
FUN_080a87b8: @ 0x080A87B8
	push {r4, lr}
	ldr r0, _080A87F0 @ =0x03000154
	ldr r0, [r0]
	cmp r0, #0
	bne _080A87FE
	movs r1, #0x98
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A87FC
	ldr r1, _080A87F4 @ =FUN_080a85f0
	ldr r2, _080A87F8 @ =FUN_080a869c
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080a8754
	cmp r0, #0
	bge _080A87FC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A87FE
	.align 2, 0
_080A87F0: .4byte 0x03000154
_080A87F4: .4byte FUN_080a85f0
_080A87F8: .4byte FUN_080a869c
_080A87FC:
	adds r0, r4, #0
_080A87FE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a8804
FUN_080a8804: @ 0x080A8804
	adds r2, r0, #0
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r2, r3
	str r1, [r0]
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a881c
FUN_080a881c: @ 0x080A881C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080A8870
	adds r4, r5, #0
	adds r4, #0x6c
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r6, r5, r1
_080A8848:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	ldr r1, _080A886C @ =FUN_080a8950
	bl FUN_080a8804
	adds r4, #0x2c
	cmp r4, r6
	ble _080A8848
	ldr r0, [r5, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x1c]
	b _080A8940
	.align 2, 0
_080A886C: .4byte FUN_080a8950
_080A8870:
	ldrh r1, [r1]
	movs r0, #0x20
	subs r6, r0, r1
	adds r2, r6, #1
	str r2, [sp]
	adds r0, r5, #0
	adds r0, #0x64
	str r0, [sp, #4]
	movs r1, #0x66
	adds r1, r1, r5
	mov sl, r1
	movs r2, #0x68
	adds r2, r2, r5
	mov sb, r2
	ldr r0, _080A88C8 @ =0x085B0A08
	mov r8, r0
	adds r4, r5, #0
	adds r4, #0x6c
	movs r7, #7
_080A8896:
	ldrh r0, [r4, #0x28]
	adds r0, #4
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0x2a]
	muls r0, r6, r0
	ldr r1, [sp]
	bl Div
	strh r0, [r4, #0x2a]
	ldrh r2, [r4, #0x2a]
	ldrh r0, [r4, #0x28]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A88CC
	asrs r2, r0, #0xc
	b _080A88D2
	.align 2, 0
_080A88C8: .4byte 0x085B0A08
_080A88CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A88D2:
	ldr r1, [sp, #4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r4, #0x18]
	movs r2, #0xed
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0x1e
	subs r1, r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	mov r1, sl
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r2, [r4, #0x2a]
	ldrh r1, [r4, #0x28]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A890E
	asrs r2, r0, #0xc
	b _080A8914
_080A890E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A8914:
	mov r1, sb
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	movs r2, #0xed
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #8
	bne _080A8938
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #6
	bl FUN_0822dafc
_080A8938:
	adds r4, #0x2c
	subs r7, #1
	cmp r7, #0
	bge _080A8896
_080A8940:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a8950
FUN_080a8950: @ 0x080A8950
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080A897C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A898E
	ldr r0, [r6, #0x18]
	ldr r1, [r0, #0x18]
	ldr r0, _080A8980 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080A8984
	movs r0, #0
	b _080A898A
	.align 2, 0
_080A897C: .4byte 0x030047A4
_080A8980: .4byte 0x03002C68
_080A8984:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080A898A:
	adds r7, r0, #0
	b _080A899A
_080A898E:
	ldr r0, _080A89B8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A89BC @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r7, [r0, r2]
_080A899A:
	movs r3, #0xea
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	cmp r1, #0
	beq _080A89D8
	subs r3, #4
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A89C0
	subs r0, r1, #1
	strh r0, [r2]
	b _080A89D8
	.align 2, 0
_080A89B8: .4byte 0x030046A0
_080A89BC: .4byte 0x00000942
_080A89C0:
	cmp r7, #0
	ble _080A89C8
	subs r0, r1, #1
	strh r0, [r2]
_080A89C8:
	movs r0, #0xeb
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A89D8
	subs r0, #1
	strh r0, [r1]
_080A89D8:
	adds r0, r6, #0
	adds r0, #0x64
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r0
	cmp r2, #0
	blt _080A8A02
	cmp r1, #0
	blt _080A8A02
	ldr r0, _080A8A08 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A8A02
	ldr r0, _080A8A0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A8A10
_080A8A02:
	movs r4, #0
	b _080A8A1E
	.align 2, 0
_080A8A08: .4byte 0x030046A8
_080A8A0C: .4byte 0x030046AC
_080A8A10:
	ldr r0, _080A8A30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A8A1E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A8A34
	adds r0, #4
	b _080A8A40
	.align 2, 0
_080A8A30: .4byte 0x030046A4
_080A8A34:
	ldr r0, _080A8A54 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A8A40:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080A8A5C
	ldr r1, _080A8A58 @ =FUN_080a8cfc
	adds r0, r6, #0
	bl FUN_080a8804
	b _080A8B14
	.align 2, 0
_080A8A54: .4byte 0x030046A4
_080A8A58: .4byte FUN_080a8cfc
_080A8A5C:
	mov r5, sb
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A8A82
	cmp r1, #0
	blt _080A8A82
	ldr r0, _080A8A88 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A8A82
	ldr r0, _080A8A8C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A8A90
_080A8A82:
	movs r4, #0
	b _080A8A9E
	.align 2, 0
_080A8A88: .4byte 0x030046A8
_080A8A8C: .4byte 0x030046AC
_080A8A90:
	ldr r0, _080A8AB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A8A9E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A8AB4
	adds r0, #4
	b _080A8AC0
	.align 2, 0
_080A8AB0: .4byte 0x030046A4
_080A8AB4:
	ldr r0, _080A8AD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A8AC0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A8AD8
	cmp r2, #2
	beq _080A8ADC
	b _080A8AE0
	.align 2, 0
_080A8AD4: .4byte 0x030046A4
_080A8AD8:
	ldrb r0, [r5, #4]
	b _080A8ADE
_080A8ADC:
	ldrb r0, [r5]
_080A8ADE:
	subs r1, r1, r0
_080A8AE0:
	adds r2, r6, #0
	adds r2, #0x66
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble _080A8AF8
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	b _080A8B14
_080A8AF8:
	cmp r1, r0
	bge _080A8B14
	ldrh r0, [r2]
	subs r0, #0x1e
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r1
	bge _080A8B0C
	strh r1, [r2]
_080A8B0C:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
_080A8B14:
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r3, #0xe9
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r1]
	ldrh r3, [r2]
	cmp r0, r3
	bhs _080A8B38
	movs r1, #0xed
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, #0x14
	b _080A8B60
_080A8B38:
	ldrh r1, [r1]
	ldrh r0, [r2]
	lsls r0, r0, #1
	cmp r1, r0
	bge _080A8B52
	movs r2, #0xed
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, #0x10
	b _080A8B60
_080A8B52:
	movs r3, #0xed
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, #0xc
_080A8B60:
	strh r0, [r6, #0x2c]
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A8B7C
	b _080A8CC8
_080A8B7C:
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A8B8C
	movs r3, #0x7d
	b _080A8BCE
_080A8B8C:
	ldr r0, _080A8BB4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A8BBC
	ldr r0, [r6, #0x18]
	ldr r1, _080A8BB8 @ =0x0000035E
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #1
	adds r1, r1, r0
	mov r8, r1
	b _080A8BD0
	.align 2, 0
_080A8BB4: .4byte 0x030047A4
_080A8BB8: .4byte 0x0000035E
_080A8BBC:
	ldr r0, [r6, #0x18]
	ldr r2, _080A8C24 @ =0x0000035E
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xa
	bl Div
	adds r3, r0, #0
	muls r3, r7, r3
_080A8BCE:
	mov r8, r3
_080A8BD0:
	movs r5, #0
	movs r0, #0x68
	adds r0, r0, r6
	mov sl, r0
	add r4, sp, #0x10
	ldr r7, _080A8C28 @ =0xFFFF0000
_080A8BDC:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r1, [sp, #0x10]
	asrs r0, r1, #0x10
	adds r0, #0x80
	lsls r0, r0, #0x10
	ldr r2, _080A8C2C @ =0x0000FFFF
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x10]
	ldrh r1, [r4]
	adds r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldrh r0, [r4, #4]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [r4, #4]
	ands r2, r7
	orrs r2, r0
	str r2, [r4, #4]
	cmp r5, #2
	beq _080A8C40
	cmp r5, #2
	bgt _080A8C30
	cmp r5, #1
	beq _080A8C3A
	b _080A8C68
	.align 2, 0
_080A8C24: .4byte 0x0000035E
_080A8C28: .4byte 0xFFFF0000
_080A8C2C: .4byte 0x0000FFFF
_080A8C30:
	cmp r5, #3
	beq _080A8C46
	cmp r5, #4
	beq _080A8C58
	b _080A8C68
_080A8C3A:
	ldrh r1, [r4]
	adds r1, #0x60
	b _080A8C5C
_080A8C40:
	ldrh r1, [r4, #4]
	adds r1, #0x60
	b _080A8C4A
_080A8C46:
	ldrh r1, [r4, #4]
	subs r1, #0x60
_080A8C4A:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	ands r0, r2
	orrs r0, r1
	str r0, [r4, #4]
	b _080A8C68
_080A8C58:
	ldrh r1, [r4]
	subs r1, #0x60
_080A8C5C:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x10]
_080A8C68:
	ldr r0, _080A8CBC @ =0x00241004
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	lsls r0, r5, #2
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	mov r2, r8
	movs r3, #0x32
	bl FUN_080d85d8
	adds r5, #1
	cmp r5, #4
	ble _080A8BDC
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r3, sl
	movs r2, #0
	ldrsh r1, [r3, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #1
	str r3, [sp]
	ldr r3, _080A8CC0 @ =0x0000B546
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	ldr r1, [r6, #0x18]
	ldr r3, _080A8CC4 @ =0x000003FB
	adds r1, r1, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl KillEntity
	b _080A8CE6
	.align 2, 0
_080A8CBC: .4byte 0x00241004
_080A8CC0: .4byte 0x0000B546
_080A8CC4: .4byte 0x000003FB
_080A8CC8:
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A8CE6
	ldr r1, [r6, #0x18]
	ldr r2, _080A8CF8 @ =0x000003FB
	adds r1, r1, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl KillEntity
_080A8CE6:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8CF8: .4byte 0x000003FB

	thumb_func_start FUN_080a8cfc
FUN_080a8cfc: @ 0x080A8CFC
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x66
	ldrh r0, [r1]
	subs r0, #0x14
	strh r0, [r1]
	ldr r0, [r2, #0x64]
	ldr r1, [r2, #0x68]
	str r0, [r2, #0x38]
	str r1, [r2, #0x3c]
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080A8D38
	ldr r1, [r2, #0x18]
	ldr r0, _080A8D3C @ =0x000003FB
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl KillEntity
_080A8D38:
	pop {r0}
	bx r0
	.align 2, 0
_080A8D3C: .4byte 0x000003FB
_080A8D40:
	.byte 0x00, 0xB5, 0xEE, 0x22, 0x52, 0x00, 0x81, 0x18, 0x09, 0x68, 0xA4, 0xF1, 0x8B, 0xF8, 0x00, 0x20
	.byte 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080a8d54
FUN_080a8d54: @ 0x080A8D54
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl FUN_0822a4e0
	adds r4, #0x6c
	movs r5, #7
_080A8D62:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080A8D62
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a8d78
FUN_080a8d78: @ 0x080A8D78
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x48
	ldr r1, _080A8DC4 @ =0x0000E74B
	adds r0, r6, #0
	bl FUN_0822b16c
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #0xc
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x68]
	str r0, [r5, #0x38]
	str r1, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x38
	movs r1, #0x80
	bl FUN_082342cc
	cmp r0, #0
	beq _080A8DC8
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r6, #0
	bl FUN_0822b20c
	adds r1, r5, #0
	adds r1, #0x23
	movs r0, #1
	b _080A8DCE
	.align 2, 0
_080A8DC4: .4byte 0x0000E74B
_080A8DC8:
	adds r1, r5, #0
	adds r1, #0x23
	movs r0, #2
_080A8DCE:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a8dd8
FUN_080a8dd8: @ 0x080A8DD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r6, _080A8EBC @ =0x0203B400
	ldr r4, _080A8EC0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080A8EC4 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, _080A8EC8 @ =0x00001C1E
	bl FUN_0822b10c
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	movs r0, #0
	mov r8, r0
	adds r1, r2, #0
	adds r1, r1, r7
	mov sb, r1
	mov sl, r5
	ldr r6, _080A8ECC @ =0x085B0A08
_080A8E18:
	movs r0, #0x2c
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x6c
	adds r5, r7, r0
	mov r2, sb
	ldr r1, [r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	mov r0, sb
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #7
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r1, _080A8EC0 @ =0x030046B8
	ldr r2, [r1]
	adds r2, #1
	mov r0, sl
	ands r2, r0
	lsls r0, r2, #1
	ldr r1, _080A8EBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	adds r4, r7, r4
	mov r1, r8
	lsls r0, r1, #5
	ldr r1, [sp]
	adds r0, r1, r0
	movs r1, #0xf
	ands r3, r1
	adds r0, r0, r3
	movs r1, #0xff
	ands r0, r1
	adds r3, r4, #0
	adds r3, #0x94
	strh r0, [r3]
	adds r2, #1
	mov r0, sl
	ands r2, r0
	ldr r1, _080A8EC0 @ =0x030046B8
	str r2, [r1]
	lsls r2, r2, #1
	ldr r0, _080A8EBC @ =0x0203B400
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r2, _080A8ED0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r4, #0x96
	strh r1, [r4]
	ldrh r2, [r4]
	ldrh r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A8ED4
	asrs r2, r0, #0xc
	b _080A8EDA
	.align 2, 0
_080A8EBC: .4byte 0x0203B400
_080A8EC0: .4byte 0x030046B8
_080A8EC4: .4byte 0x000003FF
_080A8EC8: .4byte 0x00001C1E
_080A8ECC: .4byte 0x085B0A08
_080A8ED0: .4byte 0x000001FF
_080A8ED4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A8EDA:
	adds r0, r7, #0
	adds r0, #0x64
	ldrh r0, [r0]
	adds r0, r0, r2
	strh r0, [r5, #0x18]
	adds r1, r7, #0
	adds r1, #0x66
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x1a]
	movs r0, #0x2c
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r7, r0
	adds r1, r0, #0
	adds r1, #0x96
	ldrh r1, [r1]
	adds r0, #0x94
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A8F1A
	asrs r1, r0, #0xc
	b _080A8F20
_080A8F1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A8F20:
	adds r0, r7, #0
	adds r0, #0x68
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0xec
	strb r0, [r5, #0x10]
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #7
	bgt _080A8F3E
	b _080A8E18
_080A8F3E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a8f50
FUN_080a8f50: @ 0x080A8F50
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r2]
	ldr r5, [r2, #4]
	str r4, [r6, #0x64]
	str r5, [r6, #0x68]
	str r1, [r6, #0x18]
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r4, r6, r0
	strh r3, [r4]
	adds r0, r6, #0
	bl FUN_080a8d78
	adds r0, r6, #0
	bl FUN_080a8dd8
	ldr r1, [r6, #0x18]
	ldr r2, _080A8F90 @ =0x000003FB
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrh r0, [r4]
	cmp r0, #0
	beq _080A8F94
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x78
	b _080A8FB8
	.align 2, 0
_080A8F90: .4byte 0x000003FB
_080A8F94:
	ldr r0, _080A8FAC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A8FB0
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x5a
	b _080A8FB8
	.align 2, 0
_080A8FAC: .4byte 0x030047A4
_080A8FB0:
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0xb4
_080A8FB8:
	strh r0, [r1]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Div
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xeb
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, #0x15
	bl PlaySound_082406e0
	ldr r1, _080A8FF4 @ =FUN_080a881c
	adds r0, r6, #0
	bl FUN_080a8804
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A8FF4: .4byte FUN_080a881c

	thumb_func_start FUN_080a8ff8
FUN_080a8ff8: @ 0x080A8FF8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A903C
	ldr r1, _080A9034 @ =0x080A8D41
	ldr r2, _080A9038 @ =FUN_080a8d54
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_080a8f50
	cmp r0, #0
	bge _080A903C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A903E
	.align 2, 0
_080A9034: .4byte 0x080A8D41
_080A9038: .4byte FUN_080a8d54
_080A903C:
	adds r0, r4, #0
_080A903E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a9044
FUN_080a9044: @ 0x080A9044
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	movs r1, #0xff
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_080a9058
FUN_080a9058: @ 0x080A9058
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	movs r1, #0xff
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0xb
	bhi _080A907C
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08236400
_080A907C:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r2, r2, r5
	mov r8, r2
	movs r7, #0
	adds r6, r5, #0
	adds r6, #0x74
	adds r4, r5, #0
	adds r4, #0x8c
	movs r0, #7
	mov sb, r0
_080A9092:
	mov r1, r8
	ldrh r0, [r1]
	ldrb r2, [r4, #0x15]
	cmp r0, r2
	blo _080A90AC
	adds r0, r5, #0
	adds r0, #0x74
	adds r0, r0, r7
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080A9170
_080A90AC:
	movs r0, #1
	mov sl, r0
	ldrb r0, [r4, #0x14]
	ldrb r1, [r4, #0x10]
	adds r0, r0, r1
	strb r0, [r4, #0x10]
	ldrh r3, [r4, #0x16]
	ldr r2, _080A90D8 @ =0x085B0A08
	ldrb r0, [r4, #0x10]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080A90DC
	asrs r3, r0, #0xc
	b _080A90E2
	.align 2, 0
_080A90D8: .4byte 0x085B0A08
_080A90DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080A90E2:
	ldrh r0, [r5, #0x1c]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r1, [r4, #0x16]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A90FE
	asrs r1, r0, #0xc
	b _080A9104
_080A90FE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A9104:
	ldrh r0, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #4]
	mov r0, r8
	ldrh r1, [r0]
	ldrb r2, [r4, #0x12]
	cmp r1, r2
	blo _080A912E
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080A9126
	ldrb r0, [r4, #0x14]
	cmp r0, #2
	bls _080A9126
	subs r0, #1
	strb r0, [r4, #0x14]
_080A9126:
	ldrh r0, [r4, #2]
	ldrb r1, [r4, #0x11]
	adds r0, r0, r1
	strh r0, [r4, #2]
_080A912E:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A9146
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #0xc
	bl FUN_0822dafc
	b _080A915E
_080A9146:
	cmp r0, #4
	bne _080A915E
	adds r0, r7, #0
	adds r0, #0x74
	adds r0, r5, r0
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0xd
	bl FUN_0822dafc
_080A915E:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080A9170
	strb r1, [r4, #0x13]
_080A9170:
	adds r7, #0x30
	adds r6, #0x30
	adds r4, #0x30
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _080A9092
	movs r2, #0xff
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	mov r0, sl
	cmp r0, #0
	bne _080A919A
	adds r0, r5, #0
	bl KillEntity
_080A919A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080A91A8:
	.byte 0x00, 0xB5, 0x80, 0x22, 0x92, 0x00, 0x81, 0x18
	.byte 0x09, 0x68, 0xA3, 0xF1, 0x57, 0xFE, 0x00, 0x20, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080a91bc
FUN_080a91bc: @ 0x080A91BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x74
	movs r5, #7
_080A91C4:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080A91C4
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a91dc
FUN_080a91dc: @ 0x080A91DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r6, _080A92C4 @ =0x0203B400
	ldr r4, _080A92C8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080A92CC @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, _080A92D0 @ =0x00001C1E
	bl FUN_0822b10c
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	movs r3, #0
	mov sb, r3
	adds r6, r4, #0
	mov r8, r5
	movs r0, #0xf
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0x84
	adds r5, r7, #0
	adds r5, #0x74
_080A9222:
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r2, [r6]
	adds r2, #1
	mov r3, r8
	ands r2, r3
	lsls r0, r2, #1
	ldr r1, _080A92C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, sb
	lsls r0, r3, #5
	ldr r3, [sp]
	adds r0, r3, r0
	mov r3, sl
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r4, #0x18]
	movs r1, #3
	mov r0, sb
	ands r0, r1
	lsls r0, r0, #1
	adds r0, #3
	strb r0, [r4, #0x19]
	adds r2, #1
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	ldr r1, _080A92C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x40
	strh r0, [r4, #0x1e]
	adds r2, #1
	mov r3, r8
	ands r2, r3
	str r2, [r6]
	lsls r2, r2, #1
	ldr r0, _080A92C4 @ =0x0203B400
	adds r2, r2, r0
	ldrh r0, [r2]
	mov r1, sl
	ands r0, r1
	adds r0, #0xc
	strb r0, [r4, #0x1a]
	movs r0, #7
	strb r0, [r4, #0x1c]
	ldrh r2, [r4, #0x1e]
	ldrb r0, [r4, #0x18]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _080A92D4 @ =0x085B0A08
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A92D8
	asrs r2, r0, #0xc
	b _080A92DE
	.align 2, 0
_080A92C4: .4byte 0x0203B400
_080A92C8: .4byte 0x030046B8
_080A92CC: .4byte 0x000003FF
_080A92D0: .4byte 0x00001C1E
_080A92D4: .4byte 0x085B0A08
_080A92D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A92DE:
	ldrh r0, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #8]
	ldrh r0, [r7, #0x1e]
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #0x1e]
	ldrb r0, [r4, #0x18]
	lsls r0, r0, #1
	ldr r2, _080A9300 @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A9304
	asrs r1, r0, #0xc
	b _080A930A
	.align 2, 0
_080A9300: .4byte 0x085B0A08
_080A9304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A930A:
	ldrh r0, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0xc]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0xec
	strb r0, [r4]
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _080A9348 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	strb r1, [r4, #0x1b]
	cmp r1, #3
	bhi _080A934C
	movs r3, #0xfa
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0xc
	bl FUN_0822dafc
	b _080A935C
	.align 2, 0
_080A9348: .4byte 0x0203B400
_080A934C:
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0xd
	bl FUN_0822dafc
_080A935C:
	ldr r0, [r6]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _080A9398 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r1, sl
	ands r0, r1
	adds r0, #0x38
	strb r0, [r4, #0x1d]
	adds r4, #0x30
	adds r5, #0x30
	movs r2, #1
	add sb, r2
	mov r3, sb
	cmp r3, #7
	bgt _080A9386
	b _080A9222
_080A9386:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9398: .4byte 0x0203B400

	thumb_func_start FUN_080a939c
FUN_080a939c: @ 0x080A939C
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	ldr r2, _080A9418 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _080A941C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0x80
	lsls r3, r3, #8
	str r4, [sp]
	str r4, [sp, #4]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_082364f8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r5, #0x1c
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9418: .4byte 0xFFFF0000
_080A941C: .4byte 0x0000FFFF

	thumb_func_start FUN_080a9420
FUN_080a9420: @ 0x080A9420
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r2, #4]
	ldr r2, [r2]
	str r2, [r4, #0x1c]
	str r3, [r4, #0x20]
	str r1, [r4, #0x18]
	bl FUN_080a91dc
	adds r0, r4, #0
	bl FUN_080a939c
	movs r0, #0xfd
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xb4
	strh r0, [r1]
	movs r1, #3
	bl Div
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, #0x13
	bl PlaySound_082406e0
	ldr r1, _080A9474 @ =FUN_080a9058
	adds r0, r4, #0
	bl FUN_080a9044
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9474: .4byte FUN_080a9058

	thumb_func_start FUN_080a9478
FUN_080a9478: @ 0x080A9478
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x81
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A94B8
	ldr r1, _080A94B0 @ =0x080A91A9
	ldr r2, _080A94B4 @ =FUN_080a91bc
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a9420
	cmp r0, #0
	bge _080A94B8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A94BA
	.align 2, 0
_080A94B0: .4byte 0x080A91A9
_080A94B4: .4byte FUN_080a91bc
_080A94B8:
	adds r0, r4, #0
_080A94BA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a94c0
FUN_080a94c0: @ 0x080A94C0
	push {lr}
	ldr r0, _080A94D0 @ =0x03002C50
	ldr r0, [r0]
	cmp r0, #0
	beq _080A94D4
	ldrh r0, [r0, #0x18]
	b _080A94D6
	.align 2, 0
_080A94D0: .4byte 0x03002C50
_080A94D4:
	movs r0, #0
_080A94D6:
	pop {r1}
	bx r1
	.align 2, 0
_080A94DC:
	.byte 0x00, 0xB5, 0x04, 0x48
	.byte 0x01, 0x68, 0x00, 0x29, 0x01, 0xD0, 0x01, 0x20, 0x48, 0x83, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x50, 0x2C, 0x00, 0x03, 0x10, 0xB5, 0x04, 0x1C, 0x60, 0x8B, 0x00, 0x28, 0x05, 0xD0, 0xF3, 0xF7
	.byte 0x45, 0xF8, 0x20, 0x1C, 0x87, 0xF1, 0xB2, 0xFB, 0x10, 0xE0, 0x20, 0x8B, 0x01, 0x38, 0x20, 0x83
	.byte 0x00, 0x04, 0x00, 0x28, 0x0A, 0xD1, 0xF3, 0xF7, 0x39, 0xF8, 0xE0, 0x69, 0x00, 0x28, 0x02, 0xD0
	.byte 0x00, 0x21, 0x88, 0xF1, 0xC3, 0xF9, 0x20, 0x1C, 0x87, 0xF1, 0xA0, 0xFB, 0x00, 0x20, 0x10, 0xBC
	.byte 0x02, 0xBC, 0x08, 0x47, 0x01, 0x49, 0x00, 0x20, 0x08, 0x60, 0x70, 0x47, 0x50, 0x2C, 0x00, 0x03

	thumb_func_start FUN_080a9540
FUN_080a9540: @ 0x080A9540
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A9554
	bl fetch_082316e4
	b _080A9558
_080A9554:
	movs r0, #0xe1
	lsls r0, r0, #3
_080A9558:
	strh r0, [r4, #0x18]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A9568
	bl fetch_082316e4
_080A9568:
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0809c544
	ldr r0, _080A9580 @ =0x03002C50
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9580: .4byte 0x03002C50

	thumb_func_start FUN_080a9584
FUN_080a9584: @ 0x080A9584
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080A95C0 @ =0x03002C50
	ldr r0, [r0]
	cmp r0, #0
	bne _080A95CE
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A95CC
	ldr r1, _080A95C4 @ =0x080A94F5
	ldr r2, _080A95C8 @ =0x080A9535
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080a9540
	cmp r0, #0
	bge _080A95CC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A95CE
	.align 2, 0
_080A95C0: .4byte 0x03002C50
_080A95C4: .4byte 0x080A94F5
_080A95C8: .4byte 0x080A9535
_080A95CC:
	adds r0, r4, #0
_080A95CE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a95d4
FUN_080a95d4: @ 0x080A95D4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x28]
	adds r2, r0, #1
	strh r2, [r4, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A95F4
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #0
	strh r0, [r4, #0x2a]
	b _080A9624
_080A95F4:
	ldr r1, [r4, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r2, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r2, r1
	strh r0, [r4, #0x1a]
	ldrh r1, [r4, #0x28]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080A9624
	adds r0, r2, #1
	strh r0, [r4, #0x2e]
_080A9624:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a962c
FUN_080a962c: @ 0x080A962C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	movs r6, #0
	ldr r0, _080A96A8 @ =0x030046B8
	mov sl, r0
	ldr r1, _080A96AC @ =0x000003FF
	mov sb, r1
	ldr r2, _080A96B0 @ =0x085B0A08
	mov r8, r2
	movs r5, #0
	mov r4, ip
	adds r4, #0xa4
_080A964C:
	movs r0, #0x10
	strh r0, [r4]
	movs r0, #0x20
	strh r0, [r4, #2]
	mov r7, sl
	ldr r1, [r7]
	adds r1, #1
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _080A96B4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	lsls r3, r6, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	mov r7, sb
	ands r1, r7
	mov r0, sl
	str r1, [r0]
	lsls r1, r1, #1
	ldr r7, _080A96B4 @ =0x0203B400
	adds r1, r1, r7
	ldrh r0, [r1]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r1, r0, #4
	adds r3, #0x38
	movs r0, #0xff
	ands r3, r0
	lsls r3, r3, #1
	add r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A96B8
	asrs r0, r0, #0xc
	b _080A96BE
	.align 2, 0
_080A96A8: .4byte 0x030046B8
_080A96AC: .4byte 0x000003FF
_080A96B0: .4byte 0x085B0A08
_080A96B4: .4byte 0x0203B400
_080A96B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080A96BE:
	strh r0, [r4, #0x14]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A96D6
	asrs r0, r0, #0xc
	b _080A96DC
_080A96D6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080A96DC:
	strh r0, [r4, #0x16]
	mov r2, ip
	adds r2, #0x8c
	adds r2, r2, r5
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	strh r0, [r4, #0x12]
	movs r7, #0
	strh r7, [r4, #0x10]
	mov r0, ip
	adds r0, #0xc4
	adds r0, r0, r5
	ldr r1, _080A9718 @ =FUN_080a95d4
	str r1, [r0]
	adds r5, #0x3c
	adds r4, #0x3c
	adds r6, #1
	cmp r6, #7
	ble _080A964C
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9718: .4byte FUN_080a95d4

	thumb_func_start FUN_080a971c
FUN_080a971c: @ 0x080A971C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x28]
	adds r2, r0, #1
	strh r2, [r4, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A973C
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #0
	strh r0, [r4, #0x2a]
	b _080A9756
_080A973C:
	ldr r1, [r4, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
_080A9756:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a975c
FUN_080a975c: @ 0x080A975C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, [r4, #0x34]
	adds r0, r4, #0
	movs r2, #6
	bl FUN_0822dafc
	ldr r0, _080A97F8 @ =0x0203B400
	mov sb, r0
	ldr r5, _080A97FC @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080A9800 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x10
	bl Mod
	adds r0, #8
	movs r6, #0
	strh r0, [r4, #0x18]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x10
	bl Mod
	adds r0, #0x18
	strh r0, [r4, #0x1a]
	strh r6, [r4, #0x1c]
	strh r6, [r4, #0x2c]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #2
	bl Mod
	adds r0, #2
	rsbs r0, r0, #0
	strh r0, [r4, #0x2e]
	strh r6, [r4, #0x30]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r6, [r4, #0x28]
	ldr r0, _080A9804 @ =FUN_080a971c
	str r0, [r4, #0x38]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A97F8: .4byte 0x0203B400
_080A97FC: .4byte 0x030046B8
_080A9800: .4byte 0x000003FF
_080A9804: .4byte FUN_080a971c

	thumb_func_start FUN_080a9808
FUN_080a9808: @ 0x080A9808
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x28]
	adds r2, r0, #1
	strh r2, [r3, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080A9828
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r0, #0
	strh r0, [r3, #0x2a]
	b _080A983A
_080A9828:
	ldr r1, [r3, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r3, #0
	bl FUN_0822dafc
_080A983A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a9840
FUN_080a9840: @ 0x080A9840
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, [r4, #0x34]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, _080A98B0 @ =0x0203B400
	mov r8, r0
	ldr r5, _080A98B4 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r6, _080A98B8 @ =0x000003FF
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x50
	bl Mod
	adds r0, #0x18
	movs r2, #0
	strh r0, [r4, #0x18]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strh r0, [r4, #0x1a]
	strh r2, [r4, #0x1c]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r2, [r4, #0x28]
	ldr r0, _080A98BC @ =FUN_080a9808
	str r0, [r4, #0x38]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A98B0: .4byte 0x0203B400
_080A98B4: .4byte 0x030046B8
_080A98B8: .4byte 0x000003FF
_080A98BC: .4byte FUN_080a9808

	thumb_func_start FUN_080a98c0
FUN_080a98c0: @ 0x080A98C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x8c
	movs r7, #0
	movs r6, #7
_080A98CC:
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	beq _080A98E0
	adds r0, r5, #0
	adds r0, #0xc4
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080A98E0:
	adds r4, #0x3c
	adds r7, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _080A98CC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a98f0
FUN_080a98f0: @ 0x080A98F0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1e
	bne _080A9914
	adds r0, r5, #0
	bl FUN_080a962c
	ldr r0, _080A9948 @ =0x00000285
	bl PlaySound_082406e0
	ldr r0, [r5, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x24]
_080A9914:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080A9942
	bl FUN_0824082c
	ldr r2, _080A994C @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080A9950 @ =0x030047A4
	ldr r0, [r2]
	adds r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl KillEntity
_080A9942:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A9948: .4byte 0x00000285
_080A994C: .4byte 0x030044BC
_080A9950: .4byte 0x030047A4

	thumb_func_start FUN_080a9954
FUN_080a9954: @ 0x080A9954
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r2, [r1]
	cmp r2, #0
	bne _080A997A
	ldr r0, [r7, #0x18]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r2, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080A997A:
	movs r0, #0
	mov sb, r0
	ldr r0, [r7, #0x18]
	ldr r4, _080A9AA8 @ =0x00000366
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x96
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bne _080A9994
	movs r2, #1
_080A9994:
	ldr r0, [r7, #0x18]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r3, _080A9AAC @ =0x0000FFFF
	mov r8, r3
	ldr r3, [r7, #0x18]
	adds r0, r3, r4
	ldrh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r2
	blo _080A99C6
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	ldr r0, _080A9AB0 @ =0x00000259
	bl sound_08240740
	movs r3, #1
	mov sb, r3
_080A99C6:
	ldr r6, _080A9AB4 @ =0x0203B400
	ldr r4, _080A9AB8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080A9ABC @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #3
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7c
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #1
	strh r1, [r7, #0x3c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #3
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7e
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #1
	strh r1, [r7, #0x3e]
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r5, #7
	ands r5, r0
	cmp r5, #0
	bne _080A9A44
	ldr r3, _080A9AC0 @ =0x0000026E
	adds r4, r7, r3
	ldrh r1, [r4]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x8c
	adds r0, r7, r0
	bl FUN_080a975c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #7
	bls _080A9A44
	strh r5, [r4]
_080A9A44:
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r0, [r0]
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	bne _080A9A78
	ldr r0, _080A9AC0 @ =0x0000026E
	adds r4, r7, r0
	ldrh r1, [r4]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x8c
	adds r0, r7, r0
	bl FUN_080a9840
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080A9A78
	strh r5, [r4]
_080A9A78:
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	mov r0, sb
	cmp r0, #0
	beq _080A9A9C
	adds r3, #8
	adds r1, r7, r3
	ldr r0, _080A9AC4 @ =FUN_080a98f0
	str r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
_080A9A9C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9AA8: .4byte 0x00000366
_080A9AAC: .4byte 0x0000FFFF
_080A9AB0: .4byte 0x00000259
_080A9AB4: .4byte 0x0203B400
_080A9AB8: .4byte 0x030046B8
_080A9ABC: .4byte 0x000003FF
_080A9AC0: .4byte 0x0000026E
_080A9AC4: .4byte FUN_080a98f0

	thumb_func_start FUN_080a9ac8
FUN_080a9ac8: @ 0x080A9AC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sl, r0
	ldrh r0, [r0]
	adds r0, #1
	mov r1, sl
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A9B44
	ldrh r0, [r1]
	movs r5, #8
	subs r5, r5, r0
	ldr r0, _080A9B70 @ =0x0203B400
	mov sb, r0
	ldr r4, _080A9B74 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080A9B78 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	adds r1, r5, #0
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7c
	ldrh r1, [r1]
	adds r1, r1, r0
	asrs r6, r5, #1
	subs r1, r1, r6
	strh r1, [r7, #0x3c]
	ldr r0, [r4]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	adds r1, r5, #0
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7e
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, r1, r6
	strh r1, [r7, #0x3e]
_080A9B44:
	mov r1, sl
	ldrh r0, [r1]
	cmp r0, #0x1d
	bls _080A9B62
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, _080A9B7C @ =FUN_080a9954
	str r0, [r1]
	ldr r0, _080A9B80 @ =0x00000259
	bl PlaySound_082406e0
	movs r0, #0
	mov r1, sl
	strh r0, [r1]
_080A9B62:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9B70: .4byte 0x0203B400
_080A9B74: .4byte 0x030046B8
_080A9B78: .4byte 0x000003FF
_080A9B7C: .4byte FUN_080a9954
_080A9B80: .4byte 0x00000259

	thumb_func_start FUN_080a9b84
FUN_080a9b84: @ 0x080A9B84
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A9BA8
	bl FUN_082407e0
	movs r2, #4
	ldr r1, _080A9BA4 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080A9BBC
	.align 2, 0
_080A9BA4: .4byte 0x030044BC
_080A9BA8:
	cmp r0, #1
	bne _080A9BBC
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
_080A9BBC:
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r6, r5, r2
	ldrh r0, [r6]
	adds r0, #1
	adds r1, r0, #0
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A9C00
	ldr r0, [r5, #0x24]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	adds r0, r5, #0
	bl FUN_080a962c
	movs r3, #0x9d
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, _080A9BFC @ =FUN_080a9ac8
	str r0, [r1]
	movs r0, #0
	strh r0, [r6]
	movs r0, #0xa1
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080A9C82
	.align 2, 0
_080A9BFC: .4byte FUN_080a9ac8
_080A9C00:
	adds r1, #0x22
	adds r0, r5, #0
	adds r0, #0x51
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #0x2c
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x84
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #0x10
	subs r2, r4, r2
	muls r1, r2, r1
	adds r0, r0, r1
	movs r1, #0x10
	bl Div
	strh r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x7e
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x86
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r4, r4, r2
	muls r1, r4, r1
	adds r0, r0, r1
	movs r1, #0x10
	bl Div
	adds r4, r0, #0
	ldrh r0, [r6]
	lsls r0, r0, #7
	movs r1, #0x14
	bl Div
	ldr r2, _080A9C74 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A9C78
	asrs r0, r0, #0xc
	b _080A9C7E
	.align 2, 0
_080A9C74: .4byte 0x085B0A08
_080A9C78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080A9C7E:
	subs r0, r4, r0
	strh r0, [r5, #0x3e]
_080A9C82:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a9c88
FUN_080a9c88: @ 0x080A9C88
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a98c0
	movs r1, #0x9d
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9CA8:
	.byte 0x30, 0xB5, 0x04, 0x1C, 0x1C, 0x30, 0x85, 0xF1
	.byte 0x87, 0xFA, 0x8C, 0x34, 0x07, 0x25, 0x20, 0x1C, 0x83, 0xF1, 0x00, 0xFF, 0x3C, 0x34, 0x01, 0x3D
	.byte 0x00, 0x2D, 0xF8, 0xDA, 0x00, 0x20, 0x30, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080a9ccc
FUN_080a9ccc: @ 0x080A9CCC
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r4, r0, #0
	ldr r0, _080A9D28 @ =0x0000CB05
	ldr r1, _080A9D2C @ =0x00005D04
	bl FUN_082310cc
	adds r1, r0, #0
	add r2, sp, #0x10
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	add r0, sp, #0x10
	bl FUN_0822f284
	adds r2, r4, #0
	adds r2, #0x7c
	movs r1, #0
	movs r0, #8
	strh r0, [r2]
	adds r3, r4, #0
	adds r3, #0x7e
	movs r0, #0x18
	strh r0, [r3]
	adds r0, r4, #0
	adds r0, #0x80
	strh r1, [r0]
	subs r0, #0x64
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	add r1, sp, #0x10
	movs r2, #0x98
	movs r3, #0x33
	bl FUN_0822f3fc
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9D28: .4byte 0x0000CB05
_080A9D2C: .4byte 0x00005D04

	thumb_func_start FUN_080a9d30
FUN_080a9d30: @ 0x080A9D30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	ldr r0, _080A9DA4 @ =0x00001C1E
	bl FUN_0822b10c
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	mov r5, sl
	adds r5, #0x8c
	mov r8, r0
	movs r7, #7
_080A9D50:
	mov r4, sl
	adds r4, #0xc0
	add r4, r8
	str r6, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x11
	bl FUN_0822d9f0
	adds r0, r5, #0
	movs r1, #4
	rsbs r1, r1, #0
	adds r2, r1, #0
	bl FUN_0822dad4
	ldr r1, [r4]
	adds r0, r5, #0
	movs r2, #2
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r0, sb
	strb r0, [r5, #0xf]
	mov r0, sb
	strh r0, [r5, #0x28]
	strh r0, [r5, #0x2a]
	adds r5, #0x3c
	movs r0, #0x3c
	add r8, r0
	subs r7, #1
	cmp r7, #0
	bge _080A9D50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9DA4: .4byte 0x00001C1E

	thumb_func_start FUN_080a9da8
FUN_080a9da8: @ 0x080A9DA8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	str r1, [r7, #0x18]
	ldr r0, [r1, #0x2c]
	ldr r1, [r1, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _080A9DEC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r6, r7, #0
	adds r6, #0x84
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A9DF0
	asrs r0, r0, #8
	b _080A9DF6
	.align 2, 0
_080A9DEC: .4byte 0x0000FFFF
_080A9DF0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A9DF6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A9E08
	asrs r0, r0, #8
	b _080A9E0E
_080A9E08:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A9E0E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080A9E22
	asrs r0, r0, #8
	b _080A9E28
_080A9E22:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A9E28:
	subs r2, r4, r0
	movs r5, #0
	adds r4, r4, r0
	ldr r3, _080A9E7C @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	adds r0, r7, #0
	bl FUN_080a9ccc
	adds r0, r7, #0
	bl FUN_080a9d30
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, _080A9E80 @ =FUN_080a9b84
	str r0, [r1]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r5, [r0]
	ldr r2, _080A9E84 @ =0x030047A4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A9E7C: .4byte 0x030047C8
_080A9E80: .4byte FUN_080a9b84
_080A9E84: .4byte 0x030047A4

	thumb_func_start FUN_080a9e88
FUN_080a9e88: @ 0x080A9E88
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A9EC4
	ldr r1, _080A9EBC @ =FUN_080a9c88
	ldr r2, _080A9EC0 @ =0x080A9CA9
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a9da8
	cmp r0, #0
	bge _080A9EC4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A9EC6
	.align 2, 0
_080A9EBC: .4byte FUN_080a9c88
_080A9EC0: .4byte 0x080A9CA9
_080A9EC4:
	adds r0, r4, #0
_080A9EC6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a9ecc
FUN_080a9ecc: @ 0x080A9ECC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	bne _080A9F02
	ldr r0, [r4, #0x18]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r4, #0x20]
	ldrh r2, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r3, [r4, #0x18]
	ldr r2, _080A9F60 @ =0x00000366
	adds r0, r3, r2
	ldrh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r2
	blo _080A9F02
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	movs r0, #1
	strb r0, [r4, #0x1c]
_080A9F02:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A9F34
	ldr r0, [r4, #0x18]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r1, [r4, #0x22]
	ldrh r2, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r3, [r4, #0x18]
	ldr r2, _080A9F64 @ =0x0000036A
	adds r0, r3, r2
	ldrh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r2
	blo _080A9F34
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	movs r0, #1
	strb r0, [r4, #0x1d]
_080A9F34:
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A9F58
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A9F58
	ldr r0, _080A9F68 @ =0x00000259
	bl sound_08240740
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _080A9F52
	movs r1, #0
	bl FUN_082318ac
_080A9F52:
	adds r0, r4, #0
	bl KillEntity
_080A9F58:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9F60: .4byte 0x00000366
_080A9F64: .4byte 0x0000036A
_080A9F68: .4byte 0x00000259
_080A9F6C:
	.byte 0x00, 0x20, 0x70, 0x47

	thumb_func_start FUN_080a9f70
FUN_080a9f70: @ 0x080A9F70
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A9F84 @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r4, #0x18]
	cmp r0, #0
	bne _080A9F88
	movs r0, #1
	rsbs r0, r0, #0
	b _080AA044
	.align 2, 0
_080A9F84: .4byte 0x03002BE0
_080A9F88:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _080A9F9A
	bl fetch_082316e4
	adds r5, r0, #0
	b _080A9F9C
_080A9F9A:
	movs r5, #0
_080A9F9C:
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080A9FAE
	bl fetch_082316e4
	adds r6, r0, #0
	b _080A9FB0
_080A9FAE:
	movs r6, #0
_080A9FB0:
	cmp r5, #0
	beq _080A9FE4
	ldr r0, [r4, #0x18]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r3, _080A9FE0 @ =0x00000366
	adds r2, r0, r3
	ldrh r0, [r1]
	ldrh r1, [r2]
	cmp r0, r1
	bhs _080A9FE4
	ldrh r0, [r2]
	movs r1, #0x5a
	bl Div
	strh r0, [r4, #0x20]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A9FDC
	movs r0, #1
	strh r0, [r4, #0x20]
_080A9FDC:
	movs r0, #0
	b _080A9FE6
	.align 2, 0
_080A9FE0: .4byte 0x00000366
_080A9FE4:
	movs r0, #1
_080A9FE6:
	strb r0, [r4, #0x1c]
	cmp r6, #0
	beq _080AA01C
	ldr r0, [r4, #0x18]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r3, _080AA018 @ =0x0000036A
	adds r2, r0, r3
	ldrh r0, [r1]
	ldrh r1, [r2]
	cmp r0, r1
	bhs _080AA01C
	ldrh r0, [r2]
	movs r1, #0x5a
	bl Div
	strh r0, [r4, #0x22]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AA014
	movs r0, #1
	strh r0, [r4, #0x22]
_080AA014:
	movs r0, #0
	b _080AA01E
	.align 2, 0
_080AA018: .4byte 0x0000036A
_080AA01C:
	movs r0, #1
_080AA01E:
	strb r0, [r4, #0x1d]
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	beq _080AA02C
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080AA032
_080AA02C:
	ldr r0, _080AA04C @ =0x00000259
	bl PlaySound_082406e0
_080AA032:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080AA040
	bl fetch_082316e4
_080AA040:
	str r0, [r4, #0x24]
	movs r0, #0
_080AA044:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AA04C: .4byte 0x00000259
_080AA050:
	.byte 0x10, 0xB5, 0x09, 0x20, 0x28, 0x21, 0x86, 0xF1, 0xAB, 0xFD, 0x04, 0x1C, 0x00, 0x2C, 0x11, 0xD0
	.byte 0x06, 0x49, 0x07, 0x4A, 0x86, 0xF1, 0xC8, 0xFD, 0x20, 0x1C, 0xFF, 0xF7, 0x81, 0xFF, 0x00, 0x28
	.byte 0x08, 0xDA, 0x20, 0x1C, 0x86, 0xF1, 0xFA, 0xFD, 0x00, 0x20, 0x04, 0xE0, 0xCD, 0x9E, 0x0A, 0x08
	.byte 0x6D, 0x9F, 0x0A, 0x08, 0x20, 0x1C, 0x10, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080aa08c
FUN_080aa08c: @ 0x080AA08C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x28]
	adds r2, r0, #1
	strh r2, [r4, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AA0AC
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #0
	strh r0, [r4, #0x2a]
	b _080AA0DC
_080AA0AC:
	ldr r1, [r4, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r2, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r2, r1
	strh r0, [r4, #0x1a]
	ldrh r1, [r4, #0x28]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080AA0DC
	adds r0, r2, #1
	strh r0, [r4, #0x2e]
_080AA0DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080aa0e4
FUN_080aa0e4: @ 0x080AA0E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r7, #0
	ldr r0, _080AA174 @ =0x000003FF
	mov sl, r0
	ldr r1, _080AA178 @ =0x085B0A08
	mov sb, r1
	mov ip, r5
	movs r6, #0
	movs r2, #0xff
	mov r8, r2
_080AA102:
	adds r0, r5, #0
	adds r0, #0x7c
	ldrh r0, [r0]
	adds r0, #8
	movs r1, #0xbe
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x7e
	ldrh r0, [r0]
	adds r0, #8
	movs r1, #0xbf
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	ldr r0, _080AA17C @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	mov r2, sl
	ands r1, r2
	lsls r0, r1, #1
	ldr r2, _080AA180 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	lsls r3, r7, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	mov r0, sl
	ands r1, r0
	ldr r0, _080AA17C @ =0x030046B8
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _080AA180 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r4, r0, #4
	adds r3, #0x38
	mov r1, r8
	ands r3, r1
	lsls r3, r3, #1
	add r3, sb
	movs r1, #0
	ldrsh r0, [r3, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AA184
	asrs r1, r0, #0xc
	b _080AA18A
	.align 2, 0
_080AA174: .4byte 0x000003FF
_080AA178: .4byte 0x085B0A08
_080AA17C: .4byte 0x030046B8
_080AA180: .4byte 0x0203B400
_080AA184:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AA18A:
	movs r0, #0xc8
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AA1A8
	asrs r0, r0, #0xc
	b _080AA1AE
_080AA1A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AA1AE:
	movs r1, #0xc9
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r2, r5, r0
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc7
	lsls r1, r1, #1
	add r1, ip
	movs r0, #1
	strh r0, [r1]
	movs r0, #0xc6
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xce
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r0, r6
	ldr r1, _080AA204 @ =FUN_080aa08c
	str r1, [r0]
	movs r2, #0x3c
	add ip, r2
	adds r6, #0x3c
	adds r7, #1
	cmp r7, #7
	ble _080AA102
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AA204: .4byte FUN_080aa08c

	thumb_func_start FUN_080aa208
FUN_080aa208: @ 0x080AA208
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r7, #0
	movs r5, #7
_080AA216:
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	beq _080AA22C
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080AA22C:
	adds r4, #0x3c
	adds r7, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080AA216
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aa23c
FUN_080aa23c: @ 0x080AA23C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080AA260 @ =0x0000034A
	adds r4, r5, r0
	ldrh r1, [r4]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #1
	bl FUN_0823b9cc
	ldrh r0, [r4]
	cmp r0, #5
	bhi _080AA264
	adds r0, r5, #0
	adds r0, #0x94
	bl FUN_08236400
	b _080AA274
	.align 2, 0
_080AA260: .4byte 0x0000034A
_080AA264:
	cmp r0, #6
	bne _080AA274
	ldr r0, _080AA294 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_080AA274:
	ldr r0, _080AA298 @ =0x0000034A
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AA28C
	adds r0, r5, #0
	bl KillEntity
_080AA28C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AA294: .4byte 0x030047A4
_080AA298: .4byte 0x0000034A

	thumb_func_start FUN_080aa29c
FUN_080aa29c: @ 0x080AA29C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0xe4
	mov r1, r8
	adds r7, r1, r0
	ldr r0, _080AA30C @ =0x0000034A
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x12
	bl Div
	ldr r6, _080AA310 @ =0x0203B400
	ldr r5, _080AA314 @ =0x030046B8
	ldr r2, [r5]
	adds r2, #1
	ldr r4, _080AA318 @ =0x000003FF
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	lsls r0, r0, #6
	movs r3, #0x3f
	ands r1, r3
	adds r3, r0, r1
	movs r1, #0xff
	ands r3, r1
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r0, [r2]
	ands r0, r1
	adds r4, r0, #0
	adds r4, #0x80
	ldr r2, _080AA31C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AA320
	asrs r0, r0, #0xc
	b _080AA326
	.align 2, 0
_080AA30C: .4byte 0x0000034A
_080AA310: .4byte 0x0203B400
_080AA314: .4byte 0x030046B8
_080AA318: .4byte 0x000003FF
_080AA31C: .4byte 0x085B0A08
_080AA320:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AA326:
	adds r5, r0, #0
	ldr r1, _080AA344 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	muls r1, r0, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _080AA348
	asrs r2, r0, #0xd
	b _080AA34E
	.align 2, 0
_080AA344: .4byte 0x085B0A08
_080AA348:
	rsbs r0, r0, #0
	asrs r0, r0, #0xd
	rsbs r2, r0, #0
_080AA34E:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldr r0, _080AA3D4 @ =0x03003540
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r0, [r7, #0x1c]
	subs r0, #0x4b
	subs r1, r5, r2
	adds r0, r0, r1
	movs r3, #0
	strh r0, [r7, #0x1c]
	ldr r1, _080AA3D8 @ =0x00000352
	adds r0, r1, #0
	ldrh r1, [r7, #0x1e]
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
	ldrh r0, [r7, #0x20]
	subs r0, #0x4b
	adds r1, r5, r2
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	movs r2, #0xac
	lsls r2, r2, #1
	add r2, r8
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r2]
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldrh r1, [r2]
	lsls r1, r1, #1
	movs r0, #0xb0
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	strh r3, [r0]
	adds r1, r7, #0
	adds r1, #0x1c
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r5, r1, #0
	cmp r3, #0
	blt _080AA3CE
	cmp r2, #0
	blt _080AA3CE
	ldr r0, _080AA3DC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080AA3CE
	ldr r0, _080AA3E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _080AA3E4
_080AA3CE:
	movs r4, #0
	b _080AA3F2
	.align 2, 0
_080AA3D4: .4byte 0x03003540
_080AA3D8: .4byte 0x00000352
_080AA3DC: .4byte 0x030046A8
_080AA3E0: .4byte 0x030046AC
_080AA3E4:
	ldr r0, _080AA404 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_080AA3F2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080AA408
	adds r0, #4
	b _080AA414
	.align 2, 0
_080AA404: .4byte 0x030046A4
_080AA408:
	ldr r0, _080AA438 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080AA414:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080AA43C
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #1
	movs r1, #0xae
	lsls r1, r1, #1
	add r1, r8
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1]
	b _080AA4D0
	.align 2, 0
_080AA438: .4byte 0x030046A4
_080AA43C:
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080AA460
	cmp r1, #0
	blt _080AA460
	ldr r0, _080AA464 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080AA460
	ldr r0, _080AA468 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080AA46C
_080AA460:
	movs r4, #0
	b _080AA47A
	.align 2, 0
_080AA464: .4byte 0x030046A8
_080AA468: .4byte 0x030046AC
_080AA46C:
	ldr r0, _080AA48C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080AA47A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080AA490
	adds r0, #4
	b _080AA49C
	.align 2, 0
_080AA48C: .4byte 0x030046A4
_080AA490:
	ldr r0, _080AA4B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080AA49C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080AA4B4
	cmp r3, #2
	beq _080AA4B8
	b _080AA4BC
	.align 2, 0
_080AA4B0: .4byte 0x030046A4
_080AA4B4:
	ldrb r0, [r5, #4]
	b _080AA4BA
_080AA4B8:
	ldrb r0, [r5]
_080AA4BA:
	subs r2, r2, r0
_080AA4BC:
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	lsls r1, r1, #1
	movs r0, #0xae
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	strh r2, [r0]
_080AA4D0:
	movs r2, #0xac
	lsls r2, r2, #1
	add r2, r8
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aa4e8
FUN_080aa4e8: @ 0x080AA4E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	movs r0, #0
	mov sb, r0
	movs r1, #0xb0
	lsls r1, r1, #1
	add r1, r8
	str r1, [sp]
	mov sl, r0
	movs r7, #0xb0
	lsls r7, r7, #1
	add r7, r8
_080AA50A:
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, r8
	mov r1, sb
	adds r6, r0, r1
	ldrb r2, [r6]
	cmp r2, #0
	beq _080AA5B0
	movs r0, #0x2c
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #0xe4
	mov r1, r8
	adds r5, r1, r0
	cmp r2, #1
	bne _080AA584
	ldrh r0, [r5, #0x1e]
	subs r0, #0x32
	movs r1, #0
	mov ip, r1
	movs r3, #0
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, r8
	add r4, sl
	ldrh r1, [r4]
	cmp r0, r1
	bgt _080AA564
	ldr r0, _080AA560 @ =0x000001FF
	str r3, [sp, #4]
	bl PlaySound_082406e0
	ldrh r0, [r4]
	strh r0, [r5, #0x1e]
	movs r0, #2
	strb r0, [r6]
	ldr r3, [sp, #4]
	b _080AA5AE
	.align 2, 0
_080AA560: .4byte 0x000001FF
_080AA564:
	ldr r1, [sp]
	add r1, sl
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x18
	bls _080AA5B0
	ldr r0, [r5]
	orrs r0, r2
	str r0, [r5]
	mov r0, ip
	strb r0, [r6]
	strh r3, [r1]
	b _080AA5B0
_080AA584:
	ldrh r0, [r7]
	adds r1, r0, #1
	movs r2, #0
	movs r3, #0
	strh r1, [r7]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _080AA5A4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x12
	subs r1, #0xc
	ldrh r0, [r5, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	b _080AA5B0
_080AA5A4:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r2, [r6]
_080AA5AE:
	strh r3, [r7]
_080AA5B0:
	movs r1, #2
	add sl, r1
	adds r7, #2
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #1
	ble _080AA50A
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aa5d0
FUN_080aa5d0: @ 0x080AA5D0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080AA64C @ =0x0000034A
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AA5F2
	cmp r0, #0x12
	beq _080AA5F2
	cmp r0, #0x24
	beq _080AA5F2
	cmp r0, #0x36
	beq _080AA5F2
	cmp r0, #0x48
	beq _080AA5F2
	cmp r0, #0x5a
	bne _080AA5F8
_080AA5F2:
	adds r0, r4, #0
	bl FUN_080aa29c
_080AA5F8:
	adds r0, r4, #0
	bl FUN_080aa4e8
	ldr r0, _080AA64C @ =0x0000034A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x79
	bls _080AA646
	ldr r5, _080AA650 @ =0x030044BC
	ldr r6, _080AA654 @ =FUN_080aa23c
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0xe4
	movs r0, #0x88
	lsls r0, r0, #1
	adds r2, r4, r0
_080AA620:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _080AA620
	movs r2, #0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	str r6, [r0]
	subs r1, #2
	adds r0, r4, r1
	strh r2, [r0]
_080AA646:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA64C: .4byte 0x0000034A
_080AA650: .4byte 0x030044BC
_080AA654: .4byte FUN_080aa23c

	thumb_func_start FUN_080aa658
FUN_080aa658: @ 0x080AA658
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _080AA6A4 @ =0x0000034A
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080AA692
	ldr r2, _080AA6A8 @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x67
	bl PlaySound_082406e0
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _080AA6AC @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
_080AA692:
	ldrh r0, [r5]
	cmp r0, #5
	bhi _080AA6B0
	adds r0, r4, #0
	adds r0, #0x94
	bl FUN_08236400
	b _080AA6C0
	.align 2, 0
_080AA6A4: .4byte 0x0000034A
_080AA6A8: .4byte 0x030044BC
_080AA6AC: .4byte 0x00001FFF
_080AA6B0:
	cmp r0, #6
	bne _080AA6C0
	ldr r0, _080AA6DC @ =0x030047A4
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_080AA6C0:
	ldr r0, _080AA6E0 @ =0x0000034A
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bls _080AA6E4
	adds r0, r4, #0
	bl KillEntity
	b _080AA6FE
	.align 2, 0
_080AA6DC: .4byte 0x030047A4
_080AA6E0: .4byte 0x0000034A
_080AA6E4:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080AA6F4
	movs r0, #0x20
	bl FUN_0823b9cc
	b _080AA6FE
_080AA6F4:
	ldrh r1, [r2]
	movs r0, #0x30
	subs r0, r0, r1
	bl FUN_0823b9cc
_080AA6FE:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AA708:
	.byte 0xF0, 0xB5, 0x57, 0x46, 0x4E, 0x46, 0x45, 0x46
	.byte 0xE0, 0xB4, 0x83, 0xB0, 0x07, 0x1C, 0x35, 0x48, 0xC0, 0x19, 0x82, 0x46, 0x00, 0x88, 0x01, 0x30
	.byte 0x51, 0x46, 0x08, 0x80, 0x00, 0x04, 0x00, 0x0C, 0x07, 0x28, 0x2B, 0xD8, 0x08, 0x88, 0x08, 0x25
	.byte 0x2D, 0x1A, 0x2F, 0x4A, 0x91, 0x46, 0x2F, 0x4C, 0x20, 0x68, 0x01, 0x30, 0x2E, 0x49, 0x88, 0x46
	.byte 0x08, 0x40, 0x20, 0x60, 0x40, 0x00, 0x48, 0x44, 0x00, 0x88, 0xC0, 0x10, 0x29, 0x1C, 0xA1, 0xF1
	.byte 0x39, 0xFD, 0x39, 0x1C, 0x7C, 0x31, 0x09, 0x88, 0x09, 0x18, 0x6E, 0x10, 0x89, 0x1B, 0xB9, 0x87
	.byte 0x20, 0x68, 0x01, 0x30, 0x42, 0x46, 0x10, 0x40, 0x20, 0x60, 0x40, 0x00, 0x48, 0x44, 0x00, 0x88
	.byte 0xC0, 0x10, 0x29, 0x1C, 0xA1, 0xF1, 0x26, 0xFD, 0x39, 0x1C, 0x7E, 0x31, 0x09, 0x88, 0x09, 0x18
	.byte 0x89, 0x1B, 0xF9, 0x87, 0x51, 0x46, 0x08, 0x88, 0x1E, 0x28, 0x09, 0xD1, 0x38, 0x1C, 0xFF, 0xF7
	.byte 0xA9, 0xFC, 0x1A, 0x48, 0x95, 0xF1, 0xA4, 0xFF, 0x78, 0x6A, 0x01, 0x21, 0x08, 0x43, 0x78, 0x62
	.byte 0xD2, 0x22, 0x92, 0x00, 0xB8, 0x18, 0x01, 0x88, 0x01, 0x29, 0x0E, 0xD1, 0x52, 0x46, 0x10, 0x88
	.byte 0x1D, 0x28, 0x0A, 0xD1, 0x04, 0x20, 0x00, 0x90, 0x11, 0x48, 0x01, 0x90, 0x02, 0x91, 0x03, 0x20
	.byte 0x05, 0x21, 0x04, 0x22, 0x04, 0x23, 0x92, 0xF1, 0x4F, 0xFB, 0x08, 0x49, 0x78, 0x18, 0x00, 0x88
	.byte 0x2C, 0x28, 0x22, 0xD9, 0xD2, 0x22, 0x92, 0x00, 0xB8, 0x18, 0x00, 0x88, 0x00, 0x28, 0x13, 0xD1
	.byte 0xD3, 0x20, 0x80, 0x00, 0x39, 0x18, 0x07, 0x48, 0x12, 0xE0, 0x00, 0x00, 0x4A, 0x03, 0x00, 0x00
	.byte 0x00, 0xB4, 0x03, 0x02, 0xB8, 0x46, 0x00, 0x03, 0xFF, 0x03, 0x00, 0x00, 0x85, 0x02, 0x00, 0x00
	.byte 0xFF, 0x1F, 0x00, 0x00, 0xD1, 0xA5, 0x0A, 0x08, 0xD3, 0x22, 0x92, 0x00, 0xB9, 0x18, 0x07, 0x48
	.byte 0x08, 0x60, 0x07, 0x48, 0x39, 0x18, 0x00, 0x20, 0x08, 0x80, 0x03, 0xB0, 0x38, 0xBC, 0x98, 0x46
	.byte 0xA1, 0x46, 0xAA, 0x46, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x59, 0xA6, 0x0A, 0x08
	.byte 0x4A, 0x03, 0x00, 0x00

	thumb_func_start FUN_080aa834
FUN_080aa834: @ 0x080AA834
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	ldr r0, _080AA874 @ =0x0000034A
	adds r6, r5, r0
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080AA87C
	ldr r0, [r5, #0x24]
	subs r1, #1
	ands r0, r1
	str r0, [r5, #0x24]
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, _080AA878 @ =0x080AA709
	str r0, [r1]
	movs r0, #0
	strh r0, [r6]
	movs r0, #0xa1
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080AA8D2
	.align 2, 0
_080AA874: .4byte 0x0000034A
_080AA878: .4byte 0x080AA709
_080AA87C:
	ldrh r0, [r6]
	lsls r0, r0, #1
	adds r0, #0x20
	adds r1, r5, #0
	adds r1, #0x51
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x7c
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x84
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #8
	subs r2, r4, r2
	muls r1, r2, r1
	adds r0, r0, r1
	movs r1, #8
	bl Div
	strh r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x7e
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x86
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r4, r4, r2
	muls r1, r4, r1
	adds r0, r0, r1
	movs r1, #8
	bl Div
	strh r0, [r5, #0x3e]
_080AA8D2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aa8d8
FUN_080aa8d8: @ 0x080AA8D8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080aa208
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080AA8F8:
	.byte 0x70, 0xB5, 0x06, 0x1C, 0x1C, 0x30, 0x84, 0xF1
	.byte 0x5F, 0xFC, 0xB2, 0x20, 0x40, 0x00, 0x34, 0x18, 0x07, 0x25, 0x20, 0x1C, 0x83, 0xF1, 0xD6, 0xF8
	.byte 0x3C, 0x34, 0x01, 0x3D, 0x00, 0x2D, 0xF8, 0xDA, 0xD2, 0x21, 0x89, 0x00, 0x70, 0x18, 0x00, 0x88
	.byte 0x00, 0x28, 0x09, 0xD1, 0x34, 0x1C, 0xE4, 0x34, 0x01, 0x25, 0x20, 0x1C, 0x7F, 0xF1, 0xD8, 0xFD
	.byte 0x2C, 0x34, 0x01, 0x3D, 0x00, 0x2D, 0xF8, 0xDA, 0x00, 0x20, 0x70, 0xBC, 0x02, 0xBC, 0x08, 0x47

	thumb_func_start FUN_080aa940
FUN_080aa940: @ 0x080AA940
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r0, _080AA9C8 @ =0x0000CB05
	ldr r1, _080AA9CC @ =0x00005D04
	bl FUN_082310cc
	adds r1, r0, #0
	add r2, sp, #0x10
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	add r0, sp, #0x10
	bl FUN_0822f284
	movs r6, #0xd2
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r0, [r0]
	movs r2, #0x2c
	cmp r0, #0
	bne _080AA974
	movs r2, #0x27
_080AA974:
	adds r3, r5, #0
	adds r3, #0x84
	ldrh r0, [r3]
	subs r0, #8
	adds r1, r5, #0
	adds r1, #0x7c
	movs r4, #0
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x86
	ldrh r0, [r0]
	subs r0, #0x28
	adds r1, #2
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x88
	ldrh r1, [r0]
	subs r0, #8
	strh r1, [r0]
	subs r0, #0x64
	adds r2, #0x68
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r3, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #0x32
	bl FUN_0822f3fc
	adds r0, r5, #0
	adds r0, #0x51
	movs r1, #0x22
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA9C8: .4byte 0x0000CB05
_080AA9CC: .4byte 0x00005D04

	thumb_func_start FUN_080aa9d0
FUN_080aa9d0: @ 0x080AA9D0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, _080AAA24 @ =0x000024BA
	bl FUN_0822b16c
	movs r6, #0
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r7, r5, r0
_080AA9E8:
	movs r0, #0x2c
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0xe4
	adds r0, r5, r0
	adds r1, r7, #0
	movs r2, #1
	bl FUN_0822a470
	adds r0, r7, #0
	ldr r1, _080AAA28 @ =0x0000027D
	bl FUN_0822b20c
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	adds r2, r2, r4
	ldr r0, [r5, #0x18]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, #1
	cmp r6, #1
	ble _080AA9E8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAA24: .4byte 0x000024BA
_080AAA28: .4byte 0x0000027D

	thumb_func_start FUN_080aaa2c
FUN_080aaa2c: @ 0x080AAA2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	ldr r0, _080AAAA4 @ =0x00001C1E
	bl FUN_0822b10c
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	movs r5, #0xb2
	lsls r5, r5, #1
	add r5, sl
	mov r8, r0
	movs r7, #7
_080AAA4E:
	movs r4, #0xcc
	lsls r4, r4, #1
	add r4, sl
	add r4, r8
	str r6, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x11
	bl FUN_0822d9f0
	adds r0, r5, #0
	movs r1, #4
	rsbs r1, r1, #0
	adds r2, r1, #0
	bl FUN_0822dad4
	ldr r1, [r4]
	adds r0, r5, #0
	movs r2, #2
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r0, sb
	strb r0, [r5, #0xf]
	mov r0, sb
	strh r0, [r5, #0x28]
	strh r0, [r5, #0x2a]
	adds r5, #0x3c
	movs r0, #0x3c
	add r8, r0
	subs r7, #1
	cmp r7, #0
	bge _080AAA4E
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAAA4: .4byte 0x00001C1E

	thumb_func_start FUN_080aaaa8
FUN_080aaaa8: @ 0x080AAAA8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x94
	ldr r2, _080AAB08 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r3, _080AAB0C @ =0x00007530
	orrs r0, r3
	ldr r1, _080AAB10 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _080AAB14 @ =0x75300000
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	mov ip, r1
	cmp r0, #0
	bne _080AAB18
	ldr r1, [r4, #0x18]
	adds r0, r1, #0
	adds r0, #0x28
	movs r3, #1
	ldrb r0, [r0]
	lsls r3, r0
	adds r2, #0x1e
	adds r0, r1, r2
	ldrh r2, [r0]
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r5, r2, r0
	b _080AAB4E
	.align 2, 0
_080AAB08: .4byte 0xFFFF0000
_080AAB0C: .4byte 0x00007530
_080AAB10: .4byte 0x0000FFFF
_080AAB14: .4byte 0x75300000
_080AAB18:
	ldr r0, [r4, #0x18]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080AAB40
	ldr r0, _080AAB3C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #0xa
	cmp r0, #0x63
	ble _080AAB4A
	movs r0, #0x63
	b _080AAB4A
	.align 2, 0
_080AAB3C: .4byte 0x030046A0
_080AAB40:
	ldr r0, _080AAB9C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
_080AAB4A:
	movs r3, #0
	lsls r5, r0, #3
_080AAB4E:
	movs r7, #0x80
	lsls r7, r7, #5
	ldr r2, _080AABA0 @ =0x00003001
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	mov r1, ip
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r7, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #0
	bl FUN_082364f8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r1, [r4, #0x18]
	adds r1, #0x2c
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAB9C: .4byte 0x030046A0
_080AABA0: .4byte 0x00003001

	thumb_func_start FUN_080aaba4
FUN_080aaba4: @ 0x080AABA4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	str r1, [r5, #0x18]
	movs r1, #0xd2
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r2, [r0]
	ldr r0, [r5, #0x18]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _080AABF4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r6, r5, #0
	adds r6, #0x84
	mov r7, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080AABF8
	asrs r0, r0, #8
	b _080AABFE
	.align 2, 0
_080AABF4: .4byte 0x0000FFFF
_080AABF8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AABFE:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080AAC10
	asrs r0, r0, #8
	b _080AAC16
_080AAC10:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AAC16:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080AAC2A
	asrs r0, r0, #8
	b _080AAC30
_080AAC2A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AAC30:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _080AAC74 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	adds r0, r5, #0
	bl FUN_080aa940
	adds r0, r5, #0
	bl FUN_080aaa2c
	adds r0, r5, #0
	bl FUN_080aaaa8
	ldr r1, [r5, #0x18]
	ldr r2, _080AAC78 @ =0x00000359
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080AAC7C
	adds r0, r1, #0
	adds r0, #0x90
	b _080AAC80
	.align 2, 0
_080AAC74: .4byte 0x030047C8
_080AAC78: .4byte 0x00000359
_080AAC7C:
	adds r0, r1, #0
	adds r0, #0xe8
_080AAC80:
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldr r0, [r5, #0x18]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	strh r4, [r0]
	ldr r2, _080AACD8 @ =0x030047A4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #4
	ldr r1, _080AACDC @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AACBC
	adds r0, r5, #0
	bl FUN_080aa9d0
_080AACBC:
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, _080AACE0 @ =FUN_080aa834
	str r1, [r0]
	ldr r2, _080AACE4 @ =0x0000034A
	adds r0, r5, r2
	strh r4, [r0]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AACD8: .4byte 0x030047A4
_080AACDC: .4byte 0x030044BC
_080AACE0: .4byte FUN_080aa834
_080AACE4: .4byte 0x0000034A

	thumb_func_start FUN_080aace8
FUN_080aace8: @ 0x080AACE8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xd4
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AAD28
	ldr r1, _080AAD20 @ =FUN_080aa8d8
	ldr r2, _080AAD24 @ =0x080AA8F9
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080aaba4
	cmp r0, #0
	bge _080AAD28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AAD2A
	.align 2, 0
_080AAD20: .4byte FUN_080aa8d8
_080AAD24: .4byte 0x080AA8F9
_080AAD28:
	adds r0, r4, #0
_080AAD2A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080aad30
FUN_080aad30: @ 0x080AAD30
	push {lr}
	mov ip, r0
	ldr r0, _080AAD74 @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _080AAD70
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	mov r1, ip
	adds r1, #0x7c
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r3, r0, r1
	cmp r3, #0
	bge _080AAD50
	rsbs r3, r3, #0
_080AAD50:
	movs r1, #0x30
	ldrsh r0, [r2, r1]
	mov r1, ip
	adds r1, #0x80
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _080AAD64
	rsbs r0, r0, #0
_080AAD64:
	mov r2, ip
	ldrh r1, [r2, #0x1a]
	cmp r3, r1
	bgt _080AAD70
	cmp r0, r1
	ble _080AAD78
_080AAD70:
	movs r0, #0
	b _080AAD7A
	.align 2, 0
_080AAD74: .4byte 0x03002BE0
_080AAD78:
	movs r0, #1
_080AAD7A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080aad80
FUN_080aad80: @ 0x080AAD80
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080AADA8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080AADAC
	adds r0, r4, #0
	bl FUN_080aad30
	cmp r0, #0
	beq _080AADAC
	ldr r0, [r4, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _080AADB2
	.align 2, 0
_080AADA8: .4byte 0x030047A4
_080AADAC:
	ldr r0, [r4, #0x24]
	movs r1, #1
	orrs r0, r1
_080AADB2:
	str r0, [r4, #0x24]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080aadbc
FUN_080aadbc: @ 0x080AADBC
	push {lr}
	adds r0, #0x1c
	bl FUN_0822f1c0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080aadcc
FUN_080aadcc: @ 0x080AADCC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	mov r8, r0
	ldr r0, _080AAE2C @ =0x0000CB05
	ldr r1, _080AAE30 @ =0x000082F1
	bl FUN_082310cc
	adds r1, r0, #0
	add r2, sp, #0x10
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	add r0, sp, #0x10
	bl FUN_0822f284
	movs r0, #0x70
	bl prepare_08231510
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAE34
	bl fetch_082316e4
	mov r5, r8
	adds r5, #0x7c
	strh r0, [r5]
	bl fetch_082316e4
	mov r4, r8
	adds r4, #0x7e
	strh r0, [r4]
	bl fetch_082316e4
	mov r1, r8
	adds r1, #0x80
	strh r0, [r1]
	mov sl, r5
	str r4, [sp, #0x38]
	str r1, [sp, #0x3c]
	b _080AAE4C
	.align 2, 0
_080AAE2C: .4byte 0x0000CB05
_080AAE30: .4byte 0x000082F1
_080AAE34:
	mov r2, r8
	adds r2, #0x7c
	strh r3, [r2]
	mov r1, r8
	adds r1, #0x7e
	strh r3, [r1]
	mov r0, r8
	adds r0, #0x80
	strh r3, [r0]
	mov sl, r2
	str r1, [sp, #0x38]
	str r0, [sp, #0x3c]
_080AAE4C:
	movs r0, #0x6f
	bl prepare_08231510
	cmp r0, #0
	beq _080AAE8C
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080AAE84 @ =0xFFFF0000
	adds r4, r5, #0
	ands r4, r6
	orrs r4, r0
	bl fetch_082316e4
	lsls r0, r0, #0x10
	ldr r1, _080AAE88 @ =0x0000FFFF
	ands r4, r1
	adds r6, r4, #0
	orrs r6, r0
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r7
	adds r7, r5, #0
	orrs r7, r0
	b _080AAE92
	.align 2, 0
_080AAE84: .4byte 0xFFFF0000
_080AAE88: .4byte 0x0000FFFF
_080AAE8C:
	ldr r0, _080AAEA8 @ =0xFFFF0000
	movs r6, #0
	ands r7, r0
_080AAE92:
	movs r0, #0x49
	bl prepare_08231510
	cmp r0, #0
	beq _080AAEAC
	bl fetch_082316e4
	mov r5, r8
	strh r0, [r5, #0x1a]
	b _080AAEB4
	.align 2, 0
_080AAEA8: .4byte 0xFFFF0000
_080AAEAC:
	movs r0, #0xc0
	lsls r0, r0, #1
	mov r1, r8
	strh r0, [r1, #0x1a]
_080AAEB4:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080AAEC8
	bl fetch_082316e4
	mov r2, r8
	strh r0, [r2, #0x18]
	b _080AAECC
_080AAEC8:
	mov r3, r8
	strh r0, [r3, #0x18]
_080AAECC:
	movs r0, #0x52
	bl prepare_08231510
	cmp r0, #0
	beq _080AAEDE
	bl fetch_082316e4
	mov sb, r0
	b _080AAEE2
_080AAEDE:
	movs r4, #1
	mov sb, r4
_080AAEE2:
	mov r5, r8
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	beq _080AAEF2
	cmp r0, #1
	beq _080AAF08
	movs r5, #0
	b _080AAF1C
_080AAEF2:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080AAF02
	bl fetch_082316e4
	b _080AAF04
_080AAF02:
	movs r0, #0
_080AAF04:
	adds r5, r0, #0
	b _080AAF1C
_080AAF08:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _080AAF18
	bl fetch_082316e4
	b _080AAF1A
_080AAF18:
	movs r0, #0
_080AAF1A:
	adds r5, r0, #4
_080AAF1C:
	adds r0, r6, #0
	mov r1, sl
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080AAF98 @ =0xFFFF0000
	ldr r2, [sp, #0x30]
	ands r2, r4
	orrs r2, r0
	str r2, [sp, #0x30]
	asrs r1, r6, #0x10
	ldr r3, [sp, #0x38]
	ldrh r3, [r3]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _080AAF9C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x30]
	adds r1, r7, #0
	ldr r0, [sp, #0x3c]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r3, sp, #0x30
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	mov r0, r8
	adds r0, #0x1c
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	mov r4, sb
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r3, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _080AAFA0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080AAFA4
	mov r5, r8
	ldr r0, [r5, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x24]
	b _080AAFC8
	.align 2, 0
_080AAF98: .4byte 0xFFFF0000
_080AAF9C: .4byte 0x0000FFFF
_080AAFA0: .4byte 0x030047A4
_080AAFA4:
	mov r0, r8
	bl FUN_080aad30
	cmp r0, #0
	beq _080AAFBE
	mov r1, r8
	ldr r0, [r1, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2, #0x24]
	b _080AAFC8
_080AAFBE:
	mov r3, r8
	ldr r0, [r3, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r3, #0x24]
_080AAFC8:
	movs r0, #0
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
