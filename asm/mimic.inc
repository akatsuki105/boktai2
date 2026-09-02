	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_081467bc
FUN_081467bc: @ 0x081467BC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r0, _081467D4 @ =0x0000046C
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081467D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081467DA
	.align 2, 0
_081467D4: .4byte 0x0000046C
_081467D8:
	movs r0, #0
_081467DA:
	cmp r0, #0
	beq _08146886
	ldr r0, _0814689C @ =0x00000482
	adds r1, r3, r0
	movs r6, #0
	movs r5, #0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _081468A0 @ =0x00000222
	adds r0, r3, r1
	strh r5, [r0]
	adds r1, #0x2c
	adds r0, r3, r1
	strh r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r4, r3, r0
	ldr r0, _081468A4 @ =0xFFFFFC7F
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r3, r1
	ldr r1, _081468A8 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08146846
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r1, _081468AC @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _081468B0 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r3, r1
	strb r6, [r0]
	adds r1, #2
	adds r0, r3, r1
	strh r5, [r0]
	subs r1, #0x1c
	adds r0, r3, r1
	strh r5, [r0]
_08146846:
	ldr r0, _081468B4 @ =0xFFFFFBFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r0, _081468B8 @ =0x00000542
	adds r1, r3, r0
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r3, r1
	str r5, [r0]
	ldr r1, _081468BC @ =0x000005A4
	adds r0, r3, r1
	ldr r2, [r0]
	ldr r0, _081468C0 @ =0x0000046D
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081468C4 @ =0x0000046B
	adds r0, r3, r1
	strb r6, [r0]
	adds r1, #0xe8
	adds r0, r3, r1
	strb r6, [r0]
	adds r1, #0x25
	adds r0, r3, r1
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r3, r1
	strh r5, [r0]
_08146886:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r1, [r0]
	adds r0, r3, #0
	bl _call_via_r1
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814689C: .4byte 0x00000482
_081468A0: .4byte 0x00000222
_081468A4: .4byte 0xFFFFFC7F
_081468A8: .4byte 0xF3FFFFFF
_081468AC: .4byte 0xFEFFFFFF
_081468B0: .4byte 0xFFFFFDFF
_081468B4: .4byte 0xFFFFFBFF
_081468B8: .4byte 0x00000542
_081468BC: .4byte 0x000005A4
_081468C0: .4byte 0x0000046D
_081468C4: .4byte 0x0000046B

	thumb_func_start FUN_081468c8
FUN_081468c8: @ 0x081468C8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081468E0 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081468E4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081468E6
	.align 2, 0
_081468E0: .4byte 0x0000046C
_081468E4:
	movs r0, #0
_081468E6:
	cmp r0, #0
	beq _08146918
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0814694C @ =0x0000046D
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _08146950 @ =0x0000046B
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
_08146918:
	ldr r5, _08146950 @ =0x0000046B
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814695C
	movs r2, #0xf
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08146954 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	subs r5, #1
	adds r0, r4, r5
	strb r2, [r0]
	ldr r2, _08146958 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _0814696A
	.align 2, 0
_0814694C: .4byte 0x0000046D
_08146950: .4byte 0x0000046B
_08146954: .4byte 0x00000469
_08146958: .4byte 0x00000484
_0814695C:
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r0, r4, r5
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0814696A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08146970
FUN_08146970: @ 0x08146970
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _08146988 @ =0x0000046C
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814698C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814698E
	.align 2, 0
_08146988: .4byte 0x0000046C
_0814698C:
	movs r0, #0
_0814698E:
	cmp r0, #0
	beq _081469DC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r5, #0
	str r5, [r0]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	movs r3, #1
	movs r7, #0xd2
	lsls r7, r7, #3
	adds r1, r1, r7
	ldrh r2, [r1]
	movs r4, #0
	adds r0, r3, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r2, _08146A10 @ =FUN_08147530
	movs r1, #0x24
	ldr r7, _08146A14 @ =0x0000046D
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _08146A18 @ =0x0000046B
	adds r0, r6, r3
	strb r4, [r0]
	adds r7, #0xe6
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
_081469DC:
	ldr r3, _08146A18 @ =0x0000046B
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08146A20
	movs r2, #2
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	movs r1, #0
	strb r1, [r0]
	subs r3, #2
	adds r0, r6, r3
	strb r1, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _08146A1C @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _08146A2E
	.align 2, 0
_08146A10: .4byte FUN_08147530
_08146A14: .4byte 0x0000046D
_08146A18: .4byte 0x0000046B
_08146A1C: .4byte 0x00000484
_08146A20:
	movs r7, #0xc1
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
_08146A2E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08146a34
FUN_08146a34: @ 0x08146A34
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08146A4C @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08146A50
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08146A52
	.align 2, 0
_08146A4C: .4byte 0x0000046C
_08146A50:
	movs r0, #0
_08146A52:
	cmp r0, #0
	beq _08146A80
	ldr r4, _08146AB4 @ =FUN_08147030
	movs r3, #0x22
	ldr r2, _08146AB8 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08146ABC @ =0x0000046B
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
_08146A80:
	ldr r2, _08146ABC @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08146AC4
	movs r2, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08146AC0 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08146AE2
	.align 2, 0
_08146AB4: .4byte FUN_08147030
_08146AB8: .4byte 0x0000046D
_08146ABC: .4byte 0x0000046B
_08146AC0: .4byte 0x00000484
_08146AC4:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08146AE2:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08146ae8
FUN_08146ae8: @ 0x08146AE8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08146B08 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08146B0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08146B0E
	.align 2, 0
_08146B08: .4byte 0x0000046C
_08146B0C:
	movs r0, #0
_08146B0E:
	cmp r0, #0
	beq _08146B3C
	ldr r4, _08146B88 @ =FUN_081473ac
	movs r3, #0x23
	ldr r6, _08146B8C @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08146B90 @ =0x0000046B
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
_08146B3C:
	ldr r6, _08146B94 @ =0x000004A4
	adds r0, r5, r6
	ldr r1, [r0]
	movs r4, #0
	str r4, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08146B66
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
_08146B66:
	ldr r3, _08146B90 @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08146B72
	b _08146CC8
_08146B72:
	movs r2, #1
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r1, r7, r6
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08146B98
	movs r0, #1
	b _08146B9A
	.align 2, 0
_08146B88: .4byte FUN_081473ac
_08146B8C: .4byte 0x0000046D
_08146B90: .4byte 0x0000046B
_08146B94: .4byte 0x000004A4
_08146B98:
	movs r0, #0
_08146B9A:
	adds r4, r0, #0
	cmp r4, #0
	beq _08146C1C
	ldr r1, _08146BE0 @ =0x0000068C
	adds r0, r7, r1
	ldr r2, _08146BE4 @ =0x00000256
	adds r1, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08146BF0
	movs r4, #1
	mvns r1, r4
	ldrh r0, [r6]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r6]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08146BE8 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r3, [r0]
	ldr r2, _08146BEC @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	b _08146CD6
	.align 2, 0
_08146BE0: .4byte 0x0000068C
_08146BE4: .4byte 0x00000256
_08146BE8: .4byte 0x00000469
_08146BEC: .4byte 0x0000046C
_08146BF0:
	movs r2, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08146C14 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r0, _08146C18 @ =0x0000046C
	adds r1, r5, r0
	b _08146CB4
	.align 2, 0
_08146C14: .4byte 0x00000469
_08146C18: .4byte 0x0000046C
_08146C1C:
	adds r0, r5, #0
	bl FUN_081489a0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08146C94
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08146C7C @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r6, _08146C80 @ =0x0000046A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r1, _08146C84 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08146C88 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08146C8C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r3, _08146C90 @ =0x0000024E
	adds r0, r5, r3
	strh r4, [r0]
	b _08146CD6
	.align 2, 0
_08146C7C: .4byte 0x00000469
_08146C80: .4byte 0x0000046A
_08146C84: .4byte 0x00000484
_08146C88: .4byte FUN_080e48d0
_08146C8C: .4byte 0x0000046B
_08146C90: .4byte 0x0000024E
_08146C94:
	movs r1, #0xf
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	ldr r3, _08146CBC @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08146CC0 @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08146CC4 @ =0x0000046C
	adds r1, r5, r2
_08146CB4:
	movs r0, #1
	strb r0, [r1]
	b _08146CD6
	.align 2, 0
_08146CBC: .4byte 0x00000469
_08146CC0: .4byte 0x00000484
_08146CC4: .4byte 0x0000046C
_08146CC8:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_08146CD6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08146ce0
FUN_08146ce0: @ 0x08146CE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _08146D08 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08146D0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08146D0E
	.align 2, 0
_08146D08: .4byte 0x0000046C
_08146D0C:
	movs r0, #0
_08146D0E:
	cmp r0, #0
	beq _08146D92
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r4, #0
	str r4, [r0]
	ldr r5, _08146E50 @ =0x00000482
	adds r1, r7, r5
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08146E54 @ =0x00000222
	adds r0, r7, r1
	strh r4, [r0]
	ldr r2, _08146E58 @ =0x0000024E
	adds r0, r7, r2
	strh r4, [r0]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r3, r7, r5
	ldr r0, _08146E5C @ =0xFFFFFC7F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _08146E60 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08146D82
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, _08146E64 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08146E68 @ =0xFFFFFDFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	adds r5, #0x9e
	adds r0, r7, r5
	strh r4, [r0]
	ldr r1, _08146E6C @ =0x00000202
	adds r0, r7, r1
	strh r4, [r0]
_08146D82:
	ldr r0, _08146E70 @ =0xFFFFFBFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r2, _08146E74 @ =0x00000542
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
_08146D92:
	ldr r3, _08146E78 @ =0x00000484
	adds r4, r7, r3
	ldr r0, [r4]
	cmp r0, #0x1e
	bgt _08146D9E
	b _08146F88
_08146D9E:
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r4, r4, r7
	mov sb, r4
	ldr r1, _08146E7C @ =0xFFFFFEFF
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r5, #0xe6
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	movs r4, #1
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r1, r1, r0
	ldrh r2, [r1]
	movs r6, #0
	movs r3, #0
	mov r8, r3
	adds r0, r4, #0
	orrs r0, r2
	strh r0, [r1]
	adds r5, #0x13
	adds r0, r7, r5
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08146E80 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r5, _08146E84 @ =0x0000046A
	adds r0, r7, r5
	strb r6, [r0]
	ldr r1, _08146E78 @ =0x00000484
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	adds r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r2, _08146E88 @ =FUN_080e6794
	movs r1, #0xe
	adds r5, #3
	adds r0, r7, r5
	strb r4, [r0]
	subs r3, #1
	adds r0, r7, r3
	strb r6, [r0]
	ldr r4, _08146E8C @ =0x00000553
	adds r0, r7, r4
	strb r1, [r0]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r0, r7, r5
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, r8
	strh r2, [r0]
	adds r3, #0x39
	adds r0, r7, r3
	ldr r6, [r0]
	adds r5, r7, #0
	adds r5, #8
	ldr r4, _08146E90 @ =0x00000684
	add r4, sl
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0823599c
	mov r8, sb
	cmp r0, #0
	bne _08146E94
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r0, r7, r4
	b _08146EB8
	.align 2, 0
