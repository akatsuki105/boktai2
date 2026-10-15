	push {lr}
	ldr r2, _081E3E9C @ =0x0000161A
	adds r1, r0, r2
	ldrb r1, [r1]
	subs r2, #0x81
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _081E3E98
	adds r0, r1, #0
	bl FUN_08243180
	cmp r0, #0
	bne _081E3EA0
_081E3E98:
	movs r0, #0
	b _081E3EA2
	.align 2, 0
_081E3E9C: .4byte 0x0000161A
_081E3EA0:
	movs r0, #1
_081E3EA2:
	pop {r1}
	bx r1
	.align 2, 0
