	push {r4, lr}
	sub sp, #4
	adds r4, r2, #0
	adds r0, r4, #0
	adds r0, #0xec
	ldrh r0, [r0]
	cmp r0, #0
	beq _08202D88
	adds r0, r4, #0
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	bne _08202D88
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #4
	movs r1, #2
	movs r3, #0x40
	bl Puff_SpawnSpray
	adds r0, r4, #0
	bl InkBallShotManager_Remove
_08202D88:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
