	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	beq _080A950A
	bl FUN_0809c58c
	adds r0, r4, #0
	bl KillEntity
	b _080A952C
_080A950A:
	ldrh r0, [r4, #0x18]
	subs r0, #1
	strh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A952C
	bl FUN_0809c58c
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A9526
	movs r1, #0
	bl VM_ExecByID
_080A9526:
	adds r0, r4, #0
	bl KillEntity
_080A952C:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
