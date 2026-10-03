	push {r4, lr}
	ldr r0, _0823E1D4 @ =gClock
	ldrb r2, [r0, #4]
	ldrb r1, [r0, #0xa]
	adds r4, r0, #0
	cmp r2, r1
	bhs _0823E1DE
	ldrb r0, [r4, #0xc]
	cmp r0, r1
	bhs _0823E1D8
	cmp r2, r0
	blo _0823E26E
	cmp r2, r0
	bne _0823E256
	ldrb r0, [r4, #5]
	movs r3, #0
	ldrb r1, [r4, #0xd]
	b _0823E24A
	.align 2, 0
_0823E1D4: .4byte gClock
_0823E1D8:
	cmp r0, r1
	bne _0823E256
	b _0823E244
_0823E1DE:
	cmp r2, r1
	bne _0823E1FE
	ldrb r0, [r4, #0xc]
	cmp r0, r1
	bne _0823E1F2
	ldrb r1, [r4, #0xd]
	ldrb r0, [r4, #0xb]
	cmp r1, r0
	blo _0823E214
	b _0823E222
_0823E1F2:
	ldrb r0, [r4, #5]
	movs r3, #1
	ldrb r1, [r4, #0xb]
	cmp r0, r1
	bhs _0823E252
	b _0823E256
_0823E1FE:
	ldrb r0, [r4, #0xc]
	cmp r2, r0
	blo _0823E26E
	cmp r2, r0
	bne _0823E23C
	cmp r0, r1
	bne _0823E234
	ldrb r1, [r4, #0xd]
	ldrb r0, [r4, #0xb]
	cmp r1, r0
	bhs _0823E222
_0823E214:
	ldrb r2, [r4, #5]
	movs r3, #1
	cmp r2, r1
	blo _0823E26E
	cmp r2, r0
	bhs _0823E252
	b _0823E256
_0823E222:
	cmp r0, r1
	bhs _0823E256
	ldrb r2, [r4, #5]
	movs r3, #0
	cmp r2, r0
	blo _0823E256
	cmp r2, r1
	bhs _0823E252
	b _0823E26E
_0823E234:
	ldrb r0, [r4, #5]
	movs r3, #0
	ldrb r1, [r4, #0xd]
	b _0823E24A
_0823E23C:
	cmp r0, r1
	blo _0823E26E
	cmp r0, r1
	bne _0823E250
_0823E244:
	ldrb r0, [r4, #0xd]
	movs r3, #0
	ldrb r1, [r4, #0xb]
_0823E24A:
	cmp r0, r1
	bhs _0823E252
	b _0823E26E
_0823E250:
	movs r3, #0
_0823E252:
	cmp r3, #0
	bne _0823E26E
_0823E256:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0823E260
	movs r0, #0
	b _0823E284
_0823E260:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0823E26A
	movs r0, #4
	b _0823E284
_0823E26A:
	movs r0, #5
	b _0823E284
_0823E26E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0823E278
	movs r0, #1
	b _0823E284
_0823E278:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _0823E282
	movs r0, #2
	b _0823E284
_0823E282:
	movs r0, #3
_0823E284:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
