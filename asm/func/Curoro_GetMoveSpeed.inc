	push {lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0813C544 @ =0x00000664
	adds r0, r0, r1
	ldrh r0, [r0]
	lsrs r0, r0, #7
	adds r1, r0, #0
	cmp r1, #7
	ble _0813C536
	movs r1, #7
_0813C536:
	ldr r0, _0813C548 @ =0x085AD784
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_0813C544: .4byte 0x00000664
_0813C548: .4byte 0x085AD784
