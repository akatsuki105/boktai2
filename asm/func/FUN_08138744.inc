	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r3, #0
	movs r4, #0xae
	lsls r4, r4, #4
	adds r2, r0, r4
_08138756:
	ldrh r0, [r2]
	cmp r0, r1
	bne _08138760
	movs r0, #1
	b _0813876A
_08138760:
	adds r2, #2
	adds r3, #1
	cmp r3, #5
	ble _08138756
	movs r0, #0
_0813876A:
	pop {r4}
	pop {r1}
	bx r1
