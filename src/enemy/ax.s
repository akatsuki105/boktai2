	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_081958b4
FUN_081958b4: @ 0x081958B4
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, _081958E4 @ =0x00000CA2
	adds r5, r3, r1
	ldrh r1, [r5]
	lsrs r1, r1, #5
	movs r4, #0x1f
	ands r1, r4
	ldr r6, _081958E8 @ =0x00000C35
	adds r2, r3, r6
	strb r1, [r2]
	ldrh r1, [r5]
	lsrs r1, r1, #0xa
	ands r1, r4
	ldr r4, _081958EC @ =0x00000C36
	adds r2, r3, r4
	strb r1, [r2]
	adds r6, #0x2b
	adds r3, r3, r6
	ldr r1, _081958F0 @ =FUN_081958f4
	str r1, [r3]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081958E4: .4byte 0x00000CA2
_081958E8: .4byte 0x00000C35
_081958EC: .4byte 0x00000C36
_081958F0: .4byte FUN_081958f4

	thumb_func_start FUN_081958f4
FUN_081958f4: @ 0x081958F4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0819595C @ =0x00000C6C
	adds r6, r5, r0
	ldr r0, [r6]
	lsls r0, r0, #4
	ldr r1, _08195960 @ =0x00000CC2
	adds r4, r5, r1
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl Div
	ldr r2, _08195964 @ =0x00000C34
	adds r3, r5, r2
	strb r0, [r3]
	ldr r0, [r6]
	movs r2, #0
	ldrsb r2, [r4, r2]
	adds r1, r0, #0
	adds r0, #1
	str r0, [r6]
	cmp r1, r2
	bne _08195930
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, _08195968 @ =FUN_08195970
	str r1, [r0]
	movs r0, #0
	str r0, [r6]
_08195930:
	ldr r2, _0819596C @ =0x00000C36
	adds r0, r5, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	subs r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	orrs r0, r1
	adds r2, #0x6d
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0819595C: .4byte 0x00000C6C
_08195960: .4byte 0x00000CC2
_08195964: .4byte 0x00000C34
_08195968: .4byte FUN_08195970
_0819596C: .4byte 0x00000C36

	thumb_func_start FUN_08195970
FUN_08195970: @ 0x08195970
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081959DC @ =0x00000C6C
	adds r6, r5, r0
	ldr r0, [r6]
	lsls r0, r0, #3
	ldr r1, _081959E0 @ =0x00000CC2
	adds r4, r5, r1
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl Div
	adds r0, #0x10
	ldr r2, _081959E4 @ =0x00000C34
	adds r3, r5, r2
	strb r0, [r3]
	ldr r0, [r6]
	movs r2, #0
	ldrsb r2, [r4, r2]
	adds r1, r0, #0
	adds r0, #1
	str r0, [r6]
	cmp r1, r2
	bne _081959AE
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r1, _081959E8 @ =FUN_081959f0
	str r1, [r0]
	movs r0, #0
	str r0, [r6]
_081959AE:
	ldr r2, _081959EC @ =0x00000C36
	adds r0, r5, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	subs r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	orrs r0, r1
	adds r2, #0x6d
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081959DC: .4byte 0x00000C6C
_081959E0: .4byte 0x00000CC2
_081959E4: .4byte 0x00000C34
_081959E8: .4byte FUN_081959f0
_081959EC: .4byte 0x00000C36

	thumb_func_start FUN_081959f0
FUN_081959f0: @ 0x081959F0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08195A38 @ =0x00000C6C
	adds r4, r6, r0
	ldr r1, [r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	ldr r1, _08195A3C @ =0x00000CC2
	adds r5, r6, r1
	movs r1, #0
	ldrsb r1, [r5, r1]
	bl Div
	adds r0, #0x18
	ldr r2, _08195A40 @ =0x00000C34
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, [r4]
	movs r2, #0
	ldrsb r2, [r5, r2]
	adds r1, r0, #0
	adds r0, #1
	str r0, [r4]
	cmp r1, r2
	bne _08195A66
	ldr r1, _08195A44 @ =0x00000CC4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08195A4C
	movs r2, #0xc6
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r0, _08195A48 @ =FUN_08195aac
	b _08195A54
	.align 2, 0
_08195A38: .4byte 0x00000C6C
_08195A3C: .4byte 0x00000CC2
_08195A40: .4byte 0x00000C34
_08195A44: .4byte 0x00000CC4
_08195A48: .4byte FUN_08195aac
_08195A4C:
	movs r0, #0xc6
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, _08195A98 @ =FUN_08195c68
_08195A54:
	str r0, [r1]
	ldr r1, _08195A9C @ =0x00000C6C
	adds r0, r6, r1
	ldr r2, _08195AA0 @ =0x00000CC2
	adds r1, r6, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	str r1, [r0]
_08195A66:
	ldr r1, _08195AA4 @ =0x00000C36
	adds r0, r6, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	ldr r2, _08195AA8 @ =0x00000C35
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	subs r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	orrs r0, r1
	adds r2, #0x6e
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08195A98: .4byte FUN_08195c68
_08195A9C: .4byte 0x00000C6C
_08195AA0: .4byte 0x00000CC2
_08195AA4: .4byte 0x00000C36
_08195AA8: .4byte 0x00000C35

	thumb_func_start FUN_08195aac
FUN_08195aac: @ 0x08195AAC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08195B18 @ =0x00000C6C
	adds r5, r4, r0
	ldr r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	ldr r1, _08195B1C @ =0x00000CC2
	adds r6, r4, r1
	movs r1, #0
	ldrsb r1, [r6, r1]
	bl Div
	adds r0, #0x18
	ldr r3, _08195B20 @ =0x00000C34
	adds r2, r4, r3
	strb r0, [r2]
	ldr r0, [r5]
	subs r0, #1
	str r0, [r5]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _08195AEC
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, _08195B24 @ =FUN_08195b30
	str r1, [r0]
	movs r0, #0
	ldrsb r0, [r6, r0]
	str r0, [r5]
_08195AEC:
	ldr r3, _08195B28 @ =0x00000C36
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	subs r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	orrs r0, r1
	ldr r2, _08195B2C @ =0x00000CA2
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08195B18: .4byte 0x00000C6C
_08195B1C: .4byte 0x00000CC2
_08195B20: .4byte 0x00000C34
_08195B24: .4byte FUN_08195b30
_08195B28: .4byte 0x00000C36
_08195B2C: .4byte 0x00000CA2

	thumb_func_start FUN_08195b30
FUN_08195b30: @ 0x08195B30
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08195B9C @ =0x00000C6C
	adds r5, r4, r0
	ldr r0, [r5]
	lsls r0, r0, #3
	ldr r1, _08195BA0 @ =0x00000CC2
	adds r6, r4, r1
	movs r1, #0
	ldrsb r1, [r6, r1]
	bl Div
	adds r0, #0x10
	ldr r3, _08195BA4 @ =0x00000C34
	adds r2, r4, r3
	strb r0, [r2]
	ldr r0, [r5]
	subs r0, #1
	str r0, [r5]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _08195B6E
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, _08195BA8 @ =FUN_08195bb4
	str r1, [r0]
	movs r0, #0
	ldrsb r0, [r6, r0]
	str r0, [r5]
_08195B6E:
	ldr r3, _08195BAC @ =0x00000C36
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	subs r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	orrs r0, r1
	ldr r2, _08195BB0 @ =0x00000CA2
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08195B9C: .4byte 0x00000C6C
_08195BA0: .4byte 0x00000CC2
_08195BA4: .4byte 0x00000C34
_08195BA8: .4byte FUN_08195bb4
_08195BAC: .4byte 0x00000C36
_08195BB0: .4byte 0x00000CA2

	thumb_func_start FUN_08195bb4
FUN_08195bb4: @ 0x08195BB4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08195C0C @ =0x00000C6C
	adds r5, r4, r0
	ldr r0, [r5]
	lsls r0, r0, #4
	ldr r2, _08195C10 @ =0x00000CC2
	adds r1, r4, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl Div
	ldr r3, _08195C14 @ =0x00000C34
	adds r2, r4, r3
	strb r0, [r2]
	ldr r0, [r5]
	subs r0, #1
	str r0, [r5]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _08195C20
	ldr r1, _08195C18 @ =0x00000C36
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	adds r3, #1
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	orrs r0, r1
	ldr r2, _08195C1C @ =0x00000CA2
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0
	b _08195C54
	.align 2, 0
_08195C0C: .4byte 0x00000C6C
_08195C10: .4byte 0x00000CC2
_08195C14: .4byte 0x00000C34
_08195C18: .4byte 0x00000C36
_08195C1C: .4byte 0x00000CA2
_08195C20:
	movs r3, #0xc6
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, _08195C5C @ =FUN_081958b4
	str r0, [r1]
	movs r0, #0
	str r0, [r5]
	ldr r1, _08195C60 @ =0x00000C36
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r1, r1, #0xa
	subs r3, #0x2b
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #5
	orrs r1, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	orrs r0, r1
	ldr r2, _08195C64 @ =0x00000CA2
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #1
_08195C54:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08195C5C: .4byte FUN_081958b4
_08195C60: .4byte 0x00000C36
_08195C64: .4byte 0x00000CA2

	thumb_func_start FUN_08195c68
FUN_08195c68: @ 0x08195C68
	push {lr}
	adds r1, r0, #0
	ldr r2, _08195C7C @ =0x00000CC4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08195C80
	movs r0, #1
	b _08195C8C
	.align 2, 0
_08195C7C: .4byte 0x00000CC4
_08195C80:
	movs r0, #0xc6
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, _08195C90 @ =FUN_08195aac
	str r0, [r1]
	movs r0, #0
_08195C8C:
	pop {r1}
	bx r1
	.align 2, 0
_08195C90: .4byte FUN_08195aac

	thumb_func_start FUN_08195c94
FUN_08195c94: @ 0x08195C94
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, _08195CC8 @ =0x00000CA2
	adds r4, r3, r1
	ldrb r2, [r4]
	movs r5, #0x1f
	adds r1, r5, #0
	ands r1, r2
	ldr r6, _08195CCC @ =0x00000C34
	adds r2, r3, r6
	strb r1, [r2]
	ldrh r1, [r4]
	lsrs r1, r1, #5
	ands r1, r5
	adds r6, #1
	adds r2, r3, r6
	strb r1, [r2]
	ldrh r1, [r4]
	lsrs r1, r1, #0xa
	ands r1, r5
	ldr r2, _08195CD0 @ =0x00000C36
	adds r3, r3, r2
	strb r1, [r3]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08195CC8: .4byte 0x00000CA2
_08195CCC: .4byte 0x00000C34
_08195CD0: .4byte 0x00000C36

	thumb_func_start FUN_08195cd4
FUN_08195cd4: @ 0x08195CD4
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r1, _08195D44 @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #3
	bl Mod
	ldr r2, _08195D48 @ =0x00000AFC
	adds r3, r4, r2
	ldr r1, _08195D4C @ =0x085ADD90
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r1, [r3]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _08195D50 @ =0xFFFF0000
	ldr r3, [sp]
	ands r3, r5
	orrs r3, r1
	str r3, [sp]
	ldr r1, [r4, #0x18]
	ldrh r2, [r1, #0x2e]
	adds r2, #0xdc
	lsls r2, r2, #0x10
	ldr r1, _08195D54 @ =0x0000FFFF
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r4, r2
	ldr r2, [r0]
	ldrh r0, [r1]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #4]
	ldr r0, _08195D58 @ =0x00000BE4
	adds r4, r4, r0
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08195D44: .4byte 0x00000CEC
_08195D48: .4byte 0x00000AFC
_08195D4C: .4byte 0x085ADD90
_08195D50: .4byte 0xFFFF0000
_08195D54: .4byte 0x0000FFFF
_08195D58: .4byte 0x00000BE4

	thumb_func_start FUN_08195d5c
FUN_08195d5c: @ 0x08195D5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r1, _08195EF0 @ =0x00000AE6
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #0x1c
	subs r0, r0, r1
	ldr r2, _08195EF4 @ =0x0000044A
	adds r4, r6, r2
	strb r0, [r4]
	ldr r3, _08195EF8 @ =0x00000CEC
	adds r0, r6, r3
	ldr r0, [r0]
	movs r1, #3
	bl Mod
	ldr r1, _08195EFC @ =0x085B0A08
	mov r8, r1
	ldrb r1, [r4]
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	add r1, r8
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldr r1, _08195F00 @ =0x085ADD9C
	lsls r0, r0, #2
	adds r7, r0, r1
	ldr r0, [r7]
	muls r0, r2, r0
	movs r1, #0x80
	lsls r1, r1, #5
	bl Div
	ldr r2, _08195F04 @ =0x00000AFC
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _08195F08 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r1
	str r2, [sp]
	ldr r0, [r6, #0x18]
	ldrh r1, [r0, #0x2e]
	adds r1, #0xdc
	lsls r1, r1, #0x10
	ldr r0, _08195F0C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r0, [r7]
	muls r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #5
	bl Div
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #4]
	ldr r3, _08195F10 @ =0x00000B94
	adds r4, r6, r3
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08195F14 @ =0x00000BE4
	adds r0, r6, r1
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	ldr r2, _08195F18 @ =0x00000B9A
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08195E2C
	adds r0, r4, #0
	bl FUN_08236400
_08195E2C:
	movs r3, #0
	mov sb, r3
	ldr r0, _08195EF4 @ =0x0000044A
	adds r0, r6, r0
	str r0, [sp, #8]
	mov sl, r7
	mov r8, sp
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r7, r6, r1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r6, r2
_08195E46:
	ldr r3, [sp, #8]
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _08195EFC @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r3, sl
	ldr r0, [r3]
	muls r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #5
	bl Div
	movs r1, #0x2c
	mov r4, sb
	muls r4, r1, r4
	adds r4, r6, r4
	adds r1, r4, #0
	adds r1, #0x7c
	ldrh r1, [r1]
	adds r1, r1, r0
	mov r0, r8
	strh r1, [r0]
	ldr r0, [r6, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r0, #0xdc
	mov r1, r8
	strh r0, [r1, #2]
	ldr r2, [sp, #8]
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08195EFC @ =0x085B0A08
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r3, sl
	ldr r0, [r3]
	muls r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #5
	bl Div
	adds r4, #0x80
	ldrh r1, [r4]
	adds r1, r1, r0
	mov r0, r8
	strh r1, [r0, #4]
	ldrh r1, [r5, #6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08195EBC
	adds r0, r5, #0
	bl FUN_08236400
_08195EBC:
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r7, #0x50
	adds r5, #0x50
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #3
	ble _08195E46
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08195EF0: .4byte 0x00000AE6
_08195EF4: .4byte 0x0000044A
_08195EF8: .4byte 0x00000CEC
_08195EFC: .4byte 0x085B0A08
_08195F00: .4byte 0x085ADD9C
_08195F04: .4byte 0x00000AFC
_08195F08: .4byte 0xFFFF0000
_08195F0C: .4byte 0x0000FFFF
_08195F10: .4byte 0x00000B94
_08195F14: .4byte 0x00000BE4
_08195F18: .4byte 0x00000B9A

	thumb_func_start FUN_08195f1c
FUN_08195f1c: @ 0x08195F1C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x18]
	ldrh r4, [r7, #0x1e]
	adds r1, r4, #0
	subs r1, #0xdc
	ldrh r0, [r0, #0x2e]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r6, _08195FD0 @ =0x0000FFFF
	adds r1, r6, #0
	ldr r2, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	asrs r2, r1, #0x10
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r3, r2, #0
	muls r3, r0, r3
	lsls r3, r3, #6
	lsrs r3, r3, #0x10
	ldr r5, _08195FD4 @ =0xFFFF0000
	adds r0, r5, #0
	ldr r2, [sp, #0xc]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0xc]
	adds r2, r5, #0
	ands r2, r1
	orrs r2, r3
	str r2, [sp, #8]
	mov r1, sp
	ldrh r0, [r1, #8]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp]
	ands r1, r5
	orrs r1, r0
	asrs r2, r2, #0x10
	adds r4, r4, r2
	lsls r4, r4, #0x10
	ands r1, r6
	orrs r1, r4
	str r1, [sp]
	mov r2, sp
	ldrh r0, [r2, #0xc]
	ldrh r1, [r7, #0x20]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #4]
	adds r0, r7, #0
	adds r0, #0x98
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r4, r7, #0
	adds r4, #0x48
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	adds r0, #0x4e
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08195FC6
	adds r0, r4, #0
	bl FUN_08236400
_08195FC6:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08195FD0: .4byte 0x0000FFFF
_08195FD4: .4byte 0xFFFF0000

	thumb_func_start FUN_08195fd8
FUN_08195fd8: @ 0x08195FD8
	bx lr
	.align 2, 0

	thumb_func_start FUN_08195fdc
FUN_08195fdc: @ 0x08195FDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	mov r8, r1
	adds r4, r2, #0
	ldr r0, _08196024 @ =0x00000C38
	adds r6, r4, r0
	ldr r0, [r6]
	ldr r1, _08196028 @ =FUN_08197de8
	mov sb, r1
	cmp r0, sb
	bne _08195FFC
	b _08196342
_08195FFC:
	ldr r2, _0819602C @ =0x00000C28
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08196034
	ldr r3, _08196030 @ =0x00000CE6
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08196012
	b _08196342
_08196012:
	movs r0, #0
	movs r1, #0
	mov r2, r8
	strh r1, [r2, #0x3e]
	mov r1, r8
	adds r1, #0x43
	strb r0, [r1]
	b _08196342
	.align 2, 0
_08196024: .4byte 0x00000C38
_08196028: .4byte FUN_08197de8
_0819602C: .4byte 0x00000C28
_08196030: .4byte 0x00000CE6
_08196034:
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236524
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	ldr r3, _081960F4 @ =0x00000C5C
	adds r2, r4, r3
	ldr r5, [r2]
	movs r0, #0x4b
	adds r0, r0, r4
	mov sl, r0
	cmp r5, #0
	beq _0819605A
	b _081962F6
_0819605A:
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	cmp r0, #0
	bne _08196064
	b _0819630C
_08196064:
	ldr r1, [r7, #0x34]
	adds r3, #0x74
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, [r7, #0x38]
	adds r3, #4
	adds r0, r4, r3
	str r1, [r0]
	adds r1, r4, #0
	adds r1, #0x54
	movs r0, #8
	strh r0, [r1]
	ldr r0, _081960F8 @ =FUN_081973e4
	str r0, [r2]
	ldr r1, _081960FC @ =0x00000AEC
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r2, _08196100 @ =0x00000CC8
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
	ldrh r1, [r4, #0x36]
	mov r3, r8
	ldrh r0, [r3, #0x3e]
	subs r1, r1, r0
	strh r1, [r4, #0x36]
	lsls r0, r1, #0x10
	cmp r0, #0
	bge _081960A6
	ldrh r0, [r3, #0x3e]
	adds r0, r0, r1
	strh r0, [r3, #0x3e]
_081960A6:
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	ldrh r2, [r7, #0x3e]
	adds r0, r0, r2
	strh r0, [r7, #0x3e]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	cmp r0, #0
	ble _081960BA
	b _081962F6
_081960BA:
	strh r5, [r4, #0x36]
	movs r0, #1
	movs r1, #6
	adds r2, r4, #0
	adds r2, #0x4a
	strb r0, [r2]
	mov r2, sl
	strb r1, [r2]
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	mov r3, sb
	str r3, [r6]
	ldr r2, _08196104 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xf8
	lsls r1, r1, #1
	adds r3, r0, r1
	ldrh r6, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _08196108 @ =0x0000270E
	adds r5, r2, #0
	cmp r1, r0
	bgt _0819610C
	adds r0, r6, #1
	b _08196110
	.align 2, 0
_081960F4: .4byte 0x00000C5C
_081960F8: .4byte FUN_081973e4
_081960FC: .4byte 0x00000AEC
_08196100: .4byte 0x00000CC8
_08196104: .4byte 0x030046A0
_08196108: .4byte 0x0000270E
_0819610C:
	ldr r1, _08196130 @ =0x0000270F
	adds r0, r1, #0
_08196110:
	strh r0, [r3]
	ldr r2, _08196134 @ =0x00000C1C
	adds r0, r4, r2
	ldr r2, [r0]
	ldr r0, [r5]
	movs r1, #0x81
	lsls r1, r1, #2
	adds r3, r0, r1
	ldrh r6, [r3]
	movs r0, #0
	ldrsh r1, [r3, r0]
	ldr r0, _08196138 @ =0x0000270E
	cmp r1, r0
	bgt _0819613C
	adds r0, r6, #1
	b _08196140
	.align 2, 0
_08196130: .4byte 0x0000270F
_08196134: .4byte 0x00000C1C
_08196138: .4byte 0x0000270E
_0819613C:
	ldr r1, _08196164 @ =0x0000270F
	adds r0, r1, #0
_08196140:
	strh r0, [r3]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _08196176
	ldr r0, [r5]
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r0, #1
	ldr r0, _08196164 @ =0x0000270F
	cmp r1, r0
	ble _08196168
	adds r1, r0, #0
	b _0819616E
	.align 2, 0
_08196164: .4byte 0x0000270F
_08196168:
	cmp r1, #0
	bge _0819616E
	movs r1, #0
_0819616E:
	ldr r0, [r5]
	movs r2, #0x8a
	lsls r2, r2, #2
	b _08196254
_08196176:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081961B0
	ldr r0, [r5]
	ldr r3, _08196198 @ =0x0000022A
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _0819619C @ =0x0000270F
	cmp r1, r0
	ble _081961A0
	adds r1, r0, #0
	b _081961A6
	.align 2, 0
_08196198: .4byte 0x0000022A
_0819619C: .4byte 0x0000270F
_081961A0:
	cmp r1, #0
	bge _081961A6
	movs r1, #0
_081961A6:
	ldr r0, [r5]
	ldr r2, _081961AC @ =0x0000022A
	b _08196254
	.align 2, 0
_081961AC: .4byte 0x0000022A
_081961B0:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081961E6
	ldr r0, [r5]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _081961D4 @ =0x0000270F
	cmp r1, r0
	ble _081961D8
	adds r1, r0, #0
	b _081961DE
	.align 2, 0
_081961D4: .4byte 0x0000270F
_081961D8:
	cmp r1, #0
	bge _081961DE
	movs r1, #0
_081961DE:
	ldr r0, [r5]
	movs r2, #0x8b
	lsls r2, r2, #2
	b _08196254
_081961E6:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r2
	cmp r0, #0
	beq _08196220
	ldr r0, [r5]
	ldr r3, _08196208 @ =0x0000022E
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _0819620C @ =0x0000270F
	cmp r1, r0
	ble _08196210
	adds r1, r0, #0
	b _08196216
	.align 2, 0
_08196208: .4byte 0x0000022E
_0819620C: .4byte 0x0000270F
_08196210:
	cmp r1, #0
	bge _08196216
	movs r1, #0
_08196216:
	ldr r0, [r5]
	ldr r2, _0819621C @ =0x0000022E
	b _08196254
	.align 2, 0
_0819621C: .4byte 0x0000022E
_08196220:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r2, r0
	cmp r2, #0
	beq _08196258
	ldr r0, [r5]
	movs r3, #0x8c
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #1
	ldr r0, _08196244 @ =0x0000270F
	cmp r1, r0
	ble _08196248
	adds r1, r0, #0
	b _0819624E
	.align 2, 0
_08196244: .4byte 0x0000270F
_08196248:
	cmp r1, #0
	bge _0819624E
	movs r1, #0
_0819624E:
	ldr r0, [r5]
	movs r2, #0x8c
	lsls r2, r2, #2
_08196254:
	adds r0, r0, r2
	strh r1, [r0]
_08196258:
	ldrh r0, [r7, #0xa]
	cmp r0, #2
	beq _08196290
	cmp r0, #2
	bgt _08196268
	cmp r0, #1
	beq _08196272
	b _081962F6
_08196268:
	cmp r0, #4
	beq _081962B0
	cmp r0, #8
	beq _081962D0
	b _081962F6
_08196272:
	ldr r0, [r5]
	ldr r3, _08196288 @ =0x00000948
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _0819628C @ =0x0000270E
	cmp r1, r0
	bgt _081962F0
	adds r0, r3, #1
	b _081962F4
	.align 2, 0
_08196288: .4byte 0x00000948
_0819628C: .4byte 0x0000270E
_08196290:
	ldr r0, [r5]
	ldr r3, _081962A8 @ =0x0000094A
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _081962AC @ =0x0000270E
	cmp r1, r0
	bgt _081962F0
	adds r0, r3, #1
	b _081962F4
	.align 2, 0
_081962A8: .4byte 0x0000094A
_081962AC: .4byte 0x0000270E
_081962B0:
	ldr r0, [r5]
	ldr r3, _081962C8 @ =0x0000094C
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _081962CC @ =0x0000270E
	cmp r1, r0
	bgt _081962F0
	adds r0, r3, #1
	b _081962F4
	.align 2, 0
_081962C8: .4byte 0x0000094C
_081962CC: .4byte 0x0000270E
_081962D0:
	ldr r0, [r5]
	ldr r3, _081962E8 @ =0x0000094E
	adds r2, r0, r3
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _081962EC @ =0x0000270E
	cmp r1, r0
	bgt _081962F0
	adds r0, r3, #1
	b _081962F4
	.align 2, 0
_081962E8: .4byte 0x0000094E
_081962EC: .4byte 0x0000270E
_081962F0:
	ldr r1, _08196308 @ =0x0000270F
	adds r0, r1, #0
_081962F4:
	strh r0, [r2]
_081962F6:
	mov r2, r8
	ldrh r0, [r2, #0x3e]
	cmp r0, #0
	beq _0819630C
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08196314
	.align 2, 0
_08196308: .4byte 0x0000270F
_0819630C:
	movs r0, #0xc8
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08196314:
	mov r3, sl
	ldrb r0, [r3]
	cmp r0, #1
	bne _0819632C
	ldrh r0, [r4, #0x1c]
	rsbs r0, r0, #0
	lsls r0, r0, #2
	strh r0, [r4, #0x2c]
	ldrh r0, [r4, #0x20]
	rsbs r0, r0, #0
	lsls r0, r0, #2
	strh r0, [r4, #0x30]
_0819632C:
	mov r0, r8
	ldrh r1, [r0, #0x3e]
	ldr r2, _08196350 @ =0x00000CE4
	adds r0, r4, r2
	strh r1, [r0]
	mov r0, r8
	adds r0, #0x43
	ldrb r1, [r0]
	ldr r3, _08196354 @ =0x00000CE6
	adds r0, r4, r3
	strh r1, [r0]
_08196342:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196350: .4byte 0x00000CE4
_08196354: .4byte 0x00000CE6

	thumb_func_start FUN_08196358
FUN_08196358: @ 0x08196358
	movs r2, #0
	strh r2, [r0, #0x1c]
	strh r2, [r0, #0x1e]
	strh r2, [r0, #0x20]
	strh r2, [r0, #0x24]
	movs r1, #1
	strh r1, [r0, #0x26]
	strh r2, [r0, #0x28]
	ldr r1, _08196374 @ =0x00000C68
	adds r0, r0, r1
	movs r1, #0x14
	str r1, [r0]
	bx lr
	.align 2, 0
_08196374: .4byte 0x00000C68

	thumb_func_start FUN_08196378
FUN_08196378: @ 0x08196378
	push {lr}
	adds r2, r0, #0
	ldr r0, _081963B8 @ =0x00000C68
	adds r3, r2, r0
	ldr r0, [r3]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08196392
	ldrh r0, [r2, #0x26]
	ldrh r1, [r2, #0x1e]
	adds r0, r0, r1
	strh r0, [r2, #0x1e]
_08196392:
	ldr r0, [r3]
	subs r0, #1
	str r0, [r3]
	cmp r0, #0
	bne _081963A6
	ldrh r0, [r2, #0x26]
	rsbs r0, r0, #0
	strh r0, [r2, #0x26]
	movs r0, #0x28
	str r0, [r3]
_081963A6:
	ldr r0, _081963BC @ =0x00000AFE
	adds r1, r2, r0
	ldrh r0, [r2, #0x1e]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081963B8: .4byte 0x00000C68
_081963BC: .4byte 0x00000AFE

	thumb_func_start FUN_081963c0
FUN_081963c0: @ 0x081963C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081963E8 @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #7
	ble _081963E2
	ldr r2, _081963EC @ =0x00000AFC
	adds r0, r4, r2
	bl FUN_082328ec
	movs r2, #0xc7
	lsls r2, r2, #4
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r1]
_081963E2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081963E8: .4byte 0x00000CEC
_081963EC: .4byte 0x00000AFC

	thumb_func_start FUN_081963f0
FUN_081963f0: @ 0x081963F0
	push {lr}
	adds r1, r0, #0
	ldr r0, _08196414 @ =0x00000C64
	adds r2, r1, r0
	ldr r0, [r2]
	subs r0, #1
	str r0, [r2]
	cmp r0, #0
	bne _08196410
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [r2]
	ldr r0, _08196418 @ =0x00000C44
	adds r1, r1, r0
	ldr r0, _0819641C @ =FUN_08196420
	str r0, [r1]
_08196410:
	pop {r0}
	bx r0
	.align 2, 0
_08196414: .4byte 0x00000C64
_08196418: .4byte 0x00000C44
_0819641C: .4byte FUN_08196420

	thumb_func_start FUN_08196420
FUN_08196420: @ 0x08196420
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x18]
	ldrh r0, [r0, #0x2c]
	movs r1, #0x84
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r0, [r2]
	ldr r0, [r5, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r1, #2
	adds r3, r5, r1
	strh r0, [r3]
	ldr r0, [r5, #0x18]
	ldrh r0, [r0, #0x30]
	adds r1, #2
	adds r4, r5, r1
	strh r0, [r4]
	ldr r0, _081964B0 @ =0x00000AFC
	adds r1, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x85
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r0, [r2]
	ldr r0, _081964B4 @ =0x00000AFE
	adds r1, r5, r0
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r3, _081964B8 @ =0x0000042A
	adds r1, r5, r3
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #4
	adds r1, r5, r0
	ldrh r0, [r4]
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r3, #2
	adds r1, r5, r3
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _081964BC @ =0x00000449
	adds r1, r5, r3
	strb r0, [r1]
	ldr r3, _081964C0 @ =0x085B0A08
	ldrb r2, [r1]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r2, r2, #1
	adds r2, r2, r3
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r0, #0
	blt _081964C4
	asrs r0, r0, #0xa
	b _081964CA
	.align 2, 0
_081964B0: .4byte 0x00000AFC
_081964B4: .4byte 0x00000AFE
_081964B8: .4byte 0x0000042A
_081964BC: .4byte 0x00000449
_081964C0: .4byte 0x085B0A08
_081964C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081964CA:
	strh r0, [r5, #0x1c]
	cmp r1, #0
	blt _081964D4
	asrs r0, r1, #0xa
	b _081964DA
_081964D4:
	rsbs r0, r1, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081964DA:
	strh r0, [r5, #0x20]
	ldr r0, _0819650C @ =0x00000AFC
	adds r2, r5, r0
	ldrh r1, [r5, #0x2c]
	ldrh r3, [r5, #0x1c]
	adds r1, r1, r3
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	movs r0, #0xb0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldrh r1, [r5, #0x2c]
	ldrh r3, [r5, #0x20]
	adds r1, r1, r3
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	blt _08196510
	asrs r0, r0, #1
	b _08196516
	.align 2, 0
_0819650C: .4byte 0x00000AFC
_08196510:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08196516:
	strh r0, [r5, #0x2c]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	cmp r0, #0
	blt _08196524
	asrs r0, r0, #1
	b _0819652A
_08196524:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0819652A:
	strh r0, [r5, #0x30]
	ldr r3, _0819656C @ =0x00000C64
	adds r1, r5, r3
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _08196566
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [r1]
	movs r0, #1
	movs r1, #3
	adds r2, r5, #0
	adds r2, #0x4a
	strb r0, [r2]
	adds r2, #1
	strb r1, [r2]
	subs r2, #6
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08196570 @ =0x00000C38
	adds r1, r5, r0
	ldr r0, _08196574 @ =FUN_08197858
	str r0, [r1]
	ldr r2, _08196578 @ =0x00000C44
	adds r1, r5, r2
	ldr r0, _0819657C @ =FUN_081963f0
	str r0, [r1]
_08196566:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819656C: .4byte 0x00000C64
_08196570: .4byte 0x00000C38
_08196574: .4byte FUN_08197858
_08196578: .4byte 0x00000C44
_0819657C: .4byte FUN_081963f0

	thumb_func_start FUN_08196580
FUN_08196580: @ 0x08196580
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081965A6
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081965A6
	ldr r0, _081965C4 @ =0x00000CC3
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_081965A6:
	ldr r0, _081965C4 @ =0x00000CC3
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	ble _081965BE
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081965C8 @ =0x00000C48
	adds r1, r4, r0
	ldr r0, _081965CC @ =FUN_081965d0
	str r0, [r1]
_081965BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081965C4: .4byte 0x00000CC3
_081965C8: .4byte 0x00000C48
_081965CC: .4byte FUN_081965d0

	thumb_func_start FUN_081965d0
FUN_081965d0: @ 0x081965D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _081966F8 @ =0x00000CCA
	adds r1, r7, r0
	movs r2, #0x89
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	ble _08196600
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081966FC @ =0x00000169
	bl PlaySound_082406e0
_08196600:
	ldr r0, _08196700 @ =0x00000AE6
	adds r1, r7, r0
	ldrb r0, [r4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	ldr r3, _08196704 @ =0x00000CEC
	adds r0, r7, r3
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0819662A
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	ble _0819662A
	strb r1, [r4]
_0819662A:
	ldr r0, _08196708 @ =0x0000044C
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	adds r0, #1
	mov r1, sb
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x96
	bls _081966EC
	ldr r2, _0819670C @ =0x00000AFC
	adds r5, r7, r2
	movs r3, #0
	ldrsh r0, [r5, r3]
	ldr r2, [r7, #0x18]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r6, r7, r1
	movs r3, #0
	ldrsh r1, [r6, r3]
	movs r3, #0x30
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _08196710 @ =0x00000449
	adds r0, r7, r2
	strb r1, [r0]
	ldrh r1, [r5]
	movs r3, #0x86
	lsls r3, r3, #3
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, _08196714 @ =0x00000AFE
	adds r0, r0, r7
	mov r8, r0
	ldrh r1, [r0]
	subs r2, #0x17
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r1, [r6]
	adds r3, #4
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, [r7, #0x18]
	ldrh r0, [r0, #0x2c]
	movs r1, #0x84
	lsls r1, r1, #3
	adds r2, r7, r1
	strh r0, [r2]
	ldr r1, [r7, #0x18]
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r1, [r1, #0x2e]
	adds r0, r0, r1
	ldr r1, _08196718 @ =0x00000422
	adds r3, r7, r1
	strh r0, [r3]
	ldr r0, [r7, #0x18]
	ldrh r0, [r0, #0x30]
	adds r1, #2
	adds r4, r7, r1
	strh r0, [r4]
	ldrh r0, [r2]
	ldrh r1, [r5]
	subs r0, r0, r1
	movs r2, #0x85
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r0, [r3]
	mov r3, r8
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r0, [r4]
	ldrh r1, [r6]
	subs r0, r0, r1
	ldr r3, _0819671C @ =0x0000042C
	adds r1, r7, r3
	strh r0, [r1]
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	ldr r2, _08196720 @ =0x00000C48
	adds r1, r7, r2
	ldr r0, _08196724 @ =FUN_08196728
	str r0, [r1]
_081966EC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081966F8: .4byte 0x00000CCA
_081966FC: .4byte 0x00000169
_08196700: .4byte 0x00000AE6
_08196704: .4byte 0x00000CEC
_08196708: .4byte 0x0000044C
_0819670C: .4byte 0x00000AFC
_08196710: .4byte 0x00000449
_08196714: .4byte 0x00000AFE
_08196718: .4byte 0x00000422
_0819671C: .4byte 0x0000042C
_08196720: .4byte 0x00000C48
_08196724: .4byte FUN_08196728

	thumb_func_start FUN_08196728
FUN_08196728: @ 0x08196728
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _081967D0 @ =0x00000CCA
	adds r1, r4, r0
	movs r2, #0x89
	lsls r2, r2, #3
	adds r6, r4, r2
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	ble _0819675C
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081967D4 @ =0x00000169
	bl PlaySound_082406e0
_0819675C:
	movs r5, #0
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r5, r0
	bge _0819681E
	ldr r0, _081967D8 @ =0x00000AE6
	adds r2, r4, r0
	movs r7, #0
	ldr r1, _081967DC @ =0x0000044C
	adds r1, r1, r4
	mov sl, r1
	adds r3, r6, #0
	ldr r0, _081967E0 @ =0x00000C48
	adds r6, r4, r0
	ldr r1, _081967E4 @ =0x00000449
	adds r1, r1, r4
	mov ip, r1
	movs r0, #0x85
	lsls r0, r0, #3
	adds r0, r0, r4
	mov r8, r0
	ldr r1, _081967E8 @ =0x0000042C
	adds r1, r1, r4
	mov sb, r1
	adds r4, #0x60
	str r4, [sp]
_08196790:
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	mov r4, ip
	ldrb r1, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r1
	bne _08196814
	strb r1, [r2]
	mov r0, sl
	strh r7, [r0]
	strb r7, [r3]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	mov r3, sb
	movs r4, #0
	ldrsh r0, [r3, r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _081967EC @ =0x000F423F
	cmp r1, r0
	bgt _081967F4
	ldr r3, _081967F0 @ =FUN_08196830
	str r3, [r6]
	b _0819681E
	.align 2, 0
_081967D0: .4byte 0x00000CCA
_081967D4: .4byte 0x00000169
_081967D8: .4byte 0x00000AE6
_081967DC: .4byte 0x0000044C
_081967E0: .4byte 0x00000C48
_081967E4: .4byte 0x00000449
_081967E8: .4byte 0x0000042C
_081967EC: .4byte 0x000F423F
_081967F0: .4byte FUN_08196830
_081967F4:
	ldr r3, _08196810 @ =FUN_08196978
	movs r4, #1
	ldr r1, [sp]
	adds r2, r1, #0
	adds r2, #0x84
_081967FE:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _081967FE
	str r3, [r6]
	b _0819681E
	.align 2, 0
_08196810: .4byte FUN_08196978
_08196814:
	adds r5, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r5, r0
	blt _08196790
_0819681E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08196830
FUN_08196830: @ 0x08196830
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08196856
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08196856
	ldr r2, _08196880 @ =0x00000CC3
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08196856:
	ldr r0, _08196880 @ =0x00000CC3
	adds r2, r4, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #1
	ble _0819687A
	movs r1, #0
	strb r1, [r2]
	ldr r2, _08196884 @ =0x0000044C
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08196888 @ =0x00000C48
	adds r1, r4, r0
	ldr r0, _0819688C @ =FUN_08196894
	str r0, [r1]
	ldr r0, _08196890 @ =0x0000018F
	bl PlaySound_082406e0
_0819687A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08196880: .4byte 0x00000CC3
_08196884: .4byte 0x0000044C
_08196888: .4byte 0x00000C48
_0819688C: .4byte FUN_08196894
_08196890: .4byte 0x0000018F

	thumb_func_start FUN_08196894
FUN_08196894: @ 0x08196894
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08196954 @ =0x0000044C
	adds r5, r4, r0
	ldrh r0, [r5]
	muls r0, r1, r0
	movs r1, #0x10
	bl Div
	movs r2, #0x86
	lsls r2, r2, #3
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	ldr r0, _08196958 @ =0x00000AFC
	adds r7, r4, r0
	strh r1, [r7]
	ldr r1, _0819695C @ =0x0000042A
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r5]
	muls r0, r1, r0
	movs r1, #0x10
	bl Div
	ldr r2, _08196960 @ =0x00000432
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	ldr r0, _08196964 @ =0x00000AFE
	adds r6, r4, r0
	strh r1, [r6]
	ldr r1, _08196968 @ =0x0000042C
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r5]
	muls r0, r1, r0
	movs r1, #0x10
	bl Div
	ldr r2, _0819696C @ =0x00000434
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	movs r0, #0xb0
	lsls r0, r0, #4
	adds r2, r4, r0
	strh r1, [r2]
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bls _0819694C
	movs r0, #0
	strh r0, [r5]
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r7]
	adds r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r6]
	adds r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r5, _08196970 @ =FUN_08196978
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0x60
	adds r2, r4, #0
	adds r2, #0xe4
_0819693A:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _0819693A
	ldr r2, _08196974 @ =0x00000C48
	adds r0, r4, r2
	str r5, [r0]
_0819694C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196954: .4byte 0x0000044C
_08196958: .4byte 0x00000AFC
_0819695C: .4byte 0x0000042A
_08196960: .4byte 0x00000432
_08196964: .4byte 0x00000AFE
_08196968: .4byte 0x0000042C
_0819696C: .4byte 0x00000434
_08196970: .4byte FUN_08196978
_08196974: .4byte 0x00000C48

	thumb_func_start FUN_08196978
FUN_08196978: @ 0x08196978
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	ldr r1, _08196A4C @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #7
	ands r0, r2
	cmp r0, #0
	bne _081969A8
	movs r0, #0x89
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	ble _081969A8
	strb r2, [r1]
_081969A8:
	movs r5, #0
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r5, r0
	bge _08196A3C
	adds r0, r1, #0
	adds r0, r0, r4
	mov sb, r0
	mov sl, r5
_081969C2:
	ldr r0, _08196A50 @ =0x00000AE6
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x80
	bne _08196A30
	adds r7, r4, #0
	adds r7, #0x4a
	movs r1, #0x4b
	adds r1, r1, r4
	mov r8, r1
	adds r6, r4, #0
	adds r6, #0x45
	cmp r5, #3
	bgt _08196A02
	movs r3, #0x80
	movs r2, #1
	movs r0, #0x2c
	muls r0, r5, r0
	adds r0, #0x60
	adds r1, r0, r4
_081969F2:
	strb r3, [r1, #6]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x2c
	adds r5, #1
	cmp r5, #3
	ble _081969F2
_08196A02:
	mov r1, sl
	mov r0, sb
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08196358
	movs r0, #1
	strb r0, [r7]
	mov r0, sl
	mov r1, r8
	strb r0, [r1]
	ldrb r1, [r6]
	movs r0, #1
	orrs r0, r1
	strb r0, [r6]
	ldr r0, _08196A54 @ =0x00000C38
	adds r1, r4, r0
	ldr r0, _08196A58 @ =FUN_081975b8
	str r0, [r1]
	ldr r0, _08196A5C @ =0x00000C48
	adds r1, r4, r0
	ldr r0, _08196A60 @ =FUN_08196580
	str r0, [r1]
_08196A30:
	adds r5, #1
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r5, r0
	blt _081969C2
_08196A3C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196A4C: .4byte 0x00000CEC
_08196A50: .4byte 0x00000AE6
_08196A54: .4byte 0x00000C38
_08196A58: .4byte FUN_081975b8
_08196A5C: .4byte 0x00000C48
_08196A60: .4byte FUN_08196580

	thumb_func_start FUN_08196a64
FUN_08196a64: @ 0x08196A64
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08196A8A
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08196A8A
	ldr r0, _08196AA8 @ =0x00000CC3
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08196A8A:
	ldr r0, _08196AA8 @ =0x00000CC3
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	ble _08196AA2
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08196AAC @ =0x00000C4C
	adds r1, r4, r0
	ldr r0, _08196AB0 @ =FUN_08196ab4
	str r0, [r1]
_08196AA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08196AA8: .4byte 0x00000CC3
_08196AAC: .4byte 0x00000C4C
_08196AB0: .4byte FUN_08196ab4

	thumb_func_start FUN_08196ab4
FUN_08196ab4: @ 0x08196AB4
	push {r4, lr}
	adds r2, r0, #0
	ldr r1, _08196AE4 @ =0x00000CEC
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08196AFE
	movs r4, #0x8a
	lsls r4, r4, #3
	adds r3, r2, r4
	ldr r1, _08196AE8 @ =0x00000ACA
	adds r0, r2, r1
	ldr r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	blt _08196AF4
	ldr r4, _08196AEC @ =0x00000C4C
	adds r1, r2, r4
	ldr r0, _08196AF0 @ =FUN_08196b08
	str r0, [r1]
	b _08196AFE
	.align 2, 0
_08196AE4: .4byte 0x00000CEC
_08196AE8: .4byte 0x00000ACA
_08196AEC: .4byte 0x00000C4C
_08196AF0: .4byte FUN_08196b08
_08196AF4:
	ldr r4, _08196B04 @ =0x00000ACC
	adds r0, r2, r4
	ldrh r0, [r0]
	adds r0, r1, r0
	str r0, [r3]
_08196AFE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08196B04: .4byte 0x00000ACC

	thumb_func_start FUN_08196b08
FUN_08196b08: @ 0x08196B08
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r1, _08196BA0 @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08196BCA
	movs r3, #0x8a
	lsls r3, r3, #3
	adds r1, r4, r3
	ldr r2, [r1]
	cmp r2, #0
	bgt _08196BB8
	movs r0, #0x89
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r0, #1
	movs r1, #2
	adds r2, r4, #0
	adds r2, #0x4a
	strb r0, [r2]
	adds r2, #1
	strb r1, [r2]
	subs r2, #6
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r3, _08196BA4 @ =0x00000C38
	adds r1, r4, r3
	ldr r0, _08196BA8 @ =FUN_081976f4
	str r0, [r1]
	movs r6, #0
	movs r0, #0x60
	adds r0, r0, r4
	mov ip, r0
	ldr r1, _08196BAC @ =FUN_08196ab4
	mov r8, r1
	movs r7, #4
	adds r3, r4, #0
	movs r5, #0
_08196B68:
	mov r0, ip
	adds r2, r0, r5
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	orrs r0, r7
	strh r0, [r1]
	ldr r0, _08196BB0 @ =0x000002C6
	adds r1, r3, r0
	ldrh r0, [r1]
	orrs r0, r7
	strh r0, [r1]
	adds r3, #0x50
	adds r5, #0x2c
	adds r6, #1
	cmp r6, #3
	ble _08196B68
	ldr r1, _08196BB4 @ =0x00000C4C
	adds r0, r4, r1
	mov r3, r8
	str r3, [r0]
	b _08196BCA
	.align 2, 0
_08196BA0: .4byte 0x00000CEC
_08196BA4: .4byte 0x00000C38
_08196BA8: .4byte FUN_081976f4
_08196BAC: .4byte FUN_08196ab4
_08196BB0: .4byte 0x000002C6
_08196BB4: .4byte 0x00000C4C
_08196BB8:
	ldr r3, _08196BD8 @ =0x00000ACC
	adds r0, r4, r3
	ldrh r0, [r0]
	subs r0, r2, r0
	str r0, [r1]
	cmp r0, #0
	bge _08196BC8
	movs r0, #0
_08196BC8:
	str r0, [r1]
_08196BCA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196BD8: .4byte 0x00000ACC

	thumb_func_start FUN_08196bdc
FUN_08196bdc: @ 0x08196BDC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08196C02
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08196C02
	ldr r0, _08196C20 @ =0x00000CC3
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08196C02:
	ldr r0, _08196C20 @ =0x00000CC3
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	ble _08196C1A
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08196C24 @ =0x00000C4C
	adds r1, r4, r0
	ldr r0, _08196C28 @ =FUN_08196c2c
	str r0, [r1]
_08196C1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08196C20: .4byte 0x00000CC3
_08196C24: .4byte 0x00000C4C
_08196C28: .4byte FUN_08196c2c

	thumb_func_start FUN_08196c2c
FUN_08196c2c: @ 0x08196C2C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x18]
	ldrh r0, [r0, #0x2c]
	movs r1, #0x84
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r0, [r2]
	ldr r0, [r5, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r1, #2
	adds r3, r5, r1
	strh r0, [r3]
	ldr r0, [r5, #0x18]
	ldrh r0, [r0, #0x30]
	adds r1, #2
	adds r4, r5, r1
	strh r0, [r4]
	ldr r0, _08196CBC @ =0x00000AFC
	adds r1, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x85
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r0, [r2]
	ldr r0, _08196CC0 @ =0x00000AFE
	adds r1, r5, r0
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r3, _08196CC4 @ =0x0000042A
	adds r1, r5, r3
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #4
	adds r1, r5, r0
	ldrh r0, [r4]
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r3, #2
	adds r1, r5, r3
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _08196CC8 @ =0x00000449
	adds r1, r5, r3
	strb r0, [r1]
	ldr r3, _08196CCC @ =0x085B0A08
	ldrb r2, [r1]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r2, r2, #1
	adds r2, r2, r3
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r0, #0
	blt _08196CD0
	asrs r0, r0, #0xa
	b _08196CD6
	.align 2, 0
_08196CBC: .4byte 0x00000AFC
_08196CC0: .4byte 0x00000AFE
_08196CC4: .4byte 0x0000042A
_08196CC8: .4byte 0x00000449
_08196CCC: .4byte 0x085B0A08
_08196CD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_08196CD6:
	strh r0, [r5, #0x1c]
	cmp r1, #0
	blt _08196CE0
	asrs r0, r1, #0xa
	b _08196CE6
_08196CE0:
	rsbs r0, r1, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_08196CE6:
	strh r0, [r5, #0x20]
	ldr r0, _08196D30 @ =0x00000AFC
	adds r1, r5, r0
	ldrh r0, [r5, #0x1c]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r1, r5, r3
	ldrh r0, [r5, #0x20]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08196D34 @ =0x00000CEC
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08196D28
	movs r0, #0x8a
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	cmp r0, #0x50
	bne _08196D28
	ldr r2, _08196D38 @ =0x00000C4C
	adds r1, r5, r2
	ldr r0, _08196D3C @ =FUN_08196d40
	str r0, [r1]
_08196D28:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08196D30: .4byte 0x00000AFC
_08196D34: .4byte 0x00000CEC
_08196D38: .4byte 0x00000C4C
_08196D3C: .4byte FUN_08196d40

	thumb_func_start FUN_08196d40
FUN_08196d40: @ 0x08196D40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldr r1, _08196DE4 @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08196DD8
	movs r0, #0x8a
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _08196DD8
	movs r0, #0x89
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
	movs r0, #1
	movs r1, #2
	adds r2, r4, #0
	adds r2, #0x4a
	strb r0, [r2]
	adds r2, #1
	strb r1, [r2]
	subs r2, #6
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08196DE8 @ =0x00000C38
	adds r1, r4, r0
	ldr r0, _08196DEC @ =FUN_081976f4
	str r0, [r1]
	movs r6, #0
	movs r1, #0x60
	adds r1, r1, r4
	mov ip, r1
	ldr r0, _08196DF0 @ =FUN_08196c2c
	mov r8, r0
	movs r7, #4
	adds r3, r4, #0
	movs r5, #0
_08196DA4:
	mov r0, ip
	adds r2, r0, r5
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	orrs r0, r7
	strh r0, [r1]
	ldr r0, _08196DF4 @ =0x000002C6
	adds r1, r3, r0
	ldrh r0, [r1]
	orrs r0, r7
	strh r0, [r1]
	adds r3, #0x50
	adds r5, #0x2c
	adds r6, #1
	cmp r6, #3
	ble _08196DA4
	ldr r1, _08196DF8 @ =0x00000C4C
	adds r0, r4, r1
	mov r1, r8
	str r1, [r0]
_08196DD8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196DE4: .4byte 0x00000CEC
_08196DE8: .4byte 0x00000C38
_08196DEC: .4byte FUN_081976f4
_08196DF0: .4byte FUN_08196c2c
_08196DF4: .4byte 0x000002C6
_08196DF8: .4byte 0x00000C4C

	thumb_func_start FUN_08196dfc
FUN_08196dfc: @ 0x08196DFC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08196E22
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08196E22
	ldr r0, _08196E48 @ =0x00000CC3
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08196E22:
	ldr r0, _08196E48 @ =0x00000CC3
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	ble _08196E42
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xc5
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _08196E4C @ =FUN_08196e54
	str r0, [r1]
	ldr r0, _08196E50 @ =0x0000016B
	bl PlaySound_082406e0
_08196E42:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08196E48: .4byte 0x00000CC3
_08196E4C: .4byte FUN_08196e54
_08196E50: .4byte 0x0000016B

	thumb_func_start FUN_08196e54
FUN_08196e54: @ 0x08196E54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r6, #0
_08196E64:
	ldrh r2, [r7, #0x1c]
	rsbs r2, r2, #0
	strh r2, [r7, #0x1c]
	ldrh r0, [r7, #0x20]
	rsbs r0, r0, #0
	strh r0, [r7, #0x20]
	movs r0, #0x2c
	muls r0, r6, r0
	adds r3, r7, r0
	adds r1, r3, #0
	adds r1, #0x7c
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r2, r3, #0
	adds r2, #0x80
	ldrh r0, [r2]
	ldrh r1, [r7, #0x20]
	subs r0, r0, r1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0x68
	ldrb r0, [r1]
	subs r0, #2
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bgt _08196EA2
	movs r0, #1
	strb r0, [r1]
_08196EA2:
	adds r6, #1
	cmp r6, #3
	ble _08196E64
	ldr r1, _08197014 @ =0x00000CEC
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08196EB8
	b _08197004
_08196EB8:
	ldrh r0, [r7, #0x24]
	adds r0, #1
	strh r0, [r7, #0x24]
	ldrh r1, [r7, #0x28]
	adds r1, #1
	strh r1, [r7, #0x28]
	strh r0, [r7, #0x1c]
	strh r1, [r7, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bgt _08196ED2
	b _08197004
_08196ED2:
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08197018 @ =0x00000AFC
	adds r2, r7, r2
	str r2, [sp]
	ldrh r0, [r0]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r7, #0x1c]
	adds r0, r7, #0
	adds r0, #0x80
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r5, r7, r3
	ldrh r0, [r0]
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r7, #0x20]
	ldr r2, _0819701C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08197020 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08197024 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov sl, r2
	ldrb r4, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	ldr r3, _08197028 @ =0x085B0A08
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r6, #0xc8
	muls r0, r6, r0
	movs r2, #0x80
	lsls r2, r2, #5
	mov r8, r2
	mov r1, r8
	bl Div
	ldr r1, [r7, #0x18]
	ldrh r1, [r1, #0x2c]
	adds r1, r1, r0
	ldr r3, [sp]
	strh r1, [r3]
	ldr r1, [r7, #0x18]
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1, #0x2e]
	adds r0, r0, r1
	ldr r3, _0819702C @ =0x00000AFE
	adds r3, r3, r7
	mov sb, r3
	strh r0, [r3]
	mov r0, sl
	ands r4, r0
	lsls r4, r4, #1
	ldr r1, _08197028 @ =0x085B0A08
	adds r4, r4, r1
	movs r2, #0
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	mov r1, r8
	bl Div
	ldr r1, [r7, #0x18]
	ldrh r1, [r1, #0x30]
	adds r1, r1, r0
	strh r1, [r5]
	movs r6, #0
	adds r3, r7, #0
	adds r3, #0x60
	str r3, [sp, #8]
	ldr r0, [sp]
	mov r8, r0
	movs r1, #0x84
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #4]
	adds r4, r7, #0
	mov ip, sb
	ldr r2, _08197030 @ =0x00000422
	adds r2, r2, r7
	mov sl, r2
	ldr r3, _08197034 @ =0x00000424
	adds r3, r3, r7
	mov sb, r3
_08196F8E:
	movs r0, #0x2c
	adds r2, r6, #0
	muls r2, r0, r2
	ldr r0, [sp, #8]
	adds r3, r0, r2
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r2, r7, r2
	ldrh r1, [r7, #0x1c]
	mov r3, r8
	ldrh r3, [r3]
	adds r1, r1, r3
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r4, r3
	strh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x7c
	strh r1, [r0]
	ldrh r1, [r7, #0x20]
	ldrh r0, [r5]
	adds r1, r1, r0
	adds r3, #4
	adds r0, r4, r3
	strh r1, [r0]
	adds r2, #0x80
	strh r1, [r2]
	mov r1, r8
	ldrh r0, [r1]
	ldr r2, [sp, #4]
	strh r0, [r2]
	mov r3, ip
	ldrh r0, [r3]
	mov r1, sl
	strh r0, [r1]
	ldrh r0, [r5]
	mov r2, sb
	strh r0, [r2]
	ldrh r0, [r7, #0x1c]
	rsbs r0, r0, #0
	strh r0, [r7, #0x1c]
	ldrh r0, [r7, #0x20]
	rsbs r0, r0, #0
	strh r0, [r7, #0x20]
	adds r4, #8
	adds r6, #1
	cmp r6, #3
	ble _08196F8E
	ldr r3, _08197038 @ =0x00000C64
	adds r1, r7, r3
	movs r0, #0x1e
	str r0, [r1]
	movs r0, #0xc5
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, _0819703C @ =FUN_08197040
	str r0, [r1]
_08197004:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08197014: .4byte 0x00000CEC
_08197018: .4byte 0x00000AFC
_0819701C: .4byte 0x030046B8
_08197020: .4byte 0x000003FF
_08197024: .4byte 0x0203B400
_08197028: .4byte 0x085B0A08
_0819702C: .4byte 0x00000AFE
_08197030: .4byte 0x00000422
_08197034: .4byte 0x00000424
_08197038: .4byte 0x00000C64
_0819703C: .4byte FUN_08197040

	thumb_func_start FUN_08197040
FUN_08197040: @ 0x08197040
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081970A8 @ =0x00000C64
	adds r1, r4, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _081970A0
	ldr r0, _081970AC @ =0x00000422
	adds r5, r4, r0
	adds r1, r4, #0
	adds r1, #0x60
	adds r2, r4, #0
	adds r2, #0x7e
	adds r3, r4, #0
	adds r3, #0xe4
	movs r6, #2
	rsbs r6, r6, #0
_08197066:
	ldrh r0, [r5]
	strh r0, [r2]
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	adds r1, #0x2c
	adds r2, #0x2c
	cmp r1, r3
	ble _08197066
	adds r0, r4, #0
	bl FUN_08196358
	ldr r0, _081970A8 @ =0x00000C64
	adds r1, r4, r0
	movs r0, #0xf
	str r0, [r1]
	ldr r0, _081970B0 @ =0x00000C68
	adds r1, r4, r0
	movs r0, #0x14
	str r0, [r1]
	movs r0, #0xc5
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _081970B4 @ =FUN_081970b8
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081970A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081970A8: .4byte 0x00000C64
_081970AC: .4byte 0x00000422
_081970B0: .4byte 0x00000C68
_081970B4: .4byte FUN_081970b8

	thumb_func_start FUN_081970b8
FUN_081970b8: @ 0x081970B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r7, #0
	movs r0, #0x84
	lsls r0, r0, #3
	adds r0, r0, r5
	mov sl, r0
	ldr r1, _08197220 @ =0x00000C64
	adds r1, r1, r5
	mov sb, r1
	ldr r2, _08197224 @ =0x00000424
	adds r2, r2, r5
	mov r8, r2
	movs r0, #0x80
	lsls r0, r0, #3
	adds r6, r5, r0
_081970E2:
	mov r2, sl
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r2, #0
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	mov r2, sb
	ldr r0, [r2]
	muls r0, r1, r0
	movs r1, #0xf
	bl Div
	movs r1, #0x2c
	muls r1, r7, r1
	adds r4, r5, r1
	mov r2, sl
	ldrh r1, [r2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x7c
	strh r1, [r0]
	mov r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #4
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	mov r2, sb
	ldr r0, [r2]
	muls r0, r1, r0
	movs r1, #0xf
	bl Div
	mov r2, r8
	ldrh r1, [r2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x80
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0x68
	ldrb r0, [r1]
	adds r0, #3
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x3f
	ble _08197146
	movs r0, #0x40
	strb r0, [r1]
_08197146:
	adds r6, #8
	adds r7, #1
	cmp r7, #3
	ble _081970E2
	ldr r6, _08197228 @ =0x00000CEC
	adds r0, r5, r6
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0819720E
	ldr r0, _08197220 @ =0x00000C64
	adds r1, r5, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _0819720E
	adds r1, r5, #0
	adds r1, #0x4a
	str r1, [sp, #4]
	adds r2, r5, #0
	adds r2, #0x4b
	str r2, [sp]
	movs r6, #0x45
	adds r6, r6, r5
	mov ip, r6
	movs r0, #0x84
	lsls r0, r0, #3
	adds r0, r0, r5
	mov r8, r0
	ldr r1, _08197224 @ =0x00000424
	adds r1, r5, r1
	str r1, [sp, #8]
	adds r2, #0x1d
	movs r3, #0
	movs r6, #0x40
	mov sl, r6
	adds r4, r5, #0
	adds r4, #0x60
	movs r0, #1
	mov sb, r0
	movs r7, #3
_0819719C:
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r2, #0x14]
	ldr r6, [sp, #8]
	ldrh r0, [r6]
	strh r0, [r2, #0x18]
	mov r0, sl
	strb r0, [r2]
	adds r1, r4, r3
	ldr r0, [r1]
	mov r6, sb
	orrs r0, r6
	str r0, [r1]
	adds r2, #0x2c
	adds r3, #0x2c
	subs r7, #1
	cmp r7, #0
	bge _0819719C
	movs r0, #0xae
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0819722C @ =0x00000B9A
	adds r3, r5, r1
	ldrh r2, [r3]
	ldr r1, _08197230 @ =0x0000FFFB
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	ldr r6, _08197234 @ =0x00000BEA
	adds r2, r5, r6
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	movs r0, #1
	movs r1, #5
	ldr r2, [sp, #4]
	strb r0, [r2]
	ldr r6, [sp]
	strb r1, [r6]
	mov r2, ip
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r6, _08197238 @ =0x00000C38
	adds r0, r5, r6
	ldr r1, _0819723C @ =FUN_08197c30
	str r1, [r0]
	movs r2, #0xc5
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r6, _08197240 @ =FUN_08196e54
	str r6, [r0]
_0819720E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08197220: .4byte 0x00000C64
_08197224: .4byte 0x00000424
_08197228: .4byte 0x00000CEC
_0819722C: .4byte 0x00000B9A
_08197230: .4byte 0x0000FFFB
_08197234: .4byte 0x00000BEA
_08197238: .4byte 0x00000C38
_0819723C: .4byte FUN_08197c30
_08197240: .4byte FUN_08196e54

	thumb_func_start FUN_08197244
FUN_08197244: @ 0x08197244
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0819726A
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819726A
	ldr r2, _08197294 @ =0x00000CC3
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0819726A:
	ldr r0, _08197294 @ =0x00000CC3
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	ble _0819728E
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08197298 @ =0x00000AC4
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0819729C @ =0x00000AC6
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _081972A0 @ =0x00000C54
	adds r1, r4, r0
	ldr r0, _081972A4 @ =FUN_081972a8
	str r0, [r1]
_0819728E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08197294: .4byte 0x00000CC3
_08197298: .4byte 0x00000AC4
_0819729C: .4byte 0x00000AC6
_081972A0: .4byte 0x00000C54
_081972A4: .4byte FUN_081972a8

	thumb_func_start FUN_081972a8
FUN_081972a8: @ 0x081972A8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081972BC @ =0x00000AC6
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08197304
	subs r0, #1
	strh r0, [r1]
	b _08197334
	.align 2, 0
_081972BC: .4byte 0x00000AC6
_081972C0:
	adds r0, r5, r4
	ldr r1, _081972F4 @ =0x0000053C
	adds r0, r0, r1
	movs r1, #1
	adds r2, r0, #0
	adds r2, #0x2e
	strb r1, [r2]
	adds r2, #1
	strb r3, [r2]
	adds r0, #0x29
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
	movs r2, #0xb6
	lsls r2, r2, #3
	adds r0, r4, r2
	adds r0, r0, r5
	ldr r1, _081972F8 @ =FUN_08199aa4
	str r1, [r0]
	ldr r1, _081972FC @ =0x00000AC4
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _08197300 @ =0x00000AC6
	adds r0, r4, r2
	strh r1, [r0]
	b _08197334
	.align 2, 0
_081972F4: .4byte 0x0000053C
_081972F8: .4byte FUN_08199aa4
_081972FC: .4byte 0x00000AC4
_08197300: .4byte 0x00000AC6
_08197304:
	movs r1, #0
	ldr r2, _0819733C @ =0x00000C9C
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	bge _0819732C
	adds r6, r0, #0
	ldr r2, _08197340 @ =0x0000056A
	adds r0, r4, r2
	movs r5, #0
	movs r2, #0xc6
	lsls r2, r2, #1
_0819731C:
	ldrb r3, [r0]
	cmp r3, #0
	beq _081972C0
	adds r0, r0, r2
	adds r5, r5, r2
	adds r1, #1
	cmp r1, r6
	blt _0819731C
_0819732C:
	ldr r0, _08197344 @ =0x00000C54
	adds r1, r4, r0
	ldr r0, _08197348 @ =FUN_0819734c
	str r0, [r1]
_08197334:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819733C: .4byte 0x00000C9C
_08197340: .4byte 0x0000056A
_08197344: .4byte 0x00000C54
_08197348: .4byte FUN_0819734c

	thumb_func_start FUN_0819734c
FUN_0819734c: @ 0x0819734C
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r4, #0
	ldr r1, _08197398 @ =0x00000C9C
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _08197376
	ldr r1, _0819739C @ =0x0000056A
	adds r2, r3, r1
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r1, r0, #0
_08197366:
	ldrb r0, [r2]
	cmp r0, #0
	beq _0819736E
	adds r4, #1
_0819736E:
	adds r2, r2, r5
	subs r1, #1
	cmp r1, #0
	bne _08197366
_08197376:
	cmp r4, #0
	bne _081973A8
	movs r0, #1
	adds r1, r3, #0
	adds r1, #0x4a
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	adds r2, r3, #0
	adds r2, #0x45
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _081973A0 @ =0x00000C38
	adds r1, r3, r0
	ldr r0, _081973A4 @ =FUN_08197650
	b _081973CA
	.align 2, 0
_08197398: .4byte 0x00000C9C
_0819739C: .4byte 0x0000056A
_081973A0: .4byte 0x00000C38
_081973A4: .4byte FUN_08197650
_081973A8:
	ldr r1, _081973D4 @ =0x00000C9C
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _081973CC
	ldr r0, _081973D8 @ =0x00000C98
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _081973CC
	ldr r0, _081973DC @ =0x00000C54
	adds r1, r3, r0
	ldr r0, _081973E0 @ =FUN_0819734c
_081973CA:
	str r0, [r1]
_081973CC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081973D4: .4byte 0x00000C9C
_081973D8: .4byte 0x00000C98
_081973DC: .4byte 0x00000C54
_081973E0: .4byte FUN_0819734c

	thumb_func_start FUN_081973e4
FUN_081973e4: @ 0x081973E4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0x54
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	bne _0819741A
	ldr r0, _08197420 @ =0x00000AEC
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r2, _08197424 @ =0x00000CC6
	adds r1, r5, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
	ldr r1, [r4]
	movs r2, #0xca
	lsls r2, r2, #4
	adds r0, r5, r2
	str r0, [r1, #0xc]
	ldr r1, _08197428 @ =0x00000C5C
	adds r0, r5, r1
	str r6, [r0]
_0819741A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08197420: .4byte 0x00000AEC
_08197424: .4byte 0x00000CC6
_08197428: .4byte 0x00000C5C

	thumb_func_start FUN_0819742c
FUN_0819742c: @ 0x0819742C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	mov sb, r2
	ldr r2, _081974A8 @ =0x00000CE8
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r3, #0x36
	ldrsh r4, [r5, r3]
	ldr r6, _081974AC @ =0x00000CCC
	adds r2, r5, r6
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r6, #2
	adds r3, r5, r6
	ldrb r3, [r3]
	lsrs r1, r1, #2
	movs r6, #1
	mov r8, r6
	ands r1, r6
	str r1, [sp]
	adds r1, r4, #0
	bl FUN_0809c344
	add r6, sp, #0xc
	movs r7, #0
	str r7, [sp, #8]
	add r0, sp, #8
	adds r1, r6, #0
	ldr r2, _081974B0 @ =0x05000002
	bl CpuSet
	ldr r0, _081974B4 @ =0x00000CE4
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08197498
	ldr r0, _081974B8 @ =0x0000FF88
	strh r0, [r6, #2]
	ldr r1, _081974BC @ =0x00000BE4
	adds r0, r5, r1
	ldrh r1, [r4]
	ldr r2, _081974C0 @ =0x00000AFC
	adds r3, r5, r2
	str r6, [sp]
	mov r6, r8
	str r6, [sp, #4]
	mov r2, sb
	bl FUN_0805fe7c
	strh r7, [r4]
_08197498:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081974A8: .4byte 0x00000CE8
_081974AC: .4byte 0x00000CCC
_081974B0: .4byte 0x05000002
_081974B4: .4byte 0x00000CE4
_081974B8: .4byte 0x0000FF88
_081974BC: .4byte 0x00000BE4
_081974C0: .4byte 0x00000AFC

	thumb_func_start FUN_081974c4
FUN_081974c4: @ 0x081974C4
	push {r4, lr}
	ldr r2, _081974EC @ =0x00000B18
	adds r1, r0, r2
	movs r4, #0
	ldr r1, [r1]
	ldr r3, _081974F0 @ =0x00000A84
	adds r2, r0, r3
	movs r3, #0xf
_081974D4:
	strh r4, [r2]
	ldrh r0, [r1]
	strh r0, [r2, #0x20]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _081974D4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081974EC: .4byte 0x00000B18
_081974F0: .4byte 0x00000A84

	thumb_func_start FUN_081974f4
FUN_081974f4: @ 0x081974F4
	push {lr}
	movs r2, #3
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r0, r3
_081974FE:
	str r1, [r0]
	subs r0, #0x1c
	subs r2, #1
	cmp r2, #0
	bge _081974FE
	pop {r0}
	bx r0

	thumb_func_start FUN_0819750c
FUN_0819750c: @ 0x0819750C
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r3, r0, r1
	subs r1, #6
	adds r0, r0, r1
	movs r1, #3
_0819751C:
	strh r2, [r0]
	str r4, [r3]
	adds r3, #0x1c
	adds r0, #0x1c
	subs r1, #1
	cmp r1, #0
	bge _0819751C
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08197530
FUN_08197530: @ 0x08197530
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x4d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081975AC
	bl VM_GetPC
	cmp r0, #0
	beq _0819754E
	bl Script_GetValue
	adds r1, r0, #0
	b _08197550
_0819754E:
	movs r1, #0x3c
_08197550:
	ldr r2, _08197568 @ =0x00000AC4
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819756C
	bl Script_GetValue
	adds r1, r0, #0
	b _0819756E
	.align 2, 0
_08197568: .4byte 0x00000AC4
_0819756C:
	movs r1, #2
_0819756E:
	ldr r2, _08197584 @ =0x00000AC8
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08197588
	bl Script_GetValue
	adds r1, r0, #0
	b _0819758A
	.align 2, 0
_08197584: .4byte 0x00000AC8
_08197588:
	movs r1, #0x50
_0819758A:
	ldr r2, _081975A0 @ =0x00000ACA
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081975A4
	bl Script_GetValue
	adds r1, r0, #0
	b _081975A6
	.align 2, 0
_081975A0: .4byte 0x00000ACA
_081975A4:
	movs r1, #1
_081975A6:
	ldr r2, _081975B4 @ =0x00000ACC
	adds r0, r4, r2
	strh r1, [r0]
_081975AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081975B4: .4byte 0x00000ACC

	thumb_func_start FUN_081975b8
FUN_081975b8: @ 0x081975B8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081975DE
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _081975E0
_081975DE:
	movs r0, #0
_081975E0:
	cmp r0, #0
	beq _081975F6
	ldr r0, _08197638 @ =0x00000C64
	adds r1, r4, r0
	movs r0, #0x96
	str r0, [r1]
	movs r0, #0xc6
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _0819763C @ =FUN_08195c94
	str r0, [r1]
_081975F6:
	adds r0, r4, #0
	bl FUN_08196378
	ldr r0, _08197638 @ =0x00000C64
	adds r1, r4, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _08197630
	movs r0, #1
	movs r1, #4
	adds r2, r4, #0
	adds r2, #0x4a
	strb r0, [r2]
	adds r2, #1
	strb r1, [r2]
	subs r2, #6
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08197640 @ =0x00000C38
	adds r1, r4, r0
	ldr r0, _08197644 @ =FUN_08197ad4
	str r0, [r1]
	ldr r0, _08197648 @ =0x00000C48
	adds r1, r4, r0
	ldr r0, _0819764C @ =FUN_08196580
	str r0, [r1]
_08197630:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08197638: .4byte 0x00000C64
_0819763C: .4byte FUN_08195c94
_08197640: .4byte 0x00000C38
_08197644: .4byte FUN_08197ad4
_08197648: .4byte 0x00000C48
_0819764C: .4byte FUN_08196580

	thumb_func_start FUN_08197650
FUN_08197650: @ 0x08197650
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197676
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197678
_08197676:
	movs r0, #0
_08197678:
	cmp r0, #0
	beq _08197696
	ldr r0, _081976B4 @ =0x00000C64
	adds r1, r4, r0
	movs r0, #0x64
	str r0, [r1]
	ldr r0, _081976B8 @ =0x00000C44
	adds r1, r4, r0
	ldr r0, _081976BC @ =FUN_081963f0
	str r0, [r1]
	movs r0, #0xc6
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _081976C0 @ =FUN_08195c94
	str r0, [r1]
_08197696:
	adds r0, r4, #0
	bl FUN_08196378
	ldr r1, _081976B8 @ =0x00000C44
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081976AC
	adds r0, r4, #0
	bl _call_via_r1
_081976AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081976B4: .4byte 0x00000C64
_081976B8: .4byte 0x00000C44
_081976BC: .4byte FUN_081963f0
_081976C0: .4byte FUN_08195c94

	thumb_func_start FUN_081976c4
FUN_081976c4: @ 0x081976C4
	push {lr}
	adds r2, r0, #0
	ldr r1, _081976E8 @ =0x00000CEC
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _081976E4
	ldr r0, _081976EC @ =0x00000C38
	adds r1, r2, r0
	ldr r0, _081976F0 @ =FUN_081976f4
	str r0, [r1]
	movs r0, #1
	adds r2, #0x45
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_081976E4:
	pop {r0}
	bx r0
	.align 2, 0
_081976E8: .4byte 0x00000CEC
_081976EC: .4byte 0x00000C38
_081976F0: .4byte FUN_081976f4

	thumb_func_start FUN_081976f4
FUN_081976f4: @ 0x081976F4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197720
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197722
_08197720:
	movs r0, #0
_08197722:
	cmp r0, #0
	beq _081977B0
	movs r0, #0x60
	adds r0, r0, r4
	mov ip, r0
	ldr r1, _08197834 @ =FUN_08196580
	mov r8, r1
	ldr r3, _08197838 @ =FUN_081958b4
	mov sb, r3
	ldr r0, _0819783C @ =0x00000AFC
	adds r7, r4, r0
	ldr r1, _08197840 @ =0x00000AFE
	adds r6, r4, r1
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r5, r4, r3
	adds r1, r4, #0
	adds r1, #0x66
	subs r0, #0x16
	adds r3, r4, r0
	movs r2, #3
_0819774C:
	ldrh r0, [r7]
	strh r0, [r1, #0x16]
	ldrh r0, [r6]
	strh r0, [r1, #0x18]
	ldrh r0, [r5]
	strh r0, [r1, #0x1a]
	ldrb r0, [r3]
	strb r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _0819774C
	movs r3, #2
	rsbs r3, r3, #0
	mov r1, ip
	adds r2, r1, #0
	adds r2, #0x84
_0819776E:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _0819776E
	ldr r1, _08197844 @ =0x00000C48
	adds r0, r4, r1
	mov r3, r8
	str r3, [r0]
	ldr r1, _08197848 @ =0x0000044C
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x89
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	ldr r3, _0819784C @ =0x00000CCA
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	mov r3, sb
	str r3, [r0]
	adds r1, #0x63
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _08197850 @ =0x0000016F
	bl PlaySound_082406e0
_081977B0:
	ldr r3, _08197844 @ =0x00000C48
	adds r0, r4, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _081977C0
	adds r0, r4, #0
	bl _call_via_r1
_081977C0:
	ldr r1, _08197854 @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08197826
	movs r2, #3
	adds r5, r4, #0
	adds r5, #0x7c
	adds r6, r4, #0
	adds r6, #0x7e
	adds r7, r4, #0
	adds r7, #0x80
	movs r3, #0x66
	adds r3, r3, r4
	mov ip, r3
	adds r3, r4, #0
	adds r3, #0xbe
	adds r1, r4, #0
	adds r1, #0xd4
_081977EA:
	ldrh r0, [r1]
	strh r0, [r1, #0x2c]
	ldrh r0, [r1, #2]
	strh r0, [r1, #0x2e]
	ldrh r0, [r1, #4]
	strh r0, [r1, #0x30]
	ldrb r0, [r3]
	strb r0, [r1, #0x16]
	subs r3, #0x2c
	subs r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bgt _081977EA
	ldr r1, _0819783C @ =0x00000AFC
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r5]
	ldr r3, _08197840 @ =0x00000AFE
	adds r0, r4, r3
	ldrh r0, [r0]
	strh r0, [r6]
	adds r1, #4
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r7]
	subs r3, #0x18
	adds r0, r4, r3
	ldrb r0, [r0]
	mov r1, ip
	strb r0, [r1]
_08197826:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08197834: .4byte FUN_08196580
_08197838: .4byte FUN_081958b4
_0819783C: .4byte 0x00000AFC
_08197840: .4byte 0x00000AFE
_08197844: .4byte 0x00000C48
_08197848: .4byte 0x0000044C
_0819784C: .4byte 0x00000CCA
_08197850: .4byte 0x0000016F
_08197854: .4byte 0x00000CEC

	thumb_func_start FUN_08197858
FUN_08197858: @ 0x08197858
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197886
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197888
_08197886:
	movs r0, #0
_08197888:
	cmp r0, #0
	bne _0819788E
	b _0819798E
_0819788E:
	movs r6, #0
	ldr r1, _081979D0 @ =0x00000AC8
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r6, r2
	bge _08197906
	adds r5, r0, #0
_0819789C:
	movs r0, #0x2c
	adds r3, r6, #0
	muls r3, r0, r3
	adds r2, r4, r3
	ldr r1, _081979D4 @ =0x00000AFC
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x7c
	strh r1, [r0]
	ldr r1, _081979D8 @ =0x00000AFE
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x7e
	strh r0, [r1]
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x80
	strh r1, [r0]
	ldr r1, _081979DC @ =0x00000AE6
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x66
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x60
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	bl Div
	lsls r2, r6, #2
	movs r3, #0x87
	lsls r3, r3, #3
	adds r1, r4, r3
	adds r1, r1, r2
	muls r0, r6, r0
	str r0, [r1]
	adds r6, #1
	ldrh r0, [r5]
	cmp r6, r0
	blt _0819789C
_08197906:
	movs r1, #0x8a
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	ldr r2, _081979E0 @ =0x00000449
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0x89
	lsls r3, r3, #3
	adds r2, r4, r3
	movs r0, #5
	strb r0, [r2]
	movs r2, #0xcf
	lsls r2, r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	movs r6, #0
	ldr r3, _081979D0 @ =0x00000AC8
	adds r0, r4, r3
	ldr r1, _081979E4 @ =FUN_08196a64
	mov sb, r1
	ldr r2, _081979E8 @ =FUN_081958b4
	mov sl, r2
	ldrh r3, [r0]
	cmp r6, r3
	bge _0819796E
	ldr r7, _081979EC @ =0x0000FFFB
	movs r1, #0xc3
	lsls r1, r1, #1
	adds r3, r4, r1
	adds r5, r4, #0
	ldr r2, _081979F0 @ =0x000002C6
	mov r8, r2
	mov ip, r0
_0819794C:
	ldrh r1, [r3]
	adds r0, r7, #0
	ands r0, r1
	strh r0, [r3]
	mov r0, r8
	adds r2, r5, r0
	ldrh r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	strh r0, [r2]
	adds r3, #0x50
	adds r5, #0x50
	adds r6, #1
	mov r1, ip
	ldrh r1, [r1]
	cmp r6, r1
	blt _0819794C
_0819796E:
	ldr r2, _081979F4 @ =0x00000C4C
	adds r0, r4, r2
	mov r3, sb
	str r3, [r0]
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	mov r2, sl
	str r2, [r0]
	ldr r3, _081979F8 @ =0x00000CC3
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081979FC @ =0x0000016F
	bl PlaySound_082406e0
_0819798E:
	adds r0, r4, #0
	bl FUN_08196378
	movs r6, #0
	ldr r1, _081979D0 @ =0x00000AC8
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r6, r0
	blt _081979A2
	b _08197A9E
_081979A2:
	movs r2, #0x8a
	lsls r2, r2, #3
	adds r7, r4, r2
	ldr r3, _08197A00 @ =0x085B0A08
	mov r8, r3
	mov sb, r8
	movs r0, #0x87
	lsls r0, r0, #3
	adds r5, r4, r0
_081979B4:
	ldr r0, [r5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _08197A04
	asrs r1, r0, #0xa
	b _08197A0A
	.align 2, 0
_081979D0: .4byte 0x00000AC8
_081979D4: .4byte 0x00000AFC
_081979D8: .4byte 0x00000AFE
_081979DC: .4byte 0x00000AE6
_081979E0: .4byte 0x00000449
_081979E4: .4byte FUN_08196a64
_081979E8: .4byte FUN_081958b4
_081979EC: .4byte 0x0000FFFB
_081979F0: .4byte 0x000002C6
_081979F4: .4byte 0x00000C4C
_081979F8: .4byte 0x00000CC3
_081979FC: .4byte 0x0000016F
_08197A00: .4byte 0x085B0A08
_08197A04:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08197A0A:
	movs r0, #0x2c
	adds r2, r6, #0
	muls r2, r0, r2
	adds r2, r4, r2
	ldr r3, _08197A40 @ =0x00000AFC
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x7c
	strh r0, [r1]
	ldr r1, _08197A44 @ =0x00000AFE
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r2, #0x7e
	strh r0, [r2]
	ldrb r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _08197A48
	asrs r2, r0, #0xa
	b _08197A4E
	.align 2, 0
_08197A40: .4byte 0x00000AFC
_08197A44: .4byte 0x00000AFE
_08197A48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r2, r0, #0
_08197A4E:
	movs r0, #0x2c
	adds r1, r6, #0
	muls r1, r0, r1
	adds r1, r4, r1
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, #0x80
	strh r0, [r1]
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, [r5]
	adds r0, r0, r1
	str r0, [r5]
	cmp r0, #0xff
	ble _08197A90
	movs r2, #0xcf
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0x46
	bls _08197A8A
	ldr r0, _08197AC8 @ =0x00000169
	bl PlaySound_082406e0
_08197A8A:
	ldr r0, [r5]
	subs r0, #0xff
	str r0, [r5]
_08197A90:
	adds r5, #4
	adds r6, #1
	ldr r3, _08197ACC @ =0x00000AC8
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r6, r0
	blt _081979B4
_08197A9E:
	ldr r1, _08197AD0 @ =0x00000C4C
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08197AAE
	adds r0, r4, #0
	bl _call_via_r1
_08197AAE:
	movs r2, #0xcf
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08197AC8: .4byte 0x00000169
_08197ACC: .4byte 0x00000AC8
_08197AD0: .4byte 0x00000C4C

	thumb_func_start FUN_08197ad4
FUN_08197ad4: @ 0x08197AD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197B02
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197B04
_08197B02:
	movs r0, #0
_08197B04:
	cmp r0, #0
	beq _08197BE4
	movs r0, #0xae
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08197C04 @ =0x00000B9A
	adds r2, r4, r1
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _08197C08 @ =0x00000BEA
	adds r2, r4, r0
	ldrh r0, [r2]
	orrs r1, r0
	strh r1, [r2]
	movs r7, #0
	movs r1, #0x60
	adds r1, r1, r4
	mov sl, r1
	ldr r2, _08197C0C @ =0x00000AFC
	adds r2, r2, r4
	mov r8, r2
	ldr r0, _08197C10 @ =0x000002C6
	adds r6, r4, r0
	movs r1, #0xc3
	lsls r1, r1, #1
	adds r5, r4, r1
	movs r2, #4
	mov sb, r2
_08197B48:
	movs r0, #0x2c
	adds r2, r7, #0
	muls r2, r0, r2
	adds r3, r4, r2
	mov r0, r8
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x7c
	strh r1, [r0]
	ldr r1, _08197C14 @ =0x00000AFE
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0x7e
	strh r0, [r1]
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x80
	strh r1, [r0]
	ldr r1, _08197C18 @ =0x00000AE6
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x66
	strb r1, [r0]
	add r2, sl
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrh r0, [r5]
	mov r2, sb
	orrs r0, r2
	strh r0, [r5]
	ldrh r0, [r6]
	orrs r0, r2
	strh r0, [r6]
	mov r0, r8
	bl FUN_082328ec
	movs r2, #0xc7
	lsls r2, r2, #4
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r1]
	adds r6, #0x50
	adds r5, #0x50
	adds r7, #1
	cmp r7, #3
	ble _08197B48
	movs r2, #0
	movs r0, #0
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x20]
	ldr r0, _08197C1C @ =0x0000FFF9
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x28]
	movs r0, #0xc5
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _08197C20 @ =FUN_08196dfc
	str r0, [r1]
	movs r0, #0xc6
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _08197C24 @ =FUN_081958b4
	str r0, [r1]
	ldr r1, _08197C28 @ =0x00000CC3
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _08197C2C @ =0x0000016F
	bl PlaySound_082406e0
_08197BE4:
	movs r2, #0xc5
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08197BF6
	adds r0, r4, #0
	bl _call_via_r1
_08197BF6:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08197C04: .4byte 0x00000B9A
_08197C08: .4byte 0x00000BEA
_08197C0C: .4byte 0x00000AFC
_08197C10: .4byte 0x000002C6
_08197C14: .4byte 0x00000AFE
_08197C18: .4byte 0x00000AE6
_08197C1C: .4byte 0x0000FFF9
_08197C20: .4byte FUN_08196dfc
_08197C24: .4byte FUN_081958b4
_08197C28: .4byte 0x00000CC3
_08197C2C: .4byte 0x0000016F

	thumb_func_start FUN_08197c30
FUN_08197c30: @ 0x08197C30
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197C56
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197C58
_08197C56:
	movs r0, #0
_08197C58:
	cmp r0, #0
	beq _08197CF6
	ldr r1, _08197CA0 @ =0x00000C98
	adds r0, r4, r1
	movs r3, #0
	strh r3, [r0]
	ldr r2, _08197CA4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08197CA8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08197CAC @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r2, _08197CB0 @ =0x00000C9D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08197CB4 @ =0x00000C54
	adds r1, r4, r0
	ldr r0, _08197CB8 @ =FUN_08197244
	str r0, [r1]
	ldr r1, _08197CBC @ =0x00000C9A
	adds r0, r4, r1
	strh r3, [r0]
	adds r2, #0x28
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _08197CD8
	cmp r0, #1
	bgt _08197CC0
	cmp r0, #0
	beq _08197CC6
	b _08197CF0
	.align 2, 0
_08197CA0: .4byte 0x00000C98
_08197CA4: .4byte 0x030046B8
_08197CA8: .4byte 0x000003FF
_08197CAC: .4byte 0x0203B400
_08197CB0: .4byte 0x00000C9D
_08197CB4: .4byte 0x00000C54
_08197CB8: .4byte FUN_08197244
_08197CBC: .4byte 0x00000C9A
_08197CC0:
	cmp r0, #2
	beq _08197CE8
	b _08197CF0
_08197CC6:
	ldr r3, _08197CD0 @ =0x00000C58
	adds r1, r4, r3
	ldr r0, _08197CD4 @ =FUN_08199d48
	b _08197CEE
	.align 2, 0
_08197CD0: .4byte 0x00000C58
_08197CD4: .4byte FUN_08199d48
_08197CD8:
	ldr r0, _08197CE0 @ =0x00000C58
	adds r1, r4, r0
	ldr r0, _08197CE4 @ =FUN_08199cf0
	b _08197CEE
	.align 2, 0
_08197CE0: .4byte 0x00000C58
_08197CE4: .4byte FUN_08199cf0
_08197CE8:
	ldr r2, _08197D3C @ =0x00000C58
	adds r1, r4, r2
	ldr r0, _08197D40 @ =FUN_08199c98
_08197CEE:
	str r0, [r1]
_08197CF0:
	ldr r0, _08197D44 @ =0x0000016F
	bl PlaySound_082406e0
_08197CF6:
	adds r0, r4, #0
	bl FUN_08196378
	ldr r3, _08197D48 @ =0x00000C54
	adds r0, r4, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _08197D0C
	adds r0, r4, #0
	bl _call_via_r1
_08197D0C:
	ldr r0, _08197D4C @ =0x00000C9A
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldr r3, _08197D50 @ =0x0000FFFF
	adds r1, r3, #0
	ands r1, r0
	ldr r3, _08197D54 @ =0x000003FF
	adds r0, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _08197DD8
	strh r1, [r2]
	ldr r1, _08197D58 @ =0x00000CC5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08197D6C
	cmp r0, #1
	bgt _08197D5C
	cmp r0, #0
	beq _08197D62
	b _08197DD8
	.align 2, 0
_08197D3C: .4byte 0x00000C58
_08197D40: .4byte FUN_08199c98
_08197D44: .4byte 0x0000016F
_08197D48: .4byte 0x00000C54
_08197D4C: .4byte 0x00000C9A
_08197D50: .4byte 0x0000FFFF
_08197D54: .4byte 0x000003FF
_08197D58: .4byte 0x00000CC5
_08197D5C:
	cmp r0, #2
	beq _08197D98
	b _08197DD8
_08197D62:
	ldr r2, _08197D68 @ =0x00000C58
	adds r1, r4, r2
	b _08197DD4
	.align 2, 0
_08197D68: .4byte 0x00000C58
_08197D6C:
	ldr r3, _08197D7C @ =0x00000C58
	adds r1, r4, r3
	ldr r2, [r1]
	ldr r3, _08197D80 @ =FUN_08199c98
	cmp r2, r3
	bne _08197D88
	ldr r0, _08197D84 @ =FUN_08199cf0
	b _08197DD6
	.align 2, 0
_08197D7C: .4byte 0x00000C58
_08197D80: .4byte FUN_08199c98
_08197D84: .4byte FUN_08199cf0
_08197D88:
	ldr r0, _08197D94 @ =FUN_08199cf0
	cmp r2, r0
	bne _08197DD8
	str r3, [r1]
	b _08197DD8
	.align 2, 0
_08197D94: .4byte FUN_08199cf0
_08197D98:
	ldr r2, _08197DBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08197DC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08197DC4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08197DD0
	ldr r2, _08197DC8 @ =0x00000C58
	adds r1, r4, r2
	ldr r0, _08197DCC @ =FUN_08199c98
	b _08197DD6
	.align 2, 0
_08197DBC: .4byte 0x030046B8
_08197DC0: .4byte 0x000003FF
_08197DC4: .4byte 0x0203B400
_08197DC8: .4byte 0x00000C58
_08197DCC: .4byte FUN_08199c98
_08197DD0:
	ldr r3, _08197DE0 @ =0x00000C58
	adds r1, r4, r3
_08197DD4:
	ldr r0, _08197DE4 @ =FUN_08199d48
_08197DD6:
	str r0, [r1]
_08197DD8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08197DE0: .4byte 0x00000C58
_08197DE4: .4byte FUN_08199d48

	thumb_func_start FUN_08197de8
FUN_08197de8: @ 0x08197DE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	adds r7, r0, #0
	movs r0, #1
	adds r2, r7, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197E18
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197E1A
_08197E18:
	movs r0, #0
_08197E1A:
	movs r1, #0x58
	adds r1, r1, r7
	mov r8, r1
	cmp r0, #0
	beq _08197F06
	movs r2, #0x60
	adds r2, r2, r7
	mov sl, r2
	adds r3, r7, #0
	adds r3, #0x59
	str r3, [sp, #0x34]
	adds r0, r7, #0
	adds r0, #0x5c
	str r0, [sp, #0x38]
	movs r1, #1
	mov ip, r1
	movs r2, #5
	mov sb, r2
	ldr r3, _08197F9C @ =0x00000565
	adds r2, r7, r3
	ldr r0, _08197FA0 @ =0x0000053C
	adds r3, r7, r0
	movs r6, #0
	movs r5, #0xc6
	lsls r5, r5, #1
	movs r4, #3
_08197E4E:
	adds r0, r6, r7
	ldr r1, _08197FA4 @ =0x0000056A
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08197E6E
	mov r0, ip
	strb r0, [r2, #5]
	mov r1, sb
	strb r1, [r2, #6]
	ldrb r0, [r2]
	mov r1, ip
	orrs r1, r0
	strb r1, [r2]
	ldr r0, _08197FA8 @ =FUN_08199da0
	str r0, [r3, #0x74]
_08197E6E:
	adds r2, r2, r5
	adds r3, r3, r5
	adds r6, r6, r5
	subs r4, #1
	cmp r4, #0
	bge _08197E4E
	movs r4, #0
	movs r6, #1
	movs r5, #4
	adds r3, r7, #0
_08197E82:
	movs r0, #0x2c
	muls r0, r4, r0
	mov r1, sl
	adds r2, r1, r0
	ldr r1, [r2]
	adds r0, r1, #0
	ands r0, r6
	cmp r0, #0
	bne _08197EAE
	orrs r1, r6
	str r1, [r2]
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r3, r2
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	ldr r0, _08197FAC @ =0x000002C6
	adds r1, r3, r0
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
_08197EAE:
	adds r3, #0x50
	adds r4, #1
	cmp r4, #3
	ble _08197E82
	ldr r2, _08197FB0 @ =0x00000B9A
	adds r1, r7, r2
	ldrh r0, [r1]
	movs r2, #4
	movs r3, #0
	movs r4, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r0, _08197FB4 @ =0x00000BEA
	adds r1, r7, r0
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldr r1, _08197FB8 @ =0x00000C9E
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _08197FBC @ =0x00000CCF
	adds r0, r7, r2
	strb r3, [r0]
	mov r0, r8
	strb r3, [r0]
	movs r0, #0x1e
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	ldr r2, [sp, #0x38]
	ldrh r0, [r2]
	bl FUN_0807a798
	movs r3, #0xcd
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	movs r2, #0x3e
	ldrsh r1, [r7, r2]
	bl FUN_0807a840
	ldr r3, _08197FC0 @ =0x00000CC4
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
_08197F06:
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08197F18
	adds r0, r7, #0
	bl _call_via_r1
_08197F18:
	ldr r2, _08197FB8 @ =0x00000C9E
	adds r0, r7, r2
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	beq _08197F2C
	b _08198218
_08197F2C:
	movs r0, #0xae
	lsls r0, r0, #4
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r1, r8
	strb r3, [r1]
	adds r6, r7, #0
	adds r6, #0x59
	ldrb r0, [r6]
	subs r0, #1
	strb r0, [r6]
	ldr r2, _08197FC4 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _08197FC8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [r4, #4]
	ldr r2, _08197FCC @ =0x00000AFC
	adds r0, r7, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	add r5, sp, #0x1c
	str r3, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08197FD0 @ =0x05000002
	bl CpuSet
	ldr r3, _08197FBC @ =0x00000CCF
	adds r0, r7, r3
	ldrb r0, [r0]
	str r6, [sp, #0x34]
	mov sb, r4
	cmp r0, #4
	bhi _08198068
	lsls r0, r0, #2
	ldr r1, _08197FD4 @ =_08197FD8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08197F9C: .4byte 0x00000565
_08197FA0: .4byte 0x0000053C
_08197FA4: .4byte 0x0000056A
_08197FA8: .4byte FUN_08199da0
_08197FAC: .4byte 0x000002C6
_08197FB0: .4byte 0x00000B9A
_08197FB4: .4byte 0x00000BEA
_08197FB8: .4byte 0x00000C9E
_08197FBC: .4byte 0x00000CCF
_08197FC0: .4byte 0x00000CC4
_08197FC4: .4byte 0xFFFF0000
_08197FC8: .4byte 0x0000FFFF
_08197FCC: .4byte 0x00000AFC
_08197FD0: .4byte 0x05000002
_08197FD4: .4byte _08197FD8
_08197FD8: @ jump table
	.4byte _08197FEC @ case 0
	.4byte _08198010 @ case 1
	.4byte _08198028 @ case 2
	.4byte _08198040 @ case 3
	.4byte _08198058 @ case 4
_08197FEC:
	ldr r1, _08198008 @ =0x0000FF88
	strh r1, [r5]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r0, _0819800C @ =0x00000CCF
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xb7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08198068
	.align 2, 0
_08198008: .4byte 0x0000FF88
_0819800C: .4byte 0x00000CCF
_08198010:
	ldr r1, _08198020 @ =0x0000FFB5
	strh r1, [r5]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r2, _08198024 @ =0x00000CCF
	adds r1, r7, r2
	b _0819804C
	.align 2, 0
_08198020: .4byte 0x0000FFB5
_08198024: .4byte 0x00000CCF
_08198028:
	ldr r1, _08198038 @ =0x0000FFE2
	strh r1, [r5]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r3, _0819803C @ =0x00000CCF
	adds r1, r7, r3
	b _0819804C
	.align 2, 0
_08198038: .4byte 0x0000FFE2
_0819803C: .4byte 0x00000CCF
_08198040:
	movs r1, #0xf
	strh r1, [r5]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r0, _08198054 @ =0x00000CCF
	adds r1, r7, r0
_0819804C:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08198068
	.align 2, 0
_08198054: .4byte 0x00000CCF
_08198058:
	movs r2, #0
	movs r1, #0x3c
	strh r1, [r5]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r1, _08198090 @ =0x00000CCF
	adds r0, r7, r1
	strb r2, [r0]
_08198068:
	movs r2, #0
	ldrsh r3, [r5, r2]
	ldr r2, _08198094 @ =0x085B0A08
	ldr r1, _08198098 @ =0x00000AE6
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _0819809C
	asrs r0, r0, #0xc
	b _081980A2
	.align 2, 0
_08198090: .4byte 0x00000CCF
_08198094: .4byte 0x085B0A08
_08198098: .4byte 0x00000AE6
_0819809C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081980A2:
	adds r2, r0, #0
	movs r3, #4
	ldrsh r1, [r5, r3]
	ldr r3, _081980C0 @ =0x00000AE6
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _081980C4
	asrs r0, r0, #0xc
	b _081980CA
	.align 2, 0
_081980C0: .4byte 0x00000AE6
_081980C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081980CA:
	add r3, sp, #0x24
	adds r1, r2, r0
	ldrh r0, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08198100 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	movs r2, #0
	ldrsh r1, [r5, r2]
	ldr r2, _08198104 @ =0x00000AE6
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08198108
	asrs r0, r0, #0xc
	b _0819810C
	.align 2, 0
_08198100: .4byte 0xFFFF0000
_08198104: .4byte 0x00000AE6
_08198108:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_0819810C:
	adds r4, r0, #0
	movs r0, #4
	ldrsh r2, [r5, r0]
	ldr r1, _08198130 @ =0x00000AE6
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _08198134
	asrs r0, r0, #0xc
	b _0819813A
	.align 2, 0
_08198130: .4byte 0x00000AE6
_08198134:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819813A:
	adds r1, r4, r0
	ldrh r2, [r3, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _081981E0 @ =0xFFFF0000
	mov r8, r0
	ldr r0, [r3, #4]
	mov r2, r8
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	movs r4, #2
	str r4, [sp, #8]
	movs r5, #1
	str r5, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #2
	mov r2, sb
	movs r3, #0
	bl FUN_080ddcc8
	ldr r3, [sp, #0x34]
	ldrb r6, [r3]
	cmp r6, #0
	bne _08198230
	ldr r1, _081981E4 @ =0x00000B28
	adds r0, r7, r1
	bl FUN_080139a0
	adds r0, r7, #0
	adds r0, #0x4a
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r2, r7, #0
	adds r2, #0x45
	ldrb r1, [r2]
	adds r0, r5, #0
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r7, #0x18]
	ldr r0, [r0, #0x1c]
	cmp r0, #4
	beq _08198230
	ldr r2, _081981E8 @ =0x00000CD8
	adds r0, r7, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _08198230
	ldr r0, [sp, #0x2c]
	mov r3, r8
	ands r0, r3
	orrs r0, r4
	str r0, [sp, #0x2c]
	ldr r1, _081981EC @ =0x00000CDC
	adds r0, r7, r1
	add r1, sp, #0x2c
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
	ldr r2, _081981F0 @ =0x00000CC5
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r0, #0xc
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081981F8
	ldr r0, _081981F4 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r5, #0
	lsls r1, r3
	b _0819820A
	.align 2, 0
_081981E0: .4byte 0xFFFF0000
_081981E4: .4byte 0x00000B28
_081981E8: .4byte 0x00000CD8
_081981EC: .4byte 0x00000CDC
_081981F0: .4byte 0x00000CC5
_081981F4: .4byte 0x030046A0
_081981F8:
	ldr r0, _08198214 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r5, #0
	lsls r1, r0
_0819820A:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _08198230
	.align 2, 0
_08198214: .4byte 0x030046A0
_08198218:
	movs r3, #0xae
	lsls r3, r3, #4
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08198230:
	ldr r2, _0819824C @ =0x00000C9E
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819824C: .4byte 0x00000C9E

	thumb_func_start FUN_08198250
FUN_08198250: @ 0x08198250
	bx lr
	.align 2, 0

	thumb_func_start FUN_08198254
FUN_08198254: @ 0x08198254
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081982A4 @ =0x00000C5C
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08198268
	adds r0, r4, #0
	bl _call_via_r1
_08198268:
	ldr r0, _081982A8 @ =0x00000C28
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08198276
	subs r0, #1
	strh r0, [r1]
_08198276:
	ldr r1, _081982AC @ =0x00000C38
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0819829E
	adds r0, r4, #0
	bl _call_via_r1
	movs r1, #0xc4
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08198298
	adds r0, r4, #0
	bl _call_via_r1
_08198298:
	adds r0, r4, #0
	bl FUN_081963c0
_0819829E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081982A4: .4byte 0x00000C5C
_081982A8: .4byte 0x00000C28
_081982AC: .4byte 0x00000C38

	thumb_func_start FUN_081982b0
FUN_081982b0: @ 0x081982B0
	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	adds r0, #0x45
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081982D4
	ldr r0, _081982D8 @ =0x085ADDA8
	adds r1, r2, #0
	adds r1, #0x4a
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	bl _call_via_r1
_081982D4:
	pop {r0}
	bx r0
	.align 2, 0
_081982D8: .4byte 0x085ADDA8

	thumb_func_start FUN_081982dc
FUN_081982dc: @ 0x081982DC
	bx lr
	.align 2, 0

	thumb_func_start FUN_081982e0
FUN_081982e0: @ 0x081982E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	movs r2, #0x81
	lsls r2, r2, #1
	adds r4, r5, r2
	movs r3, #0
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bgt _08198308
	b _0819857C
_08198308:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _08198316
	b _0819857C
_08198316:
	adds r0, r5, #0
	adds r0, #0xdc
	ldrh r0, [r0]
	cmp r0, #0
	beq _08198322
	b _0819857C
_08198322:
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08236524
	adds r0, r6, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r2]
	cmp r0, #0
	bne _081983BC
	ldrh r0, [r7, #0x3e]
	cmp r0, #0
	beq _081983BC
	movs r3, #0x90
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #8
	strh r0, [r1]
	ldr r0, _081983A8 @ =FUN_081999f4
	str r0, [r2]
	ldr r0, [r5, #0xc]
	ldr r1, _081983AC @ =0x00000CC8
	add r1, r8
	ldrh r1, [r1]
	bl FUN_0822b20c
	ldrh r1, [r4]
	ldrh r0, [r7, #0x3e]
	subs r1, r1, r0
	strh r1, [r4]
	ldr r0, _081983B0 @ =0x00000C8A
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r3, [r6, #0x3e]
	adds r0, r0, r3
	strh r0, [r6, #0x3e]
	lsls r1, r1, #0x10
	cmp r1, #0
	bgt _081983BC
	movs r0, #1
	movs r1, #5
	movs r3, #0x8b
	lsls r3, r3, #1
	adds r2, r5, r3
	strb r0, [r2]
	adds r3, #1
	adds r2, r5, r3
	strb r1, [r2]
	ldr r1, _081983B4 @ =0x00000111
	adds r2, r5, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, _081983B8 @ =FUN_08199da0
	str r0, [r1]
	b _0819856A
	.align 2, 0
_081983A8: .4byte FUN_081999f4
_081983AC: .4byte 0x00000CC8
_081983B0: .4byte 0x00000C8A
_081983B4: .4byte 0x00000111
_081983B8: .4byte FUN_08199da0
_081983BC:
	ldr r3, _08198430 @ =0x00000117
	adds r0, r5, r3
	ldrb r2, [r0]
	adds r4, r0, #0
	cmp r2, #2
	bne _081983D6
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _08198434 @ =FUN_08198d0c
	cmp r1, r0
	bne _08198410
_081983D6:
	cmp r2, #3
	bne _081983EE
	movs r3, #0xb8
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	ldr r0, _08198438 @ =FUN_08199064
	cmp r1, r0
	beq _08198410
	ldr r0, _0819843C @ =FUN_08199094
	cmp r1, r0
	beq _08198410
_081983EE:
	cmp r2, #4
	beq _081983F4
	b _08198564
_081983F4:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _08198440 @ =FUN_081994e8
	cmp r1, r0
	beq _08198410
	ldr r0, _08198444 @ =FUN_08199568
	cmp r1, r0
	beq _08198410
	ldr r0, _08198448 @ =FUN_081996f0
	cmp r1, r0
	beq _08198410
	b _08198564
_08198410:
	adds r0, r5, #0
	bl FUN_08199a3c
	ldrb r0, [r4]
	cmp r0, #2
	bne _0819844C
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0x80
	str r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, _08198434 @ =FUN_08198d0c
	b _0819847E
	.align 2, 0
_08198430: .4byte 0x00000117
_08198434: .4byte FUN_08198d0c
_08198438: .4byte FUN_08199064
_0819843C: .4byte FUN_08199094
_08198440: .4byte FUN_081994e8
_08198444: .4byte FUN_08199568
_08198448: .4byte FUN_081996f0
_0819844C:
	cmp r0, #3
	bne _08198468
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x14
	str r0, [r1]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, _08198464 @ =FUN_0819926c
	b _0819847E
	.align 2, 0
_08198464: .4byte FUN_0819926c
_08198468:
	cmp r0, #4
	bne _08198480
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #0x64
	str r0, [r1]
	movs r0, #0xba
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _0819849C @ =FUN_08199824
_0819847E:
	str r0, [r1]
_08198480:
	ldrh r1, [r6, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081984A0
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r0, [r0]
	movs r2, #0x89
	lsls r2, r2, #1
	adds r1, r5, r2
	b _08198512
	.align 2, 0
_0819849C: .4byte FUN_08199824
_081984A0:
	mov r4, sp
	adds r3, r7, #0
	adds r3, #0xc
	adds r2, r6, #0
	adds r2, #0xc
	ldrh r0, [r6, #0xc]
	ldrh r1, [r7, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _081984FC
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081984FC
	ldr r2, _081984F0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081984F4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081984F8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0x89
	lsls r2, r2, #1
	adds r1, r5, r2
	b _08198512
	.align 2, 0
_081984F0: .4byte 0x030046B8
_081984F4: .4byte 0x000003FF
_081984F8: .4byte 0x0203B400
_081984FC:
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	movs r3, #0x89
	lsls r3, r3, #1
	adds r1, r5, r3
_08198512:
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0xa2
	movs r0, #1
	strh r0, [r1]
	subs r1, #0x50
	strh r0, [r1]
	ldrh r0, [r6, #0x22]
	adds r1, #0x18
	strh r0, [r1]
	ldr r2, _08198560 @ =0x085B0A08
	movs r0, #0x89
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	adds r1, r5, #0
	adds r1, #0xf8
	strh r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	adds r1, #4
	strh r0, [r1]
	movs r0, #0xb8
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0819857C
	.align 2, 0
_08198560: .4byte 0x085B0A08
_08198564:
	ldrh r0, [r7, #0x3e]
	cmp r0, #0
	beq _08198574
_0819856A:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0819857C
_08198574:
	movs r0, #0xc8
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0819857C:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08198588
FUN_08198588: @ 0x08198588
	push {r4, lr}
	adds r2, r0, #0
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r3, r2, r0
	ldr r0, [r3]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _081985AC
	adds r1, r2, #0
	adds r1, #0xea
	adds r0, r2, #0
	adds r0, #0xf2
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_081985AC:
	ldr r0, [r3]
	subs r0, #1
	str r0, [r3]
	cmp r0, #0
	bne _081985C4
	adds r1, r2, #0
	adds r1, #0xf2
	ldrh r0, [r1]
	rsbs r0, r0, #0
	strh r0, [r1]
	movs r0, #0x28
	str r0, [r3]
_081985C4:
	adds r0, r2, #0
	adds r0, #0xea
	ldrh r0, [r0]
	ldrh r1, [r2, #0x1e]
	adds r0, r0, r1
	strh r0, [r2, #0x1e]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081985d8
FUN_081985d8: @ 0x081985D8
	push {lr}
	adds r1, r0, #0
	movs r0, #0x80
	strb r0, [r1, #6]
	movs r0, #0x7f
	strb r0, [r1, #8]
	movs r0, #1
	strb r0, [r1, #9]
	movs r0, #0xc3
	lsls r0, r0, #1
	adds r2, r1, r0
	movs r0, #0xf8
	strb r0, [r2]
	adds r0, #0x8f
	adds r2, r1, r0
	movs r0, #0x10
	strb r0, [r2]
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, _08198610 @ =FUN_08198618
	str r0, [r1]
	ldr r0, _08198614 @ =0x0000016D
	bl PlaySound_082406e0
	pop {r0}
	bx r0
	.align 2, 0
_08198610: .4byte FUN_08198618
_08198614: .4byte 0x0000016D

	thumb_func_start FUN_08198618
FUN_08198618: @ 0x08198618
	push {r4, lr}
	adds r2, r0, #0
	movs r3, #8
	ldrsb r3, [r2, r3]
	movs r1, #9
	ldrsb r1, [r2, r1]
	cmp r3, #0x40
	ble _0819863C
	movs r4, #0xc3
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r3, r3, r0
	cmp r3, #0x3f
	bgt _0819863C
	movs r3, #0x40
_0819863C:
	cmp r1, #0x7e
	bgt _08198652
	ldr r4, _08198678 @ =0x00000187
	adds r0, r2, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	cmp r1, #0x7f
	ble _08198652
	movs r1, #0x7f
_08198652:
	strb r3, [r2, #8]
	strb r1, [r2, #9]
	cmp r1, #0x7f
	bne _08198670
	movs r0, #0x40
	strb r0, [r2, #8]
	ldr r0, _08198678 @ =0x00000187
	adds r1, r2, r0
	movs r0, #0xf0
	strb r0, [r1]
	movs r4, #0xb2
	lsls r4, r4, #1
	adds r1, r2, r4
	ldr r0, _0819867C @ =FUN_08198680
	str r0, [r1]
_08198670:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08198678: .4byte 0x00000187
_0819867C: .4byte FUN_08198680

	thumb_func_start FUN_08198680
FUN_08198680: @ 0x08198680
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #9
	ldrsb r1, [r3, r1]
	cmp r1, #0x40
	ble _0819869E
	ldr r2, _08198704 @ =0x00000187
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r1, r1, r0
	cmp r1, #0x3f
	bgt _0819869E
	movs r1, #0x40
_0819869E:
	strb r1, [r3, #9]
	cmp r1, #0x40
	bne _081986FE
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, _08198708 @ =FUN_081985d8
	str r0, [r1]
	ldr r2, _0819870C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08198710 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08198714 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r4, #1
	ands r0, r4
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	cmp r0, #0
	beq _081986D2
	movs r1, #1
_081986D2:
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	movs r1, #0x8b
	lsls r1, r1, #1
	adds r0, r3, r1
	strb r4, [r0]
	subs r2, #0x6b
	adds r0, r3, r2
	strb r4, [r0]
	ldr r0, _08198718 @ =0x00000111
	adds r2, r3, r0
	ldrb r1, [r2]
	adds r0, r4, #0
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r0, _0819871C @ =FUN_08199c38
	str r0, [r1]
_081986FE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08198704: .4byte 0x00000187
_08198708: .4byte FUN_081985d8
_0819870C: .4byte 0x030046B8
_08198710: .4byte 0x000003FF
_08198714: .4byte 0x0203B400
_08198718: .4byte 0x00000111
_0819871C: .4byte FUN_08199c38

	thumb_func_start FUN_08198720
FUN_08198720: @ 0x08198720
	adds r3, r0, #0
	ldr r2, _08198750 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08198754 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08198758 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r3, r1
	movs r1, #0x40
	ands r0, r1
	adds r0, #0x1e
	str r0, [r2]
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, _0819875C @ =FUN_08198760
	str r0, [r1]
	bx lr
	.align 2, 0
_08198750: .4byte 0x030046B8
_08198754: .4byte 0x000003FF
_08198758: .4byte 0x0203B400
_0819875C: .4byte FUN_08198760

	thumb_func_start FUN_08198760
FUN_08198760: @ 0x08198760
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	ldr r2, _081987FC @ =0x00000181
	adds r2, r2, r7
	mov r8, r2
	movs r4, #0xc1
	lsls r4, r4, #1
	adds r0, r7, r4
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r0, r1
	movs r2, #0
	mov sl, r2
	mov r4, r8
	strb r0, [r4]
	ldr r0, _08198800 @ =0x085B0A08
	mov sb, r0
	ldrb r0, [r4]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r4, #0xc8
	muls r0, r4, r0
	movs r5, #0x80
	lsls r5, r5, #5
	adds r1, r5, #0
	bl Div
	ldr r2, _08198804 @ =0x00000AFC
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r1, r5, #0
	bl Div
	movs r4, #0xb0
	lsls r4, r4, #4
	adds r1, r6, r4
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r7, #0x20]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _0819884A
	ldr r1, _08198808 @ =0x00000C58
	adds r0, r6, r1
	ldr r3, [r0]
	ldr r0, _0819880C @ =FUN_08199c98
	cmp r3, r0
	bne _08198810
	movs r0, #1
	movs r1, #2
	b _0819882A
	.align 2, 0
_081987FC: .4byte 0x00000181
_08198800: .4byte 0x085B0A08
_08198804: .4byte 0x00000AFC
_08198808: .4byte 0x00000C58
_0819880C: .4byte FUN_08199c98
_08198810:
	ldr r0, _0819881C @ =FUN_08199cf0
	cmp r3, r0
	bne _08198820
	movs r0, #1
	movs r1, #3
	b _0819882A
	.align 2, 0
_0819881C: .4byte FUN_08199cf0
_08198820:
	ldr r0, _08198858 @ =FUN_08199d48
	cmp r3, r0
	bne _0819884A
	movs r0, #1
	movs r1, #4
_0819882A:
	movs r4, #0x8b
	lsls r4, r4, #1
	adds r2, r7, r4
	strb r0, [r2]
	adds r4, #1
	adds r2, r7, r4
	strb r1, [r2]
	ldr r1, _0819885C @ =0x00000111
	adds r2, r7, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r7, r2
	str r3, [r0]
_0819884A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08198858: .4byte FUN_08199d48
_0819885C: .4byte 0x00000111

	thumb_func_start FUN_08198860
FUN_08198860: @ 0x08198860
	adds r2, r0, #0
	ldr r0, _08198890 @ =0x00000185
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r1, r2, r3
	ldr r0, _08198894 @ =FUN_08198898
	str r0, [r1]
	ldrh r1, [r2, #0x1c]
	subs r3, #0x38
	adds r0, r2, r3
	strh r1, [r0]
	ldrh r0, [r2, #0x1e]
	adds r3, #2
	adds r1, r2, r3
	strh r0, [r1]
	ldrh r1, [r2, #0x20]
	adds r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	bx lr
	.align 2, 0
_08198890: .4byte 0x00000185
_08198894: .4byte FUN_08198898

	thumb_func_start FUN_08198898
FUN_08198898: @ 0x08198898
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, ip
	ldr r2, [r0]
	ldr r1, _081989A0 @ =0x00000CEC
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _081988BC
	ldr r1, _081989A4 @ =0x00000185
	add r1, ip
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_081988BC:
	ldr r1, _081989A4 @ =0x00000185
	add r1, ip
	ldrb r0, [r1]
	mov r3, ip
	ldrb r3, [r3, #6]
	adds r0, r0, r3
	mov r4, ip
	strb r0, [r4, #6]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _081988D6
	rsbs r0, r0, #0
_081988D6:
	cmp r0, #9
	ble _081989C2
	mov r1, ip
	ldrh r0, [r1, #0x1c]
	movs r3, #0x9a
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	ldrh r0, [r1, #0x1e]
	movs r6, #0x9b
	lsls r6, r6, #1
	add r6, ip
	strh r0, [r6]
	ldrh r0, [r1, #0x20]
	movs r4, #0x9c
	lsls r4, r4, #1
	add r4, ip
	strh r0, [r4]
	ldr r0, [r2, #0x18]
	ldrh r0, [r0, #0x2c]
	movs r1, #0x96
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	ldr r0, [r2, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r0, #0xdc
	movs r5, #0x97
	lsls r5, r5, #1
	add r5, ip
	strh r0, [r5]
	ldr r0, [r2, #0x18]
	ldrh r0, [r0, #0x30]
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	ldrh r0, [r1]
	ldrh r1, [r3]
	subs r0, r0, r1
	movs r7, #0x9e
	lsls r7, r7, #1
	add r7, ip
	strh r0, [r7]
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r0, r1
	movs r3, #0x9f
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	ldrh r0, [r2]
	ldrh r1, [r4]
	subs r0, r0, r1
	movs r3, #0xa0
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	movs r1, #0xbe
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0
	str r0, [r1]
	ldr r2, _081989A8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081989AC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081989B0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08198976
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
_08198976:
	movs r0, #0xc1
	lsls r0, r0, #1
	add r0, ip
	strb r1, [r0]
	movs r0, #0
	ldrsh r1, [r7, r0]
	cmp r1, #0
	bge _08198988
	rsbs r1, r1, #0
_08198988:
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bge _08198992
	rsbs r0, r0, #0
_08198992:
	cmp r1, r0
	bge _081989B8
	movs r1, #0xb6
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _081989B4 @ =FUN_081989cc
	b _081989C0
	.align 2, 0
_081989A0: .4byte 0x00000CEC
_081989A4: .4byte 0x00000185
_081989A8: .4byte 0x030046B8
_081989AC: .4byte 0x000003FF
_081989B0: .4byte 0x0203B400
_081989B4: .4byte FUN_081989cc
_081989B8:
	movs r1, #0xb6
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _081989C8 @ =FUN_08198a88
_081989C0:
	str r0, [r1]
_081989C2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081989C8: .4byte FUN_08198a88

	thumb_func_start FUN_081989cc
FUN_081989cc: @ 0x081989CC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08198A7C @ =0x00000185
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r2, [r6, #6]
	adds r0, r0, r2
	strb r0, [r6, #6]
	ldr r1, _08198A80 @ =0x085B0A08
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r4, r6, r3
	ldr r2, [r4]
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	adds r3, #6
	adds r1, r6, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r5, r0, #0
	muls r5, r1, r5
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	adds r1, r1, r5
	strh r1, [r6, #0x1c]
	movs r3, #0x9f
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r3, #0x9b
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x1e]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x20]
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	cmp r0, #0x80
	ble _08198A74
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08198A84 @ =FUN_08198b44
	str r0, [r1]
_08198A74:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08198A7C: .4byte 0x00000185
_08198A80: .4byte 0x085B0A08
_08198A84: .4byte FUN_08198b44

	thumb_func_start FUN_08198a88
FUN_08198a88: @ 0x08198A88
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08198B38 @ =0x00000185
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r2, [r6, #6]
	adds r0, r0, r2
	strb r0, [r6, #6]
	ldr r1, _08198B3C @ =0x085B0A08
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r4, r6, r3
	ldr r2, [r4]
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	adds r3, #6
	adds r1, r6, r3
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r5, r0, #0
	muls r5, r1, r5
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x1c]
	movs r3, #0x9f
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r3, #0x9b
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x1e]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r1, [r1]
	adds r1, r1, r0
	adds r1, r1, r5
	strh r1, [r6, #0x20]
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	cmp r0, #0x80
	ble _08198B30
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08198B40 @ =FUN_08198c28
	str r0, [r1]
_08198B30:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08198B38: .4byte 0x00000185
_08198B3C: .4byte 0x085B0A08
_08198B40: .4byte FUN_08198c28

	thumb_func_start FUN_08198b44
FUN_08198b44: @ 0x08198B44
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08198C18 @ =0x00000185
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r2, [r6, #6]
	adds r0, r0, r2
	strb r0, [r6, #6]
	ldr r2, _08198C1C @ =0x085B0A08
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r3, [r4]
	subs r0, #0x7c
	subs r0, r0, r3
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r5, r0, #0
	muls r5, r1, r5
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	adds r1, r1, r5
	strh r1, [r6, #0x1c]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x1e]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x20]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	cmp r0, #0
	bne _08198C10
	movs r0, #0x80
	strb r0, [r6, #6]
	movs r0, #1
	subs r2, #0x22
	adds r1, r6, r2
	strb r0, [r1]
	adds r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	ldr r1, _08198C20 @ =0x00000111
	adds r2, r6, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r0, _08198C24 @ =FUN_08199c38
	str r0, [r1]
_08198C10:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08198C18: .4byte 0x00000185
_08198C1C: .4byte 0x085B0A08
_08198C20: .4byte 0x00000111
_08198C24: .4byte FUN_08199c38

	thumb_func_start FUN_08198c28
FUN_08198c28: @ 0x08198C28
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _08198CFC @ =0x00000185
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r2, [r6, #6]
	adds r0, r0, r2
	strb r0, [r6, #6]
	ldr r2, _08198D00 @ =0x085B0A08
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r6, r0
	ldr r3, [r4]
	subs r0, #0x7c
	subs r0, r0, r3
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r5, r0, #0
	muls r5, r1, r5
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x1c]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x1e]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x80
	bl Div
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	adds r1, r1, r5
	strh r1, [r6, #0x20]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	cmp r0, #0
	bne _08198CF4
	movs r0, #0x80
	strb r0, [r6, #6]
	movs r0, #1
	subs r2, #0x22
	adds r1, r6, r2
	strb r0, [r1]
	adds r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	ldr r1, _08198D04 @ =0x00000111
	adds r2, r6, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r0, _08198D08 @ =FUN_08199c38
	str r0, [r1]
_08198CF4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08198CFC: .4byte 0x00000185
_08198D00: .4byte 0x085B0A08
_08198D04: .4byte 0x00000111
_08198D08: .4byte FUN_08199c38

	thumb_func_start FUN_08198d0c
FUN_08198d0c: @ 0x08198D0C
	push {r4, r5, lr}
	mov ip, r0
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	mov r2, ip
	ldrb r0, [r2, #6]
	adds r0, #0x14
	strb r0, [r2, #6]
	adds r2, #0xf8
	ldrh r0, [r2]
	mov r3, ip
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r4, ip
	strh r0, [r4, #0x1c]
	mov r3, ip
	adds r3, #0xfc
	ldrh r0, [r3]
	ldrh r5, [r4, #0x20]
	adds r0, r0, r5
	strh r0, [r4, #0x20]
	ldr r0, _08198DF8 @ =0x00000CEC
	adds r1, r1, r0
	ldr r0, [r1]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08198D4A
	b _08198E46
_08198D4A:
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne _08198E0E
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bne _08198E0E
	mov r1, ip
	adds r1, #0xa2
	movs r0, #0x10
	strh r0, [r1]
	subs r1, #0x50
	strh r0, [r1]
	ldrh r0, [r4, #0x1c]
	movs r2, #0x96
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	ldrh r0, [r4, #0x1e]
	movs r4, #0x97
	lsls r4, r4, #1
	add r4, ip
	strh r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0x20]
	movs r3, #0x98
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	movs r1, #0x9a
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r2, #0x9e
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	movs r1, #0x9b
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r4]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x9f
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	movs r1, #0x9c
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r3, #0xa0
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	movs r1, #0xc1
	lsls r1, r1, #1
	add r1, ip
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r1, _08198DFC @ =0x00000185
	add r1, ip
	movs r0, #0xf6
	strb r0, [r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	cmp r1, #0
	bge _08198DE0
	rsbs r1, r1, #0
_08198DE0:
	movs r5, #0
	ldrsh r0, [r3, r5]
	cmp r0, #0
	bge _08198DEA
	rsbs r0, r0, #0
_08198DEA:
	cmp r1, r0
	bge _08198E04
	movs r1, #0xb6
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _08198E00 @ =FUN_08198b44
	b _08198E0C
	.align 2, 0
_08198DF8: .4byte 0x00000CEC
_08198DFC: .4byte 0x00000185
_08198E00: .4byte FUN_08198b44
_08198E04:
	movs r1, #0xb6
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _08198E20 @ =FUN_08198c28
_08198E0C:
	str r0, [r1]
_08198E0E:
	mov r0, ip
	adds r0, #0xf8
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r2, r0, #0
	cmp r1, #0
	blt _08198E24
	asrs r0, r1, #1
	b _08198E2A
	.align 2, 0
_08198E20: .4byte FUN_08198c28
_08198E24:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08198E2A:
	strh r0, [r2]
	mov r0, ip
	adds r0, #0xfc
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r2, r0, #0
	cmp r1, #0
	blt _08198E3E
	asrs r0, r1, #1
	b _08198E44
_08198E3E:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08198E44:
	strh r0, [r2]
_08198E46:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08198e4c
FUN_08198e4c: @ 0x08198E4C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r2, [r0, #0x18]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	movs r3, #0x1c
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #0x20
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	movs r1, #0x89
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sl, r1
	strb r0, [r1]
	movs r1, #0xa0
	subs r1, r1, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	ldr r2, _08198FA0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08198FA4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08198FA8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r2, #1
	ands r0, r2
	movs r3, #1
	rsbs r3, r3, #0
	adds r1, r3, #0
	cmp r0, #0
	beq _08198EB8
	movs r1, #1
_08198EB8:
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _08198FAC @ =0x00000183
	adds r0, r7, r1
	strb r2, [r0]
	ldrh r0, [r7, #0x1c]
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	strh r0, [r2]
	ldrh r0, [r7, #0x1e]
	subs r3, #0x4c
	adds r6, r7, r3
	strh r0, [r6]
	ldrh r0, [r7, #0x20]
	subs r1, #0x4b
	adds r1, r7, r1
	str r1, [sp, #4]
	strh r0, [r1]
	mov r2, sl
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _08198FB0 @ =0x085B0A08
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r4, #0x80
	lsls r4, r4, #5
	adds r1, r4, #0
	bl Div
	ldrh r1, [r7, #0x1c]
	adds r1, r1, r0
	movs r3, #0x96
	lsls r3, r3, #1
	adds r5, r7, r3
	strh r1, [r5]
	ldr r1, [sp]
	ldr r0, [r1, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r0, #0xdc
	movs r2, #0x97
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	strh r0, [r2]
	mov r3, sl
	ldrb r0, [r3]
	lsls r0, r0, #1
	ldr r1, _08198FB0 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r4, #0
	bl Div
	ldrh r1, [r7, #0x20]
	adds r1, r1, r0
	movs r3, #0x98
	lsls r3, r3, #1
	adds r2, r7, r3
	strh r1, [r2]
	ldrh r0, [r5]
	mov r3, r8
	ldrh r1, [r3]
	subs r0, r0, r1
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	mov r1, sb
	ldrh r0, [r1]
	ldrh r1, [r6]
	subs r0, r0, r1
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r0, [r3]
	ldrh r0, [r2]
	ldr r2, [sp, #4]
	ldrh r1, [r2]
	subs r0, r0, r1
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _08198FB4 @ =FUN_08198fb8
	str r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08198FA0: .4byte 0x030046B8
_08198FA4: .4byte 0x000003FF
_08198FA8: .4byte 0x0203B400
_08198FAC: .4byte 0x00000183
_08198FB0: .4byte 0x085B0A08
_08198FB4: .4byte FUN_08198fb8

	thumb_func_start FUN_08198fb8
FUN_08198fb8: @ 0x08198FB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r1, r0, #0
	movs r2, #0xac
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	mov sb, r0
	movs r2, #0
	ldr r7, _08199018 @ =0x00000183
	adds r3, r1, r7
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r2, r0
	bge _0819902A
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r0, r0, r1
	mov ip, r0
	subs r7, #3
	adds r6, r1, r7
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r5, r1, r0
	subs r7, #0x10
	adds r4, r1, r7
	movs r0, #0x1e
	mov sl, r0
	ldr r7, _0819901C @ =FUN_08199064
	mov r8, r7
_08198FFA:
	mov r7, ip
	ldrb r0, [r7]
	ldrb r7, [r1, #6]
	adds r0, r0, r7
	strb r0, [r1, #6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r7, [r6]
	cmp r0, r7
	bne _08199020
	mov r0, sl
	str r0, [r5]
	mov r2, r8
	str r2, [r4]
	b _0819904C
	.align 2, 0
_08199018: .4byte 0x00000183
_0819901C: .4byte FUN_08199064
_08199020:
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r2, r0
	blt _08198FFA
_0819902A:
	ldr r0, _0819905C @ =0x00000CEC
	add r0, sb
	ldr r0, [r0]
	movs r2, #7
	ands r0, r2
	cmp r0, #0
	bne _0819904C
	ldr r7, _08199060 @ =0x00000183
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	ble _0819904C
	strb r2, [r1]
_0819904C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819905C: .4byte 0x00000CEC
_08199060: .4byte 0x00000183

	thumb_func_start FUN_08199064
FUN_08199064: @ 0x08199064
	push {lr}
	adds r2, r0, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _0819908A
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, _08199090 @ =FUN_08199094
	str r1, [r0]
	movs r0, #0xb5
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0819908A:
	pop {r0}
	bx r0
	.align 2, 0
_08199090: .4byte FUN_08199094

	thumb_func_start FUN_08199094
FUN_08199094: @ 0x08199094
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r5, #0x20]
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	cmp r0, #0x14
	ble _08199112
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _08199118 @ =FUN_0819911c
	str r0, [r1]
_08199112:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08199118: .4byte FUN_0819911c

	thumb_func_start FUN_0819911c
FUN_0819911c: @ 0x0819911C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r5, #0x1c]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x14
	bl Div
	movs r2, #0x9c
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r5, #0x20]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	cmp r0, #0
	bne _081991A0
	ldr r0, _081991A8 @ =0x00000183
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	adds r2, #0x38
	adds r1, r5, r2
	ldr r0, _081991AC @ =FUN_081991b0
	str r0, [r1]
_081991A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081991A8: .4byte 0x00000183
_081991AC: .4byte FUN_081991b0

	thumb_func_start FUN_081991b0
FUN_081991b0: @ 0x081991B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	mov r8, r0
	movs r3, #0
	ldr r7, _0819921C @ =0x00000183
	adds r4, r2, r7
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r3, r0
	bge _08199232
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r6, r2, r0
	movs r1, #0
	mov sb, r1
	movs r1, #1
	subs r7, #0x72
	adds r7, r7, r2
	mov ip, r7
	subs r0, #0x26
	adds r0, r0, r2
	mov sl, r0
	movs r7, #0x8b
	lsls r7, r7, #1
	adds r5, r2, r7
_081991F2:
	ldrb r0, [r6]
	ldrb r7, [r2, #6]
	adds r0, r0, r7
	strb r0, [r2, #6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x80
	bne _08199228
	strb r1, [r5]
	ldr r3, _08199220 @ =0x00000117
	adds r0, r2, r3
	strb r1, [r0]
	mov r7, ip
	ldrb r0, [r7]
	orrs r1, r0
	strb r1, [r7]
	ldr r0, _08199224 @ =FUN_08199c38
	mov r1, sl
	str r0, [r1]
	b _08199254
	.align 2, 0
_0819921C: .4byte 0x00000183
_08199220: .4byte 0x00000117
_08199224: .4byte FUN_08199c38
_08199228:
	adds r3, #1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r3, r0
	blt _081991F2
_08199232:
	ldr r0, _08199264 @ =0x00000CEC
	add r0, r8
	ldr r0, [r0]
	movs r3, #7
	ands r0, r3
	cmp r0, #0
	bne _08199254
	ldr r7, _08199268 @ =0x00000183
	adds r1, r2, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	ble _08199254
	strb r3, [r1]
_08199254:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08199264: .4byte 0x00000CEC
_08199268: .4byte 0x00000183

	thumb_func_start FUN_0819926c
FUN_0819926c: @ 0x0819926C
	push {r4, r5, lr}
	mov ip, r0
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	mov r2, ip
	ldrb r0, [r2, #6]
	adds r0, #0x14
	strb r0, [r2, #6]
	adds r2, #0xf8
	ldrh r0, [r2]
	mov r3, ip
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r4, ip
	strh r0, [r4, #0x1c]
	mov r3, ip
	adds r3, #0xfc
	ldrh r0, [r3]
	ldrh r5, [r4, #0x20]
	adds r0, r0, r5
	strh r0, [r4, #0x20]
	ldr r0, _0819933C @ =0x00000CEC
	adds r1, r1, r0
	ldr r0, [r1]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08199366
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne _0819932A
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bne _0819932A
	mov r1, ip
	adds r1, #0xa2
	movs r0, #0x10
	strh r0, [r1]
	subs r1, #0x50
	strh r0, [r1]
	ldrh r0, [r4, #0x1c]
	movs r2, #0x96
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	ldrh r0, [r4, #0x1e]
	movs r4, #0x97
	lsls r4, r4, #1
	add r4, ip
	strh r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0x20]
	movs r3, #0x98
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	movs r1, #0x9a
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x9e
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	movs r1, #0x9b
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r4]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r2, #0x9f
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	movs r1, #0x9c
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _08199340 @ =FUN_0819911c
	str r0, [r1]
_0819932A:
	mov r0, ip
	adds r0, #0xf8
	movs r4, #0
	ldrsh r1, [r0, r4]
	adds r2, r0, #0
	cmp r1, #0
	blt _08199344
	asrs r0, r1, #1
	b _0819934A
	.align 2, 0
_0819933C: .4byte 0x00000CEC
_08199340: .4byte FUN_0819911c
_08199344:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0819934A:
	strh r0, [r2]
	mov r0, ip
	adds r0, #0xfc
	movs r5, #0
	ldrsh r1, [r0, r5]
	adds r2, r0, #0
	cmp r1, #0
	blt _0819935E
	asrs r0, r1, #1
	b _08199364
_0819935E:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08199364:
	strh r0, [r2]
_08199366:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0819936c
FUN_0819936c: @ 0x0819936C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	str r0, [sp]
	ldr r2, [r0, #0x18]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	movs r3, #0x1c
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #0x20
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	movs r1, #0x89
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	strb r0, [r1]
	ldr r2, _081994DC @ =0x00000185
	adds r0, r7, r2
	movs r3, #0
	strb r3, [r0]
	movs r0, #0xba
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _081994E0 @ =FUN_081994e8
	str r0, [r1]
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r2, [r0]
	movs r3, #0xa7
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	adds r1, #4
	adds r0, r7, r1
	strh r2, [r0]
	adds r3, #6
	adds r2, r7, r3
	ldr r0, [r2]
	ldrh r0, [r0]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	subs r3, #0x10
	adds r1, r7, r3
	strh r0, [r1]
	ldr r0, [r2]
	ldrh r0, [r0, #2]
	ldrh r1, [r7, #0x1e]
	subs r0, r0, r1
	adds r3, #2
	adds r1, r7, r3
	strh r0, [r1]
	ldr r0, [r2]
	ldrh r0, [r0, #4]
	ldrh r1, [r7, #0x20]
	subs r0, r0, r1
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r0, [r7, #0x1c]
	subs r3, #0x12
	adds r3, r3, r7
	mov sb, r3
	strh r0, [r3]
	ldrh r0, [r7, #0x1e]
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r6, r7, r1
	strh r0, [r6]
	ldrh r0, [r7, #0x20]
	subs r2, #0x10
	adds r2, r7, r2
	str r2, [sp, #4]
	strh r0, [r2]
	mov r3, r8
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _081994E4 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r4, #0x80
	lsls r4, r4, #5
	adds r1, r4, #0
	bl Div
	ldrh r1, [r7, #0x1c]
	adds r1, r1, r0
	movs r3, #0x96
	lsls r3, r3, #1
	adds r5, r7, r3
	strh r1, [r5]
	ldr r1, [sp]
	ldr r0, [r1, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r0, #0xdc
	movs r2, #0x97
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sl, r2
	strh r0, [r2]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	ldr r1, _081994E4 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r1, r4, #0
	bl Div
	ldrh r1, [r7, #0x20]
	adds r1, r1, r0
	movs r3, #0x98
	lsls r3, r3, #1
	adds r2, r7, r3
	strh r1, [r2]
	ldrh r0, [r5]
	mov r3, sb
	ldrh r1, [r3]
	subs r0, r0, r1
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	mov r1, sl
	ldrh r0, [r1]
	ldrh r1, [r6]
	subs r0, r0, r1
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r0, [r3]
	ldrh r0, [r2]
	ldr r2, [sp, #4]
	ldrh r1, [r2]
	subs r0, r0, r1
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	str r2, [r0]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081994DC: .4byte 0x00000185
_081994E0: .4byte FUN_081994e8
_081994E4: .4byte 0x085B0A08

	thumb_func_start FUN_081994e8
FUN_081994e8: @ 0x081994E8
	push {lr}
	adds r2, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	ldr r1, _0819955C @ =0x00000CEC
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0819951E
	ldr r0, _08199560 @ =0x00000185
	adds r1, r2, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08199516
	rsbs r0, r0, #0
_08199516:
	cmp r0, #0xf
	ble _0819951E
	movs r0, #0xf1
	strb r0, [r1]
_0819951E:
	ldr r1, _08199560 @ =0x00000185
	adds r3, r2, r1
	ldrb r0, [r3]
	ldrb r1, [r2, #6]
	adds r0, r0, r1
	strb r0, [r2, #6]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bge _08199556
	movs r0, #0
	str r0, [r1]
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	bge _08199548
	rsbs r0, r0, #0
_08199548:
	cmp r0, #0xf
	bne _08199556
	movs r0, #0xba
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08199564 @ =FUN_08199568
	str r0, [r1]
_08199556:
	pop {r0}
	bx r0
	.align 2, 0
_0819955C: .4byte 0x00000CEC
_08199560: .4byte 0x00000185
_08199564: .4byte FUN_08199568

	thumb_func_start FUN_08199568
FUN_08199568: @ 0x08199568
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r1, _081996E8 @ =0x00000185
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r2, [r6, #6]
	adds r0, r0, r2
	strb r0, [r6, #6]
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp]
	movs r4, #0
	ldrsh r1, [r3, r4]
	movs r7, #0xbe
	lsls r7, r7, #1
	adds r4, r6, r7
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r1, r1, r6
	mov sl, r1
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r6, #0x1c]
	movs r2, #0x9f
	lsls r2, r2, #1
	adds r2, r6, r2
	str r2, [sp, #4]
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	subs r7, #0x46
	adds r7, r7, r6
	mov r8, r7
	ldrh r1, [r7]
	adds r1, r1, r0
	strh r1, [r6, #0x1e]
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r0, r6, r0
	str r0, [sp, #8]
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r4]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r5, r6, r3
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r6, #0x20]
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	cmp r0, #0x64
	ble _081996D8
	movs r7, #0xba
	lsls r7, r7, #1
	adds r1, r6, r7
	ldr r0, _081996EC @ =FUN_081996f0
	str r0, [r1]
	movs r0, #0
	str r0, [r4]
	movs r0, #0xaa
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, [r2]
	adds r3, #0xc
	adds r1, r6, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r4, sl
	ldrh r1, [r4]
	subs r0, r0, r1
	subs r7, #0x28
	adds r7, r7, r6
	mov sb, r7
	strh r0, [r7]
	ldr r0, [r2]
	adds r3, #2
	adds r1, r6, r3
	ldrh r0, [r0, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	mov r4, r8
	ldrh r1, [r4]
	subs r0, r0, r1
	movs r7, #0xa7
	lsls r7, r7, #1
	adds r7, r6, r7
	str r7, [sp, #0xc]
	strh r0, [r7]
	ldr r0, [r2]
	adds r3, #2
	adds r1, r6, r3
	ldrh r0, [r0, #4]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldrh r1, [r5]
	subs r0, r0, r1
	movs r4, #0xa8
	lsls r4, r4, #1
	adds r3, r6, r4
	strh r0, [r3]
	mov r7, sb
	ldrh r0, [r7]
	mov r1, sl
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r4, #0x24
	adds r1, r6, r4
	strh r0, [r1]
	ldr r7, [sp, #0xc]
	ldrh r0, [r7]
	mov r4, r8
	ldrh r4, [r4]
	adds r0, r0, r4
	movs r7, #0x97
	lsls r7, r7, #1
	adds r7, r7, r6
	mov ip, r7
	strh r0, [r7]
	ldrh r0, [r3]
	ldrh r4, [r5]
	adds r0, r0, r4
	movs r7, #0x98
	lsls r7, r7, #1
	adds r4, r6, r7
	strh r0, [r4]
	ldrh r0, [r6, #0x1c]
	mov r7, sl
	strh r0, [r7]
	ldrh r0, [r6, #0x1e]
	mov r7, r8
	strh r0, [r7]
	ldrh r0, [r6, #0x20]
	strh r0, [r5]
	ldrh r0, [r1]
	mov r6, sl
	ldrh r1, [r6]
	subs r0, r0, r1
	ldr r7, [sp]
	strh r0, [r7]
	mov r1, ip
	ldrh r0, [r1]
	mov r6, r8
	ldrh r1, [r6]
	subs r0, r0, r1
	ldr r7, [sp, #4]
	strh r0, [r7]
	ldrh r0, [r4]
	ldrh r1, [r5]
	subs r0, r0, r1
	ldr r1, [sp, #8]
	strh r0, [r1]
	ldr r0, [r2]
	ldrh r0, [r0]
	mov r4, sb
	strh r0, [r4]
	ldr r0, [r2]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0xc]
	strh r0, [r6]
	ldr r0, [r2]
	ldrh r0, [r0, #4]
	strh r0, [r3]
_081996D8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081996E8: .4byte 0x00000185
_081996EC: .4byte FUN_081996f0

	thumb_func_start FUN_081996f0
FUN_081996f0: @ 0x081996F0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xaa
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r5]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0819980C @ =0xFFFF0000
	adds r2, r3, #0
	ldr r1, [sp]
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r5, #2]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	ldr r4, _08199810 @ =0x0000FFFF
	ands r4, r2
	orrs r4, r0
	str r4, [sp]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r1, r6, r2
	ldrh r0, [r5, #4]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	adds r2, #0x35
	adds r0, r6, r2
	ldrb r0, [r0]
	ldrb r3, [r6, #6]
	adds r0, r0, r3
	strb r0, [r6, #6]
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r5, r6, r3
	ldr r0, [r5]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r2, r6, r1
	mov r3, sp
	ldrh r1, [r3]
	ldrh r2, [r2]
	adds r1, r1, r2
	adds r1, r1, r0
	strh r1, [r6, #0x1c]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	movs r3, #0x9b
	lsls r3, r3, #1
	adds r1, r6, r3
	asrs r4, r4, #0x10
	ldrh r1, [r1]
	adds r4, r4, r1
	adds r4, r4, r0
	strh r4, [r6, #0x1e]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r5]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r2, r6, r3
	mov r3, sp
	ldrh r1, [r3, #4]
	ldrh r2, [r2]
	adds r1, r1, r2
	adds r1, r1, r0
	strh r1, [r6, #0x20]
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
	cmp r0, #0x64
	ble _08199802
	ldr r0, _08199814 @ =0x00000183
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x80
	strb r1, [r6, #6]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08199818 @ =0x00000117
	adds r1, r6, r3
	strb r0, [r1]
	ldr r1, _0819981C @ =0x00000111
	adds r2, r6, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r0, _08199820 @ =FUN_08199c38
	str r0, [r1]
_08199802:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819980C: .4byte 0xFFFF0000
_08199810: .4byte 0x0000FFFF
_08199814: .4byte 0x00000183
_08199818: .4byte 0x00000117
_0819981C: .4byte 0x00000111
_08199820: .4byte FUN_08199c38

	thumb_func_start FUN_08199824
FUN_08199824: @ 0x08199824
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldrb r0, [r7, #6]
	adds r0, #0x14
	strb r0, [r7, #6]
	adds r4, r7, #0
	adds r4, #0xf8
	ldrh r0, [r4]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	adds r5, r7, #0
	adds r5, #0xfc
	ldrh r0, [r5]
	ldrh r2, [r7, #0x20]
	adds r0, r0, r2
	strh r0, [r7, #0x20]
	movs r3, #0x8f
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #5
	bl Mod
	cmp r0, #0
	beq _0819986C
	b _081999E2
_0819986C:
	movs r6, #0
	ldrsh r0, [r4, r6]
	cmp r0, #0
	beq _08199876
	b _081999A8
_08199876:
	movs r0, #0
	ldrsh r2, [r5, r0]
	cmp r2, #0
	beq _08199880
	b _081999A8
_08199880:
	adds r1, r7, #0
	adds r1, #0xa2
	movs r0, #0x10
	strh r0, [r1]
	subs r1, #0x50
	strh r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xaa
	lsls r2, r2, #1
	adds r4, r7, r2
	ldr r0, [r4]
	movs r3, #0xa2
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r0]
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r5, #0x9a
	lsls r5, r5, #1
	adds r3, r7, r5
	ldrh r0, [r3]
	subs r1, r1, r0
	movs r6, #0xa6
	lsls r6, r6, #1
	adds r6, r6, r7
	mov r8, r6
	strh r1, [r6]
	ldr r0, [r4]
	movs r1, #0xa3
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r0, #2]
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r2, r2, r7
	mov ip, r2
	ldrh r0, [r2]
	subs r1, r1, r0
	adds r5, #0x1a
	adds r5, r5, r7
	mov sl, r5
	strh r1, [r5]
	ldr r0, [r4]
	movs r6, #0xa4
	lsls r6, r6, #1
	adds r2, r7, r6
	ldrh r1, [r0, #4]
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r0, #0x9c
	lsls r0, r0, #1
	adds r2, r7, r0
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r5, #0xa8
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp]
	strh r1, [r5]
	mov r6, r8
	ldrh r0, [r6]
	ldrh r1, [r3]
	adds r0, r0, r1
	movs r5, #0x96
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	mov r6, sl
	ldrh r0, [r6]
	mov r5, ip
	ldrh r5, [r5]
	adds r0, r0, r5
	movs r6, #0x97
	lsls r6, r6, #1
	adds r6, r6, r7
	mov sb, r6
	strh r0, [r6]
	ldr r5, [sp]
	ldrh r0, [r5]
	ldrh r6, [r2]
	adds r0, r0, r6
	movs r5, #0x98
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #4]
	strh r0, [r5]
	ldrh r0, [r7, #0x1c]
	strh r0, [r3]
	ldrh r0, [r7, #0x1e]
	mov r6, ip
	strh r0, [r6]
	ldrh r0, [r7, #0x20]
	strh r0, [r2]
	ldrh r0, [r1]
	ldrh r1, [r3]
	subs r0, r0, r1
	movs r3, #0x9e
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	mov r5, sb
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r0, r1
	movs r6, #0x9f
	lsls r6, r6, #1
	adds r3, r7, r6
	strh r0, [r3]
	ldr r1, [sp, #4]
	ldrh r0, [r1]
	ldrh r1, [r2]
	subs r0, r0, r1
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	ldr r0, [r4]
	ldrh r0, [r0]
	mov r3, r8
	strh r0, [r3]
	ldr r0, [r4]
	ldrh r0, [r0, #2]
	mov r5, sl
	strh r0, [r5]
	ldr r0, [r4]
	ldrh r0, [r0, #4]
	ldr r6, [sp]
	strh r0, [r6]
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r2, #0x45
	adds r1, r7, r2
	movs r0, #0xf1
	strb r0, [r1]
	movs r3, #0xba
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, _081999BC @ =FUN_081996f0
	str r0, [r1]
_081999A8:
	adds r0, r7, #0
	adds r0, #0xf8
	movs r5, #0
	ldrsh r1, [r0, r5]
	adds r2, r0, #0
	cmp r1, #0
	blt _081999C0
	asrs r0, r1, #1
	b _081999C6
	.align 2, 0
_081999BC: .4byte FUN_081996f0
_081999C0:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081999C6:
	strh r0, [r2]
	adds r0, r7, #0
	adds r0, #0xfc
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r2, r0, #0
	cmp r1, #0
	blt _081999DA
	asrs r0, r1, #1
	b _081999E0
_081999DA:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081999E0:
	strh r0, [r2]
_081999E2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081999f4
FUN_081999f4: @ 0x081999F4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	cmp r6, #0
	bne _08199A32
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r0, [r5, #0xc]
	ldr r2, _08199A38 @ =0x00000CC6
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
	ldr r0, [r5, #0xc]
	movs r1, #0xca
	lsls r1, r1, #4
	adds r4, r4, r1
	str r4, [r0, #0xc]
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r0, r5, r2
	str r6, [r0]
_08199A32:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08199A38: .4byte 0x00000CC6

	thumb_func_start FUN_08199a3c
FUN_08199a3c: @ 0x08199A3C
	push {r4, lr}
	mov ip, r0
	ldrh r0, [r0, #0x1c]
	movs r2, #0x96
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	mov r1, ip
	ldrh r0, [r1, #0x1e]
	movs r4, #0x97
	lsls r4, r4, #1
	add r4, ip
	strh r0, [r4]
	ldrh r0, [r1, #0x20]
	movs r3, #0x98
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	movs r1, #0x9a
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x9e
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	movs r1, #0x9b
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r4]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r2, #0x9f
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	movs r1, #0x9c
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0xa0
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08199aa4
FUN_08199aa4: @ 0x08199AA4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #1
	ldr r1, _08199AD4 @ =0x00000111
	adds r2, r7, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08199AD8
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #1
	b _08199ADA
	.align 2, 0
_08199AD4: .4byte 0x00000111
_08199AD8:
	movs r0, #0
_08199ADA:
	cmp r0, #0
	bne _08199AE0
	b _08199BEA
_08199AE0:
	movs r3, #0xac
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r4, [r0]
	ldr r1, _08199C0C @ =0x00000C84
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r2, #0x81
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r3, _08199C10 @ =0x00000C9C
	adds r1, r4, r3
	ldrb r1, [r1]
	bl Div
	ldr r1, _08199C14 @ =0x00000C9D
	adds r2, r4, r1
	movs r3, #0x88
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrb r1, [r1]
	muls r0, r1, r0
	ldrb r2, [r2]
	adds r0, r0, r2
	ldr r1, _08199C18 @ =0x00000181
	adds r1, r1, r7
	mov sb, r1
	strb r0, [r1]
	ldr r2, _08199C1C @ =0x085B0A08
	mov r8, r2
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r5, #0xc8
	muls r0, r5, r0
	movs r6, #0x80
	lsls r6, r6, #5
	adds r1, r6, #0
	bl Div
	ldr r1, _08199C20 @ =0x00000AFC
	adds r1, r1, r4
	mov sl, r1
	ldrh r1, [r1]
	adds r1, r1, r0
	strh r1, [r7, #0x1c]
	ldr r0, [r4, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r0, #0xdc
	strh r0, [r7, #0x1e]
	mov r2, sb
	ldrb r0, [r2]
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	adds r1, r6, #0
	bl Div
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r4, r4, r1
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r7, #0x20]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r0, #0x80
	strb r0, [r7, #6]
	movs r0, #0x7f
	strb r0, [r7, #8]
	movs r3, #1
	strb r3, [r7, #9]
	ldr r2, _08199C24 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08199C28 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08199C2C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r3
	subs r3, #2
	adds r1, r3, #0
	cmp r0, #0
	beq _08199BAA
	movs r1, #1
_08199BAA:
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	movs r3, #0xaa
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r1, sl
	str r1, [r0]
	adds r3, r7, #0
	adds r3, #0x9e
	ldrh r2, [r3]
	ldr r1, _08199C30 @ =0x0000FFFB
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3]
	adds r2, r7, #0
	adds r2, #0x4e
	ldrh r0, [r2]
	ands r1, r0
	strh r1, [r2]
	adds r1, r7, #0
	adds r1, #0xa2
	movs r0, #0x10
	strh r0, [r1]
	subs r1, #0x50
	strh r0, [r1]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, _08199C34 @ =FUN_081985d8
	str r0, [r1]
_08199BEA:
	movs r3, #0xb2
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _08199BFC
	adds r0, r7, #0
	bl _call_via_r1
_08199BFC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08199C0C: .4byte 0x00000C84
_08199C10: .4byte 0x00000C9C
_08199C14: .4byte 0x00000C9D
_08199C18: .4byte 0x00000181
_08199C1C: .4byte 0x085B0A08
_08199C20: .4byte 0x00000AFC
_08199C24: .4byte 0x030046B8
_08199C28: .4byte 0x000003FF
_08199C2C: .4byte 0x0203B400
_08199C30: .4byte 0x0000FFFB
_08199C34: .4byte FUN_081985d8

	thumb_func_start FUN_08199c38
FUN_08199c38: @ 0x08199C38
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	ldr r1, _08199C60 @ =0x00000111
	adds r2, r4, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08199C64
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	b _08199C66
	.align 2, 0
_08199C60: .4byte 0x00000111
_08199C64:
	movs r0, #0
_08199C66:
	cmp r0, #0
	beq _08199C74
	movs r0, #0xb4
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _08199C94 @ =FUN_08198720
	str r0, [r1]
_08199C74:
	adds r0, r4, #0
	bl FUN_08198588
	movs r1, #0xb4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08199C8C
	adds r0, r4, #0
	bl _call_via_r1
_08199C8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08199C94: .4byte FUN_08198720

	thumb_func_start FUN_08199c98
FUN_08199c98: @ 0x08199C98
	push {lr}
	adds r2, r0, #0
	movs r0, #1
	ldr r1, _08199CC0 @ =0x00000111
	adds r3, r2, r1
	ldrb r1, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08199CC4
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r3]
	movs r3, #0x93
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #1
	b _08199CC6
	.align 2, 0
_08199CC0: .4byte 0x00000111
_08199CC4:
	movs r0, #0
_08199CC6:
	cmp r0, #0
	beq _08199CD4
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08199CEC @ =FUN_08198860
	str r0, [r1]
_08199CD4:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08199CE6
	adds r0, r2, #0
	bl _call_via_r1
_08199CE6:
	pop {r0}
	bx r0
	.align 2, 0
_08199CEC: .4byte FUN_08198860

	thumb_func_start FUN_08199cf0
FUN_08199cf0: @ 0x08199CF0
	push {lr}
	adds r2, r0, #0
	movs r0, #1
	ldr r1, _08199D18 @ =0x00000111
	adds r3, r2, r1
	ldrb r1, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08199D1C
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r3]
	movs r3, #0x93
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #1
	b _08199D1E
	.align 2, 0
_08199D18: .4byte 0x00000111
_08199D1C:
	movs r0, #0
_08199D1E:
	cmp r0, #0
	beq _08199D2C
	movs r0, #0xb8
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08199D44 @ =FUN_08198e4c
	str r0, [r1]
_08199D2C:
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08199D3E
	adds r0, r2, #0
	bl _call_via_r1
_08199D3E:
	pop {r0}
	bx r0
	.align 2, 0
_08199D44: .4byte FUN_08198e4c

	thumb_func_start FUN_08199d48
FUN_08199d48: @ 0x08199D48
	push {lr}
	adds r2, r0, #0
	movs r0, #1
	ldr r1, _08199D70 @ =0x00000111
	adds r3, r2, r1
	ldrb r1, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08199D74
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r3]
	movs r3, #0x93
	lsls r3, r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	movs r0, #1
	b _08199D76
	.align 2, 0
_08199D70: .4byte 0x00000111
_08199D74:
	movs r0, #0
_08199D76:
	cmp r0, #0
	beq _08199D84
	movs r0, #0xba
	lsls r0, r0, #1
	adds r1, r2, r0
	ldr r0, _08199D9C @ =FUN_0819936c
	str r0, [r1]
_08199D84:
	movs r1, #0xba
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08199D96
	adds r0, r2, #0
	bl _call_via_r1
_08199D96:
	pop {r0}
	bx r0
	.align 2, 0
_08199D9C: .4byte FUN_0819936c

	thumb_func_start FUN_08199da0
FUN_08199da0: @ 0x08199DA0
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r4, r0, #0
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	movs r0, #1
	subs r1, #0x47
	adds r2, r4, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08199DD2
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	b _08199DD4
_08199DD2:
	movs r0, #0
_08199DD4:
	cmp r0, #0
	beq _08199DFE
	adds r3, r4, #0
	adds r3, #0x4e
	ldrh r0, [r3]
	movs r1, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r3, #0x50
	ldrh r0, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _08199ED4 @ =0x00000125
	adds r1, r4, r2
	movs r0, #0x14
	strb r0, [r1]
_08199DFE:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrb r1, [r5]
	adds r0, r1, #1
	strb r0, [r5]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08199E48
	ldr r0, [r4, #0xc]
	ldr r2, _08199ED8 @ =0x00000CC6
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
	movs r1, #5
	movs r0, #0x8b
	lsls r0, r0, #1
	adds r2, r4, r0
	movs r0, #0
	strb r0, [r2]
	ldr r2, _08199EDC @ =0x00000117
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	ldr r1, _08199EE0 @ =0x00000111
	adds r2, r4, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08199E48:
	ldrb r0, [r5]
	movs r5, #7
	ands r5, r0
	cmp r5, #0
	bne _08199ECA
	ldr r0, [r4, #0x6c]
	ldr r1, [r4, #0x70]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08199EE4 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x64
	lsls r1, r1, #0x10
	ldr r4, _08199EE8 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	adds r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r3
	movs r1, #0x50
	orrs r0, r1
	ands r0, r4
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x28
	orrs r0, r1
	str r0, [r2, #4]
	str r5, [sp]
	movs r0, #0xe
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #1
	movs r3, #0
	bl FUN_080ddcc8
	movs r0, #0xb7
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08199ECA:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08199ED4: .4byte 0x00000125
_08199ED8: .4byte 0x00000CC6
_08199EDC: .4byte 0x00000117
_08199EE0: .4byte 0x00000111
_08199EE4: .4byte 0xFFFF0000
_08199EE8: .4byte 0x0000FFFF

	thumb_func_start FUN_08199eec
FUN_08199eec: @ 0x08199EEC
	bx lr
	.align 2, 0

	thumb_func_start FUN_08199ef0
FUN_08199ef0: @ 0x08199EF0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x10
	ldr r2, _08199F40 @ =0x00000111
	adds r0, r4, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08199F3A
	adds r1, r4, #0
	adds r1, #0xdc
	ldrh r0, [r1]
	cmp r0, #0
	beq _08199F10
	subs r0, #1
	strh r0, [r1]
_08199F10:
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08199F22
	adds r0, r4, #0
	bl _call_via_r1
_08199F22:
	adds r0, r4, #0
	bl FUN_08195f1c
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _08199F3A
	adds r0, r4, #0
	bl _call_via_r1
_08199F3A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08199F40: .4byte 0x00000111

	thumb_func_start FUN_08199f44
FUN_08199f44: @ 0x08199F44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r1, _08199F90 @ =0x00000C9C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r7, r0
	bge _08199F86
	ldr r0, _08199F94 @ =0x085ADDB0
	mov r8, r0
	ldr r1, _08199F98 @ =0x0000056A
	adds r5, r6, r1
	ldr r0, _08199F9C @ =0x00000454
	adds r4, r6, r0
_08199F64:
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r5, r5, r1
	adds r4, r4, r1
	adds r7, #1
	ldr r1, _08199F90 @ =0x00000C9C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08199F64
_08199F86:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08199F90: .4byte 0x00000C9C
_08199F94: .4byte 0x085ADDB0
_08199F98: .4byte 0x0000056A
_08199F9C: .4byte 0x00000454

	thumb_func_start FUN_08199fa0
FUN_08199fa0: @ 0x08199FA0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	ldr r6, [r0, #0x1c]
	movs r0, #4
	ands r6, r0
	cmp r6, #0
	beq _08199FB4
	movs r0, #1
	b _08199FE8
_08199FB4:
	adds r0, r4, #0
	bl FUN_081982b0
	adds r0, r4, #0
	bl FUN_08199f44
	ldr r0, _08199FF0 @ =0x00000CE6
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _08199FDC
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0819742c
	strh r6, [r5]
	ldr r1, _08199FF4 @ =0x00000CE4
	adds r0, r4, r1
	strh r6, [r0]
_08199FDC:
	ldr r0, _08199FF8 @ =0x00000CEC
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
_08199FE8:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08199FF0: .4byte 0x00000CE6
_08199FF4: .4byte 0x00000CE4
_08199FF8: .4byte 0x00000CEC

	thumb_func_start FUN_08199ffc
FUN_08199ffc: @ 0x08199FFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xae
	lsls r1, r1, #4
	adds r0, r6, r1
	bl FUN_0822a4e0
	ldr r1, _0819A094 @ =0x00000B28
	adds r0, r6, r1
	bl FUN_08013c70
	ldr r1, _0819A098 @ =0x00000B94
	adds r0, r6, r1
	bl FUN_08236424
	ldr r1, _0819A09C @ =0x00000BE4
	adds r0, r6, r1
	bl FUN_08236424
	adds r4, r6, #0
	adds r4, #0x60
	movs r0, #3
	mov r8, r0
_0819A02E:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x2c
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r0, r8
	cmp r0, #0
	bge _0819A02E
	movs r1, #0
	mov r8, r1
	ldr r1, _0819A0A0 @ =0x00000C9C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _0819A086
	ldr r0, _0819A0A4 @ =0x000004EC
	adds r7, r6, r0
	ldr r1, _0819A0A8 @ =0x0000049C
	adds r5, r6, r1
	subs r0, #0x98
	adds r4, r6, r0
_0819A05C:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r0, r5, #0
	bl FUN_08236424
	adds r0, r7, #0
	bl FUN_08236424
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r7, r7, r1
	adds r5, r5, r1
	adds r4, r4, r1
	movs r0, #1
	add r8, r0
	ldr r1, _0819A0A0 @ =0x00000C9C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r8, r0
	blt _0819A05C
_0819A086:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0819A094: .4byte 0x00000B28
_0819A098: .4byte 0x00000B94
_0819A09C: .4byte 0x00000BE4
_0819A0A0: .4byte 0x00000C9C
_0819A0A4: .4byte 0x000004EC
_0819A0A8: .4byte 0x0000049C

	thumb_func_start FUN_0819a0ac
FUN_0819a0ac: @ 0x0819A0AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x3c
	adds r6, r0, #0
	ldr r0, _0819A1DC @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r6, #0x18]
	ldr r0, _0819A1E0 @ =0x00000B0C
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0xae
	lsls r1, r1, #4
	adds r7, r6, r1
	movs r3, #0
	movs r2, #0
	strh r2, [r6, #0x1c]
	strh r2, [r6, #0x1e]
	strh r2, [r6, #0x20]
	strh r2, [r6, #0x24]
	movs r4, #1
	movs r1, #1
	strh r1, [r6, #0x26]
	strh r2, [r6, #0x28]
	adds r5, r6, #0
	adds r5, #0x45
	strb r3, [r5]
	strh r2, [r6, #0x36]
	adds r0, r6, #0
	adds r0, #0x46
	strb r3, [r0]
	adds r0, #0x10
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	subs r0, #5
	strh r2, [r0]
	adds r0, #2
	strh r2, [r0]
	subs r0, #0xa
	strb r4, [r0]
	adds r0, #1
	strb r3, [r0]
	ldrb r0, [r5]
	orrs r1, r0
	strb r1, [r5]
	ldr r3, _0819A1E4 @ =0x00000C38
	adds r1, r6, r3
	ldr r0, _0819A1E8 @ =FUN_081976c4
	str r0, [r1]
	movs r4, #0xc6
	lsls r4, r4, #4
	adds r1, r6, r4
	ldr r0, _0819A1EC @ =FUN_081958b4
	str r0, [r1]
	ldr r5, _0819A1F0 @ =0x00000C5C
	adds r0, r6, r5
	str r2, [r0]
	ldr r0, _0819A1F4 @ =0x00000C68
	adds r1, r6, r0
	movs r0, #0x14
	str r0, [r1]
	ldr r1, _0819A1F8 @ =0x00005291
	mov r0, r8
	bl Video_GetActorSprite
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r7]
	movs r1, #2
	orrs r0, r1
	str r0, [r7]
	ldr r1, _0819A1FC @ =0x00000AEC
	adds r0, r6, r1
	ldr r0, [r0]
	ldr r2, _0819A200 @ =0x00000CC6
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0822b20c
	add r3, sp, #0x24
	mov sl, r3
	mov r4, r8
	ldr r2, [r4, #0xc]
	adds r5, #0x44
	adds r1, r6, r5
	movs r0, #0xf
	mov sb, r0
_0819A166:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	movs r3, #1
	rsbs r3, r3, #0
	add sb, r3
	mov r4, sb
	cmp r4, #0
	bge _0819A166
	movs r5, #0xca
	lsls r5, r5, #4
	adds r0, r6, r5
	mov r1, r8
	str r0, [r1, #0xc]
	ldr r2, _0819A204 @ =0x00000CC2
	adds r1, r6, r2
	movs r2, #0
	movs r0, #5
	strb r0, [r1]
	ldr r3, _0819A208 @ =0x00000CC3
	adds r0, r6, r3
	strb r2, [r0]
	ldr r4, _0819A20C @ =0x00000CC4
	adds r0, r6, r4
	strb r2, [r0]
	ldr r5, _0819A210 @ =0x00000B28
	adds r0, r6, r5
	ldr r3, _0819A214 @ =0x00000AFC
	adds r1, r6, r3
	movs r3, #0x30
	str r3, [sp]
	str r3, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	str r2, [sp, #0x10]
	str r2, [sp, #0x14]
	str r2, [sp, #0x18]
	movs r2, #0x30
	bl FUN_08013ba8
	movs r0, #0x41
	bl VM_SeekToKeyword
	adds r4, r6, #0
	adds r4, #0x42
	str r4, [sp, #0x34]
	adds r5, r6, #0
	adds r5, #0x40
	str r5, [sp, #0x30]
	cmp r0, #0
	beq _0819A28A
	bl VM_GetPC
	cmp r0, #0
	beq _0819A218
	bl Script_GetValue
	b _0819A21A
	.align 2, 0
_0819A1DC: .4byte 0x03002BE0
_0819A1E0: .4byte 0x00000B0C
_0819A1E4: .4byte 0x00000C38
_0819A1E8: .4byte FUN_081976c4
_0819A1EC: .4byte FUN_081958b4
_0819A1F0: .4byte 0x00000C5C
_0819A1F4: .4byte 0x00000C68
_0819A1F8: .4byte 0x00005291
_0819A1FC: .4byte 0x00000AEC
_0819A200: .4byte 0x00000CC6
_0819A204: .4byte 0x00000CC2
_0819A208: .4byte 0x00000CC3
_0819A20C: .4byte 0x00000CC4
_0819A210: .4byte 0x00000B28
_0819A214: .4byte 0x00000AFC
_0819A218:
	movs r0, #0
_0819A21A:
	strh r0, [r6, #0x36]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A22A
	bl Script_GetValue
	b _0819A22C
_0819A22A:
	movs r0, #0
_0819A22C:
	strh r0, [r6, #0x38]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A23C
	bl Script_GetValue
	b _0819A23E
_0819A23C:
	movs r0, #0
_0819A23E:
	strh r0, [r6, #0x3a]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A24E
	bl Script_GetValue
	b _0819A250
_0819A24E:
	movs r0, #0
_0819A250:
	strh r0, [r6, #0x3c]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A260
	bl Script_GetValue
	b _0819A262
_0819A260:
	movs r0, #0
_0819A262:
	adds r4, r6, #0
	adds r4, #0x42
	strh r0, [r4]
	bl VM_GetPC
	str r4, [sp, #0x34]
	cmp r0, #0
	beq _0819A278
	bl Script_GetValue
	b _0819A27A
_0819A278:
	movs r0, #0
_0819A27A:
	adds r2, r6, #0
	adds r2, #0x40
	strh r0, [r2]
	ldrh r1, [r6, #0x36]
	ldr r3, _0819A2BC @ =0x00000CCC
	adds r0, r6, r3
	strh r1, [r0]
	str r2, [sp, #0x30]
_0819A28A:
	movs r0, #0x54
	bl VM_SeekToKeyword
	movs r4, #0x1c
	adds r4, r4, r7
	mov r8, r4
	adds r5, r6, #0
	adds r5, #0x60
	str r5, [sp, #0x38]
	cmp r0, #0
	beq _0819A328
	movs r5, #0
	movs r0, #1
	mov sb, r0
_0819A2A6:
	ldr r1, _0819A2C0 @ =0x00000C74
	adds r0, r6, r1
	adds r4, r0, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0819A2C4
	bl Script_GetValue
	b _0819A2C6
	.align 2, 0
_0819A2BC: .4byte 0x00000CCC
_0819A2C0: .4byte 0x00000C74
_0819A2C4:
	movs r0, #0
_0819A2C6:
	strh r0, [r4]
	ldr r2, _0819A2DC @ =0x00000C78
	adds r0, r6, r2
	adds r4, r0, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0819A2E0
	bl Script_GetValue
	b _0819A2E2
	.align 2, 0
_0819A2DC: .4byte 0x00000C78
_0819A2E0:
	movs r0, #0
_0819A2E2:
	strh r0, [r4]
	ldr r3, _0819A2F8 @ =0x00000C7C
	adds r0, r6, r3
	adds r4, r0, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0819A2FC
	bl Script_GetValue
	b _0819A2FE
	.align 2, 0
_0819A2F8: .4byte 0x00000C7C
_0819A2FC:
	movs r0, #0
_0819A2FE:
	strh r0, [r4]
	movs r4, #0xc8
	lsls r4, r4, #4
	adds r0, r6, r4
	adds r4, r0, r5
	bl VM_GetPC
	cmp r0, #0
	beq _0819A316
	bl Script_GetValue
	b _0819A318
_0819A316:
	movs r0, #0
_0819A318:
	strh r0, [r4]
	adds r5, #2
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _0819A2A6
_0819A328:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0819A344
	bl Script_GetValue
	strh r0, [r7, #0x1c]
	bl Script_GetValue
	strh r0, [r7, #0x1e]
	bl Script_GetValue
	b _0819A348
_0819A344:
	strh r0, [r7, #0x1c]
	strh r0, [r7, #0x1e]
_0819A348:
	strh r0, [r7, #0x20]
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r2, _0819A578 @ =0x00000CCE
	adds r1, r6, r2
	strb r0, [r1]
	mov r0, r8
	bl FUN_082328ec
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r0, r0, r3
	strh r0, [r7, #0x1e]
	ldr r2, _0819A57C @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _0819A580 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x20]
	movs r0, #0
	str r0, [sp, #0x24]
	mov r4, sl
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r5, _0819A584 @ =0x00000B94
	adds r4, r6, r5
	ldr r2, _0819A588 @ =0x00002001
	movs r5, #0x10
	str r5, [sp]
	add r0, sp, #0x1c
	str r0, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r2, _0819A58C @ =0x00000C74
	adds r0, r6, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r2, #4
	adds r0, r6, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r3, _0819A590 @ =0x00000C7C
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	movs r3, #0xc8
	lsls r3, r3, #4
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _0819A594 @ =FUN_08195fd8
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	ldr r4, _0819A598 @ =0x00000B9A
	adds r2, r6, r4
	ldrh r1, [r2]
	ldr r0, _0819A59C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r0, _0819A5A0 @ =0x00000BE4
	adds r4, r6, r0
	ldr r2, _0819A5A4 @ =0x00005009
	str r5, [sp]
	add r1, sp, #0x1c
	str r1, [sp, #4]
	mov r3, sl
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r5, #0x38
	ldrsh r1, [r6, r5]
	ldr r0, [sp, #0x34]
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r5, [sp, #0x30]
	movs r0, #0
	ldrsh r3, [r5, r0]
	adds r0, r4, #0
	bl FUN_08236514
	ldr r1, _0819A5A8 @ =FUN_08195fdc
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	movs r2, #0xc4
	lsls r2, r2, #4
	adds r1, r6, r2
	ldr r0, _0819A5AC @ =FUN_08195d5c
	str r0, [r1]
	movs r3, #0
	mov sb, r3
	mov r4, sp
	adds r4, #0x1c
	str r4, [sp, #0x2c]
	movs r5, #0xb0
	lsls r5, r5, #2
	adds r7, r6, r5
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r5, r6, r0
	movs r1, #0x88
	lsls r1, r1, #1
	adds r1, r1, r6
	mov r8, r1
_0819A45E:
	mov r0, r8
	ldr r1, _0819A5B0 @ =0x00005291
	bl Video_GetActorSprite
	movs r0, #0x2c
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x60
	adds r0, r6, r0
	mov r1, r8
	movs r2, #0
	bl FUN_0822a470
	ldr r2, [sp, #0x38]
	adds r1, r2, r4
	ldr r0, _0819A5B4 @ =0x00000203
	str r0, [r1]
	adds r1, r6, r4
	adds r2, r1, #0
	adds r2, #0x67
	movs r0, #3
	strb r0, [r2]
	adds r0, r1, #0
	adds r0, #0x7c
	movs r3, #0
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	movs r4, #0x10
	str r4, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	ldr r2, _0819A588 @ =0x00002001
	movs r3, #0
	bl FUN_0823646c
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r5, #0
	bl FUN_08236400
	ldr r2, _0819A5B8 @ =0x00000C76
	adds r0, r6, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r4, _0819A5BC @ =0x00000C7A
	adds r0, r6, r4
	movs r3, #0
	ldrsh r2, [r0, r3]
	adds r4, #4
	adds r0, r6, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r4, #4
	adds r0, r6, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_082364f8
	ldrh r0, [r5, #6]
	movs r4, #4
	orrs r0, r4
	strh r0, [r5, #6]
	movs r0, #0x10
	str r0, [sp]
	ldr r1, [sp, #0x2c]
	str r1, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	ldr r2, _0819A5C0 @ =0x00004009
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0x38
	ldrsh r1, [r6, r3]
	ldr r4, [sp, #0x34]
	movs r0, #0
	ldrsh r2, [r4, r0]
	ldr r4, [sp, #0x30]
	movs r0, #0
	ldrsh r3, [r4, r0]
	adds r0, r7, #0
	bl FUN_08236514
	adds r0, r7, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r7, #0
	bl FUN_08236400
	ldrh r0, [r7, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7, #6]
	adds r7, #0x50
	adds r5, #0x50
	movs r2, #0x1c
	add r8, r2
	movs r3, #1
	add sb, r3
	mov r4, sb
	cmp r4, #3
	ble _0819A45E
	adds r0, r6, #0
	bl FUN_081974c4
	ldr r5, _0819A5C4 @ =0x00000A84
	adds r1, r6, r5
	adds r0, r6, #0
	movs r2, #0xf7
	bl FUN_0819750c
	adds r0, r6, #0
	bl FUN_08197530
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819A578: .4byte 0x00000CCE
_0819A57C: .4byte 0xFFFF0000
_0819A580: .4byte 0x0000FFFF
_0819A584: .4byte 0x00000B94
_0819A588: .4byte 0x00002001
_0819A58C: .4byte 0x00000C74
_0819A590: .4byte 0x00000C7C
_0819A594: .4byte FUN_08195fd8
_0819A598: .4byte 0x00000B9A
_0819A59C: .4byte 0x0000FFFB
_0819A5A0: .4byte 0x00000BE4
_0819A5A4: .4byte 0x00005009
_0819A5A8: .4byte FUN_08195fdc
_0819A5AC: .4byte FUN_08195d5c
_0819A5B0: .4byte 0x00005291
_0819A5B4: .4byte 0x00000203
_0819A5B8: .4byte 0x00000C76
_0819A5BC: .4byte 0x00000C7A
_0819A5C0: .4byte 0x00004009
_0819A5C4: .4byte 0x00000A84

	thumb_func_start FUN_0819a5c8
FUN_0819a5c8: @ 0x0819A5C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	ldr r2, _0819A61C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _0819A620 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0819A6D4
	bl VM_GetPC
	cmp r0, #0
	beq _0819A624
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A626
	.align 2, 0
_0819A61C: .4byte 0xFFFF0000
_0819A620: .4byte 0x0000FFFF
_0819A624:
	movs r1, #0
_0819A626:
	ldr r2, _0819A63C @ =0x00000C84
	adds r0, r6, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A640
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A642
	.align 2, 0
_0819A63C: .4byte 0x00000C84
_0819A640:
	movs r1, #0
_0819A642:
	ldr r3, _0819A658 @ =0x00000C86
	adds r0, r6, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A65C
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A65E
	.align 2, 0
_0819A658: .4byte 0x00000C86
_0819A65C:
	movs r1, #0
_0819A65E:
	ldr r2, _0819A674 @ =0x00000C88
	adds r0, r6, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A678
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A67A
	.align 2, 0
_0819A674: .4byte 0x00000C88
_0819A678:
	movs r1, #0
_0819A67A:
	ldr r3, _0819A690 @ =0x00000C8A
	adds r0, r6, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A694
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A696
	.align 2, 0
_0819A690: .4byte 0x00000C8A
_0819A694:
	movs r1, #0
_0819A696:
	ldr r2, _0819A6AC @ =0x00000CEA
	adds r0, r6, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A6B0
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A6B2
	.align 2, 0
_0819A6AC: .4byte 0x00000CEA
_0819A6B0:
	movs r1, #0
_0819A6B2:
	ldr r3, _0819A6C8 @ =0x00000C8C
	adds r0, r6, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A6CC
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A6CE
	.align 2, 0
_0819A6C8: .4byte 0x00000C8C
_0819A6CC:
	movs r1, #0
_0819A6CE:
	ldr r2, _0819A6F0 @ =0x00000C8E
	adds r0, r6, r2
	strh r1, [r0]
_0819A6D4:
	movs r0, #0x43
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0819A750
	bl VM_GetPC
	cmp r0, #0
	beq _0819A6F4
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A6F6
	.align 2, 0
_0819A6F0: .4byte 0x00000C8E
_0819A6F4:
	movs r1, #0
_0819A6F6:
	movs r3, #0xc9
	lsls r3, r3, #4
	adds r0, r6, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A70E
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A710
_0819A70E:
	movs r1, #0
_0819A710:
	ldr r2, _0819A728 @ =0x00000C92
	adds r0, r6, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A72C
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A72E
	.align 2, 0
_0819A728: .4byte 0x00000C92
_0819A72C:
	movs r1, #0
_0819A72E:
	ldr r3, _0819A744 @ =0x00000C94
	adds r0, r6, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A748
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A74A
	.align 2, 0
_0819A744: .4byte 0x00000C94
_0819A748:
	movs r1, #0
_0819A74A:
	ldr r2, _0819A764 @ =0x00000C96
	adds r0, r6, r2
	strh r1, [r0]
_0819A750:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0819A76C
	bl Script_GetValue
	ldr r3, _0819A768 @ =0x00000C9C
	adds r1, r6, r3
	b _0819A772
	.align 2, 0
_0819A764: .4byte 0x00000C96
_0819A768: .4byte 0x00000C9C
_0819A76C:
	ldr r0, _0819A8F8 @ =0x00000C9C
	adds r1, r6, r0
	movs r0, #4
_0819A772:
	strb r0, [r1]
	movs r1, #0
	str r1, [sp, #0x1c]
	mov sb, r1
	ldr r2, _0819A8FC @ =0x000004EC
	adds r2, r2, r6
	mov r8, r2
	ldr r3, _0819A900 @ =0x0000049C
	adds r7, r6, r3
	ldr r0, _0819A904 @ =0x00000564
	adds r4, r6, r0
	ldr r1, _0819A908 @ =0x00000454
	adds r1, r6, r1
	str r1, [sp, #0x28]
	ldr r2, _0819A90C @ =0x0000053C
	adds r5, r6, r2
	subs r3, #0x1c
	adds r3, r6, r3
	str r3, [sp, #0x2c]
	mov sl, r1
	mov r0, sp
	adds r0, #0xc
	str r0, [sp, #0x20]
	mov r1, sp
	adds r1, #0x14
	str r1, [sp, #0x24]
_0819A7A6:
	mov r2, sb
	strh r2, [r5]
	strh r2, [r5, #2]
	strh r2, [r5, #4]
	strh r2, [r5, #8]
	movs r3, #1
	strh r3, [r5, #0xa]
	strh r2, [r5, #0xc]
	movs r0, #0
	strb r0, [r4, #1]
	strh r2, [r5, #0x1a]
	strb r0, [r4, #2]
	strb r0, [r4, #0x12]
	strb r0, [r4, #0x13]
	strh r2, [r4, #0xe]
	strh r2, [r4, #0x10]
	mov r1, sb
	str r1, [r4, #0x50]
	ldr r0, [sp, #0x2c]
	ldr r1, _0819A910 @ =0x00005292
	bl Video_GetActorSprite
	mov r0, sl
	ldr r1, [sp, #0x2c]
	movs r2, #0
	bl FUN_0822a470
	movs r0, #3
	ldr r2, [sp, #0x28]
	str r0, [r2]
	ldr r0, [r2, #0xc]
	ldr r3, _0819A914 @ =0x00000CC6
	adds r1, r6, r3
	ldrh r1, [r1]
	bl FUN_0822b20c
	mov r0, sp
	ldrb r0, [r0, #0x1c]
	strb r0, [r4]
	movs r1, #0
	strb r1, [r4, #6]
	strb r1, [r4, #7]
	ldrb r1, [r4, #1]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #1]
	str r6, [r4, #0x48]
	movs r0, #0x14
	str r0, [r4, #0x68]
	mov r2, sb
	str r2, [r4, #0x6c]
	movs r3, #0x10
	str r3, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	ldr r1, [sp, #0x24]
	str r1, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	ldr r2, _0819A918 @ =0x00002001
	movs r3, #0
	bl FUN_0823646c
	adds r0, r7, #0
	ldr r1, _0819A91C @ =FUN_081982dc
	mov r2, sl
	bl FUN_0823651c
	adds r0, r7, #0
	bl FUN_08236400
	movs r2, #0xc9
	lsls r2, r2, #4
	adds r0, r6, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	adds r2, #2
	adds r0, r6, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r3, _0819A920 @ =0x00000C94
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	ldr r3, _0819A924 @ =0x00000C96
	adds r0, r6, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r3, #0x80
	lsls r3, r3, #3
	bl FUN_082364f8
	ldrh r0, [r7, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7, #6]
	movs r2, #0x10
	str r2, [sp]
	ldr r3, [sp, #0x20]
	str r3, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	mov r0, r8
	movs r1, #0
	ldr r2, _0819A928 @ =0x00005009
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0819A92C @ =0x00000C86
	adds r0, r6, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _0819A930 @ =0x00000C8C
	adds r0, r6, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	str r2, [sp, #0x30]
	ldr r2, _0819A934 @ =0x00000C8E
	adds r0, r6, r2
	movs r2, #0
	ldrsh r3, [r0, r2]
	mov ip, r3
	mov r0, r8
	ldr r2, [sp, #0x30]
	bl FUN_08236514
	mov r0, r8
	ldr r1, _0819A938 @ =FUN_081982e0
	mov r2, sl
	bl FUN_0823651c
	mov r0, r8
	bl FUN_08236400
	mov r3, r8
	ldrh r0, [r3, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r3, #6]
	movs r2, #0xc6
	lsls r2, r2, #1
	add r8, r2
	adds r7, r7, r2
	adds r4, r4, r2
	ldr r3, [sp, #0x28]
	adds r3, r3, r2
	str r3, [sp, #0x28]
	adds r5, r5, r2
	ldr r0, [sp, #0x2c]
	adds r0, r0, r2
	str r0, [sp, #0x2c]
	add sl, r2
	ldr r1, [sp, #0x1c]
	adds r1, #1
	str r1, [sp, #0x1c]
	cmp r1, #3
	bgt _0819A8E8
	b _0819A7A6
_0819A8E8:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819A8F8: .4byte 0x00000C9C
_0819A8FC: .4byte 0x000004EC
_0819A900: .4byte 0x0000049C
_0819A904: .4byte 0x00000564
_0819A908: .4byte 0x00000454
_0819A90C: .4byte 0x0000053C
_0819A910: .4byte 0x00005292
_0819A914: .4byte 0x00000CC6
_0819A918: .4byte 0x00002001
_0819A91C: .4byte FUN_081982dc
_0819A920: .4byte 0x00000C94
_0819A924: .4byte 0x00000C96
_0819A928: .4byte 0x00005009
_0819A92C: .4byte 0x00000C86
_0819A930: .4byte 0x00000C8C
_0819A934: .4byte 0x00000C8E
_0819A938: .4byte FUN_081982e0

	thumb_func_start FUN_0819a93c
FUN_0819a93c: @ 0x0819A93C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _0819A974 @ =0x00000CC5
	adds r1, r5, r2
	strb r0, [r1]
	ldr r2, _0819A978 @ =0x0000012D
	adds r0, r2, #0
	ldrb r1, [r1]
	adds r0, r0, r1
	ldr r2, _0819A97C @ =0x00000CC6
	adds r1, r5, r2
	strh r0, [r1]
	ldr r0, _0819A980 @ =0x00000CC8
	adds r1, r5, r0
	movs r0, #0x99
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	movs r4, #0
	ldr r2, _0819A984 @ =0x00000CDC
	adds r6, r5, r2
	b _0819A990
	.align 2, 0
_0819A974: .4byte 0x00000CC5
_0819A978: .4byte 0x0000012D
_0819A97C: .4byte 0x00000CC6
_0819A980: .4byte 0x00000CC8
_0819A984: .4byte 0x00000CDC
_0819A988:
	bl Script_GetValue
	stm r6!, {r0}
	adds r4, #1
_0819A990:
	cmp r4, #1
	bgt _0819A99C
	bl VM_GetPC
	cmp r0, #0
	bne _0819A988
_0819A99C:
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0819A9B0
	bl Script_GetValue
	ldr r2, _0819A9CC @ =0x00000CD8
	adds r1, r5, r2
	str r0, [r1]
_0819A9B0:
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0819A9EA
	bl VM_GetPC
	cmp r0, #0
	beq _0819A9D0
	bl Script_GetValue
	adds r1, r0, #0
	b _0819A9D2
	.align 2, 0
_0819A9CC: .4byte 0x00000CD8
_0819A9D0:
	movs r1, #0
_0819A9D2:
	adds r0, r5, #0
	adds r0, #0x5c
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819A9E6
	bl Script_GetValue
	b _0819A9E8
_0819A9E6:
	movs r0, #0
_0819A9E8:
	strh r0, [r5, #0x3e]
_0819A9EA:
	adds r0, r5, #0
	bl FUN_0819a5c8
	adds r0, r5, #0
	bl FUN_0819a0ac
	ldr r0, _0819AA04 @ =0x00000CEC
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0819AA04: .4byte 0x00000CEC

	thumb_func_start FUN_0819aa08
FUN_0819aa08: @ 0x0819AA08
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r1, _0819AA40 @ =0x00000CF4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0819AA50
	ldr r1, _0819AA44 @ =0x00000CE8
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, _0819AA48 @ =FUN_08199fa0
	ldr r2, _0819AA4C @ =FUN_08199ffc
	adds r0, r4, #0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0819a93c
	cmp r0, #0
	bge _0819AA50
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0819AA52
	.align 2, 0
_0819AA40: .4byte 0x00000CF4
_0819AA44: .4byte 0x00000CE8
_0819AA48: .4byte FUN_08199fa0
_0819AA4C: .4byte FUN_08199ffc
_0819AA50:
	adds r0, r4, #0
_0819AA52:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0819aa58
FUN_0819aa58: @ 0x0819AA58
	bx lr
	.align 2, 0

	thumb_func_start FUN_0819aa5c
FUN_0819aa5c: @ 0x0819AA5C
	push {lr}
	adds r3, r2, #0
	ldr r0, _0819AA90 @ =0x00000CBB
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0819AA8C
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r3, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
_0819AA8C:
	pop {r0}
	bx r0
	.align 2, 0
_0819AA90: .4byte 0x00000CBB

	thumb_func_start FUN_0819aa94
FUN_0819aa94: @ 0x0819AA94
	bx lr
	.align 2, 0

	thumb_func_start FUN_0819aa98
FUN_0819aa98: @ 0x0819AA98
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	mov r8, r1
	adds r6, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819AAC2
	b _0819B1FC
_0819AAC2:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0819AAD2
	b _0819B14E
_0819AAD2:
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0819AAFC
	ldr r3, _0819AAF8 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0819AAEA
	b _0819B14E
_0819AAEA:
	movs r0, #0
	mov r4, r8
	strh r1, [r4, #0x3e]
	mov r1, r8
	adds r1, #0x43
	strb r0, [r1]
	b _0819B14E
	.align 2, 0
_0819AAF8: .4byte 0x0000048C
_0819AAFC:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0819AB0C
	b _0819B14E
_0819AB0C:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0819AB1A
	b _0819AE20
_0819AB1A:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _0819AB2A
	b _0819B14E
_0819AB2A:
	ldr r2, _0819ABBC @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0819AB3E
	b _0819B14E
_0819AB3E:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0819AB4C
	b _0819B14E
_0819AB4C:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _0819AB64
	b _0819ACAC
_0819AB64:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0819ABCC
	ands r3, r1
	cmp r3, #0
	beq _0819ABCC
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0819AB8C
	rsbs r1, r1, #0
_0819AB8C:
	cmp r1, #0x20
	bgt _0819ABCC
	ldrh r0, [r7, #0x3c]
	ldr r3, _0819ABC0 @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r7, _0819ABC4 @ =0x0000048C
	adds r0, r6, r7
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r2, _0819ABC8 @ =0x0000044E
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r3, sl
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	b _0819B14E
	.align 2, 0
_0819ABBC: .4byte 0x0000A007
_0819ABC0: .4byte 0x000004BE
_0819ABC4: .4byte 0x0000048C
_0819ABC8: .4byte 0x0000044E
_0819ABCC:
	movs r1, #0
	mov r4, r8
	strh r1, [r4, #0x3e]
	ldr r2, _0819ABF4 @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0819ABFC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819ABF8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0819AC6A
	.align 2, 0
_0819ABF4: .4byte 0x0000048A
_0819ABF8: .4byte 0x03002BE0
_0819ABFC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0819AC18
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0819AC14 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0819AC6A
	.align 2, 0
_0819AC14: .4byte 0x03002BE0
_0819AC18:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0819AC34
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0819AC30 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0819AC6A
	.align 2, 0
_0819AC30: .4byte 0x03002BE0
_0819AC34:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0819AC50
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819AC4C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0819AC6A
	.align 2, 0
_0819AC4C: .4byte 0x03002BE0
_0819AC50:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0819AC62
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0819AC6A
_0819AC62:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0819AC6C
_0819AC6A:
	movs r3, #1
_0819AC6C:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r7, _0819ACA0 @ =0x0000049C
	adds r0, r6, r7
	str r1, [r0]
	cmp r3, #0
	bne _0819AC8C
	b _0819ADE0
_0819AC8C:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819ACA4
	movs r0, #1
	b _0819ACA6
	.align 2, 0
_0819ACA0: .4byte 0x0000049C
_0819ACA4:
	movs r0, #0
_0819ACA6:
	cmp r0, #0
	bne _0819AD86
	b _0819AD9C
_0819ACAC:
	mov r0, r8
	strh r2, [r0, #0x3e]
	ldr r1, _0819ACD4 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0819ACDC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819ACD8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0819AD4A
	.align 2, 0
_0819ACD4: .4byte 0x0000048A
_0819ACD8: .4byte 0x03002BE0
_0819ACDC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0819ACF8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0819ACF4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0819AD4A
	.align 2, 0
_0819ACF4: .4byte 0x03002BE0
_0819ACF8:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0819AD14
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0819AD10 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0819AD4A
	.align 2, 0
_0819AD10: .4byte 0x03002BE0
_0819AD14:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0819AD30
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819AD2C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0819AD4A
	.align 2, 0
_0819AD2C: .4byte 0x03002BE0
_0819AD30:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0819AD42
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0819AD4A
_0819AD42:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0819AD4C
_0819AD4A:
	movs r3, #1
_0819AD4C:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r7, _0819AD7C @ =0x0000049C
	adds r0, r6, r7
	str r1, [r0]
	cmp r3, #0
	beq _0819ADE0
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819AD80
	movs r0, #1
	b _0819AD82
	.align 2, 0
_0819AD7C: .4byte 0x0000049C
_0819AD80:
	movs r0, #0
_0819AD82:
	cmp r0, #0
	beq _0819AD9C
_0819AD86:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819AD98 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0819ADA8
	.align 2, 0
_0819AD98: .4byte 0x03002BE0
_0819AD9C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0819ADE0
_0819ADA8:
	ldr r1, [r0]
	movs r7, #8
	ldrsh r5, [r1, r7]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r7, #0xc
	ldrsh r0, [r6, r7]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0819ADE0:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0819AE0C
	ldr r7, _0819AE18 @ =0x0000024E
	adds r2, r6, r7
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0819AE0C
	strh r1, [r2]
_0819AE0C:
	ldr r7, _0819AE1C @ =0x0000048C
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
	b _0819B14E
	.align 2, 0
_0819AE18: .4byte 0x0000024E
_0819AE1C: .4byte 0x0000048C
_0819AE20:
	ldr r0, _0819AE34 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0819AE38
	movs r0, #1
	b _0819AE3A
	.align 2, 0
_0819AE34: .4byte 0x030047A4
_0819AE38:
	movs r0, #0
_0819AE3A:
	cmp r0, #0
	beq _0819AE48
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236640
	b _0819AE50
_0819AE48:
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236524
_0819AE50:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0819AE88 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0819AE8C @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0xc]
	cmp r0, #2
	bls _0819AE7E
	cmp r2, #0x17
	bne _0819AE90
_0819AE7E:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _0819AEB0
	.align 2, 0
_0819AE88: .4byte 0x0000048C
_0819AE8C: .4byte 0x000001DF
_0819AE90:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0819AE7E
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _0819AEE0 @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0819AEB0
	movs r1, #0
_0819AEB0:
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0819AEEE
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0
	blt _0819AEE4
	asrs r0, r0, #1
	b _0819AEEA
	.align 2, 0
_0819AEE0: .4byte 0x00000187
_0819AEE4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0819AEEA:
	mov r3, sb
	strh r0, [r3]
_0819AEEE:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0819AF0C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _0819AF08 @ =0x000001DD
	adds r1, r6, r4
	b _0819AF80
	.align 2, 0
_0819AF08: .4byte 0x000001DD
_0819AF0C:
	mov r4, sp
	adds r3, r7, #0
	adds r3, #0xc
	mov r2, r8
	adds r2, #0xc
	mov r1, r8
	ldrh r0, [r1, #0xc]
	ldrh r1, [r7, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _0819AF6C
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0819AF6C
	ldr r2, _0819AF5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0819AF60 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0819AF64 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0819AF68 @ =0x000001DD
	adds r1, r6, r4
	b _0819AF80
	.align 2, 0
_0819AF5C: .4byte 0x030046B8
_0819AF60: .4byte 0x000003FF
_0819AF64: .4byte 0x0203B400
_0819AF68: .4byte 0x000001DD
_0819AF6C:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _0819AFA0 @ =0x000001DD
	adds r1, r6, r3
_0819AF80:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0819AFA8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0819AFA4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0819B016
	.align 2, 0
_0819AFA0: .4byte 0x000001DD
_0819AFA4: .4byte 0x03002BE0
_0819AFA8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0819AFC4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0819AFC0 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0819B016
	.align 2, 0
_0819AFC0: .4byte 0x03002BE0
_0819AFC4:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0819AFE0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819AFDC @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0819B016
	.align 2, 0
_0819AFDC: .4byte 0x03002BE0
_0819AFE0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0819AFFC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0819AFF8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0819B016
	.align 2, 0
_0819AFF8: .4byte 0x03002BE0
_0819AFFC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0819B00E
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0819B016
_0819B00E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0819B018
_0819B016:
	movs r3, #1
_0819B018:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _0819B048 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _0819B0B0
	movs r1, #2
	ldr r2, _0819B04C @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819B050
	movs r0, #1
	b _0819B052
	.align 2, 0
_0819B048: .4byte 0x0000049C
_0819B04C: .4byte 0x00000474
_0819B050:
	movs r0, #0
_0819B052:
	cmp r0, #0
	beq _0819B06C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0819B068 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0819B078
	.align 2, 0
_0819B068: .4byte 0x03002BE0
_0819B06C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0819B0B0
_0819B078:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_0819B0B0:
	ldr r4, [sp, #0xc]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0819B0E4
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0819B0E4
	ldr r3, _0819B0FC @ =0x0000024E
	adds r2, r6, r3
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	subs r3, #2
	adds r1, r6, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0819B0E4
	strh r1, [r2]
_0819B0E4:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0819B100 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0819B104 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819B108
	movs r0, #1
	b _0819B10A
	.align 2, 0
_0819B0FC: .4byte 0x0000024E
_0819B100: .4byte 0x030046A0
_0819B104: .4byte 0x00000934
_0819B108:
	movs r0, #0
_0819B10A:
	ldr r1, _0819B20C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0819B124
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #0xc]
	strb r0, [r1]
_0819B124:
	adds r0, r6, #0
	bl FUN_080e64e4
	mov r2, r8
	ldrh r0, [r2, #0x3e]
	strh r0, [r4]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r7, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r7, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0819B14E:
	movs r7, #0x8e
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r0, [r2]
	cmp r0, #0
	bne _0819B17A
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	movs r3, #0x8b
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	mov r0, r8
	adds r0, #0x43
	ldrb r1, [r0]
	ldr r4, _0819B210 @ =0x0000048C
	adds r0, r6, r4
	strb r1, [r0]
	mov r0, r8
	adds r0, #0x44
	ldrh r0, [r0]
	strh r0, [r2]
_0819B17A:
	ldr r7, [sp, #8]
	ldr r1, _0819B214 @ =0x00000CBB
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0819B1FC
	ldr r2, _0819B218 @ =0x00000EAC
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #2
	bls _0819B1FC
	ldr r3, _0819B21C @ =FUN_0819bbd8
	mov sb, r3
	ldr r4, _0819B220 @ =0x0000046D
	adds r4, r6, r4
	str r4, [sp, #0x10]
	ldr r7, _0819B224 @ =0x0000046B
	adds r5, r6, r7
	ldr r0, _0819B228 @ =0x00000553
	adds r0, r0, r6
	mov r8, r0
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r1, r6
	mov ip, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r6, r6, r2
	movs r4, #4
	ldr r7, [sp, #8]
	ldr r0, _0819B22C @ =0x00000ABE
	adds r2, r7, r0
	movs r3, #2
	adds r0, #0xf0
	adds r1, r7, r0
_0819B1C4:
	ldrh r0, [r2]
	orrs r0, r4
	strh r0, [r2]
	ldrh r0, [r1]
	orrs r0, r4
	strh r0, [r1]
	adds r2, #0x50
	adds r1, #0x50
	subs r3, #1
	cmp r3, #0
	bge _0819B1C4
	movs r2, #0
	movs r1, #0x2e
	movs r0, #1
	ldr r3, [sp, #0x10]
	strb r0, [r3]
	strb r2, [r5]
	mov r4, r8
	strb r1, [r4]
	mov r7, sb
	mov r0, ip
	str r7, [r0]
	movs r1, #0
	strh r2, [r6]
	ldr r2, [sp, #8]
	ldr r3, _0819B218 @ =0x00000EAC
	adds r0, r2, r3
	strb r1, [r0]
_0819B1FC:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819B20C: .4byte 0x0000048A
_0819B210: .4byte 0x0000048C
_0819B214: .4byte 0x00000CBB
_0819B218: .4byte 0x00000EAC
_0819B21C: .4byte FUN_0819bbd8
_0819B220: .4byte 0x0000046D
_0819B224: .4byte 0x0000046B
_0819B228: .4byte 0x00000553
_0819B22C: .4byte 0x00000ABE

	thumb_func_start FUN_0819b230
FUN_0819b230: @ 0x0819B230
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0819B250 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819B254
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819B256
	.align 2, 0
_0819B250: .4byte 0x0000046D
_0819B254:
	movs r0, #0
_0819B256:
	cmp r0, #0
	beq _0819B29E
	ldr r0, _0819B32C @ =0x00000ECE
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0819B330 @ =0x00000C98
	adds r2, r4, r1
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0819B334 @ =0xFFFFFF00
	adds r0, r1, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	movs r3, #0
	strh r0, [r2]
	ldr r0, _0819B338 @ =0x00000A4C
	adds r2, r4, r0
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0819B33C @ =0x00000A5C
	adds r0, r4, r1
	strb r3, [r0]
	ldr r2, _0819B340 @ =0x00000E41
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r2, #0x6a
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _0819B344 @ =0x00000CBB
	adds r0, r4, r1
	strb r3, [r0]
_0819B29E:
	ldr r2, _0819B338 @ =0x00000A4C
	adds r5, r4, r2
	ldr r1, _0819B33C @ =0x00000A5C
	adds r0, r4, r1
	ldrb r2, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0819f150
	adds r0, r6, #0
	bl FUN_0819fdf0
	mov r3, sp
	ldr r0, _0819B330 @ =0x00000C98
	adds r2, r4, r0
	ldrh r0, [r2]
	ldrh r1, [r5]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, _0819B348 @ =0x00000EAB
	adds r4, r4, r2
	ldrb r1, [r4]
	bl Div
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0819B324
	ldr r3, _0819B34C @ =FUN_0819b35c
	movs r2, #0x2a
	ldr r0, _0819B350 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0819B354 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0819B358 @ =0x00000553
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
_0819B324:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819B32C: .4byte 0x00000ECE
_0819B330: .4byte 0x00000C98
_0819B334: .4byte 0xFFFFFF00
_0819B338: .4byte 0x00000A4C
_0819B33C: .4byte 0x00000A5C
_0819B340: .4byte 0x00000E41
_0819B344: .4byte 0x00000CBB
_0819B348: .4byte 0x00000EAB
_0819B34C: .4byte FUN_0819b35c
_0819B350: .4byte 0x0000046D
_0819B354: .4byte 0x0000046B
_0819B358: .4byte 0x00000553

	thumb_func_start FUN_0819b35c
FUN_0819b35c: @ 0x0819B35C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, _0819B380 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819B384
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819B386
	.align 2, 0
_0819B380: .4byte 0x0000046D
_0819B384:
	movs r0, #0
_0819B386:
	cmp r0, #0
	beq _0819B3CC
	adds r0, r5, #0
	bl FUN_0819f990
	ldr r0, _0819B41C @ =0x00000C98
	adds r1, r6, r0
	adds r0, r5, #0
	bl FUN_0819fcf0
	ldr r0, _0819B420 @ =0x0000093E
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0819B424 @ =0x00000CBC
	adds r0, r6, r1
	bl FUN_08013698
	ldr r0, _0819B428 @ =0x000008BC
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xf7
	bl FUN_0819fd0c
	ldr r0, _0819B42C @ =0x0000016F
	bl PlaySound_082406e0
_0819B3CC:
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_0819f934
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819B444
	ldr r4, _0819B430 @ =FUN_0819b478
	movs r3, #0x2b
	ldr r0, _0819B434 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819B438 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r0, _0819B43C @ =0x0000093C
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xfa
	bl FUN_0819fd0c
	ldr r0, _0819B440 @ =0x0000016D
	bl PlaySound_082406e0
	b _0819B46C
	.align 2, 0
_0819B41C: .4byte 0x00000C98
_0819B420: .4byte 0x0000093E
_0819B424: .4byte 0x00000CBC
_0819B428: .4byte 0x000008BC
_0819B42C: .4byte 0x0000016F
_0819B430: .4byte FUN_0819b478
_0819B434: .4byte 0x0000046D
_0819B438: .4byte 0x0000046B
_0819B43C: .4byte 0x0000093C
_0819B440: .4byte 0x0000016D
_0819B444:
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0819B460
	ldr r0, _0819B45C @ =0x000008BC
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xf7
	bl FUN_0819fd0c
	b _0819B46C
	.align 2, 0
_0819B45C: .4byte 0x000008BC
_0819B460:
	ldr r0, _0819B474 @ =0x0000093C
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xfa
	bl FUN_0819fd0c
_0819B46C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819B474: .4byte 0x0000093C

	thumb_func_start FUN_0819b478
FUN_0819b478: @ 0x0819B478
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	ldr r2, _0819B4A4 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819B4A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819B4AA
	.align 2, 0
_0819B4A4: .4byte 0x0000046D
_0819B4A8:
	movs r0, #0
_0819B4AA:
	cmp r0, #0
	beq _0819B56E
	ldr r3, _0819B51C @ =0x00000CBB
	adds r2, r6, r3
	ldrb r1, [r2]
	movs r0, #2
	movs r3, #0
	orrs r0, r1
	strb r0, [r2]
	ldr r4, _0819B520 @ =0x00000CB9
	adds r0, r6, r4
	strb r3, [r0]
	movs r5, #0xcb
	lsls r5, r5, #4
	adds r1, r6, r5
	movs r0, #0x80
	strh r0, [r1]
	ldr r0, _0819B524 @ =0x00000CB4
	adds r1, r6, r0
	movs r0, #4
	strb r0, [r1]
	ldr r2, _0819B528 @ =0x00000CB5
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0819B52C @ =0x00000CA8
	adds r2, r6, r3
	subs r4, #0x21
	adds r0, r6, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	mov r4, sp
	adds r3, r7, #0
	adds r3, #8
	ldrh r0, [r7, #8]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _0819B530
	asrs r1, r0, #1
	b _0819B536
	.align 2, 0
_0819B51C: .4byte 0x00000CBB
_0819B520: .4byte 0x00000CB9
_0819B524: .4byte 0x00000CB4
_0819B528: .4byte 0x00000CB5
_0819B52C: .4byte 0x00000CA8
_0819B530:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0819B536:
	mov r0, sp
	strh r1, [r0]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0819B546
	asrs r0, r0, #1
	b _0819B54C
_0819B546:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0819B54C:
	mov r3, sp
	strh r0, [r3, #4]
	ldr r4, _0819B598 @ =0x00000CA8
	adds r2, r6, r4
	mov r1, sp
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
_0819B56E:
	ldr r2, _0819B59C @ =0x085B0A08
	ldr r5, _0819B5A0 @ =0x00000CB9
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0xcb
	lsls r4, r4, #4
	adds r0, r6, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819B5A4
	asrs r1, r0, #0xc
	b _0819B5AA
	.align 2, 0
_0819B598: .4byte 0x00000CA8
_0819B59C: .4byte 0x085B0A08
_0819B5A0: .4byte 0x00000CB9
_0819B5A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819B5AA:
	ldr r3, _0819B5D4 @ =0x00000CA8
	adds r0, r6, r3
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r7, #8]
	ldr r4, _0819B5D8 @ =0x00000CB9
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	adds r3, #8
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819B5DC
	asrs r1, r0, #0xc
	b _0819B5E2
	.align 2, 0
_0819B5D4: .4byte 0x00000CA8
_0819B5D8: .4byte 0x00000CB9
_0819B5DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819B5E2:
	ldr r5, _0819B618 @ =0x00000CAC
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r7, #0xc]
	ldr r1, _0819B61C @ =0x00000CB9
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r4, #0xcb
	lsls r4, r4, #4
	adds r0, r6, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819B620
	asrs r1, r0, #0xc
	b _0819B626
	.align 2, 0
_0819B618: .4byte 0x00000CAC
_0819B61C: .4byte 0x00000CB9
_0819B620:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819B626:
	ldr r3, _0819B65C @ =0x00000CA8
	adds r0, r6, r3
	ldrh r0, [r0]
	adds r0, r0, r1
	ldr r4, _0819B660 @ =0x00000A7C
	adds r1, r6, r4
	strh r0, [r1]
	ldr r5, _0819B664 @ =0x00000CB9
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r3, #8
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819B668
	asrs r1, r0, #0xc
	b _0819B66E
	.align 2, 0
_0819B65C: .4byte 0x00000CA8
_0819B660: .4byte 0x00000A7C
_0819B664: .4byte 0x00000CB9
_0819B668:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819B66E:
	ldr r5, _0819B698 @ =0x00000CAC
	adds r0, r6, r5
	ldrh r0, [r0]
	adds r0, r0, r1
	movs r2, #0xa8
	lsls r2, r2, #4
	adds r1, r6, r2
	strh r0, [r1]
	mov r3, r8
	cmp r3, #0x3b
	bgt _0819B6A4
	ldr r4, _0819B69C @ =0x00000CB4
	adds r1, r6, r4
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	ldr r5, _0819B6A0 @ =0x00000EAC
	adds r1, r6, r5
	movs r0, #0
	strb r0, [r1]
	b _0819B976
	.align 2, 0
_0819B698: .4byte 0x00000CAC
_0819B69C: .4byte 0x00000CB4
_0819B6A0: .4byte 0x00000EAC
_0819B6A4:
	mov r0, r8
	cmp r0, #0xb3
	bgt _0819B748
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0819B6DE
	ldr r2, _0819B724 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0819B728 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0819B72C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	bgt _0819B6DE
	ldr r2, _0819B730 @ =0x00000CB5
	adds r0, r6, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	rsbs r1, r1, #0
	strb r1, [r0]
	ldr r0, _0819B734 @ =0x00000169
	bl PlaySound_082406e0
_0819B6DE:
	ldr r0, _0819B738 @ =0x03002BE0
	mov r3, sp
	ldr r4, _0819B73C @ =0x00000CA8
	adds r2, r6, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrh r1, [r0, #0x2c]
	ldrh r0, [r2]
	subs r1, r1, r0
	movs r5, #0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl FUN_0823785c
	ldr r3, _0819B740 @ =0x00000CB6
	adds r1, r6, r3
	strb r0, [r1]
	ldr r4, _0819B744 @ =0x00000EAC
	adds r0, r6, r4
	strb r5, [r0]
	b _0819B976
	.align 2, 0
_0819B724: .4byte 0x030046B8
_0819B728: .4byte 0x000003FF
_0819B72C: .4byte 0x0203B400
_0819B730: .4byte 0x00000CB5
_0819B734: .4byte 0x00000169
_0819B738: .4byte 0x03002BE0
_0819B73C: .4byte 0x00000CA8
_0819B740: .4byte 0x00000CB6
_0819B744: .4byte 0x00000EAC
_0819B748:
	ldr r5, _0819B788 @ =0x00000CBB
	adds r3, r6, r5
	ldrb r1, [r3]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0819B7AA
	movs r0, #0xcb
	lsls r0, r0, #4
	adds r2, r6, r0
	ldrh r4, [r2]
	movs r5, #0
	ldrsh r1, [r2, r5]
	ldr r0, _0819B78C @ =0x000001FF
	cmp r1, r0
	bgt _0819B794
	adds r0, r4, #0
	adds r0, #8
	strh r0, [r2]
	ldr r0, _0819B790 @ =0x00000CB4
	adds r1, r6, r0
	ldrb r0, [r1]
	subs r0, #4
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bhi _0819B7AA
	movs r0, #0x10
	strb r0, [r1]
	b _0819B7AA
	.align 2, 0
_0819B788: .4byte 0x00000CBB
_0819B78C: .4byte 0x000001FF
_0819B790: .4byte 0x00000CB4
_0819B794:
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r2]
	ldr r2, _0819B7F4 @ =0x00000CB4
	adds r1, r6, r2
	movs r0, #0x10
	strb r0, [r1]
	ldrb r0, [r3]
	movs r1, #4
	orrs r0, r1
	strb r0, [r3]
_0819B7AA:
	ldr r0, _0819B7F8 @ =0x03002BE0
	mov r3, sp
	ldr r4, _0819B7FC @ =0x00000CA8
	adds r2, r6, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl FUN_0823785c
	ldr r3, _0819B800 @ =0x00000CB6
	adds r1, r6, r3
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819B808
	ldr r4, _0819B804 @ =0xFFFFFF00
	adds r1, r1, r4
	b _0819B816
	.align 2, 0
_0819B7F4: .4byte 0x00000CB4
_0819B7F8: .4byte 0x03002BE0
_0819B7FC: .4byte 0x00000CA8
_0819B800: .4byte 0x00000CB6
_0819B804: .4byte 0xFFFFFF00
_0819B808:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819B816
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_0819B816:
	adds r0, r1, #0
	cmp r1, #0
	bge _0819B81E
	rsbs r0, r1, #0
_0819B81E:
	cmp r0, #0x14
	ble _0819B83E
	cmp r1, #0
	ble _0819B834
	ldr r0, _0819B830 @ =0x00000CB6
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #4
	b _0819B83C
	.align 2, 0
_0819B830: .4byte 0x00000CB6
_0819B834:
	ldr r2, _0819B860 @ =0x00000CB6
	adds r1, r6, r2
	ldrb r0, [r1]
	subs r0, #4
_0819B83C:
	strb r0, [r1]
_0819B83E:
	ldr r2, _0819B864 @ =0x085B0A08
	ldr r3, _0819B860 @ =0x00000CB6
	adds r0, r6, r3
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #1
	cmp r0, #0
	blt _0819B868
	asrs r3, r0, #0xc
	b _0819B86E
	.align 2, 0
_0819B860: .4byte 0x00000CB6
_0819B864: .4byte 0x085B0A08
_0819B868:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0819B86E:
	ldr r5, _0819B890 @ =0x00000CA8
	adds r1, r6, r5
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r1, _0819B894 @ =0x00000CB6
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	cmp r0, #0
	blt _0819B898
	asrs r2, r0, #0xc
	b _0819B89E
	.align 2, 0
_0819B890: .4byte 0x00000CA8
_0819B894: .4byte 0x00000CB6
_0819B898:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0819B89E:
	ldr r3, _0819B908 @ =0x00000CAC
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r5, _0819B90C @ =0x00000CBB
	adds r4, r6, r5
	ldrb r1, [r4]
	movs r5, #4
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0819B976
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r3, #2
	orrs r0, r3
	str r0, [r2]
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldrb r3, [r2, #6]
	subs r0, r3, #6
	strb r0, [r2, #6]
	ldr r2, _0819B910 @ =0x00000A66
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #6
	strb r0, [r1]
	ldr r0, [r7, #0x44]
	ldrb r0, [r0, #6]
	cmp r3, r0
	bge _0819B8EC
	ldr r0, _0819B914 @ =0x00000169
	bl PlaySound_082406e0
_0819B8EC:
	ldrb r1, [r4]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0819B976
	ldr r0, _0819B918 @ =0x000001DF
	cmp r8, r0
	bgt _0819B91C
	movs r3, #0xcb
	lsls r3, r3, #4
	adds r1, r6, r3
	ldrh r0, [r1]
	subs r0, #1
	b _0819B974
	.align 2, 0
_0819B908: .4byte 0x00000CAC
_0819B90C: .4byte 0x00000CBB
_0819B910: .4byte 0x00000A66
_0819B914: .4byte 0x00000169
_0819B918: .4byte 0x000001DF
_0819B91C:
	ldr r0, _0819B930 @ =0x00000243
	cmp r8, r0
	bgt _0819B934
	movs r4, #0xcb
	lsls r4, r4, #4
	adds r1, r6, r4
	ldrh r0, [r1]
	adds r0, #6
	b _0819B974
	.align 2, 0
_0819B930: .4byte 0x00000243
_0819B934:
	ldr r0, _0819B948 @ =0x00000293
	cmp r8, r0
	bgt _0819B94C
	movs r5, #0xcb
	lsls r5, r5, #4
	adds r1, r6, r5
	ldrh r0, [r1]
	subs r0, #4
	b _0819B974
	.align 2, 0
_0819B948: .4byte 0x00000293
_0819B94C:
	ldr r0, _0819B960 @ =0x000002E3
	cmp r8, r0
	bgt _0819B964
	movs r0, #0xcb
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #4
	b _0819B974
	.align 2, 0
_0819B960: .4byte 0x000002E3
_0819B964:
	ldr r0, _0819B990 @ =0x00000333
	cmp r8, r0
	ble _0819B976
	movs r2, #0xcb
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrh r0, [r1]
	subs r0, #6
_0819B974:
	strh r0, [r1]
_0819B976:
	ldr r3, _0819B994 @ =0x00000CB4
	adds r0, r6, r3
	ldrb r1, [r0]
	ldr r4, _0819B998 @ =0x00000CB5
	adds r0, r6, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r1, r0
	cmp r0, #0
	blt _0819B99C
	asrs r2, r0, #4
	b _0819B9A2
	.align 2, 0
_0819B990: .4byte 0x00000333
_0819B994: .4byte 0x00000CB4
_0819B998: .4byte 0x00000CB5
_0819B99C:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r2, r0, #0
_0819B9A2:
	ldr r5, _0819B9EC @ =0x00000CB9
	adds r1, r6, r5
	ldrb r0, [r1]
	adds r0, r0, r2
	movs r4, #0
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0819fc5c
	ldr r1, _0819B9F0 @ =0x00000CBB
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0819BA00
	ldr r2, _0819B9F4 @ =FUN_0819baa0
	movs r1, #0x2d
	ldr r5, _0819B9F8 @ =0x0000046D
	adds r0, r7, r5
	strb r3, [r0]
	ldr r3, _0819B9FC @ =0x0000046B
	adds r0, r7, r3
	strb r4, [r0]
	adds r5, #0xe6
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	b _0819BA7C
	.align 2, 0
_0819B9EC: .4byte 0x00000CB9
_0819B9F0: .4byte 0x00000CBB
_0819B9F4: .4byte FUN_0819baa0
_0819B9F8: .4byte 0x0000046D
_0819B9FC: .4byte 0x0000046B
_0819BA00:
	movs r0, #0xfa
	lsls r0, r0, #2
	cmp r8, r0
	ble _0819BA7C
	movs r3, #0x94
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r7, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	ldr r4, _0819BA8C @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	ldr r5, _0819BA90 @ =0x0000046B
	adds r5, r5, r7
	mov r8, r5
	ldr r0, _0819BA94 @ =0x00000553
	adds r3, r7, r0
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r1, r7
	mov ip, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r7, r7, r2
	ldr r4, _0819BA98 @ =FUN_0819bbd8
	mov sl, r4
	movs r5, #4
	ldr r0, _0819BA9C @ =0x00000ABE
	adds r2, r6, r0
	movs r4, #2
	adds r0, #0xf0
	adds r1, r6, r0
_0819BA4E:
	ldrh r0, [r2]
	orrs r0, r5
	strh r0, [r2]
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	adds r2, #0x50
	adds r1, #0x50
	subs r4, #1
	cmp r4, #0
	bge _0819BA4E
	movs r2, #0
	movs r1, #0x2e
	movs r0, #1
	mov r4, sb
	strb r0, [r4]
	mov r5, r8
	strb r2, [r5]
	strb r1, [r3]
	mov r0, sl
	mov r1, ip
	str r0, [r1]
	strh r2, [r7]
_0819BA7C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819BA8C: .4byte 0x0000046D
_0819BA90: .4byte 0x0000046B
_0819BA94: .4byte 0x00000553
_0819BA98: .4byte FUN_0819bbd8
_0819BA9C: .4byte 0x00000ABE

	thumb_func_start FUN_0819baa0
FUN_0819baa0: @ 0x0819BAA0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _0819BAC0 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BAC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BAC6
	.align 2, 0
_0819BAC0: .4byte 0x0000046D
_0819BAC4:
	movs r0, #0
_0819BAC6:
	cmp r0, #0
	beq _0819BB16
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r4, r5, r0
	ldr r0, [r4]
	movs r1, #2
	orrs r0, r1
	str r0, [r4]
	ldr r1, _0819BBA8 @ =0x00000CBB
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0819BBAC @ =0x00000A5D
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0819BBB0 @ =0x00000A4C
	adds r2, r5, r0
	ldr r1, _0819BBB4 @ =0x00000A7C
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0819BBB8 @ =0x00000CB8
	adds r0, r5, r2
	ldrb r1, [r0]
	ldr r2, _0819BBBC @ =0x00000A5C
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0819BBC0 @ =0x00000A5E
	adds r1, r5, r0
	movs r0, #4
	strb r0, [r1]
	ldr r1, _0819BBC4 @ =0x00000CBC
	adds r0, r5, r1
	bl FUN_080136b4
	movs r0, #1
	str r0, [r4]
_0819BB16:
	ldr r2, _0819BBBC @ =0x00000A5C
	adds r0, r5, r2
	ldrb r2, [r0]
	ldr r1, _0819BBC0 @ =0x00000A5E
	adds r4, r5, r1
	ldrb r1, [r4]
	subs r1, r2, r1
	strb r1, [r0]
	cmp r2, r1
	bge _0819BB30
	ldr r0, _0819BBC8 @ =0x00000169
	bl PlaySound_082406e0
_0819BB30:
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	beq _0819BB42
	ldrb r0, [r4]
	cmp r0, #0x13
	bhi _0819BB42
	adds r0, #1
	strb r0, [r4]
_0819BB42:
	ldr r2, _0819BBB0 @ =0x00000A4C
	adds r1, r5, r2
	ldr r4, _0819BBBC @ =0x00000A5C
	adds r0, r5, r4
	ldrb r2, [r0]
	adds r0, r6, #0
	bl FUN_0819f150
	adds r0, r6, #0
	bl FUN_0819fdf0
	adds r0, r6, #0
	bl FUN_0819fc5c
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _0819BBA0
	cmp r7, #0x1e
	ble _0819BBA0
	adds r0, r6, #0
	bl FUN_0819fca4
	ldr r3, _0819BBCC @ =FUN_0819cc04
	movs r2, #0x33
	ldr r1, _0819BBD0 @ =0x0000046D
	adds r0, r6, r1
	movs r1, #0
	strb r4, [r0]
	ldr r4, _0819BBD4 @ =0x0000046B
	adds r0, r6, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
_0819BBA0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819BBA8: .4byte 0x00000CBB
_0819BBAC: .4byte 0x00000A5D
_0819BBB0: .4byte 0x00000A4C
_0819BBB4: .4byte 0x00000A7C
_0819BBB8: .4byte 0x00000CB8
_0819BBBC: .4byte 0x00000A5C
_0819BBC0: .4byte 0x00000A5E
_0819BBC4: .4byte 0x00000CBC
_0819BBC8: .4byte 0x00000169
_0819BBCC: .4byte FUN_0819cc04
_0819BBD0: .4byte 0x0000046D
_0819BBD4: .4byte 0x0000046B

	thumb_func_start FUN_0819bbd8
FUN_0819bbd8: @ 0x0819BBD8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r0, _0819BBFC @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BC00
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BC02
	.align 2, 0
_0819BBFC: .4byte 0x0000046D
_0819BC00:
	movs r0, #0
_0819BC02:
	cmp r0, #0
	beq _0819BC1A
	ldr r1, _0819BC58 @ =0x00000CBB
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0819BC5C @ =0x0000093C
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xfa
	bl FUN_0819fd0c
_0819BC1A:
	mov r0, sp
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_0819f8d8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819BC6C
	ldr r4, _0819BC60 @ =FUN_0819bca0
	movs r3, #0x2f
	ldr r0, _0819BC64 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819BC68 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	b _0819BC76
	.align 2, 0
_0819BC58: .4byte 0x00000CBB
_0819BC5C: .4byte 0x0000093C
_0819BC60: .4byte FUN_0819bca0
_0819BC64: .4byte 0x0000046D
_0819BC68: .4byte 0x0000046B
_0819BC6C:
	ldr r0, [sp]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0819BC88
_0819BC76:
	ldr r0, _0819BC84 @ =0x000008BC
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xf7
	bl FUN_0819fd0c
	b _0819BC94
	.align 2, 0
_0819BC84: .4byte 0x000008BC
_0819BC88:
	ldr r0, _0819BC9C @ =0x0000093C
	adds r1, r6, r0
	adds r0, r5, #0
	movs r2, #0xfa
	bl FUN_0819fd0c
_0819BC94:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819BC9C: .4byte 0x0000093C

	thumb_func_start FUN_0819bca0
FUN_0819bca0: @ 0x0819BCA0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r0, _0819BCC0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BCC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BCC6
	.align 2, 0
_0819BCC0: .4byte 0x0000046D
_0819BCC4:
	movs r0, #0
_0819BCC6:
	cmp r0, #0
	beq _0819BCD2
	ldr r0, _0819BD1C @ =0x00000CBB
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
_0819BCD2:
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r0, r2, r1
	adds r1, r3, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819BD16
	adds r0, r5, #0
	bl FUN_0819fca4
	ldr r4, _0819BD20 @ =FUN_0819cc04
	movs r3, #0x33
	ldr r0, _0819BD24 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819BD28 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0819BD16:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819BD1C: .4byte 0x00000CBB
_0819BD20: .4byte FUN_0819cc04
_0819BD24: .4byte 0x0000046D
_0819BD28: .4byte 0x0000046B

	thumb_func_start FUN_0819bd2c
FUN_0819bd2c: @ 0x0819BD2C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0819BD4C @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BD50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BD52
	.align 2, 0
_0819BD4C: .4byte 0x0000046D
_0819BD50:
	movs r0, #0
_0819BD52:
	cmp r0, #0
	beq _0819BD72
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	movs r2, #4
	ldr r0, _0819BD84 @ =0x00000E48
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0819BD88 @ =0x0000016B
	bl PlaySound_082406e0
_0819BD72:
	ldr r2, [r5, #0x44]
	ldrb r0, [r2, #8]
	movs r1, #8
	ldrsb r1, [r2, r1]
	cmp r1, #0x20
	ble _0819BD8C
	subs r0, #4
	strb r0, [r2, #8]
	b _0819BE04
	.align 2, 0
_0819BD84: .4byte 0x00000E48
_0819BD88: .4byte 0x0000016B
_0819BD8C:
	cmp r1, #8
	ble _0819BDA8
	subs r0, #2
	strb r0, [r2, #8]
	ldr r1, [r5, #0x44]
	ldrb r0, [r1, #9]
	adds r0, #4
	strb r0, [r1, #9]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_080136b4
	b _0819BE04
_0819BDA8:
	ldrb r1, [r2, #9]
	movs r0, #9
	ldrsb r0, [r2, r0]
	cmp r0, #0x77
	bgt _0819BDC4
	adds r0, r1, #0
	adds r0, #8
	strb r0, [r2, #9]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r5, r2
	bl FUN_080136b4
	b _0819BE04
_0819BDC4:
	movs r1, #1
	str r1, [r2]
	ldr r4, _0819BE0C @ =FUN_0819be1c
	movs r3, #0x23
	ldr r2, _0819BE10 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0819BE14 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r5, r2
	bl FUN_080136b4
	movs r2, #0x40
	ldr r0, _0819BE18 @ =0x00000E48
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0819BE04:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819BE0C: .4byte FUN_0819be1c
_0819BE10: .4byte 0x0000046D
_0819BE14: .4byte 0x0000046B
_0819BE18: .4byte 0x00000E48

	thumb_func_start FUN_0819be1c
FUN_0819be1c: @ 0x0819BE1C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _0819BE3C @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BE40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BE42
	.align 2, 0
_0819BE3C: .4byte 0x0000046D
_0819BE40:
	movs r0, #0
_0819BE42:
	cmp r0, #0
	beq _0819BE6A
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r5, #0x94
	lsls r5, r5, #1
	adds r2, r4, r5
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r4, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
_0819BE6A:
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	movs r5, #1
	orrs r0, r5
	str r0, [r1]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080136b4
	movs r2, #0xe4
	lsls r2, r2, #4
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r7, r0
	ble _0819BEC6
	adds r1, r4, #0
	adds r1, #8
	ldr r0, _0819BECC @ =0x03002BE0
	ldr r2, [r0]
	adds r2, #0x2c
	movs r3, #0x80
	lsls r3, r3, #0xb
	adds r0, r4, #0
	bl FUN_0819f3fc
	ldr r3, _0819BED0 @ =FUN_0819bedc
	movs r2, #0x24
	ldr r1, _0819BED4 @ =0x0000046D
	adds r0, r4, r1
	movs r1, #0
	strb r5, [r0]
	ldr r5, _0819BED8 @ =0x0000046B
	adds r0, r4, r5
	strb r1, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r4, r5
	strh r1, [r0]
_0819BEC6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819BECC: .4byte 0x03002BE0
_0819BED0: .4byte FUN_0819bedc
_0819BED4: .4byte 0x0000046D
_0819BED8: .4byte 0x0000046B

	thumb_func_start FUN_0819bedc
FUN_0819bedc: @ 0x0819BEDC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r0, _0819BEFC @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BF00
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BF02
	.align 2, 0
_0819BEFC: .4byte 0x0000046D
_0819BF00:
	movs r0, #0
_0819BF02:
	cmp r0, #0
	beq _0819BF3C
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	subs r1, #4
	ands r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r2, #6]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r3, r4, r1
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	adds r2, r4, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	movs r0, #0xb6
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0819BF3C:
	ldr r2, [r4, #0x44]
	ldrb r0, [r2, #9]
	movs r1, #9
	ldrsb r1, [r2, r1]
	cmp r1, #0x70
	ble _0819BF4E
	subs r0, #8
	strb r0, [r2, #9]
	b _0819BF98
_0819BF4E:
	cmp r1, #0x40
	ble _0819BF6C
	ldrb r0, [r2, #8]
	adds r0, #2
	strb r0, [r2, #8]
	ldr r1, [r4, #0x44]
	ldrb r0, [r1, #9]
	subs r0, #4
	strb r0, [r1, #9]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013698
	b _0819BF98
_0819BF6C:
	ldrb r1, [r2, #8]
	movs r0, #8
	ldrsb r0, [r2, r0]
	cmp r0, #0x3f
	bgt _0819BF7C
	adds r0, r1, #4
	strb r0, [r2, #8]
	b _0819BF98
_0819BF7C:
	movs r1, #0x40
	strb r1, [r2, #8]
	ldr r0, [r4, #0x44]
	strb r1, [r0, #9]
	ldr r0, _0819BFA0 @ =0x00000E48
	adds r2, r5, r0
	subs r1, #0x85
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0819BFA4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0819BF98:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819BFA0: .4byte 0x00000E48
_0819BFA4: .4byte 0x0000046B

	thumb_func_start FUN_0819bfa8
FUN_0819bfa8: @ 0x0819BFA8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0819BFC0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BFC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BFC6
	.align 2, 0
_0819BFC0: .4byte 0x0000046D
_0819BFC4:
	movs r0, #0
_0819BFC6:
	cmp r0, #0
	beq _0819BFD4
	ldr r0, [r5, #0x44]
	ldr r1, [r0]
	movs r2, #2
	orrs r1, r2
	str r1, [r0]
_0819BFD4:
	adds r0, r5, #0
	bl FUN_0819ef24
	ldr r1, [r5, #0x44]
	ldrb r0, [r1, #6]
	cmp r0, #0x13
	bhi _0819BFE6
	adds r0, #1
	strb r0, [r1, #6]
_0819BFE6:
	cmp r4, #0x3c
	ble _0819C018
	ldr r1, [r5, #0x44]
	movs r3, #0
	movs r0, #0x14
	strb r0, [r1, #6]
	ldr r4, _0819C020 @ =FUN_0819c02c
	movs r2, #0x27
	ldr r0, _0819C024 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819C028 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
_0819C018:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819C020: .4byte FUN_0819c02c
_0819C024: .4byte 0x0000046D
_0819C028: .4byte 0x0000046B

	thumb_func_start FUN_0819c02c
FUN_0819c02c: @ 0x0819C02C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _0819C054 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C058
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C05A
	.align 2, 0
_0819C054: .4byte 0x0000046D
_0819C058:
	movs r0, #0
_0819C05A:
	cmp r0, #0
	beq _0819C0F4
	ldr r2, [r6, #0x44]
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r1, _0819C094 @ =0x00000A54
	adds r3, r7, r1
	ldrb r4, [r0]
	movs r5, #0xc
	ldr r2, _0819C098 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0819C09C
	asrs r1, r0, #0xc
	b _0819C0A2
	.align 2, 0
_0819C094: .4byte 0x00000A54
_0819C098: .4byte 0x085B0A08
_0819C09C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819C0A2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0819C0BC @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0819C0C0
	asrs r0, r0, #0xc
	b _0819C0C6
	.align 2, 0
_0819C0BC: .4byte 0x085B0A08
_0819C0C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819C0C6:
	strh r0, [r3, #4]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrb r1, [r0]
	ldr r3, _0819C1B0 @ =0x00000A5D
	adds r0, r7, r3
	strb r1, [r0]
	ldr r0, _0819C1B4 @ =0x00000A4C
	adds r2, r7, r0
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r6, #0x44]
	ldrb r1, [r0, #6]
	ldr r2, _0819C1B8 @ =0x00000A5C
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #1
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
_0819C0F4:
	ldr r0, [r6, #0x44]
	ldrb r4, [r0, #6]
	ldr r1, _0819C1BC @ =0x00000A5E
	adds r2, r7, r1
	ldrb r1, [r2]
	subs r1, r4, r1
	strb r1, [r0, #6]
	movs r0, #1
	mov r3, r8
	ands r0, r3
	cmp r0, #0
	beq _0819C116
	ldrb r0, [r2]
	cmp r0, #0xb
	bhi _0819C116
	adds r0, #1
	strb r0, [r2]
_0819C116:
	adds r0, r6, #0
	bl FUN_0819fdf0
	ldr r0, [r6, #0x44]
	ldrb r0, [r0, #6]
	cmp r4, r0
	bge _0819C12A
	ldr r0, _0819C1C0 @ =0x00000169
	bl PlaySound_082406e0
_0819C12A:
	mov r0, r8
	cmp r0, #0x77
	ble _0819C132
	b _0819C258
_0819C132:
	ldr r1, _0819C1B4 @ =0x00000A4C
	adds r4, r7, r1
	ldr r2, _0819C1B8 @ =0x00000A5C
	adds r5, r7, r2
	ldrb r2, [r5]
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0819f150
	ldr r3, _0819C1C4 @ =0x00000A54
	adds r1, r7, r3
	ldrh r0, [r4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r4]
	ldrh r0, [r4, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	ldr r0, _0819C1C8 @ =0x00000E3C
	adds r1, r7, r0
	ldrb r0, [r5]
	ldrb r1, [r1]
	subs r0, r0, r1
	strb r0, [r5]
	ldr r0, _0819C1CC @ =0x03002BE0
	mov r2, sp
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r4]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	ldr r2, _0819C1B0 @ =0x00000A5D
	adds r1, r7, r2
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819C1D4
	ldr r3, _0819C1D0 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0819C1E2
	.align 2, 0
_0819C1B0: .4byte 0x00000A5D
_0819C1B4: .4byte 0x00000A4C
_0819C1B8: .4byte 0x00000A5C
_0819C1BC: .4byte 0x00000A5E
_0819C1C0: .4byte 0x00000169
_0819C1C4: .4byte 0x00000A54
_0819C1C8: .4byte 0x00000E3C
_0819C1CC: .4byte 0x03002BE0
_0819C1D0: .4byte 0xFFFFFF00
_0819C1D4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C1E2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0819C1E2:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819C1EA
	rsbs r0, r0, #0
_0819C1EA:
	cmp r0, #0x20
	ble _0819C1F8
	ldr r2, _0819C224 @ =0x00000A5D
	adds r1, r7, r2
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_0819C1F8:
	ldr r3, _0819C224 @ =0x00000A5D
	adds r0, r7, r3
	ldr r2, _0819C228 @ =0x00000E3D
	adds r1, r7, r2
	subs r3, #9
	adds r4, r7, r3
	ldrb r3, [r0]
	ldrb r5, [r1]
	ldr r2, _0819C22C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _0819C230
	asrs r1, r0, #0xc
	b _0819C236
	.align 2, 0
_0819C224: .4byte 0x00000A5D
_0819C228: .4byte 0x00000E3D
_0819C22C: .4byte 0x085B0A08
_0819C230:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819C236:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0819C24E
	asrs r0, r0, #0xc
	b _0819C254
_0819C24E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819C254:
	strh r0, [r4, #4]
	b _0819C3B8
_0819C258:
	ldr r3, _0819C2C8 @ =0x00000A4C
	adds r4, r7, r3
	ldr r0, _0819C2CC @ =0x00000A5C
	adds r5, r7, r0
	ldrb r2, [r5]
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0819f150
	ldr r2, _0819C2D0 @ =0x00000A54
	adds r1, r7, r2
	ldrh r0, [r4]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r4, #2]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	ldrb r0, [r5]
	subs r0, #6
	strb r0, [r5]
	add r5, sp, #8
	adds r2, r6, #0
	adds r2, #8
	ldrh r0, [r6, #8]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r3, #0
	ldrsh r0, [r5, r3]
	movs r2, #4
	ldrsh r1, [r5, r2]
	bl FUN_0823785c
	ldr r3, _0819C2D4 @ =0x00000A5D
	adds r1, r7, r3
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819C2DC
	ldr r0, _0819C2D8 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0819C2EA
	.align 2, 0
_0819C2C8: .4byte 0x00000A4C
_0819C2CC: .4byte 0x00000A5C
_0819C2D0: .4byte 0x00000A54
_0819C2D4: .4byte 0x00000A5D
_0819C2D8: .4byte 0xFFFFFF00
_0819C2DC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C2EA
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0819C2EA:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819C2F2
	rsbs r0, r0, #0
_0819C2F2:
	cmp r0, #0xc
	ble _0819C300
	ldr r3, _0819C328 @ =0x00000A5D
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #6
	strb r0, [r1]
_0819C300:
	ldr r1, _0819C328 @ =0x00000A5D
	adds r0, r7, r1
	ldr r2, _0819C32C @ =0x00000A54
	adds r3, r7, r2
	ldrb r4, [r0]
	ldr r2, _0819C330 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _0819C334
	asrs r1, r0, #0xc
	b _0819C33A
	.align 2, 0
_0819C328: .4byte 0x00000A5D
_0819C32C: .4byte 0x00000A54
_0819C330: .4byte 0x085B0A08
_0819C334:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819C33A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _0819C354
	asrs r0, r0, #0xc
	b _0819C35A
_0819C354:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819C35A:
	strh r0, [r3, #4]
	add r0, sp, #8
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _0819C3C4 @ =0x000003FF
	cmp r1, r0
	ble _0819C380
	movs r0, #0x96
	lsls r0, r0, #2
	cmp r8, r0
	ble _0819C3B8
_0819C380:
	ldr r0, _0819C3C8 @ =0x00000A4C
	adds r2, r7, r0
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r3, _0819C3CC @ =FUN_0819c3dc
	movs r2, #0x28
	ldr r0, _0819C3D0 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0819C3D4 @ =0x0000046B
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0819C3D8 @ =0x00000553
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0
	strh r0, [r1]
_0819C3B8:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819C3C4: .4byte 0x000003FF
_0819C3C8: .4byte 0x00000A4C
_0819C3CC: .4byte FUN_0819c3dc
_0819C3D0: .4byte 0x0000046D
_0819C3D4: .4byte 0x0000046B
_0819C3D8: .4byte 0x00000553

	thumb_func_start FUN_0819c3dc
FUN_0819c3dc: @ 0x0819C3DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r5, [r6, #0x44]
	ldr r2, _0819C404 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C408
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C40A
	.align 2, 0
_0819C404: .4byte 0x0000046D
_0819C408:
	movs r0, #0
_0819C40A:
	cmp r0, #0
	beq _0819C426
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldr r0, _0819C434 @ =0x00000A5E
	adds r1, r7, r0
	movs r0, #0xc
	strb r0, [r1]
	ldr r2, _0819C438 @ =0x00000EAB
	adds r1, r7, r2
	movs r0, #0x1e
	strb r0, [r1]
_0819C426:
	ldrb r4, [r5, #6]
	cmp r4, #0x80
	ble _0819C440
	ldr r0, _0819C43C @ =0xFFFFFF00
	adds r4, r4, r0
	b _0819C44E
	.align 2, 0
_0819C434: .4byte 0x00000A5E
_0819C438: .4byte 0x00000EAB
_0819C43C: .4byte 0xFFFFFF00
_0819C440:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0819C44E
	movs r1, #0x80
	lsls r1, r1, #1
	adds r4, r4, r1
_0819C44E:
	adds r0, r6, #0
	bl FUN_0819ef24
	ldrb r1, [r5, #6]
	ldr r2, _0819C498 @ =0x00000A5E
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r0, r1, r0
	strb r0, [r5, #6]
	ldr r0, [r6, #0x44]
	ldrb r0, [r0, #6]
	cmp r1, r0
	bge _0819C46E
	ldr r0, _0819C49C @ =0x00000169
	bl PlaySound_082406e0
_0819C46E:
	mov r0, r8
	cmp r0, #0x1d
	ble _0819C48C
	adds r0, r4, #0
	cmp r0, #0
	bge _0819C47C
	rsbs r0, r0, #0
_0819C47C:
	cmp r0, #0xc
	bgt _0819C48C
	movs r0, #0
	strb r0, [r5, #6]
	ldr r2, _0819C4A0 @ =0x0000046B
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
_0819C48C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819C498: .4byte 0x00000A5E
_0819C49C: .4byte 0x00000169
_0819C4A0: .4byte 0x0000046B

	thumb_func_start FUN_0819c4a4
FUN_0819c4a4: @ 0x0819C4A4
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0819C4BC @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C4C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C4C2
	.align 2, 0
_0819C4BC: .4byte 0x0000046D
_0819C4C0:
	movs r0, #0
_0819C4C2:
	ldr r2, [r4, #0x44]
	cmp r0, #0
	beq _0819C4D0
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
_0819C4D0:
	ldrb r0, [r2, #6]
	subs r1, r0, #6
	strb r1, [r2, #6]
	ldr r1, [r4, #0x44]
	ldrb r1, [r1, #6]
	cmp r0, r1
	bge _0819C4E4
	ldr r0, _0819C4FC @ =0x00000169
	bl PlaySound_082406e0
_0819C4E4:
	cmp r5, #0x2b
	ble _0819C4F6
	ldr r1, [r4, #0x44]
	movs r0, #0
	strb r0, [r1, #6]
	ldr r0, _0819C500 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0819C4F6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819C4FC: .4byte 0x00000169
_0819C500: .4byte 0x0000046B

	thumb_func_start FUN_0819c504
FUN_0819c504: @ 0x0819C504
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r3, [r0]
	ldr r2, [r5, #0x44]
	ldr r6, _0819C528 @ =0x0000046D
	adds r1, r5, r6
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C52C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C52E
	.align 2, 0
_0819C528: .4byte 0x0000046D
_0819C52C:
	movs r0, #0
_0819C52E:
	cmp r0, #0
	beq _0819C548
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r6, _0819C554 @ =0x00000ECF
	adds r0, r3, r6
	strb r1, [r0]
_0819C548:
	ldrb r1, [r2, #6]
	cmp r1, #0x80
	ble _0819C55C
	ldr r0, _0819C558 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0819C56A
	.align 2, 0
_0819C554: .4byte 0x00000ECF
_0819C558: .4byte 0xFFFFFF00
_0819C55C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C56A
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
_0819C56A:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819C572
	rsbs r0, r0, #0
_0819C572:
	cmp r0, #0x30
	ble _0819C5B8
	cmp r4, #0x2a
	ble _0819C5F2
	ldr r4, _0819C5A8 @ =FUN_0819c5f8
	movs r3, #0x31
	ldr r0, _0819C5AC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819C5B0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	ldr r6, _0819C5B4 @ =0x00000553
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	b _0819C5F2
	.align 2, 0
_0819C5A8: .4byte FUN_0819c5f8
_0819C5AC: .4byte 0x0000046D
_0819C5B0: .4byte 0x0000046B
_0819C5B4: .4byte 0x00000553
_0819C5B8:
	ldr r1, _0819C5CC @ =0x00000ECF
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819C5D4
	ldr r6, _0819C5D0 @ =0xFFFFFF00
	adds r1, r1, r6
	b _0819C5E2
	.align 2, 0
_0819C5CC: .4byte 0x00000ECF
_0819C5D0: .4byte 0xFFFFFF00
_0819C5D4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C5E2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0819C5E2:
	cmp r1, #0
	bge _0819C5EC
	ldrb r0, [r2, #6]
	subs r0, #2
	b _0819C5F0
_0819C5EC:
	ldrb r0, [r2, #6]
	adds r0, #2
_0819C5F0:
	strb r0, [r2, #6]
_0819C5F2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0819c5f8
FUN_0819c5f8: @ 0x0819C5F8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r4, [r5, #0x44]
	ldr r0, _0819C61C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C620
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C622
	.align 2, 0
_0819C61C: .4byte 0x0000046D
_0819C620:
	movs r0, #0
_0819C622:
	cmp r0, #0
	beq _0819C63C
	ldr r0, [r4]
	movs r1, #2
	orrs r0, r1
	str r0, [r4]
	ldr r0, _0819C650 @ =0x00000EAA
	adds r1, r6, r0
	movs r0, #4
	strb r0, [r1]
	ldr r0, _0819C654 @ =0x000001E5
	bl PlaySound_082406e0
_0819C63C:
	ldr r1, _0819C658 @ =0x00000ECF
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819C660
	ldr r0, _0819C65C @ =0xFFFFFF00
	b _0819C66C
	.align 2, 0
_0819C650: .4byte 0x00000EAA
_0819C654: .4byte 0x000001E5
_0819C658: .4byte 0x00000ECF
_0819C65C: .4byte 0xFFFFFF00
_0819C660:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C66E
	movs r0, #0x80
	lsls r0, r0, #1
_0819C66C:
	adds r1, r1, r0
_0819C66E:
	cmp r1, #0
	bge _0819C684
	ldr r1, _0819C680 @ =0x00000EAA
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r1, [r4, #6]
	adds r0, r0, r1
	strb r0, [r4, #6]
	b _0819C690
	.align 2, 0
_0819C680: .4byte 0x00000EAA
_0819C684:
	ldr r1, _0819C6B4 @ =0x00000EAA
	adds r0, r6, r1
	ldrb r1, [r4, #6]
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r4, #6]
_0819C690:
	adds r0, r7, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0819C6A6
	ldr r0, _0819C6B4 @ =0x00000EAA
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_0819C6A6:
	ldrb r4, [r4, #6]
	cmp r4, #0x80
	ble _0819C6BC
	ldr r1, _0819C6B8 @ =0xFFFFFF00
	adds r4, r4, r1
	b _0819C6CA
	.align 2, 0
_0819C6B4: .4byte 0x00000EAA
_0819C6B8: .4byte 0xFFFFFF00
_0819C6BC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0819C6CA
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r4, r0
_0819C6CA:
	adds r0, r5, #0
	bl FUN_0819ef24
	adds r0, r4, #0
	cmp r0, #0
	bge _0819C6D8
	rsbs r0, r0, #0
_0819C6D8:
	cmp r0, #0x60
	ble _0819C720
	ldr r4, _0819C728 @ =FUN_0819c740
	movs r3, #0x32
	ldr r0, _0819C72C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819C730 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r0, _0819C734 @ =0x00000E48
	adds r2, r6, r0
	ldr r1, _0819C738 @ =0xFFFFFDFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0819C73C @ =0x00000EAE
	adds r1, r6, r0
	movs r0, #0x20
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_0819f530
_0819C720:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819C728: .4byte FUN_0819c740
_0819C72C: .4byte 0x0000046D
_0819C730: .4byte 0x0000046B
_0819C734: .4byte 0x00000E48
_0819C738: .4byte 0xFFFFFDFF
_0819C73C: .4byte 0x00000EAE

	thumb_func_start FUN_0819c740
FUN_0819c740: @ 0x0819C740
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r3, [r0]
	ldr r2, [r5, #0x44]
	ldr r0, _0819C764 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C768
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C76A
	.align 2, 0
_0819C764: .4byte 0x0000046D
_0819C768:
	movs r0, #0
_0819C76A:
	cmp r0, #0
	beq _0819C784
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0819C7D0 @ =0x00000EAD
	adds r1, r3, r0
	movs r0, #0x28
	strb r0, [r1]
	ldr r0, _0819C7D4 @ =0x000001E3
	bl PlaySound_082406e0
_0819C784:
	adds r0, r4, #0
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _0819C79E
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0819C79E:
	cmp r4, #0x50
	ble _0819C7CA
	ldr r4, _0819C7D8 @ =FUN_0819cc04
	movs r3, #0x33
	ldr r0, _0819C7DC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819C7E0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0819C7CA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819C7D0: .4byte 0x00000EAD
_0819C7D4: .4byte 0x000001E3
_0819C7D8: .4byte FUN_0819cc04
_0819C7DC: .4byte 0x0000046D
_0819C7E0: .4byte 0x0000046B

	thumb_func_start FUN_0819c7e4
FUN_0819c7e4: @ 0x0819C7E4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r6, [r5, #0x44]
	ldr r2, _0819C808 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C80C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C80E
	.align 2, 0
_0819C808: .4byte 0x0000046D
_0819C80C:
	movs r0, #0
_0819C80E:
	cmp r0, #0
	beq _0819C846
	ldr r0, [r6]
	movs r1, #2
	orrs r0, r1
	str r0, [r6]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _0819C854 @ =0x00000ECF
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0819C858 @ =0x00000F14
	adds r2, r4, r0
	ldr r0, _0819C85C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0819C860 @ =0x00000ECC
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0819C864 @ =0x0000016F
	bl PlaySound_082406e0
_0819C846:
	ldrb r1, [r6, #6]
	cmp r1, #0x80
	ble _0819C86C
	ldr r0, _0819C868 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0819C87A
	.align 2, 0
_0819C854: .4byte 0x00000ECF
_0819C858: .4byte 0x00000F14
_0819C85C: .4byte 0x03002BE0
_0819C860: .4byte 0x00000ECC
_0819C864: .4byte 0x0000016F
_0819C868: .4byte 0xFFFFFF00
_0819C86C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C87A
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0819C87A:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819C882
	rsbs r0, r0, #0
_0819C882:
	cmp r0, #0x30
	ble _0819C900
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0819C8B0 @ =0x00000546
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819C8BC
	ldr r1, _0819C8B4 @ =0x00000E3E
	adds r0, r4, r1
	ldrb r0, [r0]
	lsrs r0, r0, #1
	cmp r7, r0
	ble _0819C96E
	ldr r4, _0819C8B8 @ =FUN_0819c974
	movs r3, #0x35
	subs r2, #0xd9
	adds r1, r5, r2
	b _0819C8CE
	.align 2, 0
_0819C8B0: .4byte 0x00000546
_0819C8B4: .4byte 0x00000E3E
_0819C8B8: .4byte FUN_0819c974
_0819C8BC:
	ldr r2, _0819C8F0 @ =0x00000E3E
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r7, r0
	ble _0819C96E
	ldr r4, _0819C8F4 @ =FUN_0819c974
	movs r3, #0x35
	ldr r0, _0819C8F8 @ =0x0000046D
	adds r1, r5, r0
_0819C8CE:
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819C8FC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	b _0819C96E
	.align 2, 0
_0819C8F0: .4byte 0x00000E3E
_0819C8F4: .4byte FUN_0819c974
_0819C8F8: .4byte 0x0000046D
_0819C8FC: .4byte 0x0000046B
_0819C900:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0819C91C @ =0x00000546
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819C924
	ldr r1, _0819C920 @ =0x00000E3F
	adds r0, r4, r1
	ldrb r2, [r0]
	b _0819C92C
	.align 2, 0
_0819C91C: .4byte 0x00000546
_0819C920: .4byte 0x00000E3F
_0819C924:
	ldr r2, _0819C944 @ =0x00000E3F
	adds r0, r4, r2
	ldrb r0, [r0]
	lsrs r2, r0, #1
_0819C92C:
	cmp r2, #0
	bgt _0819C932
	movs r2, #1
_0819C932:
	ldr r1, _0819C948 @ =0x00000ECF
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819C950
	ldr r0, _0819C94C @ =0xFFFFFF00
	b _0819C95C
	.align 2, 0
_0819C944: .4byte 0x00000E3F
_0819C948: .4byte 0x00000ECF
_0819C94C: .4byte 0xFFFFFF00
_0819C950:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C95E
	movs r0, #0x80
	lsls r0, r0, #1
_0819C95C:
	adds r1, r1, r0
_0819C95E:
	cmp r1, #0
	bge _0819C968
	ldrb r0, [r6, #6]
	subs r0, r0, r2
	b _0819C96C
_0819C968:
	ldrb r0, [r6, #6]
	adds r0, r0, r2
_0819C96C:
	strb r0, [r6, #6]
_0819C96E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0819c974
FUN_0819c974: @ 0x0819C974
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov sb, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r7, [r5, #0x44]
	ldr r2, _0819C9A0 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C9A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C9A6
	.align 2, 0
_0819C9A0: .4byte 0x0000046D
_0819C9A4:
	movs r0, #0
_0819C9A6:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r5
	mov r8, r1
	cmp r0, #0
	beq _0819CAA8
	ldr r0, [r7]
	movs r1, #2
	orrs r0, r1
	str r0, [r7]
	ldr r2, _0819CA30 @ =0x00000EAA
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _0819CA34 @ =0x03002BE0
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0819CA38 @ =0x00000546
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819CA3C
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x2c
	bl Div
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x2c
	strh r0, [r1]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0x2c
	bl Div
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	b _0819CA7E
	.align 2, 0
_0819CA30: .4byte 0x00000EAA
_0819CA34: .4byte 0x03002BE0
_0819CA38: .4byte 0x00000546
_0819CA3C:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0819CA4A
	asrs r1, r0, #6
	b _0819CA50
_0819CA4A:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0819CA50:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x40
	strh r0, [r1]
	mov r0, sp
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0819CA70
	asrs r1, r0, #6
	b _0819CA76
_0819CA70:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r1, r0, #0
_0819CA76:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0819CA7E:
	ldr r0, _0819CACC @ =0x00000EAF
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r4, r5, r1
	ldr r1, _0819CAD0 @ =0xFFEFFFFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r2, _0819CAD4 @ =0x000008DC
	adds r1, r6, r2
	adds r0, r5, #0
	movs r2, #0xf8
	bl FUN_0819ee40
	ldr r0, _0819CAD8 @ =0x000001E5
	bl PlaySound_082406e0
	mov r8, r4
_0819CAA8:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0xa]
	adds r0, r0, r2
	strh r0, [r5, #0xa]
	ldr r1, _0819CADC @ =0x00000ECF
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819CAE4
	ldr r2, _0819CAE0 @ =0xFFFFFF00
	adds r1, r1, r2
	b _0819CAF2
	.align 2, 0
_0819CACC: .4byte 0x00000EAF
_0819CAD0: .4byte 0xFFEFFFFF
_0819CAD4: .4byte 0x000008DC
_0819CAD8: .4byte 0x000001E5
_0819CADC: .4byte 0x00000ECF
_0819CAE0: .4byte 0xFFFFFF00
_0819CAE4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819CAF2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0819CAF2:
	cmp r1, #0
	bge _0819CB08
	ldr r1, _0819CB04 @ =0x00000EAA
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r2, [r7, #6]
	adds r0, r0, r2
	strb r0, [r7, #6]
	b _0819CB14
	.align 2, 0
_0819CB04: .4byte 0x00000EAA
_0819CB08:
	ldr r1, _0819CB20 @ =0x00000EAA
	adds r0, r6, r1
	ldrb r1, [r7, #6]
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r7, #6]
_0819CB14:
	ldrb r4, [r7, #6]
	cmp r4, #0x80
	ble _0819CB28
	ldr r2, _0819CB24 @ =0xFFFFFF00
	adds r4, r4, r2
	b _0819CB36
	.align 2, 0
_0819CB20: .4byte 0x00000EAA
_0819CB24: .4byte 0xFFFFFF00
_0819CB28:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0819CB36
	movs r7, #0x80
	lsls r7, r7, #1
	adds r4, r4, r7
_0819CB36:
	adds r0, r5, #0
	bl FUN_0819ef24
	mov r0, sb
	cmp r0, #0x1b
	bgt _0819CB5C
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _0819CB7C
	ldr r2, _0819CB58 @ =0x00000EAA
	adds r1, r6, r2
	ldrb r0, [r1]
	adds r0, #4
	b _0819CB7A
	.align 2, 0
_0819CB58: .4byte 0x00000EAA
_0819CB5C:
	adds r0, r4, #0
	cmp r0, #0
	bge _0819CB64
	rsbs r0, r0, #0
_0819CB64:
	cmp r0, #0x5f
	bgt _0819CB74
	ldr r7, _0819CB70 @ =0x00000EAA
	adds r1, r6, r7
	movs r0, #8
	b _0819CB7A
	.align 2, 0
_0819CB70: .4byte 0x00000EAA
_0819CB74:
	ldr r0, _0819CBE4 @ =0x00000EAA
	adds r1, r6, r0
	movs r0, #0
_0819CB7A:
	strb r0, [r1]
_0819CB7C:
	movs r1, #0x10
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0819CBD4
	ldr r7, _0819CBE8 @ =0x00000ECD
	adds r0, r6, r7
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0819CBEC @ =FUN_0819c740
	movs r2, #0x32
	ldr r7, _0819CBF0 @ =0x0000046D
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _0819CBF4 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r7, _0819CBF8 @ =0x00000E48
	adds r2, r6, r7
	ldr r1, _0819CBFC @ =0xFFFFF7FF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0819CC00 @ =0x00000EAE
	adds r1, r6, r0
	movs r0, #0x40
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0xe
	bl FUN_0819f530
_0819CBD4:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819CBE4: .4byte 0x00000EAA
_0819CBE8: .4byte 0x00000ECD
_0819CBEC: .4byte FUN_0819c740
_0819CBF0: .4byte 0x0000046D
_0819CBF4: .4byte 0x0000046B
_0819CBF8: .4byte 0x00000E48
_0819CBFC: .4byte 0xFFFFF7FF
_0819CC00: .4byte 0x00000EAE

	thumb_func_start FUN_0819cc04
FUN_0819cc04: @ 0x0819CC04
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	ldr r5, [r7, #0x44]
	ldr r0, _0819CC24 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819CC28
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819CC2A
	.align 2, 0
_0819CC24: .4byte 0x0000046D
_0819CC28:
	movs r0, #0
_0819CC2A:
	cmp r0, #0
	beq _0819CC3E
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldr r0, _0819CC4C @ =0x00000EAB
	adds r1, r6, r0
	movs r0, #0x1e
	strb r0, [r1]
_0819CC3E:
	ldrb r2, [r5, #6]
	cmp r2, #0x80
	ble _0819CC54
	ldr r1, _0819CC50 @ =0xFFFFFF00
	adds r2, r2, r1
	b _0819CC62
	.align 2, 0
_0819CC4C: .4byte 0x00000EAB
_0819CC50: .4byte 0xFFFFFF00
_0819CC54:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0819CC62
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r2, r0
_0819CC62:
	cmp r2, #0
	ble _0819CC7C
	ldr r1, _0819CC78 @ =0x00000EAB
	adds r4, r6, r1
	ldrb r1, [r4]
	adds r0, r2, #0
	bl Div
	ldrb r1, [r5, #6]
	subs r1, r1, r0
	b _0819CC92
	.align 2, 0
_0819CC78: .4byte 0x00000EAB
_0819CC7C:
	adds r0, r2, #0
	cmp r0, #0
	bge _0819CC84
	rsbs r0, r0, #0
_0819CC84:
	ldr r1, _0819CCC0 @ =0x00000EAB
	adds r4, r6, r1
	ldrb r1, [r4]
	bl Div
	ldrb r1, [r5, #6]
	adds r1, r1, r0
_0819CC92:
	strb r1, [r5, #6]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	ldr r1, _0819CCC0 @ =0x00000EAB
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0819CCB8
	ldr r0, _0819CCC4 @ =0x000008BC
	adds r1, r6, r0
	adds r0, r7, #0
	movs r2, #0xf7
	bl FUN_0819ee40
	ldr r0, _0819CCC8 @ =0x0000046B
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_0819CCB8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819CCC0: .4byte 0x00000EAB
_0819CCC4: .4byte 0x000008BC
_0819CCC8: .4byte 0x0000046B

	thumb_func_start FUN_0819cccc
FUN_0819cccc: @ 0x0819CCCC
	push {lr}
	adds r2, r0, #0
	ldr r0, _0819CCE4 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819CCE8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819CCEA
	.align 2, 0
_0819CCE4: .4byte 0x0000046D
_0819CCE8:
	movs r0, #0
_0819CCEA:
	cmp r0, #0
	beq _0819CCF6
	adds r0, r2, #0
	movs r1, #1
	bl FUN_080efe38
_0819CCF6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0819ccfc
FUN_0819ccfc: @ 0x0819CCFC
	push {lr}
	adds r2, r0, #0
	ldr r0, _0819CD14 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819CD18
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819CD1A
	.align 2, 0
_0819CD14: .4byte 0x0000046D
_0819CD18:
	movs r0, #0
_0819CD1A:
	cmp r0, #0
	beq _0819CD2E
	ldr r0, _0819CD34 @ =0x00000482
	adds r1, r2, r0
	movs r0, #1
	strh r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080efe38
_0819CD2E:
	pop {r0}
	bx r0
	.align 2, 0
_0819CD34: .4byte 0x00000482

	thumb_func_start FUN_0819cd38
FUN_0819cd38: @ 0x0819CD38
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r5, #0
	ldr r0, _0819CD58 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819CD5C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819CD5E
	.align 2, 0
_0819CD58: .4byte 0x0000046D
_0819CD5C:
	movs r0, #0
_0819CD5E:
	cmp r0, #0
	beq _0819CDFC
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r3, r0, #3
	movs r1, #7
	ands r3, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrb r4, [r0]
	adds r0, r4, #0
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	ands r0, r1
	cmp r3, r0
	bne _0819CDCC
	movs r1, #0
	strb r4, [r5, #5]
	ldr r2, _0819CDC0 @ =0x000005A4
	adds r0, r5, r2
	ldr r3, [r0]
	ldr r4, _0819CDC4 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #1
	strb r2, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #0x25
	adds r0, r5, r4
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	ldr r4, _0819CDC8 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	b _0819CFBE
	.align 2, 0
_0819CDC0: .4byte 0x000005A4
_0819CDC4: .4byte 0x0000046D
_0819CDC8: .4byte 0x0000046B
_0819CDCC:
	subs r0, #8
	subs r0, r3, r0
	movs r1, #7
	ands r0, r1
	cmp r0, #4
	bgt _0819CDEC
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0819CDE8 @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _0819CDFC
	.align 2, 0
_0819CDE8: .4byte 0xFFFEFFFF
_0819CDEC:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0819CDFC:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	mov r8, r0
	ldr r1, _0819CE20 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819CE28
	ldr r0, _0819CE24 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0819CE38
	.align 2, 0
_0819CE20: .4byte 0x0000A02F
_0819CE24: .4byte 0x00000482
_0819CE28:
	ldr r1, _0819CE60 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0819CE38
	movs r0, #1
	strh r0, [r2]
_0819CE38:
	ldr r3, _0819CE64 @ =0x0000025D
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _0819CE68
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0819CE80
	.align 2, 0
_0819CE60: .4byte 0x00000482
_0819CE64: .4byte 0x0000025D
_0819CE68:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0819CE80:
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0819CE92
	b _0819CFBE
_0819CE92:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _0819CEDC @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819CEE0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	movs r1, #0x80
	lsls r1, r1, #9
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819CEE4
	ldrb r0, [r6, #5]
	adds r0, #0x20
	b _0819CEE8
	.align 2, 0
_0819CEDC: .4byte 0x0000046D
_0819CEE0: .4byte 0x0000046B
_0819CEE4:
	ldrb r0, [r6, #5]
	subs r0, #0x20
_0819CEE8:
	strb r0, [r6, #5]
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0819e2f4
	movs r0, #0
	mov r3, r8
	strb r0, [r3, #5]
	ldr r4, _0819CF2C @ =0x000004C4
	adds r0, r5, r4
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldrb r0, [r7]
	cmp r0, #0
	bne _0819CF38
	ldr r1, _0819CF30 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _0819CF34 @ =0x0000046E
	adds r7, r5, r2
	b _0819CFBA
	.align 2, 0
_0819CF2C: .4byte 0x000004C4
_0819CF30: .4byte 0x000004B7
_0819CF34: .4byte 0x0000046E
_0819CF38:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r3, _0819CFA8 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0819CFAC @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0819CF72
	ldrb r0, [r7]
	cmp r0, #0
	bne _0819CF72
	cmp r4, #1
	bne _0819CF64
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0819CFBE
_0819CF64:
	cmp r4, #0
	bne _0819CF72
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0819CFBE
_0819CF72:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0819CF84
	movs r3, #6
_0819CF84:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0819CFB0
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _0819CFB8
	.align 2, 0
_0819CFA8: .4byte 0x000004B7
_0819CFAC: .4byte 0x0000046E
_0819CFB0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0819CFB8:
	str r0, [r6, #8]
_0819CFBA:
	movs r0, #0
	strb r0, [r7]
_0819CFBE:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0819cfcc
FUN_0819cfcc: @ 0x0819CFCC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov sb, r1
	ldr r0, _0819D028 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819CFE8
	movs r0, #0
	strb r0, [r1]
_0819CFE8:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0819e2f4
	ldr r1, _0819D02C @ =0x000004EC
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0819D030 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0819D03C
	ldr r1, _0819D034 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _0819D038 @ =0x0000046E
	adds r7, r5, r0
	b _0819D0BE
	.align 2, 0
_0819D028: .4byte 0x0000046D
_0819D02C: .4byte 0x000004EC
_0819D030: .4byte 0x0000025D
_0819D034: .4byte 0x000004B7
_0819D038: .4byte 0x0000046E
_0819D03C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0819D0AC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0819D0B0 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0819D076
	ldrb r0, [r7]
	cmp r0, #0
	bne _0819D076
	cmp r4, #1
	bne _0819D068
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0819D0C2
_0819D068:
	cmp r4, #0
	bne _0819D076
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0819D0C2
_0819D076:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0819D088
	movs r3, #6
_0819D088:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0819D0B4
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0819D0BC
	.align 2, 0
_0819D0AC: .4byte 0x000004B7
_0819D0B0: .4byte 0x0000046E
_0819D0B4:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0819D0BC:
	str r0, [r6, #8]
_0819D0BE:
	movs r0, #0
	strb r0, [r7]
_0819D0C2:
	mov r0, sb
	cmp r0, #0x1d
	bgt _0819D0D6
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0819D0D6:
	mov r0, sb
	cmp r0, #0x3b
	ble _0819D0E4
	ldr r0, _0819D0F4 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0819D0E4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819D0F4: .4byte 0x0000046B

	thumb_func_start FUN_0819d0f8
FUN_0819d0f8: @ 0x0819D0F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0819D11C @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819D120
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819D122
	.align 2, 0
_0819D11C: .4byte 0x0000046D
_0819D120:
	movs r0, #0
_0819D122:
	cmp r0, #0
	beq _0819D148
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080efe38
	adds r0, r7, #0
	bl FUN_0819e3c8
	adds r0, r7, #0
	bl FUN_0819e2b4
_0819D148:
	movs r5, #0x83
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x85
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0819D168
	asrs r0, r0, #2
	b _0819D16E
_0819D168:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0819D16E:
	adds r3, r0, #0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _0819D18E
	asrs r0, r0, #2
	b _0819D194
_0819D18E:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0819D194:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0819D19E
	movs r3, #0xc8
	b _0819D1A8
_0819D19E:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0819D1A8
	adds r3, r0, #0
_0819D1A8:
	cmp r2, #0xc8
	ble _0819D1B0
	movs r2, #0xc8
	b _0819D1BA
_0819D1B0:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0819D1BA
	adds r2, r0, #0
_0819D1BA:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0819D1DE
	cmp r2, #0
	bne _0819D1DE
	movs r0, #1
	b _0819D1E0
_0819D1DE:
	movs r0, #0
_0819D1E0:
	cmp r0, #0
	beq _0819D262
	ldr r1, _0819D26C @ =0x0000046B
	adds r0, r7, r1
	movs r6, #0
	movs r5, #1
	strb r5, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r4, #0
	strh r0, [r2]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0xd
	subs r3, #4
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0819e2b4
	movs r2, #0x10
	ldr r1, _0819D270 @ =0x00000E48
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _0819D274 @ =0x0000024E
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #2
	movs r2, #9
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _0819D278 @ =0x0000046A
	adds r0, r7, r1
	strb r2, [r0]
	ldr r2, _0819D27C @ =0x00000484
	adds r0, r7, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r5, [r0]
_0819D262:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819D26C: .4byte 0x0000046B
_0819D270: .4byte 0x00000E48
_0819D274: .4byte 0x0000024E
_0819D278: .4byte 0x0000046A
_0819D27C: .4byte 0x00000484

	thumb_func_start FUN_0819d280
FUN_0819d280: @ 0x0819D280
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	adds r6, r0, #0
	mov sb, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, [r6, #0x44]
	mov r8, r2
	ldr r3, _0819D2B0 @ =0x0000046D
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819D2B4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819D2B6
	.align 2, 0
_0819D2B0: .4byte 0x0000046D
_0819D2B4:
	movs r0, #0
_0819D2B6:
	cmp r0, #0
	beq _0819D320
	adds r0, r6, #0
	movs r1, #0xa
	bl FUN_080efe38
	adds r0, r6, #0
	bl FUN_080e8360
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r6, r4
	ldr r1, _0819D380 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0819D384 @ =0x0000021E
	adds r0, r6, r1
	movs r3, #0
	movs r1, #0
	strh r1, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	adds r4, #0x8a
	adds r0, r6, r4
	strh r1, [r0]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	adds r1, r6, #0
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _0819D388 @ =0x00000474
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0819D38C @ =0x00000ECE
	adds r0, r7, r2
	strb r3, [r0]
	adds r0, r6, #0
	bl FUN_0819fca4
_0819D320:
	mov r0, sb
	movs r1, #2
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	beq _0819D330
	b _0819D518
_0819D330:
	ldr r2, _0819D390 @ =0xFFFF0000
	ldr r0, [sp, #0x34]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _0819D394 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x34]
	add r4, sp, #0x34
	ldr r0, [r4, #4]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [r4, #4]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [sp, #0x44]
	str r1, [sp, #0x48]
	add r5, sp, #0x3c
	str r3, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0819D398 @ =0x05000002
	bl CpuSet
	ldr r3, _0819D38C @ =0x00000ECE
	adds r0, r7, r3
	ldrb r0, [r0]
	mov sl, r4
	cmp r0, #4
	bhi _0819D430
	lsls r0, r0, #2
	ldr r1, _0819D39C @ =_0819D3A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0819D380: .4byte 0xFFFEBE3F
_0819D384: .4byte 0x0000021E
_0819D388: .4byte 0x00000474
_0819D38C: .4byte 0x00000ECE
_0819D390: .4byte 0xFFFF0000
_0819D394: .4byte 0x0000FFFF
_0819D398: .4byte 0x05000002
_0819D39C: .4byte _0819D3A0
_0819D3A0: @ jump table
	.4byte _0819D3B4 @ case 0
	.4byte _0819D3D8 @ case 1
	.4byte _0819D3F0 @ case 2
	.4byte _0819D408 @ case 3
	.4byte _0819D420 @ case 4
_0819D3B4:
	ldr r1, _0819D3D0 @ =0x0000FF88
	strh r1, [r5]
	add r0, sp, #0x3c
	strh r1, [r0, #4]
	ldr r4, _0819D3D4 @ =0x00000ECE
	adds r1, r7, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0xb7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0819D430
	.align 2, 0
_0819D3D0: .4byte 0x0000FF88
_0819D3D4: .4byte 0x00000ECE
_0819D3D8:
	ldr r1, _0819D3E8 @ =0x0000FFB5
	strh r1, [r5]
	add r0, sp, #0x3c
	strh r1, [r0, #4]
	ldr r0, _0819D3EC @ =0x00000ECE
	adds r1, r7, r0
	b _0819D414
	.align 2, 0
_0819D3E8: .4byte 0x0000FFB5
_0819D3EC: .4byte 0x00000ECE
_0819D3F0:
	ldr r1, _0819D400 @ =0x0000FFE2
	strh r1, [r5]
	add r0, sp, #0x3c
	strh r1, [r0, #4]
	ldr r2, _0819D404 @ =0x00000ECE
	adds r1, r7, r2
	b _0819D414
	.align 2, 0
_0819D400: .4byte 0x0000FFE2
_0819D404: .4byte 0x00000ECE
_0819D408:
	movs r1, #0xf
	strh r1, [r5]
	add r0, sp, #0x3c
	strh r1, [r0, #4]
	ldr r3, _0819D41C @ =0x00000ECE
	adds r1, r7, r3
_0819D414:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0819D430
	.align 2, 0
_0819D41C: .4byte 0x00000ECE
_0819D420:
	movs r2, #0
	movs r1, #0x3c
	strh r1, [r5]
	add r0, sp, #0x3c
	strh r1, [r0, #4]
	ldr r4, _0819D454 @ =0x00000ECE
	adds r0, r7, r4
	strb r2, [r0]
_0819D430:
	movs r7, #0
	ldrsh r3, [r5, r7]
	ldr r2, _0819D458 @ =0x085B0A08
	mov r1, r8
	ldrb r0, [r1, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r3, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _0819D45C
	asrs r0, r0, #0xc
	b _0819D462
	.align 2, 0
_0819D454: .4byte 0x00000ECE
_0819D458: .4byte 0x085B0A08
_0819D45C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819D462:
	adds r2, r0, #0
	movs r7, #4
	ldrsh r0, [r5, r7]
	mov r3, r8
	ldrb r1, [r3, #6]
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r7, #0
	ldrsh r1, [r1, r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819D47E
	asrs r0, r0, #0xc
	b _0819D484
_0819D47E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819D484:
	add r3, sp, #0x44
	adds r1, r2, r0
	ldrh r0, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819D4B8 @ =0xFFFF0000
	ldr r0, [sp, #0x44]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x44]
	movs r2, #0
	ldrsh r1, [r5, r2]
	mov r7, r8
	ldrb r0, [r7, #6]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _0819D4BC
	asrs r0, r0, #0xc
	b _0819D4C0
	.align 2, 0
_0819D4B8: .4byte 0xFFFF0000
_0819D4BC:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_0819D4C0:
	adds r7, r0, #0
	movs r0, #4
	ldrsh r2, [r5, r0]
	mov r1, r8
	ldrb r0, [r1, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r2, r0
	cmp r0, #0
	blt _0819D4E2
	asrs r0, r0, #0xc
	b _0819D4E8
_0819D4E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819D4E8:
	adds r1, r7, r0
	ldrh r7, [r3, #4]
	adds r1, r1, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819D5C4 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #2
	mov r2, sl
	movs r3, #0
	bl FUN_080ddcc8
_0819D518:
	ldr r0, [r6, #0x44]
	mov r1, sb
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819D52C
	b _0819D640
_0819D52C:
	ldr r1, _0819D5C8 @ =0x0000046B
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r6, #0
	bl FUN_080e6658
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0819D59C
	movs r7, #8
	ldrsh r0, [r6, r7]
	str r0, [sp, #0x14]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	str r0, [sp, #0x18]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
	str r0, [sp, #0x1c]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x28]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	ldrh r0, [r6]
	str r0, [sp, #0x30]
	ldr r1, _0819D5C4 @ =0xFFFF0000
	ldr r0, [sp, #0x4c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x4c]
	add r0, sp, #0x14
	add r1, sp, #0x4c
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0819D59C:
	ldr r1, _0819D5CC @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0819D5D4
	ldr r0, _0819D5D0 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _0819D5E6
	.align 2, 0
_0819D5C4: .4byte 0xFFFF0000
_0819D5C8: .4byte 0x0000046B
_0819D5CC: .4byte 0x000001DF
_0819D5D0: .4byte 0x030046A0
_0819D5D4:
	ldr r0, _0819D650 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0819D5E6:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xc9
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _0819D654 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r7, _0819D658 @ =0x0000046D
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _0819D65C @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _0819D660 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
_0819D640:
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819D650: .4byte 0x030046A0
_0819D654: .4byte FUN_080e48d0
_0819D658: .4byte 0x0000046D
_0819D65C: .4byte 0x00000469
_0819D660: .4byte 0x00000484

	thumb_func_start FUN_0819d664
FUN_0819d664: @ 0x0819D664
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0819D684 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819D688
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819D68A
	.align 2, 0
_0819D684: .4byte 0x0000046C
_0819D688:
	movs r0, #0
_0819D68A:
	cmp r0, #0
	beq _0819D6D0
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r6, _0819D734 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r6, _0819D738 @ =0x00000E52
	adds r1, r4, r6
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
_0819D6D0:
	adds r0, r5, #0
	bl FUN_0819ef24
	ldr r1, _0819D738 @ =0x00000E52
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r1, r0
	bls _0819D77A
	ldr r0, _0819D73C @ =0x03002BE0
	mov r2, sp
	ldr r1, [r0]
	adds r4, r1, #0
	adds r4, #0x2c
	adds r3, r5, #0
	adds r3, #8
	ldrh r0, [r5, #8]
	ldrh r1, [r1, #0x2c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r6, #4
	ldrsh r1, [r2, r6]
	bl FUN_0823785c
	adds r4, r0, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819D744
	ldr r0, _0819D740 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0819D752
	.align 2, 0
_0819D734: .4byte 0x0000046D
_0819D738: .4byte 0x00000E52
_0819D73C: .4byte 0x03002BE0
_0819D740: .4byte 0xFFFFFF00
_0819D744:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819D752
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0819D752:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819D75A
	rsbs r0, r0, #0
_0819D75A:
	cmp r0, #0x3f
	bgt _0819D762
	adds r4, #0x40
	b _0819D764
_0819D762:
	adds r4, #0xc0
_0819D764:
	movs r0, #0xff
	ands r4, r0
	movs r0, #0x20
	movs r1, #8
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bgt _0819D7F6
	movs r2, #2
	b _0819D7F6
_0819D77A:
	ldr r0, _0819D7C0 @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r6, #4
	ldrsh r1, [r2, r6]
	bl FUN_0823785c
	adds r4, r0, #0
	ldrb r0, [r5, #5]
	subs r1, r4, r0
	cmp r1, #0x80
	ble _0819D7C8
	ldr r0, _0819D7C4 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0819D7D6
	.align 2, 0
_0819D7C0: .4byte 0x03002BE0
_0819D7C4: .4byte 0xFFFFFF00
_0819D7C8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819D7D6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0819D7D6:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819D7DE
	rsbs r0, r0, #0
_0819D7DE:
	cmp r0, #0
	blt _0819D7E6
	asrs r0, r0, #3
	b _0819D7EC
_0819D7E6:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0819D7EC:
	adds r2, r0, #0
	cmp r0, #0
	bgt _0819D7F4
	movs r0, #2
_0819D7F4:
	adds r2, r0, #0
_0819D7F6:
	ldrb r0, [r5, #5]
	subs r1, r4, r0
	cmp r1, #0x80
	ble _0819D808
	ldr r3, _0819D804 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0819D816
	.align 2, 0
_0819D804: .4byte 0xFFFFFF00
_0819D808:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819D816
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
_0819D816:
	cmp r1, #0
	ble _0819D820
	ldrb r0, [r5, #5]
	adds r0, r0, r2
	b _0819D824
_0819D820:
	ldrb r0, [r5, #5]
	subs r0, r0, r2
_0819D824:
	strb r0, [r5, #5]
	add r3, sp, #8
	ldrb r4, [r5, #5]
	ldr r2, _0819D848 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0819D84C
	asrs r1, r0, #0xc
	b _0819D852
	.align 2, 0
_0819D848: .4byte 0x085B0A08
_0819D84C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819D852:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0819D86C
	asrs r0, r0, #0xc
	b _0819D872
_0819D86C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819D872:
	strh r0, [r3, #4]
	ldr r2, [r5, #0x44]
	ldrb r1, [r5, #5]
	movs r0, #0x9f
	subs r0, r0, r1
	strb r0, [r2, #6]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r5, #0x10]
	str r1, [r5, #0x14]
	ldr r3, _0819D898 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819D898: .4byte 0x00000484

	thumb_func_start FUN_0819d89c
FUN_0819d89c: @ 0x0819D89C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r0, _0819D8C0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819D8C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819D8C6
	.align 2, 0
_0819D8C0: .4byte 0x0000046C
_0819D8C4:
	movs r0, #0
_0819D8C6:
	cmp r0, #0
	beq _0819D8F8
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r0, _0819D96C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819D970 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_0819D8F8:
	ldr r0, _0819D974 @ =0x00000F0C
	adds r6, r7, r0
	ldrh r0, [r6]
	ldrh r1, [r5, #0x10]
	adds r0, r0, r1
	movs r1, #0
	mov r8, r1
	strh r0, [r5, #0x10]
	movs r0, #0xf1
	lsls r0, r0, #4
	adds r4, r7, r0
	ldrh r0, [r4]
	ldrh r1, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	ldr r0, _0819D978 @ =0x00000484
	adds r7, r5, r0
	ldr r0, [r7]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0819D936
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r6]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r4]
_0819D936:
	ldr r1, _0819D970 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0819D988
	subs r1, #3
	adds r0, r5, r1
	mov r1, r8
	strb r1, [r0]
	ldr r1, _0819D97C @ =0x00000469
	adds r0, r5, r1
	mov r1, r8
	strb r1, [r0]
	ldr r1, _0819D980 @ =0x0000046A
	adds r0, r5, r1
	mov r1, r8
	strb r1, [r0]
	ldr r0, _0819D978 @ =0x00000484
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _0819D984 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0819D98E
	.align 2, 0
_0819D96C: .4byte 0x0000046D
_0819D970: .4byte 0x0000046B
_0819D974: .4byte 0x00000F0C
_0819D978: .4byte 0x00000484
_0819D97C: .4byte 0x00000469
_0819D980: .4byte 0x0000046A
_0819D984: .4byte 0x0000046C
_0819D988:
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
_0819D98E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0819d998
FUN_0819d998: @ 0x0819D998
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0819D9B8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819D9BC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819D9BE
	.align 2, 0
_0819D9B8: .4byte 0x0000046C
_0819D9BC:
	movs r0, #0
_0819D9BE:
	cmp r0, #0
	beq _0819D9EE
	ldr r6, _0819DA3C @ =0x000005A4
	adds r0, r5, r6
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _0819DA40 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819DA44 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	subs r6, #0x51
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_0819D9EE:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819DA10
	adds r0, r5, #0
	bl FUN_0819e620
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819DA10
	b _0819DB70
_0819DA10:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r2, _0819DA48 @ =0x00000546
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819DA54
	movs r6, #8
	ldr r1, _0819DA4C @ =0x00000484
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0xc8
	lsls r0, r0, #1
	cmp r1, r0
	ble _0819DB14
	ldr r3, _0819DA50 @ =FUN_0819bd2c
	movs r1, #0x22
	subs r2, #0xd9
	b _0819DA76
	.align 2, 0
_0819DA3C: .4byte 0x000005A4
_0819DA40: .4byte 0x0000046D
_0819DA44: .4byte 0x0000046B
_0819DA48: .4byte 0x00000546
_0819DA4C: .4byte 0x00000484
_0819DA50: .4byte FUN_0819bd2c
_0819DA54:
	movs r2, #0xeb
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819DAD4
	movs r6, #6
	ldr r1, _0819DAC0 @ =0x00000484
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0xfa
	lsls r0, r0, #1
	cmp r1, r0
	ble _0819DB14
	ldr r3, _0819DAC4 @ =FUN_0819bd2c
	movs r1, #0x22
	ldr r2, _0819DAC8 @ =0x0000046D
_0819DA76:
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0819DACC @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r3, #4
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0819DAD0 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	b _0819DB70
	.align 2, 0
_0819DAC0: .4byte 0x00000484
_0819DAC4: .4byte FUN_0819bd2c
_0819DAC8: .4byte 0x0000046D
_0819DACC: .4byte 0x0000046B
_0819DAD0: .4byte 0x0000046A
_0819DAD4:
	movs r6, #4
	ldr r2, _0819DB0C @ =0x00000484
	adds r0, r5, r2
	ldr r1, [r0]
	movs r0, #0x96
	lsls r0, r0, #2
	cmp r1, r0
	ble _0819DB14
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	subs r2, #0x1b
	adds r0, r5, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r6, [r0]
	ldr r6, _0819DB0C @ =0x00000484
	adds r0, r5, r6
	str r1, [r0]
	ldr r0, _0819DB10 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0819DB70
	.align 2, 0
_0819DB0C: .4byte 0x00000484
_0819DB10: .4byte 0x0000046C
_0819DB14:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r3, r5, #0
	adds r3, #0x10
	ldrb r4, [r0]
	ldr r2, _0819DB3C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0819DB40
	asrs r1, r0, #0xc
	b _0819DB46
	.align 2, 0
_0819DB3C: .4byte 0x085B0A08
_0819DB40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0819DB46:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0819DB5E
	asrs r0, r0, #0xc
	b _0819DB64
_0819DB5E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819DB64:
	strh r0, [r3, #4]
	ldr r6, _0819DB78 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0819DB70:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819DB78: .4byte 0x00000484

	thumb_func_start FUN_0819db7c
FUN_0819db7c: @ 0x0819DB7C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0819DB94 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819DB98
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819DB9A
	.align 2, 0
_0819DB94: .4byte 0x0000046C
_0819DB98:
	movs r0, #0
_0819DB9A:
	cmp r0, #0
	beq _0819DBC8
	ldr r4, _0819DC24 @ =FUN_0819bd2c
	movs r3, #0x22
	ldr r6, _0819DC28 @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819DC2C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_0819DBC8:
	ldr r6, _0819DC2C @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0819DC3C
	ldr r1, _0819DC30 @ =0x000005A4
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0
	ldr r3, _0819DC28 @ =0x0000046D
	adds r0, r5, r3
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r3, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0819DC34 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _0819DC38 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	b _0819DC46
	.align 2, 0
_0819DC24: .4byte FUN_0819bd2c
_0819DC28: .4byte 0x0000046D
_0819DC2C: .4byte 0x0000046B
_0819DC30: .4byte 0x000005A4
_0819DC34: .4byte 0x0000046A
_0819DC38: .4byte 0x00000484
_0819DC3C:
	ldr r0, _0819DC4C @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0819DC46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819DC4C: .4byte 0x00000484

	thumb_func_start FUN_0819dc50
FUN_0819dc50: @ 0x0819DC50
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0819DC70 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819DC74
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819DC76
	.align 2, 0
_0819DC70: .4byte 0x0000046C
_0819DC74:
	movs r0, #0
_0819DC76:
	cmp r0, #0
	beq _0819DCAC
	ldr r1, _0819DCE8 @ =0x000005A4
	adds r0, r4, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _0819DCEC @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819DCF0 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _0819DCF4 @ =0x00000EA6
	adds r0, r5, r2
	strb r1, [r0]
_0819DCAC:
	ldr r5, _0819DCF8 @ =0x00000484
	adds r3, r4, r5
	ldr r0, [r3]
	cmp r0, #0x3c
	ble _0819DCDC
	movs r2, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	subs r5, #0x1b
	adds r0, r4, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r4, r5
	strb r2, [r0]
	ldr r2, _0819DCF8 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r5, #2
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
_0819DCDC:
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819DCE8: .4byte 0x000005A4
_0819DCEC: .4byte 0x0000046D
_0819DCF0: .4byte 0x0000046B
_0819DCF4: .4byte 0x00000EA6
_0819DCF8: .4byte 0x00000484

	thumb_func_start FUN_0819dcfc
FUN_0819dcfc: @ 0x0819DCFC
	ldr r1, _0819DD08 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _0819DD0C @ =0x085ADDB8
	str r1, [r0]
	bx lr
	.align 2, 0
_0819DD08: .4byte 0x00000634
_0819DD0C: .4byte 0x085ADDB8

	thumb_func_start FUN_0819dd10
FUN_0819dd10: @ 0x0819DD10
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r1, _0819DD38 @ =0x085B0A08
	ldr r2, _0819DD3C @ =0x00000EA6
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0819DD40
	asrs r2, r0, #0xc
	b _0819DD46
	.align 2, 0
_0819DD38: .4byte 0x085B0A08
_0819DD3C: .4byte 0x00000EA6
_0819DD40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0819DD46:
	ldr r0, _0819DD6C @ =0x03002BE0
	ldr r1, [r0]
	adds r0, r2, #0
	adds r0, #0xdc
	ldrh r1, [r1, #0x2e]
	adds r0, r0, r1
	strh r0, [r4, #0xa]
	ldr r2, _0819DD70 @ =0x00000A7E
	adds r1, r3, r2
	strh r0, [r1]
	ldr r0, _0819DD74 @ =0x00000EA6
	adds r1, r3, r0
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0819DD6C: .4byte 0x03002BE0
_0819DD70: .4byte 0x00000A7E
_0819DD74: .4byte 0x00000EA6

	thumb_func_start FUN_0819dd78
FUN_0819dd78: @ 0x0819DD78
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _0819DDCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0819DDD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0819DDD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _0819DDB2
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0819DDB2:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0819DDCC: .4byte 0x030046B8
_0819DDD0: .4byte 0x000003FF
_0819DDD4: .4byte 0x0203B400

	thumb_func_start FUN_0819ddd8
FUN_0819ddd8: @ 0x0819DDD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	ldr r2, _0819DF9C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _0819DFA0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x8c
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r3, _0819DFA4 @ =FUN_0819aa98
	str r6, [sp]
	adds r0, r6, #0
	add r1, sp, #0xc
	adds r2, r4, #0
	bl FUN_080e3834
	add r2, sp, #0x1c
	mov sl, r2
	add r3, sp, #0x24
	mov sb, r3
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp, #0x30]
	ldr r1, [sp, #0x2c]
	ldr r2, _0819DFA8 @ =0x00000D9C
	adds r5, r1, r2
	movs r7, #1
_0819DE3E:
	ldrh r1, [r6]
	movs r3, #0x10
	mov r8, r3
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r5, #0
	ldr r2, _0819DFAC @ =0x00004001
	movs r3, #0
	bl FUN_0823646c
	movs r1, #0xc3
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r3, [r0]
	adds r0, r5, #0
	bl FUN_08236514
	adds r0, r5, #0
	adds r1, r6, #0
	adds r1, #8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	ldr r1, _0819DFA4 @ =FUN_0819aa98
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r5, #0
	bl FUN_08236400
	adds r5, #0x50
	subs r7, #1
	cmp r7, #0
	bge _0819DE3E
	ldr r2, _0819DF9C @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _0819DFA0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x1c]
	mov r1, sl
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	movs r0, #0
	str r0, [sp, #0x24]
	mov r3, sb
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r5, _0819DFB0 @ =0x00002401
	movs r0, #0x94
	lsls r0, r0, #1
	adds r4, r6, r0
	ldrh r1, [r6]
	mov r2, r8
	str r2, [sp]
	mov r3, sl
	str r3, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_0823646c
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r6, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	ldr r1, [sp, #0x30]
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0819DFB4 @ =FUN_0819aa94
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	ldr r0, [sp, #0x2c]
	ldr r1, _0819DFB8 @ =0x00000CFC
	adds r4, r0, r1
	lsls r5, r5, #0x10
	movs r7, #1
_0819DF2C:
	ldrh r1, [r6]
	movs r0, #0x10
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	mov r3, sb
	str r3, [sp, #8]
	adds r0, r4, #0
	lsrs r2, r5, #0x10
	movs r3, #0
	bl FUN_0823646c
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r6, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	ldr r1, [sp, #0x30]
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	ldr r1, _0819DFB4 @ =FUN_0819aa94
	adds r2, r6, #0
	bl FUN_0823651c
	adds r4, #0x50
	subs r7, #1
	cmp r7, #0
	bge _0819DF2C
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819DF9C: .4byte 0xFFFF0000
_0819DFA0: .4byte 0x0000FFFF
_0819DFA4: .4byte FUN_0819aa98
_0819DFA8: .4byte 0x00000D9C
_0819DFAC: .4byte 0x00004001
_0819DFB0: .4byte 0x00002401
_0819DFB4: .4byte FUN_0819aa94
_0819DFB8: .4byte 0x00000CFC

	thumb_func_start FUN_0819dfbc
FUN_0819dfbc: @ 0x0819DFBC
	movs r0, #4
	bx lr

	thumb_func_start FUN_0819dfc0
FUN_0819dfc0: @ 0x0819DFC0
	push {r4, r5, lr}
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r4, [r2]
	ldr r2, _0819DFF0 @ =0x00000EFC
	adds r5, r4, r2
	ldr r2, [r0, #8]
	ldr r3, [r0, #0xc]
	str r2, [r5]
	str r3, [r5, #4]
	ldr r3, _0819DFF4 @ =0x00000F04
	adds r2, r4, r3
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _0819DFF8 @ =0x00000EA4
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819DFF0: .4byte 0x00000EFC
_0819DFF4: .4byte 0x00000F04
_0819DFF8: .4byte 0x00000EA4

	thumb_func_start FUN_0819dffc
FUN_0819dffc: @ 0x0819DFFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	mov r8, r1
	ldr r1, _0819E090 @ =0x00000EFC
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #4]
	str r2, [sp, #8]
	ldr r3, _0819E094 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r3
	str r1, [sp, #4]
	ldr r1, _0819E098 @ =0x00000F04
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	ldr r1, [sp, #0xc]
	ands r1, r3
	str r1, [sp, #0xc]
	ldr r1, _0819E09C @ =0x00000EA4
	add r1, r8
	ldr r3, _0819E0A0 @ =0x00000EA8
	add r3, r8
	ldr r5, _0819E0A4 @ =0x000004A4
	adds r0, r0, r5
	ldr r0, [r0]
	adds r0, #0xc
	mov sb, r0
	add r7, sp, #4
	add r2, sp, #0xc
	ldrh r6, [r1]
	movs r1, #0
	ldrsh r0, [r3, r1]
	str r0, [sp, #0x24]
	add r4, sp, #0x14
	ldrh r0, [r2]
	ldrh r1, [r7]
	subs r0, r0, r1
	movs r3, #0
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	add r5, sp, #0x1c
	str r3, [sp]
	mov r0, sp
	adds r1, r5, #0
	ldr r2, _0819E0A8 @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	muls r0, r6, r0
	mov sl, r4
	mov ip, r5
	cmp r0, #0
	blt _0819E0AC
	asrs r0, r0, #0xa
	b _0819E0B2
	.align 2, 0
_0819E090: .4byte 0x00000EFC
_0819E094: .4byte 0x0000FFFF
_0819E098: .4byte 0x00000F04
_0819E09C: .4byte 0x00000EA4
_0819E0A0: .4byte 0x00000EA8
_0819E0A4: .4byte 0x000004A4
_0819E0A8: .4byte 0x05000002
_0819E0AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_0819E0B2:
	adds r1, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	cmp r0, #0
	blt _0819E0C0
	asrs r3, r0, #0xa
	b _0819E0C6
_0819E0C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r3, r0, #0
_0819E0C6:
	lsls r2, r3, #1
	lsls r0, r1, #1
	adds r4, r0, r1
	subs r0, r3, r0
	adds r0, r0, r6
	ldr r5, [sp, #0x24]
	adds r3, r0, #0
	muls r3, r5, r3
	str r3, [sp, #0x30]
	subs r0, r2, r4
	adds r0, #1
	mov r6, ip
	movs r3, #0
	ldrsh r1, [r6, r3]
	adds r5, r0, #0
	muls r5, r1, r5
	subs r6, r4, r2
	mov r1, sl
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r6, r0
	adds r0, r5, r0
	ldr r5, [sp, #0x30]
	adds r0, r0, r5
	cmp r0, #0
	blt _0819E0FE
	asrs r1, r0, #0xa
	b _0819E104
_0819E0FE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0819E104:
	ldrh r0, [r7]
	adds r0, r0, r1
	mov r6, sb
	strh r0, [r6]
	subs r3, r2, r4
	adds r0, r3, #1
	str r0, [sp, #0x28]
	mov r1, ip
	movs r5, #2
	ldrsh r0, [r1, r5]
	ldr r6, [sp, #0x28]
	adds r5, r6, #0
	muls r5, r0, r5
	rsbs r2, r2, #0
	adds r0, r2, r4
	mov r1, sl
	movs r6, #2
	ldrsh r1, [r1, r6]
	adds r6, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r5, r0
	ldr r1, [sp, #0x30]
	adds r0, r0, r1
	adds r0, #0
	cmp r0, #0
	blt _0819E13E
	asrs r1, r0, #0xa
	b _0819E144
_0819E13E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0819E144:
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #2]
	adds r1, r3, #1
	mov r6, ip
	movs r3, #4
	ldrsh r0, [r6, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	adds r1, r2, r4
	mov r6, sl
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	adds r0, r5, r0
	ldr r3, [sp, #0x30]
	adds r0, r0, r3
	adds r0, #0
	cmp r0, #0
	blt _0819E172
	asrs r1, r0, #0xa
	b _0819E178
_0819E172:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_0819E178:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #4]
	ldr r1, _0819E198 @ =0x00000EA4
	add r1, r8
	ldrh r2, [r1]
	ldr r0, _0819E19C @ =0x000003FF
	cmp r2, r0
	bhi _0819E1A0
	adds r0, r2, #0
	adds r0, #0x80
	strh r0, [r1]
	movs r0, #0
	b _0819E1A2
	.align 2, 0
_0819E198: .4byte 0x00000EA4
_0819E19C: .4byte 0x000003FF
_0819E1A0:
	movs r0, #1
_0819E1A2:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0819e1b4
FUN_0819e1b4: @ 0x0819E1B4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start enemy_ax_0819e1ec
enemy_ax_0819e1ec: @ 0x0819E1EC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0819E288 @ =0x00000EA4
	adds r0, r4, r2
	movs r1, #0
	movs r5, #0
	strh r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0819E28C @ =0x00000EA7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819E290 @ =0x00000EA8
	adds r0, r4, r1
	strh r5, [r0]
	subs r2, #0x5e
	adds r1, r4, r2
	ldr r2, _0819E294 @ =0x00000574
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0819E298 @ =0x00000F14
	adds r2, r4, r0
	ldr r0, _0819E29C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0819E2A0 @ =0x00000EFC
	adds r1, r4, r2
	str r5, [sp]
	mov r0, sp
	ldr r2, _0819E2A4 @ =0x05000002
	bl CpuSet
	ldr r0, _0819E2A8 @ =0x00000F04
	adds r1, r4, r0
	str r5, [sp]
	mov r0, sp
	ldr r2, _0819E2A4 @ =0x05000002
	bl CpuSet
	ldr r1, _0819E2AC @ =0x00000F0C
	adds r4, r4, r1
	str r5, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0819E2A4 @ =0x05000002
	bl CpuSet
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	ldr r1, _0819E2B0 @ =0x0825221C
	adds r0, r6, #0
	movs r2, #0xd2
	bl FUN_080e6768
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819E288: .4byte 0x00000EA4
_0819E28C: .4byte 0x00000EA7
_0819E290: .4byte 0x00000EA8
_0819E294: .4byte 0x00000574
_0819E298: .4byte 0x00000F14
_0819E29C: .4byte 0x03002BE0
_0819E2A0: .4byte 0x00000EFC
_0819E2A4: .4byte 0x05000002
_0819E2A8: .4byte 0x00000F04
_0819E2AC: .4byte 0x00000F0C
_0819E2B0: .4byte 0x0825221C

	thumb_func_start FUN_0819e2b4
FUN_0819e2b4: @ 0x0819E2B4
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #0xd
	movs r2, #0xbe
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r0, _0819E2EC @ =0x00000E48
	adds r1, r1, r0
	movs r2, #0x12
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	mov r2, ip
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _0819E2F0 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_0819E2EC: .4byte 0x00000E48
_0819E2F0: .4byte 0x0000FFFB

	thumb_func_start FUN_0819e2f4
FUN_0819e2f4: @ 0x0819E2F4
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _0819E318
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _0819E31C
_0819E318:
	str r1, [r3]
	movs r0, #0
_0819E31C:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0819e324
FUN_0819e324: @ 0x0819E324
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0819dfc0
	adds r0, r4, #0
	bl FUN_0819dffc
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r6, #0
	strb r6, [r0]
	ldr r3, _0819E3BC @ =0x00000469
	adds r0, r4, r3
	strb r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r4, r3
	str r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	add r2, sp, #4
	adds r3, r4, #0
	adds r3, #8
	ldrh r0, [r5]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r1, #0xee
	lsls r1, r1, #1
	adds r4, r4, r1
	strb r0, [r4]
	ldr r2, _0819E3C0 @ =0x00000F0C
	add r8, r2
	str r6, [sp]
	mov r0, sp
	mov r1, r8
	ldr r2, _0819E3C4 @ =0x05000002
	bl CpuSet
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819E3BC: .4byte 0x00000469
_0819E3C0: .4byte 0x00000F0C
_0819E3C4: .4byte 0x05000002

	thumb_func_start FUN_0819e3c8
FUN_0819e3c8: @ 0x0819E3C8
	mov ip, r0
	movs r2, #0xc0
	lsls r2, r2, #1
	add r2, ip
	ldr r0, _0819E408 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	movs r3, #0
	strh r0, [r2]
	movs r2, #0xbc
	lsls r2, r2, #1
	add r2, ip
	ldr r1, _0819E40C @ =0xFBFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	ldr r0, _0819E410 @ =0x00000E48
	adds r1, r1, r0
	movs r2, #0x11
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _0819E414 @ =0x0000024E
	add r0, ip
	strh r3, [r0]
	bx lr
	.align 2, 0
_0819E408: .4byte 0xFFFFFEFF
_0819E40C: .4byte 0xFBFFFFFF
_0819E410: .4byte 0x00000E48
_0819E414: .4byte 0x0000024E

	thumb_func_start FUN_0819e418
FUN_0819e418: @ 0x0819E418
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819E434
	b _0819E55E
_0819E434:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819E448
	b _0819E55E
_0819E448:
	movs r1, #0x10
	ldr r2, _0819E45C @ =0x00000E48
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819E460
	movs r0, #1
	b _0819E462
	.align 2, 0
_0819E45C: .4byte 0x00000E48
_0819E460:
	movs r0, #0
_0819E462:
	adds r1, r0, #0
	cmp r1, #0
	bne _0819E474
	ldr r2, _0819E470 @ =0x0000024E
	adds r0, r6, r2
	strh r1, [r0]
	b _0819E55E
	.align 2, 0
_0819E470: .4byte 0x0000024E
_0819E474:
	ldr r0, _0819E484 @ =0x0000024E
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0819E488
	subs r0, #1
	strh r0, [r1]
	b _0819E55E
	.align 2, 0
_0819E484: .4byte 0x0000024E
_0819E488:
	adds r0, r6, #0
	bl FUN_0819dd78
	mov r7, sp
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r7, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0819E4C2
	cmp r1, #0
	blt _0819E4C2
	ldr r0, _0819E4C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0819E4C2
	ldr r0, _0819E4CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0819E4D0
_0819E4C2:
	movs r4, #0
	b _0819E4DE
	.align 2, 0
_0819E4C8: .4byte 0x030046A8
_0819E4CC: .4byte 0x030046AC
_0819E4D0:
	ldr r0, _0819E4F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0819E4DE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0819E4F4
	adds r0, #4
	b _0819E500
	.align 2, 0
_0819E4F0: .4byte 0x030046A4
_0819E4F4:
	ldr r0, _0819E514 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0819E500:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0819E518
	cmp r2, #2
	beq _0819E51C
	b _0819E520
	.align 2, 0
_0819E514: .4byte 0x030046A4
_0819E518:
	ldrb r0, [r7, #4]
	b _0819E51E
_0819E51C:
	ldrb r0, [r7]
_0819E51E:
	subs r1, r1, r0
_0819E520:
	movs r4, #0
	movs r5, #0
	strh r1, [r7, #2]
	adds r0, r6, #0
	mov r1, sp
	bl FUN_0819e324
	adds r0, r6, #0
	bl FUN_0819e3c8
	adds r0, r6, #0
	bl FUN_0819e2b4
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _0819E568 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #2
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
_0819E55E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819E568: .4byte 0x00000484

	thumb_func_start FUN_0819e56c
FUN_0819e56c: @ 0x0819E56C
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0819E5AA
	movs r4, #0
_0819E584:
	lsls r0, r4, #1
	ldr r2, _0819E59C @ =0x00000EBC
	adds r1, r6, r2
	adds r5, r1, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0819E5A0
	bl Script_GetValue
	b _0819E5A2
	.align 2, 0
_0819E59C: .4byte 0x00000EBC
_0819E5A0:
	movs r0, #0
_0819E5A2:
	strh r0, [r5]
	adds r4, #1
	cmp r4, #3
	ble _0819E584
_0819E5AA:
	movs r1, #0
	movs r4, #3
	ldr r2, _0819E5D0 @ =0x00000EBA
	adds r0, r6, r2
_0819E5B2:
	strh r1, [r0]
	subs r0, #2
	subs r4, #1
	cmp r4, #0
	bge _0819E5B2
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0819E5D4
	asrs r1, r0, #2
	b _0819E5DA
	.align 2, 0
_0819E5D0: .4byte 0x00000EBA
_0819E5D4:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_0819E5DA:
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	subs r0, r0, r1
	movs r2, #0xeb
	lsls r2, r2, #4
	adds r1, r6, r2
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0819e5f4
FUN_0819e5f4: @ 0x0819E5F4
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _0819E61C @ =0x00000EB4
	adds r1, r0, r2
	movs r2, #3
_0819E604:
	ldrh r0, [r1]
	cmp r0, #0
	beq _0819E60E
	subs r0, #1
	strh r0, [r1]
_0819E60E:
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0819E604
	pop {r0}
	bx r0
	.align 2, 0
_0819E61C: .4byte 0x00000EB4

	thumb_func_start FUN_0819e620
FUN_0819e620: @ 0x0819E620
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r2, [r0]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r3, r4
	movs r5, #0
	ldrsh r1, [r0, r5]
	ldr r4, _0819E650 @ =0x00000546
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r1, r0
	bgt _0819E658
	ldr r5, _0819E654 @ =0x00000EBA
	adds r0, r2, r5
	ldrh r4, [r0]
	cmp r4, #0
	bne _0819E658
	movs r1, #2
	movs r2, #8
	b _0819E74A
	.align 2, 0
_0819E650: .4byte 0x00000546
_0819E654: .4byte 0x00000EBA
_0819E658:
	ldr r5, _0819E688 @ =0x00000EB4
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _0819E710
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r1, [r0]
	ldr r0, _0819E68C @ =0x0000FFFE
	cmp r1, r0
	bhi _0819E710
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrb r2, [r0]
	adds r1, r2, #0
	subs r1, #0xa0
	cmp r1, #0x80
	ble _0819E694
	ldr r4, _0819E690 @ =0xFFFFFE60
	adds r1, r2, r4
	b _0819E6A0
	.align 2, 0
_0819E688: .4byte 0x00000EB4
_0819E68C: .4byte 0x0000FFFE
_0819E690: .4byte 0xFFFFFE60
_0819E694:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819E6A0
	adds r1, r2, #0
	adds r1, #0x60
_0819E6A0:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819E6A8
	rsbs r0, r0, #0
_0819E6A8:
	cmp r0, #0x29
	bgt _0819E6D8
	movs r2, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r1, #0
	strb r1, [r0]
	ldr r4, _0819E6D0 @ =0x00000469
	adds r0, r3, r4
	strb r2, [r0]
	adds r5, #2
	adds r0, r3, r5
	strb r1, [r0]
	ldr r2, _0819E6D4 @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r4, #3
	adds r1, r3, r4
	b _0819E6FA
	.align 2, 0
_0819E6D0: .4byte 0x00000469
_0819E6D4: .4byte 0x00000484
_0819E6D8:
	movs r1, #2
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r2, #0
	strb r2, [r0]
	ldr r4, _0819E704 @ =0x00000469
	adds r0, r3, r4
	strb r1, [r0]
	adds r5, #2
	adds r0, r3, r5
	strb r1, [r0]
	ldr r1, _0819E708 @ =0x00000484
	adds r0, r3, r1
	str r2, [r0]
	ldr r2, _0819E70C @ =0x0000046C
	adds r1, r3, r2
_0819E6FA:
	movs r0, #1
	strb r0, [r1]
	movs r0, #1
	b _0819E782
	.align 2, 0
_0819E704: .4byte 0x00000469
_0819E708: .4byte 0x00000484
_0819E70C: .4byte 0x0000046C
_0819E710:
	movs r4, #0xeb
	lsls r4, r4, #4
	adds r0, r2, r4
	ldrh r1, [r0]
	movs r5, #0xc2
	lsls r5, r5, #1
	adds r0, r3, r5
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	blt _0819E780
	ldr r5, _0819E738 @ =0x00000EB6
	adds r0, r2, r5
	ldrh r4, [r0]
	cmp r4, #0
	bne _0819E73C
	movs r1, #2
	movs r2, #4
	b _0819E74A
	.align 2, 0
_0819E738: .4byte 0x00000EB6
_0819E73C:
	ldr r5, _0819E770 @ =0x00000EB8
	adds r0, r2, r5
	ldrh r4, [r0]
	cmp r4, #0
	bne _0819E780
	movs r1, #2
	movs r2, #6
_0819E74A:
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	strb r4, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r1, [r0]
	ldr r1, _0819E774 @ =0x0000046A
	adds r0, r3, r1
	strb r2, [r0]
	ldr r2, _0819E778 @ =0x00000484
	adds r0, r3, r2
	str r4, [r0]
	ldr r4, _0819E77C @ =0x0000046C
	adds r1, r3, r4
	movs r0, #1
	strb r0, [r1]
	b _0819E782
	.align 2, 0
_0819E770: .4byte 0x00000EB8
_0819E774: .4byte 0x0000046A
_0819E778: .4byte 0x00000484
_0819E77C: .4byte 0x0000046C
_0819E780:
	movs r0, #0
_0819E782:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0819e788
FUN_0819e788: @ 0x0819E788
	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r2, #0
	ldr r0, _0819E7B8 @ =0x00000EC4
	adds r3, r4, r0
	movs r5, #0xff
_0819E79A:
	adds r1, r3, r2
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r2, #1
	cmp r2, #2
	ble _0819E79A
	ldr r0, _0819E7BC @ =0x00000EC7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819E7B8: .4byte 0x00000EC4
_0819E7BC: .4byte 0x00000EC7

	thumb_func_start FUN_0819e7c0
FUN_0819e7c0: @ 0x0819E7C0
	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r3, _0819E7F0 @ =0x00000EC7
	adds r2, r0, r3
	subs r3, #3
	adds r0, r0, r3
	ldrb r3, [r2]
	adds r0, r0, r3
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0819E7EA
	movs r0, #0
	strb r0, [r2]
_0819E7EA:
	pop {r0}
	bx r0
	.align 2, 0
_0819E7F0: .4byte 0x00000EC7

	thumb_func_start FUN_0819e7f4
FUN_0819e7f4: @ 0x0819E7F4
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #0
	ldr r4, _0819E814 @ =0x00000EC4
	adds r3, r0, r4
_0819E804:
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, r1
	bne _0819E818
	movs r0, #1
	b _0819E820
	.align 2, 0
_0819E814: .4byte 0x00000EC4
_0819E818:
	adds r2, #1
	cmp r2, #2
	ble _0819E804
	movs r0, #0
_0819E820:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0819e828
FUN_0819e828: @ 0x0819E828
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819E874
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	ldr r0, _0819E878 @ =0x00000F14
	adds r2, r2, r0
	ldr r0, _0819E87C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0819E874
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _0819E880
_0819E874:
	movs r0, #0
	b _0819E882
	.align 2, 0
_0819E878: .4byte 0x00000F14
_0819E87C: .4byte 0x03002BE0
_0819E880:
	movs r0, #1
_0819E882:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0819e888
FUN_0819e888: @ 0x0819E888
	bx lr
	.align 2, 0

	thumb_func_start FUN_0819e88c
FUN_0819e88c: @ 0x0819E88C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _0819E900 @ =0x00000ECC
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0
	beq _0819E8BE
	ldr r3, _0819E904 @ =0x00000ECB
	adds r0, r4, r3
	movs r2, #0
	strb r2, [r0]
	ldr r1, _0819E908 @ =0x00000ECA
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0x80
	ldr r0, _0819E90C @ =0x00000E48
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	strb r2, [r5]
_0819E8BE:
	ldr r1, _0819E910 @ =0x00000ECD
	adds r3, r4, r1
	ldrb r0, [r3]
	ldr r2, _0819E90C @ =0x00000E48
	adds r5, r4, r2
	cmp r0, #0
	beq _0819E8EE
	movs r1, #0x80
	lsls r1, r1, #1
	ldr r0, [r5]
	orrs r0, r1
	movs r1, #0x81
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r0, _0819E904 @ =0x00000ECB
	adds r1, r4, r0
	movs r2, #0
	movs r0, #3
	strb r0, [r1]
	ldr r1, _0819E908 @ =0x00000ECA
	adds r0, r4, r1
	strb r2, [r0]
	strb r2, [r3]
_0819E8EE:
	movs r1, #0xc0
	lsls r1, r1, #1
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0819E914
	movs r0, #1
	b _0819E916
	.align 2, 0
_0819E900: .4byte 0x00000ECC
_0819E904: .4byte 0x00000ECB
_0819E908: .4byte 0x00000ECA
_0819E90C: .4byte 0x00000E48
_0819E910: .4byte 0x00000ECD
_0819E914:
	movs r0, #0
_0819E916:
	cmp r0, #0
	beq _0819E9FE
	ldr r1, [r6, #0x44]
	movs r0, #0xfa
	strh r0, [r1, #0x32]
	ldr r1, [r6, #0x44]
	ldr r2, _0819E93C @ =0x0000093C
	adds r0, r4, r2
	str r0, [r1, #0x38]
	ldr r3, _0819E940 @ =0x00000ECB
	adds r0, r4, r3
	ldrb r1, [r0]
	cmp r1, #1
	beq _0819E95C
	cmp r1, #1
	bgt _0819E944
	cmp r1, #0
	beq _0819E94E
	b _0819E97C
	.align 2, 0
_0819E93C: .4byte 0x0000093C
_0819E940: .4byte 0x00000ECB
_0819E944:
	cmp r1, #2
	beq _0819E968
	cmp r1, #3
	beq _0819E974
	b _0819E97C
_0819E94E:
	ldr r2, _0819E958 @ =0x0000093E
	adds r0, r4, r2
	strh r1, [r0]
	b _0819E97C
	.align 2, 0
_0819E958: .4byte 0x0000093E
_0819E95C:
	ldr r3, _0819E964 @ =0x0000093E
	adds r1, r4, r3
	movs r0, #0x10
	b _0819E97A
	.align 2, 0
_0819E964: .4byte 0x0000093E
_0819E968:
	ldr r0, _0819E970 @ =0x0000093E
	adds r1, r4, r0
	movs r0, #0x18
	b _0819E97A
	.align 2, 0
_0819E970: .4byte 0x0000093E
_0819E974:
	ldr r2, _0819E99C @ =0x0000093E
	adds r1, r4, r2
	movs r0, #0x1f
_0819E97A:
	strh r0, [r1]
_0819E97C:
	ldr r3, _0819E9A0 @ =0x00000ECA
	adds r1, r4, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0819E9FE
	movs r1, #0x80
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0819E9A4
	movs r0, #1
	b _0819E9A6
	.align 2, 0
_0819E99C: .4byte 0x0000093E
_0819E9A0: .4byte 0x00000ECA
_0819E9A4:
	movs r0, #0
_0819E9A6:
	cmp r0, #0
	bne _0819E9E8
	ldr r0, _0819E9DC @ =0x00000ECB
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819E9F6
	ldr r0, [r6, #0x44]
	adds r0, #0x2c
	ldr r2, _0819E9E0 @ =0x0000047A
	adds r1, r6, r2
	ldrh r1, [r1]
	movs r3, #0x90
	lsls r3, r3, #3
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r1, r1, r2
	bl FUN_0822b20c
	ldr r1, _0819E9E4 @ =0xFFFFFEFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	b _0819E9FE
	.align 2, 0
_0819E9DC: .4byte 0x00000ECB
_0819E9E0: .4byte 0x0000047A
_0819E9E4: .4byte 0xFFFFFEFF
_0819E9E8:
	ldr r0, _0819EA04 @ =0x00000ECB
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0819E9F6
	adds r0, #1
	strb r0, [r1]
_0819E9F6:
	ldr r2, _0819EA08 @ =0x00000ECA
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0819E9FE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819EA04: .4byte 0x00000ECB
_0819EA08: .4byte 0x00000ECA

	thumb_func_start FUN_0819ea0c
FUN_0819ea0c: @ 0x0819EA0C
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	ldr r2, _0819EA68 @ =0x00000ECC
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0
	beq _0819EA40
	ldr r1, [r3, #0x44]
	movs r2, #0
	movs r0, #0xfa
	strh r0, [r1, #0x32]
	ldr r1, [r3, #0x44]
	ldr r6, _0819EA6C @ =0x0000093C
	adds r0, r4, r6
	str r0, [r1, #0x38]
	ldr r1, _0819EA70 @ =0x00000ECB
	adds r0, r4, r1
	strb r2, [r0]
	ldr r6, _0819EA74 @ =0x00000ECA
	adds r0, r4, r6
	strb r2, [r0]
	strb r2, [r5]
_0819EA40:
	ldr r0, _0819EA78 @ =0x00000ECD
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0819EA80
	ldr r0, [r3, #0x44]
	adds r0, #0x2c
	ldr r2, _0819EA7C @ =0x0000047A
	adds r1, r3, r2
	ldrh r1, [r1]
	movs r4, #0x90
	lsls r4, r4, #3
	adds r2, r3, r4
	ldrh r2, [r2]
	adds r1, r1, r2
	bl FUN_0822b20c
	movs r0, #0
	strb r0, [r5]
	b _0819EB24
	.align 2, 0
_0819EA68: .4byte 0x00000ECC
_0819EA6C: .4byte 0x0000093C
_0819EA70: .4byte 0x00000ECB
_0819EA74: .4byte 0x00000ECA
_0819EA78: .4byte 0x00000ECD
_0819EA7C: .4byte 0x0000047A
_0819EA80:
	ldr r0, [r3, #0x44]
	ldrh r0, [r0, #0x32]
	cmp r0, #0xfa
	bne _0819EB24
	ldr r6, _0819EA9C @ =0x00000ECB
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #6
	bhi _0819EAEC
	lsls r0, r0, #2
	ldr r1, _0819EAA0 @ =_0819EAA4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0819EA9C: .4byte 0x00000ECB
_0819EAA0: .4byte _0819EAA4
_0819EAA4: @ jump table
	.4byte _0819EAC0 @ case 0
	.4byte _0819EACC @ case 1
	.4byte _0819EAD8 @ case 2
	.4byte _0819EAE4 @ case 3
	.4byte _0819EAD8 @ case 4
	.4byte _0819EACC @ case 5
	.4byte _0819EAC0 @ case 6
_0819EAC0:
	ldr r0, _0819EAC8 @ =0x0000093E
	adds r1, r4, r0
	movs r0, #0
	b _0819EAEA
	.align 2, 0
_0819EAC8: .4byte 0x0000093E
_0819EACC:
	ldr r2, _0819EAD4 @ =0x0000093E
	adds r1, r4, r2
	movs r0, #0x10
	b _0819EAEA
	.align 2, 0
_0819EAD4: .4byte 0x0000093E
_0819EAD8:
	ldr r6, _0819EAE0 @ =0x0000093E
	adds r1, r4, r6
	movs r0, #0x18
	b _0819EAEA
	.align 2, 0
_0819EAE0: .4byte 0x0000093E
_0819EAE4:
	ldr r0, _0819EB0C @ =0x0000093E
	adds r1, r4, r0
	movs r0, #0x1f
_0819EAEA:
	strh r0, [r1]
_0819EAEC:
	ldr r2, _0819EB10 @ =0x00000ECA
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0819EB24
	ldr r6, _0819EB14 @ =0x00000ECB
	adds r1, r4, r6
	ldrb r0, [r1]
	cmp r0, #5
	bls _0819EB18
	movs r0, #0
	b _0819EB1A
	.align 2, 0
_0819EB0C: .4byte 0x0000093E
_0819EB10: .4byte 0x00000ECA
_0819EB14: .4byte 0x00000ECB
_0819EB18:
	adds r0, #1
_0819EB1A:
	strb r0, [r1]
	ldr r0, _0819EB2C @ =0x00000ECA
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_0819EB24:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819EB2C: .4byte 0x00000ECA

	thumb_func_start FUN_0819eb30
FUN_0819eb30: @ 0x0819EB30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r3, [sp]
	str r0, [sp, #4]
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r7, r0, r3
	ldr r0, _0819EB70 @ =0x03003584
	lsls r3, r1, #5
	ldr r0, [r0]
	lsls r2, r2, #5
	adds r2, r0, r2
	str r2, [sp, #8]
	strh r1, [r7, #0x22]
	adds r0, r0, r3
	mov sl, r0
	movs r0, #0
	mov sb, r0
	movs r1, #0xf
	str r1, [sp, #0xc]
_0819EB60:
	ldrh r0, [r7, #0x20]
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r0, r2
	beq _0819EB74
	mov r3, sb
	adds r0, r7, r3
	b _0819EB78
	.align 2, 0
_0819EB70: .4byte 0x03003584
_0819EB74:
	ldr r0, [sp, #8]
	add r0, sb
_0819EB78:
	ldrh r5, [r0]
	adds r3, r7, #0
	adds r3, #0x84
	add r3, sb
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	mov r8, r5
	mov r1, r8
	movs r2, #0x1f
	ands r1, r2
	mov r8, r1
	subs r0, r0, r1
	lsls r0, r0, #8
	strh r0, [r3]
	adds r6, r7, #0
	adds r6, #0xa4
	add r6, sb
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #5
	ands r0, r2
	asrs r2, r5, #5
	movs r1, #0x1f
	ands r2, r1
	subs r0, r0, r2
	lsls r0, r0, #8
	strh r0, [r6]
	adds r4, r7, #0
	adds r4, #0xc4
	add r4, sb
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r5, r5, #0xa
	ands r5, r1
	subs r0, r0, r5
	lsls r0, r0, #8
	strh r0, [r4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	ldr r1, [sp]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	bl Div
	ldr r3, [sp, #0x14]
	strh r0, [r3]
	movs r3, #0
	ldrsh r0, [r6, r3]
	ldr r1, [sp]
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r4, r1]
	ldr r1, [sp]
	bl Div
	strh r0, [r4]
	adds r0, r7, #0
	adds r0, #0x24
	add r0, sb
	mov r3, r8
	lsls r3, r3, #8
	strh r3, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	add r0, sb
	ldr r2, [sp, #0x10]
	lsls r2, r2, #8
	strh r2, [r0]
	adds r0, r7, #0
	adds r0, #0x64
	add r0, sb
	lsls r5, r5, #8
	strh r5, [r0]
	movs r0, #2
	add sl, r0
	add sb, r0
	ldr r1, [sp, #0xc]
	subs r1, #1
	str r1, [sp, #0xc]
	cmp r1, #0
	bge _0819EB60
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r7, #0x20]
	movs r2, #2
	ldr r3, [sp, #4]
	ldr r0, _0819EC4C @ =0x00000E48
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819EC4C: .4byte 0x00000E48

	thumb_func_start FUN_0819ec50
FUN_0819ec50: @ 0x0819EC50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819EC6A
	b _0819EDB0
_0819EC6A:
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r2, [r0]
	movs r1, #2
	ldr r3, _0819EC84 @ =0x00000E48
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819EC88
	movs r0, #1
	b _0819EC8A
	.align 2, 0
_0819EC84: .4byte 0x00000E48
_0819EC88:
	movs r0, #0
_0819EC8A:
	cmp r0, #0
	bne _0819EC90
	b _0819EDB0
_0819EC90:
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r7, r2, r0
	ldrh r0, [r7, #0x20]
	cmp r0, #0
	bne _0819ECC4
	ldr r1, _0819ECC0 @ =0x02008000
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, r8
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0819ECAE
	b _0819EDB8
_0819ECAE:
	mov r1, r8
	ldr r0, [r1, #0x44]
	str r7, [r0, #0x38]
	mov r0, r8
	adds r1, r7, #0
	bl FUN_0819ee1c
	b _0819EDB8
	.align 2, 0
_0819ECC0: .4byte 0x02008000
_0819ECC4:
	movs r3, #0xbc
	lsls r3, r3, #1
	add r3, r8
	str r3, [sp]
	ldr r0, _0819ED28 @ =0x0000067C
	adds r0, r2, r0
	str r0, [sp, #4]
	ldr r1, _0819ED2C @ =0x000006DC
	adds r1, r2, r1
	str r1, [sp, #8]
	ldr r3, _0819ED30 @ =0x000006FC
	adds r3, r3, r2
	mov sl, r3
	ldr r0, _0819ED34 @ =0x0000071C
	adds r0, r0, r2
	mov sb, r0
	adds r5, r7, #0
	ldr r1, _0819ED38 @ =0x000006BC
	adds r4, r2, r1
	movs r3, #0
	mov ip, r3
	ldr r0, _0819ED3C @ =0x0000069C
	adds r3, r2, r0
_0819ECF2:
	ldr r1, [sp, #4]
	add r1, ip
	ldr r0, [sp, #8]
	add r0, ip
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	mov r0, sl
	add r0, ip
	ldrh r0, [r0]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	mov r0, sb
	add r0, ip
	ldrh r0, [r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _0819ED40
	asrs r0, r0, #8
	b _0819ED46
	.align 2, 0
_0819ED28: .4byte 0x0000067C
_0819ED2C: .4byte 0x000006DC
_0819ED30: .4byte 0x000006FC
_0819ED34: .4byte 0x0000071C
_0819ED38: .4byte 0x000006BC
_0819ED3C: .4byte 0x0000069C
_0819ED40:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0819ED46:
	adds r6, r0, #0
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _0819ED54
	asrs r0, r0, #8
	b _0819ED5A
_0819ED54:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0819ED5A:
	adds r2, r0, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _0819ED68
	asrs r1, r0, #8
	b _0819ED6E
_0819ED68:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0819ED6E:
	lsls r0, r2, #5
	orrs r0, r6
	lsls r1, r1, #0xa
	orrs r1, r0
	strh r1, [r5]
	adds r5, #2
	adds r4, #2
	movs r2, #2
	add ip, r2
	adds r3, #2
	adds r0, r7, #0
	adds r0, #0x1e
	cmp r5, r0
	ble _0819ECF2
	ldrh r0, [r7, #0x20]
	subs r0, #1
	strh r0, [r7, #0x20]
	ldr r1, _0819EDB4 @ =0x02008000
	ldr r3, [sp]
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0819EDAA
	mov r1, r8
	ldr r0, [r1, #0x44]
	str r7, [r0, #0x38]
	mov r0, r8
	adds r1, r7, #0
	bl FUN_0819ee1c
_0819EDAA:
	ldrh r0, [r7, #0x20]
	cmp r0, #0
	beq _0819EDB8
_0819EDB0:
	movs r0, #0
	b _0819EDBA
	.align 2, 0
_0819EDB4: .4byte 0x02008000
_0819EDB8:
	movs r0, #1
_0819EDBA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0819edcc
FUN_0819edcc: @ 0x0819EDCC
	push {r4, r5, r6, r7, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	ldr r0, [r0, #0x44]
	movs r5, #0
	ldr r4, [r0, #0x38]
	ldr r0, _0819EE14 @ =0x000008DC
	adds r2, r1, r0
	subs r0, #0x20
	adds r3, r1, r0
	movs r7, #0
	ldr r6, _0819EE18 @ =0x00007FFF
	adds r0, #0x60
	adds r1, r1, r0
_0819EDEC:
	strh r7, [r3]
	movs r0, #0x1f
	strh r0, [r2]
	movs r0, #0xf8
	lsls r0, r0, #7
	strh r0, [r2, #0x20]
	strh r6, [r1]
	ldrh r0, [r4]
	strh r0, [r1, #0x20]
	adds r4, #2
	adds r2, #2
	adds r3, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _0819EDEC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819EE14: .4byte 0x000008DC
_0819EE18: .4byte 0x00007FFF

	thumb_func_start FUN_0819ee1c
FUN_0819ee1c: @ 0x0819EE1C
	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r2, #3
	ldr r3, _0819EE3C @ =0x00000894
	adds r0, r0, r3
_0819EE2C:
	str r1, [r0]
	subs r0, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0819EE2C
	pop {r0}
	bx r0
	.align 2, 0
_0819EE3C: .4byte 0x00000894

	thumb_func_start FUN_0819ee40
FUN_0819ee40: @ 0x0819EE40
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0819EE6C @ =0x00000774
	adds r3, r0, r1
	subs r1, #6
	adds r0, r0, r1
	movs r1, #3
_0819EE56:
	strh r2, [r0]
	str r4, [r3]
	adds r3, #0x60
	adds r0, #0x60
	subs r1, #1
	cmp r1, #0
	bge _0819EE56
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0819EE6C: .4byte 0x00000774

	thumb_func_start FUN_0819ee70
FUN_0819ee70: @ 0x0819EE70
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	movs r2, #0
	mov sb, r2
	movs r0, #0xed
	lsls r0, r0, #3
	adds r5, r6, r0
	ldr r1, _0819EEFC @ =0x0000073C
	adds r4, r6, r1
	movs r7, #0
	movs r2, #3
	mov r8, r2
_0819EE94:
	adds r0, r5, #0
	ldr r1, _0819EF00 @ =0x00005291
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r0, #0xf7
	strh r0, [r4, #0x32]
	ldr r1, _0819EF04 @ =0x00000774
	adds r0, r6, r1
	adds r0, r0, r7
	ldr r2, _0819EF08 @ =0x000008BC
	adds r1, r6, r2
	str r1, [r0]
	ldr r0, _0819EF0C @ =0x0000922E
	ldr r1, _0819EF10 @ =0x00003F72
	bl GetFile
	ldr r2, _0819EF14 @ =0x00000794
	adds r1, r6, r2
	adds r1, r1, r7
	str r0, [r1]
	ldr r0, _0819EF18 @ =0x00000201
	str r0, [r4]
	mov r0, sb
	strh r0, [r5, #0x30]
	adds r5, #0x60
	adds r4, #0x60
	adds r7, #0x60
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r2, r8
	cmp r2, #0
	bge _0819EE94
	movs r1, #0
	ldr r2, _0819EF1C @ =0x00000E44
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _0819EF20 @ =0x00000E46
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819EEFC: .4byte 0x0000073C
_0819EF00: .4byte 0x00005291
_0819EF04: .4byte 0x00000774
_0819EF08: .4byte 0x000008BC
_0819EF0C: .4byte 0x0000922E
_0819EF10: .4byte 0x00003F72
_0819EF14: .4byte 0x00000794
_0819EF18: .4byte 0x00000201
_0819EF1C: .4byte 0x00000E44
_0819EF20: .4byte 0x00000E46

	thumb_func_start FUN_0819ef24
FUN_0819ef24: @ 0x0819EF24
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r7, [r0]
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r0, [r0]
	movs r2, #1
	mov sb, r2
	ands r0, r2
	cmp r0, #0
	beq _0819EF4A
	b _0819F134
_0819EF4A:
	movs r0, #0xe5
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r3, _0819EFD0 @ =0x00000E46
	adds r1, r7, r3
	ldrh r1, [r1]
	bl Mod
	mov ip, r0
	cmp r0, #0
	beq _0819EF64
	b _0819F134
_0819EF64:
	mov r6, r8
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	ldrh r2, [r0, #0xa]
	ldr r0, _0819EFD4 @ =0x00000E44
	adds r4, r7, r0
	ldrh r0, [r4]
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #5
	ldr r5, _0819EFD8 @ =0x0000073C
	adds r0, r3, r5
	adds r0, r7, r0
	adds r0, #0x48
	ldr r6, _0819EFDC @ =0x00000794
	adds r1, r7, r6
	adds r1, r1, r3
	ldr r1, [r1]
	mov r3, ip
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r6, r0, r7
	adds r6, r6, r5
	adds r4, r0, r7
	ldr r0, _0819EFE0 @ =0x00000784
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sb
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _0819EFE4
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0819EFEC
	.align 2, 0
_0819EFD0: .4byte 0x00000E46
_0819EFD4: .4byte 0x00000E44
_0819EFD8: .4byte 0x0000073C
_0819EFDC: .4byte 0x00000794
_0819EFE0: .4byte 0x00000784
_0819EFE4:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0819EFEC:
	str r0, [r6]
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
	beq _0819F010
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0819F018
_0819F010:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0819F018:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0819F050 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _0819F088
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0819F054
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0819F048
	ldrb r0, [r4, #5]
_0819F048:
	subs r0, #1
	strh r0, [r4, #8]
	b _0819F064
	.align 2, 0
_0819F050: .4byte 0x0000FFFF
_0819F054:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0819F064
	strh r1, [r4, #8]
_0819F064:
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
	bne _0819F088
	movs r0, #1
	strb r0, [r4, #7]
_0819F088:
	ldr r3, _0819F144 @ =0x00000E44
	adds r4, r7, r3
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r6, #0xeb
	lsls r6, r6, #3
	adds r2, r7, r6
	adds r2, r2, r0
	mov r3, r8
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	subs r6, #0x1c
	adds r3, r7, r6
	adds r0, r3, r0
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r3, r3, r0
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	movs r1, #0xf3
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #8
	strh r1, [r0]
	mov r3, r8
	ldr r2, [r3, #0x44]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldrb r1, [r2, #6]
	adds r6, #6
	adds r0, r0, r6
	strb r1, [r0]
	ldr r2, [r3, #0x44]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldrb r1, [r2, #8]
	ldr r2, _0819F148 @ =0x00000744
	adds r0, r0, r2
	strb r1, [r0]
	ldr r2, [r3, #0x44]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldrb r1, [r2, #9]
	ldr r3, _0819F14C @ =0x00000745
	adds r0, r0, r3
	strb r1, [r0]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0819F134
	movs r0, #0
	strh r0, [r4]
_0819F134:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819F144: .4byte 0x00000E44
_0819F148: .4byte 0x00000744
_0819F14C: .4byte 0x00000745

	thumb_func_start FUN_0819f150
FUN_0819f150: @ 0x0819F150
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	mov sl, r1
	str r2, [sp, #4]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r7, [r0]
	mov r1, r8
	ldr r0, [r1, #0x44]
	ldr r0, [r0]
	movs r2, #1
	mov sb, r2
	ands r0, r2
	cmp r0, #0
	beq _0819F17C
	b _0819F368
_0819F17C:
	movs r0, #0xe5
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	ldr r3, _0819F204 @ =0x00000E46
	adds r1, r7, r3
	ldrh r1, [r1]
	bl Mod
	mov ip, r0
	cmp r0, #0
	beq _0819F196
	b _0819F368
_0819F196:
	mov r6, r8
	ldr r0, [r6, #0x44]
	adds r0, #0x48
	ldrh r2, [r0, #0xa]
	ldr r0, _0819F208 @ =0x00000E44
	adds r4, r7, r0
	ldrh r0, [r4]
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #5
	ldr r5, _0819F20C @ =0x0000073C
	adds r0, r3, r5
	adds r0, r7, r0
	adds r0, #0x48
	ldr r6, _0819F210 @ =0x00000794
	adds r1, r7, r6
	adds r1, r1, r3
	ldr r1, [r1]
	mov r3, ip
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r6, r0, r7
	adds r6, r6, r5
	adds r4, r0, r7
	ldr r0, _0819F214 @ =0x00000784
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sb
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _0819F218
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0819F220
	.align 2, 0
_0819F204: .4byte 0x00000E46
_0819F208: .4byte 0x00000E44
_0819F20C: .4byte 0x0000073C
_0819F210: .4byte 0x00000794
_0819F214: .4byte 0x00000784
_0819F218:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0819F220:
	str r0, [r6]
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
	beq _0819F244
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0819F24C
_0819F244:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0819F24C:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0819F284 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _0819F2BC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0819F288
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0819F27C
	ldrb r0, [r4, #5]
_0819F27C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0819F298
	.align 2, 0
_0819F284: .4byte 0x0000FFFF
_0819F288:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0819F298
	strh r1, [r4, #8]
_0819F298:
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
	bne _0819F2BC
	movs r0, #1
	strb r0, [r4, #7]
_0819F2BC:
	ldr r3, _0819F378 @ =0x00000E44
	adds r4, r7, r3
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	movs r6, #0xeb
	lsls r6, r6, #3
	adds r2, r7, r6
	adds r2, r2, r0
	mov r3, sl
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	subs r6, #0x1c
	adds r3, r7, r6
	adds r0, r3, r0
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r3, r3, r0
	ldr r0, [r3]
	movs r1, #2
	orrs r0, r1
	str r0, [r3]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	movs r1, #0xf3
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #8
	strh r1, [r0]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldr r2, _0819F37C @ =0x00000742
	adds r0, r0, r2
	mov r3, sp
	ldrb r3, [r3, #4]
	strb r3, [r0]
	mov r6, r8
	ldr r2, [r6, #0x44]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldrb r1, [r2, #8]
	ldr r2, _0819F380 @ =0x00000744
	adds r0, r0, r2
	strb r1, [r0]
	ldr r2, [r6, #0x44]
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r7, r0
	ldrb r1, [r2, #9]
	ldr r3, _0819F384 @ =0x00000745
	adds r0, r0, r3
	strb r1, [r0]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0819F368
	movs r0, #0
	strh r0, [r4]
_0819F368:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819F378: .4byte 0x00000E44
_0819F37C: .4byte 0x00000742
_0819F380: .4byte 0x00000744
_0819F384: .4byte 0x00000745

	thumb_func_start FUN_0819f388
FUN_0819f388: @ 0x0819F388
	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0819F3C8 @ =0x0000073C
	adds r2, r0, r1
	adds r3, r0, #0
	movs r5, #0xf3
	lsls r5, r5, #3
	movs r4, #3
_0819F39E:
	adds r1, r3, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _0819F3B8
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0819F3B8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0819F3B8:
	adds r2, #0x60
	adds r3, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0819F39E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819F3C8: .4byte 0x0000073C

	thumb_func_start FUN_0819f3cc
FUN_0819f3cc: @ 0x0819F3CC
	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0819F3F8 @ =0x0000073C
	adds r4, r0, r1
	movs r5, #3
_0819F3DC:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _0819F3E8
	adds r0, r4, #0
	bl FUN_0822a4e0
_0819F3E8:
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0819F3DC
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819F3F8: .4byte 0x0000073C

	thumb_func_start FUN_0819f3fc
FUN_0819f3fc: @ 0x0819F3FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sl, r0
	str r1, [sp, #0x20]
	str r2, [sp, #0x24]
	str r3, [sp, #0x28]
	mov r0, sp
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08234de8
	movs r0, #0
	mov r8, r0
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #0x2c]
	movs r6, #0
	ldr r0, [sp, #4]
	ldrb r2, [r0]
	cmp r8, r2
	bge _0819F4B0
	add r7, sp, #0xc
	add r5, sp, #0x18
	ldr r3, _0819F51C @ =0xFFFF0000
	mov sb, r3
_0819F438:
	bl FUN_08234f6c
	lsls r1, r6, #3
	adds r0, r0, r1
	str r0, [r7, #8]
	ldr r2, [sp, #0x24]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r0, [r7, #8]
	ldrh r1, [r0]
	ldrh r0, [r5]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x18]
	mov r3, sb
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r7, #8]
	ldrh r1, [r0, #2]
	ldrh r0, [r5, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r4, r1, r0
	ldr r0, [sp, #0x28]
	cmp r4, r0
	bgt _0819F4A6
	cmp r8, r4
	bge _0819F4A6
	mov r0, sl
	adds r1, r6, #0
	bl FUN_0819e7f4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819F4A6
	str r6, [sp, #0x2c]
	mov r8, r4
_0819F4A6:
	adds r6, #1
	ldr r0, [sp, #4]
	ldrb r1, [r0]
	cmp r6, r1
	blt _0819F438
_0819F4B0:
	mov r2, r8
	cmp r2, #0
	bne _0819F4D4
	ldr r2, _0819F520 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0819F524 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0819F528 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #4]
	ldrb r1, [r1]
	bl Mod
	str r0, [sp, #0x2c]
_0819F4D4:
	mov r0, sl
	ldr r1, [sp, #0x2c]
	bl FUN_0819e7c0
	mov r0, sp
	movs r1, #0
	add r2, sp, #0x2c
	ldrb r2, [r2]
	strb r2, [r0, #2]
	strb r1, [r0, #3]
	ldr r0, [sp, #4]
	bl FUN_08234f6c
	str r0, [sp, #8]
	mov r1, sp
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrh r1, [r0]
	ldr r3, [sp, #0x20]
	strh r1, [r3]
	ldr r1, _0819F52C @ =0x00000472
	add r1, sl
	ldrh r1, [r1]
	strh r1, [r3, #2]
	ldrh r0, [r0, #2]
	strh r0, [r3, #4]
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819F51C: .4byte 0xFFFF0000
_0819F520: .4byte 0x030046B8
_0819F524: .4byte 0x000003FF
_0819F528: .4byte 0x0203B400
_0819F52C: .4byte 0x00000472

	thumb_func_start FUN_0819f530
FUN_0819f530: @ 0x0819F530
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov sb, r1
	ldr r7, [r0, #0x44]
	ldr r3, _0819F5B4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x78
	orrs r0, r2
	ldr r1, _0819F5B8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	add r6, sp, #0xc
	ldr r0, [r6, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r6, #4]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	add r4, sp, #0x14
	movs r5, #0
	str r5, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _0819F5BC @ =0x05000002
	bl CpuSet
	add r0, sp, #0x1c
	mov r8, r0
	str r5, [sp, #8]
	add r0, sp, #8
	mov r1, r8
	ldr r2, _0819F5BC @ =0x05000002
	bl CpuSet
	ldr r0, _0819F5C0 @ =0x0000FF74
	strh r0, [r4]
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r3, [r4, r1]
	ldr r2, _0819F5C4 @ =0x085B0A08
	ldrb r0, [r7, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	mov sl, r6
	adds r6, r4, #0
	mov ip, r8
	cmp r0, #0
	blt _0819F5C8
	asrs r0, r0, #0xc
	b _0819F5CE
	.align 2, 0
_0819F5B4: .4byte 0xFFFF0000
_0819F5B8: .4byte 0x0000FFFF
_0819F5BC: .4byte 0x05000002
_0819F5C0: .4byte 0x0000FF74
_0819F5C4: .4byte 0x085B0A08
_0819F5C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F5CE:
	adds r5, r0, #0
	movs r3, #4
	ldrsh r2, [r6, r3]
	ldr r1, _0819F5EC @ =0x085B0A08
	ldrb r0, [r7, #6]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	mov r8, r1
	cmp r0, #0
	blt _0819F5F0
	asrs r0, r0, #0xc
	b _0819F5F6
	.align 2, 0
_0819F5EC: .4byte 0x085B0A08
_0819F5F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F5F6:
	add r3, sp, #0x24
	adds r1, r5, r0
	ldrh r0, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819F628 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	movs r2, #0
	ldrsh r1, [r6, r2]
	ldrb r0, [r7, #6]
	lsls r0, r0, #1
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _0819F62C
	asrs r0, r0, #0xc
	b _0819F630
	.align 2, 0
_0819F628: .4byte 0xFFFF0000
_0819F62C:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_0819F630:
	adds r4, r0, #0
	movs r0, #4
	ldrsh r2, [r6, r0]
	ldrb r0, [r7, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0819F650
	asrs r0, r0, #0xc
	b _0819F656
_0819F650:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F656:
	adds r1, r4, r0
	ldrh r2, [r3, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819F690 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r3, #0
	mov r1, ip
	mov r2, sl
	mov r3, sb
	bl FUN_080dbcec
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819F690: .4byte 0xFFFF0000

	thumb_func_start FUN_0819f694
FUN_0819f694: @ 0x0819F694
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x2c
	adds r5, r1, #0
	adds r7, r2, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	adds r0, r3, #0
	movs r1, #2
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	beq _0819F6B8
	b _0819F884
_0819F6B8:
	ldr r2, _0819F708 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	ldr r1, _0819F70C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	movs r1, #0x28
	orrs r0, r1
	str r0, [r4, #4]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0x24]
	str r1, [sp, #0x28]
	add r5, sp, #0x1c
	str r3, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _0819F710 @ =0x05000002
	bl CpuSet
	ldr r2, _0819F714 @ =0x00000ECE
	adds r0, r6, r2
	ldrb r0, [r0]
	mov r8, r4
	adds r4, r5, #0
	cmp r0, #4
	bhi _0819F7A0
	lsls r0, r0, #2
	ldr r1, _0819F718 @ =_0819F71C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0819F708: .4byte 0xFFFF0000
_0819F70C: .4byte 0x0000FFFF
_0819F710: .4byte 0x05000002
_0819F714: .4byte 0x00000ECE
_0819F718: .4byte _0819F71C
_0819F71C: @ jump table
	.4byte _0819F730 @ case 0
	.4byte _0819F748 @ case 1
	.4byte _0819F760 @ case 2
	.4byte _0819F778 @ case 3
	.4byte _0819F790 @ case 4
_0819F730:
	ldr r1, _0819F740 @ =0x0000FF88
	strh r1, [r4]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r3, _0819F744 @ =0x00000ECE
	adds r1, r6, r3
	b _0819F784
	.align 2, 0
_0819F740: .4byte 0x0000FF88
_0819F744: .4byte 0x00000ECE
_0819F748:
	ldr r1, _0819F758 @ =0x0000FFB5
	strh r1, [r4]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r5, _0819F75C @ =0x00000ECE
	adds r1, r6, r5
	b _0819F784
	.align 2, 0
_0819F758: .4byte 0x0000FFB5
_0819F75C: .4byte 0x00000ECE
_0819F760:
	ldr r1, _0819F770 @ =0x0000FFE2
	strh r1, [r4]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r0, _0819F774 @ =0x00000ECE
	adds r1, r6, r0
	b _0819F784
	.align 2, 0
_0819F770: .4byte 0x0000FFE2
_0819F774: .4byte 0x00000ECE
_0819F778:
	movs r1, #0xf
	strh r1, [r4]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r2, _0819F78C @ =0x00000ECE
	adds r1, r6, r2
_0819F784:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0819F7A0
	.align 2, 0
_0819F78C: .4byte 0x00000ECE
_0819F790:
	movs r2, #0
	movs r1, #0x3c
	strh r1, [r4]
	add r0, sp, #0x1c
	strh r1, [r0, #4]
	ldr r3, _0819F7C4 @ =0x00000ECE
	adds r0, r6, r3
	strb r2, [r0]
_0819F7A0:
	movs r5, #0
	ldrsh r3, [r4, r5]
	ldr r1, _0819F7C8 @ =0x085B0A08
	adds r2, r7, #0
	adds r2, #0x40
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r3, r0
	adds r6, r1, #0
	mov ip, r2
	cmp r0, #0
	blt _0819F7CC
	asrs r0, r0, #0xc
	b _0819F7D2
	.align 2, 0
_0819F7C4: .4byte 0x00000ECE
_0819F7C8: .4byte 0x085B0A08
_0819F7CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F7D2:
	adds r2, r0, #0
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0xff
	ands r1, r7
	lsls r1, r1, #1
	adds r1, r1, r6
	movs r3, #0
	ldrsh r1, [r1, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819F7EE
	asrs r0, r0, #0xc
	b _0819F7F4
_0819F7EE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F7F4:
	add r3, sp, #0x24
	adds r1, r2, r0
	ldrh r5, [r3]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819F828 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x24]
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _0819F82C
	asrs r0, r0, #0xc
	b _0819F830
	.align 2, 0
_0819F828: .4byte 0xFFFF0000
_0819F82C:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_0819F830:
	adds r5, r0, #0
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0xff
	mov r2, ip
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r6
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819F84E
	asrs r0, r0, #0xc
	b _0819F854
_0819F84E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819F854:
	adds r1, r5, r0
	ldrh r5, [r3, #4]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819F890 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r1, #2
	mov r2, r8
	movs r3, #0
	bl FUN_080ddcc8
_0819F884:
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819F890: .4byte 0xFFFF0000

	thumb_func_start FUN_0819f894
FUN_0819f894: @ 0x0819F894
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r3, [r0]
	movs r1, #0x40
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r2, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0819F8CA
	ldr r0, _0819F8D0 @ =0x00000EAD
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0819F8CA
	ldr r1, _0819F8D4 @ =0x00000EAE
	adds r0, r3, r1
	ldrb r0, [r0]
	bl FUN_0823b9cc
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_0819F8CA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0819F8D0: .4byte 0x00000EAD
_0819F8D4: .4byte 0x00000EAE

	thumb_func_start FUN_0819f8d8
FUN_0819f8d8: @ 0x0819F8D8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	cmp r5, r3
	bgt _0819F8EC
	movs r0, #0
	cmp r5, r2
	ble _0819F8EC
	movs r0, #1
_0819F8EC:
	ldr r1, _0819F914 @ =0x085ADDCC
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	cmp r0, #0
	bne _0819F91C
	ldr r1, [r4]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0819F918
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _0819F91A
	.align 2, 0
_0819F914: .4byte 0x085ADDCC
_0819F918:
	orrs r1, r2
_0819F91A:
	str r1, [r4]
_0819F91C:
	cmp r5, #0x3c
	bgt _0819F924
	movs r0, #0
	b _0819F92E
_0819F924:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
_0819F92E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0819f934
FUN_0819f934: @ 0x0819F934
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #2
	cmp r5, r3
	bgt _0819F948
	movs r0, #0
	cmp r5, r2
	ble _0819F948
	movs r0, #1
_0819F948:
	ldr r1, _0819F970 @ =0x085ADDD4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	cmp r0, #0
	bne _0819F978
	ldr r1, [r4]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0819F974
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _0819F976
	.align 2, 0
_0819F970: .4byte 0x085ADDD4
_0819F974:
	orrs r1, r2
_0819F976:
	str r1, [r4]
_0819F978:
	cmp r5, #0x3c
	bgt _0819F980
	movs r0, #0
	b _0819F98A
_0819F980:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
_0819F98A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0819f990
FUN_0819f990: @ 0x0819F990
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r7, [r0]
	ldr r0, _0819FA10 @ =0x00000A8C
	adds r4, r7, r0
	ldr r1, _0819FA14 @ =0x00005291
	adds r0, r4, #0
	bl Video_GetActorSprite
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r5, r7, r1
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, _0819FA18 @ =0x0000922E
	ldr r1, _0819FA1C @ =0x00003F72
	bl GetFile
	adds r1, r0, #0
	mov r2, r8
	ldr r0, [r2, #0x44]
	adds r0, #0x48
	ldrh r2, [r0, #0xa]
	ldr r0, _0819FA20 @ =0x00000AA8
	adds r4, r7, r0
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0819FA24
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0819FA2C
	.align 2, 0
_0819FA10: .4byte 0x00000A8C
_0819FA14: .4byte 0x00005291
_0819FA18: .4byte 0x0000922E
_0819FA1C: .4byte 0x00003F72
_0819FA20: .4byte 0x00000AA8
_0819FA24:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0819FA2C:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0819FA50
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0819FA58
_0819FA50:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0819FA58:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0819FA90 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0819FAC8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0819FA94
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0819FA88
	ldrb r0, [r4, #5]
_0819FA88:
	subs r0, #1
	strh r0, [r4, #8]
	b _0819FAA4
	.align 2, 0
_0819FA90: .4byte 0x0000FFFF
_0819FA94:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0819FAA4
	strh r1, [r4, #8]
_0819FAA4:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _0819FAC8
	movs r0, #1
	strb r0, [r4, #7]
_0819FAC8:
	movs r4, #0xa6
	lsls r4, r4, #4
	adds r1, r7, r4
	ldr r0, [r1]
	movs r3, #1
	orrs r0, r3
	str r0, [r1]
	ldr r0, _0819FC28 @ =0x00000A7C
	adds r2, r7, r0
	mov r4, r8
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _0819FC2C @ =0x00000A67
	adds r0, r7, r1
	strb r3, [r0]
	ldr r2, _0819FC30 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _0819FC34 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x8c
	lsls r1, r1, #0xf
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
	mov sl, r1
	add r2, sp, #0x1c
	mov sb, r2
	add r6, sp, #0x24
	ldr r0, _0819FC38 @ =0x00000BA8
	adds r4, r7, r0
	movs r5, #2
_0819FB22:
	movs r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	mov r2, sl
	str r2, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _0819FC3C @ =0x00005001
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r4, #0
	ldr r2, _0819FC40 @ =0x00000C98
	adds r1, r7, r2
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	ldr r1, _0819FC44 @ =FUN_0819aa5c
	adds r2, r7, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0819FB22
	ldr r2, _0819FC30 @ =0xFFFF0000
	ldr r0, [sp, #0x1c]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _0819FC34 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x1c]
	mov r4, sb
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r4, #4]
	movs r0, #0
	str r0, [sp, #0x24]
	ldr r0, [r6, #4]
	ands r0, r2
	str r0, [r6, #4]
	ldr r0, _0819FC48 @ =0x00000AB8
	adds r4, r7, r0
	movs r5, #2
_0819FB9A:
	movs r0, #0x10
	str r0, [sp]
	mov r1, sb
	str r1, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _0819FC4C @ =0x00002401
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x89
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r0]
	movs r0, #0x8b
	lsls r0, r0, #2
	add r0, r8
	ldrh r2, [r0]
	movs r0, #0x8f
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	str r0, [sp]
	movs r0, #0x8d
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	ldr r2, _0819FC40 @ =0x00000C98
	adds r1, r7, r2
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	ldr r1, _0819FC50 @ =FUN_0819aa58
	adds r2, r7, #0
	bl FUN_0823651c
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0819FB9A
	ldr r0, _0819FC54 @ =0x00000CBC
	adds r4, r7, r0
	ldr r2, _0819FC28 @ =0x00000A7C
	adds r1, r7, r2
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0801385c
	ldr r2, _0819FC58 @ =0x00000CB7
	adds r1, r7, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080136b4
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819FC28: .4byte 0x00000A7C
_0819FC2C: .4byte 0x00000A67
_0819FC30: .4byte 0xFFFF0000
_0819FC34: .4byte 0x0000FFFF
_0819FC38: .4byte 0x00000BA8
_0819FC3C: .4byte 0x00005001
_0819FC40: .4byte 0x00000C98
_0819FC44: .4byte FUN_0819aa5c
_0819FC48: .4byte 0x00000AB8
_0819FC4C: .4byte 0x00002401
_0819FC50: .4byte FUN_0819aa58
_0819FC54: .4byte 0x00000CBC
_0819FC58: .4byte 0x00000CB7

	thumb_func_start FUN_0819fc5c
FUN_0819fc5c: @ 0x0819FC5C
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0819FCA0 @ =0x00000A7C
	adds r6, r0, r1
	adds r1, #0x3c
	adds r4, r0, r1
	adds r1, #0xf0
	adds r5, r0, r1
	movs r7, #2
_0819FC74:
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r4, #0x50
	adds r5, #0x50
	subs r7, #1
	cmp r7, #0
	bge _0819FC74
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819FCA0: .4byte 0x00000A7C

	thumb_func_start FUN_0819fca4
FUN_0819fca4: @ 0x0819FCA4
	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	ldr r1, _0819FCE4 @ =0x00000A64
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0819FCDE
	ldr r0, _0819FCE8 @ =0x00000BA8
	adds r4, r6, r0
	movs r5, #2
_0819FCBE:
	adds r0, r4, #0
	bl FUN_08236424
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0819FCBE
	ldr r1, _0819FCEC @ =0x00000CBC
	adds r0, r6, r1
	bl FUN_080138fc
	movs r1, #0xa6
	lsls r1, r1, #4
	adds r0, r6, r1
	bl FUN_0822a4e0
_0819FCDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819FCE4: .4byte 0x00000A64
_0819FCE8: .4byte 0x00000BA8
_0819FCEC: .4byte 0x00000CBC

	thumb_func_start FUN_0819fcf0
FUN_0819fcf0: @ 0x0819FCF0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r0, _0819FD08 @ =0x00000A7C
	adds r2, r2, r0
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	bx lr
	.align 2, 0
_0819FD08: .4byte 0x00000A7C

	thumb_func_start FUN_0819fd0c
FUN_0819fd0c: @ 0x0819FD0C
	push {r4, lr}
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, _0819FD28 @ =0x00000A92
	adds r3, r0, r4
	strh r2, [r3]
	ldr r2, _0819FD2C @ =0x00000A98
	adds r0, r0, r2
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0819FD28: .4byte 0x00000A92
_0819FD2C: .4byte 0x00000A98

	thumb_func_start FUN_0819fd30
FUN_0819fd30: @ 0x0819FD30
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0819FDD4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _0819FDD8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
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
	adds r7, r1, #0
	ldr r2, _0819FDDC @ =0x0000095C
	adds r4, r4, r2
	movs r6, #2
_0819FD70:
	ldrh r1, [r5]
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r7, [sp, #8]
	adds r0, r4, #0
	ldr r2, _0819FDE0 @ =0x00002401
	movs r3, #0
	bl FUN_0823646c
	ldr r1, _0819FDE4 @ =0x0000022A
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _0819FDE8 @ =0x00000232
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xe
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	adds r1, r5, #0
	adds r1, #8
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	ldr r1, _0819FDEC @ =FUN_0819aa94
	adds r2, r5, #0
	bl FUN_0823651c
	adds r4, #0x50
	subs r6, #1
	cmp r6, #0
	bge _0819FD70
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819FDD4: .4byte 0xFFFF0000
_0819FDD8: .4byte 0x0000FFFF
_0819FDDC: .4byte 0x0000095C
_0819FDE0: .4byte 0x00002401
_0819FDE4: .4byte 0x0000022A
_0819FDE8: .4byte 0x00000232
_0819FDEC: .4byte FUN_0819aa94

	thumb_func_start FUN_0819fdf0
FUN_0819fdf0: @ 0x0819FDF0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r1, _0819FE14 @ =0x00000E44
	add r1, sl
	ldrh r0, [r1]
	cmp r0, #0
	bne _0819FE18
	movs r1, #3
	b _0819FE1C
	.align 2, 0
_0819FE14: .4byte 0x00000E44
_0819FE18:
	ldrh r0, [r1]
	subs r1, r0, #1
_0819FE1C:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r2, _0819FE68 @ =0x0000073C
	adds r0, r0, r2
	mov r3, sl
	adds r7, r3, r0
	movs r0, #0
	mov r8, r0
	add r4, sp, #4
	mov r1, sp
	adds r1, #0xc
	str r1, [sp, #0x14]
	ldr r6, _0819FE6C @ =0x0000095C
	add r6, sl
	mov sb, r1
_0819FE3C:
	movs r2, #0
	str r2, [sp]
	mov r0, sp
	add r1, sp, #4
	ldr r2, _0819FE70 @ =0x05000002
	bl CpuSet
	ldr r0, _0819FE74 @ =0x00000A4C
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r3, r8
	cmp r3, #1
	beq _0819FE90
	cmp r3, #1
	bgt _0819FE78
	cmp r3, #0
	beq _0819FE80
	b _0819FEA4
	.align 2, 0
_0819FE68: .4byte 0x0000073C
_0819FE6C: .4byte 0x0000095C
_0819FE70: .4byte 0x05000002
_0819FE74: .4byte 0x00000A4C
_0819FE78:
	mov r0, r8
	cmp r0, #2
	beq _0819FE9C
	b _0819FEA4
_0819FE80:
	ldr r0, _0819FE8C @ =0x0000FF88
	strh r0, [r4]
	mov r1, sp
	strh r0, [r1, #8]
	b _0819FEA4
	.align 2, 0
_0819FE8C: .4byte 0x0000FF88
_0819FE90:
	ldr r0, _0819FE98 @ =0x0000FFE2
	strh r0, [r4]
	strh r0, [r4, #4]
	b _0819FEA4
	.align 2, 0
_0819FE98: .4byte 0x0000FFE2
_0819FE9C:
	movs r0, #0x3c
	strh r0, [r4]
	mov r2, sp
	strh r0, [r2, #8]
_0819FEA4:
	movs r0, #0
	ldrsh r3, [r4, r0]
	ldr r2, _0819FEC8 @ =0x085B0A08
	ldrb r0, [r7, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _0819FECC
	asrs r0, r0, #0xc
	b _0819FED2
	.align 2, 0
_0819FEC8: .4byte 0x085B0A08
_0819FECC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819FED2:
	adds r3, r0, #0
	movs r2, #4
	ldrsh r0, [r4, r2]
	ldrb r1, [r7, #6]
	lsls r1, r1, #1
	adds r1, r1, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _0819FEEC
	asrs r0, r0, #0xc
	b _0819FEF2
_0819FEEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819FEF2:
	adds r1, r3, r0
	ldr r3, [sp, #0x14]
	ldrh r3, [r3]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0819FF24 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldrb r0, [r7, #6]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _0819FF28
	asrs r0, r0, #0xc
	b _0819FF2C
	.align 2, 0
_0819FF24: .4byte 0xFFFF0000
_0819FF28:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_0819FF2C:
	adds r3, r0, #0
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldrb r0, [r7, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0819FF4C
	asrs r0, r0, #0xc
	b _0819FF52
_0819FF4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0819FF52:
	adds r0, r3, r0
	mov r2, sb
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _0819FF98 @ =0xFFFF0000
	mov r3, sb
	ldr r1, [r3, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r3, #4]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	adds r6, #0x50
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #2
	bgt _0819FF88
	b _0819FE3C
_0819FF88:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819FF98: .4byte 0xFFFF0000

	thumb_func_start FUN_0819ff9c
FUN_0819ff9c: @ 0x0819FF9C
	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0819FFC0 @ =0x00000D9C
	adds r4, r0, r1
	movs r5, #1
_0819FFAC:
	adds r0, r4, #0
	bl FUN_08236424
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _0819FFAC
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819FFC0: .4byte 0x00000D9C

	thumb_func_start FUN_0819ffc4
FUN_0819ffc4: @ 0x0819FFC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x14]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, [sp, #0x14]
	ldr r2, [r2, #0x44]
	str r2, [sp, #0x18]
	movs r3, #0
	mov r8, r3
	ldr r0, [sp, #0x14]
	subs r1, #0xa4
	adds r0, r0, r1
	mov sl, r0
_0819FFEE:
	movs r1, #0x40
	ldr r0, _081A0000 @ =0x00000E48
	add r0, sb
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A0004
	movs r0, #1
	b _081A0006
	.align 2, 0
_081A0000: .4byte 0x00000E48
_081A0004:
	movs r0, #0
_081A0006:
	cmp r0, #0
	bne _081A002A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x14]
	ldr r3, _081A0020 @ =0x00000474
	adds r0, r2, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A0024
	movs r0, #1
	b _081A0026
	.align 2, 0
_081A0020: .4byte 0x00000474
_081A0024:
	movs r0, #0
_081A0026:
	cmp r0, #0
	beq _081A0068
_081A002A:
	mov r1, sl
	ldrh r0, [r1, #6]
	movs r2, #4
	orrs r0, r2
	strh r0, [r1, #6]
	ldr r1, [sp, #0x14]
	adds r1, #0xd8
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
	ldr r1, _081A0060 @ =0x00000DA2
	add r1, sb
	movs r5, #1
	ldr r4, _081A0064 @ =0x00000D02
	add r4, sb
_081A0048:
	ldrh r0, [r1]
	orrs r0, r2
	strh r0, [r1]
	ldrh r0, [r4]
	orrs r0, r2
	strh r0, [r4]
	adds r1, #0x50
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _081A0048
	b _081A022E
	.align 2, 0
_081A0060: .4byte 0x00000DA2
_081A0064: .4byte 0x00000D02
_081A0068:
	mov r3, sl
	ldrh r1, [r3, #6]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strh r0, [r3, #6]
	ldr r1, [sp, #0x14]
	adds r1, #0xd8
	ldrh r2, [r1, #6]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	strh r0, [r1, #6]
	str r1, [sp, #0x1c]
	add r4, sp, #4
	add r7, sp, #0xc
	mov r0, r8
	adds r0, #1
	str r0, [sp, #0x20]
	movs r6, #5
	rsbs r6, r6, #0
	ldr r3, _081A00E0 @ =0x00000DA2
	add r3, sb
	movs r5, #1
	ldr r2, _081A00E4 @ =0x00000D02
	add r2, sb
_081A009C:
	ldrh r1, [r3]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r3]
	ldrh r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	strh r0, [r2]
	adds r3, #0x50
	adds r2, #0x50
	subs r5, #1
	cmp r5, #0
	bge _081A009C
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081A00E8 @ =0x05000002
	bl CpuSet
	ldr r2, [sp, #0x14]
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	mov r3, r8
	cmp r3, #1
	beq _081A00FC
	cmp r3, #1
	bgt _081A00EC
	cmp r3, #0
	beq _081A00F4
	b _081A010A
	.align 2, 0
_081A00E0: .4byte 0x00000DA2
_081A00E4: .4byte 0x00000D02
_081A00E8: .4byte 0x05000002
_081A00EC:
	mov r0, r8
	cmp r0, #2
	beq _081A0104
	b _081A010A
_081A00F4:
	ldr r0, _081A00F8 @ =0x0000FF88
	b _081A0106
	.align 2, 0
_081A00F8: .4byte 0x0000FF88
_081A00FC:
	ldr r0, _081A0100 @ =0x0000FFE2
	b _081A0106
	.align 2, 0
_081A0100: .4byte 0x0000FFE2
_081A0104:
	movs r0, #0x3c
_081A0106:
	strh r0, [r4]
	strh r0, [r4, #4]
_081A010A:
	movs r1, #0
	ldrsh r3, [r4, r1]
	ldr r2, _081A0130 @ =0x085B0A08
	ldr r1, [sp, #0x18]
	ldrb r0, [r1, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _081A0134
	asrs r0, r0, #0xc
	b _081A013A
	.align 2, 0
_081A0130: .4byte 0x085B0A08
_081A0134:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A013A:
	adds r3, r0, #0
	movs r2, #4
	ldrsh r0, [r4, r2]
	ldr r2, [sp, #0x18]
	ldrb r1, [r2, #6]
	lsls r1, r1, #1
	adds r1, r1, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _081A0156
	asrs r0, r0, #0xc
	b _081A015C
_081A0156:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A015C:
	adds r1, r3, r0
	ldrh r3, [r7]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081A018C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	movs r0, #0
	ldrsh r1, [r4, r0]
	ldr r2, [sp, #0x18]
	ldrb r0, [r2, #6]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r1, r0, r1
	rsbs r0, r1, #0
	cmp r0, #0
	blt _081A0190
	asrs r0, r0, #0xc
	b _081A0194
	.align 2, 0
_081A018C: .4byte 0xFFFF0000
_081A0190:
	asrs r0, r1, #0xc
	rsbs r0, r0, #0
_081A0194:
	adds r3, r0, #0
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldr r1, [sp, #0x18]
	ldrb r0, [r1, #6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _081A01B6
	asrs r0, r0, #0xc
	b _081A01BC
_081A01B6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A01BC:
	adds r0, r3, r0
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _081A01F4 @ =0xFFFF0000
	ldr r1, [r7, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r7, #4]
	mov r3, r8
	cmp r3, #0
	bne _081A01F8
	ldr r0, [sp, #0x1c]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	mov r0, sl
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	mov r0, sl
	bl FUN_08236400
	b _081A0224
	.align 2, 0
_081A01F4: .4byte 0xFFFF0000
_081A01F8:
	mov r0, r8
	lsls r4, r0, #2
	add r4, r8
	lsls r4, r4, #4
	ldr r1, _081A0240 @ =0x00000D4C
	adds r0, r4, r1
	add r0, sb
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r2, _081A0244 @ =0x00000CAC
	adds r4, r4, r2
	add r4, sb
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_081A0224:
	ldr r3, [sp, #0x20]
	mov r8, r3
	cmp r3, #2
	bgt _081A022E
	b _0819FFEE
_081A022E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A0240: .4byte 0x00000D4C
_081A0244: .4byte 0x00000CAC

	thumb_func_start FUN_081a0248
FUN_081a0248: @ 0x081A0248
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r7, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, _081A0270 @ =0x00000E48
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A0274
	movs r0, #1
	b _081A0276
	.align 2, 0
_081A0270: .4byte 0x00000E48
_081A0274:
	movs r0, #0
_081A0276:
	cmp r0, #0
	beq _081A02A2
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0x8a
	lsls r1, r1, #2
	add r1, ip
	mov r8, r1
	ldrh r1, [r1]
	movs r6, #0x8c
	lsls r6, r6, #2
	add r6, ip
	ldrh r2, [r6]
	movs r5, #0x91
	lsls r5, r5, #2
	add r5, ip
	ldr r3, [r5]
	str r3, [sp]
	movs r4, #0x8e
	lsls r4, r4, #2
	b _081A03B0
_081A02A2:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r0, _081A02B8 @ =0x00000E48
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081A02BC
	movs r0, #1
	b _081A02BE
	.align 2, 0
_081A02B8: .4byte 0x00000E48
_081A02BC:
	movs r0, #0
_081A02BE:
	cmp r0, #0
	beq _081A0330
	movs r0, #0x8a
	lsls r0, r0, #2
	add r0, ip
	ldrh r6, [r0]
	lsls r6, r6, #1
	movs r0, #0x8c
	lsls r0, r0, #2
	add r0, ip
	ldrh r4, [r0]
	lsls r4, r4, #1
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0x91
	lsls r1, r1, #2
	add r1, ip
	mov r8, r1
	ldr r1, [r1]
	str r1, [sp]
	movs r5, #0x8e
	lsls r5, r5, #2
	add r5, ip
	ldrh r1, [r5]
	str r1, [sp, #4]
	adds r1, r6, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_082364f8
	ldr r2, _081A0328 @ =0x00000CFC
	adds r0, r7, r2
	mov r2, r8
	ldr r1, [r2]
	str r1, [sp]
	ldrh r1, [r5]
	str r1, [sp, #4]
	adds r1, r6, #0
	adds r2, r4, #0
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _081A032C @ =0x00000D4C
	adds r0, r7, r1
	mov r2, r8
	ldr r1, [r2]
	str r1, [sp]
	ldrh r1, [r5]
	str r1, [sp, #4]
	adds r1, r6, #0
	adds r2, r4, #0
	b _081A03E6
	.align 2, 0
_081A0328: .4byte 0x00000CFC
_081A032C: .4byte 0x00000D4C
_081A0330:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A0340
	movs r0, #1
	b _081A0342
_081A0340:
	movs r0, #0
_081A0342:
	cmp r0, #0
	beq _081A0374
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	ldr r1, _081A0368 @ =0x00000226
	add r1, ip
	mov r8, r1
	ldrh r1, [r1]
	ldr r6, _081A036C @ =0x0000022E
	add r6, ip
	ldrh r2, [r6]
	movs r5, #0x90
	lsls r5, r5, #2
	add r5, ip
	ldr r3, [r5]
	str r3, [sp]
	ldr r4, _081A0370 @ =0x00000236
	b _081A03B0
	.align 2, 0
_081A0368: .4byte 0x00000226
_081A036C: .4byte 0x0000022E
_081A0370: .4byte 0x00000236
_081A0374:
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A0384
	movs r0, #1
	b _081A0386
_081A0384:
	movs r0, #0
_081A0386:
	cmp r0, #0
	beq _081A03F8
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0x89
	lsls r1, r1, #2
	add r1, ip
	mov r8, r1
	ldrh r1, [r1]
	movs r6, #0x8b
	lsls r6, r6, #2
	add r6, ip
	ldrh r2, [r6]
	movs r5, #0x8f
	lsls r5, r5, #2
	add r5, ip
	ldr r3, [r5]
	str r3, [sp]
	movs r4, #0x8d
	lsls r4, r4, #2
_081A03B0:
	add r4, ip
	ldrh r3, [r4]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	ldr r2, _081A03F0 @ =0x00000CFC
	adds r0, r7, r2
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r6]
	ldr r3, [r5]
	str r3, [sp]
	ldrh r3, [r4]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _081A03F4 @ =0x00000D4C
	adds r0, r7, r1
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r6]
	ldr r3, [r5]
	str r3, [sp]
	ldrh r3, [r4]
	str r3, [sp, #4]
_081A03E6:
	movs r3, #0
	bl FUN_082364f8
	b _081A045A
	.align 2, 0
_081A03F0: .4byte 0x00000CFC
_081A03F4: .4byte 0x00000D4C
_081A03F8:
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0x89
	lsls r1, r1, #2
	add r1, ip
	mov r8, r1
	ldrh r1, [r1]
	movs r6, #0x8b
	lsls r6, r6, #2
	add r6, ip
	ldrh r2, [r6]
	movs r5, #0x8f
	lsls r5, r5, #2
	add r5, ip
	ldr r3, [r5]
	str r3, [sp]
	movs r4, #0x8d
	lsls r4, r4, #2
	add r4, ip
	ldrh r3, [r4]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	ldr r2, _081A0468 @ =0x00000CFC
	adds r0, r7, r2
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r6]
	ldr r3, [r5]
	str r3, [sp]
	ldrh r3, [r4]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _081A046C @ =0x00000D4C
	adds r0, r7, r1
	mov r2, r8
	ldrh r1, [r2]
	ldrh r2, [r6]
	ldr r3, [r5]
	str r3, [sp]
	ldrh r3, [r4]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
_081A045A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A0468: .4byte 0x00000CFC
_081A046C: .4byte 0x00000D4C

	thumb_func_start FUN_081a0470
FUN_081a0470: @ 0x081A0470
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #0x4f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081A0526
	bl VM_GetPC
	cmp r0, #0
	beq _081A0494
	bl Script_GetValue
	adds r1, r0, #0
	b _081A0496
_081A0494:
	movs r1, #6
_081A0496:
	ldr r2, _081A04AC @ =0x00000E3C
	adds r0, r4, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A04B0
	bl Script_GetValue
	adds r1, r0, #0
	b _081A04B2
	.align 2, 0
_081A04AC: .4byte 0x00000E3C
_081A04B0:
	movs r1, #0xc
_081A04B2:
	ldr r2, _081A04C8 @ =0x00000E3D
	adds r0, r4, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A04CC
	bl Script_GetValue
	adds r1, r0, #0
	b _081A04CE
	.align 2, 0
_081A04C8: .4byte 0x00000E3D
_081A04CC:
	movs r1, #0x3c
_081A04CE:
	ldr r2, _081A04E4 @ =0x00000E3E
	adds r0, r4, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A04E8
	bl Script_GetValue
	adds r1, r0, #0
	b _081A04EA
	.align 2, 0
_081A04E4: .4byte 0x00000E3E
_081A04E8:
	movs r1, #3
_081A04EA:
	ldr r2, _081A0500 @ =0x00000E3F
	adds r0, r4, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A0504
	bl Script_GetValue
	adds r1, r0, #0
	b _081A0506
	.align 2, 0
_081A0500: .4byte 0x00000E3F
_081A0504:
	movs r1, #0x3c
_081A0506:
	movs r2, #0xe4
	lsls r2, r2, #4
	adds r0, r4, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A051E
	bl Script_GetValue
	adds r1, r0, #0
	b _081A0520
_081A051E:
	movs r1, #0x1e
_081A0520:
	ldr r2, _081A052C @ =0x00000E41
	adds r0, r4, r2
	strb r1, [r0]
_081A0526:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081A052C: .4byte 0x00000E41

	thumb_func_start FUN_081a0530
FUN_081a0530: @ 0x081A0530
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0819dd10
	adds r0, r4, #0
	bl FUN_0819e418
	adds r0, r4, #0
	bl FUN_0819e88c
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081a054c
FUN_081a054c: @ 0x081A054C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0819f894
	adds r0, r4, #0
	bl FUN_0819f388
	adds r0, r4, #0
	bl FUN_0819ec50
	adds r0, r4, #0
	bl FUN_0819ffc4
	adds r0, r4, #0
	bl FUN_0819e5f4
	adds r0, r4, #0
	bl FUN_081a0248
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081a057c
FUN_081a057c: @ 0x081A057C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r3, _081A059C @ =0x0000046C
	adds r1, r5, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A05A0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A05A2
	.align 2, 0
_081A059C: .4byte 0x0000046C
_081A05A0:
	movs r0, #0
_081A05A2:
	cmp r0, #0
	beq _081A05EE
	ldr r4, _081A0650 @ =FUN_0819c4a4
	movs r3, #0x21
	ldr r0, _081A0654 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A0658 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081A065C @ =0x00000E48
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081A05EE:
	adds r0, r5, #0
	bl FUN_0819ef24
	ldr r1, _081A0658 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A066C
	ldr r2, _081A0660 @ =FUN_0819bd2c
	movs r1, #0x22
	ldr r3, _081A0654 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081A0658 @ =0x0000046B
	adds r0, r5, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081A0664 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r3, _081A0668 @ =0x0000046C
	adds r0, r5, r3
	strb r4, [r0]
	b _081A0676
	.align 2, 0
_081A0650: .4byte FUN_0819c4a4
_081A0654: .4byte 0x0000046D
_081A0658: .4byte 0x0000046B
_081A065C: .4byte 0x00000E48
_081A0660: .4byte FUN_0819bd2c
_081A0664: .4byte 0x00000469
_081A0668: .4byte 0x0000046C
_081A066C:
	ldr r6, _081A067C @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0676:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A067C: .4byte 0x00000484

	thumb_func_start FUN_081a0680
FUN_081a0680: @ 0x081A0680
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081A06E8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A069A
	movs r0, #0
	strb r0, [r1]
_081A069A:
	ldr r1, _081A06EC @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0700
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _081A06F0 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	ldr r1, _081A06F4 @ =0x00000E48
	adds r2, r6, r1
	ldr r1, _081A06F8 @ =0xFFFFFBFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _081A06FC @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081A070A
	.align 2, 0
_081A06E8: .4byte 0x0000046C
_081A06EC: .4byte 0x0000046B
_081A06F0: .4byte 0xFFFFFEFF
_081A06F4: .4byte 0x00000E48
_081A06F8: .4byte 0xFFFFFBFF
_081A06FC: .4byte 0x00000484
_081A0700:
	ldr r0, _081A0710 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A070A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A0710: .4byte 0x00000484

	thumb_func_start FUN_081a0714
FUN_081a0714: @ 0x081A0714
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081A0734 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A0738
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A073A
	.align 2, 0
_081A0734: .4byte 0x0000046C
_081A0738:
	movs r0, #0
_081A073A:
	cmp r0, #0
	beq _081A0792
	ldr r4, _081A07F0 @ =FUN_0819c504
	movs r3, #0x30
	ldr r7, _081A07F4 @ =0x0000046D
	adds r1, r6, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A07F8 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #2
	ldr r7, _081A07FC @ =0x00000E48
	adds r1, r5, r7
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081A0800 @ =0x00000EBC
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _081A0804 @ =0x00000EB4
	adds r0, r5, r2
	strh r1, [r0]
_081A0792:
	ldr r3, _081A07F8 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0818
	ldr r2, _081A0808 @ =FUN_0819bd2c
	movs r1, #0x22
	ldr r4, _081A07F4 @ =0x0000046D
	adds r0, r6, r4
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _081A07F8 @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	adds r4, #0xe6
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A080C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081A0810 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081A0814 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081A0822
	.align 2, 0
_081A07F0: .4byte FUN_0819c504
_081A07F4: .4byte 0x0000046D
_081A07F8: .4byte 0x0000046B
_081A07FC: .4byte 0x00000E48
_081A0800: .4byte 0x00000EBC
_081A0804: .4byte 0x00000EB4
_081A0808: .4byte FUN_0819bd2c
_081A080C: .4byte 0x00000469
_081A0810: .4byte 0x0000046A
_081A0814: .4byte 0x00000484
_081A0818:
	ldr r0, _081A0828 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0822:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A0828: .4byte 0x00000484

	thumb_func_start FUN_081a082c
FUN_081a082c: @ 0x081A082C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081A0880 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A083E
	movs r0, #0
	strb r0, [r1]
_081A083E:
	ldr r1, _081A0884 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0890
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _081A0888 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _081A088C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081A089A
	.align 2, 0
_081A0880: .4byte 0x0000046C
_081A0884: .4byte 0x0000046B
_081A0888: .4byte 0xFFFFFEFF
_081A088C: .4byte 0x00000484
_081A0890:
	ldr r0, _081A08A0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A089A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A08A0: .4byte 0x00000484

	thumb_func_start FUN_081a08a4
FUN_081a08a4: @ 0x081A08A4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081A08C4 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A08C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A08CA
	.align 2, 0
_081A08C4: .4byte 0x0000046C
_081A08C8:
	movs r0, #0
_081A08CA:
	cmp r0, #0
	beq _081A0922
	ldr r4, _081A0980 @ =FUN_0819c7e4
	movs r3, #0x34
	ldr r7, _081A0984 @ =0x0000046D
	adds r1, r6, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A0988 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r7, _081A098C @ =0x00000E48
	adds r1, r5, r7
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081A0990 @ =0x00000EBE
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _081A0994 @ =0x00000EB6
	adds r0, r5, r2
	strh r1, [r0]
_081A0922:
	ldr r3, _081A0988 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A09A8
	ldr r2, _081A0998 @ =FUN_0819bd2c
	movs r1, #0x22
	ldr r4, _081A0984 @ =0x0000046D
	adds r0, r6, r4
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _081A0988 @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	adds r4, #0xe6
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #5
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A099C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081A09A0 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081A09A4 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081A09B2
	.align 2, 0
_081A0980: .4byte FUN_0819c7e4
_081A0984: .4byte 0x0000046D
_081A0988: .4byte 0x0000046B
_081A098C: .4byte 0x00000E48
_081A0990: .4byte 0x00000EBE
_081A0994: .4byte 0x00000EB6
_081A0998: .4byte FUN_0819bd2c
_081A099C: .4byte 0x00000469
_081A09A0: .4byte 0x0000046A
_081A09A4: .4byte 0x00000484
_081A09A8:
	ldr r0, _081A09B8 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A09B2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A09B8: .4byte 0x00000484

	thumb_func_start FUN_081a09bc
FUN_081a09bc: @ 0x081A09BC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081A0A10 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A09CE
	movs r0, #0
	strb r0, [r1]
_081A09CE:
	ldr r1, _081A0A14 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0A20
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _081A0A18 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _081A0A1C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081A0A2A
	.align 2, 0
_081A0A10: .4byte 0x0000046C
_081A0A14: .4byte 0x0000046B
_081A0A18: .4byte 0xFFFFFEFF
_081A0A1C: .4byte 0x00000484
_081A0A20:
	ldr r0, _081A0A30 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0A2A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A0A30: .4byte 0x00000484

	thumb_func_start FUN_081a0a34
FUN_081a0a34: @ 0x081A0A34
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081A0A54 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A0A58
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A0A5A
	.align 2, 0
_081A0A54: .4byte 0x0000046C
_081A0A58:
	movs r0, #0
_081A0A5A:
	cmp r0, #0
	beq _081A0ACC
	ldr r3, _081A0B28 @ =FUN_0819bfa8
	movs r2, #0x26
	ldr r4, _081A0B2C @ =0x0000046D
	adds r0, r6, r4
	movs r1, #0
	movs r4, #1
	strb r4, [r0]
	ldr r7, _081A0B30 @ =0x0000046B
	adds r0, r6, r7
	strb r1, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #5
	ldr r0, _081A0B34 @ =0x00000E48
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _081A0B38 @ =0x00000EB8
	adds r0, r5, r2
	strh r1, [r0]
	ldr r3, _081A0B3C @ =0x000008DC
	adds r1, r5, r3
	adds r0, r6, #0
	movs r2, #0xf8
	bl FUN_0819ee40
	ldr r7, _081A0B40 @ =0x00000ECC
	adds r0, r5, r7
	strb r4, [r0]
	ldr r0, _081A0B44 @ =0x0000016F
	bl PlaySound_082406e0
_081A0ACC:
	ldr r1, _081A0B30 @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0B5C
	ldr r2, _081A0B48 @ =FUN_0819bd2c
	movs r1, #0x22
	ldr r3, _081A0B2C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _081A0B30 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	ldr r7, _081A0B4C @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #7
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A0B50 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081A0B54 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _081A0B58 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _081A0B66
	.align 2, 0
_081A0B28: .4byte FUN_0819bfa8
_081A0B2C: .4byte 0x0000046D
_081A0B30: .4byte 0x0000046B
_081A0B34: .4byte 0x00000E48
_081A0B38: .4byte 0x00000EB8
_081A0B3C: .4byte 0x000008DC
_081A0B40: .4byte 0x00000ECC
_081A0B44: .4byte 0x0000016F
_081A0B48: .4byte FUN_0819bd2c
_081A0B4C: .4byte 0x00000553
_081A0B50: .4byte 0x00000469
_081A0B54: .4byte 0x0000046A
_081A0B58: .4byte 0x00000484
_081A0B5C:
	ldr r0, _081A0B6C @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0B66:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A0B6C: .4byte 0x00000484

	thumb_func_start FUN_081a0b70
FUN_081a0b70: @ 0x081A0B70
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081A0B90 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A0B94
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A0B96
	.align 2, 0
_081A0B90: .4byte 0x0000046C
_081A0B94:
	movs r0, #0
_081A0B96:
	cmp r0, #0
	beq _081A0BA2
	ldr r0, _081A0BFC @ =0x00000ECD
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_081A0BA2:
	ldr r1, _081A0C00 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0C18
	ldr r2, _081A0C04 @ =0x000008BC
	adds r1, r6, r2
	adds r0, r5, #0
	movs r2, #0xf7
	bl FUN_0819ee40
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _081A0C08 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r4, #0
	strh r1, [r2]
	ldr r1, _081A0C0C @ =0x00000E48
	adds r2, r6, r1
	ldr r1, _081A0C10 @ =0xFFFFEFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _081A0C14 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _081A0C22
	.align 2, 0
_081A0BFC: .4byte 0x00000ECD
_081A0C00: .4byte 0x0000046B
_081A0C04: .4byte 0x000008BC
_081A0C08: .4byte 0xFFFFFEFF
_081A0C0C: .4byte 0x00000E48
_081A0C10: .4byte 0xFFFFEFFF
_081A0C14: .4byte 0x00000484
_081A0C18:
	ldr r0, _081A0C28 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0C22:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A0C28: .4byte 0x00000484

	thumb_func_start FUN_081a0c2c
FUN_081a0c2c: @ 0x081A0C2C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081A0C4C @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A0C50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A0C52
	.align 2, 0
_081A0C4C: .4byte 0x0000046C
_081A0C50:
	movs r0, #0
_081A0C52:
	cmp r0, #0
	beq _081A0C9C
	ldr r4, _081A0D04 @ =FUN_0819b230
	movs r3, #0x29
	ldr r7, _081A0D08 @ =0x0000046D
	adds r1, r6, r7
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A0D0C @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _081A0D10 @ =0x00000EC2
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _081A0D14 @ =0x00000EBA
	adds r0, r5, r2
	strh r1, [r0]
_081A0C9C:
	ldr r4, _081A0D0C @ =0x0000046B
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A0D28
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r1, _081A0D18 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r2, _081A0D1C @ =FUN_0819bd2c
	movs r1, #0x22
	adds r4, #2
	adds r0, r6, r4
	movs r4, #1
	strb r4, [r0]
	ldr r7, _081A0D0C @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r5, [r0]
	movs r1, #4
	subs r7, #0xeb
	adds r0, r6, r7
	strb r3, [r0]
	ldr r2, _081A0D20 @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081A0D24 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	b _081A0D32
	.align 2, 0
_081A0D04: .4byte FUN_0819b230
_081A0D08: .4byte 0x0000046D
_081A0D0C: .4byte 0x0000046B
_081A0D10: .4byte 0x00000EC2
_081A0D14: .4byte 0x00000EBA
_081A0D18: .4byte 0xFFFFFEFF
_081A0D1C: .4byte FUN_0819bd2c
_081A0D20: .4byte 0x00000469
_081A0D24: .4byte 0x00000484
_081A0D28:
	ldr r4, _081A0D38 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A0D32:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A0D38: .4byte 0x00000484

	thumb_func_start FUN_081a0d3c
FUN_081a0d3c: @ 0x081A0D3C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081A0D64 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A0D68
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A0D6A
	.align 2, 0
_081A0D64: .4byte 0x0000046C
_081A0D68:
	movs r0, #0
_081A0D6A:
	adds r7, r5, #0
	adds r7, #8
	cmp r0, #0
	bne _081A0D74
	b _081A0F00
_081A0D74:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _081A0DF0 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r0, #0xea
	lsls r0, r0, #4
	add r0, r8
	strb r1, [r0]
	ldr r0, _081A0DF4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _081A0DF8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A0DFC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081A0E00 @ =0x0203B400
	adds r0, r0, r4
	movs r1, #0xff
	ldrb r6, [r0]
	mov r4, sp
	ldr r3, _081A0E04 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r7, r2, #0
	mov ip, r3
	cmp r0, #0
	blt _081A0E08
	asrs r1, r0, #0xc
	b _081A0E0E
	.align 2, 0
_081A0DF0: .4byte 0x0000046D
_081A0DF4: .4byte 0x03002BE0
_081A0DF8: .4byte 0x030046B8
_081A0DFC: .4byte 0x000003FF
_081A0E00: .4byte 0x0203B400
_081A0E04: .4byte 0x085B0A08
_081A0E08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A0E0E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _081A0E2A
	asrs r0, r0, #0xc
	b _081A0E30
_081A0E2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A0E30:
	strh r0, [r4, #4]
	mov r0, sp
	add r2, sp, #8
	ldrh r1, [r2]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _081A0EC0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	mov r3, sp
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r4, r5, #0
	adds r4, #8
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _081A0EC4 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _081A0EC8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	movs r1, #0xff
	ldr r3, _081A0ECC @ =0x00000F0C
	add r3, r8
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	adds r7, r4, #0
	cmp r0, #0
	blt _081A0ED0
	asrs r1, r0, #0xc
	b _081A0ED6
	.align 2, 0
_081A0EC0: .4byte 0xFFFF0000
_081A0EC4: .4byte 0x000003FF
_081A0EC8: .4byte 0x0203B400
_081A0ECC: .4byte 0x00000F0C
_081A0ED0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A0ED6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _081A0EF0
	asrs r0, r0, #0xc
	b _081A0EF6
_081A0EF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A0EF6:
	strh r0, [r3, #4]
	ldr r1, _081A0FA0 @ =0x00000E56
	add r1, r8
	movs r0, #1
	strh r0, [r1]
_081A0F00:
	movs r6, #0xea
	lsls r6, r6, #4
	add r6, r8
	ldrb r1, [r6]
	mov r4, sp
	lsls r1, r1, #3
	add r1, r8
	ldr r3, _081A0FA4 @ =0x00000E58
	adds r1, r1, r3
	ldrh r0, [r1]
	ldrh r2, [r5, #8]
	subs r0, r0, r2
	mov r2, sp
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_0819ef24
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _081A1000
	ldrb r1, [r6]
	lsls r1, r1, #3
	add r1, r8
	ldr r4, _081A0FA4 @ =0x00000E58
	adds r0, r1, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #8
	ldrsh r2, [r5, r3]
	subs r0, r0, r2
	adds r4, #4
	adds r1, r1, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r0, _081A0FA0 @ =0x00000E56
	add r0, r8
	mov r6, sp
	ldrb r3, [r5, #5]
	ldrh r4, [r0]
	ldr r2, _081A0FA8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A0FAC
	asrs r1, r0, #0xc
	b _081A0FB2
	.align 2, 0
_081A0FA0: .4byte 0x00000E56
_081A0FA4: .4byte 0x00000E58
_081A0FA8: .4byte 0x085B0A08
_081A0FAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A0FB2:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _081A0FCC @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A0FD0
	asrs r0, r0, #0xc
	b _081A0FD6
	.align 2, 0
_081A0FCC: .4byte 0x085B0A08
_081A0FD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A0FD6:
	strh r0, [r6, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r4, [r5, #0x14]
	adds r0, r0, r4
	strh r0, [r5, #0x14]
	ldr r2, _081A0FFC @ =0x00000F0C
	add r2, r8
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	b _081A1124
	.align 2, 0
_081A0FFC: .4byte 0x00000F0C
_081A1000:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _081A1010
	b _081A1124
_081A1010:
	ldr r3, _081A1098 @ =0x00000F0C
	add r3, r8
	ldr r2, _081A109C @ =0x00000E98
	add r2, r8
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _081A10A0 @ =0x00000F0E
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r5, #8]
	ldr r0, _081A10A4 @ =0x00000E9C
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	movs r0, #0
	strb r0, [r6]
	ldr r0, _081A10A8 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _081A10AC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A10B0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081A10B4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r4, r0, r2
	movs r1, #0xff
	mov r3, sp
	ands r4, r1
	ldr r2, _081A10B8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	mov ip, r2
	cmp r0, #0
	blt _081A10BC
	asrs r1, r0, #0xc
	b _081A10C2
	.align 2, 0
_081A1098: .4byte 0x00000F0C
_081A109C: .4byte 0x00000E98
_081A10A0: .4byte 0x00000F0E
_081A10A4: .4byte 0x00000E9C
_081A10A8: .4byte 0x03002BE0
_081A10AC: .4byte 0x030046B8
_081A10B0: .4byte 0x000003FF
_081A10B4: .4byte 0x0203B400
_081A10B8: .4byte 0x085B0A08
_081A10BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A10C2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _081A10DE
	asrs r0, r0, #0xc
	b _081A10E4
_081A10DE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A10E4:
	strh r0, [r3, #4]
	add r2, sp, #8
	mov r0, sp
	ldrh r1, [r0]
	ldrh r3, [r2]
	adds r1, r1, r3
	strh r1, [r2]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r2, #4]
	adds r0, r0, r4
	strh r0, [r2, #4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _081A1120 @ =0x00000E56
	add r1, r8
	ldrh r0, [r1]
	lsrs r0, r0, #1
	strh r0, [r1]
	b _081A114C
	.align 2, 0
_081A1120: .4byte 0x00000E56
_081A1124:
	ldr r1, _081A1158 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081A1142
	ldr r1, _081A115C @ =0x00000E56
	add r1, r8
	ldrh r0, [r1]
	cmp r0, #0xb
	bhi _081A1142
	adds r0, #1
	strh r0, [r1]
_081A1142:
	ldr r2, _081A1158 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A114C:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A1158: .4byte 0x00000484
_081A115C: .4byte 0x00000E56

	thumb_func_start FUN_081a1160
FUN_081a1160: @ 0x081A1160
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081A1188 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A118C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A118E
	.align 2, 0
_081A1188: .4byte 0x0000046C
_081A118C:
	movs r0, #0
_081A118E:
	adds r7, r5, #0
	adds r7, #8
	cmp r0, #0
	bne _081A1198
	b _081A1324
_081A1198:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _081A1214 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r0, #0xea
	lsls r0, r0, #4
	add r0, r8
	strb r1, [r0]
	ldr r0, _081A1218 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _081A121C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A1220 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081A1224 @ =0x0203B400
	adds r0, r0, r4
	movs r1, #0xff
	ldrb r6, [r0]
	mov r4, sp
	ldr r3, _081A1228 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r7, r2, #0
	mov ip, r3
	cmp r0, #0
	blt _081A122C
	asrs r1, r0, #0xc
	b _081A1232
	.align 2, 0
_081A1214: .4byte 0x0000046D
_081A1218: .4byte 0x03002BE0
_081A121C: .4byte 0x030046B8
_081A1220: .4byte 0x000003FF
_081A1224: .4byte 0x0203B400
_081A1228: .4byte 0x085B0A08
_081A122C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A1232:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _081A124E
	asrs r0, r0, #0xc
	b _081A1254
_081A124E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A1254:
	strh r0, [r4, #4]
	mov r0, sp
	add r2, sp, #8
	ldrh r1, [r2]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _081A12E4 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	mov r3, sp
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r2, #4]
	adds r4, r5, #0
	adds r4, #8
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _081A12E8 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _081A12EC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r2, r0, r2
	movs r1, #0xff
	ldr r3, _081A12F0 @ =0x00000F0C
	add r3, r8
	ands r2, r1
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	adds r7, r4, #0
	cmp r0, #0
	blt _081A12F4
	asrs r1, r0, #0xc
	b _081A12FA
	.align 2, 0
_081A12E4: .4byte 0xFFFF0000
_081A12E8: .4byte 0x000003FF
_081A12EC: .4byte 0x0203B400
_081A12F0: .4byte 0x00000F0C
_081A12F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A12FA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r2, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _081A1314
	asrs r0, r0, #0xc
	b _081A131A
_081A1314:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A131A:
	strh r0, [r3, #4]
	ldr r1, _081A13C4 @ =0x00000E56
	add r1, r8
	movs r0, #1
	strh r0, [r1]
_081A1324:
	movs r6, #0xea
	lsls r6, r6, #4
	add r6, r8
	ldrb r1, [r6]
	mov r4, sp
	lsls r1, r1, #3
	add r1, r8
	ldr r3, _081A13C8 @ =0x00000E58
	adds r1, r1, r3
	ldrh r0, [r1]
	ldrh r2, [r5, #8]
	subs r0, r0, r2
	mov r2, sp
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_0819ef24
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r1, r0
	ble _081A1424
	ldrb r1, [r6]
	lsls r1, r1, #3
	add r1, r8
	ldr r4, _081A13C8 @ =0x00000E58
	adds r0, r1, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #8
	ldrsh r2, [r5, r3]
	subs r0, r0, r2
	adds r4, #4
	adds r1, r1, r4
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r0, _081A13C4 @ =0x00000E56
	add r0, r8
	mov r6, sp
	ldrb r3, [r5, #5]
	ldrh r4, [r0]
	ldr r2, _081A13CC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A13D0
	asrs r1, r0, #0xc
	b _081A13D6
	.align 2, 0
_081A13C4: .4byte 0x00000E56
_081A13C8: .4byte 0x00000E58
_081A13CC: .4byte 0x085B0A08
_081A13D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A13D6:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	ldr r1, _081A13F0 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A13F4
	asrs r0, r0, #0xc
	b _081A13FA
	.align 2, 0
_081A13F0: .4byte 0x085B0A08
_081A13F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A13FA:
	strh r0, [r6, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r4, [r5, #0x14]
	adds r0, r0, r4
	strh r0, [r5, #0x14]
	ldr r2, _081A1420 @ =0x00000F0C
	add r2, r8
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0x14]
	str r0, [r2]
	str r1, [r2, #4]
	b _081A153A
	.align 2, 0
_081A1420: .4byte 0x00000F0C
_081A1424:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bhi _081A1434
	b _081A153A
_081A1434:
	ldr r3, _081A14BC @ =0x00000F0C
	add r3, r8
	ldr r2, _081A14C0 @ =0x00000E98
	add r2, r8
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r1, _081A14C4 @ =0x00000F0E
	add r1, r8
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r2]
	strh r0, [r5, #8]
	ldr r0, _081A14C8 @ =0x00000E9C
	add r0, r8
	ldrh r0, [r0]
	strh r0, [r5, #0xc]
	movs r0, #0
	strb r0, [r6]
	ldr r0, _081A14CC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r2, _081A14D0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A14D4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081A14D8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0x3f
	ands r0, r1
	ldrb r2, [r2]
	adds r4, r0, r2
	movs r1, #0xff
	mov r3, sp
	ands r4, r1
	ldr r2, _081A14DC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	mov ip, r2
	cmp r0, #0
	blt _081A14E0
	asrs r1, r0, #0xc
	b _081A14E6
	.align 2, 0
_081A14BC: .4byte 0x00000F0C
_081A14C0: .4byte 0x00000E98
_081A14C4: .4byte 0x00000F0E
_081A14C8: .4byte 0x00000E9C
_081A14CC: .4byte 0x03002BE0
_081A14D0: .4byte 0x030046B8
_081A14D4: .4byte 0x000003FF
_081A14D8: .4byte 0x0203B400
_081A14DC: .4byte 0x085B0A08
_081A14E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A14E6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	add r0, ip
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _081A1502
	asrs r0, r0, #0xc
	b _081A1508
_081A1502:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A1508:
	strh r0, [r3, #4]
	add r2, sp, #8
	mov r0, sp
	ldrh r1, [r0]
	ldrh r3, [r2]
	adds r1, r1, r3
	strh r1, [r2]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r2, #4]
	adds r0, r0, r4
	strh r0, [r2, #4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	b _081A1562
_081A153A:
	ldr r1, _081A1570 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081A1558
	ldr r1, _081A1574 @ =0x00000E56
	add r1, r8
	ldrh r0, [r1]
	cmp r0, #0x11
	bhi _081A1558
	adds r0, #1
	strh r0, [r1]
_081A1558:
	ldr r2, _081A1570 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A1562:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A1570: .4byte 0x00000484
_081A1574: .4byte 0x00000E56

	thumb_func_start FUN_081a1578
FUN_081a1578: @ 0x081A1578
	ldr r1, _081A1584 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _081A1588 @ =0x085ADDDC
	str r1, [r0]
	bx lr
	.align 2, 0
_081A1584: .4byte 0x0000063C
_081A1588: .4byte 0x085ADDDC

	thumb_func_start FUN_081a158c
FUN_081a158c: @ 0x081A158C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081A15A4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A15A8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A15AA
	.align 2, 0
_081A15A4: .4byte 0x0000046C
_081A15A8:
	movs r0, #0
_081A15AA:
	cmp r0, #0
	beq _081A15F2
	ldr r4, _081A160C @ =FUN_0819cfcc
	movs r3, #0xa
	ldr r2, _081A1610 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A1614 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	subs r1, #0x48
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_081A15F2:
	ldr r1, _081A1614 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A161C
	ldr r0, _081A1618 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_0819e324
	b _081A1626
	.align 2, 0
_081A160C: .4byte FUN_0819cfcc
_081A1610: .4byte 0x0000046D
_081A1614: .4byte 0x0000046B
_081A1618: .4byte 0x03002BE0
_081A161C:
	ldr r2, _081A162C @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A1626:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A162C: .4byte 0x00000484

	thumb_func_start FUN_081a1630
FUN_081a1630: @ 0x081A1630
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _081A16B4 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A1654
	movs r0, #0
	strb r0, [r1]
_081A1654:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081A166A
	b _081A17A4
_081A166A:
	ldr r2, _081A16B8 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _081A1676
	b _081A17A0
_081A1676:
	adds r0, r6, #0
	bl FUN_0819dd78
	add r7, sp, #4
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r7]
	ldrh r1, [r1, #2]
	strh r1, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r7, #0
	cmp r2, #0
	blt _081A16AE
	cmp r1, #0
	blt _081A16AE
	ldr r0, _081A16BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081A16AE
	ldr r0, _081A16C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081A16C4
_081A16AE:
	movs r4, #0
	b _081A16D2
	.align 2, 0
_081A16B4: .4byte 0x0000046C
_081A16B8: .4byte 0x00000484
_081A16BC: .4byte 0x030046A8
_081A16C0: .4byte 0x030046AC
_081A16C4:
	ldr r0, _081A16E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081A16D2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A16E8
	adds r0, #4
	b _081A16F4
	.align 2, 0
_081A16E4: .4byte 0x030046A4
_081A16E8:
	ldr r0, _081A1708 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A16F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A170C
	cmp r2, #2
	beq _081A1710
	b _081A1714
	.align 2, 0
_081A1708: .4byte 0x030046A4
_081A170C:
	ldrb r0, [r7, #4]
	b _081A1712
_081A1710:
	ldrb r0, [r7]
_081A1712:
	subs r1, r1, r0
_081A1714:
	movs r4, #0
	movs r0, #0
	mov r8, r0
	strh r1, [r7, #2]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0819dfc0
	adds r0, r6, #0
	bl FUN_0819dffc
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #0x1a
	adds r0, r6, r2
	mov r2, r8
	str r2, [r0]
	ldr r2, _081A1794 @ =0x0000046C
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, r6, #0
	adds r3, #8
	add r2, sp, #4
	ldrh r0, [r2]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r2, #4
	ldrsh r1, [r5, r2]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	ldr r1, _081A1798 @ =0x00000F0C
	add r1, sb
	mov r0, r8
	str r0, [sp]
	mov r0, sp
	ldr r2, _081A179C @ =0x05000002
	bl CpuSet
	b _081A17A4
	.align 2, 0
_081A1794: .4byte 0x0000046C
_081A1798: .4byte 0x00000F0C
_081A179C: .4byte 0x05000002
_081A17A0:
	adds r0, #1
	str r0, [r1]
_081A17A4:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081a17b4
FUN_081a17b4: @ 0x081A17B4
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _081A17C0 @ =0x085ADE08
	str r1, [r0]
	bx lr
	.align 2, 0
_081A17C0: .4byte 0x085ADE08

	thumb_func_start FUN_081a17c4
FUN_081a17c4: @ 0x081A17C4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r4, r6
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081A1814 @ =0x00000EAC
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #2
	bhi _081A17F6
	adds r0, #1
	strb r0, [r1]
_081A17F6:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081A1864
	movs r1, #4
	ldr r2, _081A1818 @ =0x00000E48
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A181C
	movs r0, #1
	b _081A181E
	.align 2, 0
_081A1814: .4byte 0x00000EAC
_081A1818: .4byte 0x00000E48
_081A181C:
	movs r0, #0
_081A181E:
	adds r3, r0, #0
	cmp r3, #0
	bne _081A1864
	ldr r6, _081A1858 @ =0x00000EAC
	adds r5, r5, r6
	ldrb r0, [r5]
	cmp r0, #2
	bls _081A1864
	movs r1, #2
	movs r2, #6
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r3, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _081A185C @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _081A1860 @ =0x00000484
	adds r0, r4, r2
	str r3, [r0]
	adds r6, #3
	adds r1, r4, r6
	movs r0, #1
	strb r0, [r1]
	strb r3, [r5]
	b _081A1866
	.align 2, 0
_081A1858: .4byte 0x00000EAC
_081A185C: .4byte 0x0000046A
_081A1860: .4byte 0x00000484
_081A1864:
	movs r0, #1
_081A1866:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081a186c
FUN_081a186c: @ 0x081A186C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081a0530
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _081A18A4 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	adds r0, r4, #0
	bl FUN_081a054c
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081A18A4: .4byte 0x0000062C

	thumb_func_start FUN_081a18a8
FUN_081a18a8: @ 0x081A18A8
	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r1, _081A18C4 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	str r1, [r2]
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081A18C4: .4byte 0x03002BE0

	thumb_func_start FUN_081a18c8
FUN_081a18c8: @ 0x081A18C8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0819ff9c
	adds r0, r4, #0
	bl FUN_0819f3cc
	adds r0, r4, #0
	bl FUN_0819fca4
	ldr r1, _081A18F0 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A18F4
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _081A18FC
	.align 2, 0
_081A18F0: .4byte 0x0000025D
_081A18F4:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_081A18FC:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081A1918 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081A191C
	movs r0, #1
	b _081A191E
	.align 2, 0
_081A1918: .4byte 0x00000474
_081A191C:
	movs r0, #0
_081A191E:
	cmp r0, #0
	beq _081A192A
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_081A192A:
	ldr r1, _081A1984 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081A1942
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_081A1942:
	ldr r0, _081A1988 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081A195A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_081A195A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081A1972
	adds r0, r4, #0
	bl FUN_08002a58
_081A1972:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081A198C
	movs r0, #1
	b _081A198E
	.align 2, 0
_081A1984: .4byte 0x0000044C
_081A1988: .4byte 0x0000044D
_081A198C:
	movs r0, #0
_081A198E:
	cmp r0, #0
	beq _081A199A
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081A199A:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EnemyAx_Init
EnemyAx_Init: @ 0x081A19B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1ac
	adds r7, r0, #0
	str r7, [sp, #0x24]
	ldr r1, _081A1A40 @ =0x00000E48
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _081A1A44 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0xd
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0819e1b4
	ldr r3, _081A1A48 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A1A54
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081A1A4C @ =0x00005291
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _081A1A50 @ =0x00003F72
	bl FUN_080e3804
	ldr r4, _081A1A44 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x70]
	cmp r1, #0x11
	beq _081A1A30
	cmp r1, #0x17
	bne _081A1A34
_081A1A30:
	movs r0, #1
	strb r0, [r5, #7]
_081A1A34:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081A1ABC
	.align 2, 0
_081A1A40: .4byte 0x00000E48
_081A1A44: .4byte 0x000001DF
_081A1A48: .4byte 0x0000025D
_081A1A4C: .4byte 0x00005291
_081A1A50: .4byte 0x00003F72
_081A1A54:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x14
	mov r8, r0
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _081A1B38 @ =0x05000002
	bl CpuSet
	ldr r0, _081A1B3C @ =0x0000CB05
	ldr r1, _081A1B40 @ =0x00005291
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _081A1B44 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081A1B48 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x70]
_081A1ABC:
	str r7, [sp, #0x28]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _081A1B4C @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, _081A1B50 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081A1B38 @ =0x05000002
	bl CpuSet
	ldr r3, _081A1B54 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a4]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x40]
	mov r3, r8
	str r3, [sp, #0x44]
	str r6, [sp, #0x184]
	ldr r2, [sp, #0x1a4]
	adds r6, r2, #0
	cmp r0, #0
	bne _081A1B28
	b _081A1C88
_081A1B28:
	bl VM_GetPC
	cmp r0, #0
	beq _081A1B58
	bl Script_GetValue
	adds r1, r0, #0
	b _081A1B5A
	.align 2, 0
_081A1B38: .4byte 0x05000002
_081A1B3C: .4byte 0x0000CB05
_081A1B40: .4byte 0x00005291
_081A1B44: .4byte 0x000004B7
_081A1B48: .4byte 0x000001DF
_081A1B4C: .4byte 0x0000046F
_081A1B50: .4byte 0x00000474
_081A1B54: .4byte 0x000004B6
_081A1B58:
	movs r1, #0
_081A1B5A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081A1B80 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xcc]
	str r4, [sp, #0xd0]
	cmp r0, #0
	beq _081A1B84
	bl Script_GetValue
	adds r1, r0, #0
	b _081A1B86
	.align 2, 0
_081A1B80: .4byte 0x00000251
_081A1B84:
	movs r1, #0
_081A1B86:
	ldr r2, _081A1BBC @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081A1BC0 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xcc]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xd8]
	cmp r0, #0
	beq _081A1BC4
	bl Script_GetValue
	b _081A1BC8
	.align 2, 0
_081A1BBC: .4byte 0x00000252
_081A1BC0: .4byte 0x000004B4
_081A1BC4:
	ldr r4, [sp, #0xcc]
	ldrb r0, [r4]
_081A1BC8:
	strb r0, [r6]
	ldr r5, [sp, #0xcc]
	ldrb r1, [r5]
	ldr r6, [sp, #0xd8]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl FUN_08234f90
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081A1C00
	cmp r1, #0
	blt _081A1C00
	ldr r0, _081A1C04 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081A1C00
	ldr r0, _081A1C08 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081A1C0C
_081A1C00:
	movs r1, #0
	b _081A1C1A
	.align 2, 0
_081A1C04: .4byte 0x030046A8
_081A1C08: .4byte 0x030046AC
_081A1C0C:
	ldr r0, _081A1C34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081A1C1A:
	ldr r2, _081A1C38 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A1C3C
	adds r0, #4
	b _081A1C48
	.align 2, 0
_081A1C34: .4byte 0x030046A4
_081A1C38: .4byte 0x00000256
_081A1C3C:
	ldr r0, _081A1C5C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A1C48:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A1C60
	cmp r2, #2
	beq _081A1C64
	b _081A1C68
	.align 2, 0
_081A1C5C: .4byte 0x030046A4
_081A1C60:
	ldrb r0, [r4, #4]
	b _081A1C66
_081A1C64:
	ldrb r0, [r4]
_081A1C66:
	subs r1, r1, r0
_081A1C68:
	ldr r3, _081A1C80 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081A1C84 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081A1CC8
	.align 2, 0
_081A1C80: .4byte 0x00000472
_081A1C84: .4byte 0x0000FFFF
_081A1C88:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081A1CEC @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081A1CF0 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081A1CF4 @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x2c]
	str r5, [sp, #0xcc]
	str r4, [sp, #0xd0]
	str r3, [sp, #0xd8]
_081A1CC8:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081A1D12
	bl VM_GetPC
	cmp r0, #0
	beq _081A1CF8
	bl Script_GetValue
	adds r4, r0, #0
	b _081A1CFA
	.align 2, 0
_081A1CEC: .4byte 0x00000251
_081A1CF0: .4byte 0x00000252
_081A1CF4: .4byte 0x000004B4
_081A1CF8:
	movs r4, #0x30
_081A1CFA:
	bl VM_GetPC
	cmp r0, #0
	beq _081A1D0C
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081A1D0E
_081A1D0C:
	movs r5, #0x40
_081A1D0E:
	mov r8, r4
	b _081A1D18
_081A1D12:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081A1D18:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081A1D50
	bl VM_GetPC
	cmp r0, #0
	beq _081A1D32
	bl Script_GetValue
	adds r6, r0, #0
	b _081A1D34
_081A1D32:
	movs r6, #0
_081A1D34:
	bl VM_GetPC
	cmp r0, #0
	beq _081A1D44
	bl Script_GetValue
	adds r1, r0, #0
	b _081A1D46
_081A1D44:
	movs r1, #0
_081A1D46:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081A1D5A
_081A1D50:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081A1D5A:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _081A1FD8 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xec]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xc4]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x4c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x48]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xdc]
	lsls r4, r4, #0x10
	str r4, [sp, #0x64]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x6c]
	lsls r6, r6, #0x10
	str r6, [sp, #0x74]
	lsls r5, r5, #0x10
	str r5, [sp, #0x68]
	ldr r4, _081A1FDC @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xe8]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x5c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x16c]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x7c]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x170]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x174]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x168]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x19c]
	ldr r1, _081A1FE0 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x190]
	ldr r2, _081A1FE4 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x194]
	ldr r3, _081A1FE8 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x198]
	ldr r4, _081A1FEC @ =0x00000476
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0x8f
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x18c]
	ldr r6, _081A1FF0 @ =0x000004A4
	adds r6, r7, r6
	str r6, [sp, #0x38]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x3c]
	movs r2, #0xb0
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xb8]
	movs r3, #0xb1
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xc0]
	movs r4, #0xb2
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xd4]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xf4]
	ldr r6, _081A1FF4 @ =0x000005A4
	adds r6, r7, r6
	str r6, [sp, #0xf8]
	movs r1, #0xb8
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	ldr r2, _081A1FF8 @ =0x000005C4
	adds r2, r7, r2
	str r2, [sp, #0x110]
	ldr r3, _081A1FFC @ =0x000005CC
	adds r3, r7, r3
	str r3, [sp, #0x118]
	movs r4, #0xba
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	ldr r5, _081A2000 @ =0x000005D4
	adds r5, r7, r5
	str r5, [sp, #0x120]
	ldr r6, _081A2004 @ =0x000005DC
	adds r6, r7, r6
	str r6, [sp, #0x128]
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x114]
	ldr r2, _081A2008 @ =0x00000584
	adds r2, r7, r2
	str r2, [sp, #0xbc]
	ldr r3, _081A200C @ =0x00000604
	adds r3, r7, r3
	str r3, [sp, #0x14c]
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x150]
	ldr r5, _081A2010 @ =0x0000021D
	adds r5, r7, r5
	str r5, [sp, #0x88]
	ldr r6, _081A2014 @ =0x0000060C
	adds r6, r7, r6
	str r6, [sp, #0x154]
	movs r1, #0xbe
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x13c]
	ldr r2, _081A2018 @ =0x000005E4
	adds r2, r7, r2
	str r2, [sp, #0x130]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x140]
	ldr r4, _081A201C @ =0x000005FC
	adds r4, r7, r4
	str r4, [sp, #0x144]
	movs r5, #0xc0
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x148]
	ldr r6, _081A2020 @ =0x00000614
	adds r6, r7, r6
	str r6, [sp, #0x158]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x15c]
	ldr r2, _081A2024 @ =0x000005BC
	adds r2, r7, r2
	str r2, [sp, #0x108]
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x134]
	movs r4, #0xbc
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x12c]
	ldr r5, _081A2028 @ =0x000005EC
	adds r5, r7, r5
	str r5, [sp, #0x138]
	movs r6, #0xbb
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x124]
	movs r1, #0xb5
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	ldr r2, _081A202C @ =0x00000624
	adds r2, r7, r2
	str r2, [sp, #0x160]
	ldr r3, _081A2030 @ =0x0000058C
	adds r3, r7, r3
	str r3, [sp, #0xc8]
	movs r4, #0xc5
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x164]
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x104]
	ldr r6, _081A2034 @ =0x00000594
	adds r6, r7, r6
	str r6, [sp, #0xe0]
	movs r1, #0xb3
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	ldr r2, _081A2038 @ =0x0000059C
	adds r2, r7, r2
	str r2, [sp, #0xf0]
	ldr r3, _081A203C @ =0x000005B4
	adds r3, r7, r3
	str r3, [sp, #0x100]
	ldr r4, _081A2040 @ =0x00000543
	adds r4, r7, r4
	str r4, [sp, #0x80]
	movs r5, #0xcc
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0x50]
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r1, _081A2044 @ =0x00000496
	adds r1, r7, r1
	str r1, [sp, #0x34]
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x178]
	ldr r3, _081A2048 @ =0x00000469
	adds r3, r7, r3
	str r3, [sp, #0x17c]
	ldr r4, _081A204C @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x180]
	ldr r5, _081A2050 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x84]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb4]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x30]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x60]
	ldr r3, _081A2054 @ =0x00000572
	adds r3, r7, r3
	str r3, [sp, #0xb0]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x58]
	movs r5, #0xae
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xac]
	ldr r6, _081A2058 @ =0x0000055C
	adds r6, r7, r6
	str r6, [sp, #0x8c]
	movs r1, #0xac
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x90]
	ldr r2, _081A205C @ =0x00000564
	adds r2, r7, r2
	str r2, [sp, #0x94]
	ldr r3, _081A2060 @ =0x00000565
	adds r3, r7, r3
	str r3, [sp, #0x98]
	ldr r4, _081A2064 @ =0x00000566
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	ldr r5, _081A2068 @ =0x00000567
	adds r5, r7, r5
	str r5, [sp, #0xa0]
	movs r6, #0xad
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	ldr r1, _081A206C @ =0x0000056C
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	cmp r0, #0
	bne _081A1FAA
	b _081A20C8
_081A1FAA:
	movs r2, #0
	mov sl, r2
	movs r3, #0x8d
	lsls r3, r3, #2
	adds r3, r3, r7
	mov sb, r3
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r4, r4, r7
	mov r8, r4
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_081A1FCA:
	bl VM_GetPC
	cmp r0, #0
	beq _081A2070
	bl Script_GetValue
	b _081A2072
	.align 2, 0
_081A1FD8: .4byte 0x0000025D
_081A1FDC: .4byte 0x0000025A
_081A1FE0: .4byte 0x0000047A
_081A1FE4: .4byte 0x0000047C
_081A1FE8: .4byte 0x0000047E
_081A1FEC: .4byte 0x00000476
_081A1FF0: .4byte 0x000004A4
_081A1FF4: .4byte 0x000005A4
_081A1FF8: .4byte 0x000005C4
_081A1FFC: .4byte 0x000005CC
_081A2000: .4byte 0x000005D4
_081A2004: .4byte 0x000005DC
_081A2008: .4byte 0x00000584
_081A200C: .4byte 0x00000604
_081A2010: .4byte 0x0000021D
_081A2014: .4byte 0x0000060C
_081A2018: .4byte 0x000005E4
_081A201C: .4byte 0x000005FC
_081A2020: .4byte 0x00000614
_081A2024: .4byte 0x000005BC
_081A2028: .4byte 0x000005EC
_081A202C: .4byte 0x00000624
_081A2030: .4byte 0x0000058C
_081A2034: .4byte 0x00000594
_081A2038: .4byte 0x0000059C
_081A203C: .4byte 0x000005B4
_081A2040: .4byte 0x00000543
_081A2044: .4byte 0x00000496
_081A2048: .4byte 0x00000469
_081A204C: .4byte 0x0000046A
_081A2050: .4byte 0x00000553
_081A2054: .4byte 0x00000572
_081A2058: .4byte 0x0000055C
_081A205C: .4byte 0x00000564
_081A2060: .4byte 0x00000565
_081A2064: .4byte 0x00000566
_081A2068: .4byte 0x00000567
_081A206C: .4byte 0x0000056C
_081A2070:
	movs r0, #0x18
_081A2072:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081A2084
	bl Script_GetValue
	b _081A2086
_081A2084:
	movs r0, #0x18
_081A2086:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081A2098
	bl Script_GetValue
	b _081A209A
_081A2098:
	movs r0, #0
_081A209A:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081A20AC
	bl Script_GetValue
	b _081A20AE
_081A20AC:
	movs r0, #0
_081A20AE:
	strh r0, [r6]
	movs r1, #2
	add sb, r1
	movs r2, #4
	add r8, r2
	adds r5, #2
	adds r4, #2
	movs r3, #1
	add sl, r3
	mov r6, sl
	cmp r6, #3
	bgt _081A20C8
	b _081A1FCA
_081A20C8:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081A2114
	bl VM_GetPC
	cmp r0, #0
	beq _081A20E2
	bl Script_GetValue
	adds r4, r0, #0
	b _081A20E6
_081A20E2:
	movs r4, #0x96
	lsls r4, r4, #1
_081A20E6:
	bl VM_GetPC
	cmp r0, #0
	beq _081A20F6
	bl Script_GetValue
	adds r6, r0, #0
	b _081A20FA
_081A20F6:
	movs r6, #0x96
	lsls r6, r6, #1
_081A20FA:
	bl VM_GetPC
	cmp r0, #0
	beq _081A2108
	bl Script_GetValue
	b _081A210E
_081A2108:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_081A210E:
	ldr r2, [sp, #0xc4]
	strh r0, [r2]
	b _081A211C
_081A2114:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0xc4]
	strh r6, [r3]
_081A211C:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081A2134
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x44]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081A2134:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x4c]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x48]
	strh r0, [r2]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081A2204
	bl VM_GetPC
	cmp r0, #0
	beq _081A2164
	bl Script_GetValue
	b _081A2166
_081A2164:
	movs r0, #0
_081A2166:
	ldr r3, [sp, #0xdc]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _081A2174
	asrs r1, r0, #1
	b _081A217A
_081A2174:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081A217A:
	ldr r5, _081A2190 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A2194
	bl Script_GetValue
	b _081A2196
	.align 2, 0
_081A2190: .4byte 0x00000546
_081A2194:
	movs r0, #0
_081A2196:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081A21AC
	bl Script_GetValue
	b _081A21AE
_081A21AC:
	movs r0, #0
_081A21AE:
	ldr r3, _081A21C4 @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081A21C8
	bl Script_GetValue
	adds r1, r0, #0
	b _081A21CA
	.align 2, 0
_081A21C4: .4byte 0x00000187
_081A21C8:
	movs r1, #0
_081A21CA:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081A21E0
	bl Script_GetValue
	b _081A21E2
_081A21E0:
	movs r0, #0
_081A21E2:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081A21FA
	bl Script_GetValue
	adds r1, r0, #0
	b _081A21FC
_081A21FA:
	movs r1, #0
_081A21FC:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081A2204:
	ldr r5, [sp, #0xdc]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0x64]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0x6c]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0x74]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0x68]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081A2266
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _081A224C
	bl Script_GetValue
	b _081A224E
_081A224C:
	movs r0, #0
_081A224E:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081A225E
	bl Script_GetValue
	b _081A2260
_081A225E:
	movs r0, #0
_081A2260:
	ldr r6, _081A22C8 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_081A2266:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r1, [sp, #0xe8]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081A228A
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x44]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081A228A:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081A22A2
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x44]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081A22A2:
	ldr r4, [sp, #0x5c]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x184]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081A22CC
	movs r0, #1
	b _081A22CE
	.align 2, 0
_081A22C8: .4byte 0x00000189
_081A22CC:
	movs r0, #0
_081A22CE:
	cmp r0, #0
	beq _081A22DE
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081A2308 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_081A22DE:
	ldr r6, [sp, #0xec]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _081A22EA
	ldr r1, [r7, #0x44]
_081A22EA:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r1, [sp, #0x70]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _081A230C
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x16c]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _081A2318
	.align 2, 0
_081A2308: .4byte FUN_080f48ac
_081A230C:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x16c]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_081A2318:
	ldr r2, [sp, #0x70]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081A2366
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081A2366
	cmp r0, #0x16
	beq _081A2366
	cmp r0, #0x14
	beq _081A2366
	cmp r0, #9
	beq _081A2366
	cmp r0, #0x19
	beq _081A2366
	cmp r0, #0x1a
	beq _081A2366
	cmp r0, #0xd
	beq _081A2366
	cmp r0, #0x1b
	beq _081A2366
	cmp r0, #0x1f
	beq _081A2366
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0xcc]
	ldrb r2, [r3]
	ldr r4, [sp, #0xd0]
	ldrb r3, [r4]
	ldr r5, [sp, #0xd8]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_081A2366:
	movs r1, #8
	ldr r6, [sp, #0x184]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081A2376
	movs r0, #1
	b _081A2378
_081A2376:
	movs r0, #0
_081A2378:
	cmp r0, #0
	beq _081A2386
	ldr r1, [sp, #0x7c]
	ldr r0, [r1]
	ldr r2, [sp, #0x78]
	str r0, [r2]
	b _081A2398
_081A2386:
	ldr r3, [sp, #0x7c]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0x78]
	str r0, [r4]
_081A2398:
	ldrh r0, [r7]
	ldr r5, [sp, #0x170]
	strh r0, [r5]
	ldr r6, [sp, #0x168]
	ldr r0, [sp, #0x174]
	str r6, [r0]
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _081A23C2
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r2, [sp, #0x28]
	strb r0, [r2, #5]
_081A23C2:
	adds r0, r7, #0
	bl FUN_0819e56c
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081A24B0
	bl VM_GetPC
	cmp r0, #0
	beq _081A23E0
	bl Script_GetValue
	b _081A23E2
_081A23E0:
	movs r0, #0
_081A23E2:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _081A23F2
	bl Script_GetValue
	b _081A23F4
_081A23F2:
	movs r0, #0
_081A23F4:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _081A2404
	bl Script_GetValue
	b _081A2406
_081A2404:
	movs r0, #0
_081A2406:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x168]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081A242E
	cmp r1, #0
	blt _081A242E
	ldr r0, _081A2434 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081A242E
	ldr r0, _081A2438 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081A243C
_081A242E:
	movs r1, #0
	b _081A244A
	.align 2, 0
_081A2434: .4byte 0x030046A8
_081A2438: .4byte 0x030046AC
_081A243C:
	ldr r0, _081A2464 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081A244A:
	ldr r4, _081A2468 @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x168]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A246C
	adds r0, #4
	b _081A2478
	.align 2, 0
_081A2464: .4byte 0x030046A4
_081A2468: .4byte 0x00000256
_081A246C:
	ldr r0, _081A248C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A2478:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A2490
	cmp r2, #2
	beq _081A2494
	b _081A2498
	.align 2, 0
_081A248C: .4byte 0x030046A4
_081A2490:
	ldrb r0, [r5, #4]
	b _081A2496
_081A2494:
	ldrb r0, [r5]
_081A2496:
	subs r1, r1, r0
_081A2498:
	ldr r5, _081A24A8 @ =0x00000472
	adds r0, r7, r5
	strh r1, [r0]
	ldr r6, [sp, #0x24]
	ldr r2, _081A24AC @ =0x00000E54
	adds r0, r6, r2
	b _081A24BC
	.align 2, 0
_081A24A8: .4byte 0x00000472
_081A24AC: .4byte 0x00000E54
_081A24B0:
	ldr r3, _081A2514 @ =0x00000472
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, [sp, #0x24]
	ldr r5, _081A2518 @ =0x00000E54
	adds r0, r4, r5
_081A24BC:
	strh r1, [r0]
	adds r0, r7, #0
	bl FUN_081a0470
	ldr r6, [sp, #0x24]
	ldr r0, _081A251C @ =0x00000F14
	adds r2, r6, r0
	ldr r0, _081A2520 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r4, _081A2524 @ =0x0000012D
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x19c]
	strh r0, [r1]
	ldr r2, [sp, #0x190]
	strh r4, [r2]
	ldr r3, [sp, #0x194]
	strh r5, [r3]
	ldrh r0, [r1]
	adds r0, r0, r4
	ldr r4, [sp, #0x198]
	strh r0, [r4]
	ldrh r1, [r2]
	ldr r5, [sp, #0x19c]
	ldrh r0, [r5]
	adds r1, r1, r0
	ldr r6, [sp, #0xec]
	ldrb r0, [r6]
	cmp r0, #0
	bne _081A2528
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081A2534
	.align 2, 0
_081A2514: .4byte 0x00000472
_081A2518: .4byte 0x00000E54
_081A251C: .4byte 0x00000F14
_081A2520: .4byte 0x03002BE0
_081A2524: .4byte 0x0000012D
_081A2528:
	ldr r2, [r7, #0x44]
	ldr r0, _081A256C @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081A2534:
	ldr r1, [sp, #0xec]
	ldrb r0, [r1]
	cmp r0, #1
	bne _081A2584
	ldr r2, [sp, #0x70]
	ldrb r0, [r2]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081A2570
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _081A257A
	.align 2, 0
_081A256C: .4byte 0x03003584
_081A2570:
	ldr r3, [sp, #0x70]
	ldrb r0, [r3]
	bl FUN_080ecf60
	adds r4, r0, #1
_081A257A:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081A2584:
	movs r4, #0
	ldr r5, [sp, #0x190]
	ldrh r0, [r5]
	ldr r6, [sp, #0x188]
	strh r0, [r6]
	ldrh r0, [r5]
	adds r0, #2
	ldr r1, [sp, #0x18c]
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_0819edcc
	ldr r2, _081A273C @ =0x0000047E
	adds r1, r7, r2
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_0819ddd8
	ldr r5, [sp, #0x24]
	movs r6, #0xed
	lsls r6, r6, #4
	adds r3, r5, r6
	ldr r0, _081A2740 @ =0x00000EF4
	adds r5, r5, r0
	ldr r1, _081A2744 @ =FUN_081a186c
	str r1, [sp, #0x1a8]
	ldr r2, _081A2748 @ =FUN_0819dfbc
	mov r8, r2
	ldr r6, _081A274C @ =FUN_0819cd38
	mov sb, r6
	ldr r0, _081A2750 @ =FUN_0819cccc
	mov sl, r0
	ldr r1, _081A2754 @ =FUN_0819ccfc
	mov ip, r1
	ldr r2, _081A2758 @ =FUN_080f62b0
	ldr r6, _081A275C @ =FUN_080f62ac
	str r6, [sp, #0x1a0]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x40]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x38]
	str r3, [r0]
	ldr r1, [sp, #0x3c]
	str r5, [r1]
	ldr r3, [sp, #0x1a8]
	ldr r5, [sp, #0xb8]
	str r3, [r5]
	mov r6, r8
	ldr r0, [sp, #0xc0]
	str r6, [r0]
	mov r1, sb
	ldr r3, [sp, #0xd4]
	str r1, [r3]
	mov r5, sl
	ldr r6, [sp, #0xf4]
	str r5, [r6]
	mov r0, ip
	ldr r1, [sp, #0xf8]
	str r0, [r1]
	ldr r3, [sp, #0x10c]
	str r4, [r3]
	ldr r5, [sp, #0x110]
	str r2, [r5]
	ldr r6, _081A2760 @ =FUN_0819d0f8
	ldr r0, [sp, #0x118]
	str r6, [r0]
	ldr r1, _081A2764 @ =FUN_0819d280
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	ldr r0, _081A2768 @ =FUN_080f44f4
	ldr r3, [sp, #0x120]
	str r0, [r3]
	ldr r0, _081A276C @ =FUN_080f410c
	ldr r5, [sp, #0x128]
	str r0, [r5]
	ldr r6, [sp, #0x114]
	str r4, [r6]
	ldr r0, [sp, #0xbc]
	str r4, [r0]
	ldr r1, [sp, #0x1a0]
	ldr r2, [sp, #0x14c]
	str r1, [r2]
	ldr r0, _081A2770 @ =FUN_080f0430
	ldr r3, [sp, #0x150]
	str r0, [r3]
	movs r6, #1
	ldr r5, [sp, #0x88]
	strb r6, [r5]
	ldr r0, _081A2774 @ =0x085AD470
	ldr r1, [sp, #0x154]
	str r0, [r1]
	ldr r0, _081A2778 @ =FUN_080e73c8
	ldr r2, [sp, #0x13c]
	str r0, [r2]
	ldr r3, [sp, #0x130]
	str r4, [r3]
	ldr r5, [sp, #0x140]
	str r4, [r5]
	ldr r6, [sp, #0x144]
	str r4, [r6]
	ldr r0, [sp, #0x148]
	str r4, [r0]
	ldr r1, [sp, #0x158]
	str r4, [r1]
	ldr r0, _081A277C @ =FUN_080f0320
	ldr r2, [sp, #0x15c]
	str r0, [r2]
	ldr r0, _081A2780 @ =FUN_080eff14
	ldr r3, [sp, #0x108]
	str r0, [r3]
	ldr r0, _081A2784 @ =FUN_080e72b0
	ldr r5, [sp, #0x134]
	str r0, [r5]
	ldr r6, [sp, #0x12c]
	str r4, [r6]
	ldr r0, _081A2788 @ =FUN_080f47c8
	ldr r1, [sp, #0x138]
	str r0, [r1]
	ldr r0, _081A278C @ =FUN_080f54e4
	ldr r2, [sp, #0x124]
	str r0, [r2]
	ldr r3, [sp, #0xfc]
	str r4, [r3]
	ldr r0, _081A2790 @ =FUN_080f6e64
	ldr r5, [sp, #0x160]
	str r0, [r5]
	ldr r0, _081A2794 @ =FUN_080f64f0
	ldr r6, [sp, #0xc8]
	str r0, [r6]
	ldr r0, _081A2798 @ =FUN_080f84d4
	ldr r1, [sp, #0x164]
	str r0, [r1]
	ldr r0, _081A279C @ =FUN_080f624c
	ldr r2, [sp, #0x104]
	str r0, [r2]
	ldr r0, _081A27A0 @ =FUN_080f56ec
	ldr r3, [sp, #0xe0]
	str r0, [r3]
	ldr r0, _081A27A4 @ =FUN_080f5b34
	ldr r5, [sp, #0xe4]
	str r0, [r5]
	ldr r0, _081A27A8 @ =FUN_080f5fac
	ldr r6, [sp, #0xf0]
	str r0, [r6]
	ldr r0, [sp, #0x100]
	str r4, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0x80]
	strb r0, [r1]
	movs r2, #0xbf
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _081A27AC @ =enemy_ax_0819e1ec
	str r0, [r1]
	ldr r3, _081A27B0 @ =0x000005FC
	adds r0, r7, r3
	str r4, [r0]
	ldr r5, _081A27B4 @ =0x000005AC
	adds r1, r7, r5
	ldr r0, _081A27B8 @ =FUN_0819e888
	str r0, [r1]
	movs r6, #0xb6
	lsls r6, r6, #3
	adds r0, r7, r6
	str r4, [r0]
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081A27BC @ =FUN_0819e828
	str r0, [r1]
	subs r2, #0x6c
	adds r1, r7, r2
	ldr r0, _081A27C0 @ =FUN_081a17c4
	str r0, [r1]
	movs r0, #0x60
	ldr r3, [sp, #0x184]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r4, [sp, #0x40]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _081A27C4 @ =0x02100408
	ldr r5, [sp, #0x44]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r6, [sp, #0x50]
	strh r0, [r6]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081A27D2
	movs r0, #0xce
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_081A272E:
	bl VM_GetPC
	cmp r0, #0
	beq _081A27C8
	bl Script_GetValue
	b _081A27CA
	.align 2, 0
_081A273C: .4byte 0x0000047E
_081A2740: .4byte 0x00000EF4
_081A2744: .4byte FUN_081a186c
_081A2748: .4byte FUN_0819dfbc
_081A274C: .4byte FUN_0819cd38
_081A2750: .4byte FUN_0819cccc
_081A2754: .4byte FUN_0819ccfc
_081A2758: .4byte FUN_080f62b0
_081A275C: .4byte FUN_080f62ac
_081A2760: .4byte FUN_0819d0f8
_081A2764: .4byte FUN_0819d280
_081A2768: .4byte FUN_080f44f4
_081A276C: .4byte FUN_080f410c
_081A2770: .4byte FUN_080f0430
_081A2774: .4byte 0x085AD470
_081A2778: .4byte FUN_080e73c8
_081A277C: .4byte FUN_080f0320
_081A2780: .4byte FUN_080eff14
_081A2784: .4byte FUN_080e72b0
_081A2788: .4byte FUN_080f47c8
_081A278C: .4byte FUN_080f54e4
_081A2790: .4byte FUN_080f6e64
_081A2794: .4byte FUN_080f64f0
_081A2798: .4byte FUN_080f84d4
_081A279C: .4byte FUN_080f624c
_081A27A0: .4byte FUN_080f56ec
_081A27A4: .4byte FUN_080f5b34
_081A27A8: .4byte FUN_080f5fac
_081A27AC: .4byte enemy_ax_0819e1ec
_081A27B0: .4byte 0x000005FC
_081A27B4: .4byte 0x000005AC
_081A27B8: .4byte FUN_0819e888
_081A27BC: .4byte FUN_0819e828
_081A27C0: .4byte FUN_081a17c4
_081A27C4: .4byte 0x02100408
_081A27C8:
	movs r0, #0
_081A27CA:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081A272E
_081A27D2:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x54]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x34]
	strh r0, [r3]
	cmp r2, #0
	beq _081A280A
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x40]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081A280A
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081A280A:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x184]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081A281C
	movs r0, #1
	b _081A281E
_081A281C:
	movs r0, #0
_081A281E:
	cmp r0, #0
	beq _081A2830
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x44]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081A2830:
	cmp r2, #1
	beq _081A2870
	movs r1, #0
	ldr r0, [sp, #0x178]
	strb r1, [r0]
	ldr r2, [sp, #0x17c]
	strb r1, [r2]
	ldr r3, [sp, #0x180]
	strb r1, [r3]
	ldr r4, _081A2880 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081A2884 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0xf8]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x84]
	strb r1, [r6]
	ldr r0, [sp, #0xb4]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081A2870:
	movs r1, #2
	ldr r3, [sp, #0x184]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081A2888
	movs r0, #1
	b _081A288A
	.align 2, 0
_081A2880: .4byte 0x00000484
_081A2884: .4byte 0x0000046C
_081A2888:
	movs r0, #0
_081A288A:
	cmp r0, #0
	beq _081A28A4
	ldr r0, _081A28A0 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x30]
	strh r0, [r5]
	b _081A28AE
	.align 2, 0
_081A28A0: .4byte 0x030046A0
_081A28A4:
	ldr r0, [sp, #0x168]
	bl FUN_08241574
	ldr r6, [sp, #0x30]
	strh r0, [r6]
_081A28AE:
	movs r1, #0x40
	ldr r2, [sp, #0x184]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A28BE
	movs r0, #1
	b _081A28C0
_081A28BE:
	movs r0, #0
_081A28C0:
	cmp r0, #0
	beq _081A28D0
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _081A28F4 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081A28D0:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _081A2902
	ldr r0, _081A28F8 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x30]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081A28FC
	movs r0, #1
	b _081A28FE
	.align 2, 0
_081A28F4: .4byte 0xFFFFFEFF
_081A28F8: .4byte 0x030046A0
_081A28FC:
	movs r0, #0
_081A28FE:
	cmp r0, #0
	bne _081A290A
_081A2902:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_081A290A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0xec]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081A29F2
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081A294C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081A2954
_081A294C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A2954:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081A2978
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081A2980
_081A2978:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081A2980:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081A29B8 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081A29FC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081A29BC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081A29B0
	ldrb r0, [r4, #5]
_081A29B0:
	subs r0, #1
	strh r0, [r4, #8]
	b _081A29CC
	.align 2, 0
_081A29B8: .4byte 0x0000FFFF
_081A29BC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081A29CC
	strh r1, [r4, #8]
_081A29CC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
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
	bne _081A29FC
	movs r0, #1
	strb r0, [r4, #7]
	b _081A29FC
_081A29F2:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_081A29FC:
	movs r0, #0
	ldr r3, [sp, #0x60]
	str r0, [r3]
	ldr r0, _081A2A14 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081A2A18
	movs r0, #1
	b _081A2A1A
	.align 2, 0
_081A2A14: .4byte 0x030047A4
_081A2A18:
	movs r0, #0
_081A2A1A:
	cmp r0, #0
	bne _081A2A5A
	ldr r4, [sp, #0x70]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081A2A42
	adds r0, r1, #0
	cmp r0, #7
	beq _081A2A42
	cmp r0, #6
	beq _081A2A42
	cmp r0, #0x15
	beq _081A2A42
	cmp r0, #0x14
	beq _081A2A42
	cmp r0, #0x17
	bne _081A2A5A
_081A2A42:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x184]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081A2A5A:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_0819dcfc
	adds r0, r7, #0
	bl FUN_081a1578
	adds r0, r7, #0
	bl FUN_081a17b4
	ldr r1, [r7, #0x44]
	movs r2, #0
	movs r0, #1
	strb r0, [r1, #7]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r2, [r0]
	adds r0, r7, #0
	bl FUN_0819ee70
	adds r0, r7, #0
	bl FUN_0819e788
	adds r0, r7, #0
	bl FUN_0819fd30
	ldr r1, [sp, #0x184]
	ldrh r0, [r1]
	ldr r2, [sp, #0xb0]
	strh r0, [r2]
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	ldr r4, [sp, #0xac]
	strh r0, [r4]
	ldr r5, [sp, #0x40]
	ldr r0, [r5]
	ldr r6, [sp, #0x8c]
	str r0, [r6]
	ldr r1, [sp, #0x44]
	ldr r0, [r1]
	ldr r2, [sp, #0x90]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0x94]
	strb r0, [r3]
	ldr r4, [sp, #0x178]
	ldrb r0, [r4]
	ldr r5, [sp, #0x98]
	strb r0, [r5]
	ldr r6, [sp, #0x17c]
	ldrb r0, [r6]
	ldr r1, [sp, #0x9c]
	strb r0, [r1]
	ldr r2, [sp, #0x180]
	ldrb r0, [r2]
	ldr r3, [sp, #0xa0]
	strb r0, [r3]
	ldr r4, [sp, #0xb4]
	ldr r0, [r4]
	ldr r5, [sp, #0xa4]
	str r0, [r5]
	ldr r6, [sp, #0x84]
	ldrb r0, [r6]
	ldr r1, [sp, #0xa8]
	strb r0, [r1]
	ldr r2, _081A2B1C @ =0x00000574
	adds r1, r7, r2
	ldr r3, [sp, #0x24]
	ldr r4, _081A2B20 @ =0x00000E48
	adds r0, r3, r4
	ldr r0, [r0]
	str r0, [r1]
	ldr r5, _081A2B24 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _081A2B28 @ =FUN_080f09e0
	str r0, [r1]
	ldr r6, _081A2B2C @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _081A2B30 @ =FUN_081a18a8
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081A2B34 @ =FUN_081a18c8
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081A2B38
	movs r0, #0
	b _081A2B3C
	.align 2, 0
_081A2B1C: .4byte 0x00000574
_081A2B20: .4byte 0x00000E48
_081A2B24: .4byte 0x0000057C
_081A2B28: .4byte FUN_080f09e0
_081A2B2C: .4byte 0x0000061C
_081A2B30: .4byte FUN_081a18a8
_081A2B34: .4byte FUN_081a18c8
_081A2B38:
	movs r0, #1
	rsbs r0, r0, #0
_081A2B3C:
	add sp, #0x1ac
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyAx_Create
EnemyAx_Create: @ 0x081A2B4C
	push {r4, r5, lr}
	ldr r5, _081A2B80 @ =0x00000F1C
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081A2B78
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyAx_Init
	cmp r0, #0
	bge _081A2B78
	adds r0, r4, #0
	bl FUN_081a18c8
	adds r0, r4, #0
	bl Free
_081A2B78:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A2B80: .4byte 0x00000F1C
