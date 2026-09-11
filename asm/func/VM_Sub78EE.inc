	push {r4, lr}
	sub sp, #8
	ldr r0, _0800A454 @ =0x03000040
	ldr r0, [r0]
	movs r4, #0
	cmp r0, #0
	beq _0800A438
	adds r1, r0, #0
	adds r1, #0x2c
	movs r2, #0xf
_0800A428:
	ldrb r0, [r1, #5]
	cmp r0, #0
	beq _0800A430
	adds r4, #1
_0800A430:
	adds r1, #0x9c
	subs r2, #1
	cmp r2, #0
	bge _0800A428
_0800A438:
	mov r0, sp
	bl FUN_0823167c
	mov r0, sp
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800A454: .4byte 0x03000040
