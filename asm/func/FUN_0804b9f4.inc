	push {r4, r5, r6, lr}
	bl VM_GetValue
	lsls r1, r0, #1
	movs r4, #0
	movs r3, #0
	ldr r0, _0804BA2C @ =gSystemSaveData
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #0x18
	ldr r0, _0804BA30 @ =0x085AB5B0
	adds r2, r1, r0
_0804BA0C:
	adds r0, r5, r1
	ldrb r0, [r0]
	ldrb r6, [r2]
	cmp r0, r6
	bne _0804BA18
	adds r4, #1
_0804BA18:
	adds r2, #1
	adds r3, #1
	adds r1, #1
	cmp r3, #1
	ble _0804BA0C
	cmp r4, #2
	beq _0804BA34
	movs r0, #0
	b _0804BA36
	.align 2, 0
_0804BA2C: .4byte gSystemSaveData
_0804BA30: .4byte 0x085AB5B0
_0804BA34:
	movs r0, #1
_0804BA36:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
