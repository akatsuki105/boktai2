	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldr r1, [r3, #0x4c]
	cmp r1, #0
	blt _081DDB06
	movs r2, #0x18
	ldrsh r0, [r3, r2]
	cmp r1, r0
	bne _081DDB06
	ldrb r0, [r3, #0x1f]
	cmp r0, #0xe
	bhi _081DDB06
	movs r4, #0
	movs r2, #0
	ldrh r5, [r3, #0x1a]
	ldr r6, _081DDADC @ =0x0000FFFF
_081DDAD4:
	cmp r2, #0
	bge _081DDAE0
	ldr r0, _081DDADC @ =0x0000FFFF
	b _081DDAE8
	.align 2, 0
_081DDADC: .4byte 0x0000FFFF
_081DDAE0:
	ldr r1, [r3, #0x44]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r0, [r0]
_081DDAE8:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	beq _081DDAF2
	adds r4, #1
_081DDAF2:
	adds r2, #1
	cmp r2, #3
	ble _081DDAD4
	cmp r4, r5
	bne _081DDB00
	movs r0, #1
	b _081DDB02
_081DDB00:
	movs r0, #0
_081DDB02:
	cmp r0, #0
	bne _081DDB0C
_081DDB06:
	movs r0, #1
	rsbs r0, r0, #0
	b _081DDB0E
_081DDB0C:
	movs r0, #0
_081DDB0E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
