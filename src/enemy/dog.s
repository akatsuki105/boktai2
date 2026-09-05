	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start enemy_dog_08149f6c
enemy_dog_08149f6c: @ 0x08149F6C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _08149FF8 @ =0x000006C2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r3, #0xd8
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r7, #0
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	beq _0814A01A
	ldr r3, _08149FFC @ =0x000001DF
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _08149FB0
	movs r0, #4
	ldr r1, _0814A000 @ =0x00000222
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08149FB0:
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x93
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r3, #0xce
	adds r0, r4, r3
	strh r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	bne _08149FE4
	adds r0, r4, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814A012
_08149FE4:
	movs r1, #8
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814A004
	movs r0, #1
	b _0814A006
	.align 2, 0
_08149FF8: .4byte 0x000006C2
_08149FFC: .4byte 0x000001DF
_0814A000: .4byte 0x00000222
_0814A004:
	movs r0, #0
_0814A006:
	cmp r0, #0
	bne _0814A082
	adds r0, r4, #0
	bl enemy_dog_0814b500
	b _0814A082
_0814A012:
	adds r0, r4, #0
	bl enemy_dog_0814a320
	b _0814A072
_0814A01A:
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r2, r6, r3
	movs r1, #0xd
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r7, [r0]
	ldr r2, _0814A088 @ =0x00000469
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _0814A08C @ =0x0000046A
	adds r0, r4, r3
	strb r7, [r0]
	adds r6, #0x1c
	adds r0, r4, r6
	str r5, [r0]
	adds r2, #3
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _0814A090 @ =FUN_080e48d0
	movs r2, #0x10
	subs r6, #0x17
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _0814A094 @ =0x0000046B
	adds r0, r4, r1
	strb r7, [r0]
	adds r6, #0xe6
	adds r0, r4, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
_0814A072:
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0814A082:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814A088: .4byte 0x00000469
_0814A08C: .4byte 0x0000046A
_0814A090: .4byte FUN_080e48d0
_0814A094: .4byte 0x0000046B

	thumb_func_start FUN_0814a098
FUN_0814a098: @ 0x0814A098
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0814A0B8
	b _0814A30C
_0814A0B8:
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _0814A184 @ =0x00000469
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _0814A188 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r2, [r0]
	ldr r3, _0814A18C @ =FUN_080e6794
	movs r1, #0xe
	adds r7, #1
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _0814A190 @ =0x0000046B
	adds r0, r5, r2
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r7, #0
	strh r4, [r0]
	movs r3, #0x80
	mov ip, r3
	ldrh r0, [r6]
	ands r0, r3
	cmp r0, #0
	beq _0814A1A8
	ldr r4, _0814A194 @ =0x00000482
	adds r1, r5, r4
	movs r0, #2
	strh r0, [r1]
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0xc
	mov r8, r2
	movs r1, #0x14
	adds r4, #0xd6
	adds r2, r5, r4
	subs r4, #4
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _0814A198 @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _0814A19C @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	ldrh r0, [r6]
	mov r6, ip
	ands r0, r6
	cmp r0, #0
	beq _0814A174
	ldr r7, _0814A1A0 @ =0x0000024E
	adds r2, r5, r7
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0814A174
	strh r1, [r2]
_0814A174:
	movs r0, #4
	ldr r6, _0814A1A4 @ =0x00000222
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _0814A1EC
	.align 2, 0
_0814A184: .4byte 0x00000469
_0814A188: .4byte 0x0000046A
_0814A18C: .4byte FUN_080e6794
_0814A190: .4byte 0x0000046B
_0814A194: .4byte 0x00000482
_0814A198: .4byte 0x00000551
_0814A19C: .4byte 0x00000552
_0814A1A0: .4byte 0x0000024E
_0814A1A4: .4byte 0x00000222
_0814A1A8:
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _0814A228 @ =0x00000482
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r4, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _0814A22C @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _0814A230 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
_0814A1EC:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814A224
	cmp r1, #0
	blt _0814A224
	ldr r0, _0814A234 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814A224
	ldr r0, _0814A238 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814A23C
_0814A224:
	movs r4, #0
	b _0814A24A
	.align 2, 0
_0814A228: .4byte 0x00000482
_0814A22C: .4byte 0x00000551
_0814A230: .4byte 0x00000552
_0814A234: .4byte 0x030046A8
_0814A238: .4byte 0x030046AC
_0814A23C:
	ldr r0, _0814A25C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814A24A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814A260
	adds r0, #4
	b _0814A26C
	.align 2, 0
_0814A25C: .4byte 0x030046A4
_0814A260:
	ldr r0, _0814A280 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814A26C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814A284
	cmp r3, #2
	beq _0814A288
	b _0814A28C
	.align 2, 0
