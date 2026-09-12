	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0808a33c
FUN_0808a33c: @ 0x0808A33C
	movs r3, #0x9f
	lsls r3, r3, #4
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _0808A350 @ =0x000009EC
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_0808A350: .4byte 0x000009EC

	thumb_func_start FUN_0808a354
FUN_0808a354: @ 0x0808A354
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _0808A388 @ =0x000009F4
	adds r0, r3, r4
	str r1, [r0]
	ldr r0, _0808A38C @ =0x000009EE
	adds r1, r3, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0808A390 @ =0x000009F8
	adds r0, r3, r1
	strb r2, [r0]
	lsls r2, r2, #0x18
	cmp r2, #0
	beq _0808A39C
	ldr r4, _0808A394 @ =0x00000FCC
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0808A398 @ =0x0000102C
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	b _0808A3B2
	.align 2, 0
_0808A388: .4byte 0x000009F4
_0808A38C: .4byte 0x000009EE
_0808A390: .4byte 0x000009F8
_0808A394: .4byte 0x00000FCC
_0808A398: .4byte 0x0000102C
_0808A39C:
	ldr r4, _0808A3BC @ =0x00000FCC
	adds r1, r3, r4
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, _0808A3C0 @ =0x0000102C
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
_0808A3B2:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808A3BC: .4byte 0x00000FCC
_0808A3C0: .4byte 0x0000102C

	thumb_func_start FUN_0808a3c4
