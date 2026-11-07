	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D9934 @ =0x00000ECC
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D9962
	movs r4, #0
	ldr r0, _081D9934 @ =0x00000ECC
	adds r6, r5, r0
	ldr r1, _081D9938 @ =0x085AE12C
	mov r8, r1
_081D9924:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D993C
	movs r0, #1
	b _081D993E
	.align 2, 0
_081D9934: .4byte 0x00000ECC
_081D9938: .4byte 0x085AE12C
_081D993C:
	movs r0, #0
_081D993E:
	cmp r0, #0
	beq _081D995C
	movs r0, #0xbc
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	adds r0, r1, #0
	adds r0, #0x68
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D995C:
	adds r4, #1
	cmp r4, #0x13
	ble _081D9924
_081D9962:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
