	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0804ee30
FUN_0804ee30: @ 0x0804EE30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	mov r8, r0
	adds r6, r1, #0
	ldr r0, _0804EE58 @ =0x0000CB05
	ldr r1, _0804EE5C @ =0x085AB674
	lsls r2, r2, #3
	adds r5, r2, r1
	ldrh r1, [r5]
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0804EE60
	movs r0, #1
	rsbs r0, r0, #0
	b _0804EEFA
	.align 2, 0
_0804EE58: .4byte 0x0000CB05
_0804EE5C: .4byte 0x085AB674
_0804EE60:
	adds r1, r6, #0
	adds r1, #8
	adds r0, r2, #0
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4, r7}
	stm r1!, {r3, r4, r7}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #8
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	ldrb r0, [r5, #5]
	ldr r3, _0804EF08 @ =0xFFFF0000
	ldr r1, [sp, #0x10]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #0x10]
	ldrb r2, [r5, #6]
	lsls r2, r2, #0x10
	ldr r0, _0804EF0C @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	str r0, [sp, #0x14]
	adds r0, r6, #0
	adds r0, #0x28
	ldrh r2, [r5, #2]
	ldrb r1, [r5, #4]
	movs r3, #0x11
	orrs r3, r1
	movs r1, #1
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	adds r1, r4, #0
	bl FUN_0822f3fc
	movs r7, #0
	adds r4, #0x80
	movs r5, #4
_0804EEC4:
	movs r0, #1
	str r0, [sp]
	str r7, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, _0804EF10 @ =0x00000664
	add r1, r8
	movs r2, #0
	movs r3, #0x11
	bl FUN_0822f3fc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0804EEC4
	movs r0, #0
	strb r0, [r6]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0x9f
	lsls r3, r3, #2
	adds r1, r6, r3
	strb r0, [r1]
_0804EEFA:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804EF08: .4byte 0xFFFF0000
_0804EF0C: .4byte 0x0000FFFF
_0804EF10: .4byte 0x00000664

	thumb_func_start FUN_0804ef14
FUN_0804ef14: @ 0x0804EF14
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x28
	bl FUN_0822f1c0
	adds r4, #0x88
	movs r5, #4
_0804EF24:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0804EF24
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804ef38
FUN_0804ef38: @ 0x0804EF38
	ldr r2, [r1, #0x30]
	movs r3, #2
	rsbs r3, r3, #0
	ands r2, r3
	str r2, [r1, #0x30]
	bx lr

	thumb_func_start FUN_0804ef44
FUN_0804ef44: @ 0x0804EF44
	ldr r2, [r1, #0x30]
	movs r3, #1
	orrs r2, r3
	str r2, [r1, #0x30]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0804ef50
FUN_0804ef50: @ 0x0804EF50
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	adds r6, r1, #0
	mov sb, r2
	mov sl, r3
	ldr r5, [sp, #0x24]
	mov r0, sb
	bl FUN_0804f814
	adds r7, r0, #0
	movs r0, #0
	str r0, [r6, #4]
	str r0, [sp]
	ldr r4, _0804EFDC @ =0x00000564
	add r4, r8
	ldr r2, _0804EFE0 @ =0x05000001
	mov r0, sp
	adds r1, r4, #0
	bl CpuSet
	mov r1, sl
	lsls r0, r1, #2
	add r0, sl
	lsls r0, r0, #1
	adds r0, #4
	adds r5, r5, r0
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x10
	bl FUN_08230ab0
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r6, r6, r0
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #8
	bl FUN_0804e69c
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0x10
	bl FUN_08230ab0
	mov r1, sb
	lsls r0, r1, #2
	ldr r1, _0804EFE4 @ =0x00000554
	add r8, r1
	add r8, r0
	mov r1, r8
	ldr r0, [r1]
	movs r1, #3
	add sb, r1
	mov r1, sb
	bl FUN_0804a2f8
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804EFDC: .4byte 0x00000564
_0804EFE0: .4byte 0x05000001
_0804EFE4: .4byte 0x00000554

	thumb_func_start FUN_0804efe8
FUN_0804efe8: @ 0x0804EFE8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r0, r5, #0
	bl FUN_0804f814
	adds r3, r0, #0
	movs r0, #0
	str r0, [r4, #4]
	movs r2, #0
	movs r1, #0xf
	ldr r7, _0804F034 @ =0x00000277
	adds r0, r4, r7
_0804F004:
	strb r2, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0804F004
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r1, r4, r0
	adds r0, r3, #0
	movs r2, #0x10
	bl FUN_08230ab0
	lsls r1, r5, #2
	ldr r2, _0804F038 @ =0x00000554
	adds r0, r6, r2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r5, #3
	bl FUN_0804a2f8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804F034: .4byte 0x00000277
_0804F038: .4byte 0x00000554

	thumb_func_start FUN_0804f03c
FUN_0804f03c: @ 0x0804F03C
	push {lr}
	bl FUN_0804e474
	adds r2, r0, #0
	movs r1, #0
	movs r3, #1
_0804F048:
	adds r0, r2, #0
	asrs r0, r1
	ands r0, r3
	cmp r0, #0
	beq _0804F056
	adds r0, r1, #1
	b _0804F05E
_0804F056:
	adds r1, #1
	cmp r1, #3
	ble _0804F048
	movs r0, #0
_0804F05E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0804f064
FUN_0804f064: @ 0x0804F064
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	mov r8, r0
	adds r7, r1, #0
	adds r4, r2, #0
	bl FUN_0804e438
	adds r6, r0, #0
	cmp r4, #0
	bne _0804F0A8
	bl FUN_0804e638
	adds r2, r0, #0
	adds r0, r7, #0
	adds r0, #0x88
	ldr r1, _0804F0A4 @ =0x00000664
	add r1, r8
	str r4, [sp]
	movs r3, #0x18
	str r3, [sp, #4]
	movs r3, #0x46
	str r3, [sp, #8]
	movs r3, #8
	str r3, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r3, #5
	bl FUN_082376a4
	b _0804F0B0
	.align 2, 0
_0804F0A4: .4byte 0x00000664
_0804F0A8:
	bl FUN_0804e474
	cmp r0, #0
	beq _0804F0BA
_0804F0B0:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_0804ef38
	b _0804F0C2
_0804F0BA:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_0804ef44
_0804F0C2:
	cmp r6, #0
	beq _0804F160
	adds r0, r6, #0
	bl FUN_0804f03c
	adds r5, r0, #0
	cmp r4, #0
	bne _0804F130
	ldrb r0, [r7]
	cmp r0, #0
	bne _0804F160
	movs r0, #0
	bl FUN_0804f814
	adds r6, r0, #0
	str r4, [sp, #0x14]
	ldr r1, _0804F120 @ =0x00000564
	add r1, r8
	ldr r2, _0804F124 @ =0x05000001
	add r0, sp, #0x14
	bl CpuSet
	ldr r5, _0804F128 @ =0x030046A0
	ldr r1, [r5]
	movs r4, #0xf0
	lsls r4, r4, #2
	adds r1, r1, r4
	adds r0, r6, #0
	movs r2, #0x10
	bl FUN_08230ab0
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r5]
	adds r1, r1, r4
	movs r2, #0x10
	bl FUN_08230ab0
	ldr r0, _0804F12C @ =0x00000554
	add r0, r8
	ldr r0, [r0]
	movs r1, #3
	bl FUN_0804a2f8
	b _0804F148
	.align 2, 0
_0804F120: .4byte 0x00000564
_0804F124: .4byte 0x05000001
_0804F128: .4byte 0x030046A0
_0804F12C: .4byte 0x00000554
_0804F130:
	cmp r5, #0
	beq _0804F14E
	ldrb r0, [r7]
	cmp r0, #0
	bne _0804F160
	str r6, [sp]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	adds r3, r5, #0
	bl FUN_0804ef50
_0804F148:
	movs r0, #1
	strb r0, [r7]
	b _0804F160
_0804F14E:
	ldrb r0, [r7]
	cmp r0, #0
	beq _0804F160
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0804efe8
	strb r5, [r7]
_0804F160:
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804f16c
FUN_0804f16c: @ 0x0804F16C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _0804F17A
	movs r0, #0
	strb r0, [r4, #0x1a]
_0804F17A:
	ldr r0, [r4, #0x20]
	cmp r0, #0xf
	bls _0804F1C8
	bl FUN_0804e458
	adds r5, r0, #0
	cmp r5, #0
	beq _0804F1AC
	ldr r0, _0804F1A8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804F1C8
	bl FUN_0804e4c4
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #0x19]
	movs r0, #1
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x20]
	b _0804F1C8
	.align 2, 0
_0804F1A8: .4byte 0x030044E0
_0804F1AC:
	ldr r0, _0804F1D4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804F1C8
	bl FUN_0804e4c4
	movs r0, #7
	strb r0, [r4, #0x19]
	movs r0, #1
	strb r0, [r4, #0x1a]
	str r5, [r4, #0x20]
_0804F1C8:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804F1D4: .4byte 0x030044E0

	thumb_func_start FUN_0804f1d8
FUN_0804f1d8: @ 0x0804F1D8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _0804F1FA
	movs r0, #0
	strb r0, [r4, #0x1a]
	ldr r1, _0804F228 @ =0x0000055C
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #2
	bl FUN_0804a2f8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804F1FA:
	ldr r0, [r4, #0x20]
	cmp r0, #0x23
	bls _0804F21C
	ldr r0, _0804F22C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0804F21C
	bl FUN_0804e4c4
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #0x19]
	movs r0, #1
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x20]
_0804F21C:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804F228: .4byte 0x0000055C
_0804F22C: .4byte 0x030044E0

	thumb_func_start FUN_0804f230
FUN_0804f230: @ 0x0804F230
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	bl FUN_0804e474
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r6, #0x1a]
	cmp r0, #0
	beq _0804F260
	movs r0, #0
	strb r0, [r6, #0x1a]
	ldr r1, _0804F348 @ =0x0000055C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #7
	bl FUN_0804a2f8
	movs r0, #0xff
	strb r0, [r6, #0x1c]
_0804F260:
	ldrb r0, [r6, #0x1c]
	cmp r7, r0
	bne _0804F268
	b _0804F380
_0804F268:
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r1, r1, r6
	mov r8, r1
	cmp r7, #0
	beq _0804F35C
	ldr r5, _0804F34C @ =0x03005800
	ldr r0, [r5]
	ldrb r0, [r0, #2]
	cmp r7, r0
	bne _0804F35C
	bl FUN_0804e438
	cmp r0, #0
	beq _0804F33A
	movs r4, #0
	ldr r0, [r5]
	ldrb r1, [r0, #2]
	movs r0, #1
	ands r1, r0
	ldr r0, _0804F350 @ =0x0000053C
	adds r0, r0, r6
	mov sb, r0
	movs r0, #0xd2
	lsls r0, r0, #2
	adds r0, r0, r6
	mov sl, r0
	cmp r1, #0
	bne _0804F2B8
	adds r2, r5, #0
	movs r1, #1
_0804F2A6:
	adds r4, #1
	cmp r4, #3
	bgt _0804F2B8
	ldr r0, [r2]
	ldrb r0, [r0, #2]
	asrs r0, r4
	ands r0, r1
	cmp r0, #0
	beq _0804F2A6
_0804F2B8:
	movs r1, #0xb0
	lsls r1, r1, #2
	adds r1, r1, r6
	mov r8, r1
	mov r0, sb
	movs r1, #0x18
	bl ClearMemory
	ldr r5, _0804F34C @ =0x03005800
	lsls r4, r4, #5
	adds r4, #0x14
	ldr r0, [r5]
	adds r0, r0, r4
	adds r0, #6
	mov r1, sb
	movs r2, #0xb
	bl FUN_0804e69c
	ldr r0, [r5]
	adds r0, r0, r4
	adds r0, #6
	ldrb r2, [r0, #0xb]
	ldrb r0, [r0, #0xc]
	lsls r0, r0, #8
	orrs r2, r0
	ldr r0, _0804F354 @ =0x00000664
	adds r1, r6, r0
	movs r3, #0
	str r3, [sp]
	movs r0, #0x88
	str r0, [sp, #4]
	movs r0, #0x46
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r3, [sp, #0x10]
	mov r0, sl
	movs r3, #5
	bl FUN_082376a4
	movs r2, #2
	rsbs r2, r2, #0
	movs r0, #0xd4
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r4, #4
_0804F314:
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0804F314
	ldr r1, _0804F348 @ =0x0000055C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r2, #0x9f
	lsls r2, r2, #2
	add r2, r8
	movs r1, #2
	bl FUN_0804a40c
	ldr r0, _0804F358 @ =0x000001EF
	bl PlaySound_082406e0
_0804F33A:
	ldr r1, _0804F348 @ =0x0000055C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #8
	bl FUN_0804a2f8
	b _0804F37E
	.align 2, 0
_0804F348: .4byte 0x0000055C
_0804F34C: .4byte 0x03005800
_0804F350: .4byte 0x0000053C
_0804F354: .4byte 0x00000664
_0804F358: .4byte 0x000001EF
_0804F35C:
	ldr r1, _0804F3AC @ =0x0000055C
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #7
	bl FUN_0804a2f8
	movs r1, #1
	mov r2, r8
	adds r2, #0x90
	movs r4, #4
_0804F370:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r2, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0804F370
_0804F37E:
	strb r7, [r6, #0x1c]
_0804F380:
	ldr r0, _0804F3B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0804F394
	cmp r7, #0
	beq _0804F394
	bl FUN_0804e4c4
_0804F394:
	ldr r0, _0804F3B0 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0804F3C2
	cmp r7, #0
	beq _0804F3B4
	bl FUN_0804e4ac
	b _0804F3C2
	.align 2, 0
_0804F3AC: .4byte 0x0000055C
_0804F3B0: .4byte 0x030044E0
_0804F3B4:
	bl FUN_0804e4c4
	movs r0, #7
	strb r0, [r6, #0x19]
	movs r0, #1
	strb r0, [r6, #0x1a]
	str r7, [r6, #0x20]
_0804F3C2:
	ldr r0, [r6, #0x20]
	adds r0, #1
	str r0, [r6, #0x20]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0804f3d8
FUN_0804f3d8: @ 0x0804F3D8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _0804F3F2
	movs r0, #0
	strb r0, [r4, #0x1a]
	ldr r1, _0804F400 @ =0x0000055C
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #9
	bl FUN_0804a2f8
_0804F3F2:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804F400: .4byte 0x0000055C

	thumb_func_start FUN_0804f404
FUN_0804f404: @ 0x0804F404
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _0804F436
	movs r0, #0
	strb r0, [r4, #0x1a]
	ldr r1, _0804F444 @ =0x0000055C
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #6
	bl FUN_0804a2f8
	movs r3, #1
	movs r0, #0xd4
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r2, #4
_0804F428:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0804F428
_0804F436:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804F444: .4byte 0x0000055C

	thumb_func_start FUN_0804f448
FUN_0804f448: @ 0x0804F448
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _0804F46A
	movs r0, #0
	strb r0, [r4, #0x1a]
	ldr r1, _0804F478 @ =0x0000055C
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0
	bl FUN_0804a2f8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804F46A:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804F478: .4byte 0x0000055C

	thumb_func_start FUN_0804f47c
FUN_0804f47c: @ 0x0804F47C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _0804F49E
	movs r0, #0
	strb r0, [r4, #0x1a]
	ldr r1, _0804F4AC @ =0x0000055C
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #1
	bl FUN_0804a2f8
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0804F49E:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804F4AC: .4byte 0x0000055C

	thumb_func_start FUN_0804f4b0
FUN_0804f4b0: @ 0x0804F4B0
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	beq _0804F4CA
	movs r0, #0
	strb r0, [r4, #0x1a]
	movs r0, #0xde
	bl PlaySound_082406e0
	bl FUN_0804e5e8
_0804F4CA:
	ldr r0, [r4, #0x20]
	cmp r0, #4
	bne _0804F4E6
	str r0, [sp]
	ldr r0, _0804F520 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_0804F4E6:
	ldr r0, [r4, #0x20]
	cmp r0, #0x18
	bne _0804F4F0
	bl FUN_0804e604
_0804F4F0:
	ldr r0, [r4, #0x20]
	cmp r0, #0x17
	bls _0804F510
	bl FUN_0804ba3c
	cmp r0, #0
	bne _0804F510
	movs r1, #0xac
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0804F510
	movs r1, #0
	bl Script_ExecById
_0804F510:
	ldr r0, [r4, #0x20]
	adds r0, #1
	str r0, [r4, #0x20]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804F520: .4byte 0x0000FFFF

	thumb_func_start FUN_0804f524
FUN_0804f524: @ 0x0804F524
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0804e490
	adds r2, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #7
	beq _0804F5D2
	ldrb r0, [r4, #0x18]
	cmp r2, r0
	beq _0804F5D0
	subs r0, r2, #7
	cmp r0, #0x16
	bhi _0804F5D0
	lsls r0, r0, #2
	ldr r1, _0804F54C @ =_0804F550
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F54C: .4byte _0804F550
_0804F550: @ jump table
	.4byte _0804F5B4 @ case 0
	.4byte _0804F5D0 @ case 1
	.4byte _0804F5B8 @ case 2
	.4byte _0804F5D0 @ case 3
	.4byte _0804F5BC @ case 4
	.4byte _0804F5D0 @ case 5
	.4byte _0804F5D0 @ case 6
	.4byte _0804F5D0 @ case 7
	.4byte _0804F5D0 @ case 8
	.4byte _0804F5D0 @ case 9
	.4byte _0804F5D0 @ case 10
	.4byte _0804F5D0 @ case 11
	.4byte _0804F5D0 @ case 12
	.4byte _0804F5D0 @ case 13
	.4byte _0804F5D0 @ case 14
	.4byte _0804F5D0 @ case 15
	.4byte _0804F5D0 @ case 16
	.4byte _0804F5D0 @ case 17
	.4byte _0804F5D0 @ case 18
	.4byte _0804F5D0 @ case 19
	.4byte _0804F5AC @ case 20
	.4byte _0804F5C0 @ case 21
	.4byte _0804F5C4 @ case 22
_0804F5AC:
	movs r0, #1
	movs r1, #0
	strb r0, [r4, #0x19]
	b _0804F5CC
_0804F5B4:
	movs r0, #2
	b _0804F5C6
_0804F5B8:
	movs r0, #3
	b _0804F5C6
_0804F5BC:
	movs r0, #4
	b _0804F5C6
_0804F5C0:
	movs r0, #5
	b _0804F5C6
_0804F5C4:
	movs r0, #6
_0804F5C6:
	movs r1, #0
	strb r0, [r4, #0x19]
	movs r0, #1
_0804F5CC:
	strb r0, [r4, #0x1a]
	str r1, [r4, #0x20]
_0804F5D0:
	strb r2, [r4, #0x18]
_0804F5D2:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start CrossoverLobby_Update
CrossoverLobby_Update: @ 0x0804F5D8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	bl FUN_0804e59c
	cmp r0, #0
	bne _0804F616
	adds r0, r6, #0
	bl FUN_0804f524
	ldr r0, _0804F620 @ =0x085AB684
	ldrb r1, [r6, #0x19]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r6, #0
	bl _call_via_r1
	adds r5, r6, #0
	adds r5, #0x2c
	movs r4, #0
_0804F600:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0804f064
	adds r4, #1
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r5, r5, r0
	cmp r4, #1
	ble _0804F600
_0804F616:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0804F620: .4byte 0x085AB684

	thumb_func_start CrossoverLobby_Destroy
CrossoverLobby_Destroy: @ 0x0804F624
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x2c
	movs r4, #0
_0804F62E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0804ef14
	adds r4, #1
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r5, r5, r0
	cmp r4, #1
	ble _0804F62E
	ldr r0, _0804F660 @ =0x00000554
	adds r5, r6, r0
	movs r4, #2
_0804F64A:
	ldm r5!, {r0}
	bl FUN_0804a16c
	subs r4, #1
	cmp r4, #0
	bge _0804F64A
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0804F660: .4byte 0x00000554

	thumb_func_start CrossoverLobby_Init
CrossoverLobby_Init: @ 0x0804F664
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, _0804F7B0 @ =0x0000CB05
	ldr r1, _0804F7B4 @ =0x0000B343
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0804F67A
	b _0804F7C8
_0804F67A:
	ldr r1, _0804F7B8 @ =0x00000664
	adds r0, r6, r1
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	bne _0804F6A0
	b _0804F7C8
_0804F6A0:
	bl FUN_0823d340
	str r0, [r6, #0x28]
	cmp r0, #0
	bne _0804F6AC
	b _0804F7C8
_0804F6AC:
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	movs r7, #0xac
	lsls r7, r7, #3
	adds r1, r6, r7
	str r0, [r1]
	movs r1, #0
	strb r1, [r6, #0x19]
	movs r0, #1
	strb r0, [r6, #0x1a]
	str r1, [r6, #0x20]
	adds r0, r6, #0
	movs r1, #0xb
	bl FUN_0804edc8
	adds r5, r6, #0
	adds r5, #0x2c
	movs r4, #0
_0804F6D4:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0804ee30
	cmp r0, #0
	blt _0804F7C8
	adds r4, #1
	movs r0, #0xa5
	lsls r0, r0, #2
	adds r5, r5, r0
	cmp r4, #1
	ble _0804F6D4
	ldr r1, _0804F7BC @ =0x00000554
	adds r4, r6, r1
	movs r0, #3
	movs r1, #0xa
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	str r0, [r4]
	cmp r0, #0
	blt _0804F7C8
	ldr r1, [r6, #0x28]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r5, #0xa5
	lsls r5, r5, #2
	adds r2, r6, r5
	movs r1, #0
	bl FUN_0804a40c
	ldr r0, [r4]
	movs r1, #3
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r7, #0xab
	lsls r7, r7, #3
	adds r4, r6, r7
	movs r0, #0x11
	movs r1, #0xa
	movs r2, #0xa
	movs r3, #2
	bl FUN_0804a084
	str r0, [r4]
	cmp r0, #0
	blt _0804F7C8
	ldr r1, [r6, #0x28]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #0xa5
	lsls r1, r1, #3
	adds r2, r6, r1
	movs r1, #1
	bl FUN_0804a40c
	ldr r0, [r4]
	movs r1, #4
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	ldr r2, _0804F7C0 @ =0x0000055C
	adds r4, r6, r2
	movs r0, #0
	movs r1, #0xe
	movs r2, #0x1e
	movs r3, #6
	bl FUN_0804a084
	str r0, [r4]
	cmp r0, #0
	blt _0804F7C8
	ldr r1, [r6, #0x28]
	bl FUN_0804a240
	ldr r0, [r4]
	movs r1, #7
	bl FUN_0804a2f8
	ldr r0, [r4]
	bl FUN_0804a1f0
	movs r0, #0
	movs r1, #0x18
	bl FUN_0804e9f4
	movs r0, #4
	str r0, [sp]
	ldr r0, _0804F7C4 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0
	b _0804F7CC
	.align 2, 0
_0804F7B0: .4byte 0x0000CB05
_0804F7B4: .4byte 0x0000B343
_0804F7B8: .4byte 0x00000664
_0804F7BC: .4byte 0x00000554
_0804F7C0: .4byte 0x0000055C
_0804F7C4: .4byte 0x0000FFFF
_0804F7C8:
	movs r0, #1
	rsbs r0, r0, #0
_0804F7CC:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start CrossoverLobby_Create
CrossoverLobby_Create: @ 0x0804F7D4
	push {r4, lr}
	ldr r1, _0804F800 @ =0x00000684
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0804F80C
	ldr r1, _0804F804 @ =CrossoverLobby_Update
	ldr r2, _0804F808 @ =CrossoverLobby_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl CrossoverLobby_Init
	cmp r0, #0
	bge _0804F80C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0804F80E
	.align 2, 0
_0804F800: .4byte 0x00000684
_0804F804: .4byte CrossoverLobby_Update
_0804F808: .4byte CrossoverLobby_Destroy
_0804F80C:
	adds r0, r4, #0
_0804F80E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0804f814
FUN_0804f814: @ 0x0804F814
	lsls r0, r0, #4
	ldr r1, _0804F81C @ =0x030000F8
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0804F81C: .4byte 0x030000F8

