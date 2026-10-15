	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A182E
	adds r0, r4, #0
	adds r0, #0x20
	bl Mover_Unlink
_080A182E:
	adds r0, r4, #0
	adds r0, #0x64
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0xac
	bl AuxSprite_Remove
	ldr r0, _080A184C @ =0x00000237
	bl sound_08240740
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A184C: .4byte 0x00000237