_0814A280: .4byte 0x030046A4
_0814A284:
	ldrb r0, [r6, #4]
	b _0814A28A
_0814A288:
	ldrb r0, [r6]
_0814A28A:
	subs r2, r2, r0
_0814A28C:
	movs r1, #0
	strh r2, [r6, #2]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	strh r1, [r0, #6]
	ldr r7, _0814A2C8 @ =0x000004A4
	adds r0, r5, r7
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0814A2CC
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	b _0814A2F2
	.align 2, 0
_0814A2C8: .4byte 0x000004A4
_0814A2CC:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0814A2EC
	cmp r0, #2
	beq _0814A2E8
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814A2E8:
	movs r0, #1
	b _0814A2FC
_0814A2EC:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
_0814A2F2:
	ldr r1, _0814A318 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814A2FC:
	cmp r0, #0
	bne _0814A30C
	ldr r4, _0814A31C @ =0x000005C4
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
_0814A30C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814A318: .4byte 0xFFFFFDFF
_0814A31C: .4byte 0x000005C4

	thumb_func_start enemy_dog_0814a320
enemy_dog_0814a320: @ 0x0814A320
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	subs r1, #0xcc
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814A340
	b _0814A5D6
_0814A340:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r5, r3
	adds r2, #0x68
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _0814A354
	b _0814A5B6
_0814A354:
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	subs r3, #0xc
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
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
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0814A3A0
	ldr r0, _0814A39C @ =0xFFFFFF00
	adds r1, r1, r0
	b _0814A3AE
	.align 2, 0
_0814A39C: .4byte 0xFFFFFF00
_0814A3A0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0814A3AE
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0814A3AE:
	adds r0, r1, #0
	cmp r0, #0
	bge _0814A3B6
	rsbs r0, r0, #0
_0814A3B6:
	adds r3, r0, #0
	cmp r3, #0x17
	ble _0814A3BE
	b _0814A594
_0814A3BE:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	bls _0814A3CE
	cmp r0, #4
	bne _0814A474
_0814A3CE:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r3, _0814A444 @ =0x000006AC
	adds r1, r6, r3
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0814A460
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _0814A460
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _0814A448 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0814A44C @ =0x0000046A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r1, _0814A450 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0814A454 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0814A458 @ =0x0000046B
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
	ldr r1, _0814A45C @ =0x082520E4
	adds r0, r5, #0
	movs r2, #0x6f
	bl FUN_080e6768
	b _0814A5D6
	.align 2, 0
_0814A444: .4byte 0x000006AC
_0814A448: .4byte 0x00000469
_0814A44C: .4byte 0x0000046A
_0814A450: .4byte 0x00000484
_0814A454: .4byte FUN_080e48d0
_0814A458: .4byte 0x0000046B
_0814A45C: .4byte 0x082520E4
_0814A460:
	movs r1, #8
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814A472
	b _0814A5A4
_0814A472:
	b _0814A5A8
_0814A474:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _0814A4E8 @ =0x000006AC
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0814A504
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _0814A504
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _0814A4EC @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _0814A4F0 @ =0x0000046A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r1, _0814A4F4 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _0814A4F8 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0814A4FC @ =0x0000046B
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
	ldr r1, _0814A500 @ =0x082520E4
	adds r0, r5, #0
	movs r2, #0x7c
	bl FUN_080e6768
	b _0814A5D6
	.align 2, 0
_0814A4E8: .4byte 0x000006AC
_0814A4EC: .4byte 0x00000469
_0814A4F0: .4byte 0x0000046A
_0814A4F4: .4byte 0x00000484
_0814A4F8: .4byte FUN_080e48d0
_0814A4FC: .4byte 0x0000046B
_0814A500: .4byte 0x082520E4
_0814A504:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _0814A460
	cmp r3, #5
	bgt _0814A460
	ldr r3, _0814A57C @ =0x000006CA
	adds r0, r6, r3
	ldrh r4, [r0]
	cmp r4, #0
	bne _0814A460
	movs r2, #2
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	ldr r3, _0814A580 @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _0814A584 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r3, _0814A588 @ =FUN_080e48d0
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0814A58C @ =0x0000046B
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
	ldr r1, _0814A590 @ =0x082520E4
	adds r0, r5, #0
	movs r2, #0x81
	bl FUN_080e6768
	b _0814A5D6
	.align 2, 0
_0814A57C: .4byte 0x000006CA
_0814A580: .4byte 0x00000469
_0814A584: .4byte 0x00000484
_0814A588: .4byte FUN_080e48d0
_0814A58C: .4byte 0x0000046B
_0814A590: .4byte 0x082520E4
_0814A594:
	movs r1, #8
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814A5A8
_0814A5A4:
	movs r0, #1
	b _0814A5AA
_0814A5A8:
	movs r0, #0
_0814A5AA:
	cmp r0, #0
	bne _0814A5D6
	adds r0, r5, #0
	bl enemy_dog_0814b500
	b _0814A5D6
_0814A5B6:
	movs r1, #8
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814A5CA
	movs r0, #1
	b _0814A5CC
_0814A5CA:
	movs r0, #0
_0814A5CC:
	cmp r0, #0
	bne _0814A5D6
	adds r0, r5, #0
	bl enemy_dog_0814b500
_0814A5D6:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0814a5e0
FUN_0814a5e0: @ 0x0814A5E0
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r7, r1, #0
	ldrb r0, [r3, #5]
	subs r1, r7, r0
	cmp r1, #0x80
	ble _0814A5F8
	ldr r0, _0814A5F4 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0814A606
	.align 2, 0
_0814A5F4: .4byte 0xFFFFFF00
_0814A5F8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0814A606
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0814A606:
	cmp r1, #0
	bge _0814A60C
	rsbs r1, r1, #0
_0814A60C:
	ldr r4, _0814A624 @ =0x000001FD
	adds r0, r3, r4
	ldrb r0, [r0]
	cmp r1, r0
	blt _0814A620
	ldr r5, _0814A628 @ =0x00000553
	adds r0, r3, r5
	ldrb r0, [r0]
	cmp r0, #2
	bne _0814A62C
_0814A620:
	movs r0, #0
	b _0814A6DA
	.align 2, 0
_0814A624: .4byte 0x000001FD
_0814A628: .4byte 0x00000553
_0814A62C:
	ldr r2, _0814A68C @ =FUN_080e48d0
	movs r1, #0x10
	ldr r4, _0814A690 @ =0x0000046D
	adds r0, r3, r4
	movs r5, #0
	movs r6, #1
	strb r6, [r0]
	subs r4, #2
	adds r0, r3, r4
	strb r5, [r0]
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
	movs r4, #0
	strh r5, [r0]
	movs r1, #0x80
	subs r2, #0x48
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0814A69C
	movs r1, #0xd
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r3, r2
	strb r4, [r0]
	adds r2, #1
	adds r0, r3, r2
	strb r4, [r0]
	ldr r4, _0814A694 @ =0x0000046A
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _0814A698 @ =0x00000484
	adds r0, r3, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r3, r2
	b _0814A6BC
	.align 2, 0
_0814A68C: .4byte FUN_080e48d0
_0814A690: .4byte 0x0000046D
_0814A694: .4byte 0x0000046A
_0814A698: .4byte 0x00000484
_0814A69C:
	movs r1, #6
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	strb r4, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r4, [r0]
	ldr r4, _0814A6E0 @ =0x0000046A
	adds r0, r3, r4
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r3, r5
	str r2, [r0]
	ldr r1, _0814A6E4 @ =0x0000046C
	adds r0, r3, r1
_0814A6BC:
	strb r6, [r0]
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r3, r2
	strb r1, [r0]
	movs r0, #1
_0814A6DA:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0814A6E0: .4byte 0x0000046A
_0814A6E4: .4byte 0x0000046C

	thumb_func_start FUN_0814a6e8
FUN_0814a6e8: @ 0x0814A6E8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xd
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #8
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #9
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0xa
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0xb
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xc
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0814a78c
FUN_0814a78c: @ 0x0814A78C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r0, r2
	movs r3, #0
	str r3, [r1]
	adds r2, #0x18
	adds r1, r0, r2
	movs r5, #0
	strh r3, [r1]
	movs r1, #0xda
	lsls r1, r1, #3
	adds r2, r0, r1
	ldr r1, _0814A814 @ =0x0000FFFF
	strh r1, [r2]
	ldr r2, _0814A818 @ =0x000006D4
	adds r1, r0, r2
	strh r3, [r1]
	adds r2, #2
	adds r1, r0, r2
	strb r5, [r1]
	adds r2, #1
	adds r1, r0, r2
	strb r5, [r1]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #8
	bl ClearMemory
	adds r0, r4, #0
	bl FUN_080e6204
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
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
	beq _0814A81C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0814A824
	.align 2, 0
_0814A814: .4byte 0x0000FFFF
_0814A818: .4byte 0x000006D4
_0814A81C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0814A824:
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
	beq _0814A848
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0814A850
_0814A848:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0814A850:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0814A888 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0814A8C0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0814A88C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0814A880
	ldrb r0, [r4, #5]
_0814A880:
	subs r0, #1
	strh r0, [r4, #8]
	b _0814A89C
	.align 2, 0
_0814A888: .4byte 0x0000FFFF
_0814A88C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0814A89C
	strh r1, [r4, #8]
_0814A89C:
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
	bne _0814A8C0
	movs r0, #1
	strb r0, [r4, #7]
_0814A8C0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0814a8c8
FUN_0814a8c8: @ 0x0814A8C8
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #3
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0814a8dc
FUN_0814a8dc: @ 0x0814A8DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	mov ip, r0
	ldr r0, [r0, #0x44]
	adds r0, #0x48
	mov sb, r0
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	beq _0814A8F8
	b _0814AAC0
_0814A8F8:
	movs r1, #0x80
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	mov sl, r0
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, #0xfc
	add r1, ip
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x90
	lsls r0, r0, #3
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #2
	beq _0814A92A
	b _0814AA86
_0814A92A:
	mov r1, sb
	ldrh r0, [r1, #8]
	cmp r0, #7
	beq _0814A93C
	cmp r0, #5
	beq _0814A93C
	cmp r0, #1
	beq _0814A93C
	b _0814AA86
_0814A93C:
	ldr r2, _0814A9D0 @ =0x0203B400
	mov r8, r2
	ldr r6, _0814A9D4 @ =0x030046B8
	ldr r2, [r6]
	adds r2, #1
	ldr r3, _0814A9D8 @ =0x000003FF
	ands r2, r3
	lsls r0, r2, #1
	add r0, r8
	ldrh r1, [r0]
	movs r4, #0x3f
	ands r1, r4
	subs r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _0814A9DC @ =0xFFFF0000
	ldr r0, [sp, #0x3c]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x3c]
	adds r2, #1
	ands r2, r3
	str r2, [r6]
	lsls r2, r2, #1
	add r2, r8
	ldrh r1, [r2]
	ands r1, r4
	subs r1, #0x30
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0x3c
	ldr r0, [r2, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r2, #4]
	mov r1, ip
	adds r1, #8
	ldrh r0, [r2]
	mov r3, ip
	ldrh r3, [r3, #8]
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r2, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov r1, ip
	ldrb r0, [r1, #5]
	adds r4, r0, #0
	adds r4, #0x80
	movs r1, #0xff
	add r6, sp, #0x44
	ands r4, r1
	movs r5, #0x50
	ldr r3, _0814A9E0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r7, r2, #0
	mov r8, r6
	cmp r0, #0
	blt _0814A9E4
	asrs r1, r0, #0xc
	b _0814A9EA
	.align 2, 0
_0814A9D0: .4byte 0x0203B400
_0814A9D4: .4byte 0x030046B8
_0814A9D8: .4byte 0x000003FF
_0814A9DC: .4byte 0xFFFF0000
_0814A9E0: .4byte 0x085B0A08
_0814A9E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814A9EA:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	lsls r0, r4, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _0814AA02
	asrs r0, r0, #0xc
	b _0814AA08
_0814AA02:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814AA08:
	movs r5, #0
	strh r0, [r6, #4]
	add r2, sp, #0x44
	add r1, sp, #0x3c
	ldrh r0, [r1]
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r7, #4]
	mov r3, r8
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
	mov r4, ip
	ldrh r0, [r4, #0xa]
	strh r0, [r7, #2]
	add r6, sp, #0x4c
	str r5, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r6, #0
	ldr r2, _0814AAA0 @ =0x05000002
	bl CpuSet
	ldr r2, _0814AAA4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0814AAA8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0814AAAC @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x14
	ldr r2, _0814AAB0 @ =0x00001C1A
	ldr r3, _0814AAB4 @ =0x0000D1B8
	movs r0, #3
	str r0, [sp]
	str r5, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	movs r4, #1
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	str r5, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	str r4, [sp, #0x24]
	ldr r0, _0814AAB8 @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_081f22c0
_0814AA86:
	ldr r2, _0814AABC @ =0x085AD8C0
	mov r3, sb
	ldrh r1, [r3, #8]
	movs r0, #7
	ands r0, r1
	lsls r0, r0, #1
	mov r4, sl
	lsls r1, r4, #4
	adds r0, r0, r1
	adds r0, r0, r2
	ldrh r0, [r0]
	b _0814AAC2
	.align 2, 0
_0814AAA0: .4byte 0x05000002
_0814AAA4: .4byte 0x030046B8
_0814AAA8: .4byte 0x000003FF
_0814AAAC: .4byte 0x0203B400
_0814AAB0: .4byte 0x00001C1A
_0814AAB4: .4byte 0x0000D1B8
_0814AAB8: .4byte 0x00200004
_0814AABC: .4byte 0x085AD8C0
_0814AAC0:
	movs r0, #0
_0814AAC2:
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0814aad4
FUN_0814aad4: @ 0x0814AAD4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa0
	lsls r1, r1, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814AAF8
	adds r0, r4, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	b _0814AB04
_0814AAF8:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
_0814AB04:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814AB1E
	ldr r0, _0814AB24 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
_0814AB1E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0814AB24: .4byte 0x00000482

	thumb_func_start FUN_0814ab28
FUN_0814ab28: @ 0x0814AB28
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #0x3c
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r4, _0814ABFC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r4
	movs r6, #0x40
	orrs r0, r6
	ldr r2, _0814AC00 @ =0x0000FFFF
	mov sl, r2
	ands r0, r2
	movs r1, #0x80
	lsls r1, r1, #0x10
	mov r8, r1
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	orrs r0, r6
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r2, sp, #0x14
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _0814AC04 @ =FUN_0814bbc4
	str r5, [sp]
	adds r0, r5, #0
	add r1, sp, #0xc
	bl FUN_080e3834
	ldr r0, [sp, #0x1c]
	ands r0, r4
	orrs r0, r6
	mov r2, sl
	ands r0, r2
	movs r1, #0xf0
	lsls r1, r1, #0xf
	mov sl, r1
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r6
	str r0, [r1, #4]
	mov r2, r8
	str r2, [sp, #0x24]
	add r2, sp, #0x24
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _0814AC08 @ =FUN_0814b85c
	movs r0, #0
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	bl FUN_080e3984
	mov r0, sl
	str r0, [sp, #0x2c]
	add r2, sp, #0x2c
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	mov r1, r8
	str r1, [sp, #0x34]
	add r3, sp, #0x34
	ldr r0, [r3, #4]
	ands r0, r4
	str r0, [r3, #4]
	movs r0, #0xcb
	lsls r0, r0, #3
	add sb, r0
	ldr r0, _0814AC0C @ =FUN_0814b89c
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r5, [sp, #8]
	adds r0, r5, #0
	mov r1, sb
	bl FUN_080e3a14
	movs r0, #0x80
	lsls r0, r0, #1
	mov r2, sb
	ldrh r1, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
	add sp, #0x3c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814ABFC: .4byte 0xFFFF0000
_0814AC00: .4byte 0x0000FFFF
_0814AC04: .4byte FUN_0814bbc4
_0814AC08: .4byte FUN_0814b85c
_0814AC0C: .4byte FUN_0814b89c

	thumb_func_start FUN_0814ac10
FUN_0814ac10: @ 0x0814AC10
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814AC2C
	b _0814AE78
_0814AC2C:
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r0, [r5, #5]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0814AC46
	asrs r0, r1, #6
	b _0814AC4C
_0814AC46:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0814AC4C:
	lsls r4, r0, #6
	movs r2, #2
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _0814AC64
	movs r0, #1
	b _0814AC66
_0814AC64:
	movs r0, #0
_0814AC66:
	cmp r0, #0
	beq _0814ACC0
	ldr r2, _0814AC88 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	adds r3, r2, #0
	cmp r0, #0
	blt _0814AC8C
	asrs r2, r0, #0xc
	b _0814AC92
	.align 2, 0
_0814AC88: .4byte 0x085B0A08
_0814AC8C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0814AC92:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814ACBC @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	cmp r0, #0
	bge _0814AD10
	b _0814AD18
	.align 2, 0
_0814ACBC: .4byte 0xFFFF0000
_0814ACC0:
	ldr r2, _0814ACE0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	adds r3, r2, #0
	cmp r0, #0
	blt _0814ACE4
	asrs r2, r0, #0xc
	b _0814ACEA
	.align 2, 0
_0814ACE0: .4byte 0x085B0A08
_0814ACE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0814ACEA:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814AD14 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _0814AD18
_0814AD10:
	asrs r2, r0, #0xc
	b _0814AD1E
	.align 2, 0
_0814AD14: .4byte 0xFFFF0000
_0814AD18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0814AD1E:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814AD58 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _0814AD5C @ =0x0000069A
	adds r0, r6, r1
	strb r4, [r0]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	cmp r4, #0
	blt _0814AD60
	asrs r0, r4, #6
	b _0814AD66
	.align 2, 0
_0814AD58: .4byte 0xFFFF0000
_0814AD5C: .4byte 0x0000069A
_0814AD60:
	rsbs r0, r4, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0814AD66:
	cmp r0, #1
	beq _0814ADC4
	cmp r0, #1
	bgt _0814AD74
	cmp r0, #0
	beq _0814AD7E
	b _0814AE08
_0814AD74:
	cmp r0, #2
	beq _0814AD7E
	cmp r0, #3
	beq _0814ADC4
	b _0814AE08
_0814AD7E:
	movs r1, #2
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0814AD8C
	movs r0, #1
	b _0814AD8E
_0814AD8C:
	movs r0, #0
_0814AD8E:
	cmp r0, #0
	beq _0814ADAA
	ldr r3, _0814ADC0 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0xf0
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x80
	orrs r0, r1
	str r0, [r2, #4]
_0814ADAA:
	ldr r3, _0814ADC0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r1, #0x78
	orrs r0, r1
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _0814AE04
	.align 2, 0
_0814ADC0: .4byte 0xFFFF0000
_0814ADC4:
	movs r1, #2
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0814ADD2
	movs r0, #1
	b _0814ADD4
_0814ADD2:
	movs r0, #0
_0814ADD4:
	cmp r0, #0
	beq _0814ADF0
	ldr r3, _0814AE50 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r1, #0x80
	orrs r0, r1
	str r0, [sp, #8]
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0xf0
	orrs r0, r1
	str r0, [r2, #4]
_0814ADF0:
	ldr r3, _0814AE50 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x78
_0814AE04:
	orrs r0, r1
	str r0, [r2, #4]
_0814AE08:
	ldr r1, _0814AE54 @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	adds r0, #0xd8
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	str r1, [r0, #0x1c]
	str r2, [r0, #0x20]
	mov r1, sp
	movs r2, #0
	bl FUN_082364c4
	movs r1, #2
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _0814AE58
	movs r0, #1
	b _0814AE5A
	.align 2, 0
_0814AE50: .4byte 0xFFFF0000
_0814AE54: .4byte 0x0000FFFF
_0814AE58:
	movs r0, #0
_0814AE5A:
	cmp r0, #0
	beq _0814AE6A
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	b _0814AE74
_0814AE6A:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r6, r1
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
_0814AE74:
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
_0814AE78:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0814ae80
FUN_0814ae80: @ 0x0814AE80
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r2, [r0]
	movs r0, #0xd9
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0814AE9A
	subs r0, #1
	strh r0, [r1]
_0814AE9A:
	ldr r0, _0814AEAC @ =0x000006CA
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0814AEA8
	subs r0, #1
	strh r0, [r1]
_0814AEA8:
	pop {r0}
	bx r0
	.align 2, 0
_0814AEAC: .4byte 0x000006CA

	thumb_func_start FUN_0814aeb0
FUN_0814aeb0: @ 0x0814AEB0
	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _0814AECC @ =0x000006C6
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0814AEC8
	subs r0, #1
	strh r0, [r1]
_0814AEC8:
	pop {r0}
	bx r0
	.align 2, 0
_0814AECC: .4byte 0x000006C6

	thumb_func_start FUN_0814aed0
FUN_0814aed0: @ 0x0814AED0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814AFB8
	ldr r0, _0814AF24 @ =0x0000E33F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r2, [r1]
	ands r0, r2
	cmp r0, #0
	bne _0814AFB8
	movs r1, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0814AFB8
	ldr r1, _0814AF28 @ =0x00000553
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _0814AFB8
	movs r3, #0xd8
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r0, [r1]
	cmp r0, #0
	beq _0814AF2C
	subs r0, #1
	strh r0, [r1]
	b _0814AFB8
	.align 2, 0
_0814AF24: .4byte 0x0000E33F
_0814AF28: .4byte 0x00000553
_0814AF2C:
	movs r0, #0x80
	ands r2, r0
	cmp r2, #0
	beq _0814AF40
	ldr r2, _0814AF3C @ =0x000006C4
	adds r0, r5, r2
	b _0814AF44
	.align 2, 0
_0814AF3C: .4byte 0x000006C4
_0814AF40:
	ldr r3, _0814AF70 @ =0x000006C2
	adds r0, r5, r3
_0814AF44:
	ldrh r0, [r0]
	strh r0, [r1]
	movs r2, #1
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r0, r3
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _0814AF74
	movs r0, #1
	b _0814AF76
	.align 2, 0
_0814AF70: .4byte 0x000006C2
_0814AF74:
	movs r0, #0
_0814AF76:
	cmp r0, #0
	beq _0814AFB8
	movs r2, #0xf
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0814AFC0 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0814AFC4 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #2
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0814AFB8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814AFC0: .4byte 0x00000469
_0814AFC4: .4byte 0x00000484

	thumb_func_start FUN_0814afc8
FUN_0814afc8: @ 0x0814AFC8
	push {lr}
	sub sp, #0x30
	adds r2, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0xc
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0814B078
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r1, [r0]
	adds r3, #0x1c
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0814B078
	movs r3, #8
	ldrsh r0, [r2, r3]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r2, r3]
	str r0, [sp, #4]
	movs r3, #0xc
	ldrsh r0, [r2, r3]
	str r0, [sp, #8]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0xc]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r3, #0xda
	lsls r3, r3, #3
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _0814B034
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x18]
	b _0814B046
_0814B034:
	ldr r3, _0814B080 @ =0x000006D2
	adds r0, r1, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #0x18]
	ldr r3, _0814B084 @ =0x000006D4
	adds r0, r1, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
_0814B046:
	str r0, [sp, #0x1c]
	ldr r3, _0814B088 @ =0x000001DF
	adds r0, r2, r3
	ldrb r0, [r0]
	str r0, [sp, #0x20]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	str r0, [sp, #0x24]
	ldr r1, _0814B08C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r1, #0xa
	orrs r0, r1
	str r0, [sp, #0x28]
	add r1, sp, #0x28
	mov r3, sp
	str r3, [r1, #4]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	bl Script_ExecById
_0814B078:
	add sp, #0x30
	pop {r0}
	bx r0
	.align 2, 0
_0814B080: .4byte 0x000006D2
_0814B084: .4byte 0x000006D4
_0814B088: .4byte 0x000001DF
_0814B08C: .4byte 0xFFFF0000

	thumb_func_start FUN_0814b090
FUN_0814b090: @ 0x0814B090
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sb, r0
	str r1, [sp, #8]
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sb
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r1, _0814B0D4 @ =0x00000256
	add r1, sb
	str r1, [sp, #0x14]
	mov r2, sb
	adds r2, #8
	str r2, [sp, #0x1c]
	str r2, [sp, #0x18]
	ldr r0, _0814B0D8 @ =0x030046A4
	mov sl, r0
_0814B0C0:
	ldr r1, [sp, #0x14]
	ldrh r6, [r1]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814B0DC
	adds r0, #4
	b _0814B0E8
	.align 2, 0
_0814B0D4: .4byte 0x00000256
_0814B0D8: .4byte 0x030046A4
_0814B0DC:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814B0E8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814B0FC
	cmp r3, #2
	beq _0814B102
	b _0814B108
_0814B0FC:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1, #4]
	b _0814B106
_0814B102:
	ldr r1, [sp, #0x18]
	ldrb r0, [r1]
_0814B106:
	subs r2, r2, r0
_0814B108:
	mov r8, r2
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814B11A
	adds r0, #4
	b _0814B126
_0814B11A:
	mov r2, sl
	ldr r0, [r2]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814B126:
	ldrb r0, [r0]
	lsrs r7, r0, #4
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x20
	cmp r0, #0
	blt _0814B138
	asrs r0, r0, #6
	b _0814B13E
_0814B138:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0814B13E:
	movs r1, #3
	ands r1, r0
	cmp r1, #1
	beq _0814B17C
	cmp r1, #1
	bgt _0814B150
	cmp r1, #0
	beq _0814B15A
	b _0814B230
_0814B150:
	cmp r1, #2
	beq _0814B1B8
	cmp r1, #3
	beq _0814B1DA
	b _0814B230
_0814B15A:
	adds r4, r6, #1
	movs r5, #0
_0814B15E:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814B178
	adds r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0814B15E
_0814B178:
	subs r5, r4, #1
	b _0814B234
_0814B17C:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r6, r0
	movs r5, #0
_0814B18A:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814B214
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _0814B18A
	ldr r2, _0814B1B4 @ =0x030046A4
	b _0814B216
	.align 2, 0
_0814B1B4: .4byte 0x030046A4
_0814B1B8:
	subs r4, r6, #1
	movs r5, #0
_0814B1BC:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814B1D6
	subs r4, #1
	adds r5, #1
	cmp r5, #1
	blt _0814B1BC
_0814B1D6:
	adds r5, r4, #1
	b _0814B234
_0814B1DA:
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r6, r0
	movs r5, #0
_0814B1E8:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_080e8038
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814B222
	mov r2, sl
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	adds r5, #1
	cmp r5, #1
	blt _0814B1E8
	ldr r2, _0814B210 @ =0x030046A4
	b _0814B224
	.align 2, 0
_0814B210: .4byte 0x030046A4
_0814B214:
	mov r2, sl
_0814B216:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r5, r4, r0
	b _0814B234
_0814B222:
	mov r2, sl
_0814B224:
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r4, r0
	b _0814B234
_0814B230:
	ldr r2, [sp, #0x14]
	ldrh r5, [r2]
_0814B234:
	ldr r0, [sp, #0x14]
	ldrh r0, [r0]
	cmp r5, r0
	bne _0814B270
	ldr r1, [sp, #0xc]
	ldr r2, _0814B258 @ =0x000006D6
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0814B25C
	mov r1, sb
	ldrb r0, [r1, #5]
	adds r0, #0x40
	strb r0, [r1, #5]
	b _0814B264
	.align 2, 0
_0814B258: .4byte 0x000006D6
_0814B25C:
	mov r2, sb
	ldrb r0, [r2, #5]
	subs r0, #0x40
	strb r0, [r2, #5]
_0814B264:
	ldr r0, [sp, #0x10]
	adds r0, #1
	str r0, [sp, #0x10]
	cmp r0, #3
	bgt _0814B270
	b _0814B0C0
_0814B270:
	ldr r2, _0814B294 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0814B298 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0814B29C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _0814B2A4
	ldr r2, [sp, #0xc]
	ldr r0, _0814B2A0 @ =0x000006D6
	adds r1, r2, r0
	movs r0, #1
	b _0814B2AC
	.align 2, 0
_0814B294: .4byte 0x030046B8
_0814B298: .4byte 0x000003FF
_0814B29C: .4byte 0x0203B400
_0814B2A0: .4byte 0x000006D6
_0814B2A4:
	ldr r2, [sp, #0xc]
	ldr r0, _0814B2F4 @ =0x000006D6
	adds r1, r2, r0
	movs r0, #0
_0814B2AC:
	strb r0, [r1]
	mov r1, sp
	ldrb r2, [r1, #8]
	mov r1, sb
	strb r2, [r1, #5]
	mov r8, sp
	ldr r6, _0814B2F8 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814B2FC
	adds r0, #4
	b _0814B306
	.align 2, 0
_0814B2F4: .4byte 0x000006D6
_0814B2F8: .4byte 0x030046A4
_0814B2FC:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814B306:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, _0814B34C @ =0x000004A4
	add r0, sb
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _0814B350
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0814B350
	cmp r0, #2
	beq _0814B348
	mov r0, sb
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814B348:
	movs r0, #1
	b _0814B360
	.align 2, 0
_0814B34C: .4byte 0x000004A4
_0814B350:
	movs r0, #0xc0
	lsls r0, r0, #1
	add r0, sb
	ldr r1, _0814B374 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814B360:
	cmp r0, #0
	beq _0814B37C
	ldr r2, [sp, #0xc]
	ldr r0, _0814B378 @ =0x000006D7
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #1
	b _0814B38A
	.align 2, 0
_0814B374: .4byte 0xFFFFFDFF
_0814B378: .4byte 0x000006D7
_0814B37C:
	ldr r0, _0814B39C @ =0x000005C4
	add r0, sb
	ldr r1, [r0]
	mov r0, sb
	bl _call_via_r1
	movs r0, #0
_0814B38A:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0814B39C: .4byte 0x000005C4

	thumb_func_start FUN_0814b3a0
FUN_0814b3a0: @ 0x0814B3A0
	push {lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	bls _0814B3BA
	cmp r0, #4
	bne _0814B3C0
_0814B3BA:
	movs r2, #0xd9
	lsls r2, r2, #3
	b _0814B3CE
_0814B3C0:
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _0814B3D6
	adds r2, #2
_0814B3CE:
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0814B3DA
_0814B3D6:
	movs r0, #1
	b _0814B3DC
_0814B3DA:
	movs r0, #0
_0814B3DC:
	pop {r1}
	bx r1

	thumb_func_start FUN_0814b3e0
FUN_0814b3e0: @ 0x0814B3E0
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xea
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	ble _0814B4DC
	adds r0, r5, #0
	bl FUN_080f00ec
	ldr r1, _0814B45C @ =0x00000222
	adds r2, r5, r1
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r4]
	bl FUN_080f8d60
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	ldrh r1, [r0, #8]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814B456
	cmp r1, #0
	blt _0814B456
	ldr r0, _0814B460 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814B456
	ldr r0, _0814B464 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814B468
_0814B456:
	movs r1, #0
	b _0814B476
	.align 2, 0
_0814B45C: .4byte 0x00000222
_0814B460: .4byte 0x030046A8
_0814B464: .4byte 0x030046AC
_0814B468:
	ldr r0, _0814B4D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_0814B476:
	ldr r3, _0814B4D8 @ =0x0000025E
	adds r0, r5, r3
	strh r1, [r0]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
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
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	strb r0, [r5, #5]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #0xd
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #1
	b _0814B4F4
	.align 2, 0
_0814B4D4: .4byte 0x030046A4
_0814B4D8: .4byte 0x0000025E
_0814B4DC:
	movs r0, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, [r1]
	ands r0, r3
	cmp r0, #0
	beq _0814B4F2
	ldr r0, _0814B4FC @ =0xF7FFFFFF
	ands r3, r0
	str r3, [r1]
_0814B4F2:
	movs r0, #0
_0814B4F4:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0814B4FC: .4byte 0xF7FFFFFF

	thumb_func_start enemy_dog_0814b500
enemy_dog_0814b500: @ 0x0814B500
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r1, _0814B5B4 @ =0x082520E4
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, #0
	bl FUN_080e6768
	ldr r2, _0814B5B8 @ =0x000006D7
	adds r6, r4, r2
	ldrb r0, [r6]
	cmp r0, #3
	bls _0814B524
	b _0814B728
_0814B524:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _0814B544
	adds r0, r5, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814B5CC
_0814B544:
	ldrb r0, [r6]
	cmp r0, #3
	bhi _0814B5CC
	ldrb r1, [r5, #5]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #0x80
	movs r4, #0
	strb r0, [r5, #5]
	adds r0, r5, #0
	bl FUN_0814b090
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814B568
	b _0814B774
_0814B568:
	ldr r2, _0814B5BC @ =FUN_080e48d0
	movs r1, #0x10
	ldr r6, _0814B5C0 @ =0x0000046D
	adds r0, r5, r6
	movs r3, #1
	strb r3, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #0x11
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0814B5C4 @ =0x0000046A
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0814B5C8 @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _0814B774
	.align 2, 0
_0814B5B4: .4byte 0x082520E4
_0814B5B8: .4byte 0x000006D7
_0814B5BC: .4byte FUN_080e48d0
_0814B5C0: .4byte 0x0000046D
_0814B5C4: .4byte 0x0000046A
_0814B5C8: .4byte 0x00000484
_0814B5CC:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _0814B614 @ =0x000006BC
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _0814B5E0
	b _0814B728
_0814B5E0:
	ldr r3, _0814B618 @ =0x00000553
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0x1a
	bne _0814B5EC
	b _0814B774
_0814B5EC:
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r0, [r0]
	ldr r1, _0814B61C @ =0x00FFFFFF
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xc
	cmp r0, r1
	bne _0814B602
	b _0814B774
_0814B602:
	ldr r0, _0814B620 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814B624
	movs r0, #1
	b _0814B626
	.align 2, 0
_0814B614: .4byte 0x000006BC
_0814B618: .4byte 0x00000553
_0814B61C: .4byte 0x00FFFFFF
_0814B620: .4byte 0x030047A4
_0814B624:
	movs r0, #0
_0814B626:
	cmp r0, #0
	beq _0814B63A
	adds r0, r5, #0
	bl FUN_080faa98
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814B638
	b _0814B774
_0814B638:
	b _0814B648
_0814B63A:
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _0814B674 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_0814B648:
	ldr r1, _0814B678 @ =0x000004A4
	adds r0, r5, r1
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0814B67C
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _0814B6A2
	.align 2, 0
_0814B674: .4byte 0x03002BE0
_0814B678: .4byte 0x000004A4
_0814B67C:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0814B69C
	cmp r0, #2
	beq _0814B698
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814B698:
	movs r0, #1
	b _0814B6AC
_0814B69C:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
_0814B6A2:
	ldr r1, _0814B6C0 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814B6AC:
	cmp r0, #0
	bne _0814B6C8
	ldr r1, _0814B6C4 @ =0x000005C4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _0814B774
	.align 2, 0
_0814B6C0: .4byte 0xFFFFFDFF
_0814B6C4: .4byte 0x000005C4
_0814B6C8:
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _0814B71C @ =0x0000046D
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
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0814B720 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _0814B724 @ =0x00000484
	adds r0, r5, r3
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	b _0814B774
	.align 2, 0
_0814B71C: .4byte 0x0000046D
_0814B720: .4byte 0x0000046A
_0814B724: .4byte 0x00000484
_0814B728:
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0
	strb r2, [r0]
	ldr r6, _0814B77C @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _0814B780 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _0814B784 @ =FUN_0814e424
	movs r2, #0x2a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0814B788 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
_0814B774:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814B77C: .4byte 0x00000469
_0814B780: .4byte 0x0000046A
_0814B784: .4byte FUN_0814e424
_0814B788: .4byte 0x0000046B

	thumb_func_start FUN_0814b78c
FUN_0814b78c: @ 0x0814B78C
	push {lr}
	movs r2, #0xdb
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814B79E
	subs r0, #1
	strb r0, [r1]
_0814B79E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0814b7a4
FUN_0814b7a4: @ 0x0814B7A4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov ip, r0
	ldr r4, _0814B7EC @ =0x0203B400
	ldr r3, _0814B7F0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0814B7F4 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r4, [r0]
	movs r0, #0x1f
	add r6, sp, #4
	ands r4, r0
	ldr r1, _0814B7F8 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0814B7FC
	asrs r2, r0, #0xc
	b _0814B802
	.align 2, 0
_0814B7EC: .4byte 0x0203B400
_0814B7F0: .4byte 0x030046B8
_0814B7F4: .4byte 0x000003FF
_0814B7F8: .4byte 0x085B0A08
_0814B7FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0814B802:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _0814B81A
	asrs r0, r0, #0xc
	b _0814B820
_0814B81A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814B820:
	strh r0, [r6, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0814B854 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0814B858 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x30
	add r1, sp, #4
	strh r0, [r1, #2]
	movs r0, #3
	str r0, [sp]
	mov r0, ip
	movs r2, #0x3c
	movs r3, #3
	bl FUN_081ee090
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814B854: .4byte 0x000003FF
_0814B858: .4byte 0x0203B400

	thumb_func_start FUN_0814b85c
FUN_0814b85c: @ 0x0814B85C
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814B890
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0814B890
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _0814B898 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0814B890:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814B898: .4byte 0xFEFFFFFF

	thumb_func_start FUN_0814b89c
FUN_0814b89c: @ 0x0814B89C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x28
	mov sb, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r6, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814B8C6
	b _0814BBB6
_0814B8C6:
	mov r2, sb
	ldr r0, [r2, #0x24]
	ldr r1, [r2, #0x28]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrb r0, [r6, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _0814B900
	cmp r0, #1
	bgt _0814B8E8
	cmp r0, #0
	beq _0814B8F2
	b _0814B948
_0814B8E8:
	cmp r0, #2
	beq _0814B910
	cmp r0, #3
	beq _0814B930
	b _0814B948
_0814B8F2:
	add r0, sp, #0x10
	ldrh r1, [r0]
	ldr r3, _0814B8FC @ =0xFFFFFF00
	adds r1, r1, r3
	b _0814B91A
	.align 2, 0
_0814B8FC: .4byte 0xFFFFFF00
_0814B900:
	add r0, sp, #0x10
	ldrh r1, [r0, #4]
	ldr r0, _0814B90C @ =0xFFFFFF00
	adds r1, r1, r0
	b _0814B93A
	.align 2, 0
_0814B90C: .4byte 0xFFFFFF00
_0814B910:
	add r0, sp, #0x10
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_0814B91A:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814B92C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	b _0814B948
	.align 2, 0
_0814B92C: .4byte 0xFFFF0000
_0814B930:
	add r0, sp, #0x10
	ldrh r1, [r0, #4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_0814B93A:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814B9BC @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
_0814B948:
	add r2, sp, #0x18
	add r4, sp, #0x10
	adds r3, r5, #0
	adds r3, #0x24
	ldrh r0, [r5, #0x24]
	adds r1, r4, #0
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	mov r1, sb
	adds r1, #0x42
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814B9AA
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0814B9AA
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, _0814B9C0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0814B9AA:
	ldr r0, _0814B9C4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814B9C8
	movs r0, #1
	b _0814B9CA
	.align 2, 0
_0814B9BC: .4byte 0xFFFF0000
_0814B9C0: .4byte 0xFEFFFFFF
_0814B9C4: .4byte 0x030047A4
_0814B9C8:
	movs r0, #0
_0814B9CA:
	cmp r0, #0
	beq _0814B9D0
	b _0814BBB6
_0814B9D0:
	ldrh r0, [r5, #0xa]
	cmp r0, #1
	beq _0814B9D8
	b _0814BBB6
_0814B9D8:
	movs r5, #0xda
	lsls r5, r5, #3
	add r5, r8
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0
	blt _0814B9E8
	b _0814BBB6
_0814B9E8:
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0814B9FA
	cmp r0, #4
	beq _0814B9FA
	b _0814BBB6
_0814B9FA:
	ldr r0, _0814BA5C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r2, [sp, #0x20]
	asrs r1, r2, #0x10
	adds r1, #0xc8
	lsls r1, r1, #0x10
	ldr r0, _0814BA60 @ =0x0000FFFF
	mov sb, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r4, _0814BA64 @ =0x000006D2
	add r4, r8
	ldr r2, _0814BA68 @ =0x000006D4
	add r2, r8
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080ec438
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814BA30
	b _0814BBB6
_0814BA30:
	movs r2, #0
	ldrsh r1, [r4, r2]
	add r0, sp, #0x20
	str r0, [sp]
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	movs r0, #0
	movs r2, #3
	movs r3, #0
	bl FUN_080177b4
	cmp r0, #0
	bge _0814BA6C
	ldrh r1, [r5]
	mov r0, sb
	orrs r0, r1
	strh r0, [r5]
	b _0814BBB6
	.align 2, 0
_0814BA5C: .4byte 0x03002BE0
_0814BA60: .4byte 0x0000FFFF
_0814BA64: .4byte 0x000006D2
_0814BA68: .4byte 0x000006D4
_0814BA6C:
	movs r3, #0
	ldrsh r0, [r5, r3]
	bl RemoveItem
	movs r0, #0
	ldrsh r1, [r4, r0]
	cmp r1, #0xb
	beq _0814BA90
	cmp r1, #0xb
	bgt _0814BA86
	cmp r1, #8
	beq _0814BA90
	b _0814BBB6
_0814BA86:
	cmp r1, #0xe
	beq _0814BA90
	cmp r1, #0x11
	beq _0814BA90
	b _0814BBB6
_0814BA90:
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r0, _0814BAC0 @ =0x000006D9
	add r0, r8
	ldrb r0, [r0]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, r0, r1
	cmp r0, #0
	bgt _0814BAC8
	ldrh r1, [r2]
	ldr r2, _0814BAC4 @ =0x0000048A
	adds r0, r6, r2
	b _0814BACC
	.align 2, 0
_0814BAC0: .4byte 0x000006D9
_0814BAC4: .4byte 0x0000048A
_0814BAC8:
	ldr r3, _0814BB48 @ =0x0000048A
	adds r0, r6, r3
_0814BACC:
	strh r1, [r0]
	movs r1, #0xda
	lsls r1, r1, #3
	add r1, r8
	ldr r0, _0814BB4C @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r4, _0814BB50 @ =0x03002BE0
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r3, #1
	str r3, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r1, #0
	str r1, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	subs r2, #4
	adds r0, r6, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	ldr r1, _0814BB48 @ =0x0000048A
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #1
	strh r3, [r0]
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0x1e
	strh r0, [r1]
	ldr r1, _0814BB54 @ =0x0000048C
	adds r0, r6, r1
	strb r2, [r0]
	movs r1, #2
	ldr r2, _0814BB58 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814BB5C
	movs r0, #1
	b _0814BB5E
	.align 2, 0
_0814BB48: .4byte 0x0000048A
_0814BB4C: .4byte 0x0000FFFF
_0814BB50: .4byte 0x03002BE0
_0814BB54: .4byte 0x0000048C
_0814BB58: .4byte 0x00000474
_0814BB5C:
	movs r0, #0
_0814BB5E:
	cmp r0, #0
	beq _0814BB72
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0814BB7E
_0814BB72:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0814BBB6
_0814BB7E:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
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
_0814BBB6:
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0814bbc4
FUN_0814bbc4: @ 0x0814BBC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r0, #6]
	ands r0, r1
	cmp r0, #0
	beq _0814BBE4
	b _0814C278
_0814BBE4:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0814BBF4
	b _0814C278
_0814BBF4:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0814BC1C
	ldr r3, _0814BC18 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814BC0C
	b _0814C278
_0814BC0C:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _0814C278
	.align 2, 0
_0814BC18: .4byte 0x0000048C
_0814BC1C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0814BC2C
	b _0814C278
_0814BC2C:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0814BC3C
	b _0814BF48
_0814BC3C:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _0814BC4E
	b _0814C278
_0814BC4E:
	ldr r2, _0814BCE0 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0814BC62
	b _0814C278
_0814BC62:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0814BC70
	b _0814C278
_0814BC70:
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
	bne _0814BC88
	b _0814BDD0
_0814BC88:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _0814BCF0
	ands r3, r1
	cmp r3, #0
	beq _0814BCF0
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0814BCAE
	rsbs r1, r1, #0
_0814BCAE:
	cmp r1, #0x20
	bgt _0814BCF0
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _0814BCE4 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _0814BCE8 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0814BCEC @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0814C278
	.align 2, 0
_0814BCE0: .4byte 0x0000A007
_0814BCE4: .4byte 0x000004BE
_0814BCE8: .4byte 0x0000048C
_0814BCEC: .4byte 0x0000044E
_0814BCF0:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _0814BD18 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0814BD20
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0814BD1C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0814BD8E
	.align 2, 0
_0814BD18: .4byte 0x0000048A
_0814BD1C: .4byte 0x03002BE0
_0814BD20:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0814BD3C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0814BD38 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0814BD8E
	.align 2, 0
_0814BD38: .4byte 0x03002BE0
_0814BD3C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0814BD58
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0814BD54 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0814BD8E
	.align 2, 0
_0814BD54: .4byte 0x03002BE0
_0814BD58:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0814BD74
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0814BD70 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0814BD8E
	.align 2, 0
_0814BD70: .4byte 0x03002BE0
_0814BD74:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0814BD86
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0814BD8E
_0814BD86:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0814BD90
_0814BD8E:
	movs r3, #1
_0814BD90:
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
	ldr r5, _0814BDC4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0814BDB2
	b _0814BF08
_0814BDB2:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814BDC8
	movs r0, #1
	b _0814BDCA
	.align 2, 0
_0814BDC4: .4byte 0x0000049C
_0814BDC8:
	movs r0, #0
_0814BDCA:
	cmp r0, #0
	bne _0814BEAE
	b _0814BEC4
_0814BDD0:
	strh r2, [r7, #0x3e]
	ldr r1, _0814BDF8 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0814BE00
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0814BDFC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0814BE6E
	.align 2, 0
_0814BDF8: .4byte 0x0000048A
_0814BDFC: .4byte 0x03002BE0
_0814BE00:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0814BE1C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0814BE18 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0814BE6E
	.align 2, 0
_0814BE18: .4byte 0x03002BE0
_0814BE1C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0814BE38
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0814BE34 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0814BE6E
	.align 2, 0
_0814BE34: .4byte 0x03002BE0
_0814BE38:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0814BE54
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0814BE50 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0814BE6E
	.align 2, 0
_0814BE50: .4byte 0x03002BE0
_0814BE54:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0814BE66
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0814BE6E
_0814BE66:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0814BE70
_0814BE6E:
	movs r3, #1
_0814BE70:
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
	ldr r5, _0814BEA4 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _0814BF08
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814BEA8
	movs r0, #1
	b _0814BEAA
	.align 2, 0
_0814BEA4: .4byte 0x0000049C
_0814BEA8:
	movs r0, #0
_0814BEAA:
	cmp r0, #0
	beq _0814BEC4
_0814BEAE:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0814BEC0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0814BED0
	.align 2, 0
_0814BEC0: .4byte 0x03002BE0
_0814BEC4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0814BF08
_0814BED0:
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
_0814BF08:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0814BF34
	ldr r5, _0814BF40 @ =0x0000024E
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
	bls _0814BF34
	strh r1, [r2]
_0814BF34:
	ldr r5, _0814BF44 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _0814C278
	.align 2, 0
_0814BF40: .4byte 0x0000024E
_0814BF44: .4byte 0x0000048C
_0814BF48:
	ldr r0, _0814BF5C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814BF60
	movs r0, #1
	b _0814BF62
	.align 2, 0
_0814BF5C: .4byte 0x030047A4
_0814BF60:
	movs r0, #0
_0814BF62:
	cmp r0, #0
	beq _0814BF70
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236640
	b _0814BF78
_0814BF70:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
_0814BF78:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0814BFB0 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0814BFB4 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _0814BFA6
	cmp r2, #0x17
	bne _0814BFB8
_0814BFA6:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _0814BFDA
	.align 2, 0
_0814BFB0: .4byte 0x0000048C
_0814BFB4: .4byte 0x000001DF
_0814BFB8:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0814BFA6
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _0814C008 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0814BFDA
	movs r1, #0
_0814BFDA:
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
	beq _0814C016
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _0814C00C
	asrs r0, r0, #1
	b _0814C012
	.align 2, 0
_0814C008: .4byte 0x00000187
_0814C00C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0814C012:
	mov r2, sb
	strh r0, [r2]
_0814C016:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0814C034
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _0814C030 @ =0x000001DD
	adds r1, r6, r4
	b _0814C0A8
	.align 2, 0
_0814C030: .4byte 0x000001DD
_0814C034:
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
	bne _0814C094
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0814C094
	ldr r2, _0814C084 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0814C088 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0814C08C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0814C090 @ =0x000001DD
	adds r1, r6, r4
	b _0814C0A8
	.align 2, 0
_0814C084: .4byte 0x030046B8
_0814C088: .4byte 0x000003FF
_0814C08C: .4byte 0x0203B400
_0814C090: .4byte 0x000001DD
_0814C094:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _0814C0C8 @ =0x000001DD
	adds r1, r6, r3
_0814C0A8:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0814C0D0
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0814C0CC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0814C13E
	.align 2, 0
_0814C0C8: .4byte 0x000001DD
_0814C0CC: .4byte 0x03002BE0
_0814C0D0:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0814C0EC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0814C0E8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0814C13E
	.align 2, 0
_0814C0E8: .4byte 0x03002BE0
_0814C0EC:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0814C108
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0814C104 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0814C13E
	.align 2, 0
_0814C104: .4byte 0x03002BE0
_0814C108:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0814C124
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0814C120 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0814C13E
	.align 2, 0
_0814C120: .4byte 0x03002BE0
_0814C124:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0814C136
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0814C13E
_0814C136:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0814C140
_0814C13E:
	movs r3, #1
_0814C140:
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
	ldr r5, _0814C174 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0814C1DC
	movs r1, #2
	ldr r2, _0814C178 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814C17C
	movs r0, #1
	b _0814C17E
	.align 2, 0
_0814C174: .4byte 0x0000049C
_0814C178: .4byte 0x00000474
_0814C17C:
	movs r0, #0
_0814C17E:
	cmp r0, #0
	beq _0814C198
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0814C194 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0814C1A4
	.align 2, 0
_0814C194: .4byte 0x03002BE0
_0814C198:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0814C1DC
_0814C1A4:
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
_0814C1DC:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0814C210
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0814C210
	ldr r0, _0814C228 @ =0x0000024E
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
	bls _0814C210
	strh r1, [r2]
_0814C210:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0814C22C @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0814C230 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814C234
	movs r0, #1
	b _0814C236
	.align 2, 0
_0814C228: .4byte 0x0000024E
_0814C22C: .4byte 0x030046A0
_0814C230: .4byte 0x00000934
_0814C234:
	movs r0, #0
_0814C236:
	ldr r1, _0814C288 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0814C24E
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_0814C24E:
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
_0814C278:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814C288: .4byte 0x0000048A

	thumb_func_start FUN_0814c28c
FUN_0814c28c: @ 0x0814C28C
	push {lr}
	adds r2, r0, #0
	ldr r0, _0814C2AC @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814C29E
	movs r0, #0
	strb r0, [r1]
_0814C29E:
	adds r0, r2, #0
	movs r1, #1
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_0814C2AC: .4byte 0x0000046D

	thumb_func_start FUN_0814c2b0
FUN_0814c2b0: @ 0x0814C2B0
	push {lr}
	adds r2, r0, #0
	ldr r0, _0814C2D0 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814C2C2
	movs r0, #0
	strb r0, [r1]
_0814C2C2:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_0814C2D0: .4byte 0x0000046D

	thumb_func_start FUN_0814c2d4
FUN_0814c2d4: @ 0x0814C2D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r5
	ldr r0, _0814C2F4 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814C2F8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814C2FA
	.align 2, 0
_0814C2F4: .4byte 0x0000046D
_0814C2F8:
	movs r0, #0
_0814C2FA:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	cmp r0, #0
	bne _0814C308
	b _0814C78E
_0814C308:
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	ldr r3, _0814C358 @ =0x0000046A
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #6
	beq _0814C35C
	movs r1, #0x90
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0814C35C
	mov r1, r8
	ldr r0, [r1, #0x24]
	ldr r0, [r0, #8]
	ldrh r0, [r0, #4]
	lsrs r1, r0, #0xc
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	b _0814C364
	.align 2, 0
_0814C358: .4byte 0x0000046A
_0814C35C:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
_0814C364:
	cmp r1, #0
	blt _0814C36C
	asrs r0, r1, #1
	b _0814C372
_0814C36C:
	rsbs r0, r1, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0814C372:
	cmp r2, r0
	bne _0814C3FE
	ldr r2, _0814C3E4 @ =0x0000046B
	adds r0, r5, r2
	movs r6, #0
	movs r4, #1
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0814C3F4
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0814C3E8 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _0814C3EC @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r1, _0814C3F0 @ =0x000005BC
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #0x1b
	adds r3, #1
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	b _0814C958
	.align 2, 0
_0814C3E4: .4byte 0x0000046B
_0814C3E8: .4byte 0x00000469
_0814C3EC: .4byte 0x0000046A
_0814C3F0: .4byte 0x000005BC
_0814C3F4:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	b _0814C958
_0814C3FE:
	cmp r2, #1
	beq _0814C4BC
	cmp r2, #1
	bgt _0814C40C
	cmp r2, #0
	beq _0814C41A
	b _0814C786
_0814C40C:
	cmp r2, #2
	bne _0814C412
	b _0814C594
_0814C412:
	cmp r2, #3
	bne _0814C418
	b _0814C664
_0814C418:
	b _0814C786
_0814C41A:
	subs r0, r1, #2
	cmp r0, #3
	bhi _0814C46C
	movs r2, #0xd
	ldr r3, _0814C440 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0814C448
	ldr r1, _0814C444 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
	b _0814C686
	.align 2, 0
_0814C440: .4byte 0x0000025D
_0814C444: .4byte 0x000004B7
_0814C448:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xe
	ldr r3, _0814C464 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C468 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xe
	beq _0814C462
	b _0814C6C2
_0814C462:
	b _0814C6B2
	.align 2, 0
_0814C464: .4byte 0x000004B7
_0814C468: .4byte 0x0000046E
_0814C46C:
	movs r2, #0xd
	ldr r1, _0814C490 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814C498
	ldr r3, _0814C494 @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #0
	b _0814C71E
	.align 2, 0
_0814C490: .4byte 0x0000025D
_0814C494: .4byte 0x000004B7
_0814C498:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	ldr r1, _0814C4B4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C4B8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xd
	beq _0814C4B0
	b _0814C75C
_0814C4B0:
	b _0814C74C
	.align 2, 0
_0814C4B4: .4byte 0x000004B7
_0814C4B8: .4byte 0x0000046E
_0814C4BC:
	subs r0, r1, #4
	cmp r0, #3
	bhi _0814C510
	movs r2, #0xd
	ldr r3, _0814C4E4 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0814C4EC
	ldr r1, _0814C4E8 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #2
	b _0814C686
	.align 2, 0
_0814C4E4: .4byte 0x0000025D
_0814C4E8: .4byte 0x000004B7
_0814C4EC:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0xf
	ldr r3, _0814C508 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C50C @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xf
	beq _0814C506
	b _0814C6C2
_0814C506:
	b _0814C6B2
	.align 2, 0
_0814C508: .4byte 0x000004B7
_0814C50C: .4byte 0x0000046E
_0814C510:
	movs r2, #0xd
	ldr r1, _0814C538 @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0814C544
	ldr r1, _0814C53C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #3
	bl FUN_08236fac
	ldr r2, _0814C540 @ =0x0000046E
	adds r6, r5, r2
	b _0814C774
	.align 2, 0
_0814C538: .4byte 0x0000025D
_0814C53C: .4byte 0x000004B7
_0814C540: .4byte 0x0000046E
_0814C544:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	movs r2, #0x10
	ldr r3, _0814C58C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C590 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0x10
	bne _0814C56E
	ldrb r0, [r6]
	cmp r0, #0
	bne _0814C56E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0814C56E
	b _0814C778
_0814C56E:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	b _0814C774
	.align 2, 0
_0814C58C: .4byte 0x000004B7
_0814C590: .4byte 0x0000046E
_0814C594:
	subs r0, r1, #1
	cmp r0, #4
	bls _0814C614
	movs r2, #0xd
	ldr r3, _0814C5C0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814C5C8
	ldr r1, _0814C5C4 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #3
	b _0814C686
	.align 2, 0
_0814C5C0: .4byte 0x0000025D
_0814C5C4: .4byte 0x000004B7
_0814C5C8:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0x10
	ldr r3, _0814C60C @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C610 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0x10
	bne _0814C5F2
	ldrb r0, [r6]
	cmp r0, #0
	bne _0814C5F2
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0814C5F2
	b _0814C6E2
_0814C5F2:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
	b _0814C6DE
	.align 2, 0
_0814C60C: .4byte 0x000004B7
_0814C610: .4byte 0x0000046E
_0814C614:
	movs r2, #0xd
	ldr r1, _0814C638 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814C640
	ldr r3, _0814C63C @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #2
	b _0814C71E
	.align 2, 0
_0814C638: .4byte 0x0000025D
_0814C63C: .4byte 0x000004B7
_0814C640:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xf
	ldr r1, _0814C65C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C660 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xf
	beq _0814C65A
	b _0814C75C
_0814C65A:
	b _0814C74C
	.align 2, 0
_0814C65C: .4byte 0x000004B7
_0814C660: .4byte 0x0000046E
_0814C664:
	cmp r1, #3
	bhi _0814C6FC
	movs r2, #0xd
	ldr r3, _0814C690 @ =0x0000025D
	adds r0, r5, r3
	ldrb r3, [r0]
	cmp r3, #0
	bne _0814C69C
	ldr r1, _0814C694 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
_0814C686:
	bl FUN_08236fac
	ldr r2, _0814C698 @ =0x0000046E
	adds r6, r5, r2
	b _0814C6DE
	.align 2, 0
_0814C690: .4byte 0x0000025D
_0814C694: .4byte 0x000004B7
_0814C698: .4byte 0x0000046E
_0814C69C:
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r3, _0814C6F4 @ =0x000004B7
	adds r0, r5, r3
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C6F8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xd
	bne _0814C6C2
_0814C6B2:
	ldrb r0, [r6]
	cmp r0, #0
	bne _0814C6C2
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0814C6E2
_0814C6C2:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0814C6DE:
	movs r0, #0
	strb r0, [r6]
_0814C6E2:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0814C786
	.align 2, 0
_0814C6F4: .4byte 0x000004B7
_0814C6F8: .4byte 0x0000046E
_0814C6FC:
	movs r2, #0xd
	ldr r1, _0814C728 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814C734
	ldr r3, _0814C72C @ =0x000004B7
	adds r0, r5, r3
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #1
	str r2, [sp]
	movs r2, #0xd
	movs r3, #1
_0814C71E:
	bl FUN_08236fac
	ldr r0, _0814C730 @ =0x0000046E
	adds r6, r5, r0
	b _0814C774
	.align 2, 0
_0814C728: .4byte 0x0000025D
_0814C72C: .4byte 0x000004B7
_0814C730: .4byte 0x0000046E
_0814C734:
	ldr r0, [r5, #0x44]
	adds r7, r0, #0
	adds r7, #0x20
	movs r2, #0xe
	ldr r1, _0814C7B4 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0814C7B8 @ =0x0000046E
	adds r6, r5, r0
	cmp r1, #0xe
	bne _0814C75C
_0814C74C:
	ldrb r0, [r6]
	cmp r0, #0
	bne _0814C75C
	ldr r0, [r7, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0814C778
_0814C75C:
	strb r2, [r3]
	movs r4, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r4, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r7, #8]
	orrs r0, r4
	str r0, [r7, #8]
_0814C774:
	movs r0, #0
	strb r0, [r6]
_0814C778:
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _0814C7BC @ =0xFFFEFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0814C786:
	ldr r2, _0814C7B8 @ =0x0000046E
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
_0814C78E:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	cmp r0, #1
	bne _0814C7C8
	movs r1, #0x80
	lsls r1, r1, #9
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814C7C0
	mov r1, r8
	ldrb r0, [r1, #5]
	adds r0, #0x20
	strb r0, [r1, #5]
	b _0814C7C8
	.align 2, 0
_0814C7B4: .4byte 0x000004B7
_0814C7B8: .4byte 0x0000046E
_0814C7BC: .4byte 0xFFFEFFFF
_0814C7C0:
	mov r2, r8
	ldrb r0, [r2, #5]
	subs r0, #0x20
	strb r0, [r2, #5]
_0814C7C8:
	ldr r3, _0814C7F8 @ =0x00000482
	adds r2, r5, r3
	ldrh r6, [r2]
	movs r1, #0x80
	mov r3, sb
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0814C7DE
	movs r0, #3
	strh r0, [r2]
_0814C7DE:
	ldr r1, _0814C7FC @ =0x0000A02F
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0814C800
	ldr r3, _0814C7F8 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0814C810
	.align 2, 0
_0814C7F8: .4byte 0x00000482
_0814C7FC: .4byte 0x0000A02F
_0814C800:
	ldr r1, _0814C834 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0814C810
	movs r0, #1
	strh r0, [r2]
_0814C810:
	ldr r3, _0814C838 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814C83C
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
	b _0814C854
	.align 2, 0
_0814C834: .4byte 0x00000482
_0814C838: .4byte 0x0000025D
_0814C83C:
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
_0814C854:
	ldr r1, _0814C910 @ =0x00000482
	adds r0, r5, r1
	movs r7, #0
	movs r2, #0
	mov r8, r2
	strh r6, [r0]
	ldr r3, _0814C914 @ =0x0000046E
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814C958
	ldrb r0, [r5, #5]
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r1, r1, r0
	cmp r1, #0
	bge _0814C88A
	rsbs r1, r1, #0
_0814C88A:
	cmp r1, #0
	bgt _0814C928
	ldr r1, _0814C918 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0x80
	lsls r1, r1, #3
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0814C958
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r6, [r0]
	adds r1, #0x69
	adds r0, r5, r1
	strb r4, [r0]
	ldr r2, _0814C91C @ =0x0000046A
	adds r0, r5, r2
	strb r7, [r0]
	adds r3, #0x1c
	adds r0, r5, r3
	mov r1, r8
	str r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _0814C920 @ =0x000005BC
	adds r0, r5, r3
	ldr r2, [r0]
	movs r1, #0x1b
	ldr r3, _0814C924 @ =0x0000046D
	adds r0, r5, r3
	strb r4, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r7, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	mov r3, r8
	strh r3, [r0]
	b _0814C958
	.align 2, 0
_0814C910: .4byte 0x00000482
_0814C914: .4byte 0x0000046E
_0814C918: .4byte 0x0000046B
_0814C91C: .4byte 0x0000046A
_0814C920: .4byte 0x000005BC
_0814C924: .4byte 0x0000046D
_0814C928:
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #2
	ldr r0, _0814C968 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814C96C @ =0x0000046B
	adds r0, r5, r1
	strb r7, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	mov r1, r8
	strh r1, [r0]
_0814C958:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814C968: .4byte 0x0000046D
_0814C96C: .4byte 0x0000046B

	thumb_func_start FUN_0814c970
FUN_0814c970: @ 0x0814C970
	bx lr
	.align 2, 0

	thumb_func_start FUN_0814c974
FUN_0814c974: @ 0x0814C974
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0814C98C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814C990
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814C992
	.align 2, 0
_0814C98C: .4byte 0x0000046D
_0814C990:
	movs r0, #0
_0814C992:
	cmp r0, #0
	beq _0814C9B4
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080ef86c
	movs r0, #2
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _0814C9B4
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_0814C9B4:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _0814C9D0
	ldr r2, _0814CA1C @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_0814C9D0:
	ldr r1, _0814CA20 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _0814CA16
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _0814CA16
	ldr r3, _0814CA24 @ =FUN_0814ca30
	movs r2, #6
	ldr r0, _0814CA28 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814CA2C @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_0814CA16:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814CA1C: .4byte 0x000001DF
_0814CA20: .4byte 0x00000466
_0814CA24: .4byte FUN_0814ca30
_0814CA28: .4byte 0x0000046D
_0814CA2C: .4byte 0x0000046B

	thumb_func_start FUN_0814ca30
FUN_0814ca30: @ 0x0814CA30
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0814CA48 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814CA4C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814CA4E
	.align 2, 0
_0814CA48: .4byte 0x0000046D
_0814CA4C:
	movs r0, #0
_0814CA4E:
	cmp r0, #0
	beq _0814CA6A
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ef86c
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_0814CA6A:
	cmp r5, #0x28
	bne _0814CA7C
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0814CA7C:
	ldr r1, _0814CA98 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814CA92
	cmp r5, #0x78
	ble _0814CA92
	ldr r0, _0814CA9C @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0814CA92:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814CA98: .4byte 0x0000046E
_0814CA9C: .4byte 0x0000046B

	thumb_func_start FUN_0814caa0
FUN_0814caa0: @ 0x0814CAA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0814CAB8 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814CABC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814CABE
	.align 2, 0
_0814CAB8: .4byte 0x0000046D
_0814CABC:
	movs r0, #0
_0814CABE:
	cmp r0, #0
	beq _0814CAD2
	adds r0, r5, #0
	movs r1, #0xb
	bl FUN_080ef86c
	ldr r0, _0814CB04 @ =0x0000046E
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_0814CAD2:
	ldr r1, _0814CB08 @ =0x00000482
	adds r3, r5, r1
	ldrh r6, [r3]
	movs r1, #0x80
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0814CAEC
	movs r0, #3
	strh r0, [r3]
_0814CAEC:
	ldr r1, _0814CB0C @ =0x0000A02F
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0814CB10
	ldr r0, _0814CB08 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0814CB20
	.align 2, 0
_0814CB04: .4byte 0x0000046E
_0814CB08: .4byte 0x00000482
_0814CB0C: .4byte 0x0000A02F
_0814CB10:
	ldr r1, _0814CB44 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0814CB20
	movs r0, #1
	strh r0, [r2]
_0814CB20:
	ldr r1, _0814CB48 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814CB4C
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
	b _0814CB64
	.align 2, 0
_0814CB44: .4byte 0x00000482
_0814CB48: .4byte 0x0000025D
_0814CB4C:
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
_0814CB64:
	ldr r1, _0814CB84 @ =0x00000482
	adds r0, r5, r1
	strh r6, [r0]
	subs r1, #0x14
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814CB7C
	ldr r0, _0814CB88 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0814CB7C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814CB84: .4byte 0x00000482
_0814CB88: .4byte 0x0000046B

	thumb_func_start FUN_0814cb8c
FUN_0814cb8c: @ 0x0814CB8C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _0814CBA4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814CBA8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814CBAA
	.align 2, 0
_0814CBA4: .4byte 0x0000046D
_0814CBA8:
	movs r0, #0
_0814CBAA:
	cmp r0, #0
	beq _0814CBBE
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ef86c
	ldr r2, _0814CC68 @ =0x0000046E
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0814CBBE:
	ldr r3, _0814CC68 @ =0x0000046E
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814CBCA
	b _0814CCE2
_0814CBCA:
	ldr r6, _0814CC6C @ =0x0000046B
	adds r0, r4, r6
	movs r6, #0
	movs r7, #1
	strb r7, [r0]
	movs r1, #0x80
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0814CC84
	adds r3, #0x36
	adds r0, r4, r3
	ldr r0, [r0]
	movs r2, #0x1c
	ldrsh r1, [r0, r2]
	movs r3, #0x20
	ldrsh r2, [r0, r3]
	adds r0, r4, #0
	bl FUN_080e6304
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r3, _0814CC70 @ =0x0000046D
	adds r0, r4, r3
	strb r7, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r6, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	strh r6, [r0]
	movs r2, #0xc
	subs r3, #0xeb
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0814CC74 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0814CC78 @ =0x00000484
	adds r0, r4, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	movs r0, #4
	ldr r6, _0814CC7C @ =0x00000222
	adds r2, r4, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _0814CC80 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	strh r0, [r1]
	b _0814CCE2
	.align 2, 0
_0814CC68: .4byte 0x0000046E
_0814CC6C: .4byte 0x0000046B
_0814CC70: .4byte 0x0000046D
_0814CC74: .4byte 0x0000046A
_0814CC78: .4byte 0x00000484
_0814CC7C: .4byte 0x00000222
_0814CC80: .4byte 0x00000482
_0814CC84:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r1, _0814CCE8 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r2, _0814CCEC @ =0x0000046D
	adds r0, r4, r2
	strb r7, [r0]
	ldr r6, _0814CCF0 @ =0x0000046B
	adds r0, r4, r6
	strb r5, [r0]
	adds r2, #0xe6
	adds r0, r4, r2
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r4, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	strh r5, [r0]
	movs r2, #7
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _0814CCF4 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _0814CCF8 @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r6, #3
	adds r0, r4, r6
	strb r7, [r0]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
_0814CCE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814CCE8: .4byte FUN_080e48d0
_0814CCEC: .4byte 0x0000046D
_0814CCF0: .4byte 0x0000046B
_0814CCF4: .4byte 0x0000046A
_0814CCF8: .4byte 0x00000484

	thumb_func_start FUN_0814ccfc
FUN_0814ccfc: @ 0x0814CCFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc0
	adds r7, r0, #0
	ldr r0, _0814CD1C @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814CD20
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814CD22
	.align 2, 0
_0814CD1C: .4byte 0x0000046D
_0814CD20:
	movs r0, #0
_0814CD22:
	cmp r0, #0
	beq _0814CD80
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0814CD38
	asrs r1, r0, #2
	b _0814CD3E
_0814CD38:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_0814CD3E:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r0, r7, r4
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	blt _0814CD58
	asrs r1, r0, #2
	b _0814CD5E
_0814CD58:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_0814CD5E:
	movs r6, #0xe2
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r1, [r0]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	ldr r1, _0814CDB0 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r2]
_0814CD80:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0814CDB4
	asrs r0, r0, #2
	b _0814CDBA
	.align 2, 0
_0814CDB0: .4byte 0xFFFFFEFF
_0814CDB4:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0814CDBA:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _0814CDDA
	asrs r0, r0, #2
	b _0814CDE0
_0814CDDA:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0814CDE0:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0814CDEA
	movs r3, #0xc8
	b _0814CDF4
_0814CDEA:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0814CDF4
	adds r3, r0, #0
_0814CDF4:
	cmp r2, #0xc8
	ble _0814CDFC
	movs r2, #0xc8
	b _0814CE06
_0814CDFC:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0814CE06
	adds r2, r0, #0
_0814CE06:
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
	bne _0814CE2A
	cmp r2, #0
	bne _0814CE2A
	movs r0, #1
	b _0814CE2C
_0814CE2A:
	movs r0, #0
_0814CE2C:
	cmp r0, #0
	bne _0814CE34
	bl FUN_0814dd18
_0814CE34:
	ldr r6, _0814CE80 @ =0x0000046E
	adds r0, r7, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814CE42
	bl FUN_0814dd18
_0814CE42:
	ldr r0, _0814CE84 @ =0x0000046B
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	movs r3, #0x21
	rsbs r3, r3, #0
	ldrh r0, [r2]
	ands r3, r0
	strh r3, [r2]
	ldr r4, _0814CE88 @ =0x0000049C
	adds r0, r7, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xc
	ands r0, r1
	str r2, [sp, #0x9c]
	cmp r0, #0
	beq _0814CE8C
	movs r0, #2
	movs r5, #0xc1
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	bl _0814DD28
	.align 2, 0
_0814CE80: .4byte 0x0000046E
_0814CE84: .4byte 0x0000046B
_0814CE88: .4byte 0x0000049C
_0814CE8C:
	movs r2, #0x80
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _0814CE9C
	b _0814D5CC
_0814CE9C:
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, _0814CEF8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #3
	adds r3, r7, r1
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _0814CEF2
	cmp r1, #0
	blt _0814CEF2
	ldr r0, _0814CEFC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0814CEF2
	ldr r0, _0814CF00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814CF04
_0814CEF2:
	movs r4, #0
	b _0814CF12
	.align 2, 0
_0814CEF8: .4byte 0x03002BE0
_0814CEFC: .4byte 0x030046A8
_0814CF00: .4byte 0x030046AC
_0814CF04:
	ldr r0, _0814CF24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0814CF12:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814CF28
	adds r0, #4
	b _0814CF34
	.align 2, 0
_0814CF24: .4byte 0x030046A4
_0814CF28:
	ldr r0, _0814CF48 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814CF34:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814CF4C
	cmp r2, #2
	beq _0814CF50
	b _0814CF54
	.align 2, 0
_0814CF48: .4byte 0x030046A4
_0814CF4C:
	ldrb r0, [r5, #4]
	b _0814CF52
_0814CF50:
	ldrb r0, [r5]
_0814CF52:
	subs r1, r1, r0
_0814CF54:
	strh r1, [r5, #2]
	ldr r0, _0814CF68 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814CF6C
	movs r0, #1
	b _0814CF6E
	.align 2, 0
_0814CF68: .4byte 0x030047A4
_0814CF6C:
	movs r0, #0
_0814CF6E:
	cmp r0, #0
	beq _0814CFAC
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	cmp r1, #0
	beq _0814CF8E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0814CF8A
	adds r2, r0, #0
_0814CF8A:
	cmp r2, #0
	bge _0814CF98
_0814CF8E:
	ldr r3, _0814CF94 @ =0x000005C4
	adds r0, r7, r3
	b _0814D4C8
	.align 2, 0
_0814CF94: .4byte 0x000005C4
_0814CF98:
	ldr r1, _0814CFA8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0814CFF4
	.align 2, 0
_0814CFA8: .4byte 0x03002BE0
_0814CFAC:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814CFD8
	cmp r1, #0
	blt _0814CFD8
	ldr r0, _0814CFDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814CFD8
	ldr r0, _0814CFE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814CFE4
_0814CFD8:
	movs r5, #0
	b _0814CFF2
	.align 2, 0
_0814CFDC: .4byte 0x030046A8
_0814CFE0: .4byte 0x030046AC
_0814CFE4:
	ldr r0, _0814D02C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0814CFF2:
	movs r2, #0
_0814CFF4:
	ldr r6, _0814D030 @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0814D014
	ldr r1, _0814D034 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0814D014
	b _0814D408
_0814D014:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r2, [sp, #0x9c]
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	cmp r0, #0
	beq _0814D038
	movs r0, #0
	b _0814D4DE
	.align 2, 0
_0814D02C: .4byte 0x030046A4
_0814D030: .4byte 0x00000256
_0814D034: .4byte 0x03002BE0
_0814D038:
	ldr r3, _0814D0DC @ =0x00000222
	adds r2, r7, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xac]
	cmp r6, #0
	beq _0814D0F4
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r6, _0814D0E0 @ =0x0000046D
	adds r6, r7, r6
	str r6, [sp, #0x14]
	movs r2, #1
	strb r2, [r6]
	ldr r3, _0814D0E4 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x18]
	movs r4, #0
	strb r4, [r3]
	subs r5, #0x65
	adds r5, r7, r5
	str r5, [sp, #0x1c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r6, r7
	mov r8, r6
	str r1, [r6]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r5, r7, r0
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r5]
	movs r0, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r3, #0
	strb r3, [r4]
	ldr r6, _0814D0E8 @ =0x00000469
	adds r3, r7, r6
	movs r1, #0
	strb r1, [r3]
	adds r6, #1
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0814D0EC @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x10]
	str r6, [r1]
	ldr r6, _0814D0F0 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x1c]
	str r6, [sp, #0xb0]
	mov r6, r8
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _0814D2C6
	.align 2, 0
_0814D0DC: .4byte 0x00000222
_0814D0E0: .4byte 0x0000046D
_0814D0E4: .4byte 0x0000046B
_0814D0E8: .4byte 0x00000469
_0814D0EC: .4byte 0x00000484
_0814D0F0: .4byte 0x0000046C
_0814D0F4:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0814D1B8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x20]
	strb r0, [r2]
	ldr r3, _0814D1BC @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x24]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0814D1C0 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x28]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x2c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x30]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x34]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0814D1C4 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0814D1C8 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0814D1CC @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x38]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x38]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x24]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x28]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x2c]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x34]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sl
	cmp r0, #0
	blt _0814D1B2
	cmp r1, #0
	blt _0814D1B2
	ldr r0, _0814D1D0 @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _0814D1B2
	ldr r0, _0814D1D4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D1D8
_0814D1B2:
	movs r4, #0
	b _0814D1E8
	.align 2, 0
_0814D1B8: .4byte 0x0000046D
_0814D1BC: .4byte 0x0000046B
_0814D1C0: .4byte 0x00000553
_0814D1C4: .4byte 0x00000469
_0814D1C8: .4byte 0x00000484
_0814D1CC: .4byte 0x0000046C
_0814D1D0: .4byte 0x030046A8
_0814D1D4: .4byte 0x030046AC
_0814D1D8:
	ldr r0, _0814D1F8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_0814D1E8:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814D1FC
	adds r0, #4
	b _0814D208
	.align 2, 0
_0814D1F8: .4byte 0x030046A4
_0814D1FC:
	ldr r0, _0814D21C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814D208:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814D220
	cmp r2, #2
	beq _0814D226
	b _0814D22C
	.align 2, 0
_0814D21C: .4byte 0x030046A4
_0814D220:
	ldr r2, [sp, #0x38]
	ldrb r0, [r2, #4]
	b _0814D22A
_0814D226:
	ldr r3, [sp, #0x38]
	ldrb r0, [r3]
_0814D22A:
	subs r1, r1, r0
_0814D22C:
	ldr r4, [sp, #0x38]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814D258
	cmp r1, #0
	blt _0814D258
	ldr r0, _0814D25C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814D258
	ldr r0, _0814D260 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D264
_0814D258:
	movs r4, #0
	b _0814D272
	.align 2, 0
_0814D25C: .4byte 0x030046A8
_0814D260: .4byte 0x030046AC
_0814D264:
	ldr r0, _0814D288 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814D272:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814D28C
	adds r0, #4
	b _0814D298
	.align 2, 0
_0814D288: .4byte 0x030046A4
_0814D28C:
	ldr r0, _0814D2AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814D298:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814D2B0
	cmp r3, #2
	beq _0814D2B4
	b _0814D2B8
	.align 2, 0
_0814D2AC: .4byte 0x030046A4
_0814D2B0:
	ldrb r0, [r5, #4]
	b _0814D2B6
_0814D2B4:
	ldrb r0, [r5]
_0814D2B6:
	subs r2, r2, r0
_0814D2B8:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0814D2C6:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x3c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0814D2F0 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _0814D3D0
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0814D2F4
	movs r0, #1
	b _0814D2F6
	.align 2, 0
_0814D2F0: .4byte 0x00000482
_0814D2F4:
	movs r0, #0
_0814D2F6:
	ldr r1, _0814D3E0 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _0814D3D0
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _0814D3E4 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0814D3E8 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0814D3EC @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _0814D3F0 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0814D3F4 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _0814D3F8 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _0814D3FC @ =0x030046B8
	adds r2, r4, #0
_0814D33E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0814D400 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0814D404 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0814D362
	adds r3, #1
	cmp r3, #3
	ble _0814D33E
	adds r0, r4, #0
_0814D362:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x3c
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_0814D3D0:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _0814D4DE
	.align 2, 0
_0814D3E0: .4byte 0x00000482
_0814D3E4: .4byte 0x0000054F
_0814D3E8: .4byte 0x0000054C
_0814D3EC: .4byte 0x0000054E
_0814D3F0: .4byte 0x00000541
_0814D3F4: .4byte 0x000005BC
_0814D3F8: .4byte 0x00000542
_0814D3FC: .4byte 0x030046B8
_0814D400: .4byte 0x000003FF
_0814D404: .4byte 0x0203B400
_0814D408:
	mov sb, sp
	ldr r6, _0814D444 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
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
	beq _0814D448
	adds r0, #4
	b _0814D452
	.align 2, 0
_0814D444: .4byte 0x030046A4
_0814D448:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814D452:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0814D48C @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0814D494
	ldr r0, _0814D490 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0814D4BE
	.align 2, 0
_0814D48C: .4byte 0x000004A4
_0814D490: .4byte 0xFFFFFDFF
_0814D494:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0814D4B4
	cmp r0, #2
	beq _0814D4B0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814D4B0:
	movs r0, #1
	b _0814D4C0
_0814D4B4:
	ldr r0, _0814D4D4 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0814D4BE:
	movs r0, #0
_0814D4C0:
	cmp r0, #0
	bne _0814D4DC
	ldr r4, _0814D4D8 @ =0x000005C4
	adds r0, r7, r4
_0814D4C8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0814D4DE
	.align 2, 0
_0814D4D4: .4byte 0xFFFFFDFF
_0814D4D8: .4byte 0x000005C4
_0814D4DC:
	movs r0, #1
_0814D4DE:
	cmp r0, #0
	bne _0814D54E
	ldr r5, _0814D514 @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0814D51C
	ldr r0, _0814D518 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0814D546
	.align 2, 0
_0814D514: .4byte 0x000004A4
_0814D518: .4byte 0xFFFFFDFF
_0814D51C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0814D53C
	cmp r0, #2
	beq _0814D538
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814D538:
	movs r0, #1
	b _0814D548
_0814D53C:
	ldr r0, _0814D5B0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0814D546:
	movs r0, #0
_0814D548:
	cmp r0, #0
	bne _0814D54E
	b _0814DC90
_0814D54E:
	movs r0, #4
	ldr r5, _0814D5B4 @ =0x00000222
	adds r2, r7, r5
	ldrh r1, [r2]
	movs r3, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r2, [r0]
	movs r1, #0x1a
	ldr r4, _0814D5B8 @ =0x0000046D
	adds r0, r7, r4
	movs r4, #1
	strb r4, [r0]
	ldr r6, _0814D5BC @ =0x0000046B
	adds r0, r7, r6
	strb r3, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	movs r1, #0xc
	subs r6, #0xeb
	adds r0, r7, r6
	strb r3, [r0]
	ldr r2, _0814D5C0 @ =0x00000469
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _0814D5C4 @ =0x0000046A
	adds r0, r7, r3
	strb r1, [r0]
	adds r6, #0x1c
	adds r0, r7, r6
	str r5, [r0]
	ldr r1, _0814D5C8 @ =0x0000046C
	adds r0, r7, r1
	strb r4, [r0]
	b _0814DD28
	.align 2, 0
_0814D5B0: .4byte 0xFFFFFDFF
_0814D5B4: .4byte 0x00000222
_0814D5B8: .4byte 0x0000046D
_0814D5BC: .4byte 0x0000046B
_0814D5C0: .4byte 0x00000469
_0814D5C4: .4byte 0x0000046A
_0814D5C8: .4byte 0x0000046C
_0814D5CC:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, _0814D630 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x10
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r0, [r0]
	strh r3, [r0, #6]
	adds r3, r7, r5
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x98]
	str r2, [sp, #0x74]
	cmp r4, #0
	blt _0814D62A
	cmp r1, #0
	blt _0814D62A
	ldr r0, _0814D634 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0814D62A
	ldr r0, _0814D638 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D63C
_0814D62A:
	movs r4, #0
	b _0814D64A
	.align 2, 0
_0814D630: .4byte 0x03002BE0
_0814D634: .4byte 0x030046A8
_0814D638: .4byte 0x030046AC
_0814D63C:
	ldr r0, _0814D65C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0814D64A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814D660
	adds r0, #4
	b _0814D66C
	.align 2, 0
_0814D65C: .4byte 0x030046A4
_0814D660:
	ldr r0, _0814D680 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814D66C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814D684
	cmp r2, #2
	beq _0814D688
	b _0814D68C
	.align 2, 0
_0814D680: .4byte 0x030046A4
_0814D684:
	ldrb r0, [r5, #4]
	b _0814D68A
_0814D688:
	ldrb r0, [r5]
_0814D68A:
	subs r1, r1, r0
_0814D68C:
	strh r1, [r5, #2]
	ldr r0, _0814D6A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814D6A4
	movs r0, #1
	b _0814D6A6
	.align 2, 0
_0814D6A0: .4byte 0x030047A4
_0814D6A4:
	movs r0, #0
_0814D6A6:
	cmp r0, #0
	beq _0814D6E4
	movs r6, #0xec
	lsls r6, r6, #1
	adds r0, r7, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0814D6C6
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0814D6C2
	adds r2, r0, #0
_0814D6C2:
	cmp r2, #0
	bge _0814D6D0
_0814D6C6:
	ldr r1, _0814D6CC @ =0x000005C4
	adds r0, r7, r1
	b _0814DC0C
	.align 2, 0
_0814D6CC: .4byte 0x000005C4
_0814D6D0:
	ldr r1, _0814D6E0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0814D72C
	.align 2, 0
_0814D6E0: .4byte 0x03002BE0
_0814D6E4:
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814D710
	cmp r1, #0
	blt _0814D710
	ldr r0, _0814D714 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814D710
	ldr r0, _0814D718 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D71C
_0814D710:
	movs r5, #0
	b _0814D72A
	.align 2, 0
_0814D714: .4byte 0x030046A8
_0814D718: .4byte 0x030046AC
_0814D71C:
	ldr r0, _0814D764 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0814D72A:
	movs r2, #0
_0814D72C:
	ldr r3, _0814D768 @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _0814D74C
	ldr r1, _0814D76C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0814D74C
	b _0814DB48
_0814D74C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x40]
	cmp r0, #0
	beq _0814D770
	movs r0, #0
	b _0814DC22
	.align 2, 0
_0814D764: .4byte 0x030046A4
_0814D768: .4byte 0x00000256
_0814D76C: .4byte 0x03002BE0
_0814D770:
	ldr r5, _0814D814 @ =0x00000222
	adds r2, r7, r5
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r6, [sp, #0x9c]
	ldrh r0, [r6]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	str r2, [sp, #0xac]
	cmp r0, #0
	beq _0814D834
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r2, _0814D818 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x44]
	movs r3, #1
	strb r3, [r2]
	ldr r4, _0814D81C @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x48]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0814D820 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x4c]
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x50]
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	add r2, sp, #0x40
	ldrh r2, [r2]
	strh r2, [r5]
	movs r0, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r4, r7, r3
	movs r6, #0
	strb r6, [r4]
	ldr r1, _0814D824 @ =0x00000469
	adds r3, r7, r1
	strb r6, [r3]
	ldr r6, _0814D828 @ =0x0000046A
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, _0814D82C @ =0x00000484
	adds r1, r7, r0
	ldr r6, [sp, #0x40]
	str r6, [r1]
	ldr r6, _0814D830 @ =0x0000046C
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x8c]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0x84]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb0]
	ldr r6, [sp, #0x50]
	str r6, [sp, #0xb4]
	str r5, [sp, #0xa0]
	str r4, [sp, #0x78]
	str r3, [sp, #0x7c]
	str r2, [sp, #0x80]
	str r1, [sp, #0x94]
	str r0, [sp, #0x88]
	b _0814DA06
	.align 2, 0
_0814D814: .4byte 0x00000222
_0814D818: .4byte 0x0000046D
_0814D81C: .4byte 0x0000046B
_0814D820: .4byte 0x00000553
_0814D824: .4byte 0x00000469
_0814D828: .4byte 0x0000046A
_0814D82C: .4byte 0x00000484
_0814D830: .4byte 0x0000046C
_0814D834:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0814D8F8 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x54]
	strb r0, [r2]
	ldr r3, _0814D8FC @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x58]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0814D900 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	strb r0, [r5]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x60]
	str r1, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x64]
	mov r2, ip
	strh r2, [r1]
	movs r1, #5
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x68]
	strb r4, [r3]
	ldr r4, _0814D904 @ =0x00000469
	adds r5, r7, r4
	movs r6, #0
	strb r6, [r5]
	ldr r2, _0814D908 @ =0x0000046A
	adds r4, r7, r2
	strb r1, [r4]
	ldr r6, _0814D90C @ =0x00000484
	adds r3, r7, r6
	mov r1, ip
	str r1, [r3]
	subs r6, #0x18
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x98]
	ldr r0, [r0]
	str r0, [sp, #0x6c]
	ldr r1, [sp, #0x74]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x6c]
	strh r1, [r6]
	ldr r6, [sp, #0x74]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x6c]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x8c]
	ldr r6, [sp, #0x58]
	str r6, [sp, #0x84]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0xb0]
	ldr r6, [sp, #0x60]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0xa0]
	ldr r6, [sp, #0x68]
	str r6, [sp, #0x78]
	str r5, [sp, #0x7c]
	str r4, [sp, #0x80]
	str r3, [sp, #0x94]
	str r2, [sp, #0x88]
	mov r0, sb
	cmp r0, #0
	blt _0814D8F4
	cmp r1, #0
	blt _0814D8F4
	ldr r0, _0814D910 @ =0x030046A8
	ldr r0, [r0]
	cmp sb, r0
	bhs _0814D8F4
	ldr r0, _0814D914 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D918
_0814D8F4:
	movs r4, #0
	b _0814D928
	.align 2, 0
_0814D8F8: .4byte 0x0000046D
_0814D8FC: .4byte 0x0000046B
_0814D900: .4byte 0x00000553
_0814D904: .4byte 0x00000469
_0814D908: .4byte 0x0000046A
_0814D90C: .4byte 0x00000484
_0814D910: .4byte 0x030046A8
_0814D914: .4byte 0x030046AC
_0814D918:
	ldr r0, _0814D938 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sb
	adds r4, r0, r1
_0814D928:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814D93C
	adds r0, #4
	b _0814D948
	.align 2, 0
_0814D938: .4byte 0x030046A4
_0814D93C:
	ldr r0, _0814D95C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814D948:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814D960
	cmp r2, #2
	beq _0814D966
	b _0814D96C
	.align 2, 0
_0814D95C: .4byte 0x030046A4
_0814D960:
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #4]
	b _0814D96A
_0814D966:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3]
_0814D96A:
	subs r1, r1, r0
_0814D96C:
	ldr r4, [sp, #0x6c]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x98]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814D998
	cmp r1, #0
	blt _0814D998
	ldr r0, _0814D99C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814D998
	ldr r0, _0814D9A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814D9A4
_0814D998:
	movs r4, #0
	b _0814D9B2
	.align 2, 0
_0814D99C: .4byte 0x030046A8
_0814D9A0: .4byte 0x030046AC
_0814D9A4:
	ldr r0, _0814D9C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814D9B2:
	ldr r6, [sp, #0x98]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814D9CC
	adds r0, #4
	b _0814D9D8
	.align 2, 0
_0814D9C8: .4byte 0x030046A4
_0814D9CC:
	ldr r0, _0814D9EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814D9D8:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814D9F0
	cmp r3, #2
	beq _0814D9F4
	b _0814D9F8
	.align 2, 0
_0814D9EC: .4byte 0x030046A4
_0814D9F0:
	ldrb r0, [r5, #4]
	b _0814D9F6
_0814D9F4:
	ldrb r0, [r5]
_0814D9F6:
	subs r2, r2, r0
_0814D9F8:
	ldr r1, [sp, #0x98]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x98]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0814DA06:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x70]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x9c]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0814DA30 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x90]
	cmp r0, #0
	bne _0814DB10
	movs r1, #4
	ldr r6, [sp, #0xac]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0814DA34
	movs r0, #1
	b _0814DA36
	.align 2, 0
_0814DA30: .4byte 0x00000482
_0814DA34:
	movs r0, #0
_0814DA36:
	ldr r1, _0814DB20 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x90]
	cmp r0, #0
	bne _0814DB10
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xbc]
	ldr r0, _0814DB24 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0814DB28 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0814DB2C @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _0814DB30 @ =0x00000541
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _0814DB34 @ =0x000005BC
	adds r1, r7, r1
	str r1, [sp, #0xb8]
	ldr r2, _0814DB38 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _0814DB3C @ =0x030046B8
	adds r2, r4, #0
_0814DA7E:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0814DB40 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0814DB44 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0814DAA2
	adds r3, #1
	cmp r3, #3
	ble _0814DA7E
	adds r0, r4, #0
_0814DAA2:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldr r4, [sp, #0xb0]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x7c]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x80]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x70
	ldrb r1, [r0]
	mov r0, ip
	strb r1, [r0]
	ldr r1, [sp, #0xb8]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x8c]
	strb r1, [r4]
	ldr r5, [sp, #0x84]
	strb r3, [r5]
	ldr r6, [sp, #0xb0]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0xa0]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x78]
	strb r0, [r5]
	ldr r6, [sp, #0x7c]
	strb r1, [r6]
	ldr r0, [sp, #0x80]
	strb r2, [r0]
	ldr r2, [sp, #0x94]
	str r3, [r2]
	ldr r3, [sp, #0x88]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_0814DB10:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x90]
	strh r0, [r5]
	movs r0, #0
	b _0814DC22
	.align 2, 0
_0814DB20: .4byte 0x00000482
_0814DB24: .4byte 0x0000054F
_0814DB28: .4byte 0x0000054C
_0814DB2C: .4byte 0x0000054E
_0814DB30: .4byte 0x00000541
_0814DB34: .4byte 0x000005BC
_0814DB38: .4byte 0x00000542
_0814DB3C: .4byte 0x030046B8
_0814DB40: .4byte 0x000003FF
_0814DB44: .4byte 0x0203B400
_0814DB48:
	add r6, sp, #8
	ldr r0, _0814DB88 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _0814DB8C
	adds r0, #4
	b _0814DB98
	.align 2, 0
_0814DB88: .4byte 0x030046A4
_0814DB8C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814DB98:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0814DBD0 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _0814DBD8
	ldr r0, _0814DBD4 @ =0xFFFFFDFF
	ldr r6, [sp, #0x9c]
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	b _0814DC02
	.align 2, 0
_0814DBD0: .4byte 0x000004A4
_0814DBD4: .4byte 0xFFFFFDFF
_0814DBD8:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _0814DBF8
	cmp r0, #2
	beq _0814DBF4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814DBF4:
	movs r0, #1
	b _0814DC04
_0814DBF8:
	ldr r0, _0814DC18 @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0814DC02:
	movs r0, #0
_0814DC04:
	cmp r0, #0
	bne _0814DC20
	ldr r3, _0814DC1C @ =0x000005C4
	adds r0, r7, r3
_0814DC0C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0814DC22
	.align 2, 0
_0814DC18: .4byte 0xFFFFFDFF
_0814DC1C: .4byte 0x000005C4
_0814DC20:
	movs r0, #1
_0814DC22:
	cmp r0, #0
	bne _0814DCA8
	ldr r4, _0814DC58 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0814DC60
	ldr r0, _0814DC5C @ =0xFFFFFDFF
	ldr r2, [sp, #0x9c]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0814DC8A
	.align 2, 0
_0814DC58: .4byte 0x000004A4
_0814DC5C: .4byte 0xFFFFFDFF
_0814DC60:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0814DC80
	cmp r0, #2
	beq _0814DC7C
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814DC7C:
	movs r0, #1
	b _0814DC8C
_0814DC80:
	ldr r0, _0814DCA0 @ =0xFFFFFDFF
	ldr r3, [sp, #0x9c]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0814DC8A:
	movs r0, #0
_0814DC8C:
	cmp r0, #0
	bne _0814DCA8
_0814DC90:
	ldr r4, _0814DCA4 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0814DD28
	.align 2, 0
_0814DCA0: .4byte 0xFFFFFDFF
_0814DCA4: .4byte 0x000005C4
_0814DCA8:
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _0814DD04 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _0814DD08 @ =0x0000046B
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #0x4d
	adds r0, r7, r5
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r7, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, _0814DD0C @ =0x00000469
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0814DD10 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	ldr r4, _0814DD14 @ =0x00000484
	adds r0, r7, r4
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r3, [r0]
	adds r6, #0x19
	adds r1, r7, r6
	movs r0, #4
	strh r0, [r1]
	b _0814DD28
	.align 2, 0
_0814DD04: .4byte 0x0000046D
_0814DD08: .4byte 0x0000046B
_0814DD0C: .4byte 0x00000469
_0814DD10: .4byte 0x0000046A
_0814DD14: .4byte 0x00000484

	thumb_func_start FUN_0814dd18
FUN_0814dd18: @ 0x0814DD18
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0814DD28:
	add sp, #0xc0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0814dd38
FUN_0814dd38: @ 0x0814DD38
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0814DD54 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814DD58
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814DD5A
	.align 2, 0
_0814DD54: .4byte 0x0000046D
_0814DD58:
	movs r0, #0
_0814DD5A:
	cmp r0, #0
	beq _0814DD66
	adds r0, r5, #0
	movs r1, #0x11
	bl FUN_080ef86c
_0814DD66:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0
	strh r1, [r0, #8]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	strh r1, [r0, #0xe]
	adds r0, r4, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0814DDEE
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r2, r0, #6
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	cmp r2, #1
	beq _0814DDB2
	cmp r2, #1
	bgt _0814DDA0
	cmp r2, #0
	beq _0814DDAA
	b _0814DDE8
_0814DDA0:
	cmp r2, #2
	beq _0814DDBA
	cmp r2, #3
	beq _0814DDD4
	b _0814DDE8
_0814DDAA:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, #0x80
	b _0814DDC0
_0814DDB2:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, #0x80
	b _0814DDDA
_0814DDBA:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, #0xa0
_0814DDC0:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814DDD0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _0814DDE8
	.align 2, 0
_0814DDD0: .4byte 0xFFFF0000
_0814DDD4:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0x80
_0814DDDA:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814DE24 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_0814DDE8:
	mov r0, sp
	bl FUN_0814b7a4
_0814DDEE:
	cmp r4, #0x1e
	ble _0814DE1A
	ldr r4, _0814DE28 @ =FUN_0814de34
	movs r3, #0x25
	ldr r0, _0814DE2C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814DE30 @ =0x0000046B
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
_0814DE1A:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814DE24: .4byte 0xFFFF0000
_0814DE28: .4byte FUN_0814de34
_0814DE2C: .4byte 0x0000046D
_0814DE30: .4byte 0x0000046B

	thumb_func_start FUN_0814de34
FUN_0814de34: @ 0x0814DE34
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r0, _0814DE54 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814DE58
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814DE5A
	.align 2, 0
_0814DE54: .4byte 0x0000046D
_0814DE58:
	movs r0, #0
_0814DE5A:
	cmp r0, #0
	beq _0814DE78
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_080ef86c
	adds r0, r4, #0
	adds r0, #8
	ldrb r1, [r4, #5]
	movs r2, #0
	bl FUN_081f1498
	ldr r0, _0814DEA4 @ =0x000003A5
	bl PlaySound_082406e0
_0814DE78:
	adds r0, r5, #0
	subs r0, #0xd
	cmp r0, #0xa
	bhi _0814DE8A
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r6, r1
	bl FUN_08236400
_0814DE8A:
	ldr r1, _0814DEA8 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814DE9C
	ldr r0, _0814DEAC @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0814DE9C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814DEA4: .4byte 0x000003A5
_0814DEA8: .4byte 0x0000046E
_0814DEAC: .4byte 0x0000046B

	thumb_func_start FUN_0814deb0
FUN_0814deb0: @ 0x0814DEB0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r0, _0814DED0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814DED4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814DED6
	.align 2, 0
_0814DED0: .4byte 0x0000046D
_0814DED4:
	movs r0, #0
_0814DED6:
	cmp r0, #0
	beq _0814DEF8
	adds r0, r5, #0
	movs r1, #0xf
	bl FUN_080ef86c
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r2, r4, r1
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
_0814DEF8:
	ldr r1, _0814DF30 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814DF2A
	ldr r4, _0814DF34 @ =FUN_0814df40
	movs r3, #0x22
	ldr r0, _0814DF38 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814DF3C @ =0x0000046B
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
_0814DF2A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814DF30: .4byte 0x0000046E
_0814DF34: .4byte FUN_0814df40
_0814DF38: .4byte 0x0000046D
_0814DF3C: .4byte 0x0000046B

	thumb_func_start FUN_0814df40
FUN_0814df40: @ 0x0814DF40
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0814DF60 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814DF64
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814DF66
	.align 2, 0
_0814DF60: .4byte 0x0000046D
_0814DF64:
	movs r0, #0
_0814DF66:
	cmp r0, #0
	bne _0814DF6C
	b _0814E0F6
_0814DF6C:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	mov r3, sp
	adds r4, r5, #0
	adds r4, #8
	movs r0, #0xe1
	lsls r0, r0, #3
	adds r2, r7, r0
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
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl FUN_0823785c
	adds r4, r0, #0
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	lsls r2, r0, #6
	subs r1, r4, r2
	cmp r1, #0x80
	ble _0814DFC4
	ldr r0, _0814DFC0 @ =0xFFFFFF00
	b _0814DFD0
	.align 2, 0
_0814DFC0: .4byte 0xFFFFFF00
_0814DFC4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0814DFD2
	movs r0, #0x80
	lsls r0, r0, #1
_0814DFD0:
	adds r1, r1, r0
_0814DFD2:
	adds r0, r1, #0
	cmp r1, #0
	bge _0814DFDA
	rsbs r0, r1, #0
_0814DFDA:
	cmp r0, #0xf
	bgt _0814E030
	mov r3, sp
	movs r6, #0x18
	ldr r2, _0814E000 @ =0x085B0A08
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
	blt _0814E004
	asrs r1, r0, #0xc
	b _0814E00A
	.align 2, 0
_0814E000: .4byte 0x085B0A08
_0814E004:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814E00A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0814E026
	asrs r0, r0, #0xc
	b _0814E02C
_0814E026:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814E02C:
	strh r0, [r3, #4]
	b _0814E0CE
_0814E030:
	cmp r1, #0
	ble _0814E07C
	adds r3, r2, #0
	adds r3, #0x10
	movs r1, #0xff
	mov r4, sp
	ands r3, r1
	movs r6, #0x18
	ldr r2, _0814E05C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0814E060
	asrs r1, r0, #0xc
	b _0814E066
	.align 2, 0
_0814E05C: .4byte 0x085B0A08
_0814E060:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814E066:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	bge _0814E0C2
	b _0814E0C6
_0814E07C:
	adds r3, r2, #0
	adds r3, #0xef
	movs r1, #0xff
	mov r4, sp
	ands r3, r1
	movs r6, #0x18
	ldr r2, _0814E0A4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0814E0A8
	asrs r1, r0, #0xc
	b _0814E0AE
	.align 2, 0
_0814E0A4: .4byte 0x085B0A08
_0814E0A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814E0AE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0814E0C6
_0814E0C2:
	asrs r0, r0, #0xc
	b _0814E0CC
_0814E0C6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814E0CC:
	strh r0, [r4, #4]
_0814E0CE:
	mov r0, sp
	ldrh r1, [r0]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xe9
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0814E0F6:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	bl FUN_08236400
	ldr r0, [r5, #0x18]
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0814E14C
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0814E11E
	asrs r1, r0, #1
	b _0814E124
_0814E11E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0814E124:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0814E13E
	asrs r1, r0, #1
	b _0814E144
_0814E13E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0814E144:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_0814E14C:
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080ef86c
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814E19C
	ldr r4, _0814E1A4 @ =FUN_0814e1b0
	movs r3, #0x23
	ldr r0, _0814E1A8 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814E1AC @ =0x0000046B
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
_0814E19C:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814E1A4: .4byte FUN_0814e1b0
_0814E1A8: .4byte 0x0000046D
_0814E1AC: .4byte 0x0000046B

	thumb_func_start FUN_0814e1b0
FUN_0814e1b0: @ 0x0814E1B0
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0814E1C8 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814E1CC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814E1CE
	.align 2, 0
_0814E1C8: .4byte 0x0000046D
_0814E1CC:
	movs r0, #0
_0814E1CE:
	cmp r0, #0
	beq _0814E1DA
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080ef86c
_0814E1DA:
	ldr r1, _0814E1F4 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814E1EC
	ldr r0, _0814E1F8 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0814E1EC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0814E1F4: .4byte 0x0000046E
_0814E1F8: .4byte 0x0000046B

	thumb_func_start FUN_0814e1fc
FUN_0814e1fc: @ 0x0814E1FC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0814E214 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814E218
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814E21A
	.align 2, 0
_0814E214: .4byte 0x0000046D
_0814E218:
	movs r0, #0
_0814E21A:
	cmp r0, #0
	beq _0814E226
	adds r0, r4, #0
	movs r1, #0xe
	bl FUN_080ef86c
_0814E226:
	ldr r1, _0814E240 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814E238
	ldr r0, _0814E244 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0814E238:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0814E240: .4byte 0x0000046E
_0814E244: .4byte 0x0000046B

	thumb_func_start FUN_0814e248
FUN_0814e248: @ 0x0814E248
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _0814E260 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814E264
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814E266
	.align 2, 0
_0814E260: .4byte 0x0000046D
_0814E264:
	movs r0, #0
_0814E266:
	cmp r0, #0
	beq _0814E28A
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _0814E310 @ =0x00000482
	adds r1, r6, r2
	movs r0, #2
	strh r0, [r1]
_0814E28A:
	ldr r3, _0814E314 @ =0x00000542
	adds r5, r6, r3
	ldrb r1, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _0814E384
	cmp r4, #0x14
	bgt _0814E29E
	b _0814E400
_0814E29E:
	movs r1, #3
	movs r2, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	movs r3, #0
	strb r1, [r0]
	ldr r7, _0814E318 @ =0x00000469
	adds r0, r6, r7
	strb r2, [r0]
	ldr r1, _0814E31C @ =0x0000046A
	adds r0, r6, r1
	strb r3, [r0]
	adds r4, #0x1c
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #3
	adds r0, r6, r7
	strb r2, [r0]
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r4, [r0]
	movs r1, #2
	adds r7, #1
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _0814E320 @ =0x0000046B
	adds r0, r6, r2
	strb r3, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r3, [r0]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #1
	bne _0814E328
	ldr r3, _0814E324 @ =0x00000541
	adds r0, r6, r3
	ldrb r0, [r0]
	lsrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r6, r4
	b _0814E364
	.align 2, 0
_0814E310: .4byte 0x00000482
_0814E314: .4byte 0x00000542
_0814E318: .4byte 0x00000469
_0814E31C: .4byte 0x0000046A
_0814E320: .4byte 0x0000046B
_0814E324: .4byte 0x00000541
_0814E328:
	movs r1, #0
	ldrb r4, [r6, #5]
	ldr r7, _0814E374 @ =0x0203B400
	mov ip, r7
	ldr r2, _0814E378 @ =0x030046B8
	ldr r7, _0814E37C @ =0x000003FF
	movs r5, #3
	adds r3, r4, #0
_0814E338:
	ldr r0, [r2]
	adds r0, #1
	ands r0, r7
	str r0, [r2]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r3
	bne _0814E356
	adds r1, #1
	cmp r1, #3
	ble _0814E338
	adds r0, r4, #0
_0814E356:
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r6, r2
_0814E364:
	strb r0, [r1]
	ldr r3, _0814E380 @ =0x00000542
	adds r1, r6, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0814E400
	.align 2, 0
_0814E374: .4byte 0x0203B400
_0814E378: .4byte 0x030046B8
_0814E37C: .4byte 0x000003FF
_0814E380: .4byte 0x00000542
_0814E384:
	movs r0, #0xff
	orrs r0, r1
	strb r0, [r5]
	cmp r4, #6
	ble _0814E400
	ldr r4, _0814E408 @ =0x0000054F
	adds r0, r6, r4
	ldrb r2, [r0]
	movs r7, #0xa9
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r3, [r0]
	ldr r1, _0814E40C @ =0x0000046D
	adds r0, r6, r1
	movs r1, #0
	movs r5, #1
	strb r5, [r0]
	subs r4, #0xe4
	adds r0, r6, r4
	strb r1, [r0]
	adds r7, #0xb
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
	adds r4, #0xe1
	adds r0, r6, r4
	ldrb r2, [r0]
	subs r7, #6
	adds r0, r6, r7
	ldrb r3, [r0]
	adds r4, #2
	adds r0, r6, r4
	ldrb r4, [r0]
	subs r7, #0xe5
	adds r0, r6, r7
	strb r2, [r0]
	ldr r2, _0814E410 @ =0x00000469
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _0814E414 @ =0x0000046A
	adds r0, r6, r3
	strb r4, [r0]
	ldr r4, _0814E418 @ =0x00000484
	adds r0, r6, r4
	str r1, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _0814E41C @ =0xFFFFFBFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_0814E400:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814E408: .4byte 0x0000054F
_0814E40C: .4byte 0x0000046D
_0814E410: .4byte 0x00000469
_0814E414: .4byte 0x0000046A
_0814E418: .4byte 0x00000484
_0814E41C: .4byte 0xFFFFFBFF

	thumb_func_start FUN_0814e420
FUN_0814e420: @ 0x0814E420
	bx lr
	.align 2, 0

	thumb_func_start FUN_0814e424
FUN_0814e424: @ 0x0814E424
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0814E448 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814E44C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814E44E
	.align 2, 0
_0814E448: .4byte 0x0000046D
_0814E44C:
	movs r0, #0
_0814E44E:
	cmp r0, #0
	bne _0814E522
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_080ef86c
	adds r0, r4, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814E522
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r3, _0814E49C @ =0x000004A4
	adds r0, r4, r3
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
	bne _0814E4A0
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	b _0814E4C6
	.align 2, 0
_0814E49C: .4byte 0x000004A4
_0814E4A0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0814E4C0
	cmp r0, #2
	beq _0814E4BC
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814E4BC:
	movs r0, #1
	b _0814E4D0
_0814E4C0:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r4, r3
_0814E4C6:
	ldr r1, _0814E4E4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814E4D0:
	cmp r0, #0
	bne _0814E4EC
	ldr r1, _0814E4E8 @ =0x000005C4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _0814E522
	.align 2, 0
_0814E4E4: .4byte 0xFFFFFDFF
_0814E4E8: .4byte 0x000005C4
_0814E4EC:
	movs r2, #0xd5
	lsls r2, r2, #3
	add r2, r8
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x11
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0814E52C @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_0814E522:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0814E52C: .4byte 0x00000484

	thumb_func_start FUN_0814e530
FUN_0814e530: @ 0x0814E530
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	ldr r2, _0814E550 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814E554
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814E556
	.align 2, 0
_0814E550: .4byte 0x0000046D
_0814E554:
	movs r0, #0
_0814E556:
	cmp r0, #0
	beq _0814E55C
	b _0814E67A
_0814E55C:
	movs r2, #4
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _0814E572
	movs r0, #1
	b _0814E574
_0814E572:
	movs r0, #0
_0814E574:
	cmp r0, #0
	bne _0814E57A
	b _0814E672
_0814E57A:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, _0814E5C0 @ =0x000006BC
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _0814E5C8
	movs r2, #0x13
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0814E5C4 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bge _0814E64E
	b _0814E65C
	.align 2, 0
_0814E5C0: .4byte 0x000006BC
_0814E5C4: .4byte 0x00000484
_0814E5C8:
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r1, _0814E614 @ =0x000006D7
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _0814E61C
	ldrb r1, [r4, #5]
	adds r0, r4, #0
	bl FUN_0814b090
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814E67A
	movs r2, #0x11
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0814E618 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _0814E67A
	.align 2, 0
_0814E614: .4byte 0x000006D7
_0814E618: .4byte 0x00000484
_0814E61C:
	movs r2, #0x13
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0814E654 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	ldr r2, _0814E658 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	blt _0814E65C
_0814E64E:
	asrs r0, r0, #5
	b _0814E662
	.align 2, 0
_0814E654: .4byte 0x00000469
_0814E658: .4byte 0x00000484
_0814E65C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0814E662:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r4, r2
	strb r0, [r1]
	b _0814E67A
_0814E672:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
_0814E67A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0814e680
FUN_0814e680: @ 0x0814E680
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	ldr r0, _0814E698 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814E69C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814E69E
	.align 2, 0
_0814E698: .4byte 0x0000046D
_0814E69C:
	movs r0, #0
_0814E69E:
	cmp r0, #0
	beq _0814E712
	adds r0, r5, #0
	movs r1, #0xa
	bl FUN_080ef86c
	ldr r1, _0814E7D8 @ =0x0000046E
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080e64b4
	adds r0, r5, #0
	bl FUN_080e8360
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r2, r5, r6
	ldr r1, _0814E7DC @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0814E7E0 @ =0x0000021E
	adds r0, r5, r1
	strh r4, [r0]
	movs r2, #0x88
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	adds r6, #0x8a
	adds r0, r5, r6
	strh r4, [r0]
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_0814E712:
	adds r0, r5, #0
	bl FUN_080e499c
	adds r0, r5, #0
	bl FUN_080e4b3c
	adds r0, r5, #0
	bl FUN_080e4e20
	ldr r1, _0814E7D8 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814E730
	b _0814E8D8
_0814E730:
	subs r1, #0x6e
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _0814E742
	b _0814E8B0
_0814E742:
	ldr r6, _0814E7E4 @ =0x0000046B
	adds r0, r5, r6
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_0814afc8
	movs r0, #0xcd
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _0814E7B0
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r6, #0xa
	ldrsh r0, [r5, r6]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r6, #8
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	str r0, [sp, #0x1c]
	ldr r1, _0814E7E8 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r6, sp
	str r6, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0814E7B0:
	ldr r1, _0814E7EC @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0814E7F4
	ldr r0, _0814E7F0 @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe2
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r1, r4, #0
	lsls r1, r3
	b _0814E806
	.align 2, 0
_0814E7D8: .4byte 0x0000046E
_0814E7DC: .4byte 0xFFFEBE3F
_0814E7E0: .4byte 0x0000021E
_0814E7E4: .4byte 0x0000046B
_0814E7E8: .4byte 0xFFFF0000
_0814E7EC: .4byte 0x000001DF
_0814E7F0: .4byte 0x030046A0
_0814E7F4:
	ldr r0, _0814E890 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0814E806:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0814E86E
	ldr r3, _0814E894 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r6, _0814E898 @ =0x0000046D
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r2, #0
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _0814E89C @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
_0814E86E:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl FUN_080136b4
	movs r2, #1
	ldr r1, _0814E8A0 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814E8A4
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0814E8D8
	.align 2, 0
_0814E890: .4byte 0x030046A0
_0814E894: .4byte FUN_080e48d0
_0814E898: .4byte 0x0000046D
_0814E89C: .4byte 0x0000046A
_0814E8A0: .4byte 0x0000025D
_0814E8A4:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	b _0814E8D8
_0814E8B0:
	ldr r3, _0814E8E0 @ =FUN_0814e8ec
	movs r2, #0x26
	ldr r6, _0814E8E4 @ =0x0000046D
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814E8E8 @ =0x0000046B
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
_0814E8D8:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0814E8E0: .4byte FUN_0814e8ec
_0814E8E4: .4byte 0x0000046D
_0814E8E8: .4byte 0x0000046B

	thumb_func_start FUN_0814e8ec
FUN_0814e8ec: @ 0x0814E8EC
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	adds r4, r1, #0
	bl FUN_080e499c
	adds r0, r5, #0
	bl FUN_080e4b3c
	adds r0, r5, #0
	bl FUN_080e4e20
	ldr r0, [r5, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814E918
	b _0814EA7C
_0814E918:
	ldr r1, _0814E9B0 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_0814afc8
	movs r6, #0xcd
	lsls r6, r6, #1
	adds r2, r5, r6
	ldrh r0, [r2]
	cmp r0, #0
	beq _0814E986
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r6, #0xa
	ldrsh r0, [r5, r6]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r6, #0xce
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r6, #8
	adds r0, r5, r6
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	str r0, [sp, #0x1c]
	ldr r1, _0814E9B4 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r6, sp
	str r6, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0814E986:
	ldr r1, _0814E9B8 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0814E9C0
	ldr r0, _0814E9BC @ =0x030046A0
	ldr r2, [r0]
	movs r6, #0xe2
	lsls r6, r6, #2
	adds r2, r2, r6
	adds r1, r4, #0
	lsls r1, r3
	b _0814E9D2
	.align 2, 0
_0814E9B0: .4byte 0x0000046B
_0814E9B4: .4byte 0xFFFF0000
_0814E9B8: .4byte 0x000001DF
_0814E9BC: .4byte 0x030046A0
_0814E9C0:
	ldr r0, _0814EA5C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0814E9D2:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #7
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0814EA3A
	ldr r3, _0814EA60 @ =FUN_080e48d0
	movs r2, #0x10
	ldr r6, _0814EA64 @ =0x0000046D
	adds r0, r5, r6
	movs r1, #1
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r2, #0
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _0814EA68 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
_0814EA3A:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl FUN_080136b4
	movs r2, #1
	ldr r1, _0814EA6C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814EA70
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _0814EAC2
	.align 2, 0
_0814EA5C: .4byte 0x030046A0
_0814EA60: .4byte FUN_080e48d0
_0814EA64: .4byte 0x0000046D
_0814EA68: .4byte 0x0000046A
_0814EA6C: .4byte 0x0000025D
_0814EA70:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	b _0814EAC2
_0814EA7C:
	movs r1, #1
	ldr r2, _0814EA94 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0814EA98
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0814EAA2
	b _0814EAA6
	.align 2, 0
_0814EA94: .4byte 0x0000025D
_0814EA98:
	ldr r0, [r5, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _0814EAA6
_0814EAA2:
	movs r0, #1
	b _0814EAA8
_0814EAA6:
	movs r0, #0
_0814EAA8:
	cmp r0, #0
	beq _0814EAB8
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl FUN_080136b4
	b _0814EAC2
_0814EAB8:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_08013698
_0814EAC2:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0814eacc
FUN_0814eacc: @ 0x0814EACC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xbc
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r4, _0814EB08 @ =0x00008002
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r7, r2
	ldrh r2, [r3]
	ands r4, r2
	cmp r4, #0
	beq _0814EB0C
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r2
	strh r0, [r3]
_0814EB02:
	movs r0, #0
	bl FUN_0814fb76
	.align 2, 0
_0814EB08: .4byte 0x00008002
_0814EB0C:
	ldr r5, _0814EB8C @ =0x0000049C
	adds r0, r7, r5
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _0814EBA4
	ldr r1, _0814EB90 @ =0x000005CC
	adds r0, r7, r1
	ldr r2, [r0]
	movs r1, #0x12
	ldr r3, _0814EB94 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	subs r5, #0x31
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	movs r2, #0
	strh r4, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0814EB98 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	adds r5, #2
	adds r0, r7, r5
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _0814EB9C @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r7, r3
	ldr r1, _0814EBA0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r4, #0xd5
	lsls r4, r4, #3
	adds r2, r6, r4
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	bl _0814FB74
	.align 2, 0
_0814EB8C: .4byte 0x0000049C
_0814EB90: .4byte 0x000005CC
_0814EB94: .4byte 0x0000046D
_0814EB98: .4byte 0x00000469
_0814EB9C: .4byte 0x0000046C
_0814EBA0: .4byte 0xFEFFFFFF
_0814EBA4:
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r1, r2
	strh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0814EB02
	ldr r5, _0814EC7C @ =0x000004BE
	adds r0, r7, r5
	ldrh r0, [r0]
	cmp r0, #0
	bne _0814EB02
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0814EBCC
	bl FUN_0814f410
_0814EBCC:
	ldr r0, _0814EC80 @ =0x0000048D
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _0814EBF8
	ldr r1, _0814EC84 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0814EBF8
	ldr r3, _0814EC7C @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_0814EBF8:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r3, r7, r4
	ldr r0, [r3]
	cmp r0, #0
	bne _0814EC06
	b _0814EB02
_0814EC06:
	movs r2, #0x80
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #4
	ldr r1, _0814EC88 @ =0x00000222
	adds r4, r7, r1
	ldrh r1, [r4]
	movs r5, #0
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _0814EC8C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r3]
	adds r0, r7, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	str r4, [sp, #0xb0]
	cmp r0, #0
	bne _0814EC3A
	b _0814F344
_0814EC3A:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r7, r2
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r4, #0
	blt _0814EC76
	cmp r1, #0
	blt _0814EC76
	ldr r0, _0814EC90 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0814EC76
	ldr r0, _0814EC94 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814EC98
_0814EC76:
	movs r4, #0
	b _0814ECA6
	.align 2, 0
_0814EC7C: .4byte 0x000004BE
_0814EC80: .4byte 0x0000048D
_0814EC84: .4byte 0x0000048C
_0814EC88: .4byte 0x00000222
_0814EC8C: .4byte 0x03002BE0
_0814EC90: .4byte 0x030046A8
_0814EC94: .4byte 0x030046AC
_0814EC98:
	ldr r0, _0814ECB8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0814ECA6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814ECBC
	adds r0, #4
	b _0814ECC8
	.align 2, 0
_0814ECB8: .4byte 0x030046A4
_0814ECBC:
	ldr r0, _0814ECDC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814ECC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814ECE0
	cmp r2, #2
	beq _0814ECE4
	b _0814ECE8
	.align 2, 0
_0814ECDC: .4byte 0x030046A4
_0814ECE0:
	ldrb r0, [r5, #4]
	b _0814ECE6
_0814ECE4:
	ldrb r0, [r5]
_0814ECE6:
	subs r1, r1, r0
_0814ECE8:
	strh r1, [r5, #2]
	ldr r0, _0814ECFC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814ED00
	movs r0, #1
	b _0814ED02
	.align 2, 0
_0814ECFC: .4byte 0x030047A4
_0814ED00:
	movs r0, #0
_0814ED02:
	cmp r0, #0
	beq _0814ED40
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _0814ED22
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0814ED1E
	adds r2, r0, #0
_0814ED1E:
	cmp r2, #0
	bge _0814ED2C
_0814ED22:
	ldr r4, _0814ED28 @ =0x000005C4
	adds r0, r7, r4
	b _0814F24C
	.align 2, 0
_0814ED28: .4byte 0x000005C4
_0814ED2C:
	ldr r1, _0814ED3C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0814ED88
	.align 2, 0
_0814ED3C: .4byte 0x03002BE0
_0814ED40:
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814ED6C
	cmp r1, #0
	blt _0814ED6C
	ldr r0, _0814ED70 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814ED6C
	ldr r0, _0814ED74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814ED78
_0814ED6C:
	movs r5, #0
	b _0814ED86
	.align 2, 0
_0814ED70: .4byte 0x030046A8
_0814ED74: .4byte 0x030046AC
_0814ED78:
	ldr r0, _0814EDC8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0814ED86:
	movs r2, #0
_0814ED88:
	ldr r6, _0814EDCC @ =0x00000256
	adds r0, r7, r6
	ldrh r0, [r0]
	cmp r5, r0
	beq _0814EDA8
	ldr r1, _0814EDD0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0814EDA8
	b _0814F190
_0814EDA8:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	str r2, [sp, #0x98]
	cmp r1, #0
	beq _0814EDD4
	movs r0, #0
	b _0814F262
	.align 2, 0
_0814EDC8: .4byte 0x030046A4
_0814EDCC: .4byte 0x00000256
_0814EDD0: .4byte 0x03002BE0
_0814EDD4:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r2, [sp, #0xb0]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x98]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0814EE80
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0814EE70 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x10]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _0814EE74 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x14]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x18]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r5, r7
	mov r8, r5
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sb
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _0814EE78 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0814EE7C @ =0x00000484
	adds r1, r7, r6
	mov r0, sb
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x10]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x14]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x18]
	str r6, [sp, #0xac]
	mov r6, r8
	str r6, [sp, #0xb4]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _0814F04E
	.align 2, 0
_0814EE70: .4byte 0x0000046D
_0814EE74: .4byte 0x0000046B
_0814EE78: .4byte 0x00000469
_0814EE7C: .4byte 0x00000484
_0814EE80:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, _0814EF40 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x1c]
	strb r0, [r3]
	ldr r4, _0814EF44 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x20]
	movs r5, #0
	strb r5, [r4]
	ldr r6, _0814EF48 @ =0x00000553
	adds r6, r7, r6
	str r6, [sp, #0x24]
	strb r0, [r6]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x28]
	str r1, [r3]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strh r2, [r4]
	movs r1, #5
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x30]
	movs r6, #0
	strb r6, [r5]
	ldr r3, _0814EF4C @ =0x00000469
	adds r5, r7, r3
	strb r6, [r5]
	ldr r6, _0814EF50 @ =0x0000046A
	adds r4, r7, r6
	strb r1, [r4]
	ldr r1, _0814EF54 @ =0x00000484
	adds r3, r7, r1
	str r2, [r3]
	adds r6, #2
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x34]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x34]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x34]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov ip, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x20]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x28]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x30]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, ip
	cmp r0, #0
	blt _0814EF3C
	cmp r1, #0
	blt _0814EF3C
	ldr r0, _0814EF58 @ =0x030046A8
	ldr r0, [r0]
	cmp ip, r0
	bhs _0814EF3C
	ldr r0, _0814EF5C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814EF60
_0814EF3C:
	movs r4, #0
	b _0814EF70
	.align 2, 0
_0814EF40: .4byte 0x0000046D
_0814EF44: .4byte 0x0000046B
_0814EF48: .4byte 0x00000553
_0814EF4C: .4byte 0x00000469
_0814EF50: .4byte 0x0000046A
_0814EF54: .4byte 0x00000484
_0814EF58: .4byte 0x030046A8
_0814EF5C: .4byte 0x030046AC
_0814EF60:
	ldr r0, _0814EF80 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, ip
	adds r4, r0, r1
_0814EF70:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814EF84
	adds r0, #4
	b _0814EF90
	.align 2, 0
_0814EF80: .4byte 0x030046A4
_0814EF84:
	ldr r0, _0814EFA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814EF90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814EFA8
	cmp r2, #2
	beq _0814EFAE
	b _0814EFB4
	.align 2, 0
_0814EFA4: .4byte 0x030046A4
_0814EFA8:
	ldr r2, [sp, #0x34]
	ldrb r0, [r2, #4]
	b _0814EFB2
_0814EFAE:
	ldr r3, [sp, #0x34]
	ldrb r0, [r3]
_0814EFB2:
	subs r1, r1, r0
_0814EFB4:
	ldr r4, [sp, #0x34]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814EFE0
	cmp r1, #0
	blt _0814EFE0
	ldr r0, _0814EFE4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814EFE0
	ldr r0, _0814EFE8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814EFEC
_0814EFE0:
	movs r4, #0
	b _0814EFFA
	.align 2, 0
_0814EFE4: .4byte 0x030046A8
_0814EFE8: .4byte 0x030046AC
_0814EFEC:
	ldr r0, _0814F010 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814EFFA:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814F014
	adds r0, #4
	b _0814F020
	.align 2, 0
_0814F010: .4byte 0x030046A4
_0814F014:
	ldr r0, _0814F034 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814F020:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814F038
	cmp r3, #2
	beq _0814F03C
	b _0814F040
	.align 2, 0
_0814F034: .4byte 0x030046A4
_0814F038:
	ldrb r0, [r5, #4]
	b _0814F03E
_0814F03C:
	ldrb r0, [r5]
_0814F03E:
	subs r2, r2, r0
_0814F040:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0814F04E:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x38]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0814F078 @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _0814F158
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0814F07C
	movs r0, #1
	b _0814F07E
	.align 2, 0
_0814F078: .4byte 0x00000482
_0814F07C:
	movs r0, #0
_0814F07E:
	ldr r1, _0814F168 @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _0814F158
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _0814F16C @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0814F170 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0814F174 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _0814F178 @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _0814F17C @ =0x000005BC
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0814F180 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _0814F184 @ =0x030046B8
	adds r2, r4, #0
_0814F0C6:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0814F188 @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0814F18C @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0814F0EA
	adds r3, #1
	cmp r3, #3
	ble _0814F0C6
	adds r0, r4, #0
_0814F0EA:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x38
	ldrb r1, [r0]
	ldr r0, [sp, #0xa0]
	strb r1, [r0]
	mov r1, ip
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xac]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_0814F158:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _0814F262
	.align 2, 0
_0814F168: .4byte 0x00000482
_0814F16C: .4byte 0x0000054F
_0814F170: .4byte 0x0000054C
_0814F174: .4byte 0x0000054E
_0814F178: .4byte 0x00000541
_0814F17C: .4byte 0x000005BC
_0814F180: .4byte 0x00000542
_0814F184: .4byte 0x030046B8
_0814F188: .4byte 0x000003FF
_0814F18C: .4byte 0x0203B400
_0814F190:
	mov sb, sp
	ldr r6, _0814F1CC @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
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
	beq _0814F1D0
	adds r0, #4
	b _0814F1DA
	.align 2, 0
_0814F1CC: .4byte 0x030046A4
_0814F1D0:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814F1DA:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0814F210 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _0814F214
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _0814F23A
	.align 2, 0
_0814F210: .4byte 0x000004A4
_0814F214:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _0814F234
	cmp r0, #2
	beq _0814F230
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814F230:
	movs r0, #1
	b _0814F244
_0814F234:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_0814F23A:
	ldr r1, _0814F258 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814F244:
	cmp r0, #0
	bne _0814F260
	ldr r3, _0814F25C @ =0x000005C4
	adds r0, r7, r3
_0814F24C:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0814F262
	.align 2, 0
_0814F258: .4byte 0xFFFFFDFF
_0814F25C: .4byte 0x000005C4
_0814F260:
	movs r0, #1
_0814F262:
	cmp r0, #0
	bne _0814F2DC
	ldr r4, _0814F294 @ =0x000004A4
	adds r0, r7, r4
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0814F298
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0814F2BE
	.align 2, 0
_0814F294: .4byte 0x000004A4
_0814F298:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0814F2B8
	cmp r0, #2
	beq _0814F2B4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814F2B4:
	movs r0, #1
	b _0814F2C8
_0814F2B8:
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r7, r3
_0814F2BE:
	ldr r1, _0814F2D4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814F2C8:
	cmp r0, #0
	bne _0814F2DC
	ldr r4, _0814F2D8 @ =0x000005C4
	adds r0, r7, r4
	bl FUN_0814fb08
	.align 2, 0
_0814F2D4: .4byte 0xFFFFFDFF
_0814F2D8: .4byte 0x000005C4
_0814F2DC:
	movs r5, #0xb7
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r1, #0x1a
	ldr r6, _0814F334 @ =0x0000046D
	adds r0, r7, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r5, _0814F338 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r1, #0
	strh r2, [r0]
	movs r3, #0xc
	subs r5, #3
	adds r0, r7, r5
	strb r1, [r0]
	subs r6, #0xea
	adds r0, r7, r6
	strb r1, [r0]
	ldr r1, _0814F33C @ =0x0000046A
	adds r0, r7, r1
	strb r3, [r0]
	ldr r3, _0814F340 @ =0x00000484
	adds r0, r7, r3
	str r2, [r0]
	adds r5, #4
	adds r0, r7, r5
	strb r4, [r0]
	bl _0814FB74
	.align 2, 0
_0814F334: .4byte 0x0000046D
_0814F338: .4byte 0x0000046B
_0814F33C: .4byte 0x0000046A
_0814F340: .4byte 0x00000484
_0814F344:
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r4, [r0]
	cmp r4, #0
	beq _0814F354
	bl _0814FB74
_0814F354:
	ldr r2, _0814F3BC @ =FUN_080e48d0
	mov r8, r2
	movs r1, #0x10
	ldr r3, _0814F3C0 @ =0x0000046D
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r2, _0814F3C4 @ =0x0000046B
	adds r0, r7, r2
	strb r5, [r0]
	adds r2, #0xe8
	adds r0, r7, r2
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r1, #0x12
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r7, r2
	strb r5, [r0]
	ldr r5, _0814F3C8 @ =0x0000046A
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0814F3CC @ =0x00000484
	adds r0, r7, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r7, r2
	strb r3, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xa0
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _0814F3D0
	asrs r0, r1, #5
	b _0814F3D6
	.align 2, 0
_0814F3BC: .4byte FUN_080e48d0
_0814F3C0: .4byte 0x0000046D
_0814F3C4: .4byte 0x0000046B
_0814F3C8: .4byte 0x0000046A
_0814F3CC: .4byte 0x00000484
_0814F3D0:
	rsbs r0, r1, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_0814F3D6:
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r7, r4
	strb r0, [r1]
	ldrb r1, [r7, #5]
	adds r0, r1, #0
	adds r0, #0xa0
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	lsls r0, r0, #6
	strb r0, [r7, #5]
	movs r5, #0xdb
	lsls r5, r5, #3
	adds r2, r6, r5
	movs r0, #0x5a
	strb r0, [r2]
	adds r0, r7, #0
	bl FUN_0814b090
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814F40C
	b _0814FB74
_0814F40C:
	bl _0814EB02

	thumb_func_start FUN_0814f410
FUN_0814f410: @ 0x0814F410
	ldr r6, _0814F4AC @ =0x0000048D
	adds r2, r7, r6
	ldrb r0, [r2]
	cmp r0, #0
	bne _0814F43C
	ldr r1, _0814F4B0 @ =0x0000048C
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0814F43C
	ldr r3, _0814F4B4 @ =0x000004BE
	adds r0, r7, r3
	movs r1, #0x2d
	strh r1, [r0]
	movs r0, #0x41
	strb r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_0814F43C:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r7, r4
	ldr r0, [r1]
	cmp r0, #0
	bne _0814F44C
	bl _0814EB02
_0814F44C:
	ldr r0, _0814F4B8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #6]
	adds r3, r7, r6
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x94]
	str r2, [sp, #0x70]
	cmp r4, #0
	blt _0814F4A6
	cmp r1, #0
	blt _0814F4A6
	ldr r0, _0814F4BC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0814F4A6
	ldr r0, _0814F4C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814F4C4
_0814F4A6:
	movs r4, #0
	b _0814F4D2
	.align 2, 0
_0814F4AC: .4byte 0x0000048D
_0814F4B0: .4byte 0x0000048C
_0814F4B4: .4byte 0x000004BE
_0814F4B8: .4byte 0x03002BE0
_0814F4BC: .4byte 0x030046A8
_0814F4C0: .4byte 0x030046AC
_0814F4C4:
	ldr r0, _0814F4E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0814F4D2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814F4E8
	adds r0, #4
	b _0814F4F4
	.align 2, 0
_0814F4E4: .4byte 0x030046A4
_0814F4E8:
	ldr r0, _0814F508 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814F4F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814F50C
	cmp r2, #2
	beq _0814F510
	b _0814F514
	.align 2, 0
_0814F508: .4byte 0x030046A4
_0814F50C:
	ldrb r0, [r5, #4]
	b _0814F512
_0814F510:
	ldrb r0, [r5]
_0814F512:
	subs r1, r1, r0
_0814F514:
	strh r1, [r5, #2]
	ldr r0, _0814F528 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814F52C
	movs r0, #1
	b _0814F52E
	.align 2, 0
_0814F528: .4byte 0x030047A4
_0814F52C:
	movs r0, #0
_0814F52E:
	cmp r0, #0
	beq _0814F564
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0814F540
	b _0814FA80
_0814F540:
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0814F54C
	adds r2, r0, #0
_0814F54C:
	cmp r2, #0
	bge _0814F552
	b _0814FA80
_0814F552:
	ldr r1, _0814F560 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0814F5AC
	.align 2, 0
_0814F560: .4byte 0x03002BE0
_0814F564:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814F590
	cmp r1, #0
	blt _0814F590
	ldr r0, _0814F594 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814F590
	ldr r0, _0814F598 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814F59C
_0814F590:
	movs r5, #0
	b _0814F5AA
	.align 2, 0
_0814F594: .4byte 0x030046A8
_0814F598: .4byte 0x030046AC
_0814F59C:
	ldr r0, _0814F5EC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0814F5AA:
	movs r2, #0
_0814F5AC:
	ldr r4, _0814F5F0 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0814F5CC
	ldr r1, _0814F5F4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0814F5CC
	b _0814F9C4
_0814F5CC:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x3c]
	str r2, [sp, #0x98]
	cmp r1, #0
	beq _0814F5F8
	movs r0, #0
	b _0814FA9A
	.align 2, 0
_0814F5EC: .4byte 0x030046A4
_0814F5F0: .4byte 0x00000256
_0814F5F4: .4byte 0x03002BE0
_0814F5F8:
	ldr r6, _0814F69C @ =0x00000222
	adds r2, r7, r6
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x98]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r2, [sp, #0xb0]
	cmp r6, #0
	beq _0814F6B0
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	ldr r5, _0814F6A0 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x40]
	movs r6, #1
	strb r6, [r5]
	ldr r2, _0814F6A4 @ =0x0000046B
	adds r2, r7, r2
	str r2, [sp, #0x44]
	movs r3, #0
	strb r3, [r2]
	subs r4, #0x65
	adds r4, r7, r4
	str r4, [sp, #0x48]
	strb r0, [r4]
	movs r5, #0xaf
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	str r1, [r5]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r5, r7, r6
	mov r0, sp
	ldrh r0, [r0, #0x3c]
	strh r0, [r5]
	movs r0, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r4, r7, r1
	strb r3, [r4]
	ldr r2, _0814F6A8 @ =0x00000469
	adds r3, r7, r2
	movs r6, #0
	strb r6, [r3]
	adds r1, #2
	adds r2, r7, r1
	strb r0, [r2]
	ldr r6, _0814F6AC @ =0x00000484
	adds r1, r7, r6
	ldr r0, [sp, #0x3c]
	str r0, [r1]
	subs r6, #0x18
	adds r0, r7, r6
	movs r6, #1
	strb r6, [r0]
	ldr r6, [sp, #0x40]
	str r6, [sp, #0x88]
	ldr r6, [sp, #0x44]
	str r6, [sp, #0x80]
	ldr r6, [sp, #0x48]
	str r6, [sp, #0xac]
	ldr r6, [sp, #0x4c]
	str r6, [sp, #0xb4]
	str r5, [sp, #0x9c]
	str r4, [sp, #0x74]
	str r3, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r1, [sp, #0x90]
	str r0, [sp, #0x84]
	b _0814F882
	.align 2, 0
_0814F69C: .4byte 0x00000222
_0814F6A0: .4byte 0x0000046D
_0814F6A4: .4byte 0x0000046B
_0814F6A8: .4byte 0x00000469
_0814F6AC: .4byte 0x00000484
_0814F6B0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, _0814F774 @ =0x0000046D
	adds r2, r7, r2
	str r2, [sp, #0x50]
	strb r0, [r2]
	ldr r3, _0814F778 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x54]
	movs r4, #0
	strb r4, [r3]
	ldr r5, _0814F77C @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0x58]
	strb r0, [r5]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	str r1, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x60]
	strh r6, [r3]
	movs r1, #5
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0
	strb r5, [r4]
	ldr r2, _0814F780 @ =0x00000469
	adds r5, r7, r2
	movs r3, #0
	strb r3, [r5]
	adds r2, #1
	adds r4, r7, r2
	strb r1, [r4]
	ldr r1, _0814F784 @ =0x00000484
	adds r3, r7, r1
	str r6, [r3]
	ldr r6, _0814F788 @ =0x0000046C
	adds r2, r7, r6
	strb r0, [r2]
	ldr r0, [sp, #0x94]
	ldr r0, [r0]
	str r0, [sp, #0x68]
	ldr r1, [sp, #0x70]
	ldr r0, [r1, #8]
	ldrh r1, [r0]
	ldr r6, [sp, #0x68]
	strh r1, [r6]
	ldr r6, [sp, #0x70]
	ldr r0, [r6, #8]
	ldrh r0, [r0, #2]
	ldr r6, [sp, #0x68]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sl, r1
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x88]
	ldr r6, [sp, #0x54]
	str r6, [sp, #0x80]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0xac]
	ldr r6, [sp, #0x5c]
	str r6, [sp, #0xb4]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x9c]
	ldr r6, [sp, #0x64]
	str r6, [sp, #0x74]
	str r5, [sp, #0x78]
	str r4, [sp, #0x7c]
	str r3, [sp, #0x90]
	str r2, [sp, #0x84]
	mov r0, sl
	cmp r0, #0
	blt _0814F76E
	cmp r1, #0
	blt _0814F76E
	ldr r0, _0814F78C @ =0x030046A8
	ldr r0, [r0]
	cmp sl, r0
	bhs _0814F76E
	ldr r0, _0814F790 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814F794
_0814F76E:
	movs r4, #0
	b _0814F7A4
	.align 2, 0
_0814F774: .4byte 0x0000046D
_0814F778: .4byte 0x0000046B
_0814F77C: .4byte 0x00000553
_0814F780: .4byte 0x00000469
_0814F784: .4byte 0x00000484
_0814F788: .4byte 0x0000046C
_0814F78C: .4byte 0x030046A8
_0814F790: .4byte 0x030046AC
_0814F794:
	ldr r0, _0814F7B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r1, sl
	adds r4, r0, r1
_0814F7A4:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814F7B8
	adds r0, #4
	b _0814F7C4
	.align 2, 0
_0814F7B4: .4byte 0x030046A4
_0814F7B8:
	ldr r0, _0814F7D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814F7C4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814F7DC
	cmp r2, #2
	beq _0814F7E2
	b _0814F7E8
	.align 2, 0
_0814F7D8: .4byte 0x030046A4
_0814F7DC:
	ldr r2, [sp, #0x68]
	ldrb r0, [r2, #4]
	b _0814F7E6
_0814F7E2:
	ldr r3, [sp, #0x68]
	ldrb r0, [r3]
_0814F7E6:
	subs r1, r1, r0
_0814F7E8:
	ldr r4, [sp, #0x68]
	strh r1, [r4, #2]
	ldr r5, [sp, #0x94]
	ldr r0, [r5]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814F814
	cmp r1, #0
	blt _0814F814
	ldr r0, _0814F818 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814F814
	ldr r0, _0814F81C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814F820
_0814F814:
	movs r4, #0
	b _0814F82E
	.align 2, 0
_0814F818: .4byte 0x030046A8
_0814F81C: .4byte 0x030046AC
_0814F820:
	ldr r0, _0814F844 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814F82E:
	ldr r6, [sp, #0x94]
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814F848
	adds r0, #4
	b _0814F854
	.align 2, 0
_0814F844: .4byte 0x030046A4
_0814F848:
	ldr r0, _0814F868 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814F854:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0814F86C
	cmp r3, #2
	beq _0814F870
	b _0814F874
	.align 2, 0
_0814F868: .4byte 0x030046A4
_0814F86C:
	ldrb r0, [r5, #4]
	b _0814F872
_0814F870:
	ldrb r0, [r5]
_0814F872:
	subs r2, r2, r0
_0814F874:
	ldr r1, [sp, #0x94]
	ldr r0, [r1]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r2, [sp, #0x94]
	ldr r0, [r2]
	strh r1, [r0, #6]
_0814F882:
	ldrb r3, [r7, #5]
	str r3, [sp, #0x6c]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r4, [sp, #0x98]
	ldrh r0, [r4]
	ands r0, r1
	adds r4, r3, #0
	ldr r5, _0814F8AC @ =0x00000482
	adds r5, r7, r5
	str r5, [sp, #0x8c]
	cmp r0, #0
	bne _0814F98C
	movs r1, #4
	ldr r6, [sp, #0xb0]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0814F8B0
	movs r0, #1
	b _0814F8B2
	.align 2, 0
_0814F8AC: .4byte 0x00000482
_0814F8B0:
	movs r0, #0
_0814F8B2:
	ldr r1, _0814F99C @ =0x00000482
	adds r1, r7, r1
	str r1, [sp, #0x8c]
	cmp r0, #0
	bne _0814F98C
	movs r3, #0
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r6, #0xa9
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xb8]
	ldr r0, _0814F9A0 @ =0x0000054F
	adds r0, r0, r7
	mov r8, r0
	ldr r1, _0814F9A4 @ =0x0000054C
	adds r1, r1, r7
	mov sb, r1
	adds r2, #0xd
	adds r2, r2, r7
	mov sl, r2
	ldr r6, _0814F9A8 @ =0x0000054E
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r0, _0814F9AC @ =0x00000541
	adds r0, r7, r0
	str r0, [sp, #0xa0]
	ldr r1, _0814F9B0 @ =0x000005BC
	adds r1, r1, r7
	mov ip, r1
	ldr r2, _0814F9B4 @ =0x00000542
	adds r2, r7, r2
	str r2, [sp, #0xa4]
	ldr r1, _0814F9B8 @ =0x030046B8
	adds r2, r4, #0
_0814F8FA:
	ldr r0, [r1]
	adds r0, #1
	ldr r6, _0814F9BC @ =0x000003FF
	ands r0, r6
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0814F9C0 @ =0x0203B400
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r6, #3
	ands r0, r6
	lsls r0, r0, #6
	cmp r0, r2
	bne _0814F91E
	adds r3, #1
	cmp r3, #3
	ble _0814F8FA
	adds r0, r4, #0
_0814F91E:
	movs r3, #0
	strb r0, [r5]
	ldr r1, [sp, #0xb4]
	ldr r0, [r1]
	ldr r2, [sp, #0xb8]
	str r0, [r2]
	ldr r4, [sp, #0xac]
	ldrb r0, [r4]
	mov r5, r8
	strb r0, [r5]
	ldr r6, [sp, #0x74]
	ldrb r0, [r6]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x78]
	ldrb r0, [r2]
	mov r4, sl
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xa8]
	strb r0, [r6]
	add r0, sp, #0x6c
	ldrb r1, [r0]
	ldr r0, [sp, #0xa0]
	strb r1, [r0]
	mov r1, ip
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x88]
	strb r1, [r4]
	ldr r5, [sp, #0x80]
	strb r3, [r5]
	ldr r6, [sp, #0xac]
	strb r0, [r6]
	ldr r0, [sp, #0xb4]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x9c]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x74]
	strb r0, [r5]
	ldr r6, [sp, #0x78]
	strb r1, [r6]
	ldr r0, [sp, #0x7c]
	strb r2, [r0]
	ldr r2, [sp, #0x90]
	str r3, [r2]
	ldr r3, [sp, #0x84]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0xa4]
	strb r0, [r4]
_0814F98C:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r5, [sp, #0x8c]
	strh r0, [r5]
	movs r0, #0
	b _0814FA9A
	.align 2, 0
_0814F99C: .4byte 0x00000482
_0814F9A0: .4byte 0x0000054F
_0814F9A4: .4byte 0x0000054C
_0814F9A8: .4byte 0x0000054E
_0814F9AC: .4byte 0x00000541
_0814F9B0: .4byte 0x000005BC
_0814F9B4: .4byte 0x00000542
_0814F9B8: .4byte 0x030046B8
_0814F9BC: .4byte 0x000003FF
_0814F9C0: .4byte 0x0203B400
_0814F9C4:
	add r6, sp, #8
	ldr r0, _0814FA04 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	mov sl, r6
	cmp r0, #0
	beq _0814FA08
	adds r0, #4
	b _0814FA14
	.align 2, 0
_0814FA04: .4byte 0x030046A4
_0814FA08:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0814FA14:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r5, _0814FA48 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_0823599c
	cmp r0, #0
	bne _0814FA4C
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
	b _0814FA72
	.align 2, 0
_0814FA48: .4byte 0x000004A4
_0814FA4C:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sl
	bl FUN_08235f40
	cmp r0, #0
	beq _0814FA6C
	cmp r0, #2
	beq _0814FA68
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814FA68:
	movs r0, #1
	b _0814FA7C
_0814FA6C:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
_0814FA72:
	ldr r1, _0814FA90 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814FA7C:
	cmp r0, #0
	bne _0814FA98
_0814FA80:
	ldr r2, _0814FA94 @ =0x000005C4
	adds r0, r7, r2
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0814FA9A
	.align 2, 0
_0814FA90: .4byte 0xFFFFFDFF
_0814FA94: .4byte 0x000005C4
_0814FA98:
	movs r0, #1
_0814FA9A:
	cmp r0, #0
	bne _0814FB1C
	ldr r3, _0814FACC @ =0x000004A4
	adds r0, r7, r3
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r7, r4
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0814FAD0
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r7, r5
	b _0814FAF6
	.align 2, 0
_0814FACC: .4byte 0x000004A4
_0814FAD0:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0814FAF0
	cmp r0, #2
	beq _0814FAEC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814FAEC:
	movs r0, #1
	b _0814FB00
_0814FAF0:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r7, r6
_0814FAF6:
	ldr r1, _0814FB14 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_0814FB00:
	cmp r0, #0
	bne _0814FB1C
	ldr r1, _0814FB18 @ =0x000005C4
	adds r0, r7, r1
FUN_0814fb08:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	bl _0814EB02
	.align 2, 0
_0814FB14: .4byte 0xFFFFFDFF
_0814FB18: .4byte 0x000005C4
_0814FB1C:
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r3, #1
	ldr r4, _0814FB88 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r3, [r0]
	ldr r5, _0814FB8C @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _0814FB90 @ =0x00000553
	adds r0, r7, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r7, r4
	str r1, [r0]
	movs r5, #0xe4
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r1, #0
	strh r2, [r0]
	movs r4, #7
	subs r6, #0xeb
	adds r0, r7, r6
	strb r1, [r0]
	ldr r5, _0814FB94 @ =0x00000469
	adds r0, r7, r5
	strb r1, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _0814FB98 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r2, _0814FB9C @ =0x0000046C
	adds r0, r7, r2
	strb r3, [r0]
	ldr r3, _0814FBA0 @ =0x00000482
	adds r1, r7, r3
	movs r0, #4
	strh r0, [r1]
_0814FB74:
	movs r0, #1
FUN_0814fb76:
	add sp, #0xbc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0814FB88: .4byte 0x0000046D
_0814FB8C: .4byte 0x0000046B
_0814FB90: .4byte 0x00000553
_0814FB94: .4byte 0x00000469
_0814FB98: .4byte 0x00000484
_0814FB9C: .4byte 0x0000046C
_0814FBA0: .4byte 0x00000482

	thumb_func_start FUN_0814fba4
FUN_0814fba4: @ 0x0814FBA4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0814FBBC @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814FBC0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814FBC2
	.align 2, 0
_0814FBBC: .4byte 0x0000046C
_0814FBC0:
	movs r0, #0
_0814FBC2:
	cmp r0, #0
	beq _0814FC40
	ldr r4, _0814FC54 @ =FUN_0814caa0
	movs r3, #0xa
	ldr r2, _0814FC58 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0814FC5C @ =0x0000046B
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
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	strb r0, [r5, #5]
	adds r1, #0x17
	adds r0, r5, r1
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5718
	adds r0, r5, #0
	bl FUN_080e6750
	ldr r2, _0814FC60 @ =0x000001DF
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #2
	beq _0814FC24
	movs r0, #4
	ldr r1, _0814FC64 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0814FC24:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
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
_0814FC40:
	ldr r1, _0814FC5C @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814FC68
	adds r0, r5, #0
	bl enemy_dog_0814a320
	b _0814FC72
	.align 2, 0
_0814FC54: .4byte FUN_0814caa0
_0814FC58: .4byte 0x0000046D
_0814FC5C: .4byte 0x0000046B
_0814FC60: .4byte 0x000001DF
_0814FC64: .4byte 0x00000222
_0814FC68:
	ldr r2, _0814FC78 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0814FC72:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0814FC78: .4byte 0x00000484

	thumb_func_start FUN_0814fc7c
FUN_0814fc7c: @ 0x0814FC7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r7, r0, #0
	ldr r0, _0814FDE0 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814FC98
	movs r0, #0
	strb r0, [r1]
_0814FC98:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814FCB0
	bl _081504D8
_0814FCB0:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _0814FCC2
	bl _081504D8
_0814FCC2:
	ldr r2, _0814FDE4 @ =0x00000484
	adds r1, r7, r2
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0814FCD0
	bl FUN_081504d4
_0814FCD0:
	ldr r3, _0814FDE8 @ =0x000001DF
	adds r0, r7, r3
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl FUN_080e5718
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _0814FDEC @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	movs r0, #1
	strb r0, [r5]
	ldr r1, _0814FDF0 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	strb r6, [r1]
	ldr r2, _0814FDE4 @ =0x00000484
	adds r2, r2, r7
	mov sl, r2
	str r6, [r2]
	ldr r3, _0814FDE0 @ =0x0000046C
	adds r3, r3, r7
	mov ip, r3
	strb r0, [r3]
	ldr r1, _0814FDF4 @ =FUN_080e6794
	movs r0, #0xe
	ldr r4, _0814FDF8 @ =0x0000046D
	adds r4, r4, r7
	mov sb, r4
	movs r5, #1
	strb r5, [r4]
	ldr r2, _0814FDFC @ =0x0000046B
	adds r2, r2, r7
	mov r8, r2
	strb r6, [r2]
	ldr r3, _0814FE00 @ =0x00000553
	adds r5, r7, r3
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r4, r7, r0
	str r1, [r4]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r3, r7, r1
	strh r6, [r3]
	movs r0, #0x80
	subs r1, #0x48
	adds r2, r7, r1
	ldrh r1, [r2]
	ands r1, r0
	mov r0, ip
	str r0, [sp, #0x44]
	ldr r0, [sp, #8]
	str r0, [sp, #0x34]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x3c]
	mov r0, sl
	str r0, [sp, #0x50]
	mov r0, sb
	str r0, [sp, #0x48]
	mov r0, r8
	str r0, [sp, #0x40]
	str r5, [sp, #0x24]
	str r4, [sp, #0x2c]
	str r3, [sp, #0x28]
	mov sl, r2
	cmp r1, #0
	bne _0814FD6E
	b _08150308
_0814FD6E:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
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
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0814FE04 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _0814FDDA
	cmp r1, #0
	blt _0814FDDA
	ldr r0, _0814FE08 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0814FDDA
	ldr r0, _0814FE0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814FE10
_0814FDDA:
	movs r4, #0
	b _0814FE1E
	.align 2, 0
_0814FDE0: .4byte 0x0000046C
_0814FDE4: .4byte 0x00000484
_0814FDE8: .4byte 0x000001DF
_0814FDEC: .4byte 0x00000469
_0814FDF0: .4byte 0x0000046A
_0814FDF4: .4byte FUN_080e6794
_0814FDF8: .4byte 0x0000046D
_0814FDFC: .4byte 0x0000046B
_0814FE00: .4byte 0x00000553
_0814FE04: .4byte 0x00000551
_0814FE08: .4byte 0x030046A8
_0814FE0C: .4byte 0x030046AC
_0814FE10:
	ldr r0, _0814FE30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0814FE1E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814FE34
	adds r0, #4
	b _0814FE40
	.align 2, 0
_0814FE30: .4byte 0x030046A4
_0814FE34:
	ldr r0, _0814FE54 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0814FE40:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814FE58
	cmp r2, #2
	beq _0814FE5C
	b _0814FE60
	.align 2, 0
_0814FE54: .4byte 0x030046A4
_0814FE58:
	ldrb r0, [r5, #4]
	b _0814FE5E
_0814FE5C:
	ldrb r0, [r5]
_0814FE5E:
	subs r1, r1, r0
_0814FE60:
	strh r1, [r5, #2]
	ldr r0, _0814FE74 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0814FE78
	movs r0, #1
	b _0814FE7A
	.align 2, 0
_0814FE74: .4byte 0x030047A4
_0814FE78:
	movs r0, #0
_0814FE7A:
	cmp r0, #0
	beq _0814FEB8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0814FE9A
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0814FE96
	adds r2, r0, #0
_0814FE96:
	cmp r2, #0
	bge _0814FEA4
_0814FE9A:
	ldr r2, _0814FEA0 @ =0x000005C4
	adds r0, r7, r2
	b _081502F6
	.align 2, 0
_0814FEA0: .4byte 0x000005C4
_0814FEA4:
	ldr r1, _0814FEB4 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0814FF00
	.align 2, 0
_0814FEB4: .4byte 0x03002BE0
_0814FEB8:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0814FEE4
	cmp r1, #0
	blt _0814FEE4
	ldr r0, _0814FEE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0814FEE4
	ldr r0, _0814FEEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0814FEF0
_0814FEE4:
	movs r5, #0
	b _0814FEFE
	.align 2, 0
_0814FEE8: .4byte 0x030046A8
_0814FEEC: .4byte 0x030046AC
_0814FEF0:
	ldr r0, _0814FF90 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0814FEFE:
	movs r2, #0
_0814FF00:
	ldr r4, _0814FF94 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0814FF20
	ldr r1, _0814FF98 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0814FF20
	b _08150234
_0814FF20:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0814FF34
	b _081504D8
_0814FF34:
	ldr r0, _0814FF9C @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0814FFA0
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x48]
	strb r2, [r3]
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r3, [sp, #0x24]
	strb r0, [r3]
	ldr r0, [sp, #0x2c]
	str r1, [r0]
	ldr r1, [sp, #0x28]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x34]
	strb r5, [r3]
	ldr r1, [sp, #0x38]
	strb r5, [r1]
	ldr r3, [sp, #0x3c]
	strb r0, [r3]
	ldr r5, [sp, #0x50]
	str r4, [r5]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	b _081500EE
	.align 2, 0
_0814FF90: .4byte 0x030046A4
_0814FF94: .4byte 0x00000256
_0814FF98: .4byte 0x03002BE0
_0814FF9C: .4byte 0x00000222
_0814FFA0:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x48]
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	strb r5, [r4]
	ldr r2, [sp, #0x24]
	strb r0, [r2]
	ldr r4, [sp, #0x2c]
	str r1, [r4]
	ldr r1, [sp, #0x28]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x34]
	strb r5, [r2]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r5, [sp, #0x3c]
	strb r1, [r5]
	ldr r1, [sp, #0x50]
	str r3, [r1]
	ldr r2, [sp, #0x44]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08150004
	cmp r1, #0
	blt _08150004
	ldr r0, _08150008 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08150004
	ldr r0, _0815000C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08150010
_08150004:
	movs r4, #0
	b _0815001E
	.align 2, 0
_08150008: .4byte 0x030046A8
_0815000C: .4byte 0x030046AC
_08150010:
	ldr r0, _08150030 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0815001E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08150034
	adds r0, #4
	b _08150040
	.align 2, 0
_08150030: .4byte 0x030046A4
_08150034:
	ldr r0, _08150054 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08150040:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08150058
	cmp r2, #2
	beq _0815005C
	b _08150060
	.align 2, 0
_08150054: .4byte 0x030046A4
_08150058:
	ldrb r0, [r5, #4]
	b _0815005E
_0815005C:
	ldrb r0, [r5]
_0815005E:
	subs r1, r1, r0
_08150060:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08150088
	cmp r1, #0
	blt _08150088
	ldr r0, _0815008C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08150088
	ldr r0, _08150090 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08150094
_08150088:
	movs r4, #0
	b _081500A2
	.align 2, 0
_0815008C: .4byte 0x030046A8
_08150090: .4byte 0x030046AC
_08150094:
	ldr r0, _081500B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081500A2:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081500B8
	adds r0, #4
	b _081500C4
	.align 2, 0
_081500B4: .4byte 0x030046A4
_081500B8:
	ldr r0, _081500D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081500C4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081500DC
	cmp r3, #2
	beq _081500E0
	b _081500E4
	.align 2, 0
_081500D8: .4byte 0x030046A4
_081500DC:
	ldrb r0, [r5, #4]
	b _081500E2
_081500E0:
	ldrb r0, [r5]
_081500E2:
	subs r2, r2, r0
_081500E4:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081500EE:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x14]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	cmp r0, #0
	bne _081501F8
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08150118
	movs r0, #1
	b _0815011A
_08150118:
	movs r0, #0
_0815011A:
	ldr r3, _08150208 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x4c]
	cmp r0, #0
	bne _081501F8
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _0815020C @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _08150210 @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x18]
	ldr r2, _08150214 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x1c]
	ldr r4, _08150218 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x20]
	ldr r5, _0815021C @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x54]
	ldr r0, _08150220 @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x30]
	ldr r1, _08150224 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r6, _08150228 @ =0x0203B400
	ldr r1, _0815022C @ =0x030046B8
	ldr r5, _08150230 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_0815016A:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _08150188
	adds r3, #1
	cmp r3, #3
	ble _0815016A
	mov r0, r8
_08150188:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x2c]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x24]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x34]
	ldrb r0, [r4]
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	ldr r1, [sp, #0x38]
	ldrb r0, [r1]
	ldr r2, [sp, #0x1c]
	strb r0, [r2]
	ldr r4, [sp, #0x3c]
	ldrb r0, [r4]
	ldr r5, [sp, #0x20]
	strb r0, [r5]
	mov r0, sp
	ldrb r1, [r0, #0x14]
	ldr r0, [sp, #0x54]
	strb r1, [r0]
	ldr r4, [sp, #0x30]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r4, [sp, #0x40]
	strb r3, [r4]
	ldr r5, [sp, #0x24]
	strb r0, [r5]
	ldr r0, [sp, #0x2c]
	str r2, [r0]
	movs r2, #0
	ldr r4, [sp, #0x28]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	strb r2, [r4]
	ldr r5, [sp, #0x50]
	str r3, [r5]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	movs r0, #6
	ldr r1, [sp, #0x58]
	strb r0, [r1]
_081501F8:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r2, [sp, #0x4c]
	strh r0, [r2]
	b _081504D8
	.align 2, 0
_08150208: .4byte 0x00000482
_0815020C: .4byte 0x0000054F
_08150210: .4byte 0x0000054C
_08150214: .4byte 0x0000054D
_08150218: .4byte 0x0000054E
_0815021C: .4byte 0x00000541
_08150220: .4byte 0x000005BC
_08150224: .4byte 0x00000542
_08150228: .4byte 0x0203B400
_0815022C: .4byte 0x030046B8
_08150230: .4byte 0x000003FF
_08150234:
	mov sb, sp
	ldr r6, _08150270 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
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
	beq _08150274
	adds r0, #4
	b _0815027E
	.align 2, 0
_08150270: .4byte 0x030046A4
_08150274:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0815027E:
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
	ldr r5, _081502B8 @ =0x000004A4
	adds r0, r7, r5
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081502C0
	ldr r0, _081502BC @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081502EA
	.align 2, 0
_081502B8: .4byte 0x000004A4
_081502BC: .4byte 0xFFFFFDFF
_081502C0:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081502E0
	cmp r0, #2
	beq _081502DC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081502DC:
	movs r0, #1
	b _081502EC
_081502E0:
	ldr r0, _08150300 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081502EA:
	movs r0, #0
_081502EC:
	cmp r0, #0
	beq _081502F2
	b _081504D8
_081502F2:
	ldr r4, _08150304 @ =0x000005C4
	adds r0, r7, r4
_081502F6:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081504D8
	.align 2, 0
_08150300: .4byte 0xFFFFFDFF
_08150304: .4byte 0x000005C4
_08150308:
	movs r1, #0x10
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0815031A
	b _08150496
_0815031A:
	ldr r3, _08150380 @ =FUN_0814c28c
	movs r4, #7
	movs r1, #0x1e
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _08150384 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _08150388 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xa8
	adds r0, r7, r1
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815037A
	cmp r1, #0
	blt _0815037A
	ldr r0, _0815038C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815037A
	ldr r0, _08150390 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08150394
_0815037A:
	movs r4, #0
	b _081503A2
	.align 2, 0
_08150380: .4byte FUN_0814c28c
_08150384: .4byte 0x00000554
_08150388: .4byte 0x00000551
_0815038C: .4byte 0x030046A8
_08150390: .4byte 0x030046AC
_08150394:
	ldr r0, _081503B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081503A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081503B8
	adds r0, #4
	b _081503C4
	.align 2, 0
_081503B4: .4byte 0x030046A4
_081503B8:
	ldr r0, _081503D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081503C4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081503DC
	cmp r2, #2
	beq _081503E0
	b _081503E4
	.align 2, 0
_081503D8: .4byte 0x030046A4
_081503DC:
	ldrb r0, [r5, #4]
	b _081503E2
_081503E0:
	ldrb r0, [r5]
_081503E2:
	subs r1, r1, r0
_081503E4:
	strh r1, [r5, #2]
	ldr r2, _08150414 @ =0x000004A4
	adds r0, r7, r2
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r3, #0x95
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _0815041C
	ldr r0, _08150418 @ =0xFFFFFDFF
	mov r4, sl
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _08150446
	.align 2, 0
_08150414: .4byte 0x000004A4
_08150418: .4byte 0xFFFFFDFF
_0815041C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _0815043C
	cmp r0, #2
	beq _08150438
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08150438:
	movs r0, #1
	b _08150448
_0815043C:
	ldr r0, _08150480 @ =0xFFFFFDFF
	mov r5, sl
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
_08150446:
	movs r0, #0
_08150448:
	adds r3, r0, #0
	cmp r3, #0
	bne _08150488
	ldr r0, _08150484 @ =FUN_080e48d0
	movs r2, #1
	ldr r1, [sp, #0x48]
	strb r2, [r1]
	ldr r4, [sp, #0x40]
	strb r3, [r4]
	ldr r5, [sp, #0x24]
	strb r3, [r5]
	ldr r1, [sp, #0x2c]
	str r0, [r1]
	movs r1, #0
	ldr r4, [sp, #0x28]
	strh r3, [r4]
	movs r0, #3
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r0, [sp, #0x38]
	strb r1, [r0]
	ldr r4, [sp, #0x3c]
	strb r1, [r4]
	ldr r5, [sp, #0x50]
	str r3, [r5]
	ldr r0, [sp, #0x44]
	strb r2, [r0]
	b _081504D8
	.align 2, 0
_08150480: .4byte 0xFFFFFDFF
_08150484: .4byte FUN_080e48d0
_08150488:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
	b _081504D8
_08150496:
	ldr r3, _081504CC @ =FUN_0814c28c
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
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081504D0 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #2
	adds r0, r7, r5
	strb r4, [r0]
	subs r1, #0xce
	adds r0, r7, r1
	movs r2, #1
	strh r2, [r0]
	b _081504D8
	.align 2, 0
_081504CC: .4byte FUN_0814c28c
_081504D0: .4byte 0x00000551

	thumb_func_start FUN_081504d4
FUN_081504d4: @ 0x081504D4
	adds r0, #1
	str r0, [r1]
_081504D8:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081504e8
FUN_081504e8: @ 0x081504E8
	movs r1, #0xc7
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r1, _081504F4 @ =0x085AD8E0
	str r1, [r0]
	bx lr
	.align 2, 0
_081504F4: .4byte 0x085AD8E0

	thumb_func_start FUN_081504f8
FUN_081504f8: @ 0x081504F8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0814aad4
	adds r0, r4, #0
	bl FUN_0814aed0
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08150510
FUN_08150510: @ 0x08150510
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0814ac10
	adds r0, r4, #0
	bl FUN_0814ae80
	adds r0, r4, #0
	bl FUN_0814aeb0
	adds r0, r4, #0
	bl FUN_0814b78c
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08150534
FUN_08150534: @ 0x08150534
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08150554 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08150558
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815055A
	.align 2, 0
_08150554: .4byte 0x0000046C
_08150558:
	movs r0, #0
_0815055A:
	cmp r0, #0
	beq _081505FE
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	movs r5, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _0815062C @ =FUN_0814deb0
	movs r2, #0x21
	ldr r0, _08150630 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08150634 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r2, #3
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r2, _08150638 @ =0x00000226
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r3, #0x66
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r4, #0x74
	adds r3, r6, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #0xa
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _0815063C @ =0x000006D7
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _08150640 @ =0x000006CC
	adds r0, r7, r2
	ldrh r1, [r0]
	movs r3, #0xd9
	lsls r3, r3, #3
	adds r0, r7, r3
	strh r1, [r0]
_081505FE:
	ldr r4, _08150634 @ =0x0000046B
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _08150648
	ldr r1, _08150640 @ =0x000006CC
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r0, _08150644 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl enemy_dog_0814b500
	b _08150652
	.align 2, 0
_0815062C: .4byte FUN_0814deb0
_08150630: .4byte 0x0000046D
_08150634: .4byte 0x0000046B
_08150638: .4byte 0x00000226
_0815063C: .4byte 0x000006D7
_08150640: .4byte 0x000006CC
_08150644: .4byte 0xFFFFFEFF
_08150648:
	ldr r4, _0815065C @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08150652:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815065C: .4byte 0x00000484

	thumb_func_start FUN_08150660
FUN_08150660: @ 0x08150660
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08150680 @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08150684
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08150686
	.align 2, 0
_08150680: .4byte 0x0000046C
_08150684:
	movs r0, #0
_08150686:
	cmp r0, #0
	beq _0815071C
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	movs r5, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	ldr r3, _08150748 @ =FUN_0814dd38
	movs r2, #0x24
	ldr r0, _0815074C @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08150750 @ =0x0000046B
	adds r0, r6, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	movs r2, #2
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0x8a
	lsls r2, r2, #2
	adds r1, r6, r2
	ldrh r1, [r1]
	adds r3, #0x68
	adds r2, r6, r3
	ldrh r2, [r2]
	adds r4, #0x78
	adds r3, r6, r4
	ldr r3, [r3]
	str r3, [sp]
	subs r4, #0xc
	adds r3, r6, r4
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _08150754 @ =0x000006D7
	adds r0, r7, r1
	strb r5, [r0]
_0815071C:
	ldr r2, _08150750 @ =0x0000046B
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08150764
	ldr r3, _08150758 @ =0x000006CE
	adds r0, r7, r3
	ldrh r1, [r0]
	ldr r4, _0815075C @ =0x000006CA
	adds r0, r7, r4
	strh r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r0, _08150760 @ =0xFFFFFEFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r6, #0
	bl enemy_dog_0814b500
	b _0815076E
	.align 2, 0
_08150748: .4byte FUN_0814dd38
_0815074C: .4byte 0x0000046D
_08150750: .4byte 0x0000046B
_08150754: .4byte 0x000006D7
_08150758: .4byte 0x000006CE
_0815075C: .4byte 0x000006CA
_08150760: .4byte 0xFFFFFEFF
_08150764:
	ldr r2, _08150778 @ =0x00000484
	adds r1, r6, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0815076E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08150778: .4byte 0x00000484

	thumb_func_start FUN_0815077c
FUN_0815077c: @ 0x0815077C
	ldr r1, _08150788 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _0815078C @ =0x085AD8E8
	str r1, [r0]
	bx lr
	.align 2, 0
_08150788: .4byte 0x0000063C
_0815078C: .4byte 0x085AD8E8

	thumb_func_start FUN_08150790
FUN_08150790: @ 0x08150790
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _081507B4 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081507B8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081507BA
	.align 2, 0
_081507B4: .4byte 0x0000046C
_081507B8:
	movs r0, #0
_081507BA:
	cmp r0, #0
	beq _081507E8
	ldr r4, _081508F4 @ =FUN_0814e1fc
	movs r3, #0x27
	ldr r0, _081508F8 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081508FC @ =0x0000046B
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
_081507E8:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081507FE
	b _08150B06
_081507FE:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815080C
	b _08150B06
_0815080C:
	ldr r0, _08150900 @ =0x03002BE0
	mov r2, sp
	adds r3, r5, #0
	adds r3, #8
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r2, r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r2, r1, r0
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r1, [r0, #8]
	mov r8, r3
	cmp r1, #6
	beq _08150862
	cmp r1, #0xc
	beq _08150862
	cmp r1, #0x13
	beq _08150862
	cmp r1, #0x19
	bne _0815091C
_08150862:
	ldrh r1, [r0, #0xe]
	ldrb r0, [r0, #7]
	subs r0, #1
	cmp r1, r0
	bne _0815091C
	ldr r3, _08150904 @ =0x000006B4
	adds r0, r6, r3
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815091C
	ldr r4, _08150908 @ =0x000001DF
	adds r0, r5, r4
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080e5718
	movs r2, #0x10
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0815090C @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _08150910 @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08150914 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r4, #0xe1
	lsls r4, r4, #3
	adds r2, r6, r4
	ldr r0, _08150900 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081508D0
	b _08150B06
_081508D0:
	ldr r0, _08150918 @ =0x0000024E
	adds r4, r5, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bhi _081508F0
	b _08150B06
_081508F0:
	strh r1, [r4]
	b _08150B06
	.align 2, 0
_081508F4: .4byte FUN_0814e1fc
_081508F8: .4byte 0x0000046D
_081508FC: .4byte 0x0000046B
_08150900: .4byte 0x03002BE0
_08150904: .4byte 0x000006B4
_08150908: .4byte 0x000001DF
_0815090C: .4byte 0x00000469
_08150910: .4byte 0x0000046A
_08150914: .4byte 0x00000484
_08150918: .4byte 0x0000024E
_0815091C:
	ldr r4, _0815099C @ =0x0000046B
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08150928
	b _08150AFC
_08150928:
	movs r2, #0x80
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r1, r5, r6
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081509B0
	movs r2, #0xc
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081509A0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	subs r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r6, _081509A4 @ =0x00000484
	adds r0, r5, r6
	str r1, [r0]
	ldr r2, _081509A8 @ =0x0000046C
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #0x1a
	subs r6, #0x17
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _0815099C @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	movs r0, #4
	ldr r4, _081509AC @ =0x00000222
	adds r2, r5, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08150B06
	.align 2, 0
_0815099C: .4byte 0x0000046B
_081509A0: .4byte 0x00000469
_081509A4: .4byte 0x00000484
_081509A8: .4byte 0x0000046C
_081509AC: .4byte 0x00000222
_081509B0:
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081509E4
	cmp r1, #0
	blt _081509E4
	ldr r0, _081509E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081509E4
	ldr r0, _081509EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081509F0
_081509E4:
	movs r4, #0
	b _081509FE
	.align 2, 0
_081509E8: .4byte 0x030046A8
_081509EC: .4byte 0x030046AC
_081509F0:
	ldr r0, _08150A10 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081509FE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08150A14
	adds r0, #4
	b _08150A20
	.align 2, 0
_08150A10: .4byte 0x030046A4
_08150A14:
	ldr r0, _08150A34 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08150A20:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08150A38
	cmp r3, #2
	beq _08150A3C
	b _08150A40
	.align 2, 0
_08150A34: .4byte 0x030046A4
_08150A38:
	ldrb r0, [r6, #4]
	b _08150A3E
_08150A3C:
	ldrb r0, [r6]
_08150A3E:
	subs r2, r2, r0
_08150A40:
	movs r1, #0
	movs r4, #0
	strh r2, [r6, #2]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r3, [r0]
	movs r2, #1
	ldr r6, _08150AC8 @ =0x0000046D
	adds r0, r5, r6
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0x25
	adds r0, r5, r6
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	movs r3, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08150ACC @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	ldr r3, _08150AD0 @ =0x00000484
	adds r0, r5, r3
	str r4, [r0]
	ldr r4, _08150AD4 @ =0x0000046C
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0x3b
	adds r0, r5, r6
	ldr r4, [r0]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	beq _08150AD8
	adds r0, r4, #0
	mov r1, r8
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08150AD8
	cmp r0, #2
	beq _08150AC2
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08150AC2:
	movs r0, #1
	b _08150AE2
	.align 2, 0
_08150AC8: .4byte 0x0000046D
_08150ACC: .4byte 0x0000046A
_08150AD0: .4byte 0x00000484
_08150AD4: .4byte 0x0000046C
_08150AD8:
	ldr r0, _08150AF4 @ =0xFFFFFDFF
	ldrh r1, [r7]
	ands r0, r1
	strh r0, [r7]
	movs r0, #0
_08150AE2:
	cmp r0, #0
	bne _08150B06
	ldr r1, _08150AF8 @ =0x000005C4
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _08150B06
	.align 2, 0
_08150AF4: .4byte 0xFFFFFDFF
_08150AF8: .4byte 0x000005C4
_08150AFC:
	ldr r2, _08150B14 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08150B06:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08150B14: .4byte 0x00000484

	thumb_func_start FUN_08150b18
FUN_08150b18: @ 0x08150B18
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08150B3C @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08150B40
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08150B42
	.align 2, 0
_08150B3C: .4byte 0x0000046C
_08150B40:
	movs r0, #0
_08150B42:
	cmp r0, #0
	beq _08150B70
	ldr r4, _08150BC8 @ =FUN_0814caa0
	movs r3, #0xa
	ldr r6, _08150BCC @ =0x0000046D
	adds r1, r5, r6
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r7, _08150BD0 @ =0x0000046B
	adds r0, r5, r7
	strb r2, [r0]
	ldr r1, _08150BD4 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_08150B70:
	movs r7, #0xc1
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08150B86
	b _08150DDA
_08150B86:
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08150B94
	b _08150DDA
_08150B94:
	ldr r1, _08150BD0 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08150BA0
	b _08150DD0
_08150BA0:
	ldr r2, _08150BD8 @ =0x000004A4
	adds r0, r5, r2
	ldr r6, [r0]
	adds r7, r5, #0
	adds r7, #8
	movs r4, #0xe1
	lsls r4, r4, #3
	add r4, r8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08150BDC
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	b _08150C02
	.align 2, 0
_08150BC8: .4byte FUN_0814caa0
_08150BCC: .4byte 0x0000046D
_08150BD0: .4byte 0x0000046B
_08150BD4: .4byte 0x00000553
_08150BD8: .4byte 0x000004A4
_08150BDC:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08150BFC
	cmp r0, #2
	beq _08150BF8
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08150BF8:
	movs r0, #1
	b _08150C0C
_08150BFC:
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r0, r5, r6
_08150C02:
	ldr r1, _08150C20 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08150C0C:
	cmp r0, #0
	bne _08150C28
	ldr r7, _08150C24 @ =0x000005C4
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	b _08150DDA
	.align 2, 0
_08150C20: .4byte 0xFFFFFDFF
_08150C24: .4byte 0x000005C4
_08150C28:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	movs r4, #0
	movs r6, #0
	orrs r1, r0
	strh r1, [r2]
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08150CB8
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _08150CA4 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _08150CA8 @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08150CAC @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r2, #0x1a
	adds r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08150CB0 @ =0x0000046B
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
	strh r6, [r0]
	movs r0, #4
	ldr r3, _08150CB4 @ =0x00000222
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _08150DDA
	.align 2, 0
_08150CA4: .4byte 0x00000469
_08150CA8: .4byte 0x0000046A
_08150CAC: .4byte 0x00000484
_08150CB0: .4byte 0x0000046B
_08150CB4: .4byte 0x00000222
_08150CB8:
	movs r6, #0x95
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r6, [r0]
	adds r2, r5, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r6]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r6, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08150CF0
	cmp r1, #0
	blt _08150CF0
	ldr r0, _08150CF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08150CF0
	ldr r0, _08150CF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08150CFC
_08150CF0:
	movs r4, #0
	b _08150D0A
	.align 2, 0
_08150CF4: .4byte 0x030046A8
_08150CF8: .4byte 0x030046AC
_08150CFC:
	ldr r0, _08150D1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08150D0A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08150D20
	adds r0, #4
	b _08150D2C
	.align 2, 0
_08150D1C: .4byte 0x030046A4
_08150D20:
	ldr r0, _08150D40 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08150D2C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08150D44
	cmp r2, #2
	beq _08150D48
	b _08150D4C
	.align 2, 0
_08150D40: .4byte 0x030046A4
_08150D44:
	ldrb r0, [r6, #4]
	b _08150D4A
_08150D48:
	ldrb r0, [r6]
_08150D4A:
	subs r1, r1, r0
_08150D4C:
	movs r3, #0
	movs r4, #0
	strh r1, [r6, #2]
	movs r7, #0x95
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r0, [r0]
	strh r4, [r0, #6]
	movs r2, #0x10
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #1
	ldr r6, _08150DC0 @ =0x0000046D
	adds r0, r5, r6
	strb r1, [r0]
	subs r7, #0x3d
	adds r0, r5, r7
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	movs r2, #7
	subs r6, #0xeb
	adds r0, r5, r6
	strb r3, [r0]
	ldr r7, _08150DC4 @ =0x00000469
	adds r0, r5, r7
	strb r3, [r0]
	ldr r3, _08150DC8 @ =0x0000046A
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	ldr r0, _08150DCC @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	b _08150DDA
	.align 2, 0
_08150DC0: .4byte 0x0000046D
_08150DC4: .4byte 0x00000469
_08150DC8: .4byte 0x0000046A
_08150DCC: .4byte 0x00000482
_08150DD0:
	ldr r2, _08150DE4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08150DDA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08150DE4: .4byte 0x00000484

	thumb_func_start FUN_08150de8
FUN_08150de8: @ 0x08150DE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	adds r7, r0, #0
	ldr r0, _08150E08 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08150E0C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08150E0E
	.align 2, 0
_08150E08: .4byte 0x0000046C
_08150E0C:
	movs r0, #0
_08150E0E:
	cmp r0, #0
	beq _08150E5C
	ldr r1, _08150FA0 @ =0x000005A4
	adds r0, r7, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _08150FA4 @ =0x0000046D
	adds r1, r7, r4
	movs r0, #1
	strb r0, [r1]
	ldr r5, _08150FA8 @ =0x0000046B
	adds r0, r7, r5
	strb r2, [r0]
	ldr r6, _08150FAC @ =0x00000553
	adds r0, r7, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, _08150FB0 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_08150E5C:
	movs r6, #0xc1
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08150E72
	b _081514E0
_08150E72:
	adds r0, r7, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	cmp r0, #0
	beq _08150E84
	b _081514E0
_08150E84:
	ldr r0, _08150FB4 @ =0x00000484
	adds r1, r7, r0
	ldr r0, [r1]
	cmp r0, #0x14
	bgt _08150E90
	b _081514DC
_08150E90:
	ldr r1, _08150FB8 @ =0x00000222
	adds r1, r7, r1
	str r1, [sp, #8]
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r1, [r1]
	ands r0, r1
	movs r4, #0
	ldr r2, [sp, #8]
	strh r0, [r2]
	ldr r1, _08150FBC @ =FUN_080e6794
	movs r0, #0xe
	ldr r3, _08150FA4 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0xc]
	movs r5, #1
	strb r5, [r3]
	ldr r6, _08150FA8 @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x10]
	strb r4, [r6]
	ldr r2, _08150FAC @ =0x00000553
	adds r2, r7, r2
	str r2, [sp, #0x14]
	strb r0, [r2]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x18]
	str r1, [r3]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x1c]
	mov r0, r8
	strh r0, [r6]
	ldr r1, _08150FC0 @ =0x00000543
	adds r0, r7, r1
	ldrb r3, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	movs r6, #0xc
	mov sb, r6
	movs r0, #0xab
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r6, _08150FC4 @ =0x00000554
	adds r0, r7, r6
	str r3, [r0]
	str r2, [r1]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _08150FC8 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08150FCC @ =0x00000552
	adds r0, r7, r3
	mov r6, sb
	strb r6, [r0]
	movs r0, #3
	subs r1, #0xe8
	adds r1, r1, r7
	mov ip, r1
	strb r0, [r1]
	subs r2, #0xe8
	adds r2, r2, r7
	mov sl, r2
	strb r5, [r2]
	subs r3, #0xe8
	adds r3, r3, r7
	mov sb, r3
	strb r4, [r3]
	ldr r4, _08150FB4 @ =0x00000484
	adds r6, r7, r4
	mov r0, r8
	str r0, [r6]
	ldr r1, _08150FD0 @ =0x0000046C
	adds r3, r7, r1
	strb r5, [r3]
	movs r2, #0x95
	lsls r2, r2, #3
	adds r4, r7, r2
	ldr r5, [r4]
	str r5, [sp, #0x20]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r5, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	str r3, [sp, #0x3c]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x40]
	ldr r3, [sp, #0x10]
	str r3, [sp, #0x38]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x68]
	ldr r3, [sp, #0x18]
	str r3, [sp, #0x6c]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x4c]
	ldr r3, [sp, #8]
	str r3, [sp, #0x50]
	mov r0, ip
	str r0, [sp, #0x2c]
	mov r3, sl
	str r3, [sp, #0x30]
	mov r0, sb
	str r0, [sp, #0x34]
	str r6, [sp, #0x48]
	adds r6, r4, #0
	mov r8, r2
	cmp r5, #0
	blt _08150F9C
	cmp r1, #0
	blt _08150F9C
	ldr r0, _08150FD4 @ =0x030046A8
	ldr r0, [r0]
	cmp r5, r0
	bhs _08150F9C
	ldr r0, _08150FD8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08150FDC
_08150F9C:
	movs r5, #0
	b _08150FEA
	.align 2, 0
_08150FA0: .4byte 0x000005A4
_08150FA4: .4byte 0x0000046D
_08150FA8: .4byte 0x0000046B
_08150FAC: .4byte 0x00000553
_08150FB0: .4byte 0xFFFFFDFF
_08150FB4: .4byte 0x00000484
_08150FB8: .4byte 0x00000222
_08150FBC: .4byte FUN_080e6794
_08150FC0: .4byte 0x00000543
_08150FC4: .4byte 0x00000554
_08150FC8: .4byte 0x00000551
_08150FCC: .4byte 0x00000552
_08150FD0: .4byte 0x0000046C
_08150FD4: .4byte 0x030046A8
_08150FD8: .4byte 0x030046AC
_08150FDC:
	ldr r0, _08150FFC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r5
_08150FEA:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08151000
	adds r0, #4
	b _0815100C
	.align 2, 0
_08150FFC: .4byte 0x030046A4
_08151000:
	ldr r0, _08151020 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0815100C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08151024
	cmp r2, #2
	beq _0815102A
	b _08151030
	.align 2, 0
_08151020: .4byte 0x030046A4
_08151024:
	ldr r2, [sp, #0x20]
	ldrb r0, [r2, #4]
	b _0815102E
_0815102A:
	ldr r3, [sp, #0x20]
	ldrb r0, [r3]
_0815102E:
	subs r1, r1, r0
_08151030:
	ldr r4, [sp, #0x20]
	strh r1, [r4, #2]
	ldr r0, _08151048 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0815104C
	movs r0, #1
	b _0815104E
	.align 2, 0
_08151048: .4byte 0x030047A4
_0815104C:
	movs r0, #0
_0815104E:
	cmp r0, #0
	beq _0815108C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r7, r5
	ldr r1, [r0]
	cmp r1, #0
	beq _0815106E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0815106A
	adds r2, r0, #0
_0815106A:
	cmp r2, #0
	bge _08151078
_0815106E:
	ldr r6, _08151074 @ =0x000005C4
	adds r0, r7, r6
	b _081514C8
	.align 2, 0
_08151074: .4byte 0x000005C4
_08151078:
	ldr r1, _08151088 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081510D4
	.align 2, 0
_08151088: .4byte 0x03002BE0
_0815108C:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081510B8
	cmp r1, #0
	blt _081510B8
	ldr r0, _081510BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081510B8
	ldr r0, _081510C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081510C4
_081510B8:
	movs r5, #0
	b _081510D2
	.align 2, 0
_081510BC: .4byte 0x030046A8
_081510C0: .4byte 0x030046AC
_081510C4:
	ldr r0, _08151168 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081510D2:
	movs r2, #0
_081510D4:
	ldr r3, _0815116C @ =0x00000256
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r5, r0
	beq _081510F4
	ldr r1, _08151170 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081510F4
	b _0815140C
_081510F4:
	movs r0, #0x80
	lsls r0, r0, #3
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r7, r4
	ldrh r1, [r2]
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	mov sb, r2
	cmp r3, #0
	beq _0815110E
	b _081514E0
_0815110E:
	movs r0, #5
	rsbs r0, r0, #0
	ldr r5, [sp, #0x50]
	ldrh r1, [r5]
	ands r0, r1
	movs r5, #0
	ldr r1, [sp, #0x50]
	strh r0, [r1]
	movs r1, #0x80
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _08151174
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r6, [sp, #0x40]
	strb r2, [r6]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r6, [sp, #0x68]
	strb r0, [r6]
	ldr r0, [sp, #0x6c]
	str r1, [r0]
	ldr r1, [sp, #0x4c]
	strh r3, [r1]
	movs r0, #0xc
	ldr r4, [sp, #0x2c]
	strb r5, [r4]
	ldr r6, [sp, #0x30]
	strb r5, [r6]
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	ldr r4, [sp, #0x48]
	str r3, [r4]
	ldr r5, [sp, #0x3c]
	strb r2, [r5]
	b _081512C2
	.align 2, 0
_08151168: .4byte 0x030046A4
_0815116C: .4byte 0x00000256
_08151170: .4byte 0x03002BE0
_08151174:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r3, [sp, #0x40]
	strb r0, [r3]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r3, [sp, #0x68]
	strb r0, [r3]
	ldr r4, [sp, #0x6c]
	str r1, [r4]
	ldr r1, [sp, #0x4c]
	strh r2, [r1]
	movs r1, #5
	ldr r3, [sp, #0x2c]
	strb r5, [r3]
	ldr r4, [sp, #0x30]
	strb r5, [r4]
	ldr r5, [sp, #0x34]
	strb r1, [r5]
	ldr r1, [sp, #0x48]
	str r2, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r4, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r4]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r4, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081511D8
	cmp r1, #0
	blt _081511D8
	ldr r0, _081511DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081511D8
	ldr r0, _081511E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081511E4
_081511D8:
	movs r5, #0
	b _081511F2
	.align 2, 0
_081511DC: .4byte 0x030046A8
_081511E0: .4byte 0x030046AC
_081511E4:
	ldr r0, _08151204 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081511F2:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08151208
	adds r0, #4
	b _08151214
	.align 2, 0
_08151204: .4byte 0x030046A4
_08151208:
	ldr r0, _08151228 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08151214:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0815122C
	cmp r2, #2
	beq _08151230
	b _08151234
	.align 2, 0
_08151228: .4byte 0x030046A4
_0815122C:
	ldrb r0, [r4, #4]
	b _08151232
_08151230:
	ldrb r0, [r4]
_08151232:
	subs r1, r1, r0
_08151234:
	strh r1, [r4, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0815125C
	cmp r1, #0
	blt _0815125C
	ldr r0, _08151260 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0815125C
	ldr r0, _08151264 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08151268
_0815125C:
	movs r5, #0
	b _08151276
	.align 2, 0
_08151260: .4byte 0x030046A8
_08151264: .4byte 0x030046AC
_08151268:
	ldr r0, _08151288 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08151276:
	ldr r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0815128C
	adds r0, #4
	b _08151298
	.align 2, 0
_08151288: .4byte 0x030046A4
_0815128C:
	ldr r0, _081512AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08151298:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081512B0
	cmp r3, #2
	beq _081512B4
	b _081512B8
	.align 2, 0
_081512AC: .4byte 0x030046A4
_081512B0:
	ldrb r0, [r4, #4]
	b _081512B6
_081512B4:
	ldrb r0, [r4]
_081512B6:
	subs r2, r2, r0
_081512B8:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081512C2:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x24]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sb
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _081512EC @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x44]
	cmp r0, #0
	bne _081513D0
	movs r1, #4
	ldr r2, [sp, #0x50]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081512F0
	movs r0, #1
	b _081512F2
	.align 2, 0
_081512EC: .4byte 0x00000482
_081512F0:
	movs r0, #0
_081512F2:
	ldr r3, _081513E0 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x44]
	cmp r0, #0
	bne _081513D0
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _081513E4 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _081513E8 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x5c]
	ldr r1, _081513EC @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x60]
	ldr r2, _081513F0 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x64]
	ldr r4, _081513F4 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x54]
	ldr r5, _081513F8 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x28]
	ldr r6, _081513FC @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x58]
	ldr r6, _08151400 @ =0x0203B400
	ldr r1, _08151404 @ =0x030046B8
	ldr r2, _08151408 @ =0x000003FF
	movs r5, #3
	mov r4, r8
_08151342:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _08151360
	adds r3, #1
	cmp r3, #3
	ble _08151342
	mov r0, r8
_08151360:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x6c]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x68]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x5c]
	strb r0, [r2]
	ldr r4, [sp, #0x30]
	ldrb r0, [r4]
	ldr r5, [sp, #0x60]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	ldrb r0, [r6]
	ldr r1, [sp, #0x64]
	strb r0, [r1]
	add r2, sp, #0x24
	ldrb r4, [r2]
	ldr r2, [sp, #0x54]
	strb r4, [r2]
	ldr r4, [sp, #0x28]
	ldr r2, [r4]
	movs r0, #0x1b
	movs r1, #1
	ldr r5, [sp, #0x40]
	strb r1, [r5]
	ldr r6, [sp, #0x38]
	strb r3, [r6]
	ldr r4, [sp, #0x68]
	strb r0, [r4]
	ldr r5, [sp, #0x6c]
	str r2, [r5]
	movs r2, #0
	ldr r6, [sp, #0x4c]
	strh r3, [r6]
	movs r0, #3
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
	ldr r5, [sp, #0x30]
	strb r1, [r5]
	ldr r6, [sp, #0x34]
	strb r2, [r6]
	ldr r0, [sp, #0x48]
	str r3, [r0]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x58]
	strb r0, [r3]
_081513D0:
	adds r0, r7, #0
	bl FUN_080e7b6c
	movs r0, #2
	ldr r4, [sp, #0x44]
	strh r0, [r4]
	b _081514E0
	.align 2, 0
_081513E0: .4byte 0x00000482
_081513E4: .4byte 0x0000054F
_081513E8: .4byte 0x0000054C
_081513EC: .4byte 0x0000054D
_081513F0: .4byte 0x0000054E
_081513F4: .4byte 0x00000541
_081513F8: .4byte 0x000005BC
_081513FC: .4byte 0x00000542
_08151400: .4byte 0x0203B400
_08151404: .4byte 0x030046B8
_08151408: .4byte 0x000003FF
_0815140C:
	mov sb, sp
	ldr r6, _08151448 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
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
	beq _0815144C
	adds r0, #4
	b _08151456
	.align 2, 0
_08151448: .4byte 0x030046A4
_0815144C:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_08151456:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _0815148C @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _08151490
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r7, r1
	b _081514B6
	.align 2, 0
_0815148C: .4byte 0x000004A4
_08151490:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _081514B0
	cmp r0, #2
	beq _081514AC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081514AC:
	movs r0, #1
	b _081514C0
_081514B0:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
_081514B6:
	ldr r1, _081514D4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_081514C0:
	cmp r0, #0
	bne _081514E0
	ldr r3, _081514D8 @ =0x000005C4
	adds r0, r7, r3
_081514C8:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081514E0
	.align 2, 0
_081514D4: .4byte 0xFFFFFDFF
_081514D8: .4byte 0x000005C4
_081514DC:
	adds r0, #1
	str r0, [r1]
_081514E0:
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081514f0
FUN_081514f0: @ 0x081514F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08151518 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0815151C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0815151E
	.align 2, 0
_08151518: .4byte 0x0000046C
_0815151C:
	movs r0, #0
_0815151E:
	cmp r0, #0
	beq _0815155A
	ldr r4, _0815158C @ =FUN_0814e530
	movs r3, #0x29
	ldr r0, _08151590 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08151594 @ =0x0000046B
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
	movs r2, #8
	movs r1, #0xd5
	lsls r1, r1, #3
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0815155A:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r3, _08151598 @ =0x00000482
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldr r1, _0815159C @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081515A0
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081515B0
	.align 2, 0
_0815158C: .4byte FUN_0814e530
_08151590: .4byte 0x0000046D
_08151594: .4byte 0x0000046B
_08151598: .4byte 0x00000482
_0815159C: .4byte 0x0000A02F
_081515A0:
	ldr r3, _081515D4 @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081515B0
	movs r0, #1
	strh r0, [r2]
_081515B0:
	ldr r1, _081515D8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081515DC
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
	b _081515F4
	.align 2, 0
_081515D4: .4byte 0x00000482
_081515D8: .4byte 0x0000025D
_081515DC:
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
_081515F4:
	ldr r2, _0815164C @ =0x000004A4
	adds r4, r5, r2
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _08151654
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815168E
	movs r1, #3
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08151650 @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r6, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r6, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	movs r2, #4
	movs r1, #0xd5
	lsls r1, r1, #3
	add r1, r8
	ldr r0, [r1]
	orrs r0, r2
	b _081516C2
	.align 2, 0
_0815164C: .4byte 0x000004A4
_08151650: .4byte 0x00000469
_08151654:
	ldr r1, [r4]
	str r7, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815168E
	movs r2, #0x12
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081516D0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081516D4 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_0815168E:
	adds r0, r5, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081516BA
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081516C4
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081516C4
_081516BA:
	ldr r2, _081516D4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
_081516C2:
	str r0, [r1]
_081516C4:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081516D0: .4byte 0x00000469
_081516D4: .4byte 0x00000484

	thumb_func_start FUN_081516d8
FUN_081516d8: @ 0x081516D8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081516F0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081516F4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081516F6
	.align 2, 0
_081516F0: .4byte 0x0000046C
_081516F4:
	movs r0, #0
_081516F6:
	cmp r0, #0
	beq _0815172A
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _08151788 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0815178C @ =0x0000046B
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
_0815172A:
	adds r0, r5, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08151756
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815179E
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815179E
_08151756:
	ldr r3, _0815178C @ =0x0000046B
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08151794
	movs r2, #0x11
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08151790 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _0815179E
	.align 2, 0
_08151788: .4byte 0x0000046D
_0815178C: .4byte 0x0000046B
_08151790: .4byte 0x00000484
_08151794:
	ldr r0, _081517A4 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0815179E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081517A4: .4byte 0x00000484

	thumb_func_start FUN_081517a8
FUN_081517a8: @ 0x081517A8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081517C0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081517C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081517C6
	.align 2, 0
_081517C0: .4byte 0x0000046C
_081517C4:
	movs r0, #0
_081517C6:
	cmp r0, #0
	beq _081517FA
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _08151880 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _08151884 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _08151888 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
_081517FA:
	adds r0, r5, #0
	bl FUN_0814b3a0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08151826
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081518A2
	adds r0, r5, #0
	bl FUN_080f0a0c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081518A2
_08151826:
	ldr r2, _08151884 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08151898
	movs r2, #3
	movs r1, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r3, #0
	strb r2, [r0]
	ldr r6, _0815188C @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _08151890 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _08151894 @ =FUN_0814e424
	movs r2, #0x2a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08151884 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	b _081518A2
	.align 2, 0
_08151880: .4byte 0x0000046D
_08151884: .4byte 0x0000046B
_08151888: .4byte 0x00000553
_0815188C: .4byte 0x00000469
_08151890: .4byte 0x0000046A
_08151894: .4byte FUN_0814e424
_08151898:
	ldr r3, _081518A8 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081518A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081518A8: .4byte 0x00000484

	thumb_func_start FUN_081518ac
FUN_081518ac: @ 0x081518AC
	ldr r1, _081518B8 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _081518BC @ =0x085AD8F0
	str r1, [r0]
	bx lr
	.align 2, 0
_081518B8: .4byte 0x00000634
_081518BC: .4byte 0x085AD8F0

	thumb_func_start FUN_081518c0
FUN_081518c0: @ 0x081518C0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	bl FUN_081504f8
	ldr r1, _08151904 @ =0x000004BE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081518F4
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r2, _08151908 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
_081518F4:
	adds r0, r5, #0
	bl FUN_08150510
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08151904: .4byte 0x000004BE
_08151908: .4byte 0x0000062C

	thumb_func_start FUN_0815190c
FUN_0815190c: @ 0x0815190C
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start EnemyDog_Destroy
EnemyDog_Destroy: @ 0x08151918
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08151930 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08151934
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _0815193C
	.align 2, 0
_08151930: .4byte 0x0000025D
_08151934:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_0815193C:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _08151958 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0815195C
	movs r0, #1
	b _0815195E
	.align 2, 0
_08151958: .4byte 0x00000474
_0815195C:
	movs r0, #0
_0815195E:
	cmp r0, #0
	beq _0815196A
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_0815196A:
	ldr r1, _081519C4 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _08151982
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_08151982:
	ldr r0, _081519C8 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _0815199A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_0815199A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081519B2
	adds r0, r4, #0
	bl FUN_08002a58
_081519B2:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081519CC
	movs r0, #1
	b _081519CE
	.align 2, 0
_081519C4: .4byte 0x0000044C
_081519C8: .4byte 0x0000044D
_081519CC:
	movs r0, #0
_081519CE:
	cmp r0, #0
	beq _081519DA
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081519DA:
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

	thumb_func_start EnemyDog_Init
EnemyDog_Init: @ 0x081519F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a8
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	ldr r2, _08151A88 @ =0x000006D6
	adds r0, r7, r2
	strb r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r3, _08151A8C @ =0x000001DF
	adds r1, r7, r3
	movs r0, #0x15
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0814a6e8
	ldr r4, _08151A90 @ =0x0000025D
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08151A9C
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08151A94 @ =0x0000D635
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _08151A98 @ =0x0000F6E7
	bl FUN_080e3804
	ldr r6, _08151A8C @ =0x000001DF
	adds r0, r7, r6
	ldrb r1, [r0]
	str r0, [sp, #0x98]
	cmp r1, #0x11
	beq _08151A78
	cmp r1, #0x17
	bne _08151A7C
_08151A78:
	movs r0, #1
	strb r0, [r5, #7]
_08151A7C:
	movs r0, #0xef
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	b _08151B02
	.align 2, 0
_08151A88: .4byte 0x000006D6
_08151A8C: .4byte 0x000001DF
_08151A90: .4byte 0x0000025D
_08151A94: .4byte 0x0000D635
_08151A98: .4byte 0x0000F6E7
_08151A9C:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r1, sp, #0x14
	mov r8, r1
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	ldr r2, _08151B80 @ =0x05000002
	bl CpuSet
	ldr r0, _08151B84 @ =0x0000CB05
	ldr r1, _08151B88 @ =0x0000D635
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
	ldr r0, _08151B8C @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08151B90 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x98]
_08151B02:
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
	ldr r5, _08151B94 @ =0x0000046F
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
	ldr r1, _08151B98 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _08151B80 @ =0x05000002
	bl CpuSet
	ldr r3, _08151B9C @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1a0]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x6c]
	mov r3, r8
	str r3, [sp, #0x70]
	str r6, [sp, #0x48]
	ldr r2, [sp, #0x1a0]
	adds r6, r2, #0
	cmp r0, #0
	bne _08151B6E
	b _08151CD0
_08151B6E:
	bl VM_GetPC
	cmp r0, #0
	beq _08151BA0
	bl Script_GetValue
	adds r1, r0, #0
	b _08151BA2
	.align 2, 0
_08151B80: .4byte 0x05000002
_08151B84: .4byte 0x0000CB05
_08151B88: .4byte 0x0000D635
_08151B8C: .4byte 0x000004B7
_08151B90: .4byte 0x000001DF
_08151B94: .4byte 0x0000046F
_08151B98: .4byte 0x00000474
_08151B9C: .4byte 0x000004B6
_08151BA0:
	movs r1, #0
_08151BA2:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _08151BC8 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xf0]
	str r4, [sp, #0xf4]
	cmp r0, #0
	beq _08151BCC
	bl Script_GetValue
	adds r1, r0, #0
	b _08151BCE
	.align 2, 0
_08151BC8: .4byte 0x00000251
_08151BCC:
	movs r1, #0
_08151BCE:
	ldr r2, _08151C04 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _08151C08 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xf0]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0xfc]
	cmp r0, #0
	beq _08151C0C
	bl Script_GetValue
	b _08151C10
	.align 2, 0
_08151C04: .4byte 0x00000252
_08151C08: .4byte 0x000004B4
_08151C0C:
	ldr r4, [sp, #0xf0]
	ldrb r0, [r4]
_08151C10:
	strb r0, [r6]
	ldr r5, [sp, #0xf0]
	ldrb r1, [r5]
	ldr r6, [sp, #0xfc]
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
	blt _08151C48
	cmp r1, #0
	blt _08151C48
	ldr r0, _08151C4C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08151C48
	ldr r0, _08151C50 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08151C54
_08151C48:
	movs r1, #0
	b _08151C62
	.align 2, 0
_08151C4C: .4byte 0x030046A8
_08151C50: .4byte 0x030046AC
_08151C54:
	ldr r0, _08151C7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08151C62:
	ldr r2, _08151C80 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08151C84
	adds r0, #4
	b _08151C90
	.align 2, 0
_08151C7C: .4byte 0x030046A4
_08151C80: .4byte 0x00000256
_08151C84:
	ldr r0, _08151CA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08151C90:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08151CA8
	cmp r2, #2
	beq _08151CAC
	b _08151CB0
	.align 2, 0
_08151CA4: .4byte 0x030046A4
_08151CA8:
	ldrb r0, [r4, #4]
	b _08151CAE
_08151CAC:
	ldrb r0, [r4]
_08151CAE:
	subs r1, r1, r0
_08151CB0:
	ldr r3, _08151CC8 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08151CCC @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08151D10
	.align 2, 0
_08151CC8: .4byte 0x00000472
_08151CCC: .4byte 0x0000FFFF
_08151CD0:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08151D34 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _08151D38 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _08151D3C @ =0x000004B4
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
	str r5, [sp, #0xf0]
	str r4, [sp, #0xf4]
	str r3, [sp, #0xfc]
_08151D10:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08151D5A
	bl VM_GetPC
	cmp r0, #0
	beq _08151D40
	bl Script_GetValue
	adds r4, r0, #0
	b _08151D42
	.align 2, 0
_08151D34: .4byte 0x00000251
_08151D38: .4byte 0x00000252
_08151D3C: .4byte 0x000004B4
_08151D40:
	movs r4, #0x30
_08151D42:
	bl VM_GetPC
	cmp r0, #0
	beq _08151D54
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08151D56
_08151D54:
	movs r5, #0x40
_08151D56:
	mov r8, r4
	b _08151D60
_08151D5A:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_08151D60:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08151D98
	bl VM_GetPC
	cmp r0, #0
	beq _08151D7A
	bl Script_GetValue
	adds r6, r0, #0
	b _08151D7C
_08151D7A:
	movs r6, #0
_08151D7C:
	bl VM_GetPC
	cmp r0, #0
	beq _08151D8C
	bl Script_GetValue
	adds r1, r0, #0
	b _08151D8E
_08151D8C:
	movs r1, #0
_08151D8E:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08151DA2
_08151D98:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08151DA2:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _0815201C @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x110]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xe8]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x78]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x74]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x100]
	lsls r4, r4, #0x10
	str r4, [sp, #0x94]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xa0]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa4]
	lsls r5, r5, #0x10
	str r5, [sp, #0x9c]
	ldr r4, _08152020 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x10c]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x90]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x30]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xac]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x34]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x38]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x198]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x58]
	ldr r1, _08152024 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x4c]
	ldr r2, _08152028 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x50]
	ldr r3, _0815202C @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x54]
	ldr r4, _08152030 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x64]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x68]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xec]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x104]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x114]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x124]
	ldr r4, _08152034 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x128]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _08152038 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x140]
	ldr r1, _0815203C @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x148]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _08152040 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x150]
	ldr r4, _08152044 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x158]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x144]
	ldr r6, _08152048 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xf8]
	ldr r1, _0815204C @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x17c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x180]
	ldr r3, _08152050 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xb4]
	ldr r4, _08152054 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x184]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x16c]
	ldr r6, _08152058 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x160]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x170]
	ldr r2, _0815205C @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x174]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x178]
	ldr r4, _08152060 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x18c]
	ldr r6, _08152064 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x138]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x164]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x15c]
	ldr r3, _08152068 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x168]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x154]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x12c]
	ldr r6, _0815206C @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x190]
	ldr r1, _08152070 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x108]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x194]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x134]
	ldr r4, _08152074 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x118]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x11c]
	ldr r6, _08152078 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x120]
	ldr r1, _0815207C @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x130]
	ldr r2, _08152080 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x80]
	ldr r5, _08152084 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x60]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x3c]
	ldr r1, _08152088 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x40]
	ldr r2, _0815208C @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x44]
	ldr r3, _08152090 @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xb8]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xe4]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x5c]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x8c]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x88]
	ldr r2, _08152094 @ =0x00000572
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x84]
	movs r4, #0xae
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xdc]
	ldr r5, _08152098 @ =0x0000055C
	adds r5, r7, r5
	str r5, [sp, #0xbc]
	movs r6, #0xac
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xc0]
	ldr r1, _0815209C @ =0x00000564
	adds r1, r7, r1
	str r1, [sp, #0xc4]
	ldr r2, _081520A0 @ =0x00000565
	adds r2, r7, r2
	str r2, [sp, #0xc8]
	ldr r3, _081520A4 @ =0x00000566
	adds r3, r7, r3
	str r3, [sp, #0xcc]
	ldr r4, _081520A8 @ =0x00000567
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	movs r5, #0xad
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd4]
	ldr r6, _081520AC @ =0x0000056C
	adds r6, r7, r6
	str r6, [sp, #0xd8]
	cmp r0, #0
	bne _08151FEC
	b _08152106
_08151FEC:
	movs r0, #0
	mov sl, r0
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r1, r1, r7
	mov sb, r1
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r5, r7, r3
	movs r6, #0x89
	lsls r6, r6, #2
	adds r4, r7, r6
_0815200C:
	bl VM_GetPC
	cmp r0, #0
	beq _081520B0
	bl Script_GetValue
	b _081520B2
	.align 2, 0
_0815201C: .4byte 0x0000025D
_08152020: .4byte 0x0000025A
_08152024: .4byte 0x0000047A
_08152028: .4byte 0x0000047C
_0815202C: .4byte 0x0000047E
_08152030: .4byte 0x000004A4
_08152034: .4byte 0x000005A4
_08152038: .4byte 0x000005C4
_0815203C: .4byte 0x000005CC
_08152040: .4byte 0x000005D4
_08152044: .4byte 0x000005DC
_08152048: .4byte 0x00000584
_0815204C: .4byte 0x00000604
_08152050: .4byte 0x0000021D
_08152054: .4byte 0x0000060C
_08152058: .4byte 0x000005E4
_0815205C: .4byte 0x000005FC
_08152060: .4byte 0x00000614
_08152064: .4byte 0x000005BC
_08152068: .4byte 0x000005EC
_0815206C: .4byte 0x00000624
_08152070: .4byte 0x0000058C
_08152074: .4byte 0x00000594
_08152078: .4byte 0x0000059C
_0815207C: .4byte 0x000005B4
_08152080: .4byte 0x00000543
_08152084: .4byte 0x00000496
_08152088: .4byte 0x00000469
_0815208C: .4byte 0x0000046A
_08152090: .4byte 0x00000553
_08152094: .4byte 0x00000572
_08152098: .4byte 0x0000055C
_0815209C: .4byte 0x00000564
_081520A0: .4byte 0x00000565
_081520A4: .4byte 0x00000566
_081520A8: .4byte 0x00000567
_081520AC: .4byte 0x0000056C
_081520B0:
	movs r0, #0x18
_081520B2:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081520C4
	bl Script_GetValue
	b _081520C6
_081520C4:
	movs r0, #0x18
_081520C6:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081520D8
	bl Script_GetValue
	b _081520DA
_081520D8:
	movs r0, #0
_081520DA:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081520EC
	bl Script_GetValue
	b _081520EE
_081520EC:
	movs r0, #0
_081520EE:
	strh r0, [r6]
	movs r0, #2
	add sb, r0
	movs r1, #4
	add r8, r1
	adds r5, #2
	adds r4, #2
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	ble _0815200C
_08152106:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08152152
	bl VM_GetPC
	cmp r0, #0
	beq _08152120
	bl Script_GetValue
	adds r4, r0, #0
	b _08152124
_08152120:
	movs r4, #0x96
	lsls r4, r4, #1
_08152124:
	bl VM_GetPC
	cmp r0, #0
	beq _08152134
	bl Script_GetValue
	adds r6, r0, #0
	b _08152138
_08152134:
	movs r6, #0x96
	lsls r6, r6, #1
_08152138:
	bl VM_GetPC
	cmp r0, #0
	beq _08152146
	bl Script_GetValue
	b _0815214C
_08152146:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
_0815214C:
	ldr r1, [sp, #0xe8]
	strh r0, [r1]
	b _0815215A
_08152152:
	movs r4, #0
	movs r6, #0
	ldr r2, [sp, #0xe8]
	strh r6, [r2]
_0815215A:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08152172
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r3, [sp, #0x70]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_08152172:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x78]
	strh r0, [r5]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x74]
	strh r0, [r1]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08152240
	bl VM_GetPC
	cmp r0, #0
	beq _081521A2
	bl Script_GetValue
	b _081521A4
_081521A2:
	movs r0, #0
_081521A4:
	ldr r2, [sp, #0x100]
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, #0
	blt _081521B2
	asrs r1, r0, #1
	b _081521B8
_081521B2:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081521B8:
	ldr r3, _081521CC @ =0x00000546
	adds r0, r7, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081521D0
	bl Script_GetValue
	b _081521D2
	.align 2, 0
_081521CC: .4byte 0x00000546
_081521D0:
	movs r0, #0
_081521D2:
	movs r5, #0xc3
	lsls r5, r5, #1
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081521E8
	bl Script_GetValue
	b _081521EA
_081521E8:
	movs r0, #0
_081521EA:
	ldr r2, _08152200 @ =0x00000187
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08152204
	bl Script_GetValue
	adds r1, r0, #0
	b _08152206
	.align 2, 0
_08152200: .4byte 0x00000187
_08152204:
	movs r1, #0
_08152206:
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0815221C
	bl Script_GetValue
	b _0815221E
_0815221C:
	movs r0, #0
_0815221E:
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08152236
	bl Script_GetValue
	adds r1, r0, #0
	b _08152238
_08152236:
	movs r1, #0
_08152238:
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_08152240:
	ldr r3, [sp, #0x100]
	ldrh r1, [r3]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r4, [sp, #0x94]
	lsrs r2, r4, #0x10
	ldr r5, [sp, #0xa0]
	lsrs r3, r5, #0x10
	ldr r6, [sp, #0xa4]
	lsrs r0, r6, #0x10
	str r0, [sp]
	ldr r1, [sp, #0x9c]
	lsrs r0, r1, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081522A2
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r6, r7, r2
	bl VM_GetPC
	cmp r0, #0
	beq _08152288
	bl Script_GetValue
	b _0815228A
_08152288:
	movs r0, #0
_0815228A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _0815229A
	bl Script_GetValue
	b _0815229C
_0815229A:
	movs r0, #0
_0815229C:
	ldr r3, _08152304 @ =0x00000189
	adds r1, r7, r3
	strb r0, [r1]
_081522A2:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r4, [sp, #0x10c]
	strh r0, [r4]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081522C6
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r5, [sp, #0x70]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081522C6:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081522DE
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_081522DE:
	ldr r0, [sp, #0x90]
	lsrs r1, r0, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x48]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08152308
	movs r0, #1
	b _0815230A
	.align 2, 0
_08152304: .4byte 0x00000189
_08152308:
	movs r0, #0
_0815230A:
	cmp r0, #0
	beq _0815231A
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08152344 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_0815231A:
	ldr r3, [sp, #0x110]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08152326
	ldr r1, [r7, #0x44]
_08152326:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0x98]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08152348
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x30]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08152354
	.align 2, 0
_08152344: .4byte FUN_080f48ac
_08152348:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x30]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08152354:
	ldr r5, [sp, #0x98]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081523A2
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081523A2
	cmp r0, #0x16
	beq _081523A2
	cmp r0, #0x14
	beq _081523A2
	cmp r0, #9
	beq _081523A2
	cmp r0, #0x19
	beq _081523A2
	cmp r0, #0x1a
	beq _081523A2
	cmp r0, #0xd
	beq _081523A2
	cmp r0, #0x1b
	beq _081523A2
	cmp r0, #0x1f
	beq _081523A2
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xf0]
	ldrb r2, [r6]
	ldr r0, [sp, #0xf4]
	ldrb r3, [r0]
	ldr r4, [sp, #0xfc]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_081523A2:
	movs r1, #8
	ldr r5, [sp, #0x48]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081523B2
	movs r0, #1
	b _081523B4
_081523B2:
	movs r0, #0
_081523B4:
	cmp r0, #0
	beq _081523C2
	ldr r6, [sp, #0xac]
	ldr r0, [r6]
	ldr r1, [sp, #0xa8]
	str r0, [r1]
	b _081523D4
_081523C2:
	ldr r2, [sp, #0xac]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xa8]
	str r0, [r3]
_081523D4:
	ldrh r0, [r7]
	ldr r4, [sp, #0x34]
	strh r0, [r4]
	ldr r5, [sp, #0x198]
	ldr r6, [sp, #0x38]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _081523FE
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
_081523FE:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08152446
	bl VM_GetPC
	cmp r0, #0
	beq _08152418
	bl Script_GetValue
	adds r1, r0, #0
	b _0815241A
_08152418:
	movs r1, #0xc8
_0815241A:
	ldr r2, [sp, #0x24]
	ldr r3, _08152434 @ =0x000006CC
	adds r0, r2, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08152438
	bl Script_GetValue
	adds r1, r0, #0
	b _0815243E
	.align 2, 0
_08152434: .4byte 0x000006CC
_08152438:
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r1, r4, #0
_0815243E:
	ldr r5, [sp, #0x24]
	ldr r6, _08152464 @ =0x000006CE
	adds r0, r5, r6
	strh r1, [r0]
_08152446:
	movs r0, #0x59
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081524C6
	ldr r0, [sp, #0x24]
	ldr r1, _08152468 @ =0x000006B4
	adds r4, r0, r1
	bl VM_GetPC
	cmp r0, #0
	beq _0815246C
	bl Script_GetValue
	b _0815246E
	.align 2, 0
_08152464: .4byte 0x000006CE
_08152468: .4byte 0x000006B4
_0815246C:
	movs r0, #0
_0815246E:
	str r0, [r4]
	ldr r2, [sp, #0x24]
	ldr r3, _08152490 @ =0x000006B4
	adds r1, r2, r3
	ldr r0, [r1]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	str r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08152494
	bl Script_GetValue
	adds r1, r0, #0
	b _0815249A
	.align 2, 0
_08152490: .4byte 0x000006B4
_08152494:
	movs r5, #0xa0
	lsls r5, r5, #2
	adds r1, r5, #0
_0815249A:
	ldr r6, [sp, #0x24]
	ldr r2, _081524B4 @ =0x000006C2
	adds r0, r6, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081524B8
	bl Script_GetValue
	adds r1, r0, #0
	b _081524BE
	.align 2, 0
_081524B4: .4byte 0x000006C2
_081524B8:
	movs r3, #0xa0
	lsls r3, r3, #2
	adds r1, r3, #0
_081524BE:
	ldr r4, [sp, #0x24]
	ldr r5, _08152530 @ =0x000006C4
	adds r0, r4, r5
	strh r1, [r0]
_081524C6:
	movs r0, #0x64
	movs r1, #0x32
	bl VM_GetKeywordValue
	ldr r6, [sp, #0x24]
	ldr r2, _08152534 @ =0x000006D9
	adds r1, r6, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081524E0
	movs r0, #0x32
	strb r0, [r1]
_081524E0:
	ldr r3, [sp, #0x24]
	movs r4, #0xda
	lsls r4, r4, #3
	adds r1, r3, r4
	ldr r0, _08152538 @ =0x0000FFFF
	strh r0, [r1]
	ldr r5, _0815253C @ =0x000006D4
	adds r1, r3, r5
	movs r0, #0
	strh r0, [r1]
	ldr r4, _08152540 @ =0x000001F5
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r6, [sp, #0x58]
	strh r0, [r6]
	ldr r0, [sp, #0x4c]
	strh r4, [r0]
	ldr r1, [sp, #0x50]
	strh r5, [r1]
	ldrh r0, [r6]
	adds r0, r0, r4
	ldr r2, [sp, #0x54]
	strh r0, [r2]
	ldr r3, [sp, #0x4c]
	ldrh r1, [r3]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r4, [sp, #0x110]
	ldrb r0, [r4]
	cmp r0, #0
	bne _08152544
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _08152550
	.align 2, 0
_08152530: .4byte 0x000006C4
_08152534: .4byte 0x000006D9
_08152538: .4byte 0x0000FFFF
_0815253C: .4byte 0x000006D4
_08152540: .4byte 0x000001F5
_08152544:
	ldr r2, [r7, #0x44]
	ldr r0, _08152588 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08152550:
	ldr r5, [sp, #0x110]
	ldrb r0, [r5]
	cmp r0, #1
	bne _081525A0
	ldr r6, [sp, #0x98]
	ldrb r0, [r6]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0815258C
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
	b _08152596
	.align 2, 0
_08152588: .4byte 0x03003584
_0815258C:
	ldr r1, [sp, #0x98]
	ldrb r0, [r1]
	bl FUN_080ecf60
	adds r4, r0, #1
_08152596:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081525A0:
	adds r0, r7, #0
	bl FUN_0814ab28
	ldr r2, [sp, #0x24]
	ldr r3, _0815275C @ =0x000006DC
	adds r0, r2, r3
	movs r4, #0xe0
	lsls r4, r4, #3
	adds r4, r2, r4
	str r4, [sp, #0x1a4]
	ldr r5, _08152760 @ =FUN_081518c0
	mov r8, r5
	ldr r6, _08152764 @ =FUN_0814a8dc
	mov sb, r6
	ldr r1, _08152768 @ =FUN_0814c2d4
	mov sl, r1
	ldr r2, _0815276C @ =FUN_0814c28c
	mov ip, r2
	ldr r4, _08152770 @ =FUN_0814ccfc
	ldr r5, _08152774 @ =FUN_0814e680
	ldr r3, _08152778 @ =FUN_080f62b0
	ldr r6, _0815277C @ =FUN_080f62ac
	str r6, [sp, #0x19c]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x6c]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x64]
	str r0, [r1]
	ldr r2, [sp, #0x1a4]
	ldr r6, [sp, #0x68]
	str r2, [r6]
	mov r1, r8
	ldr r2, [sp, #0xec]
	str r1, [r2]
	mov r6, sb
	ldr r1, [sp, #0x104]
	str r6, [r1]
	mov r2, sl
	ldr r6, [sp, #0x114]
	str r2, [r6]
	mov r1, ip
	ldr r2, [sp, #0x124]
	str r1, [r2]
	ldr r6, _08152780 @ =FUN_0814c2b0
	ldr r1, [sp, #0x128]
	str r6, [r1]
	ldr r2, _08152784 @ =FUN_0814c974
	ldr r6, [sp, #0x13c]
	str r2, [r6]
	ldr r1, [sp, #0x140]
	str r3, [r1]
	ldr r2, [sp, #0x148]
	str r4, [r2]
	ldr r3, [sp, #0x14c]
	str r5, [r3]
	ldr r1, _08152788 @ =FUN_080f44f4
	ldr r4, [sp, #0x150]
	str r1, [r4]
	ldr r1, _0815278C @ =FUN_080f410c
	ldr r5, [sp, #0x158]
	str r1, [r5]
	ldr r6, _08152790 @ =FUN_0814cb8c
	ldr r1, [sp, #0x144]
	str r6, [r1]
	ldr r2, _08152794 @ =FUN_0814c970
	ldr r3, [sp, #0xf8]
	str r2, [r3]
	ldr r4, [sp, #0x19c]
	ldr r5, [sp, #0x17c]
	str r4, [r5]
	ldr r1, _08152798 @ =FUN_080f0430
	ldr r6, [sp, #0x180]
	str r1, [r6]
	movs r4, #0
	movs r2, #1
	ldr r1, [sp, #0xb4]
	strb r2, [r1]
	ldr r1, _0815279C @ =0x085AD470
	ldr r3, [sp, #0x184]
	str r1, [r3]
	ldr r1, _081527A0 @ =FUN_080e73c8
	ldr r5, [sp, #0x16c]
	str r1, [r5]
	ldr r6, [sp, #0x160]
	str r4, [r6]
	ldr r1, [sp, #0x170]
	str r4, [r1]
	ldr r2, [sp, #0x174]
	str r4, [r2]
	ldr r3, [sp, #0x178]
	str r4, [r3]
	ldr r5, [sp, #0x188]
	str r4, [r5]
	ldr r1, _081527A4 @ =FUN_080f0320
	ldr r6, [sp, #0x18c]
	str r1, [r6]
	ldr r1, _081527A8 @ =FUN_080eff14
	ldr r2, [sp, #0x138]
	str r1, [r2]
	ldr r1, _081527AC @ =FUN_080e72b0
	ldr r3, [sp, #0x164]
	str r1, [r3]
	ldr r5, _081527B0 @ =FUN_0814e420
	ldr r6, [sp, #0x15c]
	str r5, [r6]
	ldr r1, _081527B4 @ =FUN_080f47c8
	ldr r2, [sp, #0x168]
	str r1, [r2]
	ldr r1, _081527B8 @ =FUN_080f54e4
	ldr r3, [sp, #0x154]
	str r1, [r3]
	ldr r5, [sp, #0x12c]
	str r4, [r5]
	ldr r1, _081527BC @ =FUN_080f6e64
	ldr r6, [sp, #0x190]
	str r1, [r6]
	ldr r1, _081527C0 @ =FUN_080f64f0
	ldr r2, [sp, #0x108]
	str r1, [r2]
	ldr r1, _081527C4 @ =FUN_080f84d4
	ldr r3, [sp, #0x194]
	str r1, [r3]
	ldr r1, _081527C8 @ =FUN_080f624c
	ldr r5, [sp, #0x134]
	str r1, [r5]
	ldr r1, _081527CC @ =FUN_080f56ec
	ldr r6, [sp, #0x118]
	str r1, [r6]
	ldr r1, _081527D0 @ =FUN_080f5b34
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	ldr r1, _081527D4 @ =FUN_080f5fac
	ldr r3, [sp, #0x120]
	str r1, [r3]
	ldr r5, [sp, #0x130]
	str r4, [r5]
	movs r1, #0x28
	ldr r6, [sp, #0xb0]
	strb r1, [r6]
	ldr r1, [sp, #0x198]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	movs r0, #0xbf
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081527D8 @ =FUN_0814a78c
	str r0, [r1]
	ldr r2, _081527DC @ =0x000005FC
	adds r1, r7, r2
	ldr r0, _081527E0 @ =FUN_0814a8c8
	str r0, [r1]
	ldr r3, _081527E4 @ =0x000005AC
	adds r1, r7, r3
	ldr r0, _081527E8 @ =enemy_dog_08149f6c
	str r0, [r1]
	movs r5, #0xb6
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _081527EC @ =FUN_0814a098
	str r0, [r1]
	ldr r6, _081527F0 @ =0x0000058C
	adds r1, r7, r6
	ldr r0, _081527F4 @ =FUN_0814eacc
	str r0, [r1]
	ldr r0, _081527F8 @ =0x000005BC
	adds r1, r7, r0
	ldr r0, _081527FC @ =FUN_0814e248
	str r0, [r1]
	adds r2, #0x1c
	adds r1, r7, r2
	ldr r0, _08152800 @ =FUN_0814b3e0
	str r0, [r1]
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r4, [r0]
	ldr r4, _08152804 @ =0x00000543
	adds r1, r7, r4
	movs r0, #0x14
	strb r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #0x11
	ldr r5, [sp, #0x6c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r1, #8
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x7c]
	strh r0, [r1]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08152812
	movs r2, #0xce
	lsls r2, r2, #1
	adds r5, r7, r2
	movs r4, #4
_0815274E:
	bl VM_GetPC
	cmp r0, #0
	beq _08152808
	bl Script_GetValue
	b _0815280A
	.align 2, 0
_0815275C: .4byte 0x000006DC
_08152760: .4byte FUN_081518c0
_08152764: .4byte FUN_0814a8dc
_08152768: .4byte FUN_0814c2d4
_0815276C: .4byte FUN_0814c28c
_08152770: .4byte FUN_0814ccfc
_08152774: .4byte FUN_0814e680
_08152778: .4byte FUN_080f62b0
_0815277C: .4byte FUN_080f62ac
_08152780: .4byte FUN_0814c2b0
_08152784: .4byte FUN_0814c974
_08152788: .4byte FUN_080f44f4
_0815278C: .4byte FUN_080f410c
_08152790: .4byte FUN_0814cb8c
_08152794: .4byte FUN_0814c970
_08152798: .4byte FUN_080f0430
_0815279C: .4byte 0x085AD470
_081527A0: .4byte FUN_080e73c8
_081527A4: .4byte FUN_080f0320
_081527A8: .4byte FUN_080eff14
_081527AC: .4byte FUN_080e72b0
_081527B0: .4byte FUN_0814e420
_081527B4: .4byte FUN_080f47c8
_081527B8: .4byte FUN_080f54e4
_081527BC: .4byte FUN_080f6e64
_081527C0: .4byte FUN_080f64f0
_081527C4: .4byte FUN_080f84d4
_081527C8: .4byte FUN_080f624c
_081527CC: .4byte FUN_080f56ec
_081527D0: .4byte FUN_080f5b34
_081527D4: .4byte FUN_080f5fac
_081527D8: .4byte FUN_0814a78c
_081527DC: .4byte 0x000005FC
_081527E0: .4byte FUN_0814a8c8
_081527E4: .4byte 0x000005AC
_081527E8: .4byte enemy_dog_08149f6c
_081527EC: .4byte FUN_0814a098
_081527F0: .4byte 0x0000058C
_081527F4: .4byte FUN_0814eacc
_081527F8: .4byte 0x000005BC
_081527FC: .4byte FUN_0814e248
_08152800: .4byte FUN_0814b3e0
_08152804: .4byte 0x00000543
_08152808:
	movs r0, #0
_0815280A:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0815274E
_08152812:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x80]
	strh r0, [r3]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r4, [sp, #0x60]
	strh r0, [r4]
	cmp r2, #0
	beq _0815284A
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r5, [sp, #0x6c]
	ldr r1, [r5]
	orrs r1, r0
	str r1, [r5]
	cmp r2, #2
	bne _0815284A
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r5]
_0815284A:
	movs r2, #0
	movs r1, #4
	ldr r6, [sp, #0x48]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0815285C
	movs r0, #1
	b _0815285E
_0815285C:
	movs r0, #0
_0815285E:
	cmp r0, #0
	beq _08152870
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r2, [sp, #0x70]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r2, #1
_08152870:
	cmp r2, #1
	beq _081528B0
	movs r1, #0
	ldr r3, [sp, #0x3c]
	strb r1, [r3]
	ldr r4, [sp, #0x40]
	strb r1, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r6, _081528C0 @ =0x00000484
	adds r0, r7, r6
	str r1, [r0]
	ldr r2, _081528C4 @ =0x0000046C
	adds r0, r7, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, [sp, #0x128]
	ldr r3, [r4]
	ldr r5, _081528C8 @ =0x0000046D
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #0x19
	adds r0, r7, r6
	strb r1, [r0]
	ldr r0, [sp, #0xb8]
	strb r1, [r0]
	ldr r2, [sp, #0xe4]
	str r3, [r2]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081528B0:
	movs r1, #2
	ldr r4, [sp, #0x48]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081528CC
	movs r0, #1
	b _081528CE
	.align 2, 0
_081528C0: .4byte 0x00000484
_081528C4: .4byte 0x0000046C
_081528C8: .4byte 0x0000046D
_081528CC:
	movs r0, #0
_081528CE:
	cmp r0, #0
	beq _081528E8
	ldr r0, _081528E4 @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x92
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r6, [sp, #0x5c]
	strh r0, [r6]
	b _081528F2
	.align 2, 0
_081528E4: .4byte 0x030046A0
_081528E8:
	ldr r0, [sp, #0x198]
	bl FUN_08241574
	ldr r1, [sp, #0x5c]
	strh r0, [r1]
_081528F2:
	movs r1, #0x40
	ldr r2, [sp, #0x48]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08152902
	movs r0, #1
	b _08152904
_08152902:
	movs r0, #0
_08152904:
	cmp r0, #0
	beq _08152914
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08152938 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08152914:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _08152946
	ldr r0, _0815293C @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x5c]
	ldrh r4, [r4]
	cmp r0, r4
	bne _08152940
	movs r0, #1
	b _08152942
	.align 2, 0
_08152938: .4byte 0xFFFFFEFF
_0815293C: .4byte 0x030046A0
_08152940:
	movs r0, #0
_08152942:
	cmp r0, #0
	bne _0815294E
_08152946:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_0815294E:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x110]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08152A36
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
	beq _08152990
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08152998
_08152990:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08152998:
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
	beq _081529BC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081529C4
_081529BC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081529C4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081529FC @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08152A40
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08152A00
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081529F4
	ldrb r0, [r4, #5]
_081529F4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08152A10
	.align 2, 0
_081529FC: .4byte 0x0000FFFF
_08152A00:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08152A10
	strh r1, [r4, #8]
_08152A10:
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
	bne _08152A40
	movs r0, #1
	strb r0, [r4, #7]
	b _08152A40
_08152A36:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_08152A40:
	movs r0, #0
	ldr r3, [sp, #0x8c]
	str r0, [r3]
	ldr r0, _08152A58 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08152A5C
	movs r0, #1
	b _08152A5E
	.align 2, 0
_08152A58: .4byte 0x030047A4
_08152A5C:
	movs r0, #0
_08152A5E:
	cmp r0, #0
	bne _08152A9E
	ldr r4, [sp, #0x98]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08152A86
	adds r0, r1, #0
	cmp r0, #7
	beq _08152A86
	cmp r0, #6
	beq _08152A86
	cmp r0, #0x15
	beq _08152A86
	cmp r0, #0x14
	beq _08152A86
	cmp r0, #0x17
	bne _08152A9E
_08152A86:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x48]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08152A9E:
	ldr r6, [sp, #0x88]
	ldr r3, [r6]
	ldr r1, [sp, #0x58]
	ldrh r0, [r1]
	cmp r0, #1
	bls _08152AAE
	cmp r0, #4
	bne _08152AC0
_08152AAE:
	ldr r4, _08152ABC @ =0x000006AC
	adds r2, r3, r4
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [r2]
	b _08152AD6
	.align 2, 0
_08152ABC: .4byte 0x000006AC
_08152AC0:
	ldr r0, _08152B78 @ =0x000006AC
	adds r2, r3, r0
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [r2]
	movs r4, #0xd6
	lsls r4, r4, #3
	adds r1, r3, r4
	movs r0, #0xe1
	lsls r0, r0, #0xa
	str r0, [r1]
_08152AD6:
	movs r5, #0xd7
	lsls r5, r5, #3
	adds r1, r3, r5
	ldr r0, _08152B7C @ =0x0000FFFF
	str r0, [r1]
	ldr r6, _08152B80 @ =0x000006BC
	adds r1, r3, r6
	ldr r0, [r2]
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_081518ac
	adds r0, r7, #0
	bl FUN_081504e8
	adds r0, r7, #0
	bl FUN_0815077c
	ldr r1, [sp, #0x48]
	ldrh r0, [r1]
	ldr r2, [sp, #0xe0]
	strh r0, [r2]
	ldr r3, [sp, #0x84]
	ldrh r0, [r3]
	ldr r4, [sp, #0xdc]
	strh r0, [r4]
	ldr r5, [sp, #0x6c]
	ldr r0, [r5]
	ldr r6, [sp, #0xbc]
	str r0, [r6]
	ldr r1, [sp, #0x70]
	ldr r0, [r1]
	ldr r2, [sp, #0xc0]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xc4]
	strb r0, [r3]
	ldr r4, [sp, #0x3c]
	ldrb r0, [r4]
	ldr r5, [sp, #0xc8]
	strb r0, [r5]
	ldr r6, [sp, #0x40]
	ldrb r0, [r6]
	ldr r1, [sp, #0xcc]
	strb r0, [r1]
	ldr r2, [sp, #0x44]
	ldrb r0, [r2]
	ldr r3, [sp, #0xd0]
	strb r0, [r3]
	ldr r4, [sp, #0xe4]
	ldr r0, [r4]
	ldr r5, [sp, #0xd4]
	str r0, [r5]
	ldr r6, [sp, #0xb8]
	ldrb r0, [r6]
	ldr r1, [sp, #0xd8]
	strb r0, [r1]
	ldr r2, _08152B84 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _08152B88 @ =FUN_080f09e0
	str r0, [r1]
	ldr r3, _08152B8C @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _08152B90 @ =FUN_0815190c
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08152B94 @ =EnemyDog_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08152B98
	movs r0, #0
	b _08152B9C
	.align 2, 0
_08152B78: .4byte 0x000006AC
_08152B7C: .4byte 0x0000FFFF
_08152B80: .4byte 0x000006BC
_08152B84: .4byte 0x0000057C
_08152B88: .4byte FUN_080f09e0
_08152B8C: .4byte 0x0000061C
_08152B90: .4byte FUN_0815190c
_08152B94: .4byte EnemyDog_Destroy
_08152B98:
	movs r0, #1
	rsbs r0, r0, #0
_08152B9C:
	add sp, #0x1a8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyDog_Create
EnemyDog_Create: @ 0x08152BAC
	push {r4, r5, lr}
	movs r5, #0xe2
	lsls r5, r5, #3
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _08152BDA
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyDog_Init
	cmp r0, #0
	bge _08152BDA
	adds r0, r4, #0
	bl EnemyDog_Destroy
	adds r0, r4, #0
	bl Free
_08152BDA:
	pop {r4, r5}
	pop {r0}
	bx r0
