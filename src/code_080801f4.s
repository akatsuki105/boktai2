	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080801f4
FUN_080801f4: @ 0x080801F4
	movs r3, #0xca
	lsls r3, r3, #1
	adds r2, r0, r3
	str r1, [r2]
	adds r0, #0xca
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_08080204
FUN_08080204: @ 0x08080204
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r3, [r0, #0x18]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	mov r2, ip
	str r0, [r2, #0x38]
	str r1, [r2, #0x3c]
	mov r0, ip
	adds r0, #0xbc
	ldrh r0, [r0]
	ldrh r4, [r2, #0x3a]
	adds r0, r0, r4
	strh r0, [r2, #0x3a]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r7, r0, #5
	ldr r1, _08080270 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r6, [r0, r4]
	adds r0, r7, #0
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r5, [r0, r2]
	ldr r4, _08080274 @ =0x000002E7
	adds r3, r3, r4
	ldrb r0, [r3]
	mov r8, r1
	cmp r0, #0
	beq _080802D8
	mov r1, ip
	adds r1, #0xbe
	ldrh r0, [r1]
	muls r0, r6, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _08080278
	asrs r0, r0, #0xc
	b _0808027E
	.align 2, 0
_08080270: .4byte 0x085B0A08
_08080274: .4byte 0x000002E7
_08080278:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808027E:
	adds r4, r0, #0
	mov r1, ip
	adds r1, #0xc0
	ldrh r0, [r1]
	muls r0, r5, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _08080292
	asrs r0, r0, #0xc
	b _08080298
_08080292:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080298:
	adds r0, r4, r0
	mov r1, ip
	ldrh r1, [r1, #0x38]
	adds r0, r0, r1
	mov r4, ip
	strh r0, [r4, #0x38]
	ldrh r0, [r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _080802B0
	asrs r0, r0, #0xc
	b _080802B6
_080802B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080802B6:
	adds r1, r0, #0
	ldrh r0, [r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _080802C4
	asrs r0, r0, #0xc
	b _080802CA
_080802C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080802CA:
	subs r0, r1, r0
	mov r1, ip
	ldrh r1, [r1, #0x3c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x3c]
	b _08080348
_080802D8:
	mov r1, ip
	adds r1, #0xbe
	ldrh r0, [r1]
	muls r0, r6, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _080802EA
	asrs r0, r0, #0xc
	b _080802F0
_080802EA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080802F0:
	adds r4, r0, #0
	mov r1, ip
	adds r1, #0xc0
	ldrh r0, [r1]
	muls r0, r5, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _08080304
	asrs r0, r0, #0xc
	b _0808030A
_08080304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808030A:
	subs r0, r4, r0
	mov r4, ip
	ldrh r4, [r4, #0x38]
	adds r0, r0, r4
	mov r1, ip
	strh r0, [r1, #0x38]
	ldrh r0, [r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08080322
	asrs r0, r0, #0xc
	b _08080328
_08080322:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080328:
	adds r1, r0, #0
	ldrh r0, [r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08080336
	asrs r0, r0, #0xc
	b _0808033C
_08080336:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808033C:
	adds r0, r1, r0
	mov r2, ip
	ldrh r2, [r2, #0x3c]
	adds r0, r0, r2
	mov r4, ip
	strh r0, [r4, #0x3c]
_08080348:
	movs r2, #0xff
	lsrs r0, r7, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, ip
	adds r0, #0xc8
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r1, ip
	adds r1, #0xc2
	ldrh r0, [r1]
	muls r0, r2, r0
	adds r3, r1, #0
	cmp r0, #0
	blt _08080378
	asrs r2, r0, #0xc
	b _0808037E
_08080378:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0808037E:
	mov r0, ip
	adds r0, #0xb4
	strh r2, [r0]
	lsls r0, r7, #1
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08080398
	asrs r1, r0, #0xc
	b _0808039E
_08080398:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808039E:
	mov r0, ip
	adds r0, #0xb8
	strh r1, [r0]
	subs r0, #0x12
	strb r7, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080803b4
FUN_080803b4: @ 0x080803B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	mov sl, r0
	movs r0, #0xff
	mov r8, r0
	ldr r1, _08080410 @ =0x085B0A08
	mov sb, r1
	mov ip, r5
	movs r7, #0
	mov r3, ip
	adds r3, #0xec
	movs r6, #3
_080803E0:
	ldrb r0, [r3, #0x10]
	cmp r0, #0
	beq _08080482
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	adds r0, #1
	movs r2, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _08080414
	strb r2, [r3, #0x10]
	adds r0, r5, #0
	adds r0, #0xd4
	adds r0, r0, r7
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _08080482
	.align 2, 0
_08080410: .4byte 0x085B0A08
_08080414:
	ldrh r2, [r3, #0x12]
	ldrh r1, [r1]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r4, r0, #3
	movs r0, #0x11
	ldrsb r0, [r3, r0]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	mov r1, sl
	adds r2, r1, r0
	mov r0, r8
	ands r2, r0
	ldr r0, [r5, #0x38]
	ldr r1, [r5, #0x3c]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, r8
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080454
	asrs r1, r0, #0xc
	b _0808045A
_08080454:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808045A:
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080476
	asrs r1, r0, #0xc
	b _0808047C
_08080476:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808047C:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
_08080482:
	movs r0, #0x30
	add ip, r0
	adds r7, #0x30
	adds r3, #0x30
	subs r6, #1
	cmp r6, #0
	bge _080803E0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080804a0
FUN_080804a0: @ 0x080804A0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0xcc
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xfc
	movs r3, #0
	movs r1, #1
	strb r1, [r0]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r1, r7, #0
	adds r1, #0xd4
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	movs r1, #0x80
	lsls r1, r1, #1
	mov sb, r1
	add r0, sb
	strh r3, [r0]
	ldr r0, _08080594 @ =0x0203B400
	mov r8, r0
	ldr r6, _08080598 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r5, _0808059C @ =0x000003FF
	ands r1, r5
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrb r3, [r4]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r0, r7, r0
	asrs r2, r2, #3
	movs r3, #0x7f
	ands r2, r3
	adds r2, #0x40
	adds r0, #0xfe
	strh r2, [r0]
	adds r1, #1
	ands r1, r5
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	movs r1, #0x60
	bl Mod
	ldrb r2, [r4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r7, r1
	subs r0, #0x30
	adds r1, #0xfd
	strb r0, [r1]
	adds r0, r7, #0
	adds r0, #0xc8
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldrb r0, [r4]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #4
	adds r2, r7, r2
	adds r0, r2, #0
	adds r0, #0xfd
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	add r0, sb
	adds r5, r5, r0
	movs r3, #0xff
	ands r5, r3
	adds r2, #0xec
	ldr r0, [r7, #0x38]
	ldr r1, [r7, #0x3c]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xfe
	ldrh r2, [r0]
	ldr r1, _080805A0 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080805A4
	asrs r2, r0, #0xc
	b _080805AA
	.align 2, 0
_08080594: .4byte 0x0203B400
_08080598: .4byte 0x030046B8
_0808059C: .4byte 0x000003FF
_080805A0: .4byte 0x085B0A08
_080805A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080805AA:
	adds r3, r7, #0
	adds r3, #0xcc
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xfe
	ldrh r2, [r0]
	ldr r1, _080805E4 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080805E8
	asrs r2, r0, #0xc
	b _080805EE
	.align 2, 0
_080805E4: .4byte 0x085B0A08
_080805E8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080805EE:
	ldrb r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r0, r7, r0
	adds r0, #0xf0
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _08080612
	movs r0, #0
	strb r0, [r3]
_08080612:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08080620
FUN_08080620: @ 0x08080620
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #1
	adds r1, r0, #0
	adds r1, #0xd4
	adds r2, r0, #0
	adds r2, #0xfc
	movs r3, #3
_08080630:
	strb r5, [r2]
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x30
	adds r2, #0x30
	subs r3, #1
	cmp r3, #0
	bge _08080630
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08080648
FUN_08080648: @ 0x08080648
	push {lr}
	adds r0, r2, #0
	ldr r1, _08080658 @ =FUN_0808094c
	bl FUN_080801f4
	pop {r0}
	bx r0
	.align 2, 0
_08080658: .4byte FUN_0808094c

	thumb_func_start FUN_0808065c
FUN_0808065c: @ 0x0808065C
	push {r4, lr}
	adds r2, r0, #0
	ldr r0, _0808069C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _08080688
	adds r0, r2, #0
	adds r0, #0xc4
	ldrh r3, [r0]
	ldr r0, _080806A0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _08080688
	movs r4, #0xa0
	lsls r4, r4, #1
	adds r1, r0, r4
	ldr r0, [r1]
	adds r0, r0, r3
	str r0, [r1]
_08080688:
	ldr r0, [r2, #0x18]
	adds r1, r2, #0
	adds r1, #0xc4
	ldrh r1, [r1]
	bl Player_ReduceENE_0807aa60
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808069C: .4byte 0x030047A4
_080806A0: .4byte 0x03002C68

	thumb_func_start FUN_080806a4
FUN_080806a4: @ 0x080806A4
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xcd
	ldrb r0, [r0]
	cmp r0, #0
	beq _080806B4
	movs r0, #8
	b _080806E4
_080806B4:
	ldr r0, _080806CC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080806D0
	ldr r0, [r4, #0x18]
	bl FUN_080d1b04
	b _080806D6
	.align 2, 0
_080806CC: .4byte 0x030047A4
_080806D0:
	ldr r0, [r4, #0x18]
	bl FUN_0806f900
_080806D6:
	adds r1, r0, #0
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #1
	adds r0, r1, r0
_080806E4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080806ec
FUN_080806ec: @ 0x080806EC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r5, [r0]
	cmp r5, #3
	beq _08080706
	adds r0, r4, #0
	bl KillEntity
	b _080807EE
_08080706:
	adds r0, r4, #0
	bl FUN_08080204
	ldr r0, [r4, #0x18]
	ldr r1, _0808074C @ =0x0000037D
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08080754
	adds r0, r4, #0
	bl FUN_08080620
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl FUN_080806a4
	adds r1, r4, #0
	adds r1, #0x64
	strh r0, [r1, #0x3c]
	adds r0, r4, #0
	bl FUN_0808065c
	ldr r1, _08080750 @ =FUN_080808cc
	adds r0, r4, #0
	bl FUN_080801f4
	b _080807EE
	.align 2, 0
_0808074C: .4byte 0x0000037D
_08080750: .4byte FUN_080808cc
_08080754:
	adds r0, r4, #0
	bl FUN_080803b4
	ldr r0, [r4, #0x18]
	ldr r1, _0808077C @ =0x0000037D
	adds r0, r0, r1
	ldrb r2, [r0]
	cmp r2, #2
	bne _08080780
	adds r1, r4, #0
	adds r1, #0xca
	ldrh r0, [r1]
	ands r5, r0
	adds r6, r4, #0
	adds r6, #0xc9
	adds r7, r1, #0
	cmp r5, #3
	bne _080807C2
	b _080807A0
	.align 2, 0
_0808077C: .4byte 0x0000037D
_08080780:
	cmp r2, #3
	bne _080807A8
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r1, r4, #0
	adds r1, #0xca
	ldrh r0, [r1]
	ands r2, r0
	adds r6, r4, #0
	adds r6, #0xc9
	adds r7, r1, #0
	cmp r2, #3
	bne _080807C2
_080807A0:
	adds r0, r4, #0
	bl FUN_080804a0
	b _080807C2
_080807A8:
	adds r1, r4, #0
	adds r1, #0xc9
	ldrb r0, [r1]
	adds r6, r1, #0
	adds r7, r4, #0
	adds r7, #0xca
	cmp r0, #0
	beq _080807C2
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
_080807C2:
	ldr r0, [r4, #0x18]
	ldr r1, _080807E0 @ =0x00000A8F
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6]
	ldrh r0, [r7]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080807E4
	ldrb r0, [r6]
	adds r0, #1
	b _080807E6
	.align 2, 0
_080807E0: .4byte 0x00000A8F
_080807E4:
	ldrb r0, [r6]
_080807E6:
	strh r0, [r4, #0x2c]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
_080807EE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080807f4
FUN_080807f4: @ 0x080807F4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r6, [r0]
	cmp r6, #3
	bne _08080868
	adds r0, r4, #0
	bl FUN_08080204
	ldr r0, [r4, #0x18]
	ldr r5, _08080850 @ =0x0000037D
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #5
	bne _08080858
	adds r0, r4, #0
	bl FUN_08080620
	ldr r0, [r4, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	adds r0, #1
	strh r0, [r4, #0x2c]
	adds r0, r4, #0
	bl FUN_080806a4
	adds r1, r4, #0
	adds r1, #0x64
	strh r0, [r1, #0x3c]
	adds r0, r4, #0
	bl FUN_0808065c
	ldr r1, _08080854 @ =FUN_080808cc
	adds r0, r4, #0
	bl FUN_080801f4
	b _080808C0
	.align 2, 0
_08080850: .4byte 0x0000037D
_08080854: .4byte FUN_080808cc
_08080858:
	cmp r0, #8
	bne _08080870
	adds r0, r4, #0
	bl FUN_08080620
	adds r0, r4, #0
	bl FUN_0808065c
_08080868:
	adds r0, r4, #0
	bl KillEntity
	b _080808C0
_08080870:
	adds r0, r4, #0
	bl FUN_080803b4
	ldr r0, [r4, #0x18]
	adds r0, r0, r5
	ldrb r1, [r0]
	cmp r1, #2
	bne _08080896
	adds r1, r4, #0
	adds r1, #0xca
	ldrh r0, [r1]
	ands r6, r0
	adds r5, r1, #0
	cmp r6, #3
	bne _080808AC
	adds r0, r4, #0
	bl FUN_080804a0
	b _080808AC
_08080896:
	adds r5, r4, #0
	adds r5, #0xca
	cmp r1, #3
	bne _080808AC
	ldrh r0, [r5]
	ands r1, r0
	cmp r1, #3
	bne _080808AC
	adds r0, r4, #0
	bl FUN_080804a0
_080808AC:
	ldr r0, [r4, #0x18]
	ldr r1, _080808C8 @ =0x00000A8F
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0xc9
	strb r1, [r0]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080808C0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080808C8: .4byte 0x00000A8F

	thumb_func_start FUN_080808cc
FUN_080808cc: @ 0x080808CC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	ldrh r1, [r6, #0x38]
	adds r0, r0, r1
	strh r0, [r6, #0x38]
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	ldrh r2, [r6, #0x3c]
	adds r0, r0, r2
	strh r0, [r6, #0x3c]
	adds r4, r6, #0
	adds r4, #0x64
	adds r5, r6, #0
	adds r5, #0x38
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldr r2, [r6, #0x18]
	ldr r1, _08080924 @ =0x00080002
	ldr r0, [r2, #0x20]
	orrs r0, r1
	str r0, [r2, #0x20]
	adds r0, r5, #0
	bl FUN_082328ec
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0x3a
	ldrsh r1, [r6, r2]
	cmp r0, r1
	ble _0808092C
	ldr r1, _08080928 @ =FUN_0808094c
	adds r0, r6, #0
	bl FUN_080801f4
	b _08080944
	.align 2, 0
_08080924: .4byte 0x00080002
_08080928: .4byte FUN_0808094c
_0808092C:
	adds r1, r6, #0
	adds r1, #0xca
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _08080944
	adds r0, r6, #0
	bl KillEntity
_08080944:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808094c
FUN_0808094c: @ 0x0808094C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xca
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08080968
	movs r0, #4
	strh r0, [r2, #0x2c]
	b _080809D4
_08080968:
	cmp r0, #4
	bne _080809CA
	adds r0, r2, #0
	adds r0, #0xc8
	adds r2, #0x1c
	ldrb r1, [r0]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _08080982
	movs r0, #7
	b _08080990
_08080982:
	asrs r0, r1, #1
	ands r0, r3
	cmp r0, #0
	beq _0808098E
	movs r0, #8
	b _08080990
_0808098E:
	movs r0, #6
_08080990:
	strh r0, [r2, #0x10]
	cmp r1, #2
	bgt _0808099E
	ldr r0, [r2]
	movs r1, #0xd
	rsbs r1, r1, #0
	b _080809C4
_0808099E:
	cmp r1, #4
	bgt _080809AE
	ldr r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #8
	b _080809B6
_080809AE:
	cmp r1, #5
	bgt _080809BC
	ldr r0, [r2]
	movs r1, #0xc
_080809B6:
	orrs r0, r1
	str r0, [r2]
	b _080809D4
_080809BC:
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	subs r1, #0xd
_080809C4:
	ands r0, r1
	str r0, [r2]
	b _080809D4
_080809CA:
	cmp r0, #6
	bls _080809D4
	adds r0, r2, #0
	bl KillEntity
_080809D4:
	pop {r0}
	bx r0

	thumb_func_start FUN_080809d8
FUN_080809d8: @ 0x080809D8
	push {lr}
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080809ec
FUN_080809ec: @ 0x080809EC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl FUN_0822a4e0
	adds r4, #0xd4
	movs r5, #3
_080809FA:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080809FA
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08080a10
FUN_08080a10: @ 0x08080A10
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r4, #0
	adds r5, #0x48
	ldr r1, _08080A40 @ =0x0000210E
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #0
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	adds r1, r6, #0
	bl Video_SetActorSpritePltt
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08080A40: .4byte 0x0000210E

	thumb_func_start FUN_08080a44
FUN_08080a44: @ 0x08080A44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r4, r0, #0
	mov r8, r1
	adds r6, r2, #0
	adds r7, r3, #0
	adds r5, r4, #0
	adds r5, #0x64
	ldr r3, _08080A84 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r3
	movs r2, #0x1e
	orrs r0, r2
	ldr r1, _08080A88 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r0, #0xcd
	ldrb r0, [r0]
	cmp r0, #0
	beq _08080A8C
	str r1, [sp, #0x14]
	b _08080A8E
	.align 2, 0
_08080A84: .4byte 0xFFFF0000
_08080A88: .4byte 0x0000FFFF
_08080A8C:
	str r0, [sp, #0x14]
_08080A8E:
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	str r0, [r1, #4]
	adds r3, r1, #0
	ldr r2, _08080AEC @ =0x00002101
	ldr r1, [r4, #0x18]
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r1, #0
	mov r2, r8
	movs r3, #0x10
	bl FUN_082364f8
	ldr r1, _08080AF0 @ =FUN_08080648
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r1, r4, #0
	adds r1, #0x38
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080AEC: .4byte 0x00002101
_08080AF0: .4byte FUN_08080648

	thumb_func_start FUN_08080af4
FUN_08080af4: @ 0x08080AF4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	mov sb, r1
	adds r1, r4, #0
	adds r1, #0xcc
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08080B64 @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r4, #0
	adds r1, #0xd0
	str r0, [r1]
	adds r6, r1, #0
	adds r5, r4, #0
	adds r5, #0xfc
	adds r4, #0xd4
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	movs r7, #3
_08080B24:
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	mov r1, r8
	mov r2, r8
	bl FUN_0822dad4
	ldr r1, [r6]
	adds r0, r4, #0
	mov r2, sb
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #0
	strb r0, [r5]
	adds r5, #0x30
	adds r4, #0x30
	subs r7, #1
	cmp r7, #0
	bge _08080B24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08080B64: .4byte 0x00001C1E

	thumb_func_start FUN_08080b68
FUN_08080b68: @ 0x08080B68
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r5, [sp, #0x14]
	ldr r4, [sp, #0x30]
	ldr r6, [sp, #0x34]
	str r1, [r7, #0x18]
	adds r0, #0xbc
	movs r1, #0
	strh r2, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r5, [r0]
	adds r0, #2
	mov r2, sp
	ldrh r2, [r2, #0x18]
	strh r2, [r0]
	adds r0, #2
	strh r4, [r0]
	adds r0, #5
	strb r1, [r0]
	adds r0, #4
	strb r6, [r0]
	adds r0, r7, #0
	ldr r1, [sp, #0x1c]
	bl FUN_08080a10
	adds r0, r7, #0
	ldr r1, [sp, #0x20]
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	bl FUN_08080a44
	adds r0, r7, #0
	bl FUN_08080204
	adds r0, r7, #0
	ldr r1, [sp, #0x2c]
	bl FUN_08080af4
	ldr r0, [r7, #0x18]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	beq _08080BD4
	ldr r1, _08080BD0 @ =FUN_080806ec
	adds r0, r7, #0
	bl FUN_080801f4
	b _08080BDC
	.align 2, 0
_08080BD0: .4byte FUN_080806ec
_08080BD4:
	ldr r1, _08080BE4 @ =FUN_080807f4
	adds r0, r7, #0
	bl FUN_080801f4
_08080BDC:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08080BE4: .4byte FUN_080807f4

	thumb_func_start FUN_08080be8
FUN_08080be8: @ 0x08080BE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xcc
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08080C54
	ldr r1, _08080C4C @ =FUN_080809d8
	ldr r2, _08080C50 @ =FUN_080809ec
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x40]
	str r0, [sp, #8]
	ldr r0, [sp, #0x44]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x48]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x20]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_08080b68
	cmp r0, #0
	bge _08080C54
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08080C56
	.align 2, 0
_08080C4C: .4byte FUN_080809d8
_08080C50: .4byte FUN_080809ec
_08080C54:
	adds r0, r4, #0
_08080C56:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08080c64
FUN_08080c64: @ 0x08080C64
	push {lr}
	adds r3, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _08080C90
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _08080C88 @ =0x000002E6
	adds r1, r3, r2
	strb r0, [r1]
	ldr r0, _08080C8C @ =0x000002E7
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	b _08080C9E
	.align 2, 0
_08080C88: .4byte 0x000002E6
_08080C8C: .4byte 0x000002E7
_08080C90:
	ldr r1, _08080CA4 @ =0x000002E6
	adds r0, r3, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08080CA8 @ =0x000002E7
	adds r0, r3, r2
	strb r1, [r0]
_08080C9E:
	pop {r0}
	bx r0
	.align 2, 0
_08080CA4: .4byte 0x000002E6
_08080CA8: .4byte 0x000002E7

	thumb_func_start FUN_08080cac
FUN_08080cac: @ 0x08080CAC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r2, #0
	movs r3, #0
	movs r0, #0xb9
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, r1
	bne _08080CC4
	movs r3, #1
_08080CC4:
	strh r1, [r2]
	adds r4, r6, #0
	adds r4, #0x88
	adds r5, r6, #0
	adds r5, #0x68
	ldr r2, _08080CFC @ =0x000002E6
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, r1, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08080D00 @ =0x000002E7
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08080D04
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _08080D10
	.align 2, 0
_08080CFC: .4byte 0x000002E6
_08080D00: .4byte 0x000002E7
_08080D04:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08080D10:
	str r1, [r0]
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082372cc
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08080d2c
FUN_08080d2c: @ 0x08080D2C
	push {r4, lr}
	mov ip, r0
	adds r4, r1, #0
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08080D60 @ =0x085B0A08
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
	blt _08080D64
	asrs r0, r0, #0xc
	b _08080D6A
	.align 2, 0
_08080D60: .4byte 0x085B0A08
_08080D64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080D6A:
	mov r1, ip
	strh r0, [r1, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080D80
	asrs r0, r0, #0xc
	b _08080D86
_08080D80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080D86:
	mov r1, ip
	strh r0, [r1, #0x38]
	ldr r3, _08080DAC @ =0x000001C7
	add r3, ip
	ldrb r3, [r3]
	cmp r3, #1
	bne _08080DCE
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08080DB0
	movs r2, #0x38
	ldrsh r1, [r1, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08080DBE
	b _08080DC2
	.align 2, 0
_08080DAC: .4byte 0x000001C7
_08080DB0:
	mov r2, ip
	movs r0, #0x38
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08080DC2
_08080DBE:
	asrs r0, r0, #6
	b _08080DC8
_08080DC2:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08080DC8:
	mov r1, ip
	strh r0, [r1, #0x38]
	b _08080E06
_08080DCE:
	cmp r3, #2
	bne _08080E06
	mov r2, ip
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _08080DEA
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08080DF8
	b _08080DFC
_08080DEA:
	mov r2, ip
	movs r0, #0x34
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08080DFC
_08080DF8:
	asrs r0, r0, #6
	b _08080E02
_08080DFC:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08080E02:
	mov r1, ip
	strh r0, [r1, #0x34]
_08080E06:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08080e0c
FUN_08080e0c: @ 0x08080E0C
	push {r4, lr}
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r3, r0, r4
	movs r4, #0
	strb r1, [r3]
	ldr r3, _08080E2C @ =0x0000037D
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _08080E30 @ =0x0000037E
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080E2C: .4byte 0x0000037D
_08080E30: .4byte 0x0000037E

	thumb_func_start FUN_08080e34
FUN_08080e34: @ 0x08080E34
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	str r0, [r4, #0x20]
	ldr r1, _08080EB4 @ =0x0000038E
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r1, _08080EB8 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08080E68
	adds r0, r4, #0
	bl FUN_0809e138
	cmp r0, #0
	beq _08080E68
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
_08080E68:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08080E84
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
_08080E84:
	ldr r1, _08080EBC @ =0x00000604
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08080EC0 @ =0x00000606
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r2, _08080EC4 @ =0x0000035A
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080EB4: .4byte 0x0000038E
_08080EB8: .4byte 0x030046A0
_08080EBC: .4byte 0x00000604
_08080EC0: .4byte 0x00000606
_08080EC4: .4byte 0x0000035A

	thumb_func_start FUN_08080ec8
FUN_08080ec8: @ 0x08080EC8
	ldr r2, _08080ED4 @ =0x0000035A
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08080ED4: .4byte 0x0000035A

	thumb_func_start FUN_08080ed8
FUN_08080ed8: @ 0x08080ED8
	ldr r2, _08080EE4 @ =0x0000035A
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	bx lr
	.align 2, 0
_08080EE4: .4byte 0x0000035A

	thumb_func_start FUN_08080ee8
FUN_08080ee8: @ 0x08080EE8
	push {lr}
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _08080EFE
	movs r0, #0xd8
	bl sound_08240740
	b _08080F10
_08080EFE:
	ldr r0, _08080F14 @ =0x00000239
	bl sound_08240740
	ldr r0, _08080F18 @ =0x00000202
	bl sound_08240740
	ldr r0, _08080F1C @ =0x00000366
	bl sound_08240740
_08080F10:
	pop {r0}
	bx r0
	.align 2, 0
_08080F14: .4byte 0x00000239
_08080F18: .4byte 0x00000202
_08080F1C: .4byte 0x00000366

	thumb_func_start FUN_08080f20
FUN_08080f20: @ 0x08080F20
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08080F3E
	adds r0, r2, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	b _08080F70
_08080F3E:
	movs r0, #0x24
	ldrsh r1, [r2, r0]
	movs r4, #0x24
	ldrsh r0, [r3, r4]
	subs r4, r1, r0
	movs r0, #0x28
	ldrsh r1, [r2, r0]
	movs r2, #0x28
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r4, #0
	bne _08080F66
	cmp r1, #0
	bne _08080F66
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	b _08080F70
_08080F66:
	adds r0, r4, #0
	bl FUN_0823785c
	adds r1, r0, #0
	adds r1, #0x60
_08080F70:
	movs r0, #0xff
	ands r1, r0
	asrs r0, r1, #6
	lsls r0, r0, #1
	adds r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08080f80
FUN_08080f80: @ 0x08080F80
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	adds r1, #0x40
	ldrh r0, [r1]
	adds r6, r5, #0
	adds r6, #0x40
	movs r7, #0
	strh r0, [r6]
	ldrh r0, [r1]
	cmp r0, #0xc8
	bls _08080F9E
	movs r0, #0xc8
	strh r0, [r6]
_08080F9E:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r2, [r3, #0x38]
	ands r2, r0
	cmp r2, #0
	beq _08080FC8
	ldr r0, _08080FC4 @ =0x000003D2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08080f20
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	b _08081098
	.align 2, 0
_08080FC4: .4byte 0x000003D2
_08080FC8:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08080FE0
	ldrh r0, [r5, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r5, #6]
	strh r2, [r6]
	b _0808109A
_08080FE0:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08081084
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08081014
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r1, r4, r2
	b _08081064
_08081014:
	movs r0, #0x24
	ldrsh r1, [r3, r0]
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	subs r2, r1, r0
	movs r0, #0x28
	ldrsh r1, [r3, r0]
	movs r3, #0x28
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _08081042
	cmp r1, #0
	bne _08081042
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _08081066
_08081042:
	adds r0, r2, #0
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #4
	ands r0, r1
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r4, r3
_08081064:
	strh r0, [r1]
_08081066:
	adds r3, r5, #0
	adds r3, #0x40
	ldrh r2, [r3]
	ldr r1, _08081080 @ =0x000003E6
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	strh r1, [r3]
	ldrh r1, [r5, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5, #6]
	b _0808109A
	.align 2, 0
_08081080: .4byte 0x000003E6
_08081084:
	ldr r2, _080810A0 @ =0x000003D2
	adds r0, r4, r2
	strb r7, [r0]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08080f20
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
_08081098:
	strb r0, [r1]
_0808109A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080810A0: .4byte 0x000003D2

	thumb_func_start FUN_080810a4
FUN_080810a4: @ 0x080810A4
	push {lr}
	adds r2, r0, #0
	ldr r1, _080810E8 @ =0x0000038E
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r1, _080810EC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bgt _080810E4
	movs r1, #0x80
	lsls r1, r1, #3
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080810E4
	bl FUN_0823e1b0
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _080810E4
	cmp r1, #0
	bne _080810F0
_080810E4:
	movs r0, #1
	b _080810F2
	.align 2, 0
_080810E8: .4byte 0x0000038E
_080810EC: .4byte 0x030046A0
_080810F0:
	movs r0, #0
_080810F2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080810f8
FUN_080810f8: @ 0x080810F8
	push {r4, lr}
	movs r4, #0
_080810FC:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bls _08081110
	adds r4, #1
	cmp r4, #0xf
	ble _080810FC
	movs r0, #0
_08081110:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08081118
FUN_08081118: @ 0x08081118
	push {lr}
	sub sp, #0xc
	adds r3, r1, #0
	ldr r1, _08081148 @ =0x000009C4
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08081142
	ldr r1, _0808114C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	str r3, [sp]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_08081142:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_08081148: .4byte 0x000009C4
_0808114C: .4byte 0xFFFF0000

	thumb_func_start FUN_08081150
FUN_08081150: @ 0x08081150
	ldr r2, _0808115C @ =0x000009BC
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_0808115C: .4byte 0x000009BC

	thumb_func_start FUN_08081160
FUN_08081160: @ 0x08081160
	ldr r2, _0808116C @ =0x000009BC
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	bx lr
	.align 2, 0
_0808116C: .4byte 0x000009BC

	thumb_func_start FUN_08081170
FUN_08081170: @ 0x08081170
	push {lr}
	movs r1, #0x9c
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08081184
	movs r1, #0
	bl Script_ExecById
_08081184:
	pop {r0}
	bx r0

	thumb_func_start FUN_08081188
FUN_08081188: @ 0x08081188
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	ldr r1, _080811CC @ =0x03003584
	ldr r3, _080811D0 @ =0x0000094C
	adds r0, r2, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	ldr r0, _080811D4 @ =0x0000094E
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080811D8
	movs r5, #0
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r1, r2, r3
_080811B2:
	subs r0, r5, #5
	cmp r0, #1
	bls _080811C0
	cmp r5, #0xd
	beq _080811C0
	ldrh r0, [r6]
	strh r0, [r1]
_080811C0:
	adds r6, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080811B2
	b _08081234
	.align 2, 0
_080811CC: .4byte 0x03003584
_080811D0: .4byte 0x0000094C
_080811D4: .4byte 0x0000094E
_080811D8:
	movs r5, #0
	mov r8, r1
	movs r0, #0xa9
	lsls r0, r0, #2
	adds r7, r2, r0
_080811E2:
	subs r0, r5, #5
	cmp r0, #1
	bls _0808122A
	cmp r5, #0xd
	beq _0808122A
	ldrh r1, [r6]
	movs r3, #0x1f
	mov ip, r3
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _08081202
	movs r4, #0x1f
_08081202:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _08081212
	movs r1, #0x1f
_08081212:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _08081220
	movs r0, #0x1f
_08081220:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
_0808122A:
	adds r6, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080811E2
_08081234:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08081240
FUN_08081240: @ 0x08081240
	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r1, #2
	ldr r0, _0808125C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _08081260 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08081264
	movs r0, #1
	b _08081266
	.align 2, 0
_0808125C: .4byte 0x030046A0
_08081260: .4byte 0x00000934
_08081264:
	movs r0, #0
_08081266:
	cmp r0, #0
	bne _08081278
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08081284
	movs r3, #8
	b _08081284
_08081278:
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08081284
	movs r3, #4
_08081284:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808128c
FUN_0808128c: @ 0x0808128C
	push {r4, lr}
	ldr r1, _080812C8 @ =0x03003584
	ldr r2, [r1]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r2, r2, r1
	movs r3, #0x95
	lsls r3, r3, #4
	adds r1, r0, r3
	ldrb r3, [r1]
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r2, r2, r1
	ldrh r3, [r2]
	ldr r4, _080812CC @ =0x000002AE
	adds r1, r0, r4
	strh r3, [r1]
	adds r2, #2
	ldrh r3, [r2]
	adds r4, #2
	adds r1, r0, r4
	strh r3, [r1]
	ldrh r1, [r2, #2]
	ldr r2, _080812D0 @ =0x000002BE
	adds r0, r0, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080812C8: .4byte 0x03003584
_080812CC: .4byte 0x000002AE
_080812D0: .4byte 0x000002BE

	thumb_func_start FUN_080812d4
FUN_080812d4: @ 0x080812D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp]
	mov ip, r2
	str r3, [sp, #4]
	cmp r2, #0
	bne _080812F8
	adds r1, r0, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [r1]
	b _080813BE
_080812F8:
	mov sl, r1
	movs r3, #0
	mov r8, r3
	ldr r7, [sp]
	adds r7, #0xd0
	str r7, [sp, #0xc]
	ldr r0, [sp]
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r6, r0, r1
	ldr r2, _08081324 @ =0x0000094E
	adds r2, r0, r2
	str r2, [sp, #8]
_08081312:
	mov r0, r8
	subs r0, #5
	cmp r0, #1
	bls _08081320
	mov r3, r8
	cmp r3, #0xd
	bne _08081328
_08081320:
	ldrh r0, [r6]
	b _080813A0
	.align 2, 0
_08081324: .4byte 0x0000094E
_08081328:
	mov r7, sl
	ldrh r2, [r7]
	movs r7, #0x1f
	movs r0, #0x1f
	mov sb, r0
	ands r0, r2
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _08081340
	movs r4, #0x1f
_08081340:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _0808134E
	movs r2, #0x1f
_0808134E:
	lsrs r0, r3, #0x1a
	ands r0, r7
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _0808135A
	movs r5, #0x1f
_0808135A:
	ldrh r1, [r6]
	mov r0, sb
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	adds r4, r7, #0
	ldr r7, [sp, #4]
	muls r0, r7, r0
	adds r4, r4, r0
	ldr r0, [sp, #0x30]
	asrs r4, r0
	mov r7, ip
	muls r7, r2, r7
	adds r2, r7, #0
	ldr r7, [sp, #4]
	adds r0, r3, #0
	muls r0, r7, r0
	adds r2, r2, r0
	ldr r0, [sp, #0x30]
	asrs r2, r0
	mov r0, ip
	muls r0, r5, r0
	muls r1, r7, r1
	adds r0, r0, r1
	ldr r1, [sp, #0x30]
	asrs r0, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
_080813A0:
	strh r0, [r6, #0x20]
	movs r2, #2
	add sl, r2
	adds r6, #2
	movs r3, #1
	add r8, r3
	mov r7, r8
	cmp r7, #0xf
	ble _08081312
	ldr r1, [sp]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r3, [sp, #0xc]
	str r0, [r3]
_080813BE:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080813d0
FUN_080813d0: @ 0x080813D0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, _08081450 @ =0x00000951
	adds r0, r4, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _080813F2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808128c
_080813F2:
	adds r0, r4, #0
	bl FUN_08081240
	adds r2, r0, #0
	ldr r6, _08081454 @ =0x0000094C
	adds r1, r4, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r5
	bne _08081410
	adds r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _0808141E
_08081410:
	strh r5, [r1]
	ldr r1, _08081458 @ =0x0000094E
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08081188
_0808141E:
	ldr r2, _0808145C @ =0x00000476
	adds r0, r4, r2
	ldrb r5, [r0]
	cmp r5, #0
	beq _0808148C
	ldr r0, _08081460 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x99
	lsls r3, r3, #6
	adds r5, r0, r3
	movs r3, #0
	adds r6, r4, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
_08081442:
	subs r0, r3, #5
	cmp r0, #1
	bls _0808144C
	cmp r3, #0xd
	bne _08081464
_0808144C:
	ldrh r0, [r2]
	b _08081466
	.align 2, 0
_08081450: .4byte 0x00000951
_08081454: .4byte 0x0000094C
_08081458: .4byte 0x0000094E
_0808145C: .4byte 0x00000476
_08081460: .4byte 0x03003584
_08081464:
	ldrh r0, [r5]
_08081466:
	strh r0, [r1]
	adds r5, #2
	adds r1, #2
	adds r2, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08081442
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r6]
	ldr r2, _08081488 @ =0x00000476
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0808159C
	.align 2, 0
_08081488: .4byte 0x00000476
_0808148C:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	bne _08081512
	ldr r6, _080814D4 @ =0x00000964
	adds r3, r4, r6
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _08081502
	ldr r1, _080814D8 @ =0x03003584
	subs r6, #2
	adds r0, r4, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080814C6
	movs r0, #0x30
	strh r0, [r3]
_080814C6:
	ldrh r0, [r3]
	cmp r0, #0x1f
	bhi _080814DC
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _080814F0
	.align 2, 0
_080814D4: .4byte 0x00000964
_080814D8: .4byte 0x03003584
_080814DC:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _080814F0
	strh r5, [r3]
_080814F0:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080812d4
	b _0808159C
_08081502:
	strh r5, [r3]
	adds r1, r4, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r0, [r1]
	b _0808159C
_08081512:
	ldr r3, _0808154C @ =0x00000964
	adds r0, r4, r3
	strh r5, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _08081572
	ldr r1, _08081550 @ =0x03003584
	ldr r6, _08081554 @ =0x0000095E
	adds r0, r4, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r5, r1, r0
	movs r1, #0
	adds r6, r4, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r4, r0
	subs r0, #0x20
	adds r3, r4, r0
_0808153C:
	subs r0, r1, #5
	cmp r0, #1
	bls _08081546
	cmp r1, #0xd
	bne _08081558
_08081546:
	ldrh r0, [r3]
	b _0808155A
	.align 2, 0
_0808154C: .4byte 0x00000964
_08081550: .4byte 0x03003584
_08081554: .4byte 0x0000095E
_08081558:
	ldrh r0, [r5]
_0808155A:
	strh r0, [r2]
	adds r5, #2
	adds r2, #2
	adds r3, #2
	adds r1, #1
	cmp r1, #0xf
	ble _0808153C
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r6]
	b _08081590
_08081572:
	ldr r1, _080815A4 @ =0x03003584
	ldr r3, _080815A8 @ =0x0000095E
	adds r0, r4, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_080812d4
_08081590:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r4, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0808159C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080815A4: .4byte 0x03003584
_080815A8: .4byte 0x0000095E

	thumb_func_start FUN_080815ac
FUN_080815ac: @ 0x080815AC
	push {r4, lr}
	ldr r1, _080815E8 @ =0x0000094A
	adds r3, r0, r1
	movs r2, #0
	movs r1, #0x27
	strh r1, [r3]
	ldr r4, _080815EC @ =0x0000094C
	adds r1, r0, r4
	strh r2, [r1]
	movs r1, #0x95
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0xff
	strb r1, [r2]
	adds r2, r0, #0
	adds r2, #0xc2
	adds r1, #0x22
	strh r1, [r2]
	adds r2, #0xe
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r1, r0, r4
	str r1, [r2]
	ldrh r1, [r3]
	bl FUN_080813d0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080815E8: .4byte 0x0000094A
_080815EC: .4byte 0x0000094C

	thumb_func_start FUN_080815f0
FUN_080815f0: @ 0x080815F0
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08081614 @ =0x0000095C
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08081610
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08081618
_08081610:
	adds r0, r2, #0
	b _0808161E
	.align 2, 0
_08081614: .4byte 0x0000095C
_08081618:
	ldr r1, _08081624 @ =0x0000095A
	adds r0, r3, r1
	ldrh r0, [r0]
_0808161E:
	pop {r1}
	bx r1
	.align 2, 0
_08081624: .4byte 0x0000095A

	thumb_func_start FUN_08081628
FUN_08081628: @ 0x08081628
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08081684 @ =0x0000094A
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_080815f0
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080813d0
	adds r1, r4, #0
	adds r1, #0xa8
	ldr r2, _08081688 @ =0x00000604
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r2, #8
	adds r1, r4, r2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xaa
	adds r2, #0xa
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r2, #8
	adds r1, r4, r2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xac
	adds r2, #0xa
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r4, r4, r1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08081684: .4byte 0x0000094A
_08081688: .4byte 0x00000604

	thumb_func_start FUN_0808168c
FUN_0808168c: @ 0x0808168C
	push {lr}
	ldr r1, _0808169C @ =0x0000060C
	adds r0, r0, r1
	bl FUN_080138fc
	pop {r0}
	bx r0
	.align 2, 0
_0808169C: .4byte 0x0000060C

	thumb_func_start FUN_080816a0
FUN_080816a0: @ 0x080816A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08081748 @ =0x000005FC
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r2, [r0]
	ldr r3, [r0, #4]
	str r2, [r1]
	str r3, [r1, #4]
	ldr r2, _0808174C @ =0x00000604
	adds r0, r4, r2
	movs r5, #0
	movs r6, #0
	strh r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r6, [r0]
	adds r2, #4
	adds r0, r4, r2
	movs r2, #0
	bl FUN_0801385c
	adds r0, r4, #0
	bl FUN_080815ac
	ldr r1, _08081750 @ =0x0000097C
	adds r0, r4, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _08081754 @ =0x0000097D
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0x97
	lsls r1, r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x18
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _08081758 @ =0x000003FF
	adds r4, r4, r2
	movs r0, #0xff
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081748: .4byte 0x000005FC
_0808174C: .4byte 0x00000604
_08081750: .4byte 0x0000097C
_08081754: .4byte 0x0000097D
_08081758: .4byte 0x000003FF

	thumb_func_start FUN_0808175c
FUN_0808175c: @ 0x0808175C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r5, r4, r0
	ldr r2, _080817DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080817E0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xfe
	lsls r1, r1, #0xf
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
	ldrh r1, [r4, #0x24]
	ldr r2, _080817E4 @ =0x00004001
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #2
	movs r3, #1
	bl FUN_08236514
	ldr r1, _080817E8 @ =FUN_080843ac
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
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
_080817DC: .4byte 0xFFFF0000
_080817E0: .4byte 0x0000FFFF
_080817E4: .4byte 0x00004001
_080817E8: .4byte FUN_080843ac

	thumb_func_start FUN_080817ec
FUN_080817ec: @ 0x080817EC
	movs r1, #1
	str r1, [r0, #0x1c]
	movs r1, #0xac
	lsls r1, r1, #4
	adds r2, r0, r1
	ldr r1, _08081824 @ =FUN_08084330
	str r1, [r2]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r3, _08081828 @ =0x0000037D
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strh r2, [r1]
	ldr r2, _0808182C @ =0x03002B68
	adds r1, r0, #0
	adds r1, #0x28
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r0, [r0, #0x24]
	strh r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_08081824: .4byte FUN_08084330
_08081828: .4byte 0x0000037D
_0808182C: .4byte 0x03002B68

	thumb_func_start FUN_08081830
FUN_08081830: @ 0x08081830
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080818A0 @ =0x0000CB05
	ldr r1, _080818A4 @ =0x0000DE23
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08081846
	b _08081AA4
_08081846:
	adds r1, r6, #0
	adds r1, #0x68
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x68
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenSpriteSetFile
	adds r5, r6, #0
	adds r5, #0x88
	movs r3, #0x80
	lsls r3, r3, #8
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x2c
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822f3fc
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080818A8
	bl Script_GetValue
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	b _080818B0
	.align 2, 0
_080818A0: .4byte 0x0000CB05
_080818A4: .4byte 0x0000DE23
_080818A8:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r1, [r0]
_080818B0:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _080818D8
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _080818D0 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _080818D4 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _080818E6
	.align 2, 0
_080818D0: .4byte 0x000002E6
_080818D4: .4byte 0x000002E7
_080818D8:
	ldr r1, _08081918 @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _0808191C @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
_080818E6:
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r6, r3
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08081918 @ =0x000002E6
	adds r0, r6, r2
	ldrb r2, [r0]
	str r1, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r3, _0808191C @ =0x000002E7
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08081920
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _0808192C
	.align 2, 0
_08081918: .4byte 0x000002E6
_0808191C: .4byte 0x000002E7
_08081920:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0808192C:
	str r1, [r0]
	add r0, sp, #0x10
	bl FUN_08084734
	adds r2, r6, #0
	movs r4, #0x8f
	lsls r4, r4, #3
	adds r5, r6, r4
	movs r0, #8
	adds r0, r0, r6
	mov ip, r0
	adds r7, r6, #0
	adds r7, #0x18
_08081946:
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r5]
	str r1, [r5, #4]
	cmp r2, ip
	beq _08081974
	cmp r2, ip
	bgt _0808195C
	cmp r2, r6
	beq _0808196A
	b _0808198E
_0808195C:
	adds r0, r6, #0
	adds r0, #0x10
	cmp r2, r0
	beq _0808197C
	cmp r2, r7
	beq _08081986
	b _0808198E
_0808196A:
	movs r1, #0x2c
	movs r4, #0xa0
	rsbs r4, r4, #0
	movs r3, #5
	b _08081994
_08081974:
	movs r1, #0x2c
	movs r4, #0xfc
	movs r3, #1
	b _08081994
_0808197C:
	movs r1, #0xa0
	rsbs r1, r1, #0
	movs r4, #0x2c
	movs r3, #3
	b _08081994
_08081986:
	movs r1, #0xfc
	movs r4, #0x2c
	movs r3, #7
	b _08081994
_0808198E:
	movs r1, #0
	movs r4, #0
	movs r3, #0
_08081994:
	ldrh r0, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldr r0, _080819D4 @ =0x0000047C
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldr r1, _080819D8 @ =0x0000047E
	adds r0, r2, r1
	strh r3, [r0]
	adds r2, #8
	adds r5, #8
	cmp r2, r7
	ble _08081946
	ldr r2, _080819DC @ =0x000004A6
	adds r0, r6, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _080819E0 @ =0x00000466
	adds r0, r6, r3
	strb r1, [r0]
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080819E8
	bl Script_GetValue
	ldr r4, _080819E4 @ =0x00000467
	adds r1, r6, r4
	b _080819EE
	.align 2, 0
_080819D4: .4byte 0x0000047C
_080819D8: .4byte 0x0000047E
_080819DC: .4byte 0x000004A6
_080819E0: .4byte 0x00000466
_080819E4: .4byte 0x00000467
_080819E8:
	ldr r5, _08081A10 @ =0x00000467
	adds r1, r6, r5
	movs r0, #0x32
_080819EE:
	strb r0, [r1]
	ldr r1, _08081A14 @ =0x00000469
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x62
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08081A18
	bl Script_GetValue
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r1, r6, r2
	b _08081A20
	.align 2, 0
_08081A10: .4byte 0x00000467
_08081A14: .4byte 0x00000469
_08081A18:
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r6, r3
	movs r0, #3
_08081A20:
	strb r0, [r1]
	ldr r4, _08081A50 @ =0x0000046D
	adds r0, r6, r4
	movs r1, #0
	strb r1, [r0]
	ldr r5, _08081A54 @ =0x00000474
	adds r0, r6, r5
	strh r1, [r0]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08081A60
	bl Script_GetValue
	ldr r2, _08081A58 @ =0x0000046C
	adds r1, r6, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _08081A5C @ =0x00000472
	adds r1, r6, r3
	b _08081A6E
	.align 2, 0
_08081A50: .4byte 0x0000046D
_08081A54: .4byte 0x00000474
_08081A58: .4byte 0x0000046C
_08081A5C: .4byte 0x00000472
_08081A60:
	ldr r4, _08081A8C @ =0x0000046C
	adds r1, r6, r4
	movs r0, #4
	strb r0, [r1]
	ldr r5, _08081A90 @ =0x00000472
	adds r1, r6, r5
	movs r0, #0xb4
_08081A6E:
	strh r0, [r1]
	ldr r1, _08081A94 @ =0x0000046B
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08081A9C
	bl Script_GetValue
	ldr r2, _08081A98 @ =0x0000046A
	adds r1, r6, r2
	b _08081AA2
	.align 2, 0
_08081A8C: .4byte 0x0000046C
_08081A90: .4byte 0x00000472
_08081A94: .4byte 0x0000046B
_08081A98: .4byte 0x0000046A
_08081A9C:
	ldr r3, _08081AAC @ =0x0000046A
	adds r1, r6, r3
	movs r0, #5
_08081AA2:
	strb r0, [r1]
_08081AA4:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081AAC: .4byte 0x0000046A

	thumb_func_start FUN_08081ab0
FUN_08081ab0: @ 0x08081AB0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r1, #0
	movs r0, #1
	str r0, [r6, #0x18]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08081B04
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08081AFC @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08081B00 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _08081B0E
	.align 2, 0
_08081AFC: .4byte 0xFFFF0000
_08081B00: .4byte 0x0000FFFF
_08081B04:
	ldr r1, _08081B3C @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_08081B0E:
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08081B36
	cmp r1, #0
	blt _08081B36
	ldr r0, _08081B40 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08081B36
	ldr r0, _08081B44 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08081B48
_08081B36:
	movs r4, #0
	b _08081B56
	.align 2, 0
_08081B3C: .4byte 0xFFFF0000
_08081B40: .4byte 0x030046A8
_08081B44: .4byte 0x030046AC
_08081B48:
	ldr r0, _08081B68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08081B56:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08081B6C
	adds r0, #4
	b _08081B78
	.align 2, 0
_08081B68: .4byte 0x030046A4
_08081B6C:
	ldr r0, _08081B8C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08081B78:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08081B90
	cmp r2, #2
	beq _08081B94
	b _08081B98
	.align 2, 0
_08081B8C: .4byte 0x030046A4
_08081B90:
	ldrb r0, [r5, #4]
	b _08081B96
_08081B94:
	ldrb r0, [r5]
_08081B96:
	subs r1, r1, r0
_08081B98:
	add r0, sp, #8
	strh r1, [r0, #2]
	adds r5, r6, #0
	adds r5, #0x24
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	ldrb r0, [r6, #0x18]
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_0823b400
	adds r0, r6, #0
	bl FUN_08081830
	adds r1, r6, #0
	adds r1, #0x88
	adds r0, r5, #0
	bl FUN_0823b474
	movs r0, #0xde
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r4, #0
	add r1, sp, #8
	bl FUN_0823280c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl FUN_0823b43c
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r6, r1
	add r1, sp, #8
	bl FUN_082362fc
	ldr r0, _08081C00 @ =0x00000464
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08002a48
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08081C00: .4byte 0x00000464

	thumb_func_start FUN_08081c04
FUN_08081c04: @ 0x08081C04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _08081C30 @ =0x000009C8
	adds r6, r7, r0
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08081C38
	bl Script_GetValue
	ldr r2, _08081C34 @ =0x00000A7A
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	adds r5, r0, #0
	b _08081C42
	.align 2, 0
_08081C30: .4byte 0x000009C8
_08081C34: .4byte 0x00000A7A
_08081C38:
	ldr r0, _08081CFC @ =0x00000A7A
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	movs r5, #0x1e
_08081C42:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0x20
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x14
	strh r0, [r1]
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r1, _08081D00 @ =0x00002110
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0x43
	bl FUN_0822a470
	movs r0, #4
	strh r0, [r6, #0x10]
	adds r0, r4, #0
	movs r1, #0x32
	bl Video_SetActorSpritePltt
	movs r1, #2
	mov r8, r1
	mov r2, r8
	strb r2, [r6, #7]
	movs r0, #0x7f
	strb r0, [r6, #9]
	strb r0, [r6, #8]
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r7, r0
	ldr r2, _08081D04 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0xaa
	orrs r0, r3
	ldr r1, _08081D08 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, _08081D0C @ =0xFFEC0000
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08081D10 @ =0x00002101
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	mov r1, r8
	str r1, [sp]
	ldr r2, _08081D14 @ =0x00000A7E
	adds r0, r7, r2
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x32
	movs r3, #0x10
	bl FUN_082364f8
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081CFC: .4byte 0x00000A7A
_08081D00: .4byte 0x00002110
_08081D04: .4byte 0xFFFF0000
_08081D08: .4byte 0x0000FFFF
_08081D0C: .4byte 0xFFEC0000
_08081D10: .4byte 0x00002101
_08081D14: .4byte 0x00000A7E

	thumb_func_start FUN_08081d18
FUN_08081d18: @ 0x08081D18
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r2, r0, #0
	adds r0, #0x90
	ldr r5, [r0]
	movs r0, #1
	ands r5, r0
	cmp r5, #0
	bne _08081D94
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r6, r2, r0
	adds r0, r1, #2
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x63
	bls _08081D94
	ldr r0, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x50
	lsls r1, r1, #0x10
	ldr r3, _08081D9C @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r4, _08081DA0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	ands r0, r3
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	str r5, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldrh r0, [r6]
	subs r0, #0x64
	strh r0, [r6]
_08081D94:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081D9C: .4byte 0x0000FFFF
_08081DA0: .4byte 0xFFFF0000

	thumb_func_start FUN_08081da4
FUN_08081da4: @ 0x08081DA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _08081DCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08081DD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08081DD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0x64
	bl Mod
	cmp r0, r4
	blt _08081DD8
	movs r0, #0
	b _08081DDA
	.align 2, 0
_08081DCC: .4byte 0x030046B8
_08081DD0: .4byte 0x000003FF
_08081DD4: .4byte 0x0203B400
_08081DD8:
	movs r0, #1
_08081DDA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08081de0
FUN_08081de0: @ 0x08081DE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	mov sl, r0
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	movs r0, #0
	mov sb, r0
	movs r6, #0
	movs r1, #0xff
	mov r8, r1
	mov r5, sp
_08081DFE:
	ldr r0, _08081E28 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5]
	str r1, [r5, #4]
	lsls r2, r6, #5
	ldr r1, _08081E2C @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	cmp r0, #0
	blt _08081E30
	asrs r1, r0, #0xc
	b _08081E36
	.align 2, 0
_08081E28: .4byte 0x03002BE0
_08081E2C: .4byte 0x085B0A08
_08081E30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08081E36:
	ldrh r0, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	mov r3, r8
	ands r2, r3
	lsls r0, r2, #1
	ldr r1, _08081E54 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #9
	cmp r0, #0
	blt _08081E58
	asrs r0, r0, #0xc
	b _08081E5E
	.align 2, 0
_08081E54: .4byte 0x085B0A08
_08081E58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08081E5E:
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	strh r1, [r5, #4]
	adds r7, r5, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08081E88
	cmp r1, #0
	blt _08081E88
	ldr r0, _08081E8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08081E88
	ldr r0, _08081E90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08081E94
_08081E88:
	movs r4, #0
	b _08081EA2
	.align 2, 0
_08081E8C: .4byte 0x030046A8
_08081E90: .4byte 0x030046AC
_08081E94:
	ldr r0, _08081EB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08081EA2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08081EB8
	adds r0, #4
	b _08081EC4
	.align 2, 0
_08081EB4: .4byte 0x030046A4
_08081EB8:
	ldr r0, _08081ED8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08081EC4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08081EDC
	cmp r3, #2
	beq _08081EE0
	b _08081EE8
	.align 2, 0
_08081ED8: .4byte 0x030046A4
_08081EDC:
	ldrh r1, [r7, #4]
	b _08081EE2
_08081EE0:
	ldrh r1, [r7]
_08081EE2:
	mov r0, r8
	ands r0, r1
	subs r2, r2, r0
_08081EE8:
	mov r3, sl
	movs r1, #0x2e
	ldrsh r0, [r3, r1]
	cmp r2, r0
	bne _08081EFA
	movs r0, #1
	strh r0, [r5, #6]
	add sb, r0
	b _08081EFE
_08081EFA:
	movs r0, #0
	strh r0, [r5, #6]
_08081EFE:
	adds r5, #8
	adds r6, #1
	cmp r6, #7
	bgt _08081F08
	b _08081DFE
_08081F08:
	mov r2, sb
	cmp r2, #0
	bne _08081F28
	b _08081F60
_08081F10:
	ldr r0, [r1]
	ldr r1, [r1, #4]
	ldr r3, [sp, #0x40]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r6, #7
	movs r1, #7
	ands r0, r1
	ldr r1, [sp, #0x44]
	str r0, [r1]
	movs r0, #1
	b _08081F62
_08081F28:
	ldr r2, _08081F74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08081F78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08081F7C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r0, r0, #3
	mov r1, sb
	bl Mod
	adds r2, r0, #0
	movs r6, #0
	mov r1, sp
_08081F4A:
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq _08081F58
	cmp r2, #0
	beq _08081F10
	subs r2, #1
_08081F58:
	adds r1, #8
	adds r6, #1
	cmp r6, #7
	ble _08081F4A
_08081F60:
	movs r0, #0
_08081F62:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08081F74: .4byte 0x030046B8
_08081F78: .4byte 0x000003FF
_08081F7C: .4byte 0x0203B400

	thumb_func_start FUN_08081f80
FUN_08081f80: @ 0x08081F80
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08081FA0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
	adds r0, r4, #0
	bl FUN_08080c64
_08081FA0:
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08081fb4
FUN_08081fb4: @ 0x08081FB4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08081FCE
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08080e0c
_08081FCE:
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_08080ec8
	movs r2, #0x82
	lsls r2, r2, #2
	adds r3, r4, r2
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #0x2c
	ldrsh r6, [r4, r2]
	subs r2, r0, r6
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x30
	ldrsh r5, [r4, r1]
	subs r1, r0, r5
	movs r7, #0xc
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	cmp r0, #0x90
	bgt _08082074
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	ldr r1, _08082038 @ =0x00000471
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _08082040
	movs r0, #8
	subs r0, r0, r1
	subs r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0808203C @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0808204C
	.align 2, 0
_08082038: .4byte 0x00000471
_0808203C: .4byte 0x000002E7
_08082040:
	ldr r2, _0808206C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08082070 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0808204C:
	strb r0, [r1]
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r1, #0x8e
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08080e0c
	b _08082118
	.align 2, 0
_0808206C: .4byte 0x000002E6
_08082070: .4byte 0x000002E7
_08082074:
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r2, r0, r6
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r1, r0, r5
	adds r0, r2, #0
	bl FUN_0823785c
	adds r5, r0, #0
	ldr r2, _080820B0 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080820B4
	asrs r0, r0, #0xc
	b _080820BA
	.align 2, 0
_080820B0: .4byte 0x085B0A08
_080820B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080820BA:
	strh r0, [r4, #0x34]
	ldr r0, _080820D4 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080820D8
	asrs r0, r0, #0xc
	b _080820DE
	.align 2, 0
_080820D4: .4byte 0x085B0A08
_080820D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080820DE:
	strh r0, [r4, #0x38]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08235fd8
	cmp r0, #0
	beq _0808210E
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
_0808210E:
	ldr r1, _08082120 @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
_08082118:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08082120: .4byte 0x000001A3

	thumb_func_start FUN_08082124
FUN_08082124: @ 0x08082124
	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0808214C
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _08082148 @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0808214C
	movs r0, #1
	b _0808214E
	.align 2, 0
_08082148: .4byte 0x0000036A
_0808214C:
	movs r0, #0
_0808214E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08082154
FUN_08082154: @ 0x08082154
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _0808216E
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08080e0c
_0808216E:
	ldr r2, _08082184 @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _0808217A
	b _08082456
_0808217A:
	lsls r0, r0, #2
	ldr r1, _08082188 @ =_0808218C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08082184: .4byte 0x0000037D
_08082188: .4byte _0808218C
_0808218C: @ jump table
	.4byte _080821A0 @ case 0
	.4byte _080821B8 @ case 1
	.4byte _080822D0 @ case 2
	.4byte _080823AC @ case 3
	.4byte _0808241C @ case 4
_080821A0:
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08080e0c
	b _08082456
_080821B8:
	ldr r1, _08082214 @ =0x0000037E
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _0808226E
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08082228
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08082218 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0808221C @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _08082220 @ =0x00000932
	adds r1, r4, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08082224 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08082262
	.align 2, 0
_08082214: .4byte 0x0000037E
_08082218: .4byte 0x000002E6
_0808221C: .4byte 0x000002E7
_08082220: .4byte 0x00000932
_08082224: .4byte 0x00000934
_08082228:
	strb r2, [r1]
	ldr r1, _080822BC @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _080822C0 @ =0x00000932
	adds r1, r4, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080822C4 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x1e
_08082262:
	strh r0, [r1]
	ldr r2, _080822C8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0808226E:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _0808228A
	b _08082456
_0808228A:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080822A4
	b _080823DC
_080822A4:
	adds r0, r4, #0
	bl FUN_08082124
	adds r1, r0, #0
	cmp r1, #0
	beq _080822B2
	b _080823F2
_080822B2:
	ldr r2, _080822CC @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _0808239A
	.align 2, 0
_080822BC: .4byte 0x000002E6
_080822C0: .4byte 0x00000932
_080822C4: .4byte 0x00000934
_080822C8: .4byte 0x0000037E
_080822CC: .4byte 0x00000404
_080822D0:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _0808232C @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080822F6
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080822F6
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080822F6:
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _08082330 @ =0x0000095E
	adds r1, r4, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _08082334 @ =0x0000037E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _08082338
	movs r2, #0x96
	lsls r2, r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	b _08082344
	.align 2, 0
_0808232C: .4byte 0x00000404
_08082330: .4byte 0x0000095E
_08082334: .4byte 0x0000037E
_08082338:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_08082344:
	ldr r0, _0808237C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _0808235C
	movs r0, #0
	strh r0, [r1]
_0808235C:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08082384
	movs r0, #0xd8
	bl sound_08240740
	ldr r2, _08082380 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _080823DC
	.align 2, 0
_0808237C: .4byte 0x0000037E
_08082380: .4byte 0x00000409
_08082384:
	adds r0, r4, #0
	bl FUN_08082124
	cmp r0, #0
	bne _08082456
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _080823A8 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_0808239A:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08080e0c
	b _08082456
	.align 2, 0
_080823A8: .4byte 0x00000409
_080823AC:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080823E8
_080823DC:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08080e0c
	b _08082456
_080823E8:
	adds r0, r4, #0
	bl FUN_08082124
	cmp r0, #0
	beq _08082456
_080823F2:
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r2, _08082414 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08082418 @ =0x00000404
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08080e0c
	b _08082456
	.align 2, 0
_08082414: .4byte 0x00000409
_08082418: .4byte 0x00000404
_0808241C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082456
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _0808245C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08082460 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082456:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808245C: .4byte 0x000002E6
_08082460: .4byte 0x000002E7

	thumb_func_start FUN_08082464
FUN_08082464: @ 0x08082464
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808247C @ =0x000003FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082480
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_08080ec8
	b _08082488
	.align 2, 0
_0808247C: .4byte 0x000003FE
_08082480:
	adds r0, r4, #0
	movs r1, #0x3d
	bl FUN_08080ec8
_08082488:
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08082498
FUN_08082498: @ 0x08082498
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _08082520
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08080e0c
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080824E4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r5, _080824DC @ =0x000002E6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r6, _080824E0 @ =0x000002E7
	adds r1, r4, r6
	movs r0, #1
	strb r0, [r1]
	b _080824F4
	.align 2, 0
_080824DC: .4byte 0x000002E6
_080824E0: .4byte 0x000002E7
_080824E4:
	lsrs r1, r1, #0x19
	ldr r2, _08082510 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _08082514 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080824F4:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08082518 @ =0x00000366
	bl sound_08240740
	ldr r0, _0808251C @ =0x0000036A
	bl PlaySound_082406e0
	b _08082666
	.align 2, 0
_08082510: .4byte 0x000002E6
_08082514: .4byte 0x000002E7
_08082518: .4byte 0x00000366
_0808251C: .4byte 0x0000036A
_08082520:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r5, r4, r6
	ldrh r0, [r5]
	cmp r0, #0
	beq _0808260C
	ldr r1, _0808255C @ =0x00000395
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082598
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r2, [r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	subs r3, r1, r0
	movs r6, #0x30
	ldrsh r1, [r4, r6]
	movs r5, #4
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	rsbs r0, r3, #0
	cmp r0, #0
	blt _08082560
	asrs r0, r0, #3
	b _08082564
	.align 2, 0
_0808255C: .4byte 0x00000395
_08082560:
	asrs r0, r3, #3
	rsbs r0, r0, #0
_08082564:
	strh r0, [r4, #0x34]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08082570
	asrs r0, r0, #3
	b _08082574
_08082570:
	asrs r0, r1, #3
	rsbs r0, r0, #0
_08082574:
	strh r0, [r4, #0x38]
	movs r6, #0xf5
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrh r1, [r0]
	cmp r1, #0x55
	bls _080825FA
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080825FA
	ldr r0, _08082594 @ =0x00000191
	bl PlaySound_082406e0
	b _080825FA
	.align 2, 0
_08082594: .4byte 0x00000191
_08082598:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080825C8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r5]
	muls r0, r1, r0
	cmp r0, #0
	blt _080825CC
	asrs r0, r0, #0xc
	b _080825D2
	.align 2, 0
_080825C8: .4byte 0x085B0A08
_080825CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080825D2:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080825F0
	asrs r0, r0, #0xc
	b _080825F6
_080825F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080825F6:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
_080825FA:
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r2, r4, r5
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _08082666
_0808260C:
	ldr r6, _0808262C @ =0x000004C5
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _08082634
	ldr r1, _08082630 @ =0x000004C7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082634
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08080e0c
	b _08082666
	.align 2, 0
_0808262C: .4byte 0x000004C5
_08082630: .4byte 0x000004C7
_08082634:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082666
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r3, _0808266C @ =0x00000395
	adds r0, r4, r3
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082666:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808266C: .4byte 0x00000395

	thumb_func_start FUN_08082670
FUN_08082670: @ 0x08082670
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x19
	beq _080826D8
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl FUN_08080e0c
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080826BC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r5, _080826B4 @ =0x000002E6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r0, _080826B8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080826CC
	.align 2, 0
_080826B4: .4byte 0x000002E6
_080826B8: .4byte 0x000002E7
_080826BC:
	lsrs r1, r1, #0x19
	ldr r2, _080826F0 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080826F4 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080826CC:
	ldr r0, _080826F8 @ =0x00000366
	bl sound_08240740
	ldr r0, _080826FC @ =0x0000036B
	bl PlaySound_082406e0
_080826D8:
	ldr r5, _08082700 @ =0x0000037D
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _080826E4
	b _0808295A
_080826E4:
	lsls r0, r0, #2
	ldr r1, _08082704 @ =_08082708
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080826F0: .4byte 0x000002E6
_080826F4: .4byte 0x000002E7
_080826F8: .4byte 0x00000366
_080826FC: .4byte 0x0000036B
_08082700: .4byte 0x0000037D
_08082704: .4byte _08082708
_08082708: @ jump table
	.4byte _0808271C @ case 0
	.4byte _0808274C @ case 1
	.4byte _0808285C @ case 2
	.4byte _080828E8 @ case 3
	.4byte _0808290C @ case 4
_0808271C:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08082748 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _0808273C
	b _0808295A
_0808273C:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082748: .4byte 0x0000037E
_0808274C:
	ldr r1, _080827A0 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08082760
	ldr r2, _080827A4 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_08082760:
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080827A8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080827AC
	asrs r0, r0, #0xc
	b _080827B2
	.align 2, 0
_080827A0: .4byte 0x0000037E
_080827A4: .4byte 0x000003F6
_080827A8: .4byte 0x085B0A08
_080827AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080827B2:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _080827D4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080827D8
	asrs r0, r0, #0xc
	b _080827DE
	.align 2, 0
_080827D4: .4byte 0x085B0A08
_080827D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080827DE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r1, _0808280C @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _08082818
	ldr r2, _08082810 @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _08082814
	subs r0, r2, r0
	b _08082816
	.align 2, 0
_0808280C: .4byte 0x0000037E
_08082810: .4byte 0x000003F6
_08082814:
	movs r0, #0
_08082816:
	strh r0, [r1]
_08082818:
	ldr r3, _08082850 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _08082830
	b _0808295A
_08082830:
	ldr r0, _08082854 @ =0x000003F6
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808283C
	b _0808295A
_0808283C:
	strh r0, [r1]
	ldr r0, _08082858 @ =0x0000033A
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082850: .4byte 0x0000037E
_08082854: .4byte 0x000003F6
_08082858: .4byte 0x0000033A
_0808285C:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08082890 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08082894
	asrs r0, r0, #0xc
	b _0808289A
	.align 2, 0
_08082890: .4byte 0x085B0A08
_08082894:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808289A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080828B8
	asrs r0, r0, #0xc
	b _080828BE
_080828B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080828BE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xe3
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _0808295A
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r1, r4, r5
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl FUN_08080e0c
	b _0808295A
_080828E8:
	ldr r0, _08082908 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _0808295A
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082908: .4byte 0x0000037E
_0808290C:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _0808295A
	ldr r1, _08082960 @ =0x000003D2
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
	ldr r3, _08082964 @ =0x0000046D
	adds r2, r4, r3
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	subs r3, #1
	adds r1, r4, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08082950
	strb r5, [r2]
	ldr r5, _08082968 @ =0x00000472
	adds r0, r4, r5
	ldrh r1, [r0]
	ldr r2, _0808296C @ =0x00000474
	adds r0, r4, r2
	strh r1, [r0]
_08082950:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_0808295A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082960: .4byte 0x000003D2
_08082964: .4byte 0x0000046D
_08082968: .4byte 0x00000472
_0808296C: .4byte 0x00000474

	thumb_func_start FUN_08082970
FUN_08082970: @ 0x08082970
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x12
	beq _08082998
	ldr r0, _080829AC @ =0x00000366
	bl sound_08240740
	ldr r0, _080829B0 @ =0x0000036F
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_08080e0c
_08082998:
	ldr r3, _080829B4 @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _08082A20
	cmp r0, #1
	bgt _080829B8
	cmp r0, #0
	beq _080829BE
	b _08082A88
	.align 2, 0
_080829AC: .4byte 0x00000366
_080829B0: .4byte 0x0000036F
_080829B4: .4byte 0x0000037D
_080829B8:
	cmp r0, #2
	beq _08082A70
	b _08082A88
_080829BE:
	movs r1, #0xf9
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082A88
	movs r6, #0x99
	lsls r6, r6, #4
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08082A14 @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldr r3, _08082A18 @ =0x00000474
	adds r2, r5, r3
	str r2, [sp]
	ldr r6, _08082A1C @ =0x00000472
	adds r2, r5, r6
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_08080e0c
	b _08082A88
	.align 2, 0
_08082A14: .4byte 0x0000098C
_08082A18: .4byte 0x00000474
_08082A1C: .4byte 0x00000472
_08082A20:
	ldr r6, _08082A68 @ =0x00000474
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08082A88
	ldr r0, _08082A6C @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	movs r6, #0x99
	lsls r6, r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	lsls r3, r3, #1
	str r3, [sp, #8]
	adds r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #2
	bl FUN_08080e0c
	b _08082A88
	.align 2, 0
_08082A68: .4byte 0x00000474
_08082A6C: .4byte 0x0000098C
_08082A70:
	ldr r1, _08082A90 @ =0x000001F7
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082A88
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082A88:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082A90: .4byte 0x000001F7

	thumb_func_start FUN_08082a94
FUN_08082a94: @ 0x08082A94
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	beq _08082AF4
	ldr r0, _08082B50 @ =0x00000366
	bl sound_08240740
	ldr r0, _08082B54 @ =0x00000369
	bl PlaySound_082406e0
	movs r3, #0x99
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	ldr r6, _08082B58 @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldr r3, _08082B5C @ =0x00000474
	adds r2, r5, r3
	str r2, [sp]
	ldr r6, _08082B60 @ =0x00000472
	adds r2, r5, r6
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #3
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08080e0c
_08082AF4:
	ldr r6, _08082B64 @ =0x0000037E
	adds r0, r5, r6
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08082B86
	ldr r0, _08082B68 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0x2c
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	movs r6, #0x30
	ldrsh r1, [r2, r6]
	movs r3, #0x30
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r6, #0xba
	lsls r6, r6, #2
	adds r3, r5, r6
	ldrb r2, [r3]
	cmp r1, r2
	beq _08082B74
	adds r0, r2, #0
	subs r0, #8
	subs r0, r1, r0
	movs r1, #7
	ands r0, r1
	cmp r0, #4
	ble _08082B6C
	adds r0, r2, #7
	b _08082B70
	.align 2, 0
_08082B50: .4byte 0x00000366
_08082B54: .4byte 0x00000369
_08082B58: .4byte 0x0000098C
_08082B5C: .4byte 0x00000474
_08082B60: .4byte 0x00000472
_08082B64: .4byte 0x0000037E
_08082B68: .4byte 0x03002BE0
_08082B6C:
	adds r0, r2, #1
	movs r1, #7
_08082B70:
	ands r0, r1
	strb r0, [r3]
_08082B74:
	adds r0, r5, #0
	bl FUN_08080c64
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
_08082B86:
	ldr r0, _08082BD4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _08082BCC
	ldr r1, _08082BD8 @ =0x0000098C
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	movs r6, #0x99
	lsls r6, r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	lsls r3, r3, #1
	str r3, [sp, #8]
	adds r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_08082BCC:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082BD4: .4byte 0x0000037E
_08082BD8: .4byte 0x0000098C

	thumb_func_start FUN_08082bdc
FUN_08082bdc: @ 0x08082BDC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08082BF6
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_08082BF6:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_08080ec8
	movs r2, #0x82
	lsls r2, r2, #2
	adds r3, r4, r2
	movs r5, #0
	ldrsh r1, [r3, r5]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08082C14
	rsbs r0, r0, #0
_08082C14:
	adds r6, r0, #0
	movs r5, #0x83
	lsls r5, r5, #2
	adds r2, r4, r5
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08082C2C
	rsbs r1, r1, #0
_08082C2C:
	adds r5, r1, #0
	cmp r6, #0x1f
	bgt _08082C84
	cmp r5, #0x1f
	bgt _08082C84
	ldr r0, _08082C78 @ =0x000003F2
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldrh r0, [r3]
	strh r0, [r4, #0x2c]
	ldrh r0, [r2]
	strh r0, [r4, #0x30]
	ldr r1, _08082C7C @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08080cac
	ldr r1, _08082C80 @ =0x00000471
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
	movs r5, #0x8e
	lsls r5, r5, #3
	adds r0, r4, r5
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08080e0c
	b _08082DA0
	.align 2, 0
_08082C78: .4byte 0x000003F2
_08082C7C: .4byte 0x000001A3
_08082C80: .4byte 0x00000471
_08082C84:
	ldr r0, _08082CAC @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _08082CB0 @ =0x00000127
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x18
	strh r0, [r1]
	cmp r6, #0xbf
	bgt _08082C9E
	cmp r5, #0xbf
	ble _08082CB8
_08082C9E:
	ldr r5, _08082CB4 @ =0x000003F2
	adds r1, r4, r5
	ldrb r0, [r1]
	cmp r0, #4
	bhi _08082CC6
	adds r0, #1
	b _08082CC4
	.align 2, 0
_08082CAC: .4byte 0x0000095E
_08082CB0: .4byte 0x00000127
_08082CB4: .4byte 0x000003F2
_08082CB8:
	ldr r0, _08082CDC @ =0x000003F2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08082CC6
	subs r0, #1
_08082CC4:
	strb r0, [r1]
_08082CC6:
	ldr r1, _08082CDC @ =0x000003F2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08082CE0
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08080ec8
	b _08082CEC
	.align 2, 0
_08082CDC: .4byte 0x000003F2
_08082CE0:
	cmp r0, #0
	beq _08082CEC
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08080ec8
_08082CEC:
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r6, r1, r0
	movs r5, #0x87
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	subs r5, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _08082D30 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08082D34
	asrs r0, r0, #0xc
	b _08082D3A
	.align 2, 0
_08082D30: .4byte 0x085B0A08
_08082D34:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08082D3A:
	strh r0, [r4, #0x34]
	ldr r0, _08082D54 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08082D58
	asrs r0, r0, #0xc
	b _08082D5E
	.align 2, 0
_08082D54: .4byte 0x085B0A08
_08082D58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08082D5E:
	strh r0, [r4, #0x38]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08235fd8
	cmp r0, #0
	beq _08082D96
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
_08082D96:
	ldr r1, _08082DA8 @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08080cac
_08082DA0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082DA8: .4byte 0x000001A3

	thumb_func_start FUN_08082dac
FUN_08082dac: @ 0x08082DAC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _08082DD0
	adds r0, r4, #0
	movs r1, #9
	movs r2, #0
	bl FUN_08080e0c
	ldr r2, _08082DE8 @ =0x00000951
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_08082DD0:
	ldr r3, _08082DEC @ =0x0000037D
	adds r0, r4, r3
	ldrb r2, [r0]
	cmp r2, #1
	bne _08082DDC
	b _08082F30
_08082DDC:
	cmp r2, #1
	bgt _08082DF0
	cmp r2, #0
	beq _08082DFE
	b _08083012
	.align 2, 0
_08082DE8: .4byte 0x00000951
_08082DEC: .4byte 0x0000037D
_08082DF0:
	cmp r2, #2
	bne _08082DF6
	b _08082F84
_08082DF6:
	cmp r2, #3
	bne _08082DFC
	b _08082FE8
_08082DFC:
	b _08083012
_08082DFE:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08082E60
	movs r1, #4
	strb r1, [r3]
	ldr r3, _08082E50 @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08082E54 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r0, _08082E58 @ =0x00000932
	adds r1, r4, r0
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _08082E5C @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08082E9A
	.align 2, 0
_08082E50: .4byte 0x000002E6
_08082E54: .4byte 0x000002E7
_08082E58: .4byte 0x00000932
_08082E5C: .4byte 0x00000934
_08082E60:
	strb r2, [r3]
	ldr r1, _08082EBC @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _08082EC0 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _08082EC4 @ =0x00000932
	adds r1, r4, r2
	movs r3, #0xa5
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08082EC8 @ =0x00000934
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x14
_08082E9A:
	strh r0, [r1]
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08082ECC
	ldr r2, _08082EBC @ =0x000002E6
	adds r1, r4, r2
	movs r0, #1
	b _08082ED2
	.align 2, 0
_08082EBC: .4byte 0x000002E6
_08082EC0: .4byte 0x000002E7
_08082EC4: .4byte 0x00000932
_08082EC8: .4byte 0x00000934
_08082ECC:
	ldr r3, _08082F1C @ =0x000002E6
	adds r1, r4, r3
	movs r0, #0
_08082ED2:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	movs r2, #1
	bl FUN_08080e0c
	ldr r0, _08082F20 @ =0x0000095E
	adds r1, r4, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #2
	strh r0, [r1]
	ldr r0, _08082F24 @ =0x0000036E
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x2c
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r3, _08082F28 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl FUN_080abd14
	ldr r0, _08082F2C @ =0x00000477
	adds r1, r4, r0
	movs r0, #0x3c
	strb r0, [r1]
	b _08083012
	.align 2, 0
_08082F1C: .4byte 0x000002E6
_08082F20: .4byte 0x0000095E
_08082F24: .4byte 0x0000036E
_08082F28: .4byte 0x000003BA
_08082F2C: .4byte 0x00000477
_08082F30:
	ldr r2, _08082F80 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08082F52
	movs r0, #0x20
	strh r0, [r1]
_08082F52:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08083012
	movs r0, #0xcb
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #9
	movs r2, #2
	bl FUN_08080e0c
	b _08083012
	.align 2, 0
_08082F80: .4byte 0x0000095E
_08082F84:
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _08082FDC @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _08082FE0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08082FB6
	movs r0, #0x20
	strh r0, [r1]
_08082FB6:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, _08082FE4 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x17
	bls _08083012
	adds r0, r4, #0
	movs r1, #9
	movs r2, #3
	bl FUN_08080e0c
	b _08083012
	.align 2, 0
_08082FDC: .4byte 0x0000095E
_08082FE0: .4byte 0x0000FFFF
_08082FE4: .4byte 0x0000037E
_08082FE8:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08083012
	adds r0, r4, #0
	bl FUN_08080c64
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08083012:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808301c
FUN_0808301c: @ 0x0808301C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08083038
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0
	bl FUN_08080e0c
_08083038:
	ldr r2, _08083050 @ =0x00000951
	adds r0, r5, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _08083054 @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08083058
	cmp r0, #1
	beq _08083076
	b _080831CC
	.align 2, 0
_08083050: .4byte 0x00000951
_08083054: .4byte 0x0000037D
_08083058:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _0808306A
	b _080831CC
_0808306A:
	adds r0, r5, #0
	movs r1, #8
	movs r2, #1
	bl FUN_08080e0c
	b _080831CC
_08083076:
	bl FUN_08084754
	ldr r1, _08083098 @ =0x0000095E
	adds r0, r5, r1
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r2, _0808309C @ =0x0000037E
	adds r0, r5, r2
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080830A0
	movs r3, #0x96
	lsls r3, r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	b _080830AC
	.align 2, 0
_08083098: .4byte 0x0000095E
_0808309C: .4byte 0x0000037E
_080830A0:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	strh r0, [r1]
_080830AC:
	ldr r3, _08083150 @ =0x0000037E
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _080830C2
	movs r0, #0
	strh r0, [r1]
_080830C2:
	ldr r1, _08083154 @ =0x000001E3
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	bl FUN_080230c4
	adds r6, r0, #0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r2, #0x2c
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080830E2
	rsbs r0, r0, #0
_080830E2:
	adds r3, r0, #0
	movs r0, #4
	ldrsh r1, [r6, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080830F4
	rsbs r1, r1, #0
_080830F4:
	adds r2, r1, #0
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	cmp r3, #0xbf
	bgt _0808310A
	cmp r2, #0xbf
	ble _08083112
_0808310A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080831CC
_08083112:
	mov r4, sp
	mov r0, sp
	bl FUN_08084734
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r0, [r6, r3]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r6, r2]
	subs r2, r1, r0
	adds r0, r3, #0
	adds r1, r2, #0
	bl FUN_0823785c
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	movs r6, #0
	cmp r0, #1
	beq _08083162
	cmp r0, #1
	bgt _08083158
	cmp r0, #0
	beq _0808315E
	b _08083168
	.align 2, 0
_08083150: .4byte 0x0000037E
_08083154: .4byte 0x000001E3
_08083158:
	cmp r0, #2
	beq _08083166
	b _08083168
_0808315E:
	movs r6, #3
	b _08083168
_08083162:
	movs r6, #1
	b _08083168
_08083166:
	movs r6, #2
_08083168:
	ldr r3, _080831D4 @ =0x000004A6
	adds r7, r5, r3
	ldrb r0, [r7]
	adds r0, #3
	movs r1, #3
	ands r0, r1
	cmp r0, r6
	beq _080831C2
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x2c
	lsls r4, r6, #3
	subs r3, #0x2e
	adds r2, r4, r3
	adds r2, r5, r2
	bl FUN_08235f40
	cmp r0, #0
	beq _080831C2
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	adds r0, r5, r4
	ldr r1, _080831D8 @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _080831DC @ =0x00000471
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r6, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r7]
	movs r0, #0x1e
	bl FUN_08084798
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_080831C2:
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
_080831CC:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080831D4: .4byte 0x000004A6
_080831D8: .4byte 0x0000047E
_080831DC: .4byte 0x00000471

	thumb_func_start FUN_080831e0
FUN_080831e0: @ 0x080831E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	mov ip, r1
	adds r5, r2, #0
	adds r6, r3, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, _08083224 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08083228
	asrs r1, r0, #0xc
	b _0808322E
	.align 2, 0
_08083224: .4byte 0x085B0A08
_08083228:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808322E:
	ldrh r0, [r4, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r1, [r4, #0x2e]
	adds r1, #0xe6
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08083254
	asrs r0, r0, #0xc
	b _0808325A
_08083254:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808325A:
	ldrh r1, [r4, #0x30]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080832A4 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	str r5, [sp]
	ldr r7, _080832A8 @ =0x00000A7A
	adds r0, r4, r7
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldr r1, _080832AC @ =0x00000A7C
	adds r0, r4, r1
	ldrh r0, [r0]
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	ldr r2, _080832B0 @ =0x00000A7E
	adds r0, r4, r2
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	add r0, sp, #0x14
	adds r1, r3, #0
	movs r2, #0x20
	mov r3, ip
	bl FUN_080cbabc
	ldr r0, _080832B4 @ =0x00000367
	bl PlaySound_082406e0
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080832A4: .4byte 0xFFFF0000
_080832A8: .4byte 0x00000A7A
_080832AC: .4byte 0x00000A7C
_080832B0: .4byte 0x00000A7E
_080832B4: .4byte 0x00000367

	thumb_func_start FUN_080832b8
FUN_080832b8: @ 0x080832B8
	push {r4, r5, lr}
	sub sp, #0x18
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080832D4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08080e0c
_080832D4:
	ldr r2, _080832F4 @ =0x00000951
	adds r0, r4, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _080832F8 @ =0x0000037D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #7
	bls _080832E8
	b _080835CE
_080832E8:
	lsls r0, r0, #2
	ldr r1, _080832FC @ =_08083300
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080832F4: .4byte 0x00000951
_080832F8: .4byte 0x0000037D
_080832FC: .4byte _08083300
_08083300: @ jump table
	.4byte _08083320 @ case 0
	.4byte _0808337C @ case 1
	.4byte _080833E0 @ case 2
	.4byte _080835CE @ case 3
	.4byte _080835CE @ case 4
	.4byte _08083460 @ case 5
	.4byte _08083510 @ case 6
	.4byte _08083540 @ case 7
_08083320:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _08083332
	b _080835CE
_08083332:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08080e0c
	ldr r0, _08083368 @ =0x0000046E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _0808336C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08083370 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08083374 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #2
	ldr r2, _08083378 @ =0x0000046F
	adds r1, r4, r2
	strb r0, [r1]
	b _080835CE
	.align 2, 0
_08083368: .4byte 0x0000046E
_0808336C: .4byte 0x030046B8
_08083370: .4byte 0x000003FF
_08083374: .4byte 0x0203B400
_08083378: .4byte 0x0000046F
_0808337C:
	ldr r3, _080833BC @ =0x0000037E
	adds r5, r4, r3
	ldrh r0, [r5]
	cmp r0, #0
	bne _0808338C
	ldr r0, _080833C0 @ =0x000001F7
	bl PlaySound_082406e0
_0808338C:
	ldr r1, _080833C4 @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080833A6
	b _080835CE
_080833A6:
	bl FUN_080298dc
	cmp r0, #0
	beq _080833C8
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_080833BC: .4byte 0x0000037E
_080833C0: .4byte 0x000001F7
_080833C4: .4byte 0x000001E3
_080833C8:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #6
	movs r3, #2
	bl FUN_080831e0
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08080e0c
	b _080835CE
_080833E0:
	ldr r1, _0808343C @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08083440 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08083448
	add r2, sp, #8
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08081de0
	cmp r0, #0
	bne _0808340C
	b _080835CE
_0808340C:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	bne _08083422
	b _080835CE
_08083422:
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #8]
	ldr r3, _08083444 @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	b _08083508
	.align 2, 0
_0808343C: .4byte 0x000001E3
_08083440: .4byte 0x0000037E
_08083444: .4byte 0x00000471
_08083448:
	ldr r0, _0808345C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _0808345A
	b _080835CE
_0808345A:
	b _08083504
	.align 2, 0
_0808345C: .4byte 0x03002BE0
_08083460:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _080834A4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08083480
	b _080835CE
_08083480:
	ldr r3, _080834A8 @ =0x0000046E
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	adds r2, #0xf1
	adds r0, r4, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r0, [r0]
	cmp r1, r0
	bhs _080834AC
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_080834A4: .4byte 0x0000037E
_080834A8: .4byte 0x0000046E
_080834AC:
	ldr r0, _080834FC @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08083504
	add r5, sp, #0xc
	add r2, sp, #0x14
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08081de0
	cmp r0, #0
	bne _080834CE
	b _080835CE
_080834CE:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080835CE
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #0x14]
	ldr r3, _08083500 @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	b _08083508
	.align 2, 0
_080834FC: .4byte 0x03002BE0
_08083500: .4byte 0x00000471
_08083504:
	adds r0, r4, #0
	movs r1, #3
_08083508:
	movs r2, #6
	bl FUN_08080e0c
	b _080835CE
_08083510:
	ldr r1, _08083538 @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _0808353C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080835CE
	adds r0, r4, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_08083538: .4byte 0x000001E3
_0808353C: .4byte 0x0000037E
_08083540:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _080835B4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080835CE
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _080835B8 @ =0x000004A6
	adds r5, r4, r2
	ldrb r2, [r5]
	lsls r2, r2, #3
	movs r3, #0x8f
	lsls r3, r3, #3
	adds r2, r2, r3
	adds r2, r4, r2
	bl FUN_08235f40
	cmp r0, #0
	beq _080835C4
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r1, _080835BC @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _080835C0 @ =0x00000471
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r5]
	b _080835CE
	.align 2, 0
_080835B4: .4byte 0x0000037E
_080835B8: .4byte 0x000004A6
_080835BC: .4byte 0x0000047E
_080835C0: .4byte 0x00000471
_080835C4:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_080835CE:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080835d8
FUN_080835d8: @ 0x080835D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _080835F8
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08080e0c
_080835F8:
	ldr r2, _08083638 @ =0x00000951
	adds r0, r7, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _0808363C @ =0x000003E6
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0808367E
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r0, r7, r4
	ldrh r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r2]
	ldr r2, _08083640 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r3, r0
	cmp r0, #0
	blt _08083644
	asrs r0, r0, #0xc
	b _0808364A
	.align 2, 0
_08083638: .4byte 0x00000951
_0808363C: .4byte 0x000003E6
_08083640: .4byte 0x085B0A08
_08083644:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808364A:
	strh r0, [r7, #0x34]
	ldr r1, _08083664 @ =0x000003E6
	adds r0, r7, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08083668
	asrs r0, r0, #0xc
	b _0808366E
	.align 2, 0
_08083664: .4byte 0x000003E6
_08083668:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808366E:
	strh r0, [r7, #0x38]
	ldr r3, _08083698 @ =0x000003E6
	adds r2, r7, r3
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
_0808367E:
	ldr r4, _0808369C @ =0x0000037D
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #6
	bls _0808368C
	bl _08083E9C
_0808368C:
	lsls r0, r0, #2
	ldr r1, _080836A0 @ =_080836A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08083698: .4byte 0x000003E6
_0808369C: .4byte 0x0000037D
_080836A0: .4byte _080836A4
_080836A4: @ jump table
	.4byte _080836C0 @ case 0
	.4byte _080836EC @ case 1
	.4byte _08083774 @ case 2
	.4byte _08083800 @ case 3
	.4byte _0808388C @ case 4
	.4byte _08083E44 @ case 5
	.4byte _08083E74 @ case 6
_080836C0:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _080836DE
	bl _08083E9C
_080836DE:
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #1
	bl FUN_08080e0c
	bl _08083E9C
_080836EC:
	ldr r6, _08083754 @ =0x0000037E
	adds r4, r7, r6
	ldrh r0, [r4]
	cmp r0, #0
	bne _080836FC
	ldr r0, _08083758 @ =0x000001F7
	bl PlaySound_082406e0
_080836FC:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _0808375C @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08083720
	b _08083E9C
_08083720:
	ldr r0, _08083760 @ =0x00000402
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08083764 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08083768 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0808376C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r2, _08083770 @ =0x00000403
	adds r1, r7, r2
	strb r0, [r1]
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #2
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083754: .4byte 0x0000037E
_08083758: .4byte 0x000001F7
_0808375C: .4byte 0x000001E3
_08083760: .4byte 0x00000402
_08083764: .4byte 0x030046B8
_08083768: .4byte 0x000003FF
_0808376C: .4byte 0x0203B400
_08083770: .4byte 0x00000403
_08083774:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _080837C0 @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r3, _080837C4 @ =0x0000037E
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2c
	bhi _0808379C
	b _08083E9C
_0808379C:
	ldr r6, _080837C8 @ =0x00000402
	adds r4, r7, r6
	ldr r0, _080837CC @ =0x00000403
	adds r1, r7, r0
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	blo _080837D4
	ldr r0, _080837D0 @ =0x000002E9
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #3
	bl FUN_08080e0c
	b _080837E4
	.align 2, 0
_080837C0: .4byte 0x000001E3
_080837C4: .4byte 0x0000037E
_080837C8: .4byte 0x00000402
_080837CC: .4byte 0x00000403
_080837D0: .4byte 0x000002E9
_080837D4:
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #2
	bl FUN_08080e0c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080837E4:
	ldr r2, _080837FC @ =0x0000095E
	adds r1, r7, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r7, r3
	movs r0, #0x20
	strh r0, [r1]
	b _08083E9C
	.align 2, 0
_080837FC: .4byte 0x0000095E
_08083800:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _08083874 @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r4, _08083878 @ =0x0000037E
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _08083828
	b _08083E9C
_08083828:
	ldr r0, _0808387C @ =0x00000366
	bl PlaySound_082406e0
	movs r6, #0xba
	lsls r6, r6, #2
	adds r2, r7, r6
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r3, _08083880 @ =0x00000A8A
	adds r1, r7, r3
	strh r0, [r1]
	ldr r4, _08083884 @ =0x000004A4
	adds r1, r7, r4
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r6, _08083888 @ =0x000004A7
	adds r1, r7, r6
	strb r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_08084734
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #4
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083874: .4byte 0x000001E3
_08083878: .4byte 0x0000037E
_0808387C: .4byte 0x00000366
_08083880: .4byte 0x00000A8A
_08083884: .4byte 0x000004A4
_08083888: .4byte 0x000004A7
_0808388C:
	ldr r2, _080838F8 @ =0x000003E6
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #0x80
	bl FUN_08080ec8
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080838AE
	b _08083B48
_080838AE:
	movs r6, #0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #8
	ldrh r1, [r0]
	adds r1, #0x23
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080838FC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080838F4
	cmp r1, #0
	blt _080838F4
	ldr r0, _08083900 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080838F4
	ldr r0, _08083904 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083908
_080838F4:
	movs r4, #0
	b _08083916
	.align 2, 0
_080838F8: .4byte 0x000003E6
_080838FC: .4byte 0xFFFF0000
_08083900: .4byte 0x030046A8
_08083904: .4byte 0x030046AC
_08083908:
	ldr r0, _08083928 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083916:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0808392C
	adds r0, #4
	b _08083938
	.align 2, 0
_08083928: .4byte 0x030046A4
_0808392C:
	ldr r0, _0808394C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083938:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083950
	cmp r2, #2
	beq _08083954
	b _08083958
	.align 2, 0
_0808394C: .4byte 0x030046A4
_08083950:
	ldrb r0, [r5, #4]
	b _08083956
_08083954:
	ldrb r0, [r5]
_08083956:
	subs r1, r1, r0
_08083958:
	movs r4, #0x2e
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bne _080839FA
	add r0, sp, #8
	ldrh r0, [r0]
	subs r0, #0x46
	add r1, sp, #8
	strh r0, [r1]
	adds r5, r1, #0
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0808398E
	cmp r1, #0
	blt _0808398E
	ldr r0, _08083994 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808398E
	ldr r0, _08083998 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808399C
_0808398E:
	movs r4, #0
	b _080839AA
	.align 2, 0
_08083994: .4byte 0x030046A8
_08083998: .4byte 0x030046AC
_0808399C:
	ldr r0, _080839BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080839AA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080839C0
	adds r0, #4
	b _080839CC
	.align 2, 0
_080839BC: .4byte 0x030046A4
_080839C0:
	ldr r0, _080839E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080839CC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080839E4
	cmp r2, #2
	beq _080839E8
	b _080839EC
	.align 2, 0
_080839E0: .4byte 0x030046A4
_080839E4:
	ldrb r0, [r5, #4]
	b _080839EA
_080839E8:
	ldrb r0, [r5]
_080839EA:
	subs r1, r1, r0
_080839EC:
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	cmp r1, r0
	beq _080839F6
	movs r6, #1
_080839F6:
	cmp r6, #0
	beq _08083A0A
_080839FA:
	ldr r3, _08083A44 @ =0x000004A7
	adds r1, r7, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r0, #0x80
	subs r0, r0, r2
	strb r0, [r1]
_08083A0A:
	movs r6, #0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #8
	ldrh r1, [r0, #4]
	adds r1, #0x23
	strh r1, [r0, #4]
	adds r5, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08083A40
	cmp r1, #0
	blt _08083A40
	ldr r0, _08083A48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08083A40
	ldr r0, _08083A4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083A50
_08083A40:
	movs r4, #0
	b _08083A5E
	.align 2, 0
_08083A44: .4byte 0x000004A7
_08083A48: .4byte 0x030046A8
_08083A4C: .4byte 0x030046AC
_08083A50:
	ldr r0, _08083A70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083A5E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08083A74
	adds r0, #4
	b _08083A80
	.align 2, 0
_08083A70: .4byte 0x030046A4
_08083A74:
	ldr r0, _08083A94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083A80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083A98
	cmp r2, #2
	beq _08083A9C
	b _08083AA0
	.align 2, 0
_08083A94: .4byte 0x030046A4
_08083A98:
	ldrb r0, [r5, #4]
	b _08083A9E
_08083A9C:
	ldrb r0, [r5]
_08083A9E:
	subs r1, r1, r0
_08083AA0:
	movs r4, #0x2e
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bne _08083B3E
	add r0, sp, #8
	ldrh r1, [r0, #4]
	subs r1, #0x46
	strh r1, [r0, #4]
	adds r5, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08083AD4
	cmp r1, #0
	blt _08083AD4
	ldr r0, _08083AD8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08083AD4
	ldr r0, _08083ADC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083AE0
_08083AD4:
	movs r4, #0
	b _08083AEE
	.align 2, 0
_08083AD8: .4byte 0x030046A8
_08083ADC: .4byte 0x030046AC
_08083AE0:
	ldr r0, _08083B00 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083AEE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08083B04
	adds r0, #4
	b _08083B10
	.align 2, 0
_08083B00: .4byte 0x030046A4
_08083B04:
	ldr r0, _08083B24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083B10:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083B28
	cmp r2, #2
	beq _08083B2C
	b _08083B30
	.align 2, 0
_08083B24: .4byte 0x030046A4
_08083B28:
	ldrb r0, [r5, #4]
	b _08083B2E
_08083B2C:
	ldrb r0, [r5]
_08083B2E:
	subs r1, r1, r0
_08083B30:
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	cmp r1, r0
	beq _08083B3A
	movs r6, #1
_08083B3A:
	cmp r6, #0
	beq _08083B48
_08083B3E:
	ldr r3, _08083BE0 @ =0x000004A7
	adds r1, r7, r3
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
_08083B48:
	ldr r4, _08083BE4 @ =0x0000037E
	adds r0, r7, r4
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08083BA2
	movs r6, #0xec
	lsls r6, r6, #2
	adds r4, r7, r6
	adds r0, r4, #0
	bl FUN_08084734
	ldr r0, _08083BE8 @ =0x0203B400
	mov r8, r0
	ldr r1, _08083BEC @ =0x030046B8
	mov ip, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r3, _08083BF0 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrh r0, [r4]
	subs r0, #0xff
	ldr r6, _08083BF4 @ =0x000001FF
	adds r5, r6, #0
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r4]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	subs r3, #0x4b
	adds r2, r7, r3
	ldrh r0, [r2]
	subs r0, #0xff
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_08083BA2:
	movs r4, #0xec
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r2, #0x2c
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #0xed
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r6, #0x30
	ldrsh r2, [r7, r6]
	subs r1, r1, r2
	bl FUN_0823785c
	ldr r1, _08083BE0 @ =0x000004A7
	adds r3, r7, r1
	ldrb r2, [r3]
	subs r0, r0, r2
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _08083BF8
	adds r0, r2, #2
	b _08083BFC
	.align 2, 0
_08083BE0: .4byte 0x000004A7
_08083BE4: .4byte 0x0000037E
_08083BE8: .4byte 0x0203B400
_08083BEC: .4byte 0x030046B8
_08083BF0: .4byte 0x000003FF
_08083BF4: .4byte 0x000001FF
_08083BF8:
	adds r0, r2, #0
	adds r0, #0xfe
_08083BFC:
	strb r0, [r3]
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, #0x80
	bls _08083C20
	ldr r6, _08083C1C @ =0x000004A4
	adds r1, r7, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08083C36
	movs r0, #0x20
	b _08083C34
	.align 2, 0
_08083C1C: .4byte 0x000004A4
_08083C20:
	adds r0, r1, #0
	subs r0, #0x61
	cmp r0, #0x3e
	bhi _08083C36
	ldr r0, _08083C58 @ =0x000004A4
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08083C36
	subs r0, #1
_08083C34:
	strh r0, [r1]
_08083C36:
	ldr r2, _08083C5C @ =0x085B0A08
	ldr r1, _08083C60 @ =0x000004A7
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08083C64
	asrs r0, r0, #0xc
	b _08083C6A
	.align 2, 0
_08083C58: .4byte 0x000004A4
_08083C5C: .4byte 0x085B0A08
_08083C60: .4byte 0x000004A7
_08083C64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083C6A:
	strh r0, [r7, #0x34]
	ldr r1, _08083C88 @ =0x085B0A08
	ldr r3, _08083C8C @ =0x000004A7
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08083C90
	asrs r0, r0, #0xc
	b _08083C96
	.align 2, 0
_08083C88: .4byte 0x085B0A08
_08083C8C: .4byte 0x000004A7
_08083C90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083C96:
	strh r0, [r7, #0x38]
	ldr r6, _08083D0C @ =0x00000A8A
	adds r5, r7, r6
	ldrh r0, [r5]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r5]
	ldr r0, _08083D10 @ =0x000009E4
	adds r2, r7, r0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08083D14 @ =0x000009E6
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	ldrh r1, [r5]
	ldr r3, _08083D18 @ =0x000009CE
	adds r0, r7, r3
	strb r1, [r0]
	ldrh r1, [r5]
	ldr r0, _08083D1C @ =0x0000010F
	subs r0, r0, r1
	movs r4, #0xff
	ands r0, r4
	asrs r0, r0, #5
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r7, r6
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08080c64
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r1, [r5]
	movs r0, #0xd0
	lsls r0, r0, #1
	subs r5, r0, r1
	ands r5, r4
	ldr r1, _08083D20 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08083D24
	asrs r1, r0, #0xc
	b _08083D2A
	.align 2, 0
_08083D0C: .4byte 0x00000A8A
_08083D10: .4byte 0x000009E4
_08083D14: .4byte 0x000009E6
_08083D18: .4byte 0x000009CE
_08083D1C: .4byte 0x0000010F
_08083D20: .4byte 0x085B0A08
_08083D24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08083D2A:
	add r3, sp, #0x10
	ldrh r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08083D60 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _08083D64 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _08083D68 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08083D6C
	asrs r0, r0, #0xc
	b _08083D72
	.align 2, 0
_08083D60: .4byte 0xFFFF0000
_08083D64: .4byte 0x0000FFFF
_08083D68: .4byte 0x085B0A08
_08083D6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083D72:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _08083E2C @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r7, r0
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08083E30 @ =0x00000A52
	adds r0, r7, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_08236400
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _08083E34 @ =0x0000037E
	adds r4, r7, r2
	ldrh r0, [r4]
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	bne _08083DEE
	ldr r2, _08083E38 @ =0x0000FFFF
	str r1, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r6
	str r0, [r1, #4]
	ldr r0, [sp, #0x20]
	ands r0, r6
	movs r3, #0x20
	orrs r0, r3
	ands r0, r2
	str r0, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r6
	orrs r0, r3
	str r0, [r2, #4]
	adds r0, r7, #0
	adds r0, #0x2c
	movs r3, #2
	str r3, [sp]
	movs r3, #4
	str r3, [sp, #4]
	movs r3, #1
	bl FUN_080dbcec
_08083DEE:
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08083E00
	movs r0, #0x81
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08083E00:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08083E3C @ =0x00000403
	adds r1, r7, r3
	ldrb r1, [r1]
	adds r1, #1
	lsls r1, r1, #5
	cmp r0, r1
	blt _08083E9C
	ldr r0, _08083E40 @ =0x00000366
	bl sound_08240740
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #5
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083E2C: .4byte 0xFFFF0000
_08083E30: .4byte 0x00000A52
_08083E34: .4byte 0x0000037E
_08083E38: .4byte 0x0000FFFF
_08083E3C: .4byte 0x00000403
_08083E40: .4byte 0x00000366
_08083E44:
	ldr r1, _08083E6C @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r4, _08083E70 @ =0x0000037E
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08083E9C
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #6
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083E6C: .4byte 0x000001E3
_08083E70: .4byte 0x0000037E
_08083E74:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r6, _08083EA8 @ =0x0000037E
	adds r1, r7, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08083E9C
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08083E9C:
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08083EA8: .4byte 0x0000037E

	thumb_func_start FUN_08083eac
FUN_08083eac: @ 0x08083EAC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r6, _08083EE8 @ =0x03002BF0
	ldrh r0, [r6]
	cmp r0, #0
	beq _08083ECC
	ldr r0, _08083EEC @ =0x0000036A
	bl PlaySound_082406e0
	ldr r1, _08083EF0 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _08083EF4 @ =0x00000474
	adds r0, r4, r2
	strh r1, [r0]
_08083ECC:
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _08083EFC
	ldr r1, _08083EF8 @ =0x000003D2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08083F3C
	movs r0, #0x19
	b _08084068
	.align 2, 0
_08083EE8: .4byte 0x03002BF0
_08083EEC: .4byte 0x0000036A
_08083EF0: .4byte 0x00000472
_08083EF4: .4byte 0x00000474
_08083EF8: .4byte 0x000003D2
_08083EFC:
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r5, [r0]
	adds r0, r5, #0
	subs r0, #0x18
	cmp r0, #1
	bls _08083F66
	cmp r5, #0x15
	beq _08083F66
	ldrh r0, [r6]
	cmp r0, #0
	beq _08083F48
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	ldr r1, _08083F40 @ =0xFFFFF9FE
	ands r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #0x32
	strh r0, [r3]
	ldr r2, _08083F44 @ =0x000003D2
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
_08083F3C:
	movs r0, #0x18
	b _08084068
	.align 2, 0
_08083F40: .4byte 0xFFFFF9FE
_08083F44: .4byte 0x000003D2
_08083F48:
	cmp r5, #0x12
	beq _08083F56
	ldr r1, _08083F5C @ =0x00000474
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _08083F60
_08083F56:
	movs r0, #0x12
	b _08084068
	.align 2, 0
_08083F5C: .4byte 0x00000474
_08083F60:
	subs r0, r5, #2
	cmp r0, #1
	bhi _08083F6A
_08083F66:
	adds r0, r5, #0
	b _08084068
_08083F6A:
	cmp r5, #0x13
	bne _08083F72
	movs r0, #0x13
	b _08084068
_08083F72:
	ldr r0, _08083FD0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08083FF0
	ldr r2, _08083FD4 @ =0x00000466
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08083FF6
	ldr r3, _08083FD8 @ =0x00000467
	adds r0, r4, r3
	ldrb r0, [r0]
	bl FUN_08081da4
	cmp r0, #0
	beq _08083FE0
	add r2, sp, #8
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08081de0
	cmp r0, #0
	beq _08083FE0
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08083FE0
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #8]
	ldr r3, _08083FDC @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	movs r0, #0x13
	b _08084068
	.align 2, 0
_08083FD0: .4byte 0x03002BE0
_08083FD4: .4byte 0x00000466
_08083FD8: .4byte 0x00000467
_08083FDC: .4byte 0x00000471
_08083FE0:
	ldr r0, _08083FEC @ =0x00000466
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08083FF6
	.align 2, 0
_08083FEC: .4byte 0x00000466
_08083FF0:
	ldr r2, _08084000 @ =0x00000466
	adds r0, r4, r2
	strb r1, [r0]
_08083FF6:
	cmp r5, #1
	bne _08084004
	movs r0, #1
	b _08084068
	.align 2, 0
_08084000: .4byte 0x00000466
_08084004:
	cmp r5, #0x14
	bne _0808400C
	movs r0, #0x14
	b _08084068
_0808400C:
	cmp r5, #8
	bne _08084014
	movs r0, #8
	b _08084068
_08084014:
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _0808403C @ =0x000004A6
	adds r5, r4, r2
	ldrb r2, [r5]
	lsls r2, r2, #3
	movs r3, #0x8f
	lsls r3, r3, #3
	adds r2, r2, r3
	adds r2, r4, r2
	bl FUN_08235f40
	cmp r0, #0
	bne _08084040
	movs r0, #0
	b _08084068
	.align 2, 0
_0808403C: .4byte 0x000004A6
_08084040:
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r1, _08084070 @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _08084074 @ =0x00000471
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r5]
	movs r0, #2
_08084068:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08084070: .4byte 0x0000047E
_08084074: .4byte 0x00000471

	thumb_func_start FUN_08084078
FUN_08084078: @ 0x08084078
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrh r1, [r5, #0x34]
	ldrh r0, [r5, #0x2c]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080840D0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r5, #0x38]
	ldrh r0, [r5, #0x30]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080840CC
	cmp r1, #0
	blt _080840CC
	ldr r0, _080840D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080840CC
	ldr r0, _080840D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080840DC
_080840CC:
	movs r4, #0
	b _080840EA
	.align 2, 0
_080840D0: .4byte 0xFFFF0000
_080840D4: .4byte 0x030046A8
_080840D8: .4byte 0x030046AC
_080840DC:
	ldr r0, _080840FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080840EA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08084100
	adds r0, #4
	b _0808410C
	.align 2, 0
_080840FC: .4byte 0x030046A4
_08084100:
	ldr r0, _08084160 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808410C:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808411C
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_0808411C:
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_08080ed8
	cmp r0, #0
	beq _080841C0
	movs r0, #0
	str r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_0823b4b8
	adds r6, r5, #0
	adds r6, #0x2c
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0808415C
	cmp r1, #0
	blt _0808415C
	ldr r0, _08084164 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808415C
	ldr r0, _08084168 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808416C
_0808415C:
	movs r4, #0
	b _0808417A
	.align 2, 0
_08084160: .4byte 0x030046A4
_08084164: .4byte 0x030046A8
_08084168: .4byte 0x030046AC
_0808416C:
	ldr r0, _0808418C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808417A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08084190
	adds r0, #4
	b _0808419C
	.align 2, 0
_0808418C: .4byte 0x030046A4
_08084190:
	ldr r0, _080841B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808419C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080841B4
	cmp r2, #2
	beq _080841B8
	b _080841BC
	.align 2, 0
_080841B0: .4byte 0x030046A4
_080841B4:
	ldrb r0, [r6, #4]
	b _080841BA
_080841B8:
	ldrb r0, [r6]
_080841BA:
	subs r1, r1, r0
_080841BC:
	strh r1, [r5, #0x2e]
	b _080841E0
_080841C0:
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _080841D8
	movs r1, #0xde
	lsls r1, r1, #1
	adds r4, r5, r1
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_0823280c
	str r4, [r5, #0x3c]
_080841D8:
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_0823b4b8
_080841E0:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08080ed8
	cmp r0, #0
	beq _080841FC
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _0808421A
_080841FC:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _08084230 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_0808421A:
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_08080ed8
	cmp r0, #0
	beq _08084238
	ldr r0, _08084234 @ =0x00000464
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _08084262
	.align 2, 0
_08084230: .4byte 0x0000FFFB
_08084234: .4byte 0x00000464
_08084238:
	ldr r1, _08084298 @ =0x00000464
	adds r4, r5, r1
	ldrb r0, [r4]
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r0, #0
	bne _08084256
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r6, #0
	bl FUN_082362fc
	movs r0, #1
	strb r0, [r4]
_08084256:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r6, #0
	bl FUN_08236268
_08084262:
	adds r2, r5, #0
	adds r2, #0xa8
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r5, #0
	adds r1, #0xaa
	ldr r2, _0808429C @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842A0
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080842AC
	.align 2, 0
_08084298: .4byte 0x00000464
_0808429C: .4byte 0x000003F6
_080842A0:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080842AC:
	str r1, [r0]
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842C6
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _080842CC
_080842C6:
	ldr r0, [r4]
	ldr r1, _080842E4 @ =0xFFFFFDFF
	ands r0, r1
_080842CC:
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842EC
	ldr r1, _080842E8 @ =0x0000060C
	adds r0, r5, r1
	bl FUN_080136b4
	b _080842F4
	.align 2, 0
_080842E4: .4byte 0xFFFFFDFF
_080842E8: .4byte 0x0000060C
_080842EC:
	ldr r2, _08084310 @ =0x0000060C
	adds r0, r5, r2
	bl FUN_08013698
_080842F4:
	adds r0, r5, #0
	movs r1, #0x80
	bl FUN_08080ed8
	cmp r0, #0
	beq _08084318
	ldr r1, _08084314 @ =0x000009C8
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08084322
	.align 2, 0
_08084310: .4byte 0x0000060C
_08084314: .4byte 0x000009C8
_08084318:
	ldr r2, _0808432C @ =0x000009C8
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08084322:
	str r1, [r0]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808432C: .4byte 0x000009C8

	thumb_func_start FUN_08084330
FUN_08084330: @ 0x08084330
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	beq _08084340
	cmp r0, #2
	beq _08084388
	b _080843A4
_08084340:
	ldr r0, [r4, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808435E
	ldr r0, _0808437C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08084380 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	asrs r1, r1, #1
	adds r0, r4, #0
	bl FUN_08081d18
_0808435E:
	adds r0, r4, #0
	bl FUN_08083eac
	ldr r1, _08084384 @ =0x085ABF54
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08084078
	b _080843A4
	.align 2, 0
_0808437C: .4byte 0x030046A0
_08084380: .4byte 0x00000942
_08084384: .4byte 0x085ABF54
_08084388:
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08080ec8
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08084078
_080843A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080843ac
FUN_080843ac: @ 0x080843AC
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r6, [r4, #0x1c]
	cmp r6, #1
	beq _080843BC
	b _0808453A
_080843BC:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r3, #6]
	ands r0, r1
	cmp r0, #0
	beq _080843DE
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080843D8
	b _0808453A
_080843D8:
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2]
_080843DE:
	adds r0, r3, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	mov ip, r2
	strh r1, [r0]
	movs r7, #0xdf
	lsls r7, r7, #2
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #8
	bne _0808449C
	ldr r1, _08084440 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808449C
	ldr r2, _08084444 @ =0x00000476
	adds r1, r4, r2
	movs r0, #4
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0808444C
	ldr r3, _08084448 @ =0x0000046B
	adds r2, r4, r3
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r7, #0xee
	adds r1, r4, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08084490
	mov r0, ip
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08080e0c
	b _0808453A
	.align 2, 0
_08084440: .4byte 0x0000037D
_08084444: .4byte 0x00000476
_08084448: .4byte 0x0000046B
_0808444C:
	ldr r1, _08084488 @ =0x00000469
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r1, r4, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08084490
	mov r0, ip
	strb r0, [r2]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08080f20
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0808448C @ =0x000003D2
	adds r0, r4, r3
	strb r6, [r0]
	adds r1, r5, #0
	adds r1, #0x40
	movs r0, #0x64
	b _08084538
	.align 2, 0
_08084488: .4byte 0x00000469
_0808448C: .4byte 0x000003D2
_08084490:
	ldr r0, _08084498 @ =0x0000036A
	bl PlaySound_082406e0
	b _0808453A
	.align 2, 0
_08084498: .4byte 0x0000036A
_0808449C:
	ldr r7, _080844C8 @ =0x00000469
	adds r1, r4, r7
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080844BC
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080844CC
_080844BC:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r5, #0
	bl FUN_08080f80
	b _0808453A
	.align 2, 0
_080844C8: .4byte 0x00000469
_080844CC:
	adds r0, r3, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r2, _08084500 @ =0x000003E6
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08084504
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r4, r3
	b _08084538
	.align 2, 0
_08084500: .4byte 0x000003E6
_08084504:
	movs r7, #0x24
	ldrsh r0, [r3, r7]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r7, #0x28
	ldrsh r1, [r3, r7]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #4
	ands r0, r1
	movs r7, #0xfa
	lsls r7, r7, #2
	adds r1, r4, r7
_08084538:
	strh r0, [r1]
_0808453A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08084540
FUN_08084540: @ 0x08084540
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0]
	cmp r5, #0
	ble _0808458E
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08080ec8
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0808458E
	subs r5, #1
	cmp r5, #0
	beq _08084586
	ldr r1, _08084594 @ =0x00000476
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08084586
	asrs r0, r5, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08084586
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08080ec8
_08084586:
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_0808458E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084594: .4byte 0x00000476

	thumb_func_start FUN_08084598
FUN_08084598: @ 0x08084598
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080845D4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080845CA
	adds r0, r4, #0
	bl FUN_08080e34
	adds r0, r4, #0
	bl FUN_08084540
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08081628
_080845CA:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080845D4: .4byte 0x03002BE0

	thumb_func_start LinkPlayer2P_Destroy
LinkPlayer2P_Destroy: @ 0x080845D8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x88
	bl FUN_0822f1c0
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x24
	bl FUN_0823b284
	adds r0, r4, #0
	bl FUN_0808168c
	ldr r1, _08084620 @ =0x000009C8
	adds r0, r4, r1
	bl FUN_0822a4e0
	ldr r1, _08084624 @ =0x03002BE0
	adds r4, #0x28
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	ldr r1, _08084628 @ =0x03002B98
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08084620: .4byte 0x000009C8
_08084624: .4byte 0x03002BE0
_08084628: .4byte 0x03002B98

	thumb_func_start LinkPlayer2P_Init
LinkPlayer2P_Init: @ 0x0808462C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08081ab0
	adds r0, r4, #0
	bl FUN_0808175c
	adds r0, r4, #0
	bl FUN_080817ec
	adds r0, r4, #0
	bl FUN_08081c04
	adds r0, r4, #0
	bl FUN_080816a0
	ldr r1, _0808466C @ =0x03002BE0
	adds r0, r4, #0
	adds r0, #0x28
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r4, [r0]
	ldr r1, _08084670 @ =0x03002B98
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0808466C: .4byte 0x03002BE0
_08084670: .4byte 0x03002B98

@ 通信対戦のプレイヤー (かならず gPlayerPtr[1] に格納される) を作成する
	thumb_func_start CreateLinkPlayer2P
CreateLinkPlayer2P: @ 0x08084674
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080846B0 @ =0x03002BE0
	ldr r0, [r0, #4]
	cmp r0, #0
	bne _080846C2
	ldr r1, _080846B4 @ =0x00000AC4
	movs r0, #6
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080846C0
	ldr r1, _080846B8 @ =FUN_08084598
	ldr r2, _080846BC @ =LinkPlayer2P_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl LinkPlayer2P_Init
	cmp r0, #0
	bge _080846C0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080846C2
	.align 2, 0
_080846B0: .4byte 0x03002BE0
_080846B4: .4byte 0x00000AC4
_080846B8: .4byte FUN_08084598
_080846BC: .4byte LinkPlayer2P_Destroy
_080846C0:
	adds r0, r4, #0
_080846C2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080846c8
FUN_080846c8: @ 0x080846C8
	push {r4, lr}
	ldr r4, _080846F0 @ =0x03002BFC
	ldr r0, [r4]
	cmp r0, #0
	beq _080846E8
	adds r0, #0xb1
	ldrb r0, [r0]
	cmp r0, #6
	bne _080846E8
	ldr r0, _080846F4 @ =0x0000020E
	bl PlaySound_082406e0
	ldr r0, [r4]
	adds r0, #0xb5
	movs r1, #1
	strb r1, [r0]
_080846E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080846F0: .4byte 0x03002BFC
_080846F4: .4byte 0x0000020E

	thumb_func_start FUN_080846f8
FUN_080846f8: @ 0x080846F8
	push {lr}
	ldr r0, _0808470C @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _08084708
	movs r1, #7
	bl FUN_08084c30
_08084708:
	pop {r0}
	bx r0
	.align 2, 0
_0808470C: .4byte 0x03002BFC

	thumb_func_start FUN_08084710
FUN_08084710: @ 0x08084710
	push {lr}
	ldr r0, _08084728 @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _08084722
	adds r0, #0xb1
	ldrb r0, [r0]
	cmp r0, #6
	beq _0808472C
_08084722:
	movs r0, #0
	b _0808472E
	.align 2, 0
_08084728: .4byte 0x03002BFC
_0808472C:
	movs r0, #1
_0808472E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08084734
FUN_08084734: @ 0x08084734
	push {lr}
	adds r2, r0, #0
	ldr r0, _08084750 @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _0808474A
	adds r0, #0xc0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_0808474A:
	pop {r0}
	bx r0
	.align 2, 0
_08084750: .4byte 0x03002BFC

	thumb_func_start FUN_08084754
FUN_08084754: @ 0x08084754
	push {lr}
	ldr r3, _08084790 @ =0x03002BFC
	ldr r0, [r3]
	cmp r0, #0
	beq _0808478A
	adds r2, r0, #0
	adds r2, #0xac
	adds r0, #0xae
	ldrb r1, [r0]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	ldr r1, _08084794 @ =0x13FF0000
	cmp r0, r1
	bls _0808477A
	movs r0, #0xa0
	lsls r0, r0, #5
	strh r0, [r2]
_0808477A:
	ldr r0, [r3]
	adds r0, #0xb0
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0xb8
	movs r1, #0
	strh r1, [r0]
_0808478A:
	pop {r0}
	bx r0
	.align 2, 0
_08084790: .4byte 0x03002BFC
_08084794: .4byte 0x13FF0000

	thumb_func_start FUN_08084798
FUN_08084798: @ 0x08084798
	push {lr}
	adds r1, r0, #0
	ldr r0, _080847AC @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _080847A8
	adds r0, #0xb8
	strh r1, [r0]
_080847A8:
	pop {r0}
	bx r0
	.align 2, 0
_080847AC: .4byte 0x03002BFC

	thumb_func_start FUN_080847b0
FUN_080847b0: @ 0x080847B0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2e]
	adds r0, #1
	movs r5, #0
	strh r0, [r3, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0808485E
	movs r0, #0x18
	ldrsh r2, [r3, r0]
	ldr r1, [r3, #0x28]
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r2, r2, r0
	adds r4, r1, #0
	cmp r2, #0
	bge _080847D8
	rsbs r2, r2, #0
_080847D8:
	movs r6, #0x1c
	ldrsh r1, [r3, r6]
	movs r6, #4
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080847E8
	rsbs r1, r1, #0
_080847E8:
	cmp r2, #0x7f
	bgt _080847F0
	cmp r1, #0x7f
	ble _0808485E
_080847F0:
	movs r0, #0x32
	ldrsh r2, [r3, r0]
	ldrh r1, [r3, #0x2e]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r5, r0, #4
	ldrh r0, [r3, #0x30]
	adds r0, #1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r3, #0x30]
	ldr r2, _08084828 @ =0x085B0A08
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r5, r0
	cmp r0, #0
	blt _0808482C
	asrs r1, r0, #0xc
	b _08084832
	.align 2, 0
_08084828: .4byte 0x085B0A08
_0808482C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084832:
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r3, #0x18]
	ldrh r1, [r3, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08084850
	asrs r1, r0, #0xc
	b _08084856
_08084850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084856:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	b _08084868
_0808485E:
	strh r5, [r3, #0x2c]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_08084868:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084870
FUN_08084870: @ 0x08084870
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _0808491C @ =0x000003A6
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08084920 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0808488E
	b _0808499A
_0808488E:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0xd4
	adds r6, r7, r0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	ldr r1, _08084924 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r6]
	adds r0, r7, #0
	adds r0, #0xc0
	str r0, [r6, #0x28]
	ldr r5, _08084928 @ =0x0203B400
	ldr r4, _0808492C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	adds r3, #0x5b
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldr r2, _08084930 @ =0x000001FF
	mov ip, r2
	mov r2, ip
	ands r1, r2
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r1, [r6, #0x32]
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0xff
	ands r0, r1
	strh r0, [r6, #0x30]
	adds r0, r7, #0
	adds r0, #0xd0
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #1
	bl FUN_0822dafc
	ldr r2, _08084934 @ =0x085B0A08
	movs r3, #0x30
	ldrsh r0, [r6, r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0x32
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08084938
	asrs r1, r0, #0xc
	b _0808493E
	.align 2, 0
_0808491C: .4byte 0x000003A6
_08084920: .4byte 0x0000FFFF
_08084924: .4byte 0xFFFFFDFF
_08084928: .4byte 0x0203B400
_0808492C: .4byte 0x030046B8
_08084930: .4byte 0x000001FF
_08084934: .4byte 0x085B0A08
_08084938:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808493E:
	ldr r2, [r6, #0x28]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r6, #0x18]
	ldrh r0, [r2, #2]
	strh r0, [r6, #0x1a]
	ldr r3, _08084968 @ =0x085B0A08
	ldrh r1, [r6, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0x32
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808496C
	asrs r1, r0, #0xc
	b _08084972
	.align 2, 0
_08084968: .4byte 0x085B0A08
_0808496C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084972:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r6, #0x1c]
	ldr r0, _080849A0 @ =FUN_080847b0
	str r0, [r6, #0x38]
	movs r0, #1
	strh r0, [r6, #0x2c]
	strh r2, [r6, #0x2e]
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _0808499A
	strh r2, [r1]
_0808499A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080849A0: .4byte FUN_080847b0

	thumb_func_start FUN_080849a4
FUN_080849a4: @ 0x080849A4
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldrh r0, [r4, #0x2e]
	adds r2, r0, #1
	strh r2, [r4, #0x2e]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08084A00
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x36]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r4, #0x34]
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r4, #0x36]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bne _080849F2
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #4
	bl FUN_0822dafc
_080849F2:
	ldrh r0, [r4, #0x2e]
	cmp r0, #0xa
	bne _08084A0C
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	b _08084A08
_08084A00:
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4]
	movs r1, #1
_08084A08:
	orrs r0, r1
	str r0, [r4]
_08084A0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084a14
FUN_08084a14: @ 0x08084A14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _08084AE0 @ =0x0000020D
	bl PlaySound_082406e0
	ldr r7, _08084AE4 @ =0x030046B8
	ldr r0, _08084AE8 @ =0x000003FF
	mov sl, r0
	movs r1, #0
	str r1, [sp]
	adds r6, r5, #0
	adds r6, #0xd4
	adds r4, r6, #0
	movs r2, #0xff
	mov sb, r2
	movs r3, #0xb
	mov r8, r3
_08084A40:
	ldr r1, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	ldr r0, _08084AEC @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r4]
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r1, [r0]
	ldr r0, [r7]
	adds r0, #1
	mov r2, sl
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _08084AF0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	adds r2, #4
	adds r0, r6, #0
	bl FUN_0822dafc
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r0, [r0]
	strh r0, [r4, #0x18]
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r0, [r0]
	strh r0, [r4, #0x1a]
	adds r0, r5, #0
	adds r0, #0xc4
	ldrh r0, [r0]
	strh r0, [r4, #0x1c]
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _08084AF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x60
	bl Mod
	adds r2, r0, #0
	adds r2, #0x30
	ldr r0, [r7]
	adds r0, #1
	mov r3, sl
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _08084AF0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	ldr r3, [sp]
	adds r1, r3, r0
	mov r0, sb
	ands r1, r0
	adds r0, r1, #0
	adds r0, #0x40
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #1
	ldr r3, _08084AF4 @ =0x085B0A08
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08084AF8
	asrs r0, r0, #0xc
	b _08084AFE
	.align 2, 0
_08084AE0: .4byte 0x0000020D
_08084AE4: .4byte 0x030046B8
_08084AE8: .4byte 0x000003FF
_08084AEC: .4byte 0xFFFFFDFF
_08084AF0: .4byte 0x0203B400
_08084AF4: .4byte 0x085B0A08
_08084AF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08084AFE:
	strh r0, [r4, #0x34]
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	ldr r1, _08084B18 @ =0x085B0A08
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08084B1C
	asrs r1, r0, #0xc
	b _08084B22
	.align 2, 0
_08084B18: .4byte 0x085B0A08
_08084B1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084B22:
	movs r0, #0
	strh r1, [r4, #0x36]
	ldr r1, _08084B58 @ =FUN_080849a4
	str r1, [r4, #0x38]
	movs r1, #1
	strh r1, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	ldr r0, [sp]
	adds r0, #0x14
	str r0, [sp]
	adds r4, #0x3c
	adds r6, #0x3c
	subs r1, #2
	add r8, r1
	mov r2, r8
	cmp r2, #0
	blt _08084B46
	b _08084A40
_08084B46:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084B58: .4byte FUN_080849a4

	thumb_func_start FUN_08084b5c
FUN_08084b5c: @ 0x08084B5C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xd4
	movs r7, #0
	movs r6, #0xb
_08084B68:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	beq _08084B84
	movs r0, #0x86
	lsls r0, r0, #1
	adds r2, r5, r0
	adds r2, r2, r7
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r1, [r0]
	ldr r2, [r2]
	adds r0, r4, #0
	bl _call_via_r2
_08084B84:
	adds r4, #0x3c
	adds r7, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _08084B68
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08084b94
FUN_08084b94: @ 0x08084B94
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0xd4
	movs r5, #0xb
_08084B9C:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _08084B9C
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08084bb0
FUN_08084bb0: @ 0x08084BB0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08084C28 @ =0x000003A6
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08084C2C @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r4, #0
	adds r1, #0xd0
	str r0, [r1]
	adds r5, r1, #0
	movs r0, #0
	mov r8, r0
	adds r4, #0xd4
	movs r7, #4
	rsbs r7, r7, #0
	movs r6, #0xb
_08084BE2:
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl FUN_0822dad4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	mov r1, r8
	strh r1, [r4, #0x2c]
	strh r1, [r4, #0x2e]
	adds r4, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _08084BE2
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084C28: .4byte 0x000003A6
_08084C2C: .4byte 0x00001C1E

	thumb_func_start FUN_08084c30
FUN_08084c30: @ 0x08084C30
	mov ip, r0
	adds r0, #0xb1
	movs r3, #0
	strb r1, [r0]
	movs r2, #0xea
	lsls r2, r2, #2
	add r2, ip
	ldr r1, _08084C54 @ =0x085ABFC8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	mov r0, ip
	adds r0, #0xb2
	strh r3, [r0]
	bx lr
	.align 2, 0
_08084C54: .4byte 0x085ABFC8

	thumb_func_start FUN_08084c58
FUN_08084c58: @ 0x08084C58
	push {lr}
	adds r3, r0, #0
	adds r0, #0xac
	ldrh r0, [r0]
	cmp r0, #0
	beq _08084C96
	ldr r0, [r3, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x18]
	ldr r0, [r3, #0x60]
	ands r0, r1
	str r0, [r3, #0x60]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r1, #0xa
	movs r0, #0x50
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xb5
	strb r2, [r0]
	adds r0, r3, #0
	movs r1, #1
	bl FUN_08084c30
_08084C96:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084c9c
FUN_08084c9c: @ 0x08084C9C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xaa
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	ldr r1, _08084CE4 @ =0x0000FFFF
	adds r6, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08084CC2
	movs r0, #0x20
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08084c30
_08084CC2:
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r5, #0
	adds r1, #0xa8
	strh r0, [r1]
	ands r0, r6
	cmp r0, #0
	bne _08084CDE
	movs r0, #1
	strh r0, [r1]
_08084CDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08084CE4: .4byte 0x0000FFFF

	thumb_func_start FUN_08084ce8
FUN_08084ce8: @ 0x08084CE8
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xaa
	ldrh r0, [r1]
	cmp r0, #4
	bhi _08084D1C
	adds r0, r4, #0
	bl FUN_08084a14
	adds r1, r4, #0
	adds r1, #0xac
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x60]
	orrs r0, r1
	str r0, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08084c30
	b _08084D3C
_08084D1C:
	subs r0, #4
	strh r0, [r1]
	ldrh r1, [r1]
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r4, #0
	adds r1, #0xa8
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08084D3C
	movs r0, #1
	strh r0, [r1]
_08084D3C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084d44
FUN_08084d44: @ 0x08084D44
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0xac
	ldrh r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bls _08084D62
	strh r1, [r2]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08084c30
	b _08084D6E
_08084D62:
	cmp r0, #0
	bne _08084D6E
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08084c30
_08084D6E:
	adds r0, r4, #0
	adds r0, #0xac
	ldrh r1, [r0]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r5, r4, #0
	adds r5, #0xaa
	strh r1, [r5]
	ldr r3, _08084DBC @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084DC0 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084DC4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
	ldrh r2, [r5]
	adds r1, r4, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084DBC: .4byte 0x030046B8
_08084DC0: .4byte 0x000003FF
_08084DC4: .4byte 0x0203B400

	thumb_func_start FUN_08084dc8
FUN_08084dc8: @ 0x08084DC8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xac
	ldrh r0, [r4]
	adds r0, #0x60
	strh r0, [r4]
	lsls r0, r0, #0x10
	ldr r1, _08084E44 @ =0x13FF0000
	cmp r0, r1
	bls _08084DF4
	movs r0, #0xba
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0xa0
	lsls r0, r0, #5
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #6
	bl FUN_08084c30
_08084DF4:
	adds r0, r5, #0
	bl FUN_08084870
	ldrh r1, [r4]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084E48 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084E4C @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084E50 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084E44: .4byte 0x13FF0000
_08084E48: .4byte 0x030046B8
_08084E4C: .4byte 0x000003FF
_08084E50: .4byte 0x0203B400

	thumb_func_start FUN_08084e54
FUN_08084e54: @ 0x08084E54
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xac
	ldrh r0, [r4]
	subs r0, #0x60
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bhi _08084E78
	strh r1, [r4]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08084c30
_08084E78:
	ldrh r1, [r4]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084EC0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084EC4 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084EC8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084EC0: .4byte 0x030046B8
_08084EC4: .4byte 0x000003FF
_08084EC8: .4byte 0x0203B400

	thumb_func_start FUN_08084ecc
FUN_08084ecc: @ 0x08084ECC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0xac
	ldrh r1, [r0]
	ldr r0, _08084EE4 @ =0x000013FF
	cmp r1, r0
	bls _08084EE8
	adds r0, r5, #0
	bl FUN_08084870
	b _08084EF8
	.align 2, 0
_08084EE4: .4byte 0x000013FF
_08084EE8:
	adds r1, r5, #0
	adds r1, #0xb5
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08084c30
_08084EF8:
	adds r4, r5, #0
	adds r4, #0xba
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bls _08084F14
	ldr r0, _08084F6C @ =0x0000020F
	bl PlaySound_082406e0
	movs r0, #0
	strh r0, [r4]
_08084F14:
	adds r0, r5, #0
	adds r0, #0xac
	ldrh r1, [r0]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084F70 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084F74 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084F78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0xa8
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x78
	bls _08084F66
	movs r0, #0x78
	strh r0, [r2]
_08084F66:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084F6C: .4byte 0x0000020F
_08084F70: .4byte 0x030046B8
_08084F74: .4byte 0x000003FF
_08084F78: .4byte 0x0203B400

	thumb_func_start FUN_08084f7c
FUN_08084f7c: @ 0x08084F7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0xaa
	ldrh r0, [r1]
	cmp r0, #0xc
	bhi _0808506C
	movs r7, #0
	movs r0, #0xc0
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0xc4
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0xac
	adds r2, r2, r6
	mov sl, r2
_08084FA6:
	mov r3, sb
	movs r0, #0
	ldrsh r2, [r3, r0]
	ldr r1, _08085064 @ =0x03002BE0
	lsls r0, r7, #2
	adds r5, r0, r1
	ldr r4, [r5]
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	mov r3, r8
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	adds r0, r2, #0
	cmp r2, #0
	bge _08084FCE
	rsbs r0, r2, #0
_08084FCE:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bgt _08085038
	adds r0, r3, #0
	cmp r3, #0
	bge _08084FDE
	rsbs r0, r3, #0
_08084FDE:
	cmp r0, r1
	bgt _08085038
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, r1
	bgt _08085038
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x64
	strh r0, [r1]
	ldr r0, [r5]
	ldr r1, _08085068 @ =0x000003D2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0823785c
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #1
	adds r0, #1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r2, r3
	strb r0, [r2]
	ldr r0, [r5]
	movs r1, #0x1e
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r1, [r0]
_08085038:
	adds r7, #1
	cmp r7, #1
	ble _08084FA6
	adds r0, r6, #0
	bl FUN_08084a14
	movs r0, #0
	mov r3, sl
	strh r0, [r3]
	ldr r0, [r6, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #0x18]
	ldr r0, [r6, #0x60]
	orrs r0, r1
	str r0, [r6, #0x60]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08084c30
	b _0808508C
	.align 2, 0
_08085064: .4byte 0x03002BE0
_08085068: .4byte 0x000003D2
_0808506C:
	subs r0, #0xc
	strh r0, [r1]
	ldrh r1, [r1]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r6, #0
	adds r1, #0xa8
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808508C
	movs r0, #1
	strh r0, [r1]
_0808508C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808509c
FUN_0808509c: @ 0x0808509C
	push {lr}
	mov ip, r0
	adds r0, #0xb0
	ldrb r0, [r0]
	cmp r0, #0
	bne _080850D0
	mov r1, ip
	adds r1, #0xb8
	ldrh r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	beq _080850B8
	subs r0, #1
	b _080850CE
_080850B8:
	mov r1, ip
	adds r1, #0xac
	mov r0, ip
	adds r0, #0xaf
	ldrb r2, [r0]
	ldrh r0, [r1]
	cmp r0, r2
	bhs _080850CC
	strh r3, [r1]
	b _080850D0
_080850CC:
	subs r0, r0, r2
_080850CE:
	strh r0, [r1]
_080850D0:
	mov r0, ip
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08085138
	mov r1, ip
	adds r1, #0xb4
	ldrb r0, [r1]
	adds r0, #6
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080850EE
	movs r0, #0x7f
	strb r0, [r1]
_080850EE:
	mov r1, ip
	adds r1, #0xb6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08085118 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808511C
	mov r2, ip
	adds r2, #0xc8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r3, ip
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	adds r0, r2, #0
	b _0808512E
	.align 2, 0
_08085118: .4byte 0x0000FFFF
_0808511C:
	mov r0, ip
	adds r0, #0xc0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, ip
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	mov r0, ip
	adds r0, #0xc8
_0808512E:
	mov r2, ip
	adds r2, #0x7c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	b _08085162
_08085138:
	mov r1, ip
	adds r1, #0xb4
	ldrb r0, [r1]
	subs r0, #6
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x4f
	bhi _0808514E
	movs r0, #0x50
	strb r0, [r1]
_0808514E:
	mov r3, ip
	adds r3, #0xc0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	mov r2, ip
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	adds r2, #0x7c
	ldr r0, [r3]
	ldr r1, [r3, #4]
_08085162:
	str r0, [r2]
	str r1, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityBD74_Update
EntityBD74_Update: @ 0x0808516C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #4
	ldr r0, _080851BC @ =0x03002BC0
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	bne _080851B4
	adds r0, r4, #0
	bl FUN_08084b5c
	adds r0, r4, #0
	bl FUN_0808509c
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	adds r0, #0xa8
	ldrh r1, [r0]
	subs r0, #0x87
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #0x8a
	ldrh r1, [r0]
	subs r0, #0x41
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #0x48
	strb r5, [r0]
_080851B4:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080851BC: .4byte 0x03002BC0

	thumb_func_start EntityBD74_Destroy
EntityBD74_Destroy: @ 0x080851C0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x60
	bl FUN_0822a4e0
	adds r0, r4, #0
	bl FUN_08084b94
	ldr r1, _080851E4 @ =0x03002BFC
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080851E4: .4byte 0x03002BFC

	thumb_func_start EntityBD74_Init
EntityBD74_Init: @ 0x080851E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08085240
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085238 @ =0xFFFF0000
	mov sb, r1
	mov r2, sb
	ands r2, r6
	orrs r2, r0
	str r2, [sp]
	adds r6, r2, #0
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r1, _0808523C @ =0x0000FFFF
	adds r2, r6, #0
	ands r2, r1
	adds r6, r2, #0
	orrs r6, r0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sb
	ands r1, r7
	adds r7, r1, #0
	orrs r7, r0
	b _08085246
	.align 2, 0
_08085238: .4byte 0xFFFF0000
_0808523C: .4byte 0x0000FFFF
_08085240:
	ldr r0, _08085298 @ =0xFFFF0000
	movs r6, #0
	ands r7, r0
_08085246:
	movs r2, #0xa8
	add r2, r8
	mov sl, r2
	movs r2, #0
	movs r3, #0
	movs r0, #1
	mov r1, sl
	strh r0, [r1]
	movs r1, #0xaa
	add r1, r8
	mov sb, r1
	strh r0, [r1]
	mov r1, r8
	adds r1, #0xb4
	movs r0, #0x50
	strb r0, [r1]
	mov r0, r8
	adds r0, #0xb5
	strb r2, [r0]
	subs r0, #9
	strh r3, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	mov r2, sl
	str r2, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	cmp r0, #0
	beq _0808529C
	bl Script_GetValue
	mov r1, r8
	adds r1, #0xae
	strb r0, [r1]
	bl Script_GetValue
	mov r1, r8
	adds r1, #0xaf
	b _080852A8
	.align 2, 0
_08085298: .4byte 0xFFFF0000
_0808529C:
	mov r1, r8
	adds r1, #0xae
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xc
_080852A8:
	strb r0, [r1]
	mov r4, r8
	adds r4, #0x18
	mov r5, r8
	adds r5, #0x44
	ldr r2, _08085368 @ =0x00003641
	mov sl, r2
	adds r0, r5, #0
	mov r1, sl
	bl Video_GetActorSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #0x32
	bl Video_SetActorSpritePltt
	movs r0, #0
	strh r0, [r4, #0x10]
	ldr r1, [sp, #8]
	ldrh r0, [r1]
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	movs r2, #2
	mov sb, r2
	mov r0, sb
	strb r0, [r4, #7]
	str r6, [r4, #0x1c]
	str r7, [r4, #0x20]
	adds r4, #0x48
	adds r5, #0x48
	adds r0, r5, #0
	mov r1, sl
	bl Video_GetActorSprite
	ldr r2, _0808536C @ =0x00000203
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a470
	adds r0, r5, #0
	movs r1, #0x32
	bl Video_SetActorSpritePltt
	movs r0, #1
	strh r0, [r4, #0x10]
	ldr r1, [sp, #0xc]
	ldrh r0, [r1]
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	mov r2, sb
	strb r2, [r4, #7]
	str r6, [r4, #0x1c]
	str r7, [r4, #0x20]
	mov r0, r8
	adds r0, #0xc0
	str r6, [r0]
	str r7, [r0, #4]
	mov r1, r8
	adds r1, #0xc8
	str r6, [r1]
	str r7, [r1, #4]
	mov r2, r8
	adds r2, #0xca
	ldrh r0, [r2]
	subs r0, #0x40
	strh r0, [r2]
	ldrh r0, [r1]
	subs r0, #0x2d
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	subs r0, #0x2d
	strh r0, [r1]
	mov r0, r8
	bl FUN_08084bb0
	mov r0, r8
	movs r1, #0
	bl FUN_08084c30
	ldr r0, _08085370 @ =0x03002BFC
	mov r1, r8
	str r1, [r0]
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
_08085368: .4byte 0x00003641
_0808536C: .4byte 0x00000203
_08085370: .4byte 0x03002BFC

	thumb_func_start EntityBD74_Create
EntityBD74_Create: @ 0x08085374
	push {r4, lr}
	ldr r0, _080853AC @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	bne _080853BA
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080853B8
	ldr r1, _080853B0 @ =EntityBD74_Update
	ldr r2, _080853B4 @ =EntityBD74_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityBD74_Init
	cmp r0, #0
	bge _080853B8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080853BA
	.align 2, 0
_080853AC: .4byte 0x03002BFC
_080853B0: .4byte EntityBD74_Update
_080853B4: .4byte EntityBD74_Destroy
_080853B8:
	adds r0, r4, #0
_080853BA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080853c0
FUN_080853c0: @ 0x080853C0
	push {r4, r5, r6, lr}
	movs r1, #0x81
	lsls r1, r1, #2
	adds r4, r0, r1
	movs r6, #4
	rsbs r6, r6, #0
	movs r5, #6
_080853CE:
	ldr r0, _08085404 @ =0x00001C1C
	bl GetParticleGroup
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r6, #0
	bl FUN_0822dad4
	movs r0, #0xff
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	subs r5, #1
	adds r4, #0x28
	cmp r5, #0
	bge _080853CE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085404: .4byte 0x00001C1C

	thumb_func_start FUN_08085408
FUN_08085408: @ 0x08085408
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r6, r0, #0
	ldr r0, _08085444 @ =0x03002BE0
	ldr r5, [r0]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r1, [r1]
	mov r8, r0
	cmp r1, #6
	beq _08085448
	movs r3, #0x81
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r2, #1
	movs r1, #6
_08085432:
	ldr r0, [r4]
	orrs r0, r2
	str r0, [r4]
	subs r1, #1
	adds r4, #0x28
	cmp r1, #0
	bge _08085432
	b _08085642
	.align 2, 0
_08085444: .4byte 0x03002BE0
_08085448:
	ldr r7, _08085490 @ =0x000002E6
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r1, _08085494 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r7, #0
	ldrsh r4, [r0, r7]
	ands r3, r2
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r7, _08085498 @ =0x000002E7
	adds r0, r5, r7
	ldrb r0, [r0]
	adds r7, r1, #0
	cmp r0, #0
	beq _080854B2
	subs r1, r2, r4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _0808549C
	asrs r0, r0, #0xc
	b _080854A2
	.align 2, 0
_08085490: .4byte 0x000002E6
_08085494: .4byte 0x085B0A08
_08085498: .4byte 0x000002E7
_0808549C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080854A2:
	adds r3, r0, #0
	adds r1, r4, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	bge _080854D6
	b _080854DA
_080854B2:
	adds r1, r4, r2
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080854C2
	asrs r0, r0, #0xc
	b _080854C8
_080854C2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080854C8:
	adds r3, r0, #0
	subs r1, r2, r4
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _080854DA
_080854D6:
	asrs r0, r0, #0xc
	b _080854E0
_080854DA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080854E0:
	adds r5, r0, #0
	mov r0, r8
	ldr r4, [r0]
	ldrh r0, [r4, #0x2c]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08085544 @ =0xFFFF0000
	adds r1, r3, #0
	ldr r2, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrh r0, [r4, #0x2e]
	adds r0, #0xdc
	lsls r0, r0, #0x10
	ldr r2, _08085548 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrh r0, [r4, #0x30]
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _0808554C
	asrs r1, r0, #0xc
	b _08085552
	.align 2, 0
_08085544: .4byte 0xFFFF0000
_08085548: .4byte 0x0000FFFF
_0808554C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08085552:
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085590 @ =0xFFFF0000
	ldr r2, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x4a
	ldrh r0, [r0]
	subs r0, #0x32
	lsls r0, r0, #0x10
	ldr r2, _08085594 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	lsls r0, r3, #1
	adds r0, r0, r7
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _08085598
	asrs r1, r0, #0xc
	b _0808559E
	.align 2, 0
_08085590: .4byte 0xFFFF0000
_08085594: .4byte 0x0000FFFF
_08085598:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808559E:
	adds r0, r6, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085654 @ =0xFFFF0000
	ldr r7, [sp, #0xc]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #0xc]
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _08085658 @ =0x000002E6
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r3, #2
	rsbs r3, r3, #0
	mov sb, r3
	cmp r0, #4
	bne _080855CE
	movs r7, #0x14
	rsbs r7, r7, #0
	mov sb, r7
_080855CE:
	movs r0, #0x81
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0
	ldr r2, [sp, #8]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	mov ip, r0
	ldr r3, [sp]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	mov sl, r0
	mov r6, ip
	asrs r7, r2, #0x10
	str r7, [sp, #0x10]
	adds r0, r3, #0
	asrs r0, r0, #0x10
	mov r8, r0
	adds r5, r7, #0
_080855F4:
	adds r3, r1, #1
	movs r2, #7
	subs r2, r2, r1
	mov r0, sl
	muls r0, r2, r0
	adds r0, r6, r0
	asrs r0, r0, #3
	strh r0, [r4, #0x18]
	mov r0, r8
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r0, r0, #3
	strh r0, [r4, #0x1a]
	ldr r1, [sp, #0xc]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r1, r0, #0
	muls r1, r3, r1
	ldr r7, [sp, #4]
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	muls r0, r2, r0
	adds r1, r1, r0
	asrs r1, r1, #3
	strh r1, [r4, #0x1c]
	mov r0, sb
	strb r0, [r4, #0x10]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	add r6, ip
	ldr r1, [sp, #0x10]
	adds r5, r5, r1
	adds r1, r3, #0
	adds r4, #0x28
	cmp r1, #6
	ble _080855F4
_08085642:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085654: .4byte 0xFFFF0000
_08085658: .4byte 0x000002E6

	thumb_func_start FUN_0808565c
FUN_0808565c: @ 0x0808565C
	push {r4, r5, lr}
	movs r1, #0x81
	lsls r1, r1, #2
	adds r4, r0, r1
	movs r5, #6
_08085666:
	adds r0, r4, #0
	bl FUN_0822dabc
	subs r5, #1
	adds r4, #0x28
	cmp r5, #0
	bge _08085666
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808567c
FUN_0808567c: @ 0x0808567C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080856C4 @ =0x0000033B
	adds r6, r4, r0
	ldrb r0, [r6]
	cmp r0, #0
	bne _080856BE
	movs r0, #0xda
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r1, _080856C8 @ =0x00001C1B
	adds r0, r5, #0
	bl Video_GetActorSprite
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r4, r0
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a470
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl nop_0822a4f8
	movs r0, #6
	strh r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r6]
_080856BE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080856C4: .4byte 0x0000033B
_080856C8: .4byte 0x00001C1B

	thumb_func_start FUN_080856cc
FUN_080856cc: @ 0x080856CC
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _080856F0 @ =0x0000033B
	adds r4, r1, r0
	ldrb r0, [r4]
	cmp r0, #1
	bne _080856E8
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r0, r1, r2
	bl FUN_0822a4e0
	movs r0, #0
	strb r0, [r4]
_080856E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080856F0: .4byte 0x0000033B

	thumb_func_start FUN_080856f4
FUN_080856f4: @ 0x080856F4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xca
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r1, r0
	cmp r1, #0x5f
	bls _0808573E
	cmp r1, #0x60
	bne _08085712
	ldr r0, _08085750 @ =0x000002AA
	bl PlaySound_082406e0
_08085712:
	ldr r2, _08085754 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08085758 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0808575C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	movs r1, #0xb
	muls r0, r1, r0
	subs r0, #5
	ldr r2, _08085760 @ =0x0000031E
	adds r1, r4, r2
	strh r0, [r1]
	rsbs r0, r0, #0
	adds r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_0808573E:
	movs r0, #0xca
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085750: .4byte 0x000002AA
_08085754: .4byte 0x030046B8
_08085758: .4byte 0x000003FF
_0808575C: .4byte 0x0203B400
_08085760: .4byte 0x0000031E

	thumb_func_start FUN_08085764
FUN_08085764: @ 0x08085764
	push {r4, r5, lr}
	sub sp, #0x20
	adds r3, r0, #0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _0808579C @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x64
	muls r0, r1, r0
	adds r5, r2, #0
	cmp r0, #0
	blt _080857A0
	asrs r1, r0, #0xc
	b _080857A6
	.align 2, 0
_0808579C: .4byte 0x085B0A08
_080857A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080857A6:
	adds r0, r3, #0
	adds r0, #0x48
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	adds r1, r3, #0
	adds r1, #0x4a
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #8]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _080857D2
	asrs r2, r0, #0xc
	b _080857D8
_080857D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080857D8:
	adds r0, r3, #0
	adds r0, #0x4c
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0808580C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08085810
	asrs r0, r0, #0xc
	b _08085816
	.align 2, 0
_0808580C: .4byte 0xFFFF0000
_08085810:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08085816:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x10]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08085832
	asrs r0, r0, #0xc
	b _08085838
_08085832:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08085838:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _08085878 @ =0xFFFF0000
	add r1, sp, #0x10
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	ldr r0, [sp, #0x18]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ldr r2, _0808587C @ =0x0000FFFF
	ands r0, r2
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	movs r0, #3
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	add r0, sp, #8
	movs r3, #1
	bl FUN_080dbd08
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085878: .4byte 0xFFFF0000
_0808587C: .4byte 0x0000FFFF

	thumb_func_start FUN_08085880
FUN_08085880: @ 0x08085880
	push {r4, lr}
	sub sp, #0x20
	mov ip, r0
	ldr r2, _080858B8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080858BC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080858C0 @ =0x0203B400
	adds r0, r0, r1
	movs r1, #0xff
	ldrb r4, [r0]
	ldr r2, _080858C4 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080858C8
	asrs r0, r0, #0xc
	b _080858CE
	.align 2, 0
_080858B8: .4byte 0x030046B8
_080858BC: .4byte 0x000003FF
_080858C0: .4byte 0x0203B400
_080858C4: .4byte 0x085B0A08
_080858C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080858CE:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _080858E6
	asrs r0, r0, #0xc
	b _080858EC
_080858E6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080858EC:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _08085968 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r1, ip
	adds r1, #0x48
	adds r0, r2, #0
	ldrh r0, [r0]
	lsls r0, r0, #2
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	mov r1, ip
	adds r1, #0x4a
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r0, ip
	adds r0, #0x4c
	ldrh r2, [r2, #4]
	lsls r2, r2, #2
	ldrh r0, [r0]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r0, sp, #0x10
	ldr r1, [r0, #4]
	ands r1, r3
	orrs r1, r2
	str r1, [r0, #4]
	movs r1, #0
	str r1, [sp, #0x18]
	add r2, sp, #0x18
	ldr r1, [r2, #4]
	ands r1, r3
	str r1, [r2, #4]
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #8
	movs r3, #1
	bl FUN_080dbd08
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _0808595E
	movs r0, #0xd3
	bl PlaySound_082406e0
_0808595E:
	add sp, #0x20
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08085968: .4byte 0xFFFF0000

	thumb_func_start FUN_0808596c
FUN_0808596c: @ 0x0808596C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	movs r0, #0
	mov sb, r0
	add r7, sp, #0x18
	ldr r5, _080859AC @ =0xFFFF0000
	ldr r1, _080859B0 @ =0x0000FFFF
	mov sl, r1
	add r4, sp, #8
	add r6, sp, #0x10
_0808598A:
	mov r2, sb
	lsls r3, r2, #5
	ldr r2, _080859B4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _080859B8
	asrs r0, r0, #0xc
	b _080859BE
	.align 2, 0
_080859AC: .4byte 0xFFFF0000
_080859B0: .4byte 0x0000FFFF
_080859B4: .4byte 0x085B0A08
_080859B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080859BE:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	ands r0, r5
	orrs r0, r1
	mov r2, sl
	ands r0, r2
	str r0, [sp, #8]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	ldr r1, _080859E8 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #4
	cmp r0, #0
	blt _080859EC
	asrs r0, r0, #0xc
	b _080859F2
	.align 2, 0
_080859E8: .4byte 0x085B0A08
_080859EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080859F2:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r4, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r4, #4]
	mov r1, r8
	adds r1, #0x48
	ldrh r0, [r4]
	lsls r0, r0, #3
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r5
	orrs r1, r0
	mov r0, r8
	adds r0, #0x4a
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x10]
	mov r0, r8
	adds r0, #0x4c
	ldrh r1, [r4, #4]
	lsls r1, r1, #3
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #4]
	ands r0, r5
	orrs r0, r1
	str r0, [r6, #4]
	movs r0, #0
	str r0, [sp, #0x18]
	ldr r0, [r7, #4]
	ands r0, r5
	str r0, [r7, #4]
	movs r0, #3
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #8
	adds r2, r7, #0
	movs r3, #1
	bl FUN_080dbd08
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #7
	ble _0808598A
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08085a74
FUN_08085a74: @ 0x08085A74
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #8
	adds r2, r1, #0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, _08085B20 @ =0x0203B400
	mov r8, r0
	ldr r1, _08085B24 @ =0x030046B8
	mov ip, r1
	ldr r3, [r1]
	adds r3, #1
	ldr r6, _08085B28 @ =0x000003FF
	ands r3, r6
	lsls r0, r3, #1
	add r0, r8
	ldrh r1, [r0]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0xf
	movs r4, #0x1f
	mov sb, r4
	mov r4, sb
	ands r1, r4
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085B2C @ =0xFFFF0000
	mov sl, r1
	ldr r5, [sp]
	ands r5, r1
	orrs r5, r0
	str r5, [sp]
	adds r3, #1
	ands r3, r6
	lsls r0, r3, #1
	add r0, r8
	ldrh r4, [r0]
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0xf
	mov r0, sb
	ands r4, r0
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	mov r4, sl
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #4]
	adds r3, #1
	ands r3, r6
	mov r0, ip
	str r3, [r0]
	lsls r3, r3, #1
	add r3, r8
	ldrh r3, [r3]
	asrs r1, r5, #0x10
	subs r1, #0x10
	movs r0, #0x3f
	ands r3, r0
	subs r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _08085B30 @ =0x0000FFFF
	ands r0, r5
	orrs r0, r1
	str r0, [sp]
	movs r0, #1
	mov r1, sp
	bl FUN_080155e4
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08085B20: .4byte 0x0203B400
_08085B24: .4byte 0x030046B8
_08085B28: .4byte 0x000003FF
_08085B2C: .4byte 0xFFFF0000
_08085B30: .4byte 0x0000FFFF

	thumb_func_start FUN_08085b34
FUN_08085b34: @ 0x08085B34
	push {lr}
	adds r3, r0, #0
	ldr r1, _08085B4C @ =0x0000032A
	adds r0, r3, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _08085B72
	cmp r0, #1
	bgt _08085B50
	cmp r0, #0
	beq _08085B56
	b _08085BCA
	.align 2, 0
_08085B4C: .4byte 0x0000032A
_08085B50:
	cmp r0, #2
	beq _08085BAA
	b _08085BCA
_08085B56:
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r2, r3, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _08085BC8
	lsls r1, r0, #5
	subs r1, r1, r0
	asrs r1, r1, #6
	strh r1, [r3, #0x22]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	b _08085BCA
_08085B72:
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0x3f
	bhi _08085B82
	adds r1, r0, #0
	b _08085B88
_08085B82:
	ldrh r0, [r1]
	movs r1, #0x80
	subs r1, r1, r0
_08085B88:
	lsls r0, r1, #5
	subs r0, r0, r1
	asrs r0, r0, #6
	strh r0, [r3, #0x22]
	movs r0, #0xcb
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _08085BCA
	movs r0, #0
	strh r0, [r1]
	b _08085BCA
_08085BAA:
	movs r1, #0xcb
	lsls r1, r1, #2
	adds r2, r3, r1
	ldrh r0, [r2]
	cmp r0, #0x3f
	bhi _08085BC6
	lsls r1, r0, #5
	subs r1, r1, r0
	asrs r1, r1, #6
	strh r1, [r3, #0x22]
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	b _08085BCA
_08085BC6:
	movs r0, #0x1f
_08085BC8:
	strh r0, [r3, #0x22]
_08085BCA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08085bd0
FUN_08085bd0: @ 0x08085BD0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	ldr r1, _08085CA4 @ =0x03003584
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, _08085CA8 @ =0x00000207
	adds r0, r0, r3
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r0, r1, r0
	str r0, [sp, #4]
	ldr r4, _08085CAC @ =0x000041E0
	adds r4, r1, r4
	str r4, [sp, #8]
	ldr r1, [sp]
	adds r2, #0x18
	adds r0, r1, r2
	ldrh r1, [r0]
	movs r0, #0x40
	subs r0, r0, r1
	mov sb, r0
	mov ip, r1
	movs r3, #0
	mov sl, r3
	movs r4, #0x1f
	mov r8, r4
	movs r7, #0x1f
_08085C14:
	ldr r0, [sp, #4]
	ldrh r1, [r0]
	adds r2, r7, #0
	ands r2, r1
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x15
	mov r3, r8
	ands r6, r3
	lsrs r1, r1, #0x1a
	ands r1, r3
	ldr r0, [sp, #8]
	ldrh r4, [r0]
	adds r0, r7, #0
	ands r0, r4
	lsls r4, r4, #0x10
	lsrs r5, r4, #0x15
	ands r5, r3
	lsrs r4, r4, #0x1a
	ands r4, r3
	mov r3, sb
	muls r3, r2, r3
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	adds r3, r3, r0
	asrs r3, r3, #6
	ands r3, r7
	mov r2, sb
	muls r2, r6, r2
	mov r0, ip
	muls r0, r5, r0
	adds r2, r2, r0
	asrs r2, r2, #6
	ands r2, r7
	mov r0, sb
	muls r0, r1, r0
	adds r1, r0, #0
	mov r0, ip
	muls r0, r4, r0
	adds r1, r1, r0
	asrs r1, r1, #6
	ands r1, r7
	mov r4, sl
	lsls r0, r4, #1
	ldr r4, [sp]
	adds r4, #0x20
	adds r4, r4, r0
	lsls r2, r2, #5
	orrs r3, r2
	lsls r1, r1, #0xa
	orrs r3, r1
	strh r3, [r4]
	ldr r0, [sp, #4]
	adds r0, #2
	str r0, [sp, #4]
	ldr r1, [sp, #8]
	adds r1, #2
	str r1, [sp, #8]
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #0xf
	ble _08085C14
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08085CA4: .4byte 0x03003584
_08085CA8: .4byte 0x00000207
_08085CAC: .4byte 0x000041E0

	thumb_func_start FUN_08085cb0
FUN_08085cb0: @ 0x08085CB0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0xb0
	ldr r2, _08085CE8 @ =0x00000207
	adds r1, r1, r2
	bl Video_SetActorSpritePltt
	adds r0, r4, #0
	adds r0, #0xbc
	adds r5, r4, #0
	adds r5, #0x20
	ldr r2, [r0]
	adds r1, r5, #0
	movs r3, #0xf
_08085CCC:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _08085CCC
	adds r0, r4, #0
	adds r0, #0xbc
	str r5, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085CE8: .4byte 0x00000207

	thumb_func_start FUN_08085cec
FUN_08085cec: @ 0x08085CEC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08085D14 @ =0x0000040A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08085D04
	ldr r2, _08085D18 @ =0x00000406
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08085D1C
_08085D04:
	movs r0, #0xcd
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0x3f
	bhi _08085D2C
	adds r0, #1
	b _08085D2A
	.align 2, 0
_08085D14: .4byte 0x0000040A
_08085D18: .4byte 0x00000406
_08085D1C:
	movs r2, #0xcd
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08085D2C
	subs r0, #1
_08085D2A:
	strh r0, [r1]
_08085D2C:
	movs r0, #0xcc
	lsls r0, r0, #2
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _08085D5C
	ldr r2, _08085D58 @ =0x0000032E
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #9
	beq _08085D4E
	movs r0, #9
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	bl FUN_08085cb0
_08085D4E:
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	b _08085D9E
	.align 2, 0
_08085D58: .4byte 0x0000032E
_08085D5C:
	movs r1, #0xcd
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08085D7C
	ldr r2, _08085D78 @ =0x0000032E
	adds r1, r4, r2
	movs r0, #8
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08085bd0
	b _08085D9E
	.align 2, 0
_08085D78: .4byte 0x0000032E
_08085D7C:
	ldr r0, _08085DA4 @ =0x0000032E
	adds r1, r4, r0
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r2, [r0]
	ldrh r0, [r1]
	cmp r0, r2
	beq _08085D98
	strh r2, [r1]
	ldrh r1, [r1]
	adds r0, r4, #0
	bl FUN_08085cb0
_08085D98:
	adds r0, r4, #0
	bl FUN_08085b34
_08085D9E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085DA4: .4byte 0x0000032E

	thumb_func_start FUN_08085da8
FUN_08085da8: @ 0x08085DA8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xce
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08085DBC
	subs r0, #1
	strh r0, [r4]
_08085DBC:
	ldr r1, _08085DF4 @ =0x0000033A
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08085EB0
	adds r1, #0x4a
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08085EB0
	ldrb r0, [r5, #0x1a]
	cmp r0, #5
	bne _08085DFC
	subs r1, #0x4e
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08085EA2
	ldrh r0, [r4]
	cmp r0, #0
	bne _08085EA2
	ldr r0, _08085DF8 @ =0x0000026A
	bl PlaySound_082406e0
	movs r0, #0x64
	strh r0, [r4]
	b _08085EA2
	.align 2, 0
_08085DF4: .4byte 0x0000033A
_08085DF8: .4byte 0x0000026A
_08085DFC:
	ldr r1, _08085E34 @ =0x00000336
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08085E8E
	adds r0, r5, #0
	adds r0, #0x48
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08085E2E
	cmp r1, #0
	blt _08085E2E
	ldr r0, _08085E38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08085E2E
	ldr r0, _08085E3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08085E40
_08085E2E:
	movs r4, #0
	b _08085E4E
	.align 2, 0
_08085E34: .4byte 0x00000336
_08085E38: .4byte 0x030046A8
_08085E3C: .4byte 0x030046AC
_08085E40:
	ldr r0, _08085E60 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08085E4E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08085E64
	adds r0, #4
	b _08085E70
	.align 2, 0
_08085E60: .4byte 0x030046A4
_08085E64:
	ldr r0, _08085E84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08085E70:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	subs r0, #1
	cmp r0, #1
	bhi _08085E88
	movs r0, #0xd3
	bl PlaySound_082406e0
	b _08085E8E
	.align 2, 0
_08085E84: .4byte 0x030046A4
_08085E88:
	movs r0, #0xd2
	bl PlaySound_082406e0
_08085E8E:
	ldr r1, _08085EAC @ =0x00000336
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08085EA2
	adds r0, r5, #0
	bl FUN_08085764
_08085EA2:
	ldr r0, _08085EAC @ =0x00000336
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	b _08085EB6
	.align 2, 0
_08085EAC: .4byte 0x00000336
_08085EB0:
	ldr r0, _08085EC0 @ =0x00000336
	adds r1, r5, r0
	movs r0, #0
_08085EB6:
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08085EC0: .4byte 0x00000336

	thumb_func_start FUN_08085ec4
FUN_08085ec4: @ 0x08085EC4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08085cec
	adds r0, r4, #0
	bl FUN_08085da8
	adds r0, r4, #0
	bl FUN_08085408
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08085ee0
FUN_08085ee0: @ 0x08085EE0
	adds r3, r0, #0
	ldr r0, _08085EF4 @ =0x000001F5
	adds r2, r3, r0
	movs r0, #0
	strb r1, [r2]
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r1, r3, r2
	strh r0, [r1]
	bx lr
	.align 2, 0
_08085EF4: .4byte 0x000001F5

	thumb_func_start FUN_08085ef8
FUN_08085ef8: @ 0x08085EF8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r2, r1, #0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #4
	bls _08085F16
	adds r1, r0, #0
	movs r0, #8
	subs r3, r0, r1
	movs r6, #1
	b _08085F1A
_08085F16:
	ldrb r3, [r3]
	movs r6, #0
_08085F1A:
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r4, r5, r1
	adds r1, #0x10
	adds r0, r5, r1
	ldr r1, [r0]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r6, [sp]
	adds r0, r4, #0
	bl FUN_08236fac
	adds r5, #0x84
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
	beq _08085F64
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08085F6C
_08085F64:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08085F6C:
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
	beq _08085F90
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08085F98
_08085F90:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08085F98:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08085FD0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08086016
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08085FDA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08085FD4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08085FF0
	.align 2, 0
_08085FD0: .4byte 0x0000FFFF
_08085FD4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08085FEE
_08085FDA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08085FEE
	strh r1, [r4, #8]
	movs r2, #1
	b _08085FF0
_08085FEE:
	movs r2, #0
_08085FF0:
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
	bne _08086018
	movs r0, #1
	strb r0, [r4, #7]
	b _08086018
_08086016:
	movs r2, #0
_08086018:
	adds r0, r2, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086024
FUN_08086024: @ 0x08086024
	push {lr}
	ldrb r2, [r0, #0x1a]
	adds r1, r1, r2
	bl FUN_08085ef8
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086034
FUN_08086034: @ 0x08086034
	push {r4, lr}
	sub sp, #0x10
	adds r1, r0, #0
	movs r0, #0xc9
	lsls r0, r0, #2
	adds r3, r1, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _0808606E
	movs r2, #0
	strh r2, [r3]
	ldr r3, _08086078 @ =0x00000326
	adds r0, r1, r3
	strh r2, [r0]
	ldr r0, _0808607C @ =0x00000414
	adds r4, r1, r0
	ldr r0, [r4]
	adds r1, #0x40
	str r2, [sp]
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
_0808606E:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086078: .4byte 0x00000326
_0808607C: .4byte 0x00000414

	thumb_func_start FUN_08086080
FUN_08086080: @ 0x08086080
	push {lr}
	bl FUN_08086034
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808608c
FUN_0808608c: @ 0x0808608C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x48
	adds r0, r6, #0
	bl FUN_0823629c
	cmp r0, #0xff
	beq _080860BE
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_082362fc
	movs r0, #0xea
	lsls r0, r0, #2
	adds r2, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08235a84
	cmp r0, #0
	bne _080860C2
_080860BE:
	movs r0, #0
	b _080860C4
_080860C2:
	movs r0, #1
_080860C4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080860cc
FUN_080860cc: @ 0x080860CC
	push {lr}
	adds r2, r0, #0
	ldr r1, _08086100 @ =0x000003A6
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	ldr r1, _08086104 @ =0x000003A2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080860F4
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808610C
_080860F4:
	ldr r0, _08086108 @ =0x03002C00
	ldr r0, [r0]
	movs r1, #0
	bl FUN_08085ee0
	b _08086132
	.align 2, 0
_08086100: .4byte 0x000003A6
_08086104: .4byte 0x000003A2
_08086108: .4byte 0x03002C00
_0808610C:
	adds r0, r2, #0
	bl FUN_0808608c
	cmp r0, #0
	beq _08086128
	ldr r0, _08086124 @ =0x03002C00
	ldr r0, [r0]
	movs r1, #3
	bl FUN_08085ee0
	b _08086132
	.align 2, 0
_08086124: .4byte 0x03002C00
_08086128:
	ldr r0, _08086138 @ =0x03002C00
	ldr r0, [r0]
	movs r1, #4
	bl FUN_08085ee0
_08086132:
	pop {r0}
	bx r0
	.align 2, 0
_08086138: .4byte 0x03002C00

	thumb_func_start FUN_0808613c
FUN_0808613c: @ 0x0808613C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xf3
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x48]
	ldr r1, [r5, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _0808619C @ =0x000003CE
	adds r1, r5, r2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0808567c
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x48]
	ldr r1, [r5, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, r2, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08086198
	cmp r1, #0
	blt _08086198
	ldr r0, _080861A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08086198
	ldr r0, _080861A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080861A8
_08086198:
	movs r4, #0
	b _080861B6
	.align 2, 0
_0808619C: .4byte 0x000003CE
_080861A0: .4byte 0x030046A8
_080861A4: .4byte 0x030046AC
_080861A8:
	ldr r0, _080861C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080861B6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080861CC
	adds r0, #4
	b _080861D8
	.align 2, 0
_080861C8: .4byte 0x030046A4
_080861CC:
	ldr r0, _080861EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080861D8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080861F0
	cmp r2, #2
	beq _080861F4
	b _080861F8
	.align 2, 0
_080861EC: .4byte 0x030046A4
_080861F0:
	ldrb r0, [r6, #4]
	b _080861F6
_080861F4:
	ldrb r0, [r6]
_080861F6:
	subs r1, r1, r0
_080861F8:
	ldr r2, _0808622C @ =0x0000035A
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08086218
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_080f8cac
	movs r0, #0
	strb r0, [r4]
_08086218:
	adds r0, r5, #0
	bl FUN_08086080
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08085ee0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808622C: .4byte 0x0000035A

	thumb_func_start FUN_08086230
FUN_08086230: @ 0x08086230
	ldr r1, _08086238 @ =0x03002C00
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08086238: .4byte 0x03002C00

	thumb_func_start coffin_0808623c
coffin_0808623c: @ 0x0808623C
	push {r4, r5, lr}
	ldr r5, _08086264 @ =0x030046A0
	ldr r0, [r5]
	ldr r4, _08086268 @ =0x00000252
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0x38
	movs r1, #0
	bl TryAddItem
	ldr r0, [r5]
	adds r0, r0, r4
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086264: .4byte 0x030046A0
_08086268: .4byte 0x00000252

	thumb_func_start FUN_0808626c
FUN_0808626c: @ 0x0808626C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #4
	ands r1, r0
	cmp r1, #0
	beq _08086286
	ands r3, r0
	cmp r3, #0
	beq _08086282
	cmp r4, r2
	beq _0808628C
_08086282:
	movs r0, #0
	b _0808628E
_08086286:
	ands r3, r0
	cmp r3, #0
	bne _08086282
_0808628C:
	movs r0, #1
_0808628E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08086294
FUN_08086294: @ 0x08086294
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	mov sb, r2
	ldr r0, _08086354 @ =0x03002C00
	ldr r3, [r0]
	adds r2, r0, #0
	cmp r3, #0
	bne _080862B2
	b _0808657E
_080862B2:
	movs r0, #0
	ldrsh r1, [r5, r0]
	adds r0, r3, #0
	adds r0, #0x48
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r6, r1, r0
	movs r7, #4
	ldrsh r1, [r5, r7]
	adds r0, r3, #0
	adds r0, #0x4c
	movs r7, #0
	ldrsh r0, [r0, r7]
	subs r1, r1, r0
	mov r8, r1
	adds r0, r6, #0
	muls r0, r6, r0
	adds r7, r1, #0
	mov r1, r8
	muls r1, r7, r1
	adds r0, r0, r1
	ldr r1, _08086358 @ =0x0000BD10
	cmp r0, r1
	ble _080862E4
	b _0808657E
_080862E4:
	ldr r1, _0808635C @ =0x000001F5
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0xf
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080862F8
	b _08086408
_080862F8:
	adds r0, r1, #0
	cmp r0, #0
	beq _08086308
	cmp r0, #3
	beq _08086308
	cmp r0, #4
	beq _08086308
	b _0808657E
_08086308:
	ldr r0, [r2]
	ldr r2, _08086360 @ =0x00000386
	adds r1, r0, r2
	ldrh r2, [r1]
	movs r7, #0xe1
	lsls r7, r7, #2
	adds r0, r0, r7
	ldrb r3, [r0]
	adds r0, r4, #0
	mov r1, sb
	bl FUN_0808626c
	cmp r0, #0
	bne _08086326
	b _0808657E
_08086326:
	ldrh r2, [r5]
	lsls r0, r2, #0x10
	asrs r4, r0, #0x18
	ldrh r1, [r5, #4]
	lsls r0, r1, #0x10
	asrs r3, r0, #0x18
	mov ip, r2
	mov sb, r1
	cmp r4, #0
	blt _0808634E
	cmp r3, #0
	blt _0808634E
	ldr r0, _08086364 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0808634E
	ldr r0, _08086368 @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _0808636C
_0808634E:
	movs r4, #0
	b _0808637A
	.align 2, 0
_08086354: .4byte 0x03002C00
_08086358: .4byte 0x0000BD10
_0808635C: .4byte 0x000001F5
_08086360: .4byte 0x00000386
_08086364: .4byte 0x030046A8
_08086368: .4byte 0x030046AC
_0808636C:
	ldr r0, _080863A8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r3, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0808637A:
	ldr r2, _080863AC @ =0x03002C00
	ldr r1, [r2]
	adds r1, #0x48
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080863A4
	cmp r1, #0
	blt _080863A4
	ldr r0, _080863B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080863A4
	ldr r0, _080863B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080863B8
_080863A4:
	movs r3, #0
	b _080863C6
	.align 2, 0
_080863A8: .4byte 0x030046A4
_080863AC: .4byte 0x03002C00
_080863B0: .4byte 0x030046A8
_080863B4: .4byte 0x030046AC
_080863B8:
	ldr r0, _0808640C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_080863C6:
	cmp r4, r3
	beq _08086408
	adds r0, r3, #1
	cmp r4, r0
	beq _080863EE
	subs r0, r3, #1
	cmp r4, r0
	beq _080863EE
	ldr r0, _0808640C @ =0x030046A4
	ldr r0, [r0]
	mov sl, r0
	ldr r0, [r0, #4]
	movs r7, #4
	ldrsh r1, [r0, r7]
	adds r0, r3, r1
	cmp r4, r0
	beq _080863EE
	subs r0, r3, r1
	cmp r4, r0
	bne _08086410
_080863EE:
	movs r1, #2
	ldrsh r0, [r5, r1]
	ldr r1, [r2]
	adds r1, #0x4a
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _08086402
	rsbs r0, r0, #0
_08086402:
	cmp r0, #0xff
	ble _08086408
	b _0808657E
_08086408:
	movs r0, #1
	b _08086580
	.align 2, 0
_0808640C: .4byte 0x030046A4
_08086410:
	movs r7, #2
	ldrsh r0, [r5, r7]
	ldr r1, [r2]
	adds r1, #0x4a
	movs r2, #0
	ldrsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _08086424
	rsbs r0, r0, #0
_08086424:
	cmp r0, #0xff
	ble _0808642A
	b _0808657E
_0808642A:
	mov r7, ip
	subs r1, r7, r6
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08086478 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, sb
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08086472
	cmp r1, #0
	blt _08086472
	ldr r0, _0808647C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08086472
	ldr r0, _08086480 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08086484
_08086472:
	movs r4, #0
	b _08086490
	.align 2, 0
_08086478: .4byte 0xFFFF0000
_0808647C: .4byte 0x030046A8
_08086480: .4byte 0x030046AC
_08086484:
	lsls r0, r1, #1
	mov r1, sl
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r4, r0, r2
_08086490:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080864A0
	adds r0, #4
	b _080864AC
_080864A0:
	ldr r0, _080864C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080864AC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080864C4
	cmp r2, #2
	beq _080864C8
	b _080864CC
	.align 2, 0
_080864C0: .4byte 0x030046A4
_080864C4:
	ldrb r0, [r6, #4]
	b _080864CA
_080864C8:
	ldrb r0, [r6]
_080864CA:
	subs r1, r1, r0
_080864CC:
	movs r2, #2
	ldrsh r0, [r5, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _080864D8
	rsbs r0, r0, #0
_080864D8:
	cmp r0, #0x7f
	ble _08086408
	ldrh r1, [r5]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r5, #4]
	mov r6, r8
	subs r1, r1, r6
	strh r1, [r0, #4]
	mov r6, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0808650E
	cmp r1, #0
	blt _0808650E
	ldr r0, _08086514 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808650E
	ldr r0, _08086518 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808651C
_0808650E:
	movs r4, #0
	b _0808652A
	.align 2, 0
_08086514: .4byte 0x030046A8
_08086518: .4byte 0x030046AC
_0808651C:
	ldr r0, _0808653C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808652A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08086540
	adds r0, #4
	b _0808654C
	.align 2, 0
_0808653C: .4byte 0x030046A4
_08086540:
	ldr r0, _08086560 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808654C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08086564
	cmp r2, #2
	beq _08086568
	b _0808656C
	.align 2, 0
_08086560: .4byte 0x030046A4
_08086564:
	ldrb r0, [r6, #4]
	b _0808656A
_08086568:
	ldrb r0, [r6]
_0808656A:
	subs r1, r1, r0
_0808656C:
	movs r7, #2
	ldrsh r0, [r5, r7]
	subs r0, r0, r1
	cmp r0, #0
	bge _08086578
	rsbs r0, r0, #0
_08086578:
	cmp r0, #0x7f
	bgt _0808657E
	b _08086408
_0808657E:
	movs r0, #0
_08086580:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08086590
FUN_08086590: @ 0x08086590
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r0, _080865B8 @ =0x03002C00
	ldr r3, [r0]
	cmp r3, #0
	beq _080865B2
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0]
	str r2, [r0, #4]
	ldr r1, _080865BC @ =0x0000038E
	adds r0, r3, r1
	strh r4, [r0]
_080865B2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080865B8: .4byte 0x03002C00
_080865BC: .4byte 0x0000038E

	thumb_func_start FUN_080865c0
FUN_080865c0: @ 0x080865C0
	push {lr}
	ldr r0, _080865D0 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _080865D4
	adds r0, #0x48
	b _080865D6
	.align 2, 0
_080865D0: .4byte 0x03002C00
_080865D4:
	movs r0, #0
_080865D6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080865dc
FUN_080865dc: @ 0x080865DC
	push {lr}
	adds r2, r0, #0
	ldr r0, _080865F8 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086600
	ldr r1, _080865FC @ =0x0000040C
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #1
	b _08086608
	.align 2, 0
_080865F8: .4byte 0x03002C00
_080865FC: .4byte 0x0000040C
_08086600:
	strh r0, [r2]
	strh r0, [r2, #2]
	strh r0, [r2, #4]
	movs r0, #0
_08086608:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808660c
FUN_0808660c: @ 0x0808660C
	push {lr}
	adds r1, r0, #0
	ldr r0, _08086628 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086622
	ldr r2, _0808662C @ =0x000001F5
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, r1
	beq _08086630
_08086622:
	movs r0, #0
	b _08086632
	.align 2, 0
_08086628: .4byte 0x03002C00
_0808662C: .4byte 0x000001F5
_08086630:
	movs r0, #1
_08086632:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086638
FUN_08086638: @ 0x08086638
	push {r4, r5, r6, lr}
	ldr r0, _080866C8 @ =0x03002C00
	ldr r5, [r0]
	cmp r5, #0
	beq _080866DC
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0808666E
	bl Script_GetValue
	movs r2, #0xea
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080866CC @ =0x000003AA
	adds r1, r5, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
_0808666E:
	movs r0, #0x52
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08086684
	bl Script_GetValue
	movs r2, #0xec
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
_08086684:
	ldr r1, _080866D0 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _080866DC
	adds r6, r5, #0
	adds r6, #0x48
	adds r0, r6, #0
	bl FUN_0823629c
	cmp r0, #0xff
	beq _080866BC
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r4, r5, r2
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_082362fc
	movs r0, #0xea
	lsls r0, r0, #2
	adds r2, r5, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_08235a84
	cmp r0, #0
	bne _080866D4
_080866BC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08085ee0
	b _080866DC
	.align 2, 0
_080866C8: .4byte 0x03002C00
_080866CC: .4byte 0x000003AA
_080866D0: .4byte 0x000001F5
_080866D4:
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08085ee0
_080866DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080866e4
FUN_080866e4: @ 0x080866E4
	push {r4, lr}
	ldr r4, _08086708 @ =0x03002C00
	ldr r0, [r4]
	cmp r0, #0
	beq _08086700
	movs r1, #0
	bl FUN_08085ee0
	ldr r0, [r4]
	movs r1, #0xed
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0]
_08086700:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086708: .4byte 0x03002C00

	thumb_func_start FUN_0808670c
FUN_0808670c: @ 0x0808670C
	push {lr}
	adds r1, r0, #0
	ldr r0, _08086724 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _0808671E
	ldr r2, _08086728 @ =0x0000040A
	adds r0, r0, r2
	strb r1, [r0]
_0808671E:
	pop {r0}
	bx r0
	.align 2, 0
_08086724: .4byte 0x03002C00
_08086728: .4byte 0x0000040A

	thumb_func_start FUN_0808672c
FUN_0808672c: @ 0x0808672C
	push {lr}
	ldr r0, _08086788 @ =0x03002C00
	ldr r1, [r0]
	cmp r1, #0
	beq _08086798
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08086798
	ldr r2, _0808678C @ =0x0000040A
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08086798
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08086798
	ldr r2, _08086790 @ =0x000003B6
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08086798
	ldr r2, _08086794 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _08086782
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08086798
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08086798
_08086782:
	movs r0, #1
	b _0808679A
	.align 2, 0
_08086788: .4byte 0x03002C00
_0808678C: .4byte 0x0000040A
_08086790: .4byte 0x000003B6
_08086794: .4byte 0x000001F5
_08086798:
	movs r0, #0
_0808679A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080867a0
FUN_080867a0: @ 0x080867A0
	push {r4, r5, lr}
	sub sp, #0x10
	ldr r0, _080867D4 @ =0x03002C00
	ldr r5, [r0]
	cmp r5, #0
	beq _0808683E
	ldr r1, _080867D8 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r4, r0, #0
	cmp r4, #1
	bne _080867E0
	adds r0, r5, #0
	bl FUN_08086080
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0
	strh r4, [r0]
	ldr r0, _080867DC @ =0x000003B6
	adds r1, r5, r0
	movs r0, #0x96
	lsls r0, r0, #1
	b _08086814
	.align 2, 0
_080867D4: .4byte 0x03002C00
_080867D8: .4byte 0x000001F5
_080867DC: .4byte 0x000003B6
_080867E0:
	cmp r4, #0
	beq _080867FE
	cmp r4, #2
	beq _080867FE
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0808683E
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0808683E
_080867FE:
	adds r0, r5, #0
	bl FUN_08086080
	adds r0, r5, #0
	bl FUN_080860cc
	ldr r0, _08086848 @ =0x000003B6
	adds r1, r5, r0
	movs r3, #0
	movs r0, #0x96
	lsls r0, r0, #2
_08086814:
	strh r0, [r1]
	movs r1, #0x83
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r3, [r2]
	ldr r0, _0808684C @ =0x00000414
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	str r2, [sp]
	movs r2, #0xc8
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #1
	bl FUN_080da9c4
	str r0, [r4]
_0808683E:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08086848: .4byte 0x000003B6
_0808684C: .4byte 0x00000414

	thumb_func_start FUN_08086850
FUN_08086850: @ 0x08086850
	push {lr}
	ldr r0, _08086868 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086864
	ldr r1, _0808686C @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08086870
_08086864:
	movs r0, #0
	b _08086872
	.align 2, 0
_08086868: .4byte 0x03002C00
_0808686C: .4byte 0x000001F5
_08086870:
	movs r0, #1
_08086872:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086878
FUN_08086878: @ 0x08086878
	push {lr}
	ldr r0, _08086890 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086894
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	b _08086898
	.align 2, 0
_08086890: .4byte 0x03002C00
_08086894:
	movs r0, #1
	rsbs r0, r0, #0
_08086898:
	pop {r1}
	bx r1

	thumb_func_start FUN_0808689c
FUN_0808689c: @ 0x0808689C
	push {lr}
	adds r1, r0, #0
	ldr r0, _080868B4 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _080868B0
	movs r2, #0xe8
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
_080868B0:
	pop {r0}
	bx r0
	.align 2, 0
_080868B4: .4byte 0x03002C00

	thumb_func_start FUN_080868b8
FUN_080868b8: @ 0x080868B8
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r0, _080868D4 @ =0x03002C00
	ldr r4, [r0]
	cmp r4, #0
	beq _0808690A
	cmp r1, #0
	beq _080868D8
	adds r0, r4, #0
	movs r1, #7
	bl FUN_08085ee0
	b _080868E0
	.align 2, 0
_080868D4: .4byte 0x03002C00
_080868D8:
	adds r0, r4, #0
	movs r1, #6
	bl FUN_08085ee0
_080868E0:
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _080868FA
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_080f8cac
	movs r0, #0
	strb r0, [r5]
_080868FA:
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08086080
_0808690A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08086910
FUN_08086910: @ 0x08086910
	push {r4, lr}
	ldr r0, _08086950 @ =0x03002C00
	ldr r4, [r0]
	cmp r4, #0
	beq _0808694A
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08085ee0
	adds r0, r4, #0
	bl FUN_0808567c
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r0, r4, #0
	adds r0, #0xa0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08086954 @ =0x000005DC
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08086080
_0808694A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086950: .4byte 0x03002C00
_08086954: .4byte 0x000005DC

	thumb_func_start FUN_08086958
FUN_08086958: @ 0x08086958
	push {lr}
	ldr r0, _0808696C @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086970
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	b _08086972
	.align 2, 0
_0808696C: .4byte 0x03002C00
_08086970:
	movs r0, #0
_08086972:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086978
FUN_08086978: @ 0x08086978
	push {lr}
	adds r1, r0, #0
	ldr r0, _08086998 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086992
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0808699C
_08086992:
	movs r0, #0
	b _0808699E
	.align 2, 0
_08086998: .4byte 0x03002C00
_0808699C:
	movs r0, #1
_0808699E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080869a4
FUN_080869a4: @ 0x080869A4
	push {lr}
	ldr r0, _080869B8 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _080869C0
	ldr r1, _080869BC @ =0x00000386
	adds r0, r0, r1
	ldrh r0, [r0]
	b _080869C2
	.align 2, 0
_080869B8: .4byte 0x03002C00
_080869BC: .4byte 0x00000386
_080869C0:
	movs r0, #0
_080869C2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080869c8
FUN_080869c8: @ 0x080869C8
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldr r3, _080869F0 @ =0x03002C00
	ldr r1, [r3]
	cmp r1, #0
	beq _080869EA
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrb r0, [r1]
	orrs r2, r0
	strb r2, [r1]
	ldr r0, [r3]
	ldr r1, _080869F4 @ =0x00000386
	adds r0, r0, r1
	strh r4, [r0]
_080869EA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080869F0: .4byte 0x03002C00
_080869F4: .4byte 0x00000386

	thumb_func_start FUN_080869f8
FUN_080869f8: @ 0x080869F8
	push {lr}
	adds r2, r0, #0
	ldr r3, _08086A20 @ =0x03002C00
	ldr r1, [r3]
	cmp r1, #0
	beq _08086A1A
	movs r0, #0xe1
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrb r0, [r1]
	bics r0, r2
	movs r2, #0
	strb r0, [r1]
	ldr r0, [r3]
	ldr r1, _08086A24 @ =0x00000386
	adds r0, r0, r1
	strh r2, [r0]
_08086A1A:
	pop {r0}
	bx r0
	.align 2, 0
_08086A20: .4byte 0x03002C00
_08086A24: .4byte 0x00000386

	thumb_func_start FUN_08086a28
FUN_08086a28: @ 0x08086A28
	push {lr}
	adds r2, r0, #0
	ldr r0, _08086A40 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086A44
	ldr r1, [r0, #0x4c]
	ldr r0, [r0, #0x48]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #1
	b _08086A46
	.align 2, 0
_08086A40: .4byte 0x03002C00
_08086A44:
	movs r0, #0
_08086A46:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086a4c
FUN_08086a4c: @ 0x08086A4C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08086AAC @ =0x03002C00
	ldr r3, [r0]
	cmp r3, #0
	beq _08086AA4
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x48]
	str r1, [r3, #0x4c]
	adds r2, r3, #0
	adds r2, #0xa0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _08086AB0 @ =0x0000031E
	adds r0, r3, r1
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r1, r3, #0
	adds r1, #0xa4
	ldr r2, _08086AB4 @ =0x00000322
	adds r0, r3, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
_08086AA4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086AAC: .4byte 0x03002C00
_08086AB0: .4byte 0x0000031E
_08086AB4: .4byte 0x00000322

	thumb_func_start FUN_08086ab8
FUN_08086ab8: @ 0x08086AB8
	push {lr}
	ldr r0, _08086AE0 @ =0x03002C00
	ldr r1, [r0]
	cmp r1, #0
	beq _08086AE8
	ldrb r0, [r1, #0x1a]
	cmp r0, #4
	bne _08086AE8
	ldr r2, _08086AE4 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08086AE8
	adds r0, r1, #0
	movs r1, #9
	bl FUN_08085ee0
	movs r0, #1
	b _08086AEA
	.align 2, 0
_08086AE0: .4byte 0x03002C00
_08086AE4: .4byte 0x000001F5
_08086AE8:
	movs r0, #0
_08086AEA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086af0
FUN_08086af0: @ 0x08086AF0
	push {lr}
	ldr r0, _08086B0C @ =0x03002C00
	ldr r1, [r0]
	cmp r1, #0
	beq _08086B10
	ldrb r0, [r1, #0x1a]
	cmp r0, #4
	bne _08086B10
	adds r0, r1, #0
	movs r1, #0xa
	bl FUN_08085ee0
	movs r0, #1
	b _08086B12
	.align 2, 0
_08086B0C: .4byte 0x03002C00
_08086B10:
	movs r0, #0
_08086B12:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08086b18
FUN_08086b18: @ 0x08086B18
	push {r4, r5, r6, lr}
	ldr r5, _08086B8C @ =0x03002C00
	ldr r3, [r5]
	cmp r3, #0
	beq _08086BC2
	movs r4, #0xef
	lsls r4, r4, #2
	adds r2, r3, r4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r3, #0
	movs r1, #0xe
	bl FUN_08085ee0
	ldr r3, [r5]
	movs r0, #0x81
	lsls r0, r0, #3
	adds r1, r3, r0
	movs r0, #0xf
	strh r0, [r1]
	ldr r0, _08086B90 @ =0x03002BE0
	ldr r2, [r0]
	movs r6, #0x2c
	ldrsh r1, [r2, r6]
	adds r4, r3, r4
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r4, r1, r0
	movs r0, #0x30
	ldrsh r1, [r2, r0]
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r0, r3, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	subs r1, r1, r0
	cmp r4, #0
	bne _08086B6C
	cmp r1, #0
	beq _08086B98
_08086B6C:
	adds r0, r4, #0
	bl FUN_0823785c
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	ldr r2, [r5]
	adds r0, #7
	movs r1, #7
	ands r0, r1
	ldr r1, _08086B94 @ =0x00000404
	adds r2, r2, r1
	strh r0, [r2]
	b _08086BB6
	.align 2, 0
_08086B8C: .4byte 0x03002C00
_08086B90: .4byte 0x03002BE0
_08086B94: .4byte 0x00000404
_08086B98:
	ldr r2, _08086BC8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08086BCC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08086BD0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	ldr r6, _08086BD4 @ =0x00000404
	adds r1, r3, r6
	strh r0, [r1]
_08086BB6:
	ldr r0, _08086BD8 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _08086BDC @ =0x00000402
	adds r0, r0, r1
	movs r1, #0x1d
	strh r1, [r0]
_08086BC2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08086BC8: .4byte 0x030046B8
_08086BCC: .4byte 0x000003FF
_08086BD0: .4byte 0x0203B400
_08086BD4: .4byte 0x00000404
_08086BD8: .4byte 0x03002C00
_08086BDC: .4byte 0x00000402

	thumb_func_start FUN_08086be0
FUN_08086be0: @ 0x08086BE0
	push {r4, lr}
	sub sp, #8
	ldr r0, _08086C4C @ =0x03002C00
	ldr r4, [r0]
	cmp r4, #0
	beq _08086C44
	mov r0, sp
	bl FUN_0823167c
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	adds r0, r4, #0
	adds r0, #0x4a
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	adds r0, r4, #0
	adds r0, #0x4c
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
_08086C44:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086C4C: .4byte 0x03002C00

	thumb_func_start FUN_08086c50
FUN_08086c50: @ 0x08086C50
	push {r4, r5, r6, lr}
	ldr r0, _08086CB4 @ =0x03002C00
	ldr r5, [r0]
	cmp r5, #0
	bne _08086C5C
	b _08086D56
_08086C5C:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08086D40
	bl Script_GetValue
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r4, r5, r1
	strh r0, [r4]
	bl Script_GetValue
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	adds r6, r4, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08086CB0
	cmp r1, #0
	blt _08086CB0
	ldr r0, _08086CB8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08086CB0
	ldr r0, _08086CBC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08086CC0
_08086CB0:
	movs r4, #0
	b _08086CCE
	.align 2, 0
_08086CB4: .4byte 0x03002C00
_08086CB8: .4byte 0x030046A8
_08086CBC: .4byte 0x030046AC
_08086CC0:
	ldr r0, _08086CE0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08086CCE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08086CE4
	adds r0, #4
	b _08086CF0
	.align 2, 0
_08086CE0: .4byte 0x030046A4
_08086CE4:
	ldr r0, _08086D04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08086CF0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08086D08
	cmp r2, #2
	beq _08086D0C
	b _08086D10
	.align 2, 0
_08086D04: .4byte 0x030046A4
_08086D08:
	ldrb r0, [r6, #4]
	b _08086D0E
_08086D0C:
	ldrb r0, [r6]
_08086D0E:
	subs r1, r1, r0
_08086D10:
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x48]
	str r1, [r5, #0x4c]
	adds r3, r5, #0
	adds r3, #0xa0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r3, r5, r1
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
_08086D40:
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08086D56
	bl Script_GetValue
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
_08086D56:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08086d5c
FUN_08086d5c: @ 0x08086D5C
	push {lr}
	ldr r0, _08086D74 @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	beq _08086D6E
	ldr r2, _08086D78 @ =0x0000040B
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
_08086D6E:
	pop {r0}
	bx r0
	.align 2, 0
_08086D74: .4byte 0x03002C00
_08086D78: .4byte 0x0000040B

	thumb_func_start FUN_08086d7c
FUN_08086d7c: @ 0x08086D7C
	push {r4, lr}
	ldr r0, _08086DAC @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08086DB0 @ =0x00000252
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _08086DA4
	movs r4, #0
_08086D90:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bls _08086DA4
	adds r4, #1
	cmp r4, #0xf
	ble _08086D90
	movs r0, #0
_08086DA4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08086DAC: .4byte 0x030046A0
_08086DB0: .4byte 0x00000252

	thumb_func_start FUN_08086db4
FUN_08086db4: @ 0x08086DB4
	push {r4, r5, lr}
	ldr r0, _08086DC8 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08086DCC @ =0x00000252
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _08086DDA
	b _08086DF2
	.align 2, 0
_08086DC8: .4byte 0x030046A0
_08086DCC: .4byte 0x00000252
_08086DD0:
	adds r0, r5, #0
	bl RemoveValuable
	adds r0, r4, #0
	b _08086DF2
_08086DDA:
	movs r5, #0
_08086DDC:
	adds r0, r5, #0
	bl GetValuableItemID
	adds r4, r0, #0
	subs r4, #0x38
	cmp r4, #7
	bls _08086DD0
	adds r5, #1
	cmp r5, #0xf
	ble _08086DDC
	movs r0, #0
_08086DF2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Entity0B50_Init_Helper_08086df8
Entity0B50_Init_Helper_08086df8: @ 0x08086DF8
	push {r4, lr}
	adds r4, r0, #0
	strh r1, [r4, #0x18]
	bl FUN_08086db4
	ldr r3, _08086E48 @ =0x030046A0
	ldr r1, [r3]
	ldr r2, _08086E4C @ =0x00000252
	adds r1, r1, r2
	strh r0, [r1]
	ldr r0, [r3]
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r4, #0x1a]
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08086E22
	bl Script_GetValue
_08086E22:
	strh r0, [r4, #0x1c]
	ldr r1, _08086E50 @ =0x085ABFE8
	ldrb r0, [r4, #0x1a]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #0x1e]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08086E54
	bl Script_GetValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08085ee0
	b _08086E5C
	.align 2, 0
_08086E48: .4byte 0x030046A0
_08086E4C: .4byte 0x00000252
_08086E50: .4byte 0x085ABFE8
_08086E54:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08085ee0
_08086E5C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity0B50_Init_Helper_08086e64
Entity0B50_Init_Helper_08086e64: @ 0x08086E64
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x72
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08086E9C
	bl Script_GetValue
	movs r2, #0xea
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08086E98 @ =0x000003AA
	adds r1, r4, r3
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _08086EB0
	.align 2, 0
_08086E98: .4byte 0x000003AA
_08086E9C:
	movs r3, #0xea
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldr r2, _08086ECC @ =0x000003AA
	adds r0, r4, r2
	strh r1, [r0]
	adds r3, #4
	adds r0, r4, r3
	strh r1, [r0]
_08086EB0:
	movs r0, #0x4f
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08086ED0
	bl Script_GetValue
	movs r2, #0xec
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	b _08086ED8
	.align 2, 0
_08086ECC: .4byte 0x000003AA
_08086ED0:
	movs r3, #0xec
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
_08086ED8:
	ldr r1, _08086F18 @ =0x085ABFF8
	ldrb r0, [r4, #0x1a]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	ldr r2, _08086F1C @ =0x000003A6
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	ldrb r0, [r4, #0x1a]
	cmp r0, #2
	bne _08086F28
	ldr r0, _08086F20 @ =0x000003A2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _08086F24 @ =0x000001F5
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08086F46
	movs r0, #0
	strb r0, [r1]
	b _08086F46
	.align 2, 0
_08086F18: .4byte 0x085ABFF8
_08086F1C: .4byte 0x000003A6
_08086F20: .4byte 0x000003A2
_08086F24: .4byte 0x000001F5
_08086F28:
	ldr r3, _08086F7C @ =0x000003A2
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08086F80 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08086F46
	adds r0, r4, #0
	bl FUN_080860cc
_08086F46:
	ldr r1, _08086F84 @ =0x085ABFF8
	ldrb r0, [r4, #0x1a]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _08086F88 @ =0x00000392
	adds r1, r4, r2
	movs r2, #0
	strh r0, [r1]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r1, r4, r3
	strh r0, [r1]
	ldr r0, _08086F8C @ =0x0000039A
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08086F7C: .4byte 0x000003A2
_08086F80: .4byte 0x000001F5
_08086F84: .4byte 0x085ABFF8
_08086F88: .4byte 0x00000392
_08086F8C: .4byte 0x0000039A

	thumb_func_start FUN_08086f90
FUN_08086f90: @ 0x08086F90
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0x1a]
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r5, r6, r1
	strh r0, [r5]
	adds r4, r6, #0
	adds r4, #0xb0
	ldr r1, _08087004 @ =0x00002499
	adds r0, r4, #0
	bl Video_GetActorSprite
	adds r0, r6, #0
	adds r0, #0x84
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldrh r1, [r5]
	ldr r2, _08087008 @ =0x0000032E
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r1, [r0]
	ldr r0, _0808700C @ =0x00000207
	adds r1, r1, r0
	adds r0, r4, #0
	bl Video_SetActorSpritePltt
	adds r0, r6, #0
	adds r0, #0xbc
	subs r4, #0x90
	ldr r2, [r0]
	adds r1, r4, #0
	movs r3, #0xf
_08086FD6:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _08086FD6
	adds r0, r6, #0
	adds r0, #0xbc
	str r4, [r0]
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08087010
	bl Script_GetValue
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	b _08087018
	.align 2, 0
_08087004: .4byte 0x00002499
_08087008: .4byte 0x0000032E
_0808700C: .4byte 0x00000207
_08087010:
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r6, r2
	strb r1, [r0]
_08087018:
	ldr r0, _0808704C @ =0x0000922E
	ldr r1, _08087050 @ =0x00003D95
	bl GetFile
	movs r2, #0xf0
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08086024
	ldr r1, _08087054 @ =0x0000031E
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808704C: .4byte 0x0000922E
_08087050: .4byte 0x00003D95
_08087054: .4byte 0x0000031E

	thumb_func_start FUN_08087058
FUN_08087058: @ 0x08087058
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08087090
	bl Script_GetValue
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	b _080870A4
_08087090:
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
_080870A4:
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080870CE
	cmp r1, #0
	blt _080870CE
	ldr r0, _080870D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080870CE
	ldr r0, _080870D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080870DC
_080870CE:
	movs r4, #0
	b _080870EA
	.align 2, 0
_080870D4: .4byte 0x030046A8
_080870D8: .4byte 0x030046AC
_080870DC:
	ldr r0, _080870FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080870EA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08087100
	adds r0, #4
	b _0808710C
	.align 2, 0
_080870FC: .4byte 0x030046A4
_08087100:
	ldr r0, _08087120 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808710C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087124
	cmp r2, #2
	beq _08087128
	b _0808712C
	.align 2, 0
_08087120: .4byte 0x030046A4
_08087124:
	ldrb r0, [r6, #4]
	b _0808712A
_08087128:
	ldrb r0, [r6]
_0808712A:
	subs r1, r1, r0
_0808712C:
	movs r2, #0xfd
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, r5, #0
	adds r3, #0xa0
	movs r0, #0xfc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r3, r5, r1
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r3, r5, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3]
	str r1, [r3, #4]
	adds r4, r5, #0
	adds r4, #0x40
	ldrh r1, [r5, #0x18]
	movs r0, #6
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r1, r5, #0
	adds r1, #0x84
	adds r0, r4, #0
	bl FUN_0823b46c
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r1, r5, #0
	adds r1, #0x45
	strb r0, [r1]
	ldrh r1, [r4]
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldrb r0, [r5, #0x1a]
	cmp r0, #3
	beq _080871D4
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	bne _080871BC
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #1
	bl FUN_080f8c58
	b _080871CA
_080871BC:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r4, #0
	movs r2, #4
	bl FUN_080f8c58
_080871CA:
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080871D4:
	adds r0, r4, #0
	bl FUN_08002a48
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080871e4
FUN_080871e4: @ 0x080871E4
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0xdc
	ldr r2, _08087280 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x5a
	orrs r0, r3
	ldr r4, _08087284 @ =0x0000FFFF
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ands r0, r4
	movs r1, #0xc8
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	ldrb r0, [r5, #0x1a]
	adds r4, r1, #0
	cmp r0, #3
	beq _08087238
	ldrh r0, [r5, #0x1c]
	movs r3, #2
	cmp r0, #0
	bne _0808723A
_08087238:
	movs r3, #0x10
_0808723A:
	ldrh r1, [r5, #0x18]
	ldr r2, _08087288 @ =0x00004081
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _0808728C @ =FUN_08087528
	adds r0, r6, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r1, r5, #0
	adds r1, #0x48
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087280: .4byte 0xFFFF0000
_08087284: .4byte 0x0000FFFF
_08087288: .4byte 0x00004081
_0808728C: .4byte FUN_08087528

	thumb_func_start FUN_08087290
FUN_08087290: @ 0x08087290
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r2, _08087304 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08087308 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
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
	ldrh r1, [r5, #0x18]
	ldr r2, _0808730C @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0x32
	movs r2, #0x32
	movs r3, #0
	bl FUN_082364f8
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08087304: .4byte 0xFFFF0000
_08087308: .4byte 0x0000FFFF
_0808730C: .4byte 0x00002001

	thumb_func_start FUN_08087310
FUN_08087310: @ 0x08087310
	push {r4, lr}
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r4, #0
	movs r3, #2
	strh r3, [r1]
	adds r2, #2
	adds r1, r0, r2
	strh r4, [r1]
	ldr r1, _080873A4 @ =0x000003DA
	adds r2, r0, r1
	movs r1, #0x40
	strh r1, [r2]
	movs r1, #0xf7
	lsls r1, r1, #2
	adds r2, r0, r1
	movs r1, #3
	strh r1, [r2]
	ldr r1, _080873A8 @ =0x000003DE
	adds r2, r0, r1
	movs r1, #6
	strh r1, [r2]
	movs r2, #0xf8
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r3, [r1]
	adds r2, #2
	adds r1, r0, r2
	strh r3, [r1]
	movs r3, #0xf9
	lsls r3, r3, #2
	adds r2, r0, r3
	movs r1, #0x3c
	strh r1, [r2]
	ldr r1, _080873AC @ =0x000003E6
	adds r2, r0, r1
	movs r1, #8
	strh r1, [r2]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r1, r0, r2
	strh r4, [r1]
	adds r3, #6
	adds r1, r0, r3
	movs r2, #0xff
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r4, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r4, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r4, [r1]
	adds r3, #2
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _080873B0 @ =0x000003FA
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080873A4: .4byte 0x000003DA
_080873A8: .4byte 0x000003DE
_080873AC: .4byte 0x000003E6
_080873B0: .4byte 0x000003FA

	thumb_func_start FUN_080873b4
FUN_080873b4: @ 0x080873B4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r2, r0, #0
	ldr r0, _0808741C @ =0x00000326
	adds r3, r2, r0
	ldrh r0, [r3]
	adds r1, r0, r1
	strh r1, [r3]
	movs r0, #0xc9
	lsls r0, r0, #2
	adds r4, r2, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08087428
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	movs r5, #0x96
	lsls r5, r5, #3
	cmp r0, r5
	bls _08087436
	strh r5, [r3]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08087436
	ldr r1, _08087420 @ =0x000001F5
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08087436
	movs r0, #1
	strh r0, [r4]
	ldr r0, _08087424 @ =0x00000414
	adds r4, r2, r0
	ldr r0, [r4]
	adds r1, r2, #0
	adds r1, #0x40
	str r3, [sp]
	str r5, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	b _08087436
	.align 2, 0
_0808741C: .4byte 0x00000326
_08087420: .4byte 0x000001F5
_08087424: .4byte 0x00000414
_08087428:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x96
	lsls r1, r1, #3
	cmp r0, r1
	bls _08087436
	strh r1, [r3]
_08087436:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08087440
FUN_08087440: @ 0x08087440
	push {r4, lr}
	sub sp, #0x10
	adds r1, r0, #0
	ldr r0, _0808748C @ =0x00000326
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _08087484
	subs r0, #1
	movs r3, #0
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08087484
	movs r4, #0xc9
	lsls r4, r4, #2
	adds r0, r1, r4
	strh r3, [r0]
	strh r3, [r2]
	ldr r0, _08087490 @ =0x00000414
	adds r4, r1, r0
	ldr r0, [r4]
	adds r1, #0x40
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
_08087484:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808748C: .4byte 0x00000326
_08087490: .4byte 0x00000414

	thumb_func_start FUN_08087494
FUN_08087494: @ 0x08087494
	push {r4, lr}
	ldr r1, _080874B4 @ =0x000003B6
	adds r2, r0, r1
	ldrh r1, [r2]
	adds r3, r1, #0
	cmp r3, #0
	beq _080874C4
	ldr r4, _080874B8 @ =0x000001F5
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _080874C0
	cmp r3, #2
	bls _080874BC
	subs r0, r1, #2
	b _080874C2
	.align 2, 0
_080874B4: .4byte 0x000003B6
_080874B8: .4byte 0x000001F5
_080874BC:
	movs r0, #0
	b _080874C2
_080874C0:
	subs r0, r1, #1
_080874C2:
	strh r0, [r2]
_080874C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080874cc
FUN_080874cc: @ 0x080874CC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08087508 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0808751C
	adds r0, r4, #0
	bl FUN_08087440
	adds r0, r4, #0
	bl FUN_08087494
	ldr r0, _0808750C @ =0x00000332
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _08087510
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	b _0808751C
	.align 2, 0
_08087508: .4byte 0x030047A4
_0808750C: .4byte 0x00000332
_08087510:
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	ldr r0, _08087524 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0808751C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08087524: .4byte 0x0000FFFB

	thumb_func_start FUN_08087528
FUN_08087528: @ 0x08087528
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r3, #6]
	ands r0, r1
	cmp r0, #0
	bne _080875DC
	adds r5, r2, #0
	ldrb r0, [r5, #0x1b]
	cmp r0, #1
	beq _080875DC
	movs r2, #0
	ldrh r0, [r5, #0x1c]
	cmp r0, #0
	bne _0808755E
	ldrh r1, [r3, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08087564
	ldr r0, [r3, #0x34]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08087560
	b _08087564
_0808755E:
	movs r2, #1
_08087560:
	cmp r2, #0
	beq _080875DC
_08087564:
	ldr r1, _08087584 @ =0x00000332
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080875DC
	ldrh r0, [r3, #0x3c]
	cmp r0, #0
	beq _080875DC
	movs r0, #1
	ldr r1, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _08087588
	movs r1, #0xc8
	b _080875C4
	.align 2, 0
_08087584: .4byte 0x00000332
_08087588:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08087598
	movs r1, #0x96
	lsls r1, r1, #1
	movs r4, #0xc
	b _080875C6
_08087598:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080875A6
	movs r1, #0xfa
	lsls r1, r1, #1
	b _080875C4
_080875A6:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080875B2
	movs r1, #0x96
	b _080875C4
_080875B2:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080875C0
	movs r1, #0xfa
	lsls r1, r1, #1
	b _080875C4
_080875C0:
	movs r1, #0xc8
	lsls r1, r1, #1
_080875C4:
	movs r4, #8
_080875C6:
	adds r0, r5, #0
	bl FUN_080873b4
	movs r1, #0xcc
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #4
	strh r1, [r0]
	ldr r1, _080875E4 @ =0x00000332
	adds r0, r5, r1
	strh r4, [r0]
_080875DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080875E4: .4byte 0x00000332

	thumb_func_start FUN_080875e8
FUN_080875e8: @ 0x080875E8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08087624 @ =0x0000040C
	adds r2, r4, r0
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _08087628 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _0808762C
	asrs r3, r0, #0xc
	b _08087632
	.align 2, 0
_08087624: .4byte 0x0000040C
_08087628: .4byte 0x085B0A08
_0808762C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08087632:
	ldr r0, _08087650 @ =0x0000040C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	cmp r0, #0
	blt _08087654
	asrs r2, r0, #0xc
	b _0808765A
	.align 2, 0
_08087650: .4byte 0x0000040C
_08087654:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0808765A:
	movs r0, #0x82
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0808766c
FUN_0808766c: @ 0x0808766C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08087716
	ldr r2, _080876B4 @ =0x000001F5
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _08087716
	adds r6, r5, #0
	adds r6, #0x48
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080876AE
	cmp r1, #0
	blt _080876AE
	ldr r0, _080876B8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080876AE
	ldr r0, _080876BC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080876C0
_080876AE:
	movs r4, #0
	b _080876CE
	.align 2, 0
_080876B4: .4byte 0x000001F5
_080876B8: .4byte 0x030046A8
_080876BC: .4byte 0x030046AC
_080876C0:
	ldr r0, _080876E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080876CE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080876E4
	adds r0, #4
	b _080876F0
	.align 2, 0
_080876E0: .4byte 0x030046A4
_080876E4:
	ldr r0, _08087704 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080876F0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087708
	cmp r2, #2
	beq _0808770C
	b _08087710
	.align 2, 0
_08087704: .4byte 0x030046A4
_08087708:
	ldrb r0, [r6, #4]
	b _0808770E
_0808770C:
	ldrb r0, [r6]
_0808770E:
	subs r1, r1, r0
_08087710:
	adds r0, r5, #0
	adds r0, #0x4a
	strh r1, [r0]
_08087716:
	adds r4, r5, #0
	adds r4, #0x48
	ldr r1, _08087784 @ =0x0000031E
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0xa0
	strh r0, [r1]
	subs r1, #0x56
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xa2
	strh r0, [r1]
	subs r1, #0x56
	adds r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0xa4
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xdc
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08087780
	cmp r1, #0
	blt _08087780
	ldr r0, _08087788 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087780
	ldr r0, _0808778C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087790
_08087780:
	movs r0, #0
	b _0808779E
	.align 2, 0
_08087784: .4byte 0x0000031E
_08087788: .4byte 0x030046A8
_0808778C: .4byte 0x030046AC
_08087790:
	ldr r0, _080877B8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0808779E:
	adds r2, r5, #0
	adds r2, #0xd2
	strh r0, [r2]
	ldrh r4, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080877BC
	adds r2, r0, #4
	b _080877C8
	.align 2, 0
_080877B8: .4byte 0x030046A4
_080877BC:
	ldr r0, _08087810 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r2, r1, r0
_080877C8:
	ldrb r0, [r2]
	lsrs r0, r0, #4
	adds r1, r5, #0
	adds r1, #0xd7
	strb r0, [r1]
	ldrb r1, [r2]
	movs r0, #0xf
	ands r0, r1
	adds r1, r5, #0
	adds r1, #0xd5
	strb r0, [r1]
	ldrh r0, [r2, #2]
	adds r2, r5, #0
	adds r2, #0xda
	strh r0, [r2]
	adds r0, r5, #0
	bl FUN_080875e8
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x48]
	ldr r1, [r5, #0x4c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _08087814 @ =0x0000038E
	adds r0, r5, r2
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087810: .4byte 0x030046A4
_08087814: .4byte 0x0000038E

	thumb_func_start FUN_08087818
FUN_08087818: @ 0x08087818
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xff
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _0808782E
	adds r0, #1
	strh r0, [r1]
	b _08087968
_0808782E:
	ldr r1, _08087878 @ =0x000001F5
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _0808783A
	b _08087968
_0808783A:
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08087848
	b _08087968
_08087848:
	adds r0, r6, #0
	adds r0, #0x48
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r5, r0, #0
	cmp r2, #0
	blt _08087872
	cmp r1, #0
	blt _08087872
	ldr r0, _0808787C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087872
	ldr r0, _08087880 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087884
_08087872:
	movs r4, #0
	b _08087892
	.align 2, 0
_08087878: .4byte 0x000001F5
_0808787C: .4byte 0x030046A8
_08087880: .4byte 0x030046AC
_08087884:
	ldr r0, _080878A4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087892:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080878A8
	adds r0, #4
	b _080878B4
	.align 2, 0
_080878A4: .4byte 0x030046A4
_080878A8:
	ldr r0, _080878F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080878B4:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _08087964
	ldr r1, _080878F4 @ =0x000001F5
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08087968
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080878EC
	cmp r1, #0
	blt _080878EC
	ldr r0, _080878F8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080878EC
	ldr r0, _080878FC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087900
_080878EC:
	movs r4, #0
	b _0808790E
	.align 2, 0
_080878F0: .4byte 0x030046A4
_080878F4: .4byte 0x000001F5
_080878F8: .4byte 0x030046A8
_080878FC: .4byte 0x030046AC
_08087900:
	ldr r0, _08087920 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808790E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08087924
	adds r0, #4
	b _08087930
	.align 2, 0
_08087920: .4byte 0x030046A4
_08087924:
	ldr r0, _08087944 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087930:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087948
	cmp r2, #2
	beq _0808794C
	b _08087950
	.align 2, 0
_08087944: .4byte 0x030046A4
_08087948:
	ldrb r0, [r5, #4]
	b _0808794E
_0808794C:
	ldrb r0, [r5]
_0808794E:
	subs r1, r1, r0
_08087950:
	adds r0, r6, #0
	adds r0, #0x4a
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08087960
	rsbs r0, r0, #0
_08087960:
	cmp r0, #0xff
	ble _08087968
_08087964:
	movs r0, #1
	b _0808796A
_08087968:
	movs r0, #0
_0808796A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08087970
FUN_08087970: @ 0x08087970
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08087818
	cmp r0, #0
	beq _08087982
	adds r0, r4, #0
	bl FUN_0808613c
_08087982:
	ldr r1, _08087998 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	bhi _08087A4C
	lsls r0, r0, #2
	ldr r1, _0808799C @ =_080879A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08087998: .4byte 0x000001F5
_0808799C: .4byte _080879A0
_080879A0: @ jump table
	.4byte _080879E4 @ case 0
	.4byte _080879FC @ case 1
	.4byte _08087A4C @ case 2
	.4byte _080879E4 @ case 3
	.4byte _080879E4 @ case 4
	.4byte _08087A4C @ case 5
	.4byte _08087A4C @ case 6
	.4byte _08087A4C @ case 7
	.4byte _08087A4C @ case 8
	.4byte _08087A4C @ case 9
	.4byte _08087A4C @ case 10
	.4byte _08087A4C @ case 11
	.4byte _08087A4C @ case 12
	.4byte _08087A4C @ case 13
	.4byte _08087A4C @ case 14
	.4byte _08087A18 @ case 15
	.4byte _08087A30 @ case 16
_080879E4:
	ldr r0, _080879F8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08087A0C
	b _08087A4C
	.align 2, 0
_080879F8: .4byte 0x03002BE0
_080879FC:
	ldr r0, _08087A10 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _08087A14
_08087A0C:
	movs r0, #1
	b _08087A52
	.align 2, 0
_08087A10: .4byte 0x03002BE0
_08087A14:
	movs r0, #0
	b _08087A52
_08087A18:
	ldr r0, _08087A2C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08087A40
	b _08087A4C
	.align 2, 0
_08087A2C: .4byte 0x03002BE0
_08087A30:
	ldr r0, _08087A44 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _08087A48
_08087A40:
	movs r0, #0x10
	b _08087A52
	.align 2, 0
_08087A44: .4byte 0x03002BE0
_08087A48:
	movs r0, #0xf
	b _08087A52
_08087A4C:
	ldr r1, _08087A58 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
_08087A52:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08087A58: .4byte 0x000001F5

	thumb_func_start FUN_08087a5c
FUN_08087a5c: @ 0x08087A5C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	ldr r0, _08087A84 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08087A76
	b _08087B96
_08087A76:
	ldr r0, _08087A88 @ =0x00000396
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, #0x3f
	bhi _08087A8C
	movs r7, #0x10
	b _08087A9C
	.align 2, 0
_08087A84: .4byte 0x030047A4
_08087A88: .4byte 0x00000396
_08087A8C:
	ldr r0, _08087B4C @ =0x0000032A
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	ldrh r0, [r2]
	lsrs r0, r0, #2
	adds r7, r0, #0
	adds r7, #0x10
_08087A9C:
	ldr r1, _08087B50 @ =0x0203B400
	mov sb, r1
	ldr r5, _08087B54 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r2, _08087B58 @ =0x000003FF
	mov r8, r2
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r1, r7, #0
	bl Mod
	asrs r4, r7, #1
	subs r0, r0, r4
	ldr r2, _08087B5C @ =0x0000031E
	adds r1, r6, r2
	strh r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	adds r1, r7, #0
	bl Mod
	subs r0, r0, r4
	ldr r2, _08087B60 @ =0x00000322
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xe7
	lsls r0, r0, #2
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08087B64 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08087B1C
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r2, _08087B50 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08087B1C
	ldr r0, _08087B68 @ =0x000002B9
	bl PlaySound_082406e0
_08087B1C:
	ldr r0, _08087B6C @ =0x00000396
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x7f
	bls _08087B96
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08087B70 @ =0x000001F5
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _08087B78
	ldr r0, _08087B74 @ =0x0000039E
	adds r1, r6, r0
	movs r0, #2
	b _08087B7E
	.align 2, 0
_08087B4C: .4byte 0x0000032A
_08087B50: .4byte 0x0203B400
_08087B54: .4byte 0x030046B8
_08087B58: .4byte 0x000003FF
_08087B5C: .4byte 0x0000031E
_08087B60: .4byte 0x00000322
_08087B64: .4byte 0x0000FFFF
_08087B68: .4byte 0x000002B9
_08087B6C: .4byte 0x00000396
_08087B70: .4byte 0x000001F5
_08087B74: .4byte 0x0000039E
_08087B78:
	ldr r2, _08087BA4 @ =0x0000039E
	adds r1, r6, r2
	movs r0, #1
_08087B7E:
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #2
	bl FUN_08085ee0
	ldr r1, _08087BA8 @ =0x0000039A
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r6, r2
	strh r1, [r0]
_08087B96:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08087BA4: .4byte 0x0000039E
_08087BA8: .4byte 0x0000039A

	thumb_func_start FUN_08087bac
FUN_08087bac: @ 0x08087BAC
	push {lr}
	adds r2, r0, #0
	ldr r0, _08087BF0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08087BFE
	ldr r1, _08087BF4 @ =0x000003A2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08087BFE
	adds r1, #0x12
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08087BFE
	subs r1, #0x30
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08087BFE
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08087BF8
	subs r0, #1
	strh r0, [r1]
	b _08087BFE
	.align 2, 0
_08087BF0: .4byte 0x030047A4
_08087BF4: .4byte 0x000003A2
_08087BF8:
	adds r0, r2, #0
	bl FUN_080860cc
_08087BFE:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08087c04
FUN_08087c04: @ 0x08087C04
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08087C58 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08087C1A
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08085ee0
_08087C1A:
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	ldr r0, _08087C5C @ =0x0000FFFB
	ands r0, r1
	movs r1, #0
	strh r0, [r2]
	ldr r2, _08087C60 @ =0x0000032A
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_08086024
	ldr r0, _08087C64 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08087CB6
	movs r5, #0xe5
	lsls r5, r5, #2
	adds r3, r4, r5
	ldrh r0, [r3]
	cmp r0, #0
	beq _08087C68
	adds r0, r4, #0
	bl FUN_08087a5c
	b _08087CB6
	.align 2, 0
_08087C58: .4byte 0x000001F5
_08087C5C: .4byte 0x0000FFFB
_08087C60: .4byte 0x0000032A
_08087C64: .4byte 0x030047A4
_08087C68:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	beq _08087C7C
	adds r0, r4, #0
	bl FUN_080856f4
	b _08087CB6
_08087C7C:
	ldr r5, _08087CA4 @ =0x0000040A
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08087CB0
	ldr r1, _08087CA8 @ =0x00000392
	adds r0, r4, r1
	ldrh r1, [r0]
	subs r5, #0x7a
	adds r0, r4, r5
	strh r1, [r0]
	ldr r1, _08087CAC @ =0x000003A6
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r5, #0x14
	adds r0, r4, r5
	strh r1, [r0]
	strh r2, [r3]
	b _08087CB6
	.align 2, 0
_08087CA4: .4byte 0x0000040A
_08087CA8: .4byte 0x00000392
_08087CAC: .4byte 0x000003A6
_08087CB0:
	adds r0, r4, #0
	bl FUN_08087bac
_08087CB6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08087cbc
FUN_08087cbc: @ 0x08087CBC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _08087CF0 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08087CEC
	cmp r1, #0
	blt _08087CEC
	ldr r0, _08087CF4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087CEC
	ldr r0, _08087CF8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087CFC
_08087CEC:
	movs r4, #0
	b _08087D0A
	.align 2, 0
_08087CF0: .4byte 0x03002BE0
_08087CF4: .4byte 0x030046A8
_08087CF8: .4byte 0x030046AC
_08087CFC:
	ldr r0, _08087D1C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087D0A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08087D20
	adds r0, #4
	b _08087D2C
	.align 2, 0
_08087D1C: .4byte 0x030046A4
_08087D20:
	ldr r0, _08087D6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087D2C:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	adds r6, r7, #0
	adds r6, #0x48
	cmp r0, #0
	beq _08087D3C
	b _08087E64
_08087D3C:
	ldr r0, _08087D70 @ =0x03002BE0
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #0x2c
	ldrh r0, [r0, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08087D68
	cmp r1, #0
	blt _08087D68
	ldr r0, _08087D74 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087D68
	ldr r0, _08087D78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087D7C
_08087D68:
	movs r4, #0
	b _08087D8A
	.align 2, 0
_08087D6C: .4byte 0x030046A4
_08087D70: .4byte 0x03002BE0
_08087D74: .4byte 0x030046A8
_08087D78: .4byte 0x030046AC
_08087D7C:
	ldr r0, _08087D9C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087D8A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08087DA0
	adds r0, #4
	b _08087DAC
	.align 2, 0
_08087D9C: .4byte 0x030046A4
_08087DA0:
	ldr r0, _08087DC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087DAC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087DC4
	cmp r2, #2
	beq _08087DC8
	b _08087DCC
	.align 2, 0
_08087DC0: .4byte 0x030046A4
_08087DC4:
	ldrb r0, [r5, #4]
	b _08087DCA
_08087DC8:
	ldrb r0, [r5]
_08087DCA:
	subs r1, r1, r0
_08087DCC:
	mov r8, r1
	adds r5, r7, #0
	adds r5, #0x48
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r5, #0
	cmp r2, #0
	blt _08087DF8
	cmp r1, #0
	blt _08087DF8
	ldr r0, _08087DFC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08087DF8
	ldr r0, _08087E00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087E04
_08087DF8:
	movs r4, #0
	b _08087E12
	.align 2, 0
_08087DFC: .4byte 0x030046A8
_08087E00: .4byte 0x030046AC
_08087E04:
	ldr r0, _08087E24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08087E12:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08087E28
	adds r0, #4
	b _08087E34
	.align 2, 0
_08087E24: .4byte 0x030046A4
_08087E28:
	ldr r0, _08087E48 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08087E34:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08087E4C
	cmp r2, #2
	beq _08087E50
	b _08087E54
	.align 2, 0
_08087E48: .4byte 0x030046A4
_08087E4C:
	ldrb r0, [r5, #4]
	b _08087E52
_08087E50:
	ldrb r0, [r5]
_08087E52:
	subs r1, r1, r0
_08087E54:
	mov r2, r8
	subs r0, r2, r1
	cmp r0, #0
	bge _08087E5E
	rsbs r0, r0, #0
_08087E5E:
	cmp r0, #0xff
	bgt _08087E64
	b _08087F72
_08087E64:
	ldr r2, _08087E90 @ =0x03002BE0
	ldr r1, [r2]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08087E8C
	cmp r1, #0
	blt _08087E8C
	ldr r0, _08087E94 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08087E8C
	ldr r0, _08087E98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087E9C
_08087E8C:
	movs r4, #0
	b _08087EAA
	.align 2, 0
_08087E90: .4byte 0x03002BE0
_08087E94: .4byte 0x030046A8
_08087E98: .4byte 0x030046AC
_08087E9C:
	ldr r0, _08087ED4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_08087EAA:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08087ECE
	cmp r1, #0
	blt _08087ECE
	ldr r0, _08087ED8 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08087ECE
	ldr r0, _08087EDC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08087EE0
_08087ECE:
	movs r3, #0
	b _08087EEE
	.align 2, 0
_08087ED4: .4byte 0x030046A4
_08087ED8: .4byte 0x030046A8
_08087EDC: .4byte 0x030046AC
_08087EE0:
	ldr r0, _08087F04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_08087EEE:
	adds r0, r4, #1
	cmp r3, r0
	bne _08087F08
	ldr r1, [r2]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, #2
	strh r0, [r1, #0x2c]
	b _08087F72
	.align 2, 0
_08087F04: .4byte 0x030046A4
_08087F08:
	subs r0, r4, #1
	cmp r3, r0
	bne _08087F20
	ldr r1, [r2]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #2
	strh r0, [r1, #0x2c]
	b _08087F72
_08087F20:
	ldr r0, _08087F44 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r5, #4
	ldrsh r1, [r0, r5]
	adds r0, r4, r1
	cmp r3, r0
	bne _08087F48
	ldr r1, [r2]
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	lsls r0, r0, #8
	adds r0, #2
	b _08087F70
	.align 2, 0
_08087F44: .4byte 0x030046A4
_08087F48:
	subs r0, r4, r1
	cmp r3, r0
	bne _08087F62
	ldr r1, [r2]
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	adds r0, #1
	lsls r0, r0, #8
	subs r0, #2
	b _08087F70
_08087F62:
	ldr r1, [r2]
	ldrh r0, [r6]
	strh r0, [r1, #0x2c]
	ldr r1, [r2]
	adds r0, r7, #0
	adds r0, #0x4c
	ldrh r0, [r0]
_08087F70:
	strh r0, [r1, #0x30]
_08087F72:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08087f7c
FUN_08087f7c: @ 0x08087F7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r3, _08087FBC @ =0x03002BE0
	ldr r0, [r3]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _08087FC0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x46
	muls r0, r1, r0
	adds r5, r3, #0
	cmp r0, #0
	blt _08087FC4
	asrs r0, r0, #0xc
	b _08087FCA
	.align 2, 0
_08087FBC: .4byte 0x03002BE0
_08087FC0: .4byte 0x085B0A08
_08087FC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08087FCA:
	mov sl, r0
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x46
	muls r0, r1, r0
	cmp r0, #0
	blt _08087FE4
	asrs r0, r0, #0xc
	b _08087FEA
_08087FE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08087FEA:
	adds r7, r0, #0
	ldr r2, [r5]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	add r0, sl
	adds r3, r6, #0
	adds r3, #0x48
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r5, r0, r1
	movs r1, #0x30
	ldrsh r0, [r2, r1]
	adds r0, r0, r7
	adds r2, r6, #0
	adds r2, #0x4c
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r4, r0, r1
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r1, r1, r0
	ldr r0, _08088048 @ =0x000057E4
	mov r8, r3
	mov sb, r2
	cmp r1, r0
	ble _080880EE
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	adds r4, r0, #0
	ldr r2, _0808804C @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08088050
	asrs r0, r0, #0xc
	b _08088056
	.align 2, 0
_08088048: .4byte 0x000057E4
_0808804C: .4byte 0x085B0A08
_08088050:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08088056:
	adds r5, r0, #0
	ldr r1, _08088074 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08088078
	asrs r1, r0, #0xc
	b _0808807E
	.align 2, 0
_08088074: .4byte 0x085B0A08
_08088078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808807E:
	mov r3, r8
	movs r4, #0
	ldrsh r2, [r3, r4]
	mov r0, sl
	subs r2, r2, r0
	adds r2, r2, r5
	mov r3, sb
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r0, r0, r7
	adds r4, r0, r1
	ldr r3, _080880AC @ =0x03002BE0
	ldr r0, [r3]
	movs r5, #0x2c
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	adds r5, r3, #0
	cmp r0, #0
	blt _080880B0
	asrs r1, r0, #2
	b _080880B6
	.align 2, 0
_080880AC: .4byte 0x03002BE0
_080880B0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080880B6:
	ldr r0, [r5]
	strh r1, [r0, #0x2c]
	ldr r0, [r5]
	movs r2, #0x30
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r4
	cmp r0, #0
	blt _080880CE
	asrs r1, r0, #2
	b _080880D4
_080880CE:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080880D4:
	ldr r0, [r5]
	strh r1, [r0, #0x30]
	adds r0, r6, #0
	bl FUN_08087cbc
	ldr r0, [r5]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_080880EE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080880fc
FUN_080880fc: @ 0x080880FC
	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08088138
	movs r4, #0xe4
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrh r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	beq _08088120
	subs r0, #1
	strh r0, [r1]
	b _08088138
_08088120:
	ldr r4, _08088140 @ =0x00000392
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08088144 @ =0x00000396
	adds r0, r2, r1
	strh r3, [r0]
_08088138:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08088140: .4byte 0x00000392
_08088144: .4byte 0x00000396

	thumb_func_start FUN_08088148
FUN_08088148: @ 0x08088148
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080881CC @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0808815E
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08085ee0
_0808815E:
	movs r2, #0xed
	lsls r2, r2, #2
	adds r3, r4, r2
	ldrh r0, [r3]
	cmp r0, #0
	beq _080881AE
	ldr r5, _080881D0 @ =0x000003A2
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _080881AE
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r5, #6
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r1, r2, r0
	cmp r1, #0
	bge _0808818C
	rsbs r1, r1, #0
_0808818C:
	movs r5, #0xeb
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	subs r0, r2, r0
	cmp r0, #0
	bge _0808819E
	rsbs r0, r0, #0
_0808819E:
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r1, r2
	bgt _080881AA
	cmp r0, r2
	ble _080881AE
_080881AA:
	movs r0, #0
	strh r0, [r3]
_080881AE:
	ldr r0, _080881D4 @ =0x0000032A
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _080881D8
	adds r0, r4, #0
	bl FUN_08087f7c
	b _08088230
	.align 2, 0
_080881CC: .4byte 0x000001F5
_080881D0: .4byte 0x000003A2
_080881D4: .4byte 0x0000032A
_080881D8:
	adds r2, r4, #0
	adds r2, #0x48
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r5, #0xe2
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080881F2
	rsbs r1, r1, #0
_080881F2:
	adds r3, r4, #0
	adds r3, #0x4c
	cmp r1, #2
	bgt _08088214
	movs r5, #0
	ldrsh r0, [r3, r5]
	movs r5, #0xe3
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _08088210
	rsbs r0, r0, #0
_08088210:
	cmp r0, #2
	ble _0808821C
_08088214:
	ldr r0, _08088258 @ =0x0000033A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0808821C:
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r2]
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r3]
_08088230:
	ldr r3, _0808825C @ =0x0000038E
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	ldrb r0, [r4, #0x1a]
	cmp r0, #5
	bne _08088260
	ldr r1, _08088258 @ =0x0000033A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08088260
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _08088268
	.align 2, 0
_08088258: .4byte 0x0000033A
_0808825C: .4byte 0x0000038E
_08088260:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
_08088268:
	ldr r0, _0808828C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080882DE
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r3, r4, r2
	ldrh r0, [r3]
	cmp r0, #0
	beq _08088290
	adds r0, r4, #0
	bl FUN_08087a5c
	b _080882DE
	.align 2, 0
_0808828C: .4byte 0x030047A4
_08088290:
	movs r5, #0xc9
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrh r2, [r0]
	cmp r2, #0
	beq _080882A4
	adds r0, r4, #0
	bl FUN_080856f4
	b _080882DE
_080882A4:
	ldr r1, _080882CC @ =0x0000040A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080882D8
	ldr r5, _080882D0 @ =0x00000392
	adds r0, r4, r5
	ldrh r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	ldr r1, _080882D4 @ =0x000003A6
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r5, #0x14
	adds r0, r4, r5
	strh r1, [r0]
	strh r2, [r3]
	b _080882DE
	.align 2, 0
_080882CC: .4byte 0x0000040A
_080882D0: .4byte 0x00000392
_080882D4: .4byte 0x000003A6
_080882D8:
	adds r0, r4, #0
	bl FUN_080880fc
_080882DE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080882e4
FUN_080882e4: @ 0x080882E4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08088310
	cmp r1, #0
	blt _08088310
	ldr r0, _08088314 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08088310
	ldr r0, _08088318 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808831C
_08088310:
	movs r4, #0
	b _0808832A
	.align 2, 0
_08088314: .4byte 0x030046A8
_08088318: .4byte 0x030046AC
_0808831C:
	ldr r0, _0808833C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808832A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08088340
	adds r0, #4
	b _0808834C
	.align 2, 0
_0808833C: .4byte 0x030046A4
_08088340:
	ldr r0, _08088374 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808834C:
	ldrh r1, [r0, #2]
	ands r5, r1
	cmp r5, #0
	bne _08088426
	movs r0, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08088386
	movs r1, #0x10
	ldr r0, _08088378 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0808837C @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08088380
	movs r0, #1
	b _08088382
	.align 2, 0
_08088374: .4byte 0x030046A4
_08088378: .4byte 0x030046A0
_0808837C: .4byte 0x00000934
_08088380:
	movs r0, #0
_08088382:
	cmp r0, #0
	bne _08088426
_08088386:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080883AA
	cmp r1, #0
	blt _080883AA
	ldr r0, _080883B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080883AA
	ldr r0, _080883B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080883B8
_080883AA:
	movs r4, #0
	b _080883C6
	.align 2, 0
_080883B0: .4byte 0x030046A8
_080883B4: .4byte 0x030046AC
_080883B8:
	ldr r0, _080883D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080883C6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080883DC
	adds r0, #4
	b _080883E8
	.align 2, 0
_080883D8: .4byte 0x030046A4
_080883DC:
	ldr r0, _080883FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080883E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08088400
	cmp r2, #2
	beq _08088404
	b _08088408
	.align 2, 0
_080883FC: .4byte 0x030046A4
_08088400:
	ldrb r0, [r6, #4]
	b _08088406
_08088404:
	ldrb r0, [r6]
_08088406:
	subs r1, r1, r0
_08088408:
	movs r2, #2
	ldrsh r0, [r7, r2]
	subs r0, r0, r1
	cmp r0, #0
	bge _08088414
	rsbs r0, r0, #0
_08088414:
	cmp r0, #0x32
	bgt _08088426
	adds r0, r6, #0
	bl FUN_081d2230
	cmp r0, #0
	bne _08088426
	movs r0, #1
	b _08088428
_08088426:
	movs r0, #0
_08088428:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08088430
FUN_08088430: @ 0x08088430
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldrh r2, [r5]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _0808846C
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r1, [r0, #4]
	ldrh r5, [r5, #4]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08088468 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	mov r1, sp
	b _080884DA
	.align 2, 0
_08088468: .4byte 0xFFFF0000
_0808846C:
	movs r1, #4
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _0808848C
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r1, r2, r0
	mov r0, sp
	strh r1, [r0]
	adds r0, r4, #0
	mov r1, sp
	b _080884DA
_0808848C:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r1, r2, r0
	mov r0, sp
	strh r1, [r0]
	mov r6, sp
	adds r0, r4, #0
	mov r1, sp
	adds r2, r7, #0
	bl FUN_080882e4
	cmp r0, #0
	beq _080884E4
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp]
	str r1, [sp, #4]
	ldrh r0, [r5, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	adds r0, r4, #0
	mov r1, sp
	adds r2, r7, #0
	bl FUN_080882e4
	cmp r0, #0
	beq _080884E4
	mov r1, sp
	ldrh r0, [r5]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r0, r4, #0
_080884DA:
	adds r2, r7, #0
	bl FUN_080882e4
	cmp r0, #0
	bne _080884E8
_080884E4:
	movs r0, #0
	b _080884EA
_080884E8:
	movs r0, #1
_080884EA:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080884f4
FUN_080884f4: @ 0x080884F4
	push {lr}
	cmp r0, #0
	bge _080884FC
	rsbs r0, r0, #0
_080884FC:
	cmp r0, #0x20
	bgt _0808850E
	cmp r1, #0
	bge _08088506
	rsbs r1, r1, #0
_08088506:
	cmp r1, #0x20
	bgt _0808850E
	movs r0, #1
	b _08088510
_0808850E:
	movs r0, #0
_08088510:
	pop {r1}
	bx r1

	thumb_func_start FUN_08088514
FUN_08088514: @ 0x08088514
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r1, _08088568 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _08088534
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08085ee0
_08088534:
	ldr r0, _0808856C @ =0x030047A4
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _08088544
	b _08088708
_08088544:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08088574
	ldr r3, _08088570 @ =0x0000032A
	adds r0, r4, r3
	strh r1, [r0]
	adds r2, #0x94
	adds r0, r4, r2
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_080856f4
	adds r7, r4, #0
	adds r7, #0x48
	b _080886FC
	.align 2, 0
_08088568: .4byte 0x000001F5
_0808856C: .4byte 0x030047A4
_08088570: .4byte 0x0000032A
_08088574:
	ldr r3, _080885E8 @ =0x0000032A
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r7, r4, #0
	adds r7, #0x48
	cmp r0, #0x5a
	bhi _0808858E
	b _080886BE
_0808858E:
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r2, #0
	ldrsh r0, [r7, r2]
	subs r1, r1, r0
	mov sb, r1
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r4, #0
	adds r1, #0x4c
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r2, r2, r0
	mov r8, r2
	mov sl, r1
	mov r0, sb
	cmp r0, #0
	bne _080885C2
	cmp r2, #0
	beq _08088690
_080885C2:
	mov r0, sb
	mov r1, r8
	bl FUN_0823785c
	adds r5, r0, #0
	ldr r2, _080885EC @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _080885F0
	asrs r0, r0, #0xc
	b _080885F6
	.align 2, 0
_080885E8: .4byte 0x0000032A
_080885EC: .4byte 0x085B0A08
_080885F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080885F6:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	ldr r1, _08088618 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _0808861C
	asrs r0, r0, #0xc
	b _08088622
	.align 2, 0
_08088618: .4byte 0x085B0A08
_0808861C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08088622:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08088664 @ =0xFFFF0000
	mov r6, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldr r2, _08088668 @ =0x00000841
	adds r0, r7, #0
	mov r1, sp
	bl FUN_08088430
	adds r1, r0, #0
	cmp r1, #0
	beq _08088670
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r7]
	adds r0, r0, r1
	strh r0, [r7]
	ldrh r0, [r6, #4]
	mov r2, sl
	ldrh r2, [r2]
	adds r0, r0, r2
	mov r3, sl
	strh r0, [r3]
	ldr r0, _0808866C @ =0x0000033A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08088676
	.align 2, 0
_08088664: .4byte 0xFFFF0000
_08088668: .4byte 0x00000841
_0808866C: .4byte 0x0000033A
_08088670:
	ldr r2, _080886F0 @ =0x0000033A
	adds r0, r4, r2
	strb r1, [r0]
_08088676:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r1, [r0]
_08088690:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080886BE
	mov r0, sb
	mov r1, r8
	bl FUN_080884f4
	cmp r0, #0
	beq _080886BE
	movs r2, #0xec
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080886BE
	movs r1, #0
	bl Script_ExecById
_080886BE:
	movs r3, #0xee
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _080886D6
	movs r0, #0
	strh r0, [r1]
_080886D6:
	ldrb r0, [r4, #0x1a]
	cmp r0, #5
	bne _080886F4
	ldr r1, _080886F0 @ =0x0000033A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080886F4
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _080886FC
	.align 2, 0
_080886F0: .4byte 0x0000033A
_080886F4:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
_080886FC:
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r1, r7, #0
	bl FUN_08236268
_08088708:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08088718
FUN_08088718: @ 0x08088718
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _08088760 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _08088730
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08085ee0
_08088730:
	ldr r0, _08088764 @ =0x030047A4
	ldr r1, [r0]
	movs r6, #0x80
	lsls r6, r6, #2
	ands r1, r6
	cmp r1, #0
	beq _08088740
	b _08088902
_08088740:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r7, [r0]
	cmp r7, #0
	beq _0808876C
	ldr r4, _08088768 @ =0x0000032A
	adds r0, r5, r4
	strh r1, [r0]
	adds r2, #0x94
	adds r0, r5, r2
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_080856f4
	b _08088902
	.align 2, 0
_08088760: .4byte 0x000001F5
_08088764: .4byte 0x030047A4
_08088768: .4byte 0x0000032A
_0808876C:
	ldr r4, _080887B8 @ =0x0000032A
	adds r0, r5, r4
	movs r1, #1
	strh r1, [r0]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x5a
	bne _08088800
	ldr r2, _080887BC @ =0x000003BA
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080887C8
	ldr r2, _080887C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	adds r1, #0x47
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080887C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r2, r5, r6
	ldrb r1, [r2]
	adds r1, r1, r0
	adds r1, #2
	movs r0, #7
	ands r1, r0
	strb r1, [r2]
	strh r7, [r4]
	b _080888BA
	.align 2, 0
_080887B8: .4byte 0x0000032A
_080887BC: .4byte 0x000003BA
_080887C0: .4byte 0x030046B8
_080887C4: .4byte 0x0203B400
_080887C8:
	ldr r2, _080887F4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080887F8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080887FC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r2, r5, r6
	ldrb r1, [r2]
	adds r1, r1, r0
	adds r1, #7
	movs r0, #7
	ands r1, r0
	strb r1, [r2]
	b _080888BA
	.align 2, 0
_080887F4: .4byte 0x030046B8
_080887F8: .4byte 0x000003FF
_080887FC: .4byte 0x0203B400
_08088800:
	cmp r0, #0x5a
	bls _080888BA
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08088830 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _08088834
	asrs r0, r0, #0xc
	b _0808883A
	.align 2, 0
_08088830: .4byte 0x085B0A08
_08088834:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808883A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _08088854
	asrs r0, r0, #0xc
	b _0808885A
_08088854:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808885A:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0808889C @ =0xFFFF0000
	mov r6, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r4, r5, #0
	adds r4, #0x48
	ldr r2, _080888A0 @ =0x00000843
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08088430
	cmp r0, #0
	beq _080888A8
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	adds r1, r5, #0
	adds r1, #0x4c
	ldrh r0, [r6, #4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r4, _080888A4 @ =0x0000033A
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	b _080888BA
	.align 2, 0
_0808889C: .4byte 0xFFFF0000
_080888A0: .4byte 0x00000843
_080888A4: .4byte 0x0000033A
_080888A8:
	movs r0, #0xee
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r2, _080888D4 @ =0x000003BA
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
_080888BA:
	ldrb r0, [r5, #0x1a]
	cmp r0, #5
	bne _080888DC
	ldr r4, _080888D8 @ =0x0000033A
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080888DC
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _080888E4
	.align 2, 0
_080888D4: .4byte 0x000003BA
_080888D8: .4byte 0x0000033A
_080888DC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08086024
_080888E4:
	movs r0, #0xee
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _08088902
	adds r0, r5, #0
	bl FUN_080860cc
	movs r0, #0
	strh r0, [r4]
_08088902:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808890c
FUN_0808890c: @ 0x0808890C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _08088990 @ =0x000001F5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0808892A
	adds r0, r7, #0
	movs r1, #2
	bl FUN_08085ee0
_0808892A:
	ldr r0, _08088994 @ =0x030047A4
	ldr r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r5, r0
	cmp r5, #0
	beq _0808893A
	b _08088BAE
_0808893A:
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x40
	bhi _0808894C
	b _08088ABC
_0808894C:
	ldr r1, _08088998 @ =0x0000032A
	adds r0, r7, r1
	movs r1, #2
	strh r1, [r0]
	adds r2, #8
	adds r1, r7, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _08088964
	bl FUN_080dab9c
_08088964:
	ldr r0, _0808899C @ =0x0000039E
	adds r3, r7, r0
	ldrh r0, [r3]
	cmp r0, #2
	bne _080889A0
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r7, r1
	subs r1, #0x48
	strh r1, [r0]
	movs r5, #0xa5
	lsls r5, r5, #1
	adds r2, r7, r5
	movs r0, #0x20
	strh r0, [r2]
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #1
	strh r0, [r3]
	b _080889C2
	.align 2, 0
_08088990: .4byte 0x000001F5
_08088994: .4byte 0x030047A4
_08088998: .4byte 0x0000032A
_0808899C: .4byte 0x0000039E
_080889A0:
	cmp r0, #1
	bne _080889C2
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0x80
	strh r1, [r0]
	movs r0, #0xa5
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r0, #0x20
	strh r0, [r2]
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	strh r5, [r3]
_080889C2:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r4, r7, r5
	adds r1, r7, #0
	adds r1, #0x48
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08088A1E
	ldr r2, _08088A88 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08088A8C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08088A90 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r5, #0xd4
	adds r2, r7, r5
	ldrb r1, [r2]
	adds r1, r1, r0
	subs r1, #1
	movs r0, #7
	ands r1, r0
	strb r1, [r2]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08086024
_08088A1E:
	ldr r6, _08088A90 @ =0x0203B400
	ldr r0, _08088A88 @ =0x030046B8
	mov ip, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r3, _08088A8C @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #0x3f
	ands r0, r4
	subs r0, #0x1f
	ldr r5, _08088A94 @ =0x0000031E
	adds r2, r7, r5
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x1f
	ldr r2, _08088A98 @ =0x00000322
	adds r1, r7, r2
	strh r0, [r1]
	mov r5, r8
	ldrh r1, [r5]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08088A68
	adds r0, r7, #0
	bl FUN_08085880
_08088A68:
	ldr r1, _08088A9C @ =0x00000326
	adds r0, r7, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08088B5A
	lsrs r2, r0, #0x13
	mov r5, r8
	ldrh r1, [r5]
	adds r0, r2, #0
	adds r0, #0x40
	cmp r1, r0
	bge _08088AA0
	movs r0, #0x40
	strh r0, [r5]
	b _08088AA6
	.align 2, 0
_08088A88: .4byte 0x030046B8
_08088A8C: .4byte 0x000003FF
_08088A90: .4byte 0x0203B400
_08088A94: .4byte 0x0000031E
_08088A98: .4byte 0x00000322
_08088A9C: .4byte 0x00000326
_08088AA0:
	subs r0, r1, r2
	mov r1, r8
	strh r0, [r1]
_08088AA6:
	ldr r2, _08088AB8 @ =0x00000326
	adds r0, r7, r2
	movs r1, #0
	strh r1, [r0]
	movs r5, #0xc9
	lsls r5, r5, #2
	adds r0, r7, r5
	strh r1, [r0]
	b _08088B5A
	.align 2, 0
_08088AB8: .4byte 0x00000326
_08088ABC:
	lsrs r6, r1, #0x11
	cmp r6, #1
	bgt _08088AC4
	movs r6, #2
_08088AC4:
	ldr r0, _08088B84 @ =0x0203B400
	mov sl, r0
	ldr r1, _08088B88 @ =0x030046B8
	mov r8, r1
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08088B8C @ =0x000003FF
	mov sb, r2
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r6, #0
	bl Mod
	asrs r4, r6, #1
	subs r0, r0, r4
	ldr r2, _08088B90 @ =0x0000031E
	adds r1, r7, r2
	strh r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r6, #0
	bl Mod
	subs r0, r0, r4
	ldr r2, _08088B94 @ =0x00000322
	adds r1, r7, r2
	strh r0, [r1]
	ldr r1, _08088B98 @ =0x0000032A
	adds r0, r7, r1
	strh r5, [r0]
	adds r2, #4
	adds r0, r7, r2
	strh r5, [r0]
	subs r1, #6
	adds r0, r7, r1
	strh r5, [r0]
	adds r2, #0x76
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r5, _08088B9C @ =0x0000FFFF
	adds r1, r5, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08088B5A
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r5, _08088B84 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08088B5A
	ldr r0, _08088BA0 @ =0x000002B9
	bl PlaySound_082406e0
_08088B5A:
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08088BAE
	ldrb r0, [r7, #0x1b]
	cmp r0, #1
	bne _08088BA8
	adds r0, r7, #0
	movs r1, #0xf
	bl FUN_08085ee0
	ldr r2, _08088BA4 @ =0x00000402
	adds r1, r7, r2
	movs r0, #0x1e
	strh r0, [r1]
	b _08088BAE
	.align 2, 0
_08088B84: .4byte 0x0203B400
_08088B88: .4byte 0x030046B8
_08088B8C: .4byte 0x000003FF
_08088B90: .4byte 0x0000031E
_08088B94: .4byte 0x00000322
_08088B98: .4byte 0x0000032A
_08088B9C: .4byte 0x0000FFFF
_08088BA0: .4byte 0x000002B9
_08088BA4: .4byte 0x00000402
_08088BA8:
	adds r0, r7, #0
	bl FUN_080860cc
_08088BAE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08088bbc
FUN_08088bbc: @ 0x08088BBC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r4, r5, r2
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08086024
	ldrh r0, [r4]
	cmp r0, #0x1b
	bls _08088C4C
	cmp r0, #0x2b
	bhi _08088C28
	adds r4, r0, #0
	adds r3, r4, #0
	subs r3, #0x1c
	adds r2, r5, #0
	adds r2, #0x84
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	lsls r1, r3, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x8c
	strb r0, [r1]
	cmp r3, #8
	ble _08088C4C
	lsls r0, r3, #3
	adds r2, #9
	strb r0, [r2]
	adds r1, r4, #0
	subs r1, #0x24
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	b _08088C36
_08088C28:
	cmp r0, #0x33
	bhi _08088C40
	ldrh r0, [r4]
	subs r0, #0x2c
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xf0
_08088C36:
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	b _08088C4C
_08088C40:
	adds r0, r5, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_08088C4C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08088c54
FUN_08088c54: @ 0x08088C54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r6, #0
	strb r6, [r0]
	adds r1, r4, #0
	adds r1, #0xe2
	ldrh r0, [r1]
	movs r5, #4
	orrs r0, r5
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0x4b
	bhi _08088C90
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _08088D14
_08088C90:
	cmp r0, #0x53
	bhi _08088CCA
	ldrh r3, [r1]
	adds r2, r4, #0
	adds r2, #0x84
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	adds r0, #0x8c
	strb r5, [r0]
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #0x78
	strb r0, [r1]
	movs r0, #0x54
	subs r0, r0, r3
	movs r1, #0xc8
	muls r0, r1, r0
	adds r0, #0xf0
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r1, r4, r2
	strh r0, [r1]
	b _08088D14
_08088CCA:
	cmp r0, #0x63
	bhi _08088D14
	ldrh r0, [r1]
	adds r3, r0, #0
	subs r3, #0x54
	movs r0, #0xf
	subs r2, r0, r3
	lsls r1, r2, #2
	movs r0, #0x40
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x8c
	strb r0, [r1]
	cmp r3, #7
	bgt _08088D04
	lsls r0, r2, #3
	adds r2, r4, #0
	adds r2, #0x8d
	strb r0, [r2]
	movs r0, #8
	subs r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #1
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _08088D14
_08088D04:
	adds r1, r4, #0
	adds r1, #0x8d
	movs r0, #0x40
	strb r0, [r1]
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r6, [r0]
_08088D14:
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x67
	bls _08088D3E
	adds r0, r4, #0
	adds r0, #0x84
	ldr r1, [r0]
	movs r2, #3
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08085ee0
_08088D3E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08088d44
FUN_08088d44: @ 0x08088D44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _08088DBC @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _08088D5E
	adds r0, r4, #0
	movs r1, #5
	bl FUN_08085ee0
_08088D5E:
	ldr r0, _08088DC0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _08088D6E
	b _08088FAE
_08088D6E:
	ldr r2, _08088DC4 @ =0x0000032A
	adds r1, r4, r2
	movs r2, #0
	movs r0, #2
	strh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r0, r4, r3
	strb r2, [r0]
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	movs r5, #0
	mov r8, r5
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x3f
	bhi _08088DCC
	adds r2, r4, #0
	adds r2, #0x4a
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	ldr r3, _08088DC8 @ =0x000003CE
	adds r1, r4, r3
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r2]
	b _08088E56
	.align 2, 0
_08088DBC: .4byte 0x000001F5
_08088DC0: .4byte 0x030047A4
_08088DC4: .4byte 0x0000032A
_08088DC8: .4byte 0x000003CE
_08088DCC:
	cmp r1, #0x7f
	bhi _08088E1C
	ldr r2, _08088E0C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08088E10 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08088E14 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #1
	ands r1, r0
	lsls r0, r1, #4
	adds r0, r0, r1
	subs r0, #8
	ldr r2, _08088E18 @ =0x0000031E
	adds r1, r4, r2
	strh r0, [r1]
	rsbs r0, r0, #0
	adds r2, #4
	adds r1, r4, r2
	strh r0, [r1]
	movs r5, #1
	ldrh r1, [r3]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08088E52
	mov r8, r5
	b _08088E52
	.align 2, 0
_08088E0C: .4byte 0x030046B8
_08088E10: .4byte 0x000003FF
_08088E14: .4byte 0x0203B400
_08088E18: .4byte 0x0000031E
_08088E1C:
	cmp r1, #0xbf
	bhi _08088E3A
	lsrs r0, r0, #0x11
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _08088E2C
	movs r5, #1
_08088E2C:
	movs r0, #0xf
	ands r0, r2
	cmp r0, #0
	bne _08088E52
	movs r3, #1
	mov r8, r3
	b _08088E52
_08088E3A:
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08088E46
	movs r5, #1
_08088E46:
	movs r0, #0xf
	ands r0, r2
	cmp r0, #0
	bne _08088E52
	movs r0, #1
	mov r8, r0
_08088E52:
	cmp r5, #0
	beq _08088F04
_08088E56:
	adds r3, r4, #0
	adds r3, #0x84
	ldr r0, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r3]
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r7, r4, r1
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	cmp r2, #0
	blt _08088E9C
	cmp r1, #0
	blt _08088E9C
	ldr r0, _08088EA0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08088E9C
	ldr r0, _08088EA4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08088EA8
_08088E9C:
	movs r5, #0
	b _08088EB6
	.align 2, 0
_08088EA0: .4byte 0x030046A8
_08088EA4: .4byte 0x030046AC
_08088EA8:
	ldr r0, _08088EC8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08088EB6:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08088ECC
	adds r0, #4
	b _08088ED8
	.align 2, 0
_08088EC8: .4byte 0x030046A4
_08088ECC:
	ldr r0, _08088EEC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08088ED8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08088EF0
	cmp r2, #2
	beq _08088EF4
	b _08088EF8
	.align 2, 0
_08088EEC: .4byte 0x030046A4
_08088EF0:
	ldrb r0, [r7, #4]
	b _08088EF6
_08088EF4:
	ldrb r0, [r7]
_08088EF6:
	subs r1, r1, r0
_08088EF8:
	ldr r2, _08088F00 @ =0x0000035A
	adds r0, r4, r2
	strh r1, [r0]
	b _08088F1E
	.align 2, 0
_08088F00: .4byte 0x0000035A
_08088F04:
	adds r2, r4, #0
	adds r2, #0x84
	ldr r0, [r2]
	movs r3, #1
	orrs r0, r3
	str r0, [r2]
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r6, r2, #0
_08088F1E:
	mov r1, r8
	cmp r1, #0
	beq _08088F32
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0xf5
	lsls r2, r2, #2
	adds r1, r4, r2
	bl FUN_08085a74
_08088F32:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	movs r3, #0xfb
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	bls _08088FAE
	adds r0, r4, #0
	bl FUN_080856cc
	ldr r0, _08088F8C @ =0x03002C00
	ldr r0, [r0]
	movs r1, #0
	bl FUN_08085ee0
	movs r0, #0xec
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r2, [r1]
	cmp r2, #0
	beq _08088FA0
	movs r0, #0
	str r0, [r1]
	adds r0, r2, #0
	movs r1, #0
	bl Script_ExecById
	ldr r1, _08088F90 @ =0x0000040B
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08088F94
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	b _08088FAE
	.align 2, 0
_08088F8C: .4byte 0x03002C00
_08088F90: .4byte 0x0000040B
_08088F94:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	b _08088FAE
_08088FA0:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	ldr r2, _08088FB8 @ =0x0000040B
	adds r0, r4, r2
	strb r1, [r0]
_08088FAE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08088FB8: .4byte 0x0000040B

	thumb_func_start FUN_08088fbc
FUN_08088fbc: @ 0x08088FBC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _08089030 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08088FD4
	adds r0, r5, #0
	movs r1, #6
	bl FUN_08085ee0
_08088FD4:
	ldr r0, _08089034 @ =0x030047A4
	ldr r3, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r3, r0
	cmp r3, #0
	bne _08089076
	ldr r1, _08089038 @ =0x0000032A
	adds r0, r5, r1
	strh r3, [r0]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	adds r1, r0, #1
	strh r1, [r6]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _08089040
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08089076
	movs r1, #0x83
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r3, [r2]
	ldr r0, _0808903C @ =0x00000414
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	str r2, [sp]
	movs r2, #0xc8
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	b _08089076
	.align 2, 0
_08089030: .4byte 0x000001F5
_08089034: .4byte 0x030047A4
_08089038: .4byte 0x0000032A
_0808903C: .4byte 0x00000414
_08089040:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _0808905C
	ldr r1, _08089080 @ =0x00000414
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	ldrh r2, [r1]
	movs r1, #1
	bl FUN_080d99d4
	str r0, [r4]
_0808905C:
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r1, #0x1e
	strh r1, [r0]
	ldrh r0, [r6]
	cmp r0, #8
	bls _08089076
	ldr r0, _08089084 @ =0x0000040B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08089076:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08089080: .4byte 0x00000414
_08089084: .4byte 0x0000040B

	thumb_func_start FUN_08089088
FUN_08089088: @ 0x08089088
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r1, _080890F0 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _080890A0
	adds r0, r5, #0
	movs r1, #7
	bl FUN_08085ee0
_080890A0:
	ldr r1, _080890F4 @ =0x0000032A
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrh r0, [r6]
	adds r1, r0, #1
	strh r1, [r6]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _080890FC
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08089132
	movs r1, #0x83
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r3, [r2]
	ldr r0, _080890F8 @ =0x00000414
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	str r2, [sp]
	movs r2, #0xc8
	str r2, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	bl FUN_080da9c4
	str r0, [r4]
	b _08089132
	.align 2, 0
_080890F0: .4byte 0x000001F5
_080890F4: .4byte 0x0000032A
_080890F8: .4byte 0x00000414
_080890FC:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bne _08089118
	ldr r1, _0808913C @ =0x00000414
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x40
	ldrh r2, [r1]
	movs r1, #1
	bl FUN_080d99d4
	str r0, [r4]
_08089118:
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	subs r1, #0x3c
	strh r1, [r0]
	ldrh r0, [r6]
	cmp r0, #0x1d
	bls _08089132
	ldr r0, _08089140 @ =0x0000040B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_08089132:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808913C: .4byte 0x00000414
_08089140: .4byte 0x0000040B

	thumb_func_start FUN_08089144
FUN_08089144: @ 0x08089144
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r1, _0808919C @ =0x000001F5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08089160
	adds r0, r7, #0
	movs r1, #8
	bl FUN_08085ee0
_08089160:
	ldr r2, _080891A0 @ =0x0000032A
	adds r0, r7, r2
	movs r6, #0
	strh r6, [r0]
	movs r0, #0xfb
	lsls r0, r0, #1
	adds r5, r7, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080891AE
	ldr r1, _080891A4 @ =0x0000031E
	adds r0, r7, r1
	strh r6, [r0]
	subs r2, #8
	adds r0, r7, r2
	strh r6, [r0]
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0x1e
	bhi _080891A8
	adds r0, r7, #0
	bl FUN_080856cc
	strh r6, [r4]
	movs r0, #1
	strh r0, [r5]
	b _0808927A
	.align 2, 0
_0808919C: .4byte 0x000001F5
_080891A0: .4byte 0x0000032A
_080891A4: .4byte 0x0000031E
_080891A8:
	subs r0, #0x1e
	strh r0, [r4]
	b _0808927A
_080891AE:
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080891DE
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _080891CE
	lsls r1, r1, #4
	movs r2, #0xc8
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	b _080891E6
_080891CE:
	movs r0, #7
	subs r0, r0, r1
	lsls r0, r0, #4
	movs r6, #0xc8
	lsls r6, r6, #2
	adds r1, r7, r6
	strh r0, [r1]
	b _080891E6
_080891DE:
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r6, [r0]
_080891E6:
	movs r2, #0xfb
	lsls r2, r2, #1
	adds r2, r2, r7
	mov r8, r2
	ldrh r0, [r2]
	cmp r0, #0xb
	bhi _0808922A
	ldr r6, _08089288 @ =0x0203B400
	mov ip, r6
	ldr r5, _0808928C @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _08089290 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, ip
	ldrh r0, [r0]
	movs r4, #0x1f
	ands r0, r4
	subs r0, #0x10
	ldr r6, _08089294 @ =0x0000031E
	adds r2, r7, r6
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x10
	ldr r2, _08089298 @ =0x00000322
	adds r1, r7, r2
	strh r0, [r1]
_0808922A:
	mov r6, r8
	ldrh r0, [r6]
	cmp r0, #2
	bne _08089238
	adds r0, r7, #0
	bl FUN_0808596c
_08089238:
	mov r1, r8
	ldrh r0, [r1]
	cmp r0, #0x1d
	bls _0808927A
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08085ee0
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #1
	strh r0, [r1]
	ldr r6, _0808929C @ =0x00000326
	adds r2, r7, r6
	ldr r3, _080892A0 @ =0x0000011F
	strh r3, [r2]
	ldr r0, _080892A4 @ =0x00000414
	adds r4, r7, r0
	ldr r0, [r4]
	adds r1, r7, #0
	adds r1, #0x40
	str r2, [sp]
	str r3, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	adds r2, #0x28
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
_0808927A:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08089288: .4byte 0x0203B400
_0808928C: .4byte 0x030046B8
_08089290: .4byte 0x000003FF
_08089294: .4byte 0x0000031E
_08089298: .4byte 0x00000322
_0808929C: .4byte 0x00000326
_080892A0: .4byte 0x0000011F
_080892A4: .4byte 0x00000414

	thumb_func_start FUN_080892a8
FUN_080892a8: @ 0x080892A8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080892F0 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _080892BE
	adds r0, r4, #0
	movs r1, #0xb
	bl FUN_08085ee0
_080892BE:
	ldr r3, _080892F4 @ =0x0000032A
	adds r0, r4, r3
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	adds r3, #0x6a
	adds r0, r4, r3
	strh r1, [r0]
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r0, [r3]
	movs r1, #4
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080892F0: .4byte 0x000001F5
_080892F4: .4byte 0x0000032A

	thumb_func_start FUN_080892f8
FUN_080892f8: @ 0x080892F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08089340 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _0808930E
	adds r0, r4, #0
	movs r1, #0xd
	bl FUN_08085ee0
_0808930E:
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r1, [r3]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08086024
	cmp r0, #0
	beq _08089338
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_08085ee0
_08089338:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08089340: .4byte 0x000001F5

	thumb_func_start FUN_08089344
FUN_08089344: @ 0x08089344
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08089368 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xc
	beq _0808935A
	adds r0, r4, #0
	movs r1, #0xc
	bl FUN_08085ee0
_0808935A:
	ldrb r0, [r4, #0x1a]
	cmp r0, #6
	bne _08089370
	ldr r0, _0808936C @ =0x0000032A
	adds r1, r4, r0
	movs r0, #1
	b _08089396
	.align 2, 0
_08089368: .4byte 0x000001F5
_0808936C: .4byte 0x0000032A
_08089370:
	cmp r0, #7
	bne _08089390
	ldr r0, _08089388 @ =0x00000406
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _0808938C @ =0x0000032A
	adds r0, r4, r1
	strh r2, [r0]
	b _08089398
	.align 2, 0
_08089388: .4byte 0x00000406
_0808938C: .4byte 0x0000032A
_08089390:
	ldr r0, _080893BC @ =0x0000032A
	adds r1, r4, r0
	movs r0, #0
_08089396:
	strh r0, [r1]
_08089398:
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r1, [r3]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0x18
	bl FUN_08086024
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080893BC: .4byte 0x0000032A

	thumb_func_start FUN_080893c0
FUN_080893c0: @ 0x080893C0
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808940C @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xe
	beq _080893D6
	adds r0, r4, #0
	movs r1, #0xe
	bl FUN_08085ee0
_080893D6:
	adds r3, r4, #0
	adds r3, #0xe2
	ldrh r1, [r3]
	movs r0, #4
	movs r2, #0
	orrs r0, r1
	strh r0, [r3]
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_08086024
	cmp r0, #0
	beq _08089406
	movs r1, #0x81
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_08085ee0
_08089406:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808940C: .4byte 0x000001F5

	thumb_func_start FUN_08089410
FUN_08089410: @ 0x08089410
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808947C @ =0x00000402
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x1e
	bne _08089488
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _0808944E
	cmp r1, #0
	beq _08089470
_0808944E:
	adds r0, r2, #0
	bl FUN_0823785c
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _08089480 @ =0x00000404
	adds r1, r4, r2
	strh r0, [r1]
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r4, r3
	strb r0, [r1]
_08089470:
	ldr r0, _08089484 @ =0x0000033A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08089502
	.align 2, 0
_0808947C: .4byte 0x00000402
_08089480: .4byte 0x00000404
_08089484: .4byte 0x0000033A
_08089488:
	cmp r0, #0x1d
	bhi _08089502
	ldr r1, _080894B8 @ =0x00000404
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _080894BC @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	cmp r0, #0
	blt _080894C0
	asrs r3, r0, #0xc
	b _080894C6
	.align 2, 0
_080894B8: .4byte 0x00000404
_080894BC: .4byte 0x085B0A08
_080894C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080894C6:
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	cmp r0, #0
	blt _080894E4
	asrs r2, r0, #0xc
	b _080894EA
_080894E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080894EA:
	adds r1, r4, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08089534 @ =0x00000404
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
_08089502:
	ldr r0, _08089538 @ =0x00000402
	adds r3, r4, r0
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808952E
	ldr r2, _0808953C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08089540 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08089544 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x2d
	strh r0, [r3]
_0808952E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089534: .4byte 0x00000404
_08089538: .4byte 0x00000402
_0808953C: .4byte 0x030046B8
_08089540: .4byte 0x000003FF
_08089544: .4byte 0x0203B400

	thumb_func_start FUN_08089548
FUN_08089548: @ 0x08089548
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808959C @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xf
	beq _0808955E
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_08085ee0
_0808955E:
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	ldr r0, _080895A0 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r2, _080895A4 @ =0x0000032A
	adds r5, r4, r2
	movs r0, #1
	strh r0, [r5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	ldr r0, _080895A8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080895C8
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _080895AC
	adds r0, r4, #0
	bl FUN_08087a5c
	b _080895C8
	.align 2, 0
_0808959C: .4byte 0x000001F5
_080895A0: .4byte 0x0000FFFB
_080895A4: .4byte 0x0000032A
_080895A8: .4byte 0x030047A4
_080895AC:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080895C2
	strh r1, [r5]
	adds r0, r4, #0
	bl FUN_080856f4
	b _080895C8
_080895C2:
	adds r0, r4, #0
	bl FUN_08089410
_080895C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080895d0
FUN_080895d0: @ 0x080895D0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08089638 @ =0x00000402
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x1e
	bne _08089640
	adds r0, r4, #0
	adds r0, #0x48
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r2, r1, r0
	adds r0, r4, #0
	adds r0, #0x4c
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0xf0
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _0808960E
	cmp r1, #0
	beq _080896D4
_0808960E:
	adds r0, r2, #0
	bl FUN_0823785c
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	ldr r2, _0808963C @ =0x00000404
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r4, r3
	b _080896D2
	.align 2, 0
_08089638: .4byte 0x00000402
_0808963C: .4byte 0x00000404
_08089640:
	cmp r0, #0x1d
	bhi _080896D4
	ldr r1, _08089674 @ =0x00000404
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _08089678 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _0808967C
	asrs r3, r0, #0xc
	b _08089682
	.align 2, 0
_08089674: .4byte 0x00000404
_08089678: .4byte 0x085B0A08
_0808967C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08089682:
	adds r1, r4, #0
	adds r1, #0x48
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080896A2
	asrs r2, r0, #0xc
	b _080896A8
_080896A2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080896A8:
	adds r1, r4, #0
	adds r1, #0x4c
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08089708 @ =0x00000404
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08087f7c
	ldr r3, _0808970C @ =0x0000033A
	adds r1, r4, r3
	movs r0, #1
_080896D2:
	strb r0, [r1]
_080896D4:
	ldr r0, _08089710 @ =0x00000402
	adds r3, r4, r0
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08089700
	ldr r2, _08089714 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08089718 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0808971C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x2d
	strh r0, [r3]
_08089700:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08089708: .4byte 0x00000404
_0808970C: .4byte 0x0000033A
_08089710: .4byte 0x00000402
_08089714: .4byte 0x030046B8
_08089718: .4byte 0x000003FF
_0808971C: .4byte 0x0203B400

	thumb_func_start FUN_08089720
FUN_08089720: @ 0x08089720
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080897B4 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	beq _08089736
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_08085ee0
_08089736:
	ldr r2, _080897B8 @ =0x0000032A
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r2, r4, r3
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x48]
	str r1, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0x48
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _08089760
	rsbs r1, r1, #0
_08089760:
	cmp r1, #2
	bgt _08089782
	adds r0, r4, #0
	adds r0, #0x4c
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _0808977E
	rsbs r1, r1, #0
_0808977E:
	cmp r1, #2
	ble _0808978A
_08089782:
	ldr r3, _080897BC @ =0x0000033A
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_0808978A:
	ldr r1, _080897C0 @ =0x0000038E
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r0, [r4, #0x1a]
	cmp r0, #5
	bne _080897C4
	ldr r3, _080897BC @ =0x0000033A
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080897C4
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _080897CC
	.align 2, 0
_080897B4: .4byte 0x000001F5
_080897B8: .4byte 0x0000032A
_080897BC: .4byte 0x0000033A
_080897C0: .4byte 0x0000038E
_080897C4:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
_080897CC:
	ldr r0, _080897F0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08089820
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _080897F4
	adds r0, r4, #0
	bl FUN_08087a5c
	b _08089820
	.align 2, 0
_080897F0: .4byte 0x030047A4
_080897F4:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08089814
	ldr r3, _08089810 @ =0x0000032A
	adds r0, r4, r3
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_080856f4
	b _08089820
	.align 2, 0
_08089810: .4byte 0x0000032A
_08089814:
	adds r0, r4, #0
	bl FUN_080895d0
	adds r0, r4, #0
	bl FUN_080880fc
_08089820:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity0B50_Update
Entity0B50_Update: @ 0x08089828
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08089848 @ =0x00000406
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #4
	ldr r0, _0808984C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08089850
	adds r0, r4, #0
	bl FUN_08085408
	b _080898C4
	.align 2, 0
_08089848: .4byte 0x00000406
_0808984C: .4byte 0x03002BC0
_08089850:
	ldr r1, _08089864 @ =0x0000040B
	adds r5, r4, r1
	ldrb r1, [r5]
	cmp r1, #0
	beq _08089868
	adds r0, r4, #0
	bl KillEntity
	b _080898C4
	.align 2, 0
_08089864: .4byte 0x0000040B
_08089868:
	ldr r2, _080898CC @ =0x0000031E
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _080898D0 @ =0x0000033A
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08087970
	ldr r1, _080898D4 @ =0x085AC000
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_0808766c
	adds r0, r4, #0
	bl FUN_080874cc
	adds r0, r4, #0
	bl FUN_08085ec4
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r1, r4, r2
	adds r0, r4, #0
	adds r0, #0x48
	str r0, [r1]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08234660
	ldrb r0, [r5]
	cmp r0, #0
	beq _080898C4
	adds r0, r4, #0
	bl KillEntity
_080898C4:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080898CC: .4byte 0x0000031E
_080898D0: .4byte 0x0000033A
_080898D4: .4byte 0x085AC000

	thumb_func_start Entity0B50_Destroy
Entity0B50_Destroy: @ 0x080898D8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080898F0
	subs r1, #0x10
	adds r0, r4, r1
	bl FUN_080f8cac
_080898F0:
	adds r0, r4, #0
	adds r0, #0x40
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0x84
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0xdc
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_0808565c
	adds r0, r4, #0
	bl FUN_080856cc
	ldr r1, _08089920 @ =0x03002C00
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08089920: .4byte 0x03002C00

	thumb_func_start Entity0B50_Init
Entity0B50_Init: @ 0x08089924
	push {r4, lr}
	adds r4, r0, #0
	bl Entity0B50_Init_Helper_08086df8
	adds r0, r4, #0
	bl FUN_08086f90
	adds r0, r4, #0
	bl FUN_08087058
	adds r0, r4, #0
	bl Entity0B50_Init_Helper_08086e64
	adds r0, r4, #0
	bl FUN_080871e4
	adds r0, r4, #0
	bl FUN_08087290
	adds r0, r4, #0
	bl FUN_080853c0
	adds r0, r4, #0
	bl FUN_08087310
	ldr r1, _08089990 @ =0x0000032A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	adds r3, #6
	adds r0, r4, r3
	strh r1, [r0]
	movs r0, #0xe8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08089994 @ =0x0000FFFF
	strh r0, [r1]
	ldr r1, _08089998 @ =0x0000040B
	adds r0, r4, r1
	strb r2, [r0]
	adds r3, #0xd8
	adds r0, r4, r3
	strb r2, [r0]
	ldr r0, _0808999C @ =0x03002C00
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08089990: .4byte 0x0000032A
_08089994: .4byte 0x0000FFFF
_08089998: .4byte 0x0000040B
_0808999C: .4byte 0x03002C00

	thumb_func_start Entity0B50_Create
Entity0B50_Create: @ 0x080899A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080899DC @ =0x03002C00
	ldr r0, [r0]
	cmp r0, #0
	bne _080899EE
	ldr r1, _080899E0 @ =0x0000041C
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080899EC
	ldr r1, _080899E4 @ =Entity0B50_Update
	ldr r2, _080899E8 @ =Entity0B50_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity0B50_Init
	cmp r0, #0
	bge _080899EC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080899EE
	.align 2, 0
_080899DC: .4byte 0x03002C00
_080899E0: .4byte 0x0000041C
_080899E4: .4byte Entity0B50_Update
_080899E8: .4byte Entity0B50_Destroy
_080899EC:
	adds r0, r4, #0
_080899EE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080899f4
FUN_080899f4: @ 0x080899F4
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08089A50 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _08089A98
	ldr r0, [r0, #0x1c]
	cmp r0, #1
	bne _08089A98
	movs r7, #0
	ldr r6, _08089A54 @ =0x030046A0
	ldr r0, [r6]
	movs r4, #0xae
	lsls r4, r4, #2
	adds r1, r0, r4
	ldr r0, [r1]
	cmp r0, #0
	ble _08089A58
	ldrh r0, [r5, #0x18]
	adds r0, #1
	strh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r5, #0x1a]
	cmp r0, r2
	blo _08089A5A
	strh r7, [r5, #0x18]
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	ldr r1, [r6]
	adds r0, r1, r4
	ldr r0, [r0]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #1
	bl FUN_0809c3c0
	ldr r0, [r6]
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	bgt _08089A5A
	b _08089A5E
	.align 2, 0
_08089A50: .4byte 0x03002BE0
_08089A54: .4byte 0x030046A0
_08089A58:
	movs r7, #1
_08089A5A:
	cmp r7, #0
	beq _08089A98
_08089A5E:
	ldr r4, _08089AA0 @ =0x03002BE0
	ldr r1, [r4]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0x15
	beq _08089A98
	adds r0, r1, #0
	bl FUN_0807e854
	ldr r0, [r4]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	movs r1, #0x1f
	strb r1, [r0]
	ldr r0, [r4]
	ldr r1, _08089AA4 @ =0x0000037D
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r4]
	adds r1, #1
	adds r0, r0, r1
	strh r2, [r0]
	adds r0, r5, #0
	bl KillEntity
_08089A98:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08089AA0: .4byte 0x03002BE0
_08089AA4: .4byte 0x0000037D

	thumb_func_start FUN_08089aa8
FUN_08089aa8: @ 0x08089AA8
	movs r0, #0
	bx lr

	thumb_func_start FUN_08089aac
FUN_08089aac: @ 0x08089AAC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08089AD4 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r0, [r1]
	cmp r0, #0
	bgt _08089AC4
	movs r0, #1
	str r0, [r1]
_08089AC4:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08089AD8
	bl Script_GetValue
	b _08089ADA
	.align 2, 0
_08089AD4: .4byte 0x030046A0
_08089AD8:
	movs r0, #0x1e
_08089ADA:
	strh r0, [r4, #0x1a]
	movs r0, #0
	strh r0, [r4, #0x18]
	ldr r0, _08089B00 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r0, [r0]
	adds r2, #4
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
	bl FUN_0809c3c0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08089B00: .4byte 0x030046A0

	thumb_func_start FUN_08089b04
FUN_08089b04: @ 0x08089B04
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #8
	movs r1, #0x1c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08089B40
	ldr r1, _08089B38 @ =FUN_080899f4
	ldr r2, _08089B3C @ =FUN_08089aa8
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08089aac
	cmp r0, #0
	bge _08089B40
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08089B42
	.align 2, 0
_08089B38: .4byte FUN_080899f4
_08089B3C: .4byte FUN_08089aa8
_08089B40:
	adds r0, r4, #0
_08089B42:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
