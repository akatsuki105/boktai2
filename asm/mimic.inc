	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
	ldr r3, _08146C88 @ =Enemy_ClearStateBegun
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
_08146C88: .4byte Enemy_ClearStateBegun
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
	bl Enemy_SetEmote
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
	bl Map_IsPosInAgentIsland
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
	bl Enemy_IsPosInRect
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
	bl Map_FindTileOverride
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
	bl Map_FindTileOverride
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
	bl Map_FindTileOverride
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
	bl ArcTan2_8
	strb r0, [r6, #5]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrb r4, [r6, #5]
	ldr r2, _08147320 @ =gSineTable
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
_08147320: .4byte gSineTable
_08147324:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814732A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08147344 @ =gSineTable
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
_08147344: .4byte gSineTable
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
	bl ParticleShadow_Show
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
	bl ParticleShadow_Hide
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
	bl Enemy_SetEmote
	b _081475A8
	.align 2, 0
_08147588: .4byte 0x000001DF
_0814758C:
	cmp r5, #0xa0
	ble _081475A8
	ldr r1, _081475B0 @ =0x00000454
	adds r0, r4, r1
	ldr r0, [r0]
	bl Emote_IsInactive
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
	bl EmitSmoke
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
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08147660
	b _0814778C
_08147660:
	ldr r3, _08147754 @ =Enemy_ClearStateBegun
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
	bl ParticleShadow_Hide
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
	bl VM_ExecByID
_08147726:
	ldr r1, _08147764 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r4, r2
	ldrh r1, [r1]
	bl EnemyDex_GetEntryIdx
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
_08147754: .4byte Enemy_ClearStateBegun
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
	bl ParticleShadow_Hide
	b _081477D2
_081477C8:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl ParticleShadow_Show
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
	bl ArcTan2_8
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
	bl Enemy_IsDead
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
	bl Enemy_IsDead
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
	bl ArcTan2_8
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
	bl Hitbox_ApplyDamageAlt
	b _08147FA8
_08147FA0:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
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
	bl ArcTan2_8
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
	bl ArcTan2_8
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
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #2
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #3
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #1
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	movs r3, #0
	bl Enemy_SetAnimEntry
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #4
	movs r3, #0
	bl Enemy_SetAnimEntry
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
	ldr r2, _08148420 @ =Enemy_ClearStateBegun
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
_08148420: .4byte Enemy_ClearStateBegun
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
	bl Enemy_InitAtkHitbox
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
	bl Map_IsPosInAgentIsland
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
	bl Map_IsPosInAgentIsland
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
	bl Enemy_SetEmote
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
	bl EnemyTargetManager_FindOwnerByID
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
	bl Map_IsPosInAgentIsland
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
	ldr r3, _08148990 @ =Enemy_ClearStateBegun
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
_08148990: .4byte Enemy_ClearStateBegun
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
	ldr r3, _08148ACC @ =Enemy_ClearStateBegun
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
_08148ACC: .4byte Enemy_ClearStateBegun
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
	bl Enemy_RunStateHandler
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

