	mov ip, sp
	push {r4, r5, fp, ip, lr, pc}
	ldr r3, _0822F6F0 @ =0x03004044
	sub fp, ip, #4
	mov ip, #0
	mov lr, r0
	mov r5, r1
	ldr r2, [r3]
	mov r4, r3
	cmp ip, r2
	bge _0822F6A0
	mov r1, r2
	ldr r0, _0822F6F4 @ =0x03004470
_0822F684:
	lsl r3, ip, #1
	ldrh r2, [r0, r3]
	cmp r2, lr
	beq _0822F6E0
	add ip, ip, #1
	cmp ip, r1
	blt _0822F684
_0822F6A0:
	ldr ip, [r4]
	cmp ip, #0xf
	bgt _0822F6E8
	ldr r2, _0822F6F4 @ =0x03004470
	mov r0, r5
	ldr r1, _0822F6F8 @ =gObjectPlttBuffer
	lsl r3, ip, #1
	strh lr, [r2, r3]
	add r1, r1, ip, lsl #5
	mov r2, #8
	bl _CpuFastSet
	ldr r3, [r4]
	mov r0, r3
	add r3, r3, #1
	str r3, [r4]
	ldmdb fp, {r4, r5, fp, sp, pc}
_0822F6E0:
	mov r0, ip
	ldmdb fp, {r4, r5, fp, sp, pc}
_0822F6E8:
	mov r0, #0
	ldmdb fp, {r4, r5, fp, sp, pc}
	.align 2, 0
_0822F6F0: .4byte 0x03004044
_0822F6F4: .4byte 0x03004470
_0822F6F8: .4byte gObjectPlttBuffer
