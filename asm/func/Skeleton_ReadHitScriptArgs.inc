	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #0x78
	bl VM_SeekToNamedArg
	adds r2, r0, #0
	cmp r2, #0
	beq _0810868C
	bl VM_GetPC
	cmp r0, #0
	beq _0810865A
	bl VM_GetValue
	adds r1, r0, #0
	b _0810865C
_0810865A:
	movs r1, #0
_0810865C:
	movs r2, #0xdf
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08108674
	bl VM_GetValue
	adds r2, r0, #0
	b _08108676
_08108674:
	movs r2, #0
_08108676:
	ldr r1, _08108684 @ =0x000006FA
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08108688 @ =0x000006FB
	b _0810869E
	.align 2, 0
_08108684: .4byte 0x000006FA
_08108688: .4byte 0x000006FB
_0810868C:
	movs r1, #0xdf
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _081086A8 @ =0x000006FA
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
_0810869E:
	adds r0, r4, r2
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081086A8: .4byte 0x000006FA