_08146E50: .4byte 0x00000482
_08146E54: .4byte 0x00000222
_08146E58: .4byte 0x0000024E
_08146E5C: .4byte 0xFFFFFC7F
_08146E60: .4byte 0xF3FFFFFF
_08146E64: .4byte 0xFEFFFFFF
_08146E68: .4byte 0xFFFFFDFF
_08146E6C: .4byte 0x00000202
_08146E70: .4byte 0xFFFFFBFF
_08146E74: .4byte 0x00000542
_08146E78: .4byte 0x00000484
_08146E7C: .4byte 0xFFFFFEFF
_08146E80: .4byte 0x00000469
_08146E84: .4byte 0x0000046A
_08146E88: .4byte FUN_080e6794
_08146E8C: .4byte 0x00000553
_08146E90: .4byte 0x00000684
_08146E94:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08146EB2
	cmp r0, #2
	beq _08146EC0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _08146EC0
_08146EB2:
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
_08146EB8:
	ldr r1, _08146F14 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_08146EC0:
	ldr r1, _08146F18 @ =0x00000684
	add r1, sl
	adds r0, r7, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5e94
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _08146F24
	movs r1, #0xc1
	rsbs r1, r1, #0
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r4, #2
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r6, [r0]
	ldr r2, _08146F1C @ =0x00000551
	adds r0, r7, r2
	strb r6, [r0]
	ldr r3, _08146F20 @ =0x00000552
	adds r0, r7, r3
	strb r4, [r0]
	b _08146F6A
	.align 2, 0
_08146F14: .4byte 0xFFFFFDFF
_08146F18: .4byte 0x00000684
_08146F1C: .4byte 0x00000551
_08146F20: .4byte 0x00000552
_08146F24:
	movs r1, #0xc1
	rsbs r1, r1, #0
	mov r4, r8
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r5, _08146F74 @ =0x000005A4
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r4, _08146F78 @ =0x00000554
	adds r0, r7, r4
	str r1, [r0]
	str r3, [r2]
	subs r5, #0x54
	adds r0, r7, r5
	movs r1, #0
	strb r1, [r0]
	ldr r2, _08146F7C @ =0x00000551
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _08146F80 @ =0x00000552
	adds r0, r7, r3
	strb r1, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	add r2, sl
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08146F6A:
	ldr r4, _08146F84 @ =0x00000482
	adds r1, r7, r4
	movs r0, #1
	strh r0, [r1]
	b _08146F9C
	.align 2, 0
_08146F74: .4byte 0x000005A4
_08146F78: .4byte 0x00000554
_08146F7C: .4byte 0x00000551
_08146F80: .4byte 0x00000552
_08146F84: .4byte 0x00000482
_08146F88:
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
_08146F9C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08146fac
FUN_08146fac: @ 0x08146FAC
	ldr r1, _08146FB8 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08146FBC @ =0x085AD874
	str r1, [r0]
	bx lr
	.align 2, 0
_08146FB8: .4byte 0x00000634
_08146FBC: .4byte 0x085AD874

	thumb_func_start FUN_08146fc0
FUN_08146fc0: @ 0x08146FC0
	push {lr}
	bl FUN_0814830c
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08146fcc
FUN_08146fcc: @ 0x08146FCC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08146FE4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08146FE8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08146FEA
	.align 2, 0
_08146FE4: .4byte 0x0000046D
_08146FE8:
	movs r0, #0
_08146FEA:
	cmp r0, #0
	beq _0814700C
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080efb60
	movs r1, #0x97
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	ldr r0, _08147024 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0814700C:
	ldr r1, _08147028 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814701E
	ldr r0, _0814702C @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0814701E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08147024: .4byte 0x0000FFFB
_08147028: .4byte 0x0000046E
_0814702C: .4byte 0x0000046B

	thumb_func_start FUN_08147030
FUN_08147030: @ 0x08147030
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	ldr r2, _0814705C @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08147060
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08147062
	.align 2, 0
_0814705C: .4byte 0x0000046D
_08147060:
	movs r0, #0
_08147062:
	cmp r0, #0
	bne _08147068
	b _0814737E
