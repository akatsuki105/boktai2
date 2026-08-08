	push {r4, lr}
	ldr r2, [r2]
	cmp r2, #0
	beq _08236D38
_08236D18:
	adds r1, r2, #0
	ldr r2, [r2]
	ldrh r0, [r1, #0x14]
	ldrh r4, [r1, #0xc]
	adds r0, r0, r4
	strh r0, [r1, #0x24]
	ldrh r0, [r1, #0x16]
	ldrh r4, [r1, #0xe]
	adds r0, r0, r4
	strh r0, [r1, #0x26]
	ldrh r0, [r1, #0x18]
	ldrh r4, [r1, #0x10]
	adds r0, r0, r4
	strh r0, [r1, #0x28]
	cmp r2, #0
	bne _08236D18
_08236D38:
	ldr r3, [r3]
	cmp r3, #0
	beq _08236D6A
	movs r4, #4
_08236D40:
	adds r2, r3, #0
	ldr r3, [r3]
	ldrh r1, [r2, #6]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _08236D66
	ldrh r0, [r2, #0x14]
	ldrh r1, [r2, #0xc]
	adds r0, r0, r1
	strh r0, [r2, #0x24]
	ldrh r0, [r2, #0x16]
	ldrh r1, [r2, #0xe]
	adds r0, r0, r1
	strh r0, [r2, #0x26]
	ldrh r0, [r2, #0x18]
	ldrh r1, [r2, #0x10]
	adds r0, r0, r1
	strh r0, [r2, #0x28]
_08236D66:
	cmp r3, #0
	bne _08236D40
_08236D6A:
	pop {r4}
	pop {r0}
	bx r0
