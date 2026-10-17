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
