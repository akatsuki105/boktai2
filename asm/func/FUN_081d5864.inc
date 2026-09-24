	push {r4, r5, r6, r7, lr}
	movs r5, #0
	ldr r1, _081D588C @ =0x0000057C
	adds r2, r0, r1
	movs r3, #1
	movs r7, #0xac
	lsls r7, r7, #1
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r6, r0, r1
	adds r4, r0, #0
	adds r4, #0x1c
_081D587C:
	adds r1, r3, #0
	lsls r1, r5
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D5890
	movs r0, #1
	b _081D5892
	.align 2, 0
_081D588C: .4byte 0x0000057C
_081D5890:
	movs r0, #0
_081D5892:
	cmp r0, #0
	bne _081D58AE
	adds r1, r3, #0
	lsls r1, r5
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	adds r0, r4, #0
	adds r1, r7, #0
	bl ClearMemory
	strh r5, [r6]
	adds r0, r4, #0
	b _081D58BE
_081D58AE:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	ble _081D587C
	movs r0, #0
_081D58BE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
