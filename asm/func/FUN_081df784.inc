	push {r4, lr}
	sub sp, #8
	ldr r0, _081DF798 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DF79C
	movs r4, #1
	rsbs r4, r4, #0
	b _081DF7A0
	.align 2, 0
_081DF798: .4byte 0x03002C68
_081DF79C:
	movs r1, #0x18
	ldrsh r4, [r0, r1]
_081DF7A0:
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
