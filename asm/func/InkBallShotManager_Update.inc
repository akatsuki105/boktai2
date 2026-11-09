	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x40
	movs r7, #0
	ldr r0, _08203394 @ =0x085AE818
	mov r8, r0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r6, r0
_08203360:
	ldrh r0, [r4]
	cmp r0, #0
	beq _0820337A
	ldrb r0, [r4, #0xe]
	cmp r0, #2
	bhi _08203388
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl _call_via_r2
_0820337A:
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, r5, r0
	adds r7, #1
	cmp r7, #7
	ble _08203360
_08203388:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08203394: .4byte 0x085AE818
