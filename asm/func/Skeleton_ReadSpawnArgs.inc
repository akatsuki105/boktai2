	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r0, #0x45
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081055F2
	bl VM_GetPC
	cmp r0, #0
	beq _081055D0
	bl VM_GetValue
	adds r1, r0, #0
	b _081055D2
_081055D0:
	movs r1, #0
_081055D2:
	movs r2, #0xe5
	lsls r2, r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081055EA
	bl VM_GetValue
	adds r1, r0, #0
	b _081055EC
_081055EA:
	movs r1, #0
_081055EC:
	ldr r2, _0810560C @ =0x0000072A
	adds r0, r5, r2
	strh r1, [r0]
_081055F2:
	movs r0, #0x64
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08105640
	bl VM_GetPC
	cmp r0, #0
	beq _08105610
	bl VM_GetValue
	adds r4, r0, #0
	b _08105612
	.align 2, 0
_0810560C: .4byte 0x0000072A
_08105610:
	movs r4, #0
_08105612:
	bl VM_GetPC
	cmp r0, #0
	beq _08105622
	bl VM_GetValue
	adds r1, r0, #0
	b _08105624
_08105622:
	movs r1, #0
_08105624:
	ldr r2, _0810563C @ =0x00000726
	adds r0, r5, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08105660
	bl VM_GetValue
	adds r3, r0, #0
	b _08105646
	.align 2, 0
_0810563C: .4byte 0x00000726
_08105640:
	movs r4, #0
	movs r3, #1
	rsbs r3, r3, #0
_08105646:
	cmp r3, #0
	blt _08105660
	movs r0, #0x80
	lsls r0, r0, #4
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08105670 @ =0x00000756
	adds r0, r5, r2
	strb r3, [r0]
_08105660:
	cmp r4, #0
	beq _08105688
	cmp r4, #1
	beq _08105674
	cmp r4, #2
	beq _08105678
	b _08105688
	.align 2, 0
_08105670: .4byte 0x00000756
_08105674:
	movs r0, #0xa
	b _0810567C
_08105678:
	movs r0, #0x80
	lsls r0, r0, #5
_0810567C:
	movs r1, #0xe6
	lsls r1, r1, #3
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08105688:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
