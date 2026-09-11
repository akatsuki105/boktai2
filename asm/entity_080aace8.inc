	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

	thumb_func_start FUN_080aa708
FUN_080aa708: @ 0x080AA708
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080AA7EC @ =0x0000034A
	adds r0, r0, r7
	mov sl, r0
	ldrh r0, [r0]
	adds r0, #1
	mov r1, sl
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080AA784
	ldrh r0, [r1]
	movs r5, #8
	subs r5, r5, r0
	ldr r2, _080AA7F0 @ =0x0203B400
	mov sb, r2
	ldr r4, _080AA7F4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080AA7F8 @ =0x000003FF
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
	mov r2, r8
	ands r0, r2
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
_080AA784:
	mov r1, sl
	ldrh r0, [r1]
	cmp r0, #0x1e
	bne _080AA7A0
	adds r0, r7, #0
	bl FUN_080aa0e4
	ldr r0, _080AA7FC @ =0x00000285
	bl PlaySound_082406e0
	ldr r0, [r7, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x24]
_080AA7A0:
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r1, [r0]
	cmp r1, #1
	bne _080AA7CA
	mov r2, sl
	ldrh r0, [r2]
	cmp r0, #0x1d
	bne _080AA7CA
	movs r0, #4
	str r0, [sp]
	ldr r0, _080AA800 @ =0x00001FFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080AA7CA:
	ldr r1, _080AA7EC @ =0x0000034A
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0x2c
	bls _080AA81A
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AA808
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, _080AA804 @ =FUN_080aa5d0
	b _080AA810
	.align 2, 0
_080AA7EC: .4byte 0x0000034A
_080AA7F0: .4byte 0x0203B400
_080AA7F4: .4byte 0x030046B8
_080AA7F8: .4byte 0x000003FF
_080AA7FC: .4byte 0x00000285
_080AA800: .4byte 0x00001FFF
_080AA804: .4byte FUN_080aa5d0
_080AA808:
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080AA82C @ =FUN_080aa658
_080AA810:
	str r0, [r1]
	ldr r0, _080AA830 @ =0x0000034A
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
_080AA81A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AA82C: .4byte FUN_080aa658
_080AA830: .4byte 0x0000034A

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

	thumb_func_start FUN_080aa8f8
FUN_080aa8f8: @ 0x080AA8F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x1c
	bl FUN_0822f1c0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #7
_080AA90A:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080AA90A
	movs r1, #0xd2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AA938
	adds r4, r6, #0
	adds r4, #0xe4
	movs r5, #1
_080AA92A:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080AA92A
_080AA938:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080aa940
FUN_080aa940: @ 0x080AA940
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r0, _080AA9C8 @ =0x0000CB05
	ldr r1, _080AA9CC @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	add r2, sp, #0x10
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	add r0, sp, #0x10
	bl OpenSpriteSetFile
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
	bl Video_GetActorSprite
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
	bl Video_SetActorSpritePltt
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
	bl GetParticleGroup
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

