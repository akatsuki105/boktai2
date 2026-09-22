	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080B475A
	bl FUN_0823d340
	movs r2, #0xba
	lsls r2, r2, #3
	adds r1, r4, r2
	str r0, [r1]
_080B475A:
	ldr r0, _080B4784 @ =0x0000EAA8
	bl TextBox_SetBgPltt
	movs r1, #0xba
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextBox_Start
	movs r0, #1
	movs r1, #0xf
	movs r2, #0x1c
	movs r3, #4
	bl TextBox_SetRect
	movs r0, #1
	bl TextBox_SetInstant
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4784: .4byte 0x0000EAA8
