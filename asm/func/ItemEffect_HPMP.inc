	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r1, [r2]
	ldr r3, _08091C30 @ =0x00003FA6
	adds r0, r4, r3
	ldrh r0, [r0]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r1, r1, r3
	movs r5, #0
	strh r0, [r1]
	ldr r0, [r2]
	ldr r6, _08091C34 @ =0x00003FAA
	adds r1, r4, r6
	ldrh r1, [r1]
	movs r6, #0xda
	lsls r6, r6, #2
	adds r0, r0, r6
	strh r1, [r0]
	ldr r0, [r2]
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08091C40
	ldr r1, _08091C38 @ =0x00003AE4
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x30
	bl CheckItemOwn
	cmp r0, #0
	beq _08091C46
	ldr r3, _08091C3C @ =0x00003FBB
	adds r0, r4, r3
	b _08091C44
	.align 2, 0
_08091C30: .4byte 0x00003FA6
_08091C34: .4byte 0x00003FAA
_08091C38: .4byte 0x00003AE4
_08091C3C: .4byte 0x00003FBB
_08091C40:
	ldr r6, _08091C4C @ =0x00003FBB
	adds r0, r4, r6
_08091C44:
	strb r5, [r0]
_08091C46:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08091C4C: .4byte 0x00003FBB
