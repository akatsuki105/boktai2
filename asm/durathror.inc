	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080367cc
FUN_080367cc: @ 0x080367CC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r7, r5, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r4, #6]
	ands r0, r1
	cmp r0, #0
	beq _080367F2
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	b _08036812
_080367F2:
	movs r3, #0x24
	ldrsh r0, [r6, r3]
	movs r2, #0x24
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_08036812:
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08236524
	ldrh r1, [r6, #0x3e]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0xde
	ldrh r0, [r4, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x3e]
	ldr r1, [r4, #0x34]
	adds r0, r5, #0
	adds r0, #0xb4
	str r1, [r0]
	ldr r1, [r4, #0x38]
	adds r0, #4
	str r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08036844:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_08036848
FUN_08036848: @ 0x08036848
	push {lr}
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r0, r1
	bl FUN_08236424
	pop {r0}
	bx r0

	thumb_func_start FUN_08036858
FUN_08036858: @ 0x08036858
	adds r3, r0, #0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r3, #0x50]
	str r1, [r3, #0x54]
	movs r1, #0
	movs r2, #2
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08036884
FUN_08036884: @ 0x08036884
	push {lr}
	mov ip, r0
	ldr r3, _080368AC @ =0x085B0A08
	movs r0, #0xb6
	lsls r0, r0, #1
	add r0, ip
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080368B0
	asrs r0, r0, #0xc
	b _080368B6
	.align 2, 0
_080368AC: .4byte 0x085B0A08
_080368B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080368B6:
	movs r1, #0xb7
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080368c4
FUN_080368c4: @ 0x080368C4
	push {lr}
	adds r2, r0, #0
	movs r1, #0
	ldrsh r3, [r2, r1]
	ldr r1, _080368D8 @ =0x0000123F
	cmp r3, r1
	bgt _080368DC
	adds r1, #1
	b _080368E4
	.align 2, 0
_080368D8: .4byte 0x0000123F
_080368DC:
	movs r1, #0xc6
	lsls r1, r1, #5
	cmp r3, r1
	ble _080368E6
_080368E4:
	strh r1, [r2]
_080368E6:
	movs r1, #4
	ldrsh r3, [r2, r1]
	ldr r1, _080368F4 @ =0x0000023F
	cmp r3, r1
	bgt _080368F8
	adds r1, #1
	b _08036900
	.align 2, 0
_080368F4: .4byte 0x0000023F
_080368F8:
	movs r1, #0xd8
	lsls r1, r1, #3
	cmp r3, r1
	ble _08036902
_08036900:
	strh r1, [r2, #4]
_08036902:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08036908
FUN_08036908: @ 0x08036908
	push {lr}
	adds r2, r0, #0
	movs r1, #0
	ldrsh r3, [r2, r1]
	ldr r1, _0803691C @ =0x0000127F
	cmp r3, r1
	bgt _08036920
	adds r1, #1
	b _08036928
	.align 2, 0
_0803691C: .4byte 0x0000127F
_08036920:
	movs r1, #0xc4
	lsls r1, r1, #5
	cmp r3, r1
	ble _0803692A
_08036928:
	strh r1, [r2]
_0803692A:
	movs r1, #4
	ldrsh r3, [r2, r1]
	ldr r1, _08036938 @ =0x0000027F
	cmp r3, r1
	bgt _0803693C
	adds r1, #1
	b _08036944
	.align 2, 0
_08036938: .4byte 0x0000027F
_0803693C:
	movs r1, #0xd0
	lsls r1, r1, #3
	cmp r3, r1
	ble _08036946
_08036944:
	strh r1, [r2, #4]
_08036946:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0803694c
FUN_0803694c: @ 0x0803694C
	push {lr}
	adds r2, r0, #0
	movs r0, #4
	ldrsh r1, [r2, r0]
	ldr r0, _08036968 @ =0x0000047F
	cmp r1, r0
	bgt _08036974
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _0803696C @ =0x0000157F
	cmp r1, r0
	bgt _08036970
	movs r0, #0
	b _0803698A
	.align 2, 0
_08036968: .4byte 0x0000047F
_0803696C: .4byte 0x0000157F
_08036970:
	movs r0, #1
	b _0803698A
_08036974:
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _08036984 @ =0x0000157F
	cmp r1, r0
	ble _08036988
	movs r0, #3
	b _0803698A
	.align 2, 0
_08036984: .4byte 0x0000157F
_08036988:
	movs r0, #2
_0803698A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08036990
FUN_08036990: @ 0x08036990
	push {r4, r5, lr}
	ldr r5, _080369C8 @ =0x0203B400
	ldr r4, _080369CC @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _080369D0 @ =0x000003FF
	ands r1, r3
	lsls r2, r1, #1
	adds r2, r2, r5
	ldrh r2, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #1
	ands r2, r3
	ands r1, r3
	adds r2, r2, r1
	adds r2, #1
	adds r0, r0, r2
	movs r1, #3
	ands r0, r1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080369C8: .4byte 0x0203B400
_080369CC: .4byte 0x030046B8
_080369D0: .4byte 0x000003FF

	thumb_func_start FUN_080369d4
FUN_080369d4: @ 0x080369D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r1, #0
	ldr r0, _08036A44 @ =0x0203B400
	mov ip, r0
	ldr r1, _08036A48 @ =0x030046B8
	mov r8, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r5, _08036A4C @ =0x000003FF
	ands r1, r5
	lsls r0, r1, #1
	add r0, ip
	ldrh r3, [r0]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	add r0, ip
	ldrh r2, [r0]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	movs r4, #1
	ands r3, r4
	ands r2, r4
	adds r3, r3, r2
	ands r0, r4
	adds r3, r3, r0
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	add r0, ip
	ldrh r2, [r0]
	adds r1, #1
	ands r1, r5
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	ands r2, r4
	ands r0, r4
	adds r2, r2, r0
	lsls r3, r3, #8
	lsls r2, r2, #8
	cmp r6, #1
	beq _08036A6A
	cmp r6, #1
	bgt _08036A50
	cmp r6, #0
	beq _08036A5A
	b _08036A98
	.align 2, 0
_08036A44: .4byte 0x0203B400
_08036A48: .4byte 0x030046B8
_08036A4C: .4byte 0x000003FF
_08036A50:
	cmp r6, #2
	beq _08036A7C
	cmp r6, #3
	beq _08036A84
	b _08036A98
_08036A5A:
	movs r1, #0x94
	lsls r1, r1, #5
	adds r0, r3, r1
	strh r0, [r7]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r2, r1
	b _08036A96
_08036A6A:
	movs r1, #0xc4
	lsls r1, r1, #5
	adds r0, r1, #0
	subs r0, r0, r3
	strh r0, [r7]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r2, r1
	b _08036A96
_08036A7C:
	movs r1, #0x94
	lsls r1, r1, #5
	adds r0, r3, r1
	b _08036A8C
_08036A84:
	movs r1, #0xc4
	lsls r1, r1, #5
	adds r0, r1, #0
	subs r0, r0, r3
_08036A8C:
	strh r0, [r7]
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r1, #0
	subs r0, r0, r2
_08036A96:
	strh r0, [r7, #4]
_08036A98:
	adds r0, r7, #0
	bl FUN_08036908
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08036AC2
	cmp r1, #0
	blt _08036AC2
	ldr r0, _08036AC8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08036AC2
	ldr r0, _08036ACC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08036AD0
_08036AC2:
	movs r4, #0
	b _08036ADE
	.align 2, 0
_08036AC8: .4byte 0x030046A8
_08036ACC: .4byte 0x030046AC
_08036AD0:
	ldr r0, _08036AF0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08036ADE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08036AF4
	adds r0, #4
	b _08036B00
	.align 2, 0
_08036AF0: .4byte 0x030046A4
_08036AF4:
	ldr r0, _08036B14 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08036B00:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08036B18
	cmp r2, #2
	beq _08036B1C
	b _08036B20
	.align 2, 0
_08036B14: .4byte 0x030046A4
_08036B18:
	ldrb r0, [r7, #4]
	b _08036B1E
_08036B1C:
	ldrb r0, [r7]
_08036B1E:
	subs r1, r1, r0
_08036B20:
	strh r1, [r7, #2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08036b2c
FUN_08036b2c: @ 0x08036B2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r3, r1, #0
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r4, _08036C04 @ =0x0203B400
	mov sb, r4
	ldr r5, _08036C08 @ =0x030046B8
	ldr r4, [r5]
	adds r4, #1
	ldr r0, _08036C0C @ =0x000003FF
	mov r8, r0
	ands r4, r0
	lsls r0, r4, #1
	add r0, sb
	ldrh r1, [r0]
	add r0, sp, #0x18
	ldrh r0, [r0]
	subs r0, #0x40
	movs r5, #0x7f
	mov sl, r5
	mov r5, sl
	ands r1, r5
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08036C10 @ =0xFFFF0000
	mov ip, r1
	ldr r6, [sp, #0x18]
	ands r6, r1
	orrs r6, r0
	str r6, [sp, #0x18]
	adds r4, #1
	mov r5, r8
	ands r4, r5
	lsls r0, r4, #1
	add r0, sb
	ldrh r5, [r0]
	asrs r1, r6, #0x10
	adds r1, #0x80
	movs r0, #0x3f
	ands r5, r0
	adds r1, r1, r5
	lsls r1, r1, #0x10
	ldr r0, _08036C14 @ =0x0000FFFF
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x18]
	adds r4, #1
	mov r0, r8
	ands r4, r0
	ldr r1, _08036C08 @ =0x030046B8
	str r4, [r1]
	lsls r4, r4, #1
	add r4, sb
	ldrh r4, [r4]
	add r0, sp, #0x18
	ldrh r1, [r0, #4]
	subs r1, #0x40
	mov r5, sl
	ands r4, r5
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x1c]
	mov r4, ip
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x1c]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrb r1, [r0]
	movs r0, #6
	str r0, [sp]
	ldr r0, _08036C18 @ =0x00003001
	str r0, [sp, #4]
	movs r0, #0x30
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	movs r2, #0x10
	bl FUN_08015c28
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036C04: .4byte 0x0203B400
_08036C08: .4byte 0x030046B8
_08036C0C: .4byte 0x000003FF
_08036C10: .4byte 0xFFFF0000
_08036C14: .4byte 0x0000FFFF
_08036C18: .4byte 0x00003001

	thumb_func_start FUN_08036c1c
FUN_08036c1c: @ 0x08036C1C
	push {lr}
	sub sp, #0x10
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r3, _08036C48 @ =0x00004001
	movs r1, #0x40
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
	movs r1, #6
	movs r2, #7
	bl FUN_08015a90
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_08036C48: .4byte 0x00004001

	thumb_func_start FUN_08036c4c
FUN_08036c4c: @ 0x08036C4C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _08036C88 @ =0x0203B400
	mov r8, r0
	ldr r6, _08036C8C @ =0x030046B8
	ldr r0, [r6]
	adds r0, #1
	ldr r7, _08036C90 @ =0x000003FF
	ands r0, r7
	str r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	adds r0, r4, r0
	adds r4, r0, #1
	movs r0, #3
	ands r4, r0
	cmp r4, #1
	beq _08036CD4
	cmp r4, #1
	bgt _08036C94
	cmp r4, #0
	beq _08036C9E
	b _08036D66
	.align 2, 0
_08036C88: .4byte 0x0203B400
_08036C8C: .4byte 0x030046B8
_08036C90: .4byte 0x000003FF
_08036C94:
	cmp r4, #2
	beq _08036D14
	cmp r4, #3
	beq _08036D30
	b _08036D66
_08036C9E:
	ldr r1, [r6]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r3, #1
	ands r0, r3
	lsls r0, r0, #8
	movs r4, #0x94
	lsls r4, r4, #5
	adds r2, r4, #0
	adds r0, r0, r2
	strh r0, [r5]
	adds r1, #1
	ands r1, r7
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r3
	lsls r0, r0, #8
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r2, #0
	adds r0, r0, r1
	b _08036D64
_08036CD4:
	ldr r1, [r6]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	ldr r4, _08036D10 @ =0x0203B400
	adds r0, r0, r4
	ldrh r2, [r0]
	movs r3, #1
	ands r2, r3
	lsls r2, r2, #8
	movs r4, #0xc4
	lsls r4, r4, #5
	adds r0, r4, #0
	subs r0, r0, r2
	strh r0, [r5]
	adds r1, #1
	ands r1, r7
	str r1, [r6]
	lsls r1, r1, #1
	ldr r0, _08036D10 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	ands r0, r3
	lsls r0, r0, #8
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r2, #0
	adds r0, r0, r1
	b _08036D64
	.align 2, 0
_08036D10: .4byte 0x0203B400
_08036D14:
	ldr r1, [r6]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r3, #1
	ands r0, r3
	lsls r0, r0, #8
	movs r4, #0x94
	lsls r4, r4, #5
	adds r2, r4, #0
	adds r0, r0, r2
	b _08036D4A
_08036D30:
	ldr r1, [r6]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r3, #1
	ands r2, r3
	lsls r2, r2, #8
	movs r4, #0xc4
	lsls r4, r4, #5
	adds r0, r4, #0
	subs r0, r0, r2
_08036D4A:
	strh r0, [r5]
	adds r1, #1
	ands r1, r7
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	ands r1, r3
	lsls r1, r1, #8
	movs r2, #0xd0
	lsls r2, r2, #3
	adds r0, r2, #0
	subs r0, r0, r1
_08036D64:
	strh r0, [r5, #4]
_08036D66:
	adds r0, r5, #0
	bl FUN_08036908
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08036D90
	cmp r1, #0
	blt _08036D90
	ldr r0, _08036D94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08036D90
	ldr r0, _08036D98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08036D9C
_08036D90:
	movs r4, #0
	b _08036DAA
	.align 2, 0
_08036D94: .4byte 0x030046A8
_08036D98: .4byte 0x030046AC
_08036D9C:
	ldr r0, _08036DBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08036DAA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08036DC0
	adds r0, #4
	b _08036DCC
	.align 2, 0
_08036DBC: .4byte 0x030046A4
_08036DC0:
	ldr r0, _08036DE0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08036DCC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08036DE4
	cmp r2, #2
	beq _08036DE8
	b _08036DEC
	.align 2, 0
_08036DE0: .4byte 0x030046A4
_08036DE4:
	ldrb r0, [r5, #4]
	b _08036DEA
_08036DE8:
	ldrb r0, [r5]
_08036DEA:
	subs r1, r1, r0
_08036DEC:
	strh r1, [r5, #2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08036df8
FUN_08036df8: @ 0x08036DF8
	push {lr}
	movs r1, #0xdf
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08036E0C
	movs r1, #0
	bl Script_ExecById
_08036E0C:
	pop {r0}
	bx r0

	thumb_func_start FUN_08036e10
FUN_08036e10: @ 0x08036E10
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0
	ldr r2, _08036E38 @ =0x00000DFC
	adds r0, r3, r2
	ldr r2, [r0]
	cmp r1, r2
	bhs _08036E42
	movs r4, #0xe0
	lsls r4, r4, #4
	adds r0, r3, r4
	movs r4, #1
	ldr r3, [r0]
_08036E2A:
	adds r0, r4, #0
	lsls r0, r1
	ands r0, r3
	cmp r0, #0
	bne _08036E3C
	adds r0, r1, #0
	b _08036E46
	.align 2, 0
_08036E38: .4byte 0x00000DFC
_08036E3C:
	adds r1, #1
	cmp r1, r2
	blo _08036E2A
_08036E42:
	movs r0, #1
	rsbs r0, r0, #0
_08036E46:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08036e4c
FUN_08036e4c: @ 0x08036E4C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	adds r4, r1, #0
	bl FUN_08036e10
	adds r6, r0, #0
	ldr r0, _08036EB8 @ =0x00000DF4
	adds r7, r5, r0
	ldr r0, [r7]
	cmp r0, #0
	beq _08036EAE
	cmp r6, #0
	blt _08036EAE
	lsls r1, r6, #1
	ldr r2, _08036EBC @ =0x00000E04
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	str r0, [sp]
	movs r1, #0
	ldrsh r0, [r4, r1]
	str r0, [sp, #4]
	movs r2, #2
	ldrsh r0, [r4, r2]
	str r0, [sp, #8]
	movs r1, #4
	ldrsh r0, [r4, r1]
	str r0, [sp, #0xc]
	ldr r1, _08036EC0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r1, sp, #0x10
	mov r2, sp
	str r2, [r1, #4]
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r3, r5, r0
	movs r2, #1
	lsls r2, r6
	ldr r0, [r3]
	orrs r0, r2
	str r0, [r3]
	ldr r0, [r7]
	bl Script_ExecById
_08036EAE:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036EB8: .4byte 0x00000DF4
_08036EBC: .4byte 0x00000E04
_08036EC0: .4byte 0xFFFF0000

	thumb_func_start FUN_08036ec4
FUN_08036ec4: @ 0x08036EC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x48
	ldr r1, _08036FC4 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	movs r1, #0x94
	lsls r1, r1, #5
	orrs r0, r1
	ldr r1, _08036FC8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xfa
	lsls r1, r1, #0x14
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r0, _08036FCC @ =0x0203B400
	mov sl, r0
	ldr r1, _08036FD0 @ =0x030046B8
	mov sb, r1
	ldr r2, _08036FD4 @ =0x000003FF
	mov r8, r2
	add r4, sp, #0x14
	movs r7, #6
_08036EFE:
	mov r0, sb
	ldr r1, [r0]
	adds r1, #1
	mov r2, r8
	ands r1, r2
	lsls r0, r1, #1
	add r0, sl
	ldrh r2, [r0]
	movs r0, #7
	ands r2, r0
	lsls r2, r2, #0x18
	movs r0, #0xfa
	lsls r0, r0, #0x14
	adds r2, r2, r0
	ldr r3, _08036FC8 @ =0x0000FFFF
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x14]
	adds r1, #1
	mov r2, r8
	ands r1, r2
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	add r1, sl
	ldrh r0, [r1]
	movs r1, #5
	bl Mod
	lsls r0, r0, #0x18
	movs r1, #0xa0
	lsls r1, r1, #0x12
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	ldr r2, _08036FC4 @ =0xFFFF0000
	ldr r1, [r4, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r4, #4]
	movs r2, #8
	ldrsh r1, [r6, r2]
	movs r2, #0
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08036F5E
	rsbs r1, r1, #0
_08036F5E:
	cmp r1, #0xff
	bgt _08036F76
	movs r0, #0xc
	ldrsh r1, [r6, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08036F72
	rsbs r1, r1, #0
_08036F72:
	cmp r1, #0xff
	ble _08036FA2
_08036F76:
	movs r0, #0x30
	str r0, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #8]
	adds r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r0, #0
	movs r1, #2
	movs r2, #2
	movs r3, #0x3c
	bl FUN_0800e594
_08036FA2:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	subs r7, #1
	cmp r7, #0
	bge _08036EFE
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08036FC4: .4byte 0xFFFF0000
_08036FC8: .4byte 0x0000FFFF
_08036FCC: .4byte 0x0203B400
_08036FD0: .4byte 0x030046B8
_08036FD4: .4byte 0x000003FF

	thumb_func_start FUN_08036fd8
FUN_08036fd8: @ 0x08036FD8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	mov r8, r1
	adds r5, r2, #0
	ldr r4, [r7, #0x38]
	cmp r1, #0
	bne _080370DC
	adds r6, r4, #0
	adds r6, #0x90
	ldrh r0, [r6]
	subs r0, r0, r5
	movs r1, #0
	mov sb, r1
	strh r0, [r6]
	cmp r5, #0
	ble _08037032
	ldr r3, _08037094 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _08037098 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r2, #0x84
	lsls r2, r2, #2
	adds r0, r4, r2
	adds r3, r7, #0
	adds r3, #8
	add r1, sp, #8
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0805fe7c
_08037032:
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #0
	bgt _080370A0
	movs r3, #0x82
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r1, [r0]
	movs r5, #0xac
	lsls r5, r5, #1
	adds r0, r4, r5
	strb r1, [r0]
	movs r2, #2
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #1
	movs r1, #3
	adds r0, r4, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	mov r3, sb
	strb r3, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	mov r5, r8
	str r5, [r0]
	subs r0, #0x14
	strb r2, [r0]
	ldr r1, _0803709C @ =durathror_0803b024
	movs r0, #0x10
	adds r3, r4, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	movs r0, #0
	b _0803711A
	.align 2, 0
_08037094: .4byte 0xFFFF0000
_08037098: .4byte 0x0000FFFF
_0803709C: .4byte durathror_0803b024
_080370A0:
	movs r1, #1
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	mov r2, sb
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	mov r3, r8
	str r3, [r0]
	subs r0, #0x14
	strb r1, [r0]
	ldr r2, _080370D8 @ =bee_0803aee4
	movs r0, #0xe
	adds r3, r4, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	mov r5, r8
	str r5, [r0]
	adds r0, #0x1d
	b _08037116
	.align 2, 0
_080370D8: .4byte bee_0803aee4
_080370DC:
	movs r3, #1
	movs r1, #0
	movs r2, #2
	adds r0, r4, #0
	adds r0, #0xa4
	strb r3, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r3, [r0]
	ldr r2, _08037128 @ =FUN_0803af44
	movs r0, #0xf
	movs r5, #0xa3
	strb r0, [r5, r4]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	ldrb r1, [r7, #5]
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r4, r2
_08037116:
	strb r1, [r0]
	movs r0, #1
_0803711A:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08037128: .4byte FUN_0803af44

	thumb_func_start FUN_0803712c
FUN_0803712c: @ 0x0803712C
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #2
	bl FUN_08022a2c
	cmp r0, #0
	beq _08037144
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #2
	beq _08037148
_08037144:
	movs r0, #0
	b _0803716A
_08037148:
	movs r3, #0x80
	lsls r3, r3, #6
	movs r0, #0x40
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08015a90
	movs r0, #1
_0803716A:
	add sp, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08037174
FUN_08037174: @ 0x08037174
	push {r4, r5, r6, r7, lr}
	movs r0, #2
	bl FUN_08022a2c
	adds r5, r0, #0
	cmp r5, #0
	beq _080371C8
	adds r0, #0x97
	ldrb r0, [r0]
	cmp r0, #2
	bne _080371C8
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r3, #0
	ldr r0, _080371D0 @ =0x00000DFC
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r3, r0
	bhs _080371C8
	movs r0, #0xe0
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r6, r1, #0
	adds r0, #4
	adds r2, r5, r0
	movs r5, #1
_080371AE:
	ldrh r0, [r2]
	cmp r0, r7
	bne _080371BE
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
_080371BE:
	adds r2, #2
	adds r3, #1
	ldr r0, [r6]
	cmp r3, r0
	blo _080371AE
_080371C8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080371D0: .4byte 0x00000DFC

	thumb_func_start FUN_080371d4
FUN_080371d4: @ 0x080371D4
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x18
	mov sl, r0
	ldr r3, _080372A4 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0xa4
	orrs r0, r2
	ldr r1, _080372A8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x14]
	ldr r6, _080372AC @ =0x0203B400
	ldr r0, _080372B0 @ =0x030046B8
	mov sb, r0
	ldr r0, [r0]
	adds r0, #1
	ldr r5, _080372B4 @ =0x000003FF
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r2, #3
	mov r8, r2
	ands r1, r2
	adds r1, #2
	adds r0, #1
	ands r0, r5
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, #0x14
	str r1, [sp]
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	movs r1, #3
	add r2, sp, #0x10
	bl FUN_080ddcc8
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	mov r2, r8
	ands r1, r2
	adds r1, #2
	adds r0, #1
	ands r0, r5
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	adds r0, #0x14
	str r1, [sp]
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sl
	movs r1, #3
	add r2, sp, #0x10
	bl FUN_080ddcc8
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080372A4: .4byte 0xFFFF0000
_080372A8: .4byte 0x0000FFFF
_080372AC: .4byte 0x0203B400
_080372B0: .4byte 0x030046B8
_080372B4: .4byte 0x000003FF

	thumb_func_start FUN_080372b8
FUN_080372b8: @ 0x080372B8
	ldrb r2, [r0, #5]
	orrs r1, r2
	strb r1, [r0, #5]
	bx lr

	thumb_func_start FUN_080372c0
FUN_080372c0: @ 0x080372C0
	ldrb r0, [r0, #5]
	ands r0, r1
	bx lr
	.align 2, 0

	thumb_func_start FUN_080372c8
FUN_080372c8: @ 0x080372C8
	movs r2, #0
	strb r1, [r0, #2]
	str r2, [r0, #0x10]
	movs r1, #1
	strb r1, [r0, #3]
	bx lr

	thumb_func_start FUN_080372d4
FUN_080372d4: @ 0x080372D4
	push {lr}
	adds r1, r0, #0
	ldrb r0, [r1, #3]
	cmp r0, #0
	bne _080372E2
	movs r0, #0
	b _080372E8
_080372E2:
	movs r0, #0
	strb r0, [r1, #3]
	movs r0, #1
_080372E8:
	pop {r1}
	bx r1

	thumb_func_start FUN_080372ec
FUN_080372ec: @ 0x080372EC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	movs r1, #6
	ldrsh r0, [r5, r1]
	cmp r0, #0
	ble _08037398
	adds r0, r6, #0
	adds r0, #0x90
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #6
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	adds r0, r6, #0
	bl FUN_08022bb0
	ldrh r0, [r5, #0xe]
	subs r0, #1
	movs r4, #0
	strh r0, [r5, #0xe]
	ldr r3, _08037390 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _08037394 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r0, #0xd4
	movs r2, #6
	ldrsh r1, [r5, r2]
	adds r3, r5, #0
	adds r3, #0x44
	add r2, sp, #8
	str r2, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
	strh r4, [r5, #6]
	movs r0, #0xa
	strh r0, [r5, #0x18]
	strh r0, [r5, #0x1a]
	movs r0, #5
	strb r0, [r5, #8]
	adds r1, r5, #0
	adds r1, #0x5e
	movs r0, #0xfe
	lsls r0, r0, #7
	strh r0, [r1]
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r0, r6, r1
	str r0, [r5, #0x6c]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_0824078c
	ldrb r0, [r5]
	cmp r0, #0
	beq _08037380
	adds r0, r6, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x29
	ble _08037388
_08037380:
	movs r2, #0xe
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bgt _08037398
_08037388:
	ldrh r0, [r5, #0xc]
	strh r0, [r5, #0xe]
	movs r0, #1
	b _0803739A
	.align 2, 0
_08037390: .4byte 0xFFFF0000
_08037394: .4byte 0x0000FFFF
_08037398:
	movs r0, #0
_0803739A:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080373a4
FUN_080373a4: @ 0x080373A4
	adds r1, #0x24
	ldr r2, _080373B4 @ =0x00006543
	strh r2, [r1, #0x3a]
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [r1, #0x48]
	bx lr
	.align 2, 0
_080373B4: .4byte 0x00006543
_080373B8:
	.byte 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_080373bc
FUN_080373bc: @ 0x080373BC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r0, #2
	bl FUN_08022a2c
	adds r7, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08236524
	ldrh r0, [r4, #0x3e]
	strh r0, [r6, #6]
	movs r1, #2
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080373EA
	adds r0, r6, #0
	adds r0, #0x44
	bl FUN_080371d4
_080373EA:
	cmp r7, #0
	beq _080373FA
	adds r1, r7, #0
	adds r1, #0xde
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
_080373FA:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08037400
FUN_08037400: @ 0x08037400
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x84
	ldr r2, _08037494 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08037498 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _0803749C @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r1, r4, #0
	adds r1, #0x44
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080374A0 @ =0x080373B9
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	movs r1, #0xd3
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	str r0, [sp]
	movs r3, #0xd5
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037494: .4byte 0xFFFF0000
_08037498: .4byte 0x0000FFFF
_0803749C: .4byte 0x00002001
_080374A0: .4byte 0x080373B9

	thumb_func_start FUN_080374a4
FUN_080374a4: @ 0x080374A4
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0xd4
	ldr r2, _08037528 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _0803752C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08037530 @ =0x00005005
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r1, r5, #0
	adds r1, #0x44
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08037534 @ =FUN_080373bc
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r6, r6, r0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037528: .4byte 0xFFFF0000
_0803752C: .4byte 0x0000FFFF
_08037530: .4byte 0x00005005
_08037534: .4byte FUN_080373bc

	thumb_func_start FUN_08037538
FUN_08037538: @ 0x08037538
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, [sp, #0x28]
	ldr r7, [sp, #0x2c]
	movs r1, #0
	strb r2, [r4]
	strb r3, [r4, #2]
	strh r0, [r4, #0xc]
	strh r0, [r4, #0xe]
	str r1, [r4, #0x14]
	adds r6, r4, #0
	adds r6, #0x24
	movs r0, #0x98
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r8, r0
	movs r0, #2
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r6, #0
	mov r1, r8
	movs r2, #0
	movs r3, #1
	bl FUN_0822f3fc
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	mov r1, r8
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08037400
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080374a4
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080375a4
FUN_080375a4: @ 0x080375A4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x24
	bl FUN_0822f1c0
	adds r4, #0xd4
	adds r0, r4, #0
	bl FUN_08236424
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080375bc
FUN_080375bc: @ 0x080375BC
	push {lr}
	adds r3, r0, #0
	adds r3, #0x24
	ldr r1, [r3, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r3, #8]
	movs r1, #0
	bl FUN_080372c8
	pop {r0}
	bx r0

	thumb_func_start FUN_080375d4
FUN_080375d4: @ 0x080375D4
	push {r4, r5, r6, lr}
	sub sp, #8
	mov ip, r0
	mov r6, ip
	adds r6, #0x24
	ldr r2, _08037618 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803761C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08037620 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r3, ip
	ldrb r1, [r3, #8]
	mov r3, sp
	ldrb r4, [r0]
	lsls r5, r1, #2
	ldr r1, _08037624 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08037628
	asrs r2, r0, #0xc
	b _0803762E
	.align 2, 0
_08037618: .4byte 0x030046B8
_0803761C: .4byte 0x000003FF
_08037620: .4byte 0x0203B400
_08037624: .4byte 0x085B0A08
_08037628:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0803762E:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _08037646
	asrs r0, r0, #0xc
	b _0803764C
_08037646:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803764C:
	strh r0, [r3, #4]
	adds r3, r6, #0
	adds r3, #0x20
	mov r2, ip
	adds r2, #0x1c
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r5, ip
	ldrh r5, [r5, #0x1c]
	adds r0, r0, r5
	strh r0, [r6, #0x20]
	ldrh r0, [r1, #2]
	ldrh r4, [r2, #2]
	adds r0, r0, r4
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803767c
FUN_0803767c: @ 0x0803767C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0x14]
	movs r0, #0
	str r0, [sp, #0x18]
	ldr r7, _080376E4 @ =0x0203B400
	ldr r2, _080376E8 @ =0x030046B8
	mov sl, r2
	ldr r6, _080376EC @ =0x000003FF
	movs r3, #0xff
	mov sb, r3
	add r5, sp, #0xc
	adds r1, #0x44
	mov r8, r1
_080376A0:
	mov r4, sl
	ldr r0, [r4]
	adds r0, #1
	ands r0, r6
	lsls r1, r0, #1
	adds r1, r1, r7
	ldrh r2, [r1]
	adds r0, #1
	ands r0, r6
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	mov r0, sb
	ands r2, r0
	adds r3, r1, #0
	adds r3, #0x20
	ldr r1, _080376F0 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	mov r4, sb
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080376F4
	asrs r1, r0, #0xc
	b _080376FA
	.align 2, 0
_080376E4: .4byte 0x0203B400
_080376E8: .4byte 0x030046B8
_080376EC: .4byte 0x000003FF
_080376F0: .4byte 0x085B0A08
_080376F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080376FA:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	mov r4, sb
	ands r2, r4
	lsls r0, r2, #1
	ldr r1, _08037718 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _0803771C
	asrs r2, r0, #0xc
	b _08037722
	.align 2, 0
_08037718: .4byte 0x085B0A08
_0803771C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08037722:
	mov r3, r8
	ldrh r0, [r3]
	ldrh r4, [r5]
	adds r0, r0, r4
	strh r0, [r5]
	ldrh r1, [r5, #2]
	ldrh r0, [r3, #2]
	adds r1, r1, r0
	ldrh r0, [r3, #4]
	adds r0, r2, r0
	strh r0, [r5, #4]
	adds r1, #0x80
	strh r1, [r5, #2]
	mov r0, sl
	ldr r3, [r0]
	adds r3, #1
	ands r3, r6
	lsls r0, r3, #1
	adds r0, r0, r7
	ldrh r1, [r0]
	mov r2, sb
	ands r1, r2
	adds r3, #1
	ands r3, r6
	lsls r0, r3, #1
	adds r0, r0, r7
	ldrh r2, [r0]
	movs r4, #3
	ands r2, r4
	adds r2, #8
	mov ip, r2
	adds r3, #1
	ands r3, r6
	mov r0, sl
	str r3, [r0]
	lsls r3, r3, #1
	adds r3, r3, r7
	ldrh r3, [r3]
	ands r3, r4
	ldr r2, [sp, #0x14]
	ldr r4, _080377B4 @ =0x00000DE8
	adds r0, r2, r4
	ldr r0, [r0]
	ldr r2, [sp, #0x18]
	lsls r2, r2, #3
	str r2, [sp, #0x1c]
	adds r4, r2, #0
	adds r4, #0x1e
	str r4, [sp]
	movs r2, #0xb1
	lsls r2, r2, #1
	ldr r4, [sp, #0x14]
	adds r2, r4, r2
	ldrb r4, [r2]
	str r4, [sp, #4]
	str r5, [sp, #8]
	mov r2, ip
	bl FUN_08060220
	ldr r3, [sp, #0x18]
	adds r3, #1
	str r3, [sp, #0x18]
	cmp r3, #3
	bgt _080377A4
	b _080376A0
_080377A4:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080377B4: .4byte 0x00000DE8

	thumb_func_start FUN_080377b8
FUN_080377b8: @ 0x080377B8
	push {r4, r5, lr}
	movs r1, #0xc9
	lsls r1, r1, #3
	adds r4, r0, r1
	movs r5, #5
_080377C2:
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _0803780A
	ldrb r0, [r4]
	cmp r0, #0
	bne _0803780A
	ldrb r0, [r4, #2]
	cmp r0, #6
	beq _080377E8
	cmp r0, #6
	ble _080377DE
	cmp r0, #7
	beq _08037802
	b _0803780A
_080377DE:
	cmp r0, #4
	bgt _0803780A
	cmp r0, #2
	blt _0803780A
	b _080377EE
_080377E8:
	ldrb r0, [r4, #4]
	cmp r0, #4
	bne _080377F8
_080377EE:
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080372c8
	b _0803780A
_080377F8:
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080372c8
	b _0803780A
_08037802:
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080372c8
_0803780A:
	subs r5, #1
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0
	bge _080377C2
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803781c
FUN_0803781c: @ 0x0803781C
	push {r4, r5, lr}
	movs r1, #0xc9
	lsls r1, r1, #3
	adds r4, r0, r1
	movs r5, #5
_08037826:
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _0803783A
	ldrb r0, [r4]
	cmp r0, #0
	bne _0803783A
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_080372c8
_0803783A:
	subs r5, #1
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0
	bge _08037826
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803784c
FUN_0803784c: @ 0x0803784C
	push {r4, r5, lr}
	movs r1, #0xc9
	lsls r1, r1, #3
	adds r4, r0, r1
	movs r5, #5
_08037856:
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _08037868
	ldrb r0, [r4]
	cmp r0, #0
	bne _08037868
	adds r0, r4, #0
	bl FUN_080375bc
_08037868:
	subs r5, #1
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0
	bge _08037856
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803787c
FUN_0803787c: @ 0x0803787C
	push {lr}
	adds r0, r1, #0
	bl FUN_080372d4
	pop {r0}
	bx r0

	thumb_func_start FUN_08037888
FUN_08037888: @ 0x08037888
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_080372d4
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080372b8
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	bne _080378AA
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080372c8
	b _080378AE
_080378AA:
	subs r0, #1
	strh r0, [r4, #0xa]
_080378AE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080378b4
FUN_080378b4: @ 0x080378B4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x24
	adds r0, r4, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _08037904
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	ldrh r0, [r5, #0x22]
	subs r0, #0x78
	strh r0, [r5, #0x22]
	ldrb r0, [r4]
	cmp r0, #0
	beq _080378FE
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [r6, #0x50]
	str r1, [r6, #0x54]
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _080378FE
	adds r0, r6, #0
	bl FUN_08036df8
_080378FE:
	ldr r0, _08037920 @ =0x0000017B
	bl PlaySound_0824078c
_08037904:
	ldr r0, [r4, #0x10]
	cmp r0, #0xe
	bls _08037924
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080372ec
	cmp r0, #0
	beq _0803792C
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _0803792C
	strb r0, [r4, #9]
	b _0803792C
	.align 2, 0
_08037920: .4byte 0x0000017B
_08037924:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080372b8
_0803792C:
	ldr r0, [r4, #0x10]
	cmp r0, #0x1d
	bhi _08037964
	cmp r0, #0xe
	bls _0803793C
	ldrh r0, [r5, #0x22]
	adds r0, #8
	strh r0, [r5, #0x22]
_0803793C:
	ldr r0, [r4, #0x10]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08037964
	add r2, sp, #4
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x24]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldrh r0, [r2, #2]
	adds r0, #0xa4
	strh r0, [r2, #2]
	movs r0, #0xd2
	lsls r0, r0, #4
	adds r2, r6, r0
	movs r0, #0
	add r1, sp, #4
	bl FUN_080155e4
_08037964:
	ldr r0, [r4, #0x10]
	cmp r0, #0xf
	bne _08037976
	ldr r0, [r5, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #8]
	b _08037990
_08037976:
	cmp r0, #0x1e
	bne _08037984
	adds r0, r5, #0
	movs r1, #0x60
	bl FUN_0823723c
	b _08037990
_08037984:
	cmp r0, #0x2d
	bne _08037990
	adds r0, r5, #0
	movs r1, #0x80
	bl FUN_0823723c
_08037990:
	ldr r0, [r4, #0x10]
	cmp r0, #0x5f
	bls _0803799E
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080372c8
_0803799E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080379a8
FUN_080379a8: @ 0x080379A8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r1, #0
	adds r6, r7, #0
	adds r5, r4, #0
	adds r5, #0x24
	adds r0, r4, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _080379D4
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #1
	movs r3, #1
	bl FUN_082370cc
_080379D4:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080372b8
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080372ec
	cmp r0, #0
	beq _080379FA
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _080379FA
	strb r0, [r4, #9]
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_080372c8
	b _08037A40
_080379FA:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08037A22
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _08037A22
	movs r0, #0xa1
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r0, [r4, #0x44]
	ldr r1, [r4, #0x48]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x80
	lsls r2, r2, #0xa
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08037A22:
	ldr r0, [r4, #0x10]
	cmp r0, #0xe
	bls _08037A40
	ldrb r0, [r4, #1]
	cmp r0, #1
	bne _08037A38
	adds r0, r4, #0
	movs r1, #6
	bl FUN_080372c8
	b _08037A40
_08037A38:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080372c8
_08037A40:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08037a48
FUN_08037a48: @ 0x08037A48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r5, #0
	movs r0, #0x24
	adds r0, r0, r4
	mov sl, r0
	adds r0, r4, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _08037AC6
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	str r0, [sp]
	mov r0, sl
	movs r2, #1
	movs r3, #1
	bl FUN_082370cc
	ldr r3, _08037B04 @ =0x00000DDC
	adds r1, r5, r3
	movs r3, #0
	movs r2, #0
	movs r0, #0x3c
	strh r0, [r1]
	ldr r1, _08037B08 @ =0x00000DDE
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xde
	lsls r2, r2, #4
	adds r0, r5, r2
	strb r3, [r0]
	ldr r2, _08037B0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08037B10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08037B14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #0x17
	ldr r2, _08037B18 @ =0x00000DE1
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _08037B1C @ =0x00000DE2
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08037B20 @ =0x00000DE3
	adds r0, r5, r1
	strb r3, [r0]
_08037AC6:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080372b8
	ldrb r0, [r4]
	cmp r0, #0
	beq _08037ADE
	adds r0, r5, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x54
	ble _08037AFA
_08037ADE:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080372ec
	cmp r0, #0
	beq _08037B24
	ldrb r0, [r4]
	cmp r0, #0
	beq _08037B24
	adds r0, r6, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x54
	bgt _08037B24
_08037AFA:
	adds r0, r4, #0
	movs r1, #9
	bl FUN_080372c8
	b _08037DF8
	.align 2, 0
_08037B04: .4byte 0x00000DDC
_08037B08: .4byte 0x00000DDE
_08037B0C: .4byte 0x030046B8
_08037B10: .4byte 0x000003FF
_08037B14: .4byte 0x0203B400
_08037B18: .4byte 0x00000DE1
_08037B1C: .4byte 0x00000DE2
_08037B20: .4byte 0x00000DE3
_08037B24:
	ldr r2, _08037B98 @ =0x00000DE2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08037B30
	b _08037CD6
_08037B30:
	mov r3, sl
	ldrb r1, [r3, #0x1d]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08037B3E
	b _08037C3C
_08037B3E:
	movs r4, #0xde
	lsls r4, r4, #4
	adds r1, r5, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _08037C3C
	ldr r0, _08037B9C @ =0x00000DE1
	adds r2, r5, r0
	ldrb r0, [r2]
	subs r0, #0x10
	strb r0, [r2]
	add r3, sp, #4
	mov r4, sl
	ldr r0, [r4, #0x20]
	ldr r1, [r4, #0x24]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldrh r0, [r3, #2]
	adds r0, #0x40
	strh r0, [r3, #2]
	ldrb r2, [r2]
	add r4, sp, #0xc
	add r7, sp, #0x14
	movs r0, #3
	mov sb, r0
	adds r6, r3, #0
_08037B7A:
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	ldr r3, _08037BA0 @ =0x085B0A08
	adds r1, r1, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	lsls r1, r1, #6
	mov r8, r0
	cmp r1, #0
	blt _08037BA4
	asrs r1, r1, #0xc
	b _08037BAA
	.align 2, 0
_08037B98: .4byte 0x00000DE2
_08037B9C: .4byte 0x00000DE1
_08037BA0: .4byte 0x085B0A08
_08037BA4:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08037BAA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	ldr r1, _08037BCC @ =0x085B0A08
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0x40
	muls r0, r1, r0
	cmp r0, #0
	blt _08037BD0
	asrs r0, r0, #0xc
	b _08037BD6
	.align 2, 0
_08037BCC: .4byte 0x085B0A08
_08037BD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08037BD6:
	strh r0, [r4, #4]
	add r1, sp, #0xc
	ldrh r0, [r6]
	ldrh r1, [r1]
	adds r0, r0, r1
	add r1, sp, #0x14
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r6, #4]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
	ldr r1, _08037CA0 @ =0x00000DE4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0xcf
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	str r7, [sp]
	movs r3, #0x14
	bl FUN_0805d80c
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r2, r8
	mov r1, sb
	cmp r1, #0
	bge _08037B7A
	ldr r2, _08037CA4 @ =0x00000DDC
	adds r4, r5, r2
	ldr r0, [r4]
	cmp r0, #0
	bne _08037C2C
	movs r0, #0xbd
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08037C2C:
	movs r3, #0xde
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_08037C3C:
	ldr r4, _08037CA4 @ =0x00000DDC
	adds r3, r5, r4
	ldrh r1, [r3]
	movs r0, #3
	ands r0, r1
	cmp r0, #3
	bne _08037C6A
	ldr r2, _08037CA8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08037CAC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08037CB0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #0x17
	ldr r2, _08037CB4 @ =0x00000DE1
	adds r1, r5, r2
	strb r0, [r1]
_08037C6A:
	ldrh r0, [r3]
	cmp r0, #7
	bhi _08037C72
	b _08037DF8
_08037C72:
	movs r2, #0
	strh r2, [r3]
	ldr r3, _08037CB8 @ =0x00000DDE
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _08037CC0
	strh r2, [r1]
	ldr r4, _08037CBC @ =0x00000DE2
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
	str r0, [sp]
	mov r0, sl
	b _08037CCE
	.align 2, 0
_08037CA0: .4byte 0x00000DE4
_08037CA4: .4byte 0x00000DDC
_08037CA8: .4byte 0x030046B8
_08037CAC: .4byte 0x000003FF
_08037CB0: .4byte 0x0203B400
_08037CB4: .4byte 0x00000DE1
_08037CB8: .4byte 0x00000DDE
_08037CBC: .4byte 0x00000DE2
_08037CC0:
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	str r0, [sp]
	mov r0, sl
	movs r2, #0x2c
_08037CCE:
	movs r3, #1
	bl FUN_082370cc
	b _08037DF8
_08037CD6:
	ldr r3, _08037CF4 @ =0x00000DE3
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08037D14
	ldr r1, _08037CF8 @ =0x00000DDC
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x10
	bne _08037CFC
	mov r0, sl
	movs r1, #0x80
	bl FUN_0823723c
	b _08037D14
	.align 2, 0
_08037CF4: .4byte 0x00000DE3
_08037CF8: .4byte 0x00000DDC
_08037CFC:
	cmp r0, #0x16
	bne _08037D14
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	str r0, [sp]
	mov r0, sl
	movs r2, #1
	movs r3, #1
	bl FUN_082370cc
_08037D14:
	ldr r3, _08037D48 @ =0x00000DE3
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #1
	bhi _08037D5C
	ldr r1, _08037D4C @ =0x00000DDC
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x60
	bne _08037D50
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	str r0, [sp]
	mov r0, sl
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	mov r0, sl
	movs r1, #0x80
	bl FUN_0823723c
	b _08037D5C
	.align 2, 0
_08037D48: .4byte 0x00000DE3
_08037D4C: .4byte 0x00000DDC
_08037D50:
	cmp r0, #0x70
	bne _08037D5C
	mov r0, sl
	movs r1, #0x40
	bl FUN_0823723c
_08037D5C:
	ldr r3, _08037DB8 @ =0x00000DDC
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	movs r3, #0
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7d
	bls _08037DF8
	strh r2, [r1]
	ldr r1, _08037DBC @ =0x00000DDE
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xde
	lsls r2, r2, #4
	adds r0, r5, r2
	strb r3, [r0]
	ldr r2, _08037DC0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08037DC4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08037DC8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #0x17
	ldr r2, _08037DCC @ =0x00000DE1
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _08037DD0 @ =0x00000DE3
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _08037DD4
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080372c8
	b _08037DEE
	.align 2, 0
_08037DB8: .4byte 0x00000DDC
_08037DBC: .4byte 0x00000DDE
_08037DC0: .4byte 0x030046B8
_08037DC4: .4byte 0x000003FF
_08037DC8: .4byte 0x0203B400
_08037DCC: .4byte 0x00000DE1
_08037DD0: .4byte 0x00000DE3
_08037DD4:
	ldr r2, _08037E08 @ =0x00000DE2
	adds r0, r5, r2
	strb r3, [r0]
	movs r3, #0x98
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #4
	str r0, [sp]
	mov r0, sl
	movs r2, #0x2c
	movs r3, #1
	bl FUN_082370cc
_08037DEE:
	ldr r4, _08037E0C @ =0x00000DE3
	adds r1, r5, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08037DF8:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037E08: .4byte 0x00000DE2
_08037E0C: .4byte 0x00000DE3

	thumb_func_start FUN_08037e10
FUN_08037e10: @ 0x08037E10
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x24
	adds r0, r4, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _08037E4C
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r5, #0
	movs r1, #0x80
	bl FUN_0823723c
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _08037E4C
	bl FUN_081a4e88
_08037E4C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080372b8
	ldr r0, [r4, #0x10]
	cmp r0, #0x2d
	bne _08037E64
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_0823723c
	b _08037E70
_08037E64:
	cmp r0, #0x1e
	bne _08037E70
	adds r0, r5, #0
	movs r1, #0x60
	bl FUN_0823723c
_08037E70:
	ldr r0, [r4, #0x10]
	subs r0, #0x2d
	cmp r0, #0xe
	bhi _08037E7E
	ldrh r0, [r5, #0x22]
	subs r0, #8
	strh r0, [r5, #0x22]
_08037E7E:
	ldr r0, [r4, #0x10]
	cmp r0, #9
	bls _08037EB6
	cmp r0, #0xa
	bne _08037E8E
	ldr r0, _08037EDC @ =0x0000017B
	bl PlaySound_0824078c
_08037E8E:
	ldr r0, [r4, #0x10]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08037EB6
	add r2, sp, #4
	ldr r0, [r5, #0x20]
	ldr r1, [r5, #0x24]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldrh r0, [r2, #2]
	adds r0, #0x40
	strh r0, [r2, #2]
	movs r0, #0xd2
	lsls r0, r0, #4
	adds r2, r6, r0
	movs r0, #0
	add r1, sp, #4
	bl FUN_080155e4
_08037EB6:
	ldr r0, [r4, #0x10]
	cmp r0, #0x3b
	bls _08037ED2
	ldrb r0, [r4]
	cmp r0, #0
	beq _08037ECC
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x3c
	strh r0, [r1]
_08037ECC:
	adds r0, r4, #0
	bl FUN_080375bc
_08037ED2:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08037EDC: .4byte 0x0000017B

	thumb_func_start FUN_08037ee0
FUN_08037ee0: @ 0x08037EE0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r4, r1, #0
	mov r8, r5
	adds r6, r4, #0
	adds r6, #0x24
	adds r0, r4, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _08037F14
	movs r0, #0
	strb r0, [r4, #4]
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #2
	movs r3, #2
	bl FUN_082370cc
_08037F14:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080372b8
	ldrb r0, [r4]
	cmp r0, #0
	beq _08037F2C
	adds r0, r5, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x29
	ble _08037F3C
_08037F2C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080372ec
	cmp r0, #0
	beq _08037F46
	movs r0, #1
	strb r0, [r4, #9]
_08037F3C:
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_080372c8
	b _08038070
_08037F46:
	ldrb r0, [r4]
	adds r7, r0, #0
	ldr r3, [r4, #0x10]
	cmp r7, #0
	beq _08037FA8
	ldrb r0, [r4, #4]
	adds r1, r0, #0
	adds r2, r0, #0
	cmp r1, #4
	bne _08037F64
	movs r0, #0xf
	ands r0, r3
	cmp r0, #0xf
	bne _08037F84
	b _08037F80
_08037F64:
	cmp r1, #3
	bne _08037F74
	movs r0, #0x1f
	ands r0, r3
	cmp r0, #0x1f
	bne _08037F84
	movs r0, #4
	b _08037F82
_08037F74:
	cmp r1, #1
	bne _08037F84
	movs r0, #0x3f
	ands r0, r3
	cmp r0, #0x1f
	bne _08037F84
_08037F80:
	movs r0, #3
_08037F82:
	strb r0, [r4, #8]
_08037F84:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08037FA8
	movs r1, #0xa1
	lsls r1, r1, #3
	adds r2, r5, r1
	ldr r0, [r4, #0x44]
	ldr r1, [r4, #0x48]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x80
	lsls r2, r2, #0xa
	mov r1, r8
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08037FA8:
	movs r0, #0x3f
	ands r3, r0
	cmp r3, #0x3f
	bne _08038070
	ldrb r0, [r4, #4]
	adds r1, r0, #1
	strb r1, [r4, #4]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _08037FC8
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080372c8
	b _08038070
_08037FC8:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bne _08038016
	lsls r0, r7, #0x18
	cmp r0, #0
	beq _08038012
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r2, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x20
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0x24
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	subs r0, #1
	movs r1, #3
	ands r0, r1
	adds r2, r0, #7
	b _0803801A
_08038012:
	movs r2, #0x2d
	b _0803801A
_08038016:
	ldrb r0, [r4, #4]
	adds r2, r0, #2
_0803801A:
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r7, #1
	str r7, [sp]
	adds r0, r6, #0
	movs r3, #2
	bl FUN_082370cc
	ldrb r0, [r4, #4]
	cmp r0, #5
	bne _08038070
	add r2, sp, #0x14
	ldr r0, [r6, #0x20]
	ldr r1, [r6, #0x24]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldrh r0, [r2, #2]
	adds r0, #0x80
	strh r0, [r2, #2]
	movs r2, #0x80
	lsls r2, r2, #1
	movs r0, #6
	str r0, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	movs r1, #0xd3
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	add r0, sp, #0x14
	str r0, [sp, #0x10]
	movs r0, #8
	movs r1, #0
	movs r3, #8
	bl FUN_08056774
	ldr r0, _0803807C @ =0x0000017D
	bl PlaySound_0824078c
_08038070:
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803807C: .4byte 0x0000017D

	thumb_func_start FUN_08038080
FUN_08038080: @ 0x08038080
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	mov sb, r5
	movs r0, #0x24
	adds r0, r0, r4
	mov r8, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _080380DA
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	adds r3, r4, #0
	adds r3, #0x44
	movs r6, #0
	ldrsh r0, [r2, r6]
	movs r6, #0
	ldrsh r1, [r3, r6]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r2, r6]
	movs r6, #4
	ldrsh r2, [r3, r6]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	subs r6, r0, #1
	movs r0, #3
	ands r6, r0
	b _080380DC
_080380DA:
	movs r6, #0
_080380DC:
	adds r0, r4, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _08038150
	ldrb r0, [r4]
	cmp r0, #0
	beq _08038104
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r2, r6, #0
	adds r2, #0xb
	movs r0, #4
	str r0, [sp]
	mov r0, r8
	movs r3, #1
	bl FUN_082370cc
	b _08038118
_08038104:
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	str r0, [sp]
	mov r0, r8
	movs r2, #0x2e
	movs r3, #1
	bl FUN_082370cc
_08038118:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08038138
	adds r0, r4, #0
	adds r0, #0xd4
	movs r2, #0xdb
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #4
	movs r3, #0
	bl FUN_08236514
	b _08038150
_08038138:
	adds r0, r4, #0
	adds r0, #0xd4
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #4
	movs r3, #0
	bl FUN_08236514
_08038150:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080372b8
	ldrb r0, [r4]
	cmp r0, #0
	beq _08038168
	mov r0, sb
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x29
	ble _08038186
_08038168:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080372ec
	adds r7, r0, #0
	cmp r7, #0
	beq _0803819A
	ldrb r0, [r4]
	cmp r0, #0
	beq _08038190
	mov r0, sb
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x29
	bgt _08038190
_08038186:
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_080372c8
	b _080381F2
_08038190:
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080372c8
	b _080381F2
_0803819A:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080381E4
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r2, r6, #0
	adds r2, #0xb
	movs r0, #1
	str r0, [sp]
	mov r0, r8
	movs r3, #1
	bl FUN_082370cc
	ldrb r0, [r4]
	cmp r0, #0
	beq _080381E4
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _080381D4
	ldr r0, [r4, #0x10]
	cmp r0, #0xb3
	bls _080381F2
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080372c8
	strb r7, [r4, #9]
	b _080381F2
_080381D4:
	ldr r0, [r4, #0x10]
	cmp r0, #7
	bls _080381F2
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080372c8
	b _080381F2
_080381E4:
	ldr r0, [r4, #0x10]
	cmp r0, #0x3b
	bls _080381F2
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080372c8
_080381F2:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08038200
FUN_08038200: @ 0x08038200
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x24
	ldrb r0, [r5]
	cmp r0, #0
	beq _08038250
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	adds r3, r5, #0
	adds r3, #0x44
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	subs r4, r0, #1
	movs r0, #3
	ands r4, r0
	b _08038252
_08038250:
	movs r4, #0
_08038252:
	adds r0, r5, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _080382C6
	ldrb r0, [r5]
	cmp r0, #0
	beq _0803827A
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r2, r4, #0
	adds r2, #0xf
	movs r0, #4
	str r0, [sp]
	adds r0, r7, #0
	movs r3, #2
	bl FUN_082370cc
	b _0803828E
_0803827A:
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r0, #4
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #0x2f
	movs r3, #2
	bl FUN_082370cc
_0803828E:
	ldrb r0, [r5]
	cmp r0, #0
	beq _080382AE
	adds r0, r5, #0
	adds r0, #0xd4
	movs r4, #0xd9
	lsls r4, r4, #1
	adds r1, r6, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #4
	movs r3, #0
	bl FUN_08236514
	b _080382C6
_080382AE:
	adds r0, r5, #0
	adds r0, #0xd4
	movs r4, #0xda
	lsls r4, r4, #1
	adds r1, r6, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #4
	movs r3, #0
	bl FUN_08236514
_080382C6:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080372b8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080372b8
	ldrb r1, [r7, #0x1d]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080382E8
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080372c8
_080382E8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080382f0
FUN_080382f0: @ 0x080382F0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x24
	adds r0, r4, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _08038322
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #1
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0xbf
	lsls r0, r0, #1
	bl PlaySound_0824078c
_08038322:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080372b8
	ldr r0, [r4, #0x10]
	cmp r0, #0x3b
	bls _08038346
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803834E
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080372c8
	b _0803834E
_08038346:
	cmp r0, #0x1d
	bhi _0803834E
	movs r0, #8
	strb r0, [r4, #8]
_0803834E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start bee_08038358
bee_08038358: @ 0x08038358
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	mov r8, r0
	adds r6, r1, #0
	movs r0, #0x24
	adds r0, r0, r6
	mov sb, r0
	adds r0, r6, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _0803838C
	ldrb r0, [r6, #4]
	cmp r0, #4
	bne _08038384
	mov r0, r8
	adds r1, r6, #0
	bl FUN_0803767c
_08038384:
	movs r0, #0xbf
	lsls r0, r0, #1
	bl PlaySound_0824078c
_0803838C:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_080372b8
	ldr r0, [r6, #0x10]
	cmp r0, #0x1d
	bhi _0803839C
	b _08038500
_0803839C:
	movs r4, #3
	ands r4, r0
	cmp r4, #3
	beq _080383A6
	b _08038504
_080383A6:
	ldrb r0, [r6, #4]
	cmp r0, #4
	bls _0803841C
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _080383FE
	ldrb r0, [r6]
	cmp r0, #0
	bne _080383FE
	add r2, sp, #0x14
	mov r3, sb
	ldr r0, [r3, #0x20]
	ldr r1, [r3, #0x24]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldrh r0, [r2, #2]
	adds r0, #0x80
	movs r4, #0
	strh r0, [r2, #2]
	movs r2, #0x80
	lsls r2, r2, #1
	movs r0, #6
	str r0, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	movs r0, #0xd3
	lsls r0, r0, #1
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	add r0, sp, #0x14
	str r0, [sp, #0x10]
	movs r0, #8
	movs r1, #0
	movs r3, #8
	bl FUN_08056774
	strb r4, [r6, #9]
	ldr r0, _08038418 @ =0x0000017D
	bl PlaySound_0824078c
_080383FE:
	movs r0, #0xb1
	lsls r0, r0, #1
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803840C
	b _08038504
_0803840C:
	adds r0, r6, #0
	movs r1, #7
	bl FUN_080372c8
	b _08038504
	.align 2, 0
_08038418: .4byte 0x0000017D
_0803841C:
	adds r0, #1
	strb r0, [r6, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bne _080384D8
	ldrb r0, [r6]
	cmp r0, #0
	beq _0803846C
	movs r0, #0x86
	lsls r0, r0, #1
	add r0, r8
	ldr r2, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r3, sb
	movs r5, #0x20
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	mov r5, sb
	movs r3, #0x24
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	subs r0, #1
	ands r0, r4
	adds r7, r0, #7
	b _0803846E
_0803846C:
	movs r7, #0x2d
_0803846E:
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _080384DC
	ldrb r0, [r6]
	cmp r0, #0
	bne _080384DC
	add r3, sp, #0x1c
	mov r5, sb
	adds r5, #0x20
	mov r2, sb
	ldr r0, [r2, #0x20]
	ldr r1, [r2, #0x24]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	ldrh r0, [r3, #2]
	adds r0, #0x80
	movs r4, #0
	strh r0, [r3, #2]
	movs r2, #0x80
	lsls r2, r2, #1
	movs r0, #6
	str r0, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	movs r0, #0xd3
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	movs r0, #8
	movs r1, #0
	movs r3, #8
	bl FUN_08056774
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08036e4c
	strb r4, [r6, #9]
	movs r0, #0xf2
	lsls r0, r0, #2
	bl PlaySound_0824078c
	ldr r0, _080384D4 @ =0x0000017D
	bl PlaySound_0824078c
	b _080384DC
	.align 2, 0
_080384D4: .4byte 0x0000017D
_080384D8:
	ldrb r0, [r6, #4]
	adds r7, r0, #2
_080384DC:
	movs r1, #0x98
	lsls r1, r1, #2
	add r1, r8
	adds r2, r7, #0
	movs r0, #1
	str r0, [sp]
	mov r0, sb
	movs r3, #2
	bl FUN_082370cc
	ldrb r0, [r6, #4]
	cmp r0, #4
	bne _08038504
	mov r0, r8
	adds r1, r6, #0
	bl FUN_0803767c
	b _08038504
_08038500:
	movs r0, #8
	strb r0, [r6, #8]
_08038504:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start bee_08038514
bee_08038514: @ 0x08038514
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x24
	ldrb r0, [r5]
	cmp r0, #0
	beq _08038564
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r2, [r0]
	adds r3, r5, #0
	adds r3, #0x44
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	subs r4, r0, #1
	movs r0, #3
	ands r4, r0
	b _08038566
_08038564:
	movs r4, #0
_08038566:
	adds r0, r5, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _080385C4
	ldrb r0, [r5]
	cmp r0, #0
	beq _080385A0
	movs r0, #0x98
	lsls r0, r0, #2
	adds r1, r6, r0
	adds r2, r4, #0
	adds r2, #0xb
	movs r0, #4
	str r0, [sp]
	adds r0, r7, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r6, #0
	bl FUN_080377b8
	ldr r0, _0803859C @ =0x00000173
	bl PlaySound_0824078c
	b _080385B4
	.align 2, 0
_0803859C: .4byte 0x00000173
_080385A0:
	movs r4, #0x98
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r0, #4
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #0x2e
	movs r3, #1
	bl FUN_082370cc
_080385B4:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0803767c
	movs r0, #0xbf
	lsls r0, r0, #1
	bl PlaySound_0824078c
_080385C4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080372b8
	ldr r0, [r5, #0x10]
	cmp r0, #0x1e
	bhi _080385D6
	movs r0, #8
	strb r0, [r5, #8]
_080385D6:
	movs r1, #0xb1
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080385F0
	ldr r0, [r5, #0x10]
	cmp r0, #0x1d
	bls _080385F0
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080372c8
_080385F0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080385f8
FUN_080385f8: @ 0x080385F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	adds r6, r1, #0
	movs r0, #0x24
	adds r0, r0, r6
	mov r8, r0
	adds r0, r6, #0
	bl FUN_080372d4
	cmp r0, #0
	beq _080386F8
	ldrb r0, [r6]
	cmp r0, #0
	beq _080386E8
	adds r0, r7, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r2, r7, #0
	adds r2, #0x4d
	movs r1, #0
	mov sb, r1
	strb r0, [r2]
	ldrb r0, [r2]
	adds r0, #0x20
	movs r4, #0xff
	ands r0, r4
	asrs r0, r0, #6
	adds r0, #1
	movs r3, #3
	mov sl, r3
	mov r1, sl
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #0x10
	ands r0, r4
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r5, #0x86
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r2, [r0]
	adds r3, r6, #0
	adds r3, #0x44
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r2, #4
	ldrsh r3, [r3, r2]
	subs r1, r1, r3
	bl FUN_0823785c
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r2, #0x20
	ands r2, r4
	asrs r2, r2, #6
	adds r2, #1
	mov r3, sl
	ands r2, r3
	subs r2, #1
	movs r0, #3
	ands r2, r0
	movs r4, #0x98
	lsls r4, r4, #2
	adds r1, r7, r4
	adds r2, #0x13
	movs r0, #4
	str r0, [sp]
	mov r0, r8
	movs r3, #1
	bl FUN_082370cc
	movs r5, #0xb1
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r4, #1
	strb r4, [r0]
	adds r0, r7, #0
	bl FUN_0803781c
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080386DC @ =0x00000161
	adds r0, r7, r2
	mov r3, sb
	strb r3, [r0]
	ldr r0, _080386E0 @ =0x00000179
	bl PlaySound_0824078c
	ldr r0, _080386E4 @ =0x00000173
	bl PlaySound_0824078c
	b _080386F0
	.align 2, 0
_080386DC: .4byte 0x00000161
_080386E0: .4byte 0x00000179
_080386E4: .4byte 0x00000173
_080386E8:
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_0803767c
_080386F0:
	movs r0, #0xbf
	lsls r0, r0, #1
	bl PlaySound_0824078c
_080386F8:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_080372b8
	ldrb r0, [r6]
	cmp r0, #0
	bne _08038708
	b _08038852
_08038708:
	ldr r0, [r6, #0x10]
	cmp r0, #0x3f
	bls _08038720
	adds r0, r6, #0
	bl FUN_080375bc
	adds r1, r6, #0
	adds r1, #0x44
	adds r0, r7, #0
	bl FUN_08036858
	b _08038744
_08038720:
	cmp r0, #0x30
	bne _08038744
	adds r0, r7, #0
	bl FUN_0803784c
	ldr r4, _080387A0 @ =0x00000DF8
	adds r0, r7, r4
	ldr r0, [r0]
	cmp r0, #0
	beq _08038744
	movs r1, #0
	bl Script_ExecById
	movs r5, #0xe0
	lsls r5, r5, #4
	adds r1, r7, r5
	movs r0, #0
	str r0, [r1]
_08038744:
	ldr r0, [r6, #0x10]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08038750
	b _08038852
_08038750:
	ldr r4, _080387A4 @ =0x0203B400
	ldr r3, _080387A8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080387AC @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	mov ip, r5
	ldrb r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	add r4, sp, #0xc
	adds r1, #0x20
	mov r8, r1
	ldr r1, _080387B0 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	mov r2, ip
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	mov ip, r3
	cmp r0, #0
	blt _080387B4
	asrs r2, r0, #0xc
	b _080387BA
	.align 2, 0
_080387A0: .4byte 0x00000DF8
_080387A4: .4byte 0x0203B400
_080387A8: .4byte 0x030046B8
_080387AC: .4byte 0x000003FF
_080387B0: .4byte 0x085B0A08
_080387B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080387BA:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r5, r8
	muls r5, r0, r5
	adds r0, r5, #0
	cmp r0, #0
	blt _080387D6
	asrs r0, r0, #0xc
	b _080387DC
_080387D6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080387DC:
	strh r0, [r4, #4]
	add r3, sp, #0xc
	adds r2, r6, #0
	adds r2, #0x44
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	ldrh r2, [r3, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	adds r1, #0x80
	strh r1, [r3, #2]
	ldr r4, _0803886C @ =0x0203B400
	mov r3, ip
	ldr r0, [r3]
	adds r0, #1
	ldr r3, _08038870 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r3
	lsls r2, r0, #1
	adds r2, r2, r4
	ldrh r2, [r2]
	movs r5, #0xf
	ands r2, r5
	adds r2, #0x10
	adds r0, #1
	ands r0, r3
	mov r3, ip
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	ands r3, r5
	adds r3, #4
	ldr r4, _08038874 @ =0x00000DE8
	adds r0, r7, r4
	ldr r0, [r0]
	movs r4, #0x3c
	str r4, [sp]
	movs r5, #0xb1
	lsls r5, r5, #1
	adds r4, r7, r5
	ldrb r4, [r4]
	str r4, [sp, #4]
	add r4, sp, #0xc
	str r4, [sp, #8]
	bl FUN_08060220
_08038852:
	ldr r0, [r6, #0x10]
	cmp r0, #0x1d
	bhi _0803885C
	movs r0, #8
	strb r0, [r6, #8]
_0803885C:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803886C: .4byte 0x0203B400
_08038870: .4byte 0x000003FF
_08038874: .4byte 0x00000DE8

	thumb_func_start FUN_08038878
FUN_08038878: @ 0x08038878
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #4
	ldr r0, _08038928 @ =0x03002BC0
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _08038892
	b _080389A0
_08038892:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r2, [r0]
	movs r2, #0xc9
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r0, #0
	mov sb, r0
	mov sl, r0
	ldr r1, _0803892C @ =0x0000068C
	adds r1, r1, r7
	mov r8, r1
	adds r2, #0xda
	adds r6, r7, r2
_080388B0:
	ldrb r0, [r5, #2]
	adds r4, r5, #0
	adds r4, #0xd4
	cmp r0, #0
	beq _0803898C
	mov r0, sl
	strb r0, [r5, #5]
	ldr r1, _08038930 @ =0x085AAE30
	ldrb r0, [r5, #2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	bl _call_via_r3
	adds r0, r5, #0
	adds r0, #0x24
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r7, r2
	bl FUN_082372cc
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	beq _080388F2
	subs r0, #1
	strh r0, [r5, #0x18]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080372b8
_080388F2:
	ldrh r1, [r5, #0x1a]
	movs r2, #0x1a
	ldrsh r0, [r5, r2]
	cmp r0, #0
	ble _0803890E
	subs r0, r1, #1
	strh r0, [r5, #0x1a]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0803890E
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_080373a4
_0803890E:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080372c0
	cmp r0, #0
	beq _08038934
	ldrh r0, [r6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r6]
	mov r2, sl
	strh r2, [r5, #6]
	b _08038948
	.align 2, 0
_08038928: .4byte 0x03002BC0
_0803892C: .4byte 0x0000068C
_08038930: .4byte 0x085AAE30
_08038934:
	ldrh r1, [r6]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r6]
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
_08038948:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080372c0
	cmp r0, #0
	beq _08038968
	adds r4, r5, #0
	adds r4, #0x84
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_08038968:
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _0803897A
	adds r0, r5, #0
	bl FUN_080375d4
	ldrb r0, [r5, #8]
	subs r0, #1
	strb r0, [r5, #8]
_0803897A:
	ldr r0, [r5, #0x10]
	adds r0, #1
	str r0, [r5, #0x10]
	movs r0, #0xba
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803898C:
	movs r1, #1
	add sb, r1
	movs r2, #0x92
	lsls r2, r2, #1
	add r8, r2
	adds r6, r6, r2
	adds r5, r5, r2
	mov r0, sb
	cmp r0, #5
	ble _080388B0
_080389A0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080389b0
FUN_080389b0: @ 0x080389B0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	movs r0, #0xd2
	lsls r0, r0, #4
	adds r6, r7, r0
	movs r1, #0
	movs r5, #7
	strh r5, [r6]
	movs r2, #0xc0
	lsls r2, r2, #6
	strh r2, [r6, #2]
	movs r4, #0x40
	strh r4, [r6, #6]
	strh r1, [r6, #8]
	strh r1, [r6, #0xa]
	movs r0, #3
	strh r0, [r6, #0xc]
	strh r0, [r6, #0xe]
	strh r1, [r6, #0x10]
	strh r1, [r6, #0x12]
	strh r1, [r6, #0x14]
	strh r4, [r6, #0x16]
	movs r3, #0x80
	lsls r3, r3, #2
	strh r3, [r6, #0x18]
	strh r1, [r6, #0x1a]
	strh r1, [r6, #0x1c]
	strh r1, [r6, #0x1e]
	strh r3, [r6, #0x20]
	strh r1, [r6, #0x22]
	strh r1, [r6, #0x24]
	strh r1, [r6, #0x26]
	ldr r0, _08038A5C @ =0x00000D48
	adds r6, r7, r0
	strh r5, [r6]
	strh r2, [r6, #2]
	strh r4, [r6, #6]
	movs r2, #1
	strh r2, [r6, #8]
	strh r2, [r6, #0xa]
	movs r0, #4
	strh r0, [r6, #0xc]
	strh r2, [r6, #0xe]
	strh r4, [r6, #0x10]
	strh r1, [r6, #0x12]
	strh r1, [r6, #0x14]
	strh r4, [r6, #0x16]
	strh r3, [r6, #0x18]
	strh r1, [r6, #0x1a]
	strh r1, [r6, #0x1c]
	strh r1, [r6, #0x1e]
	strh r3, [r6, #0x20]
	strh r1, [r6, #0x22]
	strh r1, [r6, #0x24]
	strh r1, [r6, #0x26]
	movs r1, #0xc9
	lsls r1, r1, #3
	adds r4, r7, r1
	movs r5, #5
_08038A28:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0x50
	str r0, [sp, #4]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08037538
	subs r5, #1
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0
	bge _08038A28
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038A5C: .4byte 0x00000D48

	thumb_func_start FUN_08038a60
FUN_08038a60: @ 0x08038A60
	push {r4, r5, lr}
	movs r1, #0xc9
	lsls r1, r1, #3
	adds r4, r0, r1
	movs r5, #5
_08038A6A:
	adds r0, r4, #0
	bl FUN_080375a4
	subs r5, #1
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0
	bge _08038A6A
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08038a84
FUN_08038a84: @ 0x08038A84
	push {lr}
	movs r2, #0xc9
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r2, #0
	movs r3, #0x92
	lsls r3, r3, #1
_08038A92:
	ldrb r0, [r1, #2]
	cmp r0, #0
	bne _08038A9C
	adds r0, r1, #0
	b _08038AA6
_08038A9C:
	adds r2, #1
	adds r1, r1, r3
	cmp r2, #5
	ble _08038A92
	movs r0, #0
_08038AA6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08038aac
FUN_08038aac: @ 0x08038AAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r1
	adds r7, r2, #0
	adds r6, r3, #0
	bl FUN_08038a84
	adds r4, r0, #0
	cmp r4, #0
	beq _08038B48
	movs r1, #1
	bl FUN_080372c8
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x44]
	str r1, [r4, #0x48]
	movs r0, #0
	strb r7, [r4, #1]
	strb r0, [r4, #8]
	strb r6, [r4]
	strb r0, [r4, #9]
	ldr r0, [sp, #0x18]
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0xc]
	strh r0, [r4, #0xe]
	lsls r0, r6, #0x18
	cmp r0, #0
	beq _08038B1E
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x50]
	str r1, [r5, #0x54]
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _08038B04
	adds r0, r4, #0
	adds r0, #0xd4
	movs r2, #0xd8
	lsls r2, r2, #1
	b _08038B0C
_08038B04:
	adds r0, r4, #0
	adds r0, #0xd4
	movs r2, #0xd9
	lsls r2, r2, #1
_08038B0C:
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #4
	movs r3, #0
	bl FUN_08236514
	b _08038B36
_08038B1E:
	adds r0, r4, #0
	adds r0, #0xd4
	movs r2, #0xda
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #4
	movs r3, #0
	bl FUN_08236514
_08038B36:
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080373a4
_08038B48:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08038b54
FUN_08038b54: @ 0x08038B54
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #2
	add r0, sp, #4
	movs r2, #4
	bl FUN_0823556c
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	add r1, sp, #4
	movs r2, #0
	movs r3, #1
	bl FUN_08038aac
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08038b88
FUN_08038b88: @ 0x08038B88
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	ldr r6, _08038C20 @ =0x0203B400
	ldr r4, _08038C24 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _08038C28 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r7, [r0]
	movs r0, #0x3f
	ands r7, r0
	movs r0, #5
	bl FUN_08234f44
	mov sl, r0
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r1, #0xc5
	lsls r1, r1, #1
	add r1, sb
	ldr r0, _08038C2C @ =0x03002CF0
	ldr r0, [r0]
	adds r0, #1
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0xf
	ands r2, r1
	adds r6, r0, r2
	mov r0, sl
	ldrb r1, [r0]
	adds r0, r6, #0
	bl Mod
	adds r6, r0, #0
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	add r0, sp, #4
	movs r1, #5
	bl FUN_08234f90
	add r5, sp, #4
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08038C1A
	cmp r1, #0
	blt _08038C1A
	ldr r0, _08038C30 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08038C1A
	ldr r0, _08038C34 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08038C38
_08038C1A:
	movs r4, #0
	b _08038C46
	.align 2, 0
_08038C20: .4byte 0x0203B400
_08038C24: .4byte 0x030046B8
_08038C28: .4byte 0x000003FF
_08038C2C: .4byte 0x03002CF0
_08038C30: .4byte 0x030046A8
_08038C34: .4byte 0x030046AC
_08038C38:
	ldr r0, _08038C58 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08038C46:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08038C5C
	adds r0, #4
	b _08038C68
	.align 2, 0
_08038C58: .4byte 0x030046A4
_08038C5C:
	ldr r0, _08038C7C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08038C68:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08038C80
	cmp r2, #2
	beq _08038C84
	b _08038C88
	.align 2, 0
_08038C7C: .4byte 0x030046A4
_08038C80:
	ldrb r0, [r5, #4]
	b _08038C86
_08038C84:
	ldrb r0, [r5]
_08038C86:
	subs r1, r1, r0
_08038C88:
	add r0, sp, #4
	movs r4, #0
	strh r1, [r0, #2]
	str r7, [sp]
	mov r0, sb
	add r1, sp, #4
	movs r2, #1
	movs r3, #1
	bl FUN_08038aac
	ldr r0, _08038D10 @ =0x0000018B
	add r0, sb
	strb r4, [r0]
	movs r1, #0
	mov r8, r1
	add r5, sp, #4
_08038CA8:
	ldr r2, _08038D14 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08038D18 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _08038D1C @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	adds r3, r6, #1
	movs r2, #1
	ands r1, r2
	ldr r0, _08038D20 @ =0x03002CF0
	ldr r0, [r0]
	mov r4, r8
	lsrs r0, r4
	ands r0, r2
	adds r1, r1, r0
	adds r6, r3, r1
	mov r0, sl
	ldrb r1, [r0]
	adds r0, r6, #0
	bl Mod
	adds r6, r0, #0
	lsls r2, r6, #0x18
	lsrs r2, r2, #0x18
	add r0, sp, #4
	movs r1, #5
	bl FUN_08234f90
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08038D0C
	cmp r1, #0
	blt _08038D0C
	ldr r0, _08038D24 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08038D0C
	ldr r0, _08038D28 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08038D2C
_08038D0C:
	movs r4, #0
	b _08038D3A
	.align 2, 0
_08038D10: .4byte 0x0000018B
_08038D14: .4byte 0x030046B8
_08038D18: .4byte 0x000003FF
_08038D1C: .4byte 0x0203B400
_08038D20: .4byte 0x03002CF0
_08038D24: .4byte 0x030046A8
_08038D28: .4byte 0x030046AC
_08038D2C:
	ldr r0, _08038D4C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08038D3A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08038D50
	adds r0, #4
	b _08038D5C
	.align 2, 0
_08038D4C: .4byte 0x030046A4
_08038D50:
	ldr r0, _08038D70 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08038D5C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08038D74
	cmp r2, #2
	beq _08038D78
	b _08038D7C
	.align 2, 0
_08038D70: .4byte 0x030046A4
_08038D74:
	ldrb r0, [r5, #4]
	b _08038D7A
_08038D78:
	ldrb r0, [r5]
_08038D7A:
	subs r1, r1, r0
_08038D7C:
	strh r1, [r5, #2]
	movs r0, #0x3f
	ands r0, r7
	str r0, [sp]
	mov r0, sb
	add r1, sp, #4
	movs r2, #1
	movs r3, #0
	bl FUN_08038aac
	ldr r1, _08038DBC @ =0x0000018B
	add r1, sb
	ldrb r0, [r1]
	cmp r0, r7
	bge _08038D9C
	strb r7, [r1]
_08038D9C:
	adds r7, #0x10
	movs r1, #1
	add r8, r1
	mov r4, r8
	cmp r4, #3
	bgt _08038DAA
	b _08038CA8
_08038DAA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08038DBC: .4byte 0x0000018B

	thumb_func_start FUN_08038dc0
FUN_08038dc0: @ 0x08038DC0
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r2, _08038E5C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08038E60 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x81
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08038E64 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08038E68 @ =0x08036845
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	movs r1, #0xca
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0
	str r0, [sp]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08038E5C: .4byte 0xFFFF0000
_08038E60: .4byte 0x0000FFFF
_08038E64: .4byte 0x00002001
_08038E68: .4byte 0x08036845

	thumb_func_start FUN_08038e6c
FUN_08038e6c: @ 0x08038E6C
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0x84
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r2, _08038EEC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08038EF0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08038EF4 @ =0x00005101
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08038EF8 @ =FUN_080367cc
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	ldr r2, _08038EFC @ =0x00000801
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #2
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08038EEC: .4byte 0xFFFF0000
_08038EF0: .4byte 0x0000FFFF
_08038EF4: .4byte 0x00005101
_08038EF8: .4byte FUN_080367cc
_08038EFC: .4byte 0x00000801

	thumb_func_start FUN_08038f00
FUN_08038f00: @ 0x08038F00
	bx lr
	.align 2, 0

	thumb_func_start FUN_08038f04
FUN_08038f04: @ 0x08038F04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	mov r8, r5
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r7, r5, r0
	movs r6, #0
	ldr r0, _08038F24 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r5, r2
	b _080390DC
	.align 2, 0
_08038F24: .4byte 0x03002B4C
_08038F28:
	ldr r0, _08038F58 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08022474
	ldrb r0, [r4, #6]
	cmp r0, #0x16
	bls _08038F4E
	b _080390D2
_08038F4E:
	lsls r0, r0, #2
	ldr r1, _08038F5C @ =_08038F60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08038F58: .4byte 0x03002B4C
_08038F5C: .4byte _08038F60
_08038F60: @ jump table
	.4byte _08038FBC @ case 0
	.4byte _08039000 @ case 1
	.4byte _08038FD4 @ case 2
	.4byte _080390D2 @ case 3
	.4byte _080390D2 @ case 4
	.4byte _0803905E @ case 5
	.4byte _080390D2 @ case 6
	.4byte _08039086 @ case 7
	.4byte _0803908E @ case 8
	.4byte _08039096 @ case 9
	.4byte _0803903C @ case 10
	.4byte _080390D2 @ case 11
	.4byte _080390D2 @ case 12
	.4byte _080390D2 @ case 13
	.4byte _080390D2 @ case 14
	.4byte _080390D2 @ case 15
	.4byte _080390D2 @ case 16
	.4byte _080390D2 @ case 17
	.4byte _080390D2 @ case 18
	.4byte _080390D2 @ case 19
	.4byte _080390D2 @ case 20
	.4byte _080390D2 @ case 21
	.4byte _080390B2 @ case 22
_08038FBC:
	movs r2, #2
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	b _080390CA
_08038FD4:
	ldrb r0, [r4, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #1
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	subs r0, #0x14
	strb r2, [r0]
	b _080390D2
_08039000:
	ldrh r0, [r4, #8]
	adds r1, r5, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrh r0, [r4, #0xa]
	adds r3, r5, #0
	adds r3, #0x52
	strh r0, [r3]
	ldrh r0, [r4, #0xc]
	adds r2, r5, #0
	adds r2, #0x54
	strh r0, [r2]
	ldrh r1, [r1]
	movs r0, #0xa8
	lsls r0, r0, #2
	add r0, r8
	strh r1, [r0]
	ldrh r1, [r3]
	ldr r0, _08039038 @ =0x000002A2
	add r0, r8
	strh r1, [r0]
	ldrh r1, [r2]
	movs r0, #0xa9
	lsls r0, r0, #2
	add r0, r8
	strh r1, [r0]
	b _080390A4
	.align 2, 0
_08039038: .4byte 0x000002A2
_0803903C:
	ldrb r0, [r4, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0
	strb r0, [r1]
	movs r1, #2
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	b _080390C6
_0803905E:
	ldrb r0, [r4, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	strb r0, [r1]
	movs r1, #2
	movs r2, #3
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	b _080390CA
_08039086:
	movs r1, #2
	movs r2, #0
	movs r3, #4
	b _080390B8
_0803908E:
	movs r1, #2
	movs r2, #0
	movs r3, #5
	b _080390B8
_08039096:
	movs r0, #8
	ldrsh r1, [r4, r0]
	adds r0, r5, #0
	movs r2, #0xb4
	movs r3, #0xb4
	bl FUN_080230d8
_080390A4:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #1
	bl FUN_08022488
	b _080390D2
_080390B2:
	movs r1, #2
	movs r2, #0
	movs r3, #6
_080390B8:
	adds r0, r5, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r3, [r0]
_080390C6:
	adds r0, #0x16
	str r2, [r0]
_080390CA:
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_080390D2:
	adds r6, #1
	ldr r0, _080390F4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_080390DC:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _080390E8
	b _08038F28
_080390E8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080390F4: .4byte 0x03002B4C

	thumb_func_start FUN_080390f8
FUN_080390f8: @ 0x080390F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	mov r8, r6
	adds r4, r6, #0
	adds r4, #0x48
	bl FUN_08038f04
	adds r0, r4, #0
	bl FUN_0823b4b8
	adds r0, r6, #0
	adds r0, #0xab
	ldrb r0, [r0]
	cmp r0, #0
	bne _08039124
	adds r0, r6, #0
	adds r0, #0x50
	bl FUN_080368c4
_08039124:
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0x98
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r6, #0
	bl FUN_08022dfc
	ldrh r1, [r4, #8]
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0xb7
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	ldrh r1, [r4, #0xa]
	adds r0, r0, r1
	adds r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	ldrh r1, [r4, #0xc]
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _0803920C
	subs r0, r2, #1
	strh r0, [r1]
	ldr r4, _080391B4 @ =0x0203B400
	ldr r3, _080391B8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080391BC @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	movs r0, #0xf
	mov r4, sp
	adds r7, r1, #0
	ands r3, r0
	ldr r1, _080391C0 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080391C4
	asrs r2, r0, #0xc
	b _080391CA
	.align 2, 0
_080391B4: .4byte 0x0203B400
_080391B8: .4byte 0x030046B8
_080391BC: .4byte 0x000003FF
_080391C0: .4byte 0x085B0A08
_080391C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080391CA:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080391E2
	asrs r0, r0, #0xc
	b _080391E8
_080391E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080391E8:
	strh r0, [r4, #4]
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r1, r6, r2
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
_0803920C:
	mov r0, r8
	bl FUN_08022e20
	mov r2, r8
	adds r2, #0x48
	movs r7, #0x86
	lsls r7, r7, #1
	add r7, r8
	ldr r1, [r7]
	cmp r1, #0
	beq _08039254
	movs r3, #0
	ldrsh r5, [r1, r3]
	movs r3, #8
	ldrsh r0, [r2, r3]
	subs r5, r5, r0
	movs r0, #4
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r2, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	mov r1, r8
	adds r1, #0xc8
	strb r0, [r1]
	mov r2, r8
	adds r2, #0xc0
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08039254:
	mov r0, r8
	adds r0, #0x50
	bl FUN_0803694c
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, [r7]
	bl FUN_0803694c
	ldr r3, _0803927C @ =0x0000018D
	adds r1, r6, r3
	strb r0, [r1]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803927C: .4byte 0x0000018D

	thumb_func_start FUN_08039280
FUN_08039280: @ 0x08039280
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r5, r7, #0
	bl FUN_08022ec0
	adds r0, r7, #0
	bl FUN_08038878
	movs r0, #0xad
	lsls r0, r0, #1
	adds r3, r7, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080392B0
	movs r2, #4
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
_080392B0:
	movs r1, #0x84
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #4
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _080392D0
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _080392E8
_080392D0:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
_080392E8:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r4, r5, r3
	movs r1, #8
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08039302
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _08039320
_08039302:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_08039320:
	movs r1, #0x10
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08039344
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	movs r2, #0xd7
	lsls r2, r2, #4
	adds r0, r5, r2
	bl FUN_080139a0
	b _08039376
_08039344:
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r2, r5, r3
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0803936C
	movs r4, #0xd7
	lsls r4, r4, #4
	adds r0, r5, r4
	bl FUN_080139a0
	b _08039376
_0803936C:
	movs r1, #0xd7
	lsls r1, r1, #4
	adds r0, r5, r1
	bl FUN_08013984
_08039376:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _08039384
	b _080394A6
_08039384:
	ldr r0, _080393B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080393CC
	ldr r0, _080393BC @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _080393C8
	ldr r2, _080393C0 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _080393B2
	ldr r3, _080393C4 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _080393B2
	movs r2, #1
_080393B2:
	adds r0, r2, #0
	b _080393FC
	.align 2, 0
_080393B8: .4byte 0x030047A4
_080393BC: .4byte 0x03002BE0
_080393C0: .4byte 0x00000446
_080393C4: .4byte 0x00000442
_080393C8:
	movs r0, #0
	b _080393FC
_080393CC:
	ldr r0, _08039454 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _08039400
	ldr r0, _08039458 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #2
	beq _08039400
	ldr r0, _0803945C @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080393FA
	ldr r0, _08039460 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _080393FA
	movs r1, #1
_080393FA:
	adds r0, r1, #0
_080393FC:
	cmp r0, #0
	beq _0803949E
_08039400:
	movs r3, #0x9d
	lsls r3, r3, #3
	adds r2, r5, r3
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r4, #0x86
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r2, [r0]
	movs r0, #0xa1
	lsls r0, r0, #3
	adds r3, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _08039450
	cmp r1, #3
	bne _08039464
_08039450:
	movs r3, #0x46
	b _08039466
	.align 2, 0
_08039454: .4byte 0x03002B48
_08039458: .4byte 0x030046A0
_0803945C: .4byte 0x03002B8C
_08039460: .4byte 0x03002B60
_08039464:
	movs r3, #0x42
_08039466:
	cmp r1, #1
	ble _08039478
	movs r1, #0x9d
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0, #8]
	movs r2, #4
	orrs r1, r2
	b _08039486
_08039478:
	movs r2, #0x9d
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08039486:
	str r1, [r0, #8]
	movs r4, #0x9d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r2, r3, #0
	movs r3, #0
	bl Sprite_SetSprite
	b _080394B4
_0803949E:
	movs r3, #0x9d
	lsls r3, r3, #3
	adds r0, r5, r3
	b _080394AC
_080394A6:
	movs r4, #0x9d
	lsls r4, r4, #3
	adds r0, r5, r4
_080394AC:
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
_080394B4:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080394D4
	ldr r0, _080394D0 @ =0x00000E14
	adds r2, r5, r0
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2, #4]
	ands r0, r1
	b _080394DE
	.align 2, 0
_080394D0: .4byte 0x00000E14
_080394D4:
	ldr r1, _08039558 @ =0x00000E14
	adds r2, r5, r1
	movs r1, #1
	ldr r0, [r2, #4]
	orrs r0, r1
_080394DE:
	str r0, [r2, #4]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08039510
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08039510
	ldr r4, _0803955C @ =0x000002BA
	adds r1, r5, r4
	ldr r0, _08039560 @ =0x00006543
	strh r0, [r1]
	movs r0, #0xb2
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0xb8
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1]
_08039510:
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	adds r1, #1
	str r1, [r0]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08039586
	ldr r0, _08039564 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _08039568 @ =0x00005EC0
	adds r6, r0, r1
	ldr r3, _0803956C @ =0x00005EE0
	adds r2, r0, r3
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, _08039570 @ =0x00000161
	adds r3, r5, r0
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _08039578
	movs r0, #0
	strb r0, [r4]
	adds r0, r2, #0
	ldr r2, _08039574 @ =0x04000008
	bl CpuSet
	b _08039586
	.align 2, 0
_08039558: .4byte 0x00000E14
_0803955C: .4byte 0x000002BA
_08039560: .4byte 0x00006543
_08039564: .4byte 0x03003584
_08039568: .4byte 0x00005EC0
_0803956C: .4byte 0x00005EE0
_08039570: .4byte 0x00000161
_08039574: .4byte 0x04000008
_08039578:
	ldrb r3, [r3]
	movs r0, #7
	str r0, [sp]
	adds r0, r1, #0
	adds r1, r6, #0
	bl rgb555_08237468
_08039586:
	adds r0, r7, #0
	adds r0, #0xb4
	movs r1, #0
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xe0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080395a4
FUN_080395a4: @ 0x080395A4
	push {lr}
	mov ip, r0
	movs r1, #2
	adds r0, #0x98
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _080395D2
	movs r3, #1
	movs r1, #0
	movs r2, #3
	mov r0, ip
	adds r0, #0xa4
	strb r3, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r3, [r0]
	b _080395F4
_080395D2:
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne _080395DE
	movs r0, #0
	b _080395F6
_080395DE:
	mov r0, ip
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
_080395F4:
	movs r0, #1
_080395F6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080395fc
FUN_080395fc: @ 0x080395FC
	push {r4, lr}
	adds r2, r0, #0
	mov ip, r2
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039618
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0803961A
_08039618:
	movs r0, #0
_0803961A:
	adds r1, r0, #0
	cmp r1, #1
	bne _08039626
	adds r0, r2, #0
	adds r0, #0xa2
	strb r1, [r0]
_08039626:
	movs r0, #0xba
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	adds r4, r2, #0
	adds r4, #0xbc
	cmp r0, #0
	bne _08039672
	movs r1, #0xb9
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	cmp r0, #0
	beq _08039672
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08039672
	adds r0, r2, #0
	adds r0, #0xdd
	ldrb r0, [r0]
	cmp r0, #0x54
	bgt _0803966C
	movs r0, #0xa
	strh r0, [r1]
	movs r1, #1
	adds r0, r2, #0
	adds r0, #0xa6
	strb r1, [r0]
	str r3, [r4]
	adds r0, #2
	strb r1, [r0]
	b _08039672
_0803966C:
	mov r0, ip
	bl FUN_08038b54
_08039672:
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08039680
FUN_08039680: @ 0x08039680
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r1, r5, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803969C
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0803969E
_0803969C:
	movs r0, #0
_0803969E:
	cmp r0, #0
	beq _080396AA
	movs r0, #2
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
_080396AA:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080396D2
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080396D2
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080396D2
	adds r0, r4, #0
	bl FUN_08038b88
_080396D2:
	ldr r0, _080396FC @ =0x0000018B
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080396EC
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080396EC
	ldr r0, _08039700 @ =0x000002CF
	bl PlaySound_082406e0
_080396EC:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080396FC: .4byte 0x0000018B
_08039700: .4byte 0x000002CF

	thumb_func_start FUN_08039704
FUN_08039704: @ 0x08039704
	push {lr}
	mov ip, r0
	mov r1, ip
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803971E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039720
_0803971E:
	movs r0, #0
_08039720:
	cmp r0, #0
	beq _0803972C
	movs r0, #3
	mov r1, ip
	adds r1, #0xa2
	strb r0, [r1]
_0803972C:
	mov r2, ip
	adds r2, #0xbc
	ldr r0, [r2]
	cmp r0, #0x1f
	bls _0803974A
	movs r1, #3
	mov r3, ip
	adds r3, #0xa6
	movs r0, #0
	strb r1, [r3]
	str r0, [r2]
	mov r1, ip
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_0803974A:
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	pop {r0}
	bx r0

	thumb_func_start FUN_08039754
FUN_08039754: @ 0x08039754
	push {lr}
	mov ip, r0
	mov r1, ip
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803976E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039770
_0803976E:
	movs r0, #0
_08039770:
	cmp r0, #0
	beq _0803977C
	movs r0, #4
	mov r1, ip
	adds r1, #0xa2
	strb r0, [r1]
_0803977C:
	mov r2, ip
	adds r2, #0xbc
	ldr r0, [r2]
	cmp r0, #0x3b
	bls _0803979A
	movs r1, #5
	mov r3, ip
	adds r3, #0xa6
	movs r0, #0
	strb r1, [r3]
	str r0, [r2]
	mov r1, ip
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_0803979A:
	ldr r0, [r2]
	adds r0, #1
	str r0, [r2]
	pop {r0}
	bx r0

	thumb_func_start FUN_080397a4
FUN_080397a4: @ 0x080397A4
	push {lr}
	adds r3, r0, #0
	mov ip, r3
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _080397C0
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _080397C6
_080397C0:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_080397C6:
	cmp r0, #0
	beq _080397E6
	movs r0, #5
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
	movs r2, #0xc7
	lsls r2, r2, #1
	add r2, ip
	movs r0, #0x3c
	strh r0, [r2]
	ldr r0, _08039808 @ =0x00000175
	add r0, ip
	ldrb r0, [r0]
	movs r0, #0x5a
	strh r0, [r2]
_080397E6:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803980C
	movs r0, #5
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _08039816
	.align 2, 0
_08039808: .4byte 0x00000175
_0803980C:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08039816:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803981c
FUN_0803981c: @ 0x0803981C
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039836
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0803983C
_08039836:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_0803983C:
	cmp r0, #0
	beq _08039848
	movs r0, #6
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_08039848:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039868
	movs r0, #6
	adds r2, r3, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _08039872
_08039868:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08039872:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08039878
FUN_08039878: @ 0x08039878
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r1, r5, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039894
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039896
_08039894:
	movs r0, #0
_08039896:
	cmp r0, #0
	beq _080398A2
	movs r0, #7
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
_080398A2:
	adds r6, r5, #0
	adds r6, #0xbc
	ldr r0, [r6]
	cmp r0, #0x78
	bls _0803990C
	adds r4, r5, #0
	adds r4, #0x50
	ldr r1, _080398E4 @ =0x0000018D
	adds r0, r7, r1
	ldrb r0, [r0]
	bl FUN_08036990
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080369d4
	movs r0, #0xc4
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r3, #0
	strh r0, [r1]
	movs r2, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080398EC
	ldr r1, _080398E8 @ =0x00000175
	adds r0, r7, r1
	strb r2, [r0]
	movs r0, #8
	b _080398F6
	.align 2, 0
_080398E4: .4byte 0x0000018D
_080398E8: .4byte 0x00000175
_080398EC:
	ldr r0, _08039908 @ =0x00000175
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	movs r0, #7
_080398F6:
	adds r1, r5, #0
	adds r1, #0xa6
	strb r0, [r1]
	str r3, [r6]
	adds r0, r5, #0
	adds r0, #0xa8
	strb r2, [r0]
	b _08039910
	.align 2, 0
_08039908: .4byte 0x00000175
_0803990C:
	adds r0, #1
	str r0, [r6]
_08039910:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08039918
FUN_08039918: @ 0x08039918
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r1, r5, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039938
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _0803993E
_08039938:
	movs r0, #0
	movs r1, #0xa7
	adds r1, r1, r5
_0803993E:
	mov r8, r1
	cmp r0, #0
	bne _08039946
	b _08039A8E
_08039946:
	movs r0, #8
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r3, r7, r2
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r3]
	str r1, [r3, #4]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, r3, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08039990
	cmp r1, #0
	blt _08039990
	ldr r0, _08039994 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08039990
	ldr r0, _08039998 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803999C
_08039990:
	movs r4, #0
	b _080399AA
	.align 2, 0
_08039994: .4byte 0x030046A8
_08039998: .4byte 0x030046AC
_0803999C:
	ldr r0, _080399BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080399AA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080399C0
	adds r0, #4
	b _080399CC
	.align 2, 0
_080399BC: .4byte 0x030046A4
_080399C0:
	ldr r0, _080399E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080399CC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080399E4
	cmp r2, #2
	beq _080399E8
	b _080399EC
	.align 2, 0
_080399E0: .4byte 0x030046A4
_080399E4:
	ldrb r0, [r6, #4]
	b _080399EA
_080399E8:
	ldrb r0, [r6]
_080399EA:
	subs r1, r1, r0
_080399EC:
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r6, r7, r0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08039A1E
	cmp r1, #0
	blt _08039A1E
	ldr r0, _08039A24 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08039A1E
	ldr r0, _08039A28 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08039A2C
_08039A1E:
	movs r4, #0
	b _08039A3A
	.align 2, 0
_08039A24: .4byte 0x030046A8
_08039A28: .4byte 0x030046AC
_08039A2C:
	ldr r0, _08039A4C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08039A3A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08039A50
	adds r0, #4
	b _08039A5C
	.align 2, 0
_08039A4C: .4byte 0x030046A4
_08039A50:
	ldr r0, _08039A70 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08039A5C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08039A74
	cmp r3, #2
	beq _08039A78
	b _08039A7C
	.align 2, 0
_08039A70: .4byte 0x030046A4
_08039A74:
	ldrb r0, [r6, #4]
	b _08039A7A
_08039A78:
	ldrb r0, [r6]
_08039A7A:
	subs r2, r2, r0
_08039A7C:
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strh r2, [r1]
	movs r2, #0xbb
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
_08039A8E:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039AB0
	movs r0, #4
	adds r2, r5, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _08039ABA
_08039AB0:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08039ABA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08039ac4
FUN_08039ac4: @ 0x08039AC4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r1, r5, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039AE4
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039AEA
_08039AE4:
	movs r0, #0
	movs r1, #0xa7
	adds r1, r1, r5
_08039AEA:
	mov r8, r1
	cmp r0, #0
	beq _08039BC0
	movs r0, #8
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r3, r6, r2
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r3]
	str r1, [r3, #4]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r2]
	str r1, [r2, #4]
	adds r7, r3, #0
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08039B3A
	cmp r1, #0
	blt _08039B3A
	ldr r0, _08039B40 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08039B3A
	ldr r0, _08039B44 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08039B48
_08039B3A:
	movs r4, #0
	b _08039B56
	.align 2, 0
_08039B40: .4byte 0x030046A8
_08039B44: .4byte 0x030046AC
_08039B48:
	ldr r0, _08039B68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08039B56:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08039B6C
	adds r0, #4
	b _08039B78
	.align 2, 0
_08039B68: .4byte 0x030046A4
_08039B6C:
	ldr r0, _08039B8C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08039B78:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08039B90
	cmp r2, #2
	beq _08039B94
	b _08039B98
	.align 2, 0
_08039B8C: .4byte 0x030046A4
_08039B90:
	ldrb r0, [r7, #4]
	b _08039B96
_08039B94:
	ldrb r0, [r7]
_08039B96:
	subs r1, r1, r0
_08039B98:
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r4, #0
	strh r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r2, #0x12
	adds r1, r6, r2
	ldrb r1, [r1]
	bl FUN_08036c4c
	movs r1, #0xbb
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _08039BF4 @ =0x00000177
	adds r0, r6, r2
	strb r4, [r0]
_08039BC0:
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _08039BCA
	b _08039CC4
_08039BCA:
	ldr r2, _08039BF4 @ =0x00000177
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _08039BF8
	movs r0, #4
	adds r1, r5, #0
	adds r1, #0xa6
	strb r0, [r1]
	adds r1, #0x16
	movs r0, #0
	str r0, [r1]
	subs r1, #0x14
	movs r0, #1
	strb r0, [r1]
	b _08039CCE
	.align 2, 0
_08039BF4: .4byte 0x00000177
_08039BF8:
	movs r0, #9
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r3, r6, r0
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r2]
	str r1, [r2, #4]
	adds r5, r3, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08039C42
	cmp r1, #0
	blt _08039C42
	ldr r0, _08039C48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08039C42
	ldr r0, _08039C4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08039C50
_08039C42:
	movs r4, #0
	b _08039C5E
	.align 2, 0
_08039C48: .4byte 0x030046A8
_08039C4C: .4byte 0x030046AC
_08039C50:
	ldr r0, _08039C70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08039C5E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08039C74
	adds r0, #4
	b _08039C80
	.align 2, 0
_08039C70: .4byte 0x030046A4
_08039C74:
	ldr r0, _08039C94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08039C80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08039C98
	cmp r2, #2
	beq _08039C9C
	b _08039CA0
	.align 2, 0
_08039C94: .4byte 0x030046A4
_08039C98:
	ldrb r0, [r5, #4]
	b _08039C9E
_08039C9C:
	ldrb r0, [r5]
_08039C9E:
	subs r1, r1, r0
_08039CA0:
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r4, #0
	strh r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r2, #0x12
	adds r1, r6, r2
	ldrb r1, [r1]
	bl FUN_08036c4c
	movs r1, #0xbb
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	b _08039CCE
_08039CC4:
	adds r1, r5, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08039CCE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08039cd8
FUN_08039cd8: @ 0x08039CD8
	push {r4, lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039CF2
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039CF4
_08039CF2:
	movs r0, #0
_08039CF4:
	cmp r0, #0
	beq _08039D00
	movs r0, #0xd
	adds r1, r3, #0
	adds r1, #0xa2
	strb r0, [r1]
_08039D00:
	movs r4, #1
	adds r0, r3, #0
	adds r0, #0x98
	ldr r2, [r0]
	ands r2, r4
	cmp r2, #0
	bne _08039D26
	movs r1, #5
	adds r0, #0xc
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r4, [r0]
	b _08039D30
_08039D26:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08039D30:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08039d38
FUN_08039d38: @ 0x08039D38
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039D52
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039D54
_08039D52:
	movs r0, #0
_08039D54:
	cmp r0, #0
	beq _08039D60
	movs r0, #0xe
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_08039D60:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08039d70
FUN_08039d70: @ 0x08039D70
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039D8A
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039D90
_08039D8A:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_08039D90:
	cmp r0, #0
	beq _08039D9C
	movs r0, #0xf
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_08039D9C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039DC2
	movs r1, #0
	movs r2, #5
	adds r0, r3, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	b _08039DCC
_08039DC2:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08039DCC:
	pop {r0}
	bx r0

	thumb_func_start FUN_08039dd0
FUN_08039dd0: @ 0x08039DD0
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039DE6
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
_08039DE6:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0

	thumb_func_start FUN_08039df4
FUN_08039df4: @ 0x08039DF4
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039E0E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039E10
_08039E0E:
	movs r0, #0
_08039E10:
	cmp r0, #0
	beq _08039E1C
	movs r0, #0x11
	adds r1, r2, #0
	adds r1, #0xa2
	strb r0, [r1]
_08039E1C:
	adds r1, r2, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08039e2c
FUN_08039e2c: @ 0x08039E2C
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039E46
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039E48
_08039E46:
	movs r0, #0
_08039E48:
	cmp r0, #0
	beq _08039E60
	movs r0, #0x12
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08039E60:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08039e70
FUN_08039e70: @ 0x08039E70
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039E8A
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039E8C
_08039E8A:
	movs r0, #0
_08039E8C:
	cmp r0, #0
	beq _08039EA4
	movs r0, #0x13
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08039EA4:
	adds r1, r4, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08039eb4
FUN_08039eb4: @ 0x08039EB4
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039ECE
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039ED4
_08039ECE:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_08039ED4:
	cmp r0, #0
	beq _08039EE0
	movs r0, #0x14
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_08039EE0:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039F06
	movs r2, #1
	adds r0, r3, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _08039F10
_08039F06:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08039F10:
	pop {r0}
	bx r0

	thumb_func_start FUN_08039f14
FUN_08039f14: @ 0x08039F14
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039F2E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039F34
_08039F2E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_08039F34:
	cmp r0, #0
	beq _08039F40
	movs r0, #0x15
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_08039F40:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039F66
	movs r2, #1
	adds r0, r3, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _08039F70
_08039F66:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08039F70:
	pop {r0}
	bx r0

	thumb_func_start FUN_08039f74
FUN_08039f74: @ 0x08039F74
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039F8E
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039F94
_08039F8E:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_08039F94:
	cmp r0, #0
	beq _08039FA0
	movs r0, #0x16
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_08039FA0:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039FC8
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _08039FD2
_08039FC8:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08039FD2:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08039fd8
FUN_08039fd8: @ 0x08039FD8
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _08039FF2
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _08039FF8
_08039FF2:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_08039FF8:
	cmp r0, #0
	beq _0803A004
	movs r0, #0x17
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_0803A004:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A02C
	movs r1, #0
	adds r0, r3, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
	b _0803A036
_0803A02C:
	adds r1, r3, #0
	adds r1, #0xbc
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0803A036:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803a03c
FUN_0803a03c: @ 0x0803A03C
	push {lr}
	ldr r2, _0803A054 @ =0x085AAE64
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0803A054: .4byte 0x085AAE64

	thumb_func_start FUN_0803a058
FUN_0803a058: @ 0x0803A058
	push {lr}
	ldr r2, _0803A070 @ =0x085AAE88
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0803A070: .4byte 0x085AAE88

	thumb_func_start FUN_0803a074
FUN_0803a074: @ 0x0803A074
	push {lr}
	ldr r2, _0803A08C @ =0x085AAE98
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0803A08C: .4byte 0x085AAE98

	thumb_func_start FUN_0803a090
FUN_0803a090: @ 0x0803A090
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	ldr r0, _0803A0C4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0803A0BE
	adds r0, r4, #0
	bl FUN_080395a4
	cmp r0, #0
	bne _0803A0BE
	ldr r0, _0803A0C8 @ =0x085AAEB4
	adds r1, r4, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl _call_via_r1
_0803A0BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A0C4: .4byte 0x03002BC0
_0803A0C8: .4byte 0x085AAEB4

	thumb_func_start FUN_0803a0cc
FUN_0803a0cc: @ 0x0803A0CC
	push {lr}
	ldr r2, _0803A0E4 @ =0x085AAEB8
	adds r1, r0, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0803A0E4: .4byte 0x085AAEB8

	thumb_func_start FUN_0803a0e8
FUN_0803a0e8: @ 0x0803A0E8
	push {lr}
	ldr r2, _0803A100 @ =0x085AAEBC
	adds r1, r0, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0803A100: .4byte 0x085AAEBC

	thumb_func_start FUN_0803a104
FUN_0803a104: @ 0x0803A104
	push {lr}
	adds r2, r0, #0
	adds r2, #0x9d
	movs r1, #0
	strb r1, [r2]
	ldr r2, _0803A124 @ =0x085AAEC0
	adds r1, r0, #0
	adds r1, #0xa4
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0803A124: .4byte 0x085AAEC0

	thumb_func_start FUN_0803a128
FUN_0803a128: @ 0x0803A128
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A152
	movs r3, #0
	strb r3, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	bl FUN_08022da8
_0803A152:
	movs r2, #0x1c
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803a180
FUN_0803a180: @ 0x0803A180
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A1AA
	movs r3, #0
	strb r3, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	bl FUN_08022da8
_0803A1AA:
	movs r2, #0x1c
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803a1d8
FUN_0803a1d8: @ 0x0803A1D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r0
	adds r5, r1, #0
	mov r7, r8
	adds r6, r7, #0
	adds r6, #0x48
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A21E
	movs r4, #0
	strb r4, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x17
	bl FUN_08022c9c
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
_0803A21E:
	movs r2, #0xc
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	cmp r5, #0x1f
	bgt _0803A2A0
	ldrb r0, [r6, #5]
	adds r6, r7, #0
	adds r6, #0x58
	adds r4, r0, #0
	adds r4, #0x80
	ldr r2, _0803A260 @ =0x085B0A08
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	adds r1, r2, #0
	cmp r0, #0
	blt _0803A264
	asrs r3, r0, #0xc
	b _0803A26A
	.align 2, 0
_0803A260: .4byte 0x085B0A08
_0803A264:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0803A26A:
	movs r0, #0
	strh r3, [r6]
	strh r0, [r6, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _0803A288
	asrs r0, r0, #0xc
	b _0803A28E
_0803A288:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803A28E:
	strh r0, [r6, #4]
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r5, [r0]
	adds r0, r7, #0
	movs r1, #0x80
	bl FUN_08036884
_0803A2A0:
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _0803A398
	ldr r4, _0803A2F0 @ =0x0203B400
	ldr r3, _0803A2F4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0803A2F8 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	add r4, sp, #0xc
	adds r2, r1, #0
	adds r2, #0x20
	ldr r1, _0803A2FC @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r2, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _0803A300
	asrs r3, r0, #0xc
	b _0803A306
	.align 2, 0
_0803A2F0: .4byte 0x0203B400
_0803A2F4: .4byte 0x030046B8
_0803A2F8: .4byte 0x000003FF
_0803A2FC: .4byte 0x085B0A08
_0803A300:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0803A306:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0803A31E
	asrs r0, r0, #0xc
	b _0803A324
_0803A31E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803A324:
	strh r0, [r4, #4]
	add r3, sp, #0xc
	movs r4, #0xa8
	lsls r4, r4, #2
	adds r2, r7, r4
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	ldrh r5, [r3, #4]
	adds r0, r0, r5
	strh r0, [r3, #4]
	adds r1, #0x80
	strh r1, [r3, #2]
	ldr r4, _0803A3C4 @ =0x0203B400
	ldr r0, [r6]
	adds r0, #1
	ldr r3, _0803A3C8 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r3
	lsls r2, r0, #1
	adds r2, r2, r4
	ldrh r2, [r2]
	movs r5, #0xf
	ands r2, r5
	adds r2, #0x10
	adds r0, #1
	ands r0, r3
	str r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	ands r3, r5
	adds r3, #4
	ldr r6, _0803A3CC @ =0x00000DE8
	adds r0, r7, r6
	ldr r0, [r0]
	movs r4, #0x3c
	str r4, [sp]
	movs r5, #0xb1
	lsls r5, r5, #1
	adds r4, r7, r5
	ldrb r4, [r4]
	str r4, [sp, #4]
	add r6, sp, #0xc
	str r6, [sp, #8]
	bl FUN_08060220
_0803A398:
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, r8
	ldr r1, [r0]
	mov r0, r8
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803A3B6
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
_0803A3B6:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A3C4: .4byte 0x0203B400
_0803A3C8: .4byte 0x000003FF
_0803A3CC: .4byte 0x00000DE8

	thumb_func_start FUN_0803a3d0
FUN_0803a3d0: @ 0x0803A3D0
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A40A
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x1b
	bl FUN_08022c9c
	movs r0, #0xb3
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0803A40A:
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803a438
FUN_0803a438: @ 0x0803A438
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A4A2
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x1b
	bl FUN_08022c9c
	b _0803A4BC
_0803A4A2:
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x1b
	bl FUN_08022c9c
_0803A4BC:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803A4F6
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803A4F6
	movs r1, #0xc7
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r6, r0
	blt _0803A4F6
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803A4F6:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803a500
FUN_0803a500: @ 0x0803A500
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	mov r8, r1
	adds r7, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A544
	movs r4, #0
	strb r4, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0x1d
	bl FUN_08022da8
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	ldr r0, _0803A5B4 @ =0x00000175
	bl PlaySound_0824078c
_0803A544:
	movs r2, #4
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803A65A
	movs r0, #3
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _0803A622
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r6, sp, #8
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0803A5AE
	cmp r1, #0
	blt _0803A5AE
	ldr r0, _0803A5B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0803A5AE
	ldr r0, _0803A5BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803A5C0
_0803A5AE:
	movs r4, #0
	b _0803A5CE
	.align 2, 0
_0803A5B4: .4byte 0x00000175
_0803A5B8: .4byte 0x030046A8
_0803A5BC: .4byte 0x030046AC
_0803A5C0:
	ldr r0, _0803A5E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0803A5CE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0803A5E4
	adds r0, #4
	b _0803A5F0
	.align 2, 0
_0803A5E0: .4byte 0x030046A4
_0803A5E4:
	ldr r0, _0803A604 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0803A5F0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0803A608
	cmp r2, #2
	beq _0803A60C
	b _0803A610
	.align 2, 0
_0803A604: .4byte 0x030046A4
_0803A608:
	ldrb r0, [r6, #4]
	b _0803A60E
_0803A60C:
	ldrb r0, [r6]
_0803A60E:
	subs r1, r1, r0
_0803A610:
	add r0, sp, #8
	strh r1, [r0, #2]
	movs r0, #0xd2
	lsls r0, r0, #4
	adds r2, r7, r0
	movs r0, #0
	add r1, sp, #8
	bl FUN_080155e4
_0803A622:
	mov r1, r8
	cmp r1, #0x28
	ble _0803A65A
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r4, r7, r0
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r7, #0
	bl FUN_08036884
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #6
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0803A65A
	adds r0, r5, #0
	adds r0, #0xa7
	movs r1, #1
	strb r1, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	bl PlaySound_0824078c
_0803A65A:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803a668
FUN_0803a668: @ 0x0803A668
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A6BA
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0x1d
	bl FUN_08022da8
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r0, _0803A6E8 @ =0x0000FFFA
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, #0
	bl FUN_08036884
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
_0803A6BA:
	movs r2, #0x1c
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803A6E8: .4byte 0x0000FFFA

	thumb_func_start FUN_0803a6ec
FUN_0803a6ec: @ 0x0803A6EC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	mov sb, r1
	adds r6, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A72E
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r4, #0x98
	lsls r4, r4, #2
	adds r2, r5, r4
	movs r0, #1
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0x1d
	bl FUN_08022da8
	movs r0, #0xbe
	lsls r0, r0, #1
	bl PlaySound_0824078c
_0803A72E:
	movs r1, #4
	adds r4, r5, #0
	adds r4, #0x98
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	mov r8, r4
	cmp r0, #0
	beq _0803A75C
	b _0803A8AC
_0803A75C:
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #3
	bgt _0803A81A
	movs r0, #3
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	bne _0803A81A
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r7, sp, #8
	adds r0, r7, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0803A7AA
	cmp r1, #0
	blt _0803A7AA
	ldr r0, _0803A7B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0803A7AA
	ldr r0, _0803A7B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0803A7B8
_0803A7AA:
	movs r4, #0
	b _0803A7C6
	.align 2, 0
_0803A7B0: .4byte 0x030046A8
_0803A7B4: .4byte 0x030046AC
_0803A7B8:
	ldr r0, _0803A7D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0803A7C6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0803A7DC
	adds r0, #4
	b _0803A7E8
	.align 2, 0
_0803A7D8: .4byte 0x030046A4
_0803A7DC:
	ldr r0, _0803A7FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0803A7E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0803A800
	cmp r2, #2
	beq _0803A804
	b _0803A808
	.align 2, 0
_0803A7FC: .4byte 0x030046A4
_0803A800:
	ldrb r0, [r7, #4]
	b _0803A806
_0803A804:
	ldrb r0, [r7]
_0803A806:
	subs r1, r1, r0
_0803A808:
	add r0, sp, #8
	strh r1, [r0, #2]
	movs r4, #0xd2
	lsls r4, r4, #4
	adds r2, r6, r4
	movs r0, #0
	add r1, sp, #8
	bl FUN_080155e4
_0803A81A:
	mov r0, sb
	cmp r0, #0x1d
	bgt _0803A82C
	movs r1, #0x10
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _0803A8AC
_0803A82C:
	movs r4, #0xb6
	lsls r4, r4, #1
	adds r1, r6, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r6, #0
	bl FUN_08036884
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _0803A866
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x50]
	str r1, [r5, #0x54]
	b _0803A880
_0803A866:
	adds r0, r5, #0
	adds r0, #0x50
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrb r3, [r3]
	movs r4, #5
	str r4, [sp]
	bl FUN_08237970
_0803A880:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #3
	ble _0803A8AC
	ldr r2, _0803A8BC @ =FUN_0803a8c0
	movs r0, #9
	adds r3, r5, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r5, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_0803A8AC:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A8BC: .4byte FUN_0803a8c0

	thumb_func_start FUN_0803a8c0
FUN_0803a8c0: @ 0x0803A8C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r5, #0
	movs r0, #0xc8
	adds r0, r0, r5
	mov ip, r0
	ldrb r0, [r0]
	adds r2, r5, #0
	adds r2, #0x4d
	movs r1, #0
	mov sl, r1
	strb r0, [r2]
	ldrb r0, [r2]
	adds r0, #0x20
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	mov sb, r1
	mov r1, sb
	ands r0, r1
	adds r7, r5, #0
	adds r7, #0xa0
	strb r0, [r7]
	ldrb r0, [r2]
	adds r0, #0x10
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	mov r8, r1
	mov r1, r8
	ands r0, r1
	adds r6, r5, #0
	adds r6, #0xa1
	strb r0, [r6]
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803A966
	mov r0, sl
	strb r0, [r1]
	mov r1, ip
	ldrb r0, [r1]
	strb r0, [r2]
	ldrb r0, [r2]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	mov r1, sb
	ands r0, r1
	strb r0, [r7]
	ldrb r0, [r2]
	adds r0, #0x10
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	mov r2, r8
	ands r0, r2
	strb r0, [r6]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x1e
	bl FUN_08022c9c
_0803A966:
	movs r6, #4
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	mov r2, sl
	strh r2, [r0]
	subs r1, #0x5c
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803A990
	b _0803AAD8
_0803A990:
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	bne _0803A9C2
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x1f
	bl FUN_08022c9c
	b _0803AA08
_0803A9C2:
	cmp r0, #0x14
	bne _0803A9E6
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0x98
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x1e
	bl FUN_08022c9c
	b _0803AA08
_0803A9E6:
	cmp r0, #0x20
	bne _0803AA08
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #0x98
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x20
	bl FUN_08022c9c
_0803AA08:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0x1f
	ble _0803AA90
	ldr r1, _0803AA50 @ =0x0000029D
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0803AA8C
	movs r7, #0
	strh r7, [r2]
	ldr r2, _0803AA54 @ =0x00000175
	adds r0, r5, r2
	ldrb r3, [r0]
	cmp r3, #0
	beq _0803AA5C
	ldr r1, _0803AA58 @ =durathror_0803acbc
	movs r0, #0xb
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r7, [r0]
	adds r0, #0x1d
	strb r6, [r0]
	b _0803AA7A
	.align 2, 0
_0803AA50: .4byte 0x0000029D
_0803AA54: .4byte 0x00000175
_0803AA58: .4byte durathror_0803acbc
_0803AA5C:
	ldr r1, _0803AA84 @ =durathror_0803aae8
	movs r0, #0xa
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r6, [r0]
	ldr r0, _0803AA88 @ =0x00000177
	bl PlaySound_082406e0
_0803AA7A:
	adds r0, r5, #0
	bl FUN_08036c1c
	b _0803AA90
	.align 2, 0
_0803AA84: .4byte durathror_0803aae8
_0803AA88: .4byte 0x00000177
_0803AA8C:
	movs r0, #0x20
	strh r0, [r2]
_0803AA90:
	movs r0, #0xbb
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1f
	bls _0803AAB4
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #0x50]
	str r1, [r4, #0x54]
	b _0803AACE
_0803AAB4:
	adds r0, r4, #0
	adds r0, #0x50
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r5, r4
	ldrb r3, [r3]
	movs r4, #5
	str r4, [sp]
	bl FUN_08237970
_0803AACE:
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, #0
	bl FUN_08036884
_0803AAD8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start durathror_0803aae8
durathror_0803aae8: @ 0x0803AAE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	mov sl, r1
	mov sb, r7
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803AB4C
	movs r4, #0
	strb r4, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r3, #0x98
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #1
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x21
	bl FUN_08022c9c
	adds r0, r7, #0
	movs r1, #0xa
	movs r2, #0xa
	bl FUN_08022c24
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	adds r0, r7, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	ldr r2, _0803ABF8 @ =0x00000163
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _0803ABFC @ =0x000002CE
	bl PlaySound_0824078c
_0803AB4C:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803AB60
	b _0803ACA2
_0803AB60:
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803AB76
	b _0803ACA2
_0803AB76:
	movs r2, #0x80
	lsls r2, r2, #0xb
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x1f
	mov r8, r4
	mov r0, sl
	ands r0, r4
	cmp r0, #0
	bne _0803AC7E
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bhi _0803AC7E
	ldr r1, _0803AC00 @ =0x0203B400
	mov ip, r1
	ldr r2, _0803AC04 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r3, _0803AC08 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	add r0, ip
	movs r6, #0xff
	ldrb r5, [r0]
	adds r4, #0xe5
	adds r0, r7, r4
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r4, [r0]
	adds r1, #1
	ands r1, r3
	str r1, [r2]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	mov r1, r8
	ands r0, r1
	add r3, sp, #0xc
	adds r4, r4, r0
	subs r4, #0x10
	ldr r1, _0803AC0C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0803AC10
	asrs r2, r0, #0xc
	b _0803AC16
	.align 2, 0
_0803ABF8: .4byte 0x00000163
_0803ABFC: .4byte 0x000002CE
_0803AC00: .4byte 0x0203B400
_0803AC04: .4byte 0x030046B8
_0803AC08: .4byte 0x000003FF
_0803AC0C: .4byte 0x085B0A08
_0803AC10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0803AC16:
	movs r0, #0
	strh r2, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r5, r0
	cmp r0, #0
	blt _0803AC32
	asrs r0, r0, #0xc
	b _0803AC38
_0803AC32:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803AC38:
	strh r0, [r3, #4]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	add r4, sp, #0x14
	add r2, sp, #0xc
	adds r0, r2, #0
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r4, #0
	bl FUN_08036908
	ldr r0, _0803ACB4 @ =0x00000DEC
	add r0, sb
	ldr r0, [r0]
	movs r1, #0xd1
	lsls r1, r1, #1
	add r1, sb
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x20
	adds r3, r4, #0
	bl FUN_0805dd44
_0803AC7E:
	mov r3, sl
	cmp r3, #0xff
	ble _0803ACA2
	ldr r2, _0803ACB8 @ =FUN_0803ad74
	movs r0, #0xc
	adds r3, r7, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r7, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_0803ACA2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803ACB4: .4byte 0x00000DEC
_0803ACB8: .4byte FUN_0803ad74

	thumb_func_start durathror_0803acbc
durathror_0803acbc: @ 0x0803ACBC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r5, #0xa9
	ldrb r0, [r5]
	cmp r0, #0
	beq _0803AD0C
	movs r0, #0
	strb r0, [r5]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x21
	bl FUN_08022c9c
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x14
	bl FUN_08022c24
	adds r0, r4, #0
	bl FUN_08036ec4
	ldr r0, _0803AD68 @ =0x00000177
	bl PlaySound_0824078c
	ldr r0, _0803AD6C @ =0x000002CD
	bl PlaySound_0824078c
_0803AD0C:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803AD5E
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0803AD5E
	movs r2, #0x80
	lsls r2, r2, #0xb
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r6, #0x59
	ble _0803AD5E
	ldr r1, _0803AD70 @ =FUN_0803ad74
	movs r0, #0xc
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	movs r0, #1
	strb r0, [r5]
_0803AD5E:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803AD68: .4byte 0x00000177
_0803AD6C: .4byte 0x000002CD
_0803AD70: .4byte FUN_0803ad74

	thumb_func_start FUN_0803ad74
FUN_0803ad74: @ 0x0803AD74
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803ADA6
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #5
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x22
	bl FUN_08022c9c
_0803ADA6:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803ADE2
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803ADE2
	ldr r1, _0803ADEC @ =0x0000029D
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0803ADE2
	adds r0, r4, #0
	adds r0, #0xa7
	strb r2, [r0]
_0803ADE2:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803ADEC: .4byte 0x0000029D

	thumb_func_start FUN_0803adf0
FUN_0803adf0: @ 0x0803ADF0
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803AE3E
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x17
	bl FUN_08022c9c
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xc
	bl FUN_08036b2c
_0803AE3E:
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	movs r2, #0xd
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r7, #9
	bgt _0803AEB6
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r3, r4, #0
	adds r3, #0x58
	ldrb r5, [r0]
	movs r6, #0xc
	ldr r2, _0803AE8C @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803AE90
	asrs r1, r0, #0xc
	b _0803AE96
	.align 2, 0
_0803AE8C: .4byte 0x085B0A08
_0803AE90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803AE96:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803AEAE
	asrs r0, r0, #0xc
	b _0803AEB4
_0803AEAE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803AEB4:
	strh r0, [r3, #4]
_0803AEB6:
	cmp r7, #0x13
	ble _0803AED8
	ldr r2, _0803AEE0 @ =FUN_0803a500
	movs r0, #6
	adds r3, r4, #0
	adds r3, #0xa3
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_0803AED8:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803AEE0: .4byte FUN_0803a500

	thumb_func_start bee_0803aee4
bee_0803aee4: @ 0x0803AEE4
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803AF1C
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x17
	bl FUN_08022c9c
	ldr r0, _0803AF40 @ =0x00000173
	bl PlaySound_082406e0
_0803AF1C:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xc
	adds r2, r4, #0
	adds r2, #0x98
	ldr r0, [r2]
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xb
	orrs r0, r1
	str r0, [r2]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803AF40: .4byte 0x00000173

	thumb_func_start FUN_0803af44
FUN_0803af44: @ 0x0803AF44
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803AF82
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x17
	bl FUN_08022c9c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #0xc
	bl FUN_08036b2c
_0803AF82:
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803B01A
	cmp r7, #9
	bgt _0803B00E
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r3, r4, #0
	adds r3, #0x58
	ldrb r5, [r0]
	movs r6, #0x18
	ldr r2, _0803AFE4 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803AFE8
	asrs r1, r0, #0xc
	b _0803AFEE
	.align 2, 0
_0803AFE4: .4byte 0x085B0A08
_0803AFE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803AFEE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803B006
	asrs r0, r0, #0xc
	b _0803B00C
_0803B006:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803B00C:
	strh r0, [r3, #4]
_0803B00E:
	cmp r7, #0x13
	ble _0803B01A
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803B01A:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start durathror_0803b024
durathror_0803b024: @ 0x0803B024
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r5, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803B0BA
	movs r4, #0
	strb r4, [r1]
	adds r0, r5, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r5, r0
	subs r0, #0x20
	adds r2, r5, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0x28
	bl FUN_08022c9c
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r5, #0
	bl FUN_08022fb8
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl FUN_08023090
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	movs r0, #0xba
	lsls r0, r0, #1
	bl PlaySound_0824078c
_0803B0BA:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	movs r2, #0xd
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r6, #0x7f
	bgt _0803B14E
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r3, r5, #0
	adds r3, #0x58
	ldrb r4, [r0]
	ldr r2, _0803B0FC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #1
	cmp r0, #0
	blt _0803B100
	asrs r1, r0, #0xc
	b _0803B106
	.align 2, 0
_0803B0FC: .4byte 0x085B0A08
_0803B100:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803B106:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _0803B120
	asrs r0, r0, #0xc
	b _0803B126
_0803B120:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803B126:
	strh r0, [r3, #4]
	asrs r1, r6, #2
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #0x80
	bl FUN_08036884
	movs r0, #0xf
	ands r0, r6
	cmp r0, #0
	bne _0803B17A
	adds r0, r7, #0
	movs r1, #1
	movs r2, #6
	bl FUN_08036b2c
	b _0803B17A
_0803B14E:
	cmp r6, #0x80
	bne _0803B170
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
	adds r0, r5, #0
	movs r1, #0x80
	bl FUN_08036884
	ldr r0, _0803B16C @ =0x00000383
	bl PlaySound_0824078c
	b _0803B17A
	.align 2, 0
_0803B16C: .4byte 0x00000383
_0803B170:
	cmp r6, #0xa4
	bne _0803B17A
	ldr r0, _0803B19C @ =0x0000033A
	bl PlaySound_0824078c
_0803B17A:
	ldr r2, _0803B1A0 @ =0x0000029D
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803B194
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r0, r5, #0
	bl FUN_08023024
_0803B194:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B19C: .4byte 0x0000033A
_0803B1A0: .4byte 0x0000029D

	thumb_func_start FUN_0803b1a4
FUN_0803b1a4: @ 0x0803B1A4
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803B1B6
	movs r0, #0
	strb r0, [r1]
_0803B1B6:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	strh r0, [r1]
	movs r2, #0x1c
	adds r1, r3, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803b1e0
FUN_0803b1e0: @ 0x0803B1E0
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803B24C
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x19
	bl FUN_08022c9c
_0803B24C:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803b278
FUN_0803b278: @ 0x0803B278
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803B2E4
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x19
	bl FUN_08022c9c
_0803B2E4:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803b310
FUN_0803b310: @ 0x0803B310
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r4, #0
	adds r5, r4, #0
	adds r5, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803B348
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x19
	bl FUN_08022c9c
	b _0803B362
_0803B348:
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x19
	bl FUN_08022c9c
_0803B362:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	movs r2, #0xc
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803B424
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r0, [r5, #5]
	ldrb r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #0
	bge _0803B3A4
	rsbs r1, r0, #0
_0803B3A4:
	cmp r1, #3
	bgt _0803B3E6
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _0803B424
_0803B3E6:
	cmp r0, #0
	bge _0803B3F0
	ldrb r0, [r5, #5]
	adds r0, #4
	b _0803B3F4
_0803B3F0:
	ldrb r0, [r5, #5]
	subs r0, #4
_0803B3F4:
	adds r3, r4, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r4, #0
	adds r0, #0xa1
	strb r1, [r0]
_0803B424:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803b42c
FUN_0803b42c: @ 0x0803B42C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r4, #0
	adds r6, #0x48
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803B482
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x19
	bl FUN_08022c9c
	movs r2, #0x10
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r2, r4, #0
	adds r2, #0xcc
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xca
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0803B482:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _0803B4C8 @ =0x0001000C
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803B522
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	cmp r5, #0x1f
	ble _0803B4CC
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _0803B522
	.align 2, 0
_0803B4C8: .4byte 0x0001000C
_0803B4CC:
	movs r1, #3
	bics r1, r5
	movs r0, #0x20
	subs r0, r0, r5
	adds r4, #0x58
	lsls r5, r1, #6
	lsls r6, r0, #3
	ldr r2, _0803B4F8 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803B4FC
	asrs r3, r0, #0xc
	b _0803B502
	.align 2, 0
_0803B4F8: .4byte 0x085B0A08
_0803B4FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0803B502:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803B51A
	asrs r0, r0, #0xc
	b _0803B520
_0803B51A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803B520:
	strh r0, [r4, #4]
_0803B522:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0803b52c
FUN_0803b52c: @ 0x0803B52C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r7, r1, #0
	movs r0, #0x48
	adds r0, r0, r4
	mov r8, r0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803B580
	movs r0, #0
	strb r0, [r1]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r3, #0x98
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0x19
	bl FUN_08022c9c
	adds r2, r4, #0
	adds r2, #0xcc
	mov r3, r8
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xca
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0803B580:
	movs r0, #0xae
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _0803B5D4 @ =0x0001000C
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803B61C
	movs r0, #3
	ands r0, r7
	adds r3, r4, #0
	adds r3, #0x58
	lsls r5, r0, #6
	lsls r6, r7, #3
	ldr r2, _0803B5D8 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803B5DC
	asrs r1, r0, #0xc
	b _0803B5E2
	.align 2, 0
_0803B5D4: .4byte 0x0001000C
_0803B5D8: .4byte 0x085B0A08
_0803B5DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0803B5E2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0803B5FA
	asrs r0, r0, #0xc
	b _0803B600
_0803B5FA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803B600:
	strh r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0xcc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r3, r8
	str r0, [r3, #8]
	str r1, [r3, #0xc]
	cmp r7, #0x1f
	ble _0803B61C
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803B61C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0803b628
FUN_0803b628: @ 0x0803B628
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	mov sb, r1
	mov r8, r7
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803B664
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r4, #0x98
	lsls r4, r4, #2
	adds r2, r7, r4
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #0x19
	bl FUN_08022c9c
_0803B664:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r1, [r0]
	movs r0, #0xc
	adds r2, r7, #0
	adds r2, #0x98
	ldr r1, [r2]
	orrs r1, r0
	str r1, [r2]
	mov r4, sb
	cmp r4, #5
	ble _0803B686
	movs r0, #0x10
	orrs r1, r0
	str r1, [r2]
_0803B686:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B69C
	b _0803B7AA
_0803B69C:
	movs r0, #1
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0803B79C
	ldr r4, _0803B6F0 @ =0x0203B400
	ldr r3, _0803B6F4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0803B6F8 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	add r4, sp, #0xc
	adds r1, #0x20
	mov ip, r1
	ldr r1, _0803B6FC @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	adds r6, r3, #0
	cmp r0, #0
	blt _0803B700
	asrs r2, r0, #0xc
	b _0803B706
	.align 2, 0
_0803B6F0: .4byte 0x0203B400
_0803B6F4: .4byte 0x030046B8
_0803B6F8: .4byte 0x000003FF
_0803B6FC: .4byte 0x085B0A08
_0803B700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0803B706:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _0803B722
	asrs r0, r0, #0xc
	b _0803B728
_0803B722:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0803B728:
	strh r0, [r4, #4]
	add r3, sp, #0xc
	movs r2, #0xa8
	lsls r2, r2, #2
	add r2, r8
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r1, [r3, #2]
	ldrh r0, [r2, #2]
	adds r1, r1, r0
	ldrh r0, [r2, #4]
	ldrh r4, [r3, #4]
	adds r0, r0, r4
	strh r0, [r3, #4]
	adds r1, #0x80
	strh r1, [r3, #2]
	ldr r4, _0803B7B8 @ =0x0203B400
	ldr r0, [r6]
	adds r0, #1
	ldr r3, _0803B7BC @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrb r1, [r1]
	adds r0, #1
	ands r0, r3
	lsls r2, r0, #1
	adds r2, r2, r4
	ldrh r2, [r2]
	movs r5, #0xf
	ands r2, r5
	adds r2, #0x10
	adds r0, #1
	ands r0, r3
	str r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r3, [r0]
	ands r3, r5
	adds r3, #4
	ldr r0, _0803B7C0 @ =0x00000DE8
	add r0, r8
	ldr r0, [r0]
	movs r4, #0x3c
	str r4, [sp]
	movs r4, #0xb1
	lsls r4, r4, #1
	add r4, r8
	ldrb r4, [r4]
	str r4, [sp, #4]
	add r4, sp, #0xc
	str r4, [sp, #8]
	bl FUN_08060220
_0803B79C:
	mov r0, sb
	cmp r0, #9
	ble _0803B7AA
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_0803B7AA:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B7B8: .4byte 0x0203B400
_0803B7BC: .4byte 0x000003FF
_0803B7C0: .4byte 0x00000DE8

	thumb_func_start FUN_0803b7c4
FUN_0803b7c4: @ 0x0803B7C4
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa7
	movs r0, #0
	strb r0, [r1]
	movs r1, #4
	ldr r0, _0803B7E8 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0803B7E2
	adds r0, r2, #0
	bl FUN_08022f78
_0803B7E2:
	pop {r0}
	bx r0
	.align 2, 0
_0803B7E8: .4byte 0x03002BC0

	thumb_func_start FUN_0803b7ec
FUN_0803b7ec: @ 0x0803B7EC
	push {lr}
	mov ip, r0
	mov r2, ip
	adds r2, #0xa2
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bhi _0803B828
	ldr r1, _0803B824 @ =0x085AAECC
	ldrb r2, [r2]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	mov r0, ip
	adds r0, #0xa3
	movs r3, #0
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	mov r1, ip
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _0803B82A
	.align 2, 0
_0803B824: .4byte 0x085AAECC
_0803B828:
	movs r0, #0
_0803B82A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0803b830
FUN_0803b830: @ 0x0803B830
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	movs r0, #0x84
	lsls r0, r0, #2
	adds r0, r0, r4
	mov ip, r0
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r6, [r0, r2]
	movs r1, #0
	mov sl, r1
	mov r2, sl
	strh r2, [r0]
	cmp r6, #0
	bgt _0803B85E
	b _0803B984
_0803B85E:
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0xb5
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r1, r1, r6
	mov r2, r8
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	adds r5, r4, #0
	adds r5, #0x90
	ldrh r0, [r5]
	subs r0, r0, r6
	strh r0, [r5]
	movs r0, #0xad
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _0803B904 @ =0x000002BA
	adds r1, r4, r0
	movs r0, #0x99
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r0, r4, r2
	str r0, [r1]
	ldr r2, _0803B908 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	movs r7, #0x10
	orrs r0, r7
	ldr r1, _0803B90C @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r7
	str r0, [sp, #0xc]
	adds r3, r4, #0
	adds r3, #0x50
	add r0, sp, #8
	str r0, [sp]
	movs r1, #1
	mov sb, r1
	str r1, [sp, #4]
	mov r0, ip
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bgt _0803B914
	mov r0, sl
	strh r0, [r5]
	movs r2, #2
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0803B910 @ =durathror_0803b024
	adds r0, r4, #0
	adds r0, #0xa3
	strb r7, [r0]
	adds r0, #0x55
	b _0803B96A
	.align 2, 0
_0803B904: .4byte 0x000002BA
_0803B908: .4byte 0xFFFF0000
_0803B90C: .4byte 0x0000FFFF
_0803B910: .4byte durathror_0803b024
_0803B914:
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #8
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0803B936
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080371d4
_0803B936:
	mov r2, r8
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _0803B94A
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_0824078c
	b _0803B984
_0803B94A:
	ldr r0, _0803B97C @ =0x00000173
	bl PlaySound_0824078c
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	mov r2, sb
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0803B980 @ =FUN_0803adf0
	movs r0, #0xd
	adds r2, r4, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0xf8
_0803B96A:
	str r1, [r0]
	subs r0, #0x6c
	mov r1, sl
	str r1, [r0]
	adds r0, #0x1d
	mov r2, sb
	strb r2, [r0]
	movs r0, #1
	b _0803B986
	.align 2, 0
_0803B97C: .4byte 0x00000173
_0803B980: .4byte FUN_0803adf0
_0803B984:
	movs r0, #0
_0803B986:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Durathror_Update
Durathror_Update: @ 0x0803B998
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080390f8
	adds r0, r4, #0
	bl FUN_0803a104
	adds r0, r4, #0
	bl FUN_0803b7c4
	adds r0, r4, #0
	bl FUN_08039280
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Durathror_Destroy
Durathror_Destroy: @ 0x0803B9BC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xd7
	lsls r1, r1, #4
	adds r0, r4, r1
	bl FUN_08013c70
	adds r0, r4, #0
	bl FUN_08038a60
	adds r0, r4, #0
	bl FUN_08036848
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0x9d
	lsls r1, r1, #3
	adds r0, r4, r1
	bl FUN_0822f1c0
	ldr r1, _0803BA00 @ =0x00000E14
	adds r0, r4, r1
	bl FUN_0807f598
	adds r0, r4, #0
	bl FUN_08022b04
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0803BA00: .4byte 0x00000E14

	thumb_func_start Durathror_Init
Durathror_Init: @ 0x0803BA04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	adds r7, r0, #0
	mov r8, r1
	mov sb, r7
	movs r0, #0x74
	movs r1, #2
	bl Script_GetKeywordValue
	str r0, [sp, #0x34]
	adds r0, r7, #0
	ldr r1, [sp, #0x34]
	bl FUN_08022a0c
	ldr r0, _0803BA48 @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _0803BA4C
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r7, r1
	str r2, [r0]
	movs r3, #0x86
	lsls r3, r3, #1
	adds r1, r7, r3
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _0803BA5C
	.align 2, 0
_0803BA48: .4byte 0x03002BE0
_0803BA4C:
	movs r4, #0x82
	lsls r4, r4, #1
	adds r0, r7, r4
	str r2, [r0]
	movs r5, #0x86
	lsls r5, r5, #1
	adds r0, r7, r5
	str r2, [r0]
_0803BA5C:
	ldr r0, _0803BACC @ =0x0000CB05
	ldr r1, _0803BAD0 @ =0x0000D3FA
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0803BA6C
	b _0803C158
_0803BA6C:
	movs r6, #0x98
	lsls r6, r6, #2
	adds r0, r7, r6
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0803BADC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0803BAD4 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0803BAD8 @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	bl Script_GetValue
	adds r4, r0, #0
	b _0803BB04
	.align 2, 0
_0803BACC: .4byte 0x0000CB05
_0803BAD0: .4byte 0x0000D3FA
_0803BAD4: .4byte 0xFFFF0000
_0803BAD8: .4byte 0x0000FFFF
_0803BADC:
	ldr r0, _0803BB20 @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _0803BB24 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _0803BB28 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x1c]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r4, #0x40
_0803BB04:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0803BB2C
	bl Script_GetValue
	mov sl, r0
	bl Script_GetValue
	movs r6, #0xd7
	lsls r6, r6, #1
	adds r1, r7, r6
	b _0803BB3A
	.align 2, 0
_0803BB20: .4byte 0x030046A0
_0803BB24: .4byte 0xFFFF0000
_0803BB28: .4byte 0x0000FFFF
_0803BB2C:
	movs r0, #0x96
	lsls r0, r0, #2
	mov sl, r0
	movs r2, #0xd7
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0x3c
_0803BB3A:
	strh r0, [r1]
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _0803BBA2
	bl Script_GetValue
	movs r3, #0xca
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	movs r5, #0xcb
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xcd
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xce
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #8
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	adds r6, #8
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r1, r7, r2
	b _0803BBE4
_0803BBA2:
	movs r3, #0xca
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0x3c
	strh r1, [r0]
	movs r5, #0xcb
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r2, #0x32
	strh r2, [r0]
	movs r6, #0xcc
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0x46
	strh r1, [r0]
	adds r3, #8
	adds r0, r7, r3
	strh r2, [r0]
	adds r5, #8
	adds r2, r7, r5
	movs r0, #0x41
	strh r0, [r2]
	adds r6, #8
	adds r0, r7, r6
	strh r1, [r0]
	movs r0, #0xd1
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x50
_0803BBE4:
	strh r0, [r1]
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0803BC5A
	bl Script_GetValue
	movs r2, #0xd3
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	movs r5, #0xd5
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0xd9
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r5, #0xa
	adds r1, r7, r5
	strh r0, [r1]
	bl Script_GetValue
	adds r6, #0xa
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xdc
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	b _0803BCA8
_0803BC5A:
	movs r3, #0xd3
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r2, #0x32
	strh r2, [r0]
	movs r5, #0xd4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0x1e
	strh r1, [r0]
	movs r6, #0xd5
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #3
	strh r0, [r1]
	adds r3, #0xa
	adds r1, r7, r3
	movs r0, #0x2d
	strh r0, [r1]
	adds r5, #0xa
	adds r0, r7, r5
	movs r1, #0x37
	strh r1, [r0]
	adds r6, #0xa
	adds r0, r7, r6
	strh r1, [r0]
	movs r0, #0xdb
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x28
	strh r0, [r1]
	movs r1, #0xdc
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r2, [r0]
_0803BCA8:
	str r4, [sp]
	mov r0, sb
	mov r1, r8
	ldr r2, [sp, #0x34]
	add r3, sp, #0x1c
	bl Boss_Init_08022a70
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sb
	movs r6, #0
	strb r4, [r0]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	movs r2, #0xab
	add r2, sb
	mov r8, r2
	strb r0, [r2]
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r4, r7, r3
	movs r0, #0x98
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #2
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r1, sp, #0x1c
	str r1, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	movs r0, #1
	str r0, [sp]
	str r6, [sp, #4]
	mov r0, sb
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_08022da8
	ldr r4, _0803BDEC @ =0x03003584
	ldr r0, [r4]
	movs r2, #0xbd
	lsls r2, r2, #7
	adds r0, r0, r2
	movs r3, #0xb8
	lsls r3, r3, #2
	adds r1, r7, r3
	ldr r2, _0803BDF0 @ =0x04000040
	bl CpuSet
	ldr r0, [r4]
	movs r4, #0x99
	lsls r4, r4, #6
	adds r6, r0, r4
	mov r5, r8
	str r5, [sp, #0x28]
	movs r0, #0xfc
	add r0, sb
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, sb
	str r1, [sp, #0x30]
	mov r2, sb
	adds r2, #0xde
	str r2, [sp, #0x2c]
	mov r3, sb
	adds r3, #0x48
	str r3, [sp, #0x24]
	movs r4, #0xf8
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r4, #7
_0803BD4C:
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, _0803BDF4 @ =0x04000008
	bl CpuSet
	adds r5, #0x20
	subs r4, #1
	cmp r4, #0
	bge _0803BD4C
	movs r5, #0x9c
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r0, [sp, #0x1c]
	ldr r1, [sp, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	movs r6, #0x9d
	lsls r6, r6, #3
	adds r0, r7, r6
	movs r2, #0x98
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r3, _0803BDF8 @ =0x00000201
	movs r2, #2
	str r2, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r4, sp, #0x1c
	str r4, [sp, #0xc]
	movs r2, #0x40
	bl FUN_0822f3fc
	movs r4, #0
	ldr r3, _0803BDFC @ =0x00007FE8
	adds r6, #0x60
	adds r5, r7, r6
_0803BD98:
	lsls r0, r4, #5
	adds r2, r4, #1
	movs r1, #0xf
	adds r0, r0, r5
	adds r0, #0x1e
_0803BDA2:
	strh r3, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0803BDA2
	adds r4, r2, #0
	cmp r4, #7
	ble _0803BD98
	ldr r0, _0803BE00 @ =0x00000522
	adds r1, r7, r0
	movs r4, #0
	movs r5, #0
	ldr r0, _0803BE04 @ =0x00006583
	strh r0, [r1]
	movs r2, #0xa6
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r3, #0xa9
	lsls r3, r3, #3
	adds r0, r7, r3
	str r0, [r1]
	ldr r6, [sp, #0x28]
	ldrb r3, [r6]
	cmp r3, #0
	beq _0803BEA4
	movs r0, #0x44
	movs r1, #1
	bl Script_GetKeywordValue
	adds r3, r0, #0
	cmp r3, #1
	beq _0803BE34
	cmp r3, #1
	bgt _0803BE08
	cmp r3, #0
	beq _0803BE0E
	b _0803BEE6
	.align 2, 0
_0803BDEC: .4byte 0x03003584
_0803BDF0: .4byte 0x04000040
_0803BDF4: .4byte 0x04000008
_0803BDF8: .4byte 0x00000201
_0803BDFC: .4byte 0x00007FE8
_0803BE00: .4byte 0x00000522
_0803BE04: .4byte 0x00006583
_0803BE08:
	cmp r3, #2
	beq _0803BE6C
	b _0803BEE6
_0803BE0E:
	movs r1, #2
	mov r0, sb
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #0x16
	str r5, [r0]
	subs r0, #0x14
	movs r2, #1
	strb r2, [r0]
	ldr r1, _0803BE30 @ =FUN_0803b1a4
	movs r0, #0x11
	b _0803BE88
	.align 2, 0
_0803BE30: .4byte FUN_0803b1a4
_0803BE34:
	movs r1, #2
	mov r0, sb
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x16
	str r5, [r0]
	subs r0, #0x14
	strb r3, [r0]
	ldr r1, _0803BE68 @ =FUN_0803b1e0
	movs r0, #0x12
	mov r2, sb
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, sb
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	b _0803BEE6
	.align 2, 0
_0803BE68: .4byte FUN_0803b1e0
_0803BE6C:
	mov r0, sb
	adds r0, #0xa4
	strb r3, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x16
	str r5, [r0]
	subs r0, #0x14
	movs r2, #1
	strb r2, [r0]
	ldr r1, _0803BEA0 @ =FUN_0803b278
	movs r0, #0x13
_0803BE88:
	mov r3, sb
	adds r3, #0xa3
	strb r0, [r3]
	mov r0, sb
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r5, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	b _0803BEE6
	.align 2, 0
_0803BEA0: .4byte FUN_0803b278
_0803BEA4:
	mov r0, sb
	adds r0, #0xa4
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #0x16
	str r3, [r0]
	subs r0, #0x14
	movs r2, #1
	strb r2, [r0]
	ldr r1, _0803BF38 @ =FUN_0803a128
	subs r0, #5
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	movs r3, #0x9d
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_0803BEE6:
	ldr r0, _0803BF3C @ =FUN_0803b830
	mov r4, r8
	str r0, [r4]
	ldr r0, _0803BF40 @ =FUN_0803b7ec
	ldr r5, [sp, #0x30]
	str r0, [r5]
	movs r6, #0xd7
	lsls r6, r6, #1
	adds r4, r7, r6
	movs r0, #0
	ldrsh r3, [r4, r0]
	mov r0, sb
	mov r1, sl
	mov r2, sl
	bl FUN_08022b2c
	adds r0, r7, #0
	bl FUN_08038dc0
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r0, r7, #0
	bl FUN_08038e6c
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _0803BF44
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08022fac
	b _0803BF4E
	.align 2, 0
_0803BF38: .4byte FUN_0803a128
_0803BF3C: .4byte FUN_0803b830
_0803BF40: .4byte FUN_0803b7ec
_0803BF44:
	mov r0, sb
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_0803BF4E:
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _0803BF74
	movs r4, #0
	mov r5, sb
	adds r5, #0xe8
	b _0803BF68
_0803BF60:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_0803BF68:
	cmp r4, #3
	bgt _0803BF74
	bl VM_GetPC
	cmp r0, #0
	bne _0803BF60
_0803BF74:
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0xfa
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x4b
	movs r1, #0
	bl Script_GetKeywordValue
	movs r4, #0xde
	lsls r4, r4, #1
	adds r1, r7, r4
	str r0, [r1]
	movs r0, #0x78
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x2c]
	strb r0, [r5]
	adds r0, r7, #0
	bl FUN_08038f00
	movs r0, #0x6a
	bl prepare_08231510
	cmp r0, #0
	beq _0803BFC4
	bl Script_GetValue
	movs r6, #0xb3
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r7, r2
	b _0803BFD6
_0803BFC4:
	movs r3, #0xb3
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0x96
	strh r0, [r1]
	movs r4, #0xb5
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0x32
_0803BFD6:
	strh r0, [r1]
	movs r5, #0xb3
	lsls r5, r5, #1
	adds r0, r7, r5
	ldrh r0, [r0]
	movs r6, #0xb4
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	ldr r1, [sp, #0x28]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0803C028
	movs r0, #5
	bl FUN_08234f44
	adds r3, r0, #0
	ldr r2, _0803C01C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0803C020 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0803C024 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldrb r1, [r3]
	bl Mod
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	b _0803C030
	.align 2, 0
_0803C01C: .4byte 0x030046B8
_0803C020: .4byte 0x000003FF
_0803C024: .4byte 0x0203B400
_0803C028:
	movs r4, #0xc5
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
_0803C030:
	strb r0, [r1]
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	movs r5, #0xdf
	lsls r5, r5, #4
	adds r1, r7, r5
	str r0, [r1]
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r6, _0803C088 @ =0x00000DF4
	adds r1, r7, r6
	str r0, [r1]
	movs r0, #0x6b
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _0803C08C @ =0x00000DF8
	adds r1, r7, r2
	str r0, [r1]
	movs r3, #0xb9
	lsls r3, r3, #1
	adds r2, r7, r3
	movs r1, #0
	movs r0, #0x14
	strh r0, [r2]
	movs r4, #0xe0
	lsls r4, r4, #4
	adds r0, r7, r4
	str r1, [r0]
	adds r5, #0xc
	adds r0, r7, r5
	str r1, [r0]
	movs r0, #0x42
	bl prepare_08231510
	cmp r0, #0
	beq _0803C0B2
	movs r4, #0
	adds r5, r7, r5
	b _0803C0A6
	.align 2, 0
_0803C088: .4byte 0x00000DF4
_0803C08C: .4byte 0x00000DF8
_0803C090:
	bl Script_GetValue
	lsls r2, r4, #1
	ldr r6, _0803C13C @ =0x00000E04
	adds r1, r7, r6
	adds r1, r1, r2
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
	adds r4, #1
_0803C0A6:
	cmp r4, #7
	bgt _0803C0B2
	bl VM_GetPC
	cmp r0, #0
	bne _0803C090
_0803C0B2:
	ldr r0, _0803C140 @ =0x00000E14
	adds r4, r7, r0
	ldr r2, _0803C144 @ =FUN_08036fd8
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	bl FUN_0807f558
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r4, #4]
	ands r0, r1
	str r0, [r4, #4]
	movs r1, #0xd7
	lsls r1, r1, #4
	adds r4, r7, r1
	movs r2, #0xa8
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x48
	str r0, [sp]
	movs r3, #0
	str r3, [sp, #4]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #0x18
	bl FUN_08013ba8
	adds r0, r4, #0
	bl FUN_080139a0
	adds r0, r7, #0
	bl FUN_080389b0
	bl FUN_0805d79c
	ldr r3, _0803C148 @ =0x00000DE4
	adds r1, r7, r3
	str r0, [r1]
	cmp r0, #0
	beq _0803C158
	ldr r0, _0803C14C @ =0x00006545
	movs r4, #0xc8
	lsls r4, r4, #2
	adds r1, r7, r4
	bl FUN_080601a8
	ldr r5, _0803C150 @ =0x00000DE8
	adds r1, r7, r5
	str r0, [r1]
	cmp r0, #0
	beq _0803C158
	bl FUN_0805dcd4
	ldr r6, _0803C154 @ =0x00000DEC
	adds r1, r7, r6
	str r0, [r1]
	cmp r0, #0
	beq _0803C158
	movs r0, #0
	b _0803C15C
	.align 2, 0
_0803C13C: .4byte 0x00000E04
_0803C140: .4byte 0x00000E14
_0803C144: .4byte FUN_08036fd8
_0803C148: .4byte 0x00000DE4
_0803C14C: .4byte 0x00006545
_0803C150: .4byte 0x00000DE8
_0803C154: .4byte 0x00000DEC
_0803C158:
	movs r0, #1
	rsbs r0, r0, #0
_0803C15C:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