FUN_0808a3c4: @ 0x0808A3C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r1, #0
	adds r1, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x24]
	movs r4, #0
	str r4, [sp, #0xc]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	adds r2, r5, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r1, _0808A418 @ =0x030043F0
	ldr r2, _0808A41C @ =0x04000018
	adds r0, r7, #0
	bl CpuSet
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808A418: .4byte 0x030043F0
_0808A41C: .4byte 0x04000018

	thumb_func_start FUN_0808a420
FUN_0808a420: @ 0x0808A420
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _0808A43C @ =0x03003ED0
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
_0808A43C: .4byte 0x03003ED0

	thumb_func_start FUN_0808a440
FUN_0808a440: @ 0x0808A440
	push {lr}
	adds r2, r0, #0
	movs r0, #0x11
	cmp r1, #0
	beq _0808A452
	movs r0, #0x31
	cmp r1, #1
	bne _0808A452
	movs r0, #0x91
_0808A452:
	adds r0, r2, r0
	pop {r1}
	bx r1

	thumb_func_start FUN_0808a458
FUN_0808a458: @ 0x0808A458
	push {r4, lr}
	ldr r2, _0808A480 @ =0x03004494
	strh r1, [r2]
	ldr r3, _0808A484 @ =0x03004454
	ldr r4, _0808A488 @ =0x0000FFFF
	adds r2, r4, #0
	strh r2, [r3]
	ldr r2, _0808A48C @ =0x03004040
	str r0, [r2]
	ldr r2, _0808A490 @ =0x03004464
	strh r1, [r2]
	ldr r2, _0808A494 @ =0x03004490
	movs r1, #0
	strh r1, [r2]
	ldr r1, _0808A498 @ =0x0300445C
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808A480: .4byte 0x03004494
_0808A484: .4byte 0x03004454
_0808A488: .4byte 0x0000FFFF
_0808A48C: .4byte 0x03004040
_0808A490: .4byte 0x03004464
_0808A494: .4byte 0x03004490
_0808A498: .4byte 0x0300445C

	thumb_func_start min
min: @ 0x0808A49C
	push {lr}
	adds r2, r0, #0
	adds r0, r1, #0
	cmp r2, r0
	bgt _0808A4A8
	adds r0, r2, #0
_0808A4A8:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808a4ac
FUN_0808a4ac: @ 0x0808A4AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r1
	adds r4, r2, #0
	adds r6, r3, #0
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp]
	movs r5, #0x64
	muls r0, r5, r0
	subs r7, r4, r0
	adds r0, r7, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r7, r1
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0x64
	bl Div
	add r4, sp, #0xc
	str r0, [sp, #0xc]
	muls r0, r5, r0
	subs r7, r6, r0
	adds r0, r7, #0
	movs r1, #0xa
	bl Div
	str r0, [r4, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r7, r1
	str r1, [r4, #8]
	mov r0, r8
	cmp r0, #0
	bne _0808A522
	movs r6, #0
	movs r1, #0x1c
	mov r8, r1
	mov sb, r6
	movs r0, #3
	mov sl, r0
	movs r7, #0xd0
	lsls r7, r7, #8
	movs r0, #0
	ldr r1, [sp, #0x3c]
	b _0808A538
_0808A522:
	movs r6, #1
	movs r1, #0x9b
	mov r8, r1
	mov sb, r6
	movs r0, #4
	mov sl, r0
	movs r7, #0xf0
	lsls r7, r7, #8
	ldr r1, [sp, #0x3c]
	subs r1, #1
	movs r0, #0
_0808A538:
	ldr r2, [sp, #0x40]
	bl FUN_0808a420
	adds r5, r0, #0
	adds r0, r7, #0
	orrs r0, r6
	strh r0, [r5]
	adds r5, #2
	str r0, [sp, #0x18]
	adds r4, r7, #0
	mov r1, r8
	orrs r4, r1
	mov r8, sp
	movs r6, #2
_0808A554:
	mov r1, r8
	adds r1, #4
	mov r8, r1
	subs r1, #4
	ldm r1!, {r0}
	mov r1, sb
	bl FUN_0808a440
	orrs r0, r7
	strh r0, [r5]
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bge _0808A554
	strh r4, [r5]
	adds r5, #2
	add r4, sp, #0xc
	movs r6, #2
_0808A578:
	ldm r4!, {r0}
	mov r1, sb
	bl FUN_0808a440
	orrs r0, r7
	strh r0, [r5]
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bge _0808A578
	mov r0, sl
	cmp r0, #0
	beq _0808A5A0
	ldr r0, [sp, #0x18]
	mov r6, sl
_0808A596:
	strh r0, [r5]
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bne _0808A596
_0808A5A0:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808a5b0
FUN_0808a5b0: @ 0x0808A5B0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r2, #0
	adds r5, r3, #0
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r2, r0, r3
	ldr r3, [r2]
	movs r6, #0xd9
	lsls r6, r6, #2
	adds r2, r3, r6
	ldrh r2, [r2]
	adds r6, #2
	adds r3, r3, r6
	ldrh r3, [r3]
	str r4, [sp]
	str r5, [sp, #4]
	bl FUN_0808a4ac
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808a5e0
FUN_0808a5e0: @ 0x0808A5E0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r2, #0
	adds r5, r3, #0
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r2, r0, r3
	ldr r3, [r2]
	movs r6, #0xda
	lsls r6, r6, #2
	adds r2, r3, r6
	ldrh r2, [r2]
	adds r6, #2
	adds r3, r3, r6
	ldrh r3, [r3]
	str r4, [sp]
	str r5, [sp, #4]
	bl FUN_0808a4ac
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808a610
FUN_0808a610: @ 0x0808A610
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	mov sb, r2
	mov sl, r3
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r5, _0808A648 @ =0x00000366
	adds r0, r0, r5
	ldrh r2, [r0]
	cmp r1, #0
	bne _0808A64C
	movs r1, #0
	movs r5, #0
	mov r8, r5
	b _0808A666
	.align 2, 0
_0808A648: .4byte 0x00000366
_0808A64C:
	subs r1, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r2, #1
	bl Div
	adds r1, r0, #1
	asrs r5, r1, #3
	lsls r0, r5, #3
	subs r0, r1, r0
	mov r8, r0
_0808A666:
	cmp r6, #0
	bne _0808A6B4
	movs r7, #0x43
	movs r0, #0x4b
	str r0, [sp]
	movs r6, #0x4c
	cmp r1, #0x27
	ble _0808A67C
	movs r4, #0xf8
	lsls r4, r4, #2
	b _0808A6A2
_0808A67C:
	cmp r1, #0x13
	ble _0808A688
	ldr r4, _0808A684 @ =0x0000029F
	b _0808A6A2
	.align 2, 0
_0808A684: .4byte 0x0000029F
_0808A688:
	movs r1, #0xa0
	lsls r1, r1, #4
	adds r3, r4, r1
	ldrh r2, [r3]
	lsrs r0, r2, #2
	movs r1, #1
	ands r0, r1
	movs r4, #0x12
	cmp r0, #0
	beq _0808A69E
	ldr r4, _0808A6B0 @ =0x0000109F
_0808A69E:
	adds r0, r2, #1
	strh r0, [r3]
_0808A6A2:
	movs r0, #0
	mov r1, sb
	mov r2, sl
	bl FUN_0808a420
	adds r3, r0, #0
	b _0808A6E2
	.align 2, 0
_0808A6B0: .4byte 0x0000109F
_0808A6B4:
	movs r7, #0x63
	movs r2, #0x6b
	str r2, [sp]
	ldr r6, _0808A750 @ =0x000004BD
	movs r4, #0xf8
	lsls r4, r4, #2
	cmp r1, #0x27
	bgt _0808A6CC
	ldr r4, _0808A754 @ =0x0000109F
	cmp r1, #0x13
	ble _0808A6CC
	ldr r4, _0808A758 @ =0x0000029F
_0808A6CC:
	mov r1, sb
	subs r1, #1
	movs r0, #0
	mov r2, sl
	bl FUN_0808a420
	adds r3, r0, #0
	ldr r2, _0808A75C @ =0x0000D0BD
	adds r1, r2, #0
	strh r1, [r3]
	adds r3, #2
_0808A6E2:
	ldr r2, _0808A760 @ =0x03004406
	ldrh r1, [r2]
	cmp r1, r4
	beq _0808A6EC
	strh r4, [r2]
_0808A6EC:
	movs r4, #0
	cmp r4, r5
	bge _0808A708
	ldr r2, _0808A764 @ =0xFFFFD000
	adds r1, r2, #0
	adds r2, r7, #0
	orrs r2, r1
	adds r4, r5, #0
_0808A6FC:
	strh r2, [r3]
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bne _0808A6FC
	adds r4, r5, #0
_0808A708:
	mov r5, r8
	cmp r5, #0
	beq _0808A720
	mov r1, r8
	subs r1, #8
	subs r1, r7, r1
	ldr r5, _0808A764 @ =0xFFFFD000
	adds r2, r5, #0
	orrs r1, r2
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
_0808A720:
	cmp r4, #9
	bgt _0808A736
	ldr r2, _0808A764 @ =0xFFFFD000
	adds r1, r2, #0
	ldr r5, [sp]
	orrs r1, r5
_0808A72C:
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
	cmp r4, #9
	ble _0808A72C
_0808A736:
	ldr r2, _0808A764 @ =0xFFFFD000
	adds r1, r2, #0
	orrs r6, r1
	strh r6, [r3]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808A750: .4byte 0x000004BD
_0808A754: .4byte 0x0000109F
_0808A758: .4byte 0x0000029F
_0808A75C: .4byte 0x0000D0BD
_0808A760: .4byte 0x03004406
_0808A764: .4byte 0xFFFFD000

	thumb_func_start FUN_0808a768
FUN_0808a768: @ 0x0808A768
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	str r1, [sp, #0x10]
	mov sl, r2
	str r3, [sp, #0x14]
	movs r0, #0x9e
	lsls r0, r0, #4
	add r0, r8
	ldr r0, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r3, _0808A79C @ =0x0000036A
	adds r0, r0, r3
	ldrh r2, [r0]
	cmp r1, #0
	bne _0808A7A0
	movs r5, #0
	mov sb, r5
	b _0808A7BA
	.align 2, 0
_0808A79C: .4byte 0x0000036A
_0808A7A0:
	subs r1, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r2, #1
	bl Div
	adds r0, #1
	asrs r5, r0, #3
	lsls r1, r5, #3
	subs r0, r0, r1
	mov sb, r0
_0808A7BA:
	movs r0, #0x9e
	lsls r0, r0, #4
	add r0, r8
	ldr r2, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	movs r4, #0x1f
	cmp r0, #5
	beq _0808A7D2
	ldr r4, _0808A810 @ =0x0000035F
_0808A7D2:
	ldr r3, [sp, #0x10]
	cmp r3, #0
	bne _0808A81C
	movs r7, #0x53
	movs r0, #0x4b
	str r0, [sp, #0x18]
	movs r6, #0x4c
	movs r1, #0x60
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0808A802
	ldr r0, _0808A814 @ =0x00000A02
	add r0, r8
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x12
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0808A802
	ldr r4, _0808A818 @ =0x00007FFF
_0808A802:
	movs r0, #0
	mov r1, sl
	ldr r2, [sp, #0x14]
	bl FUN_0808a420
	adds r3, r0, #0
	b _0808A83A
	.align 2, 0
_0808A810: .4byte 0x0000035F
_0808A814: .4byte 0x00000A02
_0808A818: .4byte 0x00007FFF
_0808A81C:
	movs r7, #0x73
	movs r1, #0x6b
	str r1, [sp, #0x18]
	ldr r6, _0808A940 @ =0x000004BD
	mov r1, sl
	subs r1, #1
	movs r0, #0
	ldr r2, [sp, #0x14]
	bl FUN_0808a420
	adds r3, r0, #0
	ldr r2, _0808A944 @ =0x0000D0BD
	adds r1, r2, #0
	strh r1, [r3]
	adds r3, #2
_0808A83A:
	ldr r2, _0808A948 @ =0x03004408
	ldrh r1, [r2]
	cmp r1, r4
	beq _0808A844
	strh r4, [r2]
_0808A844:
	movs r4, #0
	ldr r1, _0808A94C @ =0x030047A4
	mov sl, r1
	cmp r4, r5
	bge _0808A864
	ldr r2, _0808A950 @ =0xFFFFD000
	adds r1, r2, #0
	adds r2, r7, #0
	orrs r2, r1
	adds r4, r5, #0
_0808A858:
	strh r2, [r3]
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bne _0808A858
	adds r4, r5, #0
_0808A864:
	mov r5, sb
	cmp r5, #0
	beq _0808A87C
	mov r1, sb
	subs r1, #8
	subs r1, r7, r1
	ldr r5, _0808A950 @ =0xFFFFD000
	adds r2, r5, #0
	orrs r1, r2
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
_0808A87C:
	cmp r4, #9
	bgt _0808A892
	ldr r2, _0808A950 @ =0xFFFFD000
	adds r1, r2, #0
	ldr r5, [sp, #0x18]
	orrs r1, r5
_0808A888:
	strh r1, [r3]
	adds r3, #2
	adds r4, #1
	cmp r4, #9
	ble _0808A888
_0808A892:
	ldr r1, _0808A950 @ =0xFFFFD000
	adds r7, r1, #0
	orrs r6, r7
	strh r6, [r3]
	mov r2, sl
	ldr r1, [r2]
	movs r2, #0x80
	lsls r2, r2, #5
	ands r1, r2
	cmp r1, #0
	bne _0808A98C
	ldr r3, [sp, #0x10]
	cmp r3, #0
	bne _0808A98C
	movs r1, #0x9e
	lsls r1, r1, #4
	add r1, r8
	ldr r1, [r1]
	movs r2, #8
	movs r5, #0xde
	lsls r5, r5, #2
	adds r1, r1, r5
	ldr r1, [r1]
	ands r1, r2
	cmp r1, #0
	beq _0808A95C
	ldr r5, _0808A954 @ =0x030046A0
	ldr r0, [r5]
	movs r4, #0xef
	lsls r4, r4, #2
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
	movs r0, #0
	movs r1, #9
	movs r2, #3
	bl FUN_0808a420
	adds r4, r0, #0
	mov r6, sp
	movs r5, #3
_0808A922:
	ldm r6!, {r0}
	movs r1, #0
	bl FUN_0808a440
	adds r1, r0, #0
	orrs r1, r7
	strh r1, [r4]
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _0808A922
	ldr r2, _0808A958 @ =0x00000A2F
	add r2, r8
	movs r1, #1
	b _0808A98A
	.align 2, 0
_0808A940: .4byte 0x000004BD
_0808A944: .4byte 0x0000D0BD
_0808A948: .4byte 0x03004408
_0808A94C: .4byte 0x030047A4
_0808A950: .4byte 0xFFFFD000
_0808A954: .4byte 0x030046A0
_0808A958: .4byte 0x00000A2F
_0808A95C:
	ldr r1, _0808A99C @ =0x00000A2F
	add r1, r8
	ldrb r1, [r1]
	cmp r1, #0
	beq _0808A98C
	movs r0, #0
	movs r1, #9
	movs r2, #3
	bl FUN_0808a420
	adds r1, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #8
	adds r3, r2, #0
	movs r2, #3
_0808A97A:
	strh r3, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0808A97A
	ldr r2, _0808A99C @ =0x00000A2F
	add r2, r8
	movs r1, #0
_0808A98A:
	strb r1, [r2]
_0808A98C:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808A99C: .4byte 0x00000A2F

	thumb_func_start FUN_0808a9a0
FUN_0808a9a0: @ 0x0808A9A0
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808a9a4
FUN_0808a9a4: @ 0x0808A9A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r7, r1, #0
	mov r8, r2
	mov sb, r3
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _0808A9CC
	movs r6, #1
	b _0808AA4C
_0808A9CC:
	ldr r0, _0808AA04 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0xdd
	lsls r4, r4, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _0808AA08 @ =0x000009C3
	cmp r1, r0
	ble _0808AA0C
	adds r0, #0x59
	adds r4, r5, r0
	ldrh r2, [r4]
	lsrs r0, r2, #4
	movs r1, #1
	ands r0, r1
	movs r6, #1
	cmp r0, #0
	beq _0808A9F4
	movs r6, #0
_0808A9F4:
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #2
	bne _0808AA32
	movs r0, #0x99
	lsls r0, r0, #1
	b _0808AA2E
	.align 2, 0
_0808AA04: .4byte 0x030046A0
_0808AA08: .4byte 0x000009C3
_0808AA0C:
	cmp r1, #0
	ble _0808AA44
	ldr r1, _0808AA3C @ =0x00000A1C
	adds r4, r5, r1
	ldrh r2, [r4]
	lsrs r0, r2, #5
	movs r1, #1
	ands r0, r1
	movs r6, #1
	cmp r0, #0
	beq _0808AA24
	movs r6, #0
_0808AA24:
	movs r0, #0x3f
	ands r0, r2
	cmp r0, #2
	bne _0808AA32
	ldr r0, _0808AA40 @ =0x00000131
_0808AA2E:
	bl PlaySound_082406e0
_0808AA32:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0808AA4C
	.align 2, 0
_0808AA3C: .4byte 0x00000A1C
_0808AA40: .4byte 0x00000131
_0808AA44:
	movs r6, #0
	ldr r2, _0808AA74 @ =0x00000A1C
	adds r0, r5, r2
	strh r6, [r0]
_0808AA4C:
	movs r0, #0
	mov r1, r8
	mov r2, sb
	bl FUN_0808a420
	adds r3, r0, #0
	cmp r6, #0
	beq _0808AA80
	movs r2, #0
	ldr r1, _0808AA78 @ =0x030046A0
	ldr r0, _0808AA7C @ =0xFFFFD000
	adds r4, r0, #0
_0808AA64:
	adds r0, r2, #3
	orrs r0, r4
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #0xb
	ble _0808AA64
	b _0808AB32
	.align 2, 0
_0808AA74: .4byte 0x00000A1C
_0808AA78: .4byte 0x030046A0
_0808AA7C: .4byte 0xFFFFD000
_0808AA80:
	cmp r7, #1
	bne _0808AA8C
	ldr r2, _0808AA88 @ =0x0000029F
	b _0808AAE2
	.align 2, 0
_0808AA88: .4byte 0x0000029F
_0808AA8C:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x10
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _0808AAD8
	ldr r2, _0808AAD0 @ =0x00000A04
	adds r0, r5, r2
	ldrh r0, [r0]
	ldr r2, _0808AAD4 @ =0x0000029F
	cmp r0, #0x24
	bls _0808AAB6
	subs r2, #0xa4
	cmp r0, #0x2c
	bls _0808AAB6
	cmp r0, #0x34
	bhi _0808AAB6
	subs r2, #0x84
_0808AAB6:
	ldr r4, _0808AAD0 @ =0x00000A04
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0808AAE2
	movs r0, #0
	strh r0, [r1]
	b _0808AAE2
	.align 2, 0
_0808AAD0: .4byte 0x00000A04
_0808AAD4: .4byte 0x0000029F
_0808AAD8:
	ldr r0, _0808AB80 @ =0x00000A04
	adds r1, r5, r0
	movs r0, #0x34
	strh r0, [r1]
	ldr r2, _0808AB84 @ =0x00000177
_0808AAE2:
	ldr r1, _0808AB88 @ =0x03004404
	ldrh r0, [r1]
	cmp r0, r2
	beq _0808AAEC
	strh r2, [r1]
_0808AAEC:
	ldr r0, _0808AB8C @ =0x030046A0
	ldr r1, [r0]
	ldr r2, _0808AB90 @ =0x00000942
	adds r1, r1, r2
	movs r2, #0
	ldrsh r4, [r1, r2]
	ldr r2, _0808AB94 @ =0x0000D05C
	adds r1, r2, #0
	strh r1, [r3]
	adds r3, #2
	movs r2, #0
	adds r1, r0, #0
	cmp r2, r4
	bge _0808AB1A
	ldr r2, _0808AB98 @ =0x0000D05D
	adds r0, r2, #0
	adds r2, r4, #0
_0808AB0E:
	strh r0, [r3]
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bne _0808AB0E
	adds r2, r4, #0
_0808AB1A:
	cmp r2, #9
	bgt _0808AB2C
	ldr r4, _0808AB9C @ =0x0000D05E
	adds r0, r4, #0
_0808AB22:
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #9
	ble _0808AB22
_0808AB2C:
	ldr r2, _0808ABA0 @ =0x0000D05F
	adds r0, r2, #0
	strh r0, [r3]
_0808AB32:
	movs r4, #0x9e
	lsls r4, r4, #4
	adds r0, r5, r4
	ldr r0, [r0]
	ldr r2, _0808ABA4 @ =0x0000038E
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r4, #0xb2
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	ble _0808ABAC
	movs r0, #0
	movs r1, #0xf
	movs r2, #0x11
	bl FUN_0808a420
	adds r3, r0, #0
	movs r2, #0
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r1, r0, #0
_0808AB66:
	adds r0, r2, #0
	adds r0, #0x3b
	orrs r0, r1
	strh r0, [r3]
	adds r3, #2
	adds r2, #1
	cmp r2, #4
	ble _0808AB66
	ldr r2, _0808ABA8 @ =0x00000A96
	adds r1, r5, r2
	movs r0, #1
	b _0808ABDA
	.align 2, 0
_0808AB80: .4byte 0x00000A04
_0808AB84: .4byte 0x00000177
_0808AB88: .4byte 0x03004404
_0808AB8C: .4byte 0x030046A0
_0808AB90: .4byte 0x00000942
_0808AB94: .4byte 0x0000D05C
_0808AB98: .4byte 0x0000D05D
_0808AB9C: .4byte 0x0000D05E
_0808ABA0: .4byte 0x0000D05F
_0808ABA4: .4byte 0x0000038E
_0808ABA8: .4byte 0x00000A96
_0808ABAC:
	ldr r4, _0808ABE8 @ =0x00000A96
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808ABDC
	movs r0, #0
	movs r1, #0xf
	movs r2, #0x11
	bl FUN_0808a420
	adds r3, r0, #0
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r1, #0
	movs r2, #4
_0808ABCA:
	strh r0, [r3]
	adds r3, #2
	subs r2, #1
	cmp r2, #0
	bge _0808ABCA
	ldr r2, _0808ABE8 @ =0x00000A96
	adds r1, r5, r2
	movs r0, #0
_0808ABDA:
	strb r0, [r1]
_0808ABDC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808ABE8: .4byte 0x00000A96

	thumb_func_start FUN_0808abec
FUN_0808abec: @ 0x0808ABEC
	push {r4, r5, lr}
	adds r3, r0, #0
	cmp r1, #1
	bne _0808AC58
	movs r4, #0x1f
	ldr r1, _0808AC30 @ =0x00000A1E
	adds r0, r3, r1
	movs r5, #0
	ldrsh r2, [r0, r5]
	ldr r1, _0808AC34 @ =0x030046A0
	ldr r0, [r1]
	movs r5, #0xae
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	adds r5, r1, #0
	cmp r2, r0
	bge _0808AC3C
	movs r1, #0xa2
	lsls r1, r1, #4
	adds r0, r3, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x12
	movs r0, #1
	ands r1, r0
	ldr r2, _0808AC38 @ =0x00007FFF
	cmp r1, #0
	beq _0808AC7C
_0808AC2A:
	movs r2, #0xf8
	lsls r2, r2, #2
	b _0808AC7C
	.align 2, 0
_0808AC30: .4byte 0x00000A1E
_0808AC34: .4byte 0x030046A0
_0808AC38: .4byte 0x00007FFF
_0808AC3C:
	ldr r0, _0808AC50 @ =0x00000A22
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808AC2A
	ldr r2, _0808AC54 @ =0x00007FFF
	subs r0, #1
	strh r0, [r1]
	b _0808AC7C
	.align 2, 0
_0808AC50: .4byte 0x00000A22
_0808AC54: .4byte 0x00007FFF
_0808AC58:
	ldr r4, _0808AC6C @ =0x000039CE
	ldr r5, _0808AC70 @ =0x00000A22
	adds r1, r3, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808AC78
	ldr r2, _0808AC74 @ =0x00007FFF
	subs r0, #1
	strh r0, [r1]
	b _0808AC7A
	.align 2, 0
_0808AC6C: .4byte 0x000039CE
_0808AC70: .4byte 0x00000A22
_0808AC74: .4byte 0x00007FFF
_0808AC78:
	movs r2, #0x1f
_0808AC7A:
	ldr r5, _0808ACAC @ =0x030046A0
_0808AC7C:
	ldr r1, _0808ACB0 @ =0x0300440C
	ldrh r0, [r1]
	cmp r0, r4
	beq _0808AC86
	strh r4, [r1]
_0808AC86:
	subs r1, #2
	ldrh r0, [r1]
	cmp r0, r2
	beq _0808AC90
	strh r2, [r1]
_0808AC90:
	ldr r4, [r5]
	movs r0, #0xae
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r1, [r2]
	ldr r5, _0808ACB4 @ =0x00000A1E
	adds r0, r3, r5
	strh r1, [r0]
	ldr r3, [r2]
	cmp r3, #0
	bgt _0808ACB8
	movs r5, #0
	b _0808ACDC
	.align 2, 0
_0808ACAC: .4byte 0x030046A0
_0808ACB0: .4byte 0x0300440C
_0808ACB4: .4byte 0x00000A1E
_0808ACB8:
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #1
	ble _0808ACDA
	movs r1, #0x4f
	subs r0, r3, #1
	muls r0, r1, r0
	subs r1, r2, #1
	bl Div
	adds r4, r0, #1
	asrs r5, r4, #3
	lsls r0, r5, #3
	subs r4, r4, r0
	b _0808ACDE
_0808ACDA:
	movs r5, #0xa
_0808ACDC:
	movs r4, #0
_0808ACDE:
	movs r0, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_0808a420
	adds r2, r0, #0
	ldr r1, _0808AD4C @ =0x0000D08C
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	subs r1, #1
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	subs r1, #1
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	movs r3, #0
	cmp r3, r5
	bge _0808AD1A
	subs r1, #1
	adds r0, r1, #0
	adds r3, r5, #0
_0808AD0E:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bne _0808AD0E
	adds r3, r5, #0
_0808AD1A:
	cmp r4, #0
	beq _0808AD2E
	adds r0, r4, #0
	adds r0, #0x81
	ldr r4, _0808AD50 @ =0xFFFFD000
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
_0808AD2E:
	cmp r3, #9
	bgt _0808AD40
	ldr r5, _0808AD54 @ =0x0000D081
	adds r0, r5, #0
_0808AD36:
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
	cmp r3, #9
	ble _0808AD36
_0808AD40:
	ldr r1, _0808AD58 @ =0x0000D080
	adds r0, r1, #0
	strh r0, [r2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808AD4C: .4byte 0x0000D08C
_0808AD50: .4byte 0xFFFFD000
_0808AD54: .4byte 0x0000D081
_0808AD58: .4byte 0x0000D080

	thumb_func_start FUN_0808ad5c
FUN_0808ad5c: @ 0x0808AD5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r2, #0
	movs r7, #0
	movs r5, #0
	mov sb, r5
	mov r8, r5
	mov sl, r5
	movs r6, #0
	ldr r1, _0808AD98 @ =0x00000A0A
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808AE24
	ldr r2, _0808AD9C @ =0x000039CE
	mov sl, r2
	ldr r0, _0808ADA0 @ =0x00000A0D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808ADA8
	ldr r2, _0808ADA4 @ =0x00007FFF
	mov r8, r2
	subs r0, #1
	strb r0, [r1]
	b _0808ADAC
	.align 2, 0
_0808AD98: .4byte 0x00000A0A
_0808AD9C: .4byte 0x000039CE
_0808ADA0: .4byte 0x00000A0D
_0808ADA4: .4byte 0x00007FFF
_0808ADA8:
	movs r0, #0x1f
	mov r8, r0
_0808ADAC:
	ldr r1, _0808ADC8 @ =0x00000A0C
	adds r0, r4, r1
	ldrb r0, [r0]
	mov sb, r0
	lsls r5, r0, #3
	ldr r0, _0808ADCC @ =0x00000A06
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _0808ADD0
	movs r7, #0
	movs r5, #0
	b _0808ADEC
	.align 2, 0
_0808ADC8: .4byte 0x00000A0C
_0808ADCC: .4byte 0x00000A06
_0808ADD0:
	subs r1, r5, #1
	ldrh r0, [r2]
	subs r0, #1
	muls r0, r1, r0
	ldr r2, _0808AE14 @ =0x00000A08
	adds r1, r4, r2
	ldrh r1, [r1]
	subs r1, #1
	bl Div
	adds r5, r0, #1
	asrs r7, r5, #3
	lsls r0, r7, #3
	subs r5, r5, r0
_0808ADEC:
	movs r6, #0x8c
	ldr r0, _0808AE18 @ =0x00000A0A
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	ldr r2, _0808AE1C @ =0x00000A15
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	movs r2, #1
	ldr r0, _0808AE20 @ =0x00000A12
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808AEA8
	subs r0, #1
	strh r0, [r1]
	b _0808AEA8
	.align 2, 0
_0808AE14: .4byte 0x00000A08
_0808AE18: .4byte 0x00000A0A
_0808AE1C: .4byte 0x00000A15
_0808AE20: .4byte 0x00000A12
_0808AE24:
	ldr r1, _0808AE48 @ =0x00000A12
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808AEA8
	movs r2, #0x1f
	mov sl, r2
	ldr r0, _0808AE4C @ =0x00000A14
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808AE54
	ldr r2, _0808AE50 @ =0x00007FFF
	mov r8, r2
	subs r0, #1
	strb r0, [r1]
	b _0808AE5A
	.align 2, 0
_0808AE48: .4byte 0x00000A12
_0808AE4C: .4byte 0x00000A14
_0808AE50: .4byte 0x00007FFF
_0808AE54:
	movs r0, #0xf8
	lsls r0, r0, #2
	mov r8, r0
_0808AE5A:
	movs r1, #0xa
	mov sb, r1
	ldr r0, _0808AE70 @ =0x00000A0E
	adds r2, r4, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _0808AE74
	movs r7, #0
	movs r5, #0
	b _0808AE92
	.align 2, 0
_0808AE70: .4byte 0x00000A0E
_0808AE74:
	movs r1, #0x4f
	ldrh r0, [r2]
	subs r0, #1
	muls r0, r1, r0
	movs r2, #0xa1
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r1, [r1]
	subs r1, #1
	bl Div
	adds r5, r0, #1
	asrs r7, r5, #3
	lsls r0, r7, #3
	subs r5, r5, r0
_0808AE92:
	movs r6, #0x42
	ldr r0, _0808AF4C @ =0x00000A15
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0808AF50 @ =0x00000A12
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r2, #1
_0808AEA8:
	cmp r2, #0
	beq _0808AF68
	ldr r1, _0808AF54 @ =0x0300440C
	ldrh r0, [r1]
	cmp r0, sl
	beq _0808AEB8
	mov r4, sl
	strh r4, [r1]
_0808AEB8:
	subs r1, #2
	ldrh r0, [r1]
	cmp r0, r8
	beq _0808AEC4
	mov r0, r8
	strh r0, [r1]
_0808AEC4:
	movs r0, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_0808a420
	adds r2, r0, #0
	ldr r4, _0808AF58 @ =0xFFFFD000
	adds r1, r4, #0
	movs r3, #2
_0808AED6:
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r2]
	subs r2, #2
	subs r6, #1
	subs r3, #1
	cmp r3, #0
	bge _0808AED6
	movs r3, #0
	cmp r3, r7
	bge _0808AEFE
	ldr r1, _0808AF5C @ =0x0000D089
	adds r0, r1, #0
	adds r3, r7, #0
_0808AEF2:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bne _0808AEF2
	adds r3, r7, #0
_0808AEFE:
	cmp r5, #0
	beq _0808AF12
	adds r0, r5, #0
	adds r0, #0x81
	ldr r4, _0808AF58 @ =0xFFFFD000
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
_0808AF12:
	cmp r3, sb
	bge _0808AF2A
	ldr r1, _0808AF60 @ =0x0000D081
	adds r0, r1, #0
	mov r4, sb
	subs r3, r4, r3
_0808AF1E:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bne _0808AF1E
	mov r3, sb
_0808AF2A:
	ldr r1, _0808AF64 @ =0x0000D080
	adds r0, r1, #0
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
	cmp r3, #0xa
	bgt _0808AF98
	movs r4, #0xd0
	lsls r4, r4, #8
	adds r0, r4, #0
_0808AF3E:
	strh r0, [r2]
	subs r2, #2
	adds r3, #1
	cmp r3, #0xa
	ble _0808AF3E
	b _0808AF98
	.align 2, 0
_0808AF4C: .4byte 0x00000A15
_0808AF50: .4byte 0x00000A12
_0808AF54: .4byte 0x0300440C
_0808AF58: .4byte 0xFFFFD000
_0808AF5C: .4byte 0x0000D089
_0808AF60: .4byte 0x0000D081
_0808AF64: .4byte 0x0000D080
_0808AF68:
	ldr r1, _0808AFA8 @ =0x00000A15
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808AF98
	movs r0, #0
	movs r1, #0x1d
	movs r2, #1
	bl FUN_0808a420
	adds r2, r0, #0
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r1, #0
	movs r3, #0xd
_0808AF86:
	strh r0, [r2]
	subs r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0808AF86
	ldr r2, _0808AFA8 @ =0x00000A15
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0808AF98:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808AFA8: .4byte 0x00000A15

	thumb_func_start FUN_0808afac
FUN_0808afac: @ 0x0808AFAC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r4, r7, r0
	ldr r0, [r4]
	ldr r1, _0808B038 @ =0x00000446
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808B04C
	ldr r3, _0808B03C @ =0x00000A3C
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808B040 @ =0x00000A34
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	ldr r2, [r4]
	ldr r3, _0808B044 @ =0x00000444
	adds r2, r2, r3
	ldrh r2, [r2]
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
	movs r0, #0
	movs r1, #1
	movs r2, #5
	bl FUN_0808a420
	adds r6, r0, #0
	ldr r0, [r4]
	ldr r1, _0808B038 @ =0x00000446
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, #0x3b
	movs r1, #0x3c
	bl Div
	adds r4, r0, #0
	movs r1, #0xa
	bl Div
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	movs r1, #0
	bl FUN_0808a440
	ldr r2, _0808B048 @ =0xFFFFD000
	adds r5, r2, #0
	orrs r0, r5
	strh r0, [r6]
	adds r6, #2
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808a440
	orrs r0, r5
	strh r0, [r6]
	b _0808B0C4
	.align 2, 0
_0808B038: .4byte 0x00000446
_0808B03C: .4byte 0x00000A3C
_0808B040: .4byte 0x00000A34
_0808B044: .4byte 0x00000444
_0808B048: .4byte 0xFFFFD000
_0808B04C:
	ldr r0, _0808B078 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _0808B084
	ldr r0, _0808B07C @ =0x00000A3C
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808B080 @ =0x00000A34
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	movs r2, #0x83
	b _0808B0A8
	.align 2, 0
_0808B078: .4byte 0x030046A0
_0808B07C: .4byte 0x00000A3C
_0808B080: .4byte 0x00000A34
_0808B084:
	ldr r2, _0808B0D0 @ =0x000002B2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r5, [r0, r3]
	cmp r5, #0
	beq _0808B0E0
	ldr r0, _0808B0D4 @ =0x00000A3C
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808B0D8 @ =0x00000A34
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	movs r2, #0x84
_0808B0A8:
	movs r3, #1
	bl Sprite_SetSprite
	movs r0, #0
	movs r1, #1
	movs r2, #5
	bl FUN_0808a420
	adds r6, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	strh r0, [r6, #2]
_0808B0C4:
	ldr r3, _0808B0DC @ =0x00000A94
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _0808B10C
	.align 2, 0
_0808B0D0: .4byte 0x000002B2
_0808B0D4: .4byte 0x00000A3C
_0808B0D8: .4byte 0x00000A34
_0808B0DC: .4byte 0x00000A94
_0808B0E0:
	ldr r0, _0808B114 @ =0x00000A94
	adds r4, r7, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808B10C
	ldr r1, _0808B118 @ =0x00000A3C
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	movs r2, #5
	bl FUN_0808a420
	adds r6, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r6]
	strh r0, [r6, #2]
	strb r5, [r4]
_0808B10C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B114: .4byte 0x00000A94
_0808B118: .4byte 0x00000A3C

	thumb_func_start FUN_0808b11c
FUN_0808b11c: @ 0x0808B11C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldr r0, _0808B150 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0808B158
	cmp r6, #0
	bne _0808B1A2
	subs r0, r5, #1
	cmp r0, #2
	bhi _0808B1A2
	ldr r1, _0808B154 @ =0x00000A9B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r5, r0
	beq _0808B1A2
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0808B1A2
	.align 2, 0
_0808B150: .4byte 0x030047A4
_0808B154: .4byte 0x00000A9B
_0808B158:
	ldr r0, _0808B17C @ =0x00000A98
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0808B184
	ldr r1, _0808B180 @ =0x00000A99
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808B174
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0808B174:
	movs r0, #1
	strb r0, [r7]
	b _0808B1A2
	.align 2, 0
_0808B17C: .4byte 0x00000A98
_0808B180: .4byte 0x00000A99
_0808B184:
	cmp r6, #0
	beq _0808B190
	cmp r6, #1
	bne _0808B1A2
	cmp r5, #0
	bne _0808B1A2
_0808B190:
	ldr r1, _0808B1B4 @ =0x00000A9B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r5, r0
	beq _0808B1A2
	movs r0, #0x87
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0808B1A2:
	ldr r1, _0808B1B8 @ =0x00000A9A
	adds r0, r4, r1
	strb r6, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r5, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B1B4: .4byte 0x00000A9B
_0808B1B8: .4byte 0x00000A9A

	thumb_func_start FUN_0808b1bc
FUN_0808b1bc: @ 0x0808B1BC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r1, _0808B1FC @ =0x00000A97
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808B1CC
	b _0808B2F2
_0808B1CC:
	subs r1, #0xb7
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808B1E2
	movs r1, #4
	ldr r0, _0808B200 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0808B208
_0808B1E2:
	movs r3, #1
	ldr r0, _0808B204 @ =0x00000AA8
	adds r1, r5, r0
	movs r2, #1
_0808B1EA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B1EA
	ldr r0, _0808B1FC @ =0x00000A97
	b _0808B22E
	.align 2, 0
_0808B1FC: .4byte 0x00000A97
_0808B200: .4byte 0x03002BC0
_0808B204: .4byte 0x00000AA8
_0808B208:
	ldr r1, _0808B238 @ =0x00000A9C
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r4, [r0]
	ldr r0, _0808B23C @ =0x00001734
	cmp r4, r0
	ble _0808B248
	movs r3, #1
	ldr r0, _0808B240 @ =0x00000AA8
	adds r1, r5, r0
	movs r2, #1
_0808B21E:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B21E
	ldr r0, _0808B244 @ =0x00000A98
_0808B22E:
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _0808B2F2
	.align 2, 0
_0808B238: .4byte 0x00000A9C
_0808B23C: .4byte 0x00001734
_0808B240: .4byte 0x00000AA8
_0808B244: .4byte 0x00000A98
_0808B248:
	adds r7, r5, #0
	adds r7, #0x60
	movs r3, #2
	rsbs r3, r3, #0
	ldr r0, _0808B288 @ =0x00000AA8
	adds r1, r5, r0
	movs r2, #1
_0808B256:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B256
	cmp r4, #0
	ble _0808B28C
	subs r0, r4, #1
	movs r1, #0x3c
	bl Div
	adds r4, r0, #1
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r6, r0, #0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #1
	subs r4, r4, r0
	b _0808B290
	.align 2, 0
_0808B288: .4byte 0x00000AA8
_0808B28C:
	movs r6, #0
	movs r4, #0
_0808B290:
	cmp r6, #0
	bne _0808B2BC
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r1, r7, #0
	movs r2, #0x7d
	movs r3, #1
	bl Sprite_SetSprite
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r2, r4, #0
	adds r2, #0x7d
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r7, #0
	movs r3, #1
	bl Sprite_SetSprite
	b _0808B2E8
_0808B2BC:
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r2, r6, #0
	adds r2, #0x73
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r7, #0
	movs r3, #1
	bl Sprite_SetSprite
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r5, r1
	adds r2, r4, #0
	adds r2, #0x73
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r7, #0
	movs r3, #1
	bl Sprite_SetSprite
_0808B2E8:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_0808b11c
_0808B2F2:
	ldr r0, _0808B308 @ =0x00000A99
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808B300
	subs r0, #1
	strb r0, [r1]
_0808B300:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B308: .4byte 0x00000A99

	thumb_func_start FUN_0808b30c
FUN_0808b30c: @ 0x0808B30C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r1, r2, #0
	adds r2, r3, #0
	ldr r0, [sp, #0x14]
	movs r7, #0x31
	cmp r0, #0
	bne _0808B320
	movs r7, #0x91
_0808B320:
	movs r0, #0
	bl FUN_0808a420
	adds r6, r0, #0
	cmp r4, #0
	ble _0808B358
_0808B32C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl Div
	adds r1, r0, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r2, r3, #0
	orrs r1, r2
	strh r1, [r6]
	adds r6, #2
	muls r0, r4, r0
	subs r5, r5, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
	cmp r4, #0
	bgt _0808B32C
_0808B358:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808b360
FUN_0808b360: @ 0x0808B360
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	bl FUN_0808a420
	adds r1, r0, #0
	cmp r4, #0
	ble _0808B380
	ldr r0, _0808B388 @ =0x0000F090
	adds r2, r0, #0
	adds r0, r4, #0
_0808B376:
	strh r2, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bne _0808B376
_0808B380:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B388: .4byte 0x0000F090

	thumb_func_start FUN_0808b38c
FUN_0808b38c: @ 0x0808B38C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, _0808B3EC @ =0x00003AE6
	adds r4, r4, r0
	ldrb r4, [r4]
	cmp r4, #0
	bne _0808B3FC
	ldr r2, _0808B3F0 @ =0x0000F023
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x77
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x9a
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B3F4 @ =0x030046A0
	ldr r0, [r5]
	movs r3, #0x91
	lsls r3, r3, #4
	adds r2, r0, r3
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r1, _0808B3F8 @ =0x0000270F
	cmp r0, r1
	ble _0808B3E2
	strh r1, [r2]
_0808B3E2:
	ldr r0, [r5]
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	b _0808B43E
	.align 2, 0
_0808B3EC: .4byte 0x00003AE6
_0808B3F0: .4byte 0x0000F023
_0808B3F4: .4byte 0x030046A0
_0808B3F8: .4byte 0x0000270F
_0808B3FC:
	cmp r4, #1
	bne _0808B45C
	ldr r2, _0808B450 @ =0x0000F025
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #4
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x79
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x6b
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B454 @ =0x030046A0
	ldr r0, [r5]
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r1, r0, r3
	ldr r0, [r1]
	ldr r2, _0808B458 @ =0x0000270F
	cmp r0, r2
	ble _0808B438
	str r2, [r1]
_0808B438:
	ldr r0, [r5]
	adds r0, r0, r3
	ldr r0, [r0]
_0808B43E:
	movs r1, #0xfa
	lsls r1, r1, #2
	str r4, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_0808b30c
	b _0808B4AA
	.align 2, 0
_0808B450: .4byte 0x0000F025
_0808B454: .4byte 0x030046A0
_0808B458: .4byte 0x0000270F
_0808B45C:
	ldr r2, _0808B4B4 @ =0x0000F0B9
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	subs r2, #0x98
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #0x99
	adds r0, r2, #0
	strh r0, [r1]
	subs r2, #0x20
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r4, _0808B4B8 @ =0x030046A0
	ldr r0, [r4]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r1, r0, r3
	ldr r0, [r1]
	ldr r2, _0808B4BC @ =0x0000270F
	cmp r0, r2
	ble _0808B494
	str r2, [r1]
_0808B494:
	ldr r0, [r4]
	adds r0, r0, r3
	ldr r0, [r0]
	movs r1, #0xfa
	lsls r1, r1, #2
	movs r2, #0
	str r2, [sp]
	movs r2, #0x17
	movs r3, #1
	bl FUN_0808b30c
_0808B4AA:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B4B4: .4byte 0x0000F0B9
_0808B4B8: .4byte 0x030046A0
_0808B4BC: .4byte 0x0000270F

	thumb_func_start FUN_0808b4c0
FUN_0808b4c0: @ 0x0808B4C0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _0808B564 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _0808B4DC
	cmp r1, #6
	beq _0808B4DC
	b _0808B5F4
_0808B4DC:
	ldr r2, _0808B568 @ =0x000009F8
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808B524
	ldr r2, _0808B56C @ =0x030044E0
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0808B524
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808B524
	ldr r0, _0808B570 @ =0x00003AE6
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0808B512
	strb r2, [r1]
_0808B512:
	ldr r1, _0808B574 @ =0x00003AE7
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xdc
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0808b38c
_0808B524:
	movs r0, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r2, _0808B570 @ =0x00003AE6
	adds r0, r4, r2
	ldrb r4, [r0]
	cmp r4, #0
	bne _0808B57C
	ldr r2, _0808B578 @ =0x0000F020
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	bl GetHour
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_0808b30c
	bl GetMinute
	b _0808B5A8
	.align 2, 0
_0808B564: .4byte 0x00000F56
_0808B568: .4byte 0x000009F8
_0808B56C: .4byte 0x030044E0
_0808B570: .4byte 0x00003AE6
_0808B574: .4byte 0x00003AE7
_0808B578: .4byte 0x0000F020
_0808B57C:
	cmp r4, #1
	bne _0808B5C0
	ldr r2, _0808B5B8 @ =0x0000F027
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B5BC @ =0x030047E0
	ldrb r0, [r5, #0xa]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_0808b30c
	ldrb r0, [r5, #0xb]
_0808B5A8:
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_0808b30c
	b _0808B5F4
	.align 2, 0
_0808B5B8: .4byte 0x0000F027
_0808B5BC: .4byte 0x030047E0
_0808B5C0:
	ldr r2, _0808B5FC @ =0x0000F027
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B600 @ =0x030047E0
	ldrb r0, [r5, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_0808b30c
	ldrb r0, [r5, #0xd]
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_0808b30c
_0808B5F4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B5FC: .4byte 0x0000F027
_0808B600: .4byte 0x030047E0

	thumb_func_start FUN_0808b604
FUN_0808b604: @ 0x0808B604
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r1, #1
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_0808a610
	adds r3, r6, #1
	adds r0, r5, #0
	movs r1, #1
	adds r2, r4, #0
	bl FUN_0808a768
	ldr r5, _0808B66C @ =0x030046A0
	ldr r0, [r5]
	adds r0, #0x58
	movs r1, #0
	ldrsh r0, [r0, r1]
	add r1, sp, #4
	bl FUN_08242b28
	add r0, sp, #4
	bl FUN_0807a6cc
	adds r4, #1
	adds r3, r6, #2
	movs r7, #0
	str r7, [sp]
	movs r1, #0x64
	adds r2, r4, #0
	bl FUN_0808b30c
	ldr r5, [r5]
	adds r1, r5, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _0808B670
	movs r0, #0
	bl FUN_0807a70c
	adds r3, r6, #3
	str r7, [sp]
	movs r1, #0x64
	adds r2, r4, #0
	bl FUN_0808b30c
	b _0808B698
	.align 2, 0
_0808B66C: .4byte 0x030046A0
_0808B670:
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	ldr r1, _0808B6A0 @ =0x08DAA7B0
	adds r0, r0, r1
	bl FUN_0807a70c
	adds r3, r6, #3
	str r7, [sp]
	movs r1, #0x64
	adds r2, r4, #0
	bl FUN_0808b30c
_0808B698:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B6A0: .4byte 0x08DAA7B0

	thumb_func_start FUN_0808b6a4
FUN_0808b6a4: @ 0x0808B6A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _0808B6C4 @ =0x030044E0
	ldrh r0, [r5, #2]
	movs r3, #0xf0
	adds r2, r3, #0
	ands r2, r0
	cmp r2, #0
	beq _0808B6CC
	ldr r1, _0808B6C8 @ =0x00003B24
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldrh r0, [r5, #2]
	b _0808B6F6
	.align 2, 0
_0808B6C4: .4byte 0x030044E0
_0808B6C8: .4byte 0x00003B24
_0808B6CC:
	ldrh r1, [r5]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _0808B6F4
	ldr r0, _0808B6F0 @ =0x00003B24
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0808B6F4
	strb r2, [r1]
	ldrh r0, [r5]
	b _0808B6F6
	.align 2, 0
_0808B6F0: .4byte 0x00003B24
_0808B6F4:
	movs r0, #0
_0808B6F6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808b6fc
FUN_0808b6fc: @ 0x0808B6FC
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0808B750 @ =0x0000150C
	adds r3, r5, r0
	ldr r0, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r3]
	ldr r2, _0808B754 @ =0x00001524
	adds r0, r5, r2
	movs r3, #0
	strh r3, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r3, [r0]
	ldr r2, _0808B758 @ =0x00003B25
	adds r0, r5, r2
	strb r1, [r0]
	lsls r1, r1, #0x18
	movs r2, #5
	cmp r1, #0
	beq _0808B72E
	movs r2, #4
_0808B72E:
	ldr r0, _0808B75C @ =0x00001504
	adds r4, r5, r0
	adds r5, #0x60
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082372cc
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B750: .4byte 0x0000150C
_0808B754: .4byte 0x00001524
_0808B758: .4byte 0x00003B25
_0808B75C: .4byte 0x00001504

	thumb_func_start FUN_0808b760
FUN_0808b760: @ 0x0808B760
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0808B788 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0808B794
	ldr r0, _0808B78C @ =0x0000150C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0808B790 @ =0x00003B25
	adds r0, r4, r1
	ldrb r0, [r0]
	b _0808B81C
	.align 2, 0
_0808B788: .4byte 0x030044E0
_0808B78C: .4byte 0x0000150C
_0808B790: .4byte 0x00003B25
_0808B794:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808B7B0
	ldr r3, _0808B7AC @ =0x0000150C
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0
	b _0808B81C
	.align 2, 0
_0808B7AC: .4byte 0x0000150C
_0808B7B0:
	movs r2, #0
	ldr r3, _0808B7CC @ =0x00003B25
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808B7D0
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	rsbs r0, r0, #0
	lsrs r2, r0, #0x1f
	b _0808B7DA
	.align 2, 0
_0808B7CC: .4byte 0x00003B25
_0808B7D0:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808B7DA
	movs r2, #1
_0808B7DA:
	adds r5, r4, #0
	adds r5, #0x60
	cmp r2, #0
	beq _0808B80E
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _0808B824 @ =0x00003B25
	adds r1, r4, r0
	ldrb r2, [r1]
	movs r0, #1
	subs r0, r0, r2
	movs r3, #0
	strb r0, [r1]
	ldr r2, _0808B828 @ =0x00001504
	adds r0, r4, r2
	ldrb r1, [r1]
	movs r2, #5
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
_0808B80E:
	ldr r3, _0808B828 @ =0x00001504
	adds r0, r4, r3
	adds r1, r5, #0
	bl FUN_082372cc
	movs r0, #1
	rsbs r0, r0, #0
_0808B81C:
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0808B824: .4byte 0x00003B25
_0808B828: .4byte 0x00001504

	thumb_func_start FUN_0808b82c
FUN_0808b82c: @ 0x0808B82C
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	ldr r0, _0808B864 @ =0x00000F6C
	adds r1, r3, r0
	movs r2, #0x73
_0808B838:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808B838
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r1, r3, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0808B868 @ =0x00000BB8
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B864: .4byte 0x00000F6C
_0808B868: .4byte 0x00000BB8

	thumb_func_start FUN_0808b86c
FUN_0808b86c: @ 0x0808B86C
	push {r4, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _0808B89C @ =0x00000F6C
	adds r4, r3, r0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, _0808B8A0 @ =0x00000F64
	adds r0, r3, r1
	adds r3, #0x60
	adds r2, #0x29
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r3, #0
	movs r3, #1
	bl Sprite_SetSprite
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808B89C: .4byte 0x00000F6C
_0808B8A0: .4byte 0x00000F64

	thumb_func_start FUN_0808b8a4
FUN_0808b8a4: @ 0x0808B8A4
	push {r4, r5, r6, lr}
	ldr r3, _0808B900 @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	movs r2, #0x90
	orrs r1, r2
	ldr r2, _0808B904 @ =0x0000FFFF
	ands r1, r2
	movs r2, #0x80
	lsls r2, r2, #0xe
	adds r4, r1, #0
	orrs r4, r2
	ands r5, r3
	movs r6, #0
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r3, r0, r1
_0808B8C6:
	ldr r0, _0808B908 @ =0x00000F84
	adds r2, r3, r0
	str r4, [r2]
	str r5, [r2, #4]
	movs r1, #3
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r0, _0808B90C @ =0x00000F86
	adds r2, r3, r0
	asrs r1, r6, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r3, #0x60
	adds r6, #1
	cmp r6, #0xf
	ble _0808B8C6
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808B900: .4byte 0xFFFF0000
_0808B904: .4byte 0x0000FFFF
_0808B908: .4byte 0x00000F84
_0808B90C: .4byte 0x00000F86

	thumb_func_start FUN_0808b910
FUN_0808b910: @ 0x0808B910
	push {r4, r5, r6, lr}
	ldr r3, _0808B96C @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	movs r2, #0x40
	orrs r1, r2
	ldr r2, _0808B970 @ =0x0000FFFF
	ands r1, r2
	movs r2, #0x98
	lsls r2, r2, #0xf
	adds r4, r1, #0
	orrs r4, r2
	ands r5, r3
	movs r6, #0
	movs r1, #0xd8
	lsls r1, r1, #4
	adds r3, r0, r1
_0808B932:
	ldr r0, _0808B974 @ =0x00000F84
	adds r2, r3, r0
	str r4, [r2]
	str r5, [r2, #4]
	movs r1, #1
	ands r1, r6
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r0, _0808B978 @ =0x00000F86
	adds r2, r3, r0
	asrs r1, r6, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r3, #0x60
	adds r6, #1
	cmp r6, #3
	ble _0808B932
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808B96C: .4byte 0xFFFF0000
_0808B970: .4byte 0x0000FFFF
_0808B974: .4byte 0x00000F84
_0808B978: .4byte 0x00000F86

	thumb_func_start FUN_0808b97c
FUN_0808b97c: @ 0x0808B97C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	movs r4, #0
	cmp r4, r6
	bge _0808B9B6
_0808B990:
	adds r2, r7, r4
	movs r0, #0
	mov r1, r8
	bl FUN_0808a420
	adds r2, r4, #1
	cmp r5, #0
	ble _0808B9B0
	ldr r1, _0808B9C0 @ =0x0000F001
	adds r3, r1, #0
	adds r1, r5, #0
_0808B9A6:
	strh r3, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _0808B9A6
_0808B9B0:
	adds r4, r2, #0
	cmp r4, r6
	blt _0808B990
_0808B9B6:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808B9C0: .4byte 0x0000F001

	thumb_func_start FUN_0808b9c4
FUN_0808b9c4: @ 0x0808B9C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	movs r4, #0
	cmp r4, r6
	bge _0808B9FE
_0808B9D8:
	adds r2, r7, r4
	movs r0, #0
	mov r1, r8
	bl FUN_0808a420
	adds r2, r4, #1
	cmp r5, #0
	ble _0808B9F8
	ldr r1, _0808BA08 @ =0x0000F002
	adds r3, r1, #0
	adds r1, r5, #0
_0808B9EE:
	strh r3, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _0808B9EE
_0808B9F8:
	adds r4, r2, #0
	cmp r4, r6
	blt _0808B9D8
_0808B9FE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808BA08: .4byte 0x0000F002

	thumb_func_start FUN_0808ba0c
FUN_0808ba0c: @ 0x0808BA0C
	strh r1, [r0, #0x3a]
	ldr r1, _0808BA1C @ =0x03003584
	ldrh r2, [r0, #0x3a]
	lsls r2, r2, #5
	ldr r1, [r1]
	adds r1, r1, r2
	str r1, [r0, #0x48]
	bx lr
	.align 2, 0
_0808BA1C: .4byte 0x03003584

	thumb_func_start FUN_0808ba20
FUN_0808ba20: @ 0x0808BA20
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	mov r8, r1
	adds r4, r2, #0
	movs r1, #0
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r2, r8
	movs r3, #0
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r6, r4, #1
	adds r1, r6, #0
	bl Div
	strh r0, [r5]
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	mov r2, r8
	movs r3, #2
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	adds r1, r6, #0
	bl Div
	strh r0, [r5, #2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808ba64
FUN_0808ba64: @ 0x0808BA64
	push {lr}
	adds r2, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r1, [r0]
	ldr r3, _0808BA80 @ =0x0000043E
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808BA84
	movs r1, #2
	b _0808BAA2
	.align 2, 0
_0808BA80: .4byte 0x0000043E
_0808BA84:
	ldr r3, _0808BAB8 @ =0x0000038E
	adds r0, r1, r3
	ldrb r0, [r0]
	ldr r1, _0808BABC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	cmp r0, #0
	ble _0808BAA2
	movs r1, #6
_0808BAA2:
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r2, r3
	ldr r0, [r0]
	lsls r1, r1, #1
	ldr r2, _0808BAC0 @ =0x00000938
	adds r0, r0, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_0808BAB8: .4byte 0x0000038E
_0808BABC: .4byte 0x030046A0
_0808BAC0: .4byte 0x00000938

	thumb_func_start FUN_0808bac4
FUN_0808bac4: @ 0x0808BAC4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	bl FUN_0808ba64
	ldr r1, _0808BB14 @ =0x03003584
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r0, _0808BB18 @ =0x000009B8
	adds r2, r7, r0
	movs r3, #0xf
_0808BADC:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0808BADC
	ldr r2, _0808BB1C @ =0x000009DE
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	bls _0808BB08
	b _0808C020
_0808BB08:
	lsls r0, r0, #2
	ldr r1, _0808BB20 @ =_0808BB24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808BB14: .4byte 0x03003584
_0808BB18: .4byte 0x000009B8
_0808BB1C: .4byte 0x000009DE
_0808BB20: .4byte _0808BB24
_0808BB24: @ jump table
	.4byte _0808BB3C @ case 0
	.4byte _0808BB84 @ case 1
	.4byte _0808BC18 @ case 2
	.4byte _0808BD68 @ case 3
	.4byte _0808BE9C @ case 4
	.4byte _0808BBC8 @ case 5
_0808BB3C:
	ldr r0, _0808BB74 @ =0x000024CC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0808BB78 @ =0x0000250C
	adds r1, r7, r2
	ldr r3, _0808BB7C @ =0x000009B8
	adds r0, r7, r3
	str r0, [r1]
	ldr r4, _0808BB80 @ =0x000024C4
	adds r0, r7, r4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r2, #0
	str r2, [sp]
	movs r2, #4
	b _0808BBFE
	.align 2, 0
_0808BB74: .4byte 0x000024CC
_0808BB78: .4byte 0x0000250C
_0808BB7C: .4byte 0x000009B8
_0808BB80: .4byte 0x000024C4
_0808BB84:
	ldr r3, _0808BBBC @ =0x000024CC
	adds r2, r7, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r4, #0xb6
	lsls r4, r4, #4
	adds r2, r7, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0808BBC0 @ =0x0000250C
	adds r1, r7, r0
	ldr r2, _0808BBC4 @ =0x000009B8
	adds r0, r7, r2
	str r0, [r1]
	subs r3, #8
	adds r0, r7, r3
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r2, #0
	str r2, [sp]
	movs r2, #0xcb
	b _0808BBFE
	.align 2, 0
_0808BBBC: .4byte 0x000024CC
_0808BBC0: .4byte 0x0000250C
_0808BBC4: .4byte 0x000009B8
_0808BBC8:
	ldr r0, _0808BC08 @ =0x000024CC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0808BC0C @ =0x0000250C
	adds r1, r7, r2
	ldr r3, _0808BC10 @ =0x000009B8
	adds r0, r7, r3
	str r0, [r1]
	ldr r4, _0808BC14 @ =0x000024C4
	adds r0, r7, r4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r7, r2
	adds r2, #0xa2
	movs r3, #0
	str r3, [sp]
_0808BBFE:
	movs r3, #1
	bl FUN_082370cc
	b _0808C020
	.align 2, 0
_0808BC08: .4byte 0x000024CC
_0808BC0C: .4byte 0x0000250C
_0808BC10: .4byte 0x000009B8
_0808BC14: .4byte 0x000024C4
_0808BC18:
	ldr r3, _0808BCA4 @ =0x00000B8C
	adds r4, r7, r3
	ldr r1, _0808BCA8 @ =0x0000DA6D
	adds r0, r4, #0
	bl Video_GetActorSprite
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r7, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0822a4fc
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r2, _0808BCAC @ =0x00000B7E
	adds r1, r7, r2
	movs r0, #0x60
	strh r0, [r1]
	ldr r3, _0808BCB0 @ =0x000024CC
	adds r1, r7, r3
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	ldr r0, _0808BCB4 @ =0x00000B98
	adds r1, r7, r0
	ldr r2, _0808BCB8 @ =0x000009B8
	adds r0, r7, r2
	str r0, [r1]
	ldr r3, _0808BCBC @ =0x00000BA8
	adds r6, r7, r3
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r1, [r0]
	str r4, [sp]
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl FUN_08237040
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r6, #4]
	adds r1, r4, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r4
	cmp r1, r0
	beq _0808BCC0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808BCC8
	.align 2, 0
_0808BCA4: .4byte 0x00000B8C
_0808BCA8: .4byte 0x0000DA6D
_0808BCAC: .4byte 0x00000B7E
_0808BCB0: .4byte 0x000024CC
_0808BCB4: .4byte 0x00000B98
_0808BCB8: .4byte 0x000009B8
_0808BCBC: .4byte 0x00000BA8
_0808BCC0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808BCC8:
	str r0, [r5]
	ldrb r0, [r6, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0808BCEC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808BCF4
_0808BCEC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808BCF4:
	str r0, [r5]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r3, _0808BD2C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r6, #7]
	cmp r0, r4
	bhs _0808BD0C
	b _0808C020
_0808BD0C:
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808BD30
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _0808BD26
	ldrb r0, [r6, #5]
_0808BD26:
	subs r0, #1
	strh r0, [r6, #8]
	b _0808BD40
	.align 2, 0
_0808BD2C: .4byte 0x0000FFFF
_0808BD30:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _0808BD40
	strh r1, [r6, #8]
_0808BD40:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808BD62
	b _0808C020
_0808BD62:
	movs r0, #1
	strb r0, [r6, #7]
	b _0808C020
_0808BD68:
	ldr r3, _0808BDF4 @ =0x00000B8C
	adds r4, r7, r3
	ldr r1, _0808BDF8 @ =0x0000D495
	adds r0, r4, #0
	bl Video_GetActorSprite
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r7, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0822a4fc
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r2, _0808BDFC @ =0x00000B7E
	adds r1, r7, r2
	movs r2, #0
	movs r0, #0x70
	strh r0, [r1]
	ldr r3, _0808BE00 @ =0x000024CC
	adds r1, r7, r3
	ldr r0, [r1]
	movs r6, #1
	orrs r0, r6
	str r0, [r1]
	ldr r4, _0808BE04 @ =0x00000B98
	adds r1, r7, r4
	ldr r3, _0808BE08 @ =0x000009B8
	adds r0, r7, r3
	str r0, [r1]
	ldr r0, _0808BE0C @ =0x00000BA8
	adds r4, r7, r0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r3, #0xd4
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r1, [r0]
	str r2, [sp]
	adds r0, r4, #0
	movs r3, #4
	bl FUN_08237040
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	adds r1, r6, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r6
	cmp r1, r0
	beq _0808BE10
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808BE18
	.align 2, 0
_0808BDF4: .4byte 0x00000B8C
_0808BDF8: .4byte 0x0000D495
_0808BDFC: .4byte 0x00000B7E
_0808BE00: .4byte 0x000024CC
_0808BE04: .4byte 0x00000B98
_0808BE08: .4byte 0x000009B8
_0808BE0C: .4byte 0x00000BA8
_0808BE10:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808BE18:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0808BE3C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808BE44
_0808BE3C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808BE44:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0808BE7C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	bhs _0808BE5C
	b _0808C020
_0808BE5C:
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808BE80
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0808BE76
	ldrb r0, [r4, #5]
_0808BE76:
	subs r0, #1
	strh r0, [r4, #8]
	b _0808BE90
	.align 2, 0
_0808BE7C: .4byte 0x0000FFFF
_0808BE80:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0808BE90
	strh r1, [r4, #8]
_0808BE90:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	b _0808C006
_0808BE9C:
	ldr r3, _0808BF0C @ =0x00000B8C
	adds r5, r7, r3
	ldr r1, _0808BF10 @ =0x00002499
	adds r0, r5, #0
	bl Video_GetActorSprite
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r4, r7, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a4fc
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r2, _0808BF14 @ =0x00000B7E
	adds r1, r7, r2
	movs r3, #0
	movs r0, #0x60
	strh r0, [r1]
	ldr r4, _0808BF18 @ =0x000024CC
	adds r2, r7, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0808BF1C @ =0x00000B98
	adds r1, r7, r0
	ldr r2, _0808BF20 @ =0x000009B8
	adds r0, r7, r2
	str r0, [r1]
	movs r4, #0x9e
	lsls r4, r4, #4
	adds r0, r7, r4
	ldr r1, [r0]
	ldr r0, _0808BF24 @ =0x00000387
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #5
	bne _0808BF2C
	ldr r4, _0808BF28 @ =0x00000BA8
	adds r0, r7, r4
	movs r4, #0xd5
	lsls r4, r4, #2
	adds r1, r1, r4
	ldr r1, [r1]
	ldrb r2, [r2]
	str r3, [sp]
	movs r3, #4
	bl FUN_08237040
	b _0808BF42
	.align 2, 0
_0808BF0C: .4byte 0x00000B8C
_0808BF10: .4byte 0x00002499
_0808BF14: .4byte 0x00000B7E
_0808BF18: .4byte 0x000024CC
_0808BF1C: .4byte 0x00000B98
_0808BF20: .4byte 0x000009B8
_0808BF24: .4byte 0x00000387
_0808BF28: .4byte 0x00000BA8
_0808BF2C:
	ldr r4, _0808BF78 @ =0x00000BA8
	adds r0, r7, r4
	movs r4, #0xd5
	lsls r4, r4, #2
	adds r1, r1, r4
	ldr r1, [r1]
	ldrb r2, [r2]
	str r3, [sp]
	movs r3, #0
	bl FUN_08237040
_0808BF42:
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r7, r0
	ldr r1, _0808BF78 @ =0x00000BA8
	adds r4, r7, r1
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
	beq _0808BF7C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808BF84
	.align 2, 0
_0808BF78: .4byte 0x00000BA8
_0808BF7C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808BF84:
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
	beq _0808BFA8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808BFB0
_0808BFA8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808BFB0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0808BFE8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0808C020
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808BFEC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0808BFE0
	ldrb r0, [r4, #5]
_0808BFE0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0808BFFC
	.align 2, 0
_0808BFE8: .4byte 0x0000FFFF
_0808BFEC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0808BFFC
	strh r1, [r4, #8]
_0808BFFC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
_0808C006:
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
	bne _0808C020
	movs r0, #1
	strb r0, [r4, #7]
_0808C020:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808c028
FUN_0808c028: @ 0x0808C028
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	bls _0808C042
	b _0808C15C
_0808C042:
	lsls r0, r0, #2
	ldr r1, _0808C04C @ =_0808C050
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808C04C: .4byte _0808C050
_0808C050: @ jump table
	.4byte _0808C068 @ case 0
	.4byte _0808C068 @ case 1
	.4byte _0808C07C @ case 2
	.4byte _0808C07C @ case 3
	.4byte _0808C07C @ case 4
	.4byte _0808C068 @ case 5
_0808C068:
	ldr r1, _0808C078 @ =0x000024C4
	adds r0, r2, r1
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r2, r3
	bl FUN_082372cc
	b _0808C15C
	.align 2, 0
_0808C078: .4byte 0x000024C4
_0808C07C:
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r5, r2, r0
	ldr r1, _0808C0B4 @ =0x00000BA8
	adds r4, r2, r1
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
	beq _0808C0B8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0808C0C0
	.align 2, 0
_0808C0B4: .4byte 0x00000BA8
_0808C0B8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0808C0C0:
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
	beq _0808C0E4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0808C0EC
_0808C0E4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0808C0EC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0808C124 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0808C15C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0808C128
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0808C11C
	ldrb r0, [r4, #5]
_0808C11C:
	subs r0, #1
	strh r0, [r4, #8]
	b _0808C138
	.align 2, 0
_0808C124: .4byte 0x0000FFFF
_0808C128:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0808C138
	strh r1, [r4, #8]
_0808C138:
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
	bne _0808C15C
	movs r0, #1
	strb r0, [r4, #7]
_0808C15C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808c164
FUN_0808c164: @ 0x0808C164
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r3, #0
	ldr r0, _0808C1B0 @ =0x000009D8
	adds r3, r4, r0
	strh r1, [r3]
	ldr r1, _0808C1B4 @ =0x000009DA
	adds r0, r4, r1
	strh r2, [r0]
	ldr r1, _0808C1B8 @ =0x03003584
	ldrh r0, [r3]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r0, _0808C1BC @ =0x000009B8
	adds r2, r4, r0
	movs r3, #0xf
_0808C186:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _0808C186
	ldr r1, _0808C1C0 @ =0x000009DD
	adds r0, r4, r1
	movs r1, #0
	strb r5, [r0]
	ldr r2, _0808C1C4 @ =0x000009DC
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _0808C1C8 @ =0x000009DE
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808C1B0: .4byte 0x000009D8
_0808C1B4: .4byte 0x000009DA
_0808C1B8: .4byte 0x03003584
_0808C1BC: .4byte 0x000009B8
_0808C1C0: .4byte 0x000009DD
_0808C1C4: .4byte 0x000009DC
_0808C1C8: .4byte 0x000009DE

	thumb_func_start FUN_0808c1cc
FUN_0808c1cc: @ 0x0808C1CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	ldr r0, _0808C1E8 @ =0x000009DE
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808C1EC
	movs r0, #1
	b _0808C316
	.align 2, 0
_0808C1E8: .4byte 0x000009DE
_0808C1EC:
	ldr r1, _0808C244 @ =0x03003584
	ldr r0, _0808C248 @ =0x000009D8
	add r0, sl
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r0, r1, r0
	str r0, [sp]
	ldr r0, _0808C24C @ =0x000009DA
	add r0, sl
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r1, r1, r0
	mov sb, r1
	ldr r2, _0808C250 @ =0x000009DC
	add r2, sl
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r1, _0808C254 @ =0x000009DD
	add r1, sl
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r3, [r1]
	cmp r0, r3
	blo _0808C260
	ldr r1, _0808C258 @ =0x000009B8
	add r1, sl
	movs r7, #0xf
_0808C226:
	mov r2, sb
	ldrh r0, [r2]
	strh r0, [r1]
	movs r3, #2
	add sb, r3
	adds r1, #2
	subs r7, #1
	cmp r7, #0
	bge _0808C226
	ldr r1, _0808C25C @ =0x000009DE
	add r1, sl
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0808C316
	.align 2, 0
_0808C244: .4byte 0x03003584
_0808C248: .4byte 0x000009D8
_0808C24C: .4byte 0x000009DA
_0808C250: .4byte 0x000009DC
_0808C254: .4byte 0x000009DD
_0808C258: .4byte 0x000009B8
_0808C25C: .4byte 0x000009DE
_0808C260:
	ldrb r1, [r1]
	ldrb r0, [r2]
	subs r1, r1, r0
	str r1, [sp, #4]
	movs r7, #0
	ldr r0, _0808C328 @ =0x000009DC
	add r0, sl
	str r0, [sp, #8]
	ldr r1, _0808C32C @ =0x000009DD
	add r1, sl
	str r1, [sp, #0xc]
_0808C276:
	cmp r7, #5
	beq _0808C304
	cmp r7, #0xd
	beq _0808C304
	ldr r2, [sp]
	ldrh r5, [r2]
	movs r0, #0x1f
	ands r0, r5
	lsls r5, r5, #0x10
	lsrs r3, r5, #0x15
	movs r1, #0x1f
	ands r3, r1
	lsrs r5, r5, #0x1a
	ands r5, r1
	mov r2, sb
	ldrh r4, [r2]
	movs r2, #0x1f
	ands r2, r4
	lsls r4, r4, #0x10
	lsrs r6, r4, #0x15
	ands r6, r1
	lsrs r4, r4, #0x1a
	ands r4, r1
	ldr r1, [sp, #4]
	muls r0, r1, r0
	ldr r1, [sp, #8]
	ldrb r1, [r1]
	mov r8, r1
	mov r1, r8
	muls r1, r2, r1
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	ldrb r1, [r2]
	str r3, [sp, #0x10]
	bl Div
	mov r8, r0
	ldr r3, [sp, #0x10]
	ldr r1, [sp, #4]
	adds r0, r3, #0
	muls r0, r1, r0
	ldr r2, [sp, #8]
	ldrb r1, [r2]
	muls r1, r6, r1
	adds r0, r0, r1
	ldr r3, [sp, #0xc]
	ldrb r1, [r3]
	bl Div
	adds r6, r0, #0
	ldr r1, [sp, #4]
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r2, [sp, #8]
	ldrb r1, [r2]
	muls r1, r4, r1
	adds r0, r0, r1
	ldr r3, [sp, #0xc]
	ldrb r1, [r3]
	bl Div
	lsls r1, r7, #1
	ldr r2, _0808C330 @ =0x000009B8
	add r2, sl
	adds r2, r2, r1
	lsls r0, r0, #0xa
	lsls r6, r6, #5
	orrs r0, r6
	mov r1, r8
	orrs r0, r1
	strh r0, [r2]
_0808C304:
	ldr r2, [sp]
	adds r2, #2
	str r2, [sp]
	movs r3, #2
	add sb, r3
	adds r7, #1
	cmp r7, #0xf
	ble _0808C276
	movs r0, #0
_0808C316:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0808C328: .4byte 0x000009DC
_0808C32C: .4byte 0x000009DD
_0808C330: .4byte 0x000009B8

	thumb_func_start FUN_0808c334
FUN_0808c334: @ 0x0808C334
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r3, [sp, #0x20]
	ldr r2, [sp, #0x24]
	ldr r4, [sp, #0x28]
	lsls r0, r6, #5
	ldr r1, _0808C3A4 @ =0x00003B28
	adds r0, r0, r1
	mov r7, sl
	adds r5, r7, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r5]
	str r1, [r5, #4]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	cmp r4, #0
	beq _0808C3DA
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r7, #0
	ldrsh r1, [r3, r7]
	subs r0, r0, r1
	movs r7, #2
	ldrsh r1, [r2, r7]
	movs r2, #2
	ldrsh r3, [r3, r2]
	subs r1, r1, r3
	bl FUN_0823785c
	adds r3, r0, #0
	adds r3, #0x40
	movs r1, #0xff
	ands r3, r1
	ldr r2, _0808C3A8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r4, r0
	cmp r0, #0
	blt _0808C3AC
	asrs r0, r0, #0xc
	b _0808C3B2
	.align 2, 0
_0808C3A4: .4byte 0x00003B28
_0808C3A8: .4byte 0x085B0A08
_0808C3AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808C3B2:
	strh r0, [r5, #0x10]
	ldr r0, _0808C3CC @ =0x085B0A08
	movs r1, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0808C3D0
	asrs r0, r0, #0xc
	b _0808C3D6
	.align 2, 0
_0808C3CC: .4byte 0x085B0A08
_0808C3D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808C3D6:
	strh r0, [r5, #0x12]
	b _0808C3DE
_0808C3DA:
	strh r4, [r5, #0x10]
	strh r4, [r5, #0x12]
_0808C3DE:
	lsls r4, r6, #1
	adds r4, r4, r6
	lsls r4, r4, #5
	ldr r7, _0808C430 @ =0x000020A4
	adds r4, r4, r7
	add r4, sl
	mov r1, sl
	adds r1, #0xa0
	mov r0, r8
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0808ba0c
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x20]
	str r1, [r4, #0x24]
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r0, #0
	strh r0, [r5, #0x18]
	ldr r0, [sp, #0x2c]
	strh r0, [r5, #0x1a]
	movs r0, #1
	strb r0, [r5, #0x1c]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C430: .4byte 0x000020A4

	thumb_func_start FUN_0808c434
FUN_0808c434: @ 0x0808C434
	push {r4, r5, r6, r7, lr}
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #5
	ldr r3, _0808C454 @ =0x000020A4
	adds r2, r2, r3
	adds r6, r0, r2
	lsls r1, r1, #5
	ldr r7, _0808C458 @ =0x00003B28
	adds r1, r1, r7
	adds r5, r0, r1
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	bne _0808C45C
	movs r0, #1
	b _0808C508
	.align 2, 0
_0808C454: .4byte 0x000020A4
_0808C458: .4byte 0x00003B28
_0808C45C:
	ldrh r0, [r5, #0x18]
	adds r0, #1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5, #0x1a]
	cmp r0, r1
	blo _0808C47C
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r6, #0x20]
	str r1, [r6, #0x24]
	movs r0, #0
	strb r0, [r5, #0x1c]
	movs r0, #1
	b _0808C508
_0808C47C:
	ldrh r1, [r5, #0x1a]
	ldrh r3, [r5, #0x18]
	subs r4, r1, r3
	movs r2, #0
	ldrsh r0, [r5, r2]
	muls r0, r4, r0
	movs r7, #8
	ldrsh r2, [r5, r7]
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	strh r0, [r6, #0x20]
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r4, r0
	movs r3, #0xa
	ldrsh r2, [r5, r3]
	ldrh r1, [r5, #0x18]
	muls r1, r2, r1
	adds r0, r0, r1
	ldrh r1, [r5, #0x1a]
	bl Div
	strh r0, [r6, #0x22]
	ldr r0, [r5, #0x10]
	cmp r0, #0
	beq _0808C506
	ldr r4, _0808C4DC @ =0x085B0A08
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #7
	ldrh r1, [r5, #0x1a]
	bl Div
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r7, #0
	ldrsh r2, [r1, r7]
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0808C4E0
	asrs r1, r0, #0xc
	b _0808C4E6
	.align 2, 0
_0808C4DC: .4byte 0x085B0A08
_0808C4E0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808C4E6:
	ldrh r0, [r6, #0x20]
	adds r0, r0, r1
	strh r0, [r6, #0x20]
	movs r3, #0x12
	ldrsh r0, [r5, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _0808C4FA
	asrs r1, r0, #0xc
	b _0808C500
_0808C4FA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808C500:
	ldrh r0, [r6, #0x22]
	adds r0, r0, r1
	strh r0, [r6, #0x22]
_0808C506:
	movs r0, #0
_0808C508:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808c510
FUN_0808c510: @ 0x0808C510
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	cmp r2, #0
	beq _0808C520
	ldr r0, _0808C544 @ =0x00000107
	bl PlaySound_082406e0
_0808C520:
	bl FUN_08049e5c
	adds r0, r4, #0
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808C544: .4byte 0x00000107

	thumb_func_start FUN_0808c548
FUN_0808c548: @ 0x0808C548
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808C57C @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808C5BC
	ldr r1, _0808C580 @ =0x00001BC4
	adds r0, r4, r1
	ldr r1, _0808C584 @ =0x000002DF
	bl FUN_0808ba0c
	ldr r1, _0808C588 @ =0x000009EE
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _0808C590
	ldr r1, _0808C58C @ =0x00001C2C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0808C59A
	.align 2, 0
_0808C57C: .4byte 0x00003AE8
_0808C580: .4byte 0x00001BC4
_0808C584: .4byte 0x000002DF
_0808C588: .4byte 0x000009EE
_0808C58C: .4byte 0x00001C2C
_0808C590:
	ldr r1, _0808C5B4 @ =0x00001C2C
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0808C59A:
	str r1, [r0]
	ldr r0, _0808C5B8 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _0808C5D4
	movs r0, #0
	strh r0, [r1]
	b _0808C5D4
	.align 2, 0
_0808C5B4: .4byte 0x00001C2C
_0808C5B8: .4byte 0x000009EE
_0808C5BC:
	ldr r1, _0808C5F0 @ =0x00001BC4
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
	ldr r0, _0808C5F4 @ =0x00001C2C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0808C5D4:
	ldr r1, _0808C5F8 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808C604
	ldr r1, _0808C5FC @ =0x00001C84
	adds r0, r4, r1
	ldr r1, _0808C600 @ =0x000002DF
	bl FUN_0808ba0c
	b _0808C610
	.align 2, 0
_0808C5F0: .4byte 0x00001BC4
_0808C5F4: .4byte 0x00001C2C
_0808C5F8: .4byte 0x00003AE8
_0808C5FC: .4byte 0x00001C84
_0808C600: .4byte 0x000002DF
_0808C604:
	ldr r1, _0808C618 @ =0x00001C84
	adds r0, r4, r1
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_0808C610:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808C618: .4byte 0x00001C84

	thumb_func_start FUN_0808c61c
FUN_0808c61c: @ 0x0808C61C
	push {r4, lr}
	ldr r4, _0808C640 @ =0x000025A4
	adds r3, r0, r4
	strh r1, [r3]
	adds r4, #2
	adds r3, r0, r4
	strh r2, [r3]
	adds r4, #0x5e
	adds r3, r0, r4
	strh r1, [r3]
	adds r2, #8
	ldr r1, _0808C644 @ =0x00002606
	adds r0, r0, r1
	strh r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808C640: .4byte 0x000025A4
_0808C644: .4byte 0x00002606

	thumb_func_start FUN_0808c648
FUN_0808c648: @ 0x0808C648
	push {lr}
	cmp r0, #0
	beq _0808C652
	adds r0, #0xa0
	b _0808C654
_0808C652:
	movs r0, #0x93
_0808C654:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808c658
FUN_0808c658: @ 0x0808C658
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r3, r1, #0
	adds r7, r2, #0
	cmp r3, #0
	bge _0808C678
	ldr r1, _0808C674 @ =0x0000258C
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0808C6A4
	.align 2, 0
_0808C674: .4byte 0x0000258C
_0808C678:
	ldr r0, _0808C6B8 @ =0x0000258C
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808C6BC @ =0x00002584
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r3, #0
	bl FUN_0808c648
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
_0808C6A4:
	cmp r7, #0
	bge _0808C6C4
	ldr r1, _0808C6C0 @ =0x000025EC
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0808C6F0
	.align 2, 0
_0808C6B8: .4byte 0x0000258C
_0808C6BC: .4byte 0x00002584
_0808C6C0: .4byte 0x000025EC
_0808C6C4:
	ldr r0, _0808C6F8 @ =0x000025EC
	adds r2, r6, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808C6FC @ =0x000025E4
	adds r4, r6, r1
	adds r5, r6, #0
	adds r5, #0x60
	adds r0, r7, #0
	bl FUN_0808c648
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl Sprite_SetSprite
_0808C6F0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C6F8: .4byte 0x000025EC
_0808C6FC: .4byte 0x000025E4

	thumb_func_start FUN_0808c700
FUN_0808c700: @ 0x0808C700
	push {lr}
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_0808c658
	pop {r0}
	bx r0

	thumb_func_start FUN_0808c710
FUN_0808c710: @ 0x0808C710
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x39
	ldrb r0, [r5]
	adds r2, r0, #1
	strb r2, [r5]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0808C738
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r1, r4, #0
	adds r1, #0x38
	movs r0, #0
	strb r0, [r1]
	b _0808C766
_0808C738:
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x1b
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x30]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r2, [r4, #0x32]
	ldrh r1, [r4, #0x1a]
	adds r0, r2, r1
	strh r0, [r4, #0x1a]
	ldrb r1, [r5]
	movs r0, #7
	ands r0, r1
	adds r1, r4, #0
	adds r1, #0x38
	cmp r0, #0
	bne _0808C766
	adds r0, r2, #1
	strh r0, [r4, #0x32]
_0808C766:
	ldrb r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808c770
FUN_0808c770: @ 0x0808C770
	push {r4, lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x39
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _0808C798
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r1, r2, #0
	adds r1, #0x38
	movs r0, #0
	strb r0, [r1]
	b _0808C7BA
_0808C798:
	ldrh r0, [r2, #0x30]
	ldrh r3, [r2, #0x18]
	adds r0, r0, r3
	strh r0, [r2, #0x18]
	ldrh r3, [r2, #0x32]
	ldrh r4, [r2, #0x1a]
	adds r0, r3, r4
	strh r0, [r2, #0x1a]
	ldrb r1, [r1]
	movs r0, #3
	ands r0, r1
	adds r1, r2, #0
	adds r1, #0x38
	cmp r0, #0
	bne _0808C7BA
	adds r0, r3, #1
	strh r0, [r2, #0x32]
_0808C7BA:
	ldrb r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808c7c4
FUN_0808c7c4: @ 0x0808C7C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov sb, r0
	movs r1, #0
_0808C7D2:
	lsls r0, r1, #6
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r2, _0808C830 @ =0x00003B8C
	adds r0, r0, r2
	mov r2, sb
	adds r6, r2, r0
	ldrb r0, [r6, #4]
	adds r1, #1
	mov r8, r1
	cmp r0, #0
	beq _0808C81C
	movs r3, #0
	adds r4, r6, #0
	adds r4, #0x40
	adds r5, r6, #0
	adds r5, #8
	movs r7, #7
_0808C7F6:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808C810
	ldr r1, [r6]
	ldr r2, [r4, #4]
	adds r0, r5, #0
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	cmp r0, #0
	beq _0808C810
	movs r3, #1
_0808C810:
	adds r4, #0x40
	adds r5, #0x40
	subs r7, #1
	cmp r7, #0
	bge _0808C7F6
	strb r3, [r6, #4]
_0808C81C:
	mov r1, r8
	cmp r1, #1
	ble _0808C7D2
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C830: .4byte 0x00003B8C

	thumb_func_start FUN_0808c834
FUN_0808c834: @ 0x0808C834
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r2, [sp]
	str r3, [sp, #4]
	lsls r2, r1, #6
	adds r2, r2, r1
	lsls r2, r2, #3
	ldr r1, _0808C8F0 @ =0x00003B8C
	adds r2, r2, r1
	adds r0, r0, r2
	mov r8, r0
	ldr r0, _0808C8F4 @ =0x00001C1E
	bl GetParticleGroup
	mov r2, r8
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #4]
	movs r7, #0
	ldr r3, _0808C8F8 @ =0x000003FF
	mov sl, r3
	mov r6, r8
	adds r6, #0x40
	mov r5, r8
	adds r5, #8
	adds r4, r5, #0
	ldr r0, _0808C8FC @ =0x085B0A08
	mov sb, r0
_0808C874:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r4, #0x18]
	mov r2, sp
	ldrh r2, [r2, #4]
	strh r2, [r4, #0x1a]
	mov r3, r8
	ldr r1, [r3]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r0, _0808C900 @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	mov r2, sl
	ands r1, r2
	lsls r0, r1, #1
	ldr r3, _0808C904 @ =0x0203B400
	adds r0, r0, r3
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
	ldr r0, _0808C900 @ =0x030046B8
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _0808C904 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r1, r0, #4
	adds r3, #0x38
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808C908
	asrs r0, r0, #0xc
	b _0808C90E
	.align 2, 0
_0808C8F0: .4byte 0x00003B8C
_0808C8F4: .4byte 0x00001C1E
_0808C8F8: .4byte 0x000003FF
_0808C8FC: .4byte 0x085B0A08
_0808C900: .4byte 0x030046B8
_0808C904: .4byte 0x0203B400
_0808C908:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808C90E:
	strh r0, [r4, #0x30]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808C926
	asrs r3, r0, #0xc
	b _0808C92C
_0808C926:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0808C92C:
	movs r0, #0
	strh r3, [r4, #0x32]
	movs r1, #1
	strb r1, [r6]
	strb r0, [r6, #1]
	ldr r0, _0808C958 @ =FUN_0808c710
	str r0, [r4, #0x3c]
	adds r6, #0x40
	adds r4, #0x40
	adds r5, #0x40
	adds r7, #1
	cmp r7, #7
	ble _0808C874
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808C958: .4byte FUN_0808c710

	thumb_func_start FUN_0808c95c
FUN_0808c95c: @ 0x0808C95C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r2, [sp]
	str r3, [sp, #4]
	lsls r2, r1, #6
	adds r2, r2, r1
	lsls r2, r2, #3
	ldr r1, _0808C9C4 @ =0x00003B8C
	adds r2, r2, r1
	adds r0, r0, r2
	mov sb, r0
	ldr r0, _0808C9C8 @ =0x00001C1C
	bl GetParticleGroup
	mov r2, sb
	str r0, [r2]
	movs r0, #1
	strb r0, [r2, #4]
	movs r3, #0
	mov r8, r3
	mov r6, sb
	adds r6, #0x40
	mov r5, sb
	adds r5, #8
	adds r4, r5, #0
	mov sl, r0
_0808C998:
	ldr r1, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4]
	ldr r7, _0808C9CC @ =0x030046B8
	ldr r0, [r7]
	adds r0, #1
	ldr r2, _0808C9D0 @ =0x000003FF
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _0808C9D4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r7, sl
	ands r0, r7
	cmp r0, #0
	beq _0808C9D8
	movs r0, #4
	orrs r1, r0
	b _0808C9DE
	.align 2, 0
_0808C9C4: .4byte 0x00003B8C
_0808C9C8: .4byte 0x00001C1C
_0808C9CC: .4byte 0x030046B8
_0808C9D0: .4byte 0x000003FF
_0808C9D4: .4byte 0x0203B400
_0808C9D8:
	movs r0, #5
	rsbs r0, r0, #0
	ands r1, r0
_0808C9DE:
	str r1, [r4]
	mov r0, sb
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x15
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0822dadc
	ldr r2, _0808CA4C @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r3, _0808CA50 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	ldr r7, _0808CA54 @ =0x0203B400
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r0, r8
	lsls r3, r0, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	ldr r7, _0808CA50 @ =0x000003FF
	ands r1, r7
	ldr r0, _0808CA4C @ =0x030046B8
	str r1, [r0]
	lsls r1, r1, #1
	ldr r7, _0808CA54 @ =0x0203B400
	adds r1, r1, r7
	ldrh r0, [r1]
	asrs r0, r0, #3
	mov r1, sl
	ands r0, r1
	adds r1, r0, #3
	adds r3, #0x38
	movs r0, #0xff
	ands r3, r0
	lsls r3, r3, #1
	ldr r7, _0808CA58 @ =0x085B0A08
	adds r3, r3, r7
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808CA5C
	asrs r0, r0, #0xc
	b _0808CA62
	.align 2, 0
_0808CA4C: .4byte 0x030046B8
_0808CA50: .4byte 0x000003FF
_0808CA54: .4byte 0x0203B400
_0808CA58: .4byte 0x085B0A08
_0808CA5C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808CA62:
	strh r0, [r4, #0x30]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	ldr r2, _0808CA7C @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808CA80
	asrs r0, r0, #0xc
	b _0808CA86
	.align 2, 0
_0808CA7C: .4byte 0x085B0A08
_0808CA80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808CA86:
	subs r1, r0, #2
	movs r2, #0
	strh r1, [r4, #0x32]
	ldrh r0, [r4, #0x30]
	ldr r7, [sp]
	adds r0, r0, r7
	strh r0, [r4, #0x18]
	ldr r0, [sp, #4]
	adds r1, r1, r0
	strh r1, [r4, #0x1a]
	mov r1, sl
	strb r1, [r6]
	strb r2, [r6, #1]
	ldr r0, _0808CAC8 @ =FUN_0808c770
	str r0, [r4, #0x3c]
	adds r6, #0x40
	adds r4, #0x40
	adds r5, #0x40
	movs r2, #1
	add r8, r2
	mov r3, r8
	cmp r3, #7
	bgt _0808CAB6
	b _0808C998
_0808CAB6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CAC8: .4byte FUN_0808c770

	thumb_func_start FUN_0808cacc
FUN_0808cacc: @ 0x0808CACC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #0
_0808CAD2:
	lsls r0, r1, #6
	adds r6, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _0808CAFC @ =0x00003B94
	adds r0, r0, r1
	adds r4, r7, r0
	movs r5, #7
_0808CAE2:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _0808CAE2
	adds r1, r6, #0
	cmp r1, #1
	ble _0808CAD2
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CAFC: .4byte 0x00003B94

	thumb_func_start FUN_0808cb00
FUN_0808cb00: @ 0x0808CB00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	movs r4, #0
_0808CB10:
	lsls r0, r4, #6
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r1, _0808CB88 @ =0x00003B8C
	adds r0, r0, r1
	ldr r1, [sp]
	adds r6, r1, r0
	movs r0, #0x91
	str r0, [sp, #4]
	cmp r4, #0
	bne _0808CB2A
	movs r1, #0x11
	str r1, [sp, #4]
_0808CB2A:
	ldr r0, _0808CB8C @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6]
	movs r0, #0
	strb r0, [r6, #4]
	strb r0, [r6, #5]
	adds r4, #1
	mov sl, r4
	subs r0, #4
	mov sb, r0
	movs r1, #0
	mov r8, r1
	adds r5, r6, #0
	adds r5, #0x40
	adds r4, r6, #0
	adds r4, #8
	movs r7, #7
_0808CB4E:
	ldr r1, [r6]
	adds r0, r4, #0
	ldr r2, [sp, #4]
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, sb
	mov r2, sb
	bl FUN_0822dad4
	mov r0, r8
	strb r0, [r4, #0xf]
	strb r0, [r5]
	adds r5, #0x40
	adds r4, #0x40
	subs r7, #1
	cmp r7, #0
	bge _0808CB4E
	mov r4, sl
	cmp r4, #1
	ble _0808CB10
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CB88: .4byte 0x00003B8C
_0808CB8C: .4byte 0x00001C1E

	thumb_func_start FUN_0808cb90
FUN_0808cb90: @ 0x0808CB90
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808CBCC
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808a420
	adds r2, r0, #0
	movs r1, #0
	ldr r0, _0808CBD4 @ =0xFFFFD000
	adds r3, r0, #0
_0808CBB2:
	adds r0, r1, #0
	adds r0, #0xa0
	orrs r0, r3
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #8
	ble _0808CBB2
	movs r0, #0xa3
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0808CBCC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808CBD4: .4byte 0xFFFFD000

	thumb_func_start FUN_0808cbd8
FUN_0808cbd8: @ 0x0808CBD8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CC0E
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808a420
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r2, r1, #0
	movs r1, #8
_0808CBFA:
	strh r2, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0808CBFA
	movs r0, #0xa3
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_0808CC0E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808cc14
FUN_0808cc14: @ 0x0808CC14
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808CC7E
	ldr r0, _0808CC4C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0808CC78
	ldr r1, _0808CC50 @ =0x00000A31
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x1d
	bhi _0808CC54
	adds r0, r4, #0
	bl FUN_0808cbd8
	b _0808CC5A
	.align 2, 0
_0808CC4C: .4byte 0x030046A0
_0808CC50: .4byte 0x00000A31
_0808CC54:
	adds r0, r4, #0
	bl FUN_0808cb90
_0808CC5A:
	ldr r0, _0808CC74 @ =0x00000A31
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0808CC7E
	movs r0, #0
	strb r0, [r1]
	b _0808CC7E
	.align 2, 0
_0808CC74: .4byte 0x00000A31
_0808CC78:
	adds r0, r4, #0
	bl FUN_0808cbd8
_0808CC7E:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808cc84
FUN_0808cc84: @ 0x0808CC84
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808CCA2
	b _0808CE04
_0808CCA2:
	ldr r3, _0808CCE0 @ =0x00000282
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CCB6
	adds r2, #5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CD48
_0808CCB6:
	ldr r3, _0808CCE4 @ =0x00000C03
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808CCF0
	ldr r1, _0808CCE8 @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808CCEC @ =0x00000C0C
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc8
	movs r3, #1
	bl Sprite_SetSprite
	b _0808CD24
	.align 2, 0
_0808CCE0: .4byte 0x00000282
_0808CCE4: .4byte 0x00000C03
_0808CCE8: .4byte 0x00000C02
_0808CCEC: .4byte 0x00000C0C
_0808CCF0:
	cmp r0, #0x1e
	bne _0808CD24
	ldr r3, _0808CD3C @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808CD40 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
_0808CD24:
	ldr r0, _0808CD44 @ =0x00000C03
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0808CE04
	movs r0, #0
	strb r0, [r1]
	b _0808CE04
	.align 2, 0
_0808CD3C: .4byte 0x00000C02
_0808CD40: .4byte 0x00000C0C
_0808CD44: .4byte 0x00000C03
_0808CD48:
	ldr r2, _0808CD98 @ =0x00000283
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808CDD4
	ldr r3, _0808CD9C @ =0x000009EE
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _0808CDA0 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808CDAC
	ldr r3, _0808CDA4 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808CDA8 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0808CDC4
	.align 2, 0
_0808CD98: .4byte 0x00000283
_0808CD9C: .4byte 0x000009EE
_0808CDA0: .4byte 0x0000FFFF
_0808CDA4: .4byte 0x00000C02
_0808CDA8: .4byte 0x00000C0C
_0808CDAC:
	ldr r1, _0808CDCC @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808CDD0 @ =0x00000C0C
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc9
_0808CDC4:
	movs r3, #1
	bl Sprite_SetSprite
	b _0808CE04
	.align 2, 0
_0808CDCC: .4byte 0x00000C02
_0808CDD0: .4byte 0x00000C0C
_0808CDD4:
	ldr r3, _0808CE34 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808CE38 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
_0808CE04:
	ldr r0, _0808CE3C @ =0x00000D99
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0808CE48
	ldr r1, _0808CE40 @ =0x00000D98
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x68
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808CE44 @ =0x00000DA4
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc9
	movs r3, #1
	bl Sprite_SetSprite
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	b _0808CE8E
	.align 2, 0
_0808CE34: .4byte 0x00000C02
_0808CE38: .4byte 0x00000C0C
_0808CE3C: .4byte 0x00000D99
_0808CE40: .4byte 0x00000D98
_0808CE44: .4byte 0x00000DA4
_0808CE48:
	ldr r3, _0808CE78 @ =0x00000D98
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x68
	muls r1, r0, r1
	movs r2, #0xda
	lsls r2, r2, #4
	adds r0, r4, r2
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	bne _0808CE7C
	adds r0, r1, r4
	adds r3, #0xc
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	movs r3, #1
	bl Sprite_SetSprite
	b _0808CE8E
	.align 2, 0
_0808CE78: .4byte 0x00000D98
_0808CE7C:
	adds r0, r1, r4
	ldr r1, _0808CE94 @ =0x00000DA4
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	ldrb r2, [r2]
	movs r3, #1
	bl Sprite_SetSprite
_0808CE8E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808CE94: .4byte 0x00000DA4

	thumb_func_start FUN_0808ce98
FUN_0808ce98: @ 0x0808CE98
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808CF0E
	ldr r0, _0808CEF0 @ =0x000009FE
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #7
	beq _0808CF0E
	cmp r0, #2
	bhi _0808CF0E
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
	bl FUN_0808a9a4
	adds r0, r4, #0
	bl FUN_0808afac
	ldrb r0, [r5]
	cmp r0, #0
	bne _0808CEF4
	adds r0, r4, #0
	bl FUN_0808ad5c
	b _0808CEFC
	.align 2, 0
_0808CEF0: .4byte 0x000009FE
_0808CEF4:
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_0808abec
_0808CEFC:
	adds r0, r4, #0
	bl FUN_0808cc14
	adds r0, r4, #0
	bl FUN_0808cc84
	adds r0, r4, #0
	bl FUN_0808b1bc
_0808CF0E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808cf14
FUN_0808cf14: @ 0x0808CF14
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808CF40 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808CF4A
	adds r0, r4, #0
	bl FUN_0808ce98
	adds r0, r4, #0
	bl FUN_0808da88
	cmp r0, #0
	beq _0808CF44
	movs r0, #0x86
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0808CF4A
	.align 2, 0
_0808CF40: .4byte 0x030044BC
_0808CF44:
	adds r0, r4, #0
	bl FUN_0809b3b0
_0808CF4A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808cf50
FUN_0808cf50: @ 0x0808CF50
	push {lr}
	ldr r1, _0808CF60 @ =0x00000A34
	adds r0, r0, r1
	bl FUN_0822f1c0
	pop {r0}
	bx r0
	.align 2, 0
_0808CF60: .4byte 0x00000A34

	thumb_func_start FUN_0808cf64
FUN_0808cf64: @ 0x0808CF64
	push {r4, r5, lr}
	sub sp, #0x18
	adds r5, r0, #0
	ldr r0, _0808CFA4 @ =0x030047A4
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r2, r0
	cmp r2, #0
	beq _0808CFB4
	ldr r1, _0808CFA8 @ =0xFFFF0000
	movs r2, #0
	str r2, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	ldr r1, _0808CFAC @ =0x00000A34
	adds r0, r5, r1
	movs r3, #0xb0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r3, _0808CFB0 @ =0x00010031
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0x47
	bl FUN_0822f3fc
	b _0808CFE6
	.align 2, 0
_0808CFA4: .4byte 0x030047A4
_0808CFA8: .4byte 0xFFFF0000
_0808CFAC: .4byte 0x00000A34
_0808CFB0: .4byte 0x00010031
_0808CFB4:
	movs r4, #0
	movs r1, #8
	add r0, sp, #0x10
	strh r1, [r0]
	adds r1, r0, #0
	movs r0, #0x18
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	ldr r3, _0808CFF0 @ =0x00000A34
	adds r0, r5, r3
	adds r1, r5, #0
	adds r1, #0xa0
	ldr r3, _0808CFF4 @ =0x00010031
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	movs r2, #0x68
	bl FUN_0822f3fc
	ldr r3, _0808CFF8 @ =0x00000A95
	adds r0, r5, r3
	strb r4, [r0]
_0808CFE6:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808CFF0: .4byte 0x00000A34
_0808CFF4: .4byte 0x00010031
_0808CFF8: .4byte 0x00000A95

	thumb_func_start FUN_0808cffc
FUN_0808cffc: @ 0x0808CFFC
	push {r4, r5, lr}
	movs r1, #0xaa
	lsls r1, r1, #4
	adds r4, r0, r1
	movs r5, #1
_0808D006:
	adds r0, r4, #0
	bl FUN_0822f1c0
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0808D006
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808d01c
FUN_0808d01c: @ 0x0808D01C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r1, _0808D0AC @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _0808D0B0 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r5, #0
	mov r8, r5
	movs r0, #0xaa
	lsls r0, r0, #4
	adds r4, r6, r0
	movs r7, #0
	ldr r3, _0808D0B4 @ =0x03003584
	mov sb, r3
_0808D04E:
	adds r1, r5, #0
	adds r1, #0xe
	lsls r1, r1, #0x13
	lsrs r1, r1, #0x10
	ldr r2, _0808D0B0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	add r3, sp, #0x10
	str r3, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0x60
	movs r2, #0x73
	ldr r3, _0808D0B8 @ =0x00010031
	bl FUN_0822f3fc
	mov r0, r8
	strh r0, [r4, #0x3a]
	ldr r3, _0808D0BC @ =0x00000AE8
	adds r2, r6, r3
	adds r2, r2, r7
	ldrh r1, [r4, #0x3a]
	lsls r1, r1, #5
	mov r3, sb
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [r2]
	adds r4, #0x60
	adds r7, #0x60
	adds r5, #1
	cmp r5, #1
	ble _0808D04E
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D0AC: .4byte 0x0000FFFF
_0808D0B0: .4byte 0xFFFF0000
_0808D0B4: .4byte 0x03003584
_0808D0B8: .4byte 0x00010031
_0808D0BC: .4byte 0x00000AE8

	thumb_func_start FUN_0808d0c0
FUN_0808d0c0: @ 0x0808D0C0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r5, _0808D174 @ =0x0000C091
	ldr r1, _0808D178 @ =0x0000A413
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x18]
	ldr r1, _0808D17C @ =0x0000A7D7
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x1c]
	ldr r1, _0808D180 @ =0x0000A7E7
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x20]
	ldr r1, _0808D184 @ =0x0000A7F7
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x24]
	ldr r1, _0808D188 @ =0x000083C0
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x2c]
	ldr r1, _0808D18C @ =0x000009FE
	adds r0, r4, r1
	movs r6, #0
	strb r6, [r0]
	ldr r5, _0808D190 @ =0x000092B3
	ldr r1, _0808D194 @ =0x0000EFDA
	adds r0, r5, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x30]
	ldr r1, _0808D198 @ =0x0000ECBF
	adds r0, r5, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x34]
	ldr r1, _0808D19C @ =0x00005F5E
	adds r0, r5, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x38]
	ldr r1, _0808D1A0 @ =0x0000EAA8
	adds r0, r5, #0
	bl GetFile
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4, #0x3c]
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0808a3c4
	ldr r1, _0808D1A4 @ =0x00000A94
	adds r0, r4, r1
	strb r6, [r0]
	subs r1, #0x6a
	adds r0, r4, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_0808cf64
	adds r0, r4, #0
	bl FUN_0808d01c
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808D174: .4byte 0x0000C091
_0808D178: .4byte 0x0000A413
_0808D17C: .4byte 0x0000A7D7
_0808D180: .4byte 0x0000A7E7
_0808D184: .4byte 0x0000A7F7
_0808D188: .4byte 0x000083C0
_0808D18C: .4byte 0x000009FE
_0808D190: .4byte 0x000092B3
_0808D194: .4byte 0x0000EFDA
_0808D198: .4byte 0x0000ECBF
_0808D19C: .4byte 0x00005F5E
_0808D1A0: .4byte 0x0000EAA8
_0808D1A4: .4byte 0x00000A94

	thumb_func_start FUN_0808d1a8
FUN_0808d1a8: @ 0x0808D1A8
	push {lr}
	adds r1, r0, #0
	ldr r2, _0808D1F8 @ =0x00000F3C
	adds r0, r1, r2
	ldrb r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _0808D1D2
	movs r2, #0x1b
	cmp r0, #0x11
	bls _0808D1D2
	movs r2, #0x12
	cmp r0, #0x19
	bls _0808D1D2
	movs r2, #0xa
	cmp r0, #0x21
	bls _0808D1D2
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _0808D1D2
	movs r2, #0x12
_0808D1D2:
	ldr r0, _0808D1F8 @ =0x00000F3C
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x31
	bls _0808D1E8
	movs r0, #0
	strb r0, [r1]
_0808D1E8:
	ldr r0, _0808D1FC @ =0x03004250
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r2, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0808D1F8: .4byte 0x00000F3C
_0808D1FC: .4byte 0x03004250

	thumb_func_start FUN_0808d200
FUN_0808d200: @ 0x0808D200
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	ldr r7, _0808D260 @ =0x085AC064
	movs r6, #0
_0808D20C:
	adds r4, r6, #0
	adds r4, #0x10
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0808a420
	adds r5, r0, #0
	movs r0, #0
	movs r1, #0x1a
	adds r2, r4, #0
	bl FUN_0808a420
	adds r1, r0, #0
	adds r4, r6, #1
	movs r2, #3
_0808D22C:
	ldrh r0, [r7]
	strh r0, [r5]
	adds r5, #2
	ldrh r0, [r7]
	strh r0, [r1]
	adds r1, #2
	adds r7, #2
	subs r2, #1
	cmp r2, #0
	bge _0808D22C
	adds r6, r4, #0
	cmp r6, #3
	ble _0808D20C
	ldr r1, _0808D264 @ =0x00000F3C
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	mov r0, r8
	bl FUN_0808d1a8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D260: .4byte 0x085AC064
_0808D264: .4byte 0x00000F3C

	thumb_func_start FUN_0808d268
FUN_0808d268: @ 0x0808D268
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r7, r0, #0
_0808D272:
	adds r4, r6, #0
	adds r4, #0x10
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0808a420
	adds r5, r0, #0
	movs r0, #0
	movs r1, #0x1a
	adds r2, r4, #0
	bl FUN_0808a420
	adds r4, r6, #1
	movs r1, #3
_0808D290:
	strh r7, [r5]
	adds r5, #2
	strh r7, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0808D290
	adds r6, r4, #0
	cmp r6, #3
	ble _0808D272
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808d2ac
FUN_0808d2ac: @ 0x0808D2AC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
_0808D2B2:
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r5, r0
	bge _0808D304
	movs r0, #0x64
	adds r3, r5, #0
	muls r3, r0, r3
	ldr r0, _0808D2F8 @ =0x00000C14
	adds r2, r4, r0
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r0, r3, r4
	ldr r1, _0808D2FC @ =0x00000C0C
	adds r0, r0, r1
	adds r3, r4, r3
	ldr r2, _0808D300 @ =0x00000C09
	adds r3, r3, r2
	movs r2, #0
	ldrsb r2, [r3, r2]
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	adds r1, #0xa0
	movs r3, #1
	bl Sprite_SetSprite
	b _0808D316
	.align 2, 0
_0808D2F8: .4byte 0x00000C14
_0808D2FC: .4byte 0x00000C0C
_0808D300: .4byte 0x00000C09
_0808D304:
	movs r0, #0x64
	muls r0, r5, r0
	ldr r1, _0808D354 @ =0x00000C14
	adds r2, r4, r1
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0808D316:
	movs r2, #0xf4
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r5, r0
	bge _0808D378
	movs r0, #0x68
	adds r3, r5, #0
	muls r3, r0, r3
	ldr r0, _0808D358 @ =0x00000DAC
	adds r2, r4, r0
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xda
	lsls r1, r1, #4
	adds r0, r4, r1
	adds r0, r0, r3
	ldr r1, [r0]
	cmp r1, #0
	bne _0808D360
	adds r0, r3, r4
	ldr r2, _0808D35C @ =0x00000DA4
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	b _0808D36C
	.align 2, 0
_0808D354: .4byte 0x00000C14
_0808D358: .4byte 0x00000DAC
_0808D35C: .4byte 0x00000DA4
_0808D360:
	adds r0, r3, r4
	ldr r2, _0808D374 @ =0x00000DA4
	adds r0, r0, r2
	ldrb r2, [r1]
	adds r1, r4, #0
	adds r1, #0xa0
_0808D36C:
	movs r3, #1
	bl Sprite_SetSprite
	b _0808D38A
	.align 2, 0
_0808D374: .4byte 0x00000DA4
_0808D378:
	movs r0, #0x68
	muls r0, r5, r0
	ldr r1, _0808D398 @ =0x00000DAC
	adds r2, r4, r1
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0808D38A:
	adds r5, #1
	cmp r5, #3
	ble _0808D2B2
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808D398: .4byte 0x00000DAC

	thumb_func_start FUN_0808d39c
FUN_0808d39c: @ 0x0808D39C
	push {r4, r5, lr}
	movs r3, #1
	ldr r1, _0808D3C8 @ =0x00000C14
	adds r2, r0, r1
	ldr r4, _0808D3CC @ =0x00000DAC
	adds r1, r0, r4
	ldr r5, _0808D3D0 @ =0x00000EE4
	adds r4, r0, r5
_0808D3AC:
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r2, #0x64
	adds r1, #0x68
	cmp r1, r4
	ble _0808D3AC
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808D3C8: .4byte 0x00000C14
_0808D3CC: .4byte 0x00000DAC
_0808D3D0: .4byte 0x00000EE4

	thumb_func_start FUN_0808d3d4
FUN_0808d3d4: @ 0x0808D3D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r3, #0
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r0, r0, r4
	mov sl, r0
	ldr r1, _0808D430 @ =0x00000C02
	adds r1, r1, r4
	mov sb, r1
	ldr r7, _0808D434 @ =0x00000DAC
	adds r6, r4, r7
	movs r0, #2
	rsbs r0, r0, #0
	mov ip, r0
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r1, r1, r4
	mov r8, r1
	ldr r7, _0808D438 @ =0x00000C14
	adds r2, r4, r7
	adds r5, r4, #0
_0808D408:
	mov r0, sl
	ldrb r0, [r0]
	cmp r3, r0
	bge _0808D440
	mov r1, sb
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r3, r0
	bne _0808D440
	ldr r7, _0808D43C @ =0x00000C09
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808D440
	ldr r0, [r2]
	mov r1, ip
	ands r0, r1
	b _0808D446
	.align 2, 0
_0808D430: .4byte 0x00000C02
_0808D434: .4byte 0x00000DAC
_0808D438: .4byte 0x00000C14
_0808D43C: .4byte 0x00000C09
_0808D440:
	ldr r0, [r2]
	movs r7, #1
	orrs r0, r7
_0808D446:
	str r0, [r2]
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	bge _0808D474
	ldr r1, _0808D470 @ =0x00000D98
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r3, r0
	bne _0808D474
	movs r0, #0x68
	adds r1, r3, #0
	muls r1, r0, r1
	adds r1, r6, r1
	ldr r0, [r1]
	mov r7, ip
	ands r0, r7
	b _0808D482
	.align 2, 0
_0808D470: .4byte 0x00000D98
_0808D474:
	movs r0, #0x68
	adds r1, r3, #0
	muls r1, r0, r1
	adds r1, r6, r1
	ldr r0, [r1]
	movs r7, #1
	orrs r0, r7
_0808D482:
	str r0, [r1]
	adds r2, #0x64
	adds r5, #0x64
	adds r3, #1
	cmp r3, #3
	ble _0808D408
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808d49c
FUN_0808d49c: @ 0x0808D49C
	push {r4, r5, lr}
	adds r0, r1, #0
	adds r5, r3, #0
	ldr r4, [sp, #0xc]
	adds r0, r5, r0
	subs r0, r0, r2
	adds r1, r5, #0
	bl Mod
	lsls r2, r4, #1
	adds r2, r2, r4
	movs r3, #0x88
	subs r2, r3, r2
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r2, r2, r1
	subs r1, r5, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	subs r3, r3, r0
	cmp r2, r3
	bge _0808D4D4
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r2, r2, r0
_0808D4D4:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808d4dc
FUN_0808d4dc: @ 0x0808D4DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	movs r6, #0
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0808D554
	adds r7, r4, r1
	mov r8, r6
	ldr r0, _0808D51C @ =0x00000DA4
	adds r5, r4, r0
_0808D4FC:
	movs r1, #0xda
	lsls r1, r1, #4
	adds r0, r4, r1
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	bne _0808D520
	adds r0, r5, #0
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	movs r3, #1
	bl Sprite_SetSprite
	b _0808D52E
	.align 2, 0
_0808D51C: .4byte 0x00000DA4
_0808D520:
	ldrb r2, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r1, #0xa0
	movs r3, #1
	bl Sprite_SetSprite
_0808D52E:
	ldr r1, _0808D560 @ =0x00000D98
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r7]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0808d49c
	strh r0, [r5, #0x22]
	movs r0, #0x68
	add r8, r0
	adds r5, #0x68
	adds r6, #1
	ldrb r1, [r7]
	cmp r6, r1
	blt _0808D4FC
_0808D554:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D560: .4byte 0x00000D98

	thumb_func_start FUN_0808d564
FUN_0808d564: @ 0x0808D564
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r6, #0
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0808D5BC
	adds r7, r5, r1
_0808D57A:
	movs r0, #0x64
	adds r4, r6, #0
	muls r4, r0, r4
	ldr r0, _0808D5C4 @ =0x00000C08
	adds r4, r4, r0
	adds r4, r5, r4
	adds r0, r4, #4
	movs r2, #1
	ldrsb r2, [r4, r2]
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r5, #0
	adds r1, #0xa0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _0808D5C8 @ =0x00000C02
	adds r0, r5, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r7]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0808d49c
	strh r0, [r4, #0x26]
	adds r6, #1
	ldrb r0, [r7]
	cmp r6, r0
	blt _0808D57A
_0808D5BC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D5C4: .4byte 0x00000C08
_0808D5C8: .4byte 0x00000C02

	thumb_func_start FUN_0808d5cc
FUN_0808d5cc: @ 0x0808D5CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r6, #0
	ldr r0, _0808D634 @ =0x00000D98
	adds r2, r7, r0
	movs r0, #0xff
	strb r0, [r2]
	mov sl, r6
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808D6BC
	movs r5, #0
	ldr r0, _0808D638 @ =0x030046A0
	mov sb, r0
_0808D5FE:
	movs r1, #0
	mov ip, r1
	movs r3, #0
	movs r2, #1
	rsbs r2, r2, #0
	mov r8, r2
	mov r1, sb
	ldr r0, [r1]
	lsls r4, r5, #1
	adds r0, r4, r0
	adds r1, r0, #0
	adds r1, #0x60
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _0808D63C
	bl GetWeapon
	adds r3, r0, #0
	mov r1, sb
	ldr r0, [r1]
	adds r0, r4, r0
	adds r0, #0x60
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r8, r2
	b _0808D670
	.align 2, 0
_0808D634: .4byte 0x00000D98
_0808D638: .4byte 0x030046A0
_0808D63C:
	movs r2, #0
	ldr r0, _0808D654 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0808D658
	mov r0, sl
	cmp r0, #0
	bne _0808D65E
	b _0808D662
	.align 2, 0
_0808D654: .4byte 0x030047A4
_0808D658:
	cmp r5, #3
	bne _0808D65E
	movs r2, #1
_0808D65E:
	cmp r2, #0
	beq _0808D66A
_0808D662:
	movs r3, #0
	movs r1, #1
	mov sl, r1
	mov ip, r1
_0808D66A:
	mov r2, ip
	cmp r2, #0
	beq _0808D69A
_0808D670:
	movs r0, #0x68
	muls r0, r6, r0
	ldr r1, _0808D6A4 @ =0x00000D9C
	adds r0, r0, r1
	adds r0, r7, r0
	strb r5, [r0]
	mov r2, r8
	strb r2, [r0, #1]
	str r3, [r0, #4]
	ldr r1, _0808D6A8 @ =0x030046A0
	ldr r0, [r1]
	adds r0, #0x58
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov sb, r1
	cmp r5, r0
	bne _0808D698
	ldr r1, _0808D6AC @ =0x00000D98
	adds r0, r7, r1
	strb r6, [r0]
_0808D698:
	adds r6, #1
_0808D69A:
	adds r5, #1
	cmp r5, #3
	ble _0808D5FE
	b _0808D6D2
	.align 2, 0
_0808D6A4: .4byte 0x00000D9C
_0808D6A8: .4byte 0x030046A0
_0808D6AC: .4byte 0x00000D98
_0808D6B0:
	ldr r3, _0808D6B8 @ =0x00000D98
	adds r0, r7, r3
	strb r2, [r0]
	b _0808D754
	.align 2, 0
_0808D6B8: .4byte 0x00000D98
_0808D6BC:
	ldr r1, _0808D764 @ =0x00000D9C
	adds r0, r7, r1
	movs r1, #3
	strb r1, [r0]
	strb r6, [r0, #1]
	movs r3, #0xff
	lsls r3, r3, #6
	adds r1, r7, r3
	str r1, [r0, #4]
	strb r6, [r2]
	movs r6, #1
_0808D6D2:
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r0, r7, r1
	strb r6, [r0]
	ldr r4, _0808D768 @ =0x030047A4
	cmp r6, #3
	bgt _0808D704
	movs r2, #0xff
	movs r3, #0
	movs r0, #0x68
	muls r0, r6, r0
	ldr r1, _0808D764 @ =0x00000D9C
	adds r0, r0, r1
	adds r1, r0, r7
_0808D6EE:
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r1, #1]
	orrs r0, r2
	strb r0, [r1, #1]
	str r3, [r1, #4]
	adds r1, #0x68
	adds r6, #1
	cmp r6, #3
	ble _0808D6EE
_0808D704:
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0808D754
	ldr r2, _0808D76C @ =0x00000D98
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808D754
	ldr r0, _0808D770 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #3
	strh r1, [r0]
	movs r2, #0
	movs r5, #0
	movs r3, #0xf4
	lsls r3, r3, #4
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r5, r0
	bge _0808D754
	adds r3, r0, #0
	ldr r0, _0808D764 @ =0x00000D9C
	adds r1, r7, r0
_0808D73E:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #3
	beq _0808D6B0
	cmp r0, #0
	blt _0808D74C
	adds r2, #1
_0808D74C:
	adds r1, #0x68
	adds r5, #1
	cmp r5, r3
	blt _0808D73E
_0808D754:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D764: .4byte 0x00000D9C
_0808D768: .4byte 0x030047A4
_0808D76C: .4byte 0x00000D98
_0808D770: .4byte 0x030046A0

	thumb_func_start FUN_0808d774
FUN_0808d774: @ 0x0808D774
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _0808D7E4 @ =0x00000C02
	adds r7, r6, r0
	movs r0, #0xff
	strb r0, [r7]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808D7F4
	ldr r0, _0808D7E8 @ =0x00000C04
	adds r2, r6, r0
	ldr r1, _0808D7EC @ =0x030046A0
	ldr r3, [r1]
	adds r0, r3, #0
	adds r0, #0x5a
	str r0, [r2]
	movs r4, #0
	mov r8, r1
	mov ip, r2
	adds r3, #0x68
	movs r2, #0
_0808D7B2:
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _0808D7D8
	ldr r0, _0808D7F0 @ =0x00000C08
	adds r1, r2, r0
	adds r1, r6, r1
	strb r4, [r1]
	ldrh r0, [r3]
	strb r0, [r1, #1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	bne _0808D7D4
	strb r5, [r7]
_0808D7D4:
	adds r2, #0x64
	adds r5, #1
_0808D7D8:
	adds r3, #2
	adds r4, #1
	cmp r4, #3
	ble _0808D7B2
	b _0808D83E
	.align 2, 0
_0808D7E4: .4byte 0x00000C02
_0808D7E8: .4byte 0x00000C04
_0808D7EC: .4byte 0x030046A0
_0808D7F0: .4byte 0x00000C08
_0808D7F4:
	ldr r0, _0808D818 @ =0x00000C04
	adds r2, r6, r0
	ldr r1, _0808D81C @ =0x030046A0
	ldr r0, [r1]
	adds r0, #0x5e
	str r0, [r2]
	movs r4, #0
	mov r8, r1
	adds r3, r7, #0
	movs r1, #8
	mov ip, r1
	ldr r7, _0808D820 @ =0x00000C08
	adds r1, r6, r7
_0808D80E:
	strb r4, [r1]
	cmp r4, #0
	bne _0808D824
	mov r0, ip
	b _0808D826
	.align 2, 0
_0808D818: .4byte 0x00000C04
_0808D81C: .4byte 0x030046A0
_0808D820: .4byte 0x00000C08
_0808D824:
	movs r0, #9
_0808D826:
	strb r0, [r1, #1]
	ldr r0, [r2]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r4, r0
	bne _0808D834
	strb r5, [r3]
_0808D834:
	adds r1, #0x64
	adds r5, #1
	adds r4, #1
	cmp r4, #1
	ble _0808D80E
_0808D83E:
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r6, r1
	strb r5, [r0]
	cmp r5, #3
	bgt _0808D86A
	movs r2, #0xff
	movs r0, #0x64
	muls r0, r5, r0
	ldr r7, _0808D8E0 @ =0x00000C08
	adds r0, r0, r7
	adds r1, r0, r6
_0808D856:
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r0, [r1, #1]
	orrs r0, r2
	strb r0, [r1, #1]
	adds r1, #0x64
	adds r5, #1
	cmp r5, #3
	ble _0808D856
_0808D86A:
	movs r4, #3
_0808D86C:
	subs r4, #1
	cmp r4, #0
	bge _0808D86C
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808D8F2
	ldr r7, _0808D8E4 @ =0x00000C02
	adds r0, r6, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808D8F2
	movs r4, #1
	ldr r0, _0808D8E8 @ =0x00000C04
	adds r5, r6, r0
	movs r3, #3
_0808D894:
	ldr r2, [r5]
	movs r1, #0
	ldrsh r0, [r2, r1]
	adds r0, r0, r4
	ands r0, r3
	mov r7, r8
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x68
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _0808D8EC
	ldrh r0, [r2]
	adds r0, r0, r4
	ands r0, r3
	strh r0, [r2]
	movs r3, #0
	ldr r7, _0808D8E8 @ =0x00000C04
	adds r5, r6, r7
	ldr r0, _0808D8E4 @ =0x00000C02
	adds r4, r6, r0
	ldr r1, _0808D8E0 @ =0x00000C08
	adds r2, r6, r1
_0808D8C6:
	ldr r0, [r5]
	movs r1, #0
	ldrsb r1, [r2, r1]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r1, r0
	bne _0808D8D6
	strb r3, [r4]
_0808D8D6:
	adds r2, #0x64
	adds r3, #1
	cmp r3, #3
	ble _0808D8C6
	b _0808D8F2
	.align 2, 0
_0808D8E0: .4byte 0x00000C08
_0808D8E4: .4byte 0x00000C02
_0808D8E8: .4byte 0x00000C04
_0808D8EC:
	adds r4, #1
	cmp r4, #3
	ble _0808D894
_0808D8F2:
	ldr r0, _0808D904 @ =0x00000C03
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808D904: .4byte 0x00000C03

	thumb_func_start FUN_0808d908
FUN_0808d908: @ 0x0808D908
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808d200
	adds r0, r4, #0
	bl FUN_0808d2ac
	bl FUN_082408d0
	movs r2, #4
	ldr r1, _0808D934 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0808D938 @ =FUN_0808db68
	adds r0, r4, #0
	bl FUN_0808a33c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808D934: .4byte 0x030044BC
_0808D938: .4byte FUN_0808db68

	thumb_func_start FUN_0808d93c
FUN_0808d93c: @ 0x0808D93C
	push {lr}
	adds r3, r0, #0
	ldr r0, _0808D97C @ =0x00000C02
	adds r1, r3, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0808D984
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808D984
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r3, r2
	ldr r0, [r0]
	movs r2, #0
	ldrsb r2, [r1, r2]
	movs r1, #0x64
	muls r1, r2, r1
	adds r1, r3, r1
	ldr r2, _0808D980 @ =0x00000C09
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	bl FUN_08064fd8
	b _0808D994
	.align 2, 0
_0808D97C: .4byte 0x00000C02
_0808D980: .4byte 0x00000C09
_0808D984:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	bl FUN_08064fd8
_0808D994:
	pop {r0}
	bx r0

	thumb_func_start FUN_0808d998
FUN_0808d998: @ 0x0808D998
	push {lr}
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r2, _0808D9C4 @ =0x00000D98
	adds r1, r0, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	movs r1, #0x68
	muls r1, r2, r1
	movs r2, #0xda
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r3, #0
	bl weapon_08064664
	pop {r0}
	bx r0
	.align 2, 0
_0808D9C4: .4byte 0x00000D98

	thumb_func_start FUN_0808d9c8
FUN_0808d9c8: @ 0x0808D9C8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808d268
	adds r0, r4, #0
	bl FUN_0808d998
	adds r0, r4, #0
	bl FUN_0808d93c
	ldr r0, _0808DA08 @ =0x00000C03
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808d3d4
	bl FUN_082408f4
	ldr r2, _0808DA0C @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808DA10 @ =FUN_0808cf14
	adds r0, r4, #0
	bl FUN_0808a33c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808DA08: .4byte 0x00000C03
_0808DA0C: .4byte 0x030044BC
_0808DA10: .4byte FUN_0808cf14

	thumb_func_start FUN_0808da14
FUN_0808da14: @ 0x0808DA14
	push {lr}
	adds r2, r0, #0
	ldr r0, _0808DA68 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0808DA80
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808DA80
	ldr r1, [r0, #0x1c]
	cmp r1, #1
	bne _0808DA80
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0808DA80
	ldr r1, _0808DA6C @ =0x00000F3D
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808DA80
	ldr r1, _0808DA70 @ =0x000009FE
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0808DA80
	ldr r2, _0808DA74 @ =0x00000201
	ldr r0, _0808DA78 @ =0x030047A4
	ldr r1, _0808DA7C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _0808DA80
	movs r0, #1
	b _0808DA82
	.align 2, 0
_0808DA68: .4byte 0x030044E0
_0808DA6C: .4byte 0x00000F3D
_0808DA70: .4byte 0x000009FE
_0808DA74: .4byte 0x00000201
_0808DA78: .4byte 0x030047A4
_0808DA7C: .4byte 0x030047A0
_0808DA80:
	movs r0, #0
_0808DA82:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808da88
FUN_0808da88: @ 0x0808DA88
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808da14
	cmp r0, #0
	bne _0808DA98
	movs r0, #0
	b _0808DAA0
_0808DA98:
	adds r0, r4, #0
	bl FUN_0808d908
	movs r0, #1
_0808DAA0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808daa8
FUN_0808daa8: @ 0x0808DAA8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0808DB50 @ =0x00000C01
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808DAFA
	subs r0, #1
	strb r0, [r1]
	movs r5, #0
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r5, r2
	bge _0808DAFA
	adds r6, r0, #0
_0808DACC:
	ldr r1, _0808DB54 @ =0x00000C02
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r6]
	subs r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0808d49c
	movs r1, #0x64
	muls r1, r5, r1
	adds r1, r4, r1
	ldr r2, _0808DB58 @ =0x00000C2E
	adds r1, r1, r2
	strh r0, [r1]
	adds r5, #1
	ldrb r0, [r6]
	cmp r5, r0
	blt _0808DACC
_0808DAFA:
	ldr r2, _0808DB5C @ =0x00000F41
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0808DB46
	subs r0, #1
	strb r0, [r1]
	movs r5, #0
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r2, [r0]
	cmp r5, r2
	bge _0808DB46
	adds r6, r0, #0
_0808DB18:
	ldr r1, _0808DB60 @ =0x00000D98
	adds r0, r4, r1
	movs r2, #0
	ldrsb r2, [r0, r2]
	ldrb r3, [r6]
	ldr r1, _0808DB5C @ =0x00000F41
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0808d49c
	movs r1, #0x68
	muls r1, r5, r1
	adds r1, r4, r1
	ldr r2, _0808DB64 @ =0x00000DC6
	adds r1, r1, r2
	strh r0, [r1]
	adds r5, #1
	ldrb r0, [r6]
	cmp r5, r0
	blt _0808DB18
_0808DB46:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808DB50: .4byte 0x00000C01
_0808DB54: .4byte 0x00000C02
_0808DB58: .4byte 0x00000C2E
_0808DB5C: .4byte 0x00000F41
_0808DB60: .4byte 0x00000D98
_0808DB64: .4byte 0x00000DC6

	thumb_func_start FUN_0808db68
FUN_0808db68: @ 0x0808DB68
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a5b0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a5e0
	ldr r0, _0808DBAC @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0808DBB8
	ldr r1, _0808DBB0 @ =0x00000C01
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808DBB8
	ldr r2, _0808DBB4 @ =0x00000F41
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808DBB8
	adds r0, r4, #0
	bl FUN_0808d9c8
	b _0808DCA4
	.align 2, 0
_0808DBAC: .4byte 0x030044E0
_0808DBB0: .4byte 0x00000C01
_0808DBB4: .4byte 0x00000F41
_0808DBB8:
	ldr r0, _0808DBF8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808DC42
	ldr r0, _0808DBFC @ =0x00000C01
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0808DC42
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r6, r4, r1
	ldrb r0, [r6]
	cmp r0, #1
	bls _0808DC42
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r1, _0808DC00 @ =0x00000285
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r5, #0
	beq _0808DC04
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0808DC42
	.align 2, 0
_0808DBF8: .4byte 0x030044E0
_0808DBFC: .4byte 0x00000C01
_0808DC00: .4byte 0x00000285
_0808DC04:
	ldr r0, _0808DCB8 @ =0x0000010B
	bl PlaySound_082406e0
	ldr r2, _0808DCBC @ =0x00000C02
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r6, [r6]
	cmp r0, r6
	blt _0808DC20
	strb r5, [r1]
_0808DC20:
	ldr r2, _0808DCC0 @ =0x00000C04
	adds r0, r4, r2
	ldr r2, [r0]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r4, r0
	ldr r1, _0808DCC4 @ =0x00000C08
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r2]
	movs r0, #8
	strb r0, [r7]
_0808DC42:
	ldr r0, _0808DCC8 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808DCA4
	ldr r2, _0808DCCC @ =0x00000F41
	adds r7, r4, r2
	ldrb r6, [r7]
	cmp r6, #0
	bne _0808DCA4
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #1
	bls _0808DCA4
	ldr r0, _0808DCB8 @ =0x0000010B
	bl PlaySound_082406e0
	ldr r1, _0808DCD0 @ =0x00000D98
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r5, [r5]
	cmp r0, r5
	blt _0808DC82
	strb r6, [r2]
_0808DC82:
	ldr r0, _0808DCD4 @ =0x030046A0
	ldr r1, [r0]
	adds r1, #0x58
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r0, #0x68
	muls r0, r2, r0
	adds r0, r4, r0
	ldr r2, _0808DCD8 @ =0x00000D9C
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	movs r0, #8
	strb r0, [r7]
_0808DCA4:
	adds r0, r4, #0
	bl FUN_0808daa8
	adds r0, r4, #0
	bl FUN_0808d1a8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DCB8: .4byte 0x0000010B
_0808DCBC: .4byte 0x00000C02
_0808DCC0: .4byte 0x00000C04
_0808DCC4: .4byte 0x00000C08
_0808DCC8: .4byte 0x030044E0
_0808DCCC: .4byte 0x00000F41
_0808DCD0: .4byte 0x00000D98
_0808DCD4: .4byte 0x030046A0
_0808DCD8: .4byte 0x00000D9C

	thumb_func_start FUN_0808dcdc
FUN_0808dcdc: @ 0x0808DCDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	ldr r2, _0808DD90 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #8
	orrs r0, r1
	ldr r4, _0808DD94 @ =0x0000FFFF
	ands r0, r4
	movs r3, #0x88
	lsls r3, r3, #0x10
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r2
	movs r1, #0xd8
	orrs r0, r1
	ands r0, r4
	orrs r0, r3
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r5, #0
	mov r7, r8
	adds r7, #0xa0
	ldr r0, _0808DD98 @ =0x00010011
	mov sl, r0
	movs r6, #0
	movs r1, #0x3c
	mov sb, r1
_0808DD2C:
	movs r0, #0x64
	adds r4, r5, #0
	muls r4, r0, r4
	add r4, r8
	ldr r0, _0808DD9C @ =0x00000C0C
	adds r4, r4, r0
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0xb6
	mov r3, sl
	bl FUN_0822f3fc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808ba0c
	movs r0, #0x68
	muls r0, r5, r0
	add r0, r8
	ldr r1, _0808DDA0 @ =0x00000DA4
	adds r0, r0, r1
	str r6, [sp]
	str r6, [sp, #4]
	mov r1, sb
	str r1, [sp, #8]
	add r1, sp, #0x18
	str r1, [sp, #0xc]
	adds r1, r7, #0
	movs r2, #1
	mov r3, sl
	bl FUN_0822f3fc
	adds r5, #1
	cmp r5, #3
	ble _0808DD2C
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DD90: .4byte 0xFFFF0000
_0808DD94: .4byte 0x0000FFFF
_0808DD98: .4byte 0x00010011
_0808DD9C: .4byte 0x00000C0C
_0808DDA0: .4byte 0x00000DA4

	thumb_func_start FUN_0808dda4
FUN_0808dda4: @ 0x0808DDA4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0808DDAA:
	movs r0, #0x64
	muls r0, r4, r0
	adds r0, r0, r5
	ldr r1, _0808DDD4 @ =0x00000C0C
	adds r0, r0, r1
	bl FUN_0822f1c0
	movs r0, #0x68
	muls r0, r4, r0
	adds r0, r0, r5
	ldr r1, _0808DDD8 @ =0x00000DA4
	adds r0, r0, r1
	bl FUN_0822f1c0
	adds r4, #1
	cmp r4, #3
	ble _0808DDAA
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808DDD4: .4byte 0x00000C0C
_0808DDD8: .4byte 0x00000DA4

	thumb_func_start FUN_0808dddc
FUN_0808dddc: @ 0x0808DDDC
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808dcdc
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808DE2A
	adds r0, r4, #0
	bl FUN_0808d5cc
	adds r0, r4, #0
	bl FUN_0808d774
	adds r0, r4, #0
	bl FUN_0808d4dc
	adds r0, r4, #0
	bl FUN_0808d564
	ldr r0, _0808DE20 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0808DE24
	adds r0, r4, #0
	bl FUN_0808d39c
	b _0808DE2A
	.align 2, 0
_0808DE20: .4byte 0x030047A4
_0808DE24:
	adds r0, r4, #0
	bl FUN_0808d3d4
_0808DE2A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808de30
FUN_0808de30: @ 0x0808DE30
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808d5cc
	adds r0, r4, #0
	bl FUN_0808d4dc
	adds r0, r4, #0
	bl FUN_0808d3d4
	adds r0, r4, #0
	bl FUN_0808d998
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808de50
FUN_0808de50: @ 0x0808DE50
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808d774
	adds r0, r4, #0
	bl FUN_0808d564
	adds r0, r4, #0
	bl FUN_0808d3d4
	adds r0, r4, #0
	bl FUN_0808d93c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808de70
FUN_0808de70: @ 0x0808DE70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r2, _0808DF54 @ =0x030044E0
	ldrh r1, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _0808DEDC
	ldr r0, _0808DF58 @ =0x00000C01
	adds r7, r4, r0
	ldrb r6, [r7]
	cmp r6, #0
	bne _0808DEDC
	movs r1, #0xc0
	lsls r1, r1, #4
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #1
	bls _0808DEDC
	ldr r0, _0808DF5C @ =0x0000010B
	bl PlaySound_082406e0
	ldr r2, _0808DF60 @ =0x00000C02
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r5, [r5]
	cmp r0, r5
	blt _0808DEBA
	strb r6, [r1]
_0808DEBA:
	ldr r2, _0808DF64 @ =0x00000C04
	adds r0, r4, r2
	ldr r2, [r0]
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r4, r0
	ldr r1, _0808DF68 @ =0x00000C08
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r2]
	movs r0, #8
	strb r0, [r7]
_0808DEDC:
	mov r2, r8
	ldrh r1, [r2, #2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808DF3E
	ldr r0, _0808DF6C @ =0x00000F41
	adds r7, r4, r0
	ldrb r6, [r7]
	cmp r6, #0
	bne _0808DF3E
	movs r1, #0xf4
	lsls r1, r1, #4
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #1
	bls _0808DF3E
	ldr r0, _0808DF5C @ =0x0000010B
	bl PlaySound_082406e0
	ldr r0, _0808DF70 @ =0x00000D98
	adds r2, r4, r0
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrb r5, [r5]
	cmp r0, r5
	blt _0808DF1C
	strb r6, [r2]
_0808DF1C:
	ldr r0, _0808DF74 @ =0x030046A0
	ldr r1, [r0]
	adds r1, #0x58
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r0, #0x68
	muls r0, r2, r0
	adds r0, r4, r0
	ldr r2, _0808DF78 @ =0x00000D9C
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r1]
	movs r0, #8
	strb r0, [r7]
_0808DF3E:
	adds r0, r4, #0
	bl FUN_0808daa8
	adds r0, r4, #0
	bl FUN_0808d1a8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808DF54: .4byte 0x030044E0
_0808DF58: .4byte 0x00000C01
_0808DF5C: .4byte 0x0000010B
_0808DF60: .4byte 0x00000C02
_0808DF64: .4byte 0x00000C04
_0808DF68: .4byte 0x00000C08
_0808DF6C: .4byte 0x00000F41
_0808DF70: .4byte 0x00000D98
_0808DF74: .4byte 0x030046A0
_0808DF78: .4byte 0x00000D9C

	thumb_func_start FUN_0808df7c
FUN_0808df7c: @ 0x0808DF7C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0808d39c
	ldr r0, _0808DFC0 @ =0x00000D98
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	movs r3, #0x68
	muls r0, r3, r0
	ldr r2, _0808DFC4 @ =0x00000DAC
	adds r1, r4, r2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	movs r0, #0
	ldrsb r0, [r5, r0]
	muls r0, r3, r0
	adds r0, r0, r4
	ldr r1, _0808DFC8 @ =0x00000DA4
	adds r0, r0, r1
	adds r4, #0xa0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl Sprite_SetSprite
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808DFC0: .4byte 0x00000D98
_0808DFC4: .4byte 0x00000DAC
_0808DFC8: .4byte 0x00000DA4

	thumb_func_start FUN_0808dfcc
FUN_0808dfcc: @ 0x0808DFCC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808E000 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808DFF8
	ldr r1, _0808E004 @ =0x000009FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0808DFF8
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	adds r0, r4, #0
	bl FUN_0808daa8
_0808DFF8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E000: .4byte 0x030044BC
_0808E004: .4byte 0x000009FE

	thumb_func_start FUN_0808e008
FUN_0808e008: @ 0x0808E008
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808E040 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808E0D6
	ldr r1, _0808E044 @ =0x000009FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	bhi _0808E0D6
	adds r0, r4, #0
	bl FUN_0808de70
	ldr r2, _0808E048 @ =0x00000A16
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0x3f
	bhi _0808E04C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a610
	b _0808E058
	.align 2, 0
_0808E040: .4byte 0x030044BC
_0808E044: .4byte 0x000009FE
_0808E048: .4byte 0x00000A16
_0808E04C:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808a5b0
_0808E058:
	ldr r0, _0808E084 @ =0x00000A16
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _0808E06E
	movs r0, #0
	strh r0, [r1]
_0808E06E:
	ldr r0, _0808E088 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0808E090
	ldr r1, _0808E08C @ =FUN_0808dfcc
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808E0D6
	.align 2, 0
_0808E084: .4byte 0x00000A16
_0808E088: .4byte 0x030044E0
_0808E08C: .4byte FUN_0808dfcc
_0808E090:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0808E0D6
	bl FUN_08050dac
	ldr r2, _0808E0BC @ =0x000009F9
	adds r1, r4, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0808E0C4
	ldr r1, _0808E0C0 @ =0x00000A34
	adds r0, r4, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0x46
	movs r3, #1
	bl Sprite_SetSprite
	b _0808E0D6
	.align 2, 0
_0808E0BC: .4byte 0x000009F9
_0808E0C0: .4byte 0x00000A34
_0808E0C4:
	ldr r1, _0808E0DC @ =0x00000A34
	adds r0, r4, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0x47
	movs r3, #1
	bl Sprite_SetSprite
_0808E0D6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E0DC: .4byte 0x00000A34

	thumb_func_start FUN_0808e0e0
FUN_0808e0e0: @ 0x0808E0E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [sp, #8]
	movs r0, #0
	mov r8, r0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0808a420
	adds r4, r0, #0
	movs r6, #0
	ldr r1, _0808E13C @ =0xFFFFD000
	adds r7, r1, #0
	mov r5, sp
_0808E128:
	ldr r0, [r5]
	cmp r0, #0
	ble _0808E140
	movs r1, #1
	mov r8, r1
	movs r1, #0
	bl FUN_0808a440
	orrs r0, r7
	b _0808E15A
	.align 2, 0
_0808E13C: .4byte 0xFFFFD000
_0808E140:
	mov r1, r8
	cmp r1, #0
	bne _0808E14A
	cmp r6, #2
	bne _0808E154
_0808E14A:
	movs r1, #0
	bl FUN_0808a440
	orrs r0, r7
	b _0808E15A
_0808E154:
	movs r1, #0xd0
	lsls r1, r1, #8
	adds r0, r1, #0
_0808E15A:
	strh r0, [r4]
	adds r4, #2
	adds r5, #4
	adds r6, #1
	cmp r6, #2
	ble _0808E128
	ldr r1, _0808E178 @ =0x0000D07B
	adds r0, r1, #0
	strh r0, [r4]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E178: .4byte 0x0000D07B

	thumb_func_start FUN_0808e17c
FUN_0808e17c: @ 0x0808E17C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x13
	movs r2, #3
	bl FUN_0808a420
	ldr r2, _0808E1B4 @ =0x0000D04D
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #2
	adds r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	adds r2, #0xd
	adds r1, r2, #0
	strh r1, [r0, #2]
	bl FUN_08050d64
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #3
	bl FUN_0808e0e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E1B4: .4byte 0x0000D04D

	thumb_func_start FUN_0808e1b8
FUN_0808e1b8: @ 0x0808E1B8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	movs r1, #0x14
	movs r2, #4
	bl FUN_0808a420
	ldr r2, _0808E1F0 @ =0x0000D00F
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #2
	adds r2, #1
	adds r1, r2, #0
	strh r1, [r0]
	adds r2, #0x4b
	adds r1, r2, #0
	strh r1, [r0, #2]
	bl FUN_08050d7c
	adds r3, r0, #0
	adds r0, r4, #0
	movs r1, #0x17
	movs r2, #4
	bl FUN_0808e0e0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E1F0: .4byte 0x0000D00F

	thumb_func_start FUN_0808e1f4
FUN_0808e1f4: @ 0x0808E1F4
	push {r4, r5, lr}
	movs r4, #0
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r5, r0, #0
_0808E1FE:
	adds r2, r4, #0
	adds r2, #0x11
	movs r0, #0
	movs r1, #9
	bl FUN_0808a420
	adds r2, r4, #1
	movs r1, #0xb
_0808E20E:
	strh r5, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0808E20E
	adds r4, r2, #0
	cmp r4, #1
	ble _0808E1FE
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808e224
FUN_0808e224: @ 0x0808E224
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r6, r4, r0
	ldr r0, [r6]
	cmp r0, #0
	bne _0808E236
	b _0808E3F0
_0808E236:
	ldr r1, _0808E2C8 @ =0x000009FE
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #2
	bls _0808E242
	b _0808E3F0
_0808E242:
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
	bl FUN_0808e1f4
	adds r0, r4, #0
	bl FUN_0808afac
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_0808abec
	adds r0, r4, #0
	bl FUN_0808b1bc
	adds r0, r4, #0
	bl FUN_0808e17c
	adds r0, r4, #0
	bl FUN_0808e1b8
	ldr r1, [r6]
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _0808E294
	b _0808E3F0
_0808E294:
	ldr r3, _0808E2CC @ =0x00000282
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808E334
	ldr r1, _0808E2D0 @ =0x00000C03
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808E2DC
	ldr r2, _0808E2D4 @ =0x00000C02
	adds r0, r4, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r3, _0808E2D8 @ =0x00000C0C
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc8
	movs r3, #1
	bl Sprite_SetSprite
	b _0808E310
	.align 2, 0
_0808E2C8: .4byte 0x000009FE
_0808E2CC: .4byte 0x00000282
_0808E2D0: .4byte 0x00000C03
_0808E2D4: .4byte 0x00000C02
_0808E2D8: .4byte 0x00000C0C
_0808E2DC:
	cmp r0, #0x1e
	bne _0808E310
	ldr r1, _0808E328 @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r3, _0808E32C @ =0x00000C0C
	adds r0, r0, r3
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	subs r3, #3
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
_0808E310:
	ldr r0, _0808E330 @ =0x00000C03
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0808E3F0
	movs r0, #0
	strb r0, [r1]
	b _0808E3F0
	.align 2, 0
_0808E328: .4byte 0x00000C02
_0808E32C: .4byte 0x00000C0C
_0808E330: .4byte 0x00000C03
_0808E334:
	ldr r2, _0808E384 @ =0x00000283
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808E3C0
	ldr r3, _0808E388 @ =0x000009EE
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _0808E38C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808E398
	ldr r3, _0808E390 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808E394 @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _0808E3B0
	.align 2, 0
_0808E384: .4byte 0x00000283
_0808E388: .4byte 0x000009EE
_0808E38C: .4byte 0x0000FFFF
_0808E390: .4byte 0x00000C02
_0808E394: .4byte 0x00000C0C
_0808E398:
	ldr r1, _0808E3B8 @ =0x00000C02
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	muls r0, r1, r0
	adds r0, r0, r4
	ldr r2, _0808E3BC @ =0x00000C0C
	adds r0, r0, r2
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0xc9
_0808E3B0:
	movs r3, #1
	bl Sprite_SetSprite
	b _0808E3F0
	.align 2, 0
_0808E3B8: .4byte 0x00000C02
_0808E3BC: .4byte 0x00000C0C
_0808E3C0:
	ldr r3, _0808E3F8 @ =0x00000C02
	adds r0, r4, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r0, #0x64
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, r4
	ldr r1, _0808E3FC @ =0x00000C0C
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0xa0
	adds r2, r4, r2
	adds r3, #7
	adds r2, r2, r3
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0xb6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #1
	bl Sprite_SetSprite
_0808E3F0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808E3F8: .4byte 0x00000C02
_0808E3FC: .4byte 0x00000C0C

	thumb_func_start FUN_0808e400
FUN_0808e400: @ 0x0808E400
	push {lr}
	adds r2, r0, #0
	ldr r0, _0808E41C @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0808E416
	adds r0, r2, #0
	bl FUN_0808e224
_0808E416:
	pop {r0}
	bx r0
	.align 2, 0
_0808E41C: .4byte 0x030044BC

	thumb_func_start FUN_0808e420
FUN_0808e420: @ 0x0808E420
	push {r4, r5, lr}
	ldr r0, _0808E474 @ =0x0300013C
	ldr r5, [r0]
	cmp r5, #0
	beq _0808E4D8
	adds r0, r5, #0
	bl FUN_0808d200
	adds r0, r5, #0
	bl FUN_0808d5cc
	adds r0, r5, #0
	bl FUN_0808d4dc
	adds r0, r5, #0
	bl FUN_0808d774
	adds r0, r5, #0
	bl FUN_0808d564
	adds r0, r5, #0
	bl FUN_0808d2ac
	ldr r1, _0808E478 @ =0x000009F9
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	bl FUN_08050d94
	cmp r0, #0
	beq _0808E4A0
	bl FUN_08050de8
	cmp r0, #0
	bne _0808E480
	ldr r2, _0808E47C @ =0x00000A3C
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0808E4A0
	.align 2, 0
_0808E474: .4byte 0x0300013C
_0808E478: .4byte 0x000009F9
_0808E47C: .4byte 0x00000A3C
_0808E480:
	ldr r0, _0808E4E0 @ =0x00000A3C
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808E4E4 @ =0x00000A34
	adds r0, r5, r1
	movs r2, #0xb0
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r2, #0x47
	movs r3, #1
	bl Sprite_SetSprite
_0808E4A0:
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r2, _0808E4E8 @ =0x0000036A
	adds r1, r0, r2
	ldrh r1, [r1]
	subs r2, #2
	adds r0, r0, r2
	movs r4, #0
	strh r1, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #3
	movs r3, #2
	bl FUN_0808a768
	movs r0, #0x86
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r1, _0808E4EC @ =0x00000A16
	adds r0, r5, r1
	strh r4, [r0]
	ldr r1, _0808E4F0 @ =FUN_0808e008
	adds r0, r5, #0
	bl FUN_0808a33c
_0808E4D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808E4E0: .4byte 0x00000A3C
_0808E4E4: .4byte 0x00000A34
_0808E4E8: .4byte 0x0000036A
_0808E4EC: .4byte 0x00000A16
_0808E4F0: .4byte FUN_0808e008

	thumb_func_start FUN_0808e4f4
FUN_0808e4f4: @ 0x0808E4F4
	push {r4, lr}
	ldr r0, _0808E530 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	beq _0808E528
	bl FUN_0808d268
	ldr r0, _0808E534 @ =0x00000A3C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0808d998
	adds r0, r4, #0
	bl FUN_0808d93c
	adds r0, r4, #0
	bl FUN_0808d3d4
	ldr r1, _0808E538 @ =FUN_0808e400
	adds r0, r4, #0
	bl FUN_0808a33c
_0808E528:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E530: .4byte 0x0300013C
_0808E534: .4byte 0x00000A3C
_0808E538: .4byte FUN_0808e400

	thumb_func_start FUN_0808e53c
FUN_0808e53c: @ 0x0808E53C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r3, #2
	rsbs r3, r3, #0
	ldr r0, _0808E594 @ =0x0000366C
	adds r1, r5, r0
	movs r2, #2
_0808E54A:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0808E54A
	ldr r1, _0808E598 @ =0x00003664
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xc0
	ldr r2, _0808E59C @ =0x0000401E
	adds r1, r5, r2
	ldrb r2, [r1]
	adds r2, #7
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _0808E5A0 @ =0x000036C4
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #8
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _0808E5A4 @ =0x00003724
	adds r0, r5, r2
	adds r1, r4, #0
	movs r2, #8
	movs r3, #1
	bl Sprite_SetSprite
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808E594: .4byte 0x0000366C
_0808E598: .4byte 0x00003664
_0808E59C: .4byte 0x0000401E
_0808E5A0: .4byte 0x000036C4
_0808E5A4: .4byte 0x00003724

	thumb_func_start FUN_0808e5a8
FUN_0808e5a8: @ 0x0808E5A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r1, _0808E5D4 @ =0x00004022
	adds r0, r7, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _0808E5D8
	movs r2, #0xc0
	adds r2, r2, r7
	mov sl, r2
	movs r1, #0
	add r0, sp, #0xc
_0808E5CA:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _0808E5CA
	b _0808E61A
	.align 2, 0
_0808E5D4: .4byte 0x00004022
_0808E5D8:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	subs r1, r4, r1
	str r1, [sp, #0xc]
	movs r0, #0xc0
	adds r0, r0, r7
	mov sl, r0
_0808E61A:
	mov sb, sp
	ldr r1, _0808E688 @ =0x00003784
	adds r4, r7, r1
	ldr r6, _0808E68C @ =0x00002820
	movs r5, #3
_0808E624:
	ldr r2, _0808E690 @ =0x00000F6C
	adds r1, r7, r2
	adds r1, r1, r6
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	mov r8, r2
	ands r0, r2
	str r0, [r1]
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sl
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0808E624
	ldr r2, _0808E694 @ =0x0000390C
	adds r1, r7, r2
	ldr r0, [r1]
	mov r2, r8
	ands r0, r2
	str r0, [r1]
	ldr r1, _0808E698 @ =0x00004022
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _0808E69C @ =0x0000401E
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r4, r1, #0
	muls r4, r0, r4
	cmp r4, #0
	bne _0808E6A0
	movs r1, #0
	add r0, sp, #0xc
_0808E67E:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _0808E67E
	b _0808E6DC
	.align 2, 0
_0808E688: .4byte 0x00003784
_0808E68C: .4byte 0x00002820
_0808E690: .4byte 0x00000F6C
_0808E694: .4byte 0x0000390C
_0808E698: .4byte 0x00004022
_0808E69C: .4byte 0x0000401E
_0808E6A0:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	subs r1, r4, r1
	str r1, [sp, #0xc]
_0808E6DC:
	mov r8, sp
	ldr r0, _0808E72C @ =0x00003964
	adds r4, r7, r0
	movs r6, #0xa8
	lsls r6, r6, #6
	movs r5, #3
_0808E6E8:
	ldr r1, _0808E730 @ =0x00000F6C
	adds r2, r7, r1
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r0, r8
	adds r0, #4
	mov r8, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, #8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, sl
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0808E6E8
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E72C: .4byte 0x00003964
_0808E730: .4byte 0x00000F6C

	thumb_func_start FUN_0808e734
FUN_0808e734: @ 0x0808E734
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _0808E820 @ =0xFFFF0000
	ands r0, r5
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _0808E824 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xe
	adds r5, r0, #0
	orrs r5, r1
	ldr r0, _0808E828 @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r2, _0808E82C @ =0x00004022
	adds r0, r7, r2
	ldrh r2, [r0]
	ldr r3, _0808E830 @ =0x0000401E
	adds r0, r7, r3
	ldrb r0, [r0]
	muls r0, r2, r0
	ldr r4, [r1]
	adds r4, r4, r0
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
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
	mov sl, sp
	ldr r0, _0808E834 @ =0x00002164
	adds r4, r7, r0
	movs r2, #0x90
	lsls r2, r2, #5
	mov sb, r2
	movs r3, #3
	mov r8, r3
_0808E7BE:
	ldr r0, _0808E838 @ =0x00000F6C
	adds r2, r7, r0
	add r2, sb
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	str r5, [r4, #0x20]
	str r6, [r4, #0x24]
	mov r3, sl
	adds r3, #4
	mov sl, r3
	subs r3, #4
	ldm r3!, {r2}
	adds r2, #0x14
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r7, #0
	adds r1, #0x60
	movs r3, #1
	bl Sprite_SetSprite
	adds r1, r5, #0
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0808E820 @ =0xFFFF0000
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	adds r4, #0x60
	movs r0, #0x60
	add sb, r0
	movs r2, #1
	rsbs r2, r2, #0
	add r8, r2
	mov r3, r8
	cmp r3, #0
	bge _0808E7BE
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808E820: .4byte 0xFFFF0000
_0808E824: .4byte 0x0000FFFF
_0808E828: .4byte 0x030046A0
_0808E82C: .4byte 0x00004022
_0808E830: .4byte 0x0000401E
_0808E834: .4byte 0x00002164
_0808E838: .4byte 0x00000F6C

	thumb_func_start FUN_0808e83c
FUN_0808e83c: @ 0x0808E83C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r2, [r0]
	ldr r3, _0808E868 @ =0x00004022
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r2, r2, r0
	ldr r0, _0808E86C @ =0x0000036A
	adds r1, r1, r0
	ldrh r3, [r1]
	cmp r2, #0
	bne _0808E870
	movs r3, #0
	b _0808E882
	.align 2, 0
_0808E868: .4byte 0x00004022
_0808E86C: .4byte 0x0000036A
_0808E870:
	subs r1, r2, #1
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	subs r1, r3, #1
	bl Div
	adds r3, r0, #1
_0808E882:
	ldr r1, _0808E8A8 @ =0x000028EC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	adds r1, r3, #0
	subs r1, #0x98
	ldr r2, _0808E8AC @ =0x00002904
	adds r0, r4, r2
	strh r1, [r0]
	ldr r3, _0808E8B0 @ =0x00002906
	adds r1, r4, r3
	ldr r0, _0808E8B4 @ =0x0000FFD8
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808E8A8: .4byte 0x000028EC
_0808E8AC: .4byte 0x00002904
_0808E8B0: .4byte 0x00002906
_0808E8B4: .4byte 0x0000FFD8

	thumb_func_start FUN_0808e8b8
FUN_0808e8b8: @ 0x0808E8B8
	push {lr}
	asrs r0, r0, #2
	cmp r0, #1
	beq _0808E8D2
	cmp r0, #1
	ble _0808E8D6
	cmp r0, #2
	beq _0808E8CE
	cmp r0, #3
	beq _0808E8D2
	b _0808E8D6
_0808E8CE:
	movs r0, #2
	b _0808E8D8
_0808E8D2:
	movs r0, #1
	b _0808E8D8
_0808E8D6:
	movs r0, #0
_0808E8D8:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808e8dc
FUN_0808e8dc: @ 0x0808E8DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _0808E968 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808E984
	ldr r0, _0808E96C @ =0x030046A0
	ldr r1, [r0]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r2, _0808E970 @ =0x00004022
	adds r5, r6, r2
	ldrh r3, [r5]
	adds r4, r3, #1
	subs r2, #4
	adds r0, r6, r2
	ldrb r0, [r0]
	adds r2, r4, #0
	muls r2, r0, r2
	ldr r0, [r1]
	adds r0, r0, r2
	ldr r1, _0808E974 @ =0x0000270F
	cmp r0, r1
	bgt _0808E984
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	adds r0, r0, r3
	adds r2, #2
	adds r1, r1, r2
	ldrh r1, [r1]
	cmp r0, r1
	bge _0808E984
	strh r4, [r5]
	ldr r0, _0808E978 @ =0x0000037D
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_0808e83c
	adds r0, r6, #0
	bl FUN_0808e734
	adds r0, r6, #0
	bl FUN_0808e5a8
	ldr r0, _0808E97C @ =0x00004020
	adds r4, r6, r0
	movs r0, #0x13
	strb r0, [r4]
	ldr r1, _0808E980 @ =0x00004021
	adds r5, r6, r1
	ldrb r0, [r5]
	bl FUN_0808e8b8
	adds r7, r0, #0
	ldrb r0, [r4]
	adds r3, r0, r7
	b _0808E9DC
	.align 2, 0
_0808E968: .4byte 0x030044E0
_0808E96C: .4byte 0x030046A0
_0808E970: .4byte 0x00004022
_0808E974: .4byte 0x0000270F
_0808E978: .4byte 0x0000037D
_0808E97C: .4byte 0x00004020
_0808E980: .4byte 0x00004021
_0808E984:
	ldr r0, _0808E9F0 @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808EA08
	ldr r2, _0808E9F4 @ =0x00004022
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808EA08
	subs r0, #1
	strh r0, [r1]
	ldr r0, _0808E9F8 @ =0x0000037D
	bl PlaySound_082406e0
	adds r0, r6, #0
	bl FUN_0808e83c
	adds r0, r6, #0
	bl FUN_0808e734
	adds r0, r6, #0
	bl FUN_0808e5a8
	ldr r0, _0808E9FC @ =0x00004020
	adds r4, r6, r0
	movs r0, #0x16
	strb r0, [r4]
	ldr r1, _0808EA00 @ =0x00004021
	adds r5, r6, r1
	ldrb r0, [r5]
	bl FUN_0808e8b8
	adds r7, r0, #0
	ldrb r0, [r4]
	adds r3, r0, r7
	ldr r2, _0808EA04 @ =0x00004024
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808E9DC
	movs r0, #1
	strh r0, [r1]
_0808E9DC:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0808EA40
	movs r0, #0
	strb r0, [r5]
	b _0808EA40
	.align 2, 0
_0808E9F0: .4byte 0x030044E0
_0808E9F4: .4byte 0x00004022
_0808E9F8: .4byte 0x0000037D
_0808E9FC: .4byte 0x00004020
_0808EA00: .4byte 0x00004021
_0808EA04: .4byte 0x00004024
_0808EA08:
	ldr r0, _0808EA34 @ =0x00004021
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0808EA3C
	bl FUN_0808e8b8
	adds r7, r0, #0
	ldr r1, _0808EA38 @ =0x00004020
	adds r0, r6, r1
	ldrb r0, [r0]
	adds r3, r0, r7
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0808EA40
	movs r0, #0
	strb r0, [r4]
	b _0808EA40
	.align 2, 0
_0808EA34: .4byte 0x00004021
_0808EA38: .4byte 0x00004020
_0808EA3C:
	movs r7, #0
	movs r3, #0x12
_0808EA40:
	ldr r0, _0808EAAC @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808EA78
	ldr r0, _0808EAB0 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r2, r2, r4
	ldr r1, _0808EAB4 @ =0x00004022
	adds r0, r6, r1
	ldrh r0, [r0]
	adds r0, #1
	ldr r4, _0808EAB8 @ =0x0000401E
	adds r1, r6, r4
	ldrb r1, [r1]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, _0808EABC @ =0x0000270F
	cmp r0, r1
	ble _0808EA78
	ldr r0, _0808EAC0 @ =0x00004024
	adds r1, r6, r0
	movs r0, #0x3c
	strh r0, [r1]
_0808EA78:
	ldr r2, _0808EAC0 @ =0x00004024
	adds r1, r6, r2
	ldrh r0, [r1]
	movs r4, #0xc0
	adds r4, r4, r6
	mov r8, r4
	lsls r5, r3, #0x10
	cmp r0, #0
	beq _0808EB0A
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0808EAC8
	adds r0, r6, #0
	bl FUN_0808e5a8
	movs r0, #4
	bl FUN_08047a28
	ldr r1, _0808EAC4 @ =0x00004026
	adds r0, r6, r1
	strh r4, [r0]
	b _0808EB0A
	.align 2, 0
_0808EAAC: .4byte 0x030044E0
_0808EAB0: .4byte 0x030046A0
_0808EAB4: .4byte 0x00004022
_0808EAB8: .4byte 0x0000401E
_0808EABC: .4byte 0x0000270F
_0808EAC0: .4byte 0x00004024
_0808EAC4: .4byte 0x00004026
_0808EAC8:
	ldr r2, _0808EB30 @ =0x0000390C
	adds r0, r6, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r4, #1
	ldr r0, _0808EB34 @ =0x0000396C
	adds r2, r6, r0
	ldr r0, _0808EB38 @ =0x0000378C
	adds r1, r6, r0
	movs r3, #3
_0808EAE0:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0808EAE0
	ldr r1, _0808EB3C @ =0x00004026
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _0808EB0A
	movs r0, #6
	bl FUN_08047a28
	movs r0, #1
	strh r0, [r4]
_0808EB0A:
	ldr r2, _0808EB40 @ =0x00003604
	adds r0, r6, r2
	lsrs r2, r5, #0x10
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	ldr r4, _0808EB44 @ =0x00000BE4
	adds r0, r6, r4
	ldr r2, _0808EB48 @ =0x00000143
	adds r1, r7, r2
	bl Video_SetActorSpritePltt
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808EB30: .4byte 0x0000390C
_0808EB34: .4byte 0x0000396C
_0808EB38: .4byte 0x0000378C
_0808EB3C: .4byte 0x00004026
_0808EB40: .4byte 0x00003604
_0808EB44: .4byte 0x00000BE4
_0808EB48: .4byte 0x00000143

	thumb_func_start FUN_0808eb4c
FUN_0808eb4c: @ 0x0808EB4C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r1, [r4, #0x2c]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0808EBD0 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808EBD4 @ =0x00003504
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _0808EBD8 @ =0x00003506
	adds r0, r4, r2
	strh r5, [r0]
	subs r1, #0x20
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r5, [sp]
	movs r2, #7
	movs r3, #2
	bl FUN_082370cc
	adds r0, r4, #0
	bl FUN_0808e53c
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808b6fc
	ldr r2, _0808EBDC @ =0x00001524
	adds r0, r4, r2
	ldr r1, _0808EBE0 @ =0x0000FFF8
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #1
	bl FUN_08047a28
	ldr r1, _0808EBE4 @ =FUN_0808eeac
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808EBD0: .4byte 0x000034EC
_0808EBD4: .4byte 0x00003504
_0808EBD8: .4byte 0x00003506
_0808EBDC: .4byte 0x00001524
_0808EBE0: .4byte 0x0000FFF8
_0808EBE4: .4byte FUN_0808eeac

	thumb_func_start FUN_0808ebe8
FUN_0808ebe8: @ 0x0808EBE8
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x3c]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #3
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl FUN_0808eb4c
	ldr r1, _0808EC14 @ =FUN_0808ee50
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EC14: .4byte FUN_0808ee50

	thumb_func_start FUN_0808ec18
FUN_0808ec18: @ 0x0808EC18
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	bl FUN_0808b82c
	ldr r1, [r7, #0x2c]
	movs r0, #0
	movs r2, #4
	bl FUN_0822c398
	movs r4, #0
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0808ED2C @ =0x000034EC
	adds r1, r7, r0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	ldr r1, _0808ED30 @ =0x000034E4
	adds r0, r7, r1
	adds r6, r7, #0
	adds r6, #0xc0
	str r4, [sp]
	adds r1, r6, #0
	movs r2, #5
	movs r3, #1
	bl FUN_082370cc
	ldr r2, _0808ED34 @ =0x00004022
	adds r0, r7, r2
	strh r4, [r0]
	adds r0, r7, #0
	bl FUN_0808e734
	adds r0, r7, #0
	bl FUN_0808e83c
	ldr r0, _0808ED38 @ =0x00000BB8
	adds r1, r7, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r2, _0808ED3C @ =0x0000360C
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r0, _0808ED40 @ =0x00003624
	adds r1, r7, r0
	movs r0, #0x10
	strh r0, [r1]
	adds r2, #0x1a
	adds r1, r7, r2
	ldr r0, _0808ED44 @ =0x0000FFFC
	strh r0, [r1]
	ldr r1, _0808ED48 @ =0x00003604
	adds r0, r7, r1
	adds r1, r6, #0
	movs r2, #0x12
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _0808ED4C @ =0x0000390C
	adds r1, r7, r2
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r1, _0808ED50 @ =0x00003904
	adds r0, r7, r1
	ldr r2, _0808ED54 @ =0x0000401E
	adds r1, r7, r2
	ldrb r2, [r1]
	adds r2, #7
	adds r1, r6, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _0808ED58 @ =0x0000396C
	adds r2, r7, r0
	ldr r0, _0808ED5C @ =0x0000378C
	adds r1, r7, r0
	movs r3, #3
_0808ECCA:
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r0, [r2]
	ands r0, r5
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _0808ECCA
	movs r4, #0
	adds r0, r7, #0
	bl FUN_0808e5a8
	ldr r1, _0808ED60 @ =0x00004024
	adds r0, r7, r1
	movs r1, #0
	strh r4, [r0]
	ldr r2, _0808ED64 @ =0x00004026
	adds r0, r7, r2
	strh r4, [r0]
	subs r2, #5
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _0808ED48 @ =0x00003604
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0xc0
	movs r2, #0x12
	movs r3, #1
	bl Sprite_SetSprite
	ldr r2, _0808ED68 @ =0x00000BE4
	adds r0, r7, r2
	ldr r1, _0808ED6C @ =0x00000143
	bl Video_SetActorSpritePltt
	movs r0, #4
	bl FUN_08047a28
	ldr r1, _0808ED70 @ =FUN_0808ef58
	adds r0, r7, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808ED2C: .4byte 0x000034EC
_0808ED30: .4byte 0x000034E4
_0808ED34: .4byte 0x00004022
_0808ED38: .4byte 0x00000BB8
_0808ED3C: .4byte 0x0000360C
_0808ED40: .4byte 0x00003624
_0808ED44: .4byte 0x0000FFFC
_0808ED48: .4byte 0x00003604
_0808ED4C: .4byte 0x0000390C
_0808ED50: .4byte 0x00003904
_0808ED54: .4byte 0x0000401E
_0808ED58: .4byte 0x0000396C
_0808ED5C: .4byte 0x0000378C
_0808ED60: .4byte 0x00004024
_0808ED64: .4byte 0x00004026
_0808ED68: .4byte 0x00000BE4
_0808ED6C: .4byte 0x00000143
_0808ED70: .4byte FUN_0808ef58

	thumb_func_start FUN_0808ed74
FUN_0808ed74: @ 0x0808ED74
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r1, [r4, #0x2c]
	movs r0, #0
	movs r2, #5
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _0808EDD4 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808EDD8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r5, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	movs r0, #3
	bl FUN_08047a28
	ldr r0, _0808EDDC @ =0x000002C1
	bl PlaySound_082406e0
	ldr r1, _0808EDE0 @ =FUN_0808f01c
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808EDD4: .4byte 0x000034EC
_0808EDD8: .4byte 0x000034E4
_0808EDDC: .4byte 0x000002C1
_0808EDE0: .4byte FUN_0808f01c

	thumb_func_start FUN_0808ede4
FUN_0808ede4: @ 0x0808EDE4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x3c]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #5
	bl FUN_0808a3c4
	ldr r0, _0808EE44 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _0808EE48 @ =0x00003504
	adds r0, r4, r1
	movs r2, #0
	strh r2, [r0]
	adds r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	subs r1, #0x22
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r2, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0xd
	bl FUN_08047a28
	ldr r1, _0808EE4C @ =FUN_0808f0d8
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EE44: .4byte 0x000034EC
_0808EE48: .4byte 0x00003504
_0808EE4C: .4byte FUN_0808f0d8

	thumb_func_start FUN_0808ee50
FUN_0808ee50: @ 0x0808EE50
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808EE68 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808EE6C
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808EE74
	.align 2, 0
_0808EE68: .4byte 0x000009EC
_0808EE6C:
	movs r0, #0x40
	movs r1, #0
	bl FUN_0808a458
_0808EE74:
	ldr r1, _0808EEA0 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808EEA4 @ =0x000009EC
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808EE9A
	ldr r1, _0808EEA8 @ =FUN_0808eeac
	adds r0, r4, #0
	bl FUN_0808a33c
_0808EE9A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EEA0: .4byte 0x000034E4
_0808EEA4: .4byte 0x000009EC
_0808EEA8: .4byte FUN_0808eeac

	thumb_func_start FUN_0808eeac
FUN_0808eeac: @ 0x0808EEAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808EED8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	adds r0, r4, #0
	bl FUN_0808b760
	cmp r0, #0
	bne _0808EEE0
	movs r0, #0xde
	bl PlaySound_082406e0
	ldr r1, _0808EEDC @ =FUN_0808eef8
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808EEF0
	.align 2, 0
_0808EED8: .4byte 0x000034E4
_0808EEDC: .4byte FUN_0808eef8
_0808EEE0:
	cmp r0, #1
	bne _0808EEF0
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0808ec18
_0808EEF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808eef8
FUN_0808eef8: @ 0x0808EEF8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808EF18 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808EF1C
	adds r1, r0, #0
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808EF24
	.align 2, 0
_0808EF18: .4byte 0x000009EC
_0808EF1C:
	movs r0, #0
	movs r1, #0
	bl FUN_0808a458
_0808EF24:
	ldr r1, _0808EF50 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808EF54 @ =0x000009EC
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808EF48
	adds r0, r4, #0
	bl FUN_0808f2f0
_0808EF48:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808EF50: .4byte 0x000034E4
_0808EF54: .4byte 0x000009EC

	thumb_func_start FUN_0808ef58
FUN_0808ef58: @ 0x0808EF58
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _0808EF88 @ =0x000034E4
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808EF8C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808EFF8
	ldr r2, _0808EF90 @ =0x00004022
	adds r6, r5, r2
	ldrh r1, [r6]
	cmp r1, #0
	bne _0808EF94
	movs r0, #0xde
	bl PlaySound_082406e0
	b _0808EFE2
	.align 2, 0
_0808EF88: .4byte 0x000034E4
_0808EF8C: .4byte 0x030044E0
_0808EF90: .4byte 0x00004022
_0808EF94:
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r5, r2
	ldr r0, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r4, _0808EFEC @ =0x030046A0
	ldr r1, [r4]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r1, r1, r0
	ldrh r2, [r6]
	ldr r0, _0808EFF0 @ =0x0000401E
	adds r3, r5, r0
	ldrb r0, [r3]
	muls r2, r0, r2
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	ldr r0, [r4]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r2, r0, r1
	ldrh r1, [r6]
	ldrb r0, [r3]
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	cmp r0, #0
	bge _0808EFDA
	ldr r0, _0808EFF4 @ =0x7FFFFFFF
_0808EFDA:
	str r0, [r2]
	movs r0, #0xdd
	bl PlaySound_082406e0
_0808EFE2:
	adds r0, r5, #0
	bl FUN_0808ed74
	b _0808F014
	.align 2, 0
_0808EFEC: .4byte 0x030046A0
_0808EFF0: .4byte 0x0000401E
_0808EFF4: .4byte 0x7FFFFFFF
_0808EFF8:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808F00E
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_0808eb4c
	b _0808F014
_0808F00E:
	adds r0, r5, #0
	bl FUN_0808e8dc
_0808F014:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808f01c
FUN_0808f01c: @ 0x0808F01C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F060 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808F064 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x96
	bls _0808F090
	ldr r1, _0808F068 @ =0x00004022
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808F088
	movs r0, #5
	bl FUN_08047a28
	ldr r1, _0808F06C @ =0x00004028
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808F070
	movs r1, #0
	bl Script_ExecById
	b _0808F078
	.align 2, 0
_0808F060: .4byte 0x000034E4
_0808F064: .4byte 0x000009EC
_0808F068: .4byte 0x00004022
_0808F06C: .4byte 0x00004028
_0808F070:
	movs r0, #0
	movs r1, #3
	bl FUN_08047c40
_0808F078:
	ldr r1, _0808F084 @ =FUN_0808f09c
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808F090
	.align 2, 0
_0808F084: .4byte FUN_0808f09c
_0808F088:
	ldr r1, _0808F098 @ =FUN_0809ae0c
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F090:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F098: .4byte FUN_0809ae0c

	thumb_func_start FUN_0808f09c
FUN_0808f09c: @ 0x0808F09C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F0CC @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808F0D0 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F0C6
	ldr r1, _0808F0D4 @ =FUN_0809ae0c
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F0C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F0CC: .4byte 0x000034E4
_0808F0D0: .4byte 0x000009EC
_0808F0D4: .4byte FUN_0809ae0c

	thumb_func_start FUN_0808f0d8
FUN_0808f0d8: @ 0x0808F0D8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F0F8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r1, _0808F0FC @ =0x000009EC
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0xf
	bhi _0808F100
	adds r0, r1, #0
	lsls r0, r0, #2
	b _0808F106
	.align 2, 0
_0808F0F8: .4byte 0x000034E4
_0808F0FC: .4byte 0x000009EC
_0808F100:
	cmp r1, #0x85
	bhi _0808F10E
	movs r0, #0x40
_0808F106:
	movs r1, #0
	bl FUN_0808a458
	b _0808F11C
_0808F10E:
	ldrh r1, [r0]
	movs r0, #0x96
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
_0808F11C:
	ldr r1, _0808F13C @ =0x000009EC
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x95
	bls _0808F134
	adds r0, r4, #0
	bl FUN_0808f2f0
_0808F134:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F13C: .4byte 0x000009EC

	thumb_func_start FUN_0808f140
FUN_0808f140: @ 0x0808F140
	push {lr}
	ldr r0, _0808F158 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0808F15C @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #1
	bgt _0808F160
	movs r0, #9
	b _0808F16C
	.align 2, 0
_0808F158: .4byte 0x030046A0
_0808F15C: .4byte 0x00000942
_0808F160:
	cmp r1, #9
	bgt _0808F16A
	movs r0, #0xb
	subs r0, r0, r1
	b _0808F16C
_0808F16A:
	movs r0, #2
_0808F16C:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808f170
FUN_0808f170: @ 0x0808F170
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #1
	movs r1, #0xf
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	ldr r0, [r4, #0x54]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	ldr r1, _0808F1AC @ =0x0000401F
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808F1B0
	adds r0, r4, #0
	bl FUN_0808ede4
	b _0808F1B6
	.align 2, 0
_0808F1AC: .4byte 0x0000401F
_0808F1B0:
	adds r0, r4, #0
	bl FUN_0808ebe8
_0808F1B6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808f1bc
FUN_0808f1bc: @ 0x0808F1BC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0808F208 @ =0x00003544
	adds r0, r4, r1
	adds r6, r4, #0
	adds r6, #0xc0
	ldr r1, _0808F20C @ =0x0000401C
	adds r5, r4, r1
	ldrb r2, [r5]
	adds r2, #0x19
	adds r1, r6, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _0808F210 @ =0x000035A4
	adds r0, r4, r1
	ldrb r1, [r5]
	movs r2, #0x1c
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r6, #0
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, _0808F214 @ =0x00003624
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #5
	ldr r1, _0808F218 @ =0x00003626
	adds r4, r4, r1
	strh r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F208: .4byte 0x00003544
_0808F20C: .4byte 0x0000401C
_0808F210: .4byte 0x000035A4
_0808F214: .4byte 0x00003624
_0808F218: .4byte 0x00003626

	thumb_func_start FUN_0808f21c
FUN_0808f21c: @ 0x0808F21C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #1
	movs r1, #1
	movs r2, #0x1c
	movs r3, #6
	bl FUN_08047b8c
	ldr r0, [r4, #0x54]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x30]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	movs r3, #2
	bl FUN_0808a3c4
	adds r0, r4, #0
	bl FUN_0808b82c
	ldr r0, _0808F2D4 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _0808F2D8 @ =0x00003504
	adds r1, r4, r0
	movs r0, #0
	mov r8, r0
	ldr r0, _0808F2DC @ =0x0000FFA8
	strh r0, [r1]
	ldr r0, _0808F2E0 @ =0x00003506
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F2E4 @ =0x000034E4
	adds r0, r4, r1
	adds r5, r4, #0
	adds r5, #0xc0
	mov r1, r8
	str r1, [sp]
	adds r1, r5, #0
	movs r2, #4
	movs r3, #2
	bl FUN_082370cc
	ldr r0, _0808F2E8 @ =0x00003604
	adds r6, r4, r0
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0x1d
	movs r3, #1
	bl Sprite_SetSprite
	mov r1, r8
	str r1, [sp]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #1
	bl FUN_082370cc
	movs r0, #0
	bl FUN_08047a28
	ldr r1, _0808F2EC @ =FUN_0808f520
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F2D4: .4byte 0x000034EC
_0808F2D8: .4byte 0x00003504
_0808F2DC: .4byte 0x0000FFA8
_0808F2E0: .4byte 0x00003506
_0808F2E4: .4byte 0x000034E4
_0808F2E8: .4byte 0x00003604
_0808F2EC: .4byte FUN_0808f520

	thumb_func_start FUN_0808f2f0
FUN_0808f2f0: @ 0x0808F2F0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	bl FUN_08047864
	bl FUN_08049e5c
	bl FUN_08049f84
	movs r0, #1
	movs r1, #1
	movs r2, #0x1c
	movs r3, #4
	bl FUN_08047b8c
	ldr r0, [r5, #0x54]
	bl FUN_080478f0
	movs r0, #1
	bl FUN_080477e4
	ldr r1, [r5, #0x18]
	ldr r0, [r5, #0x30]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #2
	bl FUN_0808a3c4
	adds r0, r5, #0
	bl FUN_0808b82c
	ldr r0, _0808F3D0 @ =0x000034EC
	adds r1, r5, r0
	ldr r0, [r1]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r1]
	ldr r0, _0808F3D4 @ =0x00003504
	adds r1, r5, r0
	movs r7, #0
	ldr r0, _0808F3D8 @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F3DC @ =0x00003506
	adds r1, r5, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F3E0 @ =0x000034E4
	adds r0, r5, r1
	adds r6, r5, #0
	adds r6, #0xc0
	str r7, [sp]
	adds r1, r6, #0
	movs r2, #7
	movs r3, #2
	bl FUN_082370cc
	ldr r0, _0808F3E4 @ =0x0000354C
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F38C
	ldr r0, _0808F3E8 @ =0x000035AC
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
_0808F38C:
	ldr r0, _0808F3EC @ =0x0000360C
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r1, _0808F3F0 @ =0x00003604
	adds r4, r5, r1
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x1d
	movs r3, #1
	bl Sprite_SetSprite
	str r7, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xa
	movs r3, #1
	bl FUN_082370cc
	adds r0, r5, #0
	bl FUN_0808f1bc
	movs r0, #7
	bl FUN_08047a28
	ldr r1, _0808F3F4 @ =FUN_0808f604
	adds r0, r5, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808F3D0: .4byte 0x000034EC
_0808F3D4: .4byte 0x00003504
_0808F3D8: .4byte 0x0000FFE4
_0808F3DC: .4byte 0x00003506
_0808F3E0: .4byte 0x000034E4
_0808F3E4: .4byte 0x0000354C
_0808F3E8: .4byte 0x000035AC
_0808F3EC: .4byte 0x0000360C
_0808F3F0: .4byte 0x00003604
_0808F3F4: .4byte FUN_0808f604

	thumb_func_start FUN_0808f3f8
FUN_0808f3f8: @ 0x0808F3F8
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r0, _0808F484 @ =0x000034EC
	adds r1, r4, r0
	ldr r0, [r1]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r1]
	ldr r0, _0808F488 @ =0x00003504
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _0808F48C @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F490 @ =0x00003506
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F494 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r2, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	ldr r0, _0808F498 @ =0x0000354C
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F45C
	ldr r0, _0808F49C @ =0x000035AC
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
_0808F45C:
	ldr r0, _0808F4A0 @ =0x0000360C
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	ldr r0, _0808F4A4 @ =0x000002C1
	bl PlaySound_082406e0
	movs r0, #3
	bl FUN_08047a28
	ldr r1, _0808F4A8 @ =FUN_0808f8bc
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F484: .4byte 0x000034EC
_0808F488: .4byte 0x00003504
_0808F48C: .4byte 0x0000FFE4
_0808F490: .4byte 0x00003506
_0808F494: .4byte 0x000034E4
_0808F498: .4byte 0x0000354C
_0808F49C: .4byte 0x000035AC
_0808F4A0: .4byte 0x0000360C
_0808F4A4: .4byte 0x000002C1
_0808F4A8: .4byte FUN_0808f8bc

	thumb_func_start FUN_0808f4ac
FUN_0808f4ac: @ 0x0808F4AC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_0808b82c
	ldr r0, _0808F504 @ =0x000034EC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _0808F508 @ =0x00003504
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _0808F50C @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F510 @ =0x00003506
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
	ldr r1, _0808F514 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	str r2, [sp]
	movs r2, #6
	movs r3, #2
	bl FUN_082370cc
	ldr r0, _0808F518 @ =0x000002C1
	bl PlaySound_082406e0
	movs r0, #3
	bl FUN_08047a28
	ldr r1, _0808F51C @ =FUN_0808f774
	adds r0, r4, #0
	bl FUN_0808a33c
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F504: .4byte 0x000034EC
_0808F508: .4byte 0x00003504
_0808F50C: .4byte 0x0000FFE4
_0808F510: .4byte 0x00003506
_0808F514: .4byte 0x000034E4
_0808F518: .4byte 0x000002C1
_0808F51C: .4byte FUN_0808f774

	thumb_func_start FUN_0808f520
FUN_0808f520: @ 0x0808F520
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0808F538 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808F53C
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808F544
	.align 2, 0
_0808F538: .4byte 0x000009EC
_0808F53C:
	movs r0, #0x40
	movs r1, #0
	bl FUN_0808a458
_0808F544:
	ldr r1, _0808F5E0 @ =0x000009EC
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0x10
	bne _0808F556
	movs r0, #0xb0
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0808F556:
	ldr r1, _0808F5E4 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldrh r0, [r5]
	cmp r0, #0x68
	bls _0808F572
	ldr r0, _0808F5E8 @ =0x00003504
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #5
	strh r0, [r1]
_0808F572:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x74
	bls _0808F5DA
	movs r0, #7
	bl FUN_08047a28
	ldr r0, _0808F5E8 @ =0x00003504
	adds r1, r4, r0
	ldr r0, _0808F5EC @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F5F0 @ =0x0000360C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, _0808F5F4 @ =0x0000354C
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F5C4
	ldr r0, _0808F5F8 @ =0x000035AC
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0808F5C4:
	ldr r1, _0808F5FC @ =0x0000401C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808f1bc
	ldr r1, _0808F600 @ =FUN_0808f670
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F5DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F5E0: .4byte 0x000009EC
_0808F5E4: .4byte 0x000034E4
_0808F5E8: .4byte 0x00003504
_0808F5EC: .4byte 0x0000FFE4
_0808F5F0: .4byte 0x0000360C
_0808F5F4: .4byte 0x0000354C
_0808F5F8: .4byte 0x000035AC
_0808F5FC: .4byte 0x0000401C
_0808F600: .4byte FUN_0808f670

	thumb_func_start FUN_0808f604
FUN_0808f604: @ 0x0808F604
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0808F61C @ =0x000009EC
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808F620
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808F628
	.align 2, 0
_0808F61C: .4byte 0x000009EC
_0808F620:
	movs r0, #0x40
	movs r1, #0
	bl FUN_0808a458
_0808F628:
	ldr r1, _0808F660 @ =0x000034E4
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xc0
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r1, _0808F664 @ =0x00003604
	adds r0, r5, r1
	adds r1, r4, #0
	bl FUN_082372cc
	ldr r0, _0808F668 @ =0x000009EC
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808F65A
	ldr r1, _0808F66C @ =FUN_0808f670
	adds r0, r5, #0
	bl FUN_0808a33c
_0808F65A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F660: .4byte 0x000034E4
_0808F664: .4byte 0x00003604
_0808F668: .4byte 0x000009EC
_0808F66C: .4byte FUN_0808f670

	thumb_func_start FUN_0808f670
FUN_0808f670: @ 0x0808F670
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _0808F6EC @ =0x000034E4
	adds r0, r4, r1
	adds r5, r4, #0
	adds r5, #0xc0
	adds r1, r5, #0
	bl FUN_082372cc
	ldr r2, _0808F6F0 @ =0x00003604
	adds r6, r4, r2
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_082372cc
	ldr r0, _0808F6F4 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808F720
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0x1d
	movs r3, #1
	bl Sprite_SetSprite
	ldr r1, _0808F6F8 @ =0x0000401C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808F710
	movs r0, #8
	bl FUN_08047a28
	ldr r2, _0808F6FC @ =0x0000401E
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r0, #1
	movs r1, #0x32
	muls r1, r0, r1
	movs r0, #0
	bl FUN_08047c40
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r0, _0808F700 @ =0x00001524
	adds r1, r4, r0
	ldr r0, _0808F704 @ =0x0000FFF8
	strh r0, [r1]
	ldr r2, _0808F708 @ =0x00001526
	adds r1, r4, r2
	subs r0, #0x60
	strh r0, [r1]
	ldr r1, _0808F70C @ =FUN_0808f81c
	b _0808F712
	.align 2, 0
_0808F6EC: .4byte 0x000034E4
_0808F6F0: .4byte 0x00003604
_0808F6F4: .4byte 0x030044E0
_0808F6F8: .4byte 0x0000401C
_0808F6FC: .4byte 0x0000401E
_0808F700: .4byte 0x00001524
_0808F704: .4byte 0x0000FFF8
_0808F708: .4byte 0x00001526
_0808F70C: .4byte FUN_0808f81c
_0808F710:
	ldr r1, _0808F71C @ =FUN_0808f7cc
_0808F712:
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808F76A
	.align 2, 0
_0808F71C: .4byte FUN_0808f7cc
_0808F720:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0808F736
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0808f4ac
	b _0808F76A
_0808F736:
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r4, r2
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F76A
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _0808F76A
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _0808F770 @ =0x0000401C
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	bl FUN_0808f1bc
_0808F76A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808F770: .4byte 0x0000401C

	thumb_func_start FUN_0808f774
FUN_0808f774: @ 0x0808F774
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F7BC @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808F7C0 @ =0x00003504
	adds r2, r4, r0
	ldrh r3, [r2]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x58
	rsbs r0, r0, #0
	cmp r1, r0
	ble _0808F79A
	subs r0, r3, #5
	strh r0, [r2]
_0808F79A:
	ldr r0, _0808F7C4 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F7B4
	ldr r1, _0808F7C8 @ =FUN_0809ae0c
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F7B4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F7BC: .4byte 0x000034E4
_0808F7C0: .4byte 0x00003504
_0808F7C4: .4byte 0x000009EC
_0808F7C8: .4byte FUN_0809ae0c

	thumb_func_start FUN_0808f7cc
FUN_0808f7cc: @ 0x0808F7CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0808F7EC @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808F7F0
	adds r1, r0, #0
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808F7F8
	.align 2, 0
_0808F7EC: .4byte 0x000009EC
_0808F7F0:
	movs r0, #0
	movs r1, #0
	bl FUN_0808a458
_0808F7F8:
	ldr r0, _0808F818 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _0808F810
	adds r0, r4, #0
	bl FUN_0808f170
_0808F810:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F818: .4byte 0x000009EC

	thumb_func_start FUN_0808f81c
FUN_0808f81c: @ 0x0808F81C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808F850 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	adds r0, r4, #0
	bl FUN_0808b760
	adds r5, r0, #0
	cmp r5, #0
	bne _0808F858
	movs r0, #0xde
	bl PlaySound_082406e0
	movs r0, #7
	bl FUN_08047a28
	ldr r1, _0808F854 @ =FUN_0808f670
	adds r0, r4, #0
	bl FUN_0808a33c
	b _0808F8A2
	.align 2, 0
_0808F850: .4byte 0x000034E4
_0808F854: .4byte FUN_0808f670
_0808F858:
	cmp r5, #1
	bne _0808F8A2
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r3, _0808F8A8 @ =0x030046A0
	ldr r2, [r3]
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r2, r2, r0
	ldr r1, _0808F8AC @ =0x0000401E
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #1
	movs r1, #0x32
	muls r1, r0, r1
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
	ldr r1, _0808F8B0 @ =0x0000270F
	cmp r0, r1
	ble _0808F88E
	ldr r0, [r3]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r0, r2
	str r1, [r0]
_0808F88E:
	ldr r1, _0808F8B4 @ =0x00003FB0
	adds r0, r4, r1
	strb r5, [r0]
	ldr r2, _0808F8B8 @ =0x00003FB1
	adds r1, r4, r2
	movs r0, #2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808f3f8
_0808F8A2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F8A8: .4byte 0x030046A0
_0808F8AC: .4byte 0x0000401E
_0808F8B0: .4byte 0x0000270F
_0808F8B4: .4byte 0x00003FB0
_0808F8B8: .4byte 0x00003FB1

	thumb_func_start FUN_0808f8bc
FUN_0808f8bc: @ 0x0808F8BC
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F8F8 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808F8FC @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F914
	movs r0, #5
	bl FUN_08047a28
	ldr r1, _0808F900 @ =0x00004028
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0808F904
	movs r1, #0
	bl Script_ExecById
	b _0808F90C
	.align 2, 0
_0808F8F8: .4byte 0x000034E4
_0808F8FC: .4byte 0x000009EC
_0808F900: .4byte 0x00004028
_0808F904:
	movs r0, #0
	movs r1, #3
	bl FUN_08047c40
_0808F90C:
	ldr r1, _0808F91C @ =FUN_0808f920
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F914:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F91C: .4byte FUN_0808f920

	thumb_func_start FUN_0808f920
FUN_0808f920: @ 0x0808F920
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808F950 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl FUN_082372cc
	ldr r0, _0808F954 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _0808F94A
	ldr r1, _0808F958 @ =FUN_0809ae0c
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F94A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F950: .4byte 0x000034E4
_0808F954: .4byte 0x000009EC
_0808F958: .4byte FUN_0809ae0c

	thumb_func_start FUN_0808f95c
FUN_0808f95c: @ 0x0808F95C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808f140
	ldr r2, _0808F980 @ =0x0000401E
	adds r1, r4, r2
	strb r0, [r1]
	ldr r2, _0808F984 @ =0x03003E78
	ldr r0, _0808F988 @ =0xFFFFFDFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	bl FUN_0808f21c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808F980: .4byte 0x0000401E
_0808F984: .4byte 0x03003E78
_0808F988: .4byte 0xFFFFFDFF

	thumb_func_start FUN_0808f98c
FUN_0808f98c: @ 0x0808F98C
	ldrb r1, [r0, #1]
	lsls r1, r1, #2
	ldrb r2, [r0, #2]
	adds r1, r1, r2
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	bx lr

	thumb_func_start FUN_0808f9a0
FUN_0808f9a0: @ 0x0808F9A0
	push {r4, lr}
	adds r3, r0, #0
	ldr r4, _0808F9BC @ =0x030044E0
	ldrh r0, [r4, #2]
	movs r1, #0xf0
	adds r2, r1, #0
	ands r2, r0
	cmp r2, #0
	beq _0808F9C0
	movs r0, #0
	strb r0, [r3, #7]
	ldrh r0, [r4, #2]
	b _0808F9E0
	.align 2, 0
_0808F9BC: .4byte 0x030044E0
_0808F9C0:
	ldrh r0, [r4]
	ands r1, r0
	cmp r1, #0
	beq _0808F9DC
	ldrb r0, [r3, #7]
	adds r0, #1
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0808F9DE
	strb r2, [r3, #7]
	ldrh r0, [r4]
	b _0808F9E0
_0808F9DC:
	strb r1, [r3, #7]
_0808F9DE:
	movs r0, #0
_0808F9E0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808f9e8
FUN_0808f9e8: @ 0x0808F9E8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #2]
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r2, r1
	adds r0, #8
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r3, r2, #3
	movs r0, #3
	ands r3, r0
	cmp r3, r2
	beq _0808FA40
_0808FA06:
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r3, r1
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808FA34
	cmp r0, r5
	beq _0808FA34
	strb r3, [r4, #2]
	adds r0, r4, #0
	bl FUN_0808f98c
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _0808FA42
_0808FA34:
	adds r3, #3
	movs r0, #3
	ands r3, r0
	ldrb r0, [r4, #2]
	cmp r3, r0
	bne _0808FA06
_0808FA40:
	movs r0, #0
_0808FA42:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808fa48
FUN_0808fa48: @ 0x0808FA48
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r2, [r4, #2]
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r2, r1
	adds r0, #8
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r3, r2, #1
	movs r0, #3
	ands r3, r0
	cmp r3, r2
	beq _0808FAA0
_0808FA66:
	ldrb r1, [r4, #1]
	lsls r1, r1, #2
	adds r1, r3, r1
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808FA94
	cmp r0, r5
	beq _0808FA94
	strb r3, [r4, #2]
	adds r0, r4, #0
	bl FUN_0808f98c
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _0808FAA2
_0808FA94:
	adds r3, #1
	movs r0, #3
	ands r3, r0
	ldrb r0, [r4, #2]
	cmp r3, r0
	bne _0808FA66
_0808FAA0:
	movs r0, #0
_0808FAA2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808faa8
FUN_0808faa8: @ 0x0808FAA8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r1, r3, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	subs r2, r3, #1
	cmp r3, #0
	bne _0808FAFC
_0808FAC4:
	movs r2, #8
	b _0808FAFC
_0808FAC8:
	lsls r1, r2, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808FAF6
	cmp r0, r5
	beq _0808FAF6
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl FUN_0808f98c
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _0808FB02
_0808FAF6:
	cmp r2, #0
	beq _0808FAC4
	subs r2, #1
_0808FAFC:
	cmp r2, r3
	bne _0808FAC8
	movs r0, #0
_0808FB02:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808fb08
FUN_0808fb08: @ 0x0808FB08
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r3, [r4, #1]
	lsls r1, r3, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r2, r3, #1
	cmp r3, #8
	bne _0808FB5C
_0808FB24:
	movs r2, #0
	b _0808FB5C
_0808FB28:
	lsls r1, r2, #2
	ldrb r0, [r4, #2]
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #8
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0808FB56
	cmp r0, r5
	beq _0808FB56
	strb r2, [r4, #1]
	adds r0, r4, #0
	bl FUN_0808f98c
	strb r0, [r4, #3]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r0, #1
	b _0808FB62
_0808FB56:
	cmp r2, #8
	beq _0808FB24
	adds r2, #1
_0808FB5C:
	cmp r2, r3
	bne _0808FB28
	movs r0, #0
_0808FB62:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808fb68
FUN_0808fb68: @ 0x0808FB68
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0808f9a0
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0808FB82
	adds r0, r4, #0
	bl FUN_0808f9e8
	b _0808FBB4
_0808FB82:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0808FB92
	adds r0, r4, #0
	bl FUN_0808fa48
	b _0808FBB4
_0808FB92:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0808FBA2
	adds r0, r4, #0
	bl FUN_0808faa8
	b _0808FBB4
_0808FBA2:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0808FBAE
	movs r0, #0
	b _0808FBB4
_0808FBAE:
	adds r0, r4, #0
	bl FUN_0808fb08
_0808FBB4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0808fbbc
FUN_0808fbbc: @ 0x0808FBBC
	ldrb r1, [r0, #1]
	strb r1, [r0, #4]
	ldrb r1, [r0, #2]
	strb r1, [r0, #5]
	ldrb r1, [r0, #3]
	strb r1, [r0, #6]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808fbcc
FUN_0808fbcc: @ 0x0808FBCC
	ldrb r1, [r0, #4]
	strb r1, [r0, #1]
	ldrb r1, [r0, #5]
	strb r1, [r0, #2]
	ldrb r1, [r0, #6]
	strb r1, [r0, #3]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0808fbdc
FUN_0808fbdc: @ 0x0808FBDC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	strb r1, [r4, #1]
	strb r2, [r4, #2]
	bl FUN_0808f98c
	strb r0, [r4, #3]
	strb r5, [r4, #7]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808fbf4
FUN_0808fbf4: @ 0x0808FBF4
	push {lr}
	ldr r2, _0808FC10 @ =0x00004038
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, #0xc
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1, #0xf]
	bl FUN_08047a28
	pop {r0}
	bx r0
	.align 2, 0
_0808FC10: .4byte 0x00004038

	thumb_func_start FUN_0808fc14
FUN_0808fc14: @ 0x0808FC14
	push {r4, lr}
	ldr r0, _0808FC4C @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x95
	lsls r0, r0, #2
	adds r2, r3, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0xe
	bgt _0808FC5C
	ldr r1, _0808FC50 @ =0x085ACEC8
	lsls r0, r0, #2
	adds r1, r0, r1
	ldr r2, [r1]
	ldr r1, _0808FC54 @ =0x085ACF04
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r4, _0808FC58 @ =0x00000256
	adds r0, r3, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0, #0xf]
	b _0808FC62
	.align 2, 0
_0808FC4C: .4byte 0x030046A0
_0808FC50: .4byte 0x085ACEC8
_0808FC54: .4byte 0x085ACF04
_0808FC58: .4byte 0x00000256
_0808FC5C:
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r0, #0x40
_0808FC62:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808fc68
FUN_0808fc68: @ 0x0808FC68
	push {lr}
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808FC84
	bl Script_GetValue
	ldr r1, _0808FC88 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r0, [r1]
_0808FC84:
	pop {r0}
	bx r0
	.align 2, 0
_0808FC88: .4byte 0x030046A0

	thumb_func_start FUN_0808fc8c
FUN_0808fc8c: @ 0x0808FC8C
	push {lr}
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808FCA6
	bl Script_GetValue
	ldr r1, _0808FCAC @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _0808FCB0 @ =0x00000256
	adds r1, r1, r2
	strh r0, [r1]
_0808FCA6:
	pop {r0}
	bx r0
	.align 2, 0
_0808FCAC: .4byte 0x030046A0
_0808FCB0: .4byte 0x00000256

	thumb_func_start FUN_0808fcb4
FUN_0808fcb4: @ 0x0808FCB4
	push {lr}
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808FCD0
	bl Script_GetValue
	ldr r1, _0808FCD4 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r0, [r1]
_0808FCD0:
	pop {r0}
	bx r0
	.align 2, 0
_0808FCD4: .4byte 0x030046A0

	thumb_func_start FUN_0808fcd8
FUN_0808fcd8: @ 0x0808FCD8
	push {lr}
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808FCF2
	bl Script_GetValue
	ldr r1, _0808FCF8 @ =0x030046A0
	ldr r1, [r1]
	ldr r2, _0808FCFC @ =0x0000025A
	adds r1, r1, r2
	strh r0, [r1]
_0808FCF2:
	pop {r0}
	bx r0
	.align 2, 0
_0808FCF8: .4byte 0x030046A0
_0808FCFC: .4byte 0x0000025A

	thumb_func_start FUN_0808fd00
FUN_0808fd00: @ 0x0808FD00
	push {lr}
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808FD24
	bl Script_GetValue
	ldr r1, _0808FD28 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0x98
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0808FD24:
	pop {r0}
	bx r0
	.align 2, 0
_0808FD28: .4byte 0x030046A0

	thumb_func_start FUN_0808fd2c
FUN_0808fd2c: @ 0x0808FD2C
	ldr r1, _0808FD40 @ =0x030046A0
	ldr r2, [r1]
	movs r1, #0x98
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	ands r0, r1
	bx lr
	.align 2, 0
_0808FD40: .4byte 0x030046A0

	thumb_func_start FUN_0808fd44
FUN_0808fd44: @ 0x0808FD44
	push {lr}
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _0808FD70
	ldr r0, _0808FD6C @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	b _0808FD82
	.align 2, 0
_0808FD6C: .4byte 0x030046A0
_0808FD70:
	bl Script_GetValue
	ldr r1, _0808FD88 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r0, r2
_0808FD82:
	ldr r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_0808FD88: .4byte 0x030046A0

	thumb_func_start FUN_0808fd8c
FUN_0808fd8c: @ 0x0808FD8C
	push {lr}
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808FDA0
	bl Script_GetValue
	adds r2, r0, #0
	b _0808FDAE
_0808FDA0:
	ldr r0, _0808FDC4 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
_0808FDAE:
	ldr r0, _0808FDC4 @ =0x030046A0
	ldr r1, [r0]
	lsls r0, r2, #2
	adds r0, r0, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0808FDC4: .4byte 0x030046A0

	thumb_func_start FUN_0808fdc8
FUN_0808fdc8: @ 0x0808FDC8
	push {r4, lr}
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808FDDC
	bl Script_GetValue
	adds r4, r0, #0
	b _0808FDEA
_0808FDDC:
	ldr r0, _0808FE18 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
_0808FDEA:
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808FE10
	bl Script_GetValue
	ldr r1, _0808FE18 @ =0x030046A0
	ldr r1, [r1]
	lsls r2, r4, #2
	adds r2, r2, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0808FE10:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FE18: .4byte 0x030046A0

	thumb_func_start FUN_0808fe1c
FUN_0808fe1c: @ 0x0808FE1C
	push {r4, lr}
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808FE30
	bl Script_GetValue
	adds r4, r0, #0
	b _0808FE3E
_0808FE30:
	ldr r0, _0808FE6C @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r4, [r0, r1]
_0808FE3E:
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808FE64
	bl Script_GetValue
	ldr r1, _0808FE6C @ =0x030046A0
	ldr r1, [r1]
	lsls r2, r4, #2
	adds r2, r2, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
_0808FE64:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808FE6C: .4byte 0x030046A0

	thumb_func_start FUN_0808fe70
FUN_0808fe70: @ 0x0808FE70
	adds r1, r0, #0
	movs r0, #0xf
	ands r0, r1
	bx lr

	thumb_func_start FUN_0808fe78
FUN_0808fe78: @ 0x0808FE78
	asrs r0, r0, #4
	bx lr

	thumb_func_start FUN_0808fe7c
FUN_0808fe7c: @ 0x0808FE7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov sl, r1
	mov sb, r2
	ldr r0, _0808FE9C @ =0x00004034
	add r0, r8
	ldr r0, [r0]
	cmp r0, #0
	beq _0808FF6C
	movs r7, #0
	b _0808FF52
	.align 2, 0
_0808FE9C: .4byte 0x00004034
_0808FEA0:
	ldr r1, _0808FF00 @ =0x00004038
	add r1, r8
	ldrb r0, [r6, #1]
	ldrb r1, [r1]
	cmp r0, r1
	bne _0808FF50
	ldr r0, _0808FF04 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	asrs r0, r7
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808FF50
	ldrb r3, [r6, #2]
	ldrb r2, [r6, #3]
	cmp r3, sl
	blt _0808FF50
	mov r0, sl
	adds r0, #0x20
	cmp r3, r0
	bge _0808FF50
	cmp r2, sb
	blt _0808FF50
	mov r0, sb
	adds r0, #0x20
	cmp r2, r0
	bge _0808FF50
	movs r4, #0
	subs r0, r5, #1
	cmp r0, #4
	bhi _0808FF2A
	lsls r0, r0, #2
	ldr r1, _0808FF08 @ =_0808FF0C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0808FF00: .4byte 0x00004038
_0808FF04: .4byte 0x030046A0
_0808FF08: .4byte _0808FF0C
_0808FF0C: @ jump table
	.4byte _0808FF20 @ case 0
	.4byte _0808FF24 @ case 1
	.4byte _0808FF28 @ case 2
	.4byte _0808FF28 @ case 3
	.4byte _0808FF28 @ case 4
_0808FF20:
	movs r4, #0xd
	b _0808FF2A
_0808FF24:
	movs r4, #0xf
	b _0808FF2A
_0808FF28:
	movs r4, #1
_0808FF2A:
	movs r0, #1
	adds r1, r3, #0
	bl FUN_0808a420
	adds r5, r0, #0
	ldrb r0, [r6]
	bl FUN_0808fe78
	cmp r0, #0
	beq _0808FF48
	ldr r2, _0808FF44 @ =0xFFFFE400
	adds r0, r2, #0
	b _0808FF4C
	.align 2, 0
_0808FF44: .4byte 0xFFFFE400
_0808FF48:
	ldr r1, _0808FF7C @ =0xFFFFE000
	adds r0, r1, #0
_0808FF4C:
	orrs r4, r0
	strh r4, [r5]
_0808FF50:
	adds r7, #1
_0808FF52:
	cmp r7, #0x1f
	bgt _0808FF6C
	ldr r0, _0808FF80 @ =0x00004034
	add r0, r8
	lsls r1, r7, #2
	ldr r0, [r0]
	adds r6, r0, r1
	ldrb r0, [r6]
	bl FUN_0808fe70
	adds r5, r0, #0
	cmp r5, #0
	bne _0808FEA0
_0808FF6C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808FF7C: .4byte 0xFFFFE000
_0808FF80: .4byte 0x00004034

	thumb_func_start FUN_0808ff84
FUN_0808ff84: @ 0x0808FF84
	push {r4, r5, lr}
	ldr r2, _0808FFF0 @ =0x00004044
	adds r1, r0, r2
	movs r2, #0
	strh r2, [r1]
	ldr r3, _0808FFF4 @ =0x00004046
	adds r1, r0, r3
	strh r2, [r1]
	ldr r5, _0808FFF8 @ =0x00004038
	adds r4, r0, r5
	ldrb r1, [r4]
	ldr r2, _0808FFFC @ =0x0000402C
	adds r3, r0, r2
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #4]
	subs r1, #0x1e
	lsls r1, r1, #3
	adds r5, #0x10
	adds r2, r0, r5
	strh r1, [r2]
	ldrb r1, [r4]
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #5]
	subs r1, #0x14
	lsls r1, r1, #3
	adds r5, #2
	adds r2, r0, r5
	strh r1, [r2]
	ldrb r1, [r4]
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #2]
	lsls r1, r1, #3
	adds r5, #2
	adds r2, r0, r5
	strh r1, [r2]
	ldrb r1, [r4]
	ldr r2, [r3]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrb r1, [r1, #3]
	lsls r1, r1, #3
	ldr r2, _08090000 @ =0x0000404E
	adds r0, r0, r2
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808FFF0: .4byte 0x00004044
_0808FFF4: .4byte 0x00004046
_0808FFF8: .4byte 0x00004038
_0808FFFC: .4byte 0x0000402C
_08090000: .4byte 0x0000404E

	thumb_func_start FUN_08090004
FUN_08090004: @ 0x08090004
	ldr r1, _08090030 @ =0x00002CAC
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08090034 @ =0x00002D0C
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08090038 @ =0x00002D6C
	adds r2, r0, r1
	ldr r1, [r2]
	orrs r1, r3
	str r1, [r2]
	ldr r1, _0809003C @ =0x00002DCC
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r3
	str r1, [r0]
	bx lr
	.align 2, 0
_08090030: .4byte 0x00002CAC
_08090034: .4byte 0x00002D0C
_08090038: .4byte 0x00002D6C
_0809003C: .4byte 0x00002DCC

	thumb_func_start FUN_08090040
FUN_08090040: @ 0x08090040
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r0, _08090084 @ =0x00002CAC
	adds r2, r3, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r5, _08090088 @ =0x00002D0C
	adds r4, r3, r5
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r6, _0809008C @ =0x00004040
	adds r1, r3, r6
	ldr r7, _08090090 @ =0x00004044
	adds r0, r3, r7
	movs r6, #0
	ldrsh r5, [r1, r6]
	ldrh r6, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r5, r0
	bgt _08090094
	strh r6, [r1]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080900AC
	.align 2, 0
_08090084: .4byte 0x00002CAC
_08090088: .4byte 0x00002D0C
_0809008C: .4byte 0x00004040
_08090090: .4byte 0x00004044
_08090094:
	ldr r2, _080900E8 @ =0x00004048
	adds r0, r3, r2
	ldrh r2, [r0]
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r5, r0
	blt _080900AC
	strh r2, [r1]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080900AC:
	ldr r7, _080900EC @ =0x00002D6C
	adds r4, r3, r7
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r0, _080900F0 @ =0x00002DCC
	adds r5, r3, r0
	ldr r2, [r5]
	ands r2, r1
	str r2, [r5]
	ldr r1, _080900F4 @ =0x00004042
	adds r6, r3, r1
	ldr r7, _080900F8 @ =0x00004046
	adds r7, r7, r3
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r8, r0
	bgt _080900FC
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	ldrh r0, [r7]
	b _08090110
	.align 2, 0
_080900E8: .4byte 0x00004048
_080900EC: .4byte 0x00002D6C
_080900F0: .4byte 0x00002DCC
_080900F4: .4byte 0x00004042
_080900F8: .4byte 0x00004046
_080900FC:
	ldr r7, _0809011C @ =0x0000404A
	adds r1, r3, r7
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r8, r0
	blt _08090112
	movs r0, #1
	orrs r2, r0
	str r2, [r5]
	ldrh r0, [r1]
_08090110:
	strh r0, [r6]
_08090112:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809011C: .4byte 0x0000404A

	thumb_func_start FUN_08090120
FUN_08090120: @ 0x08090120
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08090144 @ =0x00002CA4
	adds r4, r6, r0
	movs r5, #3
_0809012A:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0x80
	bl FUN_082372cc
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809012A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08090144: .4byte 0x00002CA4

	thumb_func_start FUN_08090148
FUN_08090148: @ 0x08090148
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r0, _08090214 @ =0x00002E2C
	adds r7, r5, r0
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	ldr r2, _08090218 @ =0x00002E8C
	adds r6, r5, r2
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, _0809021C @ =0x00002EEC
	adds r3, r5, r0
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r1, _08090220 @ =0x00002F4C
	adds r1, r1, r5
	mov r8, r1
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08090224 @ =0x0000403C
	adds r0, r0, r5
	mov sb, r0
	movs r0, #0xff
	mov r1, sb
	strb r0, [r1]
	ldr r2, _08090228 @ =0x0000403D
	adds r2, r5, r2
	str r2, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r2]
	ldr r0, _0809022C @ =0x0000403E
	adds r0, r5, r0
	str r0, [sp, #4]
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #4]
	strb r0, [r1]
	ldr r2, _08090230 @ =0x0000403F
	adds r2, r5, r2
	str r2, [sp, #8]
	strb r0, [r2]
	ldr r0, _08090234 @ =0x0000402C
	adds r0, r5, r0
	str r0, [sp, #0xc]
	ldr r1, _08090238 @ =0x00004038
	adds r1, r1, r5
	mov sl, r1
	ldrb r0, [r1]
	lsls r0, r0, #4
	ldr r1, [sp, #0xc]
	ldr r2, [r1]
	adds r4, r2, r0
	ldr r1, _0809023C @ =0x00004039
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080901D4
	b _08090512
_080901D4:
	movs r1, #6
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080902A4
	adds r0, r1, #0
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _0809024E
	ldrb r0, [r4, #6]
	mov r2, sb
	strb r0, [r2]
	ldr r2, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08090244
	ldr r0, _08090240 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r7]
	b _080902A4
	.align 2, 0
_08090214: .4byte 0x00002E2C
_08090218: .4byte 0x00002E8C
_0809021C: .4byte 0x00002EEC
_08090220: .4byte 0x00002F4C
_08090224: .4byte 0x0000403C
_08090228: .4byte 0x0000403D
_0809022C: .4byte 0x0000403E
_08090230: .4byte 0x0000403F
_08090234: .4byte 0x0000402C
_08090238: .4byte 0x00004038
_0809023C: .4byte 0x00004039
_08090240: .4byte 0xFFFFFDFF
_08090244:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r7]
	b _080902A4
_0809024E:
	ldr r0, _08090294 @ =0x00004050
	adds r3, r5, r0
	mov r1, sl
	ldrb r0, [r1]
	ldrh r2, [r3]
	cmp r0, r2
	beq _080902A4
	movs r1, #6
	ldrsb r1, [r4, r1]
	ldr r0, [sp, #0xc]
	ldr r2, [r0]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r6, [r3]
	lsls r0, r6, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _080902A4
	mov r1, sb
	strb r6, [r1]
	ldr r1, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7]
	movs r0, #6
	ldrsb r0, [r4, r0]
	ldrh r3, [r3]
	cmp r0, r3
	bne _0809029C
	ldr r0, _08090298 @ =0xFFFFFDFF
	ands r1, r0
	b _080902A2
	.align 2, 0
_08090294: .4byte 0x00004050
_08090298: .4byte 0xFFFFFDFF
_0809029C:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
_080902A2:
	str r1, [r7]
_080902A4:
	movs r1, #7
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090374
	adds r0, r1, #0
	ldr r2, _080902F0 @ =0x0000402C
	adds r7, r5, r2
	ldr r1, [r7]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _0809030A
	ldrb r1, [r4, #7]
	ldr r2, _080902F4 @ =0x0000403D
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _080902F8 @ =0x00002E8C
	adds r3, r5, r0
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08090300
	ldr r0, _080902FC @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r3]
	b _08090374
	.align 2, 0
_080902F0: .4byte 0x0000402C
_080902F4: .4byte 0x0000403D
_080902F8: .4byte 0x00002E8C
_080902FC: .4byte 0xFFFFFDFF
_08090300:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r3]
	b _08090374
_0809030A:
	ldr r1, _08090358 @ =0x00004038
	adds r0, r5, r1
	ldr r2, _0809035C @ =0x00004050
	adds r6, r5, r2
	ldrb r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	beq _08090374
	movs r1, #7
	ldrsb r1, [r4, r1]
	ldr r2, [r7]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r3, [r6]
	lsls r0, r3, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08090374
	ldr r2, _08090360 @ =0x0000403D
	adds r0, r5, r2
	strb r3, [r0]
	ldr r0, _08090364 @ =0x00002E8C
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #7
	ldrsb r0, [r4, r0]
	ldrh r6, [r6]
	cmp r0, r6
	bne _0809036C
	ldr r0, _08090368 @ =0xFFFFFDFF
	ands r1, r0
	b _08090372
	.align 2, 0
_08090358: .4byte 0x00004038
_0809035C: .4byte 0x00004050
_08090360: .4byte 0x0000403D
_08090364: .4byte 0x00002E8C
_08090368: .4byte 0xFFFFFDFF
_0809036C:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
_08090372:
	str r1, [r2]
_08090374:
	movs r1, #8
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090444
	adds r0, r1, #0
	ldr r1, _080903C0 @ =0x0000402C
	adds r7, r5, r1
	ldr r1, [r7]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _080903DA
	ldrb r1, [r4, #8]
	ldr r2, _080903C4 @ =0x0000403E
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _080903C8 @ =0x00002EEC
	adds r3, r5, r0
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080903D0
	ldr r0, _080903CC @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r3]
	b _08090444
	.align 2, 0
_080903C0: .4byte 0x0000402C
_080903C4: .4byte 0x0000403E
_080903C8: .4byte 0x00002EEC
_080903CC: .4byte 0xFFFFFDFF
_080903D0:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r3]
	b _08090444
_080903DA:
	ldr r1, _08090428 @ =0x00004038
	adds r0, r5, r1
	ldr r2, _0809042C @ =0x00004050
	adds r6, r5, r2
	ldrb r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	beq _08090444
	movs r1, #8
	ldrsb r1, [r4, r1]
	ldr r2, [r7]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r3, [r6]
	lsls r0, r3, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	bne _08090444
	ldr r2, _08090430 @ =0x0000403E
	adds r0, r5, r2
	strb r3, [r0]
	ldr r0, _08090434 @ =0x00002EEC
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #8
	ldrsb r0, [r4, r0]
	ldrh r6, [r6]
	cmp r0, r6
	bne _0809043C
	ldr r0, _08090438 @ =0xFFFFFDFF
	ands r1, r0
	b _08090442
	.align 2, 0
_08090428: .4byte 0x00004038
_0809042C: .4byte 0x00004050
_08090430: .4byte 0x0000403E
_08090434: .4byte 0x00002EEC
_08090438: .4byte 0xFFFFFDFF
_0809043C:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
_08090442:
	str r1, [r2]
_08090444:
	movs r1, #9
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08090452
	b _08090682
_08090452:
	adds r0, r1, #0
	ldr r1, _08090494 @ =0x0000402C
	adds r7, r5, r1
	ldr r1, [r7]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _080904A0
	ldrb r1, [r4, #9]
	ldr r2, _08090498 @ =0x0000403F
	adds r0, r5, r2
	strb r1, [r0]
	ldr r0, _0809049C @ =0x00002F4C
	adds r3, r5, r0
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0809048A
	b _0809060A
_0809048A:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	str r2, [r3]
	b _08090682
	.align 2, 0
_08090494: .4byte 0x0000402C
_08090498: .4byte 0x0000403F
_0809049C: .4byte 0x00002F4C
_080904A0:
	ldr r1, _080904F4 @ =0x00004038
	adds r0, r5, r1
	ldr r2, _080904F8 @ =0x00004050
	adds r6, r5, r2
	ldrb r0, [r0]
	ldrh r1, [r6]
	cmp r0, r1
	bne _080904B2
	b _08090682
_080904B2:
	movs r1, #9
	ldrsb r1, [r4, r1]
	ldr r2, [r7]
	lsls r1, r1, #4
	adds r1, r1, r2
	ldrh r3, [r6]
	lsls r0, r3, #4
	adds r0, r0, r2
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080904CC
	b _08090682
_080904CC:
	ldr r2, _080904FC @ =0x0000403F
	adds r0, r5, r2
	strb r3, [r0]
	ldr r0, _08090500 @ =0x00002F4C
	adds r2, r5, r0
	ldr r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	movs r0, #9
	ldrsb r0, [r4, r0]
	ldrh r6, [r6]
	cmp r0, r6
	bne _08090508
	ldr r0, _08090504 @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r2]
	b _08090682
	.align 2, 0
_080904F4: .4byte 0x00004038
_080904F8: .4byte 0x00004050
_080904FC: .4byte 0x0000403F
_08090500: .4byte 0x00002F4C
_08090504: .4byte 0xFFFFFDFF
_08090508:
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
	str r1, [r2]
	b _08090682
_08090512:
	movs r1, #0xb
	ldrsb r1, [r4, r1]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _08090570
	adds r0, r1, #0
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	bne _08090530
	b _08090682
_08090530:
	ldrb r0, [r4, #0xb]
	mov r1, sb
	strb r0, [r1]
	ldr r2, [r7]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r7]
	ldrb r1, [r4, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08090564
	movs r1, #6
	ldrsb r1, [r4, r1]
	movs r0, #0xb
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _08090564
	ldr r0, _08090560 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r7]
	b _08090682
	.align 2, 0
_08090560: .4byte 0xFFFFFDFF
_08090564:
	ldr r2, _0809056C @ =0x00002E2C
	adds r0, r5, r2
	b _08090678
	.align 2, 0
_0809056C: .4byte 0x00002E2C
_08090570:
	movs r0, #0xc
	ldrsb r0, [r4, r0]
	cmp r0, r1
	beq _080905C8
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	bne _08090588
	b _08090682
_08090588:
	ldrb r0, [r4, #0xc]
	ldr r1, [sp]
	strb r0, [r1]
	ldr r2, [r6]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r6]
	ldrb r1, [r4, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080905BC
	movs r1, #7
	ldrsb r1, [r4, r1]
	movs r0, #0xc
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _080905BC
	ldr r0, _080905B8 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r6]
	b _08090682
	.align 2, 0
_080905B8: .4byte 0xFFFFFDFF
_080905BC:
	ldr r2, _080905C4 @ =0x00002E8C
	adds r0, r5, r2
	b _08090678
	.align 2, 0
_080905C4: .4byte 0x00002E8C
_080905C8:
	movs r1, #0xd
	ldrsb r1, [r4, r1]
	cmp r1, r0
	beq _08090624
	adds r0, r1, #0
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	str r3, [sp, #0x10]
	bl FUN_0808fd2c
	ldr r3, [sp, #0x10]
	cmp r0, #0
	beq _08090682
	ldrb r0, [r4, #0xd]
	ldr r1, [sp, #4]
	strb r0, [r1]
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrb r1, [r4, #0xa]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08090618
	movs r1, #8
	ldrsb r1, [r4, r1]
	movs r0, #0xd
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _08090618
_0809060A:
	ldr r0, _08090614 @ =0xFFFFFDFF
	ands r2, r0
	str r2, [r3]
	b _08090682
	.align 2, 0
_08090614: .4byte 0xFFFFFDFF
_08090618:
	ldr r2, _08090620 @ =0x00002EEC
	adds r0, r5, r2
	b _08090678
	.align 2, 0
_08090620: .4byte 0x00002EEC
_08090624:
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	cmp r0, r1
	beq _08090682
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _08090682
	ldrb r0, [r4, #0xe]
	ldr r1, [sp, #8]
	strb r0, [r1]
	mov r0, r8
	ldr r2, [r0]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	mov r1, r8
	str r2, [r1]
	ldrb r1, [r4, #0xa]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08090674
	movs r1, #9
	ldrsb r1, [r4, r1]
	movs r0, #0xe
	ldrsb r0, [r4, r0]
	cmp r1, r0
	bne _08090674
	ldr r0, _08090670 @ =0xFFFFFDFF
	ands r2, r0
	mov r0, r8
	str r2, [r0]
	b _08090682
	.align 2, 0
_08090670: .4byte 0xFFFFFDFF
_08090674:
	ldr r1, _08090694 @ =0x00002F4C
	adds r0, r5, r1
_08090678:
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r0]
_08090682:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090694: .4byte 0x00002F4C

	thumb_func_start FUN_08090698
FUN_08090698: @ 0x08090698
	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r0, _080906C4 @ =0x0000E002
	adds r7, r0, #0
_080906A0:
	movs r4, #0
	adds r6, r5, #1
_080906A4:
	movs r0, #1
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0808a420
	strh r7, [r0]
	adds r4, #1
	cmp r4, #0x1f
	ble _080906A4
	adds r5, r6, #0
	cmp r5, #0x1f
	ble _080906A0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080906C4: .4byte 0x0000E002

	thumb_func_start FUN_080906c8
FUN_080906c8: @ 0x080906C8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08090700 @ =0x00004039
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0809070C
	ldr r1, [r4, #0x28]
	ldr r2, _08090704 @ =0x00004038
	adds r0, r4, r2
	ldrb r0, [r0]
	ldr r3, _08090708 @ =0x0000402C
	adds r2, r4, r3
	ldr r2, [r2]
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r2, [r0, #1]
	movs r0, #1
	bl FUN_0822c398
	adds r0, r4, #0
	bl FUN_0808ff84
	adds r0, r4, #0
	bl FUN_08090148
	b _0809071E
	.align 2, 0
_08090700: .4byte 0x00004039
_08090704: .4byte 0x00004038
_08090708: .4byte 0x0000402C
_0809070C:
	adds r0, r4, #0
	bl FUN_08090698
	adds r0, r4, #0
	bl FUN_08090004
	adds r0, r4, #0
	bl FUN_08090148
_0809071E:
	pop {r4}
	pop {r0}
	bx r0
