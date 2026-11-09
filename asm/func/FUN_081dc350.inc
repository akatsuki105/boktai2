	push {r4, lr}
	adds r3, r0, #0
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DC36C
	ldr r1, _081DC388 @ =0x000003D6
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r4]
_081DC36C:
	ldr r0, _081DC388 @ =0x000003D6
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0xa
	bne _081DC37C
	adds r0, r3, #0
	bl FUN_081dc2e0
_081DC37C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC388: .4byte 0x000003D6
