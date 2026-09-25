	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DBDA8
	movs r5, #0
	movs r7, #0x80
	lsls r7, r7, #2
	movs r0, #0xe5
	lsls r0, r0, #3
	adds r4, r6, r0
_080DBD40:
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r1, #1
	lsls r1, r5
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080DBD56
	movs r0, #1
	b _080DBD58
_080DBD56:
	movs r0, #0
_080DBD58:
	cmp r0, #0
	beq _080DBDA0
	adds r3, r4, #0
	ldr r0, _080DBDB0 @ =0x030047A4
	ldr r1, _080DBDB4 @ =0x030047A0
	ldr r2, [r0]
	ldr r0, [r1]
	orrs r0, r2
	ands r0, r7
	cmp r0, #0
	bne _080DBD84
	movs r0, #0x80
	lsls r0, r0, #4
	ands r2, r0
	cmp r2, #0
	beq _080DBD8E
	ldr r0, _080DBDB8 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080DBD8E
_080DBD84:
	ldrh r1, [r4, #0x10]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080DBDA0
_080DBD8E:
	ldr r0, _080DBDBC @ =0x085AD320
	ldrb r1, [r3, #0x12]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r2, [r1]
	adds r0, r6, #0
	adds r1, r3, #0
	bl _call_via_r2
_080DBDA0:
	adds r4, #0x18
	adds r5, #1
	cmp r5, #0x1f
	ble _080DBD40
_080DBDA8:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DBDB0: .4byte 0x030047A4
_080DBDB4: .4byte 0x030047A0
_080DBDB8: .4byte 0x030044BC
_080DBDBC: .4byte 0x085AD320
