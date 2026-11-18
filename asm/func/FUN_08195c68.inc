	push {lr}
	adds r1, r0, #0
	ldr r2, _08195C7C @ =0x00000CC4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08195C80
	movs r0, #1
	b _08195C8C
	.align 2, 0
_08195C7C: .4byte 0x00000CC4
_08195C80:
	movs r0, #0xc6
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, _08195C90 @ =FUN_08195aac
	str r0, [r1]
	movs r0, #0
_08195C8C:
	pop {r1}
	bx r1
	.align 2, 0
_08195C90: .4byte FUN_08195aac