_08147068:
	movs r1, #1
	ldr r3, [sp, #0x10]
	movs r4, #0xd2
	lsls r4, r4, #3
	adds r0, r3, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814707E
	movs r0, #1
	b _08147080
_0814707E:
	movs r0, #0
_08147080:
	cmp r0, #0
	bne _0814709E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_0814856c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081470B2
	adds r0, r6, #0
	bl FUN_081489f0
	b _08147396
_0814709E:
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	bl FUN_08148638
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081470B2
	b _08147396
_081470B2:
	ldr r3, _081470F4 @ =0x00000256
	adds r0, r6, r3
	ldrh r5, [r0]
	mov sb, sp
	ldr r7, _081470F8 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081470FC
	adds r0, #4
	b _08147106
	.align 2, 0
_081470F4: .4byte 0x00000256
_081470F8: .4byte 0x030046A4
_081470FC:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08147106:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r3, sb
	strh r0, [r3, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r3, #4]
	mov r2, sp
	adds r3, r6, #0
	adds r3, #8
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r6, #8]
	subs r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldrb r0, [r6, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	movs r2, #0
	mov sl, r3
	adds r1, r4, #0
	cmp r0, #1
	beq _081471E6
	cmp r0, #1
	bgt _0814715A
	cmp r0, #0
	beq _08147164
	b _08147268
_0814715A:
	cmp r0, #2
	beq _08147164
	cmp r0, #3
	beq _081471E6
	b _08147268
_08147164:
	mov r0, sp
	movs r3, #4
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _08147170
	rsbs r0, r0, #0
_08147170:
	cmp r0, #0x40
	ble _08147268
	ldr r4, _081471B8 @ =0x00000256
	adds r0, r6, r4
	ldrh r5, [r0]
	mov sb, sp
	ldr r7, _081471BC @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081471C0
	adds r0, #4
	b _081471CA
	.align 2, 0
_081471B8: .4byte 0x00000256
_081471BC: .4byte 0x030046A4
_081471C0:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081471CA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldrh r1, [r6, #8]
	mov r0, sp
	strh r1, [r0]
	b _0814726C
_081471E6:
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _081471F2
	rsbs r0, r0, #0
_081471F2:
	cmp r0, #0x40
	ble _08147268
	ldr r4, _08147238 @ =0x00000256
	adds r0, r6, r4
	ldrh r5, [r0]
	mov sb, sp
	ldr r7, _0814723C @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08147240
	adds r0, #4
	b _0814724A
	.align 2, 0
_08147238: .4byte 0x00000256
_0814723C: .4byte 0x030046A4
_08147240:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814724A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldrh r1, [r6, #0xc]
	mov r0, sp
	strh r1, [r0, #4]
	movs r2, #1
	ldrh r1, [r6, #8]
_08147268:
	cmp r2, #0
	beq _0814728E
_0814726C:
	add r2, sp, #8
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	mov r4, sl
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r5, #4
	b _081472D8
_0814728E:
	add r3, sp, #8
	ldr r2, _0814730C @ =0x000004A4
	adds r0, r6, r2
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #0x1c
	ldrh r0, [r0, #0x1c]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	mov r4, sl
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	ldr r2, _08147310 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08147314 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08147318 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	ldr r4, [sp, #0x10]
	ldr r1, _0814731C @ =0x00000692
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #2
	movs r1, #3
	ands r2, r1
	adds r5, r0, r2
	adds r2, r3, #0
_081472D8:
	movs r3, #0
	ldrsh r0, [r2, r3]
	add r1, sp, #8
	movs r4, #4
	ldrsh r1, [r1, r4]
	bl FUN_0823785c
	strb r0, [r6, #5]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrb r4, [r6, #5]
	ldr r2, _08147320 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08147324
	asrs r1, r0, #0xc
	b _0814732A
	.align 2, 0
_0814730C: .4byte 0x000004A4
_08147310: .4byte 0x030046B8
_08147314: .4byte 0x000003FF
_08147318: .4byte 0x0203B400
_0814731C: .4byte 0x00000692
_08147320: .4byte 0x085B0A08
_08147324:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814732A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08147344 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08147348
	asrs r0, r0, #0xc
	b _0814734E
	.align 2, 0
_08147344: .4byte 0x085B0A08
_08147348:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814734E:
	strh r0, [r3, #4]
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0x18
	strh r0, [r1]
	ldrb r0, [r6, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r6, #0
	movs r1, #0xe
	bl FUN_080efb60
	movs r0, #0xd9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r4, #0x9a
	lsls r4, r4, #2
	adds r0, r6, r4
	bl FUN_08013698
	b _08147396
_0814737E:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08147396
	ldr r3, _081473A8 @ =0x0000046B
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
_08147396:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081473A8: .4byte 0x0000046B

	thumb_func_start FUN_081473ac
FUN_081473ac: @ 0x081473AC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081473C4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081473C8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081473CA
	.align 2, 0
_081473C4: .4byte 0x0000046D
_081473C8:
	movs r0, #0
_081473CA:
	cmp r0, #0
	beq _08147406
	adds r0, r4, #0
	bl FUN_081489a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081473EC
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080efb60
	b _081473FC
_081473EC:
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080efb60
_081473FC:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080136b4
_08147406:
	ldr r1, _08147420 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08147418
	ldr r0, _08147424 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08147418:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08147420: .4byte 0x0000046E
_08147424: .4byte 0x0000046B

	thumb_func_start FUN_08147428
FUN_08147428: @ 0x08147428
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08147440 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08147444
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08147446
	.align 2, 0
_08147440: .4byte 0x0000046D
_08147444:
	movs r0, #0
_08147446:
	cmp r0, #0
	beq _08147466
	ldrb r0, [r5, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080efb60
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_08147466:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081474CE
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _081474D4 @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	movs r4, #0
	strh r0, [r2]
	ldr r3, _081474D8 @ =0x000005A4
	adds r0, r5, r3
	ldr r2, [r0]
	ldr r6, _081474DC @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0x25
	adds r0, r5, r6
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _081474E0 @ =0x00000469
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081474E4 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r5, r2
	strb r3, [r0]
_081474CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081474D4: .4byte 0x0000FFFB
_081474D8: .4byte 0x000005A4
_081474DC: .4byte 0x0000046D
_081474E0: .4byte 0x00000469
_081474E4: .4byte 0x00000484

	thumb_func_start FUN_081474e8
FUN_081474e8: @ 0x081474E8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08147500 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08147504
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08147506
	.align 2, 0
_08147500: .4byte 0x0000046D
_08147504:
	movs r0, #0
_08147506:
	cmp r0, #0
	beq _08147528
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080efb60
	movs r0, #0x97
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_08147528:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08147530
FUN_08147530: @ 0x08147530
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08147548 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814754C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814754E
	.align 2, 0
_08147548: .4byte 0x0000046D
_0814754C:
	movs r0, #0
_0814754E:
	cmp r0, #0
	beq _08147570
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080efb60
	movs r1, #0x97
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_08147570:
	cmp r5, #0xa0
	bne _0814758C
	ldr r1, _08147588 @ =0x000001DF
	adds r0, r4, r1
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	b _081475A8
	.align 2, 0
_08147588: .4byte 0x000001DF
_0814758C:
	cmp r5, #0xa0
	ble _081475A8
	ldr r1, _081475B0 @ =0x00000454
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_080da8a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081475A8
	ldr r0, _081475B4 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081475A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081475B0: .4byte 0x00000454
_081475B4: .4byte 0x0000046B

	thumb_func_start FUN_081475b8
FUN_081475b8: @ 0x081475B8
	push {r4, r5, r6, lr}
	sub sp, #0x40
	adds r4, r0, #0
	ldr r0, _081475D0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081475D4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081475D6
	.align 2, 0
_081475D0: .4byte 0x0000046D
_081475D4:
	movs r0, #0
_081475D6:
	cmp r0, #0
	beq _081475EA
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0xa
	bl FUN_080efb60
_081475EA:
	ldr r0, [r4, #0x44]
	adds r0, #0x48
	movs r1, #0
	strh r1, [r0, #0xe]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0x13
	bhi _08147600
	b _081477D2
_08147600:
	movs r3, #1
	ands r3, r0
	cmp r3, #0
	bne _08147646
	ldr r1, _08147750 @ =0xFFFF0000
	add r2, sp, #0x30
	ldr r0, [r2, #4]
	ands r0, r1
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2, #4]
	movs r0, #0x80
	lsls r0, r0, #0xf
	orrs r0, r1
	str r0, [sp, #0x30]
	adds r0, r4, #0
	adds r0, #8
	str r3, [sp]
	str r3, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	movs r3, #0
	bl FUN_080ddcc8
	ldrh r1, [r5]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _08147646
	movs r0, #0xb7
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08147646:
	ldr r0, [r4, #0x44]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08147660
	b _0814778C
_08147660:
	ldr r3, _08147754 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r6, _08147758 @ =0x0000046D
	adds r0, r4, r6
	movs r1, #0
	movs r5, #1
	strb r5, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	movs r2, #0
	strh r1, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r2, [r0]
	ldr r2, _0814775C @ =0x0000046A
	adds r0, r4, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r4, r6
	str r1, [r0]
	ldr r1, _08147760 @ =0x0000046C
	adds r0, r4, r1
	strb r5, [r0]
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080136b4
	adds r0, r4, #0
	bl FUN_080e6658
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r2, r4, r6
	ldrh r0, [r2]
	cmp r0, #0
	beq _08147726
	movs r1, #8
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x10]
	movs r6, #0xa
	ldrsh r0, [r4, r6]
	str r0, [sp, #0x14]
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x18]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r4, r6
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	adds r6, #8
	adds r0, r4, r6
	ldr r0, [r0]
	str r0, [sp, #0x24]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrh r0, [r4]
	str r0, [sp, #0x2c]
	ldr r1, _08147750 @ =0xFFFF0000
	ldr r0, [sp, #0x38]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x38]
	add r1, sp, #0x38
	add r6, sp, #0x10
	str r6, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_08147726:
	ldr r1, _08147764 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r4, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0814776C
	ldr r0, _08147768 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe2
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r1, r5, #0
	lsls r1, r3
	b _0814777E
	.align 2, 0
_08147750: .4byte 0xFFFF0000
_08147754: .4byte FUN_080e48d0
_08147758: .4byte 0x0000046D
_0814775C: .4byte 0x0000046A
_08147760: .4byte 0x0000046C
_08147764: .4byte 0x000001DF
_08147768: .4byte 0x030046A0
_0814776C:
	ldr r0, _08147788 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r5, #0
	lsls r1, r0
_0814777E:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _081477D2
	.align 2, 0
_08147788: .4byte 0x030046A0
_0814778C:
	movs r1, #1
	ldr r2, _081477A4 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081477A8
	ldr r0, [r4, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081477B2
	b _081477B6
	.align 2, 0
_081477A4: .4byte 0x0000025D
_081477A8:
	ldr r0, [r4, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _081477B6
_081477B2:
	movs r0, #1
	b _081477B8
_081477B6:
	movs r0, #0
_081477B8:
	cmp r0, #0
	beq _081477C8
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r4, r6
	bl FUN_080136b4
	b _081477D2
_081477C8:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013698
_081477D2:
	add sp, #0x40
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081477dc
FUN_081477dc: @ 0x081477DC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081477F4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081477F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081477FA
	.align 2, 0
_081477F4: .4byte 0x0000046D
_081477F8:
	movs r0, #0
_081477FA:
	cmp r0, #0
	beq _0814781C
	ldrb r0, [r5, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080efb60
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0814781C:
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r5, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0814783C
	asrs r0, r0, #2
	b _08147842
_0814783C:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08147842:
	adds r3, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r6, #8
	adds r1, r5, r6
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _08147860
	asrs r0, r0, #2
	b _08147866
_08147860:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08147866:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _08147870
	movs r3, #0xc8
	b _0814787A
_08147870:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0814787A
	adds r3, r0, #0
_0814787A:
	cmp r2, #0xc8
	ble _08147882
	movs r2, #0xc8
	b _0814788C
_08147882:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0814788C
	adds r2, r0, #0
_0814788C:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _081478B0
	cmp r2, #0
	bne _081478B0
	movs r0, #1
	b _081478B2
_081478B0:
	movs r0, #0
_081478B2:
	cmp r0, #0
	bne _081478B8
	b _08147A16
_081478B8:
	ldr r1, _081478E8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081478C4
	b _08147A16
_081478C4:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r0, _081478EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	beq _081478F0
	movs r0, #1
	b _081478F2
	.align 2, 0
_081478E8: .4byte 0x0000046E
_081478EC: .4byte 0x030047A4
_081478F0:
	movs r0, #0
_081478F2:
	cmp r0, #0
	beq _0814790A
	adds r0, r5, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08147918
	adds r0, r5, #0
	bl FUN_081489f0
	b _08147A26
_0814790A:
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _081479DC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_08147918:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081479F4
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	adds r3, r1, #0
	adds r3, #8
	ldrh r1, [r1, #8]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	movs r7, #0
	mov r0, sp
	strh r1, [r0]
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
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	strb r0, [r5, #5]
	ldr r3, _081479E0 @ =0x000001DF
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _08147978
	movs r0, #4
	ldr r1, _081479E4 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08147978:
	movs r0, #0x80
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _081479E8 @ =0x0000024E
	adds r0, r5, r3
	strh r1, [r0]
	movs r6, #0xe6
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r2, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r2, r2, r0
	movs r3, #1
	mvns r0, r3
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x13
	subs r6, #0x54
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r7, [r0]
	ldr r6, _081479EC @ =0x00000469
	adds r0, r5, r6
	strb r7, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r1, r5, r6
	movs r0, #0
	str r0, [r1]
	ldr r1, _081479F0 @ =0x0000046C
	adds r0, r5, r1
	strb r3, [r0]
	b _08147A16
	.align 2, 0
_081479DC: .4byte 0x03002BE0
_081479E0: .4byte 0x000001DF
_081479E4: .4byte 0x00000222
_081479E8: .4byte 0x0000024E
_081479EC: .4byte 0x00000469
_081479F0: .4byte 0x0000046C
_081479F4:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08147A30 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _08147A34 @ =0x0000046A
	adds r0, r5, r6
	strb r1, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_08147A16:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r5, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08147A26:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08147A30: .4byte 0x00000469
_08147A34: .4byte 0x0000046A

	thumb_func_start FUN_08147a38
FUN_08147a38: @ 0x08147A38
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _08147A64 @ =0x0000068E
	adds r0, r3, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #2
	adds r0, r3, r2
	strh r1, [r0]
	ldr r0, _08147A68 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08147A6C
	movs r0, #1
	b _08147A6E
	.align 2, 0
_08147A64: .4byte 0x0000068E
_08147A68: .4byte 0x030047A4
_08147A6C:
	movs r0, #0
_08147A6E:
	cmp r0, #0
	beq _08147AC8
	ldr r0, _08147AA8 @ =0x00000684
	adds r2, r3, r0
	ldr r0, [r4, #8]
	ldr r1, [r4, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08147AA2
	cmp r1, #0
	blt _08147AA2
	ldr r0, _08147AAC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08147AA2
	ldr r0, _08147AB0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08147AB4
_08147AA2:
	movs r1, #0
	b _08147AC2
	.align 2, 0
_08147AA8: .4byte 0x00000684
_08147AAC: .4byte 0x030046A8
_08147AB0: .4byte 0x030046AC
_08147AB4:
	ldr r0, _08147B0C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08147AC2:
	ldr r2, _08147B10 @ =0x0000068C
	adds r0, r3, r2
	strh r1, [r0]
_08147AC8:
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080efb60
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
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
	beq _08147B14
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08147B1C
	.align 2, 0
_08147B0C: .4byte 0x030046A4
_08147B10: .4byte 0x0000068C
_08147B14:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08147B1C:
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
	beq _08147B40
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08147B48
_08147B40:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08147B48:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08147B80 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08147BB8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08147B84
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08147B78
	ldrb r0, [r4, #5]
_08147B78:
	subs r0, #1
	strh r0, [r4, #8]
	b _08147B94
	.align 2, 0
_08147B80: .4byte 0x0000FFFF
_08147B84:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08147B94
	strh r1, [r4, #8]
_08147B94:
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
	bne _08147BB8
	movs r0, #1
	strb r0, [r4, #7]
_08147BB8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08147bc0
FUN_08147bc0: @ 0x08147BC0
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08147BF4
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08147BF4
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _08147BFC @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08147BF4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08147BFC: .4byte 0xFEFFFFFF

	thumb_func_start FUN_08147c00
FUN_08147c00: @ 0x08147C00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08147C22
	b _081482A8
_08147C22:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08147C4C
	ldr r3, _08147C48 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08147C3A
	b _081482A8
_08147C3A:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081482A8
	.align 2, 0
_08147C48: .4byte 0x0000048C
_08147C4C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08147C5C
	b _081482A8
_08147C5C:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08147C6C
	b _08147F78
_08147C6C:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _08147C7E
	b _081482A8
_08147C7E:
	ldr r2, _08147D10 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08147C92
	b _081482A8
_08147C92:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08147CA0
	b _081482A8
_08147CA0:
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
	bne _08147CB8
	b _08147E00
_08147CB8:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _08147D20
	ands r3, r1
	cmp r3, #0
	beq _08147D20
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08147CDE
	rsbs r1, r1, #0
_08147CDE:
	cmp r1, #0x20
	bgt _08147D20
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _08147D14 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _08147D18 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08147D1C @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081482A8
	.align 2, 0
_08147D10: .4byte 0x0000A007
_08147D14: .4byte 0x000004BE
_08147D18: .4byte 0x0000048C
_08147D1C: .4byte 0x0000044E
_08147D20:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _08147D48 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08147D50
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08147D4C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08147DBE
	.align 2, 0
_08147D48: .4byte 0x0000048A
_08147D4C: .4byte 0x03002BE0
_08147D50:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08147D6C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08147D68 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08147DBE
	.align 2, 0
_08147D68: .4byte 0x03002BE0
_08147D6C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08147D88
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08147D84 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08147DBE
	.align 2, 0
_08147D84: .4byte 0x03002BE0
_08147D88:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08147DA4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08147DA0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08147DBE
	.align 2, 0
_08147DA0: .4byte 0x03002BE0
_08147DA4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08147DB6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08147DBE
_08147DB6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08147DC0
_08147DBE:
	movs r3, #1
_08147DC0:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _08147DF4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _08147DE2
	b _08147F38
_08147DE2:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08147DF8
	movs r0, #1
	b _08147DFA
	.align 2, 0
_08147DF4: .4byte 0x0000049C
_08147DF8:
	movs r0, #0
_08147DFA:
	cmp r0, #0
	bne _08147EDE
	b _08147EF4
_08147E00:
	strh r2, [r7, #0x3e]
	ldr r1, _08147E28 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08147E30
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08147E2C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08147E9E
	.align 2, 0
_08147E28: .4byte 0x0000048A
_08147E2C: .4byte 0x03002BE0
_08147E30:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08147E4C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08147E48 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08147E9E
	.align 2, 0
_08147E48: .4byte 0x03002BE0
_08147E4C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08147E68
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _08147E64 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08147E9E
	.align 2, 0
_08147E64: .4byte 0x03002BE0
_08147E68:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08147E84
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08147E80 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08147E9E
	.align 2, 0
_08147E80: .4byte 0x03002BE0
_08147E84:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08147E96
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08147E9E
_08147E96:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08147EA0
_08147E9E:
	movs r3, #1
_08147EA0:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _08147ED4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _08147F38
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08147ED8
	movs r0, #1
	b _08147EDA
	.align 2, 0
_08147ED4: .4byte 0x0000049C
_08147ED8:
	movs r0, #0
_08147EDA:
	cmp r0, #0
	beq _08147EF4
_08147EDE:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08147EF0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08147F00
	.align 2, 0
_08147EF0: .4byte 0x03002BE0
_08147EF4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08147F38
_08147F00:
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
_08147F38:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08147F64
	ldr r5, _08147F70 @ =0x0000024E
	adds r2, r6, r5
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
	bls _08147F64
	strh r1, [r2]
_08147F64:
	ldr r5, _08147F74 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081482A8
	.align 2, 0
_08147F70: .4byte 0x0000024E
_08147F74: .4byte 0x0000048C
_08147F78:
	ldr r0, _08147F8C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08147F90
	movs r0, #1
	b _08147F92
	.align 2, 0
_08147F8C: .4byte 0x030047A4
_08147F90:
	movs r0, #0
_08147F92:
	cmp r0, #0
	beq _08147FA0
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _08147FA8
_08147FA0:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_08147FA8:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08147FE0 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08147FE4 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08147FD6
	cmp r2, #0x17
	bne _08147FE8
_08147FD6:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0814800A
	.align 2, 0
_08147FE0: .4byte 0x0000048C
_08147FE4: .4byte 0x000001DF
_08147FE8:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08147FD6
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _08148038 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0814800A
	movs r1, #0
_0814800A:
	adds r0, r7, #0
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
	beq _08148046
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _0814803C
	asrs r0, r0, #1
	b _08148042
	.align 2, 0
_08148038: .4byte 0x00000187
_0814803C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08148042:
	mov r2, sb
	strh r0, [r2]
_08148046:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08148064
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08148060 @ =0x000001DD
	adds r1, r6, r4
	b _081480D8
	.align 2, 0
_08148060: .4byte 0x000001DD
_08148064:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
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
	bne _081480C4
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081480C4
	ldr r2, _081480B4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081480B8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081480BC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081480C0 @ =0x000001DD
	adds r1, r6, r4
	b _081480D8
	.align 2, 0
_081480B4: .4byte 0x030046B8
_081480B8: .4byte 0x000003FF
_081480BC: .4byte 0x0203B400
_081480C0: .4byte 0x000001DD
_081480C4:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _081480F8 @ =0x000001DD
	adds r1, r6, r3
_081480D8:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08148100
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081480FC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0814816E
	.align 2, 0
_081480F8: .4byte 0x000001DD
_081480FC: .4byte 0x03002BE0
_08148100:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0814811C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08148118 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0814816E
	.align 2, 0
_08148118: .4byte 0x03002BE0
_0814811C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08148138
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08148134 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0814816E
	.align 2, 0
_08148134: .4byte 0x03002BE0
_08148138:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08148154
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08148150 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0814816E
	.align 2, 0
_08148150: .4byte 0x03002BE0
_08148154:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08148166
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0814816E
_08148166:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08148170
_0814816E:
	movs r3, #1
_08148170:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _081481A4 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0814820C
	movs r1, #2
	ldr r2, _081481A8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081481AC
	movs r0, #1
	b _081481AE
	.align 2, 0
_081481A4: .4byte 0x0000049C
_081481A8: .4byte 0x00000474
_081481AC:
	movs r0, #0
_081481AE:
	cmp r0, #0
	beq _081481C8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081481C4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081481D4
	.align 2, 0
_081481C4: .4byte 0x03002BE0
_081481C8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0814820C
_081481D4:
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
_0814820C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08148240
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08148240
	ldr r0, _08148258 @ =0x0000024E
	adds r2, r6, r0
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
	bls _08148240
	strh r1, [r2]
_08148240:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0814825C @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _08148260 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08148264
	movs r0, #1
	b _08148266
	.align 2, 0
_08148258: .4byte 0x0000024E
_0814825C: .4byte 0x030046A0
_08148260: .4byte 0x00000934
_08148264:
	movs r0, #0
_08148266:
	ldr r1, _081482B8 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0814827E
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_0814827E:
	adds r0, r6, #0
	bl FUN_080e64e4
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081482A8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081482B8: .4byte 0x0000048A

	thumb_func_start FUN_081482bc
FUN_081482bc: @ 0x081482BC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0814830c
FUN_0814830c: @ 0x0814830C
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r4, r3, r1
	ldrh r1, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081483F2
	ldr r2, _081483F8 @ =0x0000024E
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _081483F2
	movs r5, #0x38
	ands r5, r1
	cmp r5, #0
	bne _081483F2
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r3, r1
	str r5, [r0]
	ldr r2, _081483FC @ =0x00000482
	adds r1, r3, r2
	movs r6, #0
	movs r7, #1
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08148400 @ =0x00000222
	adds r0, r3, r1
	strh r5, [r0]
	ldr r2, _081483F8 @ =0x0000024E
	adds r0, r3, r2
	strh r5, [r0]
	ldr r0, _08148404 @ =0xFFFFFC7F
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r1, _08148408 @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _0814839C
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r3, r1
	ldr r1, _0814840C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08148410 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r3, r2
	strb r6, [r0]
	ldr r1, _08148414 @ =0x0000021E
	adds r0, r3, r1
	strh r5, [r0]
	subs r2, #0x1a
	adds r0, r3, r2
	strh r5, [r0]
_0814839C:
	ldr r0, _08148418 @ =0xFFFFFBFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	ldr r4, _0814841C @ =0x00000542
	adds r1, r3, r4
	movs r0, #0xff
	strb r0, [r1]
	ldr r2, _08148420 @ =FUN_080e48d0
	movs r1, #0x10
	subs r4, #0xd5
	adds r0, r3, r4
	strb r7, [r0]
	subs r4, #2
	adds r0, r3, r4
	strb r6, [r0]
	adds r4, #0xe8
	adds r0, r3, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r3, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r3, r2
	strh r5, [r0]
	movs r1, #0x11
	subs r4, #0xeb
	adds r0, r3, r4
	strb r6, [r0]
	ldr r2, _08148424 @ =0x00000469
	adds r0, r3, r2
	strb r6, [r0]
	adds r4, #2
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _08148428 @ =0x00000484
	adds r0, r3, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r3, r2
	strb r7, [r0]
_081483F2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081483F8: .4byte 0x0000024E
_081483FC: .4byte 0x00000482
_08148400: .4byte 0x00000222
_08148404: .4byte 0xFFFFFC7F
_08148408: .4byte 0xF3FFFFFF
_0814840C: .4byte 0xFEFFFFFF
_08148410: .4byte 0xFFFFFDFF
_08148414: .4byte 0x0000021E
_08148418: .4byte 0xFFFFFBFF
_0814841C: .4byte 0x00000542
_08148420: .4byte FUN_080e48d0
_08148424: .4byte 0x00000469
_08148428: .4byte 0x00000484

	thumb_func_start FUN_0814842c
FUN_0814842c: @ 0x0814842C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r2, _081484A8 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _081484AC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #8]
	add r0, sp, #8
	mov r8, r0
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0xc]
	movs r0, #0xa0
	lsls r0, r0, #0xe
	str r0, [sp, #0x10]
	add r4, sp, #0x10
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r3, _081484B0 @ =FUN_08147bc0
	movs r5, #0
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #8
	adds r2, r4, #0
	bl FUN_080e3984
	movs r1, #0x50
	add r0, sp, #8
	strh r1, [r0]
	movs r0, #0x78
	mov r2, r8
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	strh r5, [r4]
	strh r0, [r4, #2]
	strh r5, [r4, #4]
	ldr r3, _081484B4 @ =FUN_08147c00
	str r6, [sp]
	adds r0, r6, #0
	add r1, sp, #8
	adds r2, r4, #0
	bl FUN_080e3834
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081484A8: .4byte 0xFFFF0000
_081484AC: .4byte 0x0000FFFF
_081484B0: .4byte FUN_08147bc0
_081484B4: .4byte FUN_08147c00

	thumb_func_start FUN_081484b8
FUN_081484b8: @ 0x081484B8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov ip, r0
	movs r5, #0
	movs r0, #8
	mov r8, r0
	mov r3, sp
	mov r6, ip
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	add r1, ip
	mov sb, r1
	ldr r4, _0814854C @ =0x03002BE0
_081484DA:
	lsls r2, r5, #2
	ldr r1, [r4]
	cmp r1, #0
	beq _08148554
	ldr r0, _08148550 @ =0x03002BC0
	adds r0, r2, r0
	ldr r0, [r0]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	bne _08148554
	adds r2, r1, #0
	adds r2, #0x2c
	ldrh r0, [r1, #0x2c]
	mov r7, ip
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	movs r0, #0x90
	lsls r0, r0, #6
	cmp r1, r0
	bgt _08148554
	ldr r2, [r4]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08148554
	adds r0, r2, #0
	adds r0, #0x24
	mov r2, sb
	str r0, [r2]
	movs r0, #1
	b _0814855E
	.align 2, 0
_0814854C: .4byte 0x03002BE0
_08148550: .4byte 0x03002BC0
_08148554:
	adds r4, #4
	adds r5, #1
	cmp r5, #3
	ble _081484DA
	movs r0, #0
_0814855E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0814856c
FUN_0814856c: @ 0x0814856C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _08148584 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08148588
	movs r0, #1
	b _0814858A
	.align 2, 0
_08148584: .4byte 0x030047A4
_08148588:
	movs r0, #0
_0814858A:
	cmp r0, #0
	beq _081485C0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08148630
	ldrb r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, #3
	bhi _081485A6
	adds r3, r0, #0
_081485A6:
	cmp r3, #0
	blt _08148630
	movs r2, #8
	ldr r1, _081485BC @ =0x03002BC0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _081485CC
	b _08148630
	.align 2, 0
_081485BC: .4byte 0x03002BC0
_081485C0:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08148630
_081485CC:
	ldr r1, _08148610 @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	beq _08148614
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08148614
	cmp r0, #2
	beq _0814860C
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814860C:
	movs r0, #1
	b _08148624
	.align 2, 0
_08148610: .4byte 0x000004A4
_08148614:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _0814862C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08148624:
	cmp r0, #0
	beq _08148630
	movs r0, #1
	b _08148632
	.align 2, 0
_0814862C: .4byte 0xFFFFFDFF
_08148630:
	movs r0, #0
_08148632:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08148638
FUN_08148638: @ 0x08148638
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r1, _08148660 @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	ldr r3, _08148664 @ =0x00000684
	adds r5, r4, r3
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08148668
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	b _0814868E
	.align 2, 0
_08148660: .4byte 0x000004A4
_08148664: .4byte 0x00000684
_08148668:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08148688
	cmp r0, #2
	beq _08148684
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08148684:
	movs r0, #1
	b _08148698
_08148688:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
_0814868E:
	ldr r1, _081486A4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08148698:
	adds r2, r0, #0
	cmp r2, #0
	beq _081486A8
	movs r0, #1
	b _081486CE
	.align 2, 0
_081486A4: .4byte 0xFFFFFDFF
_081486A8:
	movs r1, #0x11
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081486D4 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_081486CE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081486D4: .4byte 0x00000484

	thumb_func_start FUN_081486d8
FUN_081486d8: @ 0x081486D8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r4, #5]
	ldr r2, _0814874C @ =0x000001DF
	adds r0, r4, r2
	ldrb r3, [r0]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5718
	adds r0, r4, #0
	bl FUN_080e6750
	ldr r1, _0814874C @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08148712
	movs r0, #4
	adds r1, #0x43
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08148712:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0814874C: .4byte 0x000001DF

	thumb_func_start FUN_08148750
FUN_08148750: @ 0x08148750
	push {lr}
	adds r1, r0, #0
	adds r1, #0x10
	movs r2, #0xff
	ands r1, r2
	asrs r1, r1, #6
	cmp r1, #1
	beq _08148778
	cmp r1, #1
	bgt _0814876A
	cmp r1, #0
	beq _08148774
	b _0814877A
_0814876A:
	cmp r1, #2
	beq _08148774
	cmp r1, #3
	beq _08148778
	b _0814877A
_08148774:
	movs r0, #0
	b _0814877A
_08148778:
	movs r0, #1
_0814877A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08148780
FUN_08148780: @ 0x08148780
	bx lr
	.align 2, 0

	thumb_func_start FUN_08148784
FUN_08148784: @ 0x08148784
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r3, r4, r0
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0814879A
	b _081488AE
_0814879A:
	movs r1, #0xea
	lsls r1, r1, #1
	adds r5, r4, r1
	ldr r0, [r5]
	cmp r0, #0
	ble _081487CA
	movs r0, #0x80
	subs r1, #0x52
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldrh r0, [r5]
	bl FUN_080f8d60
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r4, r2
	b _08148844
_081487CA:
	ldr r0, _081487DC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081487E0
	movs r0, #1
	b _081487E2
	.align 2, 0
_081487DC: .4byte 0x030047A4
_081487E0:
	movs r0, #0
_081487E2:
	cmp r0, #0
	beq _08148800
	adds r0, r4, #0
	bl FUN_081484b8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08148828
	adds r0, r4, #0
	bl FUN_081489a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08148850
	b _081488AE
_08148800:
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	ldr r0, _0814884C @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08148814
	rsbs r1, r1, #0
_08148814:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _081488AE
	adds r0, r4, #0
	bl FUN_081484b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08148850
_08148828:
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
_08148844:
	str r0, [r1]
	movs r0, #1
	b _081488B0
	.align 2, 0
_0814884C: .4byte 0x03002BE0
_08148850:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _081488AE
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r2, #8
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081488AE
	ldr r1, _081488B8 @ =0x000004A4
	adds r0, r4, r1
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #8
	adds r2, r3, #0
	adds r2, #8
	bl FUN_0823599c
	cmp r0, #0
	beq _081488AE
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081488AE
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r3, r4, r1
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081488AE:
	movs r0, #0
_081488B0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081488B8: .4byte 0x000004A4

	thumb_func_start FUN_081488bc
FUN_081488bc: @ 0x081488BC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081488E4
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	ldr r7, _081488E0 @ =0x0000024E
	adds r0, r4, r7
	strh r1, [r0]
	b _08148988
	.align 2, 0
_081488E0: .4byte 0x0000024E
_081488E4:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	bne _08148988
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r3, #0
	ldrsh r0, [r1, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r7, #2
	ldrsh r0, [r1, r7]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	cmn r2, r0
	bne _0814892E
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r5, [r0, r3]
	cmp r5, #0
	beq _08148936
_0814892E:
	adds r0, r4, #0
	bl FUN_081486d8
	b _0814897E
_08148936:
	ldr r3, _08148990 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r7, _08148994 @ =0x0000046D
	adds r0, r4, r7
	movs r2, #1
	strb r2, [r0]
	subs r7, #2
	adds r0, r4, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r1, #0
	strh r5, [r0]
	subs r7, #0xeb
	adds r0, r4, r7
	strb r1, [r0]
	ldr r3, _08148998 @ =0x00000469
	adds r0, r4, r3
	strb r2, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _0814899C @ =0x00000484
	adds r0, r4, r1
	str r5, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r2, [r0]
_0814897E:
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_08148988:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08148990: .4byte FUN_080e48d0
_08148994: .4byte 0x0000046D
_08148998: .4byte 0x00000469
_0814899C: .4byte 0x00000484

	thumb_func_start FUN_081489a0
FUN_081489a0: @ 0x081489A0
	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081489E4
	ldrb r0, [r1, #4]
	cmp r0, #3
	bhi _081489D8
	ldr r0, _081489DC @ =0x03002BE0
	ldrb r1, [r1, #4]
	lsls r2, r1, #2
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081489E4
	movs r0, #8
	ldr r1, _081489E0 @ =0x03002BC0
	adds r1, r2, r1
	ldr r1, [r1]
	ands r1, r0
	cmp r1, #0
	bne _081489E4
_081489D8:
	movs r0, #0
	b _081489E6
	.align 2, 0
_081489DC: .4byte 0x03002BE0
_081489E0: .4byte 0x03002BC0
_081489E4:
	movs r0, #1
_081489E6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081489ec
FUN_081489ec: @ 0x081489EC
	movs r0, #0
	bx lr

	thumb_func_start FUN_081489f0
FUN_081489f0: @ 0x081489F0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0x11
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r5, #0
	strb r5, [r0]
	ldr r6, _08148AC4 @ =0x00000469
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r4, r6
	str r5, [r0]
	ldr r1, _08148AC8 @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r3, _08148ACC @ =FUN_080e48d0
	movs r2, #0x10
	subs r6, #0x17
	adds r0, r4, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r4, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r4, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r4, r6
	strh r5, [r0]
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r4, r2
	str r5, [r0]
	ldr r6, _08148AD0 @ =0x00000482
	adds r0, r4, r6
	strh r1, [r0]
	ldr r1, _08148AD4 @ =0x00000222
	adds r0, r4, r1
	strh r5, [r0]
	adds r2, #0x76
	adds r0, r4, r2
	strh r5, [r0]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r3, r4, r6
	ldr r0, _08148AD8 @ =0xFFFFFC7F
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _08148ADC @ =0xF3FFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08148AAC
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _08148AE0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _08148AE4 @ =0xFFFFFDFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	adds r6, #0x9e
	adds r0, r4, r6
	strh r5, [r0]
	ldr r1, _08148AE8 @ =0x00000202
	adds r0, r4, r1
	strh r5, [r0]
_08148AAC:
	ldr r0, _08148AEC @ =0xFFFFFBFF
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	ldr r2, _08148AF0 @ =0x00000542
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08148AC4: .4byte 0x00000469
_08148AC8: .4byte 0x0000046C
_08148ACC: .4byte FUN_080e48d0
_08148AD0: .4byte 0x00000482
_08148AD4: .4byte 0x00000222
_08148AD8: .4byte 0xFFFFFC7F
_08148ADC: .4byte 0xF3FFFFFF
_08148AE0: .4byte 0xFEFFFFFF
_08148AE4: .4byte 0xFFFFFDFF
_08148AE8: .4byte 0x00000202
_08148AEC: .4byte 0xFFFFFBFF
_08148AF0: .4byte 0x00000542

	thumb_func_start FUN_08148af4
FUN_08148af4: @ 0x08148AF4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _08148B68 @ =0x0000049C
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _08148B7C
	ldr r2, _08148B6C @ =0x000005CC
	adds r0, r5, r2
	ldr r3, [r0]
	movs r1, #0x12
	ldr r6, _08148B70 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
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
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08148B74 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08148B78 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	movs r0, #1
	b _08148BF6
	.align 2, 0
_08148B68: .4byte 0x0000049C
_08148B6C: .4byte 0x000005CC
_08148B70: .4byte 0x0000046D
_08148B74: .4byte 0x00000469
_08148B78: .4byte 0x0000046C
_08148B7C:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r5, r6
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08148BF4
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	movs r1, #1
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08148BB4
	movs r0, #1
	b _08148BB6
_08148BB4:
	movs r0, #0
_08148BB6:
	cmp r0, #0
	bne _08148BCE
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r6, _08148BFC @ =0x00000546
	adds r0, r5, r6
	ldrh r0, [r0]
	cmp r1, r0
	bge _08148BF4
_08148BCE:
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	movs r6, #0xd2
	lsls r6, r6, #3
	adds r1, r1, r6
	movs r0, #2
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
_08148BF4:
	movs r0, #0
_08148BF6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08148BFC: .4byte 0x00000546

	thumb_func_start FUN_08148c00
FUN_08148c00: @ 0x08148C00
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08148C18 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08148C1C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08148C1E
	.align 2, 0
_08148C18: .4byte 0x0000046C
_08148C1C:
	movs r0, #0
_08148C1E:
	cmp r0, #0
	beq _08148C58
	adds r0, r4, #0
	bl FUN_081486d8
	movs r2, #2
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08148C50 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _08148C54 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _08148C62
	.align 2, 0
_08148C50: .4byte 0x00000469
_08148C54: .4byte 0x00000484
_08148C58:
	ldr r0, _08148C68 @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08148C62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08148C68: .4byte 0x00000484

	thumb_func_start FUN_08148c6c
FUN_08148c6c: @ 0x08148C6C
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _08148C78 @ =0x085AD8BC
	str r1, [r0]
	bx lr
	.align 2, 0
_08148C78: .4byte 0x085AD8BC

	thumb_func_start FUN_08148c7c
FUN_08148c7c: @ 0x08148C7C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _08148CB0 @ =0x0000062C
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
	bl FUN_08146fc0
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08148CB0: .4byte 0x0000062C

	thumb_func_start FUN_08148cb4
FUN_08148cb4: @ 0x08148CB4
	push {lr}
	bl FUN_080f06b0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EnemyMimic_Destroy
EnemyMimic_Destroy: @ 0x08148CC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08148CD8 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08148CDC
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _08148CE4
	.align 2, 0
_08148CD8: .4byte 0x0000025D
_08148CDC:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_08148CE4:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08148D00 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _08148D04
	movs r0, #1
	b _08148D06
	.align 2, 0
_08148D00: .4byte 0x00000474
_08148D04:
	movs r0, #0
_08148D06:
	cmp r0, #0
	beq _08148D12
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_08148D12:
	ldr r1, _08148D6C @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08148D2A
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_08148D2A:
	ldr r0, _08148D70 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08148D42
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_08148D42:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08148D5A
	adds r0, r4, #0
	bl FUN_08002a58
_08148D5A:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08148D74
	movs r0, #1
	b _08148D76
	.align 2, 0
_08148D6C: .4byte 0x0000044C
_08148D70: .4byte 0x0000044D
_08148D74:
	movs r0, #0
_08148D76:
	cmp r0, #0
	beq _08148D82
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_08148D82:
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

	thumb_func_start EnemyMimic_Init
EnemyMimic_Init: @ 0x08148DA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r0, _08148E20 @ =0x000001DF
	adds r1, r7, r0
	movs r0, #0xb
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_081482bc
	ldr r1, _08148E24 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08148E30
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08148E28 @ =0x00003876
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08148E2C @ =0x00009AF2
	bl FUN_080e3804
	ldr r2, _08148E20 @ =0x000001DF
	adds r0, r7, r2
	ldrb r1, [r0]
	str r0, [sp, #0x40]
	cmp r1, #0x11
	beq _08148E0E
	cmp r1, #0x17
	bne _08148E12
_08148E0E:
	movs r0, #1
	strb r0, [r5, #7]
_08148E12:
	movs r3, #0xef
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
	b _08148E9A
	.align 2, 0
_08148E20: .4byte 0x000001DF
_08148E24: .4byte 0x0000025D
_08148E28: .4byte 0x00003876
_08148E2C: .4byte 0x00009AF2
_08148E30:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r5, sp, #0x14
	mov r8, r5
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _08148F18 @ =0x05000002
	bl CpuSet
	ldr r0, _08148F1C @ =0x0000CB05
	ldr r1, _08148F20 @ =0x00003876
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r6}
	stm r2!, {r3, r6}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r5, r8
	str r5, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r6, _08148F24 @ =0x000004B7
	adds r1, r7, r6
	movs r0, #0xff
	strb r0, [r1]
	adds r0, #0xe0
	adds r0, r7, r0
	str r0, [sp, #0x40]
_08148E9A:
	str r7, [sp, #0x28]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r1, r1, r7
	mov sb, r1
	movs r4, #0
	str r4, [r1]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	str r4, [r2]
	ldr r3, _08148F28 @ =0x0000046F
	adds r0, r7, r3
	strb r4, [r0]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r6, #0
	mov sl, r6
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, _08148F2C @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08148F18 @ =0x05000002
	bl CpuSet
	ldr r3, _08148F30 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x19c]
	bl prepare_08231510
	mov r1, sb
	str r1, [sp, #0x174]
	mov r3, r8
	str r3, [sp, #0x178]
	str r6, [sp, #0x150]
	ldr r2, [sp, #0x19c]
	adds r6, r2, #0
	cmp r0, #0
	bne _08148F06
	b _08149064
_08148F06:
	bl VM_GetPC
	cmp r0, #0
	beq _08148F34
	bl Script_GetValue
	adds r1, r0, #0
	b _08148F36
	.align 2, 0
_08148F18: .4byte 0x05000002
_08148F1C: .4byte 0x0000CB05
_08148F20: .4byte 0x00003876
_08148F24: .4byte 0x000004B7
_08148F28: .4byte 0x0000046F
_08148F2C: .4byte 0x00000474
_08148F30: .4byte 0x000004B6
_08148F34:
	movs r1, #0
_08148F36:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08148F5C @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xa0]
	str r4, [sp, #0xa4]
	cmp r0, #0
	beq _08148F60
	bl Script_GetValue
	adds r1, r0, #0
	b _08148F62
	.align 2, 0
_08148F5C: .4byte 0x00000251
_08148F60:
	movs r1, #0
_08148F62:
	ldr r2, _08148F98 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08148F9C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xa0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xac]
	cmp r0, #0
	beq _08148FA0
	bl Script_GetValue
	b _08148FA4
	.align 2, 0
_08148F98: .4byte 0x00000252
_08148F9C: .4byte 0x000004B4
_08148FA0:
	ldr r4, [sp, #0xa0]
	ldrb r0, [r4]
_08148FA4:
	strb r0, [r6]
	ldr r5, [sp, #0xa0]
	ldrb r1, [r5]
	ldr r6, [sp, #0xac]
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
	blt _08148FDC
	cmp r1, #0
	blt _08148FDC
	ldr r0, _08148FE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08148FDC
	ldr r0, _08148FE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08148FE8
_08148FDC:
	movs r1, #0
	b _08148FF6
	.align 2, 0
_08148FE0: .4byte 0x030046A8
_08148FE4: .4byte 0x030046AC
_08148FE8:
	ldr r0, _08149010 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08148FF6:
	ldr r2, _08149014 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08149018
	adds r0, #4
	b _08149024
	.align 2, 0
_08149010: .4byte 0x030046A4
_08149014: .4byte 0x00000256
_08149018:
	ldr r0, _08149038 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08149024:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814903C
	cmp r2, #2
	beq _08149040
	b _08149044
	.align 2, 0
_08149038: .4byte 0x030046A4
_0814903C:
	ldrb r0, [r4, #4]
	b _08149042
_08149040:
	ldrb r0, [r4]
_08149042:
	subs r1, r1, r0
_08149044:
	ldr r3, _0814905C @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08149060 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _081490A4
	.align 2, 0
_0814905C: .4byte 0x00000472
_08149060: .4byte 0x0000FFFF
_08149064:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081490C8 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081490CC @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081490D0 @ =0x000004B4
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
	str r5, [sp, #0xa0]
	str r4, [sp, #0xa4]
	str r3, [sp, #0xac]
_081490A4:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _081490EE
	bl VM_GetPC
	cmp r0, #0
	beq _081490D4
	bl Script_GetValue
	adds r4, r0, #0
	b _081490D6
	.align 2, 0
_081490C8: .4byte 0x00000251
_081490CC: .4byte 0x00000252
_081490D0: .4byte 0x000004B4
_081490D4:
	movs r4, #0x30
_081490D6:
	bl VM_GetPC
	cmp r0, #0
	beq _081490E8
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081490EA
_081490E8:
	movs r5, #0x40
_081490EA:
	mov r8, r4
	b _081490F4
_081490EE:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081490F4:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _0814912C
	bl VM_GetPC
	cmp r0, #0
	beq _0814910E
	bl Script_GetValue
	adds r6, r0, #0
	b _08149110
_0814910E:
	movs r6, #0
_08149110:
	bl VM_GetPC
	cmp r0, #0
	beq _08149120
	bl Script_GetValue
	adds r1, r0, #0
	b _08149122
_08149120:
	movs r1, #0
_08149122:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08149136
_0814912C:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08149136:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _081493A8 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0xc0]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x98]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x180]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x17c]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	lsls r4, r4, #0x10
	str r4, [sp, #0x194]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x38]
	lsls r6, r6, #0x10
	str r6, [sp, #0x3c]
	lsls r5, r5, #0x10
	str r5, [sp, #0x34]
	ldr r4, _081493AC @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0xbc]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x190]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x138]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x44]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x48]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x13c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x140]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x134]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x160]
	ldr r1, _081493B0 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x154]
	ldr r2, _081493B4 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x158]
	ldr r3, _081493B8 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x15c]
	ldr r4, _081493BC @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x16c]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x170]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x84]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x94]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	ldr r4, _081493C0 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0xc4]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd8]
	ldr r6, _081493C4 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0xdc]
	ldr r1, _081493C8 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0xe4]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	ldr r3, _081493CC @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0xec]
	ldr r4, _081493D0 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0xf4]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xe0]
	ldr r6, _081493D4 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x88]
	ldr r1, _081493D8 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x118]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x11c]
	ldr r3, _081493DC @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0x5c]
	ldr r4, _081493E0 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x120]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x108]
	ldr r6, _081493E4 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x10c]
	ldr r2, _081493E8 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x110]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x114]
	ldr r4, _081493EC @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x124]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x128]
	ldr r6, _081493F0 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0xd4]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x100]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf8]
	ldr r3, _081493F4 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x104]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xf0]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc8]
	ldr r6, _081493F8 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x12c]
	ldr r1, _081493FC @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x90]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x130]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xd0]
	ldr r4, _08149400 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x9c]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xa8]
	ldr r6, _08149404 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0xb4]
	ldr r1, _08149408 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0xcc]
	ldr r2, _0814940C @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0x4c]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x184]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x188]
	ldr r5, _08149410 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x168]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x144]
	ldr r1, _08149414 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x148]
	ldr r2, _08149418 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _0814941C @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0x50]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x80]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x164]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x30]
	ldr r1, _08149420 @ =0x00000572
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x18c]
	movs r3, #0xae
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x78]
	ldr r4, _08149424 @ =0x0000055C
	adds r4, r7, r4
	str r4, [sp, #0x54]
	movs r5, #0xac
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x58]
	ldr r6, _08149428 @ =0x00000564
	adds r6, r7, r6
	str r6, [sp, #0x60]
	ldr r1, _0814942C @ =0x00000565
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r2, _08149430 @ =0x00000566
	adds r2, r7, r2
	str r2, [sp, #0x68]
	ldr r3, _08149434 @ =0x00000567
	adds r3, r7, r3
	str r3, [sp, #0x6c]
	movs r4, #0xad
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _08149438 @ =0x0000056C
	adds r5, r7, r5
	str r5, [sp, #0x74]
	cmp r0, #0
	bne _08149378
	b _08149492
_08149378:
	movs r6, #0
	mov sl, r6
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r5, r7, r2
	movs r3, #0x89
	lsls r3, r3, #2
	adds r4, r7, r3
_08149398:
	bl VM_GetPC
	cmp r0, #0
	beq _0814943C
	bl Script_GetValue
	b _0814943E
	.align 2, 0
_081493A8: .4byte 0x0000025D
_081493AC: .4byte 0x0000025A
_081493B0: .4byte 0x0000047A
_081493B4: .4byte 0x0000047C
_081493B8: .4byte 0x0000047E
_081493BC: .4byte 0x000004A4
_081493C0: .4byte 0x000005A4
_081493C4: .4byte 0x000005C4
_081493C8: .4byte 0x000005CC
_081493CC: .4byte 0x000005D4
_081493D0: .4byte 0x000005DC
_081493D4: .4byte 0x00000584
_081493D8: .4byte 0x00000604
_081493DC: .4byte 0x0000021D
_081493E0: .4byte 0x0000060C
_081493E4: .4byte 0x000005E4
_081493E8: .4byte 0x000005FC
_081493EC: .4byte 0x00000614
_081493F0: .4byte 0x000005BC
_081493F4: .4byte 0x000005EC
_081493F8: .4byte 0x00000624
_081493FC: .4byte 0x0000058C
_08149400: .4byte 0x00000594
_08149404: .4byte 0x0000059C
_08149408: .4byte 0x000005B4
_0814940C: .4byte 0x00000543
_08149410: .4byte 0x00000496
_08149414: .4byte 0x00000469
_08149418: .4byte 0x0000046A
_0814941C: .4byte 0x00000553
_08149420: .4byte 0x00000572
_08149424: .4byte 0x0000055C
_08149428: .4byte 0x00000564
_0814942C: .4byte 0x00000565
_08149430: .4byte 0x00000566
_08149434: .4byte 0x00000567
_08149438: .4byte 0x0000056C
_0814943C:
	movs r0, #0x18
_0814943E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08149450
	bl Script_GetValue
	b _08149452
_08149450:
	movs r0, #0x18
_08149452:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08149464
	bl Script_GetValue
	b _08149466
_08149464:
	movs r0, #0
_08149466:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08149478
	bl Script_GetValue
	b _0814947A
_08149478:
	movs r0, #0
_0814947A:
	strh r0, [r6]
	movs r6, #2
	add sb, r6
	movs r0, #4
	add r8, r0
	adds r5, #2
	adds r4, #2
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #3
	ble _08149398
_08149492:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _081494DE
	bl VM_GetPC
	cmp r0, #0
	beq _081494AC
	bl Script_GetValue
	adds r4, r0, #0
	b _081494B0
_081494AC:
	movs r4, #0x96
	lsls r4, r4, #1
_081494B0:
	bl VM_GetPC
	cmp r0, #0
	beq _081494C0
	bl Script_GetValue
	adds r6, r0, #0
	b _081494C4
_081494C0:
	movs r6, #0x96
	lsls r6, r6, #1
_081494C4:
	bl VM_GetPC
	cmp r0, #0
	beq _081494D2
	bl Script_GetValue
	b _081494D8
_081494D2:
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
_081494D8:
	ldr r5, [sp, #0x98]
	strh r0, [r5]
	b _081494E6
_081494DE:
	movs r4, #0
	movs r6, #0
	ldr r0, [sp, #0x98]
	strh r6, [r0]
_081494E6:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081494FE
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x178]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_081494FE:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x180]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x17c]
	strh r0, [r5]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _081495CC
	bl VM_GetPC
	cmp r0, #0
	beq _0814952E
	bl Script_GetValue
	b _08149530
_0814952E:
	movs r0, #0
_08149530:
	ldr r1, [sp, #0xb0]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _0814953E
	asrs r1, r0, #1
	b _08149544
_0814953E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08149544:
	ldr r2, _08149558 @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0814955C
	bl Script_GetValue
	b _0814955E
	.align 2, 0
_08149558: .4byte 0x00000546
_0814955C:
	movs r0, #0
_0814955E:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08149574
	bl Script_GetValue
	b _08149576
_08149574:
	movs r0, #0
_08149576:
	ldr r5, _0814958C @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08149590
	bl Script_GetValue
	adds r1, r0, #0
	b _08149592
	.align 2, 0
_0814958C: .4byte 0x00000187
_08149590:
	movs r1, #0
_08149592:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081495A8
	bl Script_GetValue
	b _081495AA
_081495A8:
	movs r0, #0
_081495AA:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081495C2
	bl Script_GetValue
	adds r1, r0, #0
	b _081495C4
_081495C2:
	movs r1, #0
_081495C4:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_081495CC:
	ldr r0, [sp, #0xb0]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0x194]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x38]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0x3c]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x34]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _0814962E
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08149614
	bl Script_GetValue
	b _08149616
_08149614:
	movs r0, #0
_08149616:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08149626
	bl Script_GetValue
	b _08149628
_08149626:
	movs r0, #0
_08149628:
	ldr r2, _08149690 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_0814962E:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r3, [sp, #0xbc]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08149652
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x178]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08149652:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _0814966A
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x178]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_0814966A:
	ldr r6, [sp, #0x190]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x150]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08149694
	movs r0, #1
	b _08149696
	.align 2, 0
_08149690: .4byte 0x00000189
_08149694:
	movs r0, #0
_08149696:
	cmp r0, #0
	beq _081496A6
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081496D0 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_081496A6:
	ldr r3, [sp, #0xc0]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _081496B2
	ldr r1, [r7, #0x44]
_081496B2:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _081496D4
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x138]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _081496E0
	.align 2, 0
_081496D0: .4byte FUN_080f48ac
_081496D4:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x138]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_081496E0:
	ldr r5, [sp, #0x40]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0814972E
	adds r0, r1, #0
	cmp r0, #0xb
	beq _0814972E
	cmp r0, #0x16
	beq _0814972E
	cmp r0, #0x14
	beq _0814972E
	cmp r0, #9
	beq _0814972E
	cmp r0, #0x19
	beq _0814972E
	cmp r0, #0x1a
	beq _0814972E
	cmp r0, #0xd
	beq _0814972E
	cmp r0, #0x1b
	beq _0814972E
	cmp r0, #0x1f
	beq _0814972E
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xa0]
	ldrb r2, [r6]
	ldr r0, [sp, #0xa4]
	ldrb r3, [r0]
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_0814972E:
	movs r1, #8
	ldr r5, [sp, #0x150]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0814973E
	movs r0, #1
	b _08149740
_0814973E:
	movs r0, #0
_08149740:
	cmp r0, #0
	beq _0814974E
	ldr r6, [sp, #0x48]
	ldr r0, [r6]
	ldr r1, [sp, #0x44]
	str r0, [r1]
	b _08149760
_0814974E:
	ldr r2, [sp, #0x48]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0x44]
	str r0, [r3]
_08149760:
	ldrh r0, [r7]
	ldr r4, [sp, #0x13c]
	strh r0, [r4]
	ldr r5, [sp, #0x134]
	ldr r6, [sp, #0x140]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _0814978A
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
	ldr r1, [sp, #0x28]
	strb r0, [r1, #5]
_0814978A:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r7, #5]
	movs r0, #0x73
	movs r1, #0xa
	bl Script_GetKeywordValue
	ldr r2, [sp, #0x24]
	ldr r3, _081497BC @ =0x00000692
	adds r1, r2, r3
	strb r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08149894
	bl VM_GetPC
	cmp r0, #0
	beq _081497C0
	bl Script_GetValue
	b _081497C2
	.align 2, 0
_081497BC: .4byte 0x00000692
_081497C0:
	movs r0, #0
_081497C2:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _081497D2
	bl Script_GetValue
	b _081497D4
_081497D2:
	movs r0, #0
_081497D4:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _081497E4
	bl Script_GetValue
	b _081497E6
_081497E4:
	movs r0, #0
_081497E6:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r4, [sp, #0x134]
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814980E
	cmp r1, #0
	blt _0814980E
	ldr r0, _08149814 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814980E
	ldr r0, _08149818 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814981C
_0814980E:
	movs r2, #0
	b _0814982A
	.align 2, 0
_08149814: .4byte 0x030046A8
_08149818: .4byte 0x030046AC
_0814981C:
	ldr r0, _0814984C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r2
_0814982A:
	ldr r5, _08149850 @ =0x00000256
	adds r1, r7, r5
	strh r2, [r1]
	movs r6, #0x96
	lsls r6, r6, #2
	adds r0, r7, r6
	strh r2, [r0]
	ldrh r4, [r1]
	ldr r5, [sp, #0x134]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08149854
	adds r0, #4
	b _08149860
	.align 2, 0
_0814984C: .4byte 0x030046A4
_08149850: .4byte 0x00000256
_08149854:
	ldr r0, _08149874 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08149860:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08149878
	cmp r3, #2
	beq _0814987C
	b _08149880
	.align 2, 0
_08149874: .4byte 0x030046A4
_08149878:
	ldrb r0, [r5, #4]
	b _0814987E
_0814987C:
	ldrb r0, [r5]
_0814987E:
	subs r2, r2, r0
_08149880:
	ldr r0, _081498E8 @ =0x00000472
	adds r1, r7, r0
	movs r0, #0
	strh r2, [r1]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r2, r7, r3
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r7, #0xa]
_08149894:
	ldr r4, [sp, #0x24]
	ldr r5, _081498EC @ =0x00000684
	adds r2, r4, r5
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r6, _081498F0 @ =0x00000256
	adds r0, r7, r6
	ldrh r1, [r0]
	ldr r2, _081498F4 @ =0x0000068C
	adds r0, r4, r2
	strh r1, [r0]
	ldr r4, _081498F8 @ =0x0000028A
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x160]
	strh r0, [r3]
	ldr r6, [sp, #0x154]
	strh r4, [r6]
	ldr r0, [sp, #0x158]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, r0, r4
	ldr r1, [sp, #0x15c]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0xc0]
	ldrb r0, [r2]
	cmp r0, #0
	bne _081498FC
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _08149908
	.align 2, 0
_081498E8: .4byte 0x00000472
_081498EC: .4byte 0x00000684
_081498F0: .4byte 0x00000256
_081498F4: .4byte 0x0000068C
_081498F8: .4byte 0x0000028A
_081498FC:
	ldr r2, [r7, #0x44]
	ldr r0, _08149940 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08149908:
	ldr r3, [sp, #0xc0]
	ldrb r0, [r3]
	cmp r0, #1
	bne _08149958
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08149944
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
	b _0814994E
	.align 2, 0
_08149940: .4byte 0x03003584
_08149944:
	ldr r5, [sp, #0x40]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_0814994E:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08149958:
	adds r0, r7, #0
	bl FUN_0814842c
	ldr r6, [sp, #0x24]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r3, r6, r0
	ldr r1, _08149AE4 @ =0x0000067C
	adds r4, r6, r1
	ldr r5, _08149AE8 @ =FUN_08148c7c
	movs r2, #0
	ldr r6, _08149AEC @ =FUN_08146fcc
	mov r8, r6
	ldr r0, _08149AF0 @ =FUN_081474e8
	mov sb, r0
	ldr r1, _08149AF4 @ =FUN_081477dc
	mov sl, r1
	ldr r6, _08149AF8 @ =FUN_081475b8
	mov ip, r6
	ldr r0, _08149AFC @ =FUN_081489ec
	str r0, [sp, #0x1a0]
	ldr r1, _08149B00 @ =FUN_080f62ac
	str r1, [sp, #0x198]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x174]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x16c]
	str r3, [r0]
	ldr r1, [sp, #0x170]
	str r4, [r1]
	ldr r3, [sp, #0x84]
	str r5, [r3]
	ldr r4, [sp, #0x8c]
	str r2, [r4]
	ldr r5, [sp, #0x94]
	str r2, [r5]
	mov r6, r8
	ldr r0, [sp, #0xb8]
	str r6, [r0]
	mov r1, sb
	ldr r3, [sp, #0xc4]
	str r1, [r3]
	ldr r4, [sp, #0xd8]
	str r2, [r4]
	ldr r5, [sp, #0x1a0]
	ldr r6, [sp, #0xdc]
	str r5, [r6]
	mov r0, sl
	ldr r1, [sp, #0xe4]
	str r0, [r1]
	mov r3, ip
	ldr r4, [sp, #0xe8]
	str r3, [r4]
	ldr r0, _08149B04 @ =FUN_080f44f4
	ldr r5, [sp, #0xec]
	str r0, [r5]
	ldr r0, _08149B08 @ =FUN_080f410c
	ldr r6, [sp, #0xf4]
	str r0, [r6]
	ldr r0, [sp, #0xe0]
	str r2, [r0]
	ldr r1, [sp, #0x88]
	str r2, [r1]
	ldr r3, [sp, #0x198]
	ldr r4, [sp, #0x118]
	str r3, [r4]
	ldr r0, _08149B0C @ =FUN_080f0430
	ldr r5, [sp, #0x11c]
	str r0, [r5]
	movs r0, #1
	ldr r6, [sp, #0x5c]
	strb r0, [r6]
	ldr r0, _08149B10 @ =0x085AD470
	ldr r1, [sp, #0x120]
	str r0, [r1]
	ldr r0, _08149B14 @ =FUN_080e73c8
	ldr r3, [sp, #0x108]
	str r0, [r3]
	ldr r4, [sp, #0xfc]
	str r2, [r4]
	ldr r5, [sp, #0x10c]
	str r2, [r5]
	ldr r6, [sp, #0x110]
	str r2, [r6]
	ldr r0, [sp, #0x114]
	str r2, [r0]
	ldr r1, [sp, #0x124]
	str r2, [r1]
	ldr r0, _08149B18 @ =FUN_080f0320
	ldr r3, [sp, #0x128]
	str r0, [r3]
	ldr r0, _08149B1C @ =FUN_080eff14
	ldr r4, [sp, #0xd4]
	str r0, [r4]
	ldr r0, _08149B20 @ =FUN_080e72b0
	ldr r5, [sp, #0x100]
	str r0, [r5]
	ldr r6, [sp, #0xf8]
	str r2, [r6]
	ldr r0, _08149B24 @ =FUN_080f47c8
	ldr r1, [sp, #0x104]
	str r0, [r1]
	ldr r0, _08149B28 @ =FUN_080f54e4
	ldr r3, [sp, #0xf0]
	str r0, [r3]
	ldr r4, [sp, #0xc8]
	str r2, [r4]
	ldr r0, _08149B2C @ =FUN_080f6e64
	ldr r5, [sp, #0x12c]
	str r0, [r5]
	ldr r0, _08149B30 @ =FUN_080f64f0
	ldr r6, [sp, #0x90]
	str r0, [r6]
	ldr r0, _08149B34 @ =FUN_080f84d4
	ldr r1, [sp, #0x130]
	str r0, [r1]
	ldr r0, _08149B38 @ =FUN_080f624c
	ldr r3, [sp, #0xd0]
	str r0, [r3]
	ldr r0, _08149B3C @ =FUN_080f56ec
	ldr r4, [sp, #0x9c]
	str r0, [r4]
	ldr r0, _08149B40 @ =FUN_080f5b34
	ldr r5, [sp, #0xa8]
	str r0, [r5]
	ldr r0, _08149B44 @ =FUN_080f5fac
	ldr r6, [sp, #0xb4]
	str r0, [r6]
	ldr r0, [sp, #0xcc]
	str r2, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0x4c]
	strb r0, [r1]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _08149B48 @ =FUN_08147a38
	str r0, [r1]
	ldr r4, _08149B4C @ =0x000005AC
	adds r1, r7, r4
	ldr r0, _08149B50 @ =FUN_081488bc
	str r0, [r1]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r0, r7, r5
	str r2, [r0]
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r1, r7, r6
	ldr r0, _08149B54 @ =FUN_08148784
	str r0, [r1]
	ldr r0, _08149B58 @ =0x0000058C
	adds r1, r7, r0
	ldr r0, _08149B5C @ =FUN_08148af4
	str r0, [r1]
	ldr r1, _08149B60 @ =0x00400200
	ldr r2, [sp, #0x174]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #8
	ldr r3, [sp, #0x178]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r0, #0x40
	ldr r4, [sp, #0x150]
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0x184]
	strh r0, [r5]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _08149B6E
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_08149AD6:
	bl VM_GetPC
	cmp r0, #0
	beq _08149B64
	bl Script_GetValue
	b _08149B66
	.align 2, 0
_08149AE4: .4byte 0x0000067C
_08149AE8: .4byte FUN_08148c7c
_08149AEC: .4byte FUN_08146fcc
_08149AF0: .4byte FUN_081474e8
_08149AF4: .4byte FUN_081477dc
_08149AF8: .4byte FUN_081475b8
_08149AFC: .4byte FUN_081489ec
_08149B00: .4byte FUN_080f62ac
_08149B04: .4byte FUN_080f44f4
_08149B08: .4byte FUN_080f410c
_08149B0C: .4byte FUN_080f0430
_08149B10: .4byte 0x085AD470
_08149B14: .4byte FUN_080e73c8
_08149B18: .4byte FUN_080f0320
_08149B1C: .4byte FUN_080eff14
_08149B20: .4byte FUN_080e72b0
_08149B24: .4byte FUN_080f47c8
_08149B28: .4byte FUN_080f54e4
_08149B2C: .4byte FUN_080f6e64
_08149B30: .4byte FUN_080f64f0
_08149B34: .4byte FUN_080f84d4
_08149B38: .4byte FUN_080f624c
_08149B3C: .4byte FUN_080f56ec
_08149B40: .4byte FUN_080f5b34
_08149B44: .4byte FUN_080f5fac
_08149B48: .4byte FUN_08147a38
_08149B4C: .4byte 0x000005AC
_08149B50: .4byte FUN_081488bc
_08149B54: .4byte FUN_08148784
_08149B58: .4byte 0x0000058C
_08149B5C: .4byte FUN_08148af4
_08149B60: .4byte 0x00400200
_08149B64:
	movs r0, #0
_08149B66:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08149AD6
_08149B6E:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x188]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x168]
	strh r0, [r3]
	cmp r2, #0
	beq _08149BA6
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x174]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _08149BA6
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_08149BA6:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x150]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08149BB8
	movs r0, #1
	b _08149BBA
_08149BB8:
	movs r0, #0
_08149BBA:
	cmp r0, #0
	beq _08149BCC
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x178]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_08149BCC:
	cmp r2, #1
	beq _08149C0C
	movs r1, #0
	ldr r0, [sp, #0x144]
	strb r1, [r0]
	ldr r2, [sp, #0x148]
	strb r1, [r2]
	ldr r3, [sp, #0x14c]
	strb r1, [r3]
	ldr r4, _08149C1C @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _08149C20 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0xc4]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0x50]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_08149C0C:
	movs r1, #2
	ldr r3, [sp, #0x150]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08149C24
	movs r0, #1
	b _08149C26
	.align 2, 0
_08149C1C: .4byte 0x00000484
_08149C20: .4byte 0x0000046C
_08149C24:
	movs r0, #0
_08149C26:
	cmp r0, #0
	beq _08149C40
	ldr r0, _08149C3C @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x164]
	strh r0, [r5]
	b _08149C4A
	.align 2, 0
_08149C3C: .4byte 0x030046A0
_08149C40:
	ldr r0, [sp, #0x134]
	bl FUN_08241574
	ldr r6, [sp, #0x164]
	strh r0, [r6]
_08149C4A:
	movs r1, #0x40
	ldr r2, [sp, #0x150]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08149C5A
	movs r0, #1
	b _08149C5C
_08149C5A:
	movs r0, #0
_08149C5C:
	cmp r0, #0
	beq _08149C6C
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08149C90 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08149C6C:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _08149C9E
	ldr r0, _08149C94 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x164]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08149C98
	movs r0, #1
	b _08149C9A
	.align 2, 0
_08149C90: .4byte 0xFFFFFEFF
_08149C94: .4byte 0x030046A0
_08149C98:
	movs r0, #0
_08149C9A:
	cmp r0, #0
	bne _08149CA6
_08149C9E:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08149CA6:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0xc0]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08149D8E
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
	beq _08149CE8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08149CF0
_08149CE8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08149CF0:
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
	beq _08149D14
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08149D1C
_08149D14:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08149D1C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _08149D54 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08149D98
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08149D58
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08149D4C
	ldrb r0, [r4, #5]
_08149D4C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08149D68
	.align 2, 0
_08149D54: .4byte 0x0000FFFF
_08149D58:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08149D68
	strh r1, [r4, #8]
_08149D68:
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
	bne _08149D98
	movs r0, #1
	strb r0, [r4, #7]
	b _08149D98
_08149D8E:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08149D98:
	movs r0, #0
	ldr r3, [sp, #0x30]
	str r0, [r3]
	ldr r0, _08149DB0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08149DB4
	movs r0, #1
	b _08149DB6
	.align 2, 0
_08149DB0: .4byte 0x030047A4
_08149DB4:
	movs r0, #0
_08149DB6:
	cmp r0, #0
	bne _08149DF6
	ldr r4, [sp, #0x40]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08149DDE
	adds r0, r1, #0
	cmp r0, #7
	beq _08149DDE
	cmp r0, #6
	beq _08149DDE
	cmp r0, #0x15
	beq _08149DDE
	cmp r0, #0x14
	beq _08149DDE
	cmp r0, #0x17
	bne _08149DF6
_08149DDE:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x150]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08149DF6:
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08149E4A
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r7, r6
	movs r1, #0
	movs r5, #0
	strh r0, [r2]
	ldr r3, _08149EF4 @ =FUN_08147428
	movs r2, #0x25
	ldr r4, _08149EF8 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _08149EFC @ =0x0000046B
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	ldr r2, [sp, #0x80]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r5, [r0]
	movs r0, #3
	ldr r6, [sp, #0x144]
	strb r0, [r6]
	ldr r0, [sp, #0x148]
	strb r1, [r0]
	ldr r2, [sp, #0x14c]
	strb r1, [r2]
	ldr r3, _08149F00 @ =0x00000484
	adds r0, r7, r3
	str r5, [r0]
	ldr r5, _08149F04 @ =0x0000046C
	adds r0, r7, r5
	strb r4, [r0]
_08149E4A:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_08146fac
	adds r0, r7, #0
	bl FUN_08148c6c
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	strh r0, [r1]
	ldr r1, [sp, #0x150]
	ldrh r0, [r1]
	ldr r2, [sp, #0x7c]
	strh r0, [r2]
	ldr r3, [sp, #0x18c]
	ldrh r0, [r3]
	ldr r4, [sp, #0x78]
	strh r0, [r4]
	ldr r5, [sp, #0x174]
	ldr r0, [r5]
	ldr r6, [sp, #0x54]
	str r0, [r6]
	ldr r1, [sp, #0x178]
	ldr r0, [r1]
	ldr r2, [sp, #0x58]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0x60]
	strb r0, [r3]
	ldr r4, [sp, #0x144]
	ldrb r0, [r4]
	ldr r5, [sp, #0x64]
	strb r0, [r5]
	ldr r6, [sp, #0x148]
	ldrb r0, [r6]
	ldr r1, [sp, #0x68]
	strb r0, [r1]
	ldr r2, [sp, #0x14c]
	ldrb r0, [r2]
	ldr r3, [sp, #0x6c]
	strb r0, [r3]
	ldr r4, [sp, #0x80]
	ldr r0, [r4]
	ldr r5, [sp, #0x70]
	str r0, [r5]
	ldr r6, [sp, #0x50]
	ldrb r0, [r6]
	ldr r1, [sp, #0x74]
	strb r0, [r1]
	ldr r2, _08149F08 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0xb
	strb r0, [r1]
	ldr r3, _08149F0C @ =0x0000057C
	adds r1, r7, r3
	ldr r0, _08149F10 @ =FUN_080f09e0
	str r0, [r1]
	ldr r4, _08149F14 @ =0x0000061C
	adds r1, r7, r4
	ldr r0, _08149F18 @ =FUN_08148cb4
	str r0, [r1]
	movs r5, #0xc4
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08149F1C @ =EnemyMimic_Destroy
	str r0, [r1]
	movs r6, #0x8f
	lsls r6, r6, #3
	adds r1, r7, r6
	movs r0, #0xa3
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08149F20
	movs r0, #0
	b _08149F24
	.align 2, 0
_08149EF4: .4byte FUN_08147428
_08149EF8: .4byte 0x0000046D
_08149EFC: .4byte 0x0000046B
_08149F00: .4byte 0x00000484
_08149F04: .4byte 0x0000046C
_08149F08: .4byte 0x000001DF
_08149F0C: .4byte 0x0000057C
_08149F10: .4byte FUN_080f09e0
_08149F14: .4byte 0x0000061C
_08149F18: .4byte FUN_08148cb4
_08149F1C: .4byte EnemyMimic_Destroy
_08149F20:
	movs r0, #1
	rsbs r0, r0, #0
_08149F24:
	add sp, #0x1a4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyMimic_Create
EnemyMimic_Create: @ 0x08149F34
	push {r4, r5, lr}
	ldr r5, _08149F68 @ =0x00000694
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08149F60
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyMimic_Init
	cmp r0, #0
	bge _08149F60
	adds r0, r4, #0
	bl EnemyMimic_Destroy
	adds r0, r4, #0
	bl Free
_08149F60:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08149F68: .4byte 0x00000694
