	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	ldrb r0, [r5, #0x18]
	cmp sl, r0
	bge _080A4AAC
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r0, r0, r5
	mov sb, r0
	movs r0, #0x84
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0
	adds r7, #0xd4
	ldr r0, _080A4AC0 @ =0x00000121
	adds r4, r5, r0
	adds r6, r5, #0
	adds r6, #0x3c
_080A4A70:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A4A7C
	adds r0, r7, #0
	bl Mover_Unlink
_080A4A7C:
	adds r0, r6, #0
	bl AuxSprite_Remove
	mov r0, r8
	bl Hitbox_Unregister
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	beq _080A4A94
	mov r0, sb
	bl Map_RemoveTileOverride
_080A4A94:
	movs r0, #0x88
	lsls r0, r0, #1
	add sb, r0
	add r8, r0
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, r6, r0
	movs r0, #1
	add sl, r0
	ldrb r0, [r5, #0x18]
	cmp sl, r0
	blt _080A4A70
_080A4AAC:
	ldr r1, _080A4AC4 @ =0x03002C44
	movs r0, #0
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A4AC0: .4byte 0x00000121
_080A4AC4: .4byte 0x03002C44
