	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _08047DE0 @ =0x030000C4
	ldr r4, [r0]
	cmp r4, #0
	beq _08047DE4
	adds r0, r4, #0
	bl TextBox_LoadBgPltt
	cmp r0, #0
	blt _08047DE4
	adds r0, r4, #0
	bl TextBox_UploadBgPltt
	movs r0, #0
	b _08047DE8
	.align 2, 0
_08047DE0: .4byte 0x030000C4
_08047DE4:
	movs r0, #1
	rsbs r0, r0, #0
_08047DE8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
