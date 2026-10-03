	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080BE66A
	bl FUN_0823d340
	movs r2, #0xb2
	lsls r2, r2, #5
	adds r1, r4, r2
	str r0, [r1]
_080BE66A:
	bl FUN_08049f5c
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl TextBox_SetRect
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, _080BE68C @ =0x0000A41A
	bl TextBox_SetBgPltt
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BE68C: .4byte 0x0000A41A
